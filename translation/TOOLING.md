# Catalan translation — verification tooling

Five checks that catch the failure modes a translation of this size runs into.
The width audits compare only against strings this branch actually changed, so
untouched English text is never reported. Run them from the repo root.

```sh
python3 translation/check_name_limits.py     # build-breaking: names vs array bounds
python3 translation/audit_box_widths.py      # cosmetic: C strings vs their window
python3 translation/audit_script_widths.py   # cosmetic: script dialogue vs message box
python3 translation/check_english.py         # English left in the translated text
python3 translation/check_terms.py           # same thing, same Catalan name, in every file
```

All five exit non-zero when something is wrong, so they can be wired into CI.

## `check_terms.py` — one name per thing, in every file

Builds English→Catalan pairs from the game's own tables (item, move and
ability names, region-map names) plus fixed glossary terms (Centre Pokémon,
Equip Rocket, Medalla, PokéGear…). For every translated message whose English
mentions one of those names, the Catalan must use the agreed name. It knows
that table names are abbreviated to fit ("Camp. Closca" matches "Campana
Closca"), ignores accents and elision, and accepts the short forms listed in
`ALIASES` ("la Torre", "Gimnàs de Viridiana"). Reviewed exceptions — the
English word used in another sense ("Crunch, crunch…"), real cartridge names
in the link texts — are in `terms_exceptions.txt` with the reason.

## `check_english.py` — English left in the text

Runs every word of every translated string through hunspell and reports the
ones the English dictionary accepts and the Catalan one rejects. Species and
trainer names, the name tables kept in English by design, the debug menus and
the inactive `#else` name tables are skipped. What remains after review —
proper names, abbreviations, interjections, brands and accepted loanwords —
is listed with the reason in `english_allowlist.txt`; anything not on that
list fails the check. Needs `hunspell`, `hunspell-ca` and `hunspell-en-us`.

### The English base

"Changed" means different from the untranslated English tree. The scripts look
for it at `main`, then `origin/main`; set `TRANSLATION_BASE=<ref>` to use
something else. A fresh clone usually has only `origin/main`
(`git fetch origin main` if not even that). The scripts stop with an error when
no base can be read: before this was handled, a clone without a local `main`
compared every file against an empty string, and both audits reported
`0` without checking anything.

## `check_name_limits.py` — fixed-size name tables

Names are stored in `const u8 x[COUNT][LEN + 1]` tables. One character too long
is a hard build failure (`excess elements in array initializer`), not a cosmetic
issue. Lengths are counted in **encoded bytes** via `charmap.txt`, so `l·l` and
accented glyphs count as the single bytes the ROM stores.

| Table | Usable limit | Where the limit comes from |
| --- | --- | --- |
| move name | 16 | `MOVE_NAME_LENGTH`, needs `B_EXPANDED_MOVE_NAMES = TRUE` |
| ability name | 16 | `ABILITY_NAME_LENGTH`, `B_EXPANDED_ABILITY_NAMES` already `TRUE` on `main` |
| trainer class | 12 | `gTrainerClassNames[][13]` |
| item name | **13** | `u8 name[ITEM_NAME_LENGTH]` = `name[14]` *including* the `0xFF` terminator |

The item-name limit is the easy one to get wrong: the field is 14 bytes but one
is the terminator, so 13 characters is the real maximum.

Move names are also checked in **pixels** against the two fixed slots that draw
them, with the same font choice the code makes:

| Slot | Limit | Font |
| --- | --- | --- |
| summary move list (`PrintSummaryMoveName`, x=64 in a 152 px window) | 88 px | `FONT_NORMAL`; `FONT_NARROW` for the 9 names wider than 88 px |
| battle move menu (`B_WIN_MOVE_NAME_*`) | 64 px | `FONT_NARROW`, condensed 1 px per glyph above 64 px |

## `audit_box_widths.py` — text-box overflow

**A character count cannot tell you whether text fits.** The GBA font is
variable-width — `Velocitat` and `Illuminat` have the same character count and
different pixel widths. Sizing Catalan text by counting characters is what put
350 strings outside their boxes on this branch.

This script encodes each string through `charmap.txt` and sums the game's own
glyph widths from `src/fonts.c`, then compares against the width of the window
template that actually draws that text:

| Text | Box | Source |
| --- | --- | --- |
| bag item description | 109 px × 3 lines | `WIN_DESCRIPTION` w=14 at x=3, `FONT_NORMAL` |
| ability description | 144 px, single line | `PSS_LABEL_PANE_RIGHT` w=19 at x=8 |
| battle message | 208 px | `B_WIN_MSG` w=26 |
| overworld / UI msgbox | 208 px | standard text box w=26 |
| 4-line move description | 110 px × 4 lines | `PSS_LABEL_PANE_LEFT_MOVE` w=14 at x=2 (summary screen) |
| 2-line move description | 128 px, `FONT_NARROW` | Move Relearner window 0, w=16 |

`move_descriptions.h` mixes both kinds of description, so they are matched by
symbol name (`sMoveFourLineDescription_*` vs `s*Description`). Some English
expansion-move descriptions already overflow these windows; a move description
only fails when it is over the limit **and** wider than its English source.

Useful invocations:

```sh
python3 translation/audit_box_widths.py -v              # every overflowing string
python3 translation/audit_box_widths.py dump over.json  # JSON, for scripted re-wrapping
```

### How widths are measured

- Glyph widths come from `src/fonts.c`, bytes from `charmap.txt`. The escaped
  `'\''` entry is parsed, so the apostrophe counts its real 3 px (it used to
  count 0, under-measuring every elision).
- Control codes (`{COLOR}`, `{PAUSE}`, `{CLEAR_TO}`…) take no space.
- Placeholders are replaced by representative text before measuring
  (`width_audit.PLACEHOLDER_TEXT`): a 7-letter name for `{PLAYER}` and trainer
  names, `Bulbasaur` for `{STR_VAR_n}` and Pokémon names, `Bulbasaur salvatge`
  for `{B_*_NAME_WITH_PREFIX}`, `Llançaflames` for moves, `Superpoció` for
  items, `Intimidació` for abilities.
- `battle_message.c`, `strings.c` and the move descriptions use a **relative**
  rule: a string fails only when it is over its limit *and* wider than its
  English source measured the same way. Long names overflow some English
  sentences too; that is the engine's limit, not a translation defect.

### Current state

All three scripts pass: `TOTAL OVER ARRAY LIMIT: 0`, `TOTAL OVERFLOWING: 0`, and
no script line over 216 px.

Getting there meant shortening 181 bag descriptions, 165 ability descriptions and
4 UI strings. Two things are worth knowing before editing this text again:

- **The ability pane cannot wrap.** It is a single 144px line, so an ability
  description can only be made to fit by shortening it. The English descriptions
  are themselves telegraphic — median 127px, max 145px — so the Catalan has to be
  about 26 characters. That is the budget, not a stylistic choice.
- **Bag descriptions have 3 lines of 109px.** 109px is roughly 19 characters, so
  a 3-line description holds about 57. Re-wrapping alone fixed only 36 of the
  181; the rest needed the words shortened too.

### Conventions adopted to fit

Applied consistently rather than per-string, so the same idea reads the same way
everywhere. Also recorded in [`glossary_ca.md`](glossary_ca.md).

| Long form | Short form |
| --- | --- |
| `estadística` / `estadístiques` | `estad.` |
| `Augmenta la X` | `Puja la X` |
| `Redueix la X` | `Baixa la X` |
| `Velocitat` / `Defensa` | `Vel.` / `Def.` |
| `augmenta la potència dels moviments X` | `potencia els moviments X` |
| `en un moment crític` | `en perill` |
| `en fer contacte` | `al contacte` |
| `Objecte retingut que …` | `Objecte retingut: …` |

## `audit_script_widths.py` — script dialogue

Most of the game's text is in map scripts (`data/maps/*/scripts.inc`) and the
shared `data/text/*.inc` / `data/scripts/*.inc` files, all drawn in the standard
overworld message box. `audit_box_widths.py` does not look at them; this does.

- Box: `sStandardTextBox_WindowTemplates` is 27 tiles = **216 px**. Lines over
  216 px are overflows and fail the check. 209–216 px is reported as *tight*
  (renders, but leaves no margin); 208 px is the target, same as battle text.
- Every `$`-terminated message is split on `\n`, `\l` and `\p`; each rendered
  line is measured.
- Placeholders are measured with representative text: `{PLAYER}`/`{RIVAL}` as a
  7-letter name, `{STR_VAR_n}` as a 9-letter species name.
- The Battle Dome tourney-info strings (`BattleDome_Text_Potential*`,
  `…Style*`, `…TrainerWon*`) are drawn in their own window and are skipped.

```sh
python3 translation/audit_script_widths.py -v                     # every line over 208 px
python3 translation/audit_script_widths.py -v data/maps/Route1    # one map, or any path
```

### Windows checked by hand

Text the audits cannot attribute to a window was measured against the window
template that draws it:

| Text | Window | Limit |
| --- | --- | --- |
| contest messages during a contest | `WIN_GENERAL_TEXT`, 17 tiles | 136 px |
| Battle Dome info card (potential, style, win lines) | `sInfoCardWindowTemplates`, 26 tiles | 208 px, 1 line |
| Lounge 7 move-tutor descriptions | 12 tiles | 96 px × 3 lines |
| decoration descriptions | 13 tiles | 104 px × 3 lines |
| characteristics (summary memo) | | 144 px |
| berry descriptions | | 200 px |
| PokéGear trainer-list lines (`match_call_messages.h`) | narrow font | 143 px (English max) |
| met locations in the summary memo | | 137 px |
| gift ribbon descriptions | | 122 px |
| easy-chat words | 13-tile word columns | 96 px |
| Pokédex categories | `char[12]`, x=100 | 11 bytes, 110 px |
| type names (`gTypeNames`) | battle move-type window | 6 bytes, ~34 px |
| easy-chat footer options | 28 tiles | 224 px incl. 8 px cursor each |

### Known limitations

- **Battle move names** are printed in `FONT_NARROW` in 8-tile (64 px) windows
  whose right edge is the menu frame, so the windows cannot be widened. 154
  Catalan names are wider than 64 px; `MoveSelectionDisplayMoveNames` draws
  those with `BattleSetTextCondensed()` (each glyph 1 px closer, spaces kept),
  which fits every name (the widest, Psicopotenciador, becomes 62 px). The
  action menu uses the same for "Motxilla", which is 2 px wider than its
  column. Checked on screen in mGBA.
- **Type names** are limited to 6 bytes (`TYPE_NAME_LENGTH`), hence the
  abbreviations Insec., Fant., Elèc., Psíq.
- **Region-map popup** is 80 px in the narrow font; "Ciutat EverGrande"
  (Hoenn, unused here) is 82 px.
- **Easy-chat word order** (`easy_chat_words_by_letter.h`) is still sorted by
  the English words.

## Text inside graphics — `translation/gfx/`

Some English is pixel art, not text. Each image was redrawn by a small script
that reuses the image's own letters where it has them, so the style matches.
They are one-shot transforms of the **English originals**: to redo one, check
out the original files from `origin/main` and run the scripts in this order
(`ROOT` is the repo root, or a copy of it).

| Script | Images | Change |
| --- | --- | --- |
| `make_badges.py` | `graphics/types/*.png` | type and contest badges: NORMAL, LLUITA, VOLANT, VERÍ, TERRA, ROCA, INSEC., FANT., ACER, FOC, AIGUA, PLANTA, ELÈC., PSÍQ., GEL, DRAC, FOSC, FADA; FRESC., BELL., TEND., INTEL., FORÇA |
| `make_lv.py ROOT` | `graphics/fonts/latin_*.png` | `{LV}` (0x34) and `{LV_2}` (0x105) glyphs: Lv → Nv. Widths in `src/fonts.c` grow by 0–2 px (normal 0x34 9→11, small 8→9, narrow 8→10) |
| `make_no.py ROOT` | `graphics/fonts/latin_*.png` | `{NO}` (0x108): No → № (numero sign, same cell width) |
| `make_ps.py ROOT A` | party menu `bg.png`, battle `hpbar.png`, summary `hp_bar.png` | HP bar label: HP → PS |
| `make_press_start.py ROOT` | `graphics/title_screen/press_start.png` | PRESS START → PREM START (the M is the one from GAMEFREAK). The copyright line stays |
| `make_naming.py ROOT c` | naming screen `roptions.png`, `rwindow.png` | page tabs MAJ. / min. / altres; buttons SUPR, FET; BOTÓ B. SELECT and START are button names |
| `make_status.py ROOT` | `interface/status_icons.png`, `battle_interface/status*.png` | status icons ENV, PAR, ADO, GEL, CRE, DES (PKRS stays). The grayscale opponent sheets are written back as 4-bit indexed (gbagfx maps gray g to index 15 − g) |
| `make_pokedex.py ROOT` | `pokedex/menu.png`, `search_menu.png`, `interface.png`, `area_unknown.png` | tabs ZONA / CRIT / MIDA / TORNAR; list menu A LA LLISTA, INICI LLISTA, FINAL LLISTA, A LA POKéDEX, TANCAR POKéDEX; search buttons CERCAR, CANVI, TORNAR, NOM, COLOR, TIPUS, ORDRE, MODE, FET; sidebar VISTOS, CAPTURATS, KANTO, NACIONAL, CERCAR, MENÚ; ZONA DESCONEGUDA |
| `make_storage.py ROOT` | `pokemon_storage/menu.png` | DADES PKMN, EQUIP POKéMON, TORNAR, SORTIR |
| `make_trainer_card.py ROOT` | `trainer_card/card.png` | TARGETA D'ENTRENADOR (in tiles 128-138: tile 139 is both end caps), MEDALLES |
| `make_bag_shop.py ROOT` | `bag/hm.png`, `shop/money.png`, `bag/check_berry.png` | MO, DINERS, flavours PICANT · SEC · DOLÇ · AMARG · ÀCID |
| `make_menu_info.py ROOT` | `interface/menu_info.png` | move-info type icons (same labels as the badges); TIPUS, POTÈNCIA, PRECISIÓ, PP, EFECTE |

`tiles.py` holds what the scripts share: tilemap usage (a label may only be
redrawn in tiles nothing else shows), views that put sprite or tilemap tiles
back in screen order, the game fonts, and `LearnedLabel`/`relabel`, which only
draw once the English label has been re-rendered pixel for pixel. Labels that
are still English on purpose: the copyright line, button names (SELECT, START,
A, B, L, R), EXP, PP, ID, and `trainer_card/card_fr.png` (only drawn for a
linked FireRed/LeafGreen player).

Running all of them on the `origin/main` files reproduces the committed images
byte for byte. EXP (healthbox) is kept: it reads the same in Catalan.

Layout fixes that came out of checking these screens in mGBA: the summary
skills page prints "Habilitat" in `FONT_NARROW` (48 px in the normal font ran
into the ability box at x=51); `PrintSummaryMoveName` switches long move names
to `FONT_NARROW` (Psicopotenciador was cut at the window edge); the berry tag
prints its size and firmness values after the longer label (they overlapped
"Fermesa /"), shows the size in centimetres under `UNITS_METRIC`, and its 64 px
title says "Etiqueta".

### Known limitation of the audit

The 208px limit used for `src/strings.c` is the standard overworld msgbox. A few
strings live in narrower windows — `gText_PressAToLoadEvent`, for instance, is
drawn in a 22-tile window (175px) in `mystery_event_menu.c`. The audit will not
catch a string that fits 208px but overflows its own narrower window, so check
the window template when touching menu-specific text.

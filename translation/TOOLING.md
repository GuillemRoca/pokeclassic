# Catalan translation — verification tooling

Three checks that catch the failure modes a translation of this size runs into.
The width audits compare only against strings this branch actually changed, so
untouched English text is never reported. Run them from the repo root.

```sh
python3 translation/check_name_limits.py     # build-breaking: names vs array bounds
python3 translation/audit_box_widths.py      # cosmetic: C strings vs their window
python3 translation/audit_script_widths.py   # cosmetic: script dialogue vs message box
```

All three exit non-zero when something is wrong, so they can be wired into CI.

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

### Current state

Both scripts pass: `TOTAL OVER ARRAY LIMIT: 0` and `TOTAL OVERFLOWING: 0`.

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

### Known limitation of the audit

The 208px limit used for `src/strings.c` is the standard overworld msgbox. A few
strings live in narrower windows — `gText_PressAToLoadEvent`, for instance, is
drawn in a 22-tile window (175px) in `mystery_event_menu.c`. The audit will not
catch a string that fits 208px but overflows its own narrower window, so check
the window template when touching menu-specific text.

#!/usr/bin/env python3
"""Check fixed-size name tables against their C array bounds.

Names live in `const u8 x[COUNT][LEN + 1]` tables, so a translation that is one
character too long is an `excess elements in array initializer` build failure,
not a cosmetic problem. Lengths are counted in *encoded bytes* (charmap.txt), so
`l·l` and accented glyphs count as the single bytes the ROM actually stores.

Limits below reflect this branch's config:
  B_EXPANDED_MOVE_NAMES    TRUE  -> MOVE_NAME_LENGTH    16
  B_EXPANDED_ABILITY_NAMES TRUE  -> ABILITY_NAME_LENGTH 16
  item name is `u8 name[ITEM_NAME_LENGTH]` = name[14] *including* the 0xFF
  terminator, so the usable limit is 13, not 14.

Move names are also checked in pixels against the two places that draw them
in a fixed slot, using the same font choice the code makes:
  summary move list   x=64 in a 152px window -> 88px; FONT_NORMAL, or
                      FONT_NARROW when wider (PrintSummaryMoveName)
  battle move menu    64px; FONT_NARROW, condensed by 1px per glyph when wider
                      (BattleSetTextCondensed in battle_controller_player.c)

Usage:
    python3 translation/check_name_limits.py     # exits 1 if anything is over
"""
import os, re, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from width_audit import encode, line_widths, W_NORMAL, W_NARROW, ROOT


def entries(text):
    """(designator, string) for each `[X] = _("...")` initializer."""
    out = []
    for m in re.finditer(r'\[([A-Z0-9_]+)\]\s*=\s*_\(\s*((?:"(?:[^"\\]|\\.)*"\s*)+)\)', text):
        out.append((m.group(1), ''.join(re.findall(r'"((?:[^"\\]|\\.)*)"', m.group(2)))))
    return out


def active_move_names(text):
    # only the B_EXPANDED_MOVE_NAMES == TRUE block is compiled
    return text.split('#else')[0]


def active_ability_names(text):
    # gAbilityNames: the first block is B_EXPANDED_ABILITY_NAMES == TRUE
    return text[text.index('gAbilityNames'):].split('#else')[0]


CHECKS = [
    ('src/data/text/move_names.h',          16, 'move name',     active_move_names),
    ('src/data/text/abilities.h',           16, 'ability name',  active_ability_names),
    ('src/data/text/trainer_class_names.h', 12, 'trainer class', None),
]

total = 0
print(f'{"table":18s} {"limit":>5s} {"entries":>7s} {"over":>4s}')
for path, limit, label, slicer in CHECKS:
    text = open(f'{ROOT}/{path}', encoding='utf-8').read()
    if slicer:
        text = slicer(text)
    rows = entries(text)
    bad = [(n, s, len(encode(s))) for n, s in rows if len(encode(s)) > limit]
    total += len(bad)
    print(f'{label:18s} {limit:5d} {len(rows):7d} {len(bad):4d}')
    for n, s, ln in sorted(bad, key=lambda x: -x[2]):
        print(f'      {ln:3d}  {n:28s} {s!r}')

# item names are `.name = _("...")` inside struct initializers
text = open(f'{ROOT}/src/data/items.h', encoding='utf-8').read()
items = [''.join(re.findall(r'"((?:[^"\\]|\\.)*)"', m.group(1)))
         for m in re.finditer(r'\.name\s*=\s*_\(\s*((?:"(?:[^"\\]|\\.)*"\s*)+)\)', text)]
bad = [(s, len(encode(s))) for s in items if len(encode(s)) > 13]
total += len(bad)
print(f'{"item name":18s} {13:5d} {len(items):7d} {len(bad):4d}')
for s, ln in sorted(bad, key=lambda x: -x[1]):
    print(f'      {ln:3d}  {s!r}')

print(f'\nTOTAL OVER ARRAY LIMIT: {total}')


def condensed_width(name):
    """Narrow-font extent with the condensed rule of gflib/text.c RenderText:
    every glyph wider than 1px except spaces advances 1px less."""
    codes = encode(name, for_width=True)
    ws = [W_NARROW[c] if c < len(W_NARROW) else 0 for c in codes]
    shrink = sum(1 for c, w in zip(codes, ws) if c != 0x00 and w > 1)
    return sum(ws) - max(0, shrink - 1)


moves = entries(active_move_names(open(f'{ROOT}/src/data/text/move_names.h', encoding='utf-8').read()))
px_bad = []
for n, name in moves:
    normal, narrow = line_widths(name, W_NORMAL)[0], line_widths(name, W_NARROW)[0]
    summary = normal if normal <= 88 else narrow
    battle = narrow if narrow <= 64 else condensed_width(name)
    if summary > 88:
        px_bad.append((n, name, f'summary {summary}px > 88'))
    if battle > 64:
        px_bad.append((n, name, f'battle {battle}px > 64'))
print(f'move name pixels: {len(moves)} names, {len(px_bad)} over their slot')
for n, name, why in px_bad:
    print(f'      {n:28s} {name!r}  {why}')
total += len(px_bad)
sys.exit(1 if total else 0)

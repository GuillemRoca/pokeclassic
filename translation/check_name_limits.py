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

Usage:
    python3 translation/check_name_limits.py     # exits 1 if anything is over
"""
import os, re, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from width_audit import encode, ROOT


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
sys.exit(1 if total else 0)

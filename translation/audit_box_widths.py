#!/usr/bin/env python3
"""Pixel-width audit against the REAL window widths and fonts.

Limits derived from the window templates that draw each kind of text:
  bag item description  WIN_DESCRIPTION w=14 (112px), x=3, FONT_NORMAL -> 109
  ability description   PSS_LABEL_PANE_RIGHT w=19 (152px), x=8, FONT_NORMAL -> 144
  battle message        B_WIN_MSG w=26 (208px), FONT_NORMAL -> 208
  overworld/UI msgbox   standard text box w=26 (208px), FONT_NORMAL -> 208

Only strings this branch actually changed are checked, so untouched English text
never shows up as a failure.

Usage:
    python3 translation/audit_box_widths.py            # summary, exits 1 if any overflow
    python3 translation/audit_box_widths.py -v         # list every overflowing string
    python3 translation/audit_box_widths.py dump FILE  # write JSON for scripted fixing
"""
import sys, os, json
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from width_audit import blocks, orig, line_widths, W_NORMAL, ROOT

CFG = [
    ('src/data/text/item_descriptions.h', 109, W_NORMAL, False, 'bag description'),
    ('src/data/text/abilities.h',         144, W_NORMAL, False, 'ability description'),
    ('src/battle_message.c',              208, W_NORMAL, False, 'battle message'),
    ('src/strings.c',                     208, W_NORMAL, False, 'UI / msgbox'),
]

def audit(report=True):
    out = {}
    for path, limit, widths, asm, label in CFG:
        new = blocks(open(f'{ROOT}/{path}', encoding='utf-8', errors='replace').read(), asm)
        old = blocks(orig(path), asm)
        over = []
        for a, b in zip(old, new):
            if a == b:
                continue
            w = max(line_widths(b, widths))
            if w > limit:
                over.append((w, b))
        over.sort(reverse=True)
        out[path] = (limit, label, over)
        if report:
            print(f'{path:38s} limit {limit:3d}px  {label:20s} overflowing: {len(over)}')
    return out

if __name__ == '__main__':
    args = sys.argv[1:]
    res = audit()
    total = sum(len(v[2]) for v in res.values())
    print(f'\nTOTAL OVERFLOWING: {total}')

    if args and args[0] == '-v':
        for path, (limit, label, over) in res.items():
            if not over:
                continue
            print(f'\n== {path}  (limit {limit}px, {label}) ==')
            for w, s in over:
                print(f'  {w:4d}px  {s!r}')
    elif args and args[0] == 'dump':
        dest = args[1] if len(args) > 1 else 'box_overflow.json'
        json.dump({p: [[w, s] for w, s in v[2]] for p, v in res.items()},
                  open(dest, 'w', encoding='utf-8'), ensure_ascii=False, indent=0)
        print(f'dumped -> {dest}')

    sys.exit(1 if total else 0)

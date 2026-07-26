#!/usr/bin/env python3
"""Pixel-width audit against the REAL window widths and fonts.

Limits derived from the source:
  bag item description  WIN_DESCRIPTION w=14 (112px), x=3, FONT_NORMAL -> 109
  ability description   PSS_LABEL_PANE_RIGHT w=19 (152px), x=8, FONT_NORMAL -> 144
  battle message        B_WIN_MSG w=26 (208px), FONT_NORMAL -> 208
  overworld/UI msgbox   standard text box w=26 (208px), FONT_NORMAL -> 208
"""
import sys, os, re, subprocess, json
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
    res = audit()
    total = sum(len(v[2]) for v in res.values())
    print(f'\nTOTAL OVERFLOWING: {total}')
    if len(sys.argv) > 1 and sys.argv[1] == 'dump':
        d = {p: [[w, s] for w, s in v[2]] for p, v in res.items()}
        json.dump(d, open('/tmp/claude-0/-home-user-pokeclassic/8e2ee461-919c-52c5-9360-6e8cdd19d60f/scratchpad/over.json','w'),
                  ensure_ascii=False, indent=0)
        print('dumped -> over.json')

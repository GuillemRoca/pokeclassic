#!/usr/bin/env python3
"""Redraw the 'HP' labels as 'PS' (punts de salut) in the party menu, battle and
summary HP bars. Each label keeps its per-row letter colour and background."""
import sys
from PIL import Image
ROOT = sys.argv[1]
S_VARIANT = sys.argv[2] if len(sys.argv) > 2 else 'A'
S4 = {'A': ['#####', '###..', '..###', '#####'], 'B': ['.####', '###..', '..###', '####.']}

def relabel(path, x0, y0, mask, bg_col):
    im = Image.open(path); px = im.load()
    h = len(mask)
    # letter colour per row: any non-background pixel in the old label row
    old_rows = []
    for r in range(h):
        bg = px[bg_col, y0 + r]
        cols = [px[x0 + c, y0 + r] for c in range(len(mask[0])) if px[x0 + c, y0 + r] != bg]
        old_rows.append((bg, max(set(cols), key=cols.count)))
    for r, row in enumerate(mask):
        bg, fg = old_rows[r]
        for c, ch in enumerate(row):
            px[x0 + c, y0 + r] = fg if ch == '#' else bg
    im.save(path)

# party menu: 5-row label, two copies, gap column between letters at +5
PARTY = ['#####.#####',
         '##..#.##...',
         '#####.#####',
         '##....#####'[:0] + '##.......##',
         '##....#####']
for x, y in ((35, 49), (27, 58)):
    relabel(f'{ROOT}/graphics/party_menu/bg.png', x, y, PARTY, x + 5)
# battle healthbox 'HP' tiles: 4 rows at y=2, letters at x=11..21, gap x=16
s = S4[S_VARIANT]
BATTLE = ['#####.' + s[0], '###.#.' + s[1], '#####.' + s[2], '###...' + s[3]]
relabel(f'{ROOT}/graphics/battle_interface/hpbar.png', 11, 2, BATTLE, 16)
# summary screen bar: 4 rows at y=1, letters at x=76..84, gap x=80
s2 = {'A': ['####', '##..', '..##', '####'], 'B': ['.###', '##..', '..##', '###.']}[S_VARIANT]
SUMMARY = ['####.' + s2[0], '##.#.' + s2[1], '####.' + s2[2], '##...' + s2[3]]
relabel(f'{ROOT}/graphics/summary_screen/hp_bar.png', 76, 1, SUMMARY, 80)

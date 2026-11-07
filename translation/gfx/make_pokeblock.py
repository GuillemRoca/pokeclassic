#!/usr/bin/env python3
"""Pokéblock screens in Catalan.

pokeblock/menu.png              FEEL      -> SUAV. (suavitat; FONT_NORMAL, as the English)
pokeblock/use_screen/condition  CONDITION -> CONDICIÓ (header, as the PokéGear's)
pokeblock/use_screen/updown     UP / DOWN -> PUJA / BAIXA (two 32x16 frames; FONT_NARROW
                                emboldened by one pixel like the English, outlined)
The feeding screen's graph is done by make_condition_graph.py."""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from tiles import Sheet, Font, TileGridView, ViewSheet, StripView, relabel, bar_label, font_masks
ROOT = sys.argv[1]
D = f'{ROOT}/graphics/pokeblock'

sh = Sheet(f'{D}/menu.png')
v = TileGridView(sh, [[25, 26, 27, 28, 29], [33, 34, 35, 36, 37]])   # menu.bin rows 17-18
print('menu   FEEL -> SUAV.', relabel(ViewSheet(v, 'menu'), (8, 0, 39, 15), 'FEEL', 'SUAV.', Font('normal'), 9, 0xB, 3))
sh.save()

sh = Sheet(f'{D}/use_screen/condition.png')
print('header CONDICIÓ', bar_label(StripView(sh, 64, 32, 2), (2, 2, 85, 21), 'CONDICIÓ'))
sh.save()

N8 = [(dx, dy) for dx in (-1, 0, 1) for dy in (-1, 0, 1) if dx or dy]
sh = Sheet(f'{D}/use_screen/updown.png'); px = sh.px
NARROW = Font('narrow')
for frame, text, edge in ((0, 'PUJA', 2), (1, 'BAIXA', 3)):
    y0 = frame * 16
    for y in range(y0, y0 + 16):
        for x in range(32):
            px[x, y] = 0
    masks, _ = font_masks(NARROW, text)
    ink = set()
    x = 0
    for c in text:
        dy, rows, gw = masks[c]
        for r, row in enumerate(rows):
            for k, ch in enumerate(row):
                if ch == '#':
                    ink.add((x + k, dy + r)); ink.add((x + k + 1, dy + r))   # 2 px strokes
        x += gw + 1
    w = max(qx for qx, _ in ink) + 1
    h = max(qy for _, qy in ink) + 1
    ox, oy = (32 - w) // 2, y0 + (16 - h) // 2
    ink = {(qx + ox, qy + oy) for qx, qy in ink}
    assert all(1 <= qx <= 30 for qx, _ in ink), (text, w)
    for (qx, qy) in ink:
        for dx, dy in N8:
            if (qx + dx, qy + dy) not in ink:
                px[qx + dx, qy + dy] = edge
    for q in ink:
        px[q] = 1
    print(f'updown {text:5s} {w}px')
sh.save()

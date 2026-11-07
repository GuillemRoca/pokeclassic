#!/usr/bin/env python3
"""Pokédex labels drawn in graphics, in Catalan (same words as the Pokédex text).

menu.png (FONT_NORMAL glyphs, matched pixel for pixel against the English):
  tabs   AREA / CRY / SIZE      -> ZONA / CRIT / MIDA   (no room for the accent of ÀREA)
  CANCEL (both buttons)         -> TORNAR
  list menu (9 tiles = 72 px, last two 11 tiles = 88 px):
    BACK TO LIST -> A LA LLISTA, LIST TOP -> INICI LLISTA, LIST BOTTOM -> FINAL LLISTA,
    BACK TO POKéDEX -> A LA POKéDEX, CLOSE POKéDEX -> TANCAR POKéDEX
Each box is limited to the tiles only that label uses (see tiles.usage).
"""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from tiles import Sheet, Font, relabel
ROOT = sys.argv[1]
F = Font('normal')

sh = Sheet(f'{ROOT}/graphics/pokedex/menu.png')
for box, old, new, ink, shadow, bg, align, w in [
    ((16, 18, 39, 31), 'AREA', 'ZONA', 0xF, 0xD, 0xC, 'center', 24),
    ((48, 18, 87, 31), 'CRY', 'CRIT', 0xF, 0xD, 0xC, 'center', 40),
    ((88, 18, 127, 31), 'SIZE', 'MIDA', 0xF, 0xD, 0xC, 'center', 40),
    ((16, 34, 55, 47), 'CANCEL', 'TORNAR', 9, 5, 7, 'left', None),
    ((64, 34, 103, 47), 'CANCEL', 'TORNAR', 0xF, 2, 0xB, 'left', None),
    ((0, 48, 71, 63), 'BACK TO LIST', 'A LA LLISTA', 9, 5, 0xD, 'left', None),
    ((0, 64, 71, 79), 'LIST TOP', 'INICI LLISTA', 9, 5, 0xD, 'left', None),
    ((0, 80, 71, 95), 'LIST BOTTOM', 'FINAL LLISTA', 9, 5, 0xD, 'left', None),
    ((0, 96, 87, 111), 'BACK TO POKéDEX', 'A LA POKéDEX', 9, 5, 0xD, 'left', None),
    ((0, 112, 87, 127), 'CLOSE POKéDEX', 'TANCAR POKéDEX', 9, 5, 0xD, 'left', None),
]:
    print(f'menu   {old:16s} -> {new:16s} {relabel(sh, box, old, new, F, ink, shadow, bg, align, w)}px')
sh.save()

# search_menu.png: the buttons' own 7-row font (5 px letters, 4 px for 6-letter words)
from tiles import learn_glyphs, compose, text_width, paint, check_rule
sh = Sheet(f'{ROOT}/graphics/pokedex/search_menu.png'); px = sh.px
BUTTONS = [  # box (inside the plate), English, Catalan, ink, shadow, plate colour
    ((4, 19, 35, 28), 'MODE', 'MODE', 4, 0xB, 0xA),
    ((44, 19, 75, 28), 'ORDER', 'ORDRE', 4, 0xB, 0xA),
    ((84, 19, 115, 28), 'NAME', 'NOM', 4, 0xB, 0xA),
    ((4, 35, 35, 44), 'COLOR', 'COLOR', 4, 0xB, 0xA),
    ((44, 35, 75, 44), 'TYPE', 'TIPUS', 4, 0xB, 0xA),
    ((84, 35, 115, 44), 'CANCEL', 'TORNAR', 4, 9, 8),
    ((4, 51, 35, 60), 'OK', 'FET', 4, 9, 8),
    ((44, 51, 75, 60), 'SHIFT', 'CANVI', 4, 9, 8),
    ((84, 51, 115, 60), 'SEARCH', 'CERCAR', 4, 9, 8),
]
wide, narrow = {}, {}
for box, old, new, ink, shadow, bg in BUTTONS:
    assert check_rule(px, box, ink, shadow, bg) == 'rd', old
    g, _, _, _ = learn_glyphs(px, box, ink, old)
    for c, m in g.items():
        (narrow if len(m[0]) == 4 and len(old) == 6 else wide).setdefault(c, m)
wide.update({'V': ['#...#', '#...#', '#...#', '#...#', '.#.#.', '.#.#.', '..#..'],
             'U': ['#...#'] * 6 + ['.###.']})
narrow.update({'T': ['###', '.#.', '.#.', '.#.', '.#.', '.#.', '.#.'],
               'O': ['.##.', '#..#', '#..#', '#..#', '#..#', '#..#', '.##.']})
for box, old, new, ink, shadow, bg in BUTTONS:
    glyphs = narrow if len(new) == 6 else wide
    w = text_width(glyphs, new)
    x = (box[0] + box[2] + 1 - w) // 2
    top = box[1] + 1
    paint(px, box, compose(glyphs, new, x, top), ink, shadow, bg, 'rd')
    print(f'search {old:16s} -> {new:16s} {w}px')
sh.save()

# interface.png: list-screen sidebar sprites (1D-mapped, see tiles.SpriteView)
from tiles import SpriteView, ViewSheet, draw_text
sh = Sheet(f'{ROOT}/graphics/pokedex/interface.png')
def view(first, wt, ht, name):
    return ViewSheet(SpriteView(sh, first, wt, ht), name)
# hint under the SELECT / START buttons, and the Kanto dex title (fonts matched exactly)
for (first, wt, ht), old, new, font in [((40, 4, 2), 'SEARCH', 'CERCAR', 'narrow'),
                                        ((56, 4, 2), 'MENU', 'MENÚ', 'normal'),
                                        ((160, 4, 2), 'HOENN', 'KANTO', 'small')]:
    w = relabel(view(first, wt, ht, old), (0, 0, wt * 8 - 1, 15), old, new, Font(font), 1, 0xF, 0,
                align='center', width=wt * 8)
    print(f'side   {old:16s} -> {new:16s} {w}px')
# NATIONAL: its own 3 px letters (it is 32 px; FONT_SMALL would be 37); C drawn to match
v = SpriteView(sh, 168, 4, 2)
g, _, top, _ = learn_glyphs(v, (0, 3, 31, 12), 1, 'NATIONAL')
g['C'] = ['.##', '#..', '#..', '#..', '#..', '#..', '.##']
w = text_width(g, 'NACIONAL')
paint(v, (0, 3, 31, 12), compose(g, 'NACIONAL', (32 - w) // 2, top), 1, 0xF, 0, 'rd')
print(f'side   {"NATIONAL":16s} -> {"NACIONAL":16s} {w}px')
# SEEN / OWN above the counters (64x32 sprites, underline kept): FONT_SMALL (7-row caps
# like the English, and the font of KANTO beside it), centred on the underline
N = Font('small')
for first, old, new in [(64, 'SEEN', 'VISTOS'), (96, 'OWN', 'CAPTURATS')]:
    v = SpriteView(sh, first, 8, 4)
    for y in range(0, 14):
        for x in range(64):
            if v[x, y] in (1, 0xF):
                v[x, y] = 0
    w = N.width(new)
    draw_text(v, N, new, 32 - w // 2, 6 - 4, {1: 1, 2: 0xF})   # ink rows 6-12, shadow 13, underline 14
    print(f'side   {old:16s} -> {new:16s} {w}px')
sh.save()

# area_unknown.png: three 32x32 sprites side by side (x = 160, 192, 224).
# 'ZONA DESCONEGUDA' (as the ZONA tab) is 78 px in FONT_NARROW; the 76 px box is
# widened by moving its right edge 6 px into the transparent end of the last piece.
from tiles import StripView
sh = Sheet(f'{ROOT}/graphics/pokedex/area_unknown.png')
v = StripView(sh, 32, 32, 3)
K, EDGE = 6, 82                       # frame columns 82..86 move to 88..92
for y in range(32):
    for x in range(95, EDGE + K - 1, -1):
        v[x, y] = v[x - K, y]
    for x in range(EDGE, EDGE + K):
        v[x, y] = v[EDGE - 1, y]      # interior column (border rows and fill)
for y in range(6, 26):
    for x in range(6, EDGE + K):
        if v[x, y] in (1, 2):
            v[x, y] = 0xA
N = Font('narrow')
w = N.width('ZONA DESCONEGUDA')
draw_text(v, N, 'ZONA DESCONEGUDA', 6 + (EDGE + K - 6 - w) // 2, 8, {1: 1, 2: 2})
print(f'area   {"AREA UNKNOWN":16s} -> {"ZONA DESCONEGUDA":16s} {w}px')
sh.save()

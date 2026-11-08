#!/usr/bin/env python3
"""Slot machine (Celadon Game Corner) labels in Catalan: graphics/slot_machine/menu.png,
shown through menu.bin and info_box.bin.

plates      CREDIT -> CRÈDIT, PAYOUT -> PREMI           (their 3x5 font)
bottom bar  QUIT -> SURT (SORTIR needs 35 of 32 px), CANCEL -> TORNAR; INFO. stays
pay table   BIG BONUS -> GRAN PREMI, REG BONUS -> PETIT PREMI, REPLAY -> TIRADA (a free spin,
            also on the reel symbol),
            POWER -> PODER (the payout digits after it stay)
Letters are the labels' own; S, R, T, U, M, D drawn to match. BIG/REG BONUS
share their BONUS tiles, so the second row and the cells the longer words reach
take spare tiles (never 158-162, 175-178, 192-197: the code and the Reel Time
window use those)."""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from tiles import Sheet, ScreenEdit, LearnedLabel, compose, text_width, paint, load_map
ROOT = sys.argv[1]
D = f'{ROOT}/graphics/slot_machine'
sh = Sheet(f'{D}/menu.png')
menu_map, info_map = load_map(f'{D}/menu.bin'), load_map(f'{D}/info_box.bin')
M = ScreenEdit(sh, f'{D}/menu.bin', [], others={'info': info_map}).load(0, 0, 30, 20)

def put(view, box, glyphs, text, x, top, ink, shadow, bg, space=4):
    w = text_width(glyphs, text, space=space)
    paint(view, box, compose(glyphs, text, x, top, space=space), ink, shadow, bg, 'rd')
    return w

# plates (both maps show the same tiles)
g = dict(LearnedLabel(M, (178, 9, 206, 13), 'CREDIT', {3}, None, None).check().glyphs)
g.update(LearnedLabel(M, (209, 9, 237, 13), 'PAYOUT', {3}, None, None).check().glyphs)
g['M'] = ['#...#', '##.##', '#.#.#', '#...#', '#...#']
for y in range(8, 14):
    for x in range(178, 238):
        if M[x, y] == 3:
            M[x, y] = 0xF
x = 181
for c in 'CRÈDIT':
    cc = 'E' if c == 'È' else c
    for r, row in enumerate(g[cc]):
        for i, ch in enumerate(row):
            if ch == '#':
                M[x + i, 9 + r] = 3
    if c == 'È':
        M[x + 2, 8] = 3                                         # accent on the plate's top row
    x += len(g[cc][0]) + 1
w = text_width(g, 'PREMI')
x0 = 212 + (21 - w) // 2
for c in 'PREMI':
    for r, row in enumerate(g[c]):
        for i, ch in enumerate(row):
            if ch == '#':
                M[x0 + i, 9 + r] = 3
    x0 += len(g[c][0]) + 1
print('plates CRÈDIT, PREMI')

# the info box editor is made after the menu edits are in the sheet, so it
# does not write the old plates back
M.commit()
I = ScreenEdit(sh, f'{D}/info_box.bin', [234, 235, 236, 237, 238, 239, 253, 254, 255, 269, 270, 271],
               others={'menu': menu_map}).load(0, 0, 30, 20)

# bottom bars: 7-row letters (ink 3, shadow c on a)
L = LearnedLabel(I, (128, 149, 167, 156), 'CANCEL', {3}, 0xC, 'rd').check()
b = dict(L.glyphs)
b.update(LearnedLabel(M, (128, 149, 167, 156), 'INFO.', {3}, 0xC, 'rd').glyphs)
b.update({'R': ['####.', '#...#', '#...#', '####.', '#.#..', '#..#.', '#...#'],
          'S': ['.###.', '#...#', '#....', '.###.', '....#', '#...#', '.###.'],
          'T': ['#####', '..#..', '..#..', '..#..', '..#..', '..#..', '..#..'],
          'U': ['#...#', '#...#', '#...#', '#...#', '#...#', '#...#', '.###.']})
w = text_width(b, 'SURT')
put(I, (128, 149, 167, 156), b, 'TORNAR', L.start, 149, 3, 0xC, 0xA)
M2 = ScreenEdit(sh, f'{D}/menu.bin', [], others={'info': info_map}).load(24, 18, 4, 2)
put(M2, (192, 149, 223, 156), b, 'SURT', 192 + (32 - w) // 2, 149, 3, 0xC, 0xA)
print('bar    SURT, TORNAR')

# pay table: 5-row letters (ink 1, shadow f on e)
p = {}
for txt, box in [('REG BONUS', (184, 57, 225, 62)), ('REPLAY', (208, 113, 238, 118)), ('BIG BONUS', (184, 33, 225, 38))]:
    for c, m in LearnedLabel(I, box, txt, {1}, 0xF, 'rd').glyphs.items():
        p.setdefault(c, m)
p.update({'M': ['#...#', '##.##', '#.#.#', '#...#', '#...#'], 'T': ['###', '.#.', '.#.', '.#.', '.#.'],
          'I': ['#'] * 5, 'D': ['###.', '#..#', '#..#', '#..#', '###.']})
narrow = dict(LearnedLabel(I, (208, 121, 229, 126), 'POWER', {1}, 0xF, 'rd').glyphs)
narrow['D'] = ['##.', '#.#', '#.#', '#.#', '##.']
for box, glyphs, text, x, top in [((184, 33, 237, 38), p, 'GRAN PREMI', 185, 33),
                                  ((184, 57, 237, 62), p, 'PETIT PREMI', 185, 57),
                                  ((208, 113, 237, 118), p, 'TIRADA', 209, 113),
                                  ((208, 121, 228, 126), narrow, 'PODER', 209, 121)]:
    print(f'table  {text:12s} {put(I, box, glyphs, text, x, top, 1, 0xF, 0xE, space=3)}px')

print('spare tiles left', I.save())

# reel symbol 7 (the REPLAY symbol): TIRADA, a free spin, as in the pay table.
# White letters on the dark band; the grey shading pixels between the English
# letters (index 1) would fall inside the new word, so the text rows are cleared.
rs = Sheet(f'{D}/reel_symbols/7.png')
r = dict(LearnedLabel(rs.px, (4, 13, 27, 17), 'REPLAY', {3}, None, None).glyphs)
r.update({'T': ['###', '.#.', '.#.', '.#.', '.#.'], 'I': ['#'] * 5, 'D': ['##.', '#.#', '#.#', '#.#', '##.']})
w = text_width(r, 'TIRADA')
for y in range(13, 18):
    for x in range(4, 28):
        if rs.px[x, y] in (1, 3):
            rs.px[x, y] = 0xF
for (x, y) in compose(r, 'TIRADA', 4 + (24 - w) // 2, 13):
    rs.px[x, y] = 3
rs.save()
print(f'symbol TIRADA {w}px')      # writes the sheet and info_box.bin
M2.save()                                   # QUIT tiles are the menu's own; menu.bin is unchanged

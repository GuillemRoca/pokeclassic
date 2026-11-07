#!/usr/bin/env python3
"""Bag and shop labels in Catalan.

bag/hm.png      HM    -> MO      (Màquina Oculta, as the item names)
shop/money.png  MONEY -> DINERS  (as the trainer card's "Diners")
Both are the labels' own fonts, learnt from the English letters; the missing
letters are drawn to match."""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from tiles import Sheet, LearnedLabel
ROOT = sys.argv[1]

sh = Sheet(f'{ROOT}/graphics/bag/hm.png')
L = LearnedLabel(sh.px, (1, 4, 15, 11), 'HM', {0xF}, 0xB, 'rd',
                 extra={'O': ['.###.', '#...#', '#...#', '#...#', '.###.']}).check()
print('MO', L.write('MO', align='left'))
sh.save()

sh = Sheet(f'{ROOT}/graphics/shop/money.png')
L = LearnedLabel(sh.px, (1, 3, 31, 9), 'MONEY', {0xE, 0xC, 0xD}, 6, 'outline8',
                 bgfix={y: 0 for y in range(3, 10)},
                 extra={'D': ['###.', '#..#', '#..#', '#..#', '###.'],
                        'I': ['###', '.#.', '.#.', '.#.', '###'],
                        'R': ['###.', '#..#', '###.', '#.#.', '#..#'],
                        'S': ['.###', '#...', '.##.', '...#', '###.']})
for y in range(3, 10):        # the English has a few darker outline pixels (index 2)
    for x in range(1, 32):
        if sh.px[x, y] == 2:
            sh.px[x, y] = 6
print('DINERS', L.write('DINERS', x=2))
sh.save()

# bag/check_berry.png: flavour names under the berry tag circles, a 25-tile strip
# (tiles 39-63, berry_tag.bin row 12), in its own 7-row font. Same words as the
# text: Picant, Sec, Dolç, Amarg, Àcid. The strip is one tile high, so À is a
# 5-row A with a one-pixel grave above a free row, and the cedilla takes the
# shadow row.
from tiles import TileGridView, LearnedLabel as LL, paint
sh = Sheet(f'{ROOT}/graphics/bag/check_berry.png')
v = TileGridView(sh, [list(range(39, 64))])
L = LL(v, (0, 0, 199, 7), 'SPICY DRY SWEET BITTER SOUR', {0xB}, 8, 'rd')
g = dict(L.glyphs)
g.update({'A': ['.###.', '#...#', '#...#', '#####', '#...#', '#...#', '#...#'],
          'N': ['#...#', '##..#', '#.#.#', '#..##', '#...#', '#...#', '#...#'],
          'L': ['#....'] * 6 + ['#####'],
          'G': ['.###.', '#...#', '#....', '#.###', '#...#', '#...#', '.###.'],
          'M': ['#...#', '##.##', '#.#.#', '#...#', '#...#', '#...#', '#...#'],
          'À': ['.....', '.....', '.###.', '#...#', '#####', '#...#', '#...#'],   # + grave, below
          'Ç': g['C']})
ink, cedillas = set(), []
for word, centre in [('PICANT', 19), ('SEC', 59), ('DOLÇ', 99), ('AMARG', 139.5), ('ÀCID', 179)]:
    w = sum(len(g[c][0]) for c in word) + len(word) - 1
    x = round(centre - (w - 1) / 2)
    for c in word:
        for r, row in enumerate(g[c]):
            for k, ch in enumerate(row):
                if ch == '#':
                    ink.add((x + k, r))
        if c == 'Ç':
            cedillas.append((x + 2, 7))
        if c == 'À':
            cedillas.append((x + 1, 0))      # one ink pixel, no shadow, a free row under it
        x += len(g[c][0]) + 1
    print(f'berry  {word:6s} {w}px')
paint(v, (0, 0, 199, 7), ink, 0xB, 8, 3, 'rd')
for q in cedillas:
    v[q] = 0xB
sh.save()

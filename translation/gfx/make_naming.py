#!/usr/bin/env python3
"""Catalan labels for the naming screen graphics.

roptions.png  page tabs   UPPER / lower / others  ->  MAJ. / min. / altres
rwindow.png   buttons     BACK -> SUPR, OK -> FET, 'B BUTTON' -> 'BOTÓ B'
SELECT and START are button names and stay.
"""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from naming_lib import *
from PIL import Image
ROOT = sys.argv[1]
VARIANT = sys.argv[2] if len(sys.argv) > 2 else 'c'   # c: label one row lower so the Ó accent has a gap

MICRO = {  # 7 rows: caps rows 0-6, lowercase x-height rows 2-6
    'M': ['#...#', '##.##', '#.#.#', '#...#', '#...#', '#...#', '#...#'],
    'A': ['.##.', '#..#', '#..#', '####', '#..#', '#..#', '#..#'],
    'J': ['...#', '...#', '...#', '...#', '...#', '#..#', '.##.'],
    '.': ['.', '.', '.', '.', '.', '.', '#'],
    'm': ['.....', '.....', '#####', '#.#.#', '#.#.#', '#.#.#', '#.#.#'],
    'i': ['#', '.', '#', '#', '#', '#', '#'],
    'n': ['...', '...', '###', '#.#', '#.#', '#.#', '#.#'],
    'a': ['....', '....', '.##.', '...#', '.###', '#..#', '.###'],
    'l': ['#'] * 7,
    # t, r, e, s as in the original 'others'
    't': ['...', '.#.', '###', '.#.', '.#.', '.#.', '.##'],
    'r': ['...', '...', '#.#', '##.', '#..', '#..', '#..'],
    'e': ['....', '....', '.##.', '#..#', '####', '#...', '.###'],
    's': ['...', '...', '.##', '#..', '.#.', '..#', '##.'],
}
BIG = {  # 5x7, as B A C K O in the buttons
    'S': ['.###.', '#...#', '#....', '.###.', '....#', '#...#', '.###.'],
    'U': ['#...#'] * 6 + ['.###.'],
    'P': ['####.', '#...#', '#...#', '####.', '#....', '#....', '#....'],
    'R': ['####.', '#...#', '#...#', '####.', '#.#..', '#..#.', '#...#'],
    'F': ['#####', '#....', '#....', '####.', '#....', '#....', '#....'],
    'E': ['#####', '#....', '#....', '####.', '#....', '#....', '#####'],
    'T': ['#####', '..#..', '..#..', '..#..', '..#..', '..#..', '..#..'],
}
SMALL = {  # 3x5 white on the dark label plate
    'B': ['##.', '#.#', '##.', '#.#', '##.'],      # mid-tone pixel added below, as the original
    'O': ['###', '#.#', '#.#', '#.#', '###'],
    'T': ['###', '.#.', '.#.', '.#.', '.#.'],
}

# --- page tabs ---
p = f'{ROOT}/graphics/naming_screen/roptions.png'
im = Image.open(p); px = im.load()
for band, (text, bg, sh) in enumerate((('MAJ.', 7, 6), ('min.', 9, 8), ('altres', 11, 10))):
    w = width(MICRO, text) + 1                        # + shadow column
    ink = text_ink(MICRO, text, (24 - w) // 2, band * 8)
    for q, v in render_shadow(ink, (0, band * 8, 23, band * 8 + 7), 1, sh, bg).items():
        px[q] = v
im.save(p)

# --- buttons ---
p = f'{ROOT}/graphics/naming_screen/rwindow.png'
im = Image.open(p); px = im.load()
for text, x, ytop, box in (('SUPR', 9, 37, (7, 36, 32, 44)), ('FET', 20 - width(BIG, 'FET') // 2, 59, (7, 58, 32, 66))):
    ink = text_ink(BIG, text, x, ytop)
    for q, v in render_halo(ink, box, 1, 0xC, 0xD).items():
        px[q] = v
# 'BOTÓ' plate + the B key plate (copied) on the right
key = {(x - 3, y - 48): px[x, y] for x in range(3, 9) for y in range(48, 55)}
for y in range(47, 56):
    for x in range(3, 38):
        px[x, y] = 4
dy = 1 if VARIANT == 'c' else 0
tw = width(SMALL, 'BOTO') + 2
x0 = 20 - (tw + 1 + 6) // 2
ink = text_ink(SMALL, 'BOTO', x0 + 1, 49 + dy)
ox = x0 + 1 + 3 * 4                                    # the last O
ink.add((ox + 2, 48 + dy - (1 if VARIANT == 'c' else 0)))   # acute
keep = {(x0 + 1 + 2, 51 + dy): 3}                       # B's mid-tone, as the original
for q, v in render_halo(ink, (x0, 46 + dy, x0 + tw - 1, 55), 1, 0xF, 4, keep).items():
    if q[1] >= 47:
        px[q] = v
kx = x0 + tw + 1
for (dx, dyy), v in key.items():
    px[kx + dx, 48 + dy + dyy] = v
im.save(p)

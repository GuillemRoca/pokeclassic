#!/usr/bin/env python3
"""'PRESS START' -> 'PREM START' on the title screen banner (tiles 1-20 of
press_start.png, five 32x8 sprites). P, R, E and START come from the banner, the M
from 'GAMEFREAK' in the copyright banner (tiles 21-40), moved down one row to match.
The text keeps the original centre."""
import sys
from PIL import Image
path = sys.argv[1] + '/graphics/title_screen/press_start.png'
im = Image.open(path); px = im.load()
def at(first, p):
    t = first + p // 8
    return (t % 16) * 8 + p % 8, (t // 16) * 8
def strip(first):
    return [[px[at(first, p)[0], at(first, p)[1] + y] for y in range(8)] for p in range(160)]
start, copy = strip(1), strip(21)
cols = start[27:51]                                   # P R E
cols += [[0] + c[:7] for c in copy[64:74]]            # M, one row lower
cols += [[0] * 8] * 7                                 # word gap as before
cols += start[75:117]                                 # START
x0 = round((27 + 116) / 2 - (len(cols) - 1) / 2)
new = [[0] * 8 for _ in range(160)]
for i, c in enumerate(cols):
    new[x0 + i] = c
for p in range(160):
    tx, ty = at(1, p)
    for y in range(8):
        px[tx, ty + y] = new[p][y]
im.save(path)
print('text at', x0, '-', x0 + len(cols) - 1)

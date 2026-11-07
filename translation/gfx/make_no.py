#!/usr/bin/env python3
"""Redraw {NO} (0x108, 'No') as 'Nº' in every latin font: keep the N, replace the o
by a superscript ring with a bar under it. Same cell width as before."""
import sys, re
from PIL import Image
sys.path.insert(0, __import__('os').path.dirname(__file__))
from make_lv import cell, put, shade, BG, INK, SH
ROOT = sys.argv[1]
t = open(f'{ROOT}/src/fonts.c').read()
NAMES = {'normal': 'Normal', 'small': 'Small', 'narrow': 'Narrow', 'short': 'Short', 'small_narrow': 'SmallNarrow'}
for f, n in NAMES.items():
    m = re.search('gFont%sLatinGlyphWidths' % n + r'\[\]\s*=\s*\{(.*?)\};', t, re.S)
    W = [int(x) for x in re.findall(r'\d+', m.group(1))][0x108]
    path = f'{ROOT}/graphics/fonts/latin_{f}.png'
    im = Image.open(path)
    c = cell(im, 0x108)
    ink_rows = [y for y in range(16) if INK in c[y]]
    top = ink_rows[0]
    # where the o starts: first column right of the N (N occupies cols until its right shadow)
    ncols = 6 if f in ('normal', 'narrow', 'short') else 5
    for y in range(16):
        for x in range(ncols, W):
            if c[y][x] in (INK, SH):
                c[y][x] = BG
    for (x, y), v in shade(['###', '#.#', '###', '...', '###'], top).items():
        x += ncols
        if x < W and c[y][x] == BG:
            c[y][x] = v
    put(im, 0x108, c)
    im.save(path)
    print(f, 'width', W, 'top', top)

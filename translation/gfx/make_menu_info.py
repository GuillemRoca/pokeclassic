#!/usr/bin/env python3
"""Move info icons (graphics/interface/menu_info.png) in Catalan: the TM/HM
panel of the bag and the union room.

Type icons: the same labels and the same letters as the type badges
(make_badges.py): NORMAL, LLUITA, VOLANT, VERÍ ... Labels: TYPE -> TIPUS,
POWER -> POTÈNCIA, ACCURACY -> PRECISIÓ, PP -> PP, EFFECT -> EFECTE (unused).
The label pills only have one row above the capitals, so their accents are one
pixel, and the tall middle of each pill is widened to the new word."""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import make_badges as B
from PIL import Image
ROOT = sys.argv[1]
INK, SHADOW = 0xF, 0xE
glyph = dict(B.glyph)
base, above = dict(B.base, **{'Ó': 'O'}), dict(B.above, **{'Ó': ['..#', '.#.']})
glyph['?'] = ['.##.', '#..#', '...#', '..#.', '.#..', '....', '.#..']
TYPES = {  # menu.c sMenuInfoIcons offsets (tiles) -> badge label
    0x20: 'normal', 0x64: 'fight', 0x60: 'flying', 0x80: 'poison', 0x48: 'ground', 0x44: 'rock',
    0x6C: 'bug', 0x68: 'ghost', 0x88: 'steel', 0x24: 'fire', 0x28: 'water', 0x2C: 'grass',
    0x40: 'electric', 0x84: 'psychic', 0x4C: 'ice', 0xA0: 'dragon', 0x8C: 'dark', 0x04: 'fairy'}
LABELS = {0xA8: 'TIPUS', 0xC0: 'POTÈNCIA', 0xC8: 'PRECISIÓ', 0xE0: 'PP', 0xE8: 'EFECTE'}
ONE_ROW = {'È': '.#..', 'Ó': '..#.', 'Í': '.#.'}

p = f'{ROOT}/graphics/interface/menu_info.png'
im = Image.open(p); px = im.load()

def ink_of(text, x, y, accents_rows=2):
    pts = set(); acc = set()
    for c in text:
        rows = glyph[base.get(c, c)]
        for dy, row in enumerate(rows):
            for dx, ch in enumerate(row):
                if ch == '#': pts.add((x + dx, y + dy))
        if c in base:
            if accents_rows == 2:
                for dy, row in enumerate(above[c]):
                    for dx, ch in enumerate(row):
                        if ch == '#': acc.add((x + dx, y - 2 + dy))
            else:
                for dx, ch in enumerate(ONE_ROW[c]):
                    if ch == '#': acc.add((x + dx, y - 1))
        x += len(rows[0]) + 1
    return pts, acc

def width(text):
    return sum(len(glyph[base.get(c, c)][0]) for c in text) + len(text) - 1

for off, name in TYPES.items():
    x0, y0 = (off % 16) * 8, (off // 16) * 8
    # background per row (some icons are two-tone): its most common other colour
    bgrow = {}
    for y in range(y0, y0 + 12):
        vs = [px[x, y] for x in range(x0, x0 + 32) if px[x, y] not in (INK, SHADOW)]
        bgrow[y] = max(set(vs), key=vs.count)
        for x in range(x0, x0 + 32):
            if px[x, y] in (INK, SHADOW):
                px[x, y] = bgrow[y]
    text = B.LABELS[name]
    w = width(text)
    pts, acc = ink_of(text, x0 + 1 + (30 - w) // 2, y0 + 2)
    pts |= acc
    for q in pts:
        px[q] = INK
    for (x, y) in pts:
        for q in ((x + 1, y), (x, y + 1), (x + 1, y + 1)):
            if q not in pts and px[q] == bgrow[q[1]]:
                px[q] = SHADOW
    print(f'type   {name:9s} {text:7s} {w}px')

for off, text in LABELS.items():
    x0, y0 = (off % 16) * 8, (off // 16) * 8
    w = width(text)
    tx = x0 + (42 - w) // 2
    # pill: the full-width bar (rows 4-8) stays; the tall middle (rows 2-3, 9-10) is redrawn around the word
    for y in (y0 + 2, y0 + 3, y0 + 9, y0 + 10):
        for x in range(x0, x0 + 42):
            px[x, y] = SHADOW if tx - 2 <= x <= tx + w else 0
    for y in range(y0 + 4, y0 + 9):
        for x in range(x0, x0 + 42):
            if px[x, y] == INK:
                px[x, y] = SHADOW
    pts, acc = ink_of(text, tx, y0 + 3, accents_rows=1)
    for q in pts | acc:
        px[q] = INK
    print(f'label  {text:9s} {w}px')
im.save(p)

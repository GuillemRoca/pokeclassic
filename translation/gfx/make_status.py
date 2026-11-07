#!/usr/bin/env python3
"""Status condition icons in Catalan (party, summary and battle healthbox).

PSN -> ENV (enverinat), PAR -> PAR (paralitzat), SLP -> ADO (adormit),
FRZ -> GEL (gelat), BRN -> CRE (cremat), FNT -> DES (desmaiat); PKRS stays.
Letters are the icons' own 4x6 font; E, V, D, O, G and C are drawn to match.
"""
import sys
from PIL import Image
ROOT = sys.argv[1]
F = {
    'P': ['###.', '#..#', '#..#', '###.', '#...', '#...'],
    'A': ['.##.', '#..#', '#..#', '####', '#..#', '#..#'],
    'R': ['###.', '#..#', '#..#', '###.', '#.#.', '#..#'],
    'S': ['.##.', '#..#', '.#..', '..#.', '#..#', '.##.'],
    'N': ['#..#', '##.#', '#.##', '#..#', '#..#', '#..#'],
    'L': ['#...', '#...', '#...', '#...', '#...', '####'],
    'E': ['####', '#...', '#...', '###.', '#...', '####'],
    'V': ['#...#', '#...#', '#...#', '.#.#.', '.#.#.', '..#..'],
    'D': ['###.', '#..#', '#..#', '#..#', '#..#', '###.'],
    'O': ['.##.', '#..#', '#..#', '#..#', '#..#', '.##.'],
    'G': ['.##.', '#..#', '#...', '#.##', '#..#', '.###'],
    'C': ['.##.', '#..#', '#...', '#...', '#..#', '.##.'],
}
CODES = ['ENV', 'PAR', 'ADO', 'GEL', 'CRE', None, 'DES']   # sheet order PSN PAR SLP FRZ BRN PKRS FNT

def draw(px, text, center2, y, ink, bg, x0, x1):
    """Clear old letters in columns x0..x1, rows y..y+5, then draw text centred on center2/2."""
    for yy in range(y, y + 6):
        for xx in range(x0, x1 + 1):
            if px[xx, yy] == ink:
                px[xx, yy] = bg
    w = sum(len(F[c][0]) for c in text) + len(text) - 1
    x = (center2 - w + 1) // 2
    for c in text:
        for r, row in enumerate(F[c]):
            for k, ch in enumerate(row):
                if ch == '#':
                    px[x + k, y + r] = ink
        x += len(F[c][0]) + 1

# party / summary icons: 32x8 bands, letters at x 9..22, ink 2
p = f'{ROOT}/graphics/interface/status_icons.png'
im = Image.open(p); px = im.load()
for band, code in enumerate(CODES):
    if code:
        y0 = band * 8
        draw(px, code, 9 + 22, y0 + 1, 2, px[8, y0 + 3], 7, 24)
im.save(p)
# battle healthbox icons, one per file: letters at x 3..16
for name, code in zip(('psn', 'par', 'slp', 'frz', 'brn'), CODES):
    p = f'{ROOT}/graphics/battle_interface/status_{name}.png'
    im = Image.open(p); px = im.load()
    draw(px, code, 3 + 16, 1, 2, px[2, 3], 2, 17)
    im.save(p)
# grayscale copies for the opponent / doubles (index = value / 17): 5 bands
for n in (2, 3, 4):
    p = f'{ROOT}/graphics/battle_interface/status{n}.png'
    im = Image.open(p); px = im.load()
    ink, bg = 13 * 17, px[2, 3]
    for band, code in enumerate(CODES[:5]):
        draw(px, code, 3 + 16, band * 8 + 1, ink, bg, 2, 17)
    # PIL reads 4-bit grayscale as value*17 and would write it back as 8-bit,
    # which gbagfx rejects. gbagfx maps a gray level g to colour index 15 - g, so
    # store the same indices as a 4-bit indexed image (with the matching grays).
    out = Image.new('P', im.size)
    out.putpalette([c for i in range(16) for c in ((15 - i) * 17,) * 3])
    out.putdata([15 - im.getpixel((x, y)) // 17 for y in range(im.height) for x in range(im.width)])
    out.save(p, bits=4)

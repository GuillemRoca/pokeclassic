"""Redraw the type/contest badge labels in Catalan, reusing the badges' own pixel font."""
import json, os, sys
from PIL import Image
HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
G = json.load(open(os.path.join(HERE, 'glyphs.json')))  # the badges' own letters, cut from the English art
TEXT, SHADOW = 15, 14
# letter bitmaps: 7 rows (badge rows 4..10), plus optional accent rows (badge rows 2..3) and a row below (row 11)
glyph = {ch: rows[4:11] for ch, rows in G.items()}
glyph['V'] = ['#.#', '#.#', '#.#', '#.#', '#.#', '#.#', '.#.']
glyph['Q'] = ['.##.', '#..#', '#..#', '#..#', '#..#', '#.##', '.###']
glyph['.'] = ['.', '.', '.', '.', '.', '.', '#']
above = {'È': ['.#..', '..#.'], 'Í': ['..#', '.#.']}
below = {'Ç': ['..#.']}
base = {'È': 'E', 'Í': 'I', 'Ç': 'C'}
LABELS = {
    'normal': 'NORMAL', 'fight': 'LLUITA', 'flying': 'VOLANT', 'poison': 'VERÍ', 'ground': 'TERRA',
    'rock': 'ROCA', 'bug': 'INSEC.', 'ghost': 'FANT.', 'steel': 'ACER', 'fire': 'FOC', 'water': 'AIGUA',
    'grass': 'PLANTA', 'electric': 'ELÈC.', 'psychic': 'PSÍQ.', 'ice': 'GEL', 'dragon': 'DRAC',
    'dark': 'FOSC', 'fairy': 'FADA',
    'contest_cool': 'FRESC.', 'contest_beauty': 'BELL.', 'contest_cute': 'TEND.',
    'contest_smart': 'INTEL.', 'contest_tough': 'FORÇA',
}
def render(name, label, out_dir):
    im = Image.open(f'{ROOT}/graphics/types/{name}.png'); px = im.load()
    bg = px[16, 3]
    # clear the old text: rows 2..12, columns 1..30 (inside the border)
    for y in range(2, 13):
        for x in range(1, 31):
            if px[x, y] in (TEXT, SHADOW):
                px[x, y] = bg
    widths = [len(glyph[base.get(c, c)][0]) for c in label]
    total = sum(widths) + (len(label) - 1) + 1          # 1px gap/shadow between letters + final shadow
    assert total <= 30, (label, total)
    x0 = 1 + (30 - total + 1) // 2
    ink = set()
    x = x0
    for c, w in zip(label, widths):
        rows = glyph[base.get(c, c)]
        for dy, row in enumerate(rows):
            for dx, ch in enumerate(row):
                if ch == '#': ink.add((x + dx, 4 + dy))
        for dy, row in enumerate(above.get(c, [])):
            for dx, ch in enumerate(row):
                if ch == '#': ink.add((x + dx, 2 + dy))
        for dy, row in enumerate(below.get(c, [])):
            for dx, ch in enumerate(row):
                if ch == '#': ink.add((x + dx, 11 + dy))
        x += w + 1
    for (x, y) in ink:
        px[x, y] = TEXT
    for (x, y) in ink:   # shadow: right, below and diagonal of each ink pixel
        for sx, sy in ((x + 1, y), (x, y + 1), (x + 1, y + 1)):
            if (sx, sy) not in ink and 1 <= sx <= 30 and 2 <= sy <= 12 and px[sx, sy] == bg:
                px[sx, sy] = SHADOW
    im.save(f'{out_dir}/{name}.png')
    return total
if __name__ == '__main__':
    out = sys.argv[1] if len(sys.argv) > 1 else f'{ROOT}/graphics/types'
    for n, l in LABELS.items():
        print(f'{n:15} {l:8} {render(n, l, out)}px')

#!/usr/bin/env python3
"""Condition graph labels (PokéGear condition screen and the Pokéblock feeding
screen) in Catalan: FRESCOR, BELLESA, TENDRESA, INTEL., FORÇA (as the contest
categories elsewhere; INTEL·LIGÈNCIA does not fit beside the pentagon).

The labels are white capitals with a two-tone outline (index 4 next to the ink,
f on the diagonal corners) drawn over the graph, so the old ones are removed by
filling their pixels from the surrounding picture, and the new ones are
FONT_SMALL capitals with the same outline, centred where the English was. Every
tile of the panel (map cells 12-26 x 5-16) is shown once, so the screen pixels
are written straight back into the tiles."""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from tiles import Sheet, Font, TileMapView, load_map, font_masks
ROOT = sys.argv[1]
INK, EDGE4, EDGED = 1, 4, 0xF
N8 = [(dx, dy) for dx in (-1, 0, 1) for dy in (-1, 0, 1) if dx or dy]
N4 = [(1, 0), (-1, 0), (0, 1), (0, -1)]
SMALL = Font('small')
WORDS = {'COOL': 'FRESCOR', 'BEAUTY': 'BELLESA', 'CUTE': 'TENDRESA', 'SMART': 'INTEL.', 'TOUGH': 'FORÇA'}

def words(v):
    """English labels as clusters of ink pixels, sorted top-to-bottom, left-to-right."""
    ink = {(x, y) for x in range(v.w) for y in range(v.h) if v[x, y] == INK}
    clusters = []
    seen = set()
    for p in sorted(ink, key=lambda q: (q[1], q[0])):
        if p in seen:
            continue
        stack, comp = [p], set()
        while stack:
            q = stack.pop()
            if q in seen:
                continue
            seen.add(q); comp.add(q)
            for dx in range(-3, 4):                    # letters of a word are < 4 px apart
                for dy in range(-2, 3):
                    r = (q[0] + dx, q[1] + dy)
                    if r in ink and r not in seen:
                        stack.append(r)
        clusters.append(comp)
    def word_like(c):    # the panel border is also index 1: keep low, wide clusters only
        h = max(y for _, y in c) - min(y for _, y in c) + 1
        w = max(x for x, _ in c) - min(x for x, _ in c) + 1
        return len(c) > 20 and h <= 9 and w >= 12
    return [c for c in clusters if word_like(c)]

def run(png, binf, base, order):
    sh = Sheet(png)
    v = TileMapView(sh, load_map(binf), 12, 5, 15, 12, base)
    labels = words(v)
    labels.sort(key=lambda c: (min(y for _, y in c) // 8, min(x for x, _ in c)))
    assert len(labels) == 5, len(labels)
    for comp, eng in zip(labels, order):
        x0, x1 = min(x for x, _ in comp), max(x for x, _ in comp)
        y0 = min(y for _, y in comp)
        # remove: ink and two rings around it, filled from the surroundings
        mask = set(comp)
        for _ in range(2):
            mask |= {(x + dx, y + dy) for (x, y) in mask for dx, dy in N8
                     if 0 <= x + dx < v.w and 0 <= y + dy < v.h}
        todo = set(mask)
        while todo:
            done = {}
            for (x, y) in todo:
                vs = [v[x + dx, y + dy] for dx, dy in N8
                      if 0 <= x + dx < v.w and 0 <= y + dy < v.h and (x + dx, y + dy) not in todo]
                if vs:
                    done[(x, y)] = max(set(vs), key=vs.count)
            for q, c in done.items():
                v[q] = c
            todo -= set(done)
        # draw
        text = WORDS[eng]
        masks, space = font_masks(SMALL, text)
        w = sum(masks[c][2] for c in text)
        cx = round((x0 + x1 + 1) / 2 - w / 2)
        cx = max(1, min(cx, v.w - 1 - w))
        new = set()
        x = cx
        for c in text:
            dy, rows, gw = masks[c]
            for r, row in enumerate(rows):
                for k, ch in enumerate(row):
                    if ch == '#':
                        new.add((x + k, y0 + dy + r))
            x += gw
        for (x, y) in new:
            for dx, dy in N8:
                q = (x + dx, y + dy)
                if q in new or not (0 <= q[0] < v.w and 0 <= q[1] < v.h):
                    continue
                four = any((q[0] + ex, q[1] + ey) in new for ex, ey in N4)
                if four:
                    v[q] = EDGE4
                elif v[q] != EDGE4:
                    v[q] = EDGED
        for q in new:
            v[q] = INK
        print(f'{os.path.basename(os.path.dirname(png)):12s} {eng:7s} -> {text:9s} {w}px at x={cx}')
    sh.save()

ORDER = ['COOL', 'TOUGH', 'BEAUTY', 'SMART', 'CUTE']
run(f'{ROOT}/graphics/pokenav/condition/graph.png', f'{ROOT}/graphics/pokenav/condition/graph.bin', 0, ORDER)
run(f'{ROOT}/graphics/pokeblock/use_screen/graph.png', f'{ROOT}/graphics/pokeblock/use_screen/graph.bin', 640, ORDER)

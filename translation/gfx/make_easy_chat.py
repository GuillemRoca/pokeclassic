#!/usr/bin/env python3
"""Easy chat (mail and messages) and Berry Blender labels.

easy_chat/button_window.png (one 64x64 sprite):
  DELETE          -> ESBORRA   white letters, dark edge = 8-neighbour ring (the art's own
                               rule); B and R are 3 px wide so the word fits the panel
  (B) BUTTON      -> BOTÓ (B)  grey 3x5 letters, the red B badge moved after the word
  CANCEL          -> TORNAR    as the 'TORNAR' used for CANCEL elsewhere
  SELECT / MODE   kept: SELECT is the button's name and 'MODE' is already Catalan.
easy_chat/mode.png (64x32 frames): 'GROUP' -> 'GRUP' in the same letters, same centre.
  'A-Z' and the small 'MODE' captions are already Catalan.
berry_blender/start.png: 'START' (shown after the 3-2-1 countdown) -> 'JA!'
  ('Preparats, llestos... ja!'). The art is exactly fill + 8-neighbour dark ring +
  4-neighbour light ring, so the new word is drawn as fills and the rings derived.
  A is the original letter; J and ! are drawn in the same strokes.
Run on the original files; writes them in place."""
import sys
from PIL import Image

ROOT = sys.argv[1] if len(sys.argv) > 1 else '.'


def d8(s):
    return {(x + dx, y + dy) for x, y in s for dx in (-1, 0, 1) for dy in (-1, 0, 1)}


def d4(s):
    return {(x + dx, y + dy) for x, y in s for dx, dy in ((0, 0), (1, 0), (-1, 0), (0, 1), (0, -1))}


def mask(rows, x0, y0):
    return {(x0 + x, y0 + y) for y, r in enumerate(rows) for x, ch in enumerate(r) if ch == '#'}


def outlined(px, ink_pts, ink, edge):
    for p in d8(ink_pts) - ink_pts:
        px[p] = edge
    for p in ink_pts:
        px[p] = ink


# ---------------------------------------------------------------- button window
W5 = {  # white 5-row letters of the panel (M, O, D, E, L, T, C, A, N as in the art)
    'E': ['####', '#...', '###.', '#...', '####'],
    'S': ['.###', '#...', '.##.', '...#', '###.'],
    'B': ['##.', '#.#', '##.', '#.#', '##.'],
    'O': ['.##.', '#..#', '#..#', '#..#', '.##.'],
    'r': ['##.', '#.#', '##.', '#.#', '#.#'],          # narrow R for ESBORRA
    'R': ['###.', '#..#', '###.', '#.#.', '#..#'],
    'A': ['.##.', '#..#', '#..#', '####', '#..#'],
    'T': ['#####', '..#..', '..#..', '..#..', '..#..'],
    'N': ['#..#', '##.#', '#.##', '#..#', '#..#'],
}
G3 = {  # grey 3x5 letters of 'BUTTON'
    'B': ['##.', '#.#', '##.', '#.#', '##.'],
    'O': ['###', '#.#', '#.#', '#.#', '###'],
    'T': ['###', '.#.', '.#.', '.#.', '.#.'],
}


def word(font, text, x, y, gap=1):
    pts = set()
    for ch in text:
        pts |= mask(font[ch], x, y)
        x += len(font[ch][0]) + gap
    return pts


def word_w(font, text, gap=1):
    return sum(len(font[c][0]) for c in text) + gap * (len(text) - 1)


def button_window():
    path = ROOT + '/graphics/easy_chat/button_window.png'
    im = Image.open(path)
    px = im.load()
    BG, INK, EDGE = 5, 15, 12
    L, R = 23, 57                                   # panel interior columns
    badge = {(x, y): px[x, y] for x in range(24, 32) for y in range(40, 47)}
    for y in list(range(29, 36)) + list(range(40, 47)) + list(range(47, 54)):
        for x in range(L, R + 1):
            px[x, y] = BG
    # ESBORRA, centred (its edge ring may not touch the panel border)
    w = word_w(W5, 'ESBOrrA')
    x = L + (R - L + 1 - (w + 2)) // 2 + 1
    outlined(px, word(W5, 'ESBOrrA', x, 30), INK, EDGE)
    # TORNAR, centred
    w = word_w(W5, 'TORNAR')
    x = L + (R - L + 1 - (w + 2)) // 2 + 1
    outlined(px, word(W5, 'TORNAR', x, 48), INK, EDGE)
    # BOTÓ + badge, centred
    gap = 2
    w = word_w(G3, 'BOTO') + gap + 8
    x = L + (R - L + 1 - w) // 2
    for p in word(G3, 'BOTO', x, 41):
        px[p] = EDGE
    ox = x + 3 * 4                                  # last O
    px[ox + 2, 39] = EDGE                           # acute: one pixel over a free row
    bx = x + word_w(G3, 'BOTO') + gap
    for (sx, sy), v in badge.items():
        px[bx + sx - 24, sy] = v
    im.save(path)


# ---------------------------------------------------------------- mode window
def mode_window():
    path = ROOT + '/graphics/easy_chat/mode.png'
    im = Image.open(path)
    px = im.load()
    INK, EDGE, BG = 15, 12, 14
    y0, y1 = 47, 53                                 # ink rows of GROUP (frame at y 32-63)
    cols = [x for x in range(28, 57) if any(px[x, y] == INK for y in range(y0, y1))]
    runs = []
    for x in cols:
        if runs and x == runs[-1][-1] + 1:
            runs[-1].append(x)
        else:
            runs.append([x])
    assert len(runs) == 5, runs                     # G R O U P
    glyph = {}
    for ch, r in zip('GROUP', runs):
        glyph[ch] = {(x - r[0], y - y0) for x in r for y in range(y0, y1) if px[x, y] == INK}
        glyph[ch + 'w'] = len(r)
    centre2 = runs[0][0] + runs[-1][-1]
    text = 'GRUP'
    w = sum(glyph[c + 'w'] for c in text) + len(text) - 1
    x = (centre2 - (w - 1) + 1) // 2
    for y in range(46, 54):
        for xx in range(28, 57):
            if px[xx, y] in (INK, EDGE):
                px[xx, y] = BG
    pts = set()
    for ch in text:
        pts |= {(x + gx, y0 + gy) for gx, gy in glyph[ch]}
        x += glyph[ch + 'w'] + 1
    outlined(px, pts, INK, EDGE)
    im.save(path)


# ---------------------------------------------------------------- berry blender
J = ['..#########',
     '..#########',
     '..#########',
     '........###',
     '........###',
     '........###',
     '........###',
     '........###',
     '........###',
     '........###',
     '........###',
     '........###',
     '........###',
     '........###',
     '###.....###',
     '###.....###',
     '####...####',
     '.#########.',
     '..#######..',
     '...#####...',
     '....###....']
EXCL = ['####',
        '####',
        '####',
        '####',
        '####',
        '####',
        '####',
        '####',
        '####',
        '.##.',
        '.##.',
        '.##.',
        '.##.',
        '....',
        '....',
        '....',
        '.##.',
        '####',
        '####',
        '.##.',
        '....']


def blender_start():
    path = ROOT + '/graphics/berry_blender/start.png'
    im = Image.open(path)
    px = im.load()
    W, H = im.size
    FILL, DARK, LIGHT = 12, 1, 15
    fill = {(x, y) for x in range(W) for y in range(H) if px[x, y] == FILL}
    seed = (28, 6)                                  # inside the original A
    a, st = {seed}, [seed]
    while st:
        x, y = st.pop()
        for q in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
            if q in fill and q not in a:
                a.add(q)
                st.append(q)
    ax0 = min(p[0] for p in a)
    a = {(x - ax0, y - 5) for x, y in a}
    aw = max(p[0] for p in a) + 1
    gap = 2
    total = len(J[0]) + gap + aw + gap + len(EXCL[0])
    x = (W - total) // 2
    new = mask(J, x, 5)
    x += len(J[0]) + gap
    new |= {(x + gx, 5 + gy) for gx, gy in a}
    x += aw + gap
    new |= mask(EXCL, x, 5)
    ring = d8(new) - new
    outer = d4(new | ring) - (new | ring)
    for y in range(H):
        for x in range(W):
            p = (x, y)
            px[p] = FILL if p in new else DARK if p in ring else LIGHT if p in outer else 0
    im.save(path)


if __name__ == '__main__':
    button_window()
    mode_window()
    blender_start()

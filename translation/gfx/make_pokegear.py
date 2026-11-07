#!/usr/bin/env python3
"""PokéGear (PokéNav graphics) labels in Catalan, with the same words as its texts.

All of them are FONT_NORMAL capitals (ink 1, shadow 2) on a coloured bar, so they
are rewritten with the game font in place. Options (128x16 buttons, four 32x16
pieces) and submenu headers (64x16) have only two bar rows above the capitals,
so a word with an accent is drawn one row lower and one with Ç one row higher.
The map header is two 56 px pieces: MAPA + COMPLET / AMPLIAT."""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from tiles import Sheet, Font, StripView, bar_label
ROOT = sys.argv[1]
NORMAL, NARROW = Font('normal'), Font('narrow')
INK, SHADOW = 1, 2

label = bar_label

D = f'{ROOT}/graphics/pokenav'
OPTIONS = {  # file: (Catalan, has an icon before the text)
    'hoenn_map': ('MAPA DE KANTO', True), 'match_call': ('TELÈFON', True), 'condition': ('CONDICIÓ', True),
    'ribbons': ('CINTES', True), 'switch_off': ('GUARDAR', True), 'party': ('EQUIP POKéMON', True),
    'search': ('CERCA', True), 'cancel': ('TORNAR', True), 'cool': ('FRESCOR', False), 'beauty': ('BELLESA', False),
    'cute': ('TENDRESA', False), 'smart': ('INTEL·LIGÈNCIA', False), 'tough': ('FORÇA', False)}
for name, (text, icon) in OPTIONS.items():
    sh = Sheet(f'{D}/options/{name}.png')
    # the icon square (x 8-15) is drawn in the ink colour on some buttons: keep it out of the box
    w = label(StripView(sh, 32, 16, 4), (16 if icon else 2, 2, 125, 13), text, align='left',
              border=((14, 15), 0xA) if name == 'party' else None,
              cap_top=4 if name == 'party' else None)     # the PKMN glyph is taller than the capitals
    sh.save(); print(f'option {name:10s} {text:15s} {w}px')
MAIN = {'main_menu': ('MENÚ PRINCIPAL', NARROW), 'condition': ('CONDICIÓ', NORMAL),
        'match_call': ('TELÈFON', NORMAL), 'ribbons': ('CINTES', NORMAL)}
for name, (text, font) in MAIN.items():
    sh = Sheet(f'{D}/left_headers/{name}.png')
    w = label(StripView(sh, 64, 32, 2), (2, 2, 85, 21), text, font)
    sh.save(); print(f'header {name:10s} {text:15s} {w}px')
sh = Sheet(f'{D}/left_headers/hoenn_map.png')
v = StripView(sh, 64, 32, 3)
for piece, text in enumerate(['MAPA', 'COMPLET', 'AMPLIAT']):
    w = label(v, (piece * 64 + 2, 2, piece * 64 + 55, 21), text)
    print(f'header map/{piece}      {text:15s} {w}px')
sh.save()
SUB = {'party': 'EQUIP', 'search': 'CERCA', 'cool': 'FRESCOR', 'beauty': 'BELLESA',
       'cute': 'TENDRESA', 'smart': 'INTEL.', 'tough': 'FORÇA'}
for name, text in SUB.items():
    sh = Sheet(f'{D}/left_headers/{name}.png')
    w = label(StripView(sh, 32, 16, 4), (0, 2, 61, 13), text, border=((14, 15), 0xA) if name == 'party' else None,
              cap_top=4 if name == 'party' else None)
    sh.save(); print(f'sub    {name:10s} {text:15s} {w}px')

# city_zoom_text.png: the zoomed map legend, five 96 px entries (three 32x8 sprites)
# in one tile strip: a coloured square and the name in a 6-row font of the entry's
# colour. Letters learnt from the English; I, D, U and À drawn to match.
from tiles import ink_groups
sh = Sheet(f'{D}/city_zoom_text.png')
v = StripView(sh, 64, 8, 8)
ENGLISH = ['POKéMON CENTER', 'POKé MART', 'POKéMON GYM', 'BATTLE TENT', 'POKéMON CONTEST']
CATALAN = ['CENTRE POKéMON', 'BOTIGA POKéMON', 'GIMNÀS POKéMON', 'CARPA DE COMBAT', 'CONCURS POKéMON']
glyphs = {}
colours = []
for k, text in enumerate(ENGLISH):
    x0 = 96 * k
    colour = next(v[x, 3] for x in range(x0, x0 + 12) if v[x, 3] != 0)
    colours.append(colour)
    pts, groups = ink_groups(v, (x0, 0, x0 + 95, 7), colour)
    letters = ['■'] + [c for c in text if c != ' ']
    assert len(groups) == len(letters), text
    for g, c in zip(groups, letters):
        glyphs.setdefault(c, [''.join('#' if (x, y) in pts else '.' for x in range(g[0], g[-1] + 1)) for y in range(1, 7)])
glyphs.update({'I': ['###', '.#.', '.#.', '.#.', '.#.', '###'],
               'D': ['###.', '#..#', '#..#', '#..#', '#..#', '###.'],
               'U': ['#..#', '#..#', '#..#', '#..#', '#..#', '.##.'],
               'À': glyphs['A']})
for k, text in enumerate(CATALAN):
    x0 = 96 * k
    for x in range(x0 + 13, x0 + 96):
        for y in range(8):
            v[x, y] = 0
    x = x0 + 14
    for c in text:
        if c == ' ':
            x += 3
            continue
        for r, row in enumerate(glyphs[c]):
            for i, ch in enumerate(row):
                if ch == '#':
                    v[x + i, 1 + r] = colours[k]
        if c == 'À':
            v[x, 0] = colours[k]          # grave, touching the A only at its corner
        x += len(glyphs[c][0]) + 1
    assert x - 1 <= x0 + 95, text
    print(f'legend {text:16s} {x - 1 - (x0 + 14)}px')
sh.save()

# condition/cancel.png: the CANCEL tag beside the condition party list, a 3x5 font
# in 19 px: TORNAR does not fit, so the imperative TORNA (A, N as in the English).
sh = Sheet(f'{D}/condition/cancel.png'); px = sh.px
from tiles import ink_groups
pts, groups = ink_groups(px, (4, 5, 22, 9), 0xF)
learnt = {}
for g, c in zip(groups, 'CANCEL'):
    learnt.setdefault(c, [''.join('#' if (x, y) in pts else '.' for x in range(g[0], g[-1] + 1)) for y in range(5, 10)])
G = {'T': ['###', '.#.', '.#.', '.#.', '.#.'], 'O': ['###', '#.#', '#.#', '#.#', '###'],
     'R': ['##.', '#.#', '##.', '#.#', '#.#'], 'N': learnt['N'], 'A': learnt['A']}
for y in range(5, 10):
    for x in range(4, 23):
        px[x, y] = 2
w = sum(len(G[c][0]) for c in 'TORNA') + 4
x = 4 + (19 - w) // 2
for c in 'TORNA':
    for r, row in enumerate(G[c]):
        for i, ch in enumerate(row):
            if ch == '#':
                px[x + i, 5 + r] = 0xF
    x += len(G[c][0]) + 1
sh.save()
print(f'tag    CANCEL -> TORNA {w}px')

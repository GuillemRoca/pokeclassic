#!/usr/bin/env python3
"""DexNav screen (graphics/dexnav/gui_tiles.png + gui_tilemap.bin) in Catalan.

WATER -> AIGUA, LAND -> TERRA, HIDDEN -> OCULTS, SPECIES -> ESPÈCIE, TYPE -> TIPUS,
SEARCH LEVEL -> NIVELL DE CERCA, HIDDEN ABILITY -> HAB. OCULTA (HABILITAT OCULTA
needs 71 px of a 69 px bar), CURRENT CHAIN -> CADENA ACTUAL, SEARCH (button) -> CERCA.
The left labels match FONT_SMALL(_NARROW) exactly and are rewritten with it; the
right-panel ones are FONT_SMALL capitals; the button reuses its own bold letters.
Where a longer word reaches a tile the bar repeats elsewhere, that cell gets one
of the unused tiles 167-175 (tiles.ScreenEdit)."""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from tiles import Sheet, Font, ScreenEdit, relabel, restyle, LearnedLabel
ROOT = sys.argv[1]
sh = Sheet(f'{ROOT}/graphics/dexnav/gui_tiles.png')
E = ScreenEdit(sh, f'{ROOT}/graphics/dexnav/gui_tilemap.bin', range(167, 176)).load(0, 0, 30, 20)

class V:
    px, path = E, 'dexnav'

for box, old, new, font, shadow, bg in [
        ((10, 14, 100, 21), 'WATER', 'AIGUA', 'small_narrow', 7, 8),
        ((3, 55, 47, 62), 'LAND', 'TERRA', 'small_narrow', 7, 6),
        ((34, 120, 110, 127), 'HIDDEN', 'OCULTS', 'small', 7, 2)]:
    print(f'{old:15s} -> {new:16s} {relabel(V, box, old, new, Font(font), 1, shadow, bg)}px')

S = Font('small')
for box, old, new, top in [
        ((161, 35, 231, 44), 'SPECIES', 'ESPÈCIE', 38),         # one row lower: room for the accent
        ((162, 60, 231, 68), 'TYPE', 'TIPUS', None),
        ((161, 84, 231, 92), 'SEARCH LEVEL', 'NIVELL DE CERCA', None),
        ((161, 108, 231, 116), 'HIDDEN ABILITY', 'HAB. OCULTA', None),
        ((161, 132, 231, 140), 'CURRENT CHAIN', 'CADENA ACTUAL', None)]:
    # the English labels start at x=163 (the white panels below are also index 1)
    print(f'{old:15s} -> {new:16s} {restyle(E, box, new, S, {1}, None, None, x=163, top=top)}px')

L = LearnedLabel(E, (166, 19, 219, 26), 'SEARCH', {1}, None, None).check()   # 8-row bold letters, Ⓐ icon excluded
print(f'{"SEARCH (button)":15s} -> {"CERCA":16s} {L.write("CERCA", x=L.start + (L.width("SEARCH") - L.width("CERCA")) // 2)}px')
print('free tiles left', E.save())

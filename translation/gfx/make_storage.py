#!/usr/bin/env python3
"""PC storage system labels (graphics/pokemon_storage/menu.png) in Catalan.

PKMN DATA -> DADES PKMN, PARTY POKéMON -> EQUIP POKéMON, CANCEL -> TORNAR,
CLOSE BOX -> SORTIR (the button asks "Sortir de la caixa?"). Written in FONT_SMALL
(7-row capitals like the English) with each label's own colours, gradient,
shadow or outline. Tile lists come from the .bin tilemaps (base tile 256)."""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from tiles import Sheet, Font, TileGridView, restyle
ROOT = sys.argv[1]
S = Font('small')
sh = Sheet(f'{ROOT}/graphics/pokemon_storage/menu.png')
JOBS = [
    # view rows (sheet tiles), box in the view, text, ink colours, edge, rule
    ([list(range(1, 9)), list(range(17, 25))], (3, 3, 62, 13), 'DADES PKMN', {0xE, 0xA, 5}, 3, 'outline8'),
    ([list(range(40, 48)) + [102], list(range(56, 64)) + [103]], (4, 3, 69, 12), 'EQUIP POKéMON', {8}, 7, 'rd'),
    ([[73, 74, 75, 105], [89, 90, 91, 106]], (1, 3, 31, 11), 'TORNAR', {8}, 7, 'rd'),
    ([[76, 77, 78, 79, 112, 113, 114, 115, 116], [92, 93, 94, 95, 128, 129, 130, 131, 132]], (4, 4, 67, 12), 'SORTIR', {0xE}, 9, 'rd'),
    ([list(range(117, 126)), list(range(133, 142))], (4, 4, 67, 12), 'SORTIR', {9}, None, None),
]
for rows, box, text, ink, edge, rule in JOBS:
    v = TileGridView(sh, rows)
    print(f'{text:14s} {restyle(v, box, text, S, ink, edge, rule)}px')
sh.save()

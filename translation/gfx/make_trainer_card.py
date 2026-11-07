#!/usr/bin/env python3
"""Trainer card (graphics/trainer_card/card.png, the card this game shows) in Catalan.

TRAINER CARD -> TARGETA D'ENTRENADOR. The header shows tiles 139, 128..139: tile
139 is both end caps (the left one flipped), so the text must stay in tiles
128-138 (88 px). FONT_SMALL needs 93 px, so the 3 px capitals of the Pokédex
NACIONAL label are used (77 px). BADGES -> MEDALLES (FONT_SMALL, tiles 6-11,
striped background). card_fr.png is only drawn for a linked FireRed/LeafGreen
player and is left as is."""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from tiles import Sheet, Font, restyle, compose, text_width, paint
ROOT = sys.argv[1]
NARROW_CAPS = {   # 7 rows; N, A, T, I, O, L as in the Pokédex sidebar
    'T': ['###', '.#.', '.#.', '.#.', '.#.', '.#.', '.#.'],
    'A': ['.#.', '#.#', '#.#', '###', '#.#', '#.#', '#.#'],
    'R': ['##.', '#.#', '#.#', '##.', '#.#', '#.#', '#.#'],
    'G': ['.##', '#..', '#..', '#.#', '#.#', '#.#', '.##'],
    'E': ['###', '#..', '#..', '##.', '#..', '#..', '###'],
    'D': ['##.', '#.#', '#.#', '#.#', '#.#', '#.#', '##.'],
    'N': ['#..#', '##.#', '##.#', '#.##', '#.##', '#..#', '#..#'],
    'O': ['.#.', '#.#', '#.#', '#.#', '#.#', '#.#', '.#.'],
    "'": ['#', '#', '.', '.', '.', '.', '.'],
}
sh = Sheet(f'{ROOT}/graphics/trainer_card/card.png')
text = "TARGETA D'ENTRENADOR"
w = text_width(NARROW_CAPS, text)
paint(sh.px, (0, 67, 87, 76), compose(NARROW_CAPS, text, (88 - w) // 2, 68), 0xF, None, 0xD, 'rd', clear={0xF, 8})
print('header', w)
print('badges', restyle(sh.px, (48, 0, 95, 7), 'MEDALLES', Font('small'), {1}, None, None, top=1))
sh.save()

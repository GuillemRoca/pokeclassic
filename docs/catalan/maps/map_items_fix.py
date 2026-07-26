# -*- coding: utf-8 -*-
"""Shorten Catalan item names to the real 13-char limit (name[14] incl. 0xFF).
Also updates the matching shop-list strings in strings.c."""
KIND = 'c'
FILES = ['src/data/items.h', 'src/strings.c']

T = {
"Coixinets Prot": "Coixins Prot.",
"Ulleres Negres": "Ull. Negres",
"Carta Tropical": "Carta Tropic.",
"Carta Brillant": "Carta Brill.",
"Ulleres Sàvies": "Ull. Sàvies",
"Clau Soterrani": "Clau Soterr.",
"Galeta de Lava": "Galeta Lava",
"Punxa Verinosa": "Punxa Verí",
"Mapa Mar Antic": "Mapa Mar Ant.",
"Bitllet Místic": "Bitllet Míst.",
"Carta Mecànica": "Carta Mecàn.",
"Càpsula Habil.": "Càps. Habil.",
"Carta Fabulosa": "Carta Fabul.",
"Herba Revifant": "Herba Revif.",
"Amulet Captura": "Amulet Capt.",
"Bitllet Aurora": "Bitllet Aur.",
"Llavor Miracle": "Llavor Mirac.",
"Passi Arc Iris": "Passi Arc Ir.",
"Cendra Sagrada": "Cendra Sagr.",
"Pols Estel·lar": "Pols Estel.",
"Closca de Banc": "Closca Banc",
"Cinturó Expert": "Cint. Expert",
"Caramel At.Esp": "Caram. At.Esp",
"Caramel Df.Esp": "Caram. Df.Esp",
"Escata Abissal": "Escata Abiss.",
# shop-list variants in strings.c
"Ulleres Sàvies{CLEAR_TO 0x5E}48PC": "Ull. Sàvies{CLEAR_TO 0x5E}48PC",
"Càpsula Habil.{CLEAR_TO 0x64}50PC": "Càps. Habil.{CLEAR_TO 0x64}50PC",
"Caramel At.Esp{CLEAR_TO 0x5E}24PC": "Caram. At.Esp{CLEAR_TO 0x5E}24PC",
"Caramel Df.Esp{CLEAR_TO 0x5E}24PC": "Caram. Df.Esp{CLEAR_TO 0x5E}24PC",
"Herba Revifant{CLEAR_TO 108}{FONT_SMALL}300": "Herba Revif.{CLEAR_TO 108}{FONT_SMALL}300",
}

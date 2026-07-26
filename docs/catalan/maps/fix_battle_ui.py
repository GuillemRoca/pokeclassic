# -*- coding: utf-8 -*-
"""Re-split the battle/UI messages whose lines exceeded the 208px text box."""
KIND = 'c'
FILES = ['src/battle_message.c', 'src/strings.c']
T = {
"S'ha creat una zona estranya on els objectes\\ndels Pokémon perden els seus efectes!": "S'ha creat una zona on els\\nobjectes perden els efectes!",
"S'ha creat una zona estranya on la Defensa\\ni la Def. Esp. estan intercanviades!": "S'ha creat una zona on la Defensa\\ni la Def. Esp. es canvien!",
"Sala Màgica s'ha esgotat i els efectes\\ndels objectes han tornat a la normalitat!": "Sala Màgica s'ha esgotat i els\\nobjectes tornen a la normalitat!",
"Els efectes de Bany de Fang s'han esvaït.": "L'efecte de Bany de Fang\\ns'ha esvaït.",
"Es farà realitat el somni del campionat?!\\p": "Es complirà el somni\\ndel campionat?!\\p",
"Els efectes de Bany d'Aigua s'han esvaït.": "L'efecte de Bany d'Aigua\\ns'ha esvaït.",
"{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha pujat les\\nseves estadístiques amb el seu Poder Z!": "{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha pujat les\\nestadístiques amb el Poder Z!",
"{STR_VAR_1} s'ha fet més amistós.\\nLes estadístiques internes han caigut!{PAUSE_UNTIL_PRESS}": "{STR_VAR_1} s'ha fet més amistós.\\nLes estad. internes han caigut!{PAUSE_UNTIL_PRESS}",
}

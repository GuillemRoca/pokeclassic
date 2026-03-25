SilphCo_1F_MapScripts::
	.byte 0

SilphCo_1F_EventScript_Receptionist::
	msgbox SilphCo_1F_Text_WelcomePresidentInBoardroom, MSGBOX_NPC
	end

SilphCo_1F_EventScript_FloorSign::
	msgbox SilphCo_1F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_1F_Text_WelcomePresidentInBoardroom::
    .string "Benvingut.\p"
    .string "El President és a la sala de\n"
    .string "juntes al pis 11.$"

SilphCo_1F_Text_FloorSign::
    .string "Seu Central de Silph S.A.\n"
    .string "1r pis$"


SilphCo_1F_EventScript_PostgameGrunt1::
	trainerbattle_single TRAINER_POSTGAME_ROCKET_1, SilphCo_1F_Text_PostgameGrunt1Intro, SilphCo_1F_Text_PostgameGrunt1Defeat
	msgbox SilphCo_1F_Text_PostgameGrunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_1F_Text_PostgameGrunt1Intro::
    .string "L'Equip Rocket ha tornat, nen!$"

SilphCo_1F_Text_PostgameGrunt1Defeat::
    .string "Abatut en plena joventut!$"

SilphCo_1F_Text_PostgameGrunt1PostBattle::
    .string "Som aquí per acabar el que\n"
    .string "Giovanni va començar.$"

SilphCo_1F_EventScript_PostgameGrunt2::
	trainerbattle_single TRAINER_POSTGAME_ROCKET_2, SilphCo_1F_Text_PostgameGrunt2Intro, SilphCo_1F_Text_PostgameGrunt2Defeat
	msgbox SilphCo_1F_Text_PostgameGrunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_1F_Text_PostgameGrunt2Intro::
    .string "A diferència d'alguns, nosaltres\n"
    .string "no vam fugir quan Giovanni va\l"
    .string "ser derrotat a Viridian.$"

SilphCo_1F_Text_PostgameGrunt2Defeat::
    .string "Potser hauria de plegar...$"

SilphCo_1F_Text_PostgameGrunt2PostBattle::
    .string "Mai em rendiré!\n"
    .string "Equip Rocket per sempre!$"

SilphCo_1F_EventScript_PostgameGrunt3::
	trainerbattle_single TRAINER_POSTGAME_ROCKET_3, SilphCo_1F_Text_PostgameGrunt3Intro, SilphCo_1F_Text_PostgameGrunt3Defeat
	msgbox SilphCo_1F_Text_PostgameGrunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_1F_Text_PostgameGrunt3Intro::
    .string "Dona'm tots els diners!$"

SilphCo_1F_Text_PostgameGrunt3Defeat::
    .string "Estem pelats!$"

SilphCo_1F_Text_PostgameGrunt3PostBattle::
    .string "El nou cap no ho vol admetre,\n"
    .string "però l'Equip Rocket funciona\l"
    .string "amb les últimes reserves.\p"
    .string "Necessitem que aquest cop surti\n"
    .string "bé!$"

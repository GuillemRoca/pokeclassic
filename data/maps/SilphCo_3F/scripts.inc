SilphCo_3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_3F_OnLoad
	.byte 0

SilphCo_3F_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION, 1
	release
	end

SilphCo_3F_OnLoad::
	call_if_unset FLAG_SILPH_3F_DOOR_1, EventScript_Close3FDoor1
	call_if_unset FLAG_SILPH_3F_DOOR_2, EventScript_Close3FDoor2
	end

SilphCo_3F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_3F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_3F_Text_WhatAmIToDo
	release
	end

SilphCo_3F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_3F_Text_YouAndYourMonsSavedUs
	release
	end

SilphCo_3F_EventScript_FloorSign::
	msgbox SilphCo_3F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_3F_EventScript_Jose::
	trainerbattle_single TRAINER_SCIENTIST_JOSE, SilphCo_3F_Text_JoseIntro, SilphCo_3F_Text_JoseDefeat
	msgbox SilphCo_3F_Text_JosePostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_25, SilphCo_3F_Text_GruntIntro, SilphCo_3F_Text_GruntDefeat
	msgbox SilphCo_3F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_Text_WhatAmIToDo::
    .string "Treballo per Silph S.A.\n"
    .string "Què he de fer?$"

SilphCo_3F_Text_YouAndYourMonsSavedUs::
    .string "{PLAYER}!\n"
    .string "Tu i els teus Pokémon ens heu\l"
    .string "salvat!$"

SilphCo_3F_Text_GruntIntro::
    .string "Deixa de molestar-nos, nen!$"

SilphCo_3F_Text_GruntDefeat::
    .string "Em rendeixo!$"

SilphCo_3F_Text_GruntPostBattle::
    .string "Una pista? Pots obrir portes amb\n"
    .string "una Clau Targeta!$"

SilphCo_3F_Text_JoseIntro::
    .string "Dono més suport a l'Equip Rocket\n"
    .string "que a Silph S.A.!$"

SilphCo_3F_Text_JoseDefeat::
    .string "M'has pillat de debò!$"

SilphCo_3F_Text_JosePostBattle::
    .string "Bah…\p"
    .string "L'Equip Rocket va dir que si els\n"
    .string "ajudava, em deixarien estudiar\l"
    .string "Pokémon.$"

SilphCo_3F_Text_FloorSign::
    .string "Seu Central de Silph S.A.\n"
    .string "3r pis$"

SilphCo_3F_EventScript_PostgameGrunt4::
	trainerbattle_single TRAINER_POSTGAME_ROCKET_4, SilphCo_3F_Text_PostgameGrunt4Intro, SilphCo_3F_Text_PostgameGrunt4Defeat
	msgbox SilphCo_3F_Text_PostgameGrunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_Text_PostgameGrunt4Intro::
    .string "Els Rockets mai ens rendim!$"

SilphCo_3F_Text_PostgameGrunt4Defeat::
    .string "Estem acabats!$"

SilphCo_3F_Text_PostgameGrunt4PostBattle::
    .string "Aquesta era la nostra última\n"
    .string "oportunitat.\p"
    .string "El Cap ha tornat a prendre\n"
    .string "ostatge el President de Silph.\p"
    .string "No hi ha marxa enrere!$"

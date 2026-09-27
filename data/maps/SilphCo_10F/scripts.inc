SilphCo_10F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_10F_OnLoad
	.byte 0

SilphCo_10F_OnLoad::
	call_if_unset FLAG_SILPH_10F_DOOR, EventScript_Close10FDoor
	end

SilphCo_10F_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL, 1
	release
	end

SilphCo_10F_EventScript_ItemCarbos::
	finditem ITEM_CARBOS, 1
	release
	end

SilphCo_10F_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY, 1
	release
	end

SilphCo_10F_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_10F_EventScript_WorkerFRocketsGone
	msgbox SilphCo_10F_Text_WaaaImScared
	release
	end

SilphCo_10F_EventScript_WorkerFRocketsGone::
	msgbox SilphCo_10F_Text_KeepMeCryingASecret
	release
	end

SilphCo_10F_EventScript_FloorSign::
	msgbox SilphCo_10F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_10F_EventScript_Travis::
	trainerbattle_single TRAINER_SCIENTIST_TRAVIS, SilphCo_10F_Text_TravisIntro, SilphCo_10F_Text_TravisDefeat
	msgbox SilphCo_10F_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_10F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_39, SilphCo_10F_Text_GruntIntro, SilphCo_10F_Text_GruntDefeat
	msgbox SilphCo_10F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_10F_Text_GruntIntro::
    .string "Benvingut al pis 10!\n"
    .string "Quina gentilesa de venir!$"

SilphCo_10F_Text_GruntDefeat::
    .string "Estic astorat!$"

SilphCo_10F_Text_GruntPostBattle::
    .string "Bon intent, però la sala de\n"
    .string "juntes és un pis més amunt.$"

SilphCo_10F_Text_TravisIntro::
    .string "N'hi ha prou dels teus jocs!$"

SilphCo_10F_Text_TravisDefeat::
    .string "No queden continues!$"

SilphCo_10F_Text_TravisPostBattle::
    .string "Estàs satisfet amb guanyar-me?\n"
    .string "Doncs vés-te'n a casa!$"

SilphCo_10F_Text_WaaaImScared::
    .string "Buaaa!\n"
    .string "Tinc por!$"

SilphCo_10F_Text_KeepMeCryingASecret::
    .string "Que he plorat…\n"
    .string "Si us plau, guarda el secret.$"

SilphCo_10F_Text_FloorSign::
    .string "Seu Central de Silph S.A.\n"
    .string "10è pis$"

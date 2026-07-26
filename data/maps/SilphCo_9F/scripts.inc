SilphCo_9F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_9F_OnLoad
	.byte 0

SilphCo_9F_OnLoad::
	call_if_unset FLAG_SILPH_9F_DOOR_1, EventScript_Close9FDoor1
	call_if_unset FLAG_SILPH_9F_DOOR_2, EventScript_Close9FDoor2
	call_if_unset FLAG_SILPH_9F_DOOR_3, EventScript_Close9FDoor3
	call_if_unset FLAG_SILPH_9F_DOOR_4, EventScript_Close9FDoor4
	end

SilphCo_9F_EventScript_HealWoman::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_9F_EventScript_HealWomanRocketsGone
	msgbox SilphCo_9F_Text_YouShouldTakeQuickNap
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox SilphCo_9F_Text_DontGiveUp
	release
	end

SilphCo_9F_EventScript_HealWomanRocketsGone::
	msgbox SilphCo_9F_Text_ThankYouSoMuch
	release
	end

SilphCo_9F_EventScript_FloorSign::
	msgbox SilphCo_9F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_9F_EventScript_Ed::
	trainerbattle_single TRAINER_SCIENTIST_ED, SilphCo_9F_Text_EdIntro, SilphCo_9F_Text_EdDefeat
	msgbox SilphCo_9F_Text_EdPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_37, SilphCo_9F_Text_Grunt1Intro, SilphCo_9F_Text_Grunt1Defeat
	msgbox SilphCo_9F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_38, SilphCo_9F_Text_Grunt2Intro, SilphCo_9F_Text_Grunt2Defeat
	msgbox SilphCo_9F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_Text_YouShouldTakeQuickNap::
    .string "Sembles cansat.\n"
    .string "Hauries de fer una migdiada.$"

SilphCo_9F_Text_DontGiveUp::
    .string "No et rendeixis!$"

SilphCo_9F_Text_ThankYouSoMuch::
    .string "Moltes gràcies.$"

SilphCo_9F_Text_Grunt1Intro::
    .string "Els teus Pokémon sembla que\n"
    .string "t'adoren, nen!$"

SilphCo_9F_Text_Grunt1Defeat::
    .string "Ghaaah!$"

SilphCo_9F_Text_Grunt1PostBattle::
    .string "Si hagués començat com a\n"
    .string "entrenador a la teva edat…$"

SilphCo_9F_Text_EdIntro::
    .string "Els teus Pokémon tenen punts\n"
    .string "febles! Puc aprofitar-los!$"

SilphCo_9F_Text_EdDefeat::
    .string "M'has clavat!$"

SilphCo_9F_Text_EdPostBattle::
    .string "Explotar punts febles funciona.\n"
    .string "Pensa en avantatges de tipus.$"

SilphCo_9F_Text_Grunt2Intro::
    .string "Sóc un dels quatre Germans\n"
    .string "Rocket!$"

SilphCo_9F_Text_Grunt2Defeat::
    .string "Warg!\n"
    .string "Germans, he perdut!$"

SilphCo_9F_Text_Grunt2PostBattle::
    .string "Els meus germans em venjaran!$"

SilphCo_9F_Text_FloorSign::
    .string "Seu Central de Silph S.A.\n"
    .string "9è pis$"

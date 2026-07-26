SilphCo_8F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_8F_OnLoad
	.byte 0

SilphCo_8F_OnLoad::
	call_if_unset FLAG_SILPH_8F_DOOR, EventScript_Close8FDoor
	end

SilphCo_8F_EventScript_ItemIron::
	finditem ITEM_IRON, 1
	release
	end

SilphCo_8F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_8F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_8F_Text_WonderIfSilphIsFinished
	release
	end

SilphCo_8F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_8F_Text_ThanksForSavingUs
	release
	end

SilphCo_8F_EventScript_FloorSign::
	msgbox SilphCo_8F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_8F_EventScript_Parker::
	trainerbattle_single TRAINER_SCIENTIST_PARKER, SilphCo_8F_Text_ParkerIntro, SilphCo_8F_Text_ParkerDefeat
	msgbox SilphCo_8F_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_32, SilphCo_8F_Text_Grunt1Intro, SilphCo_8F_Text_Grunt1Defeat
	msgbox SilphCo_8F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_36, SilphCo_8F_Text_Grunt2Intro, SilphCo_8F_Text_Grunt2Defeat
	msgbox SilphCo_8F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_Text_WonderIfSilphIsFinished::
    .string "Em pregunto si Silph s'ha\n"
    .string "acabat…$"

SilphCo_8F_Text_ThanksForSavingUs::
    .string "Gràcies per salvar-nos!$"

SilphCo_8F_Text_Grunt1Intro::
    .string "Fins aquí has arribat!$"

SilphCo_8F_Text_Grunt1Defeat::
    .string "No n'hi ha prou!$"

SilphCo_8F_Text_Grunt1PostBattle::
    .string "Si no tornes enrere…\n"
    .string "Demanaré reforços!$"

SilphCo_8F_Text_ParkerIntro::
    .string "Ens estàs causant problemes!$"

SilphCo_8F_Text_ParkerDefeat::
    .string "Eh?\n"
    .string "He perdut?$"

SilphCo_8F_Text_ParkerPostBattle::
    .string "Bé, què et sembla el laberint\n"
    .string "de l'Edifici Silph?$"

SilphCo_8F_Text_Grunt2Intro::
    .string "Sóc un dels quatre Germans\n"
    .string "Rocket!$"

SilphCo_8F_Text_Grunt2Defeat::
    .string "Uuh!\n"
    .string "Oh, Germans!$"

SilphCo_8F_Text_Grunt2PostBattle::
    .string "Et deixo en mans dels meus\n"
    .string "germans.$"

SilphCo_8F_Text_FloorSign::
    .string "Seu Central de Silph S.A.\n"
    .string "8è pis$"

SilphCo_8F_EventScript_Scientist::
	lock
	faceplayer
	msgbox SilphCo_8F_Text_ToRocketBossMonsAreTools
	release
	end

SilphCo_8F_Text_ToRocketBossMonsAreTools::
    .string "El Cap de l'Equip Rocket és\n"
    .string "terriblement cruel!\p"
    .string "Per a ell, els Pokémon són\n"
    .string "només eines.\p"
    .string "Què passarà si aquell tirà\n"
    .string "s'apodera de la nostra empresa…$"

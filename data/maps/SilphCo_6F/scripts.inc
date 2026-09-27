SilphCo_6F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_6F_OnLoad
	.byte 0

SilphCo_6F_OnLoad::
	call_if_unset FLAG_SILPH_6F_DOOR, EventScript_Close6FDoor
	end

SilphCo_6F_EventScript_ItemHPUp::
	finditem ITEM_HP_UP, 1
	release
	end

SilphCo_6F_EventScript_ItemXSpecial::
	finditem ITEM_X_SPECIAL, 1
	release
	end

SilphCo_6F_EventScript_WorkerM2::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_6F_EventScript_WorkerM2RocketsGone
	msgbox SilphCo_6F_Text_TargetedSilphForOurMonProducts
	release
	end

SilphCo_6F_EventScript_WorkerM2RocketsGone::
	msgbox SilphCo_6F_Text_ComeWorkForSilphWhenYoureOlder
	release
	end

SilphCo_6F_EventScript_WorkerM3::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_6F_EventScript_WorkerM3RocketsGone
	msgbox SilphCo_6F_Text_RocketsTookOverBuilding
	release
	end

SilphCo_6F_EventScript_WorkerM3RocketsGone::
	msgbox SilphCo_6F_Text_BetterGetBackToWork
	release
	end

SilphCo_6F_EventScript_WorkerM1::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_6F_EventScript_WorkerM1RocketsGone
	msgbox SilphCo_6F_Text_HelpMePlease
	release
	end

SilphCo_6F_EventScript_WorkerM1RocketsGone::
	msgbox SilphCo_6F_Text_WeGotEngaged
	release
	end

SilphCo_6F_EventScript_WorkerF1::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_6F_EventScript_WorkerF1RocketsGone
	msgbox SilphCo_6F_Text_ThatManIsSuchACoward
	release
	end

SilphCo_6F_EventScript_WorkerF1RocketsGone::
	msgbox SilphCo_6F_Text_NeedsMeToLookAfterHim
	release
	end

SilphCo_6F_EventScript_WorkerF2::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_6F_EventScript_WorkerF2RocketsGone
	msgbox SilphCo_6F_Text_RocketsTryingToConquerWorld
	release
	end

SilphCo_6F_EventScript_WorkerF2RocketsGone::
	msgbox SilphCo_6F_Text_RocketsRanAwayBecauseOfYou
	release
	end

SilphCo_6F_EventScript_FloorSign::
	msgbox SilphCo_6F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_6F_EventScript_Taylor::
	trainerbattle_single TRAINER_SCIENTIST_TAYLOR, SilphCo_6F_Text_TaylorIntro, SilphCo_6F_Text_TaylorDefeat
	msgbox SilphCo_6F_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_30, SilphCo_6F_Text_Grunt1Intro, SilphCo_6F_Text_Grunt1Defeat
	msgbox SilphCo_6F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_31, SilphCo_6F_Text_Grunt2Intro, SilphCo_6F_Text_Grunt2Defeat
	msgbox SilphCo_6F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_Text_RocketsTookOverBuilding::
    .string "Els Rockets han vingut i han\n"
    .string "pres l'edifici!$"

SilphCo_6F_Text_BetterGetBackToWork::
    .string "Bé, millor que torni a la feina.$"

SilphCo_6F_Text_HelpMePlease::
    .string "Oh, mare, oh, mare.\n"
    .string "Ajuda'm, si us plau!$"

SilphCo_6F_Text_WeGotEngaged::
    .string "Ens hem promès.\n"
    .string "Heheh!$"

SilphCo_6F_Text_ThatManIsSuchACoward::
    .string "Aquell home del meu costat…\n"
    .string "És un covard!$"

SilphCo_6F_Text_NeedsMeToLookAfterHim::
    .string "És tan desvalgut que necessita\n"
    .string "algú com jo per cuidar-lo.$"

SilphCo_6F_Text_RocketsTryingToConquerWorld::
    .string "L'Equip Rocket intenta conquerir\n"
    .string "el món amb Pokémon.$"

SilphCo_6F_Text_RocketsRanAwayBecauseOfYou::
    .string "L'Equip Rocket ha fugit, i tot és\n"
    .string "gràcies a tu!$"

SilphCo_6F_Text_TargetedSilphForOurMonProducts::
    .string "Deuen haver apuntat a Silph pels\n"
    .string "nostres productes Pokémon.$"

SilphCo_6F_Text_ComeWorkForSilphWhenYoureOlder::
    .string "Vine a treballar a Silph quan\n"
    .string "siguis més gran.$"

SilphCo_6F_Text_Grunt1Intro::
    .string "Sóc un dels quatre Germans\n"
    .string "Rocket!$"

SilphCo_6F_Text_Grunt1Defeat::
    .string "Cremat!$"

SilphCo_6F_Text_Grunt1PostBattle::
    .string "No importa!\n"
    .string "Els meus germans em venjaran!$"

SilphCo_6F_Text_TaylorIntro::
    .string "Aquell President pudent!\p"
    .string "Ben merescut que ho passa per\n"
    .string "enviar-me a la sucursal\l"
    .string "d'Unova!\p"
    .string "Per això l'Equip Rocket ens ha\n"
    .string "atacat, segur!$"

SilphCo_6F_Text_TaylorDefeat::
    .string "Llamps!$"

SilphCo_6F_Text_TaylorPostBattle::
    .string "Sucursal d'Unova?\n"
    .string "Això és a l'altra punta del món!$"

SilphCo_6F_Text_Grunt2Intro::
    .string "Goses trair l'Equip Rocket?$"

SilphCo_6F_Text_Grunt2Defeat::
    .string "Traïdor!$"

SilphCo_6F_Text_Grunt2PostBattle::
    .string "Si defenses la justícia, ens\n"
    .string "traeixes a nosaltres els dolents!$"

SilphCo_6F_Text_FloorSign::
    .string "Seu Central de Silph S.A.\n"
    .string "6è pis$"

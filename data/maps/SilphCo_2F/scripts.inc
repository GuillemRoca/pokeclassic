SilphCo_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_2F_OnLoad
	.byte 0

SilphCo_2F_OnLoad::
	call_if_unset FLAG_SILPH_2F_DOOR_1, EventScript_Close2FDoor1
	call_if_unset FLAG_SILPH_2F_DOOR_2, EventScript_Close2FDoor2
	end

SilphCo_2F_EventScript_FloorSign::
	msgbox SilphCo_2F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_2F_Text_FloorSign::
    .string "Seu Central de Silph S.A.\n"
    .string "2n pis$"

SilphCo_2F_EventScript_Connor::
	trainerbattle_single TRAINER_SCIENTIST_CONNOR, SilphCo_2F_Text_ConnorIntro, SilphCo_2F_Text_ConnorDefeat
	msgbox SilphCo_2F_Text_ConnorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_Text_ConnorIntro::
    .string "Ajuda!\n"
    .string "Sóc un empleat de Silph.$"

SilphCo_2F_Text_ConnorDefeat::
    .string "Com has sabut que era\n"
    .string "un Rocket?$"

SilphCo_2F_Text_ConnorPostBattle::
    .string "Treballo per Silph i per l'Equip\n"
    .string "Rocket alhora.$"

SilphCo_2F_EventScript_Jerry::
	trainerbattle_single TRAINER_SCIENTIST_JERRY, SilphCo_2F_Text_JerryIntro, SilphCo_2F_Text_JerryDefeat
	msgbox SilphCo_2F_Text_JerryPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_Text_JerryIntro::
    .string "Aquí és zona restringida!\n"
    .string "Vés-te'n a casa!$"

SilphCo_2F_Text_JerryDefeat::
    .string "Ets bo.$"

SilphCo_2F_Text_JerryPostBattle::
    .string "Pots resoldre el laberint d'aquí?\n"
    .string "No és fàcil, t'ho dic!$"

SilphCo_2F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_23, SilphCo_2F_Text_Grunt1Intro, SilphCo_2F_Text_Grunt1Defeat
	msgbox SilphCo_2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_Text_Grunt1Intro::
    .string "No es deixen entrar nens aquí!$"

SilphCo_2F_Text_Grunt1Defeat::
    .string "Dur!$"

SilphCo_2F_Text_Grunt1PostBattle::
    .string "Les rajoles en forma de diamant\n"
    .string "són blocs de teletransport.\p"
    .string "Són transportadors d'aquest\n"
    .string "edifici d'alta tecnologia.$"

SilphCo_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_24, SilphCo_2F_Text_Grunt2Intro, SilphCo_2F_Text_Grunt2Defeat
	msgbox SilphCo_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_Text_Grunt2Intro::
    .string "Ei, nen!\n"
    .string "Què fas voltant per aquí?$"

SilphCo_2F_Text_Grunt2Defeat::
    .string "He fallat!$"

SilphCo_2F_Text_Grunt2PostBattle::
    .string "Silph S.A. s'associarà amb\n"
    .string "l'Equip Rocket!$"


.set LOCALID_FUGITIVE, 16

Route6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route6_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route6_OnResume
	.byte 0

Route6_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route6_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route6_EventScript_Keigo::
	trainerbattle_single REMATCHABLE_TRAINER_BUG_CATCHER_KEIGO_1, Route6_Text_KeigoIntro, Route6_Text_KeigoDefeat, Route6_EventScript_RegisterKeigoAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route6_EventScript_KeigoRematch
	msgbox Route6_Text_KeigoPostBattle, MSGBOX_DEFAULT
	release
	end

Route6_Text_KeigoIntro::
    .string "Aquí no hi ha gaires insectes.$"

Route6_Text_KeigoDefeat::
    .string "No!\n"
    .string "No pot ser!$"

Route6_Text_KeigoPostBattle::
    .string "M'agraden els insectes, així que\n"
    .string "tornaré al Bosc Viridian.$"

Route6_EventScript_RegisterKeigoAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route6_Text_KeigoRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_BUG_CATCHER_KEIGO_1
	release
	end

Route6_Text_KeigoRegister:
	.string "Demostrar que els Pokémon Insecte\n"
	.string "són els més forts. Fem la\l"
	.string "revenja algun dia!$"

Route6_EventScript_KeigoRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_BUG_CATCHER_KEIGO_1, Route6_Text_KeigoRematchIntro, Route6_Text_KeigoDefeat
	msgbox Route6_Text_KeigoRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Text_KeigoRematchIntro::
	.string "Intento trobar alguna cosa bona\n"
	.string "que no sigui un Pokémon Insecte…$"

Route6_Text_KeigoRematchPostBattle::
	.string "Pensava que havia de diversificar,\n"
	.string "però sempre estimaré els Insecte!$"

Route6_EventScript_Ricky::
	trainerbattle_single TRAINER_CAMPER_RICKY, Route6_Text_RickyIntro, Route6_Text_RickyDefeat
	msgbox Route6_Text_RickyPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Text_RickyIntro::
    .string "Qui hi ha?\n"
    .string "Deixa d'escoltar-nos!$"

Route6_Text_RickyDefeat::
    .string "No puc guanyar!$"

Route6_Text_RickyPostBattle::
    .string "Xiu-xiu…\n"
    .string "Xiu-xiu…$"

Route6_EventScript_Nancy::
	trainerbattle_single TRAINER_PICNICKER_NANCY, Route6_Text_NancyIntro, Route6_Text_NancyDefeat
	msgbox Route6_Text_NancyPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Text_NancyIntro::
    .string "Perdona!\n"
    .string "Això és una conversa privada!$"

Route6_Text_NancyDefeat::
    .string "Uf!\n"
    .string "Odio perdre.$"

Route6_Text_NancyPostBattle::
    .string "Xiu-xiu…\n"
    .string "Xiu-xiu…$"

Route6_EventScript_Elijah::
	trainerbattle_single TRAINER_BUG_CATCHER_ELIJAH, Route6_Text_ElijahIntro, Route6_Text_ElijahDefeat
	msgbox Route6_Text_ElijahPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Text_ElijahIntro::
    .string "No t'havia vist mai per aquí.\n"
    .string "Ets bo?$"

Route6_Text_ElijahDefeat::
    .string "Ets massa bo!$"

Route6_Text_ElijahPostBattle::
    .string "Els meus Pokémon són febles?\n"
    .string "O sóc jo que sóc dolent?\l"
    .string "Tu què creus?$"

Route6_EventScript_Isabelle::
	trainerbattle_single TRAINER_PICNICKER_ISABELLE, Route6_Text_IsabelleIntro, Route6_Text_IsabelleDefeat
	msgbox Route6_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Text_IsabelleIntro::
    .string "Jo?\n"
    .string "Bé, d'acord. Juguem!$"

Route6_Text_IsabelleDefeat::
    .string "Les coses no han funcionat…$"

Route6_Text_IsabellePostBattle::
    .string "Vull ser més forta.\n"
    .string "Quin és el teu secret?$"

Route6_EventScript_Jeff::
	trainerbattle_single TRAINER_CAMPER_JEFF, Route6_Text_JeffIntro, Route6_Text_JeffDefeat
	msgbox Route6_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Text_JeffIntro::
    .string "Eh?\n"
    .string "Vols parlar amb mi?$"

Route6_Text_JeffDefeat::
    .string "Quin fàstic…\n"
    .string "No he pogut superar el repte…$"

Route6_Text_JeffPostBattle::
    .string "Hauria de portar més Pokémon.\n"
    .string "Així em sentiré més segur.$"

Route6_EventScript_UndergroundPathSign::
	msgbox Route6_Text_UndergroundPathSign, MSGBOX_SIGN
	release
	end

Route6_Text_UndergroundPathSign::
    .string "Pas Subterrani\n"
    .string "Cerulean City - Vermilion City$"

Route6_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end

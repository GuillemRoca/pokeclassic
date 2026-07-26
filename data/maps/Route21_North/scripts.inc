.set LOCALID_FUGITIVE, 7

Route21_North_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route21_North_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route21_North_OnResume
	.byte 0

Route21_North_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route21_North_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route21_North_EventScript_Anri::
	trainerbattle_single REMATCHABLE_TRAINER_COOLTRAINER_ANRI_1, Route21_North_Text_AnriIntro, Route21_North_Text_AnriDefeat, Route21_North_EventScript_RegisterAnriAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route21_North_EventScript_AnriRematch
	msgbox Route21_North_Text_AnriPostBattle, MSGBOX_DEFAULT
	release
	end

Route21_North_Text_AnriIntro::
    .string "M'entreno per al Camí Victòria!$"

Route21_North_Text_AnriDefeat::
    .string "Ho he donat tot.$"

Route21_North_Text_AnriPostBattle::
    .string "Només els entrenadors més forts\n"
    .string "arriben a l'Alt Comandament.$"

Route21_North_EventScript_RegisterAnriAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route21_North_Text_AnriRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_COOLTRAINER_ANRI_1
	release
	end

Route21_North_Text_AnriRegister:
	.string "M'agrada el teu estil!\p"
	.string "Truca'm si trobes un bon lloc\n"
	.string "per entrenar!$"

Route21_North_EventScript_AnriRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_COOLTRAINER_ANRI_1, Route21_North_Text_AnriRematchIntro, Route21_North_Text_AnriDefeat
	msgbox Route21_North_Text_AnriRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_North_Text_AnriRematchIntro::
	.string "Molt bé! Hora de practicar!$"

Route21_North_Text_AnriRematchPostBattle::
	.string "Necessitaràs més que força bruta\n"
	.string "per superar l'Alt Comandament!$"


Route21_North_EventScript_Ronald::
	trainerbattle_single TRAINER_FISHERMAN_RONALD, Route21_North_Text_RonaldIntro, Route21_North_Text_RonaldDefeat
	msgbox Route21_North_Text_RonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_North_Text_RonaldIntro::
	.string "Vols saber si piquen?$"

Route21_North_Text_RonaldDefeat::
	.string "Llamps!$"

Route21_North_Text_RonaldPostBattle::
	.string "No puc pescar res de bo.\n"
	.string "Ni un bon Pokémon!$"

Route21_North_EventScript_Wade::
	trainerbattle_single TRAINER_FISHERMAN_WADE, Route21_North_Text_WadeIntro, Route21_North_Text_WadeDefeat
	msgbox Route21_North_Text_WadePostBattle, MSGBOX_AUTOCLOSE
	end

Route21_North_Text_WadeIntro::
	.string "He pescat molt!\n"
	.string "Vols provar sort?$"

Route21_North_Text_WadeDefeat::
	.string "Hehe, els Magikarp no donen\n"
	.string "la talla, oi?$"

Route21_North_Text_WadePostBattle::
	.string "Sembla que només pesco Magikarp!$"

Route21_North_EventScript_Spencer::
	trainerbattle_single TRAINER_SWIMMER_MALE_SPENCER, Route21_North_Text_SpencerIntro, Route21_North_Text_SpencerDefeat
	msgbox Route21_North_Text_SpencerPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_North_Text_SpencerIntro::
	.string "El mar neteja el meu cos i ànima!$"

Route21_North_Text_SpencerDefeat::
	.string "Ayah!$"

Route21_North_Text_SpencerPostBattle::
	.string "El mar és genial, però també\n"
	.string "m'agraden les muntanyes.$"

Route21_North_EventScript_Lil::
	trainerbattle_double TRAINER_SIS_AND_BRO_LIL_IAN, Route21_North_Text_LilIntro, Route21_North_Text_LilDefeat, Route21_North_Text_LilNotEnoughMons
	msgbox Route21_North_Text_LilPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_North_Text_LilIntro::
	.string "Lil: Eh? Un combat?\n"
	.string "Ian, no ho pots fer sol?$"

Route21_North_Text_LilDefeat::
	.string "Lil: Oh, veus?\n"
	.string "Hem perdut. Content?$"

Route21_North_Text_LilPostBattle::
	.string "Lil: Estic cansada.\n"
	.string "No podem anar a casa ja?$"

Route21_North_Text_LilNotEnoughMons::
	.string "Lil: Eh? Un combat?\n"
	.string "No em ve de gust fer-ho sola.\l"
	.string "Porta dos Pokémon, vols?$"

Route21_North_EventScript_Ian::
	trainerbattle_double TRAINER_SIS_AND_BRO_LIL_IAN, Route21_North_Text_IanIntro, Route21_North_Text_IanDefeat, Route21_North_Text_IanNotEnoughMons
	msgbox Route21_North_Text_IanPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_North_Text_IanIntro::
	.string "Ian: La meva germana no fa prou\n"
	.string "exercici, l'he fet venir.$"

Route21_North_Text_IanDefeat::
	.string "Ian: Aiii, germana!\n"
	.string "Espavila't!$"

Route21_North_Text_IanPostBattle::
	.string "Ian: Va, germana!\p"
	.string "Així no perdràs pes!$"

Route21_North_Text_IanNotEnoughMons::
	.string "Ian: Volem un combat dos contra\n"
	.string "dos. Porta dos Pokémon!$"


Route21_RocketFugitive::
	trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE
	waitse
	fadescreen FADE_FROM_BLACK
	end

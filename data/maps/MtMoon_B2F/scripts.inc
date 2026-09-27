.set LOCALID_DOME_FOSSIL,  1
.set LOCALID_HELIX_FOSSIL, 2
.set LOCALID_MIGUEL,       3
.set LOCALID_JESSIE,	   12
.set LOCALID_JAMES,		   13

MtMoon_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_B2F_OnTransition
	.byte 0

MtMoon_B2F_OnTransition::
	call_if_unset FLAG_GOT_FOSSIL_FROM_MT_MOON, MtMoon_B2F_EventScript_ShowFossils
	end

MtMoon_B2F_EventScript_ShowFossils::
	clearflag FLAG_HIDE_DOME_FOSSIL
	clearflag FLAG_HIDE_HELIX_FOSSIL
	return

MtMoon_B2F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT, MtMoon_B2F_Text_Grunt1Intro, MtMoon_B2F_Text_Grunt1Defeat
	msgbox MtMoon_B2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_Text_Grunt1Intro::
    .string "Nosaltres, l'Equip Rocket, trobarem\n"
    .string "els fòssils!\p"
    .string "Reviure Pokémon d'ells ens farà\n"
    .string "guanyar una fortuna!$"

MtMoon_B2F_Text_Grunt1Defeat::
    .string "Argh!\n"
    .string "Ara sí que estic enfadat!$"

MtMoon_B2F_Text_Grunt1PostBattle::
    .string "M'has fet enfadar!\n"
    .string "L'Equip Rocket et posarà a la\l"
    .string "llista negra!$"

MtMoon_B2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_2, MtMoon_B2F_Text_Grunt2Intro, MtMoon_B2F_Text_Grunt2Defeat
	msgbox MtMoon_B2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_Text_Grunt2Intro::
    .string "Nosaltres, l'Equip Rocket, som\n"
    .string "gàngsters Pokémon!\l"
    .string "Imposem por amb la nostra força!$"

MtMoon_B2F_Text_Grunt2Defeat::
    .string "L'he espifiada!$"

MtMoon_B2F_Text_Grunt2PostBattle::
    .string "Maleït siguis!\n"
    .string "Els meus companys no permetran\l"
    .string "això!$"

MtMoon_B2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_3, MtMoon_B2F_Text_Grunt3Intro, MtMoon_B2F_Text_Grunt3Defeat
	msgbox MtMoon_B2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_Text_Grunt3Intro::
    .string "Estem fent un gran cop aquí!\n"
    .string "Fes el camp, nen!$"

MtMoon_B2F_Text_Grunt3Defeat::
    .string "Vaja, ets bo…$"

MtMoon_B2F_Text_Grunt3PostBattle::
    .string "Si trobes un fòssil, dóna-me'l\n"
    .string "i vés-te'n!$"

MtMoon_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_4, MtMoon_B2F_Text_Grunt4Intro, MtMoon_B2F_Text_Grunt4Defeat
	msgbox MtMoon_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_Text_Grunt4Intro::
    .string "Els nens petits no haurien de\n"
    .string "ficar-se amb els grans!\p"
    .string "Podria ser perillós!$"

MtMoon_B2F_Text_Grunt4Defeat::
    .string "Estic furiós!$"

MtMoon_B2F_Text_Grunt4PostBattle::
    .string "Els Pokémon vivien aquí molt abans\n"
    .string "que arribessin les persones.$"

MtMoon_B2F_EventScript_MiguelTrigger::
	lockall
	applymovement LOCALID_MIGUEL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 3
	goto MtMoon_B2F_EventScript_BattleMiguel
	end

MtMoon_B2F_EventScript_Miguel::
	lock
	faceplayer
	goto_if_set FLAG_GOT_FOSSIL_FROM_MT_MOON, MtMoon_B2F_EventScript_MiguelFossilPicked
	goto_if_defeated TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_EventScript_MiguelGoPickFossil
	goto MtMoon_B2F_EventScript_BattleMiguel
	end

MtMoon_B2F_EventScript_BattleMiguel::
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, 0
	msgbox MtMoon_B2F_Text_MiguelIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_Text_MiguelDefeat
	setvar VAR_MT_MOON_STATE, 1
	msgbox MtMoon_B2F_Text_WellEachTakeAFossil, MSGBOX_DEFAULT
	release
	end

MtMoon_B2F_Text_MiguelIntro::
    .string "Ei, para!\p"
    .string "He trobat aquests fòssils!\n"
    .string "Tots dos són meus!$"

MtMoon_B2F_Text_MiguelDefeat::
    .string "D'acord!\n"
    .string "Compartiré!$"

MtMoon_B2F_Text_WellEachTakeAFossil::
    .string "Ens agafarem un fòssil cadascú!\n"
    .string "Sense ser cobdiciós!$"

MtMoon_B2F_EventScript_MiguelFossilPicked::
	msgbox MtMoon_B2F_Text_LabOnCinnabarRegeneratesFossils, MSGBOX_DEFAULT
	release
	end

MtMoon_B2F_Text_LabOnCinnabarRegeneratesFossils::
    .string "Lluny d'aquí, a l'Illa Cinnabar,\n"
    .string "hi ha un Laboratori Pokémon.\p"
    .string "Fan recerca sobre la regeneració\n"
    .string "de fòssils.$"

MtMoon_B2F_EventScript_MiguelGoPickFossil::
	msgbox MtMoon_B2F_Text_WellEachTakeAFossil, MSGBOX_DEFAULT
	release
	end

MtMoon_B2F_EventScript_DomeFossil::
	lock
	faceplayer
	msgbox MtMoon_B2F_Text_YouWantDomeFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtMoon_B2F_EventScript_DontTakeFossil
	removeobject LOCALID_DOME_FOSSIL
	setflag FLAG_HIDE_DOME_FOSSIL
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message MtMoon_B2F_Text_ObtainedDomeFossil
	waitmessage
	waitfanfare
	additem ITEM_DOME_FOSSIL, 1
	delay 10
	closemessage
	applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_MiguelToHelixFossil
	waitmovement 3
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message MtMoon_B2F_Text_ThenThisFossilIsMine
	waitmessage
	waitfanfare
	removeobject LOCALID_HELIX_FOSSIL
	setvar VAR_FOSSIL_SELECTION, 1
	setflag FLAG_GOT_FOSSIL_FROM_MT_MOON
	release
	end

MtMoon_B2F_Text_YouWantDomeFossil::
    .string "Vols el Fòssil Domo?$"

MtMoon_B2F_Text_ObtainedDomeFossil::
    .string "Has obtingut el Fòssil Domo!$"

MtMoon_B2F_Movement_MiguelToHelixFossil::
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

MtMoon_B2F_EventScript_HelixFossil::
	lock
	faceplayer
	msgbox MtMoon_B2F_Text_YouWantHelixFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtMoon_B2F_EventScript_DontTakeFossil
	removeobject LOCALID_HELIX_FOSSIL
	setflag FLAG_HIDE_HELIX_FOSSIL
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message MtMoon_B2F_Text_ObtainedHelixFossil
	waitmessage
	waitfanfare
	additem ITEM_HELIX_FOSSIL, 1
	delay 10
	closemessage
	applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_MiguelToDomeFossil
	waitmovement 3
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message MtMoon_B2F_Text_ThenThisFossilIsMine
	waitmessage
	waitfanfare
	removeobject LOCALID_DOME_FOSSIL
	setvar VAR_FOSSIL_SELECTION, 2
	setflag FLAG_GOT_FOSSIL_FROM_MT_MOON
	release
	end

MtMoon_B2F_Text_YouWantHelixFossil::
    .string "Vols el Fòssil Hèlix?$"

MtMoon_B2F_Text_ObtainedHelixFossil::
    .string "Has obtingut el Fòssil Hèlix!$"

MtMoon_B2F_Text_ThenThisFossilIsMine::
    .string "Molt bé.\n"
    .string "Doncs aquest fòssil és meu!$"

MtMoon_B2F_Movement_MiguelToDomeFossil::
	walk_up
	walk_up
	walk_up
	step_end

MtMoon_B2F_EventScript_DontTakeFossil::
	release
	end

MtMoon_B2F_EventScript_ItemStarPiece::
	finditem ITEM_STAR_PIECE, 1
	end

MtMoon_B2F_EventScript_ItemTM46::
	finditem ITEM_TM46, 1
	end

MtMoon_B2F_EventScript_ItemRevive::
	finditem ITEM_REVIVE, 1
	end

MtMoon_B2F_EventScript_ItemAntidote::
	finditem ITEM_ANTIDOTE, 1
	end

MtMoon_B2F_EventScript_RocketDuoTrigger1::
	lockall
	msgbox MtMoon_B2F_Text_StopRightThere, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_FaceRockets1
	waitmovement 0
	goto MtMoon_B2F_EventScript_RocketDuo
	end

Movement_FaceRockets1:
	walk_up
	walk_right
	step_end

MtMoon_B2F_EventScript_RocketDuoTrigger2::
	lockall
	msgbox MtMoon_B2F_Text_StopRightThere, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_FaceRockets2
	waitmovement 0
	goto MtMoon_B2F_EventScript_RocketDuo
	end

Movement_FaceRockets2:
	walk_up
	face_right
	step_end

MtMoon_B2F_Text_StopRightThere::
	.string "???: Para aquí mateix!$"

MtMoon_B2F_EventScript_RocketDuo::
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	clearflag FLAG_HIDE_MT_MOON_JESSIE_JAMES
	addobject LOCALID_JESSIE
	addobject LOCALID_JAMES
	applymovement LOCALID_JESSIE, MtMoon_Movement_PrepareForTrouble
	applymovement LOCALID_JAMES, MtMoon_Movement_AndMakeItDouble
	waitmovement 13
	trainerbattle_double TRAINER_ROCKET_DUO_1, MtMoon_B2F_Text_RocketDuoIntro, MtMoon_B2F_Text_RocketDuoDefeat, Text_NeedTwoMons, MtMoon_B2F_EventScript_RocketDuoDefeated, NO_MUSIC
	end

MtMoon_B2F_EventScript_RocketDuoDefeated::
	delay 10
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	msgbox MtMoon_B2F_Text_RocketDuoDefeated, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_MT_MOON_JESSIE_JAMES
	setflag FLAG_HIDE_MT_MOON_ROCKETS
	removeobject LOCALID_JESSIE
	removeobject LOCALID_JAMES
	setvar VAR_MT_MOON_STATE, 2
	playse SE_EXIT
	waitse
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MtMoon_Movement_PrepareForTrouble:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	face_down
	step_end

MtMoon_Movement_AndMakeItDouble:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_left
	step_end

MtMoon_B2F_Text_RocketDuoIntro::
	.string "???: Aquest fòssil pertany\n"
	.string "a l'Equip Rocket!\p"
	.string "Rendeix-te ara, o prepara't\n"
	.string "per lluitar!$"

MtMoon_B2F_Text_RocketDuoDefeat::
	.string "Què, aquest marrec ens ha guanyat?$"

MtMoon_B2F_Text_RocketDuoDefeated::
	.string "Jessie: Això no s'acaba aquí, nen!\p"
	.string "James: L'Equip Rocket surt\n"
	.string "disparat a la velocitat de la llum!$"

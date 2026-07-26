.set LOCALID_GIOVANNI,  1
.set LOCALID_CUBONE, 	2
.set LOCALID_JAMES,		3
.set LOCALID_ROCKET2,	4
.set LOCALID_ROCKET3,  	5
.set LOCALID_JESSIE,	6
.set LOCALID_LIFT_KEY,  7

.set NUM_DOOR_GRUNTS_DEFEATED, VAR_TEMP_1

RocketHideout_B4F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B4F_OnLoad
	.byte 0

RocketHideout_B4F_OnLoad::
	setvar NUM_DOOR_GRUNTS_DEFEATED, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
	compare NUM_DOOR_GRUNTS_DEFEATED, 2
	call_if_ne RocketHideout_B4F_EventScript_SetBarrier
	end

RocketHideout_B4F_EventScript_CountGruntDefeated::
	addvar NUM_DOOR_GRUNTS_DEFEATED, 1
	return

RocketHideout_B4F_EventScript_Giovanni::
	lock
	faceplayer
	message RocketHideout_B4F_Text_GiovanniIntro
	waitmessage
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	trainerbattle_no_intro TRAINER_BOSS_GIOVANNI, RocketHideout_B4F_Text_GiovanniDefeat
	msgbox RocketHideout_B4F_Text_GiovanniPostBattle
	delay 10
	closemessage
	playse SE_BALL_OPEN
	waitse
	clearflag FLAG_HIDE_HIDEOUT_CUBONE
	addobject LOCALID_CUBONE
	playmoncry SPECIES_CUBONE, CRY_MODE_NORMAL
	waitmoncry
	msgbox RocketHideout_B4F_Text_MeetAgain
	fadescreen FADE_TO_BLACK
	closemessage
	removeobject LOCALID_GIOVANNI
	setflag FLAG_HIDE_CELADON_ROCKETS
	setflag FLAG_RESCUED_CUBONE
	removeobject LOCALID_JESSIE
	removeobject LOCALID_JAMES
	removeobject LOCALID_ROCKET2
	removeobject LOCALID_ROCKET3
	fadescreen FADE_FROM_BLACK
	goto RocketHideout_B4F_EventScript_Cubone
	end

RocketHideout_B4F_Text_GiovanniIntro::
    .string "???: Bé! He de dir que estic\n"
    .string "impressionat que hagis arribat\l"
    .string "aquí.\p"
    .string "L'Equip Rocket captura Pokémon\n"
    .string "d'arreu del món.\p"
    .string "Són eines importants per mantenir\n"
    .string "la nostra empresa criminal.\p"
    .string "Sóc el líder, Giovanni!\p"
    .string "Per la teva insolència, sentiràs\n"
    .string "un món de dolor!$"

RocketHideout_B4F_Text_GiovanniDefeat::
    .string "Què!\n"
    .string "Això no pot ser!$"

RocketHideout_B4F_Text_GiovanniPostBattle::
    .string "Giovanni: Veig que cries els teus\n"
    .string "Pokémon amb molta cura.\p"
    .string "Un nen com tu mai entendria el\n"
    .string "que espero aconseguir.\p"
    .string "Em faré enrere aquest cop, i\n"
    .string "alliberaré aquest Cubone.$"

RocketHideout_B4F_Text_MeetAgain::
    .string "Espero que ens tornem a trobar…$"

RocketHideout_B4F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_18, RocketHideout_B4F_Text_Grunt1Intro, RocketHideout_B4F_Text_Grunt1Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt1
	msgbox RocketHideout_B4F_Text_Grunt1PostBattle
	release
	end

RocketHideout_B4F_Text_Grunt1Intro::
    .string "L'ascensor no funciona?\n"
    .string "Qui té la Clau de l'Ascensor?$"

RocketHideout_B4F_Text_Grunt1Defeat::
    .string "No!$"

RocketHideout_B4F_EventScript_DefeatedGrunt1::
	msgbox RocketHideout_B4F_Text_Grunt1PostBattle
	addobject LOCALID_LIFT_KEY
	clearflag FLAG_HIDE_LIFT_KEY
	release
	end

RocketHideout_B4F_Text_Grunt1PostBattle::
    .string "Oh, no!\n"
    .string "Se m'ha caigut la Clau de\l"
    .string "l'Ascensor!$"

RocketHideout_B4F_EventScript_LiftKey::
	lock
	faceplayer
	removeobject LOCALID_LIFT_KEY
	giveitem ITEM_LIFT_KEY
	goto_if_eq  VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	release
	end

RocketHideout_B4F_EventScript_Grunt2::
	lock
	faceplayer
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_Text_Grunt2Intro, RocketHideout_B4F_Text_Grunt2Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt2
	msgbox RocketHideout_B4F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B4F_Text_Grunt2Intro::
    .string "Et conec!\n"
    .string "Vas arruïnar els plans al Mt. Moon!$"

RocketHideout_B4F_Text_Grunt2Defeat::
    .string "Un altre cop cremat!$"

RocketHideout_B4F_Text_Grunt2PostBattle::
    .string "Tens alguna cosa contra l'Equip\n"
    .string "Rocket?$"

RocketHideout_B4F_EventScript_DefeatedGrunt2::
	setvar NUM_DOOR_GRUNTS_DEFEATED, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
	compare NUM_DOOR_GRUNTS_DEFEATED, 2
	call_if_eq RocketHideout_B4F_EventScript_RemoveBarrier
	compare NUM_DOOR_GRUNTS_DEFEATED, 2
	call_if_eq RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval
	release
	end

RocketHideout_B4F_EventScript_Grunt3::
	lock
	faceplayer
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_Text_Grunt3Intro, RocketHideout_B4F_Text_Grunt3Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt3
	msgbox RocketHideout_B4F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B4F_Text_Grunt3Intro::
    .string "Com pots no veure la bellesa\n"
    .string "de la nostra maldat?$"

RocketHideout_B4F_Text_Grunt3Defeat::
    .string "Cap!\n"
    .string "Perdoni, t'he fallat!$"

RocketHideout_B4F_Text_Grunt3PostBattle::
    .string "Potser m'has derrotat, però\n"
    .string "en vindran més!$"

RocketHideout_B4F_EventScript_DefeatedGrunt3::
	setvar NUM_DOOR_GRUNTS_DEFEATED, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
	compare NUM_DOOR_GRUNTS_DEFEATED, 2
	call_if_eq RocketHideout_B4F_EventScript_RemoveBarrier
	compare NUM_DOOR_GRUNTS_DEFEATED, 2
	call_if_eq RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval
	release
	end

RocketHideout_B4F_EventScript_Jessie::
	trainerbattle_single TRAINER_ROCKET_HIDEOUT_JESSIE, RocketHideout_B4F_Text_JessieIntro, RocketHideout_B4F_Text_JessieDefeat
	msgbox RocketHideout_B4F_Text_JessiePostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B4F_Text_JessieIntro::
	.string "Jessie: Ets aquell marrec que no\n"
	.string "para d'interrompre els plans!$"

RocketHideout_B4F_Text_JessieDefeat::
	.string "Jessie: No! No! No!$"

RocketHideout_B4F_Text_JessiePostBattle::
	.string "Jessie: Potser m'has derrotat\n"
	.string "un altre cop, però el Cap\l"
	.string "s'encarregarà de tu per sempre.$"

RocketHideout_B4F_EventScript_James::
	trainerbattle_single TRAINER_ROCKET_HIDEOUT_JAMES, RocketHideout_B4F_Text_JamesIntro, RocketHideout_B4F_Text_JamesDefeat
	msgbox RocketHideout_B4F_Text_JamesPostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B4F_Text_JamesIntro::
	.string "James: Comences a treure la gràcia\n"
	.string "a tot això.$"

RocketHideout_B4F_Text_JamesDefeat::
	.string "James: Això realment comença\n"
	.string "a afectar-me!$"

RocketHideout_B4F_Text_JamesPostBattle::
	.string "James: Per cert, sento molt\n"
	.string "el que li va passar a la mare\l"
	.string "d'aquell Cubone...$"

RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval::
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	return

RocketHideout_B4F_EventScript_SetBarrier::
	setmetatile 17, 12, METATILE_SilphCo_HideoutBarrier_TopLeft_Floor, 1
	setmetatile 18, 12, METATILE_SilphCo_HideoutBarrier_TopRight_Floor, 1
	setmetatile 17, 13, METATILE_SilphCo_HideoutBarrier_BottomLeft, 1
	setmetatile 18, 13, METATILE_SilphCo_HideoutBarrier_BottomRight, 1
	setmetatile 17, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	return

RocketHideout_B4F_EventScript_RemoveBarrier::
	setmetatile 17, 12, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 12, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 17, 13, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 13, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 17, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 14, METATILE_SilphCo_HideoutFloor, 0
	return


RocketHideout_B4F_EventScript_ItemTM49::
	finditem ITEM_TM49, 1
	release
	end

RocketHideout_B4F_EventScript_ItemMaxEther::
	finditem ITEM_MAX_ETHER, 1
	release
	end

RocketHideout_B4F_EventScript_ItemCalcium::
	finditem ITEM_CALCIUM, 1
	release
	end

RocketHideout_B4F_EventScript_Cubone::
	delay 30
	playse SE_PIN
	applymovement LOCALID_CUBONE, Common_Movement_ExclamationMark
	waitmovement 2
	applymovement LOCALID_CUBONE, Movement_CuboneExit
	waitmovement 2
	playmoncry SPECIES_CUBONE, CRY_MODE_NORMAL
	waitmoncry
	removeobject LOCALID_CUBONE
	release
	end

Movement_CuboneExit::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	face_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

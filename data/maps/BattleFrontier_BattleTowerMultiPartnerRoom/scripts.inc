.set LOCALID_ATTENDANT, 1

BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_ATTENDANT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 2, 5
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "Si us plau, tria una parella\n"
	.string "d'entre els Entrenadors d'aquí.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{PLAYER}, no has trobat parella\n"
	.string "per al teu equip.\p"
	.string "Vols deixar de buscar i tornar\n"
	.string "al taulell de recepció?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "Doncs, si us plau, tria una parella\n"
	.string "d'entre els Entrenadors d'aquí.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "Gràcies per triar una parella.\p"
	.string "Ara et portaré a la Sala de\n"
	.string "Combat Múltiple.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "Sóc l'aprenent núm. {STR_VAR_2}\n"
	.string "de {STR_VAR_1}.\n"
	.string "Pots dir-me {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "Per consell de {STR_VAR_1}, porto\n"
	.string "un {STR_VAR_3} amb {STR_VAR_2} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "Si us plau, deixa'm unir-me a tu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "Gràcies!\n"
	.string "Vaig a registrar-me ara mateix!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "Volia molt fer equip amb tu,\n"
	.string "{PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "Sóc l'aprenent núm. {STR_VAR_2}\n"
	.string "de {STR_VAR_1}.\n"
	.string "Em dic {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "Vaig rebre consell de {STR_VAR_1} i\n"
	.string "vaig triar un {STR_VAR_3} amb {STR_VAR_2} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "Si us plau, fem equip!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "Moltes gràcies!\n"
	.string "Faré el registre de seguida!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}, esperava poder fer\n"
	.string "equip amb tu…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "Em… em dic {STR_VAR_3}, i sóc\n"
	.string "l'aprenent núm. {STR_VAR_2} de {STR_VAR_1}.\p"
	.string "Snif…\p"
	.string "Perdona!\n"
	.string "La tensió em fa plorar…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{STR_VAR_3} em va aconsellar, així\n"
	.string "que tinc un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "Snif…\n"
	.string "Si us plau, fes equip amb mi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "Oh, de veritat? Ho faràs?\n"
	.string "Genial! Fantàstic! Uuuuh!\p"
	.string "Oh… perdona…\n"
	.string "Estic tan content que ploro…\p"
	.string "Vaig a registrar-me ara mateix.\n"
	.string "No marxis, si us plau!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "Oh, p-però…\n"
	.string "Snif… Buaaaaah!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "Ei, hola! Sóc {STR_VAR_3}!\n"
	.string "Sóc l'aprenent núm. {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3} em va recomanar l'equip.\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1},\n"
	.string "això és el que tinc! Mola, eh?\p"
	.string "Vinga, va!\n"
	.string "Fem equip!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "Bé! Genial!\n"
	.string "Vaig a registrar-me, vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "Ooh, per què?\n"
	.string "Volia fer equip, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "Sóc {STR_VAR_3}, l'aprenent núm. {STR_VAR_2}\n"
	.string "del famós {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "Vaig demanar consell a {STR_VAR_3}.\n"
	.string "Un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "i un {STR_VAR_2} amb {STR_VAR_1},\n"
	.string "aquesta és la meva parella.\p"
	.string "Si us plau, vols fer equip\n"
	.string "amb mi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "Gràcies!\n"
	.string "Vaig a registrar-me ara mateix!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}, esperava unir-me\n"
	.string "a tu en un equip…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "Em… estic molt content que\n"
	.string "t'hagis aturat a parlar amb mi.\p"
	.string "Sóc {STR_VAR_3}.\n"
	.string "Sóc l'aprenent núm. {STR_VAR_2} de {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3} em va aconsellar.\n"
	.string "Li estic molt agraït.\p"
	.string "Tinc un equip d'un {STR_VAR_2}\n"
	.string "amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\n"
	.string "Sé que demano molt…\p"
	.string "No crec que vulguis, però\n"
	.string "podria unir-me a tu com a parella?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "De veritat? No m'ho crec!\n"
	.string "No puc creure que em deixis unir-me!\l"
	.string "Jo… no et decebré!\p"
	.string "Em… si realment va bé, vaig a\n"
	.string "registrar-me ara mateix!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "Oh…\n"
	.string "Ja sabia que no era prou bo…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "Hola, sóc {STR_VAR_3}.\n"
	.string "Sóc l'aprenent núm. {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3} em va dir que seria bo\n"
	.string "fer aquest equip:\l"
	.string "un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "i un {STR_VAR_2} que sap\n"
	.string "usar {STR_VAR_1}.\p"
	.string "No està malament, eh?\n"
	.string "Vols que faci equip amb tu?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "D'acord, encantat d'unir-me!\n"
	.string "Espero que no ho fiquis tot malament!\l"
	.string "Vaig a registrar-me.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "Eh? Per què m'has rebutjat?\n"
	.string "No saps jutjar la gent!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "Sóc {STR_VAR_3} i sóc un Triatleta.\n"
	.string "Estic ocupat cada dia entre córrer,\l"
	.string "entrenar i rappejar.\p"
	.string "També sóc l'aprenent\n"
	.string "núm. {STR_VAR_2} de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "Això és el que {STR_VAR_3} va recomanar.\n"
	.string "Un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "i un que usa {STR_VAR_1},\n"
	.string "{STR_VAR_2}.\p"
	.string "M'he esforçat molt a criar-los,\n"
	.string "tot i estar tan ocupat.\p"
	.string "Fem equip\n"
	.string "i provem sort!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "Gràcies, així m'agrada!\n"
	.string "Espera't mentre vaig a registrar-me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "He tret temps de la meva agenda\n"
	.string "per ser aquí! Vinga, home!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "Ei!\n"
	.string "Què tal?\p"
	.string "Sóc {STR_VAR_3}, l'aprenent\n"
	.string "núm. {STR_VAR_2} de {STR_VAR_1}. Encantat!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "Escolta, escolta! Has de sentir\n"
	.string "els Pokémon que {STR_VAR_3} va recomanar.\l"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\n"
	.string "És clar que els he criat superbé!\p"
	.string "Vols fer equip?\n"
	.string "Segur que serem un gran combo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "Bé, crec que serà divertit!\n"
	.string "Vaig a registrar-me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "Oh, ets molt dolent!\n"
	.string "Vinc recomanat, ho saps.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "Permet que em presenti.\n"
	.string "Sóc {STR_VAR_3}.\p"
	.string "Serveixo com a aprenent\n"
	.string "núm. {STR_VAR_2} de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "Vaig demanar el savi consell de\n"
	.string "{STR_VAR_3} i vaig criar el meu equip\l"
	.string "d'un {STR_VAR_2} amb {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "i un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "Si us plau, accepta fer equip amb mi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "Oh… estic encantat!\n"
	.string "Prometo donar el millor de mi!\p"
	.string "Per descomptat que ens registraré!\n"
	.string "Espera't!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "Esperava unir-me a tu,\n"
	.string "{PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "Ui! M'has parlat!\n"
	.string "Jo… estic emocionadíssim!\p"
	.string "Sóc {STR_VAR_3}! Sóc l'aprenent\n"
	.string "núm. {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "Per consell de {STR_VAR_3}, vaig entrenar\n"
	.string "un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "i un que usa {STR_VAR_1},\n"
	.string "{STR_VAR_2}.\p"
	.string "Si us plau, pots concedir-me el desig?\n"
	.string "Vull ser la teva parella d'equip!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "Ui! Jo… estic marejat!\n"
	.string "Moltes gràcies!\l"
	.string "Vaig a registrar-nos ara mateix!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "Buaah! No tens pietat?\n"
	.string "Però això et fa més guai…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "Iehu! Sóc l'aprenent\n"
	.string "núm. {STR_VAR_2} de {STR_VAR_1}!\p"
	.string "Em dic {STR_VAR_3}, hola, hola!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "El meu mentor {STR_VAR_3} va recomanar\n"
	.string "un {STR_VAR_2} mestre en {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "i un {STR_VAR_2} mestre\n"
	.string "en {STR_VAR_1}.\p"
	.string "Bon material, eh?\n"
	.string "Faràs equip amb mi, oi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "D'acord, excel·lent!\n"
	.string "Faré el registre ràpidament!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "Gwaaah!\n"
	.string "Ets molt calculador, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "Ei! Hi ha un problema greu! Avui és\n"
	.string "l'últim dia de la Torre de Combat!\p"
	.string "… … … … … …\n"
	.string "Només era broma!\p"
	.string "La gent em diu {STR_VAR_3} i jo també!\n"
	.string "Sóc el milèsim aprenent de {STR_VAR_1}!\l"
	.string "En realitat, sóc el núm. {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3} em va aconsellar.\n"
	.string "{STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "{STR_VAR_2} amb {STR_VAR_1}.\n"
	.string "En tinc deu de cada!\l"
	.string "Bé, en realitat només un de cada!\p"
	.string "Què me'n dius?\n"
	.string "Vols provar combats en equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "Visca!\n"
	.string "Et donaré un Pokémon com a gràcies!\p"
	.string "Era broma! Però sí que vaig a fer\n"
	.string "el registre, d'acord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "Oh, que fred! Hauré de destruir\n"
	.string "la Torre de Combat per això!\p"
	.string "És clar que no ho faré!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "Ei, estic a tope de ritme!\n"
	.string "Pokémon, sota el meu control!\p"
	.string "Sóc {STR_VAR_3}, el Mariner rapper.\n"
	.string "No em confonguis amb un ploramiques!\p"
	.string "Sóc l'aprenent núm. {STR_VAR_2} de {STR_VAR_1}.\n"
	.string "No em subestimis!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "Amb el consell de {STR_VAR_3} vaig\n"
	.string "muntar el meu equip d'orgull!\l"
	.string "Un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "i un que usa {STR_VAR_1},\n"
	.string "{STR_VAR_2}!\p"
	.string "Hem de commemorar la nostra trobada\n"
	.string "amb una victòria en equip!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "Ei, ei, m'agrada el teu estil!\n"
	.string "Vaig a fer el registre!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "Oh, ei, {PLAYER}, que fred!\n"
	.string "Si em permets ser franc!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "Iuhuuu!\n"
	.string "Oh, no fugis! Només m'ho passava bé!\p"
	.string "Hola! Sóc {STR_VAR_3}!\n"
	.string "Sóc l'aprenent núm. {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3} em va dir què fer.\n"
	.string "Així que un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "i un que usa {STR_VAR_1},\n"
	.string "{STR_VAR_2}, vaig triar.\p"
	.string "Què me'n dius?\n"
	.string "Vinga, fes-me el dia!\p"
	.string "Si us plau, t'ho suplico!\n"
	.string "Deixa'm unir-me a tu!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "Sííí! La sort m'acompanya!\n"
	.string "Estic molt content!\p"
	.string "Abans d'anar a la batalla,\n"
	.string "vaig a registrar-me ara mateix!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "Em rebutges?\n"
	.string "{PLAYER}, em fas posar trist!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "Tos!\p"
	.string "Oh, perdona, tinc un refredat.\n"
	.string "Els meus Pokémon estan bé, però.\p"
	.string "Em dic {STR_VAR_3}, sóc l'aprenent\n"
	.string "núm. {STR_VAR_2} de {STR_VAR_1}. Tos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "Vaig seguir el consell de {STR_VAR_3}\n"
	.string "i vaig muntar el meu equip\l"
	.string "d'un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "Els vaig entrenar cada dia,\n"
	.string "fins i tot amb vent i pluja.\p"
	.string "Per això tinc aquest refredat,\n"
	.string "crec.\p"
	.string "Això és el meu estil.\n"
	.string "Vols ser la meva parella?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "Gràcies, t'ho agraeixo!\n"
	.string "Tos, tos!\l"
	.string "Espera mentre vaig a registrar-me.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "Oh, no vols?\n"
	.string "{PLAYER}, crec que faríem bona parella.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "Oh, hola!\n"
	.string "Estic molt nerviós.\p"
	.string "Sóc {STR_VAR_3}.\n"
	.string "Sóc l'aprenent núm. {STR_VAR_2} de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3} va dir que anirà bé:\n"
	.string "un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "Em fa vergonya dir-ho, però\n"
	.string "vols unir-te a mi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "Oh, vaja, gràcies!\n"
	.string "Em fa vergonya, però ho donaré tot!\p"
	.string "Vaig a fer el registre.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "Oh, si us plau, no diguis que no!\n"
	.string "Ja em fa prou vergonya…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "Sóc {STR_VAR_3}, sense mentir.\n"
	.string "Sóc l'aprenent núm. {STR_VAR_2} de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{STR_VAR_3} va recomanar el meu equip.\p"
	.string "Com que el consell semblava sincer,\n"
	.string "vaig decidir portar\l"
	.string "el meu {STR_VAR_2} que usa {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "el meu {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "Si és possible, m'agradaria que\n"
	.string "m'acceptessis com a parella.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "De veritat m'acceptes?\n"
	.string "Seria terrible si no.\p"
	.string "Però com que has acceptat, molt bé.\n"
	.string "Vaig a registrar-nos a tots dos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "Hm? Per què refuses?\n"
	.string "Això és una broma, per tu?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "Sóc {STR_VAR_1}, i sóc una Noia!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "El que tinc és un {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} i un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_2} que usa {STR_VAR_1}.\n"
	.string "Això és el que porto.\p"
	.string "Vols ser la meva parella?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "Gràcies!\n"
	.string "Vaig a fer el registre!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "No vols ser la meva parella?\n"
	.string "Te'n penediràs!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "Hola!\p"
	.string "Sóc el Jovenet {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "Vols saber què tinc?\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Seràs la meva parella d'equip,\n"
	.string "oi que sí?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "Bé!\n"
	.string "Vaig a registrar-me, vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "Oh! Si fessis equip amb els meus\n"
	.string "Pokémon, seríem imparables!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "Uepa!\n"
	.string "Sóc l'Excursionista {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "Saps què porto?\n"
	.string "El meu {STR_VAR_2} que usa {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "el meu {STR_VAR_2} que usa {STR_VAR_1}!\p"
	.string "Sona bé, eh?\n"
	.string "Vols fer equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "Uepa!\n"
	.string "Vaig a fer el registre, doncs.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "M'hauria agradat combatre amb tu\n"
	.string "al meu costat.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "Hola!\n"
	.string "Sóc {STR_VAR_1}, i sóc una Bellesa!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "Saps què he estat criant?\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Què et sembla?\n"
	.string "Vols fer equip junts?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "Meravellós!\n"
	.string "Vaig a fer el registre ara!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "Quina decepció!\p"
	.string "Nosaltres dos junts hauríem estat\n"
	.string "els millors!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "Ep!\p"
	.string "Saps qui sóc?\n"
	.string "Sóc {STR_VAR_1}, el Pescador!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "Porto un equip d'un\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "un {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "Què, com ho veus?\n"
	.string "Vols combatre al meu costat?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "Bé, bé!\n"
	.string "Deixa-ho en les meves mans!\p"
	.string "Vaig a registrar-nos ara.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "Fèiem tan bona parella, però…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "Encantada de conèixer-te.\n"
	.string "Sóc {STR_VAR_1}, una Dama.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "M'acompanyen un equip d'un\n"
	.string "{STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "Espero ser del teu gust.\n"
	.string "Desitjo tenir-te com a parella.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "T'ho agraeixo sincerament.\n"
	.string "M'encarregaré del registre.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "Segur que et penediràs de no\n"
	.string "haver-me triat com a parella.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "Sóc la Triatleta {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "El que tinc…\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\n"
	.string "Aquesta és la meva parella!\p"
	.string "Si us plau?\n"
	.string "Vols fer equip amb mi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "Oh, gràcies!\n"
	.string "Vaig a registrar-me al taulell.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "Nosaltres dos junts hauríem estat\n"
	.string "molt forts, segur!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "Epa!\n"
	.string "Sóc el Caçainsectes {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "Mira què tinc!\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Escolta!\n"
	.string "Vols fer equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "Entesos!\p"
	.string "Vaig a fer el registre\n"
	.string "al taulell.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "Oh, els meus Pokémon són genials.\n"
	.string "Espero que no te'n penedeixis!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "Bon dia!\n"
	.string "Sóc l'Estudiant {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "El que he estat criant és un\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "i un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "No està malament, no creus?\n"
	.string "Voldries fer equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "Moltes gràcies!\n"
	.string "Vaig a fer el registre.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "Quina llàstima…\p"
	.string "Esperava poder aprendre de tu\n"
	.string "com a parella…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "Ep! Deixa que em presenti!\n"
	.string "Sóc el Ric {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "Endevina què tinc!\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Et dono l'oportunitat de fer\n"
	.string "equip amb mi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "Bona decisió!\p"
	.string "Faré el registre\n"
	.string "ràpidament!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "Em rebutges a mi, de tota la gent?\n"
	.string "Te'n penediràs, segur!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "Hiiah!\n"
	.string "Sóc el Cinturó Negre {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "Com a companys, tinc\n"
	.string "un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "i un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Si us plau, concedeix-me el desig!\n"
	.string "Deixa'm ser la teva parella!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "Hiiah!\n"
	.string "Vaig a registrar-nos de seguida!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "Ja veig… Espero tenir l'oportunitat\n"
	.string "el proper cop que ens veiem…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "Hola!\n"
	.string "Sóc {STR_VAR_1}, i sóc una Nedadora!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "Et diré què tinc.\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\n"
	.string "Puc ser del teu equip, si us plau?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "Gràcies!\n"
	.string "Vaig a registrar-nos ara!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "Si haguéssim fet equip, hauríem\n"
	.string "estat tan forts!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "Salutacions…\n"
	.string "Sóc la Bruixa {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "Porto amb mi un {STR_VAR_2} que\n"
	.string "usa {STR_VAR_1} juntament amb un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_2} que usa {STR_VAR_1}…\p"
	.string "T'ho suplico…\n"
	.string "Uneix-te a mi en un equip…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "T'ho agraeixo…\n"
	.string "Ens registraré…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "Desitjava tant unir-me a tu…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "Com estàs? Sóc {STR_VAR_1},\n"
	.string "i sóc un Criador Pokémon!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "Estic criant una bona parella!\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Què et sembla?\n"
	.string "Et ve de gust fer equip amb mi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "Molt amable!\p"
	.string "Vaig a encarregar-me del registre,\n"
	.string "espera't aquí!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "Tenia ganes de ser\n"
	.string "la teva parella…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "Hola!\n"
	.string "Sóc la Triatleta {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "Vols saber amb què corro?\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Bé?\n"
	.string "Vols fer equip amb mi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "Molt bé!\p"
	.string "Faré el registre\n"
	.string "ràpidament!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "Tu i jo hauríem estat els millors.\n"
	.string "Quina llàstima…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "Ei! Em dic {STR_VAR_1}!\n"
	.string "Sóc un Triatleta!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "Corro amb el meu equip resistent:\n"
	.string "un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "No està gens malament, eh?\n"
	.string "Hauríem de fer equip junts!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "Molt bé!\n"
	.string "Vaig a registrar-me en un moment!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "Volia molt combatre com a\n"
	.string "parella teva…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "Sóc la Lluitadora {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "He estat endurint un\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "un {STR_VAR_2} que usa {STR_VAR_1}!\p"
	.string "T'agrada el combo?\n"
	.string "Què tal si fem equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "Oh, gràcies!\p"
	.string "Vaig a fer el registre\n"
	.string "ara mateix!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "Amb tu, pensava que podríem formar\n"
	.string "l'equip definitiu…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "Sóc el Triatleta {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "He estat corrent amb un {STR_VAR_2}\n"
	.string "que sap usar {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "i un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Podríem fer equip.\n"
	.string "No seria genial?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "Gràcies!\p"
	.string "Vaig a registrar-nos,\n"
	.string "ara mateix!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "Oh, quina llàstima. Hauríem estat\n"
	.string "l'equip més fort de tots!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "Jo?\n"
	.string "Sóc el Nedador {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "Què porto?\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Ei?\n"
	.string "Faràs equip amb mi, oi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "D'acord!\p"
	.string "Vaig a registrar-me!\n"
	.string "Siguem excel·lents junts!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "Els meus Pokémon són forts, segur…\n"
	.string "Llàstima que no vulguis fer equip.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "Iuhu!\n"
	.string "Sóc el Guitarrista {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "Mira el meu seguici!\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Iuhu! Bastant salvatge, eh?\n"
	.string "Hem de fer un duet en equip!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "Iuhu! Molt bé!\n"
	.string "Vaig a fer el registre ara!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "Els meus Pokémon són la canya!\n"
	.string "Te'n penediràs, ja ho veuràs!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "Encantat de conèixer-te.\n"
	.string "Sóc {STR_VAR_1}, un Cavaller.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "M'acompanyen el meu fidel\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "un {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "Puc demanar-te que t'uneixis a mi\n"
	.string "com a parella d'equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "Ah, t'agraeixo la confiança.\n"
	.string "M'encarregaré del registre.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "Molt desafortunat…\p"
	.string "Esperaré una propera\n"
	.string "oportunitat…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "Hola, sóc {STR_VAR_1},\n"
	.string "i sóc un Pokéfan.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "Ara porto un {STR_VAR_2}\n"
	.string "que sap el moviment {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "T'agrada el que veus?\n"
	.string "Per què no ets la meva parella?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "Gràcies!\n"
	.string "M'encarrego del registre!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "Els meus Pokémon són de primera…\n"
	.string "Llàstima que no ho apreciïs.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "Hm!\n"
	.string "Sóc {STR_VAR_1}, i sóc un Expert!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "Els Pokémon que he endurit són\n"
	.string "un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Què me'n dius de fer equip amb mi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "Hm!\n"
	.string "Vaig a registrar-nos ara mateix!\l"
	.string "Donem-ho tot!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "Espero que la teva elecció sigui\n"
	.string "realment correcta…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "Hola, hola.\n"
	.string "Sóc {STR_VAR_1}, i sóc una Experta.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "He criat els meus Pokémon a fons.\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}:\n"
	.string "això és el que tinc.\p"
	.string "No t'agradaria fer equip amb mi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "Bé, bé.\n"
	.string "Vaig a fer el registre de seguida.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "Potser podem fer equip el proper\n"
	.string "cop que ens veiem.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "Sóc el Domadragons {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "L'equip que he estat endurint és\n"
	.string "un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Què et sembla?\n"
	.string "Vols ser la meva parella?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "D'acord, ho donaré tot!\n"
	.string "Vaig a registrar-me, vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "No trobaràs gaires parelles\n"
	.string "més fortes que jo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "Sóc l'Ornitòleg {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "Quins Pokémon tinc?\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "No creus que faríem un bon\n"
	.string "equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "Genial, gràcies!\n"
	.string "M'encarrego del registre!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "Els meus Pokémon i jo som forts.\n"
	.string "Quina decepció.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "Sóc el Noi Ninja {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "El meu equip Pokémon és un\n"
	.string "{STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Fem equip junts!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "Bé!\n"
	.string "Deixa'm anar a registrar-me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "Te'n penediràs de no tenir els meus\n"
	.string "Pokémon forts al teu costat!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "Hola!\n"
	.string "Sóc la Dama Parasol {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "M'escorten el meu {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "No són bonics?\n"
	.string "Vols unir-te a nosaltres?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "Moltes gràcies!\p"
	.string "Vaig a registrar-me al taulell.\n"
	.string "No ens decebem mútuament!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "Els meus Pokémon són molt forts.\n"
	.string "Quina decepció…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "Hola.\n"
	.string "Sóc {STR_VAR_1}, un Entomòleg!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "He trobat els meus Pokémon, sí.\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}:\n"
	.string "són els que he trobat.\p"
	.string "T'interessaria formar\n"
	.string "un equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "D'acord!\n"
	.string "Entès!\p"
	.string "No trigaré amb el registre!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "Amb els Pokémon que he trobat,\n"
	.string "no hauríem perdut…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "Ahoi!\n"
	.string "Sóc el Mariner {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "Deixa'm ensenyar-te el meu orgull!\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "És clar que no em rebutjaràs.\n"
	.string "Fem equip, oi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "No esperava menys!\n"
	.string "Vaig a registrar-me.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "Hauríem arrasat amb\n"
	.string "l'oposició! Quina llàstima!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "Hola, sóc {STR_VAR_1}.\n"
	.string "Sóc un Col·leccionista.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "Les joies de la meva col·lecció són\n"
	.string "el meu {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Genial, eh?\n"
	.string "Hauríem de fer equip junts.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "Oh, sí!\p"
	.string "Bé, no perdem temps.\n"
	.string "Vaig a registrar-nos a tots dos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "Bé, és decebedor.\n"
	.string "No aprècies els meus Pokémon.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "Hola, sóc {STR_VAR_1}.\n"
	.string "Sóc un Guarda Pokémon.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "M'acompanyen un\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "No creus que faríem un equip\n"
	.string "impressionant?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "Fantàstic!\n"
	.string "Vaig a fer el registre ara.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "El proper cop, tria els meus\n"
	.string "Pokémon, vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "Em dic {STR_VAR_1}.\n"
	.string "Sóc una Guarda Pokémon!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "Deixa'm parlar del meu equip. Tinc\n"
	.string "un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "T'agradaria fer equip\n"
	.string "amb la meva colla?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "Ho donarem tot!\n"
	.string "Faré el registre ràpidament!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "Espero que triïs els meus Pokémon\n"
	.string "el proper cop.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "Encantada. Sóc {STR_VAR_1}.\n"
	.string "Em considero una Dama Aroma.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "Viatjo amb un {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Espero que siguin del teu gust.\n"
	.string "Voldries ser la meva parella?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "Em sento honorada.\n"
	.string "Vaig a registrar-me ara mateix.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "Seria meravellós si poguéssim fer\n"
	.string "equip el proper cop que ens veiem.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "Vols saber qui sóc?\n"
	.string "Sóc {STR_VAR_1}, l'Erudit de Ruïnes!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "Els Pokémon que porto són\n"
	.string "un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Intrigant, eh?\n"
	.string "Què tal si fem equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "Bona decisió!\n"
	.string "Vaig a fer el registre.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "Hmm…\n"
	.string "Crec que els meus Pokémon són forts…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "Sóc l'Entrenador Maco {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "Els Pokémon que tinc ara són un\n"
	.string "{STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\n"
	.string "Mola, eh?\p"
	.string "No creus que molaria molt\n"
	.string "si féssim equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "Genial!\n"
	.string "Vaig a fer el registre volant!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "Pensava que faríem\n"
	.string "el millor equip de la història.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "Sóc l'Entrenadora Maca {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "L'equip que he estat criant té un\n"
	.string "{STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "Et sembla bé?\n"
	.string "Què tal si fem de parelles d'equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "Perfecte!\n"
	.string "Vaig a fer el registre.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "Pensava que seríem\n"
	.string "un equip molt fort…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "Epa!\n"
	.string "Sóc {STR_VAR_1}, el Pokèman!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "Què té un tio com jo?\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1},\n"
	.string "això és tot!\p"
	.string "Fem-ho!\n"
	.string "Arrasarem com a equip!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "Bona tria!\n"
	.string "Vaig a registrar-nos a tots dos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "Els meus Pokémon són brutals!\n"
	.string "No és culpa meva si te'n peneds!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "Ep!\n"
	.string "Sóc l'Encenedor {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "Saps què ha cuinat el meu entrenament?\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Bé, què me'n dius?\n"
	.string "Vols fer equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "Molt bé!\n"
	.string "Vaig a fer el registre.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "Promet que faràs equip amb mi\n"
	.string "el proper cop que ens trobem.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "Sóc {STR_VAR_1}, i sóc un Campista!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "He estat criant un {STR_VAR_2} que\n"
	.string "usa {STR_VAR_1} i un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "Creus que seria divertit fer equip?\n"
	.string "Jo crec que sí!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "Sí!\n"
	.string "Me'n vaig a registrar-me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "El proper cop, d'acord?\n"
	.string "Vull ser del teu equip.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "Hola!\n"
	.string "Sóc {STR_VAR_1}, una Excursionista!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "Els Pokémon que he portat són\n"
	.string "un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "T'interessa unir-te a mi\n"
	.string "en un equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "Oh, gràcies!\n"
	.string "Vaig a fer el registre ara.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "Estaria bé si pogués unir-me a tu\n"
	.string "un altre cop.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "Sóc el Mentalista {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "La parella que he criat és\n"
	.string "un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "Voldries fer equip\n"
	.string "amb mi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "Per descomptat!\n"
	.string "M'encarrego del registre!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "Si ens tornem a veure, m'agradaria\n"
	.string "fer equip amb tu.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "Sóc {STR_VAR_1}.\n"
	.string "Sóc una Mentalista.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}:\n"
	.string "són els meus deixebles.\p"
	.string "No t'intriga la idea de formar\n"
	.string "un equip?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "Gràcies.\n"
	.string "Vaig a fer el registre.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "Espero que hi hagi una altra\n"
	.string "oportunitat de forjar aliança.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "Sóc l'Estudiant {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "Un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "i un {STR_VAR_2} que usa {STR_VAR_1}\n"
	.string "són la meva parella de Pokémon.\p"
	.string "Puc ser la teva parella\n"
	.string "d'equip, si us plau?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "Ooh, gràcies!\n"
	.string "Vaig a registrar-me al taulell!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "Si us plau?\n"
	.string "Puc unir-me a tu el proper cop?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "Epa! Em dic {STR_VAR_1}!\n"
	.string "Sóc una Criadora Pokémon!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "Els Pokémon que he criat són un\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "un {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "Sembla interessant?\n"
	.string "Què tal si fem equip, doncs?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "Molt bé!\n"
	.string "Deixa el registre a les meves mans!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "Has de fer equip amb mi el proper cop,\n"
	.string "d'acord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "Sóc {STR_VAR_1}, i estic orgullosa\n"
	.string "de dir que sóc una Pokéfan.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "Els adorables Pokémon que he criat\n"
	.string "són un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}.\p"
	.string "No són els més bonics?\n"
	.string "Hauríem de fer equip!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "Gràcies, bonic!\n"
	.string "Me'n vaig a registrar-me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "Els meus adorables Pokémon són els\n"
	.string "millors, ja ho saps. Que molest!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "Hola, sóc la Nedadora {STR_VAR_1}.$"


BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "Un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "i un {STR_VAR_2} que usa {STR_VAR_1}\n"
	.string "és el que he entrenat.\p"
	.string "Tu i jo, fem equip.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "Genial!\n"
	.string "Vaig a registrar-nos a tots dos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "Si ens tornem a veure, em deus\n"
	.string "un equip!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "Què passa?\n"
	.string "Sóc {STR_VAR_1}, un Triatleta.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "Tinc un parell de Pokémon decents.\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Estaria bé fer equip junts,\n"
	.string "què et sembla?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "Molt bé!\n"
	.string "Espera't mentre em registro, vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "Espero que em deixis unir-me\n"
	.string "el proper cop, d'acord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "Sóc la Triatleta {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "un altre {STR_VAR_2} que sap\n"
	.string "usar {STR_VAR_1}. Aquesta és la parella.\p"
	.string "Què et sembla?\n"
	.string "Faríem bon equip, diria.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "M'agrada la resposta!\n"
	.string "Faré el registre ràpidament!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "Em donaràs una altra oportunitat\n"
	.string "de fer equip, oi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "Ei, hola!\n"
	.string "Sóc {STR_VAR_1}, i sóc un Nedador!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "Mira què he estat criant!\n"
	.string "Un {STR_VAR_2} amb {STR_VAR_1} i$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "un {STR_VAR_2} amb {STR_VAR_1}!\p"
	.string "Genial, eh?\n"
	.string "Seria genial fer equip també!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "T'ho agraeixo!\n"
	.string "Vaig a fer el registre!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "Si ens tornem a veure, has de fer\n"
	.string "equip amb mi. Ho faràs, oi?$"

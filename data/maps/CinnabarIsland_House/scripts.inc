.set LOCALID_SEA_CAPTAIN, 1

CinnabarIsland_House_MapScripts::
	.byte 0

CinnabarIsland_House_Woman::
	lock
	faceplayer
	goto_if_set FLAG_SHOWN_OLD_SEA_MAP, CinnabarIsland_House_Woman2
	msgbox CinnabarIsland_House_Text_MissesSailing, MSGBOX_NPC
	release
	end

CinnabarIsland_House_Text_MissesSailing::
	.string "El meu pare va ser un gran\n"
	.string "Capità de Mar.\p"
	.string "Però no és el mateix des que\n"
	.string "es va jubilar.\p"
	.string "Es passa el temps mirant\n"
	.string "el mar amb enyorança...$"

CinnabarIsland_House_Woman2::
	msgbox CinnabarIsland_House_Text_Wonderful, MSGBOX_NPC
	release
	end

CinnabarIsland_House_Text_Wonderful::
	.string "Això és meravellós!\p"
	.string "Feia temps que no veia el meu\n"
	.string "pare tan emocionat!$"

CinnabarIsland_House_SeaCaptain::
	lock
	checkitem ITEM_OLD_SEA_MAP
	goto_if_eq VAR_RESULT, FALSE, CinnabarIsland_House_SeaCaptain_Grumpy
	msgbox CinnabarIsland_House_Text_WhatsLeft, MSGBOX_DEFAULT
	faceplayer
	playse SE_PIN
	applymovement LOCALID_SEA_CAPTAIN, Common_Movement_ExclamationMark
	waitmovement 1
	waitse
	msgbox CinnabarIsland_House_Text_WhatsThatYeGot, MSGBOX_DEFAULT
	waitmessage
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	call_if_eq VAR_FACING, DIR_NORTH, CinnabarIsland_House_BehindSeaCaptain
	call_if_ne VAR_FACING, DIR_NORTH, CinnabarIsland_House_SideOfSeaCaptain
	waitmovement 1
	playse SE_EXIT
	removeobject LOCALID_SEA_CAPTAIN
	setflag FLAG_SHOWN_OLD_SEA_MAP
	setflag FLAG_HIDE_CINNABAR_SEA_CAPTAIN_HOUSE
	clearflag FLAG_HIDE_CINNABAR_SEA_CAPTAIN
	release
	end

CinnabarIsland_House_BehindSeaCaptain::
	applymovement LOCALID_SEA_CAPTAIN, Movement_CaptainExit1
	return

CinnabarIsland_House_SideOfSeaCaptain::
	applymovement LOCALID_SEA_CAPTAIN, Movement_CaptainExit2
	return

Movement_CaptainExit1::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

Movement_CaptainExit2::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	face_down
	step_end


CinnabarIsland_House_Text_WhatsThatYeGot::
	.string "Apa!\p"
	.string "Què tens aquí, nano?\p"
	.string "..."
	.string "És un Vell Mapa Marí!\p"
	.string "Escolta...he donat la volta al\n"
	.string "món més cops dels que hi ha\l"
	.string "Pokémon, i goso dir que mai he\l"
	.string "vist aquella illa d'aquest mapa!\p"
	.string "...\p"
	.string "Què? Vols que t'hi porti\n"
	.string "navegant?\p"
	.string "...\p"
	.string "Fem-ho! Una última aventura per\n"
	.string "a aquest vell Capità de Mar!$"

CinnabarIsland_House_SeaCaptain_Grumpy::
	msgbox CinnabarIsland_House_Text_Grumpy, MSGBOX_NPC
	release
	end

CinnabarIsland_House_Text_WhatsLeft::
	.string "Hrmmph...\p"
	.string "He explorat cada racó\n"
	.string "del món...\p"
	.string "Què em queda per fer...$"

CinnabarIsland_House_Text_Grumpy::
	.string "Hrmmph...$"



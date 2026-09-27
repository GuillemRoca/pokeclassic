.set LOCALID_MOM, 1

PalletTown_PlayersHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_PlayersHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_PlayersHouse_2F_OnWarp
	.byte 0

PalletTown_PlayersHouse_2F_OnTransition:
	call SecretBase_EventScript_SetDecorationFlags
	setrespawn HEAL_LOCATION_PLAYERS_HOUSE
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	end

PalletTown_PlayersHouse_2F_OnWarp:
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, SecretBase_EventScript_InitDecorations
	.2byte 0

PlayersHouse_2F_EventScript_NewGameStart1::
	lockall
	addobject LOCALID_MOM
	playse SE_DOOR
	applymovement LOCALID_MOM, MomWalksUpstairs
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	applymovement LOCALID_MOM, WalkToPlayer1
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox PalletTown_PlayersHouse_2F_Text_LookAtTheTime, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	msgbox PalletTown_PlayersHouse_2F_Text_GoingToBeLate, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, WalkToStairs1
	waitmovement 1
	turnobject LOCALID_MOM, DIR_SOUTH
	msgbox PalletTown_PlayersHouse_2F_Text_FoldedYourLaundry, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, MomGoesDownstairs
	waitmovement 1
	setflag FLAG_HIDE_MOM_PLAYERS_ROOM
	playse SE_EXIT
	removeobject LOCALID_MOM
	setvar VAR_ADVENTURE_BEGINS, 1
	releaseall
	end

PlayersHouse_2F_EventScript_PostGame1::
	lockall
	addobject LOCALID_MOM
	playse SE_DOOR
	applymovement LOCALID_MOM, MomWalksUpstairs
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	applymovement LOCALID_MOM, WalkToPlayer1
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox PalletTown_PlayersHouse_2F_Text_WeHaveAVisitor, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, WalkToStairs1
	waitmovement 1
	applymovement LOCALID_MOM, MomGoesDownstairs
	waitmovement 1
	setflag FLAG_HIDE_MOM_PLAYERS_ROOM
	playse SE_EXIT
	removeobject LOCALID_MOM
	setvar VAR_SECRET_BATTLE_CLEAR, 2
	releaseall
	end

PlayersHouse_2F_EventScript_NewGameStart2::
	lockall
	addobject LOCALID_MOM
	applymovement LOCALID_MOM, MomWalksUpstairsAlt
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	applymovement LOCALID_MOM, WalkToPlayer2
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox PalletTown_PlayersHouse_2F_Text_LookAtTheTime, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	msgbox PalletTown_PlayersHouse_2F_Text_GoingToBeLate, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, WalkToStairs2
	waitmovement 1
	turnobject LOCALID_MOM, DIR_SOUTH
	msgbox PalletTown_PlayersHouse_2F_Text_FoldedYourLaundry, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, MomGoesDownstairs
	waitmovement 1
	setflag FLAG_HIDE_MOM_PLAYERS_ROOM
	playse SE_EXIT
	removeobject LOCALID_MOM
	setvar VAR_ADVENTURE_BEGINS, 1
	releaseall
	end

PlayersHouse_2F_EventScript_PostGame2::
	lockall
	addobject LOCALID_MOM
	applymovement LOCALID_MOM, MomWalksUpstairsAlt
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	applymovement LOCALID_MOM, WalkToPlayer2
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox PalletTown_PlayersHouse_2F_Text_WeHaveAVisitor, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, WalkToStairs2
	waitmovement 1
	applymovement LOCALID_MOM, MomGoesDownstairs
	waitmovement 1
	setflag FLAG_HIDE_MOM_PLAYERS_ROOM
	playse SE_EXIT
	removeobject LOCALID_MOM
	setvar VAR_SECRET_BATTLE_CLEAR, 2
	releaseall
	end

PlayersHouse_2F_EventScript_NewGameStart3::
	lockall
	addobject LOCALID_MOM
	applymovement LOCALID_MOM, MomWalksUpstairs
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	applymovement LOCALID_MOM, WalkToPlayer3
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox PalletTown_PlayersHouse_2F_Text_LookAtTheTime, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	msgbox PalletTown_PlayersHouse_2F_Text_GoingToBeLate, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, WalkToStairs3
	waitmovement 1
	turnobject LOCALID_MOM, DIR_SOUTH
	msgbox PalletTown_PlayersHouse_2F_Text_FoldedYourLaundry, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, MomGoesDownstairs
	waitmovement 1
	setflag FLAG_HIDE_MOM_PLAYERS_ROOM
	playse SE_EXIT
	removeobject LOCALID_MOM
	setvar VAR_ADVENTURE_BEGINS, 1
	releaseall
	end

PlayersHouse_2F_EventScript_PostGame3::
	lockall
	addobject LOCALID_MOM
	applymovement LOCALID_MOM, MomWalksUpstairs
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	applymovement LOCALID_MOM, WalkToPlayer3
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox PalletTown_PlayersHouse_2F_Text_WeHaveAVisitor, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, WalkToStairs3
	waitmovement 1
	applymovement LOCALID_MOM, MomGoesDownstairs
	waitmovement 1
	setflag FLAG_HIDE_MOM_PLAYERS_ROOM
	playse SE_EXIT
	removeobject LOCALID_MOM
	setvar VAR_SECRET_BATTLE_CLEAR, 2
	releaseall
	end

MomWalksUpstairs:
	walk_right
	walk_down
	step_end

MomWalksUpstairsAlt:
	walk_right
	walk_down
	walk_down
	step_end

WalkToPlayer1:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WalkToPlayer2:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

WalkToPlayer3:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

WalkToStairs1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

WalkToStairs2:
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

WalkToStairs3:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

MomGoesDownstairs:
	walk_up
	walk_left
	step_end

PalletTown_PlayersHouse_2F_Text_WeHaveAVisitor:
	.string "Mare: {PLAYER}! Ja m'ho imaginava\p"
	.string "que et trobaria jugant aquí\n"
	.string "a dalt un altre cop.\p"
	.string "Hauries de baixar.\n"
	.string "Algú ha vingut a veure't!$"

PalletTown_PlayersHouse_2F_Text_LookAtTheTime:
	.string "Mare: {PLAYER}! Aquí estàs!\p"
	.string "Has estat jugant aquí a dalt\n"
	.string "tot aquest temps?\p"
	.string "No havies de trobar-te amb el\n"
	.string "Professor Oak al seu lab avui?\p"
	.string "Saps tan sols quina hora és?$"

PalletTown_PlayersHouse_2F_Text_GoingToBeLate:
	.string "Hauries d'anar cap al laboratori,\n"
	.string "que no hi arribaràs a temps!$"

PalletTown_PlayersHouse_2F_Text_FoldedYourLaundry:
	.string "Oh! Si vols canviar-te de roba\n"
	.string "abans de sortir,\l"
	.string "t'he posat la roba a la calaixera.$"


PlayersHouse_2F_EventScript_PC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_PLAYERS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

PlayersHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_PLAYERS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

PlayersHouse_2F_EventScript_CheckWallClock::
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	waitstate
	releaseall
	end

PlayersHouse_2F_EventScript_SetWallClock::
	fadescreen FADE_TO_BLACK
	special StartWallClock
	waitstate
	return

PlayersHouse_2F_EventScript_Console::
	lock
	msgbox PlayersHouse_2F_Text_Console, MSGBOX_DEFAULT
	release
	end

PlayersHouse_2F_Text_Console:
	.string "És una consola de jocs antiga.\p"
	.string "El retro-gaming fa furor!$"

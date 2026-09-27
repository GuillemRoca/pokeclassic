FuchsiaCity_SafariZone_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_SafariZone_Entrance_OnFrame
	.byte 0

FuchsiaCity_SafariZone_Entrance_OnFrame:
	map_script_2 VAR_SAFARI_ZONE_STATE, 1, FuchsiaCity_SafariZone_Entrance_EventScript_ExitSafariZone
	.2byte 0

FuchsiaCity_SafariZone_Entrance_EventScript_ExitSafariZone::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_ExitSafariZone
	waitmovement 0
	setvar VAR_SAFARI_ZONE_STATE, 0
	releaseall
	end

FuchsiaCity_SafariZone_Entrance_Movement_ExitSafariZone:
	walk_down
	walk_down
	walk_down
	step_end

FuchsiaCity_SafariZone_Entrance_EventScript_WelcomeAttendant::
	lock
	faceplayer
	msgbox FuchsiaCity_SafariZone_Entrance_Text_WelcomeFirstTime, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZone_Entrance_EventScript_FirstTimeInfo
	msgbox FuchsiaCity_SafariZone_Entrance_Text_ComeInAndEnjoy, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_SafariZone_Entrance_EventScript_InfoAttendant::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_TrainerTip, MSGBOX_SIGN
	end

FuchsiaCity_SafariZone_Entrance_Text_TrainerTip:
	.string "Un consell!\p"
	.string "Llança {POKEBLOCK}s als Pokémon salvatges\n"
	.string "perquè siguin menys propensos a fugir.$"

FuchsiaCity_SafariZone_Entrance_Text_WelcomeFirstTime:
	.string "Benvingut a la Zona Safari!\n"
	.string "És el teu primer cop aquí?$"

FuchsiaCity_SafariZone_Entrance_Text_ComeInAndEnjoy:
	.string "Entra i gaudeix de la Zona Safari!$"

FuchsiaCity_SafariZone_Entrance_EventScript_FirstTimeInfo::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_FirstTimeInfo, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_SafariZone_Entrance_Text_FirstTimeInfo:
	.string "Quan entris a la Zona Safari,\n"
	.string "comences amb 30 Safari Balls per\l"
	.string "atrapar Pokémon.\p"
	.string "El Joc Safari acaba quan et quedes\n"
	.string "sense Safari Balls, o quan hagis\l"
	.string "caminat 500 passos.\p"
	.string "Entra i gaudeix de la Zona Safari!$"

FuchsiaCity_SafariZone_Entrance_EventScript_EntranceCounterTriggerLeft::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ApproachCounterLeft
	waitmovement 0
	goto FuchsiaCity_SafariZone_Entrance_EventScript_EntranceCounter
	end

Movement_ApproachCounterLeft::
	walk_right
	walk_right
	step_end

FuchsiaCity_SafariZone_Entrance_EventScript_EntranceCounterTriggerMid::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ApproachCounterMid
	waitmovement 0
	goto FuchsiaCity_SafariZone_Entrance_EventScript_EntranceCounter
	end

Movement_ApproachCounterMid::
	walk_right
	step_end

FuchsiaCity_SafariZone_Entrance_EventScript_EntranceCounter::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZone_Entrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZone_Entrance_EventScript_TryEnterSafariZone
	msgbox FuchsiaCity_SafariZone_Entrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZone_Entrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZone_Entrance_Text_WouldYouLikeToPlay:
	.string "Benvingut a la Zona Safari!\p"
	.string "Tot el que puguis atrapar per\n"
	.string "només ¥500!\l"
	.string "Vols jugar al Joc Safari?$"

FuchsiaCity_SafariZone_Entrance_Text_PlayAnotherTime:
	.string "D'acord.\n"
	.string "Juga un altre cop!$"

FuchsiaCity_SafariZone_Entrance_EventScript_TryEnterSafariZone::
	call FuchsiaCity_SafariZone_Entrance_EventScript_CheckHasRoomForPokemon
	checkmoney 500
	goto_if_eq VAR_RESULT, 0, FuchsiaCity_SafariZone_Entrance_EventScript_NotEnoughMoney
	playse SE_SHOP
	msgbox FuchsiaCity_SafariZone_Entrance_Text_ThatWillBe500Please, MSGBOX_DEFAULT
	removemoney 500
	updatemoneybox
	msgbox FuchsiaCity_SafariZone_Entrance_Text_HereAreYourSafariBalls, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message FuchsiaCity_SafariZone_Entrance_Text_Received30SafariBalls
	waitfanfare
	msgbox FuchsiaCity_SafariZone_Entrance_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZone
	waitmovement 0
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 2
	warp MAP_SAFARI_ZONE_CENTER, 26, 30
	waitstate
	end

FuchsiaCity_SafariZone_Entrance_Text_ThatWillBe500Please:
	.string "Seran ¥500, si us plau.$"

FuchsiaCity_SafariZone_Entrance_Text_HereAreYourSafariBalls:
	.string "Aquí tens les teves Safari Balls.$"

FuchsiaCity_SafariZone_Entrance_Text_Received30SafariBalls:
    .string "{PLAYER} ha rebut 30 Safari Balls\n"
    .string "de l'assistent.$"

FuchsiaCity_SafariZone_Entrance_Text_PleaseEnjoyYourself:
    .string "T'avisarem per megafonia quan\n"
    .string "se t'acabi el temps o les\l"
    .string "Safari Balls.\p"
    .string "Bé, et desitjo molta sort!$"

FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZone:
	walk_left
	walk_up
	walk_up
	delay_16
	step_end

FuchsiaCity_SafariZone_Entrance_EventScript_CheckHasRoomForPokemon::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, Common_EventScript_Return
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, 1, Common_EventScript_Return
	msgbox FuchsiaCity_SafariZone_Entrance_Text_PCIsFull, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZone_Entrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZone_Entrance_Text_PCIsFull:
	.string "Perdona!\n"
	.string "La teva Caixa del PC és plena.$"

FuchsiaCity_SafariZone_Entrance_EventScript_NotEnoughMoney::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZone_Entrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZone_Entrance_Text_NotEnoughMoney:
	.string "No tens prou diners.\n"
	.string "Perdona.$"

FuchsiaCity_SafariZone_Entrance_EventScript_MovePlayerBackFromCounter::
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_BackAwayFromCounter
	waitmovement 0
	releaseall
	end

FuchsiaCity_SafariZone_Entrance_Movement_BackAwayFromCounter:
	walk_down
	step_end



FuchsiaCity_SafariZone_Entrance_EventScript_ExitCounterTriggerLeft::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ApproachCounterLeft
	waitmovement 0
	goto FuchsiaCity_SafariZone_Entrance_EventScript_ExitCounter
	end

FuchsiaCity_SafariZone_Entrance_EventScript_ExitCounterTriggerMid::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ApproachCounterMid
	waitmovement 0
	goto FuchsiaCity_SafariZone_Entrance_EventScript_ExitCounter
	end

FuchsiaCity_SafariZone_Entrance_EventScript_ExitCounter::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox FuchsiaCity_SafariZone_Entrance_Text_StillHaveTimeExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZone_Entrance_EventScript_Exit
	msgbox FuchsiaCity_SafariZone_Entrance_Text_EnjoyTheRestOfYourAdventure, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZone
	waitmovement 0
	warp MAP_SAFARI_ZONE_CENTER, 26, 30
	waitstate
	end

FuchsiaCity_SafariZone_Entrance_Text_EnjoyTheRestOfYourAdventure:
	.string "Gaudeix de la resta de la teva\n"
	.string "aventura salvatge!$"

FuchsiaCity_SafariZone_Entrance_Text_StillHaveTimeExit:
    .string "Marxaràs de la Zona Safari\n"
    .string "abans d'hora?$"

FuchsiaCity_SafariZone_Entrance_EventScript_Exit::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_ExitEarlyThankYouForPlaying, MSGBOX_DEFAULT
	setvar VAR_SAFARI_ZONE_STATE, 0
	special ExitSafariMode
	goto FuchsiaCity_SafariZone_Entrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZone_Entrance_Text_ExitEarlyThankYouForPlaying:
    .string "Si us plau, retorna les Safari\n"
    .string "Balls que et quedin.$"

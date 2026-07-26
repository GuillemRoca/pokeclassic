.set LOCALID_SCOTT, 1
.set LOCALID_TOWER_ATTENDANT, 2

BattleTower_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleTower_Entrance_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleTower_Entrance_OnWarp
	.byte 0

BattleTower_Entrance_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleTower_Entrance_EventScript_TurnPlayer
	.2byte 0

BattleTower_Entrance_OnFrame::
	map_script_2 VAR_BATTLE_TOWER, 0, BattleTower_Entrance_BattleTowerCutscene
	map_script_2 VAR_TEMP_0, 0, BattleTower_Entrance_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleTower_Entrance_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, BattleTower_Entrance_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleTower_Entrance_EventScript_WonChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleTower_Entrance_EventScript_LostChallenge
	.2byte 0

BattleTower_Entrance_EventScript_TurnPlayer::
	goto_if_unset FLAG_SYS_FRONTIER_PASS, BattleTower_Entrance_EventScript_SkipTurnPlayer
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	end

BattleTower_Entrance_EventScript_SkipTurnPlayer::
	end

BattleTower_Entrance_BattleTowerCutscene::
	applymovement OBJ_EVENT_ID_PLAYER, BTCutscene_ApproachScott
	waitmovement 0
	turnobject LOCALID_SCOTT, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_SCOTT, Common_Movement_ExclamationMark
	waitmovement 1
	waitse
	msgbox BattleTower_Entrance_YouMadeIt, MSGBOX_DEFAULT
	waitmessage
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitse
	waitmovement 0
	msgbox BattleTower_Entrance_LetMeExplain, MSGBOX_DEFAULT
	waitmessage
	closemessage
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox BattleTower_Entrance_GotFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	clearflag FLAG_HIDE_SCOTT_AT_HOUSE
	waitfanfare
	closemessage
	msgbox BattleTower_Entrance_GreatToSeeYouHere, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement LOCALID_SCOTT, BTCutscene_ScottLeave
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox BattleTower_Entrance_ThisIsIt, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement LOCALID_SCOTT, BTCutscene_ScottExit
	waitmovement 1
	playse SE_EXIT
	removeobject LOCALID_SCOTT
	setflag FLAG_HIDE_SCOTT_HALLWAY
	setvar VAR_BATTLE_TOWER, 1
	release
	end

BTCutscene_ApproachScott::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BTCutscene_ScottLeave::
	walk_left
	walk_down
	walk_down
	walk_right
	walk_down
	face_up
	step_end

BTCutscene_ScottExit::
	walk_down
	walk_down
	delay_16
	step_end


BattleTower_Entrance_YouMadeIt::
	.string "Scott: Aquí ets, Campió!\p"
	.string "Per fi has arribat a les grans\n"
	.string "Lligues.\p"
	.string "Què? No saps què és aquest lloc?\p"
	.string "Això és el meu orgull!\p"
	.string "No observava el teu progrés\n"
	.string "a la Lliga només per diversió.\p"
	.string "He estat buscant els millors\n"
	.string "Entrenadors Pokémon de Kanto i\l"
	.string "convidant-los a aquest lloc...\p"
	.string "la Torre de Combat!$"

BattleTower_Entrance_LetMeExplain::
	.string "Scott: Deixa'm explicar.\p"
	.string "A la Lliga Pokémon, puges de rang\n"
	.string "combatent altres Entrenadors en\l"
	.string "combats normals, oi?\p"
	.string "Ara que ets Campió, potser\n"
	.string "aquells combats ja no són prou\l"
	.string "desafiament per a tu.\p"
	.string "Només els millors Entrenadors de\n"
	.string "Kanto poden entrar a la Torre:\l"
	.string "tothom que trobis és al seu millor!\p"
	.string "I a més, tenim regles i normes\n"
	.string "diferents de la Lliga!\p"
	.string "Hi ha moltes maneres de combatre\n"
	.string "aquí!.\p"
	.string "És el somni de tot Entrenador!\p"
	.string "Ara que ets aquí, necessitaràs\n"
	.string "una d'aquestes!$"

BattleTower_Entrance_GotFrontierPass::
	.string "{PLAYER} ha rebut un Passi de la\n"
	.string "Torre de l'Scott!$"

BattleTower_Entrance_GreatToSeeYouHere:
	.string "Scott: Quina alegria veure't aquí,\n"
	.string "de veritat!\p"
	.string "Naturalment, espero que també\n"
	.string "experimentis l'essència pura\l"
	.string "del combat.$"

BattleTower_Entrance_ThisIsIt::
	.string "Scott: Això és tot, campió.\p"
	.string "Tota la teva carrera: per a això\n"
	.string "ha estat.\p"
	.string "Els millors combats de la teva\n"
	.string "vida són allà dalt.\p"
	.string "Ha estat genial veure't arribar\n"
	.string "fins aquí!\p"
	.string "Hauria de recórrer el món per\n"
	.string "trobar un altre Entrenador\l"
	.string "com tu...$"

BattleTower_Entrance_CoolTrainerM::
	lock
	faceplayer
	msgbox BattleTower_Entrance_Text_CoolTrainerM, MSGBOX_DEFAULT
	release
	end

BattleTower_Entrance_Text_CoolTrainerM::
	.string "Pensava que m'anava bé, però\n"
	.string "no vaig poder mantenir la ratxa!\p"
	.string "Esperava guanyar més BP per\n"
	.string "objectes d'entrenament!$"

BattleTower_Entrance_CoolTrainerF::
	lock
	faceplayer
	msgbox BattleTower_Entrance_Text_CoolTrainerF, MSGBOX_DEFAULT
	release
	end

BattleTower_Entrance_Text_CoolTrainerF::
	.string "He gastat els meus BP en mentes\n"
	.string "estranyes.\p"
	.string "Els meus Pokémon van començar\n"
	.string "a actuar diferent quan els en\l"
	.string "vaig donar una!$"

BattleTower_Entrance_BattleGirl::
	lock
	faceplayer
	msgbox BattleTower_Entrance_Text_BattleGirl, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, BattleTower_Entrance_BattleGirlDisagree
	msgbox BattleTower_Entrance_Text_BattleGirlYes, MSGBOX_DEFAULT
	release
	end

BattleTower_Entrance_BattleGirlDisagree::
	msgbox BattleTower_Entrance_Text_BattleGirlNo, MSGBOX_DEFAULT
	release
	end

BattleTower_Entrance_Text_BattleGirl::
	.string "Els Combats Dobles són la prova\n"
	.string "definitiva d'un Entrenador!\p"
	.string "No hi estàs d'acord?$"

BattleTower_Entrance_Text_BattleGirlYes::
	.string "Sabia que hi estaries d'acord.$"

BattleTower_Entrance_Text_BattleGirlNo::
	.string "Oh, li dones la raó a ell?$"

BattleTower_Entrance_BlackBelt::
	lock
	faceplayer
	msgbox BattleTower_Entrance_Text_BlackBelt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, BattleTower_Entrance_BlackBeltDisagree
	msgbox BattleTower_Entrance_Text_BlackBeltYes, MSGBOX_DEFAULT
	release
	end

BattleTower_Entrance_BlackBeltDisagree::
	msgbox BattleTower_Entrance_Text_BlackBeltNo, MSGBOX_DEFAULT
	release
	end

BattleTower_Entrance_Text_BlackBelt::
	.string "Els Combats Individuals són la\n"
	.string "prova definitiva d'un Entrenador!\p"
	.string "No hi estàs d'acord?$"

BattleTower_Entrance_Text_BlackBeltYes::
	.string "Sabia que hi estaries d'acord.$"

BattleTower_Entrance_Text_BlackBeltNo::
	.string "Oh, li dones la raó a ella?$"




BattleTower_Entrance_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleTower_Entrance_EventScript_QuitWithoutSaving::
	lock
	faceplayer
	msgbox BattleTower_Entrance_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	tower_set TOWER_DATA_WIN_STREAK, 0
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LeaveKiosk
	waitmovement 0
	release
	end

BattleTower_Entrance_EventScript_Retired::
	clearflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LeaveKiosk
	waitmovement 0
	release
	end

Movement_LeaveKiosk:
	walk_down
	step_end

BattleTower_Entrance_Text_DidntSaveBeforeQuitting:
	.string "Disculpa!\p"
	.string "No vas desar abans de sortir\n"
	.string "del desafiament l'última vegada.\p"
	.string "Per això, el teu desafiament ha\n"
	.string "estat desqualificat. Ho sento!$"

BattleTower_Entrance_EventScript_WonChallenge::
	lock
	faceplayer
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleTower_Entrance_EventScript_DefeatedMaiden
	message BattleTower_Entrance_Text_CongratsBeatenSeven
	waitmessage
	goto BattleTower_Entrance_EventScript_GiveRibbons

BattleTower_Entrance_Text_CongratsBeatenSeven:
	.string "Felicitats!\n"
	.string "Has derrotat els set Entrenadors!\p"
	.string "$"

BattleTower_Entrance_EventScript_DefeatedMaiden::
	msgbox BattleTower_Entrance_Text_CongratsDefeatedMaiden, MSGBOX_DEFAULT
BattleTower_Entrance_EventScript_GiveRibbons::
	tower_giveribbons
	goto_if_eq VAR_RESULT, FALSE, BattleTower_Entrance_EventScript_GiveBattlePoints
	message BattleTower_Entrance_Text_HereAreSomeRibbons
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox BattleTower_Entrance_Text_PutRibbonOnMons, MSGBOX_DEFAULT
BattleTower_Entrance_EventScript_GiveBattlePoints::
	msgbox BattleTower_Entrance_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ne VAR_RESULT, 49, BattleTower_Entrance_EventScript_LookForwardToChallenge
	msgbox BattleTower_Entrance_Text_AboutToFace50thTrainer, MSGBOX_DEFAULT
BattleTower_Entrance_EventScript_LookForwardToChallenge::
	msgbox BattleTower_Entrance_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	release
	end

BattleTower_Entrance_Text_CongratsDefeatedMaiden:
	.string "Felicitats!\n"
	.string "Has derrotat la Dama del Saló\l"
	.string "i has escombrat set Entrenadors!$"

BattleTower_Entrance_EventScript_LostChallenge::
	goto_if_ne BattleTower_Entrance_EventScript_CancelWinStreak
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ne VAR_RESULT, 0, BattleTower_Entrance_EventScript_LostThanksForPlaying
BattleTower_Entrance_EventScript_CancelWinStreak::
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, FALSE
BattleTower_Entrance_EventScript_LostThanksForPlaying::
	lock
	faceplayer
	message BattleTower_Entrance_Text_ThankYouForPlaying
	waitmessage
	msgbox BattleTower_Entrance_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	release
	end

BattleTower_Entrance_EventScript_ResumeChallenge::
	lock
	faceplayer
	message BattleTower_Entrance_Text_WeveBeenWaitingForYou
	waitmessage
	message BattleTower_Entrance_Text_ProgressWillBeSaved
	waitmessage
	tower_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	goto BattleTower_Entrance_EventScript_EnterElevator
	end

BattleTower_Entrance_EventScript_BattleTowerAttendant::
	lock
	faceplayer
	msgbox BattleTower_Entrance_Text_ChallengeBattleTower, MSGBOX_DEFAULT
	waitmessage
	turnobject LOCALID_TOWER_ATTENDANT, DIR_EAST
	release
	end

BattleTower_Entrance_Text_ChallengeBattleTower::
	.string "Oh! T'interessa desafiar\n"
	.string "la Torre de Combat?\p"
	.string "Vine per davant, si us plau!$"

BattleTower_Entrance_EventScript_BattleTowerTrigger::
	lock
	goto_if_set FLAG_CANCEL_BATTLE_ROOM_CHALLENGE, BattleTower_Entrance_EventScript_Retired
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_Movement_PlayerFaceTowerKiosk
	turnobject LOCALID_TOWER_ATTENDANT, DIR_EAST
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
	special SavePlayerParty
	msgbox BattleTower_Entrance_Text_TowerWelcome, MSGBOX_DEFAULT
BattleTower_Entrance_EventScript_ChooseBattleTowerMode::
	multichoice 17, 0, MULTI_BATTLE_MODE_2, FALSE
	switch VAR_RESULT
	case 0, BattleTower_Entrance_EventScript_TryEnterSinglesChallenge
	case 1, BattleTower_Entrance_EventScript_TryEnterDoublesChallenge
	case 2, BattleTower_Entrance_EventScript_ExplainChallenge
	case 3, BattleTower_Entrance_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleTower_Entrance_EventScript_CancelChallenge
	end

BattleTower_Entrance_EventScript_BattleTowerBlocker::
	lock
	playse SE_PIN
	applymovement LOCALID_TOWER_ATTENDANT, Common_Movement_ExclamationMark
	waitse
	msgbox BattleTower_Entrance_Text_ChallengeBattleTowerBlocker, MSGBOX_DEFAULT
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LeaveKiosk
	waitmovement 0
	release
	end

BattleTower_Entrance_Text_ChallengeBattleTowerBlocker::
	.string "Oh! T'interessa desafiar\n"
	.string "la Torre de Combat?\p"
	.string "Vine a parlar amb mi, si us plau!$"

BattleFrontier_Movement_PlayerFaceTowerKiosk::
	face_left
	step_end

BattleTower_Entrance_Text_TowerWelcome:
	.string "Benvingut a la Torre de Combat,\n"
	.string "on el talent dels Entrenadors\l"
	.string "és posat a prova!\p"
	.string "Seré la teva guia a les\n"
	.string "Sales de Combat.\p"
	.string "En quin tipus de desafiament\n"
	.string "participaràs avui?$"

BattleTower_Entrance_EventScript_ExplainChallenge::
	msgbox BattleTower_Entrance_Text_ExplainChallenge, MSGBOX_DEFAULT
	waitmessage
	goto BattleTower_Entrance_EventScript_ChooseBattleTowerMode
	end

BattleTower_Entrance_Text_ExplainChallenge:
	.string "La Torre de Combat és una\n"
	.string "instal·lació amb dos tipus de\l"
	.string "combat: Individual i Doble.\p"
	.string "Per a cada tipus, hi ha Sales\n"
	.string "de Combat separades.\p"
	.string "Segons la Sala, necessitaràs\n"
	.string "un cert nombre de Pokémon.\p"
	.string "El mode Individual requereix\n"
	.string "tres Pokémon, i el Doble en\l"
	.string "requereix quatre.$"

BattleTower_Entrance_Text_WhichLevelMode:
	.string "Quin mode de nivell desafiaràs\n"
	.string "avui?$"

BattleTower_Entrance_EventScript_TryEnterSinglesChallenge::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	message BattleTower_Entrance_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleTower_Entrance_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleTower_Entrance_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleTower_Entrance_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleTower_Entrance_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleTower_Entrance_EventScript_LoadPartyCancelChallenge
	msgbox BattleTower_Entrance_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleTower_Entrance_EventScript_LoadPartyCancelChallenge
	case YES, BattleTower_Entrance_EventScript_SaveBeforeSinglesChallenge
	case MULTI_B_PRESSED, BattleTower_Entrance_EventScript_LoadPartyCancelChallenge

BattleTower_Entrance_EventScript_SaveBeforeSinglesChallenge::
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_TEMP_0, 0
	tower_init
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	goto_if_eq VAR_RESULT, 0, BattleTower_Entrance_EventScript_CancelChallengeSaveFailed
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, TRUE
	goto BattleTower_Entrance_EventScript_EnterElevator
	end

BattleTower_Entrance_EventScript_TryEnterDoublesChallenge::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	message BattleTower_Entrance_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleTower_Entrance_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleTower_Entrance_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleTower_Entrance_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleTower_Entrance_Text_PleaseSelectFourMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_DOUBLES_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleTower_Entrance_EventScript_LoadPartyCancelChallenge
	msgbox BattleTower_Entrance_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleTower_Entrance_EventScript_LoadPartyCancelChallenge
	case YES, BattleTower_Entrance_EventScript_SaveBeforeDoublesChallenge
	case MULTI_B_PRESSED, BattleTower_Entrance_EventScript_LoadPartyCancelChallenge

BattleTower_Entrance_EventScript_SaveBeforeDoublesChallenge::
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_TEMP_0, 0
	tower_init
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	goto_if_eq VAR_RESULT, 0, BattleTower_Entrance_EventScript_CancelChallengeSaveFailed
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
	goto BattleTower_Entrance_EventScript_EnterElevator
	end

BattleTower_Entrance_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleTower_Entrance_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleTower_Entrance_EventScript_NotEnoughValidMonsLvOpen
	end

BattleTower_Entrance_EventScript_NotEnoughValidMonsLv50::
	switch VAR_FRONTIER_BATTLE_MODE
	case FRONTIER_MODE_SINGLES, BattleTower_Entrance_EventScript_NotEnoughValidMonsLv50Singles
	case FRONTIER_MODE_DOUBLES, BattleTower_Entrance_EventScript_NotEnoughValidMonsLv50Doubles
	goto BattleTower_Entrance_EventScript_EndCancelChallenge
	end

BattleTower_Entrance_EventScript_NotEnoughValidMonsLv50Singles::
	msgbox BattleTower_Entrance_Text_NotEnoughValidMonsLv50Singles, MSGBOX_DEFAULT
	goto BattleTower_Entrance_EventScript_EndCancelChallenge
	end

BattleTower_Entrance_EventScript_NotEnoughValidMonsLv50Doubles::
	msgbox BattleTower_Entrance_Text_NotEnoughValidMonsLv50Doubles, MSGBOX_DEFAULT
	goto BattleTower_Entrance_EventScript_EndCancelChallenge
	end

BattleTower_Entrance_EventScript_NotEnoughValidMonsLvOpen::
	switch VAR_FRONTIER_BATTLE_MODE
	case FRONTIER_MODE_SINGLES, BattleTower_Entrance_EventScript_NotEnoughValidMonsLvOpenSingles
	case FRONTIER_MODE_DOUBLES, BattleTower_Entrance_EventScript_NotEnoughValidMonsLvOpenDoubles
	goto BattleTower_Entrance_EventScript_EndCancelChallenge
	end

BattleTower_Entrance_EventScript_NotEnoughValidMonsLvOpenSingles::
	msgbox BattleTower_Entrance_Text_NotEnoughValidMonsLvOpenSingles, MSGBOX_DEFAULT
	goto BattleTower_Entrance_EventScript_EndCancelChallenge
	end

BattleTower_Entrance_EventScript_NotEnoughValidMonsLvOpenDoubles::
	msgbox BattleTower_Entrance_Text_NotEnoughValidMonsLvOpenDoubles, MSGBOX_DEFAULT
	goto BattleTower_Entrance_EventScript_EndCancelChallenge
	end

BattleTower_Entrance_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS  @ No status provided, so it relies on VAR_0x8006 being 0 already
	goto BattleTower_Entrance_EventScript_CancelChallenge
	end

BattleTower_Entrance_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
BattleTower_Entrance_EventScript_CancelChallenge::
	special CloseLink
	msgbox BattleTower_Entrance_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
BattleTower_Entrance_EventScript_EndCancelChallenge::
	release
	end

BattleTower_Entrance_EventScript_EnterElevator::
	special SavePlayerParty
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
	call BattleTower_Entrance_EventScript_GetPartySize
	special CallFrontierUtilFunc
	setvar VAR_RESULT, 0
	call BattleTower_Entrance_EventScript_ShowYouToBattleRoom
	clearflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 2, 5
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleTower_Entrance_EventScript_ShowYouToBattleRoom::
	call BattleTower_Entrance_EventScript_BufferModeText
	msgbox BattleTower_Entrance_Text_ShowYouToBattleRoom, MSGBOX_DEFAULT
	goto BattleTower_Entrance_EventScript_WalkToElevator

BattleTower_Entrance_EventScript_WalkToElevator::
	closemessage
	applymovement LOCALID_TOWER_ATTENDANT, BattleTower_Entrance_Movement_WalkToPlayer
	waitmovement 2
	applymovement LOCALID_TOWER_ATTENDANT, BattleTower_Entrance_Movement_WalkToElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleTower_Entrance_Movement_WalkToElevator
	waitmovement 0
	opendoor 13, 1
	waitdooranim
	applymovement LOCALID_TOWER_ATTENDANT, BattleTower_Entrance_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleTower_Entrance_Movement_PlayerEnterElevator
	waitmovement 0
	closedoor 13, 1
	waitdooranim
	return

BattleTower_Entrance_Movement_WalkToPlayer:
	walk_up
	walk_right
	walk_right
	step_end

BattleTower_Entrance_Movement_WalkToElevator:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleTower_Entrance_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleTower_Entrance_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleTower_Entrance_EventScript_BufferModeText::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleTower_Entrance_EventScript_BufferTextSingle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleTower_Entrance_EventScript_BufferTextDouble
	return

BattleTower_Entrance_EventScript_BufferTextSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleTower_Entrance_EventScript_BufferTextDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleTower_Entrance_EventScript_GetPartySize::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleTower_Entrance_EventScript_GetSinglesPartySize
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleTower_Entrance_EventScript_GetDoublesPartySize
	return

BattleTower_Entrance_EventScript_GetSinglesPartySize::
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	return

BattleTower_Entrance_EventScript_GetDoublesPartySize::
	setvar VAR_0x8005, FRONTIER_DOUBLES_PARTY_SIZE
	return

BattleFrontier_EventScript_GetLvlMode::
	frontier_get FRONTIER_DATA_LVL_MODE
	return

BattleTower_Entrance_Text_HereAreSomeRibbons:
	.string "Aquí tens unes Cintes per derrotar\n"
	.string "set Entrenadors durs seguits.\p"
	.string "{PLAYER} ha rebut unes Cintes!$"

BattleTower_Entrance_Text_PutRibbonOnMons:
	.string "{PLAYER} ha posat les Cintes\n"
	.string "als Pokémon participants.$"

BattleTower_Entrance_Text_LookForwardToAnotherChallenge:
	.string "Esperem veure't en un altre\n"
	.string "desafiament!$"

BattleTower_Entrance_Text_OkayToSaveBeforeEntering:
	.string "Abans d'entrar a la Sala de Combat,\n"
	.string "s'ha de desar el progrés. D'acord?$"

BattleTower_Entrance_Text_ShowYouToBattleRoom:
	.string "Ara t'acompanyaré a la Sala\n"
	.string "de Combat {STR_VAR_1}.$"

BattleTower_Entrance_Text_NotEnoughValidMonsLv50Singles:
	.string "Disculpa!\p"
	.string "No tens tres Pokémon vàlids.\p"
	.string "Necessites tres Pokémon diferents\n"
	.string "de Nivell 50 o inferior.\p"
	.string "També han de portar objectes\n"
	.string "diferents.\p"
	.string "A més, els Ous no són vàlids.\p"
	.string "Vine quan estiguis preparat.$"

BattleTower_Entrance_Text_NotEnoughValidMonsLvOpenSingles:
	.string "Disculpa!\p"
	.string "No tens tres Pokémon vàlids.\p"
	.string "Necessites tres Pokémon\n"
	.string "diferents per entrar.\p"
	.string "També han de portar objectes\n"
	.string "diferents.\p"
	.string "A més, els Ous no són vàlids.\p"
	.string "Vine quan estiguis preparat.$"

BattleTower_Entrance_Text_NotEnoughValidMonsLv50Doubles:
	.string "Disculpa!\p"
	.string "No tens quatre Pokémon vàlids.\p"
	.string "Necessites quatre Pokémon\n"
	.string "diferents de Nivell 50 o inferior.\p"
	.string "També han de portar objectes\n"
	.string "diferents.\p"
	.string "A més, els Ous no són vàlids.\p"
	.string "Vine quan estiguis preparat.$"

BattleTower_Entrance_Text_NotEnoughValidMonsLvOpenDoubles:
	.string "Disculpa!\p"
	.string "No tens quatre Pokémon vàlids.\p"
	.string "Necessites quatre Pokémon\n"
	.string "diferents per entrar.\p"
	.string "També han de portar objectes\n"
	.string "diferents.\p"
	.string "A més, els Ous no són vàlids.\p"
	.string "Vine quan estiguis preparat.$"

BattleTower_Entrance_Text_SelectThreeMons:
	.string "Ara selecciona els tres Pokémon\n"
	.string "que vols inscriure.$"

BattleTower_Entrance_Text_PleaseSelectFourMons:
	.string "Ara selecciona els quatre Pokémon\n"
	.string "que vols inscriure.$"

BattleTower_Entrance_Text_PleaseSelectTwoMons:
	.string "Ara selecciona els dos Pokémon\n"
	.string "que vols inscriure.$"

BattleTower_Entrance_Text_SaveGameBeforeShowingIn:
	.string "Desaré la partida abans\n"
	.string "d'acompanyar-te. Espera.$"

BattleTower_Entrance_Text_AwardYouTheseBattlePoints:
	.string "En reconeixement del teu talent\n"
	.string "infinit, t'atorguem aquests\l"
	.string "Punt(s) de Combat.$"

BattleFrontier_Text_ObtainedXBattlePoints:
	.string "{PLAYER} ha obtingut {STR_VAR_1} Punt(s) de Combat.$"

BattleTower_Entrance_Text_ReceivedPrize:
	.string "{PLAYER} ha rebut el premi\n"
	.string "{STR_VAR_1}.$"

BattleTower_Entrance_Text_ThankYouForPlaying:
	.string "Gràcies per participar!\p"
	.string "$"

BattleTower_Entrance_Text_WeveBeenWaitingForYou:
	.string "T'estàvem esperant!\p"
	.string "$"

BattleTower_Entrance_Text_ProgressWillBeSaved:
	.string "Abans d'entrar a la Sala de Combat,\n"
	.string "es desarà el progrés. Espera.$"

BattleTower_Entrance_Text_AboutToFace50thTrainer:
	.string "Estàs a punt d'enfrontar-te\n"
	.string "al 50è Entrenador.\p"
	.string "D'ara endavant, cada cop que\n"
	.string "guanyis set Entrenadors seguits,\l"
	.string "els teus Pokémon rebran una Cinta\l"
	.string "commemorativa.\p"
	.string "Bona sort!$"

BattleTower_Entrance_EventScript_Woman::
	msgbox BattleTower_Entrance_Text_WinsInRowRecorded, MSGBOX_NPC
	end

BattleTower_Entrance_Text_WinsInRowRecorded:
	.string "El nombre de victòries seguides\n"
	.string "es registra.\p"
	.string "Millor que no perdi d'una manera\n"
	.string "vergonyosa!$"

BattleTower_Entrance_EventScript_Boy::
	msgbox BattleTower_Entrance_Text_CanLeaveUntilLossOrSevenWins, MSGBOX_NPC
	end

BattleTower_Entrance_Text_CanLeaveUntilLossOrSevenWins:
	.string "Un cop has entrat a la Torre de\n"
	.string "Combat, no pots sortir fins que\l"
	.string "perdis o guanyis set seguits.\p"
	.string "Més val que estiguis segur que\n"
	.string "estàs a l'alçada.$"

.set LOCALID_ATTENDANT, 1

BattleFrontier_BattleArenaLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_0, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge

BattleFrontier_BattleArenaLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_0, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 9, 13
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena:
	.string "On l'esperit combatiu dels\n"
	.string "Entrenadors es posa a prova!\p"
	.string "Benvingut a l'Arena de Combat!\p"
	.string "Sóc la teva guia al Torneig KO Fix!$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
	.string "Vols acceptar el repte\n"
	.string "de l'Arena de Combat?$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
	.string "Esperem el teu repte\n"
	.string "en una altra ocasió!$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
	.string "A l'Arena de Combat, fem\n"
	.string "el Torneig KO Fix.\p"
	.string "Tots els participants entren amb\n"
	.string "un equip de tres Pokémon.\p"
	.string "Els tres Pokémon s'han d'ordenar\n"
	.string "en l'ordre en què han d'aparèixer.\p"
	.string "Durant el combat, els Pokémon surten\n"
	.string "d'un en un en l'ordre establert.\p"
	.string "Un cop un Pokémon entra en combat,\n"
	.string "ha de quedar-se fins que es decideixi.\p"
	.string "Si un combat no es decideix en\n"
	.string "tres torns, es va a judici.\p"
	.string "Si vols interrompre el teu repte,\n"
	.string "si us plau, desa la partida.\p"
	.string "Si no deses, no podràs continuar\n"
	.string "amb el teu repte.\p"
	.string "Si aconsegueixes la proesa de vèncer\n"
	.string "set Entrenadors seguits,\l"
	.string "et donarem Punts de Combat.$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave:
	.string "Abans de dur-te a l'Arena de\n"
	.string "Combat, has de desar. D'acord?$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
	.string "L'Arena de Combat ofereix dos\n"
	.string "nivells, Nivell 50 i Nivell Obert.\l"
	.string "Quin tries?$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
	.string "Molt bé, ara selecciona els teus\n"
	.string "tres Pokémon, si us plau.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Estimat/da aspirant!\p"
	.string "No tens els tres Pokémon\n"
	.string "necessaris per entrar.\p"
	.string "Per classificar-te, has de portar\n"
	.string "tres Pokémon diferents.\p"
	.string "Tampoc poden portar el mateix\n"
	.string "tipus d'objectes.\p"
	.string "Els Ous{STR_VAR_1} no són elegibles.\p"
	.string "Quan hagis fet els preparatius,\n"
	.string "si us plau, torna.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
	.string "Estimat/da aspirant!\p"
	.string "No tens els tres Pokémon\n"
	.string "necessaris per entrar.\p"
	.string "Per classificar-te, has de portar\n"
	.string "tres Pokémon diferents.\p"
	.string "Els tres Pokémon diferents han\n"
	.string "de ser de Nivell 50 o inferior.\p"
	.string "Tampoc poden portar el mateix\n"
	.string "tipus d'objectes.\p"
	.string "els Ous{STR_VAR_1} no són elegibles.\p"
	.string "Quan hagis fet els preparatius,\n"
	.string "si us plau, torna.$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
	.string "Ara et guiaré fins a\n"
	.string "l'Arena de Combat.$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
	.string "Estimat/da aspirant!\p"
	.string "No vas desar la partida abans\n"
	.string "d'apagar, oi?\p"
	.string "És una llàstima, però això ha\n"
	.string "resultat en la teva desqualificació\l"
	.string "del repte.\p"
	.string "Pots, és clar, començar amb un\n"
	.string "nou repte.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
	.string "Et felicitem per la teva esplèndida\n"
	.string "ratxa de victòries contra set Entrenadors!$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
	.string "La teva fita serà registrada.\n"
	.string "Espera mentre deso la partida.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
	.string "Per commemorar la teva ratxa de\n"
	.string "7 victòries, et donem aquest premi.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
	.string "{PLAYER} ha rebut el premi\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
	.string "Oh?\n"
	.string "Sembla que la teva Motxilla és plena.\p"
	.string "Et recomano que facis espai i\n"
	.string "tornis a buscar el premi.$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
	.string "Moltes gràcies per participar!\p"
	.string "Espera mentre deso la partida.$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
	.string "Esperem el teu repte\n"
	.string "en una altra ocasió!$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
	.string "Esperàvem amb moltes ganes\n"
	.string "la teva arribada.\p"
	.string "Abans de dur-te a l'Arena de\n"
	.string "Combat, he de desar la partida.\l"
	.string "Si us plau, espera.$"

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
	.string "Vols que gravi el teu últim combat\n"
	.string "de l'Arena al teu Passi Frontera?$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
	.string "Vaig perdre per decisió de l'Àrbitre…\p"
	.string "No crec que fos bona idea usar\n"
	.string "només moviments defensius i no atacar…$"

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
	.string "Vaig guanyar per judici!\p"
	.string "Colpejar constantment els\n"
	.string "Pokémon de l'oponent va funcionar!$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
	.string "El nostre combat va ser declarat empat.\p"
	.string "Quan es va acabar el temps, tant els\n"
	.string "meus Pokémon com els de l'oponent\l"
	.string "tenien quasi els mateixos PS.$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
	.string "A l'Arena de Combat, l'ordre dels\n"
	.string "Pokémon és molt important.\p"
	.string "Per exemple, si el teu primer Pokémon\n"
	.string "té certs desavantatges de tipus,\l"
	.string "intenta que el segon tingui\l"
	.string "moviments supereficaços\l"
	.string "contra el primer.\p"
	.string "Crec que és una bona manera de\n"
	.string "fer un equip eficaç.$"

BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
	.string "Les regles del Torneig KO Fix.$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
	.string "Quina secció vols llegir?$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
	.string "El Torneig KO Fix té regles especials,\n"
	.string "a diferència dels combats normals.\p"
	.string "Primer, un combat dura només\n"
	.string "tres torns.\p"
	.string "Si el resultat no es decideix en\n"
	.string "tres torns, es va a judici.\p"
	.string "L'Àrbitre triarà el guanyador\n"
	.string "segons com han combatut els Pokémon.\p"
	.string "A més, un Pokémon no pot ser canviat\n"
	.string "fins que es decideixi el resultat.$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
	.string “El primer factor és “Ment.”\n”
	.string “Avalua com d'agressius\l”
	.string “han estat els combatents.\p”
	.string “Es basa en la freqüència amb què\n”
	.string “els Entrenadors han ordenat\l”
	.string “moviments ofensius.$”

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
	.string “El segon factor és “Habilitat.”\n”
	.string “Avalua com d'eficaçment s'han\l”
	.string “usat els moviments Pokémon.\p”
	.string “Si un moviment ha funcionat bé,\n”
	.string “la puntuació d'Habilitat puja.\p”
	.string “Si un moviment ha fallat, la puntuació\n”
	.string “d'Habilitat baixa.\p”
	.string “Si era un moviment ofensiu, la\n”
	.string “puntuació puja si era “super\l”
	.string “eficaç” i baixa si era\l”
	.string “”poc eficaç.”\p”
	.string “La puntuació no pujarà per moviments\n”
	.string “com Protecció i Detecció.\p”
	.string “Si l'oponent ha usat Protecció o\n”
	.string “Detecció, i el teu Pokémon no ha\l”
	.string “impactat, la seva puntuació\l”
	.string “no baixarà.$”

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
	.string “El tercer factor és “Cos.”\n”
	.string “Es basa en quants PS quedaven\l”
	.string “al final del combat.\p”
	.string “La puntuació té en compte quants\n”
	.string “PS tenia el Pokémon a l'inici del\l”
	.string “combat i quants li quedaven al final.$”

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
	.string "Una victòria arrancada al Magnat de\n"
	.string "l'Arena i set Entrenadors vençuts!\p"
	.string "Et felicitem pel teu repte\n"
	.string "tan esplèndid!$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
	.string "Estimat/da aspirant, en reconeixement\n"
	.string "del teu esperit incansable, si us\l"
	.string "plau accepta aquests Punts de Combat.$"

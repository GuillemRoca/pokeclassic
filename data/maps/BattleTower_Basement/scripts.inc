.set LOCALID_FACTORY_ATTENDANT, 1

BattleTower_Basement_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleTower_Basement_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleTower_Basement_OnWarp
	.byte 0

BattleTower_Basement_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleTower_Basement_EventScript_TurnPlayer
	.2byte 0

BattleTower_Basement_EventScript_TurnPlayer::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	end

BattleTower_Basement_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleTower_Basement_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleTower_Basement_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, BattleTower_Basement_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleTower_Basement_EventScript_WonChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleTower_Basement_EventScript_LostChallenge
	.2byte 0

BattleTower_Basement_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleTower_Basement_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleTower_Basement_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	factory_setswapped
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
	factory_set FACTORY_DATA_WIN_STREAK, 0
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LeaveKiosk
	releaseall
	end

BattleTower_Basement_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleTower_Basement_EventScript_DefeatedHead
	msgbox BattleTower_Basement_Text_CongratsSevenWins, MSGBOX_DEFAULT
	waitmessage
	goto BattleTower_Basement_EventScript_GiveBattlePoints

BattleTower_Basement_EventScript_DefeatedHead::
	msgbox BattleTower_Basement_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
	waitmessage
BattleTower_Basement_EventScript_GiveBattlePoints::
	msgbox BattleTower_Basement_Text_AwardBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleTower_Basement_Text_ExchangeMonsAndSave
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	factory_save 0
	playse SE_SAVE
	waitse
	msgbox BattleTower_Basement_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LeaveKiosk
	releaseall
	end

BattleTower_Basement_EventScript_LostChallenge::
	lockall
	message BattleTower_Basement_Text_ReturnMonsSaveResults
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	factory_save 0
	playse SE_SAVE
	waitse

BattleTower_Basement_EventScript_ResumeChallenge::
	lockall
	message BattleTower_Basement_Text_WaitingForYouToResume
	waitmessage
	factory_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_0, 255
	setvar VAR_0x8006, 2
	goto BattleTower_Basement_EventScript_EnterChallenge

BattleTower_Basement_EventScript_FactoryTrigger::
	lock
	goto_if_set FLAG_CANCEL_BATTLE_ROOM_CHALLENGE, BattleTower_Entrance_EventScript_Retired
	applymovement OBJ_EVENT_ID_PLAYER, BattleFactory_Movement_PlayerFaceTowerKiosk
	turnobject LOCALID_FACTORY_ATTENDANT, DIR_WEST
	msgbox BattleFactoryLobby_Text_Welcome, MSGBOX_DEFAULT
BattleFactoryLobby_EventScript_ChooseBattleTowerMode::
	multichoice 17, 0, MULTI_BATTLE_MODE_2, FALSE
	switch VAR_RESULT
	case 0, BattleTower_Basement_EventScript_SinglesAttendant
	case 1, BattleTower_Basement_EventScript_DoublesAttendant
	case 2, BattleTower_Basement_EventScript_ExplainChallenge
	case 3, BattleTower_Basement_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleTower_Basement_EventScript_CancelChallenge
	end

BattleFactory_Movement_PlayerFaceTowerKiosk::
	face_right
	step_end

BattleFactoryLobby_Text_Welcome:
	.string "Benvingut a la Fàbrica de Combat,\n"
	.string "on la intel·ligència dels\l"
	.string "Entrenadors és posada a prova!\p"
	.string "Sóc la teva guia del Torneig\n"
	.string "d'Intercanvi de Combat.\p"
	.string "En quin tipus de torneig\n"
	.string "participaràs avui?$"

BattleTower_Basement_EventScript_SinglesAttendant::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleTower_Basement_EventScript_StartChallenge
	end

BattleTower_Basement_EventScript_DoublesAttendant::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleTower_Basement_EventScript_StartChallenge
	end

BattleTower_Basement_EventScript_StartChallenge::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleTower_Basement_EventScript_TakeSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleTower_Basement_EventScript_TakeDoublesChallenge
	message BattleTower_Basement_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleTower_Basement_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleTower_Basement_EventScript_CancelChallenge
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleTower_Basement_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleTower_Basement_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleTower_Basement_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleTower_Basement_EventScript_LoadPartyAndCancelChallenge

BattleTower_Basement_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_0, 0
	factory_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	goto_if_eq VAR_RESULT, 0, BattleTower_Basement_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0
BattleTower_Basement_EventScript_EnterChallenge::
	special SavePlayerParty
	msgbox BattleTower_Basement_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FACTORY_ATTENDANT, BattleFactoryLobby_Movement_AttendantApproachPlayer
	waitmovement 1
	applymovement LOCALID_FACTORY_ATTENDANT, BattleFactoryLobby_Movement_ApproachDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFactoryLobby_Movement_ApproachDoor
	waitmovement 0
	opendoor 13,1
	waitdooranim
	applymovement LOCALID_FACTORY_ATTENDANT, BattleFactoryLobby_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFactoryLobby_Movement_PlayerEnterElevator
	waitmovement 0
	closedoor 13,1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFactoryLobby_Movement_AttendantApproachPlayer:
	walk_up
	walk_left
	walk_left
	step_end

BattleFactoryLobby_Movement_ApproachDoor:
	walk_up
	step_end

BattleFactoryLobby_Movement_PlayerEnterElevator:
	walk_up
BattleFactoryLobby_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleTower_Basement_EventScript_TakeSinglesChallenge::
	message BattleTower_Basement_Text_TakeSinglesChallenge
	return

BattleTower_Basement_Text_TakeSinglesChallenge:
	.string "Faràs el desafiament\n"
	.string "d'Intercanvi Individual?$"

BattleTower_Basement_EventScript_TakeDoublesChallenge::
	message BattleTower_Basement_Text_TakeDoublesChallenge
	return

BattleTower_Basement_Text_TakeDoublesChallenge:
	.string "Faràs el desafiament\n"
	.string "d'Intercanvi Doble?$"

BattleTower_Basement_EventScript_ExplainChallenge::
	msgbox BattleTower_Basement_Text_ExplainChallenge, MSGBOX_DEFAULT
	waitmessage
	goto BattleFactoryLobby_EventScript_ChooseBattleTowerMode
	end

BattleTower_Basement_Text_ExplainChallenge:
	.string "El Torneig d'Intercanvi és una\n"
	.string "competició amb Pokémon de lloguer.\p"
	.string "Primer, se't prestaran tres\n"
	.string "Pokémon per a aquest esdeveniment.\p"
	.string "Amb els Pokémon de lloguer,\n"
	.string "hauràs de fer Combats Individuals\l"
	.string "o Dobles, segons el mode.\p"
	.string "Si guanyes, pots intercanviar\n"
	.string "un dels teus Pokémon de lloguer.\p"
	.string "Repeteix el cicle de combatre i\n"
	.string "intercanviar: si guanyes set cops\l"
	.string "seguits, guanyaràs Punts de Combat.\p"
	.string "Si vols interrompre el teu\n"
	.string "desafiament, desa la partida.\p"
	.string "Si no deses, seràs desqualificat\n"
	.string "del desafiament.$"

BattleTower_Basement_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleTower_Basement_EventScript_CancelChallenge

BattleTower_Basement_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleTower_Basement_EventScript_CancelChallenge::
	msgbox BattleTower_Basement_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

BattleTower_Basement_Text_LookForwardToNextVisit:
	.string "Esperem la teva propera visita.$"

BattleTower_Basement_Text_WhichLevelMode:
	.string "Quin nivell vols desafiar?\n"
	.string "Nivell 50 o Nivell Obert?$"

BattleTower_Basement_Text_OkayToSaveBeforeChallenge:
	.string "Abans de començar el desafiament,\n"
	.string "he de desar la partida. D'acord?$"

BattleTower_Basement_Text_StepThisWay:
	.string "Si us plau, vine per aquí.$"

BattleTower_Basement_Text_ReturnMonsSaveResults:
	.string "Gràcies per participar!\p"
	.string "Et tornaré els Pokémon a canvi\n"
	.string "dels Pokémon de lloguer.\p"
	.string "He de desar els resultats.\n"
	.string "Espera, si us plau.$"

BattleTower_Basement_Text_CongratsSevenWins:
	.string "Felicitats! Has guanyat set\n"
	.string "combats d'Intercanvi seguits!$"

BattleTower_Basement_Text_WaitingForYouToResume:
	.string "T'estàvem esperant!\p"
	.string "Abans de reprendre el desafiament,\n"
	.string "he de desar la partida.$"

BattleTower_Basement_Text_DidntSaveBeforeQuitting:
	.string "Em sap greu, però no vas desar\n"
	.string "abans de sortir l'última vegada.\p"
	.string "Com a resultat, has estat\n"
	.string "desqualificat del desafiament.$"

BattleTower_Basement_Text_CongratsForDefeatingHead:
	.string "Felicitats per derrotar el Cap\n"
	.string "de la Fàbrica i guanyar set\l"
	.string "combats seguits!$"

BattleTower_Basement_Text_AwardBattlePoints:
	.string "En reconeixement de la teva riquesa\n"
	.string "de coneixement i gran intel·ligència,\l"
	.string "t'atorguem aquests Punt(s) de Combat.$"

BattleTower_Basement_Text_ExchangeMonsAndSave:
	.string "Deixa'm intercanviar els Pokémon\n"
	.string "pels de lloguer.\p"
	.string "He de desar les dades del combat,\n"
	.string "espera si us plau.$"

BattleTower_Basement_EventScript_RulesBoard::
	lockall
	msgbox BattleTower_Basement_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleTower_Basement_EventScript_ReadRulesBoard
	end

BattleTower_Basement_Text_RulesAreListed:
	.string "Les regles d'Intercanvi de Combat\n"
	.string "estan exposades.$"

BattleTower_Basement_EventScript_ReadRulesBoard::
	message BattleTower_Basement_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleTower_Basement_EventScript_RulesBasics
	case 1, BattleTower_Basement_EventScript_RulesSwapPartner
	case 2, BattleTower_Basement_EventScript_RulesSwapNumber
	case 3, BattleTower_Basement_EventScript_RulesSwapNotes
	case 4, BattleTower_Basement_EventScript_RulesOpenLv
	case 5, BattleTower_Basement_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleTower_Basement_EventScript_ExitRules
	end

BattleTower_Basement_Text_ReadWhichHeading:
	.string "Quina secció vols llegir?$"

BattleTower_Basement_EventScript_RulesBasics::
	msgbox BattleTower_Basement_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto BattleTower_Basement_EventScript_ReadRulesBoard
	end

BattleTower_Basement_Text_ExplainBasicRules:
	.string "A l'Intercanvi de Combat, només\n"
	.string "pots usar tres Pokémon.\p"
	.string "Tant si llogues com intercanvies,\n"
	.string "el teu equip no pot tenir dos o\l"
	.string "més Pokémon iguals.$"

BattleTower_Basement_EventScript_RulesSwapPartner::
	msgbox BattleTower_Basement_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto BattleTower_Basement_EventScript_ReadRulesBoard
	end

BattleTower_Basement_Text_ExplainSwapPartnerRules:
	.string "Només pots intercanviar Pokémon\n"
	.string "amb l'Entrenador que acabes de\l"
	.string "derrotar.\p"
	.string "Només pots triar dels Pokémon\n"
	.string "de l'Entrenador vençut.$"

BattleTower_Basement_EventScript_RulesSwapNumber::
	msgbox BattleTower_Basement_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto BattleTower_Basement_EventScript_ReadRulesBoard
	end

BattleTower_Basement_Text_ExplainSwapNumberRules:
	.string "Després de cada victòria, pots\n"
	.string "intercanviar per un dels Pokémon\l"
	.string "del rival vençut.\p"
	.string "No podràs intercanviar Pokémon\n"
	.string "amb el 7è Entrenador de l'esdeveniment.$"

BattleTower_Basement_EventScript_RulesSwapNotes::
	msgbox BattleTower_Basement_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
	goto BattleTower_Basement_EventScript_ReadRulesBoard
	end

BattleTower_Basement_Text_ExplainSwapNotesRules:
	.string "Hi ha dos punts clau a l'hora\n"
	.string "d'intercanviar Pokémon.\p"
	.string "Primer, no pots veure les stats\n"
	.string "del Pokémon que rebràs.\p"
	.string "Segon, els Pokémon del teu equip\n"
	.string "estan en seqüència, segons l'ordre\l"
	.string "en què els vas llogar.\p"
	.string "Aquesta seqüència no canvia\n"
	.string "ni amb intercanvis.$"

BattleTower_Basement_EventScript_RulesOpenLv::
	msgbox BattleTower_Basement_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
	goto BattleTower_Basement_EventScript_ReadRulesBoard
	end

BattleTower_Basement_Text_ExplainOpenLvRules:
	.string "Al Nivell Obert, els Pokémon de\n"
	.string "lloguer i els dels rivals són\l"
	.string "tots de Nivell 100.$"

BattleTower_Basement_EventScript_ExitRules::
	releaseall
	end

BattleTower_Basement_EventScript_Blocker::
	lock
	playse SE_PIN
	applymovement LOCALID_FACTORY_ATTENDANT, Common_Movement_ExclamationMark
	waitse
	msgbox BattleTower_Basement_Text_Blocker, MSGBOX_DEFAULT
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LeaveKiosk
	waitmovement 0
	release
	end

BattleTower_Basement_Text_Blocker::
	.string "Oh! Només els participants del\n"
	.string "Torneig d'Intercanvi poden\l"
	.string "passar per aquí.\p"
	.string "Si t'interessa participar,\n"
	.string "vine a parlar amb mi!$"

BattleTower_Basement_EventScript_Attendant::
	lock
	faceplayer
	msgbox BattleTower_Basement_Text_JoinBattleSwap, MSGBOX_DEFAULT
	waitmessage
	turnobject LOCALID_TOWER_ATTENDANT, DIR_WEST
	release
	end

BattleTower_Basement_Text_JoinBattleSwap::
	.string "Aquí celebrem els Torneigs\n"
	.string "d'Intercanvi de Combat.\p"
	.string "Vine per davant si t'interessa\n"
	.string "participar.$"

BattleTower_Basement_EventScript_Woman::
	msgbox BattleTower_Basement_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
	end

BattleTower_Basement_Text_NeedKnowledgeOfMonsMoves:
	.string "Ei!\n"
	.string "Tu!\p"
	.string "Penses que els esdeveniments d'aquí\n"
	.string "són fàcils perquè no necessites\l"
	.string "un equip entrenat?\p"
	.string "Jo no estaria tan segura\n"
	.string "de guanyar fàcilment.\p"
	.string "Si no tens un bon coneixement\n"
	.string "dels Pokémon i els seus moviments,\l"
	.string "serà difícil seguir guanyant.$"

BattleTower_Basement_EventScript_Camper::
	msgbox BattleTower_Basement_Text_SwappedForWeakMon, MSGBOX_NPC
	end

BattleTower_Basement_Text_SwappedForWeakMon:
	.string "Vaig intercanviar per un Pokémon\n"
	.string "feble… Pensava que era bo…\p"
	.string "Ens han escombrat…$"

BattleTower_Basement_EventScript_Picnicker::
	lock
	faceplayer
	msgbox BattleTower_Basement_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
	release
	end

BattleTower_Basement_Text_NeedToCheckOpponentsMons:
	.string "Les coses no m'han anat gens bé.\p"
	.string "Has de revisar els Pokémon del\n"
	.string "rival durant el combat per veure\l"
	.string "si són bons.$"

BattleTower_Basement_EventScript_FatMan::
	msgbox BattleTower_Basement_Text_CantFigureOutStaffHints, MSGBOX_NPC
	end

BattleTower_Basement_Text_CantFigureOutStaffHints:
	.string "Saps que el personal d'aquí et\n"
	.string "dóna pistes sobre el pròxim rival?\p"
	.string "Doncs, sóc un home fet i dret,\n"
	.string "però em costa entendre les pistes.$"

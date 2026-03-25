.set LOCALID_GREETER, 1
.set LOCALID_GUIDE, 2
.set LOCALID_SCOTT, 4

BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_GREETER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_GUIDE, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
	.string "És la primera vegada que véns?\n"
	.string "Si us plau, vine per aquí!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
	.string "La primera línia dels combats\n"
	.string "Pokémon!\l"
	.string "Benvingut a la Frontera de Combat!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
	.string "Als visitants nous els donem\n"
	.string "el Passi Frontera.\p"
	.string "Serveix per a totes les\n"
	.string "instal·lacions de la Frontera.\p"
	.string "Aquí el tens!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.string "{PLAYER} ha obtingut\n"
	.string "el Passi Frontera.$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.string "{PLAYER} ha col·locat la Targeta\n"
	.string "d'Entrenador al Passi Frontera.$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
	.string "Esperem que gaudeixis de tot el que\n"
	.string "la Frontera de Combat ofereix!$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.string "???: Vaja, si és {PLAYER}{KUN}!\n"
	.string "Has vingut fins aquí!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
	.string "Guia: Oh! Sr. Scott, senyor!\n"
	.string "Bon dia, senyor!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
	.string "Scott: Quina alegria veure't aquí,\n"
	.string "de veritat!\p"
	.string "Espero que et prenguis el temps\n"
	.string "d'explorar-ho tot.\p"
	.string "Naturalment, espero que també\n"
	.string "experimentis l'essència pura\l"
	.string "del combat.\p"
	.string "També tinc la meva residència\n"
	.string "aquí, vine a visitar-me si tens\l"
	.string "temps.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
	.string "Sóc la teva guia de les diverses\n"
	.string "instal·lacions de la Frontera.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.string "De quina vols saber-ne més?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
	.string "És la torre gegant considerada\n"
	.string "el símbol de la Frontera.\p"
	.string "Hi ha quatre Sales de Combat\n"
	.string "per a Individual, Doble, Múltiple\l"
	.string "i Múltiple per Enllaç.$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
	.string "El Domo de Combat és l'edifici\n"
	.string "gran amb forma d'ou enorme.\p"
	.string "S'hi celebren els Torneigs de\n"
	.string "Combat.\p"
	.string "Hi ha dues modalitats: per a\n"
	.string "Combats Individuals i Dobles.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
	.string "El Palau de Combat és l'edifici\n"
	.string "vermell a la dreta de la Frontera.\p"
	.string "Hi ha dues Sales de Combat\n"
	.string "per a Individual i Doble.$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
	.string "L'Arena de Combat és l'edifici\n"
	.string "amb forma de dojo al centre-dreta\l"
	.string "de la Frontera.\p"
	.string "S'hi celebra el Torneig KO\n"
	.string "a l'Arena de Combat.$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
	.string "La Fàbrica de Combat és l'edifici\n"
	.string "gran més proper a nosaltres.\p"
	.string "S'hi celebra l'Intercanvi de\n"
	.string "Combat.\p"
	.string "L'Intercanvi ofereix dues\n"
	.string "modalitats: per a Combats\l"
	.string "Individuals i Dobles.$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
	.string "La Llança de Combat és l'edifici\n"
	.string "amb forma de Pokémon al centre-\l"
	.string "esquerra de la Frontera.\p"
	.string "S'hi celebra l'Elecció de\n"
	.string "Combat.$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
	.string "La Piràmide de Combat és\n"
	.string "l'enorme piràmide.\p"
	.string "S'hi celebra la Cerca de\n"
	.string "Combat.$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
	.string "La Sala de Rànquing és a prop\n"
	.string "de la Torre de Combat.\p"
	.string "Allà pots veure els rècords més\n"
	.string "fantàstics dels Entrenadors que\l"
	.string "han afrontat els desafiaments\l"
	.string "de la Frontera de Combat.$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
	.string "La Cantonada de Serveis d'Intercanvi\n"
	.string "és a prop de la Torre de Combat.\p"
	.string "Els Punts de Combat guanyats\n"
	.string "a la Frontera es poden canviar\l"
	.string "per premis fabulosos allà.$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
	.string "Sóc la teva guia de les regles\n"
	.string "bàsiques comunes a tots els\l"
	.string "desafiaments de les instal·lacions\l"
	.string "de la Frontera de Combat.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.string "De què vols saber-ne més?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
	.string "Tots els desafiaments de la\n"
	.string "Frontera de Combat tenen dues\l"
	.string "modalitats: Nivell 50 i Nivell Obert.$"

BattleFrontier_ReceptionGate_Text_Level50Info:
	.string "El mode Nivell 50 és per a Pokémon\n"
	.string "de nivell 50 o inferior.\p"
	.string "Tingueu en compte, però, que\n"
	.string "cap Entrenador rival tindrà\l"
	.string "Pokémon per sota del nivell 50.\p"
	.string "Aquesta modalitat és l'entrada\n"
	.string "als combats de la Frontera.\p"
	.string "Per començar, esperem que\n"
	.string "desafiïs aquesta modalitat.$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
	.string "El mode Nivell Obert no limita\n"
	.string "el nivell dels Pokémon que\l"
	.string "participen.\p"
	.string "El nivell dels teus rivals\n"
	.string "s'ajustarà al nivell dels\l"
	.string "teus Pokémon.\p"
	.string "Tanmateix, cap rival tindrà\n"
	.string "Pokémon per sota del nivell 60.$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
	.string "Pràcticament qualsevol Pokémon\n"
	.string "pot participar en els desafiaments.\p"
	.string "Els Ous i certs Pokémon, però,\n"
	.string "no hi són permesos.\p"
	.string "El nombre de Pokémon necessaris\n"
	.string "depèn de la instal·lació.\p"
	.string "A totes les instal·lacions, no es\n"
	.string "permeten dos o més Pokémon\l"
	.string "de la mateixa espècie.$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
	.string "En entrar a un desafiament,\n"
	.string "els Pokémon no poden portar\l"
	.string "el mateix tipus d'objecte.\p"
	.string "Assegura't que tots els Pokémon\n"
	.string "portin objectes diferents.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.string "Sóc la teva guia del Passi Frontera.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.string "De què vols saber-ne més?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
	.string "Hi ha set instal·lacions a\n"
	.string "la Frontera de Combat.\p"
	.string "Els Entrenadors que demostrin\n"
	.string "les seves habilitats poden rebre\l"
	.string "símbols de cada instal·lació.\p"
	.string "Per guanyar un símbol, potser\n"
	.string "hauràs de derrotar Entrenadors\l"
	.string "seguits i guanyar events repetits.\p"
	.string "No és fàcil guanyar símbols.\n"
	.string "Et desitjo molta sort!$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
	.string "Es pot enregistrar un combat\n"
	.string "al Passi Frontera.\p"
	.string "Pots enregistrar un combat\n"
	.string "amb un amic o amics.\p"
	.string "O pots enregistrar un combat\n"
	.string "de la Frontera excepte els de\l"
	.string "la Llança de Combat o\l"
	.string "la Piràmide de Combat.\p"
	.string "Pots triar enregistrar el combat\n"
	.string "al final d'una batalla.$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
	.string "Els Punts de Combat són premis\n"
	.string "per als Entrenadors que han\l"
	.string "combatut brillantment a la\l"
	.string "Frontera de Combat.\p"
	.string "Pots canviar-los per premis\n"
	.string "a la Cantonada de Serveis\l"
	.string "d'Intercanvi.$"

BattleFrontier_Lounge3_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
	end

BattleFrontier_Lounge3_EventScript_Bet5::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet10::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet15::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_PlaceBet::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet
	end

BattleFrontier_Lounge3_EventScript_FinishBet::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
	end

BattleFrontier_Lounge3_EventScript_WonChallenge::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge::
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
	end

BattleFrontier_Lounge3_EventScript_Man::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FatMan::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string "…Què vols?\p"
	.string "No veus que estem una mica\n"
	.string "ocupats? No pot esperar?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
	.string "…Eh?\n"
	.string "Em sembla que ets un Entrenador dur.\p"
	.string "Heheh…\n"
	.string "Escolta, tinc una proposta.\p"
	.string "Tenim un petit grup aquí,\n"
	.string "i juguem a un joc amb el que\l"
	.string "passa a la Frontera de Combat.\p"
	.string "Les regles són molt simples.\p"
	.string "Primer, triem una de les\n"
	.string "instal·lacions de la Frontera.\p"
	.string "Després, cadascú tria un Entrenador\n"
	.string "diferent que hi participa,\l"
	.string "i apostem Punts de Combat.\p"
	.string "Qui aposti per l'Entrenador amb\n"
	.string "el millor rècord s'emporta tots\l"
	.string "els Punts de Combat del pot.\p"
	.string "Sona simple, oi?\n"
	.string "Doncs, bé…$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string "El que busco és un Entrenador que\n"
	.string "vagi a desafiar les Sales de\l"
	.string "Combat Individual de la Torre.\p"
	.string "Però fins ara, no he vist cap\n"
	.string "Entrenador amb qualitat.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string "El que busco és un Entrenador que\n"
	.string "vagi a desafiar les Sales de\l"
	.string "Combat Doble de la Torre.\p"
	.string "Però fins ara, no he vist cap\n"
	.string "Entrenador amb qualitat.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string "El que busco és un Entrenador que\n"
	.string "vagi a desafiar les Sales de\l"
	.string "Combat Múltiple de la Torre.\p"
	.string "Però fins ara, no he vist cap\n"
	.string "Entrenador amb qualitat.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string "El que busco és un Entrenador que\n"
	.string "vagi a entrar al Torneig de\l"
	.string "Combat Individual del Domo.\p"
	.string "Però fins ara, no he vist cap\n"
	.string "Entrenador amb qualitat.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string "El que busco és un Entrenador que\n"
	.string "vagi a entrar al Torneig de\l"
	.string "Combat Doble del Domo.\p"
	.string "Però fins ara, no he vist cap\n"
	.string "Entrenador amb qualitat.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string "El que busco és un Entrenador que\n"
	.string "vagi a entrar al Torneig\l"
	.string "d'Intercanvi Individual de la Fàbrica.\p"
	.string "Però fins ara, no he vist cap\n"
	.string "Entrenador amb qualitat.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string "El que busco és un Entrenador que\n"
	.string "vagi a entrar al Torneig\l"
	.string "d'Intercanvi Doble de la Fàbrica.\p"
	.string "Però fins ara, no he vist cap\n"
	.string "Entrenador amb qualitat.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string "El que busco és un Entrenador que\n"
	.string "vagi a desafiar les Sales de\l"
	.string "Combat Individual del Palau.\p"
	.string "Però fins ara, no he vist cap\n"
	.string "Entrenador amb qualitat.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string "El que busco és un Entrenador que\n"
	.string "vagi a desafiar les Sales de\l"
	.string "Combat Doble del Palau.\p"
	.string "Però fins ara, no he vist cap\n"
	.string "Entrenador amb qualitat.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string "El que busco és un Entrenador que\n"
	.string "vagi a entrar al Torneig\l"
	.string "KO de l'Arena de Combat.\p"
	.string "Però fins ara, no he vist cap\n"
	.string "Entrenador amb qualitat.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string "El que busco és un Entrenador que\n"
	.string "vagi a entrar a l'Elecció de\l"
	.string "Combat de la Llança.\p"
	.string "Però fins ara, no he vist cap\n"
	.string "Entrenador amb qualitat.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string "El que busco és un Entrenador que\n"
	.string "vagi a entrar a la Cerca de\l"
	.string "Combat de la Piràmide.\p"
	.string "Però fins ara, no he vist cap\n"
	.string "Entrenador amb qualitat.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string "Et compensaré, ja ho veuràs.\n"
	.string "Què me'n dius?\l"
	.string "Vols participar en l'event per mi?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string "Perfecte.\n"
	.string "I… Què tal si em deixes uns\l"
	.string "Punts de Combat?\p"
	.string "Confia en mi, et mostraré\n"
	.string "la meva gratitud després.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string "Genial, genial!\n"
	.string "Quants me'n pots deixar?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string "Oh, no, no, no!\n"
	.string "No tens prou Punts de Combat!\p"
	.string "No em facis perdre el temps\n"
	.string "a tothom!$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string "Heheh! Moltes gràcies!\n"
	.string "Au, endavant!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string "Vés a les Sales de Combat\n"
	.string "Individual de la Torre ràpid!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No ho espatllis!\l"
	.string "El futur de tots dos en depèn!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string "Vés a les Sales de Combat\n"
	.string "Doble de la Torre ràpid!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No ho espatllis!\l"
	.string "El futur de tots dos en depèn!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string "Vés a les Sales de Combat\n"
	.string "Múltiple de la Torre ràpid!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No ho espatllis!\l"
	.string "El futur de tots dos en depèn!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string "Vés al Torneig de Combat\n"
	.string "Individual del Domo ràpid!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No ho espatllis!\l"
	.string "El futur de tots dos en depèn!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string "Vés al Torneig de Combat\n"
	.string "Doble del Domo ràpid!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No ho espatllis!\l"
	.string "El futur de tots dos en depèn!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string "Vés al Torneig d'Intercanvi\n"
	.string "Individual de la Fàbrica ràpid!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No ho espatllis!\l"
	.string "El futur de tots dos en depèn!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string "Vés al Torneig d'Intercanvi\n"
	.string "Doble de la Fàbrica ràpid!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No ho espatllis!\l"
	.string "El futur de tots dos en depèn!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string "Vés a les Sales de Combat\n"
	.string "Individual del Palau ràpid!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No ho espatllis!\l"
	.string "El futur de tots dos en depèn!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string "Vés a les Sales de Combat\n"
	.string "Doble del Palau ràpid!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No ho espatllis!\l"
	.string "El futur de tots dos en depèn!$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string "Vés al Torneig KO de\n"
	.string "l'Arena de Combat ràpid!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No ho espatllis!\l"
	.string "El futur de tots dos en depèn!$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string "Vés a l'Elecció de Combat\n"
	.string "de la Llança ràpid!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No ho espatllis!\l"
	.string "El futur de tots dos en depèn!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string "Vés a la Cerca de Combat\n"
	.string "de la Piràmide ràpid!\p"
	.string "Has de guanyar sí o sí!\n"
	.string "No ho espatllis!\l"
	.string "El futur de tots dos en depèn!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string "Oh, ets tu…\n"
	.string "Bon intent…\p"
	.string "Em sap greu, però no et puc\n"
	.string "tornar els Punts de Combat…\p"
	.string "Suposo que ens haurà de motivar\n"
	.string "per esforçar-nos més el pròxim cop!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string "Oh, sí!\n"
	.string "Hola, campió!\p"
	.string "Sabia que podies!\n"
	.string "Sabia que ho faries!\l"
	.string "Tots dos hem guanyat!\p"
	.string "Et torno els Punts de Combat i,\n"
	.string "és clar, una mica extra de part meva!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string "{PLAYER} ha obtingut\n"
	.string "{STR_VAR_1} Punts de Combat.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string "Si vols un altre desafiament,\n"
	.string "pensa en mi!$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string "No t'interessa?! No hauries de\n"
	.string "tenir por d'arriscar-te!$"

BattleFrontier_Lounge3_Text_Oh::
	.string "Oh…$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string "He apostat per l'Entrenador\n"
	.string "equivocat un altre cop!\p"
	.string "Potser hauria de combatre\n"
	.string "normalment com tothom…$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string "Aquell Entrenador…\p"
	.string "És bo, però es posa massa nerviós\n"
	.string "per sobreviure al Domo de Combat…$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string "Rialleta!\n"
	.string "Sé reconèixer un guanyador!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string "Aquells Entrenadors…\n"
	.string "Què fan?\l"
	.string "Haurien d'estar competint.$"

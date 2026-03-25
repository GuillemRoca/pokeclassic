.set LOCALID_SS_TIDAL, 2
.set LOCALID_FERRY_ATTENDANT, 3
.set LOCALID_MANIAC_1, 9
.set LOCALID_MANIAC_2, 10
.set LOCALID_GIRL, 12
.set LOCALID_CAMPER, 14
.set LOCALID_FISHERMAN_2, 18
.set LOCALID_MAN_4, 23

BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "Aquest és el Domo de Combat!\n"
	.string "El teu camí cap a la superestrella\l"
	.string "invencible!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "Aquesta és la Fàbrica de Combat!\n"
	.string "Busca els Pokémon més forts!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "Aquesta és la Llança de Combat!\n"
	.string "Tria un dels tres camins!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "Aquesta és la Torre de Combat.\p"
	.string "Els Entrenadors porten els seus\n"
	.string "millors Pokémon per a combats\l"
	.string "d'eliminació.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "Hola, véns pel ferri?\n"
	.string "Puc veure el teu Tiquet?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER} no té el Tiquet…\p"
	.string "Ho sento molt.\p"
	.string "Necessites un Tiquet per pujar\n"
	.string "al ferri.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} ha ensenyat el Tiquet.\p"
	.string "Perfecte! Això és tot!\p"
	.string "On voldries anar?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "Ciutat Portual, doncs!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "Ciutat Llirimàs, doncs!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "Navega amb nosaltres un altre cop!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "Si us plau, pugeu al ferri\n"
	.string "i espereu la sortida.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "Llavors, on voldries anar?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "Sóc el millor de tots els meus amics.\n"
	.string "Però aquí…\l"
	.string "No he servit de res!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "Vull anar a la Torre de Combat,\n"
	.string "però no la trobo tot i que tinc\l"
	.string "un mapa de la Frontera.\p"
	.string "Aquest lloc és massa gran!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "Volia fer un desafiament tan bon\n"
	.string "punt arribés.\p"
	.string "Però pel camí, em vaig marejar…\n"
	.string "Buurp…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "No és que qualsevol pugui venir\n"
	.string "aquí, ho saps?\p"
	.string "Només els Entrenadors reconeguts\n"
	.string "com a durs són portats aquí.\p"
	.string "Per això molts Entrenadors ni\n"
	.string "coneixen la Frontera de Combat.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "Ei, tio…\p"
	.string "Estàs segur que podem competir\n"
	.string "encara que no tinguem Pokémon?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "Eh…\n"
	.string "Segur que anirà bé.\p"
	.string "Crec…\p"
	.string "Però recordes aquell home gran?\n"
	.string "Va dir: "Us deixaré Pokémon!"$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "Això és la Fàbrica de Combat.\n"
	.string "Pots llogar Pokémon forts allà.\p"
	.string "Però em fa pensar.\n"
	.string "Qui cria els Pokémon de lloguer?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "Tinc por d'entrar a la Llança\n"
	.string "de Combat per culpa de Seviper…\p"
	.string "P-però he vingut fins aquí, així\n"
	.string "que intentaré conquerir-ho tot!\l"
	.string "…Tremolor…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "Juguem a pedra, paper, tisores!\n"
	.string "Un, dos, tres!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "Bé! He guanyat!\n"
	.string "Faré el desafiament de la Llança!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "Oh, no…\n"
	.string "He perdut.\p"
	.string "Avui no tinc sort.\n"
	.string "Deixaré el desafiament de la\l"
	.string "Llança per demà.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "Crec que sóc l'única persona aquí\n"
	.string "que, per alguna raó, prefereix\l"
	.string "pescar abans que combatre.\p"
	.string "Eh? No es pot pescar res aquí?\n"
	.string "Quina decepció…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "Avui continuaré combatent, passi\n"
	.string "el que passi, fins a aconseguir\l"
	.string "un Símbol.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "Oh? Vas a desafiar\n"
	.string "el Domo de Combat?\p"
	.string "Et desitjo molta sort.\n"
	.string "Que tots dos guanyem i ens\l"
	.string "trobem als desafiaments.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "Avi, per aquí!\n"
	.string "El Domo de Combat és aquí!\l"
	.string "Endavant, avi!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "Ah, aquest és el Domo de Combat?\n"
	.string "No deixaré que cap Gentlemen\l"
	.string "em guanyi!\p"
	.string "Però on és l'entrada?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "Aquí no hi havia res fa no gaire\n"
	.string "temps.\p"
	.string "Però mira-ho ara! Increïble!\n"
	.string "Portaré la meva mare a veure-ho.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "Per fi he arribat a la Frontera\n"
	.string "de Combat!\p"
	.string "Segur que crido l'atenció amb\n"
	.string "el meu aspecte i habilitat!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "Nyam, nyam…\p"
	.string "Sembla que aquesta plaça està\n"
	.string "plena de gent dura.\p"
	.string "Nyam, nyam…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "Crec, crec…\p"
	.string "Fa un temps, vaig conèixer una\n"
	.string "noia gran a la Llança de Combat.\p"
	.string "Tenia uns ulls que feien por\n"
	.string "d'una manera molt bèstia.\p"
	.string "Crec, crec…\p"
	.string "Es va enfadar molt: "Vols parar\n"
	.string "de menjar!" I em va etzibar.\p"
	.string "Va ser una experiència\n"
	.string "esgarrifosa, sí senyor.\p"
	.string "Crec, crec…$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "Eh? Escolta't!\n"
	.string "Això no és res!\p"
	.string "L'última vegada que vaig animar-lo,\n"
	.string "les nostres mirades es van creuar!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "Quèèèè?!\n"
	.string "Pfft!\p"
	.string "Això només va passar perquè\n"
	.string "jo seia al teu costat!\p"
	.string "L'As del Domo va mirar cap aquí\n"
	.string "perquè els meus crits eren\l"
	.string "molt forts!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "Oh, silenci!\n"
	.string "Baixeu la veu!\p"
	.string "Fans com vosaltres hauríeu\n"
	.string "d'animar algun Líder de Gimnàs!\p"
	.string "L'As del Domo és meu!\n"
	.string "L'únic ídol per a mi!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "Aquesta gent discutint allà…\p"
	.string "Costa de creure, però abans\n"
	.string "eren Entrenadors, i dels bons.\p"
	.string "Eren increïblement forts\n"
	.string "i famosos.\p"
	.string "Però van ser aniquilats per un\n"
	.string "cert Entrenador en un torneig.\p"
	.string "Van quedar tan impressionats,\n"
	.string "que es van enamorar d'ell.\p"
	.string "Ara són fans d'aquell Entrenador.\n"
	.string "Van a animar el seu ídol al\l"
	.string "Domo de Combat cada dia.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "He sentit un rumor que algú va\n"
	.string "veure un Pokémon amb una cua\l"
	.string "molt llarga a la Frontera.\p"
	.string "Deu ser adorable. N'estic segura…\p"
	.string "Oh, els desafiaments poden esperar.\n"
	.string "He de trobar la criatura!$"

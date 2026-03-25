.set LOCALID_ATTENDANT, 1
.set LOCALID_NURSE, 2
.set LOCALID_GIRL, 4
.set LOCALID_MAN, 5

TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy OBJ_EVENT_ID_PLAYER, 9, 6
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_NURSE
	addobject LOCALID_ATTENDANT
	addobject LOCALID_MAN
	addobject LOCALID_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
  callnative UpdateFollowingPokemon
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
  callnative UpdateFollowingPokemon
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Expanded:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

TrainerHill_Entrance_Text_StillGettingReady:
	.string "Aquest és el Turó dels Entrenadors,\n"
	.string "on pots gaudir de combats per\l"
	.string "parelles amb molts Entrenadors.\p"
	.string "Malauradament, encara estem\n"
	.string "preparant-ho tot.\l"
	.string "Torna més tard, si us plau!$"

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
	.string "Benvingut!\p"
	.string "Aquest és el Turó dels Entrenadors,\n"
	.string "on pots gaudir de combats per\l"
	.string "parelles amb molts Entrenadors!$"

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
	.string "És la teva primera visita aquí?\p"
	.string "Abans d'entrar, si us plau,\n"
	.string "desa la partida.$"

TrainerHill_Entrance_Text_TrainersUpToFloorX:
	.string "A veure…\n"
	.string "Els Entrenadors d'aquí ara són…\p"
	.string "Fins al pis núm. {STR_VAR_1}.$"

TrainerHill_Entrance_Text_TrainersInEveryRoom:
	.string "A veure…\n"
	.string "Els Entrenadors d'aquí ara són…\p"
	.string "Sembla que hi ha Entrenadors\n"
	.string "reunits a totes les sales.$"

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
	.string "Vols desafiar els Entrenadors\n"
	.string "que estan esperant?$"

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
	.string "Cronometraré el teu progrés.\n"
	.string "Molta sort!\p"
	.string "Preparats…\p"
	.string "Llestos…\p"
	.string "Ja!$"

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
	.string "Torna a visitar-nos!$"

TrainerHill_Entrance_Text_TooBadTremendousEffort:
	.string "Quina llàstima.\p"
	.string "Crec que has fet un esforç\n"
	.string "tremend en els teus combats.\p"
	.string "Torna i prova-ho de nou!$"

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
	.string "Espero que donis el millor de tu.$"

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
	.string "Quan els Entrenadors canvien de\n"
	.string "lloc, el moviment pot ser caòtic.\p"
	.string "Per evitar l'allau, hem mogut\n"
	.string "el taulell de recepció aquí.\p"
	.string "Disculpa les molèsties.$"

TrainerHill_Entrance_Text_ThankYouForPlaying:
	.string "Gràcies per participar!$"

TrainerHill_Entrance_Text_ExplainTrainerHill:
	.string "Aquí, al Turó dels Entrenadors,\n"
	.string "organitzem un event anomenat\l"
	.string "Atac Contrarellotge.\p"
	.string "És una cursa que mesura quant\n"
	.string "trigues a arribar al propietari\l"
	.string "al terrat des d'aquest taulell.\p"
	.string "Els millors temps es publiquen al\n"
	.string "Tauler de Temps. Prova a competir\l"
	.string "amb els teus amics.\p"
	.string "En els combats pel camí, no es\n"
	.string "donaran ni Punts d'Exp. ni diners.$"

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
	.string "Oh, ho sento, però sembla que\n"
	.string "només tens un Pokémon amb tu.\p"
	.string "Necessitaràs almenys dos Pokémon\n"
	.string "per participar en aquest event.$"

TrainerHill_Roof_Text_YouFinallyCameBravo:
	.string "Hm! Hm!\p"
	.string "Per fi has vingut!\n"
	.string "Sí, has arribat!\p"
	.string "Espera! No ho diguis!\n"
	.string "Sé per què has vingut fins aquí\l"
	.string "tu sol!\p"
	.string "Volies veure'm a mi, el propietari\n"
	.string "del Turó dels Entrenadors,\l"
	.string "perquè…\p"
	.string "Vols formar un equip amb mi!\n"
	.string "Visca!\p"
	.string "…Eh?\n"
	.string "No és això?\p"
	.string "En tot cas, t'he observat pujant.\n"
	.string "Combats meravellosos! Bravo!$"

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
	.string "Per a algú tan meravellós com tu,\n"
	.string "tinc el regal més meravellós!$"

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
	.string "Oh, no, tot ple de coses!\n"
	.string "Tornaràs més tard a buscar-ho!$"

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
	.string "Oh, espera! Has arribat aquí\n"
	.string "meravellosament ràpid?\p"
	.string "Que esplèndid! No calia que\n"
	.string "t'afanyessis tant per veure'm!\p"
	.string "Que encantador! Faré que\n"
	.string "actualitzin el Tauler de Temps\l"
	.string "a la recepció!$"

TrainerHill_Roof_Text_YouWerentVeryQuick:
	.string "Però, oh…\n"
	.string "No has estat gaire ràpid.$"

TrainerHill_Roof_Text_ArriveZippierNextTime:
	.string "Potser m'agradaria més si\n"
	.string "arribessis més ràpid el pròxim\l"
	.string "cop.\p"
	.string "Aleshores, estaré encantat de\n"
	.string "formar equip amb tu!\p"
	.string "Fins que ens retrobem, amic!$"

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
	.string "Vaig fer construir el Turó dels\n"
	.string "Entrenadors per una sola raó!\p"
	.string "Per trobar el company més adequat\n"
	.string "amb qui formar un equip!$"

TrainerHill_Entrance_Text_ChallengeTime:
	.string "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} seg.$"

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
	.string "Qui sap quina mena d'Entrenadors\n"
	.string "i combinacions de Pokémon hi ha?\p"
	.string "L'únic que sé és que atuiré\n"
	.string "qualsevol que se'm posi al davant!$"

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
	.string "He sentit que Entrenadors forts\n"
	.string "vénen a aquest Turó d'arreu.\p"
	.string "No puc esperar per provar sort!\p"
	.string "Atuiré qualsevol que se'm posi\n"
	.string "al davant!$"

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.string "Veus el Tauler de Temps d'allà?\p"
	.string "Els meus amics i jo estem intentant\n"
	.string "veure qui arriba al cim en menys\l"
	.string "temps.$"

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
	.string "Saps quan obriran aquest lloc?\p"
	.string "Estic esperant per ser el primer\n"
	.string "aspirant de la història!$"

TrainerHill_Elevator_Text_ReturnToReception:
	.string "Vols tornar al taulell\n"
	.string "de recepció?$"

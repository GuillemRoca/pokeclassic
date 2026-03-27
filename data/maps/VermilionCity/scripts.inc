.set LOCALID_OAK, 1
.set LOCALID_SAILOR, 7
.set LOCALID_JENNY, 9
.set LOCALID_SQUIRTLE, 10

VermilionCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, VermilionCity_OnResume
	.byte 0

VermilionCity_OnTransition:
	setflag FLAG_VISITED_VERMILION_CITY
	call_if_set FLAG_GOT_SQUIRTLE,  VermillionCity_EventScript_RepositionJenny
	call Common_EventScript_GetDayOrNight
	end

VermillionCity_EventScript_RepositionJenny::
	setobjectxyperm LOCALID_JENNY, 22, 20
	setobjectmovementtype LOCALID_JENNY, MOVEMENT_TYPE_LOOK_AROUND
	return

VermilionCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end

VermilionCity_EventScript_CitySign::
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
	end

VermilionCity_Text_CitySign::
    .string "Ciutat Vermilion\n"
    .string "El Port de les Postes de Sol$"

@TODO: Change text depending on Snorlax State
VermilionCity_EventScript_SnorlaxNotice::
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
	end

VermilionCity_Text_SnorlaxBlockingRoute12::
    .string "AVÍS!\p"
    .string "La Ruta 12 pot estar bloquejada\n"
    .string "per un Pokémon adormit.\p"
    .string "Desvia't pel Túnel Roca cap a\n"
    .string "Poble Lavanda.\p"
    .string "Policia de Vermilion$"

VermilionCity_EventScript_PokemonFanClubSign::
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

VermilionCity_Text_PokemonFanClubSign::
    .string "Club de Fans Pokémon\n"
    .string "Tots els fans Pokémon benvinguts!$"

VermilionCity_EventScript_GymSign::
	lockall
	msgbox VermilionCity_Text_GymSign, MSGBOX_SIGN
	releaseall
	end

VermilionCity_Text_GymSign::
    .string "Gimnàs Pokémon de Vermilion\n"
    .string "Líder: Lt. Surge\l"
    .string "El Lloctinent Llampec!$"

VermilionCity_EventScript_HarborSign::
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
	end

VermilionCity_Text_VermilionHarbor::
    .string "Port de Vermilion$"

VermilionCity_EventScript_ProfOakTrigger1::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 1
	goto VermilionCity_EventScript_ProfOak

VermilionCity_EventScript_ProfOakTrigger2::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 2
	goto VermilionCity_EventScript_ProfOak

VermilionCity_EventScript_ProfOakTrigger3::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 3
	goto VermilionCity_EventScript_ProfOak

VermilionCity_EventScript_ProfOak::
	applymovement LOCALID_OAK, Movement_OakDockApproach
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_OAK, Common_Movement_ExclamationMark
	waitse
	playbgm MUS_RG_OAK, 0
	call_if_eq VAR_TEMP_1, 1, VermilionCity_EventScript_OakApproachPlayer1
	call_if_eq VAR_TEMP_1, 2, VermilionCity_EventScript_OakApproachPlayer2
	call_if_eq VAR_TEMP_1, 3, VermilionCity_EventScript_OakApproachPlayer3
	waitmovement 1
	msgbox VermilionCity_Text_VisitedSSAnne, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredOak, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_PROF_OAK
	setvar VAR_OAK_LAB_STATE, 9
	release
	msgbox VermilionCity_Text_EnjoySSAnne, MSGBOX_DEFAULT
	call_if_le VAR_TEMP_1, 2, VermilionCity_EventScript_OakExit
	call_if_eq VAR_TEMP_1, 3, VermilionCity_EventScript_OakExitAlt
	waitmovement 1
	removeobject LOCALID_OAK
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	fadedefaultbgm
	releaseall
	end

Movement_OakDockApproach::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VermilionCity_Text_VisitedSSAnne::
	.string "Oak: Oh! {PLAYER}! Anaves a\n"
	.string "visitar el S.S. Anne?\p"
	.string "Em temo que t'has perdut la meva\n"
	.string "presentació sobre la Pokédex!\p"
	.string "Què, no sabies que hi seria?\n"
	.string "Quina llàstima...\p"
	.string "Oh! Ja ho sé! Tens un Mòbil,\n"
	.string "oi? Et donaré el meu número!\p"
	.string "Així, podria contactar-te si\n"
	.string "sorgeix alguna cosa. I si vols,\l"
	.string "pots trucar-me per avaluar la\l"
	.string "teva Pokédex mentre ets al\l"
	.string "camp.$"

VermilionCity_Text_EnjoySSAnne::
	.string "Oak: M'ha agradat veure't!\n"
	.string "Gaudeix del S.S. Anne.\p"
	.string "Hi ha molts entrenadors forts\n"
	.string "reunint-s'hi, però no et\l"
	.string "distreguis de la Pokédex!$"

VermilionCity_EventScript_OakApproachPlayer1::
	applymovement LOCALID_OAK, Movement_OakDockEntrance1
	return

Movement_OakDockEntrance1::
	walk_up
	walk_up
	walk_left
	face_up
	step_end

VermilionCity_EventScript_OakApproachPlayer2::
	applymovement LOCALID_OAK, Movement_OakDockEntrance2
	return

Movement_OakDockEntrance2::
	walk_up
	walk_up
	step_end

VermilionCity_EventScript_OakApproachPlayer3::
	applymovement LOCALID_OAK, Movement_OakDockEntrance3
	return

Movement_OakDockEntrance3::
	walk_up
	walk_up
	walk_right
	face_up
	step_end

VermilionCity_EventScript_OakExit::
	applymovement LOCALID_OAK, Movement_OakDockExit
	return

Movement_OakDockExit::
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

VermilionCity_EventScript_OakExitAlt::
	applymovement LOCALID_OAK, Movement_OakDockExitAlt
	return

Movement_OakDockExitAlt::
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end


VermilionCity_EventScript_OldMan1::
	lock
	faceplayer
	goto_if_eq VAR_SS_ANNE_STATE, 3, VermilionCity_EventScript_OldMan1SSAnneLeft
	msgbox VermilionCity_Text_DidYouSeeSSAnneInHarbor
	release
	end

VermilionCity_Text_DidYouSeeSSAnneInHarbor::
    .string "Has vist el S.S. Anne atracat\n"
    .string "al port?$"

VermilionCity_EventScript_OldMan1SSAnneLeft::
	msgbox VermilionCity_Text_SSAnneHasDepartedForYear
	release
	end

VermilionCity_Text_SSAnneHasDepartedForYear::
    .string "Així que el S.S. Anne ha marxat?\p"
    .string "Tornarà a Vermilion cap a\n"
    .string "aquesta època l'any que ve.$"

VermilionCity_EventScript_Woman::
	msgbox VermilionCity_Text_GrimerMultipliesInSludge, MSGBOX_NPC
	end

VermilionCity_Text_GrimerMultipliesInSludge::
    .string "Aquí tenim cura de la contaminació.\p"
    .string "Hem sentit que Grimer es multiplica\n"
    .string "en els fangs tòxics.$"

VermilionCity_EventScript_OldMan2::
	msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
	end

VermilionCity_Text_BuildingOnThisLand::
    .string "Estic construint un edifici en\n"
    .string "aquest terreny. Tot és meu.\p"
    .string "El meu Pokémon està compactant\n"
    .string "la terra per als fonaments.$"

VermilionCity_EventScript_Machop::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	msgbox VermilionCity_Text_Machop, MSGBOX_NPC
	waitmoncry
	msgbox VermilionCity_Text_MachopStompingLandFlat, MSGBOX_NPC
	release
	end

VermilionCity_Text_Machop::
    .string "Machop: Guoh! Gogogoh!$"

VermilionCity_Text_MachopStompingLandFlat::
    .string "Un Machop està aplanant la terra.$"

VermilionCity_EventScript_Sailor::
	msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
	end

VermilionCity_Text_SSAnneVisitsOnceAYear::
    .string "El S.S. Anne és un famós creuer\n"
    .string "de luxe.\p"
    .string "Visita Vermilion un cop l'any.$"

VermilionCity_EventScript_FerrySailor::
	lock
	faceplayer
	goto_if_eq VAR_SS_ANNE_STATE, 3, VermilionCity_EventScript_CheckSSTidal
	msgbox VermilionCity_Text_WelcomeToTheSSAnne, MSGBOX_NPC
	release
	end

VermilionCity_Text_WelcomeToTheSSAnne::
    .string "Mariner: Benvingut al S.S. Anne!$"

VermilionCity_EventScript_CheckSSTidal::
	goto_if_unset FLAG_HIDE_SS_TIDAL, VermilionCity_EventScript_SSTidalArrived
	msgbox VermilionCity_Text_TheShipSetSail, MSGBOX_NPC
	release
	end

VermilionCity_Text_TheShipSetSail::
    .string "El vaixell ha salpat.$"

VermilionCity_EventScript_SSTidalArrived::
	.string "N'has sentit a parlar?\p"
	.string "Un nou vaixell, el S.S. Tidal, ha\n"
	.string "arribat al port!$"

VermilionCity_EventScript_TicketCheckTrigger1::
	lock
	setvar VAR_TEMP_2, 1
	goto VermilionCity_EventScript_TicketCheck
	end

VermilionCity_EventScript_TicketCheckTrigger2::
	lock
	setvar VAR_TEMP_2, 2
	goto VermilionCity_EventScript_TicketCheck
	end

VermilionCity_EventScript_TicketCheck::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_TEMP_2, 1, VermilionCity_EventScript_TicketCheck1
	call_if_eq VAR_TEMP_2, 2, VermilionCity_EventScript_TicketCheck2
	waitmovement 7
	msgbox VermilionCity_Text_DoYouHaveATicket, MSGBOX_NPC
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_EventScript_NoTicket
	playse SE_PIN
	msgbox VermilionCity_Text_FlashedSSTicket, MSGBOX_DEFAULT
	setvar VAR_SS_TICKET_CHECK, 1
	waitse
	msgbox VermilionCity_Text_SailorGreat, MSGBOX_NPC
	call_if_eq VAR_TEMP_2, 1, VermilionCity_EventScript_MoveSailor1
	call_if_eq VAR_TEMP_2, 2, VermilionCity_EventScript_MoveSailor2
	end

VermilionCity_Text_DoYouHaveATicket::
    .string "Mariner: Benvingut al S.S. Anne!\p"
    .string "Disculpa, tens un bitllet?$"

VermilionCity_Text_FlashedSSTicket::
    .string "{PLAYER} ha ensenyat el BITLLET!$"

VermilionCity_Text_SailorGreat::
    .string "Mariner: Genial!\n"
    .string "Benvingut al S.S. Anne!$"

VermilionCity_EventScript_TicketCheck1::
	applymovement LOCALID_SAILOR, Movement_TicketCheck1
	return

Movement_TicketCheck1::
	walk_left
	walk_left
	face_up
	step_end

VermilionCity_EventScript_TicketCheck2::
	applymovement LOCALID_SAILOR, Movement_TicketCheck2
	return

Movement_TicketCheck2::
	walk_left
	face_up
	step_end

VermilionCity_EventScript_NoTicket::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	waitse
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
	call_if_eq VAR_TEMP_2, 1, VermilionCity_EventScript_MoveSailor1
	call_if_eq VAR_TEMP_2, 2, VermilionCity_EventScript_MoveSailor2
	waitmovement 7
	applymovement OBJ_EVENT_ID_PLAYER, Movement_CannotEnterSSAnne
	waitmovement 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

VermilionCity_Text_DontHaveNeededSSTicket::
    .string "Ho sento!\p"
    .string "Necessites un Bitllet per pujar.$"

VermilionCity_EventScript_MoveSailor1::
	applymovement LOCALID_SAILOR, Movement_MoveSailor1
	return

Movement_MoveSailor1::
	walk_right
	walk_right
	face_up
	step_end

VermilionCity_EventScript_MoveSailor2::
	applymovement LOCALID_SAILOR, Movement_MoveSailor2
	return

Movement_MoveSailor2::
	walk_right
	face_up
	step_end

Movement_CannotEnterSSAnne::
	walk_up
	walk_up
	step_end

VermilionCity_EventScript_ExitedTicketCheck::
	lockall
	setvar VAR_SS_TICKET_CHECK, 0
	releaseall
	end

VermilionCity_EventScript_SquirtleEventAlternate::
	setvar VAR_GOT_SQUIRTLE, 2
VermilionCity_EventScript_SquirtleEvent::
	lockall
	turnobject LOCALID_JENNY, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_JENNY, Common_Movement_ExclamationMark
	waitse
	msgbox VermilionCity_Text_SquirtleIsAMenace, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE03_GET, VermilionCity_EventScript_DontGiveSquirtle
	call_if_eq VAR_GOT_SQUIRTLE, 2, VermilionCity_EventScript_Sidestep
	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepForward
	waitmovement 0
	playse SE_PIN
	message VermilionCity_Text_PlayerFlashedBadge
	waitse
	waitmessage
	msgbox VermilionCity_Text_AStrongTrainer, MSGBOX_DEFAULT
	waitmessage
	turnobject LOCALID_JENNY, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_SQUIRTLE, Movement_MoveToPlayer
	waitmovement 10
	playse SE_PIN
	applymovement LOCALID_SQUIRTLE, Common_Movement_Heart
	setvar VAR_TEMP_1, SPECIES_SQUIRTLE
	givemon SPECIES_SQUIRTLE, 10, ITEM_BLACK_GLASSES
	goto_if_eq VAR_RESULT, 0, VermilionCity_EventScript_SquirtleParty
	goto_if_eq VAR_RESULT, 1, VermilionCity_EventScript_SquirtlePC
	goto_if_eq VAR_RESULT, 2, VermilionCity_EventScript_NoRoomForSquirtle
	releaseall
	end


VermilionCity_EventScript_SquirtleParty::
	call VermilionCity_EventScript_GetSquirtle
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_EventScript_GotSquirtle
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto VermilionCity_EventScript_GotSquirtle
	end

VermilionCity_EventScript_GetSquirtle::
	playfanfare MUS_LEVEL_UP
	message VermilionCity_EventScript_Text_BailedOutSquirtle
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_SQUIRTLE
	return

VermilionCity_EventScript_Text_BailedOutSquirtle::
	.string "{PLAYER} ha rescatat el Squirtle!$"

VermilionCity_EventScript_GotSquirtle::
	setflag FLAG_GOT_SQUIRTLE
	setvar VAR_GOT_SQUIRTLE, 1
	removeobject LOCALID_SQUIRTLE
	release
	end

VermilionCity_EventScript_SquirtlePC::
	call VermilionCity_EventScript_GetSquirtle
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_EventScript_TransferSquirtle
	call Common_EventScript_NameReceivedBoxMon
	goto VermilionCity_EventScript_TransferSquirtle
	end

VermilionCity_EventScript_TransferSquirtle::
	bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
	call Common_EventScript_TransferredToPC
	goto VermilionCity_EventScript_GotSquirtle
	end

VermilionCity_EventScript_NoRoomForSquirtle::
	msgbox VermilionCity_Text_NoRoomForMorePokemon, MSGBOX_DEFAULT
	applymovement LOCALID_SQUIRTLE, Movement_SquirtleReturn
	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepBack
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepBack
	waitmovement 0
	release
	end

Movement_SquirtleReturn::
	walk_right
	walk_up
	face_left
	step_end

VermilionCity_Text_NoRoomForMorePokemon::
    .string "Agent: No tens espai?\n"
    .string "Doncs, a la presó, Squirtle!$"

VermilionCity_EventScript_Sidestep::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_Sidestep
	waitmovement 0
	return

Movement_Sidestep::
	walk_left
	step_end

Movement_MoveToPlayer::
	walk_down
	walk_left
	step_end

VermilionCity_Text_PlayerFlashedBadge::
	.string "{PLAYER} ha ensenyat la Medalla Tro.$"

VermilionCity_Text_AStrongTrainer::
	.string "Agent: Oh! Tens la Medalla Tro?\p"
	.string "Has de ser un entrenador molt fort.\p"
	.string "Què dius?\p"
	.string "Dius que respondràs per aquest\n"
	.string "Pokémon?\p"
	.string "...\p"
	.string "No sé què dirà el meu cap sobre\n"
	.string "això, però tinc un bon pressentiment\l"
	.string "sobre tu.\p"
	.string "Has demostrat les teves habilitats\n"
	.string "com a entrenador Pokémon.\p"
	.string "Potser un bon model a seguir és\n"
	.string "el que necessita aquest Pokémon!$"


VermilionCity_EventScript_DontGiveSquirtle::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepBack
	waitmovement 0
	setvar VAR_GOT_SQUIRTLE, 0
	release
	end

 Movement_StepForward::
 	walk_up
 	step_end

VermilionCity_Text_SquirtleIsAMenace::
	.string "Agent: Enrere, ciutadà!\p"
	.string "Aquest Squirtle és un perillós!\p"
	.string "Ha estat cometent delictes per\n"
	.string "tota Ciutat Vermilion!\p"
	.string "L'he acorralat, però espero\n"
	.string "reforços per endur-me'l!$"

VermilionCity_EventScript_Jenny::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SQUIRTLE, VermilionCity_EventScript_JennyGaveSquirtle
	msgbox VermilionCity_Text_SquirtleIsAMenace, MSGBOX_NPC
	release
	end

VermilionCity_EventScript_JennyGaveSquirtle::
	msgbox VermilionCity_Text_JennyGaveSquirtle, MSGBOX_NPC
	release
	end

VermilionCity_Text_JennyGaveSquirtle::
	.string "Primer van ser Motards i Lladres,\n"
	.string "i després l'Equip Rocket.\p"
	.string "Aquesta feina ja és prou difícil\n"
	.string "sense que els Pokémon també\l"
	.string "es dediquin al crim!$"

VermilionCity_EventScript_Squirtle::
	lock
	faceplayer
	playmoncry SPECIES_SQUIRTLE, CRY_MODE_NORMAL
	msgbox VermilionCity_Text_SquirtleGlasses, MSGBOX_NPC
	release
	end

VermilionCity_Text_SquirtleGlasses::
	.string "Porta ulleres de sol, aquest\n"
	.string "Squirtle?$"

VermilionCity_EventScript_Blastoisinite::
	finditem ITEM_BLASTOISINITE, 1
	release
	end

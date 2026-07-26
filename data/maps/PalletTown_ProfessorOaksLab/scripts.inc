.set LOCALID_OAK, 1
.set LOCALID_RIVAL, 2
.set LOCALID_POKEBALL, 3
.set LOCALID_POKEDEX_L, 7
.set LOCALID_POKEDEX_R, 8
.set LOCALID_PIKACHU, 9

@OAK LAB STATES:
@ 0: Player hasn't met Oak yet
@ 1: Player met Oak and warped back to lab
@ 2: Oak gave intro speech
@ 3: Rival grabbed Eevee
@ 4: Triggered Rival Battle
@ 5: Returned from Rival Battle
@ 6: Collected Oak's Parcel
@ 7: Received Pokedex
@ 8: Left Lab after getting Pokedex
@ 9: Registered Oak in Cell Phone

PalletTown_ProfessorOaksLab_MapScripts::
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, PalletTown_ProfessorOaksLab_OnReturnToField
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_ProfessorOaksLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_ProfessorOaksLab_OnFrame
	.byte 0

PalletTown_ProfessorOaksLab_OnReturnToField:
	call_if_eq VAR_OAK_LAB_STATE, 4, PalletTown_ProfessorOaksLab_EventScript_HealAfterFirstBattle
	end

PalletTown_ProfessorOaksLab_EventScript_HealAfterFirstBattle::
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	setvar VAR_OAK_LAB_STATE, 5
	end

PalletTown_ProfessorOaksLab_OnWarp:
	map_script_2 VAR_OAK_LAB_STATE, 1, PalletTown_ProfessorOaksLab_EventScript_SetPositionsForStarterScene
	map_script_2 VAR_OAK_LAB_STATE, 6, PalletTown_ProfessorOaksLab_EventScript_SetPositionsForPokedexScene
	.2byte 0

PalletTown_ProfessorOaksLab_EventScript_SetPositionsForStarterScene::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_RIVAL, DIR_NORTH
	end

PalletTown_ProfessorOaksLab_EventScript_SetPositionsForPokedexScene::
	setobjectxyperm LOCALID_RIVAL, 6, 11
	setobjectmovementtype LOCALID_OAK, MOVEMENT_TYPE_FACE_UP
	savebgm MUS_RG_OAK
	end

PalletTown_ProfessorOaksLab_OnFrame:
	map_script_2 VAR_OAK_LAB_STATE, 1, PalletTown_ProfessorOaksLab_EventScript_GetStarterScene
	map_script_2 VAR_OAK_LAB_STATE, 6, PalletTown_ProfessorOaksLab_EventScript_GetPokedexScene
	.2byte 0

PalletTown_ProfessorOaksLab_EventScript_GetStarterScene::
	lockall
	msgbox PalletTown_ProfessorOaksLab_Text_RivalFedUpWithWaiting, MSGBOX_DEFAULT
	applymovement LOCALID_OAK, Common_Movement_QuestionMark
	waitmovement 1
	msgbox PalletTown_ProfessorOaksLab_Text_TakeStarter, MSGBOX_DEFAULT
	msgbox PalletTown_ProfessorOaksLab_Text_RivalNoFairWhatAboutMe, MSGBOX_DEFAULT
	msgbox PalletTown_ProfessorOaksLab_Text_OakBePatientRival, MSGBOX_DEFAULT
	setvar VAR_OAK_LAB_STATE, 2
	releaseall
	end

PalletTown_ProfessorOaksLab_Text_RivalFedUpWithWaiting:
    .string "{RIVAL}: Avi!\n"
    .string "Estic tip d'esperar!$"

PalletTown_ProfessorOaksLab_Text_TakeStarter::
    .string "Oak: {RIVAL}?\n"
    .string "Deixa'm pensar…\p"
    .string "Ah, és clar, t'havia dit que\n"
    .string "vinguessis! Espera't una mica!\p"
    .string "Vine, {PLAYER}.\p"
    .string "Hi ha una Pokéball al meu escriptori.\p"
    .string "Quan era jove, era un entrenador\n"
    .string "Pokémon de debò.\p"
    .string "Però ara, de gran, estudio els\n"
    .string "Pokémon més que no combato.\p"
    .string "M'agradaria que criessis aquest\n"
    .string "Pokémon per mi!$"

PalletTown_ProfessorOaksLab_Text_RivalNoFairWhatAboutMe::
    .string "{RIVAL}: Ei! Avi! No és just!\n"
    .string "I jo què?$"

PalletTown_ProfessorOaksLab_Text_OakBePatientRival::
    .string "Oak: Tingues paciència, {RIVAL}.\p"
    .string "Després et portaré a capturar\n"
    .string "el teu propi Pokémon.$"

PalletTown_ProfessorOaksLab_EventScript_ApproachPokeBallBehindDesk::
	lockall
	turnobject LOCALID_RIVAL, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 2
	applymovement LOCALID_RIVAL, Movement_RivalMoveToDesk2
	waitmovement 2
	applymovement LOCALID_RIVAL, Movement_StealEeveeTooSlow
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox PalletTown_ProfessorOaksLab_Text_TooSlow, MSGBOX_DEFAULT
	removeobject LOCALID_POKEBALL
	setflag FLAG_HIDE_OAK_LAB_POKEBALL
	msgbox PalletTown_ProfessorOaksLab_Text_WereGoingToGetOne, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerReturnToOakFar
	waitmovement 0
	goto PalletTown_ProfessorOaksLab_EventScript_GetPartnerPikachu
	end

Movement_RivalMoveToDesk2::
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

Movement_StealEeveeTooSlow::
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	delay_16
	delay_16
	delay_16
	step_end

PalletTown_ProfessorOaksLab_Text_TooSlow::
	.string "{RIVAL}: Massa lent, {PLAYER}!\p"
	.string "Això et passa per venir\n"
	.string "fent la volta llarga.$"

Movement_PlayerReturnToOakFar::
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	face_up
	step_end

PalletTown_ProfessorOaksLab_EventScript_RivalStealEevee::
	lockall
	turnobject LOCALID_RIVAL, DIR_EAST
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 2
	applymovement LOCALID_RIVAL, Movement_RivalMoveToDesk
	waitmovement 2
	playse SE_WALL_HIT
	applymovement LOCALID_RIVAL, Movement_PushPlayer
	applymovement OBJ_EVENT_ID_PLAYER, Movement_GetPushed
	waitse
	waitmovement 2
	applymovement LOCALID_RIVAL, Movement_TakeEevee
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitse
	waitmovement 0
	removeobject LOCALID_POKEBALL
	setflag FLAG_HIDE_OAK_LAB_POKEBALL
	msgbox PalletTown_ProfessorOaksLab_Text_WereGoingToGetOne, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerReturnToOak
	waitmovement 0
	goto PalletTown_ProfessorOaksLab_EventScript_GetPartnerPikachu
	end

Movement_RivalMoveToDesk::
	walk_right
	walk_right
	walk_right
	step_end

Movement_PushPlayer::
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

Movement_GetPushed::
	walk_right
	face_left
	step_end

Movement_TakeEevee::
	walk_right
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	delay_16
	step_end

Movement_PlayerReturnToOak::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

PalletTown_ProfessorOaksLab_Text_WereGoingToGetOne::
	.string "Oak: {RIVAL}!\p"
	.string "Uf...està bé.\n"
	.string "Aquest Pokémon és teu.\p"
	.string "{PLAYER}, vine cap aquí.$"

PalletTown_ProfessorOaksLab_EventScript_PreventExit::
	applymovement LOCALID_OAK, Movement_OakStopPlayer
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_OAK, Common_Movement_QuestionMark
	waitmovement 1
	msgbox PalletTown_ProfessorOaksLab_Text_DontWantAPokemon, MSGBOX_DEFAULT
	applymovement LOCALID_OAK, Movement_OakReturnToPosition
	applymovement OBJ_EVENT_ID_PLAYER, Movement_CantExitLab
	waitmovement 0
	release
	end

Movement_OakStopPlayer::
	walk_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	delay_8
	step_end

Movement_OakReturnToPosition::
	walk_up
	face_down
	step_end

PalletTown_ProfessorOaksLab_Text_DontWantAPokemon::
	.string "Oak: No vols un\n"
	.string "Pokémon, {PLAYER}?$"

Movement_CantExitLab::
	walk_up
	face_up
	step_end

PalletTown_ProfessorOaksLab_EventScript_GetPartnerPikachu::
	msgbox PalletTown_ProfessorOaksLab_Text_PikachuFromEarlier, MSGBOX_DEFAULT
	playse SE_BALL_OPEN
	clearflag FLAG_HIDE_OAK_LAB_PIKACHU
	addobject LOCALID_PIKACHU
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	waitmoncry
	turnobject LOCALID_OAK, DIR_WEST
	applymovement LOCALID_OAK, Common_Movement_ExclamationMark
	msgbox PalletTown_ProfessorOaksLab_Text_PikachuBrokeFree, MSGBOX_DEFAULT
	turnobject LOCALID_OAK, DIR_SOUTH
	msgbox PalletTown_ProfessorOaksLab_Text_PikachuWantsToFollow, MSGBOX_DEFAULT
	applymovement LOCALID_PIKACHU, Movement_PikachuJoinsParty
	waitmovement 9
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_PIKACHU, Common_Movement_Heart
	waitmovement 9
	waitse
	givemon SPECIES_PIKACHU_PARTNER, 5
	playfanfare MUS_OBTAIN_ITEM
	msgbox PalletTown_ProfessorOaksLab_Text_PikachuJoinedTeam, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	setflag FLAG_SYS_POKEMON_GET
	msgbox PalletTown_ProfessorOaksLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PalletTown_ProfessorOaksLab_EventScript_NicknameStarter
	goto_if_eq VAR_RESULT, NO, PalletTown_ProfessorOaksLab_EventScript_PikachuJoinsParty
	end

Movement_PikachuJoinsParty::
	walk_down
	face_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	step_end

PalletTown_ProfessorOaksLab_Text_PikachuFromEarlier:
	.string "Oak: Tècnicament, aquell no era\n"
	.string "el meu últim Pokémon.\p"
	.string "Encara tinc el Pikachu\n"
	.string "que he capturat abans...\p"
	.string "Pensava tornar-lo al seu\n"
	.string "hàbitat natural, però\l"
	.string "potser val més que te'l quedis.$"
	
PalletTown_ProfessorOaksLab_Text_PikachuBrokeFree:
	.string "Oak: Increïble!\p"
	.string "Ha sortit de la seva Pokéball!$"

PalletTown_ProfessorOaksLab_Text_PikachuWantsToFollow:
	.string "Oak: Sembla que li has despertat\n"
	.string "molt d'interès, {PLAYER}.\p"
	.string "Sembla que Pikachu ja ha pres\n"
	.string "la seva decisió!\p"
	.string "Sens dubte t'has de quedar aquest\n"
	.string "Pokémon.$"

PalletTown_ProfessorOaksLab_Text_PikachuJoinedTeam:
	.string "Pikachu ha decidit quedar-se al\n"
	.string "costat de {PLAYER}!$"

PalletTown_ProfessorOaksLab_Text_WhyNotGiveNicknameToMon:
	.string "Oak: Escolta, per què no poses\n"
	.string "un sobrenom al teu nou company?$"

PalletTown_ProfessorOaksLab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto PalletTown_ProfessorOaksLab_EventScript_PikachuJoinsParty
	end

PalletTown_ProfessorOaksLab_EventScript_PikachuJoinsParty::
	removeobject LOCALID_PIKACHU
	setflag FLAG_HIDE_OAK_LAB_PIKACHU
	callnative UpdateFollowingPokemon
	setvar VAR_OAK_LAB_STATE, 3
	releaseall
	end

PalletTown_ProfessorOaksLab_EventScript_RivalTrigger1::
	setvar VAR_TEMP_1, 1
	goto PalletTown_ProfessorOaksLab_EventScript_RivalWantsToBattle
	end

PalletTown_ProfessorOaksLab_EventScript_RivalTrigger2::
	setvar VAR_TEMP_1, 2
	goto PalletTown_ProfessorOaksLab_EventScript_RivalWantsToBattle
	end

PalletTown_ProfessorOaksLab_EventScript_RivalTrigger3::
	setvar VAR_TEMP_1, 3
	goto PalletTown_ProfessorOaksLab_EventScript_RivalWantsToBattle
	end

PalletTown_ProfessorOaksLab_EventScript_RivalWantsToBattle::
	lockall
	setvar VAR_OAK_LAB_STATE, 4
	turnobject LOCALID_RIVAL, DIR_SOUTH
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLetsCheckOutMons, MSGBOX_DEFAULT
	call_if_eq VAR_TEMP_1, 1, PalletTown_ProfessorOaksLab_EventScript_RivalApproach1
	call_if_eq VAR_TEMP_1, 2, PalletTown_ProfessorOaksLab_EventScript_RivalApproach2
	call_if_eq VAR_TEMP_1, 3, PalletTown_ProfessorOaksLab_EventScript_RivalApproach3
	waitmovement 2
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TRAINER_RIVAL_FIRST_BATTLE,PalletTown_ProfessorOaksLab_Text_RivalBattleIntro,PalletTown_ProfessorOaksLab_Text_RivalDefeated,PalletTown_ProfessorOaksLab_EventScript_RivalBattleOutcome
	end

PalletTown_ProfessorOaksLab_Text_RivalLetsCheckOutMons::
    .string "{RIVAL}: Espera, {PLAYER}!$"

PalletTown_ProfessorOaksLab_Text_RivalBattleIntro::
    .string "Provem els nostres Pokémon!\p"
    .string "Vinga, t'accepto el repte!$"

PalletTown_ProfessorOaksLab_Text_RivalDefeated::
    .string "{RIVAL}: QUÈ?\n"
    .string "No m'ho puc creure!\l"
    .string "He triat el Pokémon equivocat!$"

PalletTown_ProfessorOaksLab_EventScript_RivalBattleOutcome::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PalletTown_ProfessorOaksLab_EventScript_RivalBattleWon
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleLost
	end

PalletTown_ProfessorOaksLab_EventScript_RivalBattleLost::
	msgbox PalletTown_ProfessorOaksLab_Text_RivalVictory, MSGBOX_DEFAULT
	goto PalletTown_ProfessorOaksLab_EventScript_PostRivalBattle
	end

PalletTown_ProfessorOaksLab_Text_RivalVictory::
    .string "{RIVAL}: Sí!\n"
    .string "Sóc bo o què?$"

PalletTown_ProfessorOaksLab_EventScript_RivalBattleWon::
	addvar VAR_RIVAL_WINRATE, 1
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGoToughenMyMon, MSGBOX_DEFAULT
	goto PalletTown_ProfessorOaksLab_EventScript_PostRivalBattle
	end

PalletTown_ProfessorOaksLab_Text_RivalGoToughenMyMon::
    .string "{RIVAL}: Molt bé! Faré combatre\n"
    .string "el meu Pokémon per enfortir-lo!\p"
    .string "{PLAYER}! Avi!\n"
    .string "Ja ens veurem!$"

PalletTown_ProfessorOaksLab_EventScript_PostRivalBattle::
	closemessage
	call_if_eq VAR_TEMP_1, 1, PalletTown_ProfessorOaksLab_EventScript_RivalLeavesAfterBattle1
	call_if_eq VAR_TEMP_1, 2, PalletTown_ProfessorOaksLab_EventScript_RivalLeavesAfterBattle2
	call_if_eq VAR_TEMP_1, 3, PalletTown_ProfessorOaksLab_EventScript_RivalLeavesAfterBattle3
	playbgm MUS_RG_RIVAL_EXIT, 0
	waitmovement 2
	playse SE_EXIT
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_RIVAL_IN_LAB
	setvar VAR_ADVENTURE_BEGINS, 3
	fadedefaultbgm
	releaseall
	end

PalletTown_ProfessorOaksLab_EventScript_RivalApproach1::
	applymovement LOCALID_RIVAL, Movement_RivalApproach1
	return

PalletTown_ProfessorOaksLab_EventScript_RivalApproach2::
	applymovement LOCALID_RIVAL, Movement_RivalApproach2
	return

PalletTown_ProfessorOaksLab_EventScript_RivalApproach3::
	applymovement LOCALID_RIVAL, Movement_RivalApproach3
	return

Movement_RivalApproach1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

Movement_RivalApproach2:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	face_down
	step_end

Movement_RivalApproach3:
	walk_down
	walk_down
	walk_left
	walk_left
	face_down
	step_end

PalletTown_ProfessorOaksLab_EventScript_RivalLeavesAfterBattle1::
	applymovement LOCALID_RIVAL, Movement_RivalLeavesAfterBattle1
	return

PalletTown_ProfessorOaksLab_EventScript_RivalLeavesAfterBattle2::
	applymovement LOCALID_RIVAL, Movement_RivalLeavesAfterBattle2
	return

PalletTown_ProfessorOaksLab_EventScript_RivalLeavesAfterBattle3::
	applymovement LOCALID_RIVAL, Movement_RivalLeavesAfterBattle3
	return

Movement_RivalLeavesAfterBattle1:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Movement_RivalLeavesAfterBattle2:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

Movement_RivalLeavesAfterBattle3:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PalletTown_ProfessorOaksLab_EventScript_GetPokedexScene::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachOak
	waitmovement 0
	turnobject LOCALID_OAK, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_OAK, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_OAK, Common_Movement_Delay48
	waitmovement 1
	msgbox PalletTown_ProfessorOaksLab_Text_OakHaveSomethingForMe, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_TMHM
	message PalletTown_ProfessorOaksLab_Text_DeliveredOaksParcel
	waitmessage
	waitfanfare
	removeitem ITEM_OAKS_PARCEL, 1
	msgbox PalletTown_ProfessorOaksLab_Text_OakCustomBallIOrdered
	addobject LOCALID_RIVAL
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGramps, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement LOCALID_RIVAL, Movement_RivalReturnsToLab
	waitmovement 2
	fadedefaultbgm
	msgbox PalletTown_ProfessorOaksLab_Text_RivalWhatDidYouCallMeFor
	closemessage
	delay 30
	playse SE_PIN
	applymovement LOCALID_OAK, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_OAK, Common_Movement_Delay48
	waitmovement 1
	msgbox PalletTown_ProfessorOaksLab_Text_OakHaveRequestForYouTwo
	closemessage
	applymovement LOCALID_OAK, Movement_OakGoToPokedex1
	msgbox PalletTown_ProfessorOaksLab_Text_OakPokedexOnDesk
	closemessage
	delay 40
	msgbox PalletTown_ProfessorOaksLab_Text_OakTakeTheseWithYou
	closemessage
	applymovement LOCALID_OAK, Common_Movement_WalkInPlaceFasterUp
	waitmovement 1
	removeobject LOCALID_POKEDEX_L
	delay 10
	applymovement LOCALID_OAK, Movement_OakGoToPokedex2
	waitmovement 1
	applymovement LOCALID_OAK, Common_Movement_WalkInPlaceFasterUp
	waitmovement 1
	removeobject LOCALID_POKEDEX_R
	setflag FLAG_HIDE_POKEDEX_ON_TABLE
	delay 10
	applymovement LOCALID_OAK, Movement_OakReturnToPlayer
	waitmovement 1
	delay 10
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PalletTown_ProfessorOaksLab_Text_ReceivedPokedexFromOak
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	msgbox PalletTown_ProfessorOaksLab_Text_OakCatchMonsForDataTakeThese
	giveitem ITEM_POKE_BALL, 5
	@PalletTown_ProfessorOaksLab_Text_ReceivedFivePokeBalls 
	msgbox PalletTown_ProfessorOaksLab_Text_OakExplainCatching
	msgbox PalletTown_ProfessorOaksLab_Text_OakCompleteMonGuideWasMyDream
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLeaveItToMeGramps
	turnobject LOCALID_RIVAL, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox PalletTown_ProfessorOaksLab_Text_RivalTellSisNotToGiveYouNumber
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_RIVAL, Movement_RivalLeavesWithPokedex
	waitmovement 2
	playse SE_EXIT
	removeobject LOCALID_RIVAL
	fadedefaultbgm
	setflag FLAG_HIDE_OFFICER_JENNY_VIRIDIAN_CITY
	setvar VAR_OAK_LAB_STATE, 7
	setvar VAR_ADVENTURE_BEGINS, 6
	setvar VAR_ROUTE_22_RIVAL_STATE, 1
	release
	end

Movement_PlayerApproachOak:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_RivalReturnsToLab:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	face_up
	step_end

Movement_OakGoToPokedex1:
	walk_up
	walk_left
	walk_left
	face_up
	step_end

Movement_OakGoToPokedex2:
	walk_right
	face_up
	step_end

Movement_OakReturnToPlayer:
	walk_right
	walk_down
	step_end

Movement_RivalLeavesWithPokedex:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PalletTown_ProfessorOaksLab_Text_OakHaveSomethingForMe::
    .string "Oak: Oh, {PLAYER}!\n"
    .string "Com va el teu nou Pokémon?\p"
    .string "Bé, sembla que cada cop està més\n"
    .string "unit a tu.\p"
    .string "Deus tenir talent com a entrenador\n"
    .string "Pokémon.\p"
    .string "Què és això?\n"
    .string "Tens alguna cosa per mi?$"

PalletTown_ProfessorOaksLab_Text_DeliveredOaksParcel::
    .string "{PLAYER} ha lliurat el Paquet d'Oak.$"

PalletTown_ProfessorOaksLab_Text_OakCustomBallIOrdered::
    .string "Ah!\n"
    .string "És la Poké Ball personalitzada!\p"
    .string "L'havia encarregat.\n"
    .string "Gràcies!$"

PalletTown_ProfessorOaksLab_Text_RivalGramps::
    .string "{RIVAL}: Avi!$"

PalletTown_ProfessorOaksLab_Text_RivalWhatDidYouCallMeFor::
    .string "{RIVAL}: Quasi me n'oblido!\n"
    .string "Per què m'has fet venir?$"

PalletTown_ProfessorOaksLab_Text_OakHaveRequestForYouTwo::
    .string "Oak: Ah, és clar!\n"
    .string "Tinc una petició per a tots dos.$"

PalletTown_ProfessorOaksLab_Text_OakPokedexOnDesk::
    .string "A l'escriptori hi ha el meu invent,\n"
    .string "el Pokédex!\p"
    .string "Registra automàticament dades dels\n"
    .string "Pokémon que has vist o capturat.\p"
    .string "És una enciclopèdia d'alta tecnologia!$"

PalletTown_ProfessorOaksLab_Text_OakTakeTheseWithYou::
    .string "Oak: {PLAYER} i {RIVAL}.\n"
    .string "Emporteu-vos-els.$"

PalletTown_ProfessorOaksLab_Text_ReceivedPokedexFromOak::
    .string "{PLAYER} ha rebut el Pokédex\n"
    .string "del Professor Oak!$"

PalletTown_ProfessorOaksLab_Text_OakCatchMonsForDataTakeThese::
    .string "Oak: No pots obtenir dades detallades\n"
    .string "dels Pokémon només veient-los.\p"
    .string "Els has de capturar per obtenir\n"
    .string "les dades completes.\p"
    .string "Així que aquí tens uns estris per\n"
    .string "capturar Pokémon salvatges.$"

PalletTown_ProfessorOaksLab_Text_ReceivedFivePokeBalls::
    .string "{PLAYER} ha rebut cinc Poké Balls.$"

PalletTown_ProfessorOaksLab_Text_OakExplainCatching::
    .string "Quan apareix un Pokémon salvatge,\n"
    .string "és una presa legítima.\p"
    .string "Només has de llançar-li una Poké Ball\n"
    .string "i provar de capturar-lo!\p"
    .string "Però això no sempre funciona.\p"
    .string "Un Pokémon sa pot escapar.\n"
    .string "Cal tenir sort!$"

PalletTown_ProfessorOaksLab_Text_OakCompleteMonGuideWasMyDream::
    .string "Fer una guia completa de tots\n"
    .string "els Pokémon del món…\p"
    .string "Aquest era el meu somni!\p"
    .string "Però sóc massa gran.\n"
    .string "No puc acabar la feina.\p"
    .string "Per això vull que vosaltres dos\n"
    .string "compliu el meu somni.\p"
    .string "Aneu-hi, tots dos.\p"
    .string "Això és una gran empresa en la\n"
    .string "història dels Pokémon!$"

PalletTown_ProfessorOaksLab_Text_RivalLeaveItToMeGramps::
    .string "{RIVAL}: Molt bé, avi!\n"
    .string "Deixa-m'ho tot a mi!$"

PalletTown_ProfessorOaksLab_Text_RivalTellSisNotToGiveYouNumber::
    .string "{PLAYER}, em sap greu dir-ho, però\n"
    .string "no ets necessari per a això.\p"
    .string "D'aquí endavant vas sol, així que\n"
    .string "no et molestis a trucar-me!\p"
    .string "I no intentis aconseguir el meu número\n"
    .string "de la meva germana, tampoc.\p"
    .string "Li diré que no te'l doni,\n"
    .string "{PLAYER}! Ha, ha, ha!$"

PalletTown_ProfessorOaksLab_EventScript_Rival::
	goto_if_eq VAR_OAK_LAB_STATE, 0, PalletTown_ProfessorOaksLab_EventScript_RivalWaiting
	goto_if_eq VAR_OAK_LAB_STATE, 2, PalletTown_ProfessorOaksLab_EventScript_RivalNotGreedy
	goto_if_eq VAR_OAK_LAB_STATE, 3, PalletTown_ProfessorOaksLab_EventScript_RivalMyMonLooksTough
	end

PalletTown_ProfessorOaksLab_EventScript_RivalWaiting::
	lock
	faceplayer
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGrampsIsntAround, MSGBOX_DEFAULT
	release
	end

PalletTown_ProfessorOaksLab_Text_RivalGrampsIsntAround::
    .string "{RIVAL}: Què, només ets {PLAYER}?\n"
    .string "L'avi no hi és.$"

PalletTown_ProfessorOaksLab_EventScript_RivalNotGreedy::
	lock
	faceplayer
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGoChoosePlayer, MSGBOX_DEFAULT
	release
	end 

PalletTown_ProfessorOaksLab_Text_RivalGoChoosePlayer:
    .string "{RIVAL}: Bah, jo no necessito ser\n"
    .string "cobdiciós com tu. Jo sóc madur!\p"
    .string "Vinga, queda-te'l, {PLAYER}!$"

PalletTown_ProfessorOaksLab_EventScript_RivalMyMonLooksTough::
	lock
	faceplayer
	msgbox PalletTown_ProfessorOaksLab_Text_RivalMyMonLooksTougher, MSGBOX_DEFAULT
	release
	end 

PalletTown_ProfessorOaksLab_Text_RivalMyMonLooksTougher::
    .string "{RIVAL}: El meu Pokémon sembla molt\n"
    .string "més fort que el teu, {PLAYER}.$"

PalletTown_ProfessorOaksLab_EventScript_Computer::
	msgbox PalletTown_ProfessorOaksLab_Text_EmailMessage, MSGBOX_SIGN
	end

PalletTown_ProfessorOaksLab_Text_EmailMessage::
    .string "Aquí hi ha un correu electrònic.\p"
    .string "…\p"
    .string "Per fi!\n"
    .string "Els millors entrenadors de la\l"
    .string "Lliga Pokémon estan a punt per\l"
    .string "enfrontar-se a qui vulgui!\p"
    .string "Porta els teus millors Pokémon i mira\n"
    .string "quin nivell tens com a entrenador!\p"
    .string "Seu de la Lliga Pokémon\n"
    .string "Altiplà Indigo\p"
    .string "Prof. Oak, vingui a veure'ns!\n"
    .string "…$"

PalletTown_ProfessorOaksLab_EventScript_LeftSign::
	msgbox PalletTown_ProfessorOaksLab_Text_PressStartToOpenMenu, MSGBOX_SIGN
	end

PalletTown_ProfessorOaksLab_Text_PressStartToOpenMenu::
    .string "Prem START per obrir el MENÚ!\p"
    .string "L'opció DESAR és al MENÚ.\n"
    .string "Fes-la servir sovint.$"

PalletTown_ProfessorOaksLab_EventScript_RightSign::
	msgbox PalletTown_ProfessorOaksLab_Text_AllMonTypesHaveStrongAndWeakPoints
	releaseall
	end

PalletTown_ProfessorOaksLab_Text_AllMonTypesHaveStrongAndWeakPoints::
    .string "Tots els tipus de Pokémon tenen punts\n"
    .string "forts i febles contra els altres.$"

PalletTown_ProfessorOaksLab_EventScript_Aide1::
	lock
	faceplayer
	msgbox PalletTown_ProfessorOaksLab_Text_StudyAsOaksAide
	release
	end

PalletTown_ProfessorOaksLab_Text_StudyAsOaksAide::
    .string "Estudio els Pokémon com a ajudant\n"
    .string "del Prof. Oak.$"

PalletTown_ProfessorOaksLab_EventScript_Aide2::
	lock
	faceplayer
	goto_if_set FLAG_REGISTERED_AIDE, PalletTown_ProfessorOaksLab_EventScript_JealousAide
	msgbox PalletTown_ProfessorOaksLab_Text_CedarRunsErrands
	release
	end

PalletTown_ProfessorOaksLab_Text_CedarRunsErrands::
    .string "La Cedar és la nova ajudant del lab,\n"
    .string "així que sempre està fent encàrrecs.$"

PalletTown_ProfessorOaksLab_EventScript_JealousAide::
	msgbox PalletTown_ProfessorOaksLab_Text_Jealous
	release
	end

PalletTown_ProfessorOaksLab_Text_Jealous::
    .string "Si he de ser sincer, la feina de lab\n"
    .string "pot ser una mica avorrida.\p"
    .string "Al principi me'n reia, però ara\n"
    .string "tinc una mica d'enveja que la Cedar\l"
    .string "hagi pogut viatjar tant!$"

PalletTown_ProfessorOaksLab_EventScript_Cedar::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_ALL_CHARMS, PalletTown_ProfessorOaksLab_EventScript_CedarAllItems
	goto_if_set FLAG_RECEIVED_EXP_SHARE, PalletTown_ProfessorOaksLab_EventScript_CedarPostgame
	msgbox PalletTown_ProfessorOaksLab_Text_JustJoined
	setflag FLAG_MET_CEDAR
	release
	end

PalletTown_ProfessorOaksLab_Text_JustJoined::
    .string "Cedar: Hola. Encantada de conèixer-te!\n"
    .string "Fa poc que m'he incorporat a l'equip\l"
    .string "del Professor Oak.\p"
    .string "Estic il·lusionada de treballar amb tots.$"

PalletTown_ProfessorOaksLab_EventScript_CedarPostgame::
	msgbox PalletTown_ProfessorOaksLab_Text_CedarHiPlayer, MSGBOX_DEFAULT
	goto_if_unset FLAG_RECEIVED_CATCHING_CHARM, PalletTown_ProfessorOaksLab_EventScript_GetCatchingCharm
	goto_if_unset FLAG_RECEIVED_OVAL_CHARM, PalletTown_ProfessorOaksLab_EventScript_GetOvalCharm
PalletTown_ProfessorOaksLab_EventScript_CedarCheckNext::
	goto_if_unset FLAG_RECEIVED_SHINY_CHARM, PalletTown_ProfessorOaksLab_EventScript_GetShinyCharm
PalletTown_ProfessorOaksLab_EventScript_CedarMaybeMoreItems::
	msgbox PalletTown_ProfessorOaksLab_Text_MaybeMoreItems, MSGBOX_DEFAULT
	release
	end

PalletTown_ProfessorOaksLab_EventScript_GetCatchingCharm::
	goto_if_unset FLAG_SYS_GAME_CLEAR, PalletTown_ProfessorOaksLab_EventScript_CedarMaybeMoreItems
	msgbox PalletTown_ProfessorOaksLab_Text_CatchingCharmReward
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PalletTown_ProfessorOaksLab_Text_ReceivedCatchingCharm
	waitmessage
	waitfanfare
	setflag FLAG_RECEIVED_CATCHING_CHARM
	additem ITEM_CATCHING_CHARM, 1
	call_if_unset FLAG_RECEIVED_ALL_CHARMS, Cedar_CheckCharms
	release
	end

PalletTown_ProfessorOaksLab_Text_CatchingCharmReward::
	.string "Vaja! Has derrotat l'Alt Comandament?\n"
	.string "Això és tot un èxit!\p"
	.string "Saps què? Encara hi ha més Pokémon\n"
	.string "per veure per aquí fora.\p"
	.string "Això t'ajudarà a completar el Pokédex!$"

PalletTown_ProfessorOaksLab_Text_ReceivedCatchingCharm::
	.string "{PLAYER} ha guanyat l'Amulet Captura!"

PalletTown_ProfessorOaksLab_EventScript_GetOvalCharm::
	goto_if_unset FLAG_CLEARED_SECRET_BATTLE, PalletTown_ProfessorOaksLab_EventScript_CedarCheckNext
	msgbox PalletTown_ProfessorOaksLab_Text_OvalCharmReward
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PalletTown_ProfessorOaksLab_Text_ReceivedOvalCharm
	waitmessage
	waitfanfare
	setflag FLAG_RECEIVED_OVAL_CHARM
	additem ITEM_OVAL_CHARM, 1
	call_if_unset FLAG_RECEIVED_ALL_CHARMS, Cedar_CheckCharms
	release
	end

PalletTown_ProfessorOaksLab_Text_OvalCharmReward::
	.string "Vaja! Has derrotat el Professor Oak?\n"
	.string "Això és tot un èxit!\p"
	.string "Criar Pokémon és igual d'important\n"
	.string "que combatre, saps?\p"
	.string "Això t'ajudarà a criar nous Pokémon!$"

PalletTown_ProfessorOaksLab_Text_ReceivedOvalCharm::
	.string "{PLAYER} ha guanyat l'Amulet Oval!"

PalletTown_ProfessorOaksLab_EventScript_GetShinyCharm::
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, FALSE, PalletTown_ProfessorOaksLab_EventScript_CedarMaybeMoreItems
	msgbox PalletTown_ProfessorOaksLab_Text_ShinyCharmReward
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PalletTown_ProfessorOaksLab_Text_ReceivedShinyCharm
	waitmessage
	waitfanfare
	setflag FLAG_RECEIVED_SHINY_CHARM
	additem ITEM_SHINY_CHARM, 1
	call_if_unset FLAG_RECEIVED_ALL_CHARMS, Cedar_CheckCharms
	release
	end

PalletTown_ProfessorOaksLab_Text_ShinyCharmReward::
	.string "Increïble! Els has capturat tots?\n"
	.string "Això és un èxit extraordinari!\p"
	.string "He sentit que els Pokémon tenen\n"
	.string "variants rares.\p"
	.string "Però jo no n'he vist mai cap...\p"
	.string "Això potser t'ajudarà a trobar-ne!$"

PalletTown_ProfessorOaksLab_Text_ReceivedShinyCharm::
	.string "{PLAYER} ha guanyat l'Amulet Lluent!"

Cedar_CheckCharms::
	goto_if_unset FLAG_RECEIVED_CATCHING_CHARM, Common_EventScript_Return
	goto_if_unset FLAG_RECEIVED_OVAL_CHARM, Common_EventScript_Return
	goto_if_unset FLAG_RECEIVED_SHINY_CHARM, Common_EventScript_Return
	setflag FLAG_RECEIVED_ALL_CHARMS
	return

PalletTown_ProfessorOaksLab_EventScript_CedarAllItems::
	msgbox PalletTown_ProfessorOaksLab_Text_WhatAJourney
	release
	end

PalletTown_ProfessorOaksLab_Text_CedarHiPlayer:
	.string "Cedar: Hola, {PLAYER}!\n"
	.string "Véns a veure el professor?\p"
	.string "Oh? Has vingut a veure'm a mi?$"

PalletTown_ProfessorOaksLab_Text_MaybeMoreItems::
	.string "Mmm, ara mateix no tinc cap objecte\n"
	.string "nou per donar-te.\p"
	.string "Però m'encantaria continuar sentint\n"
	.string "les teves aventures!\p"
	.string "Si tens algun bon èxit per\n"
	.string "explicar-me, podria convèncer\l"
	.string "el Prof. Oak que et doni alguna cosa bona!$"

PalletTown_ProfessorOaksLab_Text_WhatAJourney::
	.string "Cedar: Oh, {PLAYER}!\n"
	.string "Que bé veure't.\p"
	.string "Aquesta vegada no tinc cap objecte\n"
	.string "nou per tu, però. Ha!\p"
	.string "Saps? Quan vaig entrar al Laboratori\n"
	.string "del Prof. Oak, no m'agradava haver de\l"
	.string "passar tant de temps viatjant fora!\p"
	.string "Però seguir el teu viatge també ha\n"
	.string "estat una aventura per mi!\p"
	.string "He vist molt de Kanto i he entès\n"
	.string "com deu ser la vida d'un entrenador.\p"
	.string "Ara entenc per què el Prof. Oak em va\n"
	.string "encarregar aquella feina.\p"
	.string "Així que gràcies per l'aventura!$"

PalletTown_ProfessorOaksLab_EventScript_Pokedex::
	msgbox PalletTown_ProfessorOaksLab_Text_BlankEncyclopedia, MSGBOX_NPC
	end

PalletTown_ProfessorOaksLab_Text_BlankEncyclopedia::
    .string "És com una enciclopèdia, però les\n"
    .string "pàgines estan en blanc.$"

PalletTown_ProfessorOaksLab_EventScript_LastPokeBall::
	msgbox PalletTown_ProfessorOaksLab_Text_OaksLastMon, MSGBOX_DEFAULT
	release
	end

PalletTown_ProfessorOaksLab_Text_OaksLastMon::
    .string "És l'últim Pokémon del Prof. Oak.$"

PalletTown_ProfessorOaksLab_EventScript_ProfOak::
	lock
	faceplayer
	goto_if_eq VAR_OAK_LAB_STATE, 2, PalletTown_ProfessorOaksLab_EventScript_GoTakePokeball
	goto_if_eq VAR_OAK_LAB_STATE, 3, PalletTown_ProfessorOaksLab_EventScript_OakCanReachNextTownWithMon
	goto_if_le VAR_OAK_LAB_STATE, 5, PalletTown_ProfessorOaksLab_EventScript_OakBattleMonForItToGrow
	goto_if_eq VAR_OAK_LAB_STATE, 7, PalletTown_ProfessorOaksLab_EventScript_OakMonsAroundWorldWait
	goto_if_unset FLAG_REGISTERED_PROF_OAK, EventScript_RegisterProfOak
	goto ProfOak_EventScript_AskRatePokedex
	end

PalletTown_ProfessorOaksLab_EventScript_GoTakePokeball::
	msgbox PalletTown_ProfessorOaksLab_Text_TakeMyPokemon, MSGBOX_DEFAULT
	turnobject LOCALID_OAK, DIR_SOUTH
	release
	end

PalletTown_ProfessorOaksLab_Text_TakeMyPokemon::
    .string "Oak: Molt bé, {PLAYER}.\p"
    .string "Dins d'aquella Pokéball hi ha\n"
    .string "un dels meus Pokémon.\p"
    .string "Cuida-me'l bé, si us plau!$"

PalletTown_ProfessorOaksLab_EventScript_OakCanReachNextTownWithMon::
	msgbox PalletTown_ProfessorOaksLab_Text_OakCanReachNextTownWithMon, MSGBOX_DEFAULT
	turnobject LOCALID_OAK, DIR_SOUTH
	release
	end

PalletTown_ProfessorOaksLab_Text_OakCanReachNextTownWithMon::
    .string "Oak: Si apareix un Pokémon salvatge,\n"
    .string "el teu Pokémon pot combatre-hi.\p"
    .string "Amb ell al teu costat, hauries de\n"
    .string "poder arribar al poble següent.$"

PalletTown_ProfessorOaksLab_EventScript_OakBattleMonForItToGrow::
	msgbox PalletTown_ProfessorOaksLab_Text_OakBattleMonForItToGrow, MSGBOX_DEFAULT
	turnobject LOCALID_OAK, DIR_SOUTH
	release
	end

PalletTown_ProfessorOaksLab_Text_OakBattleMonForItToGrow::
    .string "Oak: {PLAYER}, cria el teu jove\n"
    .string "Pokémon fent-lo combatre.\p"
    .string "Ha de combatre per créixer.$"

PalletTown_ProfessorOaksLab_EventScript_OakMonsAroundWorldWait::
	msgbox PalletTown_ProfessorOaksLab_Text_OakMonsAroundWorldWait, MSGBOX_DEFAULT
	turnobject LOCALID_OAK, DIR_SOUTH
	release
	end

PalletTown_ProfessorOaksLab_Text_OakMonsAroundWorldWait::
    .string "Els Pokémon de tot el món t'esperen,\n"
    .string "{PLAYER}!$"

EventScript_RegisterProfOak::
	msgbox MatchCall_Text_OakRegisterCall, MSGBOX_DEFAULT
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
	end

ProfOak_EventScript_AskRatePokedex::
	msgbox gOakDexRatingText_GoodToSeeYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ProfOak_EventScript_DeclineRating
	call ProfOak_EventScript_RatePokedex
	release
	end

ProfOak_EventScript_DeclineRating::
	msgbox gOakDexRatingText_Cancel, MSGBOX_DEFAULT
	release
	end

ProfOak_EventScript_ShowRatingMessage::
	copyvar VAR_0x8004, VAR_0x8009
	special ShowPokedexRatingMessage
	waitmessage
	waitbuttonpress
	return

ProfOak_EventScript_RatePokedex::
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_0x8008  @ Num Hoenn seen
	buffernumberstring STR_VAR_2, VAR_0x8009  @ Num Hoenn caught
	msgbox gOakDexRatingText_SoYouveSeenAndCaught, MSGBOX_DEFAULT
	call ProfOak_EventScript_ShowRatingMessage
	return


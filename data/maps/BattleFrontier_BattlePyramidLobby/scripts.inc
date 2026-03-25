.set LOCALID_ATTENDANT, 1
.set LOCALID_HINT_GIVER, 2

BattleFrontier_BattlePyramidLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
BattleFrontier_BattlePyramidLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth:
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving::
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	closemessage
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing::
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints::
	special DoBattlePyramidMonsHaveHeldItem
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_setprize
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge::
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge

BattleFrontier_BattlePyramidLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_0, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pyramid_init
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	pyramid_seedfloor
	pyramid_settrainers
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_HintGiver::
	lockall
	applymovement LOCALID_HINT_GIVER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint::
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	return

@ Shouldnt occur
BattleFrontier_BattlePyramidLobby_EventScript_NoHint::
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment::
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPoison::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBurn::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintIce::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintRock::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFighting::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWeather::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBug::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintDark::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWater::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintGhost::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintSteel::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintNormal::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag

BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag::
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside:
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag, MSGBOX_DEFAULT
	return

@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep::
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag::
	special ChooseItemsToTossFromPyramidBag
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty::
	special BattlePyramidChooseMonHeldItems
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems::
	special DoBattlePyramidMonsHaveHeldItem
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems
	return

BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_Woman::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid:
	.string "On el coratge dels Entrenadors\n"

	.string "es posa a prova!\p"

	.string "Benvingut a la Piràmide de Combat!\p"

	.string "Sóc el teu guia per a\n"

	.string "la Cerca de Combat.$"


BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge:
	.string "Tens el coratge per embarcar-te\n"

	.string "en el desafiament de la Cerca?$"


BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge:
	.string "Esperem el teu desafiament futur!$"


BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid:
	.string "La Cerca de Combat és un event\n"

	.string "on has d'explorar la Piràmide\l"

	.string "i intentar arribar al cim.\p"

	.string "A la Piràmide hi ha set pisos de\n"

	.string "laberints, plens no només\l"

	.string "d'Entrenadors sinó de Pokémon salvatges.\p"

	.string "Has d'entrar amb tres Pokémon,\n"

	.string "cap d'ells portant cap objecte.\p"

	.string "Durant l'ascens, se't donarà\n"

	.string "una Bossa de Combat per objectes.\p"

	.string "Si fracasses, qualsevol objecte\n"

	.string "de la Bossa de Combat desapareix.\p"

	.string "Si vols interrompre el desafiament,\n"

	.string "has de seleccionar “Descans”\l"

	.string "i desar la partida.\p"

	.string "Si no deses abans d'interrompre,\n"

	.string "seràs desqualificat.$"


BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode:
	.string "La Piràmide ofereix dos cursos,\n"

	.string "Nivell 50 i Nivell Obert.\l"

	.string "A quin entraràs?$"


BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons:
	.string "Molt bé. Tria els tres Pokémon\n"

	.string "que vols que t'acompanyin.$"


BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Un petit problema, aventurer!\p"

	.string "Sembla que no tens els tres\n"

	.string "Pokémon qualificats pel desafiament.\p"

	.string "Recorda també treure tots els\n"

	.string "objectes dels teus Pokémon.\p"

	.string "Els Ous{STR_VAR_1} no són elegibles.\p"

	.string "Quan estiguis a punt, parla\n"

	.string "amb mi.$"


BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50:
	.string "Un petit problema, aventurer!\p"

	.string "Sembla que no tens els tres\n"

	.string "Pokémon qualificats pel desafiament.\p"

	.string "Els tres Pokémon han de ser\n"

	.string "diferents i cap per sobre del Nv. 50.\p"

	.string "Recorda també treure tots els\n"

	.string "objectes dels teus Pokémon.\p"

	.string "Els Ous{STR_VAR_1} no són elegibles.\p"

	.string "Quan estiguis a punt, parla\n"

	.string "amb mi.$"


BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge:
	.string "Abans d'entrar a la Piràmide de\n"

	.string "Combat, cal desar. D'acord?$"


BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid:
	.string "Molt bé. Ara t'acompanyaré a\n"

	.string "la Piràmide de Combat.$"


BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping:
	.string "Guardarem la teva Bossa per\n"

	.string "seguretat, {PLAYER}, mentre explores.$"


BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag:
	.string "A canvi, pren aquesta Bossa de\n"

	.string "Combat, la que vas usar abans.$"


BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag:
	.string "A canvi, pren aquesta\n"

	.string "Bossa de Combat.$"


BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag:
	.string "{PLAYER} ha canviat la Bossa per\n"

	.string "la Bossa de Combat.$"


BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel:
	.string "Quan trepitgis aquest panell,\n"

	.string "seràs transportat a un pis\l"

	.string "superior de la Piràmide.\p"

	.string "Espero que la teva cerca\n"

	.string "vagi bé!$"


BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag:
	.string "Un greu problema, explorador!\p"

	.string "No vas desar abans d'acabar\n"

	.string "el desafiament l'última vegada.\p"

	.string "Per tant, el teu desafiament ha\n"

	.string "estat desqualificat, ho sento.\p"

	.string "Aquí tens la Bossa que\n"

	.string "guardàvem per a tu.\p"

	.string "{PLAYER} ha recuperat la Bossa.$"


BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid:
	.string "Quin goig veure't de tornada!\p"

	.string "Has conquerit la Piràmide!\n"

	.string "Fantàstic!$"


BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake:
	.string "Ah, un petit problema.\p"

	.string "Almenys un Pokémon porta\n"

	.string "un objecte.\p"

	.string "Ho sento, els objectes obtinguts\n"

	.string "a la Piràmide no es poden endur.$"


BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag:
	.string "Tots els objectes dels teus Pokémon\n"

	.string "es mouran a la Bossa de Combat, {PLAYER}.$"


BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep:
	.string "La Bossa de Combat no pot guardar\n"

	.string "tots els objectes, ho sento.\p"

	.string "Tria els objectes que vols guardar\n"

	.string "a la Bossa i amb els teus Pokémon.$"


BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem:
	.string "Almenys un Pokémon encara\n"

	.string "porta un objecte.$"


BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep:
	.string "Tria els objectes que vols guardar\n"

	.string "a la Bossa i amb els teus Pokémon.$"


@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld:
	.string "{PLAYER} ha tornat tot el que\n"

	.string "portaven els Pokémon.$"


BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept:
	.string "La Bossa de Combat que has usat\n"

	.string "es guardarà pel pròxim desafiament.\p"

	.string "{PLAYER} ha lliurat la Bossa de Combat\n"

	.string "per recuperar la Bossa.$"


BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait:
	.string "He de registrar els resultats.\n"

	.string "Si us plau, espera.$"


@ Unused
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis:
	.string "Com a record per conquerir\n"

	.string "la Piràmide de Combat, pren això.$"


@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} ha rebut el premi\n"

	.string "{STR_VAR_1}.$"


@ Unused
BattleFrontier_BattlePyramidLobby_Text_BagIsFull:
	.string "…Ah…\n"

	.string "La teva Bossa sembla plena.\p"

	.string "Torna quan hagis organitzat\n"

	.string "el contingut de la Bossa.$"


BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag:
	.string "Quina llàstima…\p"

	.string "Aquí tens la Bossa que\n"

	.string "guardàvem per a tu.\p"

	.string "{PLAYER} ha recuperat la Bossa.$"


BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge:
	.string "Esperem amb ganes el teu\n"

	.string "pròxim desafiament!$"


@ Unused
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize:
	.string "Esperàvem la teva\n"

	.string "arribada!\p"

	.string "Aquí tens el premi per conquerir\n"

	.string "la Piràmide.$"


BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait:
	.string "Benvingut…\p"

	.string "Estaré encantat de dir-te quines\n"

	.string "desgràcies t'esperen a la Piràmide…$"


BattleFrontier_BattlePyramidLobby_Text_Aah:
	.string "… … … … … …\n"

	.string "… … … … … …\p"

	.string "… … … … … …\n"

	.string "Aah!$"


BattleFrontier_BattlePyramidLobby_Text_HintParalysis:
	.string "Veig una pluja d'espurnes…\p"

	.string "…I dins, veig els teus Pokémon\n"

	.string "lluitant amb la paràlisi…$"


BattleFrontier_BattlePyramidLobby_Text_HintPoison:
	.string "Veig verí…\p"

	.string "…I veig els teus Pokémon patint\n"

	.string "pels efectes del verí…$"


BattleFrontier_BattlePyramidLobby_Text_HintBurn:
	.string "Veig flames vermelles brillants…\p"

	.string "…I veig els teus Pokémon patint\n"

	.string "per cremades…$"


BattleFrontier_BattlePyramidLobby_Text_HintPPWaste:
	.string "Sento la tremenda pressió d'una\n"

	.string "ira no corresposta…\p"

	.string "És una maledicció…\p"

	.string "…I veig els teus Pokémon sense\n"

	.string "Punts de Poder i havent d'usar\l"

	.string "Forcejada…$"


BattleFrontier_BattlePyramidLobby_Text_HintLevitate:
	.string "Veig Pokémon flotant enlaire…\p"

	.string "…I veig els teus Pokémon frustrats\n"

	.string "per moviments Terra inútils…$"


BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility:
	.string "Sento una energia terrible que\n"

	.string "sorgeix del terra…\p"

	.string "…I veig els teus Pokémon incapaços\n"

	.string "d'escapar-se de les seves garres…$"


BattleFrontier_BattlePyramidLobby_Text_HintIce:
	.string "Veig Pokémon de tipus Gel…\p"

	.string "…I veig els teus Pokémon lluitant\n"

	.string "contra els efectes del gel…$"


BattleFrontier_BattlePyramidLobby_Text_HintExplosion:
	.string "Veig moviments que posen en perill\n"

	.string "l'usuari…\p"

	.string "…I veig els teus Pokémon caient\n"

	.string "davant d'ells…$"


BattleFrontier_BattlePyramidLobby_Text_HintPsychic:
	.string "Veig Pokémon de tipus Psíquic…\p"

	.string "…I veig els teus Pokémon turmentats\n"

	.string "per moviments Psíquics…$"


BattleFrontier_BattlePyramidLobby_Text_HintRock:
	.string "Veig Pokémon de tipus Roca…\p"

	.string "…I veig els teus Pokémon patint\n"

	.string "per moviments de Roca…$"


BattleFrontier_BattlePyramidLobby_Text_HintFighting:
	.string "Veig Pokémon de tipus Lluita…\p"

	.string "…I veig els teus Pokémon colpejats\n"

	.string "per moviments de Lluita…$"


BattleFrontier_BattlePyramidLobby_Text_HintWeather:
	.string "Dansa Pluja… Dia Assolellat…\n"

	.string "Tempesta de Sorra… Calamarsa…\p"

	.string "Veig Pokémon que es tornen més\n"

	.string "forts amb el temps…\p"

	.string "…I veig els teus Pokémon confusos\n"

	.string "per diferents tipus de moviments…$"


BattleFrontier_BattlePyramidLobby_Text_HintBug:
	.string "Veig Pokémon de tipus Insecte…\p"

	.string "…I veig els teus Pokémon patint\n"

	.string "per diferents tipus d'atacs…$"


BattleFrontier_BattlePyramidLobby_Text_HintDark:
	.string "Veig Pokémon de tipus Fosc…\p"

	.string "…I veig els teus Pokémon patint\n"

	.string "per moviments de tipus Fosc…$"


BattleFrontier_BattlePyramidLobby_Text_HintWater:
	.string "Veig Pokémon de tipus Aigua…\p"

	.string "…I veig els teus Pokémon patint\n"

	.string "per moviments de tipus Aigua…$"


BattleFrontier_BattlePyramidLobby_Text_HintGhost:
	.string "Veig Pokémon de tipus Fantasma…\p"

	.string "…I veig els teus Pokémon patint\n"

	.string "per moviments de tipus Fantasma…$"


BattleFrontier_BattlePyramidLobby_Text_HintSteel:
	.string "Veig Pokémon de tipus Acer…\p"

	.string "…I veig els teus Pokémon patint\n"

	.string "per moviments enormement potents…$"


BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon:
	.string "Veig Pokémon voladors…\p"

	.string "…I veig els teus Pokémon patint\n"

	.string "per moviments enormement potents…$"


BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve:
	.string "Veig aquells que han evolucionat\n"

	.string "pel poder de les pedres…\p"

	.string "També sento foc, aigua\n"

	.string "i electricitat…\p"

	.string "…I veig els teus Pokémon patint\n"

	.string "per aquests tres poders…$"


BattleFrontier_BattlePyramidLobby_Text_HintNormal:
	.string "Veig Pokémon de tipus Normal…\p"

	.string "…I veig els teus Pokémon patint\n"

	.string "per moviments enormement potents…$"


BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot:
	.string "Que creguis les meves prediccions\n"

	.string "o no, és decisió teva…\p"

	.string "El futur es pot canviar sempre…\n"

	.string "Et desitjo un bon viatge…$"


BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning:
	.string "Ho sabies?\p"

	.string "Si corres ràpid, els Entrenadors\n"

	.string "et poden notar i venir a lluitar.\p"

	.string "Així que, si vols evitar Entrenadors,\n"

	.string "no els miris als ulls, i passa\l"

	.string "amb cautela i en silenci.$"


BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems:
	.string "Aaaaarrrrgh!\p"

	.string "Tenia un munt d'objectes, però els\n"

	.string "he perdut tots en perdre!\p"

	.string "Aaaaarrrrgh!$"


BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing:
	.string "Benvingut!\n"

	.string "Has fet l'impensable!\p"

	.string "Has derrotat el Rei de la Piràmide\n"

	.string "i has conquerit la Piràmide de Combat!$"


BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints:
	.string "Jove explorador!\n"

	.string "En reconeixement del teu coratge,\l"

	.string "et donem aquests Punts de Combat!$"


BattleFrontier_BattlePyramidLobby_Text_RulesAreListed:
	.string "Les regles de la Cerca estan llistades.$"


BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading:
	.string "Quina secció vols llegir?$"


BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules:
	.string "Quan conquereixes la Piràmide,\n"

	.string "els Pokémon salvatges que hi apareixen\l"

	.string "són reemplaçats per uns de diferents.\p"

	.string "Explora, observa i aprèn quins tipus\n"

	.string "de Pokémon salvatges pots trobar.$"


BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules:
	.string "Hi ha Entrenadors amagats dins\n"

	.string "la Piràmide.\p"

	.string "A cada pis, hi ha fins a\n"

	.string "vuit Entrenadors.\p"

	.string "Quan derrotes un Entrenador, rebràs\n"

	.string "una pista útil per a la teva aventura.$"


BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules:
	.string "Els laberints de la Piràmide canvien\n"

	.string "cada vegada que hi entres.\p"

	.string "Els laberints estan mal il·luminats.\n"

	.string "Has d'avançar amb precaució.\p"

	.string "La llum augmenta cada cop que\n"

	.string "derrotes un Pokémon o Entrenador.$"


BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules:
	.string "La Bossa de Combat fa de Bossa\n"

	.string "mentre ets a la Piràmide.\p"

	.string "Hi ha dues Bosses de Combat\n"

	.string "separades, una per al Nivell 50\l"

	.string "i una per al Nivell Obert.\p"

	.string "Cadascuna pot guardar fins a 99\n"

	.string "unitats de deu tipus d'objectes.\p"

	.string "El contingut de la Bossa de Combat\n"

	.string "es perd si fracasses a la cerca.$"


.set LOCALID_LILYCOVE_LADY, 4
.set LOCALID_LADYS_MON, 5

LilycoveCity_PokemonCenter_1F_EventScript_LilycoveLady::
	special Script_GetLilycoveLadyId
	switch VAR_RESULT
	case LILYCOVE_LADY_QUIZ, LilycoveCity_PokemonCenter_1F_EventScript_QuizLady
	case LILYCOVE_LADY_FAVOR, LilycoveCity_PokemonCenter_1F_EventScript_FavorLady
	case LILYCOVE_LADY_CONTEST, LilycoveCity_PokemonCenter_1F_EventScript_ContestLady
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheFavorLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetFavorLadyState
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_READY, LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyReady
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED, LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyCompleted
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE, LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyCompleted::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ThankYouForLastTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyReady::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_ObsessedWithThing, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasAnotherPlayerGivenFavorLadyItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_TellAboutPlayersItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_TellAboutPlayersItem::
	special BufferFavorLadyItemName
	special BufferFavorLadyPlayerName
	specialvar VAR_RESULT, DidFavorLadyLikeItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveBadThing
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveGreatThing
	end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveBadThing::
	msgbox LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeBadThing, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveGreatThing::
	msgbox LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeGreatThing, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_RequestItem::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WillYouShareThing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_AcceptFavor
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor::
	msgbox LilycoveCity_PokemonCenter_1F_Text_IsThatSoGoodbye, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AcceptFavor::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WhatWillYouGiveMe, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem::
	fadescreen FADE_TO_BLACK
	setvar VAR_RESULT, 0
	special Script_FavorLadyOpenBagMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChooseFavorItem
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_GiveFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChooseFavorItem::
	msgbox LilycoveCity_PokemonCenter_1F_Text_NotWillingToShare, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_GiveFavorItem::
	specialvar VAR_RESULT, Script_DoesFavorLadyLikeItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_DidntLikeFavorItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_CheckLovedItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_DidntLikeFavorItem::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllTryToCherishIt, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_CheckLovedItem::
	specialvar VAR_RESULT, IsFavorLadyThresholdMet
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_LikedFavorItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_LovedFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_LikedFavorItem::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_IWillCherishThis, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_LovedFavorItem::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_IWillTreasureThis, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize::
	setvar VAR_0x8004, 0
	specialvar VAR_0x8004, FavorLadyGetPrize
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllGiveYouThisInReturn, MSGBOX_DEFAULT
	giveitem VAR_0x8004
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_NoRoomForFavorPrize
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_ReceivedFavorPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_NoRoomForFavorPrize::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouDontHaveSpaceForIt, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ReceivedFavorPrize::
	special SetFavorLadyState_Complete
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_QuizLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheQuizLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetQuizLadyState
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_READY, LilycoveCity_PokemonCenter_1F_EventScript_HasQuiz
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED, LilycoveCity_PokemonCenter_1F_EventScript_CheckMadeQuiz
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE, LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_HasQuiz::
	specialvar VAR_RESULT, GetQuizAuthor
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_PLAYER, LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_OTHER_PLAYER, LilycoveCity_PokemonCenter_1F_EventScript_PlayerQuizReady
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_LADY, LilycoveCity_PokemonCenter_1F_EventScript_LadyQuizReady
	end

LilycoveCity_PokemonCenter_1F_EventScript_CheckMadeQuiz::
	specialvar VAR_RESULT, IsQuizLadyWaitingForChallenger
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingToTakeYourQuiz, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerQuizReady::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_LadyQuizReady::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz::
	setvar VAR_0x8004, 0
	msgbox LilycoveCity_PokemonCenter_1F_Text_TakeQuizChallenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_HowBoringBye, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz::
	special ClearQuizLadyPlayerAnswer
	goto_if_eq VAR_0x8004, 0, LilycoveCity_PokemonCenter_1F_EventScript_ShowQuestion
	goto_if_eq VAR_0x8004, EASY_CHAT_TYPE_QUIZ_ANSWER, LilycoveCity_PokemonCenter_1F_EventScript_GetAnswer

LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState::
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitQuiz
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_SubmitQuizResponse
	end

LilycoveCity_PokemonCenter_1F_EventScript_ShowQuestion::
	special QuizLadyShowQuizQuestion
	waitstate
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState
	end

LilycoveCity_PokemonCenter_1F_EventScript_GetAnswer::
	special QuizLadyGetPlayerAnswer
	waitstate
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YoureGoingToQuit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_QuitTakingQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_QuitTakingQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_TakeTheQuizAnotherTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_SubmitQuizResponse::
	special SetQuizLadyState_Complete
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitForAnswer, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsQuizAnswerCorrect
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_IncorrectResponse
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_CorrectResponse
	end

LilycoveCity_PokemonCenter_1F_EventScript_CorrectResponse::
	playse SE_SUCCESS
	delay 10
	playse SE_SUCCESS
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRight, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_IncorrectResponse::
	special BufferQuizCorrectAnswer
	special BufferQuizPrizeName
	playse SE_FAILURE
	delay 10
	playse SE_FAILURE
	msgbox LilycoveCity_PokemonCenter_1F_Text_WrongTheCorrectAnswerIs, MSGBOX_DEFAULT
	msgbox LilycoveCity_PokemonCenter_1F_Text_IGetToKeepPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
	end

@ VAR_RESULT is essentially ignored, both jumps are identical
LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize::
	specialvar VAR_RESULT, BufferQuizAuthorNameAndCheckIfLady
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_GivePrize1
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_GivePrize0
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize1::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_GivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize0::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_GivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize::
	setvar VAR_0x8005, 0
	special BufferQuizPrizeItem
	special SetQuizLadyState_Complete
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_NoSpaceForQuizPrize
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_NoSpaceForQuizPrize::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YourBagIsFilledUp, MSGBOX_DEFAULT
	special SetQuizLadyState_GivePrize
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_MakeYourOwnQuiz, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_MakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz::
	special QuizLadyPickNewQuestion
	msgbox LilycoveCity_PokemonCenter_1F_Text_MaybeNextTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_MakeQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_PickYourPrize, MSGBOX_DEFAULT
LilycoveCity_PokemonCenter_1F_EventScript_PickPrize::
	fadescreen FADE_TO_BLACK
	setvar VAR_RESULT, 0
	special Script_QuizLadyOpenBagMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChoosingPrize
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_WriteQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChoosingPrize::
	msgbox LilycoveCity_PokemonCenter_1F_Text_QuitChoosingPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_PickPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_WriteQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WriteYourQuiz, MSGBOX_DEFAULT
	special ClearQuizLadyQuestionAndAnswer
	special ClearQuizLadyPlayerAnswer
	setvar VAR_0x8004, EASY_CHAT_TYPE_QUIZ_QUESTION
LilycoveCity_PokemonCenter_1F_EventScript_WriteQuizQuestion::
	fadescreen FADE_TO_BLACK
	special QuizLadySetCustomQuestion
	waitstate
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitWritingQuizQuestion
	goto LilycoveCity_PokemonCenter_1F_EventScript_FinishMakingQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitWritingQuizQuestion::
	msgbox LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_WriteQuizQuestion
	end

LilycoveCity_PokemonCenter_1F_EventScript_FinishMakingQuiz::
	special QuizLadyTakePrizeForCustomQuiz
	special QuizLadyRecordCustomQuizData
	special QuizLadySetWaitingForChallenger
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllLookForAChallenger, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ContestLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheContestLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasPlayerGivenContestLadyPokeblock
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_NotGivenPokeblock
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock
	end

@ Redundant with above script, VAR_RESULT will always be FALSE here
LilycoveCity_PokemonCenter_1F_EventScript_NotGivenPokeblock::
	specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_AskForPokeblock
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ThankForPokeblock, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskForPokeblock::
	special Script_BufferContestLadyCategoryAndMonName
	msgbox LilycoveCity_PokemonCenter_1F_Text_MyFriendDisplaysQuality, MSGBOX_DEFAULT
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_NoPokeblockCase
	msgbox LilycoveCity_PokemonCenter_1F_Text_AskingForOnePokeblock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WhatACheapskate, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseForContestLady
	waitstate
	goto_if_eq VAR_RESULT, 0xFFFF, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitGivingPokeblock
	goto_if_ne VAR_RESULT, 0xFFFF, LilycoveCity_PokemonCenter_1F_EventScript_GivePokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitGivingPokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ICantHaveOnePokeblock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllUseYourPokeblock, MSGBOX_DEFAULT
	special SetContestLadyGivenPokeblock
	special GetContestLadyMonSpecies
	goto LilycoveCity_PokemonCenter_1F_EventScript_FeedPokeblock
	end

@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
LilycoveCity_PokemonCenter_1F_EventScript_FeedPokeblock::
	applymovement LOCALID_LILYCOVE_LADY, LilycoveCity_PokemonCenter_1F_Movement_LadyFaceMon
	waitmovement 0
	delay 60
	applymovement LOCALID_LADYS_MON, LilycoveCity_PokemonCenter_1F_Movement_MonFaceLady
	waitmovement 0
	delay 60
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	delay 120
	waitmoncry
	goto_if_eq VAR_0x8004, 1, LilycoveCity_PokemonCenter_1F_EventScript_MonEnjoyPokeblock
	goto LilycoveCity_PokemonCenter_1F_EventScript_FinishFeedPokeblock
	end

@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
LilycoveCity_PokemonCenter_1F_EventScript_MonEnjoyPokeblock::
	applymovement LOCALID_LADYS_MON, LilycoveCity_PokemonCenter_1F_Movement_MonJump
	waitmovement 0
	delay 60
LilycoveCity_PokemonCenter_1F_EventScript_FinishFeedPokeblock::
	applymovement LOCALID_LILYCOVE_LADY, LilycoveCity_PokemonCenter_1F_Movement_LadyFacePlayer
	waitmovement 0
	delay 60
	goto_if_eq VAR_0x8004, 0, LilycoveCity_PokemonCenter_1F_EventScript_MonDislikedPokeblock
	goto_if_eq VAR_0x8004, 1, LilycoveCity_PokemonCenter_1F_EventScript_MonLikedPokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_MonDislikedPokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_NoChangeThanks, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow
	end

LilycoveCity_PokemonCenter_1F_EventScript_MonLikedPokeblock::
	special Script_BufferContestLadyCategoryAndMonName
	msgbox LilycoveCity_PokemonCenter_1F_Text_ReallyImprovedThanks, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow
	end

LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow::
	specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_AirContestLadyShow
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AirContestLadyShow::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ReadyToEnterContests, MSGBOX_DEFAULT
	special PutLilycoveContestLadyShowOnTheAir
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_NoPokeblockCase::
	msgbox LilycoveCity_PokemonCenter_1F_Text_DontHaveAPokeblockCase, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_Movement_LadyFaceMon:
	face_right
	delay_8
	step_end

LilycoveCity_PokemonCenter_1F_Movement_MonFaceLady:
	face_left
	delay_8
	step_end

@ Unused
LilycoveCity_PokemonCenter_1F_Movement_MonFaceDown:
	face_down
	step_end

LilycoveCity_PokemonCenter_1F_Movement_LadyFacePlayer:
	face_player
	step_end

LilycoveCity_PokemonCenter_1F_Movement_MonJump:
	disable_jump_landing_ground_effect
	jump_in_place_left
	disable_jump_landing_ground_effect
	jump_in_place_left
	step_end

LilycoveCity_PokemonCenter_1F_EventScript_ContestLadyMon::
	specialvar VAR_RESULT, GetContestLadyCategory
	special Script_BufferContestLadyCategoryAndMonName
	special GetContestLadyMonSpecies
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_COOL, LilycoveCity_PokemonCenter_1F_EventScript_Zigzagoon
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_BEAUTY, LilycoveCity_PokemonCenter_1F_EventScript_Skitty
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_CUTE, LilycoveCity_PokemonCenter_1F_EventScript_Poochyena
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_SMART, LilycoveCity_PokemonCenter_1F_EventScript_Kecleon
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_TOUGH, LilycoveCity_PokemonCenter_1F_EventScript_Pikachu
	end

LilycoveCity_PokemonCenter_1F_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Poochyena::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Poochyena, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_Text_ImTheFavorLady:
	.string "Sóc la Senyora dels Favors…$"


LilycoveCity_PokemonCenter_1F_Text_ObsessedWithThing:
	.string "Últimament estic obsessionada\n"

	.string "amb les coses {STR_VAR_1}…$"


LilycoveCity_PokemonCenter_1F_Text_ThankYouForLastTime:
	.string "Oh…\n"

	.string "Gràcies per l'últim cop…$"


LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeBadThing:
	.string "Abans, crec que era {STR_VAR_3}…\p"

	.string "{STR_VAR_3} em va donar un {STR_VAR_2},\n"

	.string "dient que era {STR_VAR_1}.\p"

	.string "Però no era {STR_VAR_1}.\n"

	.string "Ni de bon tros.$"


LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeGreatThing:
	.string "Abans, {STR_VAR_3} em va donar un\n"

	.string "{STR_VAR_2} molt {STR_VAR_1}.\p"

	.string "Ara el guardo amb molt d'afecte.$"


LilycoveCity_PokemonCenter_1F_Text_WillYouShareThing:
	.string "Escolta, si tens alguna cosa\n"

	.string "que sigui {STR_VAR_1}, me la\l"

	.string "podries donar?$"


LilycoveCity_PokemonCenter_1F_Text_WhatWillYouGiveMe:
	.string "…De debò?\n"

	.string "Què em donaràs?$"


LilycoveCity_PokemonCenter_1F_Text_IsThatSoGoodbye:
	.string "Ah, sí?\n"

	.string "Doncs, adéu…$"


LilycoveCity_PokemonCenter_1F_Text_NotWillingToShare:
	.string "Oh…\n"

	.string "No vols compartir res?$"


LilycoveCity_PokemonCenter_1F_Text_IllTryToCherishIt:
	.string "Oh?\n"

	.string "Aquest {STR_VAR_2} és {STR_VAR_1}?\p"

	.string "…Ah, de veritat?\p"

	.string "Bé, igualment t'ho agraeixo.\n"

	.string "Intentaré estimar-lo…$"


LilycoveCity_PokemonCenter_1F_Text_IWillCherishThis:
	.string "Oh…\p"

	.string "Això és un {STR_VAR_2}\n"

	.string "força {STR_VAR_1}…\p"

	.string "No és bonic?\n"

	.string "És tan ideal…\p"

	.string "Gràcies…\n"

	.string "Ho guardaré amb molt d'afecte…$"


LilycoveCity_PokemonCenter_1F_Text_IWillTreasureThis:
	.string "…Oh, oh, oh…\p"

	.string "Això és increïble!\n"

	.string "Això sí que és {STR_VAR_1}!\p"

	.string "No sabia que un {STR_VAR_2}\n"

	.string "pogués ser tan {STR_VAR_1}!\p"

	.string "Gràcies!\p"

	.string "Ho guardaré com un tresor\n"

	.string "tota la vida!$"


LilycoveCity_PokemonCenter_1F_Text_IllGiveYouThisInReturn:
	.string "Et donaré aquest objecte meravellós\n"

	.string "a canvi del teu regal fabulós.\p"

	.string "Espero que el guardis amb afecte…$"


LilycoveCity_PokemonCenter_1F_Text_YouDontHaveSpaceForIt:
	.string "Oh, no el pots tenir si no tens\n"

	.string "espai per guardar-lo.\p"

	.string "Vine a veure'm quan tinguis\n"

	.string "la Motxilla ordenada…$"


LilycoveCity_PokemonCenter_1F_Text_ImTheQuizLady:
	.string "Sóc la Senyora dels Qüestionaris!\n"

	.string "M'encanten els qüestionaris!$"


LilycoveCity_PokemonCenter_1F_Text_WaitingToTakeYourQuiz:
	.string "Oh?\p"

	.string "Estic esperant que algú respongui\n"

	.string "el qüestionari que has creat.\p"

	.string "Podem parlar un altre cop, d'acord?$"


LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger:
	.string "Estic esperant que algú accepti\n"

	.string "el qüestionari de {STR_VAR_1}!$"


LilycoveCity_PokemonCenter_1F_Text_TakeQuizChallenge:
	.string "Si respons correctament, pots\n"

	.string "guanyar premis fabulosos!\p"

	.string "Vols acceptar el repte del\n"

	.string "qüestionari?$"


LilycoveCity_PokemonCenter_1F_Text_WaitForAnswer:
	.string "… … … … … …\n"

	.string "… … … … … …$"


LilycoveCity_PokemonCenter_1F_Text_HowBoringBye:
	.string "Oh, que avorrit!\n"

	.string "Adéu!$"


LilycoveCity_PokemonCenter_1F_Text_YoureGoingToQuit:
	.string "Ohhh!\n"

	.string "Deixaràs el qüestionari?$"


LilycoveCity_PokemonCenter_1F_Text_TakeTheQuizAnotherTime:
	.string "Accepta el repte del qüestionari\n"

	.string "un altre dia!$"


LilycoveCity_PokemonCenter_1F_Text_YouGotItRight:
	.string "Ets increïble! Has encertat!\n"

	.string "Ets molt llest/a!$"


LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize:
	.string "Felicitats!\n"

	.string "Has encertat el qüestionari!\p"

	.string "Has guanyat un premi ofert per\n"

	.string "{STR_VAR_1}!$"


@ Unused
LilycoveCity_PokemonCenter_1F_Text_XReceivedOneY:
	.string "{STR_VAR_1} ha rebut\n"

	.string "un/a {STR_VAR_2}!$"


LilycoveCity_PokemonCenter_1F_Text_YourBagIsFilledUp:
	.string "Oh? La Motxilla és plena!\n"

	.string "Vine quan tinguis espai.$"


LilycoveCity_PokemonCenter_1F_Text_WrongTheCorrectAnswerIs:
	.string "Hmm… Incorrecte!\n"

	.string "La resposta correcta és “{STR_VAR_3}”!$"


LilycoveCity_PokemonCenter_1F_Text_IGetToKeepPrize:
	.string "Quina llàstima!\p"

	.string "Em quedo el premi del qüestionari\n"

	.string "{STR_VAR_1}!$"


LilycoveCity_PokemonCenter_1F_Text_MakeYourOwnQuiz:
	.string "Escolta, escolta!\n"

	.string "Vols crear el teu propi qüestionari?$"


LilycoveCity_PokemonCenter_1F_Text_MaybeNextTime:
	.string "Oh, ja veig…\n"

	.string "Bé, potser un altre cop!$"


LilycoveCity_PokemonCenter_1F_Text_PickYourPrize:
	.string "D'acord, primer has de triar el\n"

	.string "premi per a qui respongui bé\l"

	.string "el teu qüestionari.\p"

	.string "Però compte, si qui el fa no\n"

	.string "encerta, em quedo jo\l"

	.string "el premi!$"


LilycoveCity_PokemonCenter_1F_Text_QuitChoosingPrize:
	.string "Si no tries un premi,\n"

	.string "no es pot crear el qüestionari.\p"

	.string "Vols deixar de crear\n"

	.string "el teu qüestionari?$"


LilycoveCity_PokemonCenter_1F_Text_WriteYourQuiz:
	.string "Oh, que bé!\n"

	.string "Quin premi tan fantàstic!\p"

	.string "Ara, has d'escriure la pregunta\n"

	.string "del qüestionari i la resposta.$"


LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizQuestion:
	.string "Vols deixar d'escriure\n"

	.string "la pregunta del qüestionari?$"


@ Unused
LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizAnswer:
	.string "Vols deixar de triar\n"

	.string "la resposta del qüestionari?$"


LilycoveCity_PokemonCenter_1F_Text_IllLookForAChallenger:
	.string "Gràcies!\n"

	.string "Has creat un bon qüestionari.\p"

	.string "Buscaré algú que accepti el repte\n"

	.string "del teu qüestionari ara mateix.$"


LilycoveCity_PokemonCenter_1F_Text_ImTheContestLady:
	.string "Sóc la Senyora dels Concursos!\n"

	.string "M'encanten els Concursos!$"


LilycoveCity_PokemonCenter_1F_Text_ThankForPokeblock:
	.string "Gràcies pel {POKEBLOCK} d'abans!$"


LilycoveCity_PokemonCenter_1F_Text_MyFriendDisplaysQuality:
	.string "Aquest és el meu amic {STR_VAR_1}!\n"

	.string "És l'epítom de {STR_VAR_2}!\p"

	.string "Però crec que pot mostrar\n"

	.string "encara més {STR_VAR_2}!$"


LilycoveCity_PokemonCenter_1F_Text_DontHaveAPokeblockCase:
	.string "Per tant, necessito la teva ajuda!\p"

	.string "Si us plau, em dones un {POKEBLOCK}?\n"

	.string "Només en demano un!\p"

	.string "…Oh, però…\n"

	.string "No tens un Estoig de {POKEBLOCK}?\l"

	.string "Això no va bé. Un altre cop, doncs!$"


LilycoveCity_PokemonCenter_1F_Text_AskingForOnePokeblock:
	.string "Per tant, necessito la teva ajuda!\p"

	.string "Si us plau, em dones un {POKEBLOCK}?\n"

	.string "Només en demano un!$"


LilycoveCity_PokemonCenter_1F_Text_ICantHaveOnePokeblock:
	.string "Ohhh!\n"

	.string "No em pots donar un {POKEBLOCK}?!$"


LilycoveCity_PokemonCenter_1F_Text_WhatACheapskate:
	.string "Bah!\n"

	.string "Quin garrepa!$"


LilycoveCity_PokemonCenter_1F_Text_IllUseYourPokeblock:
	.string "Bé!\n"

	.string "Gràcies!\p"

	.string "Alimentaré el meu Pokémon amb\n"

	.string "el teu {POKEBLOCK} ara mateix.$"


LilycoveCity_PokemonCenter_1F_Text_NoChangeThanks:
	.string "…No sembla que hagi canviat\n"

	.string "gens ni mica…\p"

	.string "Hmm…\p"

	.string "Bé, tant se val!\n"

	.string "Moltes gràcies!$"


LilycoveCity_PokemonCenter_1F_Text_ReallyImprovedThanks:
	.string "Oh, bé!\n"

	.string "Està molt content!\p"

	.string "Crec que ha millorat molt la\n"

	.string "qualitat de {STR_VAR_2} de {STR_VAR_1}.\p"

	.string "Moltes gràcies!$"


LilycoveCity_PokemonCenter_1F_Text_ReadyToEnterContests:
	.string "Hmm…\p"

	.string "Crec que estem preparats per\n"

	.string "participar en Concursos.\p"

	.string "Si ens veus en algun,\n"

	.string "espero que ens animis!$"


LilycoveCity_PokemonCenter_1F_Text_Zigzagoon:
	.string "{STR_VAR_1}: Guguuh!$"


LilycoveCity_PokemonCenter_1F_Text_Kecleon:
	.string "{STR_VAR_1}: Igigigiiih!$"


LilycoveCity_PokemonCenter_1F_Text_Poochyena:
	.string "{STR_VAR_1}: Baaarun…$"


LilycoveCity_PokemonCenter_1F_Text_Pikachu:
	.string "{STR_VAR_1}: Pikka!$"


LilycoveCity_PokemonCenter_1F_Text_Skitty:
	.string "{STR_VAR_1}: Umyaaaan!$"


MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, 0
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 1
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_SYS_HIPSTER_MEET
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special GetHipsterSpokenFlag
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfPhrase, MSGBOX_DEFAULT
	special SetHipsterSpokenFlag
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "Hola, sóc el Comerciant.\n"

	.string "Vols intercanviar decoracions?$"


MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "Oh…\n"

	.string "M'has deixat una mica trist…$"


MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "Però si ja hem intercanviat\n"

	.string "decoracions, tu i jo.$"


MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "Si veus algun objecte decoratiu\n"

	.string "meu que t'agradi, digues-ho.$"


MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "No vols res?\n"

	.string "Em sento rebutjat…$"


MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "Aquell objecte decoratiu va ser\n"

	.string "de {STR_VAR_1}.\p"

	.string "El vols?$"


MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "Eh… Un moment. No tens ni una\n"

	.string "sola peça de decoració!$"


MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "D'acord, tria la decoració que\n"

	.string "m'intercanviaràs.$"


MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "No vols intercanviar?\n"

	.string "Em sento rebutjat…$"


MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "Ja tens tots els {STR_VAR_2} que es\n"

	.string "poden guardar. No tens espai.$"


MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "D'acord, intercanviem el meu\n"

	.string "{STR_VAR_3} pel teu {STR_VAR_2}?$"


MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "Aquesta decoració està en ús.\n"

	.string "No la pots intercanviar.$"


MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "Doncs intercanviem!\n"

	.string "T'envio la decoració al teu PC.$"


MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "Ui! Ho sento! Aquesta és una peça\n"

	.string "de decoració molt rara.\l"

	.string "No la puc intercanviar!\p"

	.string "Et puc oferir alguna altra cosa?$"


MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	waitstate
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	waitstate
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "Sóc el Contacontes.\n"

	.string "T'explicaré històries\l"

	.string "d'Entrenadors llegendaris.\p"

	.string "Vols escoltar la meva història?$"


MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "Oh…\n"

	.string "M'has deixat una mica trist…$"


MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "Conec aquestes llegendes.\n"

	.string "Quina vols que t'expliqui?$"


MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "Però no conec cap Entrenador\n"

	.string "llegendari.\l"

	.string "Per tant, no tinc històries.\p"

	.string "On es pot trobar un Entrenador\n"

	.string "digne d'una llegenda?$"


MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "Què dius?!\n"

	.string "Tu… Tu…\p"

	.string "{STR_VAR_2}\n"

	.string "{STR_VAR_1} cop(s)?!\p"

	.string "Això sí que és magnífic!\n"

	.string "Neix una nova llegenda!$"


MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "Em fa pensar, podrien haver-hi\n"

	.string "altres Entrenadors amb llegendes\l"

	.string "encara més impressionants?$"


MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "Ets Entrenador?\p"

	.string "Doncs digue'm, tens alguna\n"

	.string "història ni que sigui\l"

	.string "remotament llegendària?$"


@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "Per cert… Voldries escoltar\n"

	.string "una altra història llegendària?$"


MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "Hmm…\n"

	.string "No estic satisfet…\p"

	.string "M'agradaria que em portessis\n"

	.string "notícies dignes de ser una\l"

	.string "llegenda.$"


MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "M'agradaria que a més gent li\n"

	.string "interessés escoltar les meves\l"

	.string "històries d'Entrenadors\l"

	.string "llegendaris.$"


MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "L'Entrenador Prudent$"


MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "Ha desat la partida$"


MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Aquest Entrenador va desar\n"

	.string "la partida {STR_VAR_1} vegades!\p"

	.string "No trobaràs un Entrenador més\n"

	.string "prudent que {STR_VAR_3}!$"


MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "L'Entrenador Tendència$"


MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "Ha iniciat tendències$"


MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Aquest Entrenador va iniciar\n"

	.string "tendències {STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} marca tendència a tota\n"

	.string "la regió de Hoenn!$"


MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
    .string "L'Entrenador Jardiner$"


MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "Ha plantat Baies$"


MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Aquest Entrenador va plantar\n"

	.string "Baies {STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} és un llegendari amant\n"

	.string "de les Baies!$"


MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "L'Entrenador Ciclista$"


MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "Ha canviat de Bici$"


MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Aquest Entrenador va canviar\n"

	.string "de Bici {STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} deu estimar les Bicis\n"

	.string "amb passió!$"


MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "L'Entrenador Entrevistat$"


MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "Ha estat entrevistat$"


MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Aquest Entrenador va ser\n"

	.string "entrevistat {STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} deu ser un Entrenador\n"

	.string "que atrau molta atenció!$"


MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "L'Entrenador Combatent$"


MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "Ha combatut$"


MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha combatut {STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} deu ser un Entrenador\n"

	.string "que mai rebutja un combat!$"


MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "L'Entrenador Caçador$"


MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "Ha capturat Pokémon$"


MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Aquest Entrenador va capturar\n"

	.string "{STR_VAR_1} Pokémon!\p"

	.string "{STR_VAR_3} és un llegendari caçador\n"

	.string "de Pokémon salvatges!$"


MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "L'Entrenador Pescador$"


MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "Ha pescat Pokémon amb Canya$"


MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Aquest Entrenador va capturar\n"

	.string "{STR_VAR_1} Pokémon pescant!\p"

	.string "{STR_VAR_3} és un llegendari expert\n"

	.string "en pesca!$"


MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "L'Entrenador Covador$"


MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "Ha fet eclosionar Ous$"


MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha fet eclosionar {STR_VAR_1} Pokémon\n"

	.string "dels Ous!\p"

	.string "{STR_VAR_3} és un llegendari covador\n"

	.string "d'Ous!$"


MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "L'Entrenador Evolucionador$"


MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "Ha evolucionat Pokémon$"


MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha fet evolucionar {STR_VAR_1}\n"

	.string "Pokémon!\p"

	.string "{STR_VAR_3} és el millor fent\n"

	.string "evolucionar Pokémon!$"


MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "L'Amant dels Centres Pokémon$"


MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "Ha usat Centres Pokémon$"


MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha curat Pokémon {STR_VAR_1} vegades\n"

	.string "als Centres Pokémon!\p"

	.string "No hi ha major amant dels Centres\n"

	.string "Pokémon que {STR_VAR_3}!$"


MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "L'Entrenador Casolà$"


MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "Ha reposat Pokémon a casa$"


MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha curat Pokémon a casa\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "No hi ha ningú més casolà\n"

	.string "que {STR_VAR_3}!$"


MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "L'Amant del Safari$"


MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "Ha entrat a la Zona Safari$"


MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha entrat a la Zona Safari\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} deu treure el seu costat\n"

	.string "salvatge a la Zona Safari!$"


MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "L'Entrenador Tallador$"


MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "Ha usat Tallar$"


MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha usat Tallar\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} deu ser un Entrenador\n"

	.string "que adora Tallar!$"


MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "L'Entrenador Trencapedres$"


MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "Ha trencat roques$"


MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha usat Trenca Roques\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} deu ser un Entrenador que\n"

	.string "no deixa cap pedra sencera!$"


MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "L'Entrenador Mudancer$"


MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "Ha mogut la Base Secreta$"


MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha mogut la Base Secreta\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} és un Entrenador que\n"

	.string "li agrada mudar-se sovint!$"


MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "L'Entrenador Esquitxador$"


MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "Ha usat Esquitxada$"


MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha usat Esquitxada\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} deu ser un Entrenador\n"

	.string "que adora esquitxar!$"


MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "L'Entrenador Tenaç$"


MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "Ha hagut de recórrer a Lluita$"


MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha hagut de recórrer a Lluita\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} és un Entrenador tenaç\n"

	.string "que mai es rendeix!$"


MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "El Campió de les Tragaperres$"


MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "Ha guanyat el premi gros$"


MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha guanyat el premi gros de les\n"

	.string "Tragaperres {STR_VAR_1} vegades.\p"

	.string "{STR_VAR_3} és un Entrenador amb sort\n"

	.string "a les Tragaperres!$"


MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "El Campió de la Ruleta$"


MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "Ha tingut victòries seguides de$"


MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha guanyat a la Ruleta\n"

	.string "{STR_VAR_1} vegades seguides.\p"

	.string "{STR_VAR_3} va tenir sort quan la bola\n"

	.string "va botar a la Ruleta!$"


MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "El Retador de la Torre Combat$"


MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "Ha acceptat el repte de la Torre$"


MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha acceptat el repte de la\n"

	.string "Torre Combat {STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} aspira a l'excel·lència\n"

	.string "a la Torre Combat!$"


MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "L'Amant de les Mescles$"


MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "Ha fet {POKEBLOCK}s$"


MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha fet {POKEBLOCK}s\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "Ningú no utilitza la Mescladora\n"

	.string "de Baies millor que {STR_VAR_3}!$"


MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "L'Amant dels Concursos$"


MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "Ha participat en Concursos$"


MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha participat en Concursos\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} deu adorar lluir els\n"

	.string "seus Pokémon!$"


MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "El Mestre dels Concursos$"


MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "Ha guanyat Concursos$"


MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha guanyat Concursos\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} deu ser un increïble\n"

	.string "mestre dels Concursos!$"


MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "El Comprador Feliç$"


MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "Ha anat de compres$"


MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha comprat objectes a botigues\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} deu ser d'aquelles\n"

	.string "persones nascudes per comprar.$"


MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "El Trobador d'Objectes$"


MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "Ha usat un Buscaobjectes$"


MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha usat un Buscaobjectes\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} deu gaudir buscant\n"

	.string "objectes amagats pel terra!$"


MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "L'Entrenador Xop$"


MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "Li ha plogut a sobre$"


MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Li ha plogut a sobre\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "El carisma de {STR_VAR_3} deu\n"

	.string "atreure fins i tot la pluja!$"


MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "L'Àvid Lector de Pokédex$"


MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "Ha consultat la Pokédex$"


MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha consultat la Pokédex\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} deu adorar examinar\n"

	.string "Pokémon a la Pokédex!$"


MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "El Col·leccionista de Cintes$"


MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "Ha rebut Cintes$"


MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha rebut Cintes\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} deu ser un Entrenador\n"

	.string "que adora col·leccionar Cintes!$"


MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "El Saltador de Sortints$"


MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "Ha saltat per sortints$"


MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha saltat per sortints\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "Si hi ha un sortint per saltar,\n"

	.string "{STR_VAR_3} no el pot ignorar!$"


MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "El Llegendari Televident$"


MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "Ha mirat la TV$"


MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha mirat la TV\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} deu adorar mirar la TV!$"


MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "L'Entrenador Puntual$"


MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "Ha mirat l'hora$"


MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha mirat l'hora\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} deu ser un Entrenador\n"

	.string "puntual i conscient del temps.$"


MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "El Mag de la Loteria Pokémon$"


MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "Ha guanyat Loteries Pokémon$"


MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha guanyat Loteries Pokémon\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} deu tenir molts amics\n"

	.string "amb qui intercanviar Pokémon!$"


MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "L'Usuari de la Guarderia$"


MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "Ha deixat Pokémon a la Guarderia$"


MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha deixat Pokémon a la Guarderia\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} deu ser un Entrenador\n"

	.string "que cria Pokémon amb ambició!$"


MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "L'Amant del Telefèric$"


MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "Ha pujat al Telefèric$"


MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "Ha pujat al Telefèric\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} deu ser un Entrenador\n"

	.string "que no para de pujar i baixar!$"


MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "L'Amant de les Termes$"


MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "S'ha banyat a les termes$"


MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "Aquesta és la història d'un\n"

	.string "Entrenador anomenat {STR_VAR_3}.\p"

	.string "S'ha banyat a les termes\n"

	.string "{STR_VAR_1} vegades!\p"

	.string "{STR_VAR_3} deu ser un Entrenador\n"

	.string "amb la pell ben suau!$"



MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "Sóc en Xalat!\n"

	.string "Tinc una història fascinant!\p"

	.string "Vols escoltar la meva història?$"


MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "Oh…\n"

	.string "M'has deixat una mica trist…$"


MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "A més, estava pensant…$"


MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "Això és tot, crec…\p"

	.string "Hauríem de xerrar un altre cop!\n"

	.string "Adéu!$"


MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "Hola, sóc el Bard.\n"

	.string "Vols escoltar la meva cançó?$"


MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "Oh…\n"

	.string "M'has deixat una mica trist…$"


MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "Oh, quina cançó tan emotiva…\n"

	.string "M'agradaria tocar-la per altri…$"


MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "I bé?\n"

	.string "Què et sembla la meva cançó?\p"

	.string "Però no estic gaire content\n"

	.string "amb la lletra.\p"

	.string "Voldries escriure una lletra\n"

	.string "nova per a mi?$"


MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "Oh…\n"

	.string "M'has deixat una mica trist…$"


MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "Moltes gràcies!\n"

	.string "Deixa'm cantar-la per a tu.$"


MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "Era així com volies que\n"

	.string "sonés la cançó?$"


MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "D'acord! Ja està, doncs.\n"

	.string "Cantaré aquesta cançó un temps.$"


MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "Ei, bona! Em diuen el Modernot.\n"

	.string "T'ensenyaré el que és tendència.$"


MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "Però ei, ja t'he ensenyat el que\n"

	.string "és tendència.\p"

	.string "M'agradaria compartir-ho\n"

	.string "amb altres persones.$"


MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "Però ei, ja saps molt sobre\n"

	.string "el que és tendència.\p"

	.string "No tinc res de nou per\n"

	.string "ensenyar-te!$"


MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfPhrase:
	.string "Ei, has sentit a parlar de\n"

	.string "“{STR_VAR_1}”?\p"

	.string "Què vol dir? Bé…\n"

	.string "Pregunta al teu pare o mare!$"


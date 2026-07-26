VermilionCity_House1_MapScripts::
	.byte 0

VermilionCity_House1_EventScript_FishingGuru::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, VermilionCity_House1_EventScript_AlreadyGotOldRod
	msgbox VermilionCity_House1_Text_ImFishingGuruDoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VermilionCity_House1_EventScript_GiveOldRod
	msgbox VermilionCity_House1_Text_OhThatsSoDisappointing, MSGBOX_DEFAULT
	release
	end

VermilionCity_House1_Text_ImFishingGuruDoYouLikeToFish::
    .string "Sóc el Gurú de la Pesca!\p"
    .string "M'encanta pescar!\n"
    .string "No puc viure sense fer-ho.\p"
    .string "Digues, a tu t'agrada pescar?$"

VermilionCity_House1_Text_OhThatsSoDisappointing::
    .string "Oh…\n"
    .string "Quina decepció…$"

VermilionCity_House1_EventScript_AlreadyGotOldRod::
	msgbox VermilionCity_House1_Text_HowAreTheFishBiting
	release
	end

VermilionCity_House1_Text_HowAreTheFishBiting::
    .string "Hola, {PLAYER}!\p"
    .string "Com piquen els peixos?$"

VermilionCity_House1_EventScript_GiveOldRod::
	checkitemspace ITEM_OLD_ROD, 1
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_House1_EventScript_NoRoomForOldRod
	additem ITEM_OLD_ROD
	msgbox VermilionCity_House1_Text_TakeThisAndFish, MSGBOX_DEFAULT
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox VermilionCity_House1_Text_ReceivedOldRodFromFishingGuru, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_OLD_ROD, 1
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox VermilionCity_House1_Text_FishingIsAWayOfLife, MSGBOX_DEFAULT
	release
	end

VermilionCity_House1_Text_TakeThisAndFish::
    .string "Genial! M'agrada el teu estil.\n"
    .string "Crec que podem ser amics.\p"
    .string "Pren això i vés a pescar, amic!$"

VermilionCity_House1_Text_FishingIsAWayOfLife::
    .string "La pesca és un estil de vida!\n"
    .string "És com la millor poesia.\p"
    .string "Dels mars als rius, surt a\n"
    .string "pescar el gran, amic meu.$"


VermilionCity_House1_EventScript_NoRoomForOldRod::
	msgbox VermilionCity_House1_Text_NoRoomForNiceGift, MSGBOX_DEFAULT
	release
	end

VermilionCity_House1_Text_NoRoomForNiceGift::
    .string "Oh, no!\p"
    .string "Tenia un bon regal per a tu, però\n"
    .string "no tens espai!$"

VermilionCity_House1_Text_ReceivedOldRodFromFishingGuru::
    .string "{PLAYER} ha rebut una Canya Vella\n"
    .string "del Gurú de la Pesca.$"





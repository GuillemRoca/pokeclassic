FuchsiaCity_House2_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_FishingGurusBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_GOOD_ROD, FuchsiaCity_House2_EventScript_AlreadyGotGoodRod
	msgbox FuchsiaCity_House2_Text_DoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House2_EventScript_GiveGoodRod
	msgbox FuchsiaCity_House2_Text_OhThatsDisappointing
	release
	end

FuchsiaCity_House2_EventScript_AlreadyGotGoodRod::
	msgbox FuchsiaCity_House2_Text_HowAreTheFishBiting
	release
	end

FuchsiaCity_House2_EventScript_GiveGoodRod::
	msgbox FuchsiaCity_House2_Text_LikeYourStyleTakeThis
	checkitemspace ITEM_GOOD_ROD, 1
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_House2_EventScript_NoRoomForGoodRod
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message FuchsiaCity_House2_Text_ReceivedGoodRod
	waitfanfare
	waitmessage
	additem ITEM_GOOD_ROD
	msgbox FuchsiaCity_House2_Text_GoodRodCanCatchBetterMons
	setflag FLAG_RECEIVED_GOOD_ROD
	release
	end

FuchsiaCity_House2_EventScript_NoRoomForGoodRod::
	msgbox FuchsiaCity_House2_Text_YouHaveNoRoomForGift
	release
	end

FuchsiaCity_House2_Text_DoYouLikeToFish::
    .string "Sóc el germà gran del Guru\n"
    .string "de la Pesca.\p"
    .string "M'encanta pescar!\n"
    .string "No puc viure sense!\p"
    .string "Digues, t'agrada pescar?$"

FuchsiaCity_House2_Text_LikeYourStyleTakeThis::
    .string "Genial! M'agrada el teu estil.\n"
    .string "Crec que podem ser amics.\p"
    .string "Pren això i pesca, jove amic!$"

FuchsiaCity_House2_Text_ReceivedGoodRod::
    .string "{PLAYER} ha rebut una Bona Canya\n"
    .string "del germà del Guru de la Pesca.$"

FuchsiaCity_House2_Text_GoodRodCanCatchBetterMons::
    .string "La pesca és una forma de vida!\n"
    .string "És com la poesia més fina.\p"
    .string "Una Canya Vella només podia\n"
    .string "atrapar Magikarp, oi?\p"
    .string "Però amb una Bona Canya, pots\n"
    .string "atrapar Pokémon molt millors.$"

FuchsiaCity_House2_Text_OhThatsDisappointing::
    .string "Oh…\n"
    .string "Quina decepció…$"

FuchsiaCity_House2_Text_HowAreTheFishBiting::
    .string "Hola, {PLAYER}!\p"
    .string "Com va la pesca?$"

FuchsiaCity_House2_Text_YouHaveNoRoomForGift::
    .string "Oh, no!\p"
    .string "Tenia un regal per a tu, però\n"
    .string "no tens espai!$"

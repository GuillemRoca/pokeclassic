Route12_FishingHouse_MapScripts::
	.byte 0

Route12_FishingHouse_EventScript_FishingGuruBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, Route12_FishingHouse_EventScript_CheckMagikarpRecord
	msgbox Route12_FishingHouse_Text_DoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route12_FishingHouse_EventScript_GiveSuperRod
	msgbox Route12_FishingHouse_Text_OhThatsDisappointing
	release
	end

Route12_FishingHouse_Text_DoYouLikeToFish::
    .string "Sóc el germà petit del Guru\n"
    .string "de la Pesca.\p"
    .string "M'encanta pescar!\n"
    .string "No puc viure sense!\p"
    .string "Digues, t'agrada pescar?$"

Route12_FishingHouse_Text_OhThatsDisappointing::
    .string "Oh…\n"
    .string "Quina decepció…$"

Route12_FishingHouse_EventScript_GiveSuperRod::
	checkitemspace ITEM_SUPER_ROD, 1
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoRoomForSuperRod
	msgbox Route12_FishingHouse_Text_TakeThisAndFish
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message Route12_FishingHouse_Text_ReceivedSuperRod
	waitfanfare
	waitmessage
	additem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox Route12_FishingHouse_Text_IfYouCatchBigMagikarpShowMe
	release
	end

Route12_FishingHouse_EventScript_NoRoomForSuperRod::
	msgbox Route12_FishingHouse_Text_NoRoomForGift
	release
	end

Route12_FishingHouse_Text_NoRoomForGift::
    .string "Oh, no!\p"
    .string "Tenia un regal per a tu, però\n"
    .string "no tens lloc.$"

Route12_FishingHouse_Text_ReceivedSuperRod::
    .string "{PLAYER} ha rebut una Súper Canya\n"
    .string "del germà del Guru de la Pesca.$"

Route12_FishingHouse_Text_TakeThisAndFish::
    .string "Genial! M'agrada el teu estil.\n"
    .string "Crec que podem ser amics.\p"
    .string "Agafa això i pesca, jove amic!$"

Route12_FishingHouse_Text_IfYouCatchBigMagikarpShowMe::
    .string "Pescar és un estil de vida!\n"
    .string "És com la millor poesia.\p"
    .string "Des de mars fins a rius, surt\n"
    .string "i pesca el peix gros, amic.\p"
    .string "Ara, tinc un favor a demanar.\p"
    .string "Si mai pesques un Magikarp gran,\n"
    .string "vull veure'l.\p"
    .string "Tant com m'agrada pescar, també\n"
    .string "m'encanta veure Magikarp\l"
    .string "gegants.$"

Route12_FishingHouse_EventScript_CheckMagikarpRecord::
	setvar VAR_0x8004, SPECIES_MAGIKARP
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq  VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoMagikarpInParty
	special GetMagikarpSizeRecordInfo
	msgbox Route12_FishingHouse_Text_OhMagikarpAllowMeToSee
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_ge VAR_RESULT, PARTY_SIZE, Route12_FishingHouse_EventScript_CancelShowMon
	special CompareMagikarpSize
	goto_if_eq VAR_RESULT, 1, Route12_FishingHouse_EventScript_NotMagikarp
	goto_if_eq VAR_RESULT, 2, Route12_FishingHouse_EventScript_NotRecordMagikarp
	goto_if_eq VAR_RESULT, 3, Route12_FishingHouse_EventScript_NewRecordMagikarp
	goto_if_eq VAR_RESULT, 4, Route12_FishingHouse_EventScript_TieRecordMagikarp
	release
	end

Route12_FishingHouse_Text_OhMagikarpAllowMeToSee::
    .string "Oh? {PLAYER}?\n"
    .string "Oi, si és un Magikarp!\p"
    .string "Deixa'm veure'l, ràpid!$"

Route12_FishingHouse_EventScript_NoMagikarpInParty::
	msgbox Route12_FishingHouse_Text_TryFishingBringMeMagikarp
	release
	end

Route12_FishingHouse_Text_TryFishingBringMeMagikarp::
    .string "Hola, {PLAYER}!\n"
    .string "Has estat pescant?\p"
    .string "Prova de pescar a qualsevol cos\n"
    .string "d'aigua amb canyes diferents!\p"
    .string "Trobaràs Pokémon diferents en\n"
    .string "llocs diferents, i a hores\l"
    .string "diferents del dia!\p"
    .string "Oh, i no oblidis portar-me\n"
    .string "Magikarp gegants.$"

Route12_FishingHouse_EventScript_CancelShowMon::
	release
	end

Route12_FishingHouse_EventScript_NotMagikarp::
	msgbox Route12_FishingHouse_Text_DoesntLookLikeMagikarp
	release
	end

Route12_FishingHouse_EventScript_NotRecordMagikarp::
	goto_if_unset FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_NewRecordMagikarp
	msgbox Route12_FishingHouse_Text_HmmXInchesDoesntMeasureUp
	release
	end

Route12_FishingHouse_EventScript_TieRecordMagikarp::
	goto_if_unset FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_NewRecordMagikarp
	msgbox Route12_FishingHouse_Text_HuhXInchesSameSizeAsLast
	release
	end

Route12_FishingHouse_EventScript_NewRecordMagikarp::
	setflag FLAG_GOT_RECORD_SETTING_MAGIKARP
	msgbox Route12_FishingHouse_Text_WhoaXInchesTakeThis
	giveitem ITEM_BIG_PEARL
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoRoomForNetBall
	msgbox Route12_FishingHouse_Text_LookForwardToGreaterRecords
	release
	end

Route12_FishingHouse_Text_WhoaXInchesTakeThis::
    .string "… … …Uau!\n"
    .string "{STR_VAR_2} polzades!\p"
    .string "Tens una apreciació rara pels\n"
    .string "aspectes fins i poètics de\l"
    .string "la pesca!\p"
    .string "Has d'agafar això.\n"
    .string "Insisteixo!$"

Route12_FishingHouse_EventScript_NoRoomForNetBall::
	msgbox Route12_FishingHouse_Text_NoRoomForGift
	release
	end

Route12_FishingHouse_EventScript_MagikarpRecordSign::
	lockall
	goto_if_set FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_MagikarpRecordSignRecordSet
	msgbox Route12_FishingHouse_Text_BlankChartOfSomeSort
	releaseall
	end

Route12_FishingHouse_EventScript_MagikarpRecordSignRecordSet::
	special GetMagikarpSizeRecordInfo
	msgbox Route12_FishingHouse_Text_MostGiganticMagikarpXInches
	releaseall
	end

Route12_FishingHouse_Text_LookForwardToGreaterRecords::
    .string "Espero amb ganes veure rècords\n"
    .string "encara més grans!$"

Route12_FishingHouse_Text_HuhXInchesSameSizeAsLast::
    .string "Eh?\n"
    .string "{STR_VAR_2} polzades?\p"
    .string "Fa la mateixa mida que l'últim\n"
    .string "que vaig veure.$"

Route12_FishingHouse_Text_HmmXInchesDoesntMeasureUp::
    .string "Hmm…\n"
    .string "Fa {STR_VAR_2} polzades.\p"
    .string "No arriba al de {STR_VAR_3}\n"
    .string "polzades que vas portar abans.$"

Route12_FishingHouse_Text_DoesntLookLikeMagikarp::
    .string "Ehm… Això no s'assembla gaire\n"
    .string "a un Magikarp.$"

Route12_FishingHouse_Text_MostGiganticMagikarpXInches::
    .string "El Magikarp més gegant que\n"
    .string "he vist mai…\p"
    .string "{STR_VAR_3} polzades!$"

Route12_FishingHouse_Text_BlankChartOfSomeSort::
    .string "És un gràfic en blanc.\p"
    .string "Té espais per escriure-hi\n"
    .string "rècords d'algun tipus.$"

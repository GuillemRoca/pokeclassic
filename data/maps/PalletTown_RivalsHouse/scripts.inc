.set LOCALID_DAISY, 1

PalletTown_RivalsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_RivalsHouse_OnTransition
	.byte 0

PalletTown_RivalsHouse_OnTransition::
	goto_if_le VAR_OAK_LAB_STATE, 7, PalletTown_RivalsHouse_EventScript_MoveDaisyToTable
	end

PalletTown_RivalsHouse_EventScript_MoveDaisyToTable::
	setobjectmovementtype LOCALID_DAISY, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_DAISY, 5, 4
	end

PalletTown_RivalsHouse_EventScript_Picture::
	msgbox PalletTown_RivalsHouse_Text_ItsBigMapOfKanto, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_Text_ItsBigMapOfKanto::
    .string "És un mapa gran de la regió de\n"
    .string "Kanto.\p"
    .string "No és molt més fàcil fer servir\n"
    .string "el mapa del PokéGear?!$"

PalletTown_RivalsHouse_EventScript_Bookshelf::
	msgbox PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks::
    .string "Els prestatges estan plens de\n"
    .string "llibres sobre Pokémon.$"

PalletTown_RivalsHouse_EventScript_Daisy::
	lock
	faceplayer
	goto_if_le VAR_OAK_LAB_STATE, 3, PalletTown_RivalsHouse_EventScript_Daisy1
	goto_if_le VAR_OAK_LAB_STATE, 4, PalletTown_RivalsHouse_EventScript_Daisy2
	goto_if_unset FLAG_REGISTERED_RIVAL, PalletTown_RivalsHouse_EventScript_Daisy3
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_RivalsHouse_EventScript_GroomMon
	goto PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest
	end

PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest::
	msgbox PalletTown_RivalsHouse_Text_PleaseGiveMonsRest, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_PleaseGiveMonsRest::
    .string "Daisy: Igual que les persones,\n"
    .string "els Pokémon són éssers vius.\p"
    .string "Quan estiguin cansats, deixa'ls\n"
    .string "descansar, si us plau.$"

PalletTown_RivalsHouse_EventScript_Daisy1::
	msgbox PalletTown_RivalsHouse_Text_HiBrothersAtLab, MSGBOX_DEFAULT
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
	release
	end

PalletTown_RivalsHouse_Text_HiBrothersAtLab::
    .string "Daisy: Hola, {PLAYER}!\p"
    .string "El meu germà, {RIVAL}, és al\n"
    .string "laboratori de l'avi.$"

PalletTown_RivalsHouse_EventScript_Daisy2::
	msgbox PalletTown_RivalsHouse_Text_HeardYouBattledRival, MSGBOX_DEFAULT
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
	release
	end

PalletTown_RivalsHouse_Text_HeardYouBattledRival::
    .string "Daisy: {PLAYER}, he sentit que\n"
    .string "has combatut contra {RIVAL}.\p"
    .string "M'hauria agradat veure-ho!$"

PalletTown_RivalsHouse_EventScript_Daisy3::
	goto_if_le VAR_OAK_LAB_STATE, 7, PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest
	msgbox PalletTown_RivalsHouse_Text_GetRivalNumber, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredRival, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_RIVAL
	setflag FLAG_REGISTERED_DAISY
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
	release
	end

PalletTown_RivalsHouse_Text_GetRivalNumber::
    .string "L'avi et va demanar que fessis\n"
    .string "un encàrrec?\p"
    .string "I {RIVAL} ni tan sols et va\n"
    .string "donar el seu número?\p"
    .string "Vaja, quin maleducat.\n"
    .string "Deixa'm ajudar-te.$"

PalletTown_RivalsHouse_EventScript_GroomMon:: @TODO
	goto_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 500, PalletTown_RivalsHouse_EventScript_RateMonFriendship
	msgbox PalletTown_RivalsHouse_Text_LikeMeToGroomMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PalletTown_RivalsHouse_EventScript_DeclineGrooming
	msgbox PalletTown_RivalsHouse_Text_GroomWhichOne
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_RivalsHouse_EventScript_DeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_RivalsHouse_EventScript_CantGroomEgg
	msgbox PalletTown_RivalsHouse_Text_LookingNiceInNoTime, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special DaisyMassageServices
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_RivalsHouse_Text_ThereYouGoAllDone, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_DAISY, Common_Movement_Heart
	applymovement LOCALID_DAISY, Common_Movement_Delay48
	waitmovement 1
	release
	end

PalletTown_RivalsHouse_Text_LikeMeToGroomMon::
    .string "Daisy: Hola, {PLAYER}!\n"
    .string "Quin bon moment.\p"
    .string "Estic a punt de prendre un te.\n"
    .string "Vols unir-t'hi?\p"
    .string "Oh, mira.\n"
    .string "Els teus Pokémon estan una mica\l"
    .string "bruts.\p"
    .string "Vols que en pentini un?$"

PalletTown_RivalsHouse_EventScript_DeclineGrooming::
	msgbox PalletTown_RivalsHouse_Text_DontNeedAnyGrooming
	release
	end

PalletTown_RivalsHouse_Text_DontNeedAnyGrooming::
    .string "No necessites que els pentini?\n"
    .string "D'acord, prendrem te.$"

PalletTown_RivalsHouse_Text_GroomWhichOne::
    .string "Quin hauria de pentinar?$"

PalletTown_RivalsHouse_EventScript_CantGroomEgg::
	msgbox PalletTown_RivalsHouse_Text_CantGroomAnEgg, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_CantGroomAnEgg::
    .string "Oh, ho sento. Sincerament,\n"
    .string "no puc pentinar un Ou.$"

PalletTown_RivalsHouse_Text_LookingNiceInNoTime::
    .string "Daisy: D'acord, el deixaré bonic\n"
    .string "en un tres i no res.$"

PalletTown_RivalsHouse_Text_ThereYouGoAllDone::
    .string "{STR_VAR_1} sembla somiar despert…\p"
    .string "Daisy: Ja està! Tot fet.\n"
    .string "Veus? No queda bonic?\p"
    .string "Hihi…\n"
    .string "És un Pokémon tan bufó.$"


PalletTown_RivalsHouse_EventScript_RateMonFriendship::
	msgbox PalletTown_RivalsHouse_Text_MayISeeFirstMon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case 0, PalletTown_RivalsHouse_EventScript_MonFriendshipLowest
	case 1, PalletTown_RivalsHouse_EventScript_MonFriendshipLower
	case 2, PalletTown_RivalsHouse_EventScript_MonFriendshipLow
	case 3, PalletTown_RivalsHouse_EventScript_MonFriendshipMid
	case 4, PalletTown_RivalsHouse_EventScript_MonFriendshipHigh
	case 5, PalletTown_RivalsHouse_EventScript_MonFriendshipHigher
	case 6, PalletTown_RivalsHouse_EventScript_MonFriendshipHighest
	end

PalletTown_RivalsHouse_Text_MayISeeFirstMon::
    .string "Daisy: Els teus Pokémon t'estimen\n"
    .string "si els cries amb amor.\p"
    .string "Per exemple, {PLAYER}, puc veure\n"
    .string "el teu primer Pokémon?$"

PalletTown_RivalsHouse_EventScript_MonFriendshipLowest::
	msgbox PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch::
    .string "…Mmm, no m'és fàcil dir-te\n"
    .string "això, però…\p"
    .string "Hi ha alguna raó per la qual\n"
    .string "el teu Pokémon t'odiaria tant?$"

PalletTown_RivalsHouse_EventScript_MonFriendshipLower::
	msgbox PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou::
    .string "{PLAYER}, no m'agrada com\n"
    .string "et mira de reüll.\p"
    .string "Podries provar de ser una mica\n"
    .string "més amable?$"

PalletTown_RivalsHouse_EventScript_MonFriendshipLow::
	msgbox PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet::
    .string "Encara no té gaire confiança\n"
    .string "amb tu.\p"
    .string "Els Pokémon són molt recelosos\n"
    .string "quan tot just els tens.$"

PalletTown_RivalsHouse_EventScript_MonFriendshipMid::
	msgbox PalletTown_RivalsHouse_Text_ItsWarmingUpToYou, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_ItsWarmingUpToYou::
    .string "S'està acostumant a tu.\n"
    .string "La confiança entre vosaltres creix.$"

PalletTown_RivalsHouse_EventScript_MonFriendshipHigh::
	msgbox PalletTown_RivalsHouse_Text_ItsQuiteFriendly, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_ItsQuiteFriendly::
    .string "És bastant amigable amb tu.\n"
    .string "Continua tractant-lo bé!$"

PalletTown_RivalsHouse_EventScript_MonFriendshipHigher::
	msgbox PalletTown_RivalsHouse_Text_ItLooksVeryHappy, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_ItLooksVeryHappy::
    .string "Sembla molt content.\p"
    .string "M'agradaria que {RIVAL} ho veiés\n"
    .string "i n'aprengués alguna cosa.$"

PalletTown_RivalsHouse_EventScript_MonFriendshipHighest::
	msgbox PalletTown_RivalsHouse_Text_CouldntLoveYouMore, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_CouldntLoveYouMore::
    .string "No podria estimar-te més\n"
    .string "del que ho fa ara.\p"
    .string "El teu Pokémon és feliç\n"
    .string "més enllà de les paraules.$"




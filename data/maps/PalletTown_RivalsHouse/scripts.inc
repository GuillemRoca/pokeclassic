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
    .string "És un mapa gran de la regió de Kanto.\p"
    .string "No és molt més còmode fer servir\n"
    .string "el mapa del PokéGear?!$"

PalletTown_RivalsHouse_EventScript_Bookshelf::
	msgbox PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks::
    .string "Les prestatgeries són plenes de\n"
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
    .string "Daisy: Igual que les persones, els\n"
    .string "Pokémon són éssers vius.\p"
    .string "Quan es cansen, si us plau, deixa'ls\n"
    .string "descansar.$"

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
    .string "Daisy: {PLAYER}, m'han dit que has\n"
    .string "combatut contra {RIVAL}.\p"
    .string "Tant de bo ho hagués vist!$"

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
    .string "L'avi t'ha demanat que li facis\n"
    .string "un encàrrec?\p"
    .string "I {RIVAL} no t'ha volgut donar\n"
    .string "ni el seu número?\p"
    .string "Uf, quina poca educació.\n"
    .string "Vine, deixa'm ajudar-te.$"

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
    .string "Arribes en bon moment.\p"
    .string "Ara mateix anava a prendre un te.\n"
    .string "Vols acompanyar-me?\p"
    .string "Oh, però mira.\n"
    .string "Els teus Pokémon estan una mica bruts.\p"
    .string "Vols que en pentini un?$"

PalletTown_RivalsHouse_EventScript_DeclineGrooming::
	msgbox PalletTown_RivalsHouse_Text_DontNeedAnyGrooming
	release
	end

PalletTown_RivalsHouse_Text_DontNeedAnyGrooming::
    .string "No en vols pentinar cap?\n"
    .string "D'acord, doncs només prendrem te.$"

PalletTown_RivalsHouse_Text_GroomWhichOne::
    .string "Quin vols que pentini?$"

PalletTown_RivalsHouse_EventScript_CantGroomEgg::
	msgbox PalletTown_RivalsHouse_Text_CantGroomAnEgg, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_CantGroomAnEgg::
    .string "Oh, perdona. Sincerament, no puc\n"
    .string "pentinar un Ou.$"

PalletTown_RivalsHouse_Text_LookingNiceInNoTime::
    .string "Daisy: Molt bé, el deixaré ben\n"
    .string "maco en un moment.$"

PalletTown_RivalsHouse_Text_ThereYouGoAllDone::
    .string "{STR_VAR_1} sembla content i somiador…\p"
    .string "Daisy: Ja està! Acabat.\n"
    .string "Ho veus? No està maco?\p"
    .string "Ha, ha…\n"
    .string "Quin Pokémon més bonic.$"


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
    .string "Daisy: Els teus Pokémon t'arriben a\n"
    .string "estimar si els cries amb amor.\p"
    .string "Per exemple, {PLAYER}, puc veure\n"
    .string "el teu primer Pokémon?$"

PalletTown_RivalsHouse_EventScript_MonFriendshipLowest::
	msgbox PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch::
    .string "…Ehm, no em resulta fàcil dir-te\n"
    .string "això, però…\p"
    .string "Hi ha algun motiu perquè el teu\n"
    .string "Pokémon t'odiï tant?$"

PalletTown_RivalsHouse_EventScript_MonFriendshipLower::
	msgbox PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou::
    .string "{PLAYER}, no m'agrada com et\n"
    .string "mira de reüll.\p"
    .string "Podries provar de ser una mica més\n"
    .string "amable amb ell?$"

PalletTown_RivalsHouse_EventScript_MonFriendshipLow::
	msgbox PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet::
    .string "Encara no t'acaba de tenir\n"
    .string "confiança.\p"
    .string "Tots els Pokémon són desconfiats\n"
    .string "quan els acabes d'aconseguir.$"

PalletTown_RivalsHouse_EventScript_MonFriendshipMid::
	msgbox PalletTown_RivalsHouse_Text_ItsWarmingUpToYou, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_ItsWarmingUpToYou::
    .string "S'està acostumant a tu.\n"
    .string "La confiança va creixent entre vosaltres.$"

PalletTown_RivalsHouse_EventScript_MonFriendshipHigh::
	msgbox PalletTown_RivalsHouse_Text_ItsQuiteFriendly, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_ItsQuiteFriendly::
    .string "Es porta bastant bé amb tu.\n"
    .string "Continua tractant-lo bé!$"

PalletTown_RivalsHouse_EventScript_MonFriendshipHigher::
	msgbox PalletTown_RivalsHouse_Text_ItLooksVeryHappy, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_ItLooksVeryHappy::
    .string "Sembla molt content.\p"
    .string "Tant de bo {RIVAL} ho pogués veure i\n"
    .string "n'aprengués alguna cosa.$"

PalletTown_RivalsHouse_EventScript_MonFriendshipHighest::
	msgbox PalletTown_RivalsHouse_Text_CouldntLoveYouMore, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_CouldntLoveYouMore::
    .string "No et podria estimar més\n"
    .string "del que t'estima ara.\p"
    .string "El teu Pokémon és feliç més enllà\n"
    .string "de les paraules.$"




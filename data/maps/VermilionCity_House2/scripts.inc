VermilionCity_House2_MapScripts::
	.byte 0

VermilionCity_House2_EventScript_Elyssa::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_FARFETCHD
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	goto_if_set FLAG_IN_GAME_TRADE_FARFETCHD, VermilionCity_House2_EventScript_AlreadyTraded
	msgbox VermilionCity_House2_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_House2_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, VermilionCity_House2_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, VermilionCity_House2_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox VermilionCity_House2_Text_HeyThanks, MSGBOX_DEFAULT
	setflag FLAG_IN_GAME_TRADE_FARFETCHD
	release
	end

VermilionCity_House2_Text_HeyThanks::
	.string "Ei, gràcies!$"

VermilionCity_House2_Text_LookingForMonWannaTradeForMon::
	.string "Hola!\n"
	.string "Tens un {STR_VAR_1}?\p"
	.string "Vols intercanviar-lo pel meu\n"
	.string "{STR_VAR_2}?$"

VermilionCity_House2_EventScript_DeclineTrade::
	msgbox VermilionCity_House2_Text_DeclinedTrade
	release
	end

VermilionCity_House2_Text_DeclinedTrade::
	.string "Quina llàstima.$"

VermilionCity_House2_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox VermilionCity_House2_Text_WhatThatsNotMon
	release
	end

VermilionCity_House2_Text_WhatThatsNotMon::
	.string "…Això no és un {STR_VAR_1}.\p"
	.string "Si en trobes un, intercanvia-me'l\n"
	.string "si us plau!$"

VermilionCity_House2_EventScript_AlreadyTraded::
	msgbox VermilionCity_House2_Text_IsntMyOldMonGreat
	release
	end

VermilionCity_House2_Text_IsntMyOldMonGreat::
	.string "Com va el meu antic {STR_VAR_2}?\n"
	.string "El meu {STR_VAR_1} va genial!$"

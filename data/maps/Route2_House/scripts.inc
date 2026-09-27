Route2_House_MapScripts::
	.byte 0

Route2_House_EventScript_Scientist::
	msgbox Route2_House_Text_FaintedMonsCanUseFieldMoves, MSGBOX_NPC
	end

Route2_House_Text_FaintedMonsCanUseFieldMoves::
    .string "Un Pokémon debilitat simplement\n"
    .string "no té energia per combatre.\p"
    .string "Però pot fer servir moviments com\n"
    .string "Tallar fora de combat.$"

Route2_House_EventScript_Reyley::
	lock
	faceplayer
	goto_if_set FLAG_IN_GAME_TRADE_MR_MIME, Route2_House_EventScript_AlreadyTraded
	setvar VAR_0x8008, INGAME_TRADE_MR_MIME
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox Route2_House_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route2_House_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route2_House_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, Route2_House_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox Route2_House_Text_HeyThanks, MSGBOX_DEFAULT
	setflag FLAG_IN_GAME_TRADE_MR_MIME
	release
	end

Route2_House_Text_HeyThanks::
	.string "Ei, gràcies!$"

Route2_House_Text_LookingForMonWannaTradeForMon::
	.string "Estic buscant el Pokémon\n"
	.string "{STR_VAR_1}!\p"
	.string "Vols canviar-ne un pel meu\n"
	.string "{STR_VAR_2}?$"

Route2_House_EventScript_DeclineTrade::
	msgbox Route2_House_Text_AwwOhWell
	release
	end

Route2_House_Text_AwwOhWell::
	.string "Oh!\n"
	.string "Bé, tant se val…$"

Route2_House_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Route2_House_Text_WhatThatsNoMon
	release
	end

Route2_House_Text_WhatThatsNoMon::
	.string "Què?\n"
	.string "Això no és un {STR_VAR_1}!$"

Route2_House_EventScript_AlreadyTraded::
	msgbox Route2_House_Text_IsntMyOldMonGreat
	release
	end

Route2_House_Text_IsntMyOldMonGreat::
	.string "No és genial el meu {STR_VAR_2}?$"


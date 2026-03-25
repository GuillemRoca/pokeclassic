Route11_EastEntrance_2F_MapScripts::
	.byte 0

Route11_EastEntrance_2F_EventScript_LeftBinoculars::
	lockall
	goto_if_set FLAG_WOKE_UP_ROUTE_12_SNORLAX, Route11_EastEntrance_2F_EventScript_LeftBinocularsSnorlaxGone
	msgbox Route11_EastEntrance_2F_Text_BigMonAsleepOnRoad
	releaseall
	end

Route11_EastEntrance_2F_Text_BigMonAsleepOnRoad::
    .string "A veure què mostren els\n"
    .string "prismàtics…\p"
    .string "Un Pokémon gran dorm al camí!$"

Route11_EastEntrance_2F_EventScript_LeftBinocularsSnorlaxGone::
	msgbox Route11_EastEntrance_2F_Text_WhatABreathtakingView
	releaseall
	end

Route11_EastEntrance_2F_Text_WhatABreathtakingView::
    .string "A veure què mostren els\n"
    .string "prismàtics…\p"
    .string "Quina vista tan impressionant!$"

Route11_EastEntrance_2F_EventScript_RightBinoculars::
	msgbox Route11_EastEntrance_2F_Text_RockTunnelGoodRouteToLavender, MSGBOX_SIGN
	end

Route11_EastEntrance_2F_Text_RockTunnelGoodRouteToLavender::
    .string "A veure què mostren els\n"
    .string "prismàtics…\p"
    .string "Per arribar a Lavender Town des\n"
    .string "de Cerulean City…\p"
    .string "El Túnel Roca sembla una bona\n"
    .string "ruta.$"

Route11_EastEntrance_2F_EventScript_Turner::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_NIDORINA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	goto_if_set FLAG_IN_GAME_TRADE_NIDORINA, Route11_EastEntrance_2F_EventScript_AlreadyTraded
	msgbox Route11_EastEntrance_2F_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route11_EastEntrance_2F_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route11_EastEntrance_2F_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, Route11_EastEntrance_2F_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox Route11_EastEntrance_2F_Text_HeyThanks, MSGBOX_DEFAULT
	setflag FLAG_IN_GAME_TRADE_NIDORINA
	release
	end

Route11_EastEntrance_2F_Text_HeyThanks::
	.string "Ei, gràcies!$"

Route11_EastEntrance_2F_Text_LookingForMonWannaTradeForMon::
	.string "Hola!\n"
	.string "Tens un {STR_VAR_1}?\p"
	.string "Vols canviar-lo pel meu\n"
	.string "{STR_VAR_2}?$"

Route11_EastEntrance_2F_EventScript_DeclineTrade::
	msgbox Route11_EastEntrance_2F_Text_DeclinedTrade
	release
	end

Route11_EastEntrance_2F_Text_DeclinedTrade::
	.string "Quina llàstima.$"

Route11_EastEntrance_2F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Route11_EastEntrance_2F_Text_WhatThatsNotMon
	release
	end

Route11_EastEntrance_2F_Text_WhatThatsNotMon::
	.string "Què?\n"
	.string "Això no és un {STR_VAR_1}!$"

Route11_EastEntrance_2F_EventScript_AlreadyTraded::
	msgbox Route11_EastEntrance_2F_Text_IsntMyOldMonGreat
	release
	end

Route11_EastEntrance_2F_Text_IsntMyOldMonGreat::
	.string "Com va el meu antic {STR_VAR_2}?\n"
	.string "El meu {STR_VAR_1} va genial!$"

@Aide Gift 3
Route11_EastEntrance_2F_EventScript_Aide::
    lock
    faceplayer
    goto_if_set FLAG_RECEIVED_ITEMFINDER, Route11_EastEntrance_2F_EventScript_AlreadyGotReward
    msgbox Route11_EastEntrance_2F_Text_GiveReward, MSGBOX_DEFAULT
    checkitemspace ITEM_ITEMFINDER, 1
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
    giveitem ITEM_ITEMFINDER, 1
    waitmessage
    setflag FLAG_RECEIVED_ITEMFINDER
    setflag FLAG_HIDE_AIDE_ROUTE11
    clearflag FLAG_AIDE_LOCATION_3
    clearflag FLAG_QUEUE_AIDE_CALL
    setvar VAR_AIDE_CALL_STEP_COUNTER, 0
    msgbox Route11_EastEntrance_2F_Text_ExplainReward, MSGBOX_DEFAULT
    call_if_set FLAG_BADGE05_GET, Route11_EastEntrance_2F_EventScript_AideNextLocation
    release
    end

Route11_EastEntrance_2F_Text_GiveReward::
    .string "Hola, {PLAYER}!\p"
    .string "El Prof. Oak diu que ho fas\n"
    .string "molt bé, així que t'he de donar\l"
    .string "aquesta recompensa.$"

Route11_EastEntrance_2F_EventScript_AlreadyGotReward::
    msgbox Route11_EastEntrance_2F_Text_ExplainReward, MSGBOX_DEFAULT
    release
    end

Route11_EastEntrance_2F_Text_ExplainReward::
    .string "Hi ha objectes al terra que\n"
    .string "poden estar amagats.\p"
    .string "Fes servir el Cercaobjectes\n"
    .string "per detectar objectes amagats.\p"
    .string "La màquina és una mica limitada.\n"
    .string "No pot precisar on són.\p"
    .string "El que fa és mostrar la direcció\n"
    .string "on és l'objecte.\p"
    .string "Fes-lo servir per orientar-te\n"
    .string "i busca la zona sospitosa a mà.$"

Route11_EastEntrance_2F_EventScript_AideNextLocation::
    setflag FLAG_QUEUE_AIDE_CALL
    setflag FLAG_AIDE_LOCATION_4
    return

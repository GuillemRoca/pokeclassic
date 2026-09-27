BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
	.string "Em pregunto si emetran entrevistes\n"
	.string "amb Entrenadors forts avui?$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.string "Si obrís un restaurant aquí,\n"
	.string "segur que guanyaria diners.$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
	.string "Buf…\p"
	.string "Necessito fer un descans després\n"
	.string "d'uns combats intensos…\p"
	.string "Però fins i tot ara, no paro\n"
	.string "de pensar estratègies i combos.$"


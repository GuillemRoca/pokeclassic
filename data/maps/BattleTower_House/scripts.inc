BattleTower_House_MapScripts::
	.byte 0

BattleTower_House_Scott::
	lock
	faceplayer
	msgbox BattleTower_House_Text_Scott, MSGBOX_NPC
	release
	end

BattleTower_House_Text_Scott::
	.string "Scott: Ei, Campió/ona!\n"
	.string "Gaudint de la Torre de Combat?\p"
	.string "Crec que per fi faré un descans\n"
	.string "de buscar Entrenadors.\p"
	.string "Qui sap, potser provaré\n"
	.string "uns combats jo mateix! Ha!$"

BattleTower_House_Sign::
	msgbox BattleTower_House_Text_Permit, MSGBOX_SIGN
	release
	end

BattleTower_House_Text_Permit::
	.string "És un permís per construir\n"
	.string "la Torre de Combat!$"

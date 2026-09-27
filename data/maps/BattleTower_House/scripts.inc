BattleTower_House_MapScripts::
	.byte 0

BattleTower_House_Scott::
	lock
	faceplayer
	msgbox BattleTower_House_Text_Scott, MSGBOX_NPC
	release
	end

BattleTower_House_Text_Scott::
	.string "Scott: Ei, {MASC}Campió{FEM}Campiona{ENDG}!\n"
	.string "Què et sembla la Torre de Combat?\p"
	.string "Crec que per fi deixaré de buscar\n"
	.string "Entrenadors una temporada.\p"
	.string "Qui sap, potser faré\n"
	.string "algun combat jo mateix! Ha!$"

BattleTower_House_Sign::
	msgbox BattleTower_House_Text_Permit, MSGBOX_SIGN
	release
	end

BattleTower_House_Text_Permit::
	.string "És un permís per construir\n"
	.string "la Torre de Combat!$"

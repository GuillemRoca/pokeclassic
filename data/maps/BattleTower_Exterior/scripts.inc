BattleTower_Exterior_MapScripts::
	.byte 0

BattleTower_Exterior_CoolTrainer1::
	msgbox BattleTower_Exterior_Text_WaitInLine, MSGBOX_NPC
	release
	end

BattleTower_Exterior_Text_WaitInLine::
	.string "Ei! Has de fer cua!$"

BattleTower_Exterior_CoolTrainer2::
	msgbox BattleTower_Exterior_Text_LineIsntMoving, MSGBOX_NPC
	release
	end

BattleTower_Exterior_Text_LineIsntMoving::
	.string "Uf, aquesta cua no es mou\n"
	.string "des de fa segles!$"

BattleTower_Exterior_Trainer3::
	msgbox BattleTower_Exterior_Text_BeatElite, MSGBOX_NPC
	release
	end

BattleTower_Exterior_Text_BeatElite::
	.string "Només els millors Entrenadors són\n"
	.string "convidats a la Torre de Combat!$"


BattleTower_Exterior_Jenny::
	goto_if_set FLAG_SYS_FRONTIER_PASS, BattleTower_Exterior_Jenny2
	msgbox BattleTower_Exterior_Text_AirTraffic, MSGBOX_NPC
	release
	end

BattleTower_Exterior_Text_AirTraffic::
	.string "Hi ha molt interès per la\n"
	.string "Torre de Combat.\p"
	.string "M'han posat aquí per gestionar\n"
	.string "la multitud.\p"
	.string "I no permetem que ningú hi voli\n"
	.string "sense un Passi de la Torre.$"

BattleTower_Exterior_Jenny2::
	msgbox BattleTower_Exterior_Text_TowerPass, MSGBOX_NPC
	release
	end

BattleTower_Exterior_Text_TowerPass::
	.string "Oh! Tens un Passi de la Torre.\n"
	.string "Ara estàs autoritzat a volar aquí!$"

BattleTower_Exterior_Lass::
	msgbox BattleTower_Exterior_Text_OnAStreak, MSGBOX_NPC
	release
	end

BattleTower_Exterior_Text_OnAStreak::
	.string "Tinc una ratxa de victòries a la\n"
	.string "Torre de Combat.\p"
	.string "Poliwrath i jo hem sortit a\n"
	.string "prendre l'aire.\p"
	.string "És important descansar.\n"
	.string "No vols posar-te nerviós/a!$"

BattleTower_Exterior_Poliwrath::
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox BattleTower_Exterior_Text_Poliwrath, MSGBOX_NPC
	release
	end

BattleTower_Exterior_Text_Poliwrath::
	.string "Poliwrath et mira.\n"
	.string "Està ple de determinació.$"

BattleTower_Exterior_Youngster::
	lock
	faceplayer
	msgbox BattleTower_Exterior_Text_BattleTower, MSGBOX_NPC
	release
	end

BattleTower_Exterior_Text_BattleTower::
	.string "Aquesta Torre de Combat està\n"
	.string "molt bé, oi?\p"
	.string "He sentit que el propietari està\n"
	.string "obsessionat amb trobar els més forts!$"

BattleTower_Exterior_Punk::
	lockall
	faceplayer
	goto_if_set FLAG_GOT_RED_CARD, BattleTower_Exterior_Punk2
	msgbox BattleTower_Exterior_Text_GotCarded, MSGBOX_DEFAULT
	giveitem ITEM_RED_CARD, 1
	msgbox BattleTower_Exterior_Text_KickedOut, MSGBOX_DEFAULT
	setflag FLAG_GOT_RED_CARD
	releaseall
	end

BattleTower_Exterior_Text_GotCarded::
	.string "No m'ho puc creure!\p"
	.string "Vaig cridar a l'àrbitre i em va\n"
	.string "donar una d'aquestes!$"

BattleTower_Exterior_Punk2::
	lockall
	msgbox BattleTower_Exterior_Text_KickedOut, MSGBOX_DEFAULT
	releaseall
	end

BattleTower_Exterior_Text_KickedOut::
	.string "No em puc creure que m'hagin tret\n"
	.string "només perquè he fet trampes!$"

BattleTower_Exterior_BattleTowerSign::
	msgbox BattleTower_Exterior_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleTower_Exterior_Text_BattleTowerSign::
    .string "La Torre de Combat de Kanto!\n"
    .string "Arriba fins al cim!$"

BattleTower_Exterior_BattleTowerHouse::
	msgbox BattleTower_Exterior_Text_BattleTowerHouse, MSGBOX_SIGN
	end

BattleTower_Exterior_Text_BattleTowerHouse::
    .string "Casa de l'Scott$"

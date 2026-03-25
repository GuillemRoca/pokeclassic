MysteryGiftScript_BattleCard::
	setvaddress MysteryGiftScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryGiftScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, REQUIRED_CARD_BATTLES, MysteryGiftScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryGiftScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "Gràcies per utilitzar el sistema\n"
	.string "de Regal Misteriós.\p"
	.string "La teva Targeta de Combats registra\n"
	.string "el teu historial de combats contra\l"
	.string "Entrenadors amb la mateixa Targeta.\p"
	.string "Busca i lluita contra Entrenadors\n"
	.string "que tinguin la mateixa Targeta.\p"
	.string "Pots consultar la classificació\n"
	.string "general llegint les notícies.\p"
	.string "Prova-ho!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "Gràcies per utilitzar el sistema\n"
	.string "de Regal Misteriós.\p"
	.string "Felicitats!\p"
	.string "Has guanyat un premi per guanyar\n"
	.string "tres combats!\p"
	.string "Esperem que t'inspiri a\n"
	.string "lluitar una mica més.$"

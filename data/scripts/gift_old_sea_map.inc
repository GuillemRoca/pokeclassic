MysteryGiftScript_OldSeaMap::
	setvaddress MysteryGiftScript_OldSeaMap
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_OLD_SEA_MAP, OldSeaMap_Obtained
	vgoto_if_set FLAG_CAUGHT_MEW, OldSeaMap_Obtained
	checkitem ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, TRUE, OldSeaMap_Obtained
	vmessage sText_MysteryGiftOldSeaMapForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, FALSE, OldSeaMap_NoBagSpace
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	vmessage sText_MysteryGiftOldSeaMapUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_NoBagSpace:
	vmessage sText_MysteryGiftOldSeaMapBagFull
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_Obtained:
	vmessage sText_MysteryGiftOldSeaMapThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftOldSeaMapForYou:
	.string "Gràcies per utilitzar el sistema\n"
	.string "de Regal Misteriós.\p"
	.string "Deixa'm confirmar: ets {PLAYER}?\p"
	.string "Hem rebut aquest Mapa Marí Antic\n"
	.string "adreçat a tu.$"

sText_MysteryGiftOldSeaMapUseAtPort:
	.string "Sembla que és per fer servir al\n"
	.string "port de Ciutat Lliricove.\p"
	.string "Per què no ho proves i veus\n"
	.string "de què es tracta?$"

sText_MysteryGiftOldSeaMapThankYou:
	.string "Gràcies per utilitzar el sistema\n"
	.string "de Regal Misteriós.$"

sText_MysteryGiftOldSeaMapBagFull:
	.string "Oh, ho sento, {PLAYER}.\n"
	.string "La Butxaca d'Obj. Clau és plena.\p"
	.string "Desa alguna cosa al teu PC\n"
	.string "i torna a buscar-ho.$"

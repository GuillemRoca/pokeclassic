MysteryGiftScript_AuroraTicket::
	setvaddress MysteryGiftScript_AuroraTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, AuroraTicket_Obtained
	checkitem ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, AuroraTicket_Obtained
	vmessage sText_AuroraTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, AuroraTicket_NoBagSpace
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	vmessage sText_AuroraTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace:
	vmessage sText_AuroraTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_Obtained:
	vmessage sText_AuroraTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicketForYou:
	.string "Gràcies per utilitzar el sistema\n"
	.string "de Regal Misteriós.\p"
	.string "Tu deus ser {PLAYER}.\n"
	.string "Hi ha un tiquet aquí per a tu.$"

sText_AuroraTicketUseAtPort:
	.string "Sembla que és per fer servir al\n"
	.string "port de Ciutat Lliricove.\p"
	.string "Per què no ho proves i veus\n"
	.string "de què es tracta?$"

sText_AuroraTicketThankYou:
	.string "Gràcies per utilitzar el sistema\n"
	.string "de Regal Misteriós.$"

sText_AuroraTicketBagFull:
	.string "Oh, ho sento, {PLAYER}.\n"
	.string "La Butxaca d'Obj. Clau és plena.\p"
	.string "Desa alguna cosa al teu PC\n"
	.string "i torna a buscar-ho.$"

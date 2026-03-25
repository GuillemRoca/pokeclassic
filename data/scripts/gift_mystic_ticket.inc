MysteryGiftScript_MysticTicket::
	setvaddress MysteryGiftScript_MysticTicket
	lock
	faceplayer
	checkitem ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, MysticTicket_Obtained
	vmessage sText_MysticTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, MysticTicket_NoBagSpace
	giveitem ITEM_MYSTIC_TICKET
	vmessage sText_MysticTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_NoBagSpace:
	vmessage sText_MysticTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_Obtained:
	vmessage sText_MysticTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysticTicketForYou:
	.string "Gràcies per utilitzar el sistema\n"
	.string "de Regal Misteriós.\p"
	.string "Tu deus ser {PLAYER}.\n"
	.string "Hi ha un tiquet aquí per a tu.$"

sText_MysticTicketUseAtPort:
	.string "Sembla que és per fer servir al\n"
	.string "port de Ciutat Lliricove.\p"
	.string "Per què no ho proves i veus\n"
	.string "de què es tracta?$"

sText_MysticTicketThankYou:
	.string "Gràcies per utilitzar el sistema\n"
	.string "de Regal Misteriós.$"

sText_MysticTicketBagFull:
	.string "Oh, ho sento, {PLAYER}.\n"
	.string "La Butxaca d'Obj. Clau és plena.\p"
	.string "Desa alguna cosa al teu PC\n"
	.string "i torna a buscar-ho.$"

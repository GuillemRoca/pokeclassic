SafariZone_West_MapScripts::
	.byte 0

SafariZone_West_EventScript_ItemTM32::
	finditem ITEM_TM32, 1
	release
	end

SafariZone_West_EventScript_ItemGoldTeeth::
	finditem ITEM_GOLD_TEETH, 1
	release
	end

SafariZone_West_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE, 1
	release
	end

SafariZone_West_EventScript_RestHouseSign::
	msgbox SafariZone_West_Text_RestHouse, MSGBOX_SIGN
	end

SafariZone_West_Text_RestHouse::
    .string "Casa de Descans$"

SafariZone_West_EventScript_LostTeethNotice::
	msgbox SafariZone_West_Text_PleaseFindWardensLostTeeth, MSGBOX_SIGN
	end

SafariZone_West_Text_PleaseFindWardensLostTeeth::
    .string "Avís\p"
    .string "Es prega que trobeu les Dents\n"
    .string "d'Or perdudes del Guarda del\l"
    .string "Safari. Són per aquí a prop.\p"
    .string "Hi ha recompensa!\n"
    .string "Contacte: el Guarda$"

SafariZone_West_EventScript_TrainerTips::
	msgbox SafariZone_West_Text_SearchForSecretHouse, MSGBOX_SIGN
	end

SafariZone_West_Text_SearchForSecretHouse::
    .string "Consells d'Entrenador:\p"
    .string "Campanya d'exploració de la Zona!\n"
    .string "A la recerca de la Casa Secreta!$"

SafariZone_West_EventScript_AreaSign::
	msgbox SafariZone_West_Text_AreaSign, MSGBOX_SIGN
	end

SafariZone_West_Text_AreaSign::
    .string "Àrea 3\n"
    .string "Est: Àrea Central$"

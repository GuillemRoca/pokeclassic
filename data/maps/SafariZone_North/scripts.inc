SafariZone_North_MapScripts::
	.byte 0

SafariZone_North_EventScript_ItemQuickClaw::
	finditem ITEM_QUICK_CLAW, 1
	end

SafariZone_North_EventScript_ItemTM47::
	finditem ITEM_TM47, 1
	end

SafariZone_North_EventScript_ItemProtein::
	finditem ITEM_PROTEIN, 1
	end

SafariZone_North_EventScript_RestHouseSign::
	msgbox SafariZone_North_Text_RestHouse, MSGBOX_SIGN
	end

SafariZone_North_Text_RestHouse::
    .string "Casa de Descans$"

SafariZone_North_EventScript_TrainerTips1::
	msgbox SafariZone_North_Text_SecretHouseStillAhead, MSGBOX_SIGN
	end

SafariZone_North_Text_SecretHouseStillAhead::
    .string "Consells d'Entrenador\p"
    .string "La Casa Secreta encara és\n"
    .string "més endavant.$"

SafariZone_North_EventScript_AreaSign::
	msgbox SafariZone_North_Text_Area2, MSGBOX_SIGN
	end

SafariZone_North_Text_Area2::
    .string "Àrea 2$"

SafariZone_North_EventScript_TrainerTips2::
	msgbox SafariZone_North_Text_ZigzagThroughTallGrass, MSGBOX_SIGN
	end

SafariZone_North_Text_ZigzagThroughTallGrass::
    .string "Consells d'Entrenador:\p"
    .string "Els Pokémon s'amaguen a l'herba\n"
    .string "alta.\p"
    .string "Fes ziga-zagues per zones\n"
    .string "d'herba per fer-los sortir.$"

SafariZone_North_EventScript_TrainerTips3::
	msgbox SafariZone_North_Text_WinFreeHMFindSecretHouse, MSGBOX_SIGN
	end

SafariZone_North_Text_WinFreeHMFindSecretHouse::
    .string "Consells d'Entrenador\p"
    .string "Guanya una MO gratis si trobes\n"
    .string "la Casa Secreta.$"

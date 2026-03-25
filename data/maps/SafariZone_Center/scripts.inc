SafariZone_Center_MapScripts::
	.byte 0

SafariZone_Center_EventScript_RestHouseSign::
	msgbox SafariZone_Center_Text_RestHouse, MSGBOX_SIGN
	end

SafariZone_Center_Text_RestHouse::
    .string "Casa de Descans$"

SafariZone_Center_EventScript_TrainerTips::
	msgbox SafariZone_Center_Text_PressStartToCheckTime, MSGBOX_SIGN
	end

SafariZone_Center_Text_PressStartToCheckTime::
    .string "Consells d'Entrenador:\p"
	.string "Si poses un {POKEBLOCK} a un\n"
	.string "Dispensador, els Pokémon\l"
	.string "s'hi reuniran.$"

SafariZone_Center_EventScript_AreaSign::
	msgbox SafariZone_Center_Text_CenterArea, MSGBOX_SIGN
	end

SafariZone_Center_Text_CenterArea::
    .string "Àrea Central$"


SafariZone_Center_EventScript_ItemNugget::
	finditem ITEM_NUGGET, 1
	release
	end

SafariZone_Center_EventScript_Pinsirte::
	finditem ITEM_PINSIRITE, 1
	release
	end

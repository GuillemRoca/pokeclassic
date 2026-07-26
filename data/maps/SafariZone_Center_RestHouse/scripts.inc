SafariZone_Center_RestHouse_MapScripts::
	.byte 0

SafariZone_Center_RestHouse_EventScript_Sara::
	msgbox SafariZone_Center_Text_WhereDidErikGo, MSGBOX_NPC
	end

SafariZone_Center_Text_WhereDidErikGo::
    .string "Sara: On ha anat el meu xicot,\n"
    .string "Erik?$"

SafariZone_Center_RestHouse_EventScript_Scientist::
	msgbox SafariZone_Center_Text_CatchingMonsAsGifts, MSGBOX_NPC
	end

SafariZone_Center_Text_CatchingMonsAsGifts::
    .string "Capturo Pokémon per endur-me'ls\n"
    .string "de regal.$"


SafariZone_Center_RestHouse_EventScript_RangerF::
	msgbox SafariZone_Center_RestHouse_Text_RangerF, MSGBOX_NPC
	end

SafariZone_Center_RestHouse_Text_RangerF:
	.string "Si fas servir {POKEBLOCK}s, els Pokémon\n"
	.string "salvatges no fugiran tan ràpid.\p"
	.string "No serveix de gaire donar {POKEBLOCK}s\n"
	.string "a Pokémon que no fugen fàcilment.$"

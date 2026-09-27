SafariZone_East_RestHouse_MapScripts::
	.byte 0

SafariZone_East_RestHouse_EventScript_Rocker::
	msgbox SafariZone_East_Text_CaughtChanseyAllWorthwhile, MSGBOX_NPC
	end

SafariZone_East_Text_CaughtChanseyAllWorthwhile::
    .string "He capturat un Chansey!\p"
    .string "Això fa que tot hagi valgut\n"
    .string "la pena.$"

SafariZone_East_RestHouse_EventScript_Scientist::
	msgbox SafariZone_East_Text_HowManyDidYouCatch, MSGBOX_NPC
	end

SafariZone_East_Text_HowManyDidYouCatch::
    .string "Quants n'has capturat?\n"
    .string "Estic rebentat de l'esforç!$"

SafariZone_East_RestHouse_EventScript_BaldingMan::
	msgbox SafariZone_East_Text_TiredFromAllTheFun, MSGBOX_NPC
	end

SafariZone_East_Text_TiredFromAllTheFun::
    .string "Uf!\n"
    .string "Estic cansat de tanta diversió!$"

SafariZone_East_RestHouse_EventScript_RangerM::
	msgbox SafariZone_East_RestHouse_Text_RangerM, MSGBOX_NPC
	end

SafariZone_East_RestHouse_Text_RangerM:
	.string "Si poses un {POKEBLOCK} al Dispensador,\n"
	.string "els Pokémon s'hi senten atrets.$"
	.string "Crec que Pokémon amb el mateix\n"
	.string "tipus de caràcter són atrets\l"
	.string "per un cert {POKEBLOCK}.$"

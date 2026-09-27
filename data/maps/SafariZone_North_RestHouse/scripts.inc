SafariZone_North_RestHouse_MapScripts::
	.byte 0

SafariZone_North_RestHouse_EventScript_Fisher::
	msgbox SafariZone_East_Text_PrizeInDeepestPartOfSafariZone, MSGBOX_NPC
	end

SafariZone_East_Text_PrizeInDeepestPartOfSafariZone::
    .string "Ves a la part més profunda de la\n"
    .string "Zona Safari. Guanyaràs un premi!$"

SafariZone_North_RestHouse_EventScript_Scientist::
	msgbox SafariZone_East_Text_KeepAnyItemFoundOnSafari, MSGBOX_NPC
	end

SafariZone_East_Text_KeepAnyItemFoundOnSafari::
    .string "Pots quedar-te qualsevol objecte\n"
    .string "que trobis a la Zona Safari.\p"
    .string "Però se t'acabarà el temps si\n"
    .string "intentes agafar-los tots alhora.$"

SafariZone_North_RestHouse_EventScript_Gentleman::
	msgbox SafariZone_East_Text_MyEeveeEvolvedIntoFlareon, MSGBOX_NPC
	end

SafariZone_East_Text_MyEeveeEvolvedIntoFlareon::
    .string "El meu Eevee va evolucionar a\n"
    .string "Flareon.\p"
    .string "Però l'Eevee d'un amic es va\n"
    .string "convertir en Vaporeon. Per què?$"

SafariZone_North_RestHouse_EventScript_Woman::
	msgbox SafariZone_North_RestHouse_Text_Woman, MSGBOX_NPC
	end

SafariZone_North_RestHouse_Text_Woman:
	.string "De vegades, quan llenço un {POKEBLOCK}\n"
	.string "als Pokémon, l'ignoren.\p"
	.string "Els Pokémon tenen gustos i\n"
	.string "preferències sobre el que mengen?$"

SafariZone_North_RestHouse_EventScript_BaldingMan::
	lock
	faceplayer
	msgbox SafariZone_North_RestHouse_Text_KogaPatrolsSafariEverySoOften
	release
	end

SafariZone_North_RestHouse_Text_KogaPatrolsSafariEverySoOften::
    .string "La Zona Safari és enorme, no\n"
    .string "trobes?\p"
    .string "El Líder del Gimnàs de Fuchsia,\n"
    .string "Koga, patrulla els terrenys\l"
    .string "de tant en tant.\p"
    .string "Gràcies a ell, podem jugar aquí\n"
    .string "sabent que estem segurs.$"

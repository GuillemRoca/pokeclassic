SilphCo_5F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_5F_OnLoad
	.byte 0

SilphCo_5F_OnLoad::
	call_if_unset FLAG_SILPH_5F_DOOR_1, EventScript_Close5FDoor1
	call_if_unset FLAG_SILPH_5F_DOOR_2, EventScript_Close5FDoor2
	call_if_unset FLAG_SILPH_5F_DOOR_3, EventScript_Close5FDoor3
	end

SilphCo_5F_EventScript_ItemProtein::
	finditem ITEM_PROTEIN, 1
	release
	end

SilphCo_5F_EventScript_ItemTM01::
	finditem ITEM_TM01, 1
	release
	end

SilphCo_5F_EventScript_ItemCardKey::
	finditem ITEM_CARD_KEY, 1
	release
	end

SilphCo_5F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_5F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_5F_Text_RocketsInUproarAboutIntruder
	release
	end

SilphCo_5F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_5F_Text_YoureOurHeroThankYou
	release
	end

SilphCo_5F_EventScript_PokemonReport1::
	msgbox SilphCo_5F_Text_PorygonFirstVRMon, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_PokemonReport2::
	msgbox SilphCo_5F_Text_Over350TechniquesConfirmed, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_PokemonReport3::
	msgbox SilphCo_5F_Text_SomeMonsEvolveWhenTraded, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_FloorSign::
	msgbox SilphCo_5F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_Beau::
	trainerbattle_single TRAINER_SCIENTIST_BEAU, SilphCo_5F_Text_BeauIntro, SilphCo_5F_Text_BeauDefeat
	msgbox SilphCo_5F_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_28, SilphCo_5F_Text_Grunt1Intro, SilphCo_5F_Text_Grunt1Defeat
	msgbox SilphCo_5F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_29, SilphCo_5F_Text_Grunt2Intro, SilphCo_5F_Text_Grunt2Defeat
	msgbox SilphCo_5F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Dalton::
	trainerbattle_single TRAINER_JUGGLER_DALTON, SilphCo_5F_Text_DaltonIntro, SilphCo_5F_Text_DaltonDefeat
	msgbox SilphCo_5F_Text_DaltonPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_Text_RocketsInUproarAboutIntruder::
    .string "L'Equip Rocket està revolucionat\n"
    .string "per un intrús.\p"
    .string "Ets tu, oi?$"

SilphCo_5F_Text_YoureOurHeroThankYou::
    .string "L'Equip Rocket ha fugit!\n"
    .string "Ets el nostre heroi! Gràcies!$"

SilphCo_5F_Text_Grunt1Intro::
    .string "He sentit que un nen voltava\n"
    .string "per aquí.$"

SilphCo_5F_Text_Grunt1Defeat::
    .string "Bum!$"

SilphCo_5F_Text_Grunt1PostBattle::
    .string "No és intel·ligent buscar brega\n"
    .string "amb l'Equip Rocket!$"

SilphCo_5F_Text_BeauIntro::
    .string "Estudiem tecnologia de Poké Ball\n"
    .string "en aquest pis.$"

SilphCo_5F_Text_BeauDefeat::
    .string "Llamps!\n"
    .string "Maleït sigui!$"

SilphCo_5F_Text_BeauPostBattle::
    .string "Treballàvem en la Poké Ball\n"
    .string "definitiva que ho capturaria tot.$"

SilphCo_5F_Text_DaltonIntro::
    .string "Quèè?\p"
    .string "No hi hauria d'haver cap nen\n"
    .string "aquí!$"

SilphCo_5F_Text_DaltonDefeat::
    .string "Oh, mare meva!$"

SilphCo_5F_Text_DaltonPostBattle::
    .string "Només ets al 5è pis.\n"
    .string "Queda molt fins al meu Cap!$"

SilphCo_5F_Text_Grunt2Intro::
    .string "Mostra una mica de respecte\n"
    .string "per l'Equip Rocket!$"

SilphCo_5F_Text_Grunt2Defeat::
    .string "Tos…\n"
    .string "Tos…$"

SilphCo_5F_Text_Grunt2PostBattle::
    .string "Ara que ho penso.\p"
    .string "Koffing evoluciona a Weezing!$"

SilphCo_5F_Text_PorygonFirstVRMon::
    .string "És un Informe Pokémon!\p"
    .string "En casos rars, alguns Pokémon\n"
    .string "poden tenir habilitats diferents.$"

SilphCo_5F_Text_Over350TechniquesConfirmed::
    .string "És un Informe Pokémon!\p"
    .string "S'han confirmat més de 350\n"
    .string "tècniques Pokémon.$"

SilphCo_5F_Text_SomeMonsEvolveWhenTraded::
    .string "És un Informe Pokémon!\p"
    .string "S'ha confirmat que alguns Pokémon\n"
    .string "evolucionen en ser intercanviats.$"

SilphCo_5F_Text_FloorSign::
    .string "Seu Central de Silph S.A.\n"
    .string "5è pis$"

SilphCo_5F_EventScript_Scientist::
	lock
	faceplayer
	msgbox SilphCo_5F_Text_RocketBossLookingForStrongMons
	release
	end

SilphCo_5F_Text_RocketBossLookingForStrongMons::
    .string "Aquells brètols que han ocupat\n"
    .string "el nostre edifici…\p"
    .string "El seu Cap deia que buscava\n"
    .string "Pokémon forts.\p"
    .string "Espero que el nostre President\n"
    .string "hagi evitat problemes…$"

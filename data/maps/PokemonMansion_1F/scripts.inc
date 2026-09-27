PokemonMansion_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonMansion_1F_OnTransition
	.byte 0

PokemonMansion_1F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_1F
	end

PokemonMansion_1F_OnTransition::
	end

PokemonMansion_1F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 0
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_1F_EventScript_Ted::
	trainerbattle_single TRAINER_SCIENTIST_TED, PokemonMansion_1F_Text_TedIntro, PokemonMansion_1F_Text_TedDefeat
	msgbox PokemonMansion_1F_Text_TedPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_1F_Text_TedIntro::
    .string "Qui ets?\n"
    .string "Aquí no hi hauria de ser ningú.$"

PokemonMansion_1F_Text_TedDefeat::
    .string "Au!$"

PokemonMansion_1F_Text_TedPostBattle::
    .string "Una clau? No sé de què\n"
    .string "em parles.$"

PokemonMansion_1F_EventScript_Johnson::
	trainerbattle_single TRAINER_YOUNGSTER_JOHNSON, PokemonMansion_1F_Text_JohnsonIntro, PokemonMansion_1F_Text_JohnsonDefeat
	msgbox PokemonMansion_1F_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_1F_Text_JohnsonIntro::
    .string "A-a-aah! M'has espantat!\n"
    .string "Pensava que eres un fantasma.$"

PokemonMansion_1F_Text_JohnsonDefeat::
    .string "Tsc!\n"
    .string "No guanyo cap combat.$"

PokemonMansion_1F_Text_JohnsonPostBattle::
    .string "Estava explorant aquí sol,\n"
    .string "però tinc mala espina.\p"
    .string "Hauria de marxar aviat.$"

PokemonMansion_1F_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE, 1
	release
	end

PokemonMansion_1F_EventScript_ItemProtein::
	finditem ITEM_PROTEIN, 1
	release
	end

PokemonMansion_1F_EventScript_ItemCarbos::
	finditem ITEM_CARBOS, 1
	release
	end

PokemonMansion_1F_EventScript_ItemBlackSludge::
	finditem ITEM_BLACK_SLUDGE, 1
	release
	end

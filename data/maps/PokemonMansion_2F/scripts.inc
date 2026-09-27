PokemonMansion_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_2F_OnLoad
	.byte 0

PokemonMansion_2F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_2F
	end

PokemonMansion_2F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 1
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_2F_EventScript_DiaryJuly5th::
	msgbox PokemonMansion_1F_Text_NewMonDiscoveredInGuyanaJungle, MSGBOX_SIGN
	end

PokemonMansion_2F_EventScript_DiaryJuly10th::
	msgbox PokemonMansion_1F_Text_ChristenedDiscoveredMonMew, MSGBOX_SIGN
	end

PokemonMansion_2F_EventScript_Arnie::
	trainerbattle_single TRAINER_BURGLAR_ARNIE, PokemonMansion_1F_Text_ArnieIntro, PokemonMansion_1F_Text_ArnieDefeat
	msgbox PokemonMansion_1F_Text_ArniePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_Text_PressSecretSwitch::
    .string "Un interruptor secret!\p"
    .string "El prems?$"

PokemonMansion_Text_WhoWouldnt::
    .string "Qui no ho faria?$"

PokemonMansion_Text_NotQuiteYet::
    .string "Encara no!$"

PokemonMansion_1F_Text_ArnieIntro::
    .string "No puc sortir!\n"
    .string "Aquest lloc és un gran trencaclosques.$"

PokemonMansion_1F_Text_ArnieDefeat::
    .string "Oh, no!\n"
    .string "La meva bossa de botí!$"

PokemonMansion_1F_Text_ArniePostBattle::
    .string "Els interruptors d'aquí obren i\n"
    .string "tanquen grups alterns de portes.$"

PokemonMansion_1F_Text_NewMonDiscoveredInGuyanaJungle::
    .string "Diari: 5 de juliol\n"
    .string "Guaiana, Sud-amèrica\p"
    .string "S'ha descobert un nou Pokémon\n"
    .string "a les profunditats de la selva.$"

PokemonMansion_1F_Text_ChristenedDiscoveredMonMew::
    .string "Diari: 10 de juliol\n"
    .string "Hem batejat el Pokémon recentment\l"
    .string "descobert com a Mew.$"

PokemonMansion_2F_EventScript_ItemZinc::
	finditem ITEM_ZINC, 1
	release
	end

PokemonMansion_2F_EventScript_ItemHPUp::
	finditem ITEM_HP_UP, 1
	release
	end

PokemonMansion_2F_EventScript_ItemCalcium::
	finditem ITEM_CALCIUM, 1
	release
	end

PokemonMansion_2F_EventScript_CharizarditeX::
	finditem ITEM_CHARIZARDITE_X, 1
	release
	end


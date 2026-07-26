PokemonMansion_3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_3F_OnLoad
	.byte 0

PokemonMansion_3F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_3F
	end

PokemonMansion_3F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 2
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_3F_EventScript_DiaryFeb6th::
	msgbox PokemonMansion_1F_Text_MewGaveBirthToMewtwo, MSGBOX_SIGN
	end

PokemonMansion_3F_EventScript_Simon::
	trainerbattle_single TRAINER_BURGLAR_SIMON, PokemonMansion_1F_Text_SimonIntro, PokemonMansion_1F_Text_SimonDefeat
	msgbox PokemonMansion_1F_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_3F_EventScript_Braydon::
	trainerbattle_single TRAINER_SCIENTIST_BRAYDON, PokemonMansion_1F_Text_BraydonIntro, PokemonMansion_1F_Text_BraydonDefeat
	msgbox PokemonMansion_1F_Text_BraydonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_1F_Text_SimonIntro::
    .string "Aquest lloc és, com, enorme!$"

PokemonMansion_1F_Text_SimonDefeat::
    .string "Ai!$"

PokemonMansion_1F_Text_SimonPostBattle::
    .string "On deu haver anat el meu company?$"

PokemonMansion_1F_Text_BraydonIntro::
    .string "El meu mentor vivia aquí.$"

PokemonMansion_1F_Text_BraydonDefeat::
    .string "Uf!\n"
    .string "Aclaparant!$"

PokemonMansion_1F_Text_BraydonPostBattle::
    .string "Estàs encallat?\n"
    .string "Prova de saltar per allà!$"

PokemonMansion_1F_Text_MewGaveBirthToMewtwo::
    .string "Diari: 6 de febrer\n"
    .string "Mew ha donat a llum.\p"
    .string "Hem batejat el nadó com a Mewtwo.$"

PokemonMansion_3F_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION, 1
	release
	end

PokemonMansion_3F_EventScript_ItemIron::
	finditem ITEM_IRON, 1
	release
	end

PokemonMansion_3F_EventScript_ItemCharcoal::
	finditem ITEM_CHARCOAL, 1
	release
	end

PokemonMansion_3F_EventScript_CharizarditeY::
	finditem ITEM_CHARIZARDITE_Y, 1
	release
	end


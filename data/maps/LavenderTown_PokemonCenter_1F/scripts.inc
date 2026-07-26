.set LOCALID_NURSE, 1

LavenderTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_PokemonCenter_1F_OnTransition
	.byte 0

LavenderTown_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN
	end

LavenderTown_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

LavenderTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox LavenderTown_PokemonCenter_1F_Text_RocketsDoAnythingForMoney, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_1F_Text_RocketsDoAnythingForMoney::
    .string "L'Equip Rocket farà qualsevol\n"
    .string "cosa per diners!\p"
    .string "No hi ha feina massa bruta, ni\n"
    .string "acte massa vil, ni crim massa\l"
    .string "malvat!$"

LavenderTown_PokemonCenter_1F_EventScript_Lass::
	msgbox LavenderTown_PokemonCenter_1F_Text_CubonesMotherKilledByRockets, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_1F_Text_CubonesMotherKilledByRockets::
    .string "Vaig veure la mare d'un Cubone\n"
    .string "intentant escapar de l'Equip Rocket.\p"
    .string "La van matar mentre intentava fugir…$"

LavenderTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox LavenderTown_PokemonCenter_1F_Text_PeoplePayForCuboneSkulls, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_1F_Text_PeoplePayForCuboneSkulls::
    .string "Saps que l'espècie Cubone porta\n"
    .string "cranis, oi?\p"
    .string "La gent paga molt per un.$"

LavenderTown_PokemonCenter_1F_EventScript_BaldingMan::
	msgbox LavenderTown_PokemonCenter_1F_Text_HearMrFujiNotFromAroundHere, MSGBOX_NPC
	release
	end

LavenderTown_PokemonCenter_1F_Text_HearMrFujiNotFromAroundHere::
    .string "Fa poc que visc en aquesta ciutat.\p"
    .string "He sentit que el Sr. Fuji tampoc\n"
    .string "és d'aquí originalment.$"

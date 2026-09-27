.set LOCALID_NURSE, 1

ViridianCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_1F_OnTransition
	.byte 0

ViridianCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	end

ViridianCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

ViridianCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC::
    .string "No dubtis a usar el PC del racó.\p"
    .string "La recepcionista m'ho va dir.\n"
    .string "Que amable és!$"

ViridianCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons::
    .string "Els Centres Pokémon curen els teus\n"
    .string "Pokémon cansats, ferits o debilitats.\p"
    .string "Deixen tots els Pokémon\n"
    .string "completament sans.$"

ViridianCity_PokemonCenter_1F_EventScript_Boy::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown::
    .string "Hi ha un Centre Pokémon a cada\n"
    .string "poble d'ara endavant.\p"
    .string "No cobren diners, així que no\n"
    .string "tinguis vergonya de curar-los.$"

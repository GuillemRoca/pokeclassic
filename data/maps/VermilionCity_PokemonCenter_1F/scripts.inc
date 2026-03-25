.set LOCALID_NURSE, 1

VermilionCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_1F_OnTransition
	.byte 0

VermilionCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY
	end

VermilionCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

VermilionCity_PokemonCenter_1F_EventScript_Man::
	msgbox VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking::
    .string "El meu Pokémon estava enverinat!\n"
    .string "Va caure mentre caminàvem!$"

VermilionCity_PokemonCenter_1F_EventScript_Hiker::
	msgbox VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild::
    .string "Encara que siguin del mateix nivell,\n"
    .string "els Pokémon poden tenir\l"
    .string "estadístiques molt diferents.\p"
    .string "Un Pokémon criat per un entrenador\n"
    .string "és més fort que un salvatge.$"

VermilionCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes::
    .string "És cert que un Pokémon de nivell\n"
    .string "més alt serà més poderós…\p"
    .string "Però tots els Pokémon tindran\n"
    .string "punts febles contra certs tipus.\p"
    .string "Així que sembla que no hi ha cap\n"
    .string "Pokémon universalment fort.$"

VermilionCity_PokemonCenter_1F_EventScript_RematchWoman::
	msgbox VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain, MSGBOX_NPC
	release
	end

VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain::
    .string "Les ganes de combatre amb algú\n"
    .string "amb qui ja t'has enfrontat…\p"
    .string "Has tingut mai aquesta sensació?\n"
    .string "Segur que sí.\p"
    .string "Jo també volia combatre amb\n"
    .string "certes persones una i altra vegada.\p"
    .string "Hauria de trucar a uns entrenadors\n"
    .string "amb el meu Mòbil!$"

.set LOCALID_NURSE, 1

SaffronCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonCenter_1F_OnTransition
	.byte 0

SaffronCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_SAFFRON_CITY
	end

SaffronCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end


SaffronCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox SaffronCity_PokemonCenter_1F_Text_SilphCoVictimOfFame, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_1F_EventScript_Woman::
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SaffronCity_PokemonCenter_1F_EventScript_Woman2
	msgbox SaffronCity_PokemonCenter_1F_Text_RocketsUpstairs, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_1F_Text_RocketsUpstairs::
	.string "L'Equip Rocket és tan sospitós!\p"
	.string "Ens van deixar tranquils aquí baix\n"
	.string "mentre saquejen el segon pis!$"

SaffronCity_PokemonCenter_1F_EventScript_Woman2::
	msgbox SaffronCity_PokemonCenter_1F_Text_GrowthRatesDifferBySpecies, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_1F_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SaffronCity_PokemonCenter_1F_EventScript_YoungsterRocketsGone
	msgbox SaffronCity_PokemonCenter_1F_Text_GreatIfEliteFourCameBeatRockets
	release
	end

SaffronCity_PokemonCenter_1F_EventScript_YoungsterRocketsGone::
	msgbox SaffronCity_PokemonCenter_1F_Text_TeamRocketTookOff
	release
	end

SaffronCity_PokemonCenter_1F_Text_GrowthRatesDifferBySpecies::
    .string "El ritme de creixement dels\n"
    .string "Pokémon varia segons l'espècie.$"

SaffronCity_PokemonCenter_1F_Text_SilphCoVictimOfFame::
    .string "Silph S.A. és molt coneguda.\p"
    .string "És víctima de la seva pròpia\n"
    .string "fama: va atreure l'Equip Rocket.$"

SaffronCity_PokemonCenter_1F_Text_GreatIfEliteFourCameBeatRockets::
    .string "Ai…\n"
    .string "No seria genial?\p"
    .string "Si l'Alt Comandament vingués i\n"
    .string "aixafés l'Equip Rocket?$"

SaffronCity_PokemonCenter_1F_Text_TeamRocketTookOff::
    .string "L'Equip Rocket ha fugit!\n"
    .string "Podem sortir tranquils!\l"
    .string "Fantàstic!$"

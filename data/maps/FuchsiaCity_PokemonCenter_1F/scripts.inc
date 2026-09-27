.set LOCALID_NURSE, 1

FuchsiaCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_PokemonCenter_1F_OnTransition
	.byte 0

FuchsiaCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_FUCHSIA_CITY
	end

FuchsiaCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

FuchsiaCity_PokemonCenter_1F_EventScript_Man::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_CantBecomeGoodTrainerWithOneMon, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_Text_CantBecomeGoodTrainerWithOneMon::
    .string "No pots ser un bon Entrenador\n"
    .string "amb un sol Pokémon fort.\p"
    .string "Però criar molts Pokémon de forma\n"
    .string "equilibrada tampoc és fàcil.$"

FuchsiaCity_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_PokemonLeagueWestOfViridian, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_Text_PokemonLeagueWestOfViridian::
    .string "Hi ha un camí estret a l'oest\n"
    .string "de Ciutat Viridian.\p"
    .string "Porta a la Seu de la Lliga Pokémon.\n"
    .string "La Seu governa tots els Entrenadors.$"

FuchsiaCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_VisitSafariZoneForPokedex, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_Text_VisitSafariZoneForPokedex::
    .string "Si estàs treballant en la Pokédex,\n"
    .string "visita la Zona Safari.\p"
    .string "Tota mena de Pokémon rars\n"
    .string "es crien allà.$"

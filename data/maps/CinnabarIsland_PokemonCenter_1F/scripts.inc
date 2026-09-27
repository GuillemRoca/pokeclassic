.set LOCALID_NURSE, 1

CinnabarIsland_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_PokemonCenter_1F_OnTransition
	.byte 0

CinnabarIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_CINNABAR_ISLAND
	end

CinnabarIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

CinnabarIsland_PokemonCenter_1F_EventScript_Gentleman::
	msgbox CinnabarIsland_PokemonCenter_1F_Text_VisitUnionRoom, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox CinnabarIsland_PokemonCenter_1F_Text_CinnabarGymLocked, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter_1F_EventScript_Youngster::
	msgbox CinnabarIsland_PokemonCenter_1F_Text_EvolutionCanWaitForNewMoves, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter_1F_Text_CinnabarGymLocked::
    .string "L'amic del Líder del Gimnàs vivia\n"
    .string "en aquella mansió cremada.\p"
    .string "Almenys això diuen.$"

CinnabarIsland_PokemonCenter_1F_Text_VisitUnionRoom::
    .string "Tens molts amics?\p"
    .string "Fer-se gran pot ser solitari, així\n"
    .string "que és important provar coses noves\l"
    .string "de tant en tant.\p"
    .string "Qui sap, potser acabaràs fent\n"
    .string "nous amics.$"

CinnabarIsland_PokemonCenter_1F_Text_EvolutionCanWaitForNewMoves::
    .string "Els Pokémon poden aprendre\n"
    .string "tècniques després de cancel·lar\l"
    .string "l'evolució.\p"
    .string "L'evolució pot esperar fins que\n"
    .string "s'hagin après nous moviments.$"

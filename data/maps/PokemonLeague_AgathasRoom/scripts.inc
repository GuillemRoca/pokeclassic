PokemonLeague_AgathasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_AgathasRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_AgathasRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_AgathasRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_AgathasRoom_OnFrame
	.byte 0

PokemonLeague_AgathasRoom_OnResume::
	setvar VAR_0x8004, 2
	call PokemonLeague_EventScript_DoLightingEffect
	end

PokemonLeague_AgathasRoom_OnLoad::
	call_if_set FLAG_DEFEATED_AGATHA, PokemonLeague_AgathasRoom_EventScript_SetDoorOpen
	compare VAR_ELITE_4_STATE, 3
	call_if_eq PokemonLeague_AgathasRoom_EventScript_CloseEntry
	end

PokemonLeague_AgathasRoom_EventScript_CloseEntry::
	call PokemonLeague_EventScript_CloseEntry
	return

PokemonLeague_AgathasRoom_EventScript_SetDoorOpen::
	call PokemonLeague_EventScript_SetDoorOpen
	return

PokemonLeague_AgathasRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_AgathasRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_AgathasRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PokemonLeague_AgathasRoom_OnFrame::
	map_script_2 VAR_ELITE_4_STATE, 2, PokemonLeague_AgathasRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_AgathasRoom_EventScript_EnterRoom::
	lockall
	call PokemonLeague_EventScript_EnterRoom
	setvar VAR_ELITE_4_STATE, 3
	releaseall
	end

PokemonLeague_AgathasRoom_EventScript_Agatha::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_AGATHA, PokemonLeague_AgathasRoom_EventScript_PostBattle
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_AgathasRoom_EventScript_AgathaPostgame
	msgbox PokemonLeague_AgathasRoom_Text_Intro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_ELITE_FOUR_AGATHA, PokemonLeague_AgathasRoom_Text_Defeat
	clearflag FLAG_TEMP_5
	goto PokemonLeague_AgathasRoom_EventScript_DefeatedAgatha
	end

PokemonLeague_AgathasRoom_EventScript_AgathaPostgame::
	msgbox PokemonLeague_AgathasRoom_Text_Intro2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro POSTGAME_ELITE_FOUR_AGATHA, PokemonLeague_AgathasRoom_Text_Defeat2
	clearflag FLAG_TEMP_5
	goto PokemonLeague_AgathasRoom_EventScript_DefeatedAgatha
	end

PokemonLeague_AgathasRoom_EventScript_DefeatedAgatha::
	setflag FLAG_DEFEATED_AGATHA
	call PokemonLeague_EventScript_OpenDoor
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_AgathasRoom_EventScript_PostBattle2
	msgbox PokemonLeague_AgathasRoom_Text_PostBattle
	release
	end

PokemonLeague_AgathasRoom_EventScript_PostBattle::
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_AgathasRoom_EventScript_PostBattle2
	msgbox PokemonLeague_AgathasRoom_Text_PostBattle
	release
	end

PokemonLeague_AgathasRoom_EventScript_PostBattle2::
	msgbox PokemonLeague_AgathasRoom_Text_PostBattle2
	release
	end

PokemonLeague_AgathasRoom_Text_Intro::
    .string "Sóc l'Agatha de l'Alt Comandament.\p"
    .string "He sentit que l'Oak s'ha interessat\n"
    .string "molt per tu, nen.\p"
    .string "Aquell vell tòtil va ser dur i\n"
    .string "atractiu en el seu dia.\p"
    .string "Però això va ser fa dècades.\n"
    .string "Ara és l'ombra del que va ser.\p"
    .string "Ara només vol trastegar amb\n"
    .string "la seva Pokédex.\p"
    .string "S'equivoca.\n"
    .string "Els Pokémon són per combatre!\p"
    .string "{PLAYER}! Et mostraré com\n"
    .string "lluita un entrenador de debò!$"

PokemonLeague_AgathasRoom_Text_Intro2::
    .string "Així que has vingut!\p"
    .string "No és propi de mi perdre\n"
    .string "una vegada rere l'altra.\p"
    .string "Dóna-ho tot en aquest combat!$"

PokemonLeague_AgathasRoom_Text_Defeat::
    .string "Oh, vaja!\n"
    .string "Ets algú especial, nen!$"

PokemonLeague_AgathasRoom_Text_Defeat2::
    .string "No està malament!$"

PokemonLeague_AgathasRoom_Text_PostBattle::
    .string "Has guanyat!\p"
    .string "Ara veig què hi veu aquell\n"
    .string "vell tòtil en tu.\p"
    .string "No tinc res més a dir.\n"
    .string "Corre, nen!$"

PokemonLeague_AgathasRoom_Text_PostBattle2::
    .string "No és estrany que aquell vell\n"
    .string "s'hagi interessat tant per tu.\p"
    .string "L'Oak i jo vam ser bons rivals\n"
    .string "també, saps. Com tu i {RIVAL}.\p"
    .string "Bé, a què esperes?\n"
    .string "Vés a la següent sala!$"

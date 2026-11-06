.set LOCALID_BRUNO, 1

PokemonLeague_BrunosRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_BrunosRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_BrunosRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_BrunosRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_BrunosRoom_OnFrame
	.byte 0

PokemonLeague_BrunosRoom_OnResume::
	setvar VAR_0x8004, 1
	call PokemonLeague_EventScript_DoLightingEffect
	end

PokemonLeague_BrunosRoom_OnLoad::
	call_if_set FLAG_DEFEATED_BRUNO, PokemonLeague_BrunosRoom_EventScript_SetDoorOpen
	compare VAR_ELITE_4_STATE, 2
	call_if_eq PokemonLeague_BrunosRoom_EventScript_CloseEntry
	end

PokemonLeague_BrunosRoom_EventScript_CloseEntry::
	call PokemonLeague_EventScript_CloseEntry
	return

PokemonLeague_BrunosRoom_EventScript_SetDoorOpen::
	call PokemonLeague_EventScript_SetDoorOpen
	return

PokemonLeague_BrunosRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_BrunosRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_BrunosRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PokemonLeague_BrunosRoom_OnFrame::
	map_script_2 VAR_ELITE_4_STATE, 1, PokemonLeague_BrunosRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_BrunosRoom_EventScript_EnterRoom::
	lockall
	call PokemonLeague_EventScript_EnterRoom
	setvar VAR_ELITE_4_STATE, 2
	releaseall
	end

PokemonLeague_BrunosRoom_EventScript_Bruno::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_BRUNO, PokemonLeague_BrunosRoom_EventScript_PostBattle
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_BrunosRoom_EventScript_BrunoPostgame
	msgbox PokemonLeague_BrunosRoom_Text_Intro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_ELITE_FOUR_BRUNO, PokemonLeague_BrunosRoom_Text_Defeat
	clearflag FLAG_TEMP_5
	goto PokemonLeague_BrunosRoom_EventScript_DefeatedBruno
	end

PokemonLeague_BrunosRoom_EventScript_BrunoPostgame::
	msgbox PokemonLeague_BrunosRoom_Text_Intro2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro POSTGAME_ELITE_FOUR_BRUNO, PokemonLeague_BrunosRoom_Text_Defeat2
	clearflag FLAG_TEMP_5
	goto PokemonLeague_BrunosRoom_EventScript_DefeatedBruno
	end

PokemonLeague_BrunosRoom_EventScript_DefeatedBruno::
	setflag FLAG_DEFEATED_BRUNO
	call PokemonLeague_EventScript_OpenDoor
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_BrunosRoom_EventScript_PostBattle2
	msgbox PokemonLeague_BrunosRoom_Text_PostBattle
	closemessage
	goto PokemonLeague_BrunosRoom_EventScript_BrunoLookAway
	end

PokemonLeague_BrunosRoom_EventScript_PostBattle::
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_BrunosRoom_EventScript_PostBattle2
	msgbox PokemonLeague_BrunosRoom_Text_PostBattle
	closemessage
	goto PokemonLeague_BrunosRoom_EventScript_BrunoLookAway
	end

PokemonLeague_BrunosRoom_EventScript_PostBattle2::
	msgbox PokemonLeague_BrunosRoom_Text_PostBattle2
	closemessage
	goto PokemonLeague_BrunosRoom_EventScript_BrunoLookAway
	end

PokemonLeague_BrunosRoom_EventScript_BrunoLookAway::
	call_if_eq VAR_FACING, DIR_NORTH, PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayRight
	call_if_eq VAR_FACING, DIR_SOUTH, PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayLeft
	call_if_eq VAR_FACING, DIR_WEST, PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayDown
	call_if_eq VAR_FACING, DIR_EAST, PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayDown
	release
	end

PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayLeft::
	applymovement LOCALID_BRUNO, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 1
	return

PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayRight::
	applymovement LOCALID_BRUNO, Common_Movement_WalkInPlaceFasterRight
	waitmovement 1
	return

PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayDown::
	applymovement LOCALID_BRUNO, Common_Movement_WalkInPlaceFasterDown
	waitmovement 1
	return

PokemonLeague_BrunosRoom_Text_Intro::
    .string "Soc en Bruno de l'Alt Comandament!\p"
    .string "Amb un entrenament rigorós,\n"
    .string "les persones i els Pokémon poden\l"
    .string "fer-se més forts sense límit.\p"
    .string "He viscut i entrenat amb els meus\n"
    .string "Pokémon de lluita!\l"
    .string "I això mai canviarà!\p"
    .string "{PLAYER}!\p"
    .string "T'aixafarem amb el nostre\n"
    .string "poder superior!\p"
    .string "Hu ha!$"

PokemonLeague_BrunosRoom_Text_Intro2::
    .string "He pogut sentir la intensitat del\n"
    .string "teu combat amb la Lorelei des\l"
    .string "d'aquí!\p"
    .string "Ara és el moment de mostrar-te\n"
    .string "el poder dels meus Pokémon de\l"
    .string "tipus Lluita, que he entrenat\l"
    .string "tan dur com tu el teu equip!\p"
    .string "Hu ha! Hu! HA!!!$"

PokemonLeague_BrunosRoom_Text_Defeat::
    .string "Per què?\n"
    .string "Com he pogut perdre?$"

PokemonLeague_BrunosRoom_Text_Defeat2::
    .string "Me'n penedeixo!$"

PokemonLeague_BrunosRoom_Text_PostBattle::
    .string "La meva feina s'ha acabat.\n"
    .string "Vés a afrontar el proper repte.$"

PokemonLeague_BrunosRoom_Text_PostBattle2::
    .string "Ugh! No! Així que el meu\n"
    .string "entrenament encara no és prou?\p"
    .string "...Vés.\p"
    .string "No et preocupis per mi.\n"
    .string "Continua endavant!$"

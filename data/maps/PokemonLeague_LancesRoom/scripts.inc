.set LOCALID_LANCE, 1

PokemonLeague_LancesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_LancesRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_LancesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_LancesRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_LancesRoom_OnFrame
	.byte 0

PokemonLeague_LancesRoom_OnResume::
	setvar VAR_0x8004, 3
	call PokemonLeague_EventScript_DoLightingEffect
	end

PokemonLeague_LancesRoom_OnLoad::
	compare VAR_ELITE_4_STATE, 4
	call_if_eq PokemonLeague_LancesRoom_EventScript_CloseEntry
	call_if_set FLAG_DEFEATED_LANCE, PokemonLeague_LancesRoom_EventScript_SetDoorOpen
	end

PokemonLeague_LancesRoom_EventScript_CloseEntry::
	call PokemonLeague_LancesRoom_EventScript_SetEntryClosed
	return

PokemonLeague_LancesRoom_EventScript_SetDoorOpen::
	call PokemonLeague_EventScript_SetDoorOpenLance
	return

PokemonLeague_LancesRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_LancesRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_LancesRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PokemonLeague_LancesRoom_OnFrame::
	map_script_2 VAR_ELITE_4_STATE, 3, PokemonLeague_LancesRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_LancesRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_LancesRoom_Movement_WalkThroughCorridor
	waitmovement 0
	setflag FLAG_TEMP_2
	call PokemonLeague_LancesRoom_EventScript_SetEntryClosed
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

PokemonLeague_LancesRoom_EventScript_SetEntryClosed::
	setmetatile 5, 14, METATILE_PokemonLeague_Entry_TopLeft_Closed, 1
	setmetatile 6, 14, METATILE_PokemonLeague_Entry_TopMid_Closed, 1
	setmetatile 7, 14, METATILE_PokemonLeague_Entry_TopRight_Closed, 1
	setmetatile 5, 15, METATILE_PokemonLeague_Entry_BottomLeft_Closed, 1
	setmetatile 6, 15, METATILE_PokemonLeague_Entry_BottomMid_Closed, 1
	setmetatile 7, 15, METATILE_PokemonLeague_Entry_BottomRight_Closed, 1
	setmetatile 6, 16, METATILE_PokemonLeague_Floor_ShadeFull_Lance, 0
	setmetatile 7, 16, METATILE_PokemonLeague_Floor_ShadeFull_Lance, 0
	return

PokemonLeague_LancesRoom_Movement_WalkThroughCorridor::
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_LancesRoom_EventScript_Lance::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LANCE, PokemonLeague_LancesRoom_EventScript_PostBattle
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_LancesRoom_EventScript_LancePostgame
	msgbox PokemonLeague_LancesRoom_Text_Intro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_ELITE_FOUR_LANCE, PokemonLeague_LancesRoom_Text_Defeat
	setdynamicwarp MAP_POKEMON_LEAGUE_CHAMPIONS_ROOM, 6, 19
	clearflag FLAG_TEMP_5
	goto PokemonLeague_LancesRoom_EventScript_DefeatedLance
	end

PokemonLeague_LancesRoom_EventScript_LancePostgame::
	msgbox PokemonLeague_LancesRoom_Text_Intro2

	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro POSTGAME_ELITE_FOUR_LANCE, PokemonLeague_LancesRoom_Text_Defeat2
	clearflag FLAG_TEMP_5
	setdynamicwarp MAP_POKEMON_LEAGUE_SECRET_BATTLE, 6, 19
	goto PokemonLeague_LancesRoom_EventScript_DefeatedLance
	end

PokemonLeague_LancesRoom_EventScript_DefeatedLance::
	setvar VAR_0x8004, 0
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_LANCE
	call PokemonLeague_EventScript_OpenDoorLance
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_LancesRoom_EventScript_PostBattle2
	msgbox PokemonLeague_LancesRoom_Text_PostBattle
	closemessage
	release
	end

PokemonLeague_LancesRoom_EventScript_PostBattle::
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_LancesRoom_EventScript_PostBattle2
	msgbox PokemonLeague_LancesRoom_Text_PostBattle
	release
	end

PokemonLeague_LancesRoom_EventScript_PostBattle2::
	msgbox PokemonLeague_LancesRoom_Text_PostBattle2
	release
	end

PokemonLeague_LancesRoom_Text_Intro::
    .string "Ah! He sentit parlar de tu,\n"
    .string "{PLAYER}!\p"
    .string "Lidero l'Alt Comandament.\p"
    .string "Pots dir-me Lance, el mestre\n"
    .string "dels dracs.\p"
    .string "Ja saps que els dracs són\n"
    .string "Pokémon mítics.\p"
    .string "Són difícils de capturar i criar,\n"
    .string "però els seus poders són superiors.\p"
    .string "Són pràcticament indestructibles.\n"
    .string "No serveix de res ser astut.\p"
    .string "Bé, estàs preparat per perdre?\p"
    .string "El teu desafiament a la Lliga\n"
    .string "acaba amb mi, {PLAYER}!$"

PokemonLeague_LancesRoom_Text_Intro2::
    .string "M'alegro que hagis vingut.\p"
    .string "La reputació de la Lliga Pokémon\n"
    .string "ha crescut molt!\p"
    .string "Tot gràcies a tu.\p"
    .string "Em faria vergonya dir-me Lance\n"
    .string "l'Entrenador de Dracs si no et\l"
    .string "desafiés a un combat!$"

PokemonLeague_LancesRoom_Text_Defeat::
    .string "Ja està!\p"
    .string "Em costa admetre-ho, però ets\n"
    .string "un mestre Pokémon!$"

PokemonLeague_LancesRoom_Text_Defeat2::
    .string "Com he pogut ser empès\n"
    .string "fins a aquest punt?$"

PokemonLeague_LancesRoom_Text_PostBattle::
    .string "Encara no puc creure que els meus\n"
    .string "dracs hagin perdut, {PLAYER}.\p"
    .string "Ara ets el Campió de la Lliga\n"
    .string "Pokémon!\p"
    .string "…O ho series, però encara\n"
    .string "et queda un repte més.\p"
    .string "Hi ha un entrenador més!\n"
    .string "Es diu…\p"
    .string "{RIVAL}!\p"
    .string "Va derrotar l'Alt Comandament\n"
    .string "abans que tu.\p"
    .string "Ell és el veritable Campió de\n"
    .string "la Lliga Pokémon.$"

PokemonLeague_LancesRoom_Text_PostBattle2::
    .string "La meva brigada de dracs no és\n"
    .string "feble.\p"
    .string "...El que vull dir és que la teva\n"
    .string "força és realment increïble!\p"
    .string "Ara, {PLAYER}!\p"
    .string "Has derrotat l'Alt Comandament\n"
    .string "un cop més, però un últim repte\l"
    .string "t'espera!\p"
    .string "Hem preparat un desafiament\n"
    .string "especial per a tu, Campió!$"

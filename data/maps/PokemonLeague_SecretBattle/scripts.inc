.equ LOCALID_PROF_OAK, 1

PokemonLeague_SecretBattle_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_SecretBattle_OnWarp
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_SecretBattle_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_SecretBattle_OnFrame
	.byte 0

PokemonLeague_SecretBattle_OnResume::
	setvar VAR_0x8004, 4
	call PokemonLeague_EventScript_DoLightingEffect
	call PokemonLeague_SecretBattle_EventScript_CheckStopTrigger
	end

PokemonLeague_SecretBattle_EventScript_CheckStopTrigger::
	goto_if_defeated SECRET_BATTLE_OAK, PokemonLeague_SecretBattle_EventScript_StopSceneTrigger
	return

PokemonLeague_SecretBattle_EventScript_StopSceneTrigger::
	setvar VAR_TEMP_1, 1
	return

PokemonLeague_SecretBattle_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_SecretBattle_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_SecretBattle_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PokemonLeague_SecretBattle_OnFrame::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_SecretBattle_EventScript_EnterRoom
	.2byte 0

PokemonLeague_SecretBattle_EventScript_EnterRoom::
	lockall
	setflag FLAG_TEMP_2
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_SecretBattle_Movement_PlayerEnter
	waitmovement 0
	delay 20
	turnobject LOCALID_PROF_OAK, DIR_SOUTH
	msgbox PokemonLeague_SecretBattle_Text_Intro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	savebgm MUS_RG_VICTORY_GYM_LEADER
	trainerbattle_no_intro SECRET_BATTLE_OAK, PokemonLeague_SecretBattle_Text_Defeat
	setflag FLAG_TEMP_4
	clearflag FLAG_TEMP_5
	setflag FLAG_CLEARED_SECRET_BATTLE
	call_if_unset FLAG_REVEALED_MEGA_STONES, Postgame_RevealMegaStones
	setflag FLAG_DEFEATED_SECRET_BATTLE
	setflag FLAG_TEMP_4
	playbgm MUS_RG_SLOW_PALLET, 0
	msgbox PokemonLeague_SecretBattle_Text_PostBattle
	closemessage
	applymovement LOCALID_PROF_OAK, PokemonLeague_SecretBattle_Movement_OakExit
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_SecretBattle_Movement_PlayerExit
	waitmovement 0
	setvar VAR_TEMP_1, 1
	warp MAP_POKEMON_LEAGUE_HALL_OF_FAME, 255, 5, 12
	waitstate
	releaseall
	end

Postgame_RevealMegaStones::
	clearflag FLAG_HIDE_VENUSAURITE
	clearflag FLAG_HIDE_CHARIZARDITE_X
	clearflag FLAG_HIDE_CHARIZARDITE_Y
	clearflag FLAG_HIDE_BLASTOISINTE
	clearflag FLAG_HIDE_BEEDRILLITE
	clearflag FLAG_HIDE_PIDEGOTITE
	clearflag FLAG_HIDE_ALAKAZITE
	clearflag FLAG_HIDE_SLOWBRONITE
	clearflag FLAG_HIDE_GENGARITE
	clearflag FLAG_HIDE_KANGASKHANITE
	clearflag FLAG_HIDE_PINSIRITE
	clearflag FLAG_HIDE_GYARDOSITE
	clearflag FLAG_HIDE_AERODACTYLITE
	clearflag FLAG_HIDE_MEWTONITE_Y
	clearflag FLAG_HIDE_MEWTONITE_X
	clearflag FLAG_HIDE_PALLET_BILL
	setflag FLAG_REVEALED_MEGA_STONES
	setvar VAR_SECRET_BATTLE_CLEAR, 1
	return

PokemonLeague_SecretBattle_Movement_PlayerEnter::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_SecretBattle_Movement_PlayerExit::
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

PokemonLeague_SecretBattle_Movement_OakExit::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

PokemonLeague_SecretBattle_Text_Intro::
    .string "Oak: Hola, {PLAYER}!\p"
    .string "Tenia ganes de veure't.\p"
    .string "Fa molt de temps, era un\n"
    .string "entrenador com tu i {RIVAL}.\p"
    .string "Veure't treballar amb la Pokédex\n"
    .string "m'ha recordat per què em vaig\l"
    .string "fascinar pels Pokémon.\p"
    .string "He pogut veure com tu i {RIVAL}\n"
    .string "us heu fet més forts i heu creat\l"
    .string "vincles amb els vostres Pokémon.\p"
    .string "Fins i tot t'has convertit en\n"
    .string "Campió de la Lliga!\p"
    .string "Saps, l'Agatha i jo érem molt\n"
    .string "com tu i {RIVAL} en el nostre\l"
    .string "temps.\p"
    .string "Fa molt que no dic això\n"
    .string "a ningú...\p"
    .string "Et desafio a un combat Pokémon!$"

PokemonLeague_SecretBattle_Text_Defeat::
    .string "Meravellós!\p"
    .string "Simplement meravellós!$"

PokemonLeague_SecretBattle_Text_PostBattle::
    .string "{PLAYER}...\n"
    .string "Ets realment impressionant!\p"
    .string "Sens dubte mereixes el títol\n"
    .string "de Campió de la Lliga Pokémon!\p"
    .string "Vine amb mi!$"

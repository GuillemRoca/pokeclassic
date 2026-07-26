.equ LOCALID_RIVAL,    1
.equ LOCALID_PROF_OAK, 2

PokemonLeague_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_ChampionsRoom_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_ChampionsRoom_OnFrame
	.byte 0

PokemonLeague_ChampionsRoom_OnResume::
	setvar VAR_0x8004, 4
	call PokemonLeague_EventScript_DoLightingEffect
	call_if_eq VAR_RIVAL_WINRATE, 2, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerJolteon
	call_if_eq VAR_RIVAL_WINRATE, 1, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerFlareon
	call_if_eq VAR_RIVAL_WINRATE, 0, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerVaporeon
	end

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerJolteon::
	goto_if_defeated TRAINER_RIVAL_CHAMPION_JOLTEON, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerFlareon::
	goto_if_defeated TRAINER_RIVAL_CHAMPION_FLAREON, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerVaporeon::
	goto_if_defeated TRAINER_RIVAL_CHAMPION_VAPOREON, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger::
	setvar VAR_TEMP_1, 1
	return

PokemonLeague_ChampionsRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_ChampionsRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_ChampionsRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PokemonLeague_ChampionsRoom_OnFrame::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_ChampionsRoom_EventScript_EnterRoom::
	lockall
	setflag FLAG_TEMP_2
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerEnter
	waitmovement 0
	delay 20
	msgbox PokemonLeague_ChampionsRoom_Text_Intro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	savebgm MUS_RG_VICTORY_GYM_LEADER
	call PokemonLeague_ChampionsRoom_EventScript_Battle
	setflag FLAG_TEMP_4
	clearflag FLAG_TEMP_5
	setflag FLAG_DEFEATED_RIVAL_CHAMPION
	setflag FLAG_TEMP_4
	msgbox PokemonLeague_ChampionsRoom_Text_PostBattle
	playbgm MUS_RG_SLOW_PALLET, 0
	addobject LOCALID_PROF_OAK
	msgbox PokemonLeague_ChampionsRoom_Text_OakPlayer
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerWatchOakEnter
	applymovement LOCALID_RIVAL, PokemonLeague_ChampionsRoom_Movement_RivalWatchOakEnter
	applymovement LOCALID_PROF_OAK, PokemonLeague_ChampionsRoom_Movement_OakEnter
	waitmovement 0
	delay 25
	msgbox PokemonLeague_ChampionsRoom_Text_OakCongratulations
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_OakImDisappointedRival
	closemessage
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 20
	msgbox PokemonLeague_ChampionsRoom_Text_OakPlayerComeWithMe
	closemessage
	delay 13
	applymovement LOCALID_PROF_OAK, PokemonLeague_ChampionsRoom_Movement_OakExit
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setvar VAR_TEMP_1, 1
	warp MAP_POKEMON_LEAGUE_HALL_OF_FAME, 255, 5, 12
	waitstate
	releaseall
	end

PokemonLeague_ChampionsRoom_EventScript_Battle::
	call_if_eq VAR_RIVAL_WINRATE, 2, PokemonLeague_ChampionsRoom_EventScript_BattleJolteon
	call_if_eq VAR_RIVAL_WINRATE, 1, PokemonLeague_ChampionsRoom_EventScript_BattleFlareon
	call_if_eq VAR_RIVAL_WINRATE, 0, PokemonLeague_ChampionsRoom_EventScript_BattleVaporeon
	return

PokemonLeague_ChampionsRoom_EventScript_BattleJolteon::
	trainerbattle_no_intro TRAINER_RIVAL_CHAMPION_JOLTEON, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_BattleFlareon::
	trainerbattle_no_intro TRAINER_RIVAL_CHAMPION_FLAREON, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_BattleVaporeon::
	trainerbattle_no_intro TRAINER_RIVAL_CHAMPION_VAPOREON, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_Movement_PlayerEnter::
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

PokemonLeague_ChampionsRoom_Movement_PlayerExit::
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerWatchOakEnter::
	delay_8
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

PokemonLeague_ChampionsRoom_Movement_OakEnter::
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_in_place_faster_down
	delay_16
	step_end

PokemonLeague_ChampionsRoom_Movement_OakExit::
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

PokemonLeague_ChampionsRoom_Movement_RivalWatchOakEnter::
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end


PokemonLeague_ChampionsRoom_Text_Intro::
    .string "{RIVAL}: Ei, {PLAYER}!\p"
    .string "Tenia ganes de veure't,\n"
    .string "{PLAYER}.\p"
    .string "El meu rival ha de ser fort\n"
    .string "per mantenir-me en forma.\p"
    .string "Mentre treballava amb la Pokédex,\n"
    .string "vaig buscar Pokémon per tot arreu.\p"
    .string "A més, vaig muntar equips\n"
    .string "per guanyar qualsevol tipus.\p"
    .string "I ara…\p"
    .string "Sóc el Campió de la Lliga Pokémon!\p"
    .string "{PLAYER}!\n"
    .string "Saps què vol dir això?\p"
    .string "T'ho diré.\p"
    .string "Sóc l'entrenador més poderós\n"
    .string "del món!$"

PokemonLeague_ChampionsRoom_Text_Defeat::
    .string "NO!\n"
    .string "No pot ser!\l"
    .string "M'has guanyat al meu millor!\p"
    .string "Després de tota la feina per\n"
    .string "ser Campió de la Lliga?\p"
    .string "El meu regnat ja s'ha acabat?\n"
    .string "No és just!$"

PokemonLeague_ChampionsRoom_Text_PostBattle::
    .string "Per què?\n"
    .string "Per què he perdut?\p"
    .string "No vaig cometre cap error criant\n"
    .string "els meus Pokémon…\p"
    .string "Maleït! Ets el nou Campió de\n"
    .string "la Lliga Pokémon!\p"
    .string "Tot i que no m'agrada admetre-ho…$"

PokemonLeague_ChampionsRoom_Text_OakPlayer::
    .string "Oak: {PLAYER}!$"

PokemonLeague_ChampionsRoom_Text_OakCongratulations::
    .string "Oak: Així que has guanyat!\n"
    .string "Sincerament, felicitats!\p"
    .string "Ets el nou Campió de la Lliga\n"
    .string "Pokémon!\p"
    .string "Has crescut molt des que vas\n"
    .string "marxar amb Pikachu per treballar\l"
    .string "amb la Pokédex.\p"
    .string "{PLAYER}, t'has fet gran!$"

PokemonLeague_ChampionsRoom_Text_OakImDisappointedRival::
    .string "Oak: {RIVAL}…\n"
    .string "Estic decebut amb tu.\p"
    .string "He vingut quan he sabut que\n"
    .string "havies derrotat l'Alt Comandament.\p"
    .string "Però, quan he arribat, ja\n"
    .string "havies perdut!\p"
    .string "{RIVAL}, entens per què\n"
    .string "has perdut?\p"
    .string "Has oblidat tractar els teus\n"
    .string "Pokémon amb amor i confiança.\p"
    .string "Sense això, mai tornaràs\n"
    .string "a ser Campió!$"

PokemonLeague_ChampionsRoom_Text_OakPlayerComeWithMe::
    .string "Oak: {PLAYER}.\p"
    .string "Entens que la teva victòria\n"
    .string "no ha estat només mèrit teu.\p"
    .string "El vincle que comparteixes amb\n"
    .string "els teus Pokémon és meravellós.\p"
    .string "{PLAYER}!\n"
    .string "Vine amb mi!$"

.set LOCALID_NURSE, 1
.set LOCALID_GUARD, 5

IndigoPlateau_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_PokemonCenter_1F_OnTransition
	.byte 0

IndigoPlateau_PokemonCenter_1F_OnTransition::
	setflag FLAG_VISITED_INDIGO_PLATEAU
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

IndigoPlateau_PokemonCenter_1F_EventScript_GymGuy::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_GymGuyAdvice, MSGBOX_NPC
	end

IndigoPlateau_PokemonCenter_1F_Text_GymGuyAdvice::
    .string "Ei!\n"
    .string "Futur Campió!\p"
    .string "A la Lliga Pokémon, t'enfrontaràs\n"
    .string "a l'Alt Comandament seguit.\p"
    .string "Si perds, hauràs de tornar\n"
    .string "a començar des de zero!\p"
    .string "Ara és el moment!\n"
    .string "Endavant!$"

IndigoPlateau_PokemonCenter_1F_EventScript_DoorGuard::
    lock
    faceplayer
    goto_if_unset FLAG_SYS_GAME_CLEAR, IndigoPlateau_PokemonCenter_1F_EventScript_EliteFourFirstChallenge
    msgbox IndigoPlateau_PokemonCenter_1F_Text_GreetingsChampion, MSGBOX_NPC
    goto_if_unset FLAG_DAILY_TITLE_MATCH, IndigoPlateau_PokemonCenter_1F_EventScript_TitleMatch
    goto IndigoPlateau_PokemonCenter_1F_EventScript_EliteFourPostGame
    end

IndigoPlateau_PokemonCenter_1F_Text_GreetingsChampion::
	.string "Hola, Campió {PLAYER}!$"

IndigoPlateau_PokemonCenter_1F_EventScript_TitleMatch::
	playse SE_PIN
	applymovement LOCALID_GUARD, Common_Movement_ExclamationMark
	waitmovement 5
	msgbox IndigoPlateau_PokemonCenter_1F_Text_Challenger, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, IndigoPlateau_PokemonCenter_1F_EventScript_Decline
	setflag FLAG_DAILY_TITLE_MATCH
	setvar VAR_TITLE_MATCH_OPPONENT, 0
	addvar VAR_TITLE_MATCHES, 1
	call ClearTitleMatches
	msgbox IndigoPlateau_PokemonCenter_1F_Text_ExcellentGoodLuck, MSGBOX_DEFAULT
    goto IndigoPlateau_PokemonCenter_1F_EventScript_EnterEliteFour
    end

ClearTitleMatches::
	cleartrainerflag TITLE_MATCH_STEPH
	cleartrainerflag TITLE_MATCH_LIZ
	cleartrainerflag TITLE_MATCH_MIKE
	cleartrainerflag TITLE_MATCH_CHRIS
	cleartrainerflag TITLE_MATCH_KEV
	cleartrainerflag TITLE_MATCH_MEGHAN
	cleartrainerflag TITLE_MATCH_STEVE
	cleartrainerflag TITLE_MATCH_M
	cleartrainerflag TITLE_MATCH_BEAN
	cleartrainerflag TITLE_MATCH_ANNIE
	cleartrainerflag TITLE_MATCH_BROCK
	cleartrainerflag TITLE_MATCH_MISTY
	cleartrainerflag TITLE_MATCH_SURGE
	cleartrainerflag TITLE_MATCH_ERIKA
	cleartrainerflag TITLE_MATCH_SABRINA
	cleartrainerflag TITLE_MATCH_KOGA
	cleartrainerflag TITLE_MATCH_BLAINE
	cleartrainerflag TITLE_MATCH_ROCKET
	cleartrainerflag TITLE_MATCH_DAISY
	cleartrainerflag TITLE_MATCH_RIVAL_VAPOREON
	cleartrainerflag TITLE_MATCH_RIVAL_JOLTEON
	cleartrainerflag TITLE_MATCH_RIVAL_FLAREON
	return

IndigoPlateau_PokemonCenter_1F_EventScript_EliteFourPostGame::
    msgbox IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourPostGame, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, IndigoPlateau_PokemonCenter_1F_EventScript_Decline
    msgbox IndigoPlateau_PokemonCenter_1F_Text_ExcellentGoodLuck, MSGBOX_DEFAULT
    setvar VAR_ELITE_4_MODE, 2
    goto IndigoPlateau_PokemonCenter_1F_EventScript_EnterEliteFour
    end

IndigoPlateau_PokemonCenter_1F_Text_Challenger::
	.string "Oh! Sembla que algú ha derrotat\n"
	.string "l'Alt Comandament avui.\p"
	.string "Et desafien a un Combat pel Títol!\n"
	.string "Ets aquí per acceptar el repte?$"

IndigoPlateau_PokemonCenter_1F_EventScript_EliteFourFirstChallenge::
    msgbox IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFour, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, IndigoPlateau_PokemonCenter_1F_EventScript_Decline
    msgbox IndigoPlateau_PokemonCenter_1F_Text_ExcellentGoodLuck, MSGBOX_DEFAULT
    setvar VAR_ELITE_4_MODE, 1
    goto IndigoPlateau_PokemonCenter_1F_EventScript_EnterEliteFour
    end

IndigoPlateau_PokemonCenter_1F_EventScript_EnterEliteFour::
	call_if_eq VAR_FACING, DIR_NORTH, IndigoPlateau_PokemonCenter_1F_EventScript_EnterNorth
	call_if_eq VAR_FACING, DIR_WEST, IndigoPlateau_PokemonCenter_1F_EventScript_EnterWest
	call_if_eq VAR_FACING, DIR_EAST, IndigoPlateau_PokemonCenter_1F_EventScript_EnterEast
	goto_if_eq VAR_ELITE_4_MODE, 0, IndigoPlateau_PokemonCenter_1F_EventScript_WarpTitleMatch
	warp MAP_POKEMON_LEAGUE_LORELEIS_ROOM, 6, 12
	waitstate
	end

IndigoPlateau_PokemonCenter_1F_EventScript_WarpTitleMatch::
	warp MAP_POKEMON_LEAGUE_CHALLENGER_ROOM, 6, 3
	waitstate
	end

IndigoPlateau_PokemonCenter_1F_EventScript_EnterNorth::
	applymovement LOCALID_GUARD, Guard_Movement_StepRight
	waitmovement 5
	applymovement OBJ_EVENT_ID_PLAYER, Player_Movement_EnterNorth
	waitmovement 0
	return

IndigoPlateau_PokemonCenter_1F_EventScript_EnterWest::
	applymovement LOCALID_GUARD, Guard_Movement_StepLeft
	waitmovement 5
	applymovement OBJ_EVENT_ID_PLAYER, Player_Movement_EnterWest
	waitmovement 0
	return

IndigoPlateau_PokemonCenter_1F_EventScript_EnterEast::
	applymovement LOCALID_GUARD, Guard_Movement_StepRight
	waitmovement 5
	applymovement OBJ_EVENT_ID_PLAYER, Player_Movement_EnterEast
	waitmovement 0
	return

Guard_Movement_StepRight:
	walk_right
	face_down
	step_end

Guard_Movement_StepLeft:
	walk_left
	face_down
	step_end

Player_Movement_EnterNorth:
	walk_up
	walk_up
	set_invisible
	step_end

Player_Movement_EnterWest:
	walk_left
	walk_up
	set_invisible
	step_end

Player_Movement_EnterEast:
	walk_right
	walk_up
	set_invisible
	step_end

IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFour::
    .string "A partir d'aquí, t'enfrontaràs\n"
    .string "a l'Alt Comandament un per un.\p"
    .string "Si guanyes, s'obrirà una porta\n"
    .string "cap al següent entrenador.\p"
    .string "No podràs tornar fins que els\n"
    .string "hagis derrotat a tots, o hagis\l"
    .string "perdut.\p"
    .string "Estàs preparat per al repte?$"

IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourPostGame::
    .string "Com a Campió, pots desafiar\n"
    .string "l'Alt Comandament a combats\l"
    .string "d'exhibició.\p"
    .string "Però ves amb compte.\p"
    .string "Ara que ja has demostrat les\n"
    .string "teves habilitats, no es\l"
    .string "contindran.\p"
    .string "Estàs preparat per al repte?$"

IndigoPlateau_PokemonCenter_1F_EventScript_Decline::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_GuardDecline, MSGBOX_DEFAULT
	turnobject LOCALID_GUARD, DIR_SOUTH
	release
	end

IndigoPlateau_PokemonCenter_1F_Text_GuardDecline::
	.string "Entesos.\n"
	.string "Vine a veure'm si canvies d'idea.$"

IndigoPlateau_PokemonCenter_1F_Text_ExcellentGoodLuck::
	.string "Excel·lent!\n"
	.string "Bona sort!$"

IndigoPlateau_PokemonCenter_1F_EventScript_BlackBelt::
    lock
    faceplayer
    msgbox IndigoPlateau_PokemonCenter_1F_Text_AgathaWhuppedUs
    release
    end

IndigoPlateau_PokemonCenter_1F_Text_AgathaWhuppedUs::
    .string "Els Pokémon de tipus Fantasma de\n"
    .string "l'Agatha són terroríficament durs.\p"
    .string "Vaig agafar els meus Pokémon de\n"
    .string "tipus Lluita i els vaig entrenar\l"
    .string "al màxim.\p"
    .string "Vaig anar a lluitar contra l'Agatha\n"
    .string "ben confiat, però ens va escombrar.\p"
    .string "Aquella senyora gran també té\n"
    .string "molt mal geni.\p"
    .string "No cal gaire perquè aquella dona\n"
    .string "espantosa es posi a cridar.$"

IndigoPlateau_PokemonCenter_1F_EventScript_Dragontamer::
    lock
    faceplayer
    msgbox IndigoPlateau_PokemonCenter_1F_Text_LancesCousinGymLeaderFarAway
    release
    end

IndigoPlateau_PokemonCenter_1F_Text_LancesCousinGymLeaderFarAway::
    .string "Potser ser membre de l'Alt\n"
    .string "Comandament ho portes a la sang.\p"
    .string "Pel que he sentit, en Lance té\n"
    .string "un cosí que és Líder de Gimnàs\l"
    .string "en algun lloc llunyà.$"

IndigoPlateau_PokemonCenter_1F_EventScript_PokemonJournal::
	lock
	faceplayer
	msgbox PokemonJournal_Text_SpecialFeatureLance
	release
	end

PokemonJournal_Text_SpecialFeatureLance::
	.string "Diari Pokémon\p"
	.string "Reportatge especial:\n"
	.string "Lance de l'Alt Comandament!\p"
	.string "Es creu que l'avi d'en Lance és\n"
	.string "l'ancià d'un famós clan de\l"
	.string "mestres de dracs.$"

IndigoPlateau_PokemonCenter_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart IndigoPlateau_PokemonCenter_1F_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
IndigoPlateau_PokemonCenter_1F_Pokemart::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end


IndigoPlateau_PokemonCenter_1F_EventScript_BattleGirl::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_BATTLE_BERRY, IndigoPlateau_PokemonCenter_1F_EventScript_Determination
	msgbox IndigoPlateau_PokemonCenter_1F_Text_NoPokeCenters MSGBOX_NPC
	random 3
	call_if_eq VAR_RESULT, 0, IndigoPlateau_PokemonCenter_1F_EventScript_GiveSitrusBerry
	call_if_eq VAR_RESULT, 1, IndigoPlateau_PokemonCenter_1F_EventScript_GiveLumBerry
	call_if_eq VAR_RESULT, 2, IndigoPlateau_PokemonCenter_1F_EventScript_GiveLeppaBerry
	setflag FLAG_DAILY_BATTLE_BERRY
	goto IndigoPlateau_PokemonCenter_1F_EventScript_Determination
	end

IndigoPlateau_PokemonCenter_1F_EventScript_GiveSitrusBerry::
	giveitem ITEM_SITRUS_BERRY, 1
	return

IndigoPlateau_PokemonCenter_1F_EventScript_GiveLumBerry::
	giveitem ITEM_LUM_BERRY, 1
	return

IndigoPlateau_PokemonCenter_1F_EventScript_GiveLeppaBerry::
	giveitem ITEM_LEPPA_BERRY, 1
	return

IndigoPlateau_PokemonCenter_1F_Text_NoPokeCenters::
	.string "Quan t'enfrontis a l'Alt Comandament,\n"
	.string "no podràs tornar al Centre Pokémon\l"
	.string "per curar-te!\p"
	.string "Una baia com aquesta pot marcar\n"
	.string "la diferència!$"

IndigoPlateau_PokemonCenter_1F_EventScript_Determination::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_Determination, MSGBOX_NPC
	release
	end

IndigoPlateau_PokemonCenter_1F_Text_Determination::
	.string "Cal tot el que tens per enfrontar-te\n"
	.string "a l'Alt Comandament!\p"
	.string "Espero que estiguis ple de determinació!$"

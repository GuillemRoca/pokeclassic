.set LOCALID_OPPONENT, 1

PokemonLeague_ChallengerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TitleMatch_Heal
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonLeague_ChallengerRoom_OnTransition
	@map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_ChallengerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_ChallengerRoom_OnFrame
	.byte 0

TitleMatch_Heal::
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	end

PokemonLeague_ChallengerRoom_OnTransition::
	call_if_eq VAR_TITLE_MATCH_OPPONENT, 0, PokemonLeague_ChallengerRoom_SelectOpponent
	return


PokemonLeague_ChallengerRoom_SelectOpponent::
	call_if_ne VAR_TITLE_MATCHES, 3, PokemonLeague_ChallengerRoom_StandardOpponent
	call_if_eq VAR_TITLE_MATCHES, 3, PokemonLeague_ChallengerRoom_SpecialOpponent
	return

PokemonLeague_ChallengerRoom_StandardOpponent::
	random 9
	addvar VAR_RESULT, 1
	call_if_eq VAR_RESULT, 1, PokemonLeague_ChallengerRoom_Setup_Steph
	call_if_eq VAR_RESULT, 2, PokemonLeague_ChallengerRoom_Setup_Liz
	call_if_eq VAR_RESULT, 3, PokemonLeague_ChallengerRoom_Setup_Mike
	call_if_eq VAR_RESULT, 4, PokemonLeague_ChallengerRoom_Setup_Chris
	call_if_eq VAR_RESULT, 5, PokemonLeague_ChallengerRoom_Setup_Kev
	call_if_eq VAR_RESULT, 6, PokemonLeague_ChallengerRoom_Setup_Meghan
	call_if_eq VAR_RESULT, 7, PokemonLeague_ChallengerRoom_Setup_Steve
	call_if_eq VAR_RESULT, 8, PokemonLeague_ChallengerRoom_Setup_M
	call_if_eq VAR_RESULT, 9, PokemonLeague_ChallengerRoom_Setup_Bean
	call_if_eq VAR_RESULT, 10, PokemonLeague_ChallengerRoom_Setup_Annie
	return

PokemonLeague_ChallengerRoom_SpecialOpponent::
	random 9
	addvar VAR_RESULT, 1
	call_if_eq VAR_RESULT, 1, PokemonLeague_ChallengerRoom_Setup_Brock
	call_if_eq VAR_RESULT, 2, PokemonLeague_ChallengerRoom_Setup_Misty
	call_if_eq VAR_RESULT, 3, PokemonLeague_ChallengerRoom_Setup_Surge
	call_if_eq VAR_RESULT, 4, PokemonLeague_ChallengerRoom_Setup_Erika
	call_if_eq VAR_RESULT, 5, PokemonLeague_ChallengerRoom_Setup_Sabrina
	call_if_eq VAR_RESULT, 6, PokemonLeague_ChallengerRoom_Setup_Koga
	call_if_eq VAR_RESULT, 7, PokemonLeague_ChallengerRoom_Setup_Blaine
	call_if_eq VAR_RESULT, 8, PokemonLeague_ChallengerRoom_Setup_Rocket
	call_if_eq VAR_RESULT, 9, PokemonLeague_ChallengerRoom_Setup_Daisy
	call_if_eq VAR_RESULT, 10, PokemonLeague_ChallengerRoom_Setup_Rival
	return

PokemonLeague_ChallengerRoom_Setup_Steph::
	setvar VAR_TITLE_MATCH_OPPONENT, 1
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LASS
	return

PokemonLeague_ChallengerRoom_Setup_Liz::
	setvar VAR_TITLE_MATCH_OPPONENT, 2
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F
	return

PokemonLeague_ChallengerRoom_Setup_Mike::
	setvar VAR_TITLE_MATCH_OPPONENT, 3
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_COOL_TRAINER_M
	return

PokemonLeague_ChallengerRoom_Setup_Chris::
	setvar VAR_TITLE_MATCH_OPPONENT, 4
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_CUEBALL
	return

PokemonLeague_ChallengerRoom_Setup_Kev::
	setvar VAR_TITLE_MATCH_OPPONENT, 5
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_NINJA_BOY
	return

PokemonLeague_ChallengerRoom_Setup_Meghan::
	setvar VAR_TITLE_MATCH_OPPONENT, 6
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_HEX_MANIAC
	return

PokemonLeague_ChallengerRoom_Setup_Steve::
	setvar VAR_TITLE_MATCH_OPPONENT, 7
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_DRAGON_TAMER
	return

PokemonLeague_ChallengerRoom_Setup_M::
	setvar VAR_TITLE_MATCH_OPPONENT, 8
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BUG_CATCHER
	return

PokemonLeague_ChallengerRoom_Setup_Bean::
	setvar VAR_TITLE_MATCH_OPPONENT, 9
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_YOUNGSTER
	return

PokemonLeague_ChallengerRoom_Setup_Annie::
	setvar VAR_TITLE_MATCH_OPPONENT, 10
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SCHOOL_KID_F
	return

PokemonLeague_ChallengerRoom_Setup_Brock::
	setvar VAR_TITLE_MATCH_OPPONENT, 11
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BROCK
	return

PokemonLeague_ChallengerRoom_Setup_Misty::
	setvar VAR_TITLE_MATCH_OPPONENT, 12
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MISTY
	return

PokemonLeague_ChallengerRoom_Setup_Surge::
	setvar VAR_TITLE_MATCH_OPPONENT, 13
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SURGE
	return

PokemonLeague_ChallengerRoom_Setup_Erika::
	setvar VAR_TITLE_MATCH_OPPONENT, 14
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ERIKA
	return

PokemonLeague_ChallengerRoom_Setup_Sabrina::
	setvar VAR_TITLE_MATCH_OPPONENT, 15
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SABRINA
	return

PokemonLeague_ChallengerRoom_Setup_Koga::
	setvar VAR_TITLE_MATCH_OPPONENT, 16
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_KOGA
	return

PokemonLeague_ChallengerRoom_Setup_Blaine::
	setvar VAR_TITLE_MATCH_OPPONENT, 17
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BLAINE
	return

PokemonLeague_ChallengerRoom_Setup_Rocket::
	setvar VAR_TITLE_MATCH_OPPONENT, 18
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ROCKET_MEMBER_F
	return

PokemonLeague_ChallengerRoom_Setup_Daisy::
	setvar VAR_TITLE_MATCH_OPPONENT, 19
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_DAISY
	return

PokemonLeague_ChallengerRoom_Setup_Rival::
	setvar VAR_TITLE_MATCH_OPPONENT, 20
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BLUE
	return

PokemonLeague_ChallengerRoom_OnFrame::
	map_script_2 VAR_TEMP_0, 0, PokemonLeague_ChallengerRoom_EnterScene
	.2byte 0

PokemonLeague_ChallengerRoom_EnterScene::
	setvar VAR_TEMP_0, 1
	applymovement OBJ_EVENT_ID_PLAYER, ChallengeRoom_PlayerEnter
	waitmovement 0
	applymovement LOCALID_OPPONENT, ChallengeRoom_OpponentEnter
	waitmovement 1
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 1, TitleMatch_Steph
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 2, TitleMatch_Liz
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 3, TitleMatch_Mike
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 4, TitleMatch_Chris
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 5, TitleMatch_Kev
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 6, TitleMatch_Meghan
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 7, TitleMatch_Steve
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 8, TitleMatch_M
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 9, TitleMatch_Bean
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 10, TitleMatch_Annie
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 11, TitleMatch_Brock
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 12, TitleMatch_Misty
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 13, TitleMatch_Surge
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 14, TitleMatch_Erika
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 15, TitleMatch_Sabrina
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 16, TitleMatch_Koga
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 17, TitleMatch_Blaine
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 18, TitleMatch_Rocket
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 19, TitleMatch_Daisy
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 20, TitleMatch_Rival
	end

ChallengeRoom_PlayerEnter::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ChallengeRoom_OpponentEnter::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TitleMatch_BattleOutcome::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TitleMatch_EventScript_Victory
	goto TitleMatch_EventScript_Defeat
	end

TitleMatch_EventScript_Victory::
	msgbox TitleMatch_Text_TitleMatchVictory, MSGBOX_DEFAULT
	warp MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F, 11, 14
	goto TitleMatch_EventScript_Exit
	end

TitleMatch_EventScript_Defeat::
	msgbox TitleMatch_Text_TitleMatchVictory, MSGBOX_DEFAULT
TitleMatch_EventScript_Exit::
	waitmessage
	closemessage
	applymovement LOCALID_OPPONENT, ChallengeRoom_PlayerEnter
	waitmovement 1
	warp MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F, 11, 14
	waitstate
	end


TitleMatch_Text_TitleMatchVictory::
	.string "El Combat pel Títol ha acabat!\n"
	.string "{PLAYER} ha guanyat el combat!$"

TitleMatch_Text_TitleMatchDefeated::
	.string "El Combat pel Títol ha acabat!\n"
	.string "{PLAYER} ha estat derrotat!\p"
	.string "Kanto té un nou campió!$"

TitleMatch_Steph::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_STEPH, TitleMatch_Text_StephIntro, TitleMatch_Text_StephDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_StephIntro::
	.string "Estic preparada!$"

TitleMatch_Text_StephDefeated::
	.string "Bé, me'n vaig.$"

TitleMatch_Liz::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_LIZ, TitleMatch_Text_LizIntro, TitleMatch_Text_LizDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_LizIntro::
	.string "Soc un geni.$"

TitleMatch_Text_LizDefeated::
	.string "Oh, no!$"

TitleMatch_Mike::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_MIKE, TitleMatch_Text_MikeIntro, TitleMatch_Text_MikeDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_MikeIntro::
	.string "El meu rival és en Chris.$"

TitleMatch_Text_MikeDefeated::
	.string "M'és igual si guanyes, mentre\n"
	.string "ell perdi.$"

TitleMatch_Chris::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_CHRIS, TitleMatch_Text_ChrisIntro, TitleMatch_Text_ChrisDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_ChrisIntro::
	.string "No és hora de jugar!$"

TitleMatch_Text_ChrisDefeated::
	.string "Massa por!"

TitleMatch_Kev::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_KEV, TitleMatch_Text_KevIntro, TitleMatch_Text_KevDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_KevIntro::
	.string "Tinc el poder dels Pokémon\n"
	.string "al meu costat!$"

TitleMatch_Text_KevDefeated::
	.string "No! Hauria d'haver usat tota\n"
	.string "la meva força!$"

TitleMatch_Meghan::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_MEGHAN, TitleMatch_Text_MeghanIntro, TitleMatch_Text_MeghanDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_MeghanIntro::
	.string "Ja no és possible desconnectar-se.$"

TitleMatch_Text_MeghanDefeated::
	.string "Fes el camp!$"

TitleMatch_Steve::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_STEVE, TitleMatch_Text_SteveIntro, TitleMatch_Text_SteveDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_SteveIntro::
	.string "Pokémon va de poder.$"

TitleMatch_Text_SteveDefeated::
	.string "Avui no era el meu dia.$"

TitleMatch_M::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_M, TitleMatch_Text_MIntro, TitleMatch_Text_MDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_MIntro::
	.string "Aquest és el meu territori!$"

TitleMatch_Text_MDefeated::
	.string "Deixa'm en pau!$"

TitleMatch_Bean::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_BEAN, TitleMatch_Text_BeanIntro, TitleMatch_Text_BeanDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_BeanIntro::
	.string "No toleraré els maleducats.$"

TitleMatch_Text_BeanDefeated::
	.string "Ets dur! M'agrada!$"

TitleMatch_Annie::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_ANNIE, TitleMatch_Text_AnnieIntro, TitleMatch_Text_AnnieDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_AnnieIntro::
	.string "He agafat els Pokémon de la\n"
	.string "meva mare.$"

TitleMatch_Text_AnnieDefeated::
	.string "Buaaaa! Vull la meva mare!$"

TitleMatch_Brock::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_BROCK, TitleMatch_Text_BrockIntro, TitleMatch_Text_BrockDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_BrockIntro::
	.string "Brock: Estic en ratxa!$"

TitleMatch_Text_BrockDefeated::
	.string "Has avançat molt, {PLAYER}.$"

TitleMatch_Misty::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_MISTY, TitleMatch_Text_MistyIntro, TitleMatch_Text_MistyDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_MistyIntro::
	.string "Misty: Ei, ets tu!\p"
	.string "Això de ser campió hauria de\n"
	.string "ser fàcil, doncs.$"

TitleMatch_Text_MistyDefeated::
	.string "Ecs! No puc creure que hagi\n"
	.string "perdut contra tu un altre cop!$"

TitleMatch_Surge::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_SURGE, TitleMatch_Text_SurgeIntro, TitleMatch_Text_SurgeDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_SurgeIntro::
	.string "Surge: La vida és una guerra, nen.\p"
	.string "Això és un camp de batalla més.$"

TitleMatch_Text_SurgeDefeated::
	.string "Tornem a l'entrenament bàsic!$"

TitleMatch_Erika::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_ERIKA, TitleMatch_Text_ErikaIntro, TitleMatch_Text_ErikaDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_ErikaIntro::
	.string "Erika: Hola, {PLAYER}.\p"
	.string "Fem un altre combat?$"

TitleMatch_Text_ErikaDefeated::
	.string "Sembla que he tornat a perdre...$"

TitleMatch_Sabrina::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_SABRINA, TitleMatch_Text_SabrinaIntro, TitleMatch_Text_SabrinaDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_SabrinaIntro::
	.string "Sabrina: Havia previst aquest combat.$"

TitleMatch_Text_SabrinaDefeated::
	.string "Sabia que acabaria així...$"

TitleMatch_Koga::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_KOGA, TitleMatch_Text_KogaIntro, TitleMatch_Text_KogaDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_KogaIntro::
	.string "Koga: He decidit fer el pas\n"
	.string "i unir-me a l'Alt Comandament.\p"
	.string "Tu ets el meu únic obstacle!$"

TitleMatch_Text_KogaDefeated::
	.string "Encara no en soc digne.$"

TitleMatch_Blaine::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_BLAINE, TitleMatch_Text_BlaineIntro, TitleMatch_Text_BlaineDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_BlaineIntro::
	.string "Blaine: M'has encès la flama!$"

TitleMatch_Text_BlaineDefeated::
	.string "No prou calent!$"

TitleMatch_Rocket::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_ROCKET, TitleMatch_Text_RocketIntro, TitleMatch_Text_RocketDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_RocketIntro::
	.string "Vam lluitar a Silph SA.\p"
	.string "Intento anar pel bon camí.\n"
	.string "Tu em vas inspirar a intentar\l"
	.string "ser un entrenador de debò.$"

TitleMatch_Text_RocketDefeated::
	.string "No mereixia guanyar després de\n"
	.string "totes les coses horribles que\l"
	.string "he fet.$"

TitleMatch_Daisy::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_DAISY, TitleMatch_Text_DaisyIntro, TitleMatch_Text_DaisyDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_DaisyIntro::
	.string "Daisy: Hola, {PLAYER}!\p"
	.string "Tu i el meu germà sempre\n"
	.string "parlàveu de combatre, així que\l"
	.string "vaig decidir provar-ho.\p"
	.string "Sembla que jo també soc força\n"
	.string "bona!$"

TitleMatch_Text_DaisyDefeated::
	.string "Ha estat divertit!$"

TitleMatch_Rival::
	goto_if_eq VAR_RIVAL_WINRATE, 2, TitleMatch_Rival_Jolteon
	goto_if_eq VAR_RIVAL_WINRATE, 1, TitleMatch_Rival_Flareon
	goto TitleMatch_Rival_Vaporeon

TitleMatch_Rival_Jolteon::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_RIVAL_JOLTEON, TitleMatch_Text_RivalIntro, TitleMatch_Text_RivalDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Rival_Flareon::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_RIVAL_FLAREON, TitleMatch_Text_RivalIntro, TitleMatch_Text_RivalDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Rival_Vaporeon::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_RIVAL_VAPOREON, TitleMatch_Text_RivalIntro, TitleMatch_Text_RivalDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_RivalIntro::
	.string "{RIVAL}: Bé, ens retrobem!\p"
	.string "Ara és la meva oportunitat de\n"
	.string "demostrar que soc el veritable\l"
	.string "campió!$"

TitleMatch_Text_RivalDefeated::
	.string "Heh, encara no en saps prou.$"

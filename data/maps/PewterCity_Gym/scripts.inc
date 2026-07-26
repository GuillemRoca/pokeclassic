.set LOCALID_SCOTT, 3

PewterCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_Gym_OnTransition
	.byte 0

PewterCity_Gym_OnTransition::
	call_if_unset FLAG_DAILY_BROCK_REMATCH, PewterCity_Gym_ResetRematchFlags
	end

PewterCity_Gym_ResetRematchFlags::
	cleartrainerflag LEADER_REMATCH_BROCK_ORIGINAL
	cleartrainerflag LEADER_REMATCH_BROCK_POSTGAME
	return

PewterCity_Gym_EventScript_Brock::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE01_GET, PewterCity_Gym_EventScript_ChallengeBrock
	goto_if_unset FLAG_GOT_BROCK_REWARD, PewterCity_Gym_EventScript_GetTM
	goto_if_unset FLAG_DAILY_BROCK_REMATCH, PewterCity_Gym_EventScript_RematchLeader
	goto PewterCity_Gym_EventScript_LeaderPostBattle
	end

PewterCity_Gym_EventScript_ChallengeBrock::
	msgbox PewterCity_Gym_Text_BrockSpeech, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_BROCK, PewterCity_Gym_Text_BrockIntro, PewterCity_Gym_Text_BrockDefeat, PewterCity_Gym_EventScript_DefeatedBrockGetBadge
	end

PewterCity_Gym_Text_BrockSpeech::
	.string "Així que ets aquí. Sóc Brock.\n"
    .string "Sóc el Líder del Gimnàs de Pewter.\p"
    .string "La meva voluntat de ferro es\n"
    .string "reflecteix en els meus Pokémon.\p"
    .string "Els meus Pokémon són durs com\n"
    .string "la roca i tenen una determinació\l"
    .string "autèntica.\p"
    .string "Així és, tots els meus Pokémon\n"
    .string "són de tipus Roca!\p"
    .string "Fuhaha! Vens a desafiar-me\n"
    .string "sabent que perdràs?\p"
    .string "És l'honor d'Entrenador el que\n"
    .string "t'obliga a desafiar-me.$"

PewterCity_Gym_Text_BrockIntro::
    .string "Molt bé, doncs!\n"
    .string "Demostra'm el que vals!$"

PewterCity_Gym_Text_BrockDefeat::
    .string "Et vaig subestimar, i per això\n"
    .string "he perdut.$"

PewterCity_Gym_EventScript_DefeatedBrockGetBadge::
	msgbox PewterCity_Gym_Text_GetBadgeFromBrock, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	message PewterCity_Gym_Text_ReceivedBadge
	waitfanfare
	waitmessage
	msgbox PewterCity_Gym_Text_ExplainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	setflag FLAG_DAILY_BROCK_REMATCH
	setflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
	settrainerflag TRAINER_CAMPER_LIAM
	setvar VAR_PEWTER_CITY_STATE, 1
	goto PewterCity_Gym_EventScript_GetTM
	end

PewterCity_Gym_Text_GetBadgeFromBrock::
	.string "Com a prova de la teva victòria,\n"
    .string "et concedeixo això… la Medalla\l"
    .string "Roca oficial de la Lliga Pokémon.$"

PewterCity_Gym_Text_ReceivedBadge::
	.string "{PLAYER} ha rebut la Medalla\n"
    .string "Roca de Brock!$"

PewterCity_Gym_Text_ExplainBadge::
	.string "Només tenir la Medalla Roca fa\n"
    .string "els teus Pokémon més poderosos.\p"
    .string "També permet usar el moviment\n"
    .string "Flash fora de combat.\p"
    .string "Per descomptat, un Pokémon ha de\n"
    .string "conèixer Flash per usar-lo.$"

PewterCity_Gym_EventScript_GetTM::
	msgbox PewterCity_Gym_Text_TakeThisWithYou, MSGBOX_DEFAULT
	checkitemspace ITEM_TM39, 1
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Gym_EventScript_NoRoomForTM
	playfanfare MUS_OBTAIN_TMHM
	msgbox PewterCity_Gym_Text_ReceivedTMFromBrock, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_TM39, 1
	setflag FLAG_GOT_BROCK_REWARD
	msgbox PewterCity_Gym_Text_ExplainTM, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_TakeThisWithYou::
    .string "Espera!\n"
    .string "Emporta't això.$"

PewterCity_Gym_Text_ReceivedTMFromBrock::
    .string "{PLAYER} ha rebut la MT39\n"
    .string "de Brock.$"

PewterCity_Gym_Text_ExplainTM::
    .string "Una MT, Màquina Tècnica, conté\n"
    .string "una tècnica per a Pokémon.\p"
    .string "Usar una MT ensenya el moviment\n"
    .string "que conté a un Pokémon.\p"
    .string "La MT39 conté Tomba Roca.\p"
    .string "Llança roques a l'enemic i\n"
    .string "redueix la seva velocitat.$"

PewterCity_Gym_EventScript_NoRoomForTM::
	msgbox PewterCity_Gym_Text_NoRoomForTM, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_NoRoomForTM::
    .string "No tens espai per a això.$"

PewterCity_Gym_EventScript_LeaderPostBattle::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, PewterCity_Gym_EventScript_LeaderPostBattleGameClear
	msgbox PewterCity_Gym_Text_LeaderPostBattle, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_LeaderPostBattle::
    .string "Hi ha tota mena d'Entrenadors en\n"
    .string "aquest gran món nostre.\p"
    .string "Sembla que tens molt de talent\n"
    .string "com a Entrenador Pokémon.\p"
    .string "Deixa'm fer-te un suggeriment.\p"
    .string "Vés al Gimnàs de Cerulean i posa\n"
    .string "a prova les teves habilitats.$"

PewterCity_Gym_EventScript_LeaderPostBattleGameClear::
	msgbox PewterCity_Gym_Text_PostBattleGameClear, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_PostBattleGameClear::
	.string "Has avançat molt des que vas\n"
	.string "guanyar la Medalla Roca, {PLAYER}!$"

PewterCity_Gym_EventScript_RematchLeader::
	msgbox PewterCity_Gym_Text_RematchLeader, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Gym_EventScript_DeclineRematch
	goto_if_set FLAG_SYS_GAME_CLEAR, PewterCity_Gym_EventScript_PostgameRematch
	goto PewterCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

PewterCity_Gym_Text_RematchLeader::
	.string "…Tens un aspecte molt diferent\n"
	.string "de quan ens vam conèixer!\p"
	.string "…Si us plau, concedeix-me el\n"
	.string "privilegi de combatre una altra\l"
	.string "vegada!$"

PewterCity_Gym_EventScript_DeclineRematch::
	msgbox PewterCity_Gym_Text_DeclineRematch, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_DeclineRematch::
	.string "Ja veig…$"

PewterCity_Gym_EventScript_PostgameRematch::
	msgbox PewterCity_Gym_Text_RematchMode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, PewterCity_Gym_EventScript_LeaderRematch_PostGameTeam
	goto PewterCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

PewterCity_Gym_Text_RematchMode::
	.string "Ara que ets el Campió,\n"
	.string "vols anar amb tot?$"

PewterCity_Gym_EventScript_LeaderRematch_OriginalTeam::
	trainerbattle_single LEADER_REMATCH_BROCK_ORIGINAL, PewterCity_Gym_Text_RematchOriginal, PewterCity_Gym_Text_RematchDefeat, PewterCity_Gym_EventScript_DefeatedLeaderRematch
	end

PewterCity_Gym_Text_RematchOriginal::
	.string "D'acord, {PLAYER}!\n"
	.string "Revivim el nostre primer combat!$"

PewterCity_Gym_EventScript_LeaderRematch_PostGameTeam::
	trainerbattle_single LEADER_REMATCH_BROCK_POSTGAME, PewterCity_Gym_Text_RematchPostgame, PewterCity_Gym_Text_RematchDefeat, PewterCity_Gym_EventScript_DefeatedLeaderRematch
	end

PewterCity_Gym_Text_RematchPostgame::
	.string "Deixa'm mostrar-te la veritable\n"
	.string "força de roca dels meus Pokémon!$"

PewterCity_Gym_EventScript_DefeatedLeaderRematch::
	setflag FLAG_DAILY_BROCK_REMATCH
	goto PewterCity_Gym_EventScript_LeaderPostBattle
	end

PewterCity_Gym_Text_RematchDefeat::
	.string "Sabia que eres fort, però això…$"

PewterCity_Gym_EventScript_Liam::
	trainerbattle_single TRAINER_CAMPER_LIAM, PewterCity_Gym_Text_LiamIntro, PewterCity_Gym_Text_LiamDefeat
	msgbox PewterCity_Gym_Text_LiamPostBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_Text_LiamIntro::
    .string "Para aquí, nen!\p"
    .string "Estàs a deu mil anys llum\n"
    .string "d'enfrontar-te a Brock!$"

PewterCity_Gym_Text_LiamDefeat::
    .string "Ostres!\p"
    .string "Els anys llum no mesuren temps…\n"
    .string "Mesuren distància!$"

PewterCity_Gym_Text_LiamPostBattle::
    .string "Ets bastant bo.\n"
    .string "…Però no tant com Brock!$"

PewterCity_Gym_EventScript_ScottTrigger1::
	call PewterCity_Gym_EventScript_ScottTriggered
	applymovement OBJ_EVENT_ID_PLAYER, Movement_MoveToScott1
	waitmovement 0
	turnobject LOCALID_SCOTT, DIR_WEST
	goto PewterCity_Gym_EventScript_ThatWasReallySomething
	end

Movement_MoveToScott1:
	walk_up
	walk_up
	walk_right
	step_end

PewterCity_Gym_EventScript_ScottTrigger2::
	call PewterCity_Gym_EventScript_ScottTriggered
	applymovement OBJ_EVENT_ID_PLAYER, Movement_MoveToScott2
	waitmovement 0
	turnobject LOCALID_SCOTT, DIR_WEST
	goto PewterCity_Gym_EventScript_ThatWasReallySomething
	end

Movement_MoveToScott2:
	walk_up
	face_right
	step_end

PewterCity_Gym_EventScript_ScottTrigger3::
	call PewterCity_Gym_EventScript_ScottTriggered
	applymovement OBJ_EVENT_ID_PLAYER, Movement_MoveToScott3
	waitmovement 0
	goto PewterCity_Gym_EventScript_ThatWasReallySomething
	end

Movement_MoveToScott3:
	walk_up
	step_end

PewterCity_Gym_EventScript_ScottTriggered::
	applymovement LOCALID_SCOTT, Common_Movement_ExclamationMark
	waitmovement 3
	msgbox PewterCity_Gym_Text_HeyWaitUp, MSGBOX_DEFAULT
	return

PewterCity_Gym_Text_HeyWaitUp::
	.string "Ei, nen! Espera!$"

PewterCity_Gym_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_REGISTERED_SCOTT, PewterCity_Gym_EventScript_GymGuyPostVictory
	goto_if_set FLAG_BADGE01_GET, PewterCity_Gym_EventScript_ThatWasReallySomething
	msgbox PewterCity_Gym_Text_LetMeTakeYouToTheTop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Gym_EventScript_GymGuyTakeMeToTop
	goto_if_eq VAR_RESULT, NO, PewterCity_Gym_EventScript_GymGuyDontTakeMeToTop
	end

PewterCity_Gym_Text_LetMeTakeYouToTheTop::
    .string "Hola!\n"
    .string "Vols somiar en gran?\p"
    .string "Gosaries somiar en ser\n"
    .string "el Campió Pokémon?\p"
    .string "Jo no sóc Entrenador, però et\n"
    .string "puc aconsellar per guanyar.\p"
    .string "Deixa que et porti al cim!$"

PewterCity_Gym_EventScript_GymGuyTakeMeToTop::
	msgbox PewterCity_Gym_Text_LetsGetHappening, MSGBOX_DEFAULT
	goto PewterCity_Gym_EventScript_GymGuyAdvice
	end

PewterCity_Gym_Text_LetsGetHappening::
    .string "Molt bé!\n"
    .string "Comencem!$"

PewterCity_Gym_EventScript_GymGuyDontTakeMeToTop::
	msgbox PewterCity_Gym_Text_ItsFreeLetsGetHappening, MSGBOX_DEFAULT
	goto PewterCity_Gym_EventScript_GymGuyAdvice
	end

PewterCity_Gym_Text_ItsFreeLetsGetHappening::
    .string "És un servei gratuït!\n"
    .string "Comencem!$"

PewterCity_Gym_EventScript_GymGuyAdvice::
	msgbox PewterCity_Gym_Text_TryDifferentPartyOrders, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_TryDifferentPartyOrders::
    .string "El primer Pokémon en un combat és\n"
    .string "el de l'esquerra de la Llista.\p"
    .string "Canviant l'ordre dels Pokémon,\n"
    .string "pots tenir avantatge.\p"
    .string "Prova ordres diferents segons\n"
    .string "l'equip del teu rival.$"


PewterCity_Gym_EventScript_GymGuyPostVictory::
	msgbox PewterCity_Gym_Text_YoureChampMaterial, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_YoureChampMaterial::
    .string "Tens fusta de Campió Pokémon!$"

PewterCity_Gym_EventScript_ThatWasReallySomething::
	msgbox PewterCity_Gym_Text_ThatWasReallySomething, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_SCOTT
	setvar VAR_PEWTER_CITY_STATE, 2
	release
	end

PewterCity_Gym_Text_ThatWasReallySomething::
    .string "Uau, això ha estat increïble!\p"
    .string "Potser era només la teva primera\n"
    .string "Medalla de Gimnàs, però tinc olfacte\l"
    .string "per aquestes coses.\p"
    .string "Tens el que cal!\p"
    .string "Escolta, estic buscant per tot\n"
    .string "Kanto Entrenadors amb talent.\p"
    .string "Deixa'm donar-te el meu número.\n"
    .string "Et pot ser útil!$"

PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue, MSGBOX_SIGN
	releaseall
	end

PewterCity_Gym_Text_GymStatue::
    .string "Gimnàs Pokémon de Pewter\n"
    .string "Líder: Brock\p"
    .string "Entrenadors guanyadors:\n"
    .string "{RIVAL}$"

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon, MSGBOX_SIGN
	releaseall
	end

PewterCity_Gym_Text_GymStatuePlayerWon::
    .string "Gimnàs Pokémon de Pewter\n"
    .string "Líder: Brock\p"
    .string "Entrenadors guanyadors:\n"
    .string "{RIVAL}, {PLAYER}$"

FuchsiaCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_Gym_OnTransition
	.byte 0

FuchsiaCity_Gym_OnTransition::
	call_if_unset FLAG_DAILY_KOGA_REMATCH, FuchsiaCity_Gym_ResetRematchFlags
	end

FuchsiaCity_Gym_ResetRematchFlags::
	cleartrainerflag LEADER_REMATCH_KOGA_ORIGINAL
	cleartrainerflag LEADER_REMATCH_KOGA_POSTGAME
	return

FuchsiaCity_Gym_EventScript_Koga::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE05_GET, FuchsiaCity_Gym_EventScript_ChallengeLeader
	goto_if_unset FLAG_GOT_KOGA_REWARD, FuchsiaCity_Gym_EventScript_GetTM
	goto_if_unset FLAG_DAILY_KOGA_REMATCH, FuchsiaCity_Gym_EventScript_RematchLeader
	goto FuchsiaCity_Gym_EventScript_LeaderPostBattle
	end

FuchsiaCity_Gym_EventScript_ChallengeLeader::
	msgbox FuchsiaCity_Gym_Text_LeaderSpeech, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_KOGA, FuchsiaCity_Gym_Text_LeaderIntro, FuchsiaCity_Gym_Text_LeaderDefeat, FuchsiaCity_Gym_EventScript_DefeatedLeaderGetBadge
	end

FuchsiaCity_Gym_Text_LeaderSpeech::
    .string "Koga: Fwahahaha!\p"
    .string "Un simple nen com tu gosa\n"
    .string "desafiar-me?\p"
    .string "Només la idea em fa tremolar\n"
    .string "de riure!\p"
    .string "Molt bé, et mostraré el veritable\n"
    .string "terror com a mestre ninja.\p"
    .string "El verí porta la perdició lenta.\n"
    .string "El son deixa l'enemic indefens.$"

FuchsiaCity_Gym_Text_LeaderIntro::
    .string "Desespera davant l'horror\n"
    .string "dels Pokémon de tipus Verí!$"

FuchsiaCity_Gym_Text_LeaderDefeat::
    .string "Hmph!\n"
    .string "Has demostrat la teva vàlua!$"

FuchsiaCity_Gym_EventScript_DefeatedLeaderGetBadge::
	msgbox FuchsiaCity_Gym_Text_GetBadge, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	message FuchsiaCity_Gym_Text_ReceivedBadge
	waitfanfare
	waitmessage
	msgbox FuchsiaCity_Gym_Text_ExplainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE05_GET
	setflag FLAG_DAILY_KOGA_REMATCH
	settrainerflag TRAINER_TAMER_PHIL
	settrainerflag TRAINER_TAMER_EDGAR
	settrainerflag TRAINER_JUGGLER_KIRK
	settrainerflag TRAINER_JUGGLER_SHAWN
	settrainerflag TRAINER_JUGGLER_KAYDEN
	settrainerflag TRAINER_JUGGLER_NATE
	call_if_set FLAG_RECEIVED_ITEMFINDER, FuchsiaCity_Gym_EventScript_QueueNextAideCall
	goto FuchsiaCity_Gym_EventScript_GetTM
	end

FuchsiaCity_Gym_EventScript_QueueNextAideCall::
	setflag FLAG_QUEUE_AIDE_CALL
	setflag FLAG_AIDE_LOCATION_4
	return

FuchsiaCity_Gym_Text_GetBadge::
    .string "Aquí tens!\n"
    .string "Pren la Medalla Ànima!$"

FuchsiaCity_Gym_Text_ReceivedBadge::
	.string "{PLAYER} ha rebut la Medalla\n"
    .string "Ànima de Koga!$"

FuchsiaCity_Gym_Text_ExplainBadge::
    .string "La Medalla Ànima et permetrà\n"
   .string "fer SURF fora de combat.$"

FuchsiaCity_Gym_EventScript_GetTM::
	msgbox FuchsiaCity_Gym_Text_TakeThisWithYou, MSGBOX_DEFAULT
	checkitemspace ITEM_TM06, 1
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_Gym_EventScript_NoRoomForTM
	playfanfare MUS_OBTAIN_TMHM
	msgbox FuchsiaCity_Gym_Text_ReceivedTM, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_TM06, 1
	setflag FLAG_GOT_KOGA_REWARD
	msgbox FuchsiaCity_Gym_Text_ExplainTM, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_Text_TakeThisWithYou::
    .string "Ah!\n"
    .string "Pren això també!$"

FuchsiaCity_Gym_Text_ReceivedTM::
	.string "{PLAYER} ha rebut la MT06\n"
    .string "de Koga.$"

FuchsiaCity_Gym_Text_ExplainTM::
    .string "Dins d'aquella MT06 hi ha\n"
    .string "Tòxic!\p"
    .string "És una tècnica secreta que\n"
    .string "data de fa quatre-cents anys.$"

FuchsiaCity_Gym_EventScript_NoRoomForTM::
	msgbox FuchsiaCity_Gym_Text_NoRoomForTM, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_Text_NoRoomForTM::
    .string "Fes espai per a això, nen!$"

FuchsiaCity_Gym_EventScript_LeaderPostBattle::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, FuchsiaCity_Gym_EventScript_LeaderPostBattleGameClear
	msgbox FuchsiaCity_Gym_Text_LeaderPostBattle, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_Text_LeaderPostBattle::
    .string "Quan un Pokémon pateix Tòxic,\n"
    .string "sofreix cada cop més.\p"
    .string "El dany empitjora a mesura que\n"
    .string "avança el combat!\p"
    .string "Sens dubte terroritzarà enemics!$"

FuchsiaCity_Gym_EventScript_LeaderPostBattleGameClear::
	msgbox FuchsiaCity_Gym_Text_PostBattleGameClear, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_Text_PostBattleGameClear::
	.string "Amb Entrenadors com tu i {RIVAL}\n"
	.string "la Lliga Pokémon ha de ser un lloc\l"
	.string "de força formidable!\p"
	.string "Realment, és motiu d'orgull!\p"
	.string "Precisament, he estat pensant\n"
	.string "a aspirar a l'Alt Comandament...$"

FuchsiaCity_Gym_EventScript_RematchLeader::
	msgbox FuchsiaCity_Gym_Text_RematchLeader, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_Gym_EventScript_DeclineRematch
	goto_if_set FLAG_SYS_GAME_CLEAR, FuchsiaCity_Gym_EventScript_PostgameRematch
	goto FuchsiaCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

FuchsiaCity_Gym_Text_RematchLeader::
	.string "Fwahahaha! Si no és el nen.\p"
	.string "Sembla que el destí ens ha tornat\n"
	.string "a reunir.\p"
	.string "Has vingut en un moment molt\n"
	.string "oportú.\p"
	.string "Justament pensava que volia posar\n"
	.string "a prova les meves noves tècniques\l"
	.string "sinistres...\p"
	.string "...en un combat que acabarà amb\n"
	.string "la teva derrota total!\n"
	.string "Acceptes el meu desafiament?$"

FuchsiaCity_Gym_EventScript_DeclineRematch::
	msgbox FuchsiaCity_Gym_Text_DeclineRematch, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_Text_DeclineRematch::
	.string "Ja has perdut!$"

FuchsiaCity_Gym_EventScript_PostgameRematch::
	msgbox FuchsiaCity_Gym_Text_RematchMode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, FuchsiaCity_Gym_EventScript_LeaderRematch_PostGameTeam
	goto FuchsiaCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

FuchsiaCity_Gym_Text_RematchMode::
	.string "Ara que ets el campió,\n"
	.string "vols anar amb tot?$"

FuchsiaCity_Gym_EventScript_LeaderRematch_OriginalTeam::
	trainerbattle_single LEADER_REMATCH_KOGA_ORIGINAL, FuchsiaCity_Gym_Text_RematchOriginal, FuchsiaCity_Gym_Text_RematchDefeat, FuchsiaCity_Gym_EventScript_DefeatedLeaderRematch
	end

FuchsiaCity_Gym_Text_RematchOriginal::
	.string "Fwahahaha!\n"
	.string "Revivem els nostres combats!$"

FuchsiaCity_Gym_EventScript_LeaderRematch_PostGameTeam::
	trainerbattle_single LEADER_REMATCH_KOGA_POSTGAME, FuchsiaCity_Gym_Text_RematchPostgame, FuchsiaCity_Gym_Text_RematchDefeat, FuchsiaCity_Gym_EventScript_DefeatedLeaderRematch
	end

FuchsiaCity_Gym_Text_RematchPostgame::
	.string "Fwahahaha!\p"
	.string "Avui no només et derrotaré, sinó\n"
	.string "que també demostraré la meva\l"
	.string "dignitat paterna a la meva filla!$"

FuchsiaCity_Gym_EventScript_DefeatedLeaderRematch::
	setflag FLAG_DAILY_KOGA_REMATCH
	goto FuchsiaCity_Gym_EventScript_LeaderPostBattle
	end

FuchsiaCity_Gym_Text_RematchDefeat::
	.string "...Si no sóc prou fort per\n"
	.string "derrotar-te, només queda una cosa.\p"
	.string "He de perfeccionar les meves\n"
	.string "habilitats.$"

FuchsiaCity_Gym_EventScript_Phil::
	trainerbattle_single TRAINER_TAMER_PHIL, FuchsiaCity_Gym_Text_PhilIntro, FuchsiaCity_Gym_Text_PhilDefeat
	msgbox FuchsiaCity_Gym_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_Text_PhilIntro::
    .string "Para aquí!\p"
    .string "Les famoses parets invisibles\n"
    .string "del Gimnàs Fuchsia et frustren?$"

FuchsiaCity_Gym_Text_PhilDefeat::
    .string "Uau!\n"
    .string "Ets bo!$"

FuchsiaCity_Gym_Text_PhilPostBattle::
    .string "M'has impressionat!\n"
    .string "Aquí tens una pista!\p"
    .string "Busca bé els forats a les\n"
    .string "parets invisibles!$"

FuchsiaCity_Gym_EventScript_Edgar::
	trainerbattle_single TRAINER_TAMER_EDGAR, FuchsiaCity_Gym_Text_EdgarIntro, FuchsiaCity_Gym_Text_EdgarDefeat
	msgbox FuchsiaCity_Gym_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_Text_EdgarIntro::
    .string "Jo també estudio el camí del\n"
    .string "ninja amb el Mestre Koga!\p"
    .string "Els ninja tenen una llarga\n"
    .string "història d'usar animals!$"

FuchsiaCity_Gym_Text_EdgarDefeat::
    .string "Auuu!$"

FuchsiaCity_Gym_Text_EdgarPostBattle::
    .string "Encara em queda molt per\n"
    .string "aprendre.$"

FuchsiaCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_JUGGLER_KIRK, FuchsiaCity_Gym_Text_KirkIntro, FuchsiaCity_Gym_Text_KirkDefeat
	msgbox FuchsiaCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_Text_KirkIntro::
    .string "Abans era mag.\p"
    .string "Però somiava ser ninja, així\n"
    .string "que vaig unir-me a aquest gimnàs.$"

FuchsiaCity_Gym_Text_KirkDefeat::
    .string "Estic acabat!$"

FuchsiaCity_Gym_Text_KirkPostBattle::
    .string "Tot i perdre, seguiré entrenant\n"
    .string "seguint els ensenyaments de\l"
    .string "Koga, el meu mestre ninja.$"

FuchsiaCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_JUGGLER_SHAWN, FuchsiaCity_Gym_Text_ShawnIntro, FuchsiaCity_Gym_Text_ShawnDefeat
	msgbox FuchsiaCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_Text_ShawnIntro::
    .string "El Mestre Koga prové d'una llarga\n"
    .string "línia de ninjas.\p"
    .string "Tu de què descendeixes?$"

FuchsiaCity_Gym_Text_ShawnDefeat::
    .string "Ets més hàbil del que\n"
    .string "pensava!$"

FuchsiaCity_Gym_Text_ShawnPostBattle::
    .string "On hi ha llum, hi ha ombra!\p"
    .string "Llum i ombra!\n"
    .string "Quin tries?$"

FuchsiaCity_Gym_EventScript_Kayden::
	trainerbattle_single TRAINER_JUGGLER_KAYDEN, FuchsiaCity_Gym_Text_KaydenIntro, FuchsiaCity_Gym_Text_KaydenDefeat
	msgbox FuchsiaCity_Gym_Text_KaydenPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_Text_KaydenIntro::
    .string "La força no ho és tot en Pokémon.\n"
    .string "Ho entens?\p"
    .string "Pokémon va d'estratègia!\p"
    .string "Et mostraré com l'estratègia\n"
    .string "venç la força bruta.$"

FuchsiaCity_Gym_Text_KaydenDefeat::
    .string "Què?\n"
    .string "Extraordinari!$"

FuchsiaCity_Gym_Text_KaydenPostBattle::
    .string "Combines força i intel·ligència?\n"
    .string "Bona estratègia!\p"
    .string "Remarcable per a un entrenador\n"
    .string "tan jove.$"

FuchsiaCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_JUGGLER_NATE, FuchsiaCity_Gym_Text_NateIntro, FuchsiaCity_Gym_Text_NateDefeat
	msgbox FuchsiaCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_Text_NateIntro::
    .string "A veure si pots amb les meves\n"
    .string "tècniques especials!$"

FuchsiaCity_Gym_Text_NateDefeat::
    .string "M'has enganyat!$"

FuchsiaCity_Gym_Text_NatePostBattle::
    .string "M'agraden les tècniques de verí\n"
    .string "i son, perquè perduren després\l"
    .string "del combat!$"

FuchsiaCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE05_GET, FuchsiaCity_Gym_EventScript_GymGuyPostVictory
	msgbox FuchsiaCity_Gym_Text_GymGuyAdvice
	release
	end

FuchsiaCity_Gym_Text_GymGuyAdvice::
    .string "Ei!\n"
    .string "Futur campió!\p"
    .string "El Gimnàs Fuchsia és un lloc\n"
    .string "ple de trampes. Està ple\l"
    .string "de parets invisibles!\p"
    .string "Koga pot semblar a prop, però\n"
    .string "està bloquejat.\p"
    .string "Has de trobar forats a les\n"
    .string "parets per arribar-hi.$"

FuchsiaCity_Gym_EventScript_GymGuyPostVictory::
	msgbox FuchsiaCity_Gym_Text_GymGuyPostVictory
	release
	end

FuchsiaCity_Gym_Text_GymGuyPostVictory::
    .string "Impressiona com els ninjas\n"
    .string "encara aterren, fins avui!$"

FuchsiaCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE05_GET, FuchsiaCity_Gym_EventScript_GymStatuePostVictory
	msgbox FuchsiaCity_Gym_Text_GymStatue
	releaseall
	end

FuchsiaCity_Gym_EventScript_GymStatuePostVictory::
	msgbox FuchsiaCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

FuchsiaCity_Gym_Text_GymStatue::
    .string "Gimnàs Pokémon de Fuchsia\n"
    .string "Líder: Koga\p"
    .string "Entrenadors guanyadors:\n"
    .string "{RIVAL}$"

FuchsiaCity_Gym_Text_GymStatuePlayerWon::
    .string "Gimnàs Pokémon de Fuchsia\n"
    .string "Líder: Koga\p"
    .string "Entrenadors guanyadors:\n"
    .string "{RIVAL}, {PLAYER}$"


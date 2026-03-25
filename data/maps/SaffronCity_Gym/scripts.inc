SaffronCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_Gym_OnTransition
	.byte 0

SaffronCity_Gym_OnTransition::
	call_if_unset FLAG_DAILY_SABRINA_REMATCH, SaffronCity_Gym_ResetRematchFlags
	end

SaffronCity_Gym_ResetRematchFlags::
	cleartrainerflag LEADER_REMATCH_SABRINA_ORIGINAL
	cleartrainerflag LEADER_REMATCH_SABRINA_POSTGAME
	return

SaffronCity_Gym_EventScript_Johan::
	trainerbattle_single TRAINER_PSYCHIC_JOHANNA, SaffronCity_Gym_Text_JohanIntro, SaffronCity_Gym_Text_JohanDefeat
	msgbox SaffronCity_Gym_Text_JohanPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_JohanIntro::
    .string "El nostre poder invisible et fa\n"
    .string "por?$"

SaffronCity_Gym_Text_JohanDefeat::
    .string "No ho havia previst!$"

SaffronCity_Gym_Text_JohanPostBattle::
    .string "Els Pokémon Psíquics només temen\n"
    .string "fantasmes i insectes!$"

SaffronCity_Gym_EventScript_Tyron::
	trainerbattle_single TRAINER_PSYCHIC_TRISH, SaffronCity_Gym_Text_TyronIntro, SaffronCity_Gym_Text_TyronDefeat
	msgbox SaffronCity_Gym_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_TyronIntro::
    .string "Ho entens, oi?\p"
    .string "Que només amb força no n'hi ha\n"
    .string "prou al món dels Pokémon?$"

SaffronCity_Gym_Text_TyronDefeat::
    .string "No m'ho crec!$"

SaffronCity_Gym_Text_TyronPostBattle::
    .string "Sabrina acaba de derrotar el\n"
    .string "Mestre de Karate del costat.$"

SaffronCity_Gym_EventScript_Cameron::
	trainerbattle_single TRAINER_PSYCHIC_CAMERON, SaffronCity_Gym_Text_CameronIntro, SaffronCity_Gym_Text_CameronDefeat
	msgbox SaffronCity_Gym_Text_CameronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_CameronIntro::
    .string "Sabrina és jove, però és la\n"
    .string "nostra Líder d'alt nivell.\p"
    .string "No hi arribaràs fàcilment!$"

SaffronCity_Gym_Text_CameronDefeat::
    .string "Au!\n"
    .string "Fora de combat!$"

SaffronCity_Gym_Text_CameronPostBattle::
    .string "Hi havia dos Gimnasos Pokémon\n"
    .string "a Saffron.\p"
    .string "El Dojo de Lluita del costat va\n"
    .string "perdre l'estatus de Gimnàs.\p"
    .string "Els vam esclafar quan es va\n"
    .string "decidir tenir-ne un de sol.$"

SaffronCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PSYCHIC_PRESTON, SaffronCity_Gym_Text_PrestonIntro, SaffronCity_Gym_Text_PrestonDefeat
	msgbox SaffronCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_PrestonIntro::
    .string "El Gimnàs Pokémon de Saffron és\n"
    .string "famós per entrenar psíquics.\p"
    .string "Vols veure Sabrina, oi?\n"
    .string "Ho puc notar!$"

SaffronCity_Gym_Text_PrestonDefeat::
    .string "Arrrgh!$"

SaffronCity_Gym_Text_PrestonPostBattle::
    .string "Exacte! He fet servir la telepatia\n"
    .string "per llegir-te la ment!$"

SaffronCity_Gym_EventScript_Amanda::
	trainerbattle_single TRAINER_CHANNELER_AMANDA, SaffronCity_Gym_Text_AmandaIntro, SaffronCity_Gym_Text_AmandaDefeat
	msgbox SaffronCity_Gym_Text_AmandaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_AmandaIntro::
    .string "Sabrina és molt més jove que jo,\n"
    .string "però s'ha guanyat el meu respecte.$"

SaffronCity_Gym_Text_AmandaDefeat::
    .string "No n'hi ha prou!$"

SaffronCity_Gym_Text_AmandaPostBattle::
    .string "En un combat entre iguals, el que\n"
    .string "té més voluntat guanya.\p"
    .string "Si vols guanyar Sabrina, concentra't\n"
    .string "i desitja la victòria.$"

SaffronCity_Gym_EventScript_Stacy::
	trainerbattle_single TRAINER_CHANNELER_STACY, SaffronCity_Gym_Text_StacyIntro, SaffronCity_Gym_Text_StacyDefeat
	msgbox SaffronCity_Gym_Text_StacyPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_StacyIntro::
    .string "Els Pokémon s'assemblen als seus\n"
    .string "entrenadors.\p"
    .string "Els teus Pokémon han de ser durs!$"

SaffronCity_Gym_Text_StacyDefeat::
    .string "Ho sabia!$"

SaffronCity_Gym_Text_StacyPostBattle::
    .string "Encara tinc molt a aprendre…\p"
    .string "He de dominar Psíquic i\n"
    .string "ensenyar-lo als meus Pokémon…$"

SaffronCity_Gym_EventScript_Tasha::
	trainerbattle_single TRAINER_CHANNELER_TASHA, SaffronCity_Gym_Text_TashaIntro, SaffronCity_Gym_Text_TashaDefeat
	msgbox SaffronCity_Gym_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_TashaIntro::
    .string "Tu i jo, els nostres Pokémon\n"
    .string "lluitaran!$"

SaffronCity_Gym_Text_TashaDefeat::
    .string "He perdut al final!$"

SaffronCity_Gym_Text_TashaPostBattle::
    .string "Sabia que això passaria.$"


SaffronCity_Gym_EventScript_Sabrina::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE06_GET, SaffronCity_Gym_EventScript_ChallengeLeader
	goto_if_unset FLAG_GOT_SABRINA_REWARD, SaffronCity_Gym_EventScript_GetTM
	goto_if_unset FLAG_DAILY_SABRINA_REMATCH, SaffronCity_Gym_EventScript_RematchLeader
	goto SaffronCity_Gym_EventScript_LeaderPostBattle
	end

SaffronCity_Gym_EventScript_ChallengeLeader::
	msgbox SaffronCity_Gym_Text_LeaderSpeech, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_SABRINA, SaffronCity_Gym_Text_LeaderIntro, SaffronCity_Gym_Text_LeaderDefeat, SaffronCity_Gym_EventScript_DefeatedLeaderGetBadge
	end

SaffronCity_Gym_Text_LeaderSpeech::
    .string "Havia tingut una visió de la\n"
    .string "teva arribada.\p"
    .string "Tinc poders psíquics des que\n"
    .string "era petita.\p"
    .string "Va començar quan una cullera\n"
    .string "que vaig llançar es va doblegar.$"

SaffronCity_Gym_Text_LeaderIntro::
    .string "No m'agrada lluitar, però si\n"
    .string "vols, et mostraré els meus\l"
    .string "poders!$"

SaffronCity_Gym_Text_LeaderDefeat::
    .string "Aquesta derrota em sorprèn!\n"
    .string "Però una derrota és una derrota.$"

SaffronCity_Gym_EventScript_DefeatedLeaderGetBadge::
	msgbox SaffronCity_Gym_Text_GetBadge, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	message SaffronCity_Gym_Text_ReceivedBadge
	waitfanfare
	waitmessage
	msgbox SaffronCity_Gym_Text_ExplainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE06_GET
	setflag FLAG_DAILY_SABRINA_REMATCH
	settrainerflag TRAINER_PSYCHIC_PRESTON
	settrainerflag TRAINER_PSYCHIC_CAMERON
	settrainerflag TRAINER_CHANNELER_TASHA
	settrainerflag TRAINER_PSYCHIC_TRISH
	settrainerflag TRAINER_CHANNELER_STACY
	settrainerflag TRAINER_PSYCHIC_JOHANNA
	settrainerflag TRAINER_CHANNELER_AMANDA
	call_if_set FLAG_RECEIVED_AIDE_AMULET_COIN, SaffronCity_Gym_EventScript_QueueNextAideCall
	goto SaffronCity_Gym_EventScript_GetTM
	end

SaffronCity_Gym_EventScript_QueueNextAideCall::
	setflag FLAG_QUEUE_AIDE_CALL
    setflag FLAG_AIDE_LOCATION_5
    return

SaffronCity_Gym_Text_GetBadge::
    .string "Admeto que no m'he esforçat\n"
    .string "prou per guanyar.\p"
    .string "La teva victòria t'ha valgut\n"
    .string "la Medalla Pantà.$"

SaffronCity_Gym_Text_ReceivedBadge::
	.string "{PLAYER} ha rebut la Medalla\n"
    .string "Ànima de Sabrina!$"

SaffronCity_Gym_Text_ExplainBadge::
    .string "La Medalla Pantà permet als teus\n"
    .string "Pokémon usar Trenca Roques.\p"
    .string "També farà que els Pokémon fins\n"
    .string "a Nv. 70 t'obeeixin.\p"
    .string "Els Pokémon més forts es tornaran\n"
    .string "salvatges, ignorant les teves\l"
    .string "ordres en combat.\p"
    .string "No puges massa els teus Pokémon\n"
    .string "per evitar aquest problema.$"

SaffronCity_Gym_EventScript_GetTM::
	msgbox SaffronCity_Gym_Text_TakeThisWithYou, MSGBOX_DEFAULT
	checkitemspace ITEM_TM04, 1
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Gym_EventScript_NoRoomForTM
	playfanfare MUS_OBTAIN_TMHM
	msgbox SaffronCity_Gym_Text_ReceivedTM, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_TM04, 1
	setflag FLAG_GOT_SABRINA_REWARD
	msgbox SaffronCity_Gym_Text_ExplainTM, MSGBOX_DEFAULT
	release
	end

SaffronCity_Gym_Text_TakeThisWithYou::
    .string "Espera, enduu-te aquesta MT.$"

SaffronCity_Gym_Text_ReceivedTM::
	.string "{PLAYER} ha rebut la MT04\n"
    .string "de Sabrina.$"

SaffronCity_Gym_Text_ExplainTM::
    .string "La MT04 és Calma Mental.\p"
    .string "Fa que el Pokémon es concentri\n"
    .string "per pujar At. Esp. i Def. Esp.$"

SaffronCity_Gym_EventScript_NoRoomForTM::
	msgbox SaffronCity_Gym_Text_NoRoomForTM, MSGBOX_DEFAULT
	release
	end

SaffronCity_Gym_Text_NoRoomForTM::
    .string "La teva Motxilla està plena.$"

SaffronCity_Gym_EventScript_LeaderPostBattle::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, SaffronCity_Gym_EventScript_LeaderPostBattleGameClear
	msgbox SaffronCity_Gym_Text_LeaderPostBattle, MSGBOX_DEFAULT
	release
	end

SaffronCity_Gym_Text_LeaderPostBattle::
    .string "El poder psíquic no és una cosa\n"
    .string "que només uns pocs tenen.\p"
    .string "Tothom té poder psíquic.\n"
    .string "La gent simplement no se n'adona.$"

SaffronCity_Gym_EventScript_LeaderPostBattleGameClear::
	msgbox SaffronCity_Gym_Text_PostBattleGameClear, MSGBOX_DEFAULT
	release
	end

SaffronCity_Gym_Text_PostBattleGameClear::
	.string "Ho has fet molt bé.\p"
	.string "Si no puc igualar-te ara, només\n"
	.string "puc seguir entrenant.\p"
	.string "Continua posant a prova la\n"
	.string "teva habilitat!$"

SaffronCity_Gym_EventScript_RematchLeader::
	msgbox SaffronCity_Gym_Text_RematchLeader, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Gym_EventScript_DeclineRematch
	goto_if_set FLAG_SYS_GAME_CLEAR, SaffronCity_Gym_EventScript_PostgameRematch
	goto SaffronCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

SaffronCity_Gym_Text_RematchLeader::
	.string "...És cert que el poder psíquic\n"
	.string "és una habilitat potent.\p"
	.string "No obstant, hi ha coses que no\n"
	.string "es poden superar només amb\l"
	.string "aquest poder.\p"
	.string "Finalment ho entenc, després de\n"
	.string "perdre contra tu l'últim cop.\p"
	.string "No dependré només del poder\n"
	.string "psíquic aquesta vegada.\p"
	.string "La meva veritable força...el meu\n"
	.string "veritable jo...\p"
	.string "Permet-me posar-los a prova\n"
	.string "contra tu!$"

SaffronCity_Gym_EventScript_DeclineRematch::
	msgbox SaffronCity_Gym_Text_DeclineRematch, MSGBOX_DEFAULT
	release
	end

SaffronCity_Gym_Text_DeclineRematch::
	.string "Havia previst aquesta\n"
	.string "possibilitat...$"

SaffronCity_Gym_EventScript_PostgameRematch::
	msgbox SaffronCity_Gym_Text_RematchMode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_Gym_EventScript_LeaderRematch_PostGameTeam
	goto SaffronCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

SaffronCity_Gym_Text_RematchMode::
	.string "Ara que ets el campió, vols\n"
	.string "anar amb tot?$"

SaffronCity_Gym_EventScript_LeaderRematch_OriginalTeam::
	trainerbattle_single LEADER_REMATCH_SABRINA_ORIGINAL, SaffronCity_Gym_Text_RematchOriginal, SaffronCity_Gym_Text_RematchDefeat, SaffronCity_Gym_EventScript_DefeatedLeaderRematch
	end

SaffronCity_Gym_Text_RematchOriginal::
	.string "Mirem el nostre passat per\n"
	.string "descobrir el nostre futur!$"

SaffronCity_Gym_EventScript_LeaderRematch_PostGameTeam::
	trainerbattle_single LEADER_REMATCH_SABRINA_POSTGAME, SaffronCity_Gym_Text_RematchPostgame, SaffronCity_Gym_Text_RematchDefeat, SaffronCity_Gym_EventScript_DefeatedLeaderRematch
	end

SaffronCity_Gym_Text_RematchPostgame::
	.string "Havia previst que vindries mirant\n"
	.string "el futur.\p"
	.string "Però intencionadament no vaig\n"
	.string "mirar qui guanyaria el combat.\p"
	.string "Descobrim-ho junts!$"

SaffronCity_Gym_EventScript_DefeatedLeaderRematch::
	setflag FLAG_DAILY_SABRINA_REMATCH
	goto SaffronCity_Gym_EventScript_LeaderPostBattle
	end

SaffronCity_Gym_Text_RematchDefeat::
	.string "No trobaré un Entrenador com tu\n"
	.string "en uns tres anys.$"


SaffronCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE06_GET, SaffronCity_Gym_EventScript_GymGuyPostVictory
	msgbox SaffronCity_Gym_Text_GymGuyAdvice
	release
	end

SaffronCity_Gym_Text_GymGuyAdvice::
    .string "Ei!\n"
    .string "Futur campió!\p"
    .string "Els Pokémon de Sabrina fan servir\n"
    .string "poder psíquic en lloc de força.\p"
    .string "Els Pokémon de Lluita són\n"
    .string "especialment febles contra els\l"
    .string "Pokémon Psíquics.\p"
    .string "Seran destruïts abans de poder\n"
    .string "llançar un cop!$"

SaffronCity_Gym_EventScript_GymGuyPostVictory::
	msgbox SaffronCity_Gym_Text_GymGuyPostVictory
	release
	end

SaffronCity_Gym_Text_GymGuyPostVictory::
    .string "Poder psíquic, eh?\p"
    .string "Si jo tingués això, faria fortuna\n"
    .string "a les màquines escurabutxaques!$"

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_Text_GymStatue::
    .string "Gimnàs Pokémon de Saffron\n"
    .string "Líder: Sabrina\p"
    .string "Entrenadors guanyadors:\n"
    .string "{RIVAL}$"

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SaffronCity_Gym_Text_GymStatuePlayerWon::
    .string "Gimnàs Pokémon de Saffron\n"
    .string "Líder: Sabrina\p"
    .string "Entrenadors guanyadors:\n"
    .string "{RIVAL}, {PLAYER}$"

CeladonCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_Gym_OnTransition
	.byte 0

CeladonCity_Gym_OnTransition::
	call_if_unset FLAG_DAILY_ERIKA_REMATCH, CeladonCity_Gym_ResetRematchFlags
	end

CeladonCity_Gym_ResetRematchFlags::
	cleartrainerflag LEADER_REMATCH_ERIKA_ORIGINAL
	cleartrainerflag LEADER_REMATCH_ERIKA_POSTGAME
	return

CeladonCity_Gym_EventScript_Erika::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE04_GET, CeladonCity_Gym_EventScript_ChallengeLeader
	goto_if_unset FLAG_GOT_ERIKA_REWARD, CeladonCity_Gym_EventScript_GetTM
	goto_if_unset FLAG_DAILY_ERIKA_REMATCH, CeladonCity_Gym_EventScript_RematchLeader
	goto CeladonCity_Gym_EventScript_LeaderPostBattle
	end

CeladonCity_Gym_EventScript_ChallengeLeader::
	msgbox CeladonCity_Gym_Text_LeaderSpeech, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_ERIKA, CeladonCity_Gym_Text_LeaderIntro, CeladonCity_Gym_Text_LeaderDefeat, CeladonCity_Gym_EventScript_DefeatedLeaderGetBadge
	end

CeladonCity_Gym_Text_LeaderSpeech::
    .string "Hola…\n"
    .string "Bon temps, oi?\l"
    .string "Molt agradable…\p"
    .string "…Oh, vaja…\n"
    .string "M'he quedat adormida. Benvingut.\p"
    .string "Em dic Erika.\n"
    .string "Sóc la Líder del Gimnàs Celadon.\p"
    .string "Sóc estudiant de l'art de\n"
    .string "l'arranjament floral.\p"
    .string "Els meus Pokémon són únicament\n"
    .string "de tipus Planta.$"


CeladonCity_Gym_Text_LeaderIntro::
    .string "…Oh, perdona, no sabia que\n"
    .string "volies desafiar-me.\p"
    .string "Molt bé, però no perdré.$"

CeladonCity_Gym_Text_LeaderDefeat::
    .string "Oh!\n"
    .string "Accepto la derrota.$"

CeladonCity_Gym_EventScript_DefeatedLeaderGetBadge::
	msgbox CeladonCity_Gym_Text_GetBadge, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	message CeladonCity_Gym_Text_ReceivedBadge
	waitfanfare
	waitmessage
	msgbox CeladonCity_Gym_Text_ExplainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE04_GET
	setflag FLAG_DAILY_ERIKA_REMATCH
	settrainerflag TRAINER_LASS_KAY
	settrainerflag TRAINER_LASS_LISA
	settrainerflag TRAINER_PICNICKER_TINA
	settrainerflag TRAINER_BEAUTY_BRIDGET
	settrainerflag TRAINER_BEAUTY_TAMIA
	settrainerflag TRAINER_BEAUTY_LORI
	settrainerflag TRAINER_COOLTRAINER_MARY
	call_if_set FLAG_RECEIVED_AIDE_EVERSTONE, CeladonCity_Gym_EventScript_NextAideCall
	goto CeladonCity_Gym_EventScript_GetTM
	end

CeladonCity_Gym_EventScript_NextAideCall::
	setflag FLAG_QUEUE_AIDE_CALL
	setflag FLAG_AIDE_LOCATION_3
	return

CeladonCity_Gym_Text_GetBadge::
    .string "Ets extraordinàriament fort.\p"
    .string "He de concedir-te la Medalla\n"
    .string "Arc de Sant Martí.$"

CeladonCity_Gym_Text_ReceivedBadge::
	.string "{PLAYER} ha rebut la Medalla\n"
    .string "Arc de Sant Martí d'Erika!$"

CeladonCity_Gym_Text_ExplainBadge::
    .string "La Medalla Arc de Sant Martí farà\n"
    .string "que els Pokémon fins a Nv. 50\l"
    .string "t'obeixin.\p"
    .string "També permet als Pokémon usar\n"
    .string "Força dins i fora de combat.$"

CeladonCity_Gym_EventScript_GetTM::
	msgbox CeladonCity_Gym_Text_TakeThisWithYou, MSGBOX_DEFAULT
	checkitemspace ITEM_TM19, 1
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Gym_EventScript_NoRoomForTM
	playfanfare MUS_OBTAIN_TMHM
	msgbox CeladonCity_Gym_Text_ReceivedTM, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_TM19, 1
	setflag FLAG_GOT_ERIKA_REWARD
	msgbox CeladonCity_Gym_Text_ExplainTM, MSGBOX_DEFAULT
	release
	end

CeladonCity_Gym_Text_TakeThisWithYou::
    .string "Si us plau, pren també això.$"

CeladonCity_Gym_Text_ReceivedTM::
	.string "{PLAYER} ha rebut la MT19\n"
    .string "d'Erika.$"

CeladonCity_Gym_Text_ExplainTM::
    .string "La MT19 conté Gigadrenatge.\p"
    .string "La meitat del dany que infligeix\n"
    .string "es drena per curar el teu Pokémon.\p"
    .string "No trobes que és un moviment\n"
    .string "meravellós?$"

CeladonCity_Gym_EventScript_NoRoomForTM::
	msgbox CeladonCity_Gym_Text_NoRoomForTM, MSGBOX_DEFAULT
	release
	end

CeladonCity_Gym_Text_NoRoomForTM::
    .string "Hauries de fer espai per a això.$"

CeladonCity_Gym_EventScript_LeaderPostBattle::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, CeladonCity_Gym_EventScript_LeaderPostBattleGameClear
	msgbox CeladonCity_Gym_Text_LeaderPostBattle, MSGBOX_DEFAULT
	release
	end

CeladonCity_Gym_Text_LeaderPostBattle::
    .string "Estàs catalogant Pokémon?\n"
    .string "He de dir que estic impressionada.\p"
    .string "Jo mai col·leccionaria Pokémon\n"
    .string "si no fossin atractius.$"

CeladonCity_Gym_EventScript_LeaderPostBattleGameClear::
	msgbox CeladonCity_Gym_Text_PostBattleGameClear, MSGBOX_DEFAULT
	release
	end

CeladonCity_Gym_Text_PostBattleGameClear::
	.string "Bon temps, oi?\p"
	.string "Molt agradable...\p"
	.string "Em fa por que m'adormi...$"

CeladonCity_Gym_EventScript_RematchLeader::
	msgbox CeladonCity_Gym_Text_RematchLeader, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Gym_EventScript_DeclineRematch
	goto_if_set FLAG_SYS_GAME_CLEAR, CeladonCity_Gym_EventScript_PostgameRematch
	goto CeladonCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

CeladonCity_Gym_Text_RematchLeader::
	.string "Oh, si no és qui està intentant\n"
	.string "completar la Pokédex.\p"
	.string "Espero que les coses t'hagin anat bé\n"
	.string "des de la nostra última trobada.\p"
	.string "...Ja veig. Has estat molt ocupat.\p"
	.string "No m'agraden gaire les coses\n"
	.string "públiques...\p"
	.string "No obstant, els combats són\n"
	.string "diferents. Per això has vingut, oi?$"

CeladonCity_Gym_EventScript_DeclineRematch::
	msgbox CeladonCity_Gym_Text_DeclineRematch, MSGBOX_DEFAULT
	release
	end

CeladonCity_Gym_Text_DeclineRematch::
	.string "Oh bé...potser un altre cop.$"

CeladonCity_Gym_EventScript_PostgameRematch::
	msgbox CeladonCity_Gym_Text_RematchMode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_Gym_EventScript_LeaderRematch_PostGameTeam
	goto CeladonCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

CeladonCity_Gym_Text_RematchMode::
	.string "Ara que ets el campió,\n"
	.string "vols anar amb tot?$"

CeladonCity_Gym_EventScript_LeaderRematch_OriginalTeam::
	trainerbattle_single LEADER_REMATCH_ERIKA_ORIGINAL, CeladonCity_Gym_Text_RematchOriginal, CeladonCity_Gym_Text_RematchDefeat, CeladonCity_Gym_EventScript_DefeatedLeaderRematch
	end

CeladonCity_Gym_Text_RematchOriginal::
	.string "Encantador, {PLAYER}!\n"
	.string "Estimem aquest record!$"

CeladonCity_Gym_EventScript_LeaderRematch_PostGameTeam::
	trainerbattle_single LEADER_REMATCH_ERIKA_POSTGAME, CeladonCity_Gym_Text_RematchPostgame, CeladonCity_Gym_Text_RematchDefeat, CeladonCity_Gym_EventScript_DefeatedLeaderRematch
	end

CeladonCity_Gym_Text_RematchPostgame::
	.string "Molt bé, {PLAYER}!\n"
	.string "Prepara't per un combat total!$"

CeladonCity_Gym_EventScript_DefeatedLeaderRematch::
	setflag FLAG_DAILY_ERIKA_REMATCH
	goto CeladonCity_Gym_EventScript_LeaderPostBattle
	end

CeladonCity_Gym_Text_RematchDefeat::
	.string "Simplement meravellós.\p"
	.string "Ha estat un esforç digne d'almenys\n"
	.string "10 Medalles Arc de Sant Martí.$"

CeladonCity_Gym_EventScript_Kay::
	trainerbattle_single TRAINER_LASS_KAY, CeladonCity_Gym_Text_KayIntro, CeladonCity_Gym_Text_KayDefeat
	msgbox CeladonCity_Gym_Text_KayPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_KayIntro::
    .string "T'hauria de parlar d'aquest\n"
    .string "Gimnàs.\p"
    .string "Aquí només s'admeten autèntiques\n"
    .string "senyores!$"

CeladonCity_Gym_Text_KayDefeat::
    .string "Ets massa brut!$"

CeladonCity_Gym_Text_KayPostBattle::
    .string "Bah!\n"
    .string "Espero que l'Erika t'esclafi!$"

CeladonCity_Gym_EventScript_Lisa::
	trainerbattle_single TRAINER_LASS_LISA, CeladonCity_Gym_Text_LisaIntro, CeladonCity_Gym_Text_LisaDefeat
	msgbox CeladonCity_Gym_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_LisaIntro::
    .string "Oh, ei!\p"
    .string "No ens agraden els Pokémon de\n"
    .string "tipus Insecte o Foc aquí!$"

CeladonCity_Gym_Text_LisaDefeat::
    .string "Oh!\n"
    .string "Tu!$"

CeladonCity_Gym_Text_LisaPostBattle::
    .string "La nostra Líder Erika pot ser\n"
    .string "tranquil·la, però és famosa aquí.$"

CeladonCity_Gym_EventScript_Tina::
	trainerbattle_single TRAINER_PICNICKER_TINA, CeladonCity_Gym_Text_TinaIntro, CeladonCity_Gym_Text_TinaDefeat
	msgbox CeladonCity_Gym_Text_TinaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_TinaIntro::
    .string "…No estaves espiant aquí\n"
    .string "abans?$"

CeladonCity_Gym_Text_TinaDefeat::
    .string "M'has obert els ulls!$"

CeladonCity_Gym_Text_TinaPostBattle::
    .string "Oh, miraves l'Erika…\n"
    .string "No em miraves a mi…$"

CeladonCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BEAUTY_BRIDGET, CeladonCity_Gym_Text_BridgetIntro, CeladonCity_Gym_Text_BridgetDefeat
	msgbox CeladonCity_Gym_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_BridgetIntro::
    .string "Oh, benvingut.\n"
    .string "M'estava avorrint.$"

CeladonCity_Gym_Text_BridgetDefeat::
    .string "El meu maquillatge!$"

CeladonCity_Gym_Text_BridgetPostBattle::
    .string "Els Pokémon de tipus Planta són\n"
    .string "forts contra el tipus Aigua.\p"
    .string "També tenen avantatge contra els\n"
    .string "Pokémon de tipus Roca i Terra.$"

CeladonCity_Gym_EventScript_Tamia::
	trainerbattle_single TRAINER_BEAUTY_TAMIA, CeladonCity_Gym_Text_TamiaIntro, CeladonCity_Gym_Text_TamiaDefeat
	msgbox CeladonCity_Gym_Text_TamiaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_TamiaIntro::
    .string "Mira, mira!\n"
    .string "Veus els meus Pokémon!\p"
    .string "M'agrada el tipus Planta.\n"
    .string "M'agrada com són fàcils de criar.$"

CeladonCity_Gym_Text_TamiaDefeat::
    .string "No!$"

CeladonCity_Gym_Text_TamiaPostBattle::
    .string "Només usem Pokémon de tipus\n"
    .string "Planta al nostre Gimnàs.\p"
    .string "Per què? També els fem servir\n"
    .string "per fer arranjaments florals!$"

CeladonCity_Gym_EventScript_Lori::
	trainerbattle_single TRAINER_BEAUTY_LORI, CeladonCity_Gym_Text_LoriIntro, CeladonCity_Gym_Text_LoriDefeat
	msgbox CeladonCity_Gym_Text_LoriPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_LoriIntro::
    .string "Encantada de conèixer-te.\n"
    .string "El meu hobby és entrenar Pokémon.$"

CeladonCity_Gym_Text_LoriDefeat::
    .string "Oh!\n"
    .string "Esplèndid!$"

CeladonCity_Gym_Text_LoriPostBattle::
    .string "Tinc una cita a cegues aviat.\n"
    .string "He d'aprendre a ser educada,\l"
    .string "sobretot si he de combatre.$"

CeladonCity_Gym_EventScript_Mary::
	trainerbattle_single TRAINER_COOLTRAINER_MARY, CeladonCity_Gym_Text_MaryIntro, CeladonCity_Gym_Text_MaryDefeat
	msgbox CeladonCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_MaryIntro::
    .string "Benvingut al Gimnàs Celadon!\p"
    .string "Millor que no subestimis\n"
    .string "les senyores d'aquí.$"

CeladonCity_Gym_Text_MaryDefeat::
    .string "Oh!\n"
    .string "Derrotada!$"

CeladonCity_Gym_Text_MaryPostBattle::
    .string "No he portat els meus millors\n"
    .string "Pokémon. Espera la propera!$"

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_Text_GymStatue::
    .string "Gimnàs POKémon de Celadon\n"
    .string "Líder: Erika\p"
    .string "Entrenadors guanyadors:\n"
    .string "{RIVAL}$"

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_GymStatuePlayerWon::
    .string "Gimnàs POKémon de Celadon\n"
    .string "Líder: Erika\p"
    .string "Entrenadors guanyadors:\n"
    .string "{RIVAL}, {PLAYER}$"

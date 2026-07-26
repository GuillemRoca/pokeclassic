CeruleanCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_Gym_OnTransition
	.byte 0

CeruleanCity_Gym_OnTransition::
	call_if_unset FLAG_DAILY_MISTY_REMATCH, CeruleanCity_Gym_ResetRematchFlags
	end

CeruleanCity_Gym_ResetRematchFlags::
	cleartrainerflag LEADER_REMATCH_MISTY_ORIGINAL
	cleartrainerflag LEADER_REMATCH_MISTY_POSTGAME
	return

CeruleanCity_Gym_EventScript_Misty::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_ChallengeMisty
	goto_if_unset FLAG_GOT_MISTY_REWARD, CeruleanCity_Gym_EventScript_GetTM
	goto_if_unset FLAG_DAILY_MISTY_REMATCH, CeruleanCity_Gym_EventScript_RematchLeader
	goto CeruleanCity_Gym_EventScript_LeaderPostBattle
	end

CeruleanCity_Gym_EventScript_ChallengeMisty::
	msgbox CeruleanCity_Gym_Text_MistySpeech, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_MISTY, CeruleanCity_Gym_Text_MistyIntro, CeruleanCity_Gym_Text_MistyDefeat, CeruleanCity_Gym_EventScript_DefeatedMistyGetBadge
	end

CeruleanCity_Gym_Text_MistySpeech::
    .string "Hola, ets una cara nova!\p"
    .string "Només els Entrenadors amb una\n"
    .string "filosofia sobre Pokémon poden\l"
    .string "ser professionals.\p"
    .string "Quina és la teva manera d'atrapar\n"
    .string "i entrenar Pokémon?$"

CeruleanCity_Gym_Text_MistyIntro::
    .string "La meva estratègia és l'atac\n"
    .string "total amb Pokémon d'Aigua!$"

CeruleanCity_Gym_Text_MistyDefeat::
	.string "Uau!\n"
    .string "Ets massa fort!\p"
    .string "D'acord!$"

CeruleanCity_Gym_EventScript_DefeatedMistyGetBadge::
	msgbox CeruleanCity_Gym_Text_GetBadge, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	message CeruleanCity_Gym_Text_ReceivedBadge
	waitfanfare
	waitmessage
	msgbox CeruleanCity_Gym_Text_ExplainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE02_GET
	setflag FLAG_DAILY_MISTY_REMATCH
	settrainerflag TRAINER_PICNICKER_DIANA
	settrainerflag TRAINER_SWIMMER_MALE_LUIS
	setflag FLAG_QUEUE_AIDE_CALL
	setflag FLAG_AIDE_LOCATION_1
	goto CeruleanCity_Gym_EventScript_GetTM
	end

CeruleanCity_Gym_Text_GetBadge::
    .string "Pots quedar-te la Medalla\n"
    .string "Cascada per demostrar que\l"
    .string "m'has vençut.$"

CeruleanCity_Gym_Text_ReceivedBadge::
	.string "{PLAYER} ha rebut la Medalla\n"
    .string "Cascada de la Misty!$"

CeruleanCity_Gym_Text_ExplainBadge::
	.string "La Medalla Cascada fa que tots\n"
    .string "els Pokémon fins a Nv. 30 obeixin.\p"
    .string "Això inclou els que has obtingut\n"
    .string "per intercanvi.\p"
    .string "A més, ara pots fer servir\n"
    .string "Tallar fora de combat.\p"
    .string "Pots Tallar arbrets per obrir\n"
    .string "nous camins.$"

CeruleanCity_Gym_EventScript_GetTM::
	msgbox CeruleanCity_Gym_Text_TakeThisWithYou, MSGBOX_DEFAULT
	checkitemspace ITEM_TM03, 1
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_Gym_EventScript_NoRoomForTM
	playfanfare MUS_OBTAIN_TMHM
	msgbox CeruleanCity_Gym_Text_ReceivedTM, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_TM03, 1
	setflag FLAG_GOT_MISTY_REWARD
	msgbox CeruleanCity_Gym_Text_ExplainTM, MSGBOX_DEFAULT
	call_if_eq VAR_SEA_COTTAGE_STATE, 3, CeruleanCity_Gym_EventScript_PrepDexNavCall
	release
	end

CeruleanCity_Gym_Text_TakeThisWithYou::
	 .string "També pots quedar-te la meva\n"
	 .string "MT preferida.$"

CeruleanCity_Gym_Text_ReceivedTM::
    .string "{PLAYER} ha rebut la MT03\n"
    .string "de la Misty.$"

CeruleanCity_Gym_Text_ExplainTM::
    .string "La MT03 ensenya Pols d'Aigua.\p"
    .string "Fes-la servir amb un Pokémon\n"
    .string "aquàtic!$"

CeruleanCity_Gym_EventScript_NoRoomForTM::
	msgbox CeruleanCity_Gym_Text_NoRoomForTM, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_Text_NoRoomForTM::
    .string "Fes espai per a això!$"

CeruleanCity_Gym_EventScript_LeaderPostBattle::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, CeruleanCity_Gym_EventScript_LeaderPostBattleGameClear
	msgbox CeruleanCity_Gym_Text_LeaderPostBattle, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_Text_LeaderPostBattle::
	.string "Misty: De vegades vull deixar\n"
	.string "enrere aquesta piscineta i\l"
	.string "nedar al gran blau!$"

CeruleanCity_Gym_EventScript_LeaderPostBattleGameClear::
	msgbox CeruleanCity_Gym_Text_PostBattleGameClear, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_Text_PostBattleGameClear::
	.string "Saps què?\p"
    .string "El meu somni era lluitar contra\n"
    .string "Entrenadors forts i ser Líder\l"
    .string "de Gimnàs...\p"
    .string "He complert el meu somni, i ara\n"
    .string "el següent és derrotar-te!$"

CeruleanCity_Gym_EventScript_RematchLeader::
	msgbox CeruleanCity_Gym_Text_RematchLeader, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_Gym_EventScript_DeclineRematch
	goto_if_set FLAG_SYS_GAME_CLEAR, CeruleanCity_Gym_EventScript_PostgameRematch
	goto CeruleanCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

CeruleanCity_Gym_Text_RematchLeader::
	.string "He sentit un rumor interessant!\p"
	.string "Tu i aquell altre noi heu estat\n"
	.string "lluitant contra l'Equip Rocket.\p"
	.string "És veritat?\p"
	.string "Argh! No aguanto més!\p"
	.string "T'has fet tan fort que necessito\n"
	.string "tornar a combatre contra tu!\p"
	.string "Ho tens clar? No pots dir que no!$"

CeruleanCity_Gym_EventScript_DeclineRematch::
	msgbox CeruleanCity_Gym_Text_DeclineRematch, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_Text_DeclineRematch::
	.string "Argh! Vinga! Lluita amb mi!$"

CeruleanCity_Gym_EventScript_PostgameRematch::
	msgbox CeruleanCity_Gym_Text_RematchMode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, CeruleanCity_Gym_EventScript_LeaderRematch_PostGameTeam
	goto CeruleanCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

CeruleanCity_Gym_Text_RematchMode::
	.string "Ara que ets el campió,\n"
	.string "vols anar amb tot?$"

CeruleanCity_Gym_EventScript_LeaderRematch_OriginalTeam::
	trainerbattle_single LEADER_REMATCH_MISTY_ORIGINAL, CeruleanCity_Gym_Text_RematchOriginal, CeruleanCity_Gym_Text_RematchDefeat, CeruleanCity_Gym_EventScript_DefeatedLeaderRematch
	end

CeruleanCity_Gym_Text_RematchOriginal::
	.string "D'acord, {PLAYER}!\n"
	.string "Som-hi!$"

CeruleanCity_Gym_EventScript_LeaderRematch_PostGameTeam::
	trainerbattle_single LEADER_REMATCH_MISTY_POSTGAME, CeruleanCity_Gym_Text_RematchPostgame, CeruleanCity_Gym_Text_RematchDefeat, CeruleanCity_Gym_EventScript_DefeatedLeaderRematch
	end

CeruleanCity_Gym_Text_RematchPostgame::
	.string "Els meus adorables Pokémon estan\n"
	.string "preparats per enfrontar-te!\p"
	.string "L'ofensiva definitiva de\n"
	.string "Pokémon de tipus Aigua!\p"
	.string "Espero que estiguis preparat!$"

CeruleanCity_Gym_EventScript_DefeatedLeaderRematch::
	setflag FLAG_DAILY_MISTY_REMATCH
	goto CeruleanCity_Gym_EventScript_LeaderPostBattle
	end

CeruleanCity_Gym_Text_RematchDefeat::
	.string "Hmph! Que molest!$"


CeruleanCity_Gym_EventScript_PrepDexNavCall::
	setvar VAR_SEA_COTTAGE_STATE, 4
	return

CeruleanCity_Gym_EventScript_Diana::
	trainerbattle_single TRAINER_PICNICKER_DIANA, CeruleanCity_Gym_Text_DianaIntro, CeruleanCity_Gym_Text_DianaDefeat
	msgbox CeruleanCity_Gym_Text_DianaPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_Text_DianaIntro::
    .string "Què? Tu?\n"
    .string "Sóc més que suficient per a tu!\p"
    .string "La Misty no s'haurà de molestar.$"

CeruleanCity_Gym_Text_DianaDefeat::
    .string "M'has aclaparat!$"

CeruleanCity_Gym_Text_DianaPostBattle::
    .string "Has d'enfrontar-te a altres\n"
    .string "Entrenadors per saber com\l"
    .string "de bo ets realment.$"

CeruleanCity_Gym_EventScript_Luis::
	trainerbattle_single TRAINER_SWIMMER_MALE_LUIS, CeruleanCity_Gym_Text_LuisIntro, CeruleanCity_Gym_Text_LuisDefeat
	msgbox CeruleanCity_Gym_Text_LuisPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_Text_LuisIntro::
    .string "Splash!\p"
    .string "Sóc el primer!\n"
    .string "Som-hi!$"

CeruleanCity_Gym_Text_LuisDefeat::
    .string "No pot ser!$"

CeruleanCity_Gym_Text_LuisPostBattle::
    .string "La Misty és una Entrenadora que\n"
    .string "seguirà millorant.\p"
    .string "No perdrà contra algú com tu!$"

CeruleanCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_GymGuyPostVictory
	msgbox CeruleanCity_Gym_Text_GymGuyAdvice, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_Text_GymGuyAdvice::
    .string "Ei!\n"
    .string "Futur campió!\p"
    .string "Deixa'm donar-te un consell!\p"
    .string "La Líder, Misty, és una pro\n"
    .string "dels Pokémon d'Aigua.\p"
    .string "Pots buidar tota la seva aigua\n"
    .string "amb Pokémon de tipus Planta.\p"
    .string "O pots fer servir Pokémon de\n"
    .string "tipus Elèctric i fulminar-los!$"

CeruleanCity_Gym_EventScript_GymGuyPostVictory::
	msgbox CeruleanCity_Gym_Text_WeMakePrettyGoodTeam, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_Text_WeMakePrettyGoodTeam::
    .string "Has vençut la Misty!\n"
    .string "Veus? Què et deia?\p"
    .string "Tu i jo, noi, fem un equip\n"
    .string "de primera!$"

CeruleanCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeruleanCity_Gym_Text_GymStatue, MSGBOX_SIGN
	releaseall
	end

CeruleanCity_Gym_Text_GymStatue::
    .string "Gimnàs Pokémon de Cerulean\n"
    .string "Líder: Misty\p"
    .string "Entrenadors guanyadors:\n"
    .string "{RIVAL}$"

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon, MSGBOX_SIGN
	releaseall
	end

CeruleanCity_Gym_Text_GymStatuePlayerWon::
    .string "Gimnàs Pokémon de Cerulean\n"
    .string "Líder: Misty\p"
    .string "Entrenadors guanyadors:\n"
    .string "{RIVAL}, {PLAYER}$"

.set LOCALID_GIOVANNI, 1
.set LOCALID_RIVAL, 2

ViridianCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_Gym_OnTransition
	.byte 0

ViridianCity_Gym_OnTransition::
	call_if_unset FLAG_DAILY_RIVAL_REMATCH, ViridianCity_Gym_ResetRematchFlags
	end

ViridianCity_Gym_ResetRematchFlags::
	cleartrainerflag TRAINER_RIVAL_POSTGAME_JOLTEON
	cleartrainerflag TRAINER_RIVAL_POSTGAME_FLAREON
	cleartrainerflag TRAINER_RIVAL_POSTGAME_VAPOREON
	return

ViridianCity_Gym_EventScript_Giovanni::
	msgbox ViridianCity_Gym_Text_GiovanniSpeech, MSGBOX_NPC
	trainerbattle_single TRAINER_LEADER_GIOVANNI, ViridianCity_Gym_Text_GiovanniIntro, ViridianCity_Gym_Text_GiovanniDefeat, ViridianCity_Gym_EventScript_DefeatedGiovanni
	goto_if_unset FLAG_GOT_GIOVANNI_REWARD, ViridianCity_Gym_EventScript_GiveTM26
	msgbox ViridianCity_Gym_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_GIOVANNI
	fadescreen FADE_FROM_BLACK
	release
	end

ViridianCity_Gym_Text_GiovanniSpeech::
    .string "Fwahahaha!\n"
    .string "Benvingut al meu amagatall!\p"
    .string "Així serà fins que pugui restaurar\n"
    .string "l'Equip Rocket a la seva antiga\l"
    .string "glòria.\p"
    .string "Però m'has trobat de nou.\n"
    .string "Que així sigui.$"

ViridianCity_Gym_Text_GiovanniIntro::
    .string "Aquest cop no em contindré!\p"
    .string "Una vegada més, t'enfrontaràs\n"
    .string "a Giovanni, el millor Entrenador!$"

ViridianCity_Gym_Text_GiovanniPostBattle::
    .string "Havent perdut d'aquesta manera,\n"
    .string "no puc mirar els meus seguidors\l"
    .string "a la cara.\l"
    .string "He traït la seva confiança.\p"
    .string "A partir d'avui, l'Equip Rocket\n"
    .string "s'ha acabat per sempre!\p"
    .string "Quant a mi, em dedicaré\n"
    .string "a entrenar de nou.\p"
    .string "Retrobem-nos algun dia!\n"
    .string "Adéu!$"

ViridianCity_Gym_Text_GiovanniDefeat::
    .string "Ha!\n"
    .string "Ha estat un combat molt intens.$"

ViridianCity_Gym_Text_GiovanniGiveBadge::
    .string "Has guanyat!\p"
    .string "Com a prova, aquí tens la\n"
    .string "Medalla Terra!$"

ViridianCity_Gym_Text_ReceivedBadgeFromGiovanni::
    .string "{PLAYER} ha rebut la Medalla\n"
    .string "Terra de Giovanni.$"

ViridianCity_Gym_EventScript_DefeatedGiovanni::
	msgbox ViridianCity_Gym_Text_GiovanniGiveBadge
	playfanfare MUS_OBTAIN_BADGE
	message ViridianCity_Gym_Text_ReceivedBadgeFromGiovanni
	waitmessage
	waitfanfare
	settrainerflag 	TRAINER_TAMER_JASON
	settrainerflag 	TRAINER_TAMER_COLE
	settrainerflag 	TRAINER_BLACK_BELT_ATSUSHI
	settrainerflag 	TRAINER_BLACK_BELT_KIYO
	settrainerflag 	TRAINER_BLACK_BELT_TAKASHI
	settrainerflag 	TRAINER_COOLTRAINER_SAMUEL
	settrainerflag 	TRAINER_COOLTRAINER_YUJI
	settrainerflag 	TRAINER_COOLTRAINER_WARREN
	setflag FLAG_BADGE08_GET
	setvar VAR_ROUTE_22_RIVAL_STATE, 4
	goto ViridianCity_Gym_EventScript_GiveTM26
	end

ViridianCity_Gym_EventScript_GiveTM26::
	msgbox ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis
	checkitemspace ITEM_TM26, 1
	compare VAR_RESULT, FALSE
	goto_if_eq ViridianCity_Gym_EventScript_NoRoomForTM26
	playfanfare MUS_OBTAIN_TMHM
	message ViridianCity_Gym_Text_ReceivedTM26FromGiovanni
	waitmessage
	waitfanfare
	additem ITEM_TM26, 1
	setflag FLAG_GOT_GIOVANNI_REWARD
	msgbox ViridianCity_Gym_Text_ExplainTM26
	release
	end

ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis::
    .string "La Medalla Terra fa que Pokémon\n"
    .string "de qualsevol nivell obeixin\l"
    .string "sense qüestionar.\p"
    .string "És la prova del teu domini com\n"
    .string "a Entrenador Pokémon.\p"
    .string "Amb ella, pots desafiar la\n"
    .string "Lliga Pokémon.\p"
    .string "A més, pren aquesta MT.\p"
    .string "Considera-ho un regal per al teu\n"
    .string "desafiament a la Lliga Pokémon.$"

ViridianCity_Gym_Text_ReceivedTM26FromGiovanni::
    .string "{PLAYER} ha rebut la MT26\n"
    .string "de Giovanni.$"

ViridianCity_Gym_EventScript_NoRoomForTM26::
	msgbox ViridianCity_Gym_Text_YouDoNotHaveSpace
	release
	end

ViridianCity_Gym_Text_ExplainTM26::
    .string "La MT26 conté Terratrèmol.\p"
    .string "És un atac poderós que causa\n"
    .string "un tremolor massiu.\p"
    .string "El vaig crear quan dirigia el\n"
    .string "Gimnàs d'aquí, fa molt de temps…$"

ViridianCity_Gym_Text_YouDoNotHaveSpace::
    .string "No tens espai per a això!\p"
    .string "No em quedaré aquí gaire temps.\p"
    .string "Hauries de fer espai i tornar\n"
    .string "a parlar amb mi.$"


ViridianCity_Gym_EventScript_Jason::
	trainerbattle_single TRAINER_TAMER_JASON, ViridianCity_Gym_Text_JasonIntro, ViridianCity_Gym_Text_JasonDefeat
	msgbox ViridianCity_Gym_Text_JasonPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_JasonIntro::
    .string "Els Pokémon i jo fem una música\n"
    .string "meravellosa junts!$"

ViridianCity_Gym_Text_JasonDefeat::
    .string "Esteu en perfecta harmonia!$"

ViridianCity_Gym_Text_JasonPostBattle::
    .string "Saps la identitat del nostre\n"
    .string "Líder de Gimnàs?$"

ViridianCity_Gym_EventScript_Cole::
	trainerbattle_single TRAINER_TAMER_COLE, ViridianCity_Gym_Text_ColeIntro, ViridianCity_Gym_Text_ColeDefeat
	msgbox ViridianCity_Gym_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_ColeIntro::
    .string "Els teus Pokémon s'acovardiran\n"
    .string "amb el sonar del meu fuet!$"

ViridianCity_Gym_Text_ColeDefeat::
    .string "Au!\n"
    .string "Fuetada!$"

ViridianCity_Gym_Text_ColePostBattle::
    .string "Espera!\n"
    .string "Ha estat un descuit!$"

ViridianCity_Gym_EventScript_Atsushi::
	trainerbattle_single TRAINER_BLACK_BELT_ATSUSHI, ViridianCity_Gym_Text_AtsushiIntro, ViridianCity_Gym_Text_AtsushiDefeat
	msgbox ViridianCity_Gym_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_AtsushiIntro::
    .string "Rrrroar!\n"
    .string "M'estic enfurismant!$"

ViridianCity_Gym_Text_AtsushiDefeat::
    .string "Wargh!$"

ViridianCity_Gym_Text_AtsushiPostBattle::
    .string "Encara no en sóc digne!$"

ViridianCity_Gym_EventScript_Kiyo::
	trainerbattle_single TRAINER_BLACK_BELT_KIYO, ViridianCity_Gym_Text_KiyoIntro, ViridianCity_Gym_Text_KiyoDefeat
	msgbox ViridianCity_Gym_Text_KiyoPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_KiyoIntro::
    .string "El karate és la forma definitiva\n"
    .string "d'arts marcials!$"

ViridianCity_Gym_Text_KiyoDefeat::
    .string "Aiyah!$"

ViridianCity_Gym_Text_KiyoPostBattle::
    .string "Si els meus Pokémon fossin tan\n"
    .string "bons en karate com jo…$"

ViridianCity_Gym_EventScript_Takashi::
	trainerbattle_single TRAINER_BLACK_BELT_TAKASHI, ViridianCity_Gym_Text_TakashiIntro, ViridianCity_Gym_Text_TakashiDefeat
	msgbox ViridianCity_Gym_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_TakashiIntro::
    .string "Sóc el Rei del Karate!\n"
    .string "El teu destí depèn de mi!$"

ViridianCity_Gym_Text_TakashiDefeat::
    .string "Ayah!$"

ViridianCity_Gym_Text_TakashiPostBattle::
    .string "La Lliga Pokémon?\n"
    .string "Tu? No et passis!$"

ViridianCity_Gym_EventScript_Samuel::
	trainerbattle_single TRAINER_COOLTRAINER_SAMUEL, ViridianCity_Gym_Text_SamuelIntro, ViridianCity_Gym_Text_SamuelDefeat
	msgbox ViridianCity_Gym_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_SamuelIntro::
    .string "El Gimnàs de Viridian va estar\n"
    .string "tancat molt de temps.\p"
    .string "Però ara, el nostre Líder ha\n"
    .string "tornat!$"

ViridianCity_Gym_Text_SamuelDefeat::
    .string "M'han derrotat?$"

ViridianCity_Gym_Text_SamuelPostBattle::
    .string "Només pots anar a la Lliga Pokémon\n"
    .string "si derrotes el nostre Líder de\l"
    .string "Gimnàs!$"

ViridianCity_Gym_EventScript_Yuji::
	trainerbattle_single TRAINER_COOLTRAINER_YUJI, ViridianCity_Gym_Text_YujiIntro, ViridianCity_Gym_Text_YujiDefeat
	msgbox ViridianCity_Gym_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_YujiIntro::
    .string "Heh!\n"
    .string "Ja deus estar quedant-te sense\l"
    .string "forces!$"

ViridianCity_Gym_Text_YujiDefeat::
    .string "M'he quedat sense forces!$"

ViridianCity_Gym_Text_YujiPostBattle::
    .string "Necessitaràs poder per seguir\n"
    .string "el ritme del nostre Líder.$"

ViridianCity_Gym_EventScript_Warren::
	trainerbattle_single TRAINER_COOLTRAINER_WARREN, ViridianCity_Gym_Text_WarrenIntro, ViridianCity_Gym_Text_WarrenDefeat
	msgbox ViridianCity_Gym_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_WarrenIntro::
    .string "Els veritablement talentosos\n"
    .string "guanyen amb estil.$"

ViridianCity_Gym_Text_WarrenDefeat::
    .string "He perdut el control!$"

ViridianCity_Gym_Text_WarrenPostBattle::
    .string "El Líder em renyarà per perdre\n"
    .string "d'aquesta manera…$"


ViridianCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE08_GET, ViridianCity_Gym_EventScript_GymGuyPostVictory
	msgbox ViridianCity_Gym_Text_GymGuyAdvice
	release
	end

ViridianCity_Gym_Text_GymGuyAdvice::
    .string "Ei!\n"
    .string "Futur campió!\p"
    .string "Ni jo conec la identitat del\n"
    .string "Líder de Viridian.\p"
    .string "Però una cosa és segura.\n"
    .string "Aquest serà el més dur de tots\l"
    .string "els Líders de Gimnàs.\p"
    .string "A més, he sentit que els\n"
    .string "Entrenadors d'aquí prefereixen\l"
    .string "Pokémon de tipus Terra.$"

ViridianCity_Gym_EventScript_GymGuyPostVictory::
	msgbox ViridianCity_Gym_Text_GymGuyPostVictory
	release
	end

ViridianCity_Gym_Text_GymGuyPostVictory::
    .string "Estic al·lucinat! En Giovanni era\n"
    .string "el Líder del Gimnàs de Viridian?$"

ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_Text_GymStatue::
    .string "Gimnàs Pokémon de Viridian\n"
    .string "Líder: ?\p"
    .string "Entrenadors guanyadors:\n"
    .string "{RIVAL}$"

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GymStatuePlayerWon::
    .string "Gimnàs Pokémon de Viridian\n"
    .string "Líder: ?\p"
    .string "Entrenadors guanyadors:\n"
    .string "{RIVAL}, {PLAYER}$"

ViridianCity_Gym_EventScript_Rival::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_RIVAL_REMATCH, ViridianCity_Gym_EventScript_RivalPostBattle
	goto_if_set FLAG_RIVAL_REMATCHED, ViridianCity_Gym_EventScript_SkipRivalSpeech
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 2
	msgbox ViridianCity_Gym_Text_RivalSpeech, MSGBOX_NPC
	setflag FLAG_RIVAL_REMATCHED
ViridianCity_Gym_EventScript_SkipRivalSpeech::
	msgbox ViridianCity_Gym_Text_RematchLeader, MSGBOX_DEFAULT
	goto_if_eq VAR_RIVAL_WINRATE, 2, ViridianCity_Gym_EventScript_RivalJolteon
	goto_if_eq VAR_RIVAL_WINRATE, 1, ViridianCity_Gym_EventScript_RivalFlareon
	goto ViridianCity_Gym_EventScript_RivalVaporeon
	end

ViridianCity_Gym_Text_RivalSpeech::
	.string "{RIVAL}: ...{PLAYER}?\n"
	.string "He estat pensant...\p"
	.string "Quan vaig començar aquest viatge,\n"
	.string "de veritat creia que era el millor\l"
	.string "de tots...\p"
	.string "Però tu sempre eres allà, just\n"
	.string "darrere meu...i em vaig descuidar.\p"
	.string "Necessito temps per reflexionar.\n"
	.string "Qui sap...\p"
	.string "Potser no sóc el campió, però\n"
	.string "algun dia, podria ser Líder de\l"
	.string "Gimnàs...\p"
	.string "...\p"
	.string "Bah, tant se val! No és moment\n"
	.string "de posar-se sentimental!$"

ViridianCity_Gym_Text_RematchLeader::
	.string "I tu, què hi fas aquí?\n"
	.string "Has vingut a refregar-m'ho?\p"
	.string "Doncs t'has equivocat!\p"
	.string "No creguis que et deixaré\n"
	.string "aparèixer sense desafiar-te a\l"
	.string "un combat!$"

ViridianCity_Gym_EventScript_RivalJolteon::
	trainerbattle_single TRAINER_RIVAL_POSTGAME_JOLTEON, ViridianCity_Gym_Text_RivalIntro, ViridianCity_Gym_Text_RivalDefeat, ViridianCity_Gym_EventScript_DefeatedRival
	end

ViridianCity_Gym_EventScript_RivalFlareon::
	trainerbattle_single TRAINER_RIVAL_POSTGAME_FLAREON, ViridianCity_Gym_Text_RivalIntro, ViridianCity_Gym_Text_RivalDefeat, ViridianCity_Gym_EventScript_DefeatedRival
	end

ViridianCity_Gym_EventScript_RivalVaporeon::
	trainerbattle_single TRAINER_RIVAL_POSTGAME_VAPOREON, ViridianCity_Gym_Text_RivalIntro, ViridianCity_Gym_Text_RivalDefeat, ViridianCity_Gym_EventScript_DefeatedRival
	end

ViridianCity_Gym_Text_RivalIntro::
	.string "D'acord!\n"
	.string "Fa temps que no ho dono tot.\p"
	.string "Demostraré que segueixo sent\n"
	.string "el millor!$"

ViridianCity_Gym_Text_RivalDefeat::
	.string "Ai, què he fet?$"

ViridianCity_Gym_EventScript_DefeatedRival::
	setflag FLAG_DAILY_RIVAL_REMATCH
ViridianCity_Gym_EventScript_RivalPostBattle::
	msgbox ViridianCity_Gym_Text_RivalPostBattle, MSGBOX_DEFAULT
	call_if_unset FLAG_GOT_GIOVANNI_REWARD, ViridianCity_Gym_EventScript_RivalFoundTM
	turnobject LOCALID_RIVAL, DIR_NORTH
	release
	end

ViridianCity_Gym_Text_RivalPostBattle::
	.string "No m'agrada admetre-ho, però\n"
	.string "encara no estic al teu nivell.\p"
	.string "Però el pròxim cop et guanyaré!$"

ViridianCity_Gym_EventScript_RivalFoundTM::
	msgbox ViridianCity_Gym_Text_FoundThis, MSGBOX_DEFAULT
	checkitemspace ITEM_TM26, 1
	compare VAR_RESULT, FALSE
	goto_if_eq ViridianCity_Gym_EventScript_NoRoomForTM262
	playfanfare MUS_OBTAIN_TMHM
	message ViridianCity_Gym_Text_ReceivedTM26FromRival
	waitmessage
	waitfanfare
	additem ITEM_TM26, 1
	setflag FLAG_GOT_GIOVANNI_REWARD
	msgbox ViridianCity_Gym_Text_RivalExplainTM26
	return

ViridianCity_Gym_Text_FoundThis::
	.string "Oh, quasi m'oblido!\p"
	.string "He trobat això quan estava\n"
	.string "explorant aquest lloc.\p"
	.string "Tant com odio recompensar-te,\n"
	.string "ja tinc aquesta MT.\p"
	.string "Hauries d'agafar-lo.$"

ViridianCity_Gym_Text_ReceivedTM26FromRival::
    .string "{PLAYER} ha rebut la MT26\n"
    .string "de {RIVAL}.$"

ViridianCity_Gym_EventScript_NoRoomForTM262::
	msgbox ViridianCity_Gym_Text_YouDoNotHaveSpace2
	release
	end

ViridianCity_Gym_Text_RivalExplainTM26::
    .string "La MT26 conté Terratrèmol.\p"
    .string "És un atac poderós que causa\n"
    .string "un tremolor massiu.$"

ViridianCity_Gym_Text_YouDoNotHaveSpace2::
    .string "Oh, no tens espai per a això?\p"
    .string "Llàstima! Me'l quedo. Ha!$"

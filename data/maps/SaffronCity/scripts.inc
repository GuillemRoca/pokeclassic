.set LOCALID_DOOR_GUARD, 1
.set LOCALID_LOOKER, 16

SaffronCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_OnTransition
	.byte 0

SaffronCity_OnTransition::
	setflag FLAG_VISITED_SAFFRON_CITY
	call_if_unset FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_MoveDoorGuardGrunt
	call_if_set FLAG_LOOKER_POSTGAME_STARTED, CheckLookerPostgame
	end

CheckLookerPostgame::
	call_if_unset FLAG_LOOKER_POSTGAME_COMPLETED, ShowPostGameRockets
	return

ShowPostGameRockets::
	clearflag FLAG_HIDE_SILPH_POSTGAME_ROCKET
	return

SaffronCity_EventScript_MoveDoorGuardGrunt::
	setobjectxyperm LOCALID_DOOR_GUARD, 33, 31
	return

SaffronCity_EventScript_DoorGuardGrunt::
	lock
	goto_if_set FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_DoorGuardAsleep
	faceplayer
	msgbox SaffronCity_Text_ImASecurityGuard
	turnobject LOCALID_DOOR_GUARD, DIR_SOUTH
	release
	end

SaffronCity_Text_ImASecurityGuard::
    .string "Soc un guarda de seguretat.\p"
    .string "No deixo entrar nens sospitosos!$"

SaffronCity_EventScript_DoorGuardAsleep::
	msgbox SaffronCity_Text_HesTakingASnooze
	release
	end

SaffronCity_Text_HesTakingASnooze::
    .string "…\n"
    .string "Ronc…\p"
    .string "Ha! S'ha quedat adormit!$"

SaffronCity_EventScript_RocketGrunt1::
	msgbox SaffronCity_Text_WhatDoYouWantGetLost, MSGBOX_NPC
	end

SaffronCity_Text_WhatDoYouWantGetLost::
    .string "Què vols?\n"
    .string "Fes el camp!$"

SaffronCity_EventScript_RocketGrunt2::
	msgbox SaffronCity_Text_BossTakeTownForTeamRocket, MSGBOX_NPC
	end

SaffronCity_Text_BossTakeTownForTeamRocket::
    .string "El Cap ha dit que prendrà aquesta\n"
    .string "ciutat en nom de l'Equip Rocket!$"

SaffronCity_EventScript_RocketGrunt3::
	msgbox SaffronCity_Text_DontGetDefiantOrIllHurtYou, MSGBOX_NPC
	end

SaffronCity_Text_DontGetDefiantOrIllHurtYou::
    .string "No et rebel·lis!\n"
    .string "O hauré de fer-te mal!$"

SaffronCity_EventScript_RocketGrunt4::
	msgbox SaffronCity_Text_SaffronBelongsToTeamRocket, MSGBOX_NPC
	end

SaffronCity_Text_SaffronBelongsToTeamRocket::
    .string "Ciutat Safrà pertany a l'Equip\n"
    .string "Rocket!$"

SaffronCity_EventScript_RocketGrunt5::
	msgbox SaffronCity_Text_CriminalLifeMakesMeFeelAlive, MSGBOX_NPC
	end

SaffronCity_Text_CriminalLifeMakesMeFeelAlive::
    .string "La meva vida de criminal em fa\n"
    .string "sentir tan viu!$"

SaffronCity_EventScript_RocketGrunt6::
	msgbox SaffronCity_Text_WatchWhereYoureWalking, MSGBOX_NPC
	end

SaffronCity_Text_WatchWhereYoureWalking::
    .string "Au!\n"
    .string "Mira per on camines!$"

SaffronCity_EventScript_RocketGrunt7::
	msgbox SaffronCity_Text_WeCanExploitMonsAroundWorld, MSGBOX_NPC
	end

SaffronCity_Text_WeCanExploitMonsAroundWorld::
    .string "Amb Silph S.A. sota control, podrem\n"
    .string "explotar Pokémon d'arreu del món!\p"
    .string "Ens farem riquíssims, sííí!$"


SaffronCity_EventScript_BattleGirl::
	msgbox SaffronCity_Text_HowCanClubNotRecognizeLance, MSGBOX_NPC
	release
	end

SaffronCity_Text_HowCanClubNotRecognizeLance::
    .string "Aquest Club de Fans…\n"
    .string "Ningú aquí no té ni idea!\p"
    .string "Com poden no adonar-se de com\n"
    .string "n'és, de genial, en Lance?\p"
    .string "Defensa la justícia!\n"
    .string "És genial, i alhora apassionat!\l"
    .string "En Lance és el millor!$"

SaffronCity_EventScript_WorkerM::
	msgbox SaffronCity_Text_YouBeatTeamRocket, MSGBOX_NPC
	end

SaffronCity_Text_YouBeatTeamRocket::
    .string "Has derrotat l'Equip Rocket tu\n"
    .string "sol? Això és increïble!$"

SaffronCity_EventScript_Youngster::
	msgbox SaffronCity_Text_SafeToGoOutAgain, MSGBOX_NPC
	end

SaffronCity_Text_SafeToGoOutAgain::
    .string "Sí! L'Equip Rocket se n'ha anat!\n"
    .string "Ja es pot sortir tranquil!$"

SaffronCity_EventScript_Lass::
	msgbox SaffronCity_Text_PeopleComingBackToSaffron, MSGBOX_NPC
	end

SaffronCity_Text_PeopleComingBackToSaffron::
    .string "La gent va fugir en massa d'aquí\n"
    .string "quan van arribar els Rockets.\p"
    .string "Haurien de tornar a Ciutat Safrà\n"
    .string "ben aviat.$"

SaffronCity_EventScript_Boy::
	msgbox SaffronCity_Text_FlewHereOnPidgeot, MSGBOX_NPC
	end

SaffronCity_Text_FlewHereOnPidgeot::
    .string "He volat fins aquí amb el meu\n"
    .string "Pidgeot quan vaig llegir la\l"
    .string "notícia de Silph S.A.\p"
    .string "Ja s'ha acabat?\n"
    .string "M'he perdut l'acció mediàtica…$"

SaffronCity_EventScript_Pidgeot::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	msgbox SaffronCity_Text_Pidgeot
	waitmoncry
	release
	end

SaffronCity_Text_Pidgeot::
    .string "Pidgeot: Bi bibii!$"

SaffronCity_EventScript_Man::
	msgbox SaffronCity_Text_SawRocketBossEscaping, MSGBOX_NPC
	end

SaffronCity_Text_SawRocketBossEscaping::
    .string "He vist el Cap Rocket escapant\n"
    .string "de l'edifici de Silph S.A.$"

SaffronCity_EventScript_GymSign::
	lockall
	msgbox SaffronCity_Text_GymSign
	releaseall
	end

SaffronCity_Text_GymSign::
    .string "Gimnàs Pokémon de Ciutat Safrà\n"
    .string "Líder: Sabrina\l"
    .string "La Mestra dels Pokémon Psíquics!$"

SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_CitySign, MSGBOX_SIGN
	end

SaffronCity_Text_CitySign::
    .string "Ciutat Safrà\n"
    .string "La resplendent terra del comerç$"

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_Text_FightingDojo::
    .string "Dojo de Lluita$"

SaffronCity_EventScript_TrainerFanClubSign::
	msgbox SaffronCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

SaffronCity_Text_TrainerFanClubSign::
    .string "Club de Fans d'Entrenadors\n"
    .string "Pokémon\p"
    .string "Molts Entrenadors han gargotejat\n"
    .string "els seus noms en aquest cartell.$"

SaffronCity_EventScript_TrainerTips1::
	msgbox SaffronCity_Text_FullHealCuresStatus, MSGBOX_SIGN
	end

SaffronCity_Text_FullHealCuresStatus::
    .string "Consells d'Entrenador:\p"
    .string "La Cura Total guareix tots els\n"
    .string "problemes d'estat: cremades,\l"
    .string "paràlisi, enverinament, congelació\l"
    .string "i son.\p"
    .string "Costa una mica més, però és més\n"
    .string "pràctic que comprar altres\l"
    .string "objectes.$"

SaffronCity_EventScript_TrainerTips2::
	msgbox SaffronCity_Text_GreatBallImprovedCatchRate, MSGBOX_SIGN
	end

SaffronCity_Text_GreatBallImprovedCatchRate::
    .string "Consells d'Entrenador:\p"
    .string "La nova Gran Ball ofereix una\n"
    .string "taxa de captura millorada.\p"
    .string "Prova-la amb aquells Pokémon\n"
    .string "difícils de capturar.$"

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_Text_SilphCoSign::
    .string "Seu Central de Silph S.A.$"

SaffronCity_EventScript_MrPsychicsHouseSign::
	msgbox SaffronCity_Text_MrPsychicsHouse, MSGBOX_SIGN
	end

SaffronCity_Text_MrPsychicsHouse::
    .string "Casa del Sr. Psíquic$"

SaffronCity_EventScript_SilphProductSign::
	msgbox SaffronCity_Text_SilphsLatestProduct, MSGBOX_SIGN
	end

SaffronCity_Text_SilphsLatestProduct::
    .string "L'últim producte de Silph S.A.!\n"
    .string "Data de llançament per determinar…$"

SaffronCity_EventScript_SkippedLookerScene::
	setvar VAR_SILPH_STATE, 4
	end

SaffronCity_EventScript_LookerTriggerL1::
	setobjectxyperm LOCALID_LOOKER, 24, 32
	setvar VAR_TEMP_1, 1
	goto SaffronCity_EventScript_Looker

SaffronCity_EventScript_LookerTriggerL2::
	setobjectxyperm LOCALID_LOOKER, 24, 33
	setvar VAR_TEMP_1, 1
	goto SaffronCity_EventScript_Looker

SaffronCity_EventScript_LookerTriggerL3::
	setobjectxyperm LOCALID_LOOKER, 24, 34
	setvar VAR_TEMP_1, 1
	goto SaffronCity_EventScript_Looker

SaffronCity_EventScript_LookerTriggerR1::
	setobjectxyperm LOCALID_LOOKER, 42, 32
	setvar VAR_TEMP_1, 2
	goto SaffronCity_EventScript_Looker

SaffronCity_EventScript_LookerTriggerR2::
	setobjectxyperm LOCALID_LOOKER, 42, 33
	setvar VAR_TEMP_1, 2
	goto SaffronCity_EventScript_Looker

SaffronCity_EventScript_LookerTriggerR3::
	setobjectxyperm LOCALID_LOOKER, 42, 34
	setvar VAR_TEMP_1, 2
	goto SaffronCity_EventScript_Looker

SaffronCity_EventScript_Looker::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	playbgm MUS_ENCOUNTER_CHAMPION, 0
	clearflag FLAG_HIDE_SAFFRON_CITY_LOOKER
	addobject LOCALID_LOOKER
	call_if_eq VAR_TEMP_1, 1, SaffronCity_EventScript_MoveLookerLeft
	call_if_eq VAR_TEMP_1, 2, SaffronCity_EventScript_MoveLookerRight
	waitmovement 16
	playse SE_PIN
	applymovement LOCALID_LOOKER, Common_Movement_ExclamationMark
	waitse
	waitmovement 16
	msgbox SaffronCity_Text_ShouldntBeSurprised, MSGBOX_DEFAULT
	waitmessage
	call_if_eq VAR_TEMP_1, 1, SaffronCity_EventScript_MoveLookerRight
	call_if_eq VAR_TEMP_1, 2, SaffronCity_EventScript_MoveLookerLeft
	waitmovement 16
	removeobject LOCALID_LOOKER
	fadedefaultbgm
	setvar VAR_SILPH_STATE, 4
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

SaffronCity_EventScript_MoveLookerLeft::
	applymovement LOCALID_LOOKER, Movement_LookerWalksRight
	return

Movement_LookerWalksRight::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SaffronCity_EventScript_MoveLookerRight::
	applymovement LOCALID_LOOKER, Movement_LookerWalksLeft
	return

Movement_LookerWalksLeft::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SaffronCity_Text_ShouldntBeSurprised::
	.string "Looker: Bé, comencem a establir\n"
	.string "un perímetre...Oh! {PLAYER}!\p"
	.string "Acabem d'arrestar els soldats de\n"
	.string "l'Equip Rocket que terroritzaven\l"
	.string "els ciutadans. Estem a punt per\l"
	.string "assaltar Silph S.A. i derrotar\l"
	.string "el seu Cap!\p"
	.string "Els Plans Rocket que vas lliurar\n"
	.string "ens han estat molt útils, però\l"
	.string "aquest cop t'has de fer a un costat\l"
	.string "i deixar que se n'encarreguin\l"
	.string "els adults!\p"
	.string "...\p"
	.string "Que has fet què?!\p"
	.string "Ja has derrotat els Rockets de\n"
	.string "dins de Silph S.A. i has rescatat\l"
	.string "el President?\p"
	.string "És increïble, però molt imprudent!\p"
	.string "Espera...\n"
	.string "I el Cap Rocket?\p"
	.string "Ha escapat? Un altre cop? Llamps!\p"
	.string "Hem desmantellat totes les bases\n"
	.string "Rocket que hem trobat, i l'hem\l"
	.string "perseguit per tot Kanto.\p"
	.string "No li poden quedar gaires llocs\n"
	.string "per amagar-se.\p"
	.string "Però no tenim cap pista!\n"
	.string "Hauré de continuar investigant.$"

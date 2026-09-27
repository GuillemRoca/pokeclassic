.set LOCALID_GIOVANNI, 1
.set LOCALID_GRUNT1,   4
.set LOCALID_GRUNT2,   5
.set LOCALID_JESSIE,   6
.set LOCALID_JAMES,    7
.set LOCALID_ROCKET_LEADER, 9
.set LOCALID_LOOKER, 10

SilphCo_11F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_11F_OnLoad
	.byte 0

SilphCo_11F_OnLoad::
	call_if_unset FLAG_SILPH_11F_DOOR, EventScript_Close11FDoor
	end

SilphCo_11F_EventScript_ItemZinc::
	finditem ITEM_ZINC, 1
	release
	end

SilphCo_11F_EventScript_President::
	lock
	faceplayer
	goto_if_set FLAG_LOOKER_POSTGAME_COMPLETED, SilphCo_11F_EventScript_PresidentPostgame
	goto_if_set	FLAG_LOOKER_POSTGAME_STARTED, SilphCo_11F_EventScript_PresidentHostage
	goto_if_set FLAG_GOT_MASTER_BALL_FROM_SILPH, SilphCo_11F_EventScript_AlreadyGotMasterBall
	msgbox SilphCo_11F_Text_ThanksForSavingMe
	checkitemspace ITEM_MASTER_BALL, 1
	goto_if_eq VAR_RESULT, FALSE, SilphCo_11F_EventScript_NoRoomForMasterBall
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message SilphCo_11F_Text_ObtainedMasterBallFromPresident
	additem ITEM_MASTER_BALL, 1
	waitfanfare
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	setflag FLAG_GOT_MASTER_BALL_FROM_SILPH
	release
	end

SilphCo_11F_EventScript_PresidentPostgame::
	goto_if_set FLAG_DAILY_PREZ_BATTLE, SilphCo_11F_EventScript_PresidentPostgamePostBattle
	msgbox SilphCo_11F_Text_PracticeBattling, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_11F_EventScript_DeclinePrezBattle
	trainerbattle_no_intro TRAINER_SILPH_PREZ, SilphCo_11F_Text_PrezDefeat
	msgbox SilphCo_11F_Text_WhatAGreatBattle, MSGBOX_NPC
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message SilphCo_11F_Text_ObtainedMasterBallFromPresident
	additem ITEM_MASTER_BALL, 1
	waitfanfare
	setflag FLAG_DAILY_PREZ_BATTLE
	release
	end

SilphCo_11F_Text_WhatAGreatBattle::
	.string "President: Veig que encara tinc\n"
	.string "marge per millorar!\p"
	.string "Però ja no hauràs de preocupar-te\n"
	.string "de rescatar-me més!\p"
	.string "Si us plau, accepta això com a\n"
	.string "recompensa.$"

SilphCo_11F_Text_PrezDefeat::
	.string "Sembla que ni un President pot\n"
	.string "igualar un Campió!$"

SilphCo_11F_Text_PracticeBattling::
	.string "President: Ah, hola {PLAYER}!\p"
	.string "Véns a veure com estic?\p"
	.string "Hoho...bé, no et preocupis. No\n"
	.string "hi ha hagut cap senyal de l'Equip\l"
	.string "Rocket aquí.\p"
	.string "Mai no es pot ser massa prudent,\n"
	.string "així que he començat a entrenar\l"
	.string "els meus propis Pokémon per\l"
	.string "protegir-me!\p"
	.string "Escolta...ja que has vingut fins\n"
	.string "aquí, què tal un combat?$"

SilphCo_11F_EventScript_DeclinePrezBattle::
	msgbox SilphCo_11F_Text_IUnderstand, MSGBOX_NPC
	release
	end

SilphCo_11F_Text_IUnderstand::
	.string "Ho entenc. Les coses han d'anar\n"
	.string "molt atrafegades per a un Campió.$"

SilphCo_11F_EventScript_PresidentPostgamePostBattle::
	msgbox SilphCo_11F_Text_TheseRocketsPunks, MSGBOX_NPC
	end

SilphCo_11F_Text_TheseRocketsPunks::
	.string "President: Silph S.A. intenta\n"
	.string "fer del món un lloc millor tant\l"
	.string "per a persones com per a Pokémon.\p"
	.string "Però brètols com l'Equip Rocket\n"
	.string "mai ho entendran.$"

SilphCo_11F_EventScript_PresidentHostage::
	msgbox SilphCo_11F_Text_TheseRockets, MSGBOX_NPC
	end

SilphCo_11F_Text_TheseRockets::
	.string "President: Ja n'hi ha prou\n"
	.string "d'aquests Rockets!$"

SilphCo_11F_EventScript_NoRoomForMasterBall::
	msgbox SilphCo_11F_Text_YouHaveNoRoomForThis
	release
	end

SilphCo_11F_EventScript_AlreadyGotMasterBall::
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	release
	end

SilphCo_11F_EventScript_Secretary::
	goto_if_set FLAG_DAILY_PREZ_BATTLE, SilphCo_11F_EventScript_SecretaryPostbattle
	goto_if_set FLAG_LOOKER_POSTGAME_COMPLETED, SilphCo_11F_EventScript_SecretaryPostgame
	goto_if_set	FLAG_LOOKER_POSTGAME_STARTED, SilphCo_11F_EventScript_HappeningAgain
	msgbox SilphCo_11F_Text_ThanksForRescuingUs, MSGBOX_NPC
	end

SilphCo_11F_EventScript_SecretaryPostbattle::
	msgbox SilphCo_11F_Text_PrezTeam, MSGBOX_NPC
	end

SilphCo_11F_Text_PrezTeam::
	.string "Després de veure't lluitar contra\n"
	.string "l'Equip Rocket dues vegades, el\l"
	.string "President s'ha obsessionat amb\l"
	.string "els combats Pokémon.\p"
	.string "Es passa tot el temps investigant\n"
	.string "nous moviments...\p"
	.string "La qual cosa vol dir que jo he de\n"
	.string "respondre tots els seus correus!$"

SilphCo_11F_EventScript_HappeningAgain::
	msgbox SilphCo_11F_Text_HappeningAgain, MSGBOX_NPC
	end

SilphCo_11F_EventScript_SecretaryPostgame::
	msgbox SilphCo_11F_Text_NotWhatIExpected, MSGBOX_NPC
	end

SilphCo_11F_Text_NotWhatIExpected::
	.string "Aquesta feina no és el que\n"
	.string "m'esperava. Sóc secretària,\l"
	.string "no guardaespatlles.\p"
	.string "Estic pensant a demanar un\n"
	.string "augment!$"

SilphCo_11F_Text_HappeningAgain::
	.string "Aiiieee!! No puc creure que\n"
	.string "torni a passar! Ajudeu-nos!$"

SilphCo_11F_EventScript_GiovanniTriggerLeft::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 0
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_GiovanniTriggerRight::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 1
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_BattleGiovanni::
	applymovement LOCALID_GIOVANNI, Common_Movement_WalkInPlaceFasterDown
	waitmovement 1
	delay 25
	msgbox SilphCo_11F_Text_GiovanniIntro
	closemessage
	call_if_eq  VAR_TEMP_1, 0, SilphCo_11F_EventScript_GiovanniApproachLeft
	call_if_eq VAR_TEMP_1, 1, SilphCo_11F_EventScript_GiovanniApproachRight
	setvar VAR_LAST_TALKED, LOCALID_GIOVANNI
	trainerbattle_no_intro TRAINER_BOSS_GIOVANNI_2, SilphCo_11F_Text_GiovanniDefeat
	msgbox SilphCo_11F_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_GIOVANNI
	removeobject LOCALID_GRUNT1
	removeobject LOCALID_GRUNT2
	fadescreen FADE_FROM_BLACK
	setvar VAR_SILPH_STATE, 3
	setflag FLAG_HIDE_SAFFRON_ROCKETS
	clearflag FLAG_HIDE_ROCKET_BURGLARS
	clearflag FLAG_HIDE_SAFFRON_CIVILIANS
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	releaseall
	end

SilphCo_11F_EventScript_GiovanniApproachLeft::
	applymovement LOCALID_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachLeft
	applymovement OBJ_EVENT_ID_PLAYER, SilphCo_11F_Movement_PlayerFaceGiovanni
	waitmovement 1
	return

SilphCo_11F_EventScript_GiovanniApproachRight::
	applymovement LOCALID_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachRight
	waitmovement 1
	return

SilphCo_11F_Movement_GiovanniApproachLeft::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_fast_left
	step_end

SilphCo_11F_Movement_GiovanniApproachRight::
	walk_down
	walk_down
	walk_down
	step_end

SilphCo_11F_Movement_PlayerFaceGiovanni::
	delay_16
	delay_16
	delay_16
	delay_8
	delay_4
	walk_in_place_fast_right
	step_end


SilphCo_11F_EventScript_JessieJames::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_JESSIE, Movement_JessieJamesApproachPlayer
	applymovement LOCALID_JAMES, Movement_JessieJamesApproachPlayer
	waitmovement 6
	msgbox SilphCo_11F_Text_StopYouOnceAndForAll
	trainerbattle_no_intro TRAINER_SILPH_CO_JESSIE_JAMES, SilphCo_11F_Text_JessieJamesDefeat
	msgbox SilphCo_11F_Text_JessieJamesPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	waitse
	removeobject LOCALID_JESSIE
	removeobject LOCALID_JAMES
	fadescreen FADE_FROM_BLACK
	delay 10
	setvar VAR_SILPH_STATE, 2
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

SilphCo_11F_Text_StopYouOnceAndForAll::
	.string "James: Vaja, mira qui és.\n"
	.string "Jessie: El marrec ha arribat\l"
	.string "puntualment.\p"
	.string "Jessie: Sabíem que vindries.\n"
	.string "James: Però fins aquí has arribat.\l"
	.string "Jessie: El nostre Cap té reunió.\n"
	.string "James: Així que t'enfrontaràs\l"
	.string "a nosaltres!$"

SilphCo_11F_Text_JessieJamesDefeat::
	.string "Jessie: Argh! Odio els nens!\p"
	.string "James: Com sempre...$"

SilphCo_11F_Text_JessieJamesPostBattle::
	.string "Jessie: Hem fallat al cap.\n"
	.string "James: Era la nostra última\l"
	.string "oportunitat!\p"
	.string "Jessie i James: Sembla que\n"
	.string "tornarem a sortir volant!$"

Movement_JessieJamesApproachPlayer:
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
SilphCo_11F_EventScript_Monitor::
	msgbox SilphCo_11F_Text_MonitorHasMonsOnIt, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_FloorSign::
	msgbox SilphCo_11F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_40, SilphCo_11F_Text_Grunt1Intro, SilphCo_11F_Text_Grunt1Defeat
	msgbox SilphCo_11F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_11F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_41, SilphCo_11F_Text_Grunt2Intro, SilphCo_11F_Text_Grunt2Defeat
	msgbox SilphCo_11F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_11F_Text_ThanksForSavingMe::
    .string "President: Oh, estimat nen!\n"
    .string "Gràcies per salvar Silph.\p"
    .string "Mai oblidaré que ens vas salvar\n"
    .string "en el nostre moment de perill.\p"
    .string "T'ho he d'agrair d'alguna manera.\p"
    .string "Com que sóc ric, et puc donar\n"
    .string "el que vulguis.\p"
    .string "Potser això et servirà.$"

SilphCo_11F_Text_ObtainedMasterBallFromPresident::
    .string "{PLAYER} ha obtingut una Master\n"
    .string "Ball del President!$"

SilphCo_11F_Text_ThatsOurSecretPrototype::
    .string "President: Això no es pot comprar\n"
    .string "enlloc.\p"
    .string "És el nostre prototip secret de\n"
    .string "Master Ball.\p"
    .string "Capturarà qualsevol Pokémon\n"
    .string "sense falta!\p"
    .string "Però hauries de ser discret\n"
    .string "sobre el seu ús.$"

SilphCo_11F_Text_YouHaveNoRoomForThis::
    .string "No tens espai per a això.$"

SilphCo_11F_Text_ThanksForRescuingUs::
    .string "Secretària: Gràcies per\n"
    .string "rescatar-nos a tots.\p"
    .string "Nosaltres, des del President\n"
    .string "avall, t'estem en deute.$"

SilphCo_11F_Text_GiovanniIntro::
    .string "Ah, {PLAYER}!\n"
    .string "Ens tornem a trobar!\p"
    .string "El President i jo estem discutint\n"
    .string "una proposta de negoci vital.\p"
    .string "No fiquis el nas en assumptes\n"
    .string "d'adults…\p"
    .string "O experimenta un món de dolor!$"

SilphCo_11F_Text_GiovanniDefeat::
    .string "Arrgh!!\n"
    .string "He tornat a perdre!?$"

SilphCo_11F_Text_GiovanniPostBattle::
    .string "Maleït sigui!\n"
    .string "Has arruïnat els nostres plans\l"
    .string "per a Silph!\p"
    .string "Però l'Equip Rocket mai caurà!\p"
    .string "{PLAYER}! No oblidis mai que tots\n"
    .string "els Pokémon existeixen per a\l"
    .string "l'Equip Rocket!\p"
    .string "Me n'he d'anar, però tornaré!$"

SilphCo_11F_Text_Grunt2Intro::
    .string "Para aquí!\n"
    .string "No et moguis!$"

SilphCo_11F_Text_Grunt2Defeat::
    .string "No…\n"
    .string "Si us plau!$"

SilphCo_11F_Text_Grunt2PostBattle::
    .string "Vols veure el meu Cap?$"

SilphCo_11F_Text_Grunt1Intro::
    .string "Alt! Tens cita amb el\n"
    .string "meu Cap?$"

SilphCo_11F_Text_Grunt1Defeat::
    .string "Gaah!\n"
    .string "Demolit!$"

SilphCo_11F_Text_Grunt1PostBattle::
    .string "Vigila on trepitges…\n"
    .string "Al meu Cap li agraden els\l"
    .string "Pokémon durs!$"

SilphCo_11F_Text_MonitorHasMonsOnIt::
    .string "El monitor mostra Pokémon!$"

SilphCo_11F_Text_FloorSign::
    .string "Seu Central de Silph S.A.\n"
    .string "11è pis$"


@Postgame
SilphCo_11F_EventScript_PostgameRocket::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_ROCKET_LEADER, Common_Movement_ExclamationMark
	waitse
	msgbox SilphCo_11F_Text_GiovanniWasWeak, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_POSTGAME_ROCKET_LEADER, SilphCo_11F_Text_RocketLeaderDefeat
	playse SE_PIN
	applymovement LOCALID_ROCKET_LEADER, Common_Movement_ExclamationMark
	waitse
	msgbox SilphCo_11F_Text_HowCouldThisHappen, MSGBOX_NPC
	clearflag FLAG_HIDE_SILPH_POSTGAME_LOOKER
	addobject LOCALID_LOOKER
	playbgm MUS_ENCOUNTER_CHAMPION, 0
	call_if_eq VAR_FACING, DIR_EAST, SilphCo_11F_EventScript_LookerMovement1
	call_if_eq VAR_FACING, DIR_WEST, SilphCo_11F_EventScript_LookerMovement2
	msgbox SilphCo_11F_Text_ThatsEnoughFromYou, MSGBOX_NPC
	waitmessage
	closemessage
	msgbox SilphCo_11F_Text_RocketWellNeverStop, MSGBOX_NPC
	waitmessage
	closemessage
	msgbox SilphCo_11F_Text_TakingYouIn, MSGBOX_NPC
	call_if_eq VAR_FACING, DIR_EAST, SilphCo_11F_EventScript_LookerMovement3
	call_if_eq VAR_FACING, DIR_WEST, SilphCo_11F_EventScript_LookerMovement4
	waitmovement 10
	setflag	FLAG_HIDE_SILPH_POSTGAME_ROCKET
	setflag	FLAG_HIDE_SILPH_POSTGAME_LOOKER
	setflag FLAG_LOOKER_POSTGAME_COMPLETED
	clearflag FLAG_HIDE_LOOKER_CELADON
	removeobject LOCALID_LOOKER
	removeobject LOCALID_ROCKET_LEADER
	fadedefaultbgm
	release
	end

SilphCo_11F_Text_ThatsEnoughFromYou::
	.string "Looker: Prou!\p"
	.string "Ja ho hem sentit tot abans.\p"
	.string "Aquest és el vostre problema,\n"
	.string "Rockets. Tot gira al voltant\l"
	.string "d'una sola cosa...el poder!\p"
	.string "Per això sempre perdreu contra\n"
	.string "algú com {PLAYER}.\p"
	.string "Ell sap què significa realment\n"
	.string "viure al costat dels Pokémon.\p"
	.string "...\p"
	.string "Has dit que Giovanni era feble,\n"
	.string "però crec que fins i tot ell ho\l"
	.string "sabia al final.$"

SilphCo_11F_Text_RocketWellNeverStop::
	.string "Rocket: ...\p"
	.string "Potser sí...\p"
	.string "Però mai no pararem!\p"
	.string "L'Equip Rocket tornarà a\n"
	.string "alçar-se!$"

SilphCo_11F_Text_TakingYouIn::
	.string "Looker: Ja ho veurem.\p"
	.string "{PLAYER}! M'emporto aquest\n"
	.string "Rocket.\p"
	.string "Gràcies per tota la teva ajuda\n"
	.string "aquí. Hauries de venir a veure'm\n"
	.string "la propera vegada que siguis a\n"
	.string "Ciutat Celadon.$"

SilphCo_11F_EventScript_LookerMovement1::
	applymovement LOCALID_LOOKER, SilphCo_11F_LookerMovement_Approach1
	waitmovement 10
	turnobject LOCALID_ROCKET_LEADER, DIR_EAST
	return

SilphCo_11F_EventScript_LookerMovement2::
	applymovement LOCALID_LOOKER, SilphCo_11F_LookerMovement_Approach2
	waitmovement 10
	turnobject LOCALID_ROCKET_LEADER, DIR_WEST
	return

SilphCo_11F_LookerMovement_Approach1::
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

SilphCo_11F_LookerMovement_Approach2::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

SilphCo_11F_EventScript_LookerMovement3::
	applymovement LOCALID_LOOKER, SilphCo_11F_LookerMovement_Exit1
	applymovement LOCALID_ROCKET_LEADER, SilphCo_11F_RocketMovement_Exit1
	return

SilphCo_11F_RocketMovement_Exit1::
	walk_right
SilphCo_11F_LookerMovement_Exit1::
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SilphCo_11F_RocketMovement_Exit2::
	walk_left
SilphCo_11F_LookerMovement_Exit2::
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SilphCo_11F_EventScript_LookerMovement4::
	applymovement LOCALID_LOOKER, SilphCo_11F_RocketMovement_Exit2
	applymovement LOCALID_ROCKET_LEADER, SilphCo_11F_RocketMovement_Exit2
	return


SilphCo_11F_Text_GiovanniWasWeak::
	.string "Rocket: Ha! De debò has\n"
	.string "aparegut?\p"
	.string "Què? El gran campió de Kanto\n"
	.string "es pensa que em derrotarà?\p"
	.string "Bé, escolta bé, nen.\p"
	.string "Giovanni era feble!\p"
	.string "Va deixar que un don ningú com\n"
	.string "tu li passés per sobre!\p"
	.string "Sota el meu lideratge, l'Equip\n"
	.string "Rocket no es rendiria només\l"
	.string "perquè un nen s'interposa!\p"
	.string "Saluda al nou Equip Rocket!$"

SilphCo_11F_Text_RocketLeaderDefeat::
	.string "Què?! Sóc més feble que\n"
	.string "Giovanni?\p"

SilphCo_11F_Text_HowCouldThisHappen::
	.string "No m'ho puc creure...\p"
	.string "Això havia de ser el nostre gran\n"
	.string "retorn!\p"
	.string "Pensàvem que Giovanni era\n"
	.string "feble... però tu ets massa bo!$"




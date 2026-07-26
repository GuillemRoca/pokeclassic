.set LOCALID_JENNY, 5
.set LOCALID_SLOWBRO, 9
.set LOCALID_LASS, 4
.set LOCALID_RIVAL, 10
.set LOCALID_TMBALL, 12
.set LOCALID_GRUNT, 6
.set LOCALID_BULBASAUR, 14
.set LOCALID_BREEDER, 13

CeruleanCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CeruleanCity_OnResume
	.byte 0

CeruleanCity_OnTransition:
	setflag FLAG_VISITED_CERULEAN_CITY
	call_if_set FLAG_SYS_GAME_CLEAR, CeruleanCity_EventScript_ClearCeruleanCaveGuard
	call_if_unset FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_BlockExits
	call_if_set FLAG_GOT_BULBASAUR,  CeruleanCity_EventScript_MoveBreederInside
	call Common_EventScript_GetDayOrNight
	end

CeruleanCity_EventScript_ClearCeruleanCaveGuard::
	setflag FLAG_HIDE_CERULEAN_CAVE_GUARD
	return

CeruleanCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end

CeruleanCity_EventScript_BlockExits::
	setobjectxyperm LOCALID_JENNY, 30, 12
	setobjectxyperm LOCALID_SLOWBRO, 26, 31
	setobjectxyperm LOCALID_LASS, 27, 31
	return

CeruleanCity_EventScript_MoveBreederInside::
	clearflag FLAG_HIDE_CERULEAN_BREEDER
	return

CeruleanCity_EventScript_CitySign::
	msgbox CeruleanCity_Text_CitySign, MSGBOX_SIGN
	end

CeruleanCity_Text_CitySign::
    .string "Ciutat Cerulean\n"
    .string "Una aura blava i misteriosa.$"

CeruleanCity_EventScript_TrainerTips::
	msgbox CeruleanCity_Text_TrainerTipsHeldItems, MSGBOX_SIGN
	end

CeruleanCity_Text_TrainerTipsHeldItems::
    .string "Consells d'Entrenador:\p"
    .string "Un Pokémon pot portar un\n"
    .string "objecte equipat.\p"
    .string "Alguns objectes els pot fer\n"
    .string "servir el Pokémon en combat.$"

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_Text_BikeShopSign::
    .string "Herba i coves? Sense problema!\n"
    .string "Botiga de Bicicletes$"

CeruleanCity_EventScript_GymSign::
	lockall
	msgbox CeruleanCity_Text_GymSign, MSGBOX_SIGN
	releaseall
	end

CeruleanCity_Text_GymSign::
    .string "Gimnàs Pokémon de Cerulean\n"
    .string "Líder: Misty\l"
    .string "La Sirena Intrèpida!$"

CeruleanCity_EventScript_Police::
	lock
	faceplayer
	msgbox CeruleanCity_Text_PeopleHereWereRobbed, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_JENNY, DIR_SOUTH
	release
	end

CeruleanCity_Text_PeopleHereWereRobbed::
    .string "Aquí han robat la gent.\p"
    .string "És evident que l'Equip Rocket\n"
    .string "està darrere d'aquest crim!\p"
    .string "La nostra Policia té problemes\n"
    .string "amb els Rockets, així que hem\l"
    .string "demanat ajuda a la Policia\l"
    .string "Internacional!$"

CeruleanCity_EventScript_LittleBoy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_LittleBoySlowbroMoved
	msgbox CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree::
    .string "Si aquell Slowbro no hi fos,\n"
    .string "podries Tallar l'arbret.\p"
    .string "Així podries arribar\n"
    .string "a l'altre costat.\p"
    .string "Crec que hi ha una altra\n"
    .string "manera, però.$"

CeruleanCity_EventScript_LittleBoySlowbroMoved::
	msgbox CeruleanCity_Text_YouCanCutDownSmallTrees, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_YouCanCutDownSmallTrees::
    .string "Sabies que pots Tallar\n"
    .string "els arbrets?\p"
    .string "Fins i tot l'arbret davant\n"
    .string "de la botiga es pot Tallar.\p"
    .string "Crec que hi ha una altra\n"
    .string "manera, però.$"

CeruleanCity_EventScript_BaldingMan::
	msgbox CeruleanCity_Text_PokemonEncyclopediaAmusing, MSGBOX_NPC
	end

CeruleanCity_Text_PokemonEncyclopediaAmusing::
    .string "Fas una enciclopèdia sobre\n"
    .string "Pokémon? Sona divertit.$"

CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_TrainerLifeIsToughIsntIt, MSGBOX_NPC
	end

CeruleanCity_Text_TrainerLifeIsToughIsntIt::
    .string "Tu també ets Entrenador?\p"
    .string "Col·leccionar, combatre…\n"
    .string "És una vida dura, oi?$"

CeruleanCity_EventScript_Woman::
	lock
	faceplayer
	msgbox CeruleanCity_Text_WantBrightRedBicycle
	closemessage
	turnobject LOCALID_WOMAN, DIR_NORTH
	release
	end

CeruleanCity_Text_WantBrightRedBicycle::
    .string "Vull una bicicleta vermella.\p"
    .string "Me la guardaré a casa, així no\n"
    .string "s'embruta.$"

CeruleanCity_EventScript_CeruleanCaveGuard::
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
	end

CeruleanCity_Text_ThisIsCeruleanCave::
    .string "Això és la Cova Cerulean.\p"
    .string "Hi viuen Pokémon molt forts\n"
    .string "allà dins.\p"
    .string "Cal un Entrenador molt especial\n"
    .string "per poder-hi entrar.\p"
    .string "Com de fort?\n"
    .string "Hmm....\p"
    .string "Diria que només algú que\n"
    .string "pugui ser Campió de la Lliga\l"
    .string "Pokémon ho aguantaria.$"

CeruleanCity_EventScript_Lass::
	lock
	random 3
	goto_if_eq VAR_RESULT, 0, CeruleanCity_EventScript_SlowbroLass1
	goto_if_eq VAR_RESULT, 1, CeruleanCity_EventScript_SlowbroLass2
	goto_if_eq VAR_RESULT, 2, CeruleanCity_EventScript_SlowbroLass3
	end

CeruleanCity_Slowbro::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	delay 40
	playse SE_PIN
	applymovement LOCALID_SLOWBRO, Common_Movement_QuestionMark
	waitmovement 9
	delay 30
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return

CeruleanCity_EventScript_SlowbroLass1::
	msgbox CeruleanCity_Text_SlowbroUseSonicboom, MSGBOX_DEFAULT
	call CeruleanCity_Slowbro
	msgbox CeruleanCity_Text_SlowbroPayAttention, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroUseSonicboom::
    .string "Va, Slowbro!\n"
    .string "Fes servir Explosió Sònica!$"

CeruleanCity_Text_SlowbroPayAttention::
    .string "Vinga, Slowbro, para atenció!$"

CeruleanCity_EventScript_SlowbroLass2::
	msgbox CeruleanCity_Text_SlowbroPunch, MSGBOX_DEFAULT
	call CeruleanCity_Slowbro
	msgbox CeruleanCity_Text_NoYouBlewItAgain, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroPunch::
    .string "Slowbro, cop de puny!$"

CeruleanCity_Text_NoYouBlewItAgain::
    .string "No!\n"
    .string "L'has tornat a espifiar!$"

CeruleanCity_EventScript_SlowbroLass3::
	msgbox CeruleanCity_Text_SlowbroWithdraw, MSGBOX_DEFAULT
	call CeruleanCity_Slowbro
	msgbox CeruleanCity_Text_HardToControlMonsObedience, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroWithdraw::
    .string "Slowbro, REFUGI!$"

CeruleanCity_Text_HardToControlMonsObedience::
    .string "No! Això no!\n"
    .string "Que difícil és controlar Pokémon!\p"
    .string "L'obediència del teu Pokémon\n"
    .string "depèn de les teves habilitats\l"
    .string "com a entrenador.$"

CeruleanCity_EventScript_Slowbro::
	lock
	random 4
	goto_if_eq VAR_RESULT, 0, CeruleanCity_EventScript_Slowbro1
	goto_if_eq VAR_RESULT, 1, CeruleanCity_EventScript_Slowbro2
	goto_if_eq VAR_RESULT, 2, CeruleanCity_EventScript_Slowbro3
	goto_if_eq VAR_RESULT, 3, CeruleanCity_EventScript_Slowbro4
	end

CeruleanCity_EventScript_Slowbro1::
	msgbox CeruleanCity_Text_SlowbroTookSnooze, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroTookSnooze::
    .string "Slowbro s'ha adormit…$"

CeruleanCity_EventScript_Slowbro2::
	msgbox CeruleanCity_Text_SlowbroLoafingAround, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroLoafingAround::
    .string "Slowbro està fent el dropo…$"

CeruleanCity_EventScript_Slowbro3::
	msgbox CeruleanCity_Text_SlowbroTurnedAway, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroTurnedAway::
    .string "Slowbro ha girat la cara…$"

CeruleanCity_EventScript_Slowbro4::
	msgbox CeruleanCity_Text_SlowbroIgnoredOrders, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroIgnoredOrders::
    .string "Slowbro ha ignorat les ordres…$"

CeruleanCity_EventScript_RivalTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_RIVAL, 23, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm LOCALID_RIVAL, 24, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_Rival::
	setvar VAR_ROUTE_22_RIVAL_STATE, 3
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	clearflag FLAG_HIDE_CERULEAN_RIVAL
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalEnter
	waitmovement 10
	msgbox CeruleanCity_Text_RivalAppears, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_RIVAL_CERULEAN_CITY, CeruleanCity_Text_RivalIntro, CeruleanCity_Text_RivalDefeat, CeruleanCity_EventScript_RivalDefeated, NO_MUSIC
	end

CeruleanCity_EventScript_RivalDefeated::
	msgbox CeruleanCity_Text_RivalPostBattle, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, CeruleanCity_EventScript_RivalStartExit
	call_if_eq VAR_TEMP_1, 1, CeruleanCity_EventScript_RivalStartExit
	call_if_eq VAR_TEMP_1, 2, CeruleanCity_EventScript_RivalStartExitRight
	msgbox CeruleanCity_Text_OhRightLittlePresentAsFavor, MSGBOX_DEFAULT
	setvar VAR_RIVAL_CERULEAN_CITY, 1
	setflag FLAG_RECEIVED_POKEBLOCK_CASE
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox CeruleanCity_Text_ObtainedPokeblockCase, MSGBOX_DEFAULT
	additem ITEM_POKEBLOCK_CASE
	waitfanfare
	msgbox CeruleanCity_Text_ExplainPokeblockSmellYa, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalExit
	waitmovement 10
	fadedefaultbgm
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_CERULEAN_RIVAL
	releaseall
	end

CeruleanCity_Text_RivalAppears::
    .string "{RIVAL}: Ei! {PLAYER}!\p"
    .string "Encara vas arrossegant-te\n"
    .string "per aquí?\p"
    .string "Jo vaig genial! He atrapat\n"
    .string "un munt de Pokémon forts!$"

CeruleanCity_Text_RivalIntro::
    .string "Deixa'm veure què has atrapat,\n"
    .string "{PLAYER}!$"

CeruleanCity_Text_RivalDefeat::
    .string "Ei!\n"
    .string "Para ja!\l"
    .string "Ja has guanyat!$"

CeruleanCity_Text_RivalPostBattle::
    .string "{RIVAL}: Ei, saps què?\p"
    .string "He anat a casa d'en Bill i m'ha\n"
    .string "ensenyat la seva última invenció.\p"
    .string "M'ajudarà molt a omplir\n"
    .string "la meva Pokédex!\p"
    .string "Al cap i a la fi, en Bill és\n"
    .string "famós com a PokéManíac.\p"
    .string "Va inventar el Sistema\n"
    .string "d'Emmagatzematge Pokémon al PC.\p"
    .string "Com que fas servir el seu sistema,\n"
    .string "hauries d'anar a donar-li les\l"
    .string "gràcies.\p"
    .string "Bé, me'n vaig!\n"
    .string "Ens veiem!$"

CeruleanCity_Text_OhRightLittlePresentAsFavor::
    .string "Ah, sí, és veritat.\p"
    .string "La meva germana m'ha enviat un\n"
    .string "regal, però accidentalment n'ha\l"
    .string "posat dos a la caixa.\p"
    .string "No necessito tots dos, així que\n"
    .string "pots quedar-te'n un.\p"
    .string "No, de debò.\p"
    .string "Te'l dono com a favor, ja que\n"
    .string "sempre vas al meu darrere.$"

CeruleanCity_Text_ObtainedPokeblockCase::
	.string "Has obtingut un Estoig PokéBloc!\p"
	.string "{PLAYER} ha guardat l'Estoig\n"
	.string "PokéBloc als Obj. Clau.$"

CeruleanCity_Text_ExplainPokeblockSmellYa::
    .string "Un poca-cosa com tu…\n"
    .string "Això et va perfecte.\p"
    .string "Jo no el necessito perquè\n"
    .string "m'importen un rave els Concursos.\p"
    .string "Bé, ara sí que me'n vaig.\n"
    .string "Ens veiem!$"

CeruleanCity_EventScript_RivalStartExit::
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExit
	applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalStartExit
	waitmovement 10
	return

CeruleanCity_EventScript_RivalStartExitRight::
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExitRight
	applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalStartExitRight
	waitmovement 10
	return

CeruleanCity_Movement_PlayerWatchRivalExit::
	delay_16
	delay_8
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	walk_in_place_fast_down
	walk_in_place_fast_down
	step_end

CeruleanCity_Movement_PlayerWatchRivalExitRight::
	delay_16
	delay_8
	walk_in_place_fast_left
	walk_in_place_fast_left
	delay_16
	walk_in_place_fast_down
	walk_in_place_fast_down
	step_end

CeruleanCity_Movement_RivalEnter::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Movement_RivalStartExit::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_RivalStartExitRight::
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_RivalExit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_EventScript_Grunt::
	lock
	faceplayer
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_EventScript_GruntDefeated
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntIntro, CeruleanCity_Text_GruntDefeat, CeruleanCity_EventScript_GruntDefeated
	end

CeruleanCity_Text_GruntIntro::
    .string "Eh! Fora d'aquí!\n"
    .string "No és casa teva!\p"
    .string "…Eh?\n"
    .string "Jo?\p"
    .string "Sóc un simple vianant!\n"
    .string "No em creus?$"

CeruleanCity_Text_GruntDefeat::
    .string "Reclu: Para! Em rendeixo!\n"
    .string "Me n'aniré discretament!$"

CeruleanCity_EventScript_GruntDefeated::
	setvar VAR_CERULEAN_CITY_ROCKETS, 2
	msgbox CeruleanCity_Text_OkayIllReturnStolenTM, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_CERULEAN_ROCKET
	removeobject LOCALID_GRUNT
	clearflag FLAG_HIDE_CERULEAN_TM28
	addobject LOCALID_TMBALL
	playse SE_FLEE
	waitse
	fadescreen FADE_FROM_BLACK
	release
	end

CeruleanCity_Text_OkayIllReturnStolenTM::
    .string "…D'acord! Aquí tens!\p"
    .string "No aniré a la presó\n"
    .string "per una MT!$"

CeruleanCity_EventScript_StolenTM::
	lock
	checkitemspace ITEM_TM28, 1
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_EventScript_NoRoomForTM28
	setflag FLAG_HIDE_CERULEAN_TM28
	removeobject LOCALID_TMBALL
	playfanfare MUS_OBTAIN_TMHM
	msgbox CeruleanCity_Text_RecoveredStolenTM, MSGBOX_DEFAULT
	additem ITEM_TM28, 1
	setflag FLAG_RECOVERED_STOLEN_TM
	release
	end

CeruleanCity_Text_RecoveredStolenTM::
	.string "{PLAYER} ha recuperat la MT28\n"
	.string "robada!$"

CeruleanCity_EventScript_NoRoomForTM28::
	msgbox CeruleanCity_Text_MakeRoomForThis, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_MakeRoomForThis::
	.string "No tens prou espai.\n"
	.string "Fes-ne una mica!$"

CeruleanCity_EventScript_GruntTriggerTop::
	lockall
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 6
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	goto CeruleanCity_EventScript_Grunt
	end

CeruleanCity_EventScript_GruntTriggerBottom::
	lockall
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 6
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto CeruleanCity_EventScript_Grunt
	end

CeruleanCity_EventScript_Bulbasaur::
	lock
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, 4, CeruleanCity_EventScript_BulbasaurHappy
	turnobject LOCALID_BULBASAUR, DIR_NORTH
	playmoncry SPECIES_BULBASAUR, CRY_MODE_NORMAL
	msgbox CeruleanCity_Text_Bulbasaur, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanCity_Text_Bulbasaur:
	.string "Bulbasaur: ...grrr...$"

CeruleanCity_EventScript_BulbasaurHappy::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	delay 8
	playse SE_PIN
	applymovement LOCALID_BULBASAUR, Common_Movement_Heart
	waitmovement 14
	delay 8
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

CeruleanCity_EventScript_BulbasaurBreeder::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BULBASAUR, CeruleanCity_EventScript_ProudOfBulbasaur
	msgbox CeruleanCity_Text_BulbasaurDoesntTrustPeople, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_lt VAR_RESULT, 4, CeruleanCity_EventScript_BulbasaurStillNeedsTime
	call_if_eq VAR_FACING, DIR_NORTH, CeruleanCity_EventScript_BulbasaurApproachPlayerNear
	call_if_eq VAR_FACING, DIR_WEST, CeruleanCity_EventScript_BulbasaurApproachPlayerFar
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	delay 8
	playse SE_PIN
	applymovement LOCALID_BULBASAUR, Common_Movement_Heart
	waitmovement 14
	delay 8
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	turnobject LOCALID_BREEDER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_BREEDER, Common_Movement_ExclamationMark
	waitse
	waitmovement 13
	faceplayer
	msgbox CeruleanCity_Text_BulbasaurTrustsYou, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_BULBASAUR
	givemon SPECIES_BULBASAUR, 7, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, CeruleanCity_EventScript_BulbasaurParty
	goto_if_eq VAR_RESULT, 1, CeruleanCity_EventScript_BulbasaurPC
	goto_if_eq VAR_RESULT, 2, CeruleanCity_EventScript_NoRoomForBulbasaur
	end

CeruleanCity_EventScript_BulbasaurApproachPlayerNear::
	applymovement LOCALID_BULBASAUR, Movement_BulbaNear
	waitmovement 14
	return

Movement_BulbaNear:
 	walk_down
 	walk_in_place_fast_right
 	walk_in_place_fast_right
 	walk_in_place_fast_right
 	walk_in_place_fast_right
 	delay_16
 	step_end

CeruleanCity_EventScript_BulbasaurApproachPlayerFar::
	applymovement LOCALID_BULBASAUR,  Movement_BulbaFar
	waitmovement 14
	return

Movement_BulbaFar:
 	walk_down
 	walk_right
 	walk_right
 	walk_in_place_fast_up
 	walk_in_place_fast_up
 	walk_in_place_fast_up
 	walk_in_place_fast_up
 	delay_16
 	step_end

CeruleanCity_EventScript_BulbasaurParty::
	call CeruleanCity_EventScript_GetBulbasaur
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_EventScript_GotBulbasaur
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto CeruleanCity_EventScript_GotBulbasaur
	end

CeruleanCity_EventScript_GetBulbasaur::
	playfanfare MUS_LEVEL_UP
	message CeruleanCity_EventScript_Text_BefriendedBulbasaur
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
	return

CeruleanCity_EventScript_Text_BefriendedBulbasaur::
	.string "{PLAYER} s'ha fet amic del Bulbasaur!$"

CeruleanCity_EventScript_GotBulbasaur::
	setflag FLAG_GOT_BULBASAUR
	removeobject LOCALID_BULBASAUR
	release
	end

CeruleanCity_EventScript_BulbasaurPC::
	call CeruleanCity_EventScript_GetBulbasaur
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_EventScript_TransferBulbasaur
	call Common_EventScript_NameReceivedBoxMon
	goto CeruleanCity_EventScript_TransferBulbasaur
	end

CeruleanCity_EventScript_TransferBulbasaur::
	bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
	call Common_EventScript_TransferredToPC
	goto CeruleanCity_EventScript_GotBulbasaur
	end

CeruleanCity_EventScript_NoRoomForBulbasaur::
	msgbox CeruleanCity_Text_NoRoomForMorePokemon, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_NoRoomForMorePokemon::
    .string "Oh! No tens espai per a\n"
    .string "més Pokémon!$"

CeruleanCity_Text_BulbasaurDoesntTrustPeople::
	.string "Aquest Bulbasaur va resultar\n"
	.string "ferit intentant aturar l'Equip\l"
	.string "Rocket de segrestar Pokémon...\p"
	.string "Intento que torni a confiar\n"
	.string "en les persones.$"

CeruleanCity_Text_BulbasaurTrustsYou::
	.string "Increïble! Meravellós!\p"
	.string "Aquest Bulbasaur confia en tu!\p"
	.string "Ha tornat a obrir el cor\n"
	.string "a les persones...\p"
	.string "Crec que vol anar amb tu.\p"
	.string "D'acord! Jo també confio en tu!\p"
	.string "Si us plau, cuida'l bé!$"

CeruleanCity_EventScript_BulbasaurStillNeedsTime::
	turnobject LOCALID_BREEDER, DIR_WEST
	msgbox CeruleanCity_Text_BulbasaurNeedsTime, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_BulbasaurNeedsTime::
	.string "Encara necessita temps.\p"
	.string "No el culpo per guardar rancor.\n"
	.string "El que va fer l'Equip Rocket\l"
	.string "és imperdonable!$"

CeruleanCity_EventScript_ProudOfBulbasaur::
	msgbox CeruleanCity_Text_ProudOfBulbasaur, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_ProudOfBulbasaur::
	.string "Estic molt orgullós del Bulbasaur.\p"
	.string "Cal molt de coratge per\n"
	.string "confiar en els altres.$"

CeruleanCity_EventScript_BillCallsPlayer::
	lockall
	pokenavcall CeruleanCity_Text_DexNavCall
	waitmessage
	setvar VAR_SEA_COTTAGE_STATE, 5
	releaseall
	end

CeruleanCity_Text_DexNavCall::
	.string "???: Ei, ets {PLAYER}?\p"
	.string "Bill: Sí, sóc en Bill!\p"
	.string "He hagut d'enviar un correu al\n"
	.string "Prof. Oak per aconseguir el teu\l"
	.string "número. Espero que no et molesti!\p"
	.string "Devia tenir el cervell una mica\n"
	.string "remenat pel teletransportador\l"
	.string "quan em vas rescatar. Se m'ha\l"
	.string "oblidat ensenyar-te una cosa!\p"
	.string "Torna a la Caseta del Mar\n"
	.string "i t'ho ensenyaré!$"

CeruleanCity_EventScript_Venusaurite::
	finditem ITEM_VENUSAURITE, 1
	release
	end

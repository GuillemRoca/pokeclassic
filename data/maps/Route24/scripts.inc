.set LOCALID_CALE, 1
.set LOCALID_ALI, 2
.set LOCALID_TIMMY, 3
.set LOCALID_RELI, 4
.set LOCALID_ETHAN, 5
.set LOCALID_DISGUISED_ROCKET, 8
.set LOCALID_JESSIE, 9
.set LOCALID_JAMES, 10
.set LOCALID_ROCKET, 11
.set LOCALID_LOOKER, 12
.set LOCALID_CHARMANDER, 13


Route24_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route24_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route24_OnResume
	.byte 0

Route24_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route24_OnResume:
	call Common_EventScript_GetDayOrNight
	end

@Charmander
Route24_EventScript_Charmander::
	call Route24_EventScript_CharmanderEmote
	playmoncry SPECIES_CHARMANDER, CRY_MODE_NORMAL
	msgbox Route24_Text_Charmander, MSGBOX_NPC
	waitmoncry
	release
	end

Route24_Text_Charmander:
	.string "Charmander: Char!$"

Route24_EventScript_CharmanderEmote::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_CHARMANDER, Common_Movement_ExclamationMark
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return

Route24_EventScript_CharmanderGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_CHARMANDER, Route24_EventScript_HowsCharmander
	msgbox Route24_Text_NotCutOutToBeATrainer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_BetterReleaseIt
	setvar VAR_TEMP_1, SPECIES_CHARMANDER
	givemon SPECIES_CHARMANDER, 7, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, Route24_EventScript_CharmanderParty
	goto_if_eq VAR_RESULT, 1, Route24_EventScript_CharmanderPC
	goto_if_eq VAR_RESULT, 2, Route24_EventScript_NoRoomForCharmander
	end

Route24_EventScript_HowsCharmander::
	msgbox Route24_Text_HowsCharmander, MSGBOX_NPC
	release
	end

Route24_Text_HowsCharmander::
	.string "Com va el Charmander?$"

Route24_Text_NotCutOutToBeATrainer::
	.string "No se'm dona bé criar Pokémon.\p"
	.string "Hauria d'alliberar el meu\n"
	.string "Charmander perquè no l'he\l"
	.string "criat bé...\p"
	.string "Si em promets que en tindràs\n"
	.string "cura, és teu.$"

Route24_EventScript_BetterReleaseIt::
	msgbox Route24_Text_BetterReleaseIt, MSGBOX_NPC
	release
	end

Route24_Text_BetterReleaseIt::
	.string "Oh...serà millor alliberar-lo...$"


Route24_EventScript_CharmanderParty::
	call Route24_EventScript_GetCharmander
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route24_EventScript_GotCharmander
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route24_EventScript_GotCharmander
	end

Route24_EventScript_GetCharmander::
	playfanfare MUS_LEVEL_UP
	message Route24_EventScript_Text_TakeCareOfCharmander
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CHARMANDER
	return

Route24_EventScript_Text_TakeCareOfCharmander::
	.string "{PLAYER} ha promès cuidar bé\n"
	.string "el Charmander de l'entrenador!$"

Route24_EventScript_GotCharmander::
	setflag FLAG_GOT_CHARMANDER
	removeobject LOCALID_CHARMANDER
	release
	end

Route24_EventScript_CharmanderPC::
	call Route24_EventScript_GetCharmander
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route24_EventScript_TransferCharmander
	call Common_EventScript_NameReceivedBoxMon
	goto Route24_EventScript_TransferCharmander
	end

Route24_EventScript_TransferCharmander::
	call Common_EventScript_TransferredToPC
	goto Route24_EventScript_GotCharmander
	end

Route24_EventScript_NoRoomForCharmander::
	msgbox Route24_Text_NoRoomForMorePokemon, MSGBOX_DEFAULT
	release
	end

Route24_Text_NoRoomForMorePokemon::
    .string "Oh! No tens espai per a\n"
    .string "més Pokémon!$"

@Rocket Scene

Route24_EventScript_RocketTriggerLeft::
	lock
	applymovement LOCALID_DISGUISED_ROCKET, Movement_StopPlayerLeft
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	waitmovement 8
	msgbox Route24_Text_GetYourReward, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Movement_CenterPlayerLeft
	waitmovement 0
	turnobject LOCALID_DISGUISED_ROCKET, DIR_SOUTH
	goto Route24_EventScript_DisguisedRocket
	end

Movement_StopPlayerLeft:
	face_left
	emote_question_mark
	delay_16
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	delay_16
	delay_16
	step_end

Movement_CenterPlayerLeft:
	walk_down
	walk_right
	face_up
	step_end

Route24_EventScript_RocketTriggerRight::
	lock
	applymovement LOCALID_DISGUISED_ROCKET, Movement_StopPlayerRight
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	waitmovement 8
	msgbox Route24_Text_GetYourReward, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Movement_CenterPlayerRight
	waitmovement 0
	turnobject LOCALID_DISGUISED_ROCKET, DIR_SOUTH
	goto Route24_EventScript_DisguisedRocket
	end

Movement_StopPlayerRight:
	face_right
	emote_question_mark
	delay_16
	delay_16
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	delay_16
	step_end

Movement_CenterPlayerRight:
	walk_down
	walk_left
	face_up
	step_end

Route24_Text_GetYourReward:
	.string "Perdona!\n"
	.string "No vols la teva recompensa?$"

Route24_EventScript_DisguisedRocket::
	lock
	msgbox Route24_Text_JustEarnedFabulousPrize, MSGBOX_DEFAULT
	checkitemspace ITEM_NUGGET, 1
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_NoRoomForNugget
	playfanfare MUS_OBTAIN_ITEM
	msgbox Route24_Text_ReceivedNuggetFromMysteryTrainer, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_NUGGET, 1
	applymovement LOCALID_DISGUISED_ROCKET, Movement_LookSuspicious
	msgbox Route24_Text_SecretPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route24_EventScript_SecretPrize
	msgbox Route24_Text_WasntReallyAQuestion, MSGBOX_DEFAULT
	removeobject LOCALID_ROCKET
	setobjectxyperm LOCALID_ROCKET, 11, 15
	clearflag FLAG_HIDE_ROUTE24_ROCKET
	applymovement LOCALID_DISGUISED_ROCKET, Movement_RocketReveal
	playse SE_EXIT
	waitse
	addobject LOCALID_ROCKET
	removeobject LOCALID_DISGUISED_ROCKET
	goto Route24_EventScript_DisguisedRocketBattle
	end

Route24_Text_JustEarnedFabulousPrize::
    .string "Felicitats! Has vençut els\n"
    .string "cinc Entrenadors del concurs!\p"
    .string "Has guanyat un premi fabulós!$"

Route24_Text_ReceivedNuggetFromMysteryTrainer::
    .string "{PLAYER} ha rebut una Pepita\n"
    .string "de l'Entrenador misteriós!$"

Route24_Text_SecretPrize::
	.string "Saps, noi, no he vist mai\n"
	.string "ningú lluitar així...\p"
	.string "Crec que qualifiques per al\n"
	.string "Premi Secret!\p"
	.string "Què em dius...\n"
	.string "Vols el Premi Secret?$"

Movement_LookSuspicious:
	face_left
	delay_16
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	face_down
	step_end

Route24_Text_WasntReallyAQuestion::
	.string "Potser no m'he explicat bé.\p"
	.string "No era realment una pregunta.\p"
	.string "Mira, el Pont Pepita està\n"
	.string "finançat per l'Equip Rocket!$"

Movement_RocketReveal::
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	delay_16
	step_end

Route24_EventScript_DisguisedRocketBattle::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_6, Route24_Text_RocketGruntIntro, Route24_Text_RocketGruntDefeat, Route24_EventScript_DisguisedRocketDefeated
	end

Route24_Text_RocketGruntIntro:
	.string "Som un grup de criminals\n"
    .string "professionals de Pokémon!\p"
    .string "Un entrenador fort com tu...\n"
    .string "els meus caps s'enfadarien si\l"
    .string "perdés l'oportunitat de\l"
    .string "reclutar-te!\p"
    .string "Aquest és el premi secret:\n"
    .string "unir-te a l'Equip Rocket!\p"
    .string "…Bé, necessites convèncer-te!\p"
    .string "Et faré una oferta que no\n"
    .string "podràs rebutjar!$"

Route24_Text_RocketGruntDefeat::
    .string "Argh!\n"
    .string "Ets bo!$"

Route24_EventScript_DisguisedRocketDefeated::
	msgbox Route24_Text_BossesAreGonnaKillMe, MSGBOX_DEFAULT
	applymovement LOCALID_ROCKET, Movement_RocketBails
	waitmovement 11
	removeobject LOCALID_JESSIE
	removeobject LOCALID_JAMES
	setvar VAR_CERULEAN_CITY_ROCKETS, 1
	fadenewbgm MUS_ENCOUNTER_CHAMPION
	goto Route24_EventScript_LookerConclusion
	end

Route24_Text_BossesAreGonnaKillMe::
	.string "Els meus caps em mataran!\n"
	.string "He de fugir!$"

Route24_EventScript_SecretPrize::
	applymovement LOCALID_DISGUISED_ROCKET, Common_Movement_ExclamationMark
	msgbox Route24_Text_OhWowThatsGreat, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DISGUISED_ROCKET, Movement_GetJessieJames
	fadescreen FADE_TO_BLACK
	setflag FLAG_SYS_FORCE_LOAD_OFFSCREEN_OBJ
	waitmovement 9
	removeobject LOCALID_DISGUISED_ROCKET
	delay 10
	fadescreen FADE_FROM_BLACK
	fadenewbgm MUS_RG_ENCOUNTER_ROCKET
	applymovement LOCALID_ROCKET, Movement_RocketApproach
	applymovement LOCALID_JESSIE, Movement_JessieJamesEnter
	applymovement LOCALID_JAMES, Movement_JessieJamesEnter
	waitmovement 11
	msgbox Route24_Text_ThisIsTheKid, MSGBOX_DEFAULT
	applymovement LOCALID_JESSIE, Movement_JessieAction
	applymovement LOCALID_JAMES, Movement_JamesAction
	waitmovement 9
	msgbox Route24_Text_YouFool, MSGBOX_DEFAULT
	applymovement LOCALID_ROCKET, Common_Movement_ExclamationMark
	waitmovement 11
	msgbox Route24_Text_YourProblemNow, MSGBOX_DEFAULT
	applymovement LOCALID_ROCKET, Movement_RocketBails
	closemessage
	waitmovement 11
	removeobject LOCALID_ROCKET
	applymovement LOCALID_JESSIE, Movement_JessieApproach
	applymovement LOCALID_JAMES, Movement_JamesApproach
	waitmovement 9
	goto Route24_EventScript_BattleJessieJames
	end

Movement_RocketApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Movement_JessieJamesEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route24_Text_ThisIsTheKid::
	.string "Jessie, James, aquest és el\n"
	.string "nen del qual us parlava!\p"
	.string "S'ha guanyat el Premi Secret.\p"
    .string "Amb la seva habilitat, seria un\n"
    .string "líder de l'Equip Rocket.\p"
    .string "N'estic segur!\p"
    .string "Què en dieu?\n"
    .string "El deixem unir-se?$"

Route24_Text_OhWowThatsGreat::
	.string "Uau! De debò?\p"
	.string "Normalment costa més\n"
	.string "convèncer la gent...\p"
	.string "Genial! Deixa'm anar a buscar\n"
	.string "els meus caps, i preparem\l"
	.string "el teu Premi Secret!$"

Movement_GetJessieJames::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_JessieAction:
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	delay_16
	delay_16
	step_end

Movement_JamesAction:
	delay_16
	delay_16
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	step_end

Movement_RocketBails:
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	delay_16
	walk_in_place_fast_left
	walk_in_place_fast_left
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_JessieApproach:
	walk_down
	face_right
	emote_exclamation_mark
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	delay_16
	step_end

Movement_JamesApproach:
	delay_16
	delay_16
	walk_down
	face_left
	emote_exclamation_mark
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

Route24_Text_YouFool:
	.string "Jessie: Ximple!\p"
	.string "James: Imbècil!\p"
	.string "Jessie: Aquest és el marrec\n"
	.string "que va arruïnar els nostres\l"
	.string "plans al Mt. Moon!\p"
	.string "James: Segurament ha portat\n"
	.string "la Policia Internacional\l"
	.string "fins a nosaltres!$"

Route24_Text_YourProblemNow:
	.string "Rocket: Ui!\p"
	.string "Bé...ehm...llavors tots dos\n"
	.string "voleu la revenja, oi?\p"
	.string "Sí! Vaig a avisar els altres!$"

Route24_EventScript_BattleJessieJames::
	trainerbattle_double TRAINER_ROCKET_DUO_NB, Route24_Text_RocketDuoIntro, Route24_Text_RocketDuoDefeat, Text_NeedTwoMons, Route24_EventScript_RocketDuoDefeated, NO_MUSIC
	end

Route24_Text_RocketDuoIntro:
	.string "Jessie: Per vèncer-nos al\n"
	.string "Mt. Moon...\p"
	.string "James: Et farem quedar\n"
	.string "com un bufó!\p"
	.string "Jessie: Prepara't per als\n"
	.string "problemes!\n"
	.string "James: I més que dobles!$"

Route24_Text_RocketDuoDefeat:
	.string "Marrec! Com has pogut\n"
	.string "fer-nos això un altre cop!$"

Route24_EventScript_RocketDuoDefeated::
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	msgbox Route24_Text_WontBeTheLastTime, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	closemessage
	playse SE_FLEE
	waitse
	removeobject LOCALID_JESSIE
	removeobject LOCALID_JAMES
	clearflag FLAG_SYS_FORCE_LOAD_OFFSCREEN_OBJ
	setvar VAR_CERULEAN_CITY_ROCKETS, 1
	fadenewbgm MUS_ENCOUNTER_CHAMPION
	fadescreen FADE_FROM_BLACK
	goto Route24_EventScript_LookerConclusion

Route24_Text_WontBeTheLastTime::
	.string "Aquesta no serà l'última vegada\n"
	.string "que t'enfrontaràs a l'Equip\l"
	.string "Rocket!\p"
	.string "Alegra't que avui t'ho posem\n"
	.string "fàcil!$"

Route24_EventScript_LookerConclusion::
	closemessage
	clearflag FLAG_HIDE_ROUTE24_LOOKER
	addobject LOCALID_LOOKER
	setobjectxyperm LOCALID_ROCKET, 11,9
	clearflag FLAG_HIDE_ROUTE24_ROCKET
	addobject LOCALID_ROCKET
	applymovement OBJ_EVENT_ID_PLAYER, Movement_MoveToLooker
	waitmovement 0
	message Route25_Text_ComingWithUs
	waitmessage
	delay 10
	closemessage
	applymovement LOCALID_LOOKER, Movement_LookerCaughtRocket
	applymovement LOCALID_ROCKET, Movement_RocketGotCaught
	waitmovement 12
	removeobject LOCALID_LOOKER
	removeobject LOCALID_ROCKET
	fadedefaultbgm
	releaseall
	end

Route25_Text_ComingWithUs::
	.string "Looker: No tan ràpid.\n"
	.string "Vindràs amb nosaltres.\p"
	.string "Tinc ganes de saber més\n"
	.string "sobre aquest Premi Secret...$"

Movement_MoveToLooker::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	emote_exclamation_mark
	step_end

Movement_LookerCaughtRocket::
	delay_16
	delay_16
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Movement_RocketGotCaught::
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	delay_16
	delay_16
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route24_EventScript_NoRoomForNugget::
	msgbox Route24_Text_YouDontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route24_Text_YouDontHaveAnyRoom::
    .string "No tens espai!\p"
    .string "Al meu cap li molestaria que\n"
    .string "no et donés el premi, així\l"
    .string "que torna quan tinguis espai!$"

Route24_EventScript_ItemTM45::
	finditem ITEM_TM45, 1
	end

Route24_EventScript_Shane::
	trainerbattle_single REMATCHABLE_TRAINER_CAMPER_SHANE_1, Route24_Text_ShaneIntro, Route24_Text_ShaneDefeat, Route24_EventScript_RegisterShaneAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route24_EventScript_ShaneRematch
	msgbox Route24_Text_ShanePostBattle, MSGBOX_DEFAULT
	release
	end

Route24_Text_ShaneIntro::
    .string "He estat mirant els teus combats\n"
    .string "al Pont Pepita des d'aquí!$"

Route24_Text_ShaneDefeat::
    .string "Ja m'ho pensava!$"

Route24_Text_ShanePostBattle::
    .string "M'he amagat perquè la gent del\n"
    .string "pont em feia por.$"

Route24_EventScript_RegisterShaneAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route24_Text_ShaneRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_CAMPER_SHANE_1
	release
	end

Route24_Text_ShaneRegister:
	.string "Uau! Ets fort!\p"
	.string "Si fossis el meu amic, no\n"
	.string "hauria de tenir por!$"

Route24_EventScript_ShaneRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_CAMPER_SHANE_1, Route24_Text_ShaneRematchIntro, Route24_Text_ShaneDefeat
	msgbox Route24_Text_ShaneRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route24_Text_ShaneRematchIntro::
	.string "Ei, {PLAYER}!\n"
	.string "Ensenya'm a ser fort com tu!$"

Route24_Text_ShaneRematchPostBattle::
	.string "Seguiré mirant-te des d'aquí!$"


@Normal Nugget Bridge Trainers
Movement_NuggetBridgeTrainerExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route24_EventScript_Cale::
	trainerbattle_single TRAINER_BUG_CATCHER_CALE, Route24_Text_CaleIntro, Route24_Text_CaleDefeat, Route24_EventScript_CalePostBattle
	end

Route24_EventScript_CalePostBattle::
	msgbox Route24_Text_CalePostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_CALE, Movement_NuggetBridgeTrainerExit
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	waitmovement 1
	removeobject LOCALID_CALE
	end

Route24_Text_CaleIntro::
    .string "La gent anomena això el\n"
    .string "Pont Pepita!\p"
    .string "Venç els cinc Entrenadors i\n"
    .string "guanya un premi fabulós!\p"
    .string "Creus que pots?$"

Route24_Text_CaleDefeat::
    .string "Uau!\n"
    .string "Ben fet!$"

Route24_Text_CalePostBattle::
    .string "Ho he donat tot. No em penedeixo!$"

Route24_EventScript_Ali::
	trainerbattle_single TRAINER_LASS_ALI, Route24_Text_AliIntro, Route24_Text_AliDefeat, Route24_EventScript_AliPostBattle

Route24_EventScript_AliPostBattle::
	msgbox Route24_Text_AliPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_ALI, Movement_NuggetBridgeTrainerExit
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	waitmovement 2
	removeobject LOCALID_ALI
	end

Route24_Text_AliIntro::
    .string "Sóc la segona!\n"
    .string "Ara la cosa es posa seriosa!$"

Route24_Text_AliDefeat::
    .string "Com he pogut perdre?$"

Route24_Text_AliPostBattle::
    .string "Ho he donat tot. No em penedeixo!$"

Route24_EventScript_Timmy::
	trainerbattle_single TRAINER_YOUNGSTER_TIMMY, Route24_Text_TimmyIntro, Route24_Text_TimmyDefeat, Route24_EventSript_TimmyPostBattle
	end

Route24_EventSript_TimmyPostBattle::
	msgbox Route24_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_TIMMY, Movement_NuggetBridgeTrainerExit
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	waitmovement 3
	removeobject LOCALID_TIMMY
	end

Route24_Text_TimmyIntro::
    .string "Aquí ve el Nº 3!\n"
    .string "No serà fàcil!$"

Route24_Text_TimmyDefeat::
    .string "Au!\n"
    .string "Aixafat!$"

Route24_Text_TimmyPostBattle::
    .string "Ho he donat tot. No em penedeixo!$"

Route24_EventScript_Reli::
	trainerbattle_single TRAINER_LASS_RELI, Route24_Text_ReliIntro, Route24_Text_ReliDefeat, Route24_EventScript_ReliPostBattle
	end

Route24_EventScript_ReliPostBattle::
	msgbox Route24_Text_ReliPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_RELI, Movement_NuggetBridgeTrainerExit
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	waitmovement 4
	removeobject LOCALID_RELI
	end

Route24_Text_ReliIntro::
    .string "Sóc la Nº 4!\n"
    .string "Estàs cansat?$"

Route24_Text_ReliDefeat::
    .string "Jo també he perdut!$"

Route24_Text_ReliPostBattle::
    .string "Ho he donat tot, no em penedeixo!$"

Route24_EventScript_Ethan::
	trainerbattle_single TRAINER_CAMPER_ETHAN, Route24_Text_EthanIntro, Route24_Text_EthanDefeat, Route24_EventScript_EthanPostBattle
	end

Route24_EventScript_EthanPostBattle::
	msgbox Route24_Text_EthanPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_ETHAN, Movement_NuggetBridgeTrainerExit
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	waitmovement 5
	removeobject LOCALID_ETHAN
	end

Route24_Text_EthanIntro::
    .string "D'acord! Sóc el Nº 5!\n"
    .string "T'aixafaré!$"

Route24_Text_EthanDefeat::
    .string "Uau!\n"
    .string "Massa fort!$"

Route24_Text_EthanPostBattle::
    .string "Ho he donat tot. No em penedeixo!$"

@TODO: Postgame Nugget Bridge


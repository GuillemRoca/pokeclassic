.set LOCALID_RIVAL,     2
.set LOCALID_WORKER_M2, 6

SilphCo_7F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_7F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_7F_OnTransition
	.byte 0

SilphCo_7F_OnLoad::
	call_if_unset FLAG_SILPH_7F_DOOR_1, EventScript_Close7FDoor1
	call_if_unset FLAG_SILPH_7F_DOOR_2, EventScript_Close7FDoor2
	call_if_unset FLAG_SILPH_7F_DOOR_3, EventScript_Close7FDoor3
	end

SilphCo_7F_OnTransition::
	call_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_7F_EventScript_SetObjRocketsGone
	end

SilphCo_7F_EventScript_ItemCalcium::
	finditem ITEM_CALCIUM, 1
	release
	end

SilphCo_7F_EventScript_SetObjRocketsGone::
	setobjectmovementtype LOCALID_WORKER_M2, MOVEMENT_TYPE_FACE_UP
	return

SilphCo_7F_EventScript_LaprasGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_LAPRAS_FROM_SILPH, SilphCo_7F_EventScript_AlreadyGotLapras
	msgbox SilphCo_7F_Text_HaveMonForSavingUs
	setvar VAR_TEMP_1, SPECIES_LAPRAS
	givemon SPECIES_LAPRAS, 25, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, SilphCo_7F_EventScript_LaprasParty
	goto_if_eq VAR_RESULT, 1, SilphCo_7F_EventScript_LaprasPC
	goto_if_eq VAR_RESULT, 2, SilphCo_7F_EventScript_NoRoomForLapras
	end

SilphCo_7F_EventScript_AlreadyGotLapras::
	msgbox SilphCo_7F_Text_RocketBossWentToBoardroom
	release
	end

SilphCo_7F_EventScript_LaprasParty::
	call SilphCo_7F_EventScript_GetLapras
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_GotLapras
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SilphCo_7F_EventScript_GotLapras
	end

SilphCo_7F_EventScript_GetLapras::
	playfanfare MUS_LEVEL_UP
	message SilphCo_7F_EventScript_Text_TakeCareOfLapras
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LAPRAS
	return

SilphCo_7F_EventScript_Text_TakeCareOfLapras::
	.string "{PLAYER} ha acceptat el Lapras\n"
	.string "del Científic de Silph S.A.!$"

SilphCo_7F_EventScript_GotLapras::
	msgbox SilphCo_7F_Text_ExplainLapras
	setflag FLAG_GOT_LAPRAS_FROM_SILPH
	release
	end

SilphCo_7F_EventScript_LaprasPC::
	call SilphCo_7F_EventScript_GetLapras
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_TransferLapras
	call Common_EventScript_NameReceivedBoxMon
	goto SilphCo_7F_EventScript_TransferLapras
	end

SilphCo_7F_EventScript_TransferLapras::
	call Common_EventScript_TransferredToPC
	goto SilphCo_7F_EventScript_GotLapras
	end

SilphCo_7F_EventScript_NoRoomForLapras::
	msgbox SilphCo_7F_Text_NoRoomForMorePokemon, MSGBOX_DEFAULT
	release
	end

SilphCo_7F_Text_NoRoomForMorePokemon::
	.string "Oh! No tens espai per a més\n"
	.string "Pokémon!"

SilphCo_7F_EventScript_RivalTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 1
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalScene::
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 2
	msgbox SilphCo_7F_Text_RivalWhatKeptYou
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalApproachTop
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalApproachBottom
	msgbox SilphCo_7F_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_RIVAL
	call_if_eq VAR_RIVAL_WINRATE, 2, SilphCo_7F_EventScript_RivalJolteon
	call_if_eq VAR_RIVAL_WINRATE, 1, SilphCo_7F_EventScript_RivalFlareon
	call_if_eq VAR_RIVAL_WINRATE, 0, SilphCo_7F_EventScript_RivalVaporeon
	msgbox SilphCo_7F_Text_RivalPostBattle
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalExitTop
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalExitBottom
	playse SE_WARP_IN
	fadedefaultbgm
	removeobject LOCALID_RIVAL
	waitse
	setvar VAR_SILPH_STATE, 1
	releaseall
	end

SilphCo_7F_EventScript_RivalApproachTop::
	closemessage
	applymovement LOCALID_RIVAL, SilphCo_7F_Movement_RivalApproachTop
	waitmovement 2
	return

SilphCo_7F_EventScript_RivalApproachBottom::
	return

SilphCo_7F_EventScript_RivalJolteon::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_CO_JOLTEON, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalFlareon::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_CO_FLAREON, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalVaporeon::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_CO_VAPOREON, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalExitTop::
	applymovement LOCALID_RIVAL, SilphCo_7F_Movement_RivalExitTop
	waitmovement 2
	return

SilphCo_7F_EventScript_RivalExitBottom::
	applymovement LOCALID_RIVAL, SilphCo_7F_Movement_RivalExitBottom
	waitmovement 2
	return

SilphCo_7F_Movement_RivalApproachTop::
	walk_up
	step_end

SilphCo_7F_Movement_RivalExitTop::
	walk_right
	walk_right
	walk_right
	walk_up
	delay_16
	step_end

SilphCo_7F_Movement_RivalExitBottom::
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	delay_16
	step_end



SilphCo_7F_EventScript_WorkerM1::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_7F_EventScript_WorkerM1RocketsGone
	msgbox SilphCo_7F_Text_RocketsAfterMasterBall
	release
	end

SilphCo_7F_EventScript_WorkerM1RocketsGone::
	msgbox SilphCo_7F_Text_CanceledMasterBallProject
	release
	end

SilphCo_7F_EventScript_WorkerM2::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_7F_EventScript_WorkerM2RocketsGone
	msgbox SilphCo_7F_Text_BadIfTeamRocketTookOver
	release
	end

SilphCo_7F_EventScript_WorkerM2RocketsGone::
	msgbox SilphCo_7F_Text_WowYouChasedOffTeamRocket
	release
	end

SilphCo_7F_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_7F_EventScript_WorkerFRocketsGone
	msgbox SilphCo_7F_Text_ReallyDangerousHere
	release
	end

SilphCo_7F_EventScript_WorkerFRocketsGone::
	msgbox SilphCo_7F_Text_ThankYouSoMuch
	release
	end

SilphCo_7F_EventScript_FloorSign::
	msgbox SilphCo_7F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_7F_EventScript_Joshua::
	trainerbattle_single TRAINER_SCIENTIST_JOSHUA, SilphCo_7F_Text_JoshuaIntro, SilphCo_7F_Text_JoshuaDefeat
	msgbox SilphCo_7F_Text_JoshuaPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_33, SilphCo_7F_Text_Grunt1Intro, SilphCo_7F_Text_Grunt1Defeat
	msgbox SilphCo_7F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_34, SilphCo_7F_Text_Grunt2Intro, SilphCo_7F_Text_Grunt2Defeat
	msgbox SilphCo_7F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_35, SilphCo_7F_Text_Grunt3Intro, SilphCo_7F_Text_Grunt3Defeat
	msgbox SilphCo_7F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_Text_HaveMonForSavingUs::
    .string "Oh! Hola! No ets un Rocket!\n"
    .string "Has vingut a salvar-nos?\l"
    .string "Moltes gràcies!\p"
    .string "Vull donar-te aquest Pokémon\n"
    .string "per salvar-nos.$"

SilphCo_7F_Text_ObtainedLaprasFromEmployee::
    .string "{PLAYER} ha obtingut un LAPRAS\n"
    .string "de l'empleat de Silph!$"

SilphCo_7F_Text_ExplainLapras::
    .string "És un Lapras.\n"
    .string "És un Pokémon molt intel·ligent.\p"
    .string "El teníem al nostre laboratori,\n"
    .string "però estarà molt millor amb tu.\p"
    .string "Crec que seràs un bon entrenador\n"
    .string "per a Lapras!\p"
    .string "És un bon nedador. Et portarà\n"
    .string "per l'aigua!$"

SilphCo_7F_Text_RocketBossWentToBoardroom::
    .string "El Cap de l'Equip Rocket ha anat\n"
    .string "a la sala de juntes!\p"
    .string "El nostre President estarà bé?\n"
    .string "Estic preocupat.$"

SilphCo_7F_Text_RocketsAfterMasterBall::
    .string "L'Equip Rocket anava darrere la\n"
    .string "Master Ball, que captura\l"
    .string "qualsevol Pokémon.$"

SilphCo_7F_Text_CanceledMasterBallProject::
    .string "Hem cancel·lat el projecte de la\n"
    .string "MASTER Ball per culpa de l'Equip\l"
    .string "Rocket.$"

SilphCo_7F_Text_BadIfTeamRocketTookOver::
    .string "Seria dolent si l'Equip Rocket\n"
    .string "s'apoderés de Silph o dels\l"
    .string "nostres Pokémon.$"

SilphCo_7F_Text_WowYouChasedOffTeamRocket::
    .string "Uau!\p"
    .string "Has foragitat l'Equip Rocket\n"
    .string "tot sol?$"

SilphCo_7F_Text_ReallyDangerousHere::
    .string "Tu!\n"
    .string "Aquí és molt perillós!\p"
    .string "Has vingut a salvar-me?\n"
    .string "No pots!$"

SilphCo_7F_Text_ThankYouSoMuch::
    .string "Moltes gràcies!$"

SilphCo_7F_Text_Grunt3Intro::
    .string "Oh-oh!\n"
    .string "Ensumo un ratolí!$"

SilphCo_7F_Text_Grunt3Defeat::
    .string "Llums apagats!$"

SilphCo_7F_Text_Grunt3PostBattle::
    .string "No trobaràs el meu Cap només\n"
    .string "corrent per aquí!$"

SilphCo_7F_Text_JoshuaIntro::
    .string "Heheh!\p"
    .string "M'has confós amb un treballador\n"
    .string "de Silph?$"

SilphCo_7F_Text_JoshuaDefeat::
    .string "Estic acabat!$"

SilphCo_7F_Text_JoshuaPostBattle::
    .string "Malgrat la teva edat, ets un\n"
    .string "entrenador hàbil!$"

SilphCo_7F_Text_Grunt1Intro::
    .string "Sóc un dels quatre Germans\n"
    .string "Rocket!$"

SilphCo_7F_Text_Grunt1Defeat::
    .string "Aack!\n"
    .string "Germans, he perdut!$"

SilphCo_7F_Text_Grunt1PostBattle::
    .string "No importa.\n"
    .string "Els meus germans em tornaran\l"
    .string "el favor!$"

SilphCo_7F_Text_Grunt2Intro::
    .string "Un intrús infantil?\n"
    .string "Deus ser tu!$"

SilphCo_7F_Text_Grunt2Defeat::
    .string "D'acord!\n"
    .string "He perdut!$"

SilphCo_7F_Text_Grunt2PostBattle::
    .string "Vés-te'n a casa abans que el meu\n"
    .string "Cap s'enfadi!$"

SilphCo_7F_Text_RivalWhatKeptYou::
    .string "{RIVAL}: Què t'ha entretingut,\n"
    .string "{PLAYER}?$"

SilphCo_7F_Text_RivalIntro::
    .string "{RIVAL}: Hahaha! Sabia que\n"
    .string "apareixeries si esperava aquí!\p"
    .string "Suposo que l'Equip Rocket t'ha\n"
    .string "alentit! No és que m'importi!\p"
    .string "Et vaig veure a SAFFRON, així que\n"
    .string "vaig decidir veure si has\l"
    .string "millorat!$"

SilphCo_7F_Text_RivalDefeat::
    .string "Oh, no!\n"
    .string "Bé, estàs preparat per al Cap\l"
    .string "Rocket!$"

SilphCo_7F_Text_RivalPostBattle::
    .string "Bé, {PLAYER}!\n"
    .string "Jo segueixo pujant i avançant!\p"
    .string "Consultant la meva Pokédex,\n"
    .string "començo a veure què és fort i\l"
    .string "com evolucionen!\p"
    .string "Sóc un geni o què?\p"
    .string "Vaig a la Lliga Pokémon a fotre\n"
    .string "fora l'Alt Comandament.\p"
    .string "Seré l'Entrenador més poderós\n"
    .string "del món!\p"
    .string "{PLAYER}, bé, bona sort!\n"
    .string "No pateixis!\l"
    .string "Ens veiem!$"

SilphCo_7F_Text_FloorSign::
    .string "Seu Central de Silph S.A.\n"
    .string "7è pis$"


SilphCo_7F_EventScript_PostgameGrunt5::
	trainerbattle_single TRAINER_POSTGAME_ROCKET_5, SilphCo_7F_Text_PostgameGrunt5Intro, SilphCo_7F_Text_PostgameGrunt5Defeat
	msgbox SilphCo_7F_Text_PostgameGrunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_Text_PostgameGrunt5Intro::
    .string "No faràs quedar malament l'Equip\n"
    .string "Rocket un altre cop, nen!$"

SilphCo_7F_Text_PostgameGrunt5Defeat::
    .string "Això no pot estar passant!$"

SilphCo_7F_Text_PostgameGrunt5PostBattle::
    .string "El nostre Cap és el més fort de\n"
    .string "tots els Soldats.$"

SilphCo_7F_EventScript_PostgameGrunt6::
	trainerbattle_single TRAINER_POSTGAME_ROCKET_6, SilphCo_7F_Text_PostgameGrunt6Intro, SilphCo_7F_Text_PostgameGrunt6Defeat
	msgbox SilphCo_7F_Text_PostgameGrunt6PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_Text_PostgameGrunt6Intro::
    .string "Només els Soldats més lleials\n"
    .string "van ser escollits per a aquesta\l"
    .string "missió.$"

SilphCo_7F_Text_PostgameGrunt6Defeat::
    .string "Equip Rocket fins al final!$"

SilphCo_7F_Text_PostgameGrunt6PostBattle::
    .string "Encara en quedem més per\n"
    .string "aquí fora.$"

SilphCo_7F_EventScript_ItemTM08::
	finditem ITEM_TM08, 1
	release
	end

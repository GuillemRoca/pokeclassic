VictoryRoad_3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_3F_OnLoad
	.byte 0

VictoryRoad_3F_OnLoad::
	call_if_ne VAR_VICTORY_ROAD_3F_STATE, 100, VictoryRoad_3F_EventScript_SetRockBarrier
	end

VictoryRoad_3F_EventScript_SetRockBarrier::
	setmetatile 12, 12, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 12, 13, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_3F_EventScript_FloorSwitch::
	lockall
	goto_if_eq VAR_VICTORY_ROAD_3F_STATE, 100, VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed
	setmetatile 12, 12, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 12, 13, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm 7
	copyobjectxytoperm 10
	setvar VAR_VICTORY_ROAD_3F_STATE, 100
	releaseall
	end

VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed::
	releaseall
	end

VictoryRoad_3F_EventScript_George::
	trainerbattle_single TRAINER_COOLTRAINER_GEORGE, VictoryRoad_3F_Text_GeorgeIntro, VictoryRoad_3F_Text_GeorgeDefeat
	msgbox VictoryRoad_3F_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_Text_GeorgeIntro::
    .string "He sentit rumors d'un nen prodigi.$"

VictoryRoad_3F_Text_GeorgeDefeat::
    .string "Els rumors eren certs!$"

VictoryRoad_3F_Text_GeorgePostBattle::
    .string "Així que ets tu qui va derrotar\n"
    .string "en Giovanni del Team Rocket?$"

VictoryRoad_3F_EventScript_Colby::
	trainerbattle_single TRAINER_COOLTRAINER_COLBY, VictoryRoad_3F_Text_ColbyIntro, VictoryRoad_3F_Text_ColbyDefeat
	msgbox VictoryRoad_3F_Text_ColbyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_Text_ColbyIntro::
    .string "Només els escollits poden passar!$"

VictoryRoad_3F_Text_ColbyDefeat::
    .string "No m'ho puc creure!$"

VictoryRoad_3F_Text_ColbyPostBattle::
    .string "Tots els Entrenadors d'aquí van\n"
    .string "cap a la Lliga Pokémon.\p"
    .string "No baixis la guàrdia.$"

VictoryRoad_3F_EventScript_Caroline::
	trainerbattle_single TRAINER_COOLTRAINER_CAROLINE, VictoryRoad_3F_Text_CarolineIntro, VictoryRoad_3F_Text_CarolineDefeat
	msgbox VictoryRoad_3F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_Text_CarolineIntro::
    .string "Et mostraré com de bo ets.\n"
    .string "O no!$"

VictoryRoad_3F_Text_CarolineDefeat::
    .string "Estic furiosa!$"

VictoryRoad_3F_Text_CarolinePostBattle::
    .string "M'has mostrat com de bona\n"
    .string "era jo…$"

VictoryRoad_3F_EventScript_Alexa::
	trainerbattle_single TRAINER_COOLTRAINER_ALEXA, VictoryRoad_3F_Text_AlexaIntro, VictoryRoad_3F_Text_AlexaDefeat
	msgbox VictoryRoad_3F_Text_AlexaPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_Text_AlexaIntro::
    .string "Els Entrenadors viuen per buscar\n"
    .string "oponents més forts.$"

VictoryRoad_3F_Text_AlexaDefeat::
    .string "Oh!\n"
    .string "Que fort!$"

VictoryRoad_3F_Text_AlexaPostBattle::
    .string "Lluitant combats durs, et fas\n"
    .string "més fort.$"

VictoryRoad_3F_EventScript_Ray::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_RayIntro, VictoryRoad_3F_Text_RayDefeat, VictoryRoad_3F_Text_RayNotEnoughMons
	msgbox VictoryRoad_3F_Text_RayPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_Text_RayIntro::
    .string "Ray: Junts, nosaltres dos estem\n"
    .string "destinats a la grandesa!$"

VictoryRoad_3F_Text_RayDefeat::
    .string "Ray: Ridícul!\n"
    .string "Això no pot ser!$"

VictoryRoad_3F_Text_RayPostBattle::
    .string "Ray: Ens has derrotat.\n"
    .string "La grandesa segueix sent esquiva…$"

VictoryRoad_3F_Text_RayNotEnoughMons::
    .string "Ray: Junts, nosaltres dos aspirem\n"
    .string "al cim.\p"
    .string "Necessitem que portis dos Pokémon\n"
    .string "al combat amb nosaltres.$"

VictoryRoad_3F_EventScript_Tyra::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_TyraIntro, VictoryRoad_3F_Text_TyraDefeat, VictoryRoad_3F_Text_TyraNotEnoughMons
	msgbox VictoryRoad_3F_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_Text_TyraIntro::
    .string "Tyra: Estem intentant ser\n"
    .string "campions junts.$"

VictoryRoad_3F_Text_TyraDefeat::
    .string "Tyra: Oh, però…$"

VictoryRoad_3F_Text_TyraPostBattle::
    .string "Tyra: M'has ensenyat que el poder\n"
    .string "pot ser infinit en forma.$"

VictoryRoad_3F_Text_TyraNotEnoughMons::
    .string "Tyra: No pots combatre amb\n"
    .string "nosaltres si només tens un\l"
    .string "Pokémon.$"

VictoryRoad_3F_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE, 1
	release
	end

VictoryRoad_3F_EventScript_ItemTM50::
	finditem ITEM_TM50, 1
	release
	end

VictoryRoad_3F_EventScript_ItemPowerStone::
	finditem ITEM_POWER_STONE, 1
	release
	end

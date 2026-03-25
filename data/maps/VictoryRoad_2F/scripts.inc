VictoryRoad_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_2F_OnLoad
	.byte 0

VictoryRoad_2F_OnLoad::
	call_if_ne VAR_VICTORY_ROAD_2F_BOULDER1, 100, VictoryRoad_2F_EventScript_SetRockBarrier1
	call_if_ne VAR_VICTORY_ROAD_2F_BOULDER2, 100, VictoryRoad_2F_EventScript_SetRockBarrier2
	end

VictoryRoad_2F_EventScript_SetRockBarrier1::
	setmetatile 13, 10, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 13, 11, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_2F_EventScript_SetRockBarrier2::
	setmetatile 33, 16, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 33, 17, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_2F_EventScript_FloorSwitch1::
	lockall
	goto_if_eq VAR_VICTORY_ROAD_2F_BOULDER1, 100, VictoryRoad_2F_EventScript_FloorSwitch1AlreadyPressed
	setmetatile 13, 10, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 13, 11, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm 11
	setvar VAR_VICTORY_ROAD_2F_BOULDER1, 100
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch1AlreadyPressed::
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch2::
	lockall
	goto_if_eq VAR_VICTORY_ROAD_2F_BOULDER2, 100, VictoryRoad_2F_EventScript_FloorSwitch2AlreadyPressed
	setmetatile 33, 16, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 33, 17, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm 12
	setvar VAR_VICTORY_ROAD_2F_BOULDER2, 100
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch2AlreadyPressed::
	releaseall
	end

VictoryRoad_2F_EventScript_Dawson::
	trainerbattle_single TRAINER_POKEMANIAC_DAWSON, VictoryRoad_2F_Text_DawsonIntro, VictoryRoad_2F_Text_DawsonDefeat
	msgbox VictoryRoad_2F_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_Text_DawsonIntro::
    .string "Si passes per aquí, podràs\n"
    .string "enfrontar-te a l'Alt Comandament.$"

VictoryRoad_2F_Text_DawsonDefeat::
    .string "No!\n"
    .string "Increïble!$"

VictoryRoad_2F_Text_DawsonPostBattle::
    .string "Et puc guanyar quan es tracta\n"
    .string "de coneixements sobre Pokémon!$"

VictoryRoad_2F_EventScript_Daisuke::
	trainerbattle_single TRAINER_BLACK_BELT_DAISUKE, VictoryRoad_2F_Text_DaisukeIntro, VictoryRoad_2F_Text_DaisukeDefeat
	msgbox VictoryRoad_2F_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_Text_DaisukeIntro::
    .string "Això és el Camí de la Victòria.\n"
    .string "La prova final per als entrenadors!$"

VictoryRoad_2F_Text_DaisukeDefeat::
    .string "Atxó!$"

VictoryRoad_2F_Text_DaisukePostBattle::
    .string "Si t'encalles, prova de moure\n"
    .string "algunes roques.$"

VictoryRoad_2F_EventScript_Nelson::
	trainerbattle_single TRAINER_JUGGLER_NELSON, VictoryRoad_2F_Text_NelsonIntro, VictoryRoad_2F_Text_NelsonDefeat
	msgbox VictoryRoad_2F_Text_NelsonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_Text_NelsonIntro::
    .string "Ah, així que vols desafiar\n"
    .string "l'Alt Comandament?$"

VictoryRoad_2F_Text_NelsonDefeat::
    .string "M'has enxampat!$"

VictoryRoad_2F_Text_NelsonPostBattle::
    .string "{RIVAL} també va passar per aquí.$"

VictoryRoad_2F_EventScript_Gregory::
	trainerbattle_single TRAINER_JUGGLER_GREGORY, VictoryRoad_2F_Text_GregoryIntro, VictoryRoad_2F_Text_GregoryDefeat
	msgbox VictoryRoad_2F_Text_GregoryPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_Text_GregoryIntro::
    .string "El Camí de la Victòria és massa\n"
    .string "dur?$"

VictoryRoad_2F_Text_GregoryDefeat::
    .string "Ben fet!$"

VictoryRoad_2F_Text_GregoryPostBattle::
    .string "Molts entrenadors abandonen el\n"
    .string "seu desafiament aquí i tornen\l"
    .string "a casa.$"

VictoryRoad_2F_EventScript_Vincent::
	trainerbattle_single TRAINER_TAMER_VINCENT, VictoryRoad_2F_Text_VincentIntro, VictoryRoad_2F_Text_VincentDefeat
	msgbox VictoryRoad_2F_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_Text_VincentIntro::
    .string "Vine!\n"
    .string "Et donaré una pallissa!$"

VictoryRoad_2F_Text_VincentDefeat::
    .string "M'han derrotat!$"

VictoryRoad_2F_Text_VincentPostBattle::
    .string "T'has guanyat el dret de ser al\n"
    .string "Camí de la Victòria…$"

VictoryRoad_2F_EventScript_ItemTM37::
	finditem ITEM_TM37, 1
	release
	end

VictoryRoad_2F_EventScript_ItemGuardSpec::
	finditem ITEM_GUARD_SPEC, 1
	release
	end

VictoryRoad_2F_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL, 1
	release
	end

VictoryRoad_2F_EventScript_ItemTM07::
	finditem ITEM_TM07, 1
	release
	end

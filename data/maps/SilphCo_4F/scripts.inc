SilphCo_4F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_4F_OnLoad
	.byte 0

SilphCo_4F_OnLoad::
	call_if_unset FLAG_SILPH_4F_DOOR_1, EventScript_Close4FDoor1
	call_if_unset FLAG_SILPH_4F_DOOR_2, EventScript_Close4FDoor2
	end

SilphCo_4F_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE, 1
	release
	end

SilphCo_4F_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE, 1
	release
	end

SilphCo_4F_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL, 1
	release
	end

SilphCo_4F_EventScript_ItemTM41::
	finditem ITEM_TM41, 1
	release
	end

SilphCo_4F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_4F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_4F_Text_CantYouSeeImHiding
	release
	end

SilphCo_4F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_4F_Text_TeamRocketIsGone
	release
	end

SilphCo_4F_EventScript_FloorSign::
	msgbox SilphCo_4F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_4F_EventScript_Rodney::
	trainerbattle_single TRAINER_SCIENTIST_RODNEY, SilphCo_4F_Text_RodneyIntro, SilphCo_4F_Text_RodneyDefeat
	msgbox SilphCo_4F_Text_RodneyPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_26, SilphCo_4F_Text_Grunt1Intro, SilphCo_4F_Text_Grunt1Defeat
	msgbox SilphCo_4F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_27, SilphCo_4F_Text_Grunt2Intro, SilphCo_4F_Text_Grunt2Defeat
	msgbox SilphCo_4F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_Text_CantYouSeeImHiding::
    .string "Xxt!\n"
    .string "No veus que m'amago?$"

SilphCo_4F_Text_TeamRocketIsGone::
    .string "Eh?\n"
    .string "L'Equip Rocket se n'ha anat?$"

SilphCo_4F_Text_Grunt1Intro::
    .string "L'Equip Rocket ha pres el control\n"
    .string "de Silph S.A.!$"

SilphCo_4F_Text_Grunt1Defeat::
    .string "Arrgh!$"

SilphCo_4F_Text_Grunt1PostBattle::
    .string "Fwahahaha!\n"
    .string "El meu Cap anava darrere d'aquí!$"

SilphCo_4F_Text_RodneyIntro::
    .string "El meu Pokémon és el meu servent\n"
    .string "lleial.$"

SilphCo_4F_Text_RodneyDefeat::
    .string "Llamp!\n"
    .string "Pokémon feble!$"

SilphCo_4F_Text_RodneyPostBattle::
    .string "Les portes estan tancades\n"
    .string "electrònicament.\p"
    .string "Cal una Clau Targeta per obrir\n"
    .string "les portes d'aquí.$"

SilphCo_4F_Text_Grunt2Intro::
    .string "Intrús detectat!$"

SilphCo_4F_Text_Grunt2Defeat::
    .string "Qui ets?$"

SilphCo_4F_Text_Grunt2PostBattle::
    .string "Millor que avisi el Cap al pis 11!$"

SilphCo_4F_Text_FloorSign::
    .string "Seu Central de Silph S.A.\n"
    .string "4t pis$"

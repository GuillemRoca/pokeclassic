LavenderTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_OnTransition
	.byte 0

LavenderTown_OnTransition::
	setflag FLAG_VISITED_LAVENDER_TOWN
	end

LavenderTown_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox LavenderTown_Text_DoYouBelieveInGhosts, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LavenderTown_EventScript_LittleGirlBelieve
	msgbox LavenderTown_Text_JustImaginingWhiteHand
	release
	end

LavenderTown_Text_DoYouBelieveInGhosts::
    .string "Creus en els fantasmes?$"

LavenderTown_Text_JustImaginingWhiteHand::
    .string "Hahaha, ja veig que no.\p"
    .string "Aquella mà blanca a la teva\n"
    .string "espatlla… M'ho estic imaginant.$"


LavenderTown_EventScript_LittleGirlBelieve::
	msgbox LavenderTown_Text_SoThereAreBelievers
	release
	end

LavenderTown_Text_SoThereAreBelievers::
    .string "De veritat?\n"
    .string "Així que hi ha qui hi creu…$"

LavenderTown_EventScript_WorkerM::
	msgbox LavenderTown_Text_TownKnownAsMonGraveSite, MSGBOX_NPC
	end

LavenderTown_Text_TownKnownAsMonGraveSite::
    .string "Aquesta ciutat és coneguda com\n"
    .string "el cementiri dels Pokémon.\p"
    .string "Es fan serveis commemoratius\n"
    .string "a la Torre Pokémon.$"

LavenderTown_EventScript_Boy::
	msgbox LavenderTown_Text_GhostsAppearedInTower, MSGBOX_NPC
	end

LavenderTown_Text_GhostsAppearedInTower::
    .string "Han aparegut fantasmes a la\n"
    .string "Torre Pokémon.\p"
    .string "Crec que són els esperits dels\n"
    .string "Pokémon que els Rockets van matar.$"

LavenderTown_Text_TownSign::
    .string "Poble Lavanda\n"
    .string "El Noble Poble Porpra$"

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_TownSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_TrainerTips::
	msgbox LavenderTown_Text_TrainerTips, MSGBOX_SIGN
	end

LavenderTown_Text_TrainerTips::
    .string "Consells d'Entrenador!\n"
    .string "Mantén premut el Botó A per\n"
    .string "caminar en silenci amb el PokéNav!$"

LavenderTown_EventScript_VolunteerHouseSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouse, MSGBOX_SIGN
	end

LavenderTown_Text_VolunteerPokemonHouse::
    .string "Casa Voluntària\n"
    .string "Pokémon de Lavanda$"

LavenderTown_EventScript_PokemonTowerSign::
	msgbox LavenderTown_Text_PokemonTowerSign, MSGBOX_SIGN
	end

LavenderTown_Text_PokemonTowerSign::
    .string "Torre Pokémon\n"
    .string "Calma els Esperits dels Pokémon$"

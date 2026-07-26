SaffronCity_MrPsychicsHouse_MapScripts::
	.byte 0

SaffronCity_MrPsychicsHouse_EventScript_MrPsychic::
	lock
	faceplayer
	goto_if_set FLAG_REVEALED_MEGA_STONES, SaffronCity_MrPsychicsHouse_EventScript_GetAlakazite
	goto SaffronCity_MrPsychicsHouse_EventScript_GetPsychic
	end

SaffronCity_MrPsychicsHouse_EventScript_GetPsychic::
	goto_if_set FLAG_GOT_TM29_FROM_MR_PSYCHIC, SaffronCity_MrPsychicsHouse_EventScript_AlreadyGotTM29
	msgbox SaffronCity_MrPsychicsHouse_Text_YouWantedThis
	checkitemspace ITEM_TM29, 1
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_MrPsychicsHouse_EventScript_NoRoomForTM29
	giveitem ITEM_TM29, 1
	msgbox SaffronCity_MrPsychicsHouse_Text_ExplainTM29
	setflag FLAG_GOT_TM29_FROM_MR_PSYCHIC
	release
	end

SaffronCity_MrPsychicsHouse_EventScript_GetAlakazite::
	goto_if_set FLAG_HIDE_ALAKAZITE, SaffronCity_MrPsychicsHouse_EventScript_GetPsychic
	msgbox SaffronCity_MrPsychicsHouse_Text_YouWantedThis
	checkitemspace ITEM_ALAKAZITE, 1
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_MrPsychicsHouse_EventScript_NoRoomForTM29
	giveitem ITEM_ALAKAZITE, 1
	msgbox SaffronCity_MrPsychicsHouse_Text_ExplainAlakazite
	setflag FLAG_HIDE_ALAKAZITE
	release
	end

SaffronCity_MrPsychicsHouse_Text_ExplainAlakazite::
	.string "Ja ho saps, oi?\n"
    .string "Aquesta pedra és una Alakazita.\p"
    .string "Desbloqueja el potencial psíquic\n"
    .string "definitiu d'un Alakazam!$"

SaffronCity_MrPsychicsHouse_EventScript_NoRoomForTM29::
	msgbox SaffronCity_MrPsychicsHouse_Text_YouveNoRoom
	release
	end

SaffronCity_MrPsychicsHouse_EventScript_AlreadyGotTM29::
	msgbox SaffronCity_MrPsychicsHouse_Text_ExplainTM29
	release
	end

SaffronCity_MrPsychicsHouse_Text_YouWantedThis::
    .string "…Espera! No diguis res!\p"
    .string "Volies això!$"

SaffronCity_MrPsychicsHouse_Text_ExplainTM29::
    .string "Ja ho saps, oi?\n"
    .string "La MT29 és Psíquic.\p"
    .string "És un atac que també pot baixar\n"
    .string "les estadístiques especials.$"

SaffronCity_MrPsychicsHouse_Text_YouveNoRoom::
    .string "On penses posar-ho?\n"
    .string "No tens espai.$"

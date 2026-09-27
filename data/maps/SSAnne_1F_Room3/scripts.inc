SSAnne_1F_Room3_MapScripts::
	.byte 0

SSAnne_1F_Room3_EventScript_LittleGirl::
	msgbox SSAnne_1F_Room3_Text_AlwaysTravelWithJigglypuff, MSGBOX_NPC
	end

SSAnne_1F_Room3_Text_AlwaysTravelWithJigglypuff::
    .string "Sempre viatjo amb Jigglypuff.\n"
    .string "Mai marxo de casa sense ell.$"

SSAnne_1F_Room3_EventScript_BaldingMan::
	msgbox SSAnne_1F_Room3_Text_CruiseIsElegantAndCozy, MSGBOX_NPC
	end

SSAnne_1F_Room3_Text_CruiseIsElegantAndCozy::
    .string "Un creuer pel món és tan elegant\n"
    .string "i acollidor!$"

SSAnne_1F_Room3_EventScript_Jigglypuff::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_JIGGLYPUFF, CRY_MODE_NORMAL
	msgbox SSAnne_1F_Room3_Text_Jigglypuff
	waitmoncry
	release
	end

SSAnne_1F_Room3_Text_Jigglypuff::
    .string "Jigglypuff: Puup pupuu!$"

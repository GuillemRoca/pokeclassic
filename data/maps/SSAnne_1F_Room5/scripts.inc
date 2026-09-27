SSAnne_1F_Room5_MapScripts::
	.byte 0

SSAnne_1F_Room5_EventScript_Arthur::
	trainerbattle_single TRAINER_GENTLEMAN_ARTHUR, SSAnne_1F_Room5_Text_ArthurIntro, SSAnne_1F_Room5_Text_ArthurDefeat
	msgbox SSAnne_1F_Room5_Text_ArthurPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room5_Text_ArthurIntro::
    .string "Insolent cadell!\n"
    .string "Com goses entrar així!$"

SSAnne_1F_Room5_Text_ArthurDefeat::
    .string "Bah! Nen maleducat!\n"
    .string "No tens cap sentit de cortesia!$"

SSAnne_1F_Room5_Text_ArthurPostBattle::
    .string "Desitjo que em deixis sol!\n"
    .string "Fora!$"

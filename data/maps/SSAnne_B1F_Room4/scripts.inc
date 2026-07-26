SSAnne_B1F_Room4_MapScripts::
	.byte 0

SSAnne_B1F_Room4_EventScript_Leonard::
	trainerbattle_single TRAINER_SAILOR_LEONARD, SSAnne_B1F_Room4_Text_LeonardIntro, SSAnne_B1F_Room4_Text_LeonardDefeat
	msgbox SSAnne_B1F_Room4_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room4_Text_LeonardIntro::
    .string "Ja saps què diuen dels mariners\n"
    .string "i els combats!$"

SSAnne_B1F_Room4_Text_LeonardDefeat::
    .string "Bé!\n"
    .string "Bon combat, company!$"

SSAnne_B1F_Room4_Text_LeonardPostBattle::
    .string "Hahaha!\n"
    .string "Vols ser mariner, company?$"

SSAnne_B1F_Room4_EventScript_Duncan::
	trainerbattle_single TRAINER_SAILOR_DUNCAN, SSAnne_B1F_Room4_Text_DuncanIntro, SSAnne_B1F_Room4_Text_DuncanDefeat
	msgbox SSAnne_B1F_Room4_Text_DuncanPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room4_Text_DuncanIntro::
    .string "Vine, doncs!\n"
    .string "El meu orgull de mariner hi va!$"

SSAnne_B1F_Room4_Text_DuncanDefeat::
    .string "El teu esperit m'ha enfonsat!$"

SSAnne_B1F_Room4_Text_DuncanPostBattle::
    .string "Has vist el Guru de la Pesca a\n"
    .string "Ciutat Vermilion?$"

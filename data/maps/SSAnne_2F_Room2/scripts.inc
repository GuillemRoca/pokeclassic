SSAnne_2F_Room2_MapScripts::
	.byte 0

SSAnne_2F_Room2_EventScript_ItemStardust::
	finditem ITEM_STARDUST, 1
	release
	end

SSAnne_2F_Room2_EventScript_Dale::
	trainerbattle_single TRAINER_FISHERMAN_DALE, SSAnne_2F_Room2_Text_DaleIntro, SSAnne_2F_Room2_Text_DaleDefeat
	msgbox SSAnne_2F_Room2_Text_DalePostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room2_Text_DaleIntro::
    .string "Mira què he pescat!$"

SSAnne_2F_Room2_Text_DaleDefeat::
    .string "No me'n queden!$"

SSAnne_2F_Room2_Text_DalePostBattle::
    .string "Festa?\p"
    .string "La festa del creuer ja hauria\n"
    .string "d'haver acabat.$"

SSAnne_2F_Room2_EventScript_Brooks::
	trainerbattle_single TRAINER_GENTLEMAN_BROOKS, SSAnne_2F_Room2_Text_BrooksIntro, SSAnne_2F_Room2_Text_BrooksDefeat
	msgbox SSAnne_2F_Room2_Text_BrooksPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room2_Text_BrooksIntro::
    .string "Competir contra els joves em\n"
    .string "manté jove.$"

SSAnne_2F_Room2_Text_BrooksDefeat::
    .string "Bon combat!\n"
    .string "Ah, em sento jove de nou!$"

SSAnne_2F_Room2_Text_BrooksPostBattle::
    .string "Fa quinze anys, hauria\n"
    .string "guanyat!$"

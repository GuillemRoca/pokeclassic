SSAnne_B1F_Room3_MapScripts::
	.byte 0

SSAnne_B1F_Room3_EventScript_Dylan::
	trainerbattle_single TRAINER_SAILOR_DYLAN, SSAnne_B1F_Room3_Text_DylanIntro, SSAnne_B1F_Room3_Text_DylanDefeat
	msgbox SSAnne_B1F_Room3_Text_DylanPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room3_Text_DylanIntro::
    .string "M'agraden els nens valents\n"
    .string "com tu!$"

SSAnne_B1F_Room3_Text_DylanDefeat::
    .string "Argh!\n"
    .string "L'he perdut!$"

SSAnne_B1F_Room3_Text_DylanPostBattle::
    .string "Els Pokémon marins viuen a\n"
    .string "aigües profundes. Necessitaràs\l"
    .string "una canya per pescar-los!$"

SSAnne_B1F_Room3_EventScript_ItemEther::
	finditem ITEM_ETHER, 1
	release
	end

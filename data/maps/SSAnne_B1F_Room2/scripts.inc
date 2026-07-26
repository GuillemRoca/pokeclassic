SSAnne_B1F_Room2_MapScripts::
	.byte 0

SSAnne_B1F_Room2_EventScript_Huey::
	trainerbattle_single TRAINER_SAILOR_HUEY, SSAnne_B1F_Room2_Text_HueyIntro, SSAnne_B1F_Room2_Text_HueyDefeat
	msgbox SSAnne_B1F_Room2_Text_HueyPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room2_Text_HueyIntro::
    .string "Fins i tot els mariners tenim\n"
    .string "Pokémon!$"

SSAnne_B1F_Room2_Text_HueyDefeat::
    .string "D'acord, no estàs gens malament.$"

SSAnne_B1F_Room2_Text_HueyPostBattle::
    .string "Hem capturat tots els nostres\n"
    .string "Pokémon mentre érem a alta mar.$"

SSAnne_B1F_Room2_EventScript_ItemTM44::
	finditem ITEM_TM44, 1
	release
	end

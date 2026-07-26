SSAnne_1F_Room7_MapScripts::
	.byte 0


SSAnne_1F_Room7_EventScript_Thomas::
	trainerbattle_single TRAINER_GENTLEMAN_THOMAS, SSAnne_1F_Room7_Text_ThomasIntro, SSAnne_1F_Room7_Text_ThomasDefeat
	msgbox SSAnne_1F_Room7_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room7_Text_ThomasIntro::
    .string "No sóc més que un viatger\n"
    .string "solitari…\p"
    .string "Els meus únics companys i amics\n"
    .string "són Pokémon dels meus viatges…$"

SSAnne_1F_Room7_Text_ThomasDefeat::
    .string "Oh, els meus amics…$"

SSAnne_1F_Room7_Text_ThomasPostBattle::
    .string "Has de ser amable amb els amics!$"

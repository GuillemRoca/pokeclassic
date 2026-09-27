SSAnne_2F_Room4_MapScripts::
	.byte 0

SSAnne_2F_Room4_EventScript_Lamar::
	trainerbattle_single TRAINER_GENTLEMAN_LAMAR, SSAnne_2F_Room4_Text_LamarIntro, SSAnne_2F_Room4_Text_LamarDefeat
	msgbox SSAnne_2F_Room4_Text_LamarPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room4_Text_LamarIntro::
    .string "Què valores més, un Pokémon\n"
    .string "fort o un de rar?$"

SSAnne_2F_Room4_Text_LamarDefeat::
    .string "Et saludo!$"

SSAnne_2F_Room4_Text_LamarPostBattle::
    .string "Personalment, prefereixo Pokémon\n"
    .string "forts i rars.$"

SSAnne_2F_Room4_EventScript_Dawn::
	trainerbattle_single TRAINER_LADY_DAWN, SSAnne_2F_Room4_Text_DawnIntro, SSAnne_2F_Room4_Text_DawnDefeat
	msgbox SSAnne_2F_Room4_Text_DawnPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room4_Text_DawnIntro::
    .string "No crec que t'hagi vist a la\n"
    .string "festa?$"

SSAnne_2F_Room4_Text_DawnDefeat::
    .string "Ves amb calma!$"

SSAnne_2F_Room4_Text_DawnPostBattle::
    .string "Oh, m'encanten els teus Pokémon\n"
    .string "forts! Com t'envejo!$"

SSAnne_2F_Room4_EventScript_ItemXAttack::
	finditem ITEM_X_ATTACK, 1
	release
	end

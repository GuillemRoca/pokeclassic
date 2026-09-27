SSAnne_B1F_Room1_MapScripts::
	.byte 0

SSAnne_B1F_Room1_EventScript_Barny::
	trainerbattle_single TRAINER_FISHERMAN_BARNY, SSAnne_B1F_Room1_Text_BarnyIntro, SSAnne_B1F_Room1_Text_BarnyDefeat
	msgbox SSAnne_B1F_Room1_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room1_Text_BarnyIntro::
    .string "Hola, {MASC}foraster{FEM}forastera{ENDG}!\p"
    .string "No sé si ets de mar o de\n"
    .string "muntanya, però para i xerra.\p"
    .string "Tots els meus Pokémon són del mar.$"

SSAnne_B1F_Room1_Text_BarnyDefeat::
    .string "Llamp!\n"
    .string "Se m'ha escapat!$"

SSAnne_B1F_Room1_Text_BarnyPostBattle::
    .string "I jo que volia fer-te el meu\n"
    .string "ajudant!$"

SSAnne_B1F_Room1_EventScript_Phillip::
	trainerbattle_single TRAINER_SAILOR_PHILLIP, SSAnne_B1F_Room1_Text_PhillipIntro, SSAnne_B1F_Room1_Text_PhillipDefeat
	msgbox SSAnne_B1F_Room1_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room1_Text_PhillipIntro::
    .string "{MASC}Company{FEM}Companya{ENDG}, si perds, et llanço\n"
    .string "per la borda!$"

SSAnne_B1F_Room1_Text_PhillipDefeat::
    .string "Argh!\n"
    .string "Derrotat per {MASC}un nen{FEM}una nena{ENDG}!$"

SSAnne_B1F_Room1_Text_PhillipPostBattle::
    .string "Quan som a alta mar, de vegades\n"
    .string "passen Pokémon medusa.$"

SSAnne_B1F_Room1_MapScripts::
	.byte 0

SSAnne_B1F_Room1_EventScript_Barny::
	trainerbattle_single TRAINER_FISHERMAN_BARNY, SSAnne_B1F_Room1_Text_BarnyIntro, SSAnne_B1F_Room1_Text_BarnyDefeat
	msgbox SSAnne_B1F_Room1_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room1_Text_BarnyIntro::
    .string "Hola, foraster!\p"
    .string "No sé si ets de mar o de\n"
    .string "muntanya, però para i xerra.\p"
    .string "Tots els meus Pokémon són del mar.$"

SSAnne_B1F_Room1_Text_BarnyDefeat::
    .string "Llamp!\n"
    .string "Se m'ha escapat!$"

SSAnne_B1F_Room1_Text_BarnyPostBattle::
    .string "Anava a fer-te el meu\n"
    .string "ajudant, també!$"

SSAnne_B1F_Room1_EventScript_Phillip::
	trainerbattle_single TRAINER_SAILOR_PHILLIP, SSAnne_B1F_Room1_Text_PhillipIntro, SSAnne_B1F_Room1_Text_PhillipDefeat
	msgbox SSAnne_B1F_Room1_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room1_Text_PhillipIntro::
    .string "Mariner, caminaràs pel tauló\n"
    .string "si perds!$"

SSAnne_B1F_Room1_Text_PhillipDefeat::
    .string "Argh!\n"
    .string "Derrotat per un nen!$"

SSAnne_B1F_Room1_Text_PhillipPostBattle::
    .string "Quan som a alta mar, de vegades\n"
    .string "passen meduses Pokémon.$"

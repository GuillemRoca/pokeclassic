SSAnne_Deck_MapScripts::
	.byte 0

SSAnne_Deck_EventScript_Youngster::
	msgbox SSAnne_Deck_Text_ShipDepartingSoon, MSGBOX_NPC
	end

SSAnne_Deck_Text_ShipDepartingSoon::
    .string "La festa s'ha acabat.\n"
    .string "El vaixell zarparà aviat.$"

SSAnne_Deck_EventScript_BaldingMan::
	msgbox SSAnne_Deck_Text_FeelSeasick, MSGBOX_NPC
	end

SSAnne_Deck_Text_FeelSeasick::
    .string "Uff… Em trobo malament…\p"
    .string "M'he marejat, així que he sortit\n"
    .string "a prendre l'aire…$"

SSAnne_Deck_EventScript_Sailor::
	msgbox SSAnne_Deck_Text_ScrubbingDecksHardWork, MSGBOX_NPC
	end

SSAnne_Deck_Text_ScrubbingDecksHardWork::
    .string "Uf!\n"
    .string "Fregar la coberta és dur!$"

SSAnne_Deck_EventScript_Edmond::
	trainerbattle_single TRAINER_SAILOR_EDMOND, SSAnne_Deck_Text_EdmondIntro, SSAnne_Deck_Text_EdmondDefeat
	msgbox SSAnne_Deck_Text_EdmondPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_Deck_Text_EdmondIntro::
    .string "Ei, company!\p"
    .string "Fem un petit ball!$"

SSAnne_Deck_Text_EdmondDefeat::
    .string "Ets impressionant!$"

SSAnne_Deck_Text_EdmondPostBattle::
    .string "Quantes espècies de Pokémon creus\n"
    .string "que hi ha en aquest gran món?$"

SSAnne_Deck_EventScript_Trevor::
	trainerbattle_single TRAINER_SAILOR_TREVOR, SSAnne_Deck_Text_TrevorIntro, SSAnne_Deck_Text_TrevorDefeat
	msgbox SSAnne_Deck_Text_TrevorPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_Deck_Text_TrevorIntro::
    .string "Ep, aquí!\n"
    .string "Estàs marejat?$"

SSAnne_Deck_Text_TrevorDefeat::
    .string "He estat descuidat!$"

SSAnne_Deck_Text_TrevorPostBattle::
    .string "El meu pare diu que hi ha 100\n"
    .string "espècies de Pokémon. Jo crec\l"
    .string "que n'hi ha més.$"

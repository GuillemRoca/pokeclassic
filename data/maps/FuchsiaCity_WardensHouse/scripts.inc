FuchsiaCity_WardensHouse_MapScripts::
	.byte 0

FuchsiaCity_WardensHouse_EventScript_Warden::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM04, FuchsiaCity_WardensHouse_EventScript_ExplainStrength
	goto_if_set FLAG_HIDE_SAFARI_ZONE_WEST_GOLD_TEETH, FuchsiaCity_WardensHouse_EventScript_GiveGoldTeeth
	msgbox FuchsiaCity_WardensHouse_Text_HifFuffHefifoo, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, FuchsiaCity_WardensHouse_EventScript_WardenYes
	call_if_eq VAR_RESULT, NO, FuchsiaCity_WardensHouse_EventScript_WardenNo
	release
	end

FuchsiaCity_WardensHouse_Text_HifFuffHefifoo::
    .string "Guardià: Hif fuff hefifoo!\p"
    .string "Ha lof ha feef ee hafahi ho.\n"
    .string "Heff hee fwee!$"

FuchsiaCity_WardensHouse_EventScript_GiveGoldTeeth::
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message FuchsiaCity_WardensHouse_Text_GaveGoldTeethToWarden
	waitmessage
	waitfanfare
	msgbox FuchsiaCity_WardensHouse_Text_WardenPoppedInHisTeeth
	checkplayergender
	msgbox FuchsiaCity_WardensHouse_Text_ThanksGiveYouSomething
	playfanfare MUS_OBTAIN_TMHM
	message FuchsiaCity_WardensHouse_Text_ReceivedHM04FromWarden
	waitfanfare
	additem ITEM_HM04, 1
	setflag FLAG_RECEIVED_HM04
	removeitem ITEM_GOLD_TEETH, 1
	release
	end

FuchsiaCity_WardensHouse_Text_ThanksGiveYouSomething::
    .string "Guardià: Gràcies!\n"
    .string "M'has salvat la vida!\p"
    .string "Ningú no entenia ni una paraula\n"
    .string "del que deia, ni una!\p"
    .string "Em feia massa vergonya per\n"
    .string "ensenyar la cara per l'Oficina.\p"
    .string "Deixa'm donar-te alguna cosa\n"
    .string "per les molèsties.$"

FuchsiaCity_WardensHouse_EventScript_WardenYes::
	msgbox FuchsiaCity_WardensHouse_Text_AhHowheeHoHoo
	return

FuchsiaCity_WardensHouse_Text_AhHowheeHoHoo::
    .string "Ah howhee ho hoo!\n"
    .string "Eef ee hafahi ho!$"

FuchsiaCity_WardensHouse_EventScript_WardenNo::
	msgbox FuchsiaCity_WardensHouse_Text_HeOhayHeHaHoo
	return

FuchsiaCity_WardensHouse_Text_HeOhayHeHaHoo::
    .string "Ha?\n"
    .string "He ohay heh ha hoo ee haheh!$"

FuchsiaCity_WardensHouse_EventScript_ExplainStrength::
	msgbox FuchsiaCity_WardensHouse_Text_ExplainStrength
	release
	end

FuchsiaCity_WardensHouse_Text_ExplainStrength::
    .string "Guardià: Dins la MO04 trobaràs\n"
    .string "Força.\p"
    .string "Permet als Pokémon moure roques\n"
    .string "quan ets fora de combat.\p"
    .string "Ah sí, has trobat la Casa\n"
    .string "Secreta a la Zona Safari?$"

FuchsiaCity_WardensHouse_EventScript_DisplaySign1::
	msgbox FuchsiaCity_WardensHouse_Text_MonPhotosFossilsOnDisplay, MSGBOX_SIGN
	end

FuchsiaCity_WardensHouse_EventScript_DisplaySign2::
	msgbox FuchsiaCity_WardensHouse_Text_OldMonMerchandiseOnDisplay, MSGBOX_SIGN
	end

FuchsiaCity_WardensHouse_Text_GaveGoldTeethToWarden::
    .string "{PLAYER} ha donat les Dents\n"
    .string "d'Or al Guardià.$"

FuchsiaCity_WardensHouse_Text_WardenPoppedInHisTeeth::
    .string "El Guardià s'ha posat les dents!$"

FuchsiaCity_WardensHouse_Text_ReceivedHM04FromWarden::
    .string "{PLAYER} ha rebut la MO04\n"
    .string "del Guardià.$"

FuchsiaCity_WardensHouse_Text_MonPhotosFossilsOnDisplay::
    .string "Fotos de Pokémon i fòssils\n"
    .string "estan exposats.$"

FuchsiaCity_WardensHouse_Text_OldMonMerchandiseOnDisplay::
    .string "Merchandise antiga de Pokémon\n"
    .string "està exposada.$"

FuchsiaCity_WardensHouse_EventScript_PokemonJournalKoga::
	msgbox PokemonJournal_Text_SpecialFeatureKoga, MSGBOX_SIGN
	release
	end

PokemonJournal_Text_SpecialFeatureKoga::
	.string "Diari Pokémon:\p"
	.string "Reportatge: Líder del Gimnàs\n"
	.string "de Fuchsia, Koga!\p"
	.string "Es diu que Koga té un coneixement\n"
	.string "profund de la medicina.\p"
	.string "Fins i tot prepara medicines per\n"
	.string "curar els seus Pokémon.$"

FuchsiaCity_WardensHouse_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY, 1
	release
	end


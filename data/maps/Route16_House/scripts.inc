Route16_House_MapScripts::
	.byte 0

Route16_House_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM02, Route16_House_EventScript_AlreadyGotHM02
	msgbox Route16_House_Text_FoundMySecretRetreat
	checkitemspace ITEM_HM02, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Route16_House_EventScript_NoRoomForHM02
	playfanfare MUS_OBTAIN_TMHM
	message Route16_House_Text_ReceivedHM02FromGirl
	waitfanfare
	waitmessage
	closemessage
	additem ITEM_HM02, 1
	msgbox Route16_House_Text_ExplainHM02
	setflag FLAG_RECEIVED_HM02
	release
	end

Route16_House_EventScript_NoRoomForHM02::
	msgbox Route16_House_Text_DontHaveAnyRoomForThis
	release
	end

Route16_House_EventScript_AlreadyGotHM02::
	msgbox Route16_House_Text_ExplainHM02
	release
	end

Route16_House_EventScript_Pidgeot::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	msgbox Route16_House_Text_Pidgeot
	waitmoncry
	release
	end

Route16_House_Text_FoundMySecretRetreat::
    .string "Oh, vaja.\n"
    .string "Has trobat el meu refugi secret.\p"
    .string "Si us plau, no diguis a ningú\n"
    .string "que sóc aquí.\l"
    .string "T'ho compensaré amb això!$"

Route16_House_Text_ReceivedHM02FromGirl::
    .string "{PLAYER} ha rebut la MO02\n"
    .string "de la noia.$"

Route16_House_Text_ExplainHM02::
    .string "La MO02 és Volar.\n"
    .string "És un moviment increïblement\l"
    .string "pràctic.\p"
    .string "Si us plau, fes-ne bon ús.$"

Route16_House_Text_DontHaveAnyRoomForThis::
    .string "No tens lloc per a això.$"

Route16_House_Text_Pidgeot::
    .string "Pidgeot: Kyueen!$"

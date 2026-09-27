Route12_NorthEntrance_2F_MapScripts::
	.byte 0

Route12_NorthEntrance_2F_EventScript_LeftBinoculars::
	msgbox Route12_NorthEntrance_2F_Text_TheresManFishing, MSGBOX_SIGN
	end

Route12_NorthEntrance_2F_Text_TheresManFishing::
    .string "A veure què mostren els\n"
    .string "prismàtics…\p"
    .string "Hi ha un home pescant!$"

Route12_NorthEntrance_2F_EventScript_RightBinoculars::
	msgbox Route12_NorthEntrance_2F_Text_ItsPokemonTower, MSGBOX_SIGN
	end

Route12_NorthEntrance_2F_Text_ItsPokemonTower::
    .string "A veure què mostren els\n"
    .string "prismàtics…\p"
    .string "És la Torre Pokémon!$"

Route12_NorthEntrance_2F_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM27, Route12_NorthEntrance_2F_EventScript_ExplainTM27
	msgbox Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymore
	checkitemspace ITEM_TM27, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Route12_NorthEntrance_2F_EventScript_NoRoomForTM27
	playfanfare MUS_OBTAIN_TMHM
	message Route12_NorthEntrance_2F_Text_ReceivedTM27
	waitfanfare
	waitmessage
	additem ITEM_TM27, 1
	msgbox Route12_NorthEntrance_2F_Text_ExplainTM27
	setflag FLAG_GOT_TM27
	release
	end

Route12_NorthEntrance_2F_Text_ReceivedTM27::
    .string "{PLAYER} ha rebut la MT27\n"
    .string "de la noia en dol.$"

Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymore::
    .string "Les cendres del meu Pokémon són\n"
    .string "a la Torre Pokémon.\p"
    .string "Pots quedar-te aquesta MT.\n"
    .string "Ja no la necessito…$"

Route12_NorthEntrance_2F_EventScript_ExplainTM27::
    msgbox Route12_NorthEntrance_2F_Text_ExplainTM27
    release
    end

Route12_NorthEntrance_2F_Text_ExplainTM27::
    .string "La MT27 és un moviment anomenat\n"
    .string "Retorn…\p"
    .string "Si tractes bé els teus Pokémon,\n"
    .string "et retornaran l'amor lluitant\l"
    .string "amb totes les forces.$"

Route12_NorthEntrance_2F_EventScript_NoRoomForTM27::
    msgbox Route12_NorthEntrance_2F_Text_DontHaveRoomForThis
    release
    end

Route12_NorthEntrance_2F_Text_DontHaveRoomForThis::
    .string "No tens lloc per a això.$"

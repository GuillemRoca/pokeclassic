Route15_WestEntrance_2F_MapScripts::
	.byte 0

Route15_WestEntrance_2F_EventScript_LeftBinoculars::
	lockall
	goto_if_set FLAG_CAUGHT_ARTICUNO, Route15_WestEntrance_2F_EventScript_RightBinoculars
	msgbox Route15_WestEntrance_2F_Text_LargeShiningBird
	showmonpic SPECIES_ARTICUNO, 10, 3
	delay 20
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_ARTICUNO
	special SetSeenMon
	releaseall
	end

Route15_WestEntrance_2F_EventScript_RightBinoculars::
	msgbox Route15_WestEntrance_2F_Text_SmallIslandOnHorizon, MSGBOX_SIGN
	end

Route15_WestEntrance_2F_Text_LargeShiningBird::
    .string "A veure què mostren els\n"
    .string "prismàtics…\p"
    .string "Un gran ocell brillant vola\n"
    .string "cap al mar.$"

Route15_WestEntrance_2F_Text_SmallIslandOnHorizon::
    .string "A veure què mostren els\n"
    .string "prismàtics…\p"
    .string "Sembla una petita illa a\n"
    .string "l'horitzó!$"

@Aide Gift 5
Route15_WestEntrance_2F_EventScript_Aide::
    lock
    faceplayer
    goto_if_set FLAG_RECEIVED_EXP_SHARE, Route15_WestEntrance_2F_EventScript_AlreadyGotReward
    msgbox Route15_WestEntrance_2F_Text_GiveReward, MSGBOX_DEFAULT
    checkitemspace ITEM_EXP_SHARE, 1
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
    giveitem ITEM_EXP_SHARE, 1
    waitmessage
    setflag FLAG_RECEIVED_EXP_SHARE
    setflag FLAG_HIDE_AIDE_ROUTE15
    clearflag FLAG_AIDE_LOCATION_5
    clearflag FLAG_QUEUE_AIDE_CALL
    setvar VAR_AIDE_CALL_STEP_COUNTER, 0
    msgbox Route15_WestEntrance_2F_Text_ExplainReward, MSGBOX_DEFAULT
    clearflag FLAG_HIDE_AIDE_OAK_LAB
    release
    end

Route15_WestEntrance_2F_Text_GiveReward::
    .string "{PLAYER}!\p"
    .string "Vas llançat.\p"
    .string "A mesura que avanci el viatge,\n"
    .string "criar Pokémon pot ser més difícil,\l"
    .string "sobretot si canvies d'equip!\p"
    .string "Així que hem creat un dispositiu\n"
    .string "que pot facilitar la cria.$"

Route15_WestEntrance_2F_EventScript_AlreadyGotReward::
    msgbox Route15_WestEntrance_2F_Text_ExplainReward, MSGBOX_DEFAULT
    release
    end

Route15_WestEntrance_2F_Text_ExplainReward::
    .string "Pots activar el Rep. Exp. a la\n"
    .string "bossa d'Objectes Clau.\p"
    .string "Reparteix punts d'EXP. als\n"
    .string "Pokémon del teu equip, encara\l"
    .string "que no hagin participat en\l"
    .string "el combat.\p"
    .string "El pots desactivar quan vulguis!$"

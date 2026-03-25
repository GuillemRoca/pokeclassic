Route16_NorthEntrance_2F_MapScripts::
	.byte 0

Route16_NorthEntrance_2F_EventScript_LittleBoy::
	msgbox Route16_NorthEntrance_2F_Text_OnBikeRideWithGirlfriend, MSGBOX_NPC
	end

Route16_NorthEntrance_2F_Text_OnBikeRideWithGirlfriend::
    .string "Faig un passeig relaxat amb la\n"
    .string "meva bici nova amb la meva nòvia.$"

Route16_NorthEntrance_2F_EventScript_LittleGirl::
	msgbox Route16_NorthEntrance_2F_Text_RidingTogetherOnNewBikes, MSGBOX_NPC
	end

Route16_NorthEntrance_2F_Text_RidingTogetherOnNewBikes::
    .string "Anem a passejar junts amb les\n"
    .string "nostres bicis noves.$"

Route16_NorthEntrance_2F_EventScript_LeftBinoculars::
	msgbox Route16_NorthEntrance_2F_Text_ItsCeladonDeptStore, MSGBOX_SIGN
	end

Route16_NorthEntrance_2F_Text_ItsCeladonDeptStore::
    .string "A veure què mostren els\n"
    .string "prismàtics…\p"
    .string "Són els Grans Magatzems\n"
    .string "de Celadon!$"

Route16_NorthEntrance_2F_EventScript_RightBinoculars::
	msgbox Route16_NorthEntrance_2F_Text_LongPathOverWater, MSGBOX_SIGN
	end

Route16_NorthEntrance_2F_Text_LongPathOverWater::
    .string "A veure què mostren els\n"
    .string "prismàtics…\p"
    .string "Hi ha un camí llarg sobre l'aigua\n"
    .string "molt lluny.$"


@Aide Gift 4
Route16_NorthEntrance_2F_EventScript_Aide::
    lock
    faceplayer
    goto_if_set FLAG_RECEIVED_AIDE_AMULET_COIN, Route16_NorthEntrance_2F_EventScript_AlreadyGotReward
    msgbox Route16_NorthEntrance_2F_Text_GiveReward, MSGBOX_DEFAULT
    checkitemspace ITEM_AMULET_COIN, 1
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
    giveitem ITEM_AMULET_COIN, 1
    waitmessage
    setflag FLAG_RECEIVED_AIDE_AMULET_COIN
    setflag FLAG_HIDE_AIDE_ROUTE16
    clearflag FLAG_AIDE_LOCATION_4
    clearflag FLAG_QUEUE_AIDE_CALL
    setvar VAR_AIDE_CALL_STEP_COUNTER, 0
    msgbox Route16_NorthEntrance_2F_Text_ExplainReward, MSGBOX_DEFAULT
    call_if_set FLAG_BADGE06_GET, Route16_NorthEntrance_2F_EventScript_AideNextLocation
    release
    end

Route16_NorthEntrance_2F_Text_GiveReward::
    .string "Oh… {PLAYER}!\p"
    .string "M'alegro que m'hagis pogut\n"
    .string "trobar!\p"
    .string "Entre el Snorlax adormit i\n"
    .string "els Motoristes que fan por, no\l"
    .string "sabia si ens trobaríem!\p"
    .string "La vida d'Entrenador deu ser\n"
    .string "dura, espero que això t'ajudi\l"
    .string "una mica.$"

Route16_NorthEntrance_2F_EventScript_AlreadyGotReward::
    msgbox Route16_NorthEntrance_2F_Text_ExplainReward, MSGBOX_DEFAULT
    release
    end

Route16_NorthEntrance_2F_Text_ExplainReward::
	.string "Sabies que els Pokémon poden\n"
	.string "portar objectes?\p"
    .string "La Moneda Amuleto és un objecte\n"
    .string "per portar un Pokémon.\p"
    .string "Si el Pokémon surt en un combat\n"
    .string "guanyat, guanyaràs més diners.$"

Route16_NorthEntrance_2F_EventScript_AideNextLocation::
    setflag FLAG_QUEUE_AIDE_CALL
    setflag FLAG_AIDE_LOCATION_5
    return

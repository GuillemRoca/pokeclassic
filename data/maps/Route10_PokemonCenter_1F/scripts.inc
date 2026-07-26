.set LOCALID_NURSE, 1

Route10_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_PokemonCenter_1F_OnTransition
	.byte 0

Route10_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_ROUTE_10
	end

Route10_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

Route10_PokemonCenter_1F_EventScript_FatMan::
	msgbox Route10_PokemonCenter_1F_Text_NuggetUselessSoldFor5000, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_Text_NuggetUselessSoldFor5000::
    .string "Una pepita no serveix per a res.\n"
    .string "Així que l'he venuda per ¥5000.$"

Route10_PokemonCenter_1F_EventScript_Gentleman::
	msgbox Route10_PokemonCenter_1F_Text_EveryTypeStrongerThanOthers, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_Text_EveryTypeStrongerThanOthers::
    .string "Els tipus de Pokémon interactuen\n"
    .string "de manera diferent entre ells.\p"
    .string "Cada tipus és més fort contra\n"
    .string "alguns i més feble contra altres.$"

Route10_PokemonCenter_1F_EventScript_Youngster::
	msgbox Route10_PokemonCenter_1F_Text_HeardGhostsHauntLavender, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_Text_HeardGhostsHauntLavender::
    .string "He sentit que hi ha fantasmes\n"
    .string "a Poble Lavanda.$"

@Aide Gift 2
Route10_PokemonCenter_1F_EventScript_Aide::
    lock
    faceplayer
    goto_if_set FLAG_RECEIVED_AIDE_EVERSTONE, Route10_PokemonCenter_1F_EventScript_AlreadyGotReward
    msgbox Route10_PokemonCenter_1F_Text_GiveReward, MSGBOX_DEFAULT
    checkitemspace ITEM_EVERSTONE, 1
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
    giveitem ITEM_EVERSTONE, 1
    waitmessage
    setflag FLAG_RECEIVED_AIDE_EVERSTONE
    setflag FLAG_HIDE_AIDE_ROUTE10
    clearflag FLAG_AIDE_LOCATION_2
    clearflag FLAG_QUEUE_AIDE_CALL
    setvar VAR_AIDE_CALL_STEP_COUNTER, 0
    msgbox Route10_PokemonCenter_1F_Text_ExplainReward, MSGBOX_DEFAULT
    call_if_set FLAG_BADGE04_GET, Route10_PokemonCenter_1F_EventScript_AideNextLocation
    release
    end

Route10_PokemonCenter_1F_Text_GiveReward::
    .string "Oh… {PLAYER}!\n"
    .string "T'estava buscant!\p"
    .string "Sóc jo, Cedar, l'ajudant\n"
    .string "sempre present del Prof. Oak.\p"
    .string "Com va la teva Pokédex?\p"
    .string "Truca al Prof. Oak algun dia\n"
    .string "per revisar el teu progrés!\p"
    .string "En fi, m'ha confiat aquesta\n"
    .string "Pedra Eterna.\p"
    .string "Doncs, {PLAYER}, aquí la tens!$"

Route10_PokemonCenter_1F_EventScript_AlreadyGotReward::
    msgbox Route10_PokemonCenter_1F_Text_ExplainReward, MSGBOX_DEFAULT
    release
    end

Route10_PokemonCenter_1F_Text_ExplainReward::
    .string "Fer evolucionar Pokémon pot\n"
    .string "ajudar a completar la Pokédex.\p"
    .string "Però a vegades no voldràs que\n"
    .string "un Pokémon evolucioni.\p"
    .string "En aquest cas, dóna la Pedra\n"
    .string "Eterna a aquell Pokémon.\p"
    .string "Evitarà l'evolució, segons\n"
    .string "el Professor.$"

Route10_PokemonCenter_1F_EventScript_AideNextLocation::
    setflag FLAG_QUEUE_AIDE_CALL
    setflag FLAG_AIDE_LOCATION_3
    return

.set LOCALID_EXPERT, 1
.set LOCALID_LASS, 2
.set LOCALID_YOUNGSTER, 3
.set LOCALID_DAISY, 4

.set NUM_OPPONENTS, VAR_0x8009

FuchsiaCity_House3_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, BerryHouse_OnTransition
	.byte 0

BerryHouse_OnTransition::
    call_if_unset FLAG_DAILY_BERRY_BLEND_OPPONENTS, BerryHouse_SetTodaysOpponents
    call BerryHouse_SetPositions
    end

BerryHouse_SetTodaysOpponents::
    setflag FLAG_DAILY_BERRY_BLEND_OPPONENTS
    random 3
    addvar VAR_RESULT, 1
    copyvar VAR_BERRY_HOUSE_VISITORS, VAR_RESULT
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 1, BerryHouse_CheckForDaisy
    return


BerryHouse_CheckForDaisy::
    random 10
    goto_if_ne VAR_RESULT, 9, Common_EventScript_Return
    setvar VAR_BERRY_HOUSE_VISITORS, 4
    return


BerryHouse_SetPositions::
    call_if_eq VAR_BERRY_HOUSE_VISITORS, 4, BerryHouse_DaisyVisiting
    call_if_eq VAR_BERRY_HOUSE_VISITORS, 3, BerryHouse_LassAndYoungsterVisiting
    call_if_eq VAR_BERRY_HOUSE_VISITORS, 2, BerryHouse_LassVisiting
    call_if_eq VAR_BERRY_HOUSE_VISITORS, 1, BerryHouse_NoOneVisiting
    return

BerryHouse_DaisyVisiting::
    clearflag FLAG_HIDE_BERRY_HOUSE_DAISY
    addobject LOCALID_DAISY
    setobjectxyperm LOCALID_EXPERT, 4, 5
    removeobject LOCALID_LASS
    setflag FLAG_HIDE_BERRY_HOUSE_LASS
    removeobject LOCALID_YOUNGSTER
    setflag FLAG_HIDE_BERRY_HOUSE_YOUNGSTER
    return

BerryHouse_LassAndYoungsterVisiting::
    clearflag FLAG_HIDE_BERRY_HOUSE_YOUNGSTER
    addobject LOCALID_YOUNGSTER
    clearflag FLAG_HIDE_BERRY_HOUSE_LASS
    addobject LOCALID_LASS
    removeobject LOCALID_DAISY
    setflag FLAG_HIDE_BERRY_HOUSE_DAISY
    return

BerryHouse_LassVisiting::
    clearflag FLAG_HIDE_BERRY_HOUSE_LASS
    addobject LOCALID_LASS
    removeobject LOCALID_YOUNGSTER
    setflag FLAG_HIDE_BERRY_HOUSE_YOUNGSTER
    removeobject LOCALID_DAISY
    setflag FLAG_HIDE_BERRY_HOUSE_DAISY
    return

BerryHouse_NoOneVisiting::
    removeobject LOCALID_DAISY
    setflag FLAG_HIDE_BERRY_HOUSE_DAISY
    removeobject LOCALID_LASS
    setflag FLAG_HIDE_BERRY_HOUSE_LASS
    removeobject LOCALID_YOUNGSTER
    setflag FLAG_HIDE_BERRY_HOUSE_YOUNGSTER
    return

FuchsiaCity_House3_EventScript_Grandfather::
    lock
    faceplayer
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 4, FuchsiaCity_House3_EventScript_DaisyVisits
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 3, FuchsiaCity_House3_EventScript_WholeFamily
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 2, FuchsiaCity_House3_EventScript_OldestGrandhchild
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 1, FuchsiaCity_House3_EventScript_NoVisitors
    end

FuchsiaCity_House3_EventScript_DaisyVisits::
    msgbox FuchsiaCity_House3_Text_DaisyVisits, MSGBOX_NPC
    call BerryHouse_EventScript_GetDailyBerry
    release
    end

FuchsiaCity_House3_Text_DaisyVisits:
    .string "Oh, tu també coneixes la Daisy?\p"
    .string "Ens visita de tant en tant.\n"
    .string "És molt amable amb nosaltres.\p"
    .string "La meva dona li va ensenyar tot\n"
    .string "el que sap sobre Mescla de Baies!\p"
    .string "Potser fins i tot és millor\n"
    .string "que ella!\p"
    .string "Però no li diguis que ho he dit!$"

FuchsiaCity_House3_EventScript_WholeFamily::
    msgbox FuchsiaCity_House3_Text_WarmsMyHeart, MSGBOX_NPC
    call BerryHouse_EventScript_GetDailyBerry
    release
    end

FuchsiaCity_House3_Text_WarmsMyHeart:
    .string "M'escalfa el cor veure tota\n"
    .string "la família junta!$"

FuchsiaCity_House3_EventScript_OldestGrandhchild::
    msgbox FuchsiaCity_House3_Text_OldestGrandhchild, MSGBOX_NPC
    call BerryHouse_EventScript_GetDailyBerry
    release
    end

FuchsiaCity_House3_Text_OldestGrandhchild:
    .string "La meva néta gran ens visita\n"
    .string "avui!\p"
    .string "És entrenadora com tu!$"

FuchsiaCity_House3_EventScript_NoVisitors::
    msgbox FuchsiaCity_House3_Text_NoVisitors, MSGBOX_NPC
    call BerryHouse_EventScript_GetDailyBerry
    release
    end

FuchsiaCity_House3_Text_NoVisitors:
    .string "Fer-se gran pot ser difícil.\p"
    .string "Sobretot en dies com avui, quan\n"
    .string "no rebem cap visita...\p"
    .string "Però llavors has vingut tu, i ens\n"
    .string "has alegrat el dia!$"

FuchsiaCity_House3_EventScript_BerryBlenderSpeedRecords::
    lockall
    special ShowBerryBlenderRecordWindow
    waitbuttonpress
    special RemoveRecordsWindow
    releaseall
    end

FuchsiaCity_House3_EventScript_Picture::
    msgbox FuchsiaCity_House3_Text_Picture, MSGBOX_SIGN
    release
    end

FuchsiaCity_House3_Text_Picture::
    .string "És una foto de la parella gran\n"
    .string "quan eren joves...\p"
    .string "Hi ha un gran bosc de Baies!$"

FuchsiaCity_House3_EventScript_Lass::
    msgbox FuchsiaCity_House3_Text_Lass, MSGBOX_NPC
    turnobject LOCALID_LASS, DIR_EAST
    release
    end

FuchsiaCity_House3_Text_Lass:
    .string "Intento millorar als Concursos,\n"
    .string "així que estic aprenent a Mesclar\l"
    .string "Baies amb la meva àvia!$"

FuchsiaCity_House3_EventScript_Youngster::
    msgbox FuchsiaCity_House3_Text_Youngster, MSGBOX_NPC
    turnobject LOCALID_YOUNGSTER, DIR_WEST
    release
    end

FuchsiaCity_House3_Text_Youngster:
    .string "Preferiria estar lluitant.\n"
    .string "La meva germana diu que és bonic\l"
    .string "visitar l'àvia i l'avi.\p"
    .string "Almenys la Mescla de Baies és\n"
    .string "una mica divertida.$"

FuchsiaCity_House3_EventScript_Daisy::
    msgbox FuchsiaCity_House3_Text_Daisy, MSGBOX_NPC
    turnobject LOCALID_DAISY, DIR_SOUTH
    release
    end

FuchsiaCity_House3_Text_Daisy:
    .string "Oh! Hola, {PLAYER}!\p"
    .string "No sabia que coneixies els\n"
    .string "mestres de les Baies!\p"
    .string "Els vaig conèixer quan viatjava\n"
    .string "als Concursos.\p"
    .string "Em van ensenyar tot el que sé\n"
    .string "sobre la Mescla de Baies.\p"
    .string "Encara intento visitar-los.\n"
    .string "I no fa mal practicar!$"

FuchsiaCity_House3_EventScript_Expert::
    msgbox FuchsiaCity_House3_Text_Expert, MSGBOX_NPC
    turnobject LOCALID_EXPERT, DIR_SOUTH
    release
    end

FuchsiaCity_House3_Text_Expert:
    .string "El meu marit i jo ens vam mudar\n"
    .string "a Kanto fa molt de temps, però\l"
    .string "ningú sabia de la Mescla...\p"
    .string "Era bastant popular a casa nostra,\n"
    .string "així que intentem mantenir la\l"
    .string "tradició.\p"
    .string "Sempre que algú ens visita,\n"
    .string "Mesclem Baies junts!$"


BerryHouse_EventScript_BerryBlender::
    lockall
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 4 BerryHouse_EventScript_VsDaisy
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 3 BerryHouse_EventScript_ThreeOpponents
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 2 BerryHouse_EventScript_TwoOpponents
    setvar NUM_OPPONENTS, 1
    applymovement LOCALID_EXPERT, Common_Movement_WalkInPlaceFasterDown
    waitmovement 1
    msgbox BerryHouse_Text_WantToMakePokeblocks, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, BerryHouse_EventScript_TryUseBerryBlender
    goto BerryHouse_EventScript_DeclineBlender
    end

BerryHouse_EventScript_TwoOpponents::
    setvar NUM_OPPONENTS, 2
    applymovement LOCALID_EXPERT, Common_Movement_WalkInPlaceFasterDown
    applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFasterRight
    waitmovement 1
    msgbox BerryHouse_Text_WantToMakePokeblocks, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, BerryHouse_EventScript_TryUseBerryBlender
    goto BerryHouse_EventScript_DeclineBlender
    end

BerryHouse_EventScript_ThreeOpponents::
    setvar NUM_OPPONENTS, 3
    applymovement LOCALID_EXPERT, Common_Movement_WalkInPlaceFasterDown
    applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFasterRight
    applymovement LOCALID_YOUNGSTER, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 1
    msgbox BerryHouse_Text_WantToMakePokeblocks, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, BerryHouse_EventScript_TryUseBerryBlender
    goto BerryHouse_EventScript_DeclineBlender
    end

BerryHouse_EventScript_VsDaisy::
    setvar NUM_OPPONENTS, 1
    applymovement LOCALID_DAISY, Common_Movement_WalkInPlaceFasterDown
    waitmovement 1
    msgbox BerryHouse_Text_WantToMakePokeblocksDaisy, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, BerryHouse_EventScript_TryUseBerryBlenderDaisy
    goto BerryHouse_EventScript_DeclineBlender
    end

BerryHouse_Text_WantToMakePokeblocks:
    .string "Oh? Vols fer {POKEBLOCK}S?$"

BerryHouse_Text_WantToMakePokeblocksDaisy:
    .string "Oh? Vols fer {POKEBLOCK}S\n"
    .string "amb mi, {PLAYER}?$"

BerryHouse_EventScript_DeclineBlender:
    msgbox BerryHouse_Text_MadeOldTimerSad, MSGBOX_DEFAULT
    releaseall
    end

BerryHouse_Text_MadeOldTimerSad:
    .string "Oh…\n"
    .string "Potser un altre dia…$"

BerryHouse_EventScript_TryUseBerryBlender:
    checkitem ITEM_POKEBLOCK_CASE
    goto_if_eq VAR_RESULT, FALSE, BerryHouse_EventScript_BlenderNoCase
    specialvar VAR_RESULT, GetFirstFreePokeblockSlot
    goto_if_eq VAR_RESULT, 65535, BerryHouse_EventScript_BlenderCaseFull
    specialvar VAR_RESULT, PlayerHasBerries
    goto_if_eq VAR_RESULT, FALSE, BerryHouse_EventScript_BlenderNoBerries
    msgbox BerryHouse_Text_Excellent, MSGBOX_DEFAULT
    goto BerryHouse_EventScript_UseBerryBlender
    end

BerryHouse_Text_Excellent:
    .string "Excel·lent!$"

BerryHouse_EventScript_TryUseBerryBlenderDaisy:
    checkitem ITEM_POKEBLOCK_CASE
    goto_if_eq VAR_RESULT, FALSE, BerryHouse_EventScript_BlenderNoCaseDaisy
    specialvar VAR_RESULT, GetFirstFreePokeblockSlot
    goto_if_eq VAR_RESULT, 65535, BerryHouse_EventScript_BlenderCaseFull
    specialvar VAR_RESULT, PlayerHasBerries
    goto_if_eq VAR_RESULT, FALSE, BerryHouse_EventScript_BlenderNoBerriesDaisy
    msgbox BerryHouse_Text_Excellent, MSGBOX_DEFAULT
    goto BerryHouse_EventScript_UseBerryBlender
    end

BerryHouse_EventScript_BlenderNoCase:
    msgbox BerryHouse_Text_DontHavePokeblockCase, MSGBOX_DEFAULT
    releaseall
    end

BerryHouse_Text_DontHavePokeblockCase:
    .string "Però no tens un Estoig {POKEBLOCK}.\p"
    .string "Hauries d'aconseguir-ne un primer.$"

BerryHouse_EventScript_BlenderNoCaseDaisy:
    msgbox BerryHouse_Text_DontHavePokeblockCaseDaisy, MSGBOX_DEFAULT
    releaseall
    end

BerryHouse_Text_DontHavePokeblockCaseDaisy:
    .string "Oh? No tens un Estoig {POKEBLOCK}?\p"
    .string "{RIVAL} no te'n va donar un?$"

BerryHouse_EventScript_BlenderCaseFull:
    msgbox BerryHouse_Text_PokeblockCaseIsFull, MSGBOX_DEFAULT
    releaseall
    end

BerryHouse_Text_PokeblockCaseIsFull:
    .string "El teu Estoig {POKEBLOCK} està\n"
    .string "ple, pel que sembla.\p"
    .string "Hauries de gastar uns quants\n"
    .string "{POKEBLOCK}S i tornar.$"

BerryHouse_EventScript_BlenderNoBerries:
    msgbox BerryHouse_Text_DontHaveAnyBerries, MSGBOX_DEFAULT
    call_if_unset FLAG_DAILY_BERRY_HOUSE_RECEIVED_BERRY, BerryHouse_EventScript_HusbandGiveYouBerry
    releaseall
    end

BerryHouse_Text_DontHaveAnyBerries:
    .string "No tens cap Baia,\n"
    .string "oi?\p"
    .string "Si no tens Baies,\n"
    .string "no pots fer {POKEBLOCK}S.\p"
    .string "Sempre estarem fent {POKEBLOCK}S aquí,\n"
    .string "així que fem-ne junts quan\l"
    .string "tinguis una Baia o dues.$"

BerryHouse_EventScript_HusbandGiveYouBerry::
    msgbox BerryHouse_Text_HusbandGiveYouBerry, MSGBOX_DEFAULT
    return

BerryHouse_Text_HusbandGiveYouBerry:
    .string "Si ho demanes bé, el meu marit\n"
    .string "potser té una Baia de sobres.$"

BerryHouse_EventScript_BlenderNoBerriesDaisy:
    msgbox BerryHouse_Text_DontHaveAnyBerriesDaisy, MSGBOX_DEFAULT
    call_if_unset FLAG_DAILY_BERRY_HOUSE_RECEIVED_BERRY, BerryHouse_EventScript_OldManGiveYouBerry
    releaseall
    end

BerryHouse_Text_DontHaveAnyBerriesDaisy:
    .string "Oh! No tens cap Baia?\n"
    .string "Si no tens Baies,\n"
    .string "no pots fer {POKEBLOCK}S.$"

BerryHouse_EventScript_OldManGiveYouBerry::
    msgbox BerryHouse_Text_OldManGiveYouBerry, MSGBOX_DEFAULT
    return

BerryHouse_Text_OldManGiveYouBerry:
    .string "Saps, si ho demanes bé, l'avi\n"
    .string "potser té una Baia de sobres.$"

BerryHouse_EventScript_GetDailyBerry::
    specialvar VAR_RESULT, PlayerHasBerries
    goto_if_eq VAR_RESULT, TRUE, Common_EventScript_Return
    dotimebasedevents
    goto_if_set FLAG_DAILY_BERRY_HOUSE_RECEIVED_BERRY, BerryHouse_EventScript_BlenderNoSpareBerries
    goto BerryHouse_EventScript_GiveSpareBerry
    end

BerryHouse_EventScript_BlenderNoSpareBerries::
    msgbox BerryHouse_Text_DontHaveAnyBerriesToSpare, MSGBOX_DEFAULT
    releaseall
    end

BerryHouse_Text_DontHaveAnyBerriesToSpare:
    .string "Si em quedessin Baies de sobres,\n"
    .string "te'n donaria una de gust…\p"
    .string "Però avui no en tinc cap.\n"
    .string "Haurem de fer-ho un altre dia.$"

BerryHouse_EventScript_GiveSpareBerry:
    msgbox BerryHouse_Text_DontHaveAnyBerriesHaveOne, MSGBOX_DEFAULT
    giveitem ITEM_PECHA_BERRY
    setflag FLAG_DAILY_BERRY_HOUSE_RECEIVED_BERRY
    releaseall
    end

BerryHouse_Text_DontHaveAnyBerriesHaveOne:
    .string "Oh?\n"
    .string "No tens cap Baia?\p"
    .string "Això no pot ser, oi?\p"
    .string "Si no et fa res que siguin sobres,\n"
    .string "pots quedar-te una de les meves.$"


BerryHouse_EventScript_UseBerryBlender:
    msgbox BerryHouse_Text_KnowHowToMakePokeblocks, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, BerryHouse_EventScript_StartBlender
    goto BerryHouse_EventScript_ExplainBlending
    end

BerryHouse_Text_KnowHowToMakePokeblocks:
    .string "Saps com fer un {POKEBLOCK}?$"

BerryHouse_EventScript_ExplainBlending:
    msgbox BerryHouse_Text_ExplainBerryBlending, MSGBOX_DEFAULT
    goto BerryHouse_EventScript_StartBlender
    end

BerryHouse_Text_ExplainBerryBlending:
    .string "D'acord, una petita explicació.\p"
    .string "No et preocupis, és molt senzill.\p"
    .string "Quan la fletxa de la Mescladora\n"
    .string "arribi al teu marcador, prem\l"
    .string "el Botó A.\p"
    .string "Això és tot.\n"
    .string "Veuràs com de fàcil és!$"

BerryHouse_EventScript_StartBlender:
    msgbox BerryHouse_Text_LetsBerryBlender, MSGBOX_DEFAULT
    goto BerryHouse_EventScript_DoBerryBlending
    end

BerryHouse_Text_LetsBerryBlender:
    .string "Comencem, doncs!\p"
    .string "Mesclem Baies!$"

BerryHouse_EventScript_DoBerryBlending:
    @callnative RemoveFollowingPokemon
    copyvar VAR_0x8004, NUM_OPPONENTS
    fadescreen FADE_TO_BLACK
    special DoBerryBlending
    waitstate
    @callnative UpdateFollowingPokemon
    releaseall
    end





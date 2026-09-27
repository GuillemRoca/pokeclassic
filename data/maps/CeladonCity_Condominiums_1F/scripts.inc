CeladonCity_Condominiums_1F_MapScripts::
	.byte 0

CeladonCity_Condominiums_1F_EventScript_TeaWoman::
	lock
	faceplayer
	goto_if_set FLAG_TALKED_TO_TEA_LADY_POSTGAME, CeladonCity_Condominiums_1F_EventScript_PostgameTeaWoman
	goto_if_set FLAG_SYS_GAME_CLEAR, CeladonCity_Condominiums_1F_EventScript_TeaWomanMentionDaisy
	goto_if_set FLAG_GOT_TEA, CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea
	msgbox CeladonCity_Condominiums_1F_Text_TryThisDrinkInstead
	setflag FLAG_GOT_TEA
	giveitem ITEM_TEA
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox CeladonCity_Condominiums_1F_Text_NothingBeatsThirstLikeTea
	release
	end

CeladonCity_Condominiums_1F_Text_TryThisDrinkInstead::
    .string "No t'hauries de gastar tots els\n"
    .string "diners en begudes.\p"
    .string "Prova això.$"

CeladonCity_Condominiums_1F_Text_NothingBeatsThirstLikeTea::
    .string "Res no mata la set com un bon\n"
    .string "Te calent.\p"
    .string "Realment és el millor.$"

CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea::
	msgbox CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany
	release
	end

CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany::
    .string "Els meus estimats Pokémon em fan\n"
    .string "companyia. Meowth fins i tot\l"
    .string "porta diners a casa!$"

CeladonCity_Condominiums_1F_EventScript_TeaWomanMentionDaisy::
	setflag FLAG_TALKED_TO_TEA_LADY_POSTGAME
	msgbox CeladonCity_Condominiums_1F_Text_DaisyComesToBuyTea
	release
	end

CeladonCity_Condominiums_1F_EventScript_PostgameTeaWoman::
	call_if_unset FLAG_DAILY_GOT_TEA, CeladonCity_Condominiums_1F_EventScript_GetDailyTea
	msgbox CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany
	release
	end

CeladonCity_Condominiums_1F_EventScript_GetDailyTea::
	checkitem ITEM_TEA
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_Return
	msgbox CeladonCity_Condominiums_1F_Text_TakeThisDear
	release
	setflag FLAG_DAILY_GOT_TEA
	giveitem ITEM_TEA
	return

CeladonCity_Condominiums_1F_Text_TakeThisDear::
	.string "Vols una mica de Te, bonica?"

CeladonCity_Condominiums_1F_Text_DaisyComesToBuyTea::
    .string "Oh, hola, bonica.\n"
    .string "T'ha agradat el meu Te?\p"
    .string "Per cert, bonica. Ets, per\n"
    .string "casualitat, de Poble Paleta?\p"
    .string "Una noia de Poble Paleta, Daisy,\n"
    .string "gaudeix del meu Te cada dia.\p"
    .string "Si mai vols una mica de te,\n"
    .string "vine a visitar-me.$"

CeladonCity_Condominiums_1F_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Meowth
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_Text_Meowth::
    .string "Meowth: Miau!$"

CeladonCity_Condominiums_1F_EventScript_Clefairy::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Clefairy
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_Text_Clefairy::
    .string "Clefairy: Pi pippippi!$"

CeladonCity_Condominiums_1F_EventScript_Nidoran::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDORAN_F, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Nidoran
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_Text_Nidoran::
    .string "Nidoran♀: Kya kyaoo!$"

CeladonCity_Condominiums_1F_EventScript_SuiteSign::
	msgbox CeladonCity_Condominiums_1F_Text_ManagersSuite, MSGBOX_SIGN
	end

CeladonCity_Condominiums_1F_Text_ManagersSuite::
    .string "Mansió Celadon\n"
    .string "Suite del Director$"

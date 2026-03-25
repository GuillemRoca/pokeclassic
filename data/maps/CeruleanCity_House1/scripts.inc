CeruleanCity_House1_MapScripts::
	.byte 0

CeruleanCity_House1_EventScript_BulbasaurBreeder::
	msgbox CeruleanCity_House1_Text_HowsThatBulbasaur, MSGBOX_NPC
	release
	end

CeruleanCity_House1_Text_HowsThatBulbasaur::
	.string "Com li va a aquell Bulbasaur\n"
	.string "amb els teus Pokémon?\p"
	.string "Espero que el tractis bé!$"

CeruleanCity_House1_EventScript_BerryGuy::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_WATERING_CAN, CeruleanCity_House1_EventScript_GetWailmerPail
	goto_if_set FLAG_DAILY_CERULEAN_BERRY, CeruleanCity_House1_EventScript_GrowAVariety
	goto CeruleanCity_House1_EventScript_GetDailyBerry

CeruleanCity_House1_EventScript_GetDailyBerry::
	msgbox CeruleanCity_House1_Text_PokemonLoveBerries, MSGBOX_DEFAULT
	random 6
	call_if_eq VAR_RESULT, 0, CeruleanCity_House1_EventScript_GiveGrepaBerry
	call_if_eq VAR_RESULT, 1, CeruleanCity_House1_EventScript_GiveHondewBerry
	call_if_eq VAR_RESULT, 2, CeruleanCity_House1_EventScript_GiveKelpsyBerry
	call_if_eq VAR_RESULT, 3, CeruleanCity_House1_EventScript_GivePomegBerry
	call_if_eq VAR_RESULT, 4, CeruleanCity_House1_EventScript_GiveQualotBerry
	call_if_eq VAR_RESULT, 5, CeruleanCity_House1_EventScript_GiveTamatoBerry
	setflag FLAG_DAILY_CERULEAN_BERRY
	goto CeruleanCity_House1_EventScript_GrowAVariety
	end

CeruleanCity_House1_Text_PokemonLoveBerries::
	.string "Als Pokémon els encanten les baies!\p"
	.string "Alimentar els teus Pokémon és una\n"
	.string "bona manera d'enfortir el vostre\l"
	.string "vincle.\p"
	.string "Té, per què no ho comproves\n"
	.string "tu mateix!$"

CeruleanCity_House1_EventScript_GiveGrepaBerry::
	giveitem ITEM_GREPA_BERRY, 1
	return

CeruleanCity_House1_EventScript_GiveHondewBerry::
	giveitem ITEM_HONDEW_BERRY, 1
	return

CeruleanCity_House1_EventScript_GiveKelpsyBerry::
	giveitem ITEM_KELPSY_BERRY, 1
	return

CeruleanCity_House1_EventScript_GivePomegBerry::
	giveitem ITEM_POMEG_BERRY, 1
	return

CeruleanCity_House1_EventScript_GiveQualotBerry::
	giveitem ITEM_QUALOT_BERRY, 1
	return

CeruleanCity_House1_EventScript_GiveTamatoBerry::
	giveitem ITEM_TAMATO_BERRY, 1
	return

CeruleanCity_House1_EventScript_GrowAVariety::
	msgbox CeruleanCity_House1_Text_GrowAVariety, MSGBOX_DEFAULT
	release
	end

CeruleanCity_House1_Text_GrowAVariety::
	.string "Hi ha tot tipus de baies.\p"
	.string "I no totes tenen els mateixos\n"
	.string "efectes!\p"
	.string "Prova de cultivar-ne de vàries!$"

CeruleanCity_House1_EventScript_GetWailmerPail::
	msgbox CeruleanCity_House1_Text_WifeAndIGrowBerries, MSGBOX_DEFAULT
	checkitemspace ITEM_WAILMER_PAIL, 1
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House1_EventScript_BagFull
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox CeruleanCity_House1_Text_GetWailmerPail, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_WAILMER_PAIL
	setflag FLAG_RECEIVED_WATERING_CAN
	goto CeruleanCity_House1_EventScript_GetDailyBerry
	end

CeruleanCity_House1_Text_GetWailmerPail::
	.string "{PLAYER} ha rebut la Regadora\n"
	.string "del Noi de les Baies!\p"
	.string "{PLAYER} ha guardat la Regadora\n"
	.string "a la butxaca d'Obj. Clau.$"

CeruleanCity_House1_Text_WifeAndIGrowBerries::
	.string "Potser no ho saps, però Kanto\n"
	.string "no sempre ha tingut Baies!\p"
	.string "Poden ser molt difícils de\n"
	.string "cultivar i la gent no en sabia\l"
	.string "gaire llavors.\p"
	.string "Així que la meva dona i jo vam\n"
	.string "viatjar per Kanto plantant\l"
	.string "Arbres de Baies!\p"
	.string "Si en veus algun, serveix-te.\p"
	.string "Volem que tothom cuidi millor la\n"
	.string "terra, per a gent i Pokémon!\p"
	.string "Si culls una baia, planta'n una\n"
	.string "altra! I si tens un moment,\l"
	.string "pots regar-les amb això!$"

CeruleanCity_House1_EventScript_BagFull::
	msgbox CeruleanCity_House1_Text_MaybeLater, MSGBOX_DEFAULT
	release
	end

CeruleanCity_House1_Text_MaybeLater::
 .string "Vaja - la motxilla és plena.\p"
 .string "Potser torna més tard?$"

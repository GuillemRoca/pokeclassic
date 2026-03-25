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
	.string "Als Pokémon els encanten les\n"
	.string "baies!\p"
	.string "Alimentar els teus Pokémon és\n"
	.string "una bona manera d'enfortir\l"
	.string "el vostre vincle.\p"
	.string "Tingues, comprova-ho tu\n"
	.string "mateix!$"

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
	.string "Hi ha tota mena de baies.\p"
	.string "I no totes tenen els mateixos\n"
	.string "efectes!\p"
	.string "Prova de cultivar-ne de\n"
	.string "diferents!$"

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
	.string "del Senyor de les Baies!\p"
	.string "{PLAYER} ha posat la Regadora\n"
	.string "a la butxaca d'Obj. Clau.$"

CeruleanCity_House1_Text_WifeAndIGrowBerries::
	.string "Potser no ho saps, però a Kanto\n"
	.string "no sempre hi havia Baies!\p"
	.string "Són difícils de cultivar i la\n"
	.string "gent no en sabia gaire,\l"
	.string "d'aquestes coses.\p"
	.string "Així que la meva dona i jo vam\n"
	.string "viatjar per Kanto plantant\l"
	.string "Arbres de Baies!\p"
	.string "Si en veus algun, serveix-te\n"
	.string "tu mateix.\p"
	.string "Volem que tothom cuidi millor\n"
	.string "la terra, tant per a la gent\l"
	.string "com per als Pokémon!\p"
	.string "Si culls una baia, planta'n\n"
	.string "una altra! I si tens un moment,\l"
	.string "les pots regar amb això!$"

CeruleanCity_House1_EventScript_BagFull::
	msgbox CeruleanCity_House1_Text_MaybeLater, MSGBOX_DEFAULT
	release
	end

CeruleanCity_House1_Text_MaybeLater::
 .string "Vaja, la bossa és plena.\p"
 .string "Potser torna més tard?$"


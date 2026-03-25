.set LOCALID_NURSE, 1

CeruleanCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_1F_OnTransition
	.byte 0

CeruleanCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	end

CeruleanCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

CeruleanCity_PokemonCenter_1F_EventScript_Gentleman::
	goto_if_set FLAG_REGISTERED_BILL, CeruleanCity_PokemonCenter_1F_EventScript_MetBill
	msgbox CeruleanCity_PokemonCenter_1F_Text_EveryoneCallsBillPokemaniac, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_Text_EveryoneCallsBillPokemaniac::
    .string "Has sentit parlar d'en Bill?\p"
    .string "Tothom li diu PokèManíac!\p"
    .string "Crec que la gent té enveja\n"
    .string "d'en Bill, però.\p"
    .string "Qui no voldria presumir dels\n"
    .string "seus Pokémon?$"

CeruleanCity_PokemonCenter_1F_EventScript_MetBill:
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillNumber, MSGBOX_NPC
	release
	end

CeruleanCity_PokemonCenter_1F_Text_BillNumber::
	.string "Oh, has conegut en Bill!\n"
	.string "I fins i tot t'ha donat el\l"
	.string "seu número de mòbil!\p"
	.string "Uau, és molt accessible!$"

CeruleanCity_PokemonCenter_1F_EventScript_Rocker::
	goto_if_set FLAG_REGISTERED_BILL, CeruleanCity_PokemonCenter_1F_EventScript_IsItTrueAboutBill
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillDoesWhateverForRareMons, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_Text_BillDoesWhateverForRareMons::
    .string "En Bill!\p"
    .string "He sentit que fa el que sigui\n"
    .string "per aconseguir Pokémon rars.\p"
    .string "Diuen que és capaç de fer\n"
    .string "de tot.$"

CeruleanCity_PokemonCenter_1F_EventScript_IsItTrueAboutBill::
	msgbox CeruleanCity_PokemonCenter_1F_Text_IsItTrue, MSGBOX_NPC
	release
	end

CeruleanCity_PokemonCenter_1F_Text_IsItTrue::
	.string "Oh, has conegut en Bill?\p"
	.string "És veritat el que diuen?\n"
	.string "Faria qualsevol cosa per\l"
	.string "aconseguir Pokémon rars?$"


CeruleanCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillCollectsRareMons, MSGBOX_NPC
	release
	end

CeruleanCity_PokemonCenter_1F_Text_BillCollectsRareMons::
    .string "En Bill té molts Pokémon!\n"
    .string "Col·lecciona els rars, també!$"

CeruleanCity_PokemonCenter_1F_EventScript_Lass::
	msgbox CeruleanCity_PokemonCenter_1F_Text_TryTradingUpstairs, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_Text_TryTradingUpstairs::
    .string "Abans pujàvem al pis de dalt\n"
    .string "per intercanviar Pokémon amb\l"
    .string "els amics.\p"
    .string "Podies aconseguir molta més\n"
    .string "varietat intercanviant.\p"
    .string "Però avui dia ningú sembla\n"
    .string "intercanviar Pokémon.$"

CeruleanCity_PokemonCenter_1F_EventScript_PokemonJournalMisty::
	msgbox PokemonJournal_Text_SpecialFeatureMisty, MSGBOX_SIGN
	release
	end

PokemonJournal_Text_SpecialFeatureMisty::
	.string "Diari Pokémon:\p"
	.string "Reportatge: Misty, Líder del\n"
	.string "Gimnàs de Cerulean!\p"
	.string "Diuen que la Misty idolatra\n"
	.string "la Lorelei de l'Alt Comandament.$"

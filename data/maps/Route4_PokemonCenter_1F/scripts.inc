.set LOCALID_NURSE, 1
.set MAGIKARP_PRICE, 500

Route4_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_PokemonCenter_1F_OnTransition
	.byte 0

Route4_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_ROUTE_4
	end

.set LOCALID_NURSE, 1

Route4_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

Route4_PokemonCenter_1F_EventScript_Boy::
	msgbox Route4_PokemonCenter_1F_Text_CanHaveSixMonsWithYou, MSGBOX_NPC
	end

Route4_PokemonCenter_1F_Text_CanHaveSixMonsWithYou::
    .string "Bé, poso sis Poké Balls al\n"
    .string "cinturó…\p"
    .string "Sí, amb això n'hi ha prou. Com a\n"
    .string "màxim pots portar sis Pokémon.$"

Route4_PokemonCenter_1F_EventScript_Gentleman::
	lock
	msgbox Route4_PokemonCenter_1F_Text_TeamRocketAttacksCerulean
	release
	end

Route4_PokemonCenter_1F_Text_TeamRocketAttacksCerulean::
    .string "L'Equip Rocket ataca ciutadans\n"
    .string "de Cerulean…\p"
    .string "No passa un dia sense que el\n"
    .string "Equip Rocket surti a les notícies.$"

Route4_PokemonCenter_1F_EventScript_Youngster::
	msgbox Route4_PokemonCenter_1F_Text_ShouldStoreMonsUsingPC, MSGBOX_NPC
	end

Route4_PokemonCenter_1F_Text_ShouldStoreMonsUsingPC::
    .string "A vegades, tindràs massa Pokémon\n"
    .string "per afegir-ne més.\p"
    .string "En aquest cas, simplement\n"
    .string "guarda'n alguns al PC.$"

Route4_PokemonCenter_1F_EventScript_Newspaper::
	lock
	msgbox Route4_PokemonCenter_1F_Text_Newspaper, MSGBOX_DEFAULT
	release
	end

Route4_PokemonCenter_1F_Text_Newspaper::
    .string "És un diari.\n"
    .string "EL TEAM ROCKET ATACA CIUTADANS\p"
    .string "DE CERULEAN!\p"
    .string "...diversos robatoris reportats\n"
    .string "...activitat de bandes en augment...\l"
    .string "La Policia Internacional podria\l"
    .string "intervenir-hi...$"

Route4_PokemonCenter_1F_EventScript_MagikarpSalesman::
	lock
	faceplayer
	goto_if_set FLAG_BOUGHT_MAGIKARP, Route4_PokemonCenter_1F_EventScript_AlreadyBoughtMagikarp
	showmoneybox 0, 0
	msgbox Route4_PokemonCenter_1F_Text_BuyMagikarpForJust500, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_DeclineMagikarp
	checkmoney 500
	goto_if_eq VAR_RESULT, FALSE, Route4_PokemonCenter_1F_EventScript_NotEnoughMoney
	setvar VAR_TEMP_1, SPECIES_MAGIKARP
	givemon SPECIES_MAGIKARP, 5, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, Route4_PokemonCenter_1F_EventScript_BuyMagikarpParty
	goto_if_eq VAR_RESULT, 1, Route4_PokemonCenter_1F_EventScript_BuyMagikarpPC
	goto_if_eq VAR_RESULT, 2, Route4_PokemonCenter_1F_EventScript_NoRoomForMagikarp
	end

Route4_PokemonCenter_1F_Text_BuyMagikarpForJust500::
    .string "Home: Ei, nano!\n"
    .string "Tinc una oferta genial per a tu!\p"
    .string "Et deixaré un Pokémon secret\n"
    .string "- un Magikarp - per només ¥500!\p"
    .string "Doncs, el compraràs, oi?$"


Route4_PokemonCenter_1F_EventScript_BuyMagikarpParty::
	call Route4_PokemonCenter_1F_EventScript_PayForMagikarp
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	end

Route4_PokemonCenter_1F_EventScript_BuyMagikarpPC::
	call Route4_PokemonCenter_1F_EventScript_PayForMagikarp
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_TransferMagikarp
	call Common_EventScript_NameReceivedBoxMon
	goto Route4_PokemonCenter_1F_EventScript_TransferMagikarp
	end

Route4_PokemonCenter_1F_EventScript_TransferMagikarp::
	call Common_EventScript_TransferredToPC
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	end

Route4_PokemonCenter_1F_EventScript_NoRoomForMagikarp::
	msgbox Route4_PokemonCenter_1F_Text_NoRoomForMorePokemon, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_Text_NoRoomForMorePokemon::
    .string "Sembla que no tens lloc per a\n"
    .string "cap més Pokémon.$"

Route4_PokemonCenter_1F_EventScript_PayForMagikarp::
	removemoney 500
	updatemoneybox
	playfanfare MUS_LEVEL_UP
	message Route4_PokemonCenter_1F_Text_PaidOutrageouslyForMagikarp
	waitmessage
	waitfanfare
	hidemoneybox
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKARP
	return

Route4_PokemonCenter_1F_Text_PaidOutrageouslyForMagikarp::
    .string "{PLAYER} ha pagat uns escandalosos\n"
    .string "¥500 i ha comprat el Magikarp…$"

Route4_PokemonCenter_1F_EventScript_BoughtMagikarp::
	setflag FLAG_BOUGHT_MAGIKARP
	release
	end

Route4_PokemonCenter_1F_EventScript_DeclineMagikarp::
	msgbox Route4_PokemonCenter_1F_Text_OnlyDoingThisAsFavorToYou, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_Text_OnlyDoingThisAsFavorToYou::
    .string "No? Dius que no? Només ho faig\n"
    .string "com un favor per a tu!$"

Route4_PokemonCenter_1F_EventScript_NotEnoughMoney::
	msgbox Route4_PokemonCenter_1F_Text_YoullNeedMoreMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_Text_YoullNeedMoreMoney::
    .string "Necessitaràs més diners!$"

Route4_PokemonCenter_1F_EventScript_AlreadyBoughtMagikarp::
	msgbox Route4_PokemonCenter_1F_Text_IDontGiveRefunds, MSGBOX_DEFAULT
	release
	end

Route4_PokemonCenter_1F_Text_IDontGiveRefunds::
    .string "Home: Bé, no faig devolucions.\n"
    .string "Sabies què compràveu!$"

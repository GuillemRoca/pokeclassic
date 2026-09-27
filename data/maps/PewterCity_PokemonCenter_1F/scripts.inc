.set LOCALID_NURSE, 1

PewterCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_PokemonCenter_1F_OnTransition
	.byte 0

PewterCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_PEWTER_CITY
	end

PewterCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

PewterCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox PewterCity_PokemonCenter_1F_Text_TeamRocketMtMoonImOnPhone, MSGBOX_NPC
	end

PewterCity_PokemonCenter_1F_Text_TeamRocketMtMoonImOnPhone::
    .string "Què!?\p"
    .string "L'Equip Rocket és al Mt. Moon?\n"
    .string "Eh?\p"
    .string "Estic al telèfon!\n"
    .string "Fora d'aquí!$"

PewterCity_PokemonCenter_1F_EventScript_Jigglypuff::
	lock
	faceplayer
	fadeoutbgm 0
	playbgm MUS_RG_JIGGLYPUFF, 0
	message PewterCity_PokemonCenter_1F_Text_Jigglypuff
	waitmessage
	delay 455
	playbgm MUS_RG_POKE_CENTER, 1
	closemessage
	release
	end

PewterCity_PokemonCenter_1F_Text_Jigglypuff::
    .string "Jigglypuff: Puu pupuu!$"

PewterCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PewterCity_PokemonCenter_1F_Text_WhenJiggylypuffSingsMonsGetDrowsy, MSGBOX_NPC
	end

PewterCity_PokemonCenter_1F_Text_WhenJiggylypuffSingsMonsGetDrowsy::
    .string "Badall!\p"
    .string "Quan Jigglypuff canta, els\n"
    .string "Pokémon s'adormeixen…\p"
    .string "…Jo també…\n"
    .string "Zzz…$"

PewterCity_PokemonCenter_1F_EventScript_GBAKid1::
	lock
	msgbox PewterCity_PokemonCenter_1F_Text_TradingMyClefairyForPikachu
	release
	end

PewterCity_PokemonCenter_1F_Text_TradingMyClefairyForPikachu::
    .string "Vull molt un Pikachu, així que\n"
    .string "canvio el meu Clefairy per un.$"

PewterCity_PokemonCenter_1F_EventScript_GBAKid2::
	msgbox PewterCity_PokemonCenter_1F_Text_TradingPikachuWithKid, MSGBOX_NPC
	end

PewterCity_PokemonCenter_1F_Text_TradingPikachuWithKid::
    .string "Estic intercanviant Pokémon amb\n"
    .string "aquell nen d'allà.\p"
    .string "Tenia dos Pikachu, així que he\n"
    .string "pensat que en podia canviar un.$"

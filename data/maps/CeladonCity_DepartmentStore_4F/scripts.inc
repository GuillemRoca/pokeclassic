CeladonCity_DepartmentStore_4F_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_4F_EventScript_Man::
	msgbox CeladonCity_DepartmentStore_4F_Text_GettingPokeDollAsPresent, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_Text_GettingPokeDollAsPresent::
    .string "Busco un regal per a la meva\n"
    .string "xicota.\p"
    .string "Suposo que serà una Poké Doll.\n"
    .string "És el que es porta.$"

CeladonCity_DepartmentStore_4F_EventScript_Youngster::
	msgbox CeladonCity_DepartmentStore_4F_Text_CanRunAwayWithPokeDoll, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_Text_CanRunAwayWithPokeDoll::
    .string "He sentit una cosa útil.\p"
    .string "Si apareix un Pokémon salvatge,\n"
    .string "pots distreure'l amb una Poké Doll.\p"
    .string "Pots fugir mentre el Pokémon\n"
    .string "salvatge està distret.$"

CeladonCity_DepartmentStore_4F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_4F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_4F_Text_FloorSign::
    .string "Expressa't amb regals!\n"
    .string "4F: Regals del Savi\p"
    .string "Especial Evolució!\n"
    .string "Pedres Elementals en oferta!$"

CeladonCity_DepartmentStore_4F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_4F_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_4F_Items::
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_POWER_STONE
	.2byte ITEM_NONE
	release
	end

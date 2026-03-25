CeladonCity_DepartmentStore_2F_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_2F_EventScript_UnusedNPC::
	msgbox CeladonCity_DepartmentStore_2F_Text_SuperRepelMorePowerfulRepel, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_2F_Text_SuperRepelMorePowerfulRepel::
    .string "El Super Repel manté els Pokémon\n"
    .string "febles a ratlla…\p"
    .string "Hmm, és un Repel més potent.$"

CeladonCity_DepartmentStore_2F_EventScript_Lass::
	msgbox CeladonCity_DepartmentStore_2F_Text_BuyReviveForLongOutings, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_2F_Text_BuyReviveForLongOutings::
    .string "Per a sortides llargues, hauries\n"
    .string "de comprar Revive.$"

CeladonCity_DepartmentStore_2F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_2F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_2F_Text_FloorSign::
    .string "Objectes de primera per a\n"
    .string "Entrenadors!\p"
    .string "2F: Mercat d'Entrenadors$"

CeladonCity_DepartmentStore_2F_EventScript_ClerkItems::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_2F_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_2F_Items::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_2F_EventScript_ClerkTMs::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_2F_TMs
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_2F_TMs::
	.2byte ITEM_TM05
	.2byte ITEM_TM15
	.2byte ITEM_TM28
	.2byte ITEM_TM31
	.2byte ITEM_TM43
	.2byte ITEM_TM44
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_2F_EventScript_Woman::
    lock
    faceplayer
    msgbox CeladonCity_DepartmentStore_2F_Text_LanceComesToBuyCapes
    release
    end

CeladonCity_DepartmentStore_2F_Text_LanceComesToBuyCapes::
    .string "Tenim un client, Lance, que\n"
    .string "ve de tant en tant.\p"
    .string "Sempre compra capes.\p"
    .string "Em pregunto… Tindrà moltes\n"
    .string "capes idèntiques a casa?$"

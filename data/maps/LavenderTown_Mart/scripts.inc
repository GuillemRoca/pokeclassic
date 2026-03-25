LavenderTown_Mart_MapScripts::
	.byte 0

LavenderTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavenderTown_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavenderTown_Pokemart::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_NONE
	release
	end

LavenderTown_Mart_EventScript_BaldingMan::
	msgbox LavenderTown_Mart_Text_SearchingForStatRaiseItems, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Rocker::
	msgbox LavenderTown_Mart_Text_DidYouBuyRevives, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Youngster::
	msgbox LavenderTown_Mart_Text_TrainerDuosCanChallengeYou, MSGBOX_NPC
	end

LavenderTown_Mart_Text_SearchingForStatRaiseItems::
    .string "Busco objectes que pugin les\n"
    .string "estadístiques dels Pokémon.\p"
    .string "Són efectius durant un sol\n"
    .string "combat.\p"
    .string "X Atac, X Defensa, X Velocitat\n"
    .string "i X Especial és el que busco.\p"
    .string "Saps on puc trobar-los?$"

LavenderTown_Mart_Text_DidYouBuyRevives::
    .string "Has comprat Revius?\n"
    .string "Reviuen qualsevol Pokémon debilitat!$"

LavenderTown_Mart_Text_TrainerDuosCanChallengeYou::
    .string "De vegades, un duo d'entrenadors\n"
    .string "et desafiarà amb dos Pokémon\l"
    .string "alhora.\p"
    .string "Si passa, hauràs d'enviar\n"
    .string "dos Pokémon a combatre també.$"

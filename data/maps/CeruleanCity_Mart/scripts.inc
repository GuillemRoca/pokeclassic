CeruleanCity_Mart_MapScripts::
	.byte 0

CeruleanCity_Mart_EventScript_Youngster::
	msgbox CeruleanCity_Mart_Text_RepelWorksOnWeakMons, MSGBOX_NPC
	end

CeruleanCity_Mart_Text_RepelWorksOnWeakMons::
	.string "El Repel·lent no només espanta\n"
	.string "insectes, també funciona amb\l"
	.string "Pokémon febles.\p"
	.string "Posa el teu Pokémon més fort a\n"
	.string "l'esquerra de la Llista de Pokémon.\p"
	.string "Si el primer Pokémon és fort,\n"
	.string "l'efecte del Repel·lent es potencia.$"

CeruleanCity_Mart_EventScript_Woman::
	msgbox CeruleanCity_Mart_Text_DoYouKnowAboutRareCandy, MSGBOX_NPC
	end

CeruleanCity_Mart_Text_DoYouKnowAboutRareCandy::
	.string "Coneixes els Caramels Rars?\n"
	.string "No els venen a les botigues.\p"
	.string "Crec que fan créixer els Pokémon\n"
	.string "molt ràpidament de cop.$"

CeruleanCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeruleanCity_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
CeruleanCity_Pokemart::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end

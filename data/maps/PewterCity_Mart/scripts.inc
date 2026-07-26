PewterCity_Mart_MapScripts::
	.byte 0

PewterCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart PewterCity_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PewterCity_Pokemart::
	.2byte ITEM_POKE_BALL
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

PewterCity_Mart_EventScript_Youngster::
	msgbox PewterCity_Mart_Text_BoughtWeirdFishFromShadyGuy, MSGBOX_NPC
	end

PewterCity_Mart_Text_BoughtWeirdFishFromShadyGuy::
    .string "Un vell sospitós em va enredar\n"
    .string "per comprar un Pokémon peix rar!\p"
    .string "És totalment feble i va costar\n"
    .string "¥500!$"

PewterCity_Mart_EventScript_Boy::
	msgbox PewterCity_Mart_Text_GoodThingsIfRaiseMonsDiligently, MSGBOX_NPC
	end

PewterCity_Mart_Text_GoodThingsIfRaiseMonsDiligently::
    .string "Coses bones poden passar si\n"
    .string "cries Pokémon amb dedicació.\p"
    .string "Fins i tot els febles et poden\n"
    .string "sorprendre si no et rendeixes.$"

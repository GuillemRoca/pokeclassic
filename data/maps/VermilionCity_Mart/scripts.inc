VermilionCity_Mart_MapScripts::
	.byte 0

VermilionCity_Mart_EventScript_CooltrainerF::
	msgbox VermilionCity_Mart_Text_MonsGoodOrBadDependingOnTrainer, MSGBOX_NPC
	end

VermilionCity_Mart_Text_MonsGoodOrBadDependingOnTrainer::
    .string "Crec que els Pokémon poden ser\n"
    .string "bons o dolents. Depèn de\l"
    .string "l'entrenador.$"

VermilionCity_Mart_EventScript_BaldingMan::
	msgbox VermilionCity_Mart_Text_TeamRocketAreWickedPeople, MSGBOX_NPC
	end

VermilionCity_Mart_Text_TeamRocketAreWickedPeople::
    .string "Hi ha gent malvada que farà\n"
    .string "servir Pokémon per actes criminals.\p"
    .string "L'Equip Rocket trafica amb\n"
    .string "Pokémon rars, per exemple.\p"
    .string "També abandonen els Pokémon que\n"
    .string "consideren impopulars o inútils.\p"
    .string "Aquesta és la mena de gent\n"
    .string "horrible que són, l'Equip Rocket.$"

VermilionCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VermilionCity_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VermilionCity_Pokemart::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end

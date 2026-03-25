SaffronCity_PokemonCenter_2F_MapScripts::
	.byte 0

SaffronCity_PokemonCenter_2F_Rocket1::
	msgbox SaffronCity_PokemonCenter_2F_Text_Rocket1, MSGBOX_NPC
	release
	end

SaffronCity_PokemonCenter_2F_Text_Rocket1::
	.string "Heh, fes el camp, nen!\n"
	.string "Ara això és botí de l'Equip\l"
	.string "Rocket!$"


SaffronCity_PokemonCenter_2F_Rocket2::
	msgbox SaffronCity_PokemonCenter_2F_Text_Rocket2, MSGBOX_NPC
	release
	end

SaffronCity_PokemonCenter_2F_Text_Rocket2::
	.string "Uh... he oblidat a què veníem.$"

SaffronCity_PokemonCenter_2F_Rocket3::
	msgbox SaffronCity_PokemonCenter_2F_Text_Rocket3, MSGBOX_NPC
	release
	end

SaffronCity_PokemonCenter_2F_Text_Rocket3::
	.string "Uau! Tenen coses molt rares\n"
	.string "aquí al darrere!\p"
	.string "Al Cap li encantarà aquest botí!$"


SaffronCity_PokemonCenter_2F_BlackBelt::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BLACK_BELT, SaffronCity_PokemonCenter_2F_BlackBelt2
	msgbox SaffronCity_PokemonCenter_2F_Text_Unworthy, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_BELT, 1
	setflag FLAG_RECEIVED_BLACK_BELT
	release
	end

SaffronCity_PokemonCenter_2F_BlackBelt2::
	msgbox SaffronCity_PokemonCenter_2F_Text_Unworthy2, MSGBOX_DEFAULT
	release
	end

SaffronCity_PokemonCenter_2F_Text_Unworthy::
	.string "Estic avergonyit.\p"
	.string "Quan l'Equip Rocket va atacar\n"
	.string "Ciutat Saffron, no vaig poder\l"
	.string "aturar-los.\p"
	.string "No sóc digne d'això.$"

SaffronCity_PokemonCenter_2F_Text_Unworthy2::
	.string "He de tornar al Dojo.\n"
	.string "He de reentrenar el meu cos i\l"
	.string "esperit.$"

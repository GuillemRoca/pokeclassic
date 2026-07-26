VermilionCity_PokemonCenter_2F_MapScripts::
	.byte 0

VermilionCity_PokemonCenter_2F_Pokefan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_DESTINY_KNOT, VermilionCity_PokemonCenter_2F_Pokefan2
	msgbox VermilionCity_PokemonCenter_2F_DestinyKnot, MSGBOX_DEFAULT
	giveitem ITEM_DESTINY_KNOT
	setflag FLAG_GOT_DESTINY_KNOT
	release
	end

VermilionCity_PokemonCenter_2F_DestinyKnot::
	.string "Vaig haver de deixar el meu\n"
	.string "adorable Meowth a la Guarderia\l"
	.string "quan vaig anar de creuer.\p"
	.string "No volia que se sentís sol,\n"
	.string "així que li vaig deixar un regal.\p"
	.string "Mira, en tenia un de més,\n"
	.string "hauries d'agafar-lo!$"

VermilionCity_PokemonCenter_2F_Pokefan2::
	msgbox VermilionCity_PokemonCenter_2F_Daycare, MSGBOX_DEFAULT
	release
	end

VermilionCity_PokemonCenter_2F_Daycare::
	.string "Has visitat la Guarderia?\n"
	.string "És a la Ruta 5.$"

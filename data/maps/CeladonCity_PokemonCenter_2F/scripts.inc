CeladonCity_PokemonCenter_2F_MapScripts::
	.byte 0

CeladonCity_PokemonCenter_2F_Shopper::
	lock
	faceplayer
	msgbox CeladonCity_PokemonCenter_2F_Shopping, MSGBOX_DEFAULT
	release
	end

CeladonCity_PokemonCenter_2F_Shopping::
	.string "Els Serveis de la Lliga aquí tenen\n"
	.string "opcions interessants, però prefereixo\l"
	.string "comprar als Grans Magatzems.$"

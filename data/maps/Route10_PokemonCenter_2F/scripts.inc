Route10_PokemonCenter_2F_MapScripts::
	.byte 0

Route10_PokemonCenter_2F_Hiker::
	lock
	faceplayer
	msgbox Route10_PokemonCenter_2F_Darkness, MSGBOX_DEFAULT
	release
	end

Route10_PokemonCenter_2F_Darkness::
	.string "El Túnel Roca és massa fosc per\n"
	.string "travessar-lo!$"

Route4_PokemonCenter_2F_MapScripts::
	.byte 0

Route4_PokemonCenter_2F_Hiker::
	lockall
	goto_if_set FLAG_GOT_HM06, Route4_PokemonCenter_2F_HikerRockSmash
	msgbox Route4_PokemonCenter_2F_Text_RockSmash, MSGBOX_DEFAULT
	giveitem ITEM_HM06
	waitmessage
	setflag FLAG_GOT_HM06
	msgbox Route4_PokemonCenter_2F_Text_MyGeodude, MSGBOX_DEFAULT
	releaseall
	end


Route4_PokemonCenter_2F_Text_RockSmash::
	.string "Estic buscant Pedres Lunars amb\n"
	.string "els meus Pokémon!\p"
	.string "Tu també hauries de provar-ho!$"

Route4_PokemonCenter_2F_HikerRockSmash::
	lock
	msgbox Route4_PokemonCenter_2F_Text_MyGeodude, MSGBOX_NPC
	release
	end

Route4_PokemonCenter_2F_Text_MyGeodude::
	.string "Vigila quan facis servir Destrossa\n"
	.string "Roques. A vegades, un Pokémon pot\l"
	.string "aparèixer!\p"
	.string "Així és com vaig conèixer\n"
	.string "el meu Geodude!$"

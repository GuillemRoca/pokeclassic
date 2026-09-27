CeruleanCity_PokemonCenter_2F_MapScripts::
	.byte 0

CeruleanCity_PokemonCenter_2F_Girl::
	lock
	faceplayer
	goto_if_set FLAG_GOT_EVIOLITE, CeruleanCity_PokemonCenter_2F_Girl2
	msgbox CeruleanCity_PokemonCenter_2F_Text_Eviolite, MSGBOX_DEFAULT
	giveitem ITEM_EVIOLITE
	setflag FLAG_GOT_EVIOLITE
	release
	end

CeruleanCity_PokemonCenter_2F_Text_Eviolite::
	.string "Has sentit parlar de l'Eviolita?\p"
	.string "És un objecte que potencia\n"
	.string "les estadístiques d'un Pokémon\l"
	.string "que encara no ha evolucionat!\p"
	.string "Té, hauries d'agafar-ne una!$"

CeruleanCity_PokemonCenter_2F_Girl2::
	msgbox CeruleanCity_PokemonCenter_2F_Oddish, MSGBOX_DEFAULT
	release
	end

CeruleanCity_PokemonCenter_2F_Oddish::
	.string "No vull que el meu Oddish evolucioni!\n"
	.string "És massa bonic!$"

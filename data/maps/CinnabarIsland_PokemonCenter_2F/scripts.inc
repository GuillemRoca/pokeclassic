CinnabarIsland_PokemonCenter_2F_MapScripts::
	.byte 0

CinnabarIsland_PokemonCenter_2F_Resident::
	lock
	faceplayer
	msgbox CinnabarIsland_PokemonCenter_2F_Volcano, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_PokemonCenter_2F_Volcano::
	.string "Diuen que l'Illa Cinnabar és\n"
	.string "un volcà actiu.\p"
	.string "Espero que no passi res mai!$"

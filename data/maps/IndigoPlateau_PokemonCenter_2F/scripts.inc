IndigoPlateau_PokemonCenter_2F_MapScripts::
	.byte 0

IndigoPlateau_PokemonCenter_2F_Trainer::
	lock
	faceplayer
	msgbox IndigoPlateau_PokemonCenter_2F_NervousTrainer, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_2F_NervousTrainer::
	.string "Respira fondo...\n"
	.string "Respira fondo...\p"
	.string "Estic bastant nerviós per\n"
	.string "enfrontar-me a l'Alt Comandament...$"

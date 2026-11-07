IndigoPlateau_PokemonCenter_2F_MapScripts::
	.byte 0

IndigoPlateau_PokemonCenter_2F_Trainer::
	lock
	faceplayer
	msgbox IndigoPlateau_PokemonCenter_2F_NervousTrainer, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_2F_NervousTrainer::
	.string "Respira a fons...\n"
	.string "Respira a fons...\p"
	.string "Estic bastant nerviós per\n"
	.string "enfrontar-me a l'Alt Comandament...$"

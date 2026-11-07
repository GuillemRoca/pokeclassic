MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "Gràcies per utilitzar el Sistema\n"
	.string "de Regal Misteriós.\p"
	.string "Amb aquesta Targeta Prodigi, pots\n"
	.string "participar en una enquesta en una\l"
	.string "Botiga Pokémon.\p"
	.string "Utilitza les enquestes per convidar\n"
	.string "Entrenadors a Ciutat Sootopolis.\p"
	.string "…Deixa'm donar-te una contrasenya\n"
	.string "secreta per a una enquesta:\p"
	.string "“Dona'm\n"
	.string "Increïble Entrenador”\p"
	.string "Escriu-ho en una enquesta i envia-ho\n"
	.string "al Sistema de Comunicació\l"
	.string "Sense Fils.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Gràcies per utilitzar el Sistema\n"
	.string "de Regal Misteriós.\p"
	.string "Un Entrenador ha arribat a\n"
	.string "Ciutat Sootopolis buscant-te.\p"
	.string "Esperem que gaudeixis del combat\n"
	.string "amb l'Entrenador visitant.\p"
	.string "Pots convidar altres Entrenadors\n"
	.string "introduint altres contrasenyes.\p"
	.string "Prova de buscar altres contrasenyes\n"
	.string "que puguin funcionar.$"

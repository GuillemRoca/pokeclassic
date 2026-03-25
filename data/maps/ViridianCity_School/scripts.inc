.set LOCALID_WOMAN, 1
.set LOCALID_LASS,  2

ViridianCity_School_MapScripts::
	.byte 0

ViridianCity_School_EventScript_Lass::
	lock
	faceplayer
	msgbox ViridianCity_School_Text_TryingToMemorizeNotes, MSGBOX_DEFAULT
	applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFasterUp
	waitmovement 2
	release
	end

ViridianCity_School_Text_TryingToMemorizeNotes::
    .string "Uf! Estic intentant memoritzar\n"
    .string "tots els meus apunts.$"

ViridianCity_School_EventScript_Woman::
	lock
	faceplayer
	msgbox ViridianCity_School_Text_ReadBlackboardCarefully, MSGBOX_DEFAULT
	turnobject LOCALID_WOMAN, DIR_SOUTH
	waitmovement 1
	release
	end

ViridianCity_School_Text_ReadBlackboardCarefully::
    .string "D'acord!\p"
    .string "Assegura't de llegir bé el que\n"
    .string "hi ha a la pissarra!$"

ViridianCity_School_EventScript_Notebook::
	lockall
	msgbox ViridianCity_School_Text_NotebookFirstPage, MSGBOX_DEFAULT
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookSecondPage, MSGBOX_DEFAULT
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookThirdPage, MSGBOX_DEFAULT
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookFourthPage, MSGBOX_DEFAULT
	applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFasterUp
	waitmovement 2
	msgbox ViridianCity_School_Text_HeyDontLookAtMyNotes, MSGBOX_DEFAULT
	releaseall
	end

ViridianCity_School_Text_TurnThePage::
    .string "Passar la pàgina?$"

ViridianCity_School_Text_NotebookFirstPage::
    .string "Mirem la llibreta.\p"
    .string "Primera pàgina…\p"
    .string "Les Poké Balls s'usen per\n"
    .string "atrapar Pokémon.\p"
    .string "Es poden portar fins a sis\n"
    .string "Pokémon a l'equip.\p"
    .string "Les persones que crien i\n"
    .string "combaten amb Pokémon s'anomenen\l"
    .string "Entrenadors.$"

ViridianCity_School_Text_NotebookSecondPage::
    .string "Segona pàgina…\p"
    .string "Un Pokémon sa pot ser difícil\n"
    .string "d'atrapar, així que debilita'l\l"
    .string "primer.\p"
    .string "Enverina'l, crema'l o causa-li\n"
    .string "un altre problema d'estat per\l"
    .string "debilitar-lo.$"

ViridianCity_School_Text_NotebookThirdPage::
    .string "Tercera pàgina…\p"
    .string "Els Entrenadors Pokémon busquen\n"
    .string "altres per a combats Pokémon.\p"
    .string "Per als Entrenadors, el gust de\n"
    .string "la victòria és dolç.\p"
    .string "Els combats es lliuren\n"
    .string "constantment als Gimnasos\l"
    .string "Pokémon d'arreu.$"

ViridianCity_School_Text_NotebookFourthPage::
    .string "Quarta pàgina…\p"
    .string "L'objectiu final de tot Entrenador\n"
    .string "Pokémon és simple.\p"
    .string "Derrotar els vuit Líders de\n"
    .string "Gimnàs Pokémon.\p"
    .string "Fes-ho per guanyar el dret\n"
    .string "d'enfrontar-te…\p"
    .string "A l'Alt Comandament de la Lliga\n"
    .string "Pokémon!$"

ViridianCity_School_EventScript_StopReadingNotebook::
	releaseall
	end

ViridianCity_School_Text_HeyDontLookAtMyNotes::
    .string "Noia: Ei!\n"
    .string "No miris els meus apunts!$"

ViridianCity_School_EventScript_Blackboard::
	lockall
	msgbox ViridianCity_School_Text_BlackboardListsStatusProblems
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_Text_BlackboardListsStatusProblems::
    .string "La pissarra llista els problemes\n"
    .string "d'estat dels Pokémon en combat.$"

ViridianCity_School_EventScript_ChooseBlackboardTopic::
	message ViridianCity_School_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 7, 1, MULTI_TRAINER_SCHOOL_WHITEBOARD, 3, FALSE
	switch VAR_RESULT
	case 0, ViridianCity_School_EventScript_ReadPoison
	case 1, ViridianCity_School_EventScript_ReadSleep
	case 2, ViridianCity_School_EventScript_ReadParalysis
	case 3, ViridianCity_School_EventScript_ReadBurn
	case 4, ViridianCity_School_EventScript_ReadFreeze
	case 5, ViridianCity_School_EventScript_ExitBlackboard
	case MULTI_B_PRESSED, ViridianCity_School_EventScript_ExitBlackboard
	end

ViridianCity_School_Text_ReadWhichTopic::
    .string "Quin tema vols llegir?$"

ViridianCity_School_EventScript_ReadSleep::
	msgbox ViridianCity_School_Text_ExplainSleep
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_Text_ExplainSleep::
    .string "Un Pokémon no pot atacar si\n"
    .string "està adormit.\p"
    .string "Els Pokémon seguiran adormits\n"
    .string "fins i tot després dels combats.\p"
    .string "Usa un Despertador per\n"
    .string "despertar-lo.$"

ViridianCity_School_EventScript_ReadBurn::
	msgbox ViridianCity_School_Text_ExplainBurn
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_Text_ExplainBurn::
    .string "Una cremada redueix l'Atac.\n"
    .string "També causa pèrdua contínua de PS.\p"
    .string "La cremada perdura després del\n"
    .string "combat. Usa Curacremades.$"

ViridianCity_School_EventScript_ReadPoison::
	msgbox ViridianCity_School_Text_ExplainPoison
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_Text_ExplainPoison::
    .string "Quan està enverinat, la salut\n"
    .string "del Pokémon baixa gradualment.\p"
    .string "El verí persisteix després dels\n"
    .string "combats. Usa un Antídot!$"

ViridianCity_School_EventScript_ReadFreeze::
	msgbox ViridianCity_School_Text_ExplainFreeze
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_Text_ExplainFreeze::
    .string "Un Pokémon congelat queda\n"
    .string "totalment immòbil.\p"
    .string "Segueix congelat fins i tot\n"
    .string "després del combat.\p"
    .string "Usa Antigel per descongelar\n"
    .string "el Pokémon que pateix.$"

ViridianCity_School_EventScript_ReadParalysis::
	msgbox ViridianCity_School_Text_ExplainParalysis
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_Text_ExplainParalysis::
    .string "La paràlisi redueix la Velocitat\n"
    .string "i pot impedir que el Pokémon es\l"
    .string "mogui.\p"
    .string "La paràlisi persisteix després\n"
    .string "dels combats. Usa Antiparalític.$"

ViridianCity_School_EventScript_ExitBlackboard::
	closemessage
	releaseall
	end

ViridianCity_School_EventScript_PokemonJournal::
	lock
	msgbox PokemonJournal_Text_SpecialFeatureProfOak
	release
	end

PokemonJournal_Text_SpecialFeatureProfOak::
	.string "Diari Pokémon\p"
	.string "Reportatge especial: Prof. Oak,\n"
	.string "l'Investigador Pokémon!\p"
	.string "Segons diuen, el Prof. Oak viu\n"
	.string "amb els seus néts Daisy i {RIVAL}.$"

ViridianCity_School_EventScript_PokemonJournal2::
	lock
	msgbox PokemonJournal_Text_SpecialFeatureDaisyOak
	release
	end

PokemonJournal_Text_SpecialFeatureDaisyOak::
	.string "Això és un Diari Pokémon de\n"
	.string "fa anys…\p"
	.string "Diari Pokémon\n"
	.string "Especial Concursos!\p"
	.string "La Gran Campiona del Concurs\n"
	.string "Pokémon de Primavera és la Daisy\l"
	.string "Oak de Poble Palette!$"

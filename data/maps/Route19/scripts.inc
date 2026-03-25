.set LOCALID_FUGITIVE, 13

Route19_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route19_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route19_OnResume
	.byte 0

Route19_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route19_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route19_EventScript_RouteSign::
	msgbox Route19_Text_RouteSign, MSGBOX_SIGN
	end

Route19_Text_RouteSign::
    .string "Ruta Marítima 19\n"
    .string "Fuchsia City - Illes Seafoam$"

Route19_EventScript_Richie::
	trainerbattle_single REMATCHABLE_TRAINER_TUBER_RICHIE_1, Route19_Text_RichieIntro, Route19_Text_RichieDefeat, Route19_EventScript_RegisterRichieAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route19_EventScript_RichieRematch
	msgbox Route19_Text_RichiePostBattle, MSGBOX_DEFAULT
	release
	end

Route19_Text_RichieIntro::
    .string "He d'escalfar abans de sortir\n"
    .string "a nedar.$"

Route19_Text_RichieDefeat::
    .string "Ja estic escalfat!$"

Route19_Text_RichiePostBattle::
    .string "Gràcies!\n"
    .string "Ja estic a punt per nedar.$"

Route19_EventScript_RegisterRichieAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route19_Text_RichieRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_TUBER_RICHIE_1
	release
	end

Route19_Text_RichieRegister:
	.string "M'encanta anar a la platja!\n"
	.string "Et trucaré sempre que hi sigui!$"

Route19_EventScript_RichieRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_TUBER_RICHIE_1, Route19_Text_RichieRematchIntro, Route19_Text_RichieDefeat
	msgbox Route19_Text_RichieRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_RichieRematchIntro::
	.string "Sí! Dia de platja!\n"
	.string "Escalfem per nedar!$"

Route19_Text_RichieRematchPostBattle::
	.string "He dinat molt abans de venir,\n"
	.string "així que encara no puc banyar-me.$"

Route19_EventScript_Lizzie::
	trainerbattle_single TRAINER_TUBER_LIZZIE, Route19_Text_LizzieIntro, Route19_Text_LizzieDefeat
	msgbox Route19_Text_LizziePostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_LizzieIntro::
    .string "Espera! Vés a poc a poc!\n"
    .string "Et donarà un infart!$"

Route19_Text_LizzieDefeat::
    .string "Uuh!\n"
    .string "Quina fredor!$"

Route19_Text_LizziePostBattle::
    .string "Vigila amb els Tentacool.\n"
    .string "Piquen molt!$"

Route19_EventScript_Matthew::
	trainerbattle_single TRAINER_SWIMMER_MALE_MATTHEW, Route19_Text_MatthewIntro, Route19_Text_MatthewDefeat
	msgbox Route19_Text_MatthewPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_MatthewIntro::
    .string "M'encanta nedar!\n"
    .string "I a tu?$"

Route19_Text_MatthewDefeat::
    .string "Panxada!$"

Route19_Text_MatthewPostBattle::
    .string "Puc guanyar fins i tot Pokémon\n"
    .string "marins nedant.$"

Route19_EventScript_Douglas::
	trainerbattle_single TRAINER_SWIMMER_MALE_DOUGLAS, Route19_Text_DouglasIntro, Route19_Text_DouglasDefeat
	msgbox Route19_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_DouglasIntro::
    .string "Què hi ha més enllà de l'horitzó?$"

Route19_Text_DouglasDefeat::
    .string "Glub!$"

Route19_Text_DouglasPostBattle::
    .string "Veig un parell d'illes\n"
    .string "allà lluny!$"

Route19_EventScript_David::
	trainerbattle_single TRAINER_SWIMMER_MALE_DAVID, Route19_Text_DavidIntro, Route19_Text_DavidDefeat
	msgbox Route19_Text_DavidPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_DavidIntro::
    .string "He provat de bussejar per trobar\n"
    .string "Pokémon, però no ha pogut ser.$"

Route19_Text_DavidDefeat::
    .string "Socors!$"

Route19_Text_DavidPostBattle::
    .string "Suposo que has de pescar per\n"
    .string "trobar Pokémon de mar.$"

Route19_EventScript_Tony::
	trainerbattle_single TRAINER_SWIMMER_MALE_TONY, Route19_Text_TonyIntro, Route19_Text_TonyDefeat
	msgbox Route19_Text_TonyPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_TonyIntro::
    .string "Miro el mar per oblidar totes\n"
    .string "les coses dolentes.$"

Route19_Text_TonyDefeat::
    .string "Uuh!\n"
    .string "Traumàtic!$"

Route19_Text_TonyPostBattle::
    .string "Estic mirant el mar per oblidar\n"
    .string "la cosa dolenta que ha passat!$"

Route19_EventScript_Axle::
	trainerbattle_single TRAINER_SWIMMER_MALE_AXLE, Route19_Text_AxleIntro, Route19_Text_AxleDefeat
	msgbox Route19_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_AxleIntro::
    .string "Ei!\n"
    .string "Aquestes aigües són perilloses!$"

Route19_Text_AxleDefeat::
    .string "Uuh!\n"
    .string "Perillós!$"

Route19_Text_AxlePostBattle::
    .string "L-les cames! Se m'han\n"
    .string "enrampar! Glub, glub…$"

Route19_EventScript_Anya::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_ANYA, Route19_Text_AnyaIntro, Route19_Text_AnyaDefeat
	msgbox Route19_Text_AnyaPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_AnyaIntro::
    .string "Oh, m'encanta el teu vehicle!\n"
    .string "Me'l puc quedar si guanyo?$"

Route19_Text_AnyaDefeat::
    .string "Oh! He perdut!$"

Route19_Text_AnyaPostBattle::
    .string "Encara queda molt per arribar\n"
    .string "a les Illes Seafoam…\p"
    .string "Vull tornar a Fuchsia…$"

Route19_EventScript_Alice::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_ALICE, Route19_Text_AliceIntro, Route19_Text_AliceDefeat
	msgbox Route19_Text_AlicePostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_AliceIntro::
    .string "Nedar és genial!\n"
    .string "Les cremades de sol no!$"

Route19_Text_AliceDefeat::
    .string "Quina sorpresa!$"

Route19_Text_AlicePostBattle::
    .string "El meu xicot volia nedar fins\n"
    .string "a les Illes Seafoam.$"

Route19_EventScript_Connie::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_CONNIE, Route19_Text_ConnieIntro, Route19_Text_ConnieDefeat
	msgbox Route19_Text_ConniePostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_ConnieIntro::
    .string "He vingut nedant amb les amigues…\n"
    .string "Estic cansada…$"

Route19_Text_ConnieDefeat::
    .string "Estic esgotada…$"

Route19_Text_ConniePostBattle::
    .string "Si pogués anar sobre un Pokémon\n"
    .string "al mar, voldria un Lapras.\p"
    .string "Lapras és tan gran que segur\n"
    .string "que em mantindria seca.$"

Route19_EventScript_Lia::
	trainerbattle_double TRAINER_SIS_AND_BRO_LIA_LUC, Route19_Text_LiaIntro, Route19_Text_LiaDefeat, Route19_Text_LiaNotEnoughMons
	msgbox Route19_Text_LiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_LiaIntro::
    .string "Lia: Vigilo el meu germà.\n"
    .string "Acaba de ser Entrenador.$"

Route19_Text_LiaDefeat::
    .string "Lia: Així no es tracta el meu\n"
    .string "germanet!$"

Route19_Text_LiaPostBattle::
    .string "Lia: Tens un germà petit?\p"
    .string "Espero que li ensenyis\n"
    .string "moltes coses.$"

Route19_Text_LiaNotEnoughMons::
    .string "Lia: Vull combatre junt amb\n"
    .string "el meu germanet.\p"
    .string "No tens dos Pokémon?$"

Route19_EventScript_Luc::
	trainerbattle_double TRAINER_SIS_AND_BRO_LIA_LUC, Route19_Text_LucIntro, Route19_Text_LucDefeat, Route19_Text_LucNotEnoughMons
	msgbox Route19_Text_LucPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_LucIntro::
    .string "Luc: La meva germana gran\n"
    .string "m'ha ensenyat a nedar i a\l"
    .string "entrenar Pokémon.$"

Route19_Text_LucDefeat::
    .string "Luc: Uau!\n"
    .string "Algú més fort que la germana!$"

Route19_Text_LucPostBattle::
    .string "Luc: La meva germana és forta\n"
    .string "i amable. És genial!$"

Route19_Text_LucNotEnoughMons::
    .string "Luc: No vull si no puc combatre\n"
    .string "amb la meva germana.\p"
    .string "No tens dos Pokémon?$"

Route19_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end


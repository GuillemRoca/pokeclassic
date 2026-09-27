Route17_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route17_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route17_OnResume
	.byte 0

Route17_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route17_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route17_EventScript_ItemsNotice::
	msgbox Route17_Text_WatchOutForDiscardedItems, MSGBOX_SIGN
	end

Route17_Text_WatchOutForDiscardedItems::
    .string "És un avís.\p"
    .string "Compte amb els objectes abandonats.$"

Route17_EventScript_TrainerTips1::
	msgbox Route17_Text_SameSpeciesGrowDifferentRates, MSGBOX_SIGN
	end

Route17_Text_SameSpeciesGrowDifferentRates::
    .string "Consells d'Entrenador:\p"
    .string "Tots els Pokémon són únics.\p"
    .string "Fins i tot Pokémon de la mateixa\n"
    .string "espècie i nivell creixen a\l"
    .string "ritmes diferents.$"

Route17_EventScript_TrainerTips2::
	msgbox Route17_Text_PressBToStayInPlace, MSGBOX_SIGN
	end

Route17_Text_PressBToStayInPlace::
    .string "Consells d'Entrenador:\p"
    .string "Prem el botó B per quedar-te\n"
    .string "quiet en un pendent.$"

Route17_EventScript_RouteSign::
	msgbox Route17_Text_RouteSign, MSGBOX_SIGN
	end

Route17_Text_RouteSign::
    .string "Ruta 17\n"
    .string "Ciutat Celadó - Ciutat Fúcsia$"

Route17_EventScript_BallsNotice::
	msgbox Route17_Text_DontThrowGameThrowBalls, MSGBOX_SIGN
	end

Route17_Text_DontThrowGameThrowBalls::
    .string "És un avís!\p"
    .string "No llencis la partida, llança\n"
    .string "Poké Balls!$"

Route17_EventScript_CyclingRoadSign::
	msgbox Route17_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route17_Text_CyclingRoadSign::
    .string "Carril Bici\n"
    .string "El pendent acaba aquí!$"

Route17_EventScript_Billy::
	trainerbattle_single TRAINER_BIKER_BILLY, Route17_Text_BillyIntro, Route17_Text_BillyDefeat
	msgbox Route17_Text_BillyPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_BillyIntro::
    .string "Som Motoristes!\n"
    .string "Les carreteres són nostres, tio!$"

Route17_Text_BillyDefeat::
    .string "Liquidat!$"

Route17_Text_BillyPostBattle::
    .string "Busques aventura?$"

Route17_EventScript_Nikolas::
	trainerbattle_single TRAINER_BIKER_NIKOLAS, Route17_Text_NikolasIntro, Route17_Text_NikolasDefeat
	msgbox Route17_Text_NikolasPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_NikolasIntro::
    .string "Deixa que Voltorb t'electrifiqui!$"

Route17_Text_NikolasDefeat::
    .string "Curtcircuit!$"

Route17_Text_NikolasPostBattle::
    .string "Vaig aconseguir el meu Voltorb\n"
    .string "a la Central Elèctrica abandonada.$"

Route17_EventScript_Jaxon::
	trainerbattle_single TRAINER_BIKER_JAXON, Route17_Text_JaxonIntro, Route17_Text_JaxonDefeat
	msgbox Route17_Text_JaxonPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_JaxonIntro::
    .string "Bona BICI!\n"
    .string "Què tal es condueix?$"

Route17_Text_JaxonDefeat::
    .string "Renoi!$"

Route17_Text_JaxonPostBattle::
    .string "Amb el pendent costa molt girar.$"

Route17_EventScript_William::
	trainerbattle_single TRAINER_BIKER_WILLIAM, Route17_Text_WilliamIntro, Route17_Text_WilliamDefeat
	msgbox Route17_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_WilliamIntro::
    .string "Fes-te perdedís, {MASC}nano{FEM}nena{ENDG}!\n"
    .string "Estic rebentat!$"

Route17_Text_WilliamDefeat::
    .string "Estàs {MASC}content{FEM}contenta{ENDG}?$"

Route17_Text_WilliamPostBattle::
    .string "Necessito fer una becaina!$"

Route17_EventScript_Raul::
	trainerbattle_single TRAINER_CUE_BALL_RAUL, Route17_Text_RaulIntro, Route17_Text_RaulDefeat
	msgbox Route17_Text_RaulPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_RaulIntro::
    .string "No et fas ric ràpid combatent\n"
    .string "nanos.$"

Route17_Text_RaulDefeat::
    .string "Cremat!$"

Route17_Text_RaulPostBattle::
    .string "Pots trobar coses bones pel\n"
    .string "Carril Bici.\p"
    .string "Es poden fer bons diners\n"
    .string "recollint-les i venent-les.$"

Route17_EventScript_Isaiah::
	trainerbattle_single TRAINER_CUE_BALL_ISAIAH, Route17_Text_IsaiahIntro, Route17_Text_IsaiahDefeat
	msgbox Route17_Text_IsaiahPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_IsaiahIntro::
    .string "Estic molt orgullós del meu cos.\n"
    .string "Vine, {MASC}nano{FEM}nena{ENDG}!$"

Route17_Text_IsaiahDefeat::
    .string "Uau!$"

Route17_Text_IsaiahPostBattle::
    .string "Et podria treure d'aquí a\n"
    .string "panxades!$"

Route17_EventScript_Zeek::
	trainerbattle_single TRAINER_CUE_BALL_ZEEK, Route17_Text_ZeekIntro, Route17_Text_ZeekDefeat
	msgbox Route17_Text_ZeekPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_ZeekIntro::
    .string "He fet pujar de nivell el Pokémon,\n"
    .string "però no evoluciona. Per què?$"

Route17_Text_ZeekDefeat::
    .string "Eh, tu!$"

Route17_Text_ZeekPostBattle::
    .string "Potser alguns Pokémon necessiten\n"
    .string "pedres elementals per evolucionar.$"

Route17_EventScript_Jamal::
	trainerbattle_single TRAINER_CUE_BALL_JAMAL, Route17_Text_JamalIntro, Route17_Text_JamalDefeat
	msgbox Route17_Text_JamalPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_JamalIntro::
    .string "Necessito una mica d'exercici!$"

Route17_Text_JamalDefeat::
    .string "Buf!\n"
    .string "Bon entrenament!$"

Route17_Text_JamalPostBattle::
    .string "Segur que he perdut pes!$"

Route17_EventScript_Corey::
	trainerbattle_single TRAINER_CUE_BALL_COREY, Route17_Text_CoreyIntro, Route17_Text_CoreyDefeat
	msgbox Route17_Text_CoreyPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_CoreyIntro::
    .string "Sigues {MASC}un rebel{FEM}una rebel{ENDG}!$"

Route17_Text_CoreyDefeat::
    .string "Aaaargh!$"

Route17_Text_CoreyPostBattle::
    .string "Estigues {MASC}preparat{FEM}preparada{ENDG} per lluitar\n"
    .string "per les teves idees!$"

Route17_EventScript_Virgil::
	trainerbattle_single TRAINER_BIKER_VIRGIL, Route17_Text_VirgilIntro, Route17_Text_VirgilDefeat
	msgbox Route17_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_VirgilIntro::
    .string "Vas cap a Ciutat Fúcsia?$"

Route17_Text_VirgilDefeat::
    .string "Patacada!$"

Route17_Text_VirgilPostBattle::
    .string "M'encanta baixar a tota velocitat!$"


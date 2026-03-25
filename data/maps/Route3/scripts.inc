Route3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route3_OnResume
	.byte 0

Route3_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route3_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route3_EventScript_Youngster::
	msgbox Route3_Text_TunnelFromCeruleanTiring, MSGBOX_NPC
	end

Route3_Text_TunnelFromCeruleanTiring::
    .string "Buf… Millor que descansi…\n"
    .string "Ai…\p"
    .string "Aquell túnel des de Cerulean\n"
    .string "et deixa fet pols!$"

Route3_EventScript_RouteSign::
	msgbox Route3_Text_RouteSign, MSGBOX_SIGN
	end

Route3_Text_RouteSign::
    .string "Ruta 3\n"
    .string "Mt. Moon al davant$"

Route3_EventScript_Janice::
	trainerbattle_single REMATCHABLE_TRAINER_LASS_JANICE_1, Route3_Text_JaniceIntro, Route3_Text_JaniceDefeat, Route3_EventScript_RegisterJaniceAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route3_EventScript_JaniceRematch
	msgbox Route3_Text_JanicePostBattle, MSGBOX_DEFAULT
	release
	end

Route3_Text_JaniceIntro::
    .string "Perdona!\n"
    .string "M'has mirat, oi?$"

Route3_Text_JaniceDefeat::
    .string "Ets dolent!$"

Route3_Text_JanicePostBattle::
    .string "No hauríes de mirar si no vols\n"
    .string "combatre!$"

Route3_EventScript_RegisterJaniceAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route3_Text_JaniceRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_LASS_JANICE_1
	release
	end

Route3_Text_JaniceRegister:
	.string "Odio perdre!\n"
	.string "Fem la revenja algun dia.$"

Route3_EventScript_JaniceRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_LASS_JANICE_1, Route3_Text_JaniceRematchIntro, Route3_Text_JaniceDefeat
	msgbox Route3_Text_JaniceRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_JaniceRematchIntro::
	.string "Perdona!\n"
	.string "No pares de mirar-me, oi?$"

Route3_Text_JaniceRematchPostBattle::
	.string "Odio els entrenadors dolents com tu!\n"
	.string "Algun dia t'ensenyaré!$"


Route3_EventScript_Colton::
	trainerbattle_single TRAINER_BUG_CATCHER_COLTON, Route3_Text_ColtonIntro, Route3_Text_ColtonDefeat
	msgbox Route3_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_ColtonIntro::
    .string "Ei! Has combatut el meu amic al\n"
    .string "Bosc Viridian!$"

Route3_Text_ColtonDefeat::
    .string "A mi també m'has guanyat!$"

Route3_Text_ColtonPostBattle::
    .string "Hi ha altres tipus de Pokémon\n"
    .string "a part dels que trobes als boscos.$"

Route3_EventScript_Ben::
	trainerbattle_single REMATCHABLE_TRAINER_YOUNGSTER_BEN_1, Route3_Text_BenIntro, Route3_Text_BenDefeat, Route3_EventScript_RegisterBenAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route3_EventScript_BenRematch
	msgbox Route3_Text_BenPostBattle, MSGBOX_DEFAULT
	release
	end

Route3_Text_BenIntro::
    .string "Hola!\n"
    .string "M'agraden els pantalons curts!\p"
    .string "Són deliciosament còmodes i\n"
    .string "fàcils de portar!$"

Route3_Text_BenDefeat::
    .string "No m'ho puc creure!$"

Route3_Text_BenPostBattle::
    .string "Fas servir el PC del Centre\n"
    .string "Pokémon per guardar Pokémon?\p"
    .string "Cada Caixa pot contenir fins a\n"
    .string "30 Pokémon.$"

Route3_EventScript_RegisterBenAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route3_Text_BenRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_YOUNGSTER_BEN_1
	release
	end

Route3_Text_BenRegister:
	.string "Sembles un entrenador que\n"
	.string "m'entén. Siguem amics!$"

Route3_EventScript_BenRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_YOUNGSTER_BEN_1, Route3_Text_BenRematchIntro, Route3_Text_BenDefeat
	msgbox Route3_Text_BenRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_BenRematchIntro::
	.string "Ei!\n"
	.string "Has provat de portar pantalons curts?$"

Route3_Text_BenRematchPostBattle::
	.string "Has de provar-ho!\n"
	.string "Et canviarà la vida!$"

Route3_EventScript_Greg::
	trainerbattle_single TRAINER_BUG_CATCHER_GREG, Route3_Text_GregIntro, Route3_Text_GregDefeat
	msgbox Route3_Text_GregPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_GregIntro::
    .string "Ets entrenador?\n"
    .string "Comencem de seguida!$"

Route3_Text_GregDefeat::
    .string "Si tingués Pokémon nous, hauria\n"
    .string "guanyat!$"

Route3_Text_GregPostBattle::
    .string "Si una Caixa al PC s'omple,\n"
    .string "simplement canvia a una altra.$"

Route3_EventScript_Calvin::
	trainerbattle_single TRAINER_YOUNGSTER_CALVIN, Route3_Text_CalvinIntro, Route3_Text_CalvinDefeat
	msgbox Route3_Text_CalvinPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_CalvinIntro::
    .string "Ei! No portes pantalons curts!\n"
    .string "Què et passa?$"

Route3_Text_CalvinDefeat::
    .string "He perdut!\n"
    .string "Perdut! Perdut!$"

Route3_Text_CalvinPostBattle::
    .string "Sempre porto pantalons curts,\n"
    .string "fins i tot a l'hivern. És la\l"
    .string "meva filosofia.$"

Route3_EventScript_Sally::
	trainerbattle_single TRAINER_LASS_SALLY, Route3_Text_SallyIntro, Route3_Text_SallyDefeat
	msgbox Route3_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_SallyIntro::
    .string "Aquella mirada que m'has fet…\n"
    .string "Què intrigant!$"

Route3_Text_SallyDefeat::
    .string "Sigues amable!$"

Route3_Text_SallyPostBattle::
    .string "Pots evitar combats si no deixes\n"
    .string "que els entrenadors et vegin.$"

Route3_EventScript_James::
	trainerbattle_single TRAINER_BUG_CATCHER_JAMES, Route3_Text_JamesIntro, Route3_Text_JamesDefeat
	msgbox Route3_Text_JamesPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_JamesIntro::
    .string "Combatré amb els Pokémon que\n"
    .string "acabo d'atrapar.$"

Route3_Text_JamesDefeat::
    .string "Destrossat!$"

Route3_Text_JamesPostBattle::
    .string "Els Pokémon entrenats són més\n"
    .string "forts que els salvatges.$"

Route3_EventScript_Robin::
	trainerbattle_single TRAINER_LASS_ROBIN, Route3_Text_RobinIntro, Route3_Text_RobinDefeat
	msgbox Route3_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_RobinIntro::
    .string "Iii!\n"
    .string "M'has tocat?$"

Route3_Text_RobinDefeat::
    .string "Ja està?$"

Route3_Text_RobinPostBattle::
    .string "La Ruta 4 és al peu de\n"
    .string "Mt. Moon.$"

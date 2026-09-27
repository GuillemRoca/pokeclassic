@Pokemon League Services

PkmnLeague_Services_RankSign::
	msgbox PkmnLeague_Services_Text_RankingsBoard, MSGBOX_SIGN
	release
	end

PkmnLeague_Services_Text_RankingsBoard::
	.string "Lliga Pokémon - Tauler de Rangs$"

PkmnLeague_Services_RankBoard::
	msgbox PkmnLeague_Services_Text_RankBoard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_End
	playse SE_PC_LOGIN
	waitse
	message PkmnLeague_Services_Text_Searching
	waitmessage
	playse SE_RG_HELP_OPEN
	waitse
	goto_if_set FLAG_SYS_GAME_CLEAR, PkmnLeague_Services_Ranking_Champion
	call PkmnLeague_Services_CalculateBadges
	goto_if_eq  VAR_TEMP_1, 8, PkmnLeague_Services_Ranking_Elite
	goto_if_ge  VAR_TEMP_1, 6, PkmnLeague_Services_Ranking_Veteran
	goto_if_ge  VAR_TEMP_1, 3, PkmnLeague_Services_Ranking_Seasoned
	goto_if_ge  VAR_TEMP_1, 1, PkmnLeague_Services_Ranking_Beginner
	goto PkmnLeague_Services_Ranking_Unranked
	end

PkmnLeague_Services_CalculateBadges::
	setvar VAR_TEMP_1, 0
	call_if_set FLAG_BADGE01_GET, PkmnLeague_Services_AddBadgeToVar
	call_if_set FLAG_BADGE02_GET, PkmnLeague_Services_AddBadgeToVar
	call_if_set FLAG_BADGE03_GET, PkmnLeague_Services_AddBadgeToVar
	call_if_set FLAG_BADGE04_GET, PkmnLeague_Services_AddBadgeToVar
	call_if_set FLAG_BADGE05_GET, PkmnLeague_Services_AddBadgeToVar
	call_if_set FLAG_BADGE06_GET, PkmnLeague_Services_AddBadgeToVar
	call_if_set FLAG_BADGE07_GET, PkmnLeague_Services_AddBadgeToVar
	call_if_set FLAG_BADGE08_GET, PkmnLeague_Services_AddBadgeToVar
	return

PkmnLeague_Services_AddBadgeToVar:
	addvar VAR_TEMP_1, 1
	return

PkmnLeague_Services_Text_RankBoard:
	.string "Són els rangs de la Lliga Pokémon.\p"
	.string "Vols consultar el teu rang actual?$"

PkmnLeague_Services_Ranking_Unranked::
	msgbox PkmnLeague_Services_Ranking_Text_Unranked, MSGBOX_DEFAULT
	release
	end

PkmnLeague_Services_Ranking_Text_Unranked:
	.string "Actualment no tens rang!\p"
	.string "Necessites almenys 1\n"
	.string "Medalla per obtenir un rang.$"

PkmnLeague_Services_Ranking_Beginner::
	msgbox PkmnLeague_Services_Ranking_Text_Beginner, MSGBOX_DEFAULT
	release
	end

PkmnLeague_Services_Ranking_Text_Beginner:
	.string "El teu rang actual és:\n"
	.string "Principiant!$"

PkmnLeague_Services_Ranking_Seasoned::
	msgbox PkmnLeague_Services_Ranking_Text_Seasoned, MSGBOX_DEFAULT
	release
	end

PkmnLeague_Services_Ranking_Text_Seasoned:
	.string "El teu rang actual és:\p"
	.string "Experimentat!$"

PkmnLeague_Services_Ranking_Veteran::
	msgbox PkmnLeague_Services_Ranking_Text_Veteran, MSGBOX_DEFAULT
	release
	end

PkmnLeague_Services_Ranking_Text_Veteran:
	.string "El teu rang actual és:\p"
	.string "Veterà!$"

PkmnLeague_Services_Ranking_Elite::
	msgbox PkmnLeague_Services_Ranking_Text_Elite, MSGBOX_DEFAULT
	release
	end

PkmnLeague_Services_Ranking_Text_Elite:
	.string "El teu rang actual és:\p"
	.string "Èlit!$"

PkmnLeague_Services_Ranking_Champion::
	msgbox PkmnLeague_Services_Ranking_Text_Champion, MSGBOX_DEFAULT
	goto_if_unset FLAG_DAILY_TITLE_MATCH, PkmnLeague_Services_Ranking_TitleMatch
	release
	end

PkmnLeague_Services_Ranking_Text_Champion:
	.string "El teu rang actual és:\p"
	.string "Campió!$"

PkmnLeague_Services_Text_Searching:
	.string "Buscant a la base de dades....\p"
	.string "..........\p"
	.string "Entrenador trobat....\p"
	.string "{PLAYER} de Poble Paleta.$"

PkmnLeague_Services_Ranking_TitleMatch::
	msgbox PkmnLeague_Services_Ranking_Text_TitleMatch, MSGBOX_DEFAULT
	release
	end

PkmnLeague_Services_Ranking_Text_TitleMatch:
	.string "Algú desafia el teu estatus de\n"
	.string "campió!\p"
	.string "Visita la Lliga Pokémon per enfrontar\n"
	.string "el teu rival en un Combat pel Títol!$"

@BADGE CHECKS
PkmnLeague_Services_MustBeBeginner::
	msgbox PkmnLeague_Services_Text_MustBeBeginner, MSGBOX_DEFAULT
	release
	end

PkmnLeague_Services_Text_MustBeBeginner:
	.string "Ho sento, però necessites ser com\n"
	.string "a mínim de Rang Principiant a la\l"
	.string "Lliga Pokémon per usar els serveis.$"

PkmnLeague_Services_MustBeSeasoned::
	msgbox PkmnLeague_Services_Text_MustBeSeasoned, MSGBOX_DEFAULT
	release
	end

PkmnLeague_Services_Text_MustBeSeasoned:
	.string "Ho sento, però necessites ser un\n"
	.string "Entrenador Experimentat a la Lliga\l"
	.string "Pokémon per usar els meus serveis.$"

PkmnLeague_Services_MustBeElite::
	msgbox PkmnLeague_Services_Text_MustBeElite, MSGBOX_DEFAULT
	release
	end

PkmnLeague_Services_Text_MustBeElite:
	.string "Ep, para el carro, nen!\p"
	.string "Jo només treballo amb els\n"
	.string "Entrenadors d'Èlit.\p"
	.string "Torna a veure'm quan tinguis\n"
	.string "unes quantes medalles més.$"

PkmnLeague_Services_MoveDeleter::
	lockall
	call PkmnLeague_Services_CalculateBadges
	goto_if_lt VAR_TEMP_1, 3, PkmnLeague_Services_MustBeSeasoned
	msgbox PkmnLeague_Services_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PkmnLeague_Services_ComeAgain
	goto PkmnLeague_Services_ChooseMonAndMoveToForget
	end

PkmnLeague_Services_ChooseMonAndMoveToForget::
	msgbox PkmnLeague_Services_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PkmnLeague_Services_ComeAgain
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, PkmnLeague_Services_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, PkmnLeague_Services_MonOnlyKnowsOneMove
	msgbox PkmnLeague_Services_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, PkmnLeague_Services_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox PkmnLeague_Services_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PkmnLeague_Services_ComeAgain
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, PkmnLeague_Services_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox PkmnLeague_Services_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

PkmnLeague_Services_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox PkmnLeague_Services_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

PkmnLeague_Services_EggCantForgetMoves::
	msgbox PkmnLeague_Services_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

PkmnLeague_Services_ComeAgain::
	msgbox PkmnLeague_Services_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

PkmnLeague_Services_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox PkmnLeague_Services_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

PkmnLeague_Services_Text_ICanMakeMonForgetMove:
	.string "Eh… Oh, sí!\n"
	.string "Sóc alumne de l'Oblidador.\p"
	.string "Puc fer que els Pokémon oblidin\n"
	.string "els seus moviments.\p"
	.string "Vols que ho faci?$"

PkmnLeague_Services_Text_WhichMonShouldForget:
	.string "Quin Pokémon ha d'oblidar un moviment?$"

PkmnLeague_Services_Text_WhichMoveShouldBeForgotten:
	.string "Quin moviment s'ha d'oblidar?$"

PkmnLeague_Services_Text_MonOnlyKnowsOneMove:
	.string "{STR_VAR_1} només sap un moviment,\n"
	.string "així que no es pot oblidar…$"

PkmnLeague_Services_Text_MonsMoveShouldBeForgotten:
	.string "Hm! {STR_VAR_2} de {STR_VAR_1}?\n"
	.string "Vols oblidar aquest moviment?$"

PkmnLeague_Services_Text_MonHasForgottenMove:
	.string "Ha funcionat a la perfecció!\p"
	.string "{STR_VAR_1} ha oblidat\n"
	.string "{STR_VAR_2} completament.$"

PkmnLeague_Services_Text_ComeAgain:
	.string "Torna si hi ha moviments que\n"
	.string "s'hagin d'oblidar.$"

PkmnLeague_Services_Text_EggCantForgetMoves:
	.string "Què?\n"
	.string "Cap Ou hauria de saber moviments.$"

PkmnLeague_Services_Text_CantForgetSurf:
	.string "Hm!\p"
	.string "El teu {STR_VAR_1} no sembla disposat\n"
	.string "a oblidar Surf.$"

PkmnLeague_Services_EventScript_MoveRelearner::
	lockall
	call PkmnLeague_Services_CalculateBadges
	goto_if_eq VAR_TEMP_1, 0, PkmnLeague_Services_MustBeBeginner
	goto_if_set FLAG_TEMP_1, PkmnLeague_Services_EventScript_AskTeachMove
	msgbox PkmnLeague_Services_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto PkmnLeague_Services_EventScript_AskTeachMove
	end

PkmnLeague_Services_EventScript_AskTeachMove::
	msgbox PkmnLeague_Services_Text_WantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, Common_EventScript_End
	goto PkmnLeague_Services_EventScript_ChooseMon
	end

PkmnLeague_Services_EventScript_ChooseMon::
	msgbox PkmnLeague_Services_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Common_EventScript_End
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, PkmnLeague_Services_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, PkmnLeague_Services_EventScript_NoMoveToTeachMon
	goto PkmnLeague_Services_EventScript_ChooseMove
	end

PkmnLeague_Services_EventScript_ChooseMove::
	msgbox PkmnLeague_Services_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, PkmnLeague_Services_EventScript_ChooseMon
	releaseall
	end

PkmnLeague_Services_EventScript_NoMoveToTeachMon::
	msgbox PkmnLeague_Services_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto PkmnLeague_Services_EventScript_ChooseMon
	end

PkmnLeague_Services_EventScript_CantTeachEgg::
	msgbox PkmnLeague_Services_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto PkmnLeague_Services_EventScript_ChooseMon
	end

PkmnLeague_Services_Text_ImTheMoveTutor:
	.string "Sóc un Tutor de Moviments.\p"
	.string "Conec tots els moviments que els\n"
	.string "Pokémon aprenen, tots ells, i puc\l"
	.string "ensenyar-los-hi.\p"
	.string "Puc ensenyar un moviment a un\n"
	.string "dels teus Pokémon si vols.$"

PkmnLeague_Services_Text_TutorWhichMon:
	.string "Quin Pokémon necessita tutoria?$"

PkmnLeague_Services_Text_WantMeToTeachMove:
	.string "Vols que ensenyi un Pokémon?$"

PkmnLeague_Services_Text_TeachWhichMove:
	.string "Quin moviment he d'ensenyar?$"

PkmnLeague_Services_Text_DontHaveMoveToTeachPokemon:
	.string "Ho sento…\p"
	.string "Sembla que no tinc cap moviment\n"
	.string "que pugui ensenyar a aquest Pokémon.$"

PkmnLeague_Services_Text_CantTeachEgg:
	.string "Eh? No hi ha cap moviment que\n"
	.string "pugui ensenyar a un Ou.$"


PkmnLeague_Services_EliteShop::
	lockall
	call PkmnLeague_Services_CalculateBadges
	goto_if_lt VAR_TEMP_1, 8, PkmnLeague_Services_MustBeElite
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, PkmnLeague_Services_EliteShop_PostGameShop
	goto PkmnLeague_Services_EliteShop_Elite
	end

PkmnLeague_Services_EliteShop_PostGameShop::
	pokemart PkmnLeague_Services_Mart_EliteShop_Postgame
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PkmnLeague_Services_EliteShop_Elite::
	pokemart PkmnLeague_Services_Mart_EliteShop_Elite
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PkmnLeague_Services_Mart_EliteShop_Elite:
	.2byte ITEM_PP_UP
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_ETHER
	.2byte ITEM_ELIXIR
	.2byte ITEM_NONE
	release
	end

	.align 2
PkmnLeague_Services_Mart_EliteShop_Postgame:
	.2byte ITEM_PP_UP
	.2byte ITEM_PP_MAX
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_MAX_ETHER
	.2byte ITEM_MAX_ELIXIR
	.2byte ITEM_NONE
	release
	end

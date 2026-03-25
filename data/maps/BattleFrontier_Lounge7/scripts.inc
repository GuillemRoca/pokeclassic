BattleFrontier_Lounge7_MapScripts::
	.byte 0

BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_E, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_E, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_E, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_E, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_D is the move selection
@ VAR_TEMP_E is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_D
	copyvar VAR_0x8005, VAR_TEMP_E
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end

BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_E, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "Buhahaha!\p"
	.string "No ho diries veient-me ara,\n"
	.string "però era una Entrenadora molt forta.\p"
	.string "Tenia reputació de ser la Bellesa\n"
	.string "més dura de totes!\p"
	.string "… … … … … …\p"
	.string "Què passa?\n"
	.string "No em creus.\p"
	.string "No sóc com la fatxenda aquella de\n"
	.string "allà. Jo tinc talent de debò!\p"
	.string "Deixa que t'ho demostri.\n"
	.string "Puc ensenyar als teus Pokémon\l"
	.string "moviments especials i bonics.\p"
	.string "Però les meves lliçons no són gratis.\n"
	.string "Què et sembla pagar amb una mica\l"
	.string "de Punts de Combat?$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "Buhahaha!\p"
	.string "Has tornat per aprendre moviments\n"
	.string "especials i bonics de Pokémon?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "Molt bé, mira aquí!\n"
	.string "Quin moviment t'ensenyo?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "El moviment {STR_VAR_1}, oi?\n"
	.string "Seran {STR_VAR_2} Punts de Combat, d'acord?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "Molt bé, ara tria el Pokémon\n"
	.string "a qui li he d'ensenyar el moviment.$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "Què…\n"
	.string "No tens prou Punts de Combat!$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "Ja veus com sóc d'hàbil?\n"
	.string "M'emporto els teus Punts de Combat!$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "Què dius?\n"
	.string "No vols…\p"
	.string "Si vols veure com sóc d'hàbil,\n"
	.string "vine a veure'm quan vulguis!$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "Ihihihi!\p"
	.string "Sé que costa veure-ho ara, però\n"
	.string "era una Entrenadora fantàstica.\p"
	.string "Tenia reputació de ser la Nedadora\n"
	.string "més invencible de totes!\p"
	.string "… … … … … …\p"
	.string "Què passa?\n"
	.string "No em creus.\p"
	.string "No sóc com la pallassa aquella de\n"
	.string "allà. Jo tinc experiència de debò!\p"
	.string "Puc demostrar-t'ho.\n"
	.string "Puc ensenyar als teus Pokémon\l"
	.string "moviments durs i bonics.\p"
	.string "Però les meves lliçons no són gratis.\n"
	.string "Què et sembla pagar amb una mica\l"
	.string "de Punts de Combat?$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "Ihihihi!\p"
	.string "Has vingut a aprendre moviments\n"
	.string "durs i bonics de Pokémon?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "Aquestes senyores, com es critiquen\n"
	.string "l'una a l'altra, deus pensar que\l"
	.string "no s'avenen.\p"
	.string "Però si fos cert, no estarien\n"
	.string "aquí juntes, oi?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "Quan era un jovenet,\n"
	.string "aquelles senyores eren fortes i belles.\p"
	.string "Eren ídols entre els Entrenadors.\p"
	.string "Fins i tot ara, l'edat no ha apagat\n"
	.string "les seves habilitats.\p"
	.string "De fet, els seus moviments Pokémon\n"
	.string "s'han polit encara més.\p"
	.string "Però… Per alguna raó, no puc evitar\n"
	.string "sentir això…\p"
	.string "El temps és tan cruel…$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "Recupera fins a\n"
	.string "la meitat dels PS\n"
	.string "màxims de l'usuari.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "Infligeix dany\n"
	.string "igual al nivell\n"
	.string "de l'usuari.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "Recupera la meitat\n"
	.string "del dany infligit a\n"
	.string "un enemic dormit.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "Un cop de puny\n"
	.string "fort amb un poder\n"
	.string "increïble.$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "Una puntada de peu\n"
	.string "extremadament\n"
	.string "poderosa.$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "Un cop de cos\n"
	.string "que pot causar\n"
	.string "paràlisi.$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string "Grans roques\n"
	.string "són llançades. Pot\n"
	.string "fer retrocedir.$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "Retorna qualsevol\n"
	.string "cop físic amb el\n"
	.string "doble de poder.$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string "Una descàrrega\n"
	.string "feble que\n"
	.string "paralitza l'enemic.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "Una dansa de\n"
	.string "combat que puja\n"
	.string "molt l'Atac.$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "S'enrotlla per\n"
	.string "amagar punts dèbils\n"
	.string "i pujar Defensa.$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "Un atac sorollós\n"
	.string "que només s'usa\n"
	.string "estant dormit.$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string "Llança fang a la\n"
	.string "cara de l'enemic\n"
	.string "per baixar precisió.$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "Raigs en forma\n"
	.string "d'estrella que\n"
	.string "mai fallen.$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "Un atac gelat\n"
	.string "que baixa la\n"
	.string "Velocitat enemiga.$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "Resisteix un atac\n"
	.string "1 torn, quedant\n"
	.string "amb 1 PS.$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "Copia els efectes\n"
	.string "de l'enemic i\n"
	.string "els dóna a l'usuari.$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "Un cop gelat\n"
	.string "que pot\n"
	.string "congelar l'enemic.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "Un cop electrificat\n"
	.string "que pot paralitzar\n"
	.string "l'enemic.$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "Un cop de foc\n"
	.string "que pot cremar\n"
	.string "l'enemic.$"

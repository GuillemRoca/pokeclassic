@KANTO, Updated

MoveTutor_DoubleEdge::
	lock
	faceplayer
	msgbox MoveTutor_Text_DoubleEdgeTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DoubleEdgeDeclined
	msgbox MoveTutor_Text_DoubleEdgeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_DOUBLE_EDGE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_DoubleEdgeDeclined
	goto MoveTutor_EventScript_DoubleEdgeTaught
	end

MoveTutor_Text_DoubleEdgeTeach::
    .string "Hauries d'estar orgullós de tu\n"
    .string "mateix, havent lluitat pel Camí\l"
    .string "de la Victòria tan valentament.\p"
    .string "En reconeixement de la teva gesta,\n"
    .string "t'ensenyaré Doble Tall.\p"
    .string "Vols que t'ensenyi aquesta\n"
    .string "tècnica?$"

MoveTutor_EventScript_DoubleEdgeDeclined::
	msgbox MoveTutor_Text_DoubleEdgeDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_DoubleEdgeDeclined::
    .string "T'ensenyaré la tècnica\n"
    .string "quan vulguis.$"

MoveTutor_Text_DoubleEdgeWhichMon::
    .string "A quin Pokémon he d'ensenyar\n"
    .string "Doble Tall?$"

MoveTutor_EventScript_DoubleEdgeTaught::
	msgbox MoveTutor_Text_DoubleEdgeTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_DoubleEdgeTaught::
    .string "Mantingues aquest impuls cap a\n"
    .string "la Lliga Pokémon!\p"
    .string "Llança't contra ells i\n"
    .string "deixa'ls KO!$"

MoveTutor_Metronome::
	lock
	faceplayer
	msgbox MoveTutor_Text_MetronomeTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MetronomeDeclined
	msgbox MoveTutor_Text_MetronomeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_METRONOME
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_MetronomeDeclined
	goto MoveTutor_EventScript_MetronomeTaught
	end

MoveTutor_Text_MetronomeTeach::
    .string "Tic-tic-tic!\n"
    .string "T'ensenyaré un moviment genial.\p"
    .string "Ensenya-li'l a un Pokémon i mira\n"
    .string "com la diversió es desplega!\p"
    .string "Es diu Metrònome.\n"
    .string "T'interessa?$"

MoveTutor_EventScript_MetronomeDeclined::
	msgbox MoveTutor_Text_MetronomeDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_MetronomeDeclined::
    .string "T'ho dic, és molt divertit!$"

MoveTutor_Text_MetronomeWhichMon::
    .string "D'acord!\n"
    .string "A quin Pokémon he d'ensenyar?$"

MoveTutor_EventScript_MetronomeTaught::
	msgbox MoveTutor_Text_MetronomeTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_MetronomeTaught::
    .string "Tic-tic-tic!\n"
    .string "Això és el so d'un Metrònome.\p"
    .string "Enganya el cervell del teu Pokémon\n"
    .string "perquè usi moviments que no sap.$"

MoveTutor_ThunderWave::
	lock
	faceplayer
	msgbox MoveTutor_Text_ThunderWaveTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_ThunderWaveDeclined
	msgbox MoveTutor_Text_ThunderWaveWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_THUNDER_WAVE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ThunderWaveDeclined
	goto MoveTutor_EventScript_ThunderWaveTaught
	end

MoveTutor_Text_ThunderWaveTeach::
    .string "Iiik!\n"
    .string "No! Para! Ajuda!\p"
    .string "Oh, no ets de l'Equip Rocket.\n"
    .string "Ho sento, pensava que…\p"
    .string "Em perdonaràs si t'ensenyo\n"
    .string "la tècnica Ona de Tro?$"

MoveTutor_EventScript_ThunderWaveDeclined::
	msgbox MoveTutor_Text_ThunderWaveDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_ThunderWaveDeclined::
    .string "Oh…\n"
    .string "Però Ona de Tro és molt útil…$"

MoveTutor_Text_ThunderWaveWhichMon::
    .string "M'encanta Ona de Tro!\n"
    .string "Qui l'aprendrà?$"

MoveTutor_EventScript_ThunderWaveTaught::
	msgbox MoveTutor_Text_ThunderWaveTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_ThunderWaveTaught::
    .string "Ona de Tro causa paràlisi al\n"
    .string "Pokémon objectiu.\p"
    .string "Un Pokémon paralitzat pot no\n"
    .string "poder-se moure en combat.\p"
    .string "És un moviment de tipus Elèctric,\n"
    .string "així que no funciona en tots.$"

MoveTutor_Mimic::
	lock
	faceplayer
	msgbox MoveTutor_Text_MimicTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MimicDeclined
	msgbox MoveTutor_Text_MimicWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_MIMIC
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_MimicDeclined
	goto MoveTutor_EventScript_MimicTaught
	end

MoveTutor_Text_MimicTeach::
    .string "Oh!\n"
    .string "Una Poké Doll!\p"
    .string "Per a mi?\n"
    .string "Gràcies!\p"
    .string "Saps què?\n"
    .string "Puc ensenyar el moviment Mímica.$"

MoveTutor_EventScript_MimicDeclined::
	msgbox MoveTutor_Text_MimicDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_MimicDeclined::
    .string "No t'agrada Mímica?$"

MoveTutor_Text_MimicWhichMon::
    .string "M'encanta Mímica!\n"
    .string "Qui l'aprendrà?$"

MoveTutor_EventScript_MimicTaught::
	msgbox MoveTutor_Text_MimicTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_MimicTaught::
    .string "{PLAYER}: Hola!\n"
    .string "Gràcies pel d'abans!\p"
    .string "{PLAYER}: Perdona?\p"
    .string "{PLAYER}: És tan divertit imitar\n"
    .string "cada moviment meu?\p"
    .string "IMITADORA: I tant!\n"
    .string "És genial!$"

MoveTutor_Substitute::
	lock
	faceplayer
	msgbox MoveTutor_Text_SubstituteTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SubstituteDeclined
	msgbox MoveTutor_Text_SubstituteWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SUBSTITUTE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SubstituteDeclined
	goto MoveTutor_EventScript_SubstituteTaught
	end

MoveTutor_Text_SubstituteTeach::
    .string "Ai, m'agradaria ser un nadó\n"
    .string "Kangaskhan.\p"
    .string "M'encantaria ser un substitut\n"
    .string "del nadó…\p"
    .string "I acotxar-me a la bossa de la panxa\n"
    .string "de la mare Kangaskhan.\p"
    .string "Però només els Pokémon poden usar\n"
    .string "la tècnica Substitut…\p"
    .string "Vols que ensenyi Substitut a\n"
    .string "un dels teus Pokémon?$"

MoveTutor_EventScript_SubstituteDeclined::
	msgbox MoveTutor_Text_SubstituteDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_SubstituteDeclined::
    .string "Oh, de veritat?\n"
    .string "Substitut sembla tan divertit…$"

MoveTutor_Text_SubstituteWhichMon::
    .string "Quin Pokémon vol aprendre\n"
    .string "Substitut?$"

MoveTutor_EventScript_SubstituteTaught::
	msgbox MoveTutor_Text_SubstituteTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_SubstituteTaught::
    .string "Noi, què no donaria per ficar-me\n"
    .string "dins la bossa de Kangaskhan…$"

MoveTutor_DreamEater::
	lock
	faceplayer
	msgbox MoveTutor_Text_DreamEaterTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DreamEaterDeclined
	msgbox MoveTutor_Text_DreamEaterWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_DREAM_EATER
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_DreamEaterDeclined
	goto MoveTutor_EventScript_DreamEaterTaught
	end

MoveTutor_Text_DreamEaterTeach::
    .string "Badall!\n"
    .string "Dec haver-me adormit al sol.\p"
    .string "He tingut un somni estrany sobre\n"
    .string "un Drowzee que em menjava el somni.\p"
    .string "I…\n"
    .string "He après a menjar somnis…\p"
    .string "Ugh, això fa massa por!\p"
    .string "Deixa que ho ensenyi a un Pokémon\n"
    .string "per poder oblidar-ho!$"

MoveTutor_EventScript_DreamEaterDeclined::
	msgbox MoveTutor_Text_DreamEaterDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_DreamEaterDeclined::
    .string "…Zzz…$"

MoveTutor_Text_DreamEaterWhichMon::
    .string "Quin Pokémon vol aprendre\n"
    .string "Menjasomnis?$"

MoveTutor_EventScript_DreamEaterTaught::
	msgbox MoveTutor_Text_DreamEaterTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_DreamEaterTaught::
    .string "…ZZZ…\n"
    .string "No…puc menjar…més…$"

MoveTutor_SeismicToss::
	lock
	faceplayer
	msgbox MoveTutor_Text_SeismicTossTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SeismicTossDeclined
	msgbox MoveTutor_Text_SeismicTossWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SEISMIC_TOSS
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SeismicTossDeclined
	goto MoveTutor_EventScript_SeismicTossTaught
	end

MoveTutor_Text_SeismicTossTeach::
    .string "Els secrets de l'espai…\n"
    .string "Els misteris de la terra…\p"
    .string "Hi ha tantes coses de les quals\n"
    .string "sabem tan poc.\p"
    .string "Però això ens hauria d'esperonar\n"
    .string "a estudiar més, no a rendir-nos.\p"
    .string "L'única cosa que hauries de llançar…\p"
    .string "Què tal Llançament Sísmic?\n"
    .string "L'he d'ensenyar a un Pokémon?$"

MoveTutor_EventScript_SeismicTossDeclined::
	msgbox MoveTutor_Text_SeismicTossDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_SeismicTossDeclined::
    .string "Ah, sí?\n"
    .string "Segur que tornaràs a buscar-lo.$"

MoveTutor_Text_SeismicTossWhichMon::
    .string "Quin Pokémon vol aprendre\n"
    .string "Llançament Sísmic?$"

MoveTutor_EventScript_SeismicTossTaught::
	msgbox MoveTutor_Text_SeismicTossTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_SeismicTossTaught::
    .string "Espero que no et rendeixis.\n"
    .string "Segueix endavant!$"

MoveTutor_MegaPunch::
	lock
	faceplayer
	msgbox MoveTutor_Text_MegaPunchTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MegaPunchDeclined
	msgbox MoveTutor_Text_MegaPunchWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_MEGA_PUNCH
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_MegaPunchDeclined
	goto MoveTutor_EventScript_MegaPunchTaught
	end

MoveTutor_Text_MegaPunchTeach::
    .string "Un cop d'una ferocitat rugent!\p"
    .string "Ple de poder destructiu!\p"
    .string "Quan la cosa es posa difícil,\n"
    .string "Megacop és l'atac definitiu!\l"
    .string "No hi estàs d'acord?\p"
    .string "Ara!\n"
    .string "Deixa que l'ensenyi al teu Pokémon!$"

MoveTutor_EventScript_MegaPunchDeclined::
	msgbox MoveTutor_Text_MegaPunchDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_MegaPunchDeclined::
    .string "Tornaràs quan entenguis\n"
    .string "el valor de Megacop.$"

MoveTutor_Text_MegaPunchWhichMon::
    .string "Molt bé!\n"
    .string "Quin Pokémon l'aprendrà?$"

MoveTutor_EventScript_MegaPunchTaught::
	msgbox MoveTutor_Text_MegaPunchTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_MegaPunchTaught::
    .string "Ara som companys en l'art del\n"
    .string "cop de puny!\p"
    .string "Hauries de marxar abans que et\n"
    .string "vegi el desorientat que només\l"
    .string "entrena la seva boja puntada.$"

MoveTutor_MegaKick::
	lock
	faceplayer
	msgbox MoveTutor_Text_MegaKickTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MegaKickDeclined
	msgbox MoveTutor_Text_MegaKickWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_MEGA_KICK
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_MegaKickDeclined
	goto MoveTutor_EventScript_MegaKickTaught
	end

MoveTutor_Text_MegaKickTeach::
    .string "Una puntada d'una ferocitat brutal!\p"
    .string "Plena de poder destructiu!\p"
    .string "Si ho mires bé,\n"
    .string "Megapuntada és l'atac definitiu!\l"
    .string "No hi estàs d'acord?\p"
    .string "D'acord!\n"
    .string "L'ensenyaré al teu Pokémon!$"

MoveTutor_EventScript_MegaKickDeclined::
	msgbox MoveTutor_Text_MegaKickDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_MegaKickDeclined::
    .string "Tornaràs arrossegant-te quan\n"
    .string "entenguis el valor de Megapuntada.$"

MoveTutor_Text_MegaKickWhichMon::
    .string "Molt bé!\n"
    .string "Quin Pokémon vol aprendre'l?$"

MoveTutor_EventScript_MegaKickTaught::
	msgbox MoveTutor_Text_MegaKickTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_MegaKickTaught::
    .string "Ara som ànimes bessones en l'art\n"
    .string "de la puntada!\p"
    .string "Hauries de fugir abans que et vegi\n"
    .string "l'il·lús que només entrena\l"
    .string "el seu simple cop de puny.$"

MoveTutor_RockSlide::
	lock
	faceplayer
	msgbox MoveTutor_Text_RockSlideTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_RockSlideDeclined
	msgbox MoveTutor_Text_RockSlideWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_ROCK_SLIDE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_RockSlideDeclined
	goto MoveTutor_EventScript_RockSlideTaught
	end

MoveTutor_Text_RockSlideTeach::
    .string "Quan ets en una muntanya rocosa\n"
    .string "com aquesta, els esllavissaments\l"
    .string "són una amenaça.\p"
    .string "T'ho pots imaginar?\n"
    .string "Roques caient-te a sobre?\p"
    .string "Seria com, uaaaaaah!\n"
    .string "Terror total!\p"
    .string "No sembles espantat.\n"
    .string "Vols provar Allau de Roques?$"

MoveTutor_EventScript_RockSlideDeclined::
	msgbox MoveTutor_Text_RockSlideDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_RockSlideDeclined::
    .string "Oh, al final sí que tens por.$"

MoveTutor_Text_RockSlideWhichMon::
    .string "A quin Pokémon he d'ensenyar\n"
    .string "Allau de Roques?$"

MoveTutor_EventScript_RockSlideTaught::
	msgbox MoveTutor_Text_RockSlideTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_RockSlideTaught::
    .string "Pot fer por fer-lo servir en\n"
    .string "aquest túnel…$"

MoveTutor_SoftBoiled::
	lock
	faceplayer
	msgbox MoveTutor_Text_SoftBoiledTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SoftBoiledDeclined
	msgbox MoveTutor_Text_SoftBoiledWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SOFT_BOILED
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SoftBoiledDeclined
	goto MoveTutor_EventScript_SoftBoiledTaught
	end

MoveTutor_Text_SoftBoiledTeach::
    .string "Hola!\p"
    .string "T'he vist per aquí, però mai\n"
    .string "he tingut l'oportunitat de parlar.\p"
    .string "Deu ser bona sort que ens hagi\n"
    .string "reunit finalment.\p"
    .string "M'agradaria celebrar-ho ensenyant-te\n"
    .string "el moviment Ou Passat per Aigua.$"

MoveTutor_EventScript_SoftBoiledDeclined::
	msgbox MoveTutor_Text_SoftBoiledDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_SoftBoiledDeclined::
    .string "Sempre estaré atenta a tu.\p"
    .string "Espero que puguem parlar de nou.$"

MoveTutor_Text_SoftBoiledWhichMon::
    .string "I qui és el Pokémon que tindrà\n"
    .string "l'oportunitat d'aprendre'l?$"

MoveTutor_EventScript_SoftBoiledTaught::
	msgbox MoveTutor_Text_SoftBoiledTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_SoftBoiledTaught::
    .string "Et desitjo la millor de les sorts!$"



MoveTutor_Counter::
    lock
    faceplayer
    msgbox MoveTutor_Text_CounterTeach, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_CounterDeclined
    msgbox MoveTutor_Text_CounterWhichMon, MSGBOX_DEFAULT
    setvar VAR_0x8005, TUTOR_MOVE_COUNTER
    call MoveTutor_EventScript_OpenPartyMenu
    goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_CounterDeclined
    goto MoveTutor_EventScript_CounterTaught
    end

MoveTutor_Text_CounterTeach::
    .string "Oh, hola!\n"
    .string "Per fi he acabat aquell RomHack!\p"
    .string "Encara no? Què et sembla si\n"
    .string "t'ensenyo un bon moviment?\p"
    .string "El moviment que tinc en ment és\n"
    .string "Contraatac.\p"
    .string "No com el taulell on m'estic\n"
    .string "recolzant, eh!$"

MoveTutor_EventScript_CounterDeclined::
    msgbox MoveTutor_Text_CounterDeclined, MSGBOX_DEFAULT
    release
    end

MoveTutor_Text_CounterDeclined::
    .string "No t'interessa? Vine a veure'm\n"
    .string "si canvies d'opinió.$"

MoveTutor_Text_CounterWhichMon::
    .string "A quin Pokémon he d'ensenyar\n"
    .string "Contraatac?$"

MoveTutor_EventScript_CounterTaught::
    msgbox MoveTutor_Text_CounterTaught, MSGBOX_DEFAULT
    release
    end

MoveTutor_Text_CounterTaught::
   .string "Estàs fent servir el Contraatac\n"
    .string "que li vaig ensenyar?$"




@OLD
SlateportCity_PokemonFanClub_EventScript_SwaggerTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_SWAGGER, MoveTutor_EventScript_SwaggerTaught
	msgbox MoveTutor_Text_SwaggerTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SwaggerDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SwaggerDeclined
	msgbox MoveTutor_Text_SwaggerWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SWAGGER
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SwaggerDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_SWAGGER
	goto MoveTutor_EventScript_SwaggerTaught
	end

MoveTutor_EventScript_SwaggerDeclined::
	msgbox MoveTutor_Text_SwaggerDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SwaggerTaught::
	msgbox MoveTutor_Text_SwaggerTaught, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RolloutTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_ROLLOUT, MoveTutor_EventScript_RolloutTaught
	msgbox MoveTutor_Text_RolloutTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_RolloutDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_RolloutDeclined
	msgbox MoveTutor_Text_RolloutWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_ROLLOUT
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_RolloutDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_ROLLOUT
	goto MoveTutor_EventScript_RolloutTaught
	end

MoveTutor_EventScript_RolloutDeclined::
	msgbox MoveTutor_Text_RolloutDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_RolloutTaught::
	msgbox MoveTutor_Text_RolloutTaught, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_FuryCutterTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_FURY_CUTTER, MoveTutor_EventScript_FuryCutterTaught
	msgbox MoveTutor_Text_FuryCutterTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_FuryCutterDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_FuryCutterDeclined
	msgbox MoveTutor_Text_FuryCutterWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_FURY_CUTTER
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_FuryCutterDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_FURY_CUTTER
	goto MoveTutor_EventScript_FuryCutterTaught
	end

MoveTutor_EventScript_FuryCutterDeclined::
	msgbox MoveTutor_Text_FuryCutterDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_FuryCutterTaught::
	msgbox MoveTutor_Text_FuryCutterTaught, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_SleepTalkTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_SLEEP_TALK, MoveTutor_EventScript_SleepTalkTaught
	msgbox MoveTutor_Text_SleepTalkTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SleepTalkDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SleepTalkDeclined
	msgbox MoveTutor_Text_SleepTalkWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SLEEP_TALK
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SleepTalkDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_SLEEP_TALK
	goto MoveTutor_EventScript_SleepTalkTaught
	end

MoveTutor_EventScript_SleepTalkDeclined::
	msgbox MoveTutor_Text_SleepTalkDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SleepTalkTaught::
	msgbox MoveTutor_Text_SleepTalkTaught, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DynamicPunchTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH, MoveTutor_EventScript_DynamicPunchTaught
	msgbox MoveTutor_Text_DynamicPunchTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DynamicPunchDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DynamicPunchDeclined
	msgbox MoveTutor_Text_DynamicPunchWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_DYNAMIC_PUNCH
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_DynamicPunchDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH
	goto MoveTutor_EventScript_DynamicPunchTaught
	end

MoveTutor_EventScript_DynamicPunchDeclined::
	msgbox MoveTutor_Text_DynamicPunchDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DynamicPunchTaught::
	msgbox MoveTutor_Text_DynamicPunchTaught, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_ExplosionTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_EXPLOSION, MoveTutor_EventScript_ExplosionTaught
	msgbox MoveTutor_Text_ExplosionTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_ExplosionDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_ExplosionDeclined
	msgbox MoveTutor_Text_ExplosionWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_EXPLOSION
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExplosionDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_EXPLOSION
	goto MoveTutor_EventScript_ExplosionTaught
	end

MoveTutor_EventScript_ExplosionDeclined::
	msgbox MoveTutor_Text_ExplosionDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_ExplosionTaught::
	msgbox MoveTutor_Text_ExplosionTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_OpenPartyMenu::
	special ChooseMonForMoveTutor
	waitstate
	lock
	faceplayer
	return

MoveTutor_EventScript_CanOnlyBeLearnedOnce::
	msgbox MoveTutor_Text_ThisMoveCanOnlyBeLearnedOnce, MSGBOX_YESNO
	return

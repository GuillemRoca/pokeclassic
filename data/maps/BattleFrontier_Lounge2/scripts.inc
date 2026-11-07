BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, 0, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, 1, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, 2, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, 3, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, 4, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, 5, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, 6, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, 7, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, 8, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, 9, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, 3, BattleFrontier_Lounge2_EventScript_BattleTowerNews
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, 4, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "Hola! Pel que fa a notícies de la\n"
	.string "Frontera de Combat, soc el número 1.\p"
	.string "Pots dir-me el Fanàtic de la Frontera.\p"
	.string "Només per assegurar-me'n: entrenes\n"
	.string "Pokémon, oi?\p"
	.string "Compartiré encantat les notícies més\n"
	.string "calentes de la Frontera de Combat.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "Hola! Has vingut a treure'm les\n"
	.string "últimes notícies? D'acord!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "I bé? I bé? I bé?\p"
	.string "Segur que la meva informació\n"
	.string "t'ha estat molt útil, oi?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "A veure…\p"
	.string "Sembla que el lloc de moda ara\n"
	.string "mateix és… {STR_VAR_1}!$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "A veure…\p"
	.string "Sembla que a la Torre de Combat, la\n"
	.string "modalitat {STR_VAR_1} és la més popular.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels Entrenadors d'elit que\n"
	.string "l'Scott anomena Cervells de la\l"
	.string "Frontera és allà.\p"
	.string "Qui porta el lloc és una Entrenadora\n"
	.string "misteriosa: la Mestra del Saló.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "Has combatut contra la Mestra del Saló?\p"
	.string "Quan avalua l'oponent,\n"
	.string "sembla que usa aquests Pokémon:\p"
	.string "Un Pokémon PSI de tipus Psíquic,\n"
	.string "un Pokémon Volcà de tipus Foc\l"
	.string "i un Pokémon Dormilega de tipus Normal.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "Has combatut contra la Mestra del Saló\n"
	.string "quan va de seriós?\p"
	.string "Quan combat a fons,\n"
	.string "sembla que usa aquests Pokémon:\p"
	.string "Un Pokémon Eó de tipus Drac/Psíquic,\n"
	.string "un Pokémon Tro de tipus Elèctric\l"
	.string "i un Pokémon Dormilega de tipus Normal.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels Entrenadors d'elit que\n"
	.string "l'Scott anomena Cervells de la\l"
	.string "Frontera és allà.\p"
	.string "Qui porta el lloc és un Entrenador\n"
	.string "extravagant: l'As del Domo.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "Has combatut contra l'As del Domo?\p"
	.string "Quan tracta l'oponent amb lleugeresa,\n"
	.string "usa aquests tres Pokémon:\p"
	.string "Un Pokémon Drac de tipus Drac/Volador,\n"
	.string "un Pokémon Peix Fang de tipus\l"
	.string "Aigua/Terra i un Pokémon Flama\l"
	.string "de tipus Foc/Volador.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "Has combatut contra l'As del Domo\n"
	.string "quan va de seriós?\p"
	.string "Quan demostra la seva estratègia,\n"
	.string "usa aquests tres Pokémon:\p"
	.string "Un Pokémon Eó de tipus Drac/Volador,\n"
	.string "un Pokémon Peix Fang de tipus\l"
	.string "Aigua/Terra i un Pokémon Cama Ferro\l"
	.string "de tipus Acer/Psíquic.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels Entrenadors d'elit que\n"
	.string "l'Scott anomena Cervells de la\l"
	.string "Frontera és allà.\p"
	.string "Qui porta el lloc és un Entrenador\n"
	.string "estrafolari: el Cap de la Fàbrica.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "Has combatut contra el Cap de la\n"
	.string "Fàbrica?\p"
	.string "Deixa'm pensar… Quan combat,\n"
	.string "agafa tres Pokémon de lloguer i prou.\p"
	.string "Combat pràcticament en les mateixes\n"
	.string "condicions que tu.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "Has combatut contra el Cap de la\n"
	.string "Fàbrica quan va de seriós?\p"
	.string "Quan combat seriosament, igualment\n"
	.string "agafa tres Pokémon de lloguer.\p"
	.string "Combat gairebé en les mateixes\n"
	.string "condicions que tu.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels Entrenadors d'elit que\n"
	.string "l'Scott anomena Cervells de la\l"
	.string "Frontera és allà.\p"
	.string "Qui porta el lloc és una Entrenadora\n"
	.string "que fa por: la Reina de la Llança.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "Has combatut contra la Reina de la\n"
	.string "Llança?\p"
	.string "Quan està de bon humor, diuen que\n"
	.string "usa aquests tres Pokémon:\p"
	.string "Un Pokémon Serp Ullal de tipus Verí,\n"
	.string "un Pokémon Motlle de tipus\l"
	.string "Insecte/Roca i un Pokémon Tendre\l"
	.string "de tipus Aigua.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "Has combatut contra la Reina de la\n"
	.string "Llança quan va de seriós?\p"
	.string "Quan està enfadada de debò, diuen\n"
	.string "que usa aquests tres Pokémon:\p"
	.string "Un Pokémon Serp Ullal de tipus Verí,\n"
	.string "un Pokémon Serp Ferro de tipus\l"
	.string "Acer/Terra i un Pokémon Atroç\l"
	.string "de tipus Aigua/Volador.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels Entrenadors d'elit que\n"
	.string "l'Scott anomena Cervells de la\l"
	.string "Frontera és allà.\p"
	.string "Qui porta el lloc és una Entrenadora\n"
	.string "molt maca: el Magnat de l'Arena.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "Has combatut contra el Magnat de\n"
	.string "l'Arena?\p"
	.string "Quan avalua la destresa del rival,\n"
	.string "sembla que usa aquests Pokémon:\p"
	.string "Un Pokémon Banya Única de tipus\n"
	.string "Insecte/Lluita, un Pokémon Llum Lluna\l"
	.string "de tipus Fosc i un Pokémon Muda\l"
	.string "de tipus Insecte/Fantasma.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "Has combatut contra el Magnat de\n"
	.string "l'Arena quan va de seriós?\p"
	.string "Quan combat de debò,\n"
	.string "sembla que usa aquests Pokémon:\p"
	.string "Un Pokémon Llum Lluna de tipus Fosc,\n"
	.string "un Pokémon Ombra de tipus\l"
	.string "Fantasma/Verí i un Pokémon Bolet\l"
	.string "de tipus Planta/Lluita.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels Entrenadors d'elit que\n"
	.string "l'Scott anomena Cervells de la\l"
	.string "Frontera és allà.\p"
	.string "Qui porta el lloc és un Entrenador\n"
	.string "sinistre: el Virtuós del Palau.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "Has combatut contra el Virtuós del\n"
	.string "Palau?\p"
	.string "Quan posa a prova l'esperit del rival,\n"
	.string "diuen que usa aquests Pokémon:\p"
	.string "Un Pokémon Rat Penat de tipus\n"
	.string "Verí/Volador, un Pokémon Mandrós\l"
	.string "de tipus Normal i un Pokémon\l"
	.string "Transport de tipus Aigua/Gel.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "Has combatut contra el Virtuós del\n"
	.string "Palau quan va de seriós?\p"
	.string "Quan llança tota la seva força al\n"
	.string "combat, diuen que usa aquests Pokémon:\p"
	.string "Un Pokémon Llegendari de tipus Foc,\n"
	.string "un Pokémon Mandrós de tipus Normal\l"
	.string "i un Pokémon Aurora de tipus Aigua.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels Entrenadors d'elit que\n"
	.string "l'Scott anomena Cervells de la\l"
	.string "Frontera és allà.\p"
	.string "Qui porta el lloc és un Entrenador\n"
	.string "ardent: el Rei de la Piràmide.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "Has combatut contra el Rei de la\n"
	.string "Piràmide?\p"
	.string "Quan comprova el poder del rival,\n"
	.string "sembla que usa aquests Pokémon:\p"
	.string "Un Pokémon Cim de Roca de tipus Roca,\n"
	.string "un Pokémon Iceberg de tipus Gel\l"
	.string "i un Pokémon Ferro de tipus Acer.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "Has combatut contra el Rei de la\n"
	.string "Piràmide quan va de seriós?\p"
	.string "Quan està carregat de poder,\n"
	.string "sembla que usa aquests Pokémon:\p"
	.string "Un Pokémon Glaçada de tipus\n"
	.string "Gel/Volador, un Pokémon Elèctric\l"
	.string "de tipus Elèctric/Volador i un\l"
	.string "Pokémon Flama de tipus Foc/Volador.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "Sí, hi ha diversos llocs on\n"
	.string "pots fer Combats Dobles.\p"
	.string "Però les Sales de Combat Doble de\n"
	.string "la Torre de Combat són el més bàsic!\p"
	.string "Allà és on hauries d'aprendre com\n"
	.string "es fan els Combats Dobles aquí\l"
	.string "a la Frontera de Combat.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "Vés amb compte en els combats d'aquí.\p"
	.string "He sentit que hi ha Entrenadors amb\n"
	.string "estratègies pensades expressament\l"
	.string "per als Combats Dobles.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "Un cop tinguis confiança amb els\n"
	.string "Combats Dobles aquí, hauries de\l"
	.string "pensar a desafiar altres llocs\l"
	.string "que ofereixin Combats Dobles.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "Tot tipus d'Entrenadors es reuneixen\n"
	.string "al Saló de Combat.\p"
	.string "Pensa-hi: podries trobar-te amb\n"
	.string "els teus amics o seguidors!\l"
	.string "Hauries de mirar bé!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "Si vas amb un amic, dirigeix-te a la\n"
	.string "Sala de Combat Múltiple per Enllaç.\p"
	.string "Si jugues amb un amic fort,\n"
	.string "pots esperar enemics difícils!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "Quin poder de recopilació de notícies!\n"
	.string "El meu mentor és únic!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "Quina capacitat d'observació!\n"
	.string "El meu mentor és únic!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "Quin poder de persuasió tan increïble!\n"
	.string "El meu mentor és únic!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "…Què és aquest lloc?\n"
	.string "Em fa por…$"


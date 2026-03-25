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
	.string "Hola! Pel que fa a notícies sobre\n"
	.string "la Frontera de Combat, sóc el nº 1.\p"
	.string "Pots pensar en mi com\n"
	.string "el Fanàtic de la Frontera.\p"
	.string "Només per confirmar, ets Entrenador/a,\n"
	.string "oi?\p"
	.string "Encantadíssim de compartir les últimes\n"
	.string "notícies de la Frontera de Combat.$"

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
	.string "Sembla que {STR_VAR_1}\n"
	.string "és el lloc de moda.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "A veure…\p"
	.string "Sembla que la Torre de Combat\n"
	.string "{STR_VAR_1} és el més popular.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels Entrenadors d'elit que\n"
	.string "l'Scott anomena Cervells de la\l"
	.string "Frontera és allà.\p"
	.string "És una Entrenadora misteriosa\n"
	.string "anomenada la Dama del Saló.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "Has combatut contra la Dama del Saló?\p"
	.string "Quan avalua l'oponent,\n"
	.string "sembla que usa aquests Pokémon:\p"
	.string "Un Pokémon PSI de tipus Psíquic,\n"
	.string "un Pokémon Volcà de tipus Foc,\l"
	.string "i un Pokémon Dormilega de tipus Normal.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "Has combatut contra la Dama del Saló\n"
	.string "quan va de seriós?\p"
	.string "Quan combat a fons,\n"
	.string "sembla que usa aquests Pokémon:\p"
	.string "Un Pokémon Eó de tipus Drac/Psíquic,\n"
	.string "un Pokémon Tro de tipus Elèctric,\l"
	.string "i un Pokémon Dormilega de tipus Normal.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels Entrenadors d'elit que\n"
	.string "l'Scott anomena Cervells de la\l"
	.string "Frontera és allà.\p"
	.string "És un Entrenador flamenc\n"
	.string "anomenat l'As del Domo.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "Has combatut contra l'As del Domo?\p"
	.string "Quan tracta l'oponent amb lleugeresa,\n"
	.string "usa aquests tres Pokémon:\p"
	.string "Un Pokémon Drac de tipus Drac/Volador,\n"
	.string "un Pokémon Peix Fang de tipus Aigua/Terra,\l"
	.string "i un Pokémon Flama de tipus Foc/Volador.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "Has combatut contra l'As del Domo\n"
	.string "quan va de seriós?\p"
	.string "Quan demostra la seva estratègia,\n"
	.string "usa aquests tres Pokémon:\p"
	.string "Un Pokémon Eó de tipus Drac/Volador,\n"
	.string "un Pokémon Peix Fang de tipus Aigua/Terra,\l"
	.string "i un Pokémon Cama de Ferro\l"
	.string "de tipus Acer/Psíquic.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels Entrenadors d'elit que\n"
	.string "l'Scott anomena Cervells de la\l"
	.string "Frontera és allà.\p"
	.string "És un Entrenador estrany\n"
	.string "anomenat el Cap de la Fàbrica.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "Has combatut contra el Cap de la\n"
	.string "Fàbrica?\p"
	.string "Deixa'm pensar… Quan combat,\n"
	.string "agafa tres Pokémon de lloguer.\p"
	.string "Combat en pràcticament les mateixes\n"
	.string "condicions que tu.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "Has combatut contra el Cap de la\n"
	.string "Fàbrica quan va de seriós?\p"
	.string "Quan combat seriosament,\n"
	.string "segueix agafant tres Pokémon de lloguer.\p"
	.string "Combat en virtualment les mateixes\n"
	.string "condicions que tu.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels Entrenadors d'elit que\n"
	.string "l'Scott anomena Cervells de la\l"
	.string "Frontera és allà.\p"
	.string "És una Entrenadora temible\n"
	.string "anomenada la Reina de la Llança.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "Has combatut contra la Reina de la\n"
	.string "Llança?\p"
	.string "Quan està de bon humor, diuen que\n"
	.string "usa aquests tres Pokémon:\p"
	.string "Un Pokémon Serp Ullal de tipus Verí,\n"
	.string "un Pokémon Florit de tipus Bicho/Roca,\l"
	.string "i un Pokémon Tendre de tipus Aigua.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "Has combatut contra la Reina de la\n"
	.string "Llança quan va de seriós?\p"
	.string "Quan està molt molesta, diuen que\n"
	.string "usa aquests tres Pokémon:\p"
	.string "Un Pokémon Serp Ullal de tipus Verí,\n"
	.string "un Pokémon Serp Ferro d'Acer/Terra,\l"
	.string "i un Pokémon Atroç\l"
	.string "de tipus Aigua/Volador.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels Entrenadors d'elit que\n"
	.string "l'Scott anomena Cervells de la\l"
	.string "Frontera és allà.\p"
	.string "És una Entrenadora encantadora\n"
	.string "anomenada el Magnat de l'Arena.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "Has combatut contra el Magnat de\n"
	.string "l'Arena?\p"
	.string "Quan avalua l'habilitat de l'enemic,\n"
	.string "sembla que usa aquests Pokémon:\p"
	.string "Un Pokémon Banya de tipus Bicho/Lluita,\n"
	.string "un Pokémon Lluna de tipus Fosc,\l"
	.string "i un Pokémon Muda de tipus Bicho/Fantasma.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "Has combatut contra el Magnat de\n"
	.string "l'Arena quan va de seriós?\p"
	.string "Quan combat de debò,\n"
	.string "sembla que usa aquests Pokémon:\p"
	.string "Un Pokémon Lluna de tipus Fosc,\n"
	.string "un Pokémon Ombra de Fantasma/Verí\l"
	.string "i un Pokémon Bolet\l"
	.string "de tipus Planta/Lluita.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels Entrenadors d'elit que\n"
	.string "l'Scott anomena Cervells de la\l"
	.string "Frontera és allà.\p"
	.string "És un Entrenador sinistre\n"
	.string "anomenat el Mestre del Palau.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "Has combatut contra el Mestre del\n"
	.string "Palau?\p"
	.string "Quan posa a prova l'esperit de\n"
	.string "l'oponent, diuen que usa aquests:\p"
	.string "Un Pokémon Rat Penat de Verí/Volador,\n"
	.string "un Pokémon Gandul de tipus Normal, i\l"
	.string "un Pokémon Transport d'Aigua/Gel.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "Has combatut contra el Mestre del\n"
	.string "Palau quan va de seriós?\p"
	.string "Quan llança tota la seva força al\n"
	.string "combat, diuen que usa aquests:\p"
	.string "Un Pokémon Llegendari de tipus Foc,\n"
	.string "un Pokémon Gandul de tipus Normal,\l"
	.string "i un Pokémon Aurora de tipus Aigua.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "Segur que no ho sabies!\p"
	.string "Un dels Entrenadors d'elit que\n"
	.string "l'Scott anomena Cervells de la\l"
	.string "Frontera és allà.\p"
	.string "És un Entrenador apassionat\n"
	.string "anomenat el Rei de la Piràmide.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "Has combatut contra el Rei de la\n"
	.string "Piràmide?\p"
	.string "Quan comprova el poder de l'enemic,\n"
	.string "sembla que usa aquests Pokémon:\p"
	.string "Un Pokémon Pic de Roca de tipus Roca,\n"
	.string "un Pokémon Iceberg de tipus Gel,\l"
	.string "i un Pokémon Ferro de tipus Acer.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "Has combatut contra el Rei de la\n"
	.string "Piràmide quan va de seriós?\p"
	.string "Quan està carregat de poder,\n"
	.string "sembla que usa aquests Pokémon:\p"
	.string "Un Pokémon Congelació de Gel/Volador,\n"
	.string "un Pokémon Elèctric de Elèctric/Volador,\l"
	.string "i un Pokémon Flama\l"
	.string "de tipus Foc/Volador.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "Sí, hi ha diversos llocs on\n"
	.string "pots fer Combats Dobles.\p"
	.string "Però les Sales de Combats Dobles de\n"
	.string "la Torre de Combat són el bàsic!\p"
	.string "Allà és on hauries d'aprendre com\n"
	.string "es fan els Combats Dobles aquí\l"
	.string "a la Frontera de Combat.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "Vigila en els combats d'aquí.\p"
	.string "He sentit que hi ha Entrenadors amb\n"
	.string "estratègies desenvolupades just per\l"
	.string "als Combats Dobles.$"

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
	.string "Sala de Combat Múltiple per Link.\p"
	.string "Si jugues amb un amic fort,\n"
	.string "pots esperar enemics difícils!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "Quin poder de recopilació de notícies!\n"
	.string "El meu mentor és únic!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "Quins poders d'observació tan increïbles!\n"
	.string "El meu mentor és únic!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "Quin poder de persuasió tan increïble!\n"
	.string "El meu mentor és únic!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "…Què és aquest lloc?\n"
	.string "Em fa por…$"


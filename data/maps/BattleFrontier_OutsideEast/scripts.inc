BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_Return
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
 	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "Aquesta és la Torre de Combat!\n"
	.string "Mantingues la ratxa de victòries\l"
	.string "com l'Entrenador més dur!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "Aquest és el Palau de Combat!\n"
	.string "Vigila bé els combats Pokémon!$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "Aquesta és l'Arena de Combat!\n"
	.string "Que es reuneixin els equips\l"
	.string "més durs!$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "Aquesta és la Piràmide de Combat!\n"
	.string "Avança per la Cerca de Combat!$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "Sala de Rànquing de la\n"
	.string "Frontera de Combat\l"
	.string "Aspira a nous rècords!$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "Cantonada de Serveis d'Intercanvi\n"
	.string "Intercanvia els Punts de Combat!$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "Uau!\n"
	.string "És enorme!\p"
	.string "La Torre de Combat és especial.\n"
	.string "És diferent de les altres.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "La meva gran ambició és conquerir\n"
	.string "la Frontera de Combat i la Lliga\l"
	.string "Pokémon.\p"
	.string "I si el meu somni es fa realitat…\p"
	.string "Jo… Li demanaré a la Mimi del\n"
	.string "costat si vol ser amiga meva!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "La Piràmide de Combat és massa\n"
	.string "dura! No puc arribar al cim!\p"
	.string "Com que no tinc opcions, potser\n"
	.string "puc escalar-la per fora…$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "Prospero en la foscor…\n"
	.string "Sí… Què és digne de mi?\l"
	.string "La Piràmide de Combat…\p"
	.string "Què em dius de vagar en la foscor\n"
	.string "i en total desesperació?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "No he dormit en una setmana, però\n"
	.string "he muntat l'equip definitiu!\p"
	.string "No em veig perdent, de veritat.\n"
	.string "Assaltarem l'Arena de Combat!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "L'Scott t'ha portat aquí també?\n"
	.string "Què li passa a aquest home?\p"
	.string "Sembla que realment sap\n"
	.string "detectar Entrenadors amb talent…\p"
	.string "Però no l'he vist mai combatent\n"
	.string "en persona.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "Zigg!\n"
	.string "Crec en tu, petit amic!\p"
	.string "Si guanyes, et faré totes les\n"
	.string "llaminadures que vulguis!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "Zigzagoon té la mirada perduda…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "La gent em diu tafaner,\n"
	.string "però no ho puc evitar.\p"
	.string "Tens la gorra torta!\n"
	.string "Oh, no, brossa a terra!\l"
	.string "Ui, gairebé és hora de sopar!\p"
	.string "No sé si podré aguantar només\n"
	.string "mirant al Palau de Combat…$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "Potser no ho semblo ara,\n"
	.string "però vaig guanyar un Líder de Gimnàs.\p"
	.string "Qui sap, potser hauria de tornar\n"
	.string "a intentar-ho.$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "Sóc ràpida amb la Bici, i també\n"
	.string "combatent.\p"
	.string "Guanyo combats en un obrir\n"
	.string "i tancar d'ulls!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "Sóc millor que el meu papa\n"
	.string "als Pokémon.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "Au, boniqueta meva!\n"
	.string "Vés a acumular victòries pel Papa!\p"
	.string "Ets igual que la teva mare,\n"
	.string "així que dominaràs!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "No va ser fàcil arribar aquí,\n"
	.string "però havia sentit parlar d'una\l"
	.string "noia preciosa a l'Arena de Combat.\p"
	.string "En comptes d'ella, saps què\n"
	.string "he trobat?\p"
	.string "Una multitud suada, pudent\n"
	.string "i primitiva d'artistes marcials!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "De vegades veig un home gran\n"
	.string "molt important entrant allà.\p"
	.string "Té uns Pokémon increïbles.\n"
	.string "Però sembla molt amable.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "La coneixes?\n"
	.string "La llegenda de la Piràmide?\p"
	.string "Quan arribi un Entrenador confiat\n"
	.string "cercant el cim daurat,\l"
	.string "apareixerà un home entre homes.\p"
	.string "No coneixes la llegenda?\n"
	.string "Clar que no!\l"
	.string "Me l'acabo d'inventar!\p"
	.string "Què vol dir?\n"
	.string "Això, amic meu, no t'ho sé dir!$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "Mare meva!\n"
	.string "No havia perdut mai!\p"
	.string "Però m'han escombrat sense\n"
	.string "cap mena de gràcia!\p"
	.string "I em diuen que no tinc talent?!\n"
	.string "Mare meva!$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "Aquest noi es va trobar un\n"
	.string "Entrenador terrible mentre\l"
	.string "estava a la Torre de Combat.\p"
	.string "Mira'l ara…\p"
	.string "Has d'anar amb compte si decideixes\n"
	.string "anar a la Torre de Combat.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "Sí!\n"
	.string "Per fi tinc prou Punts de Combat!\p"
	.string "Crec que els canviaré per una altra\n"
	.string "Nina gegant de peluix!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "Oh, sí, d'acord!\n"
	.string "Aquesta és la Sala de Rànquing!\p"
	.string "M'agradaria passar a la història\n"
	.string "com a supercampió i tenir el meu\l"
	.string "nom registrat aquí per sempre.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "Amb tu al meu costat, puc fer el\n"
	.string "que sigui.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "Ooh, estimat, ets meravellós!\p"
	.string "Ooh, ja no puc esperar més!\p"
	.string "Anem a una Sala de Combat\n"
	.string "Múltiple ara mateix!\p"
	.string "Si ens unim al Saló de Combat,\n"
	.string "el poder del nostre amor superarà\l"
	.string "a tots els que trobem.\p"
	.string "Davant nostre, estimat, tot\n"
	.string "caurà com fitxes de dominó!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "La Frontera de Combat no és només\n"
	.string "per a Entrenadors durs.\p"
	.string "Molta gent amb habilitats especials\n"
	.string "ha estat convidada, pel que sembla.\p"
	.string "Aquell home, l'Scott…\p"
	.string "Pot ser que hagi construït aquest\n"
	.string "lloc per un objectiu més gran…$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "Perdona, jove.\n"
	.string "Tens bona vista?\p"
	.string "Hi ha un arbre estrany aquí,\n"
	.string "i als meus ulls cansats sembla\l"
	.string "que es mou.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "Perdona, jove.\n"
	.string "Tens bona memòria?\p"
	.string "Tinc la sensació que abans hi\n"
	.string "havia un arbre estrany aquí.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "Jo…\n"
	.string "L'he vist!\p"
	.string "Hi havia un Pokémon enganxós\n"
	.string "amb una cua llarga al davant!\p"
	.string "S'amagava sota una roca\n"
	.string "i no parava de mirar-me!$"

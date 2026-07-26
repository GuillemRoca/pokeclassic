.set LOCALID_GUARD, 1

Route22_NorthEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route22_NorthEntrance_OnTransition
	.byte 0

Route22_NorthEntrance_OnTransition::
	goto_if_set FLAG_BADGE08_GET, Route22_NorthEntrance_MoveGateGuard
	end

Route22_NorthEntrance_MoveGateGuard::
	setobjectxyperm LOCALID_GUARD, 8, 2
	end

Route22_NorthEntrance_EventScript_GateGuard::
	goto_if_set FLAG_BADGE08_GET,  Route22_NorthEntrance_HeadToVictoryRoad
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	playse SE_PIN
	applymovement LOCALID_GUARD, Common_Movement_QuestionMark
	waitmovement 1
	waitse
	msgbox Route22_NorthEntrance_Text_Collect8Badges, MSGBOX_NPC
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

Route22_NorthEntrance_Text_Collect8Badges::
	.string "Oh? Vols anar a l'Altiplà\n"
	.string "Índigo?\p"
	.string "Ho sento, no puc deixar-te\n"
	.string "passar si no tens les 8\l"
	.string "Medalles de Gimnàs.$"

Route22_NorthEntrance_HeadToVictoryRoad::
	msgbox Route22_NorthEntrance_Text_HeadToVictoryRoad, MSGBOX_NPC
	release
	end

Route22_NorthEntrance_Text_HeadToVictoryRoad::
	.string "Trobaràs el Camí de la Victòria\n"
	.string "al final de la Ruta 23.\p"
	.string "Està ple d'entrenadors d'elit\n"
	.string "i Pokémon forts.\n"
	.string "És la teva prova final abans\n"
	.string "d'enfrontar l'Alt Comandament!$"


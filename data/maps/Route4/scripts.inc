.set LOCALID_JENNY_1, 7
.set LOCALID_JENNY_2, 8
.set LOCALID_LOOKER, 9
.set LOCALID_FUGITIVE_F, 15
.set LOCALID_FUGITIVE_M, 16

Route4_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route4_OnResume
	.byte 0

Route4_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route4_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route4_EventScript_Boy::
	msgbox Route4_Text_PeopleLikeAndRespectBrock, MSGBOX_NPC
	release
	end

Route4_Text_PeopleLikeAndRespectBrock::
    .string "Oh, uau, la Medalla Roca!\n"
    .string "L'has aconseguit de Brock, oi?\p"
    .string "Brock mola. No és només fort.\n"
    .string "La gent l'aprecia i el respecta.\p"
    .string "Vull ser un Líder de Gimnàs\n"
    .string "com ell.$"

Route4_EventScript_Woman::
	msgbox Route4_Text_TrippedOverGeodude, MSGBOX_NPC
	end

Route4_Text_TrippedOverGeodude::
    .string "Ai! He ensopegat amb un Pokémon\n"
    .string "de roca, Geodude!$"

Route4_EventScript_MtMoonSign::
	msgbox Route4_Text_MtMoonEntrance, MSGBOX_SIGN
	end

Route4_Text_MtMoonEntrance::
    .string "Mt. Moon\n"
    .string "Entrada del Túnel$"

Route4_EventScript_RouteSign::
	msgbox Route4_Text_RouteSign, MSGBOX_SIGN
	end

Route4_Text_RouteSign::
    .string "Ruta 4\n"
    .string "Mt. Moon - Ciutat Cerúlia$"

Route4_EventScript_Crissy::
    trainerbattle_single TRAINER_LASS_ROBIN, Route4_Text_CrissyIntro, Route4_Text_CrissyDefeat
    msgbox Route4_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
    end

Route4_Text_CrissyIntro::
    .string "He vingut a MT. MOON a buscar\n"
    .string "Pokémon bolet.$"

Route4_Text_CrissyDefeat::
    .string "Després de tot el que he fet\n"
    .string "per atrapar-los!$"

Route4_Text_CrissyPostBattle::
    .string "Potser ja no queden més bolets\n"
    .string "aquí.\p"
    .string "Crec que me'ls he endut tots.$"

Route4_EventScript_ItemTM05::
	finditem ITEM_TM05, 1
	end

Route4_EventScript_Captured1::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepDownForLooker
	waitmovement 0
	goto Route4_EventScript_Captured
	end

Movement_StepDownForLooker:
	walk_down
	face_left
	step_end

Route4_EventScript_Captured2::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_TurnAroundForLooker
	waitmovement 0
	goto Route4_EventScript_Captured
	end

Movement_TurnAroundForLooker:
	face_left
	step_end

Route4_EventScript_Captured3::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepUpForLooker
	waitmovement 0
	goto Route4_EventScript_Captured
	end

Movement_StepUpForLooker:
	walk_up
	face_left
	step_end

Movement_PoliceApproach:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route4_EventScript_Captured::
	playbgm MUS_ENCOUNTER_CHAMPION, 0
	clearflag FLAG_HIDE_ROUTE4_POLICE
	addobject LOCALID_JENNY_1
	addobject LOCALID_JENNY_2
	addobject LOCALID_LOOKER
	applymovement LOCALID_JENNY_1, Movement_PoliceApproach
	applymovement LOCALID_JENNY_2, Movement_PoliceApproach
	applymovement LOCALID_LOOKER, Movement_PoliceApproach
	waitmovement 9
	msgbox Route4_Text_StopRightThere, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Route4_Text_TeamRocketFossils, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredLooker, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_LOOKER
	applymovement LOCALID_JENNY_1, Movement_PoliceExit
	applymovement LOCALID_JENNY_2, Movement_PoliceExit
	applymovement LOCALID_LOOKER, Movement_LookerExit
	waitmovement 9
	setflag FLAG_HIDE_ROUTE4_POLICE
	removeobject LOCALID_JENNY_1
	removeobject LOCALID_JENNY_2
	removeobject LOCALID_LOOKER
	setvar VAR_MT_MOON_STATE, 3
	fadedefaultbgm
	releaseall
	end

Movement_PoliceExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Movement_LookerExit:
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route4_Text_StopRightThere::
	.string "???: Quiets aquí!\p"
	.string "Pensàveu que podríeu escapar\n"
	.string "de la Policia Internacional?\p"
	.string "Sempre aniré un pas per davant\n"
	.string "dels vostres plans, Equip Rocket!$"

Route4_Text_TeamRocketFossils::
	.string "Ha! Dius que no ets del\n"
	.string "Equip Rocket?\p"
	.string "I com expliques aquest fòssil\n"
	.string "que portes?\p"
	.string "Sabem que l'Equip Rocket busca\n"
	.string "fòssils rars per vendre'ls al\l"
	.string "mercat negre!\p"
	.string "...\n"
	.string "......\l"
	.string "...........oh.\p"
	.string "Dius que els has aturat?\n"
	.string "I que ja han fugit de Mt. Moon?\p"
	.string "Llamps! Com se'ns han escapat!\p"
	.string "Perdona pel malentès.\p"
	.string "Em dic Looker - ja que has aturat\n"
	.string "l'Equip Rocket un cop, potser podem\l"
	.string "ajudar-nos mútuament.\p"
	.string "Aquí tens el meu número de mòbil -\n"
	.string "truca'm si saps res de l'Equip Rocket!$"

Route4_EventScript_PixieDust::
	finditem ITEM_PIXIE_DUST, 1
	release
	end

Route4_RocketFugitiveF::
	trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE_F
	waitse
	fadescreen FADE_FROM_BLACK
	end

Route4_RocketFugitiveM::
	trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE_M
	waitse
	fadescreen FADE_FROM_BLACK
	end

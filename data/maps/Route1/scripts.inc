.set LOCALID_OAK, 1
.set LOCALID_PIKACHU, 2
.set LOCALID_FUGITIVE, 7

Route1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route1_OnResume
	.byte 0

Route1_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route1_OnResume:
	removeobject LOCALID_PIKACHU
	call Common_EventScript_GetDayOrNight
	end

Route1_EventScript_OakAppears1::
	lockall
	addobject LOCALID_OAK
	applymovement LOCALID_OAK, Movement_OakAppears
	waitmovement 1
	msgbox Route1_Text_OakDontGoOut, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_OAK, Movement_OakApproaches1
	waitmovement 1
	msgbox Route1_Text_OakGrassUnsafe, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_PIKACHU
	applymovement LOCALID_PIKACHU, Movement_PikachuApproaches1
	goto Route1_EventScript_PikachuEncounter
	waitmovement 2
	end

Route1_EventScript_OakAppears2::
	lockall
	addobject LOCALID_OAK
	applymovement LOCALID_OAK, Movement_OakAppears
	waitmovement 1
	msgbox Route1_Text_OakDontGoOut, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_OAK, Movement_OakApproaches2
	waitmovement 1
	msgbox Route1_Text_OakGrassUnsafe, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_PIKACHU
	applymovement LOCALID_PIKACHU, Movement_PikachuApproaches2
	waitmovement 2
	goto Route1_EventScript_PikachuEncounter
	end

Movement_OakAppears:
	walk_down
	step_end

Route1_Text_OakDontGoOut::
    .string "Oak: Ei! Espera!\n"
    .string "No vagis per aquí!$"


Movement_OakApproaches1:
	walk_down
	walk_down
	walk_down
	step_end

Movement_OakApproaches2:
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

Route1_Text_OakGrassUnsafe::
    .string "OAK: És perillós!\n"
    .string "A l'herba alta hi ha Pokémon salvatges!\p"
    .string "Necessites el teu propi Pokémon per\n"
    .string "protegir-te.$"

Movement_PikachuApproaches1:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Movement_PikachuApproaches2:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route1_EventScript_PikachuEncounter::
	turnobject LOCALID_OAK, DIR_NORTH
	playse SE_PIN
	applymovement LOCALID_OAK, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_OAK, Common_Movement_Delay48
	waitmovement 1
	special SavePlayerParty
	special PutZigzagoonInPlayerParty
	special StartWallyTutorialBattle
	setflag FLAG_HIDE_PIKACHU_ROUTE1
	waitstate
	special LoadPlayerParty
	turnobject LOCALID_OAK, DIR_SOUTH
	msgbox Route1_Text_ThatWasClose, MSGBOX_DEFAULT
	setvar VAR_ADVENTURE_BEGINS, 2
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_MAP_NAME_POPUP
	clearflag FLAG_HIDE_OAK_IN_LAB
	setvar VAR_OAK_LAB_STATE, 1
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 5
	waitstate
	releaseall
	end

Route1_Text_ThatWasClose::
    .string "Oak: Per poc!\n"
    .string "Però això és estrany...\p"
    .string "No es veuen sovint Pikachu\n"
    .string "per aquesta zona...\p"
    .string "Tornem al meu laboratori!$"

Route1_EventScript_MartClerk::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POTION_ON_ROUTE_1, Route1_EventScript_AlreadyGotPotion
	msgbox Route1_Text_WorkAtPokeMartTakeSample, MSGBOX_DEFAULT
	checkitemspace ITEM_POTION, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	giveitem ITEM_POTION, 1
	setflag FLAG_GOT_POTION_ON_ROUTE_1
	release
	end

Route1_Text_WorkAtPokeMartTakeSample::
    .string "Hola!\n"
    .string "Treballo en una botiga Pokémon.\p"
    .string "Forma part d'una cadena molt pràctica\n"
    .string "que ven tota mena d'objectes.\p"
    .string "Vine a veure'ns a la ciutat de Viridian.\p"
    .string "Ja ho sé, et donaré una mostra.\n"
    .string "Aquí ho tens!$"

Route1_EventScript_AlreadyGotPotion::
	msgbox Route1_Text_ComeSeeUsIfYouNeedPokeBalls
	release
	end

Route1_Text_ComeSeeUsIfYouNeedPokeBalls::
    .string "Vine a veure'ns si necessites\n"
    .string "Poké Balls per capturar Pokémon.$"

Route1_EventScript_Boy::
	msgbox Route1_Text_CanJumpFromLedges, MSGBOX_NPC
	end

Route1_Text_CanJumpFromLedges::
    .string "Veus aquells esglaons vora el camí?\p"
    .string "Fa una mica de por, però pots\n"
    .string "saltar-hi.\p"
    .string "Així pots tornar al Poble Pallet\n"
    .string "més de pressa.$"

Route1_EventScript_RouteSign::
	msgbox Route1_Text_RouteSign, MSGBOX_SIGN
	end

Route1_Text_RouteSign::
    .string "Ruta 1\n"
    .string "Poble Pallet - Ciutat de Viridian$"

Route1_RocketFugitive::
	trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE
	waitse
	fadescreen FADE_FROM_BLACK
	end

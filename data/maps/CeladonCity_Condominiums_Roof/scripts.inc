.set LOCALID_ROCKET, 5
.set LOCALID_JESSIE, 4
.set LOCALID_JAMES,  3
.set LOCALID_PLANS,  2

CeladonCity_Condominiums_Roof_MapScripts::
	.byte 0

CeladonCity_Condominiums_Roof_EventScript_Sign::
	msgbox CeladonCity_Condominiums_Roof_Text_IKnowEverything, MSGBOX_SIGN
	end

CeladonCity_Condominiums_Roof_Text_IKnowEverything::
    .string "Jo ho sé TOT!$"

CeladonCity_Condominiums_Roof_EventScript_Girl::
	goto_if_set FLAG_GOT_ROCKET_PLANS, CeladonCity_Condominiums_Roof_EventScript_SpyMovie
	msgbox CeladonCity_Condominiums_Roof_Text_SawAStrangeMan, MSGBOX_NPC
	end

CeladonCity_Condominiums_Roof_Text_SawAStrangeMan::
	.string "He vist un home estrany deixar\n"
	.string "alguna cosa als arbustos d'allà.\p"
	.string "Semblava un d'aquells Rockets!$"

CeladonCity_Condominiums_Roof_EventScript_SpyMovie::
	msgbox CeladonCity_Condominiums_Roof_Text_SpyMovie, MSGBOX_NPC
	end

CeladonCity_Condominiums_Roof_Text_SpyMovie::
	.string "Uau, de debò era un lliurament\n"
	.string "Rocket?\p"
	.string "Em sento com en una peli d'espies!$"

CeladonCity_Condominiums_Roof_EventScript_RocketTrigger1::
	lock
	setobjectxyperm LOCALID_ROCKET, 8, 16
	goto CeladonCity_Condominiums_Roof_EventScript_Rocket
	end

CeladonCity_Condominiums_Roof_EventScript_RocketTrigger2::
	lock
	setobjectxyperm LOCALID_ROCKET, 9, 16
	goto CeladonCity_Condominiums_Roof_EventScript_Rocket
	end

CeladonCity_Condominiums_Roof_EventScript_RocketTrigger3::
	lock
	setobjectxyperm LOCALID_ROCKET, 10, 16
	goto CeladonCity_Condominiums_Roof_EventScript_Rocket
	end


CeladonCity_Condominiums_Roof_EventScript_Rocket::
	clearflag FLAG_HIDE_CELADON_ROOFTOP_ROCKET
	addobject LOCALID_ROCKET
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_ROCKET, Movement_ApproachPlayerRooftop
	waitmovement 5
	playse SE_PIN
	applymovement LOCALID_ROCKET, Common_Movement_ExclamationMark
	waitse
	trainerbattle_single TRAINER_ROOFTOP_ROCKET_GRUNT, RooftopRocket_Intro, RooftopRocket_Defeat, CeladonCity_Condominiums_Roof_EventScript_RocketFlee
	end

Movement_ApproachPlayerRooftop:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RooftopRocket_Intro::
	.string "Rocket: Ei, nano.\p"
	.string "Estic fent una pausa per fumar.\n"
	.string "No faig res sospitós.\p"
	.string "Què? No em creus?\n"
	.string "Bé, et faré creure per força!$"

RooftopRocket_Defeat::
	.string "No he fet res dolent!\n"
	.string "No tens cap prova!$"

CeladonCity_Condominiums_Roof_EventScript_RocketFlee::
	msgbox RooftopRocket_PostBattle, MSGBOX_AUTOCLOSE
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ROCKET
	setvar VAR_ROOFTOP_ROCKET_PLANS, 1
	playse SE_FLEE
	waitse
	delay 8
	fadescreen FADE_FROM_BLACK
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

RooftopRocket_PostBattle::
	.string "No tinc temps per perdre'l\n"
	.string "combatent amb nanos.\p"
	.string "No has vist res, entesos?\p"
	.string "I no vagis a ficar el nas\n"
	.string "pels arbustos d'allà darrere.$"

CeladonCity_Condominiums_Roof_EventScript_RocketPlans::
	msgbox CeladonCity_Condominiums_Roof_Text_RocketPlans
	removeobject LOCALID_PLANS
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	additem ITEM_ROCKET_PLANS, 1
	message CeladonCity_Condominiums_Roof_Text_ObtainRocketPlans
	waitfanfare
	waitmessage
	closemessage
	goto_if_eq VAR_ROOFTOP_ROCKET_PLANS, 2, CeladonCity_Condominiums_Roof_EventScript_JessieJamesBattle2
	release
	end

CeladonCity_Condominiums_Roof_Text_RocketPlans::
	.string "És una bossa sospitosa...\p"
	.string "Està plena de missatges del\n"
	.string "Team Rocket!$"

CeladonCity_Condominiums_Roof_Text_ObtainRocketPlans::
	.string "{PLAYER} ha trobat els Plans\n"
	.string "Rocket!$"

CeladonCity_Condominiums_Roof_EventScript_JessieJamesBattle2::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	clearflag FLAG_HIDE_CELADON_ROOFTOP_JESSIE_JAMES
	addobject LOCALID_JESSIE
	addobject LOCALID_JAMES
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	msgbox CeladonCity_Condominiums_Roof_Text_LookWhoItIs, MSGBOX_AUTOCLOSE
	applymovement LOCALID_JESSIE, Movement_BlockPlayerEscape
	applymovement LOCALID_JAMES, Movement_BlockPlayerEscape
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_EAST
	waitmovement 4
	goto PokemonTower_7F_EventScript_JessieJamesBattle
	end

CeladonCity_Condominiums_Roof_EventScript_JessieJamesBattle::
	trainerbattle_double TRAINER_POKEMON_TOWER_JESSIE_JAMES CeladonCity_Condominiums_Roof_Text_RocketDuoIntro, CeladonCity_Condominiums_Roof_Text_RocketDuoDefeat, Text_NeedTwoMons, CeladonCity_Condominiums_Roof_EventScript_RocketDuoDefeated, NO_MUSIC
	end

CeladonCity_Condominiums_Roof_Text_LookWhoItIs::
	.string "James: Mira qui tenim aquí.\n"
	.string "Jessie: És clar que és aquest nen.$"

Movement_BlockPlayerEscape:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

	.string "James: Com sabies del nostre\n"
	.string "punt d'entrega secret? És secret!\p"
	.string "Jessie: Algú de la base deu haver\n"
	.string "parlat!\p"
	.string ""

CeladonCity_Condominiums_Roof_Text_RocketDuoIntro::
	.string "Jessie: Com sabies del nostre\n"
	.string "punt d'entrega secret?\p"
	.string "James: Sí, el punt és que\n"
	.string "és un secret!\p"
	.string "Jessie: Bé, haurem d'assegurar\n"
	.string "que segueixi sent un secret!$"


CeladonCity_Condominiums_Roof_Text_RocketDuoDefeat::
	.string "Jessie: Comences a posar-me\n"
	.string "molt nerviosa, mocós!\p"
	.string "James: Com pot ser que passi això!?$"

CeladonCity_Condominiums_Roof_EventScript_RocketDuoDefeated::
	msgbox CeladonCity_Condominiums_Roof_Text_RocketDuoDefeated, MSGBOX_AUTOCLOSE
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	waitse
	removeobject LOCALID_JAMES
	removeobject LOCALID_JESSIE
	setvar VAR_ROOFTOP_ROCKET_PLANS, 3
	fadescreen FADE_FROM_BLACK
	fadeinbgm 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

CeladonCity_Condominiums_Roof_Text_RocketDuoDefeated::
	.string "Jessie: Sembla que enlairem el vol!\n"
	.string "James: Sembla que enlairem el vol!$"

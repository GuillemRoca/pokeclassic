.set LOCALID_GRUNT1, 1
.set LOCALID_GRUNT2, 2
.set LOCALID_GRUNT3, 3
.set LOCALID_JESSIE, 4
.set LOCALID_JAMES,  5

PokemonTower_7F_MapScripts::
	.byte 0

PokemonTower_7F_EventScript_MrFuji::
    lock
    faceplayer
    setflag FLAG_HIDE_POKEMON_TOWER_FUJI
    clearflag FLAG_HIDE_POKEHOUSE_FUJI
    setflag FLAG_RESCUED_MR_FUJI
    msgbox PokemonTower_7F_Text_MrFujiThankYouFollowMe, MSGBOX_DEFAULT
    goto_if_unset FLAG_DELIVERED_ROCKET_PLANS, PokemonTower_7F_EventScript_JessieJamesSecretBattle3
    goto PokemonTower_7F_EventScript_MrFujiExit
    release
    end

PokemonTower_7F_Text_MrFujiThankYouFollowMe::
    .string "Sr. Fuji: Eh?\n"
    .string "Has vingut a salvar-me?\p"
    .string "Gràcies. Però he vingut aquí\n"
    .string "per voluntat pròpia.\p"
    .string "He vingut a calmar l'esperit\n"
    .string "de la mare del Cubone.\p"
    .string "Crec que l'esperit de Marowak\n"
    .string "finalment ens ha deixat.\p"
    .string "T'he d'agrair la teva amable\n"
    .string "preocupació.\p"
    .string "Segueix-me fins a casa meva,\n"
    .string "la Casa Pokémon, al peu\l"
    .string "d'aquesta torre.$"

PokemonTower_7F_EventScript_MrFujiExit::
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	clearflag FLAG_SYS_FORCE_LOAD_OFFSCREEN_OBJ
	setvar VAR_POKEMON_TOWER_STATE, 3
	warp MAP_LAVENDER_TOWN_VOLUNTEER_POKEMON_HOUSE, 4, 6
	waitstate
	release
	end

PokemonTower_7F_EventScript_JessieJamesSecretBattle3::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setflag FLAG_SYS_FORCE_LOAD_OFFSCREEN_OBJ
	clearflag FLAG_HIDE_POKEMON_TOWER_JESSIE_JAMES
	msgbox PokemonTower_7F_Text_HoldItKid, MSGBOX_AUTOCLOSE
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_SOUTH
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	addobject LOCALID_JESSIE
	addobject LOCALID_JAMES
	applymovement LOCALID_JESSIE, Movement_RocketDuoEnters
	applymovement LOCALID_JAMES, Movement_RocketDuoEnters
	waitmovement 4
	goto PokemonTower_7F_EventScript_JessieJamesBattle
	end

PokemonTower_7F_EventScript_JessieJamesBattle::
	trainerbattle_double TRAINER_POKEMON_TOWER_JESSIE_JAMES PokemonTower_7F_RocketDuoIntro, PokemonTower_7F_RocketDuoDefeat, Text_NeedTwoMons, PokemonTower_7F_EventScript_RocketDuoDefeated, NO_MUSIC
	end

PokemonTower_7F_Text_HoldItKid::
	.string "Jessie: Para aquí mateix, marrec.$"

Movement_RocketDuoEnters:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonTower_7F_RocketDuoIntro::
	.string "James: T'hem perseguit des de\n"
	.string "Celadon per recuperar els plans!\p"
	.string "Jessie: Hauries d'haver-los donat\n"
	.string "a la Policia Internacional quan\l"
	.string "en tenies l'oportunitat.\p"
	.string "James: Ens els tornarem a quedar!$"

PokemonTower_7F_RocketDuoDefeat::
    .string "Jessie: Marrec!\n"
    .string "James: Te'n penediràs!$"

PokemonTower_7F_EventScript_RocketDuoDefeated::
	msgbox PokemonTower_7F_Text_RocketDuoDefeated, MSGBOX_AUTOCLOSE
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	waitse
	removeobject LOCALID_JESSIE
	removeobject LOCALID_JAMES
	fadescreen FADE_FROM_BLACK
	fadeinbgm 0
	msgbox PokemonTower_7F_Text_LetsGoToHouse, MSGBOX_AUTOCLOSE
	goto PokemonTower_7F_EventScript_MrFujiExit
	end

PokemonTower_7F_Text_RocketDuoDefeated::
    .string "Jessie: Ugh! De debò? Un altre cop?\p"
    .string "James: Sembla que la nostra\n"
    .string "oportunitat de recuperar els plans\l"
    .string "ha fracassat...\p"
    .string "Jessie: No creus que ja ho sé?\n"
    .string "Tant se val, si aquest marrec\l"
    .string "encara no ha donat els plans a la\l"
    .string "Policia Internacional, vol dir que\l"
    .string "encara tenim temps per anar a\l"
    .string "ajudar amb la presa de Ciutat Safrà.\p"
    .string "Jessie i James: L'Equip Rocket\n"
    .string "surt disparat un altre cop!$"

PokemonTower_7F_Text_LetsGoToHouse::
	.string "Sr. Fuji: Bé, això ha estat\n"
	.string "inesperat.\p"
	.string "Tornem a casa meva abans que\n"
	.string "apareguin més Rockets...$"

PokemonTower_7F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_19, PokemonTower_7F_Text_Grunt1Intro, PokemonTower_7F_Text_Grunt1Defeat, PokemonTower_7F_EventScript_DefeatedGrunt1
	msgbox PokemonTower_7F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_7F_EventScript_DefeatedGrunt1::
	msgbox PokemonTower_7F_Text_Grunt1PostBattle
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 10
	goto_if_eq PokemonTower_7F_EventScript_Grunt1ExitMid
	compare VAR_0x8004, 11
	goto_if_eq PokemonTower_7F_EventScript_Grunt1ExitRight
	compare VAR_0x8004, 9
	goto_if_eq PokemonTower_7F_EventScript_Grunt1ExitLeft
	applymovement LOCALID_GRUNT1, PokemonTower_7F_Movement_Grunt1Exit
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt1
	end

PokemonTower_7F_EventScript_Grunt1ExitMid::
	applymovement LOCALID_GRUNT1, PokemonTower_7F_Movement_Grunt1ExitMid
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt1
	end

PokemonTower_7F_EventScript_Grunt1ExitRight::
	applymovement LOCALID_GRUNT1, PokemonTower_7F_Movement_Grunt1ExitRight
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt1
	end

PokemonTower_7F_EventScript_Grunt1ExitLeft::
	applymovement LOCALID_GRUNT1, PokemonTower_7F_Movement_Grunt1ExitLeft
	waitmovement 0
	playse SE_EXIT
	delay 25
	goto PokemonTower_7F_EventScript_RemoveGrunt1
	end

PokemonTower_7F_Text_Grunt1Intro::
    .string "Què vols?\n"
    .string "Per què ets aquí?$"

PokemonTower_7F_Text_Grunt1Defeat::
    .string "Em rendeixo!$"

PokemonTower_7F_Text_Grunt1PostBattle::
    .string "No oblidaré això!$"

PokemonTower_7F_EventScript_RemoveGrunt1::
	removeobject LOCALID_GRUNT1
	release
	end

PokemonTower_7F_Movement_Grunt1ExitMid::
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt1ExitRight::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt1Exit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt1ExitLeft::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

PokemonTower_7F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_20, PokemonTower_7F_Text_Grunt2Intro, PokemonTower_7F_Text_Grunt2Defeat, PokemonTower_7F_EventScript_DefeatedGrunt2
	msgbox PokemonTower_7F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_7F_Text_Grunt2Intro::
    .string "Aquest vell va venir directament\n"
    .string "al nostre Amagatall.\p"
    .string "Llavors, es va posar a predicar\n"
    .string "que l'Equip Rocket maltracta\l"
    .string "els Pokémon.\p"
    .string "Doncs, només n'estem parlant\n"
    .string "com adults.$"

PokemonTower_7F_Text_Grunt2Defeat::
    .string "Si us plau!\n"
    .string "Prou!$"

PokemonTower_7F_Text_Grunt2PostBattle::
    .string "Els Pokémon només serveixen per\n"
    .string "fer diners. Per què no usar-los?\p"
    .string "No et fiquis on no et criden!$"

PokemonTower_7F_EventScript_DefeatedGrunt2::
	msgbox PokemonTower_7F_Text_Grunt2PostBattle
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 12
	goto_if_eq PokemonTower_7F_EventScript_Grunt2ExitLeft
	compare VAR_0x8004, 13
	goto_if_eq PokemonTower_7F_EventScript_Grunt2ExitRight
	applymovement LOCALID_GRUNT2, PokemonTower_7F_Movement_Grunt2Exit
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt2
	end

PokemonTower_7F_EventScript_Grunt2ExitLeft::
	applymovement LOCALID_GRUNT2, PokemonTower_7F_Movement_Grunt2ExitLeft
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt2
	end

PokemonTower_7F_EventScript_Grunt2ExitRight::
	applymovement LOCALID_GRUNT2, PokemonTower_7F_Movement_Grunt2ExitRight
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt2
	end

PokemonTower_7F_EventScript_RemoveGrunt2::
	removeobject LOCALID_GRUNT2
	release
	end

PokemonTower_7F_Movement_Grunt2ExitLeft::
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt2Exit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt2ExitRight::
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_21, PokemonTower_7F_Text_Grunt3Intro, PokemonTower_7F_Text_Grunt3Defeat, PokemonTower_7F_EventScript_DefeatedGrunt3
	msgbox PokemonTower_7F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_7F_Text_Grunt3Intro::
    .string "No salvaràs ningú, nen!$"

PokemonTower_7F_Text_Grunt3Defeat::
    .string "No lluiteu contra nosaltres,\n"
    .string "els Rockets!$"

PokemonTower_7F_Text_Grunt3PostBattle::
    .string "No te'n sortiràs amb la teva!$"

PokemonTower_7F_EventScript_DefeatedGrunt3::
	msgbox PokemonTower_7F_Text_Grunt3PostBattle
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 10
	goto_if_eq PokemonTower_7F_EventScript_Grunt3ExitRight
	compare VAR_0x8004, 9
	goto_if_eq PokemonTower_7F_EventScript_Grunt3ExitLeft
	applymovement LOCALID_GRUNT3, PokemonTower_7F_Movement_Grunt3Exit
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt3
	end

PokemonTower_7F_EventScript_Grunt3ExitRight::
	applymovement LOCALID_GRUNT3, PokemonTower_7F_Movement_Grunt3ExitRight
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt3
	end

PokemonTower_7F_EventScript_Grunt3ExitLeft::
	applymovement LOCALID_GRUNT3, PokemonTower_7F_Movement_Grunt3ExitLeft
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt3
	end

PokemonTower_7F_EventScript_RemoveGrunt3::
	removeobject LOCALID_GRUNT3
	release
	end

PokemonTower_7F_EventScript_Unused::
	release
	end

PokemonTower_7F_Movement_Grunt3ExitRight::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt3Exit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt3ExitLeft::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

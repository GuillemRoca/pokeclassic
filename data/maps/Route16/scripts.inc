Route16_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route16_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route16_OnResume
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route16_OnWarp
	.byte 0

Route16_OnTransition:
	call_if_eq VAR_CYCLING_ROAD, 1, Route16_OnTransitionCyclingRoad
	call Common_EventScript_GetDayOrNight
	end

Route16_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route16_EventScript_TryRemoveSnorlax
	call Common_EventScript_GetDayOrNight
	end

Route16_OnWarp::
	map_script_2 VAR_CYCLING_ROAD, 1, Route16_OnWarpCyclingRoad
	.2byte 0

Route16_OnWarpCyclingRoad::
	special ForcePlayerOntoBike
	end

Route16_OnTransitionCyclingRoad::
	setflag FLAG_SYS_CYCLING_ROAD
	return

@Snorlax
Route16_EventScript_TryRemoveSnorlax::
	removeobject VAR_LAST_TALKED
	return

Route16_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_POKE_FLUTE, Route16_EventScript_SnorlaxNoPokeFlute
    checkitem ITEM_POKE_FLUTE
    goto_if_eq VAR_RESULT, FALSE, Route16_EventScript_SnorlaxNoPokeFlute
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route16_EventScript_DontUsePokeFlute
	call Common_EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 30, ITEM_NONE
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE16_SNORLAX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_WOKE_UP_ROUTE_16_SNORLAX
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route16_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route16_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED,Route16_EventScript_FoughtSnorlax
	release
	end

Route16_EventScript_DontUsePokeFlute::
	release
	end

Route16_EventScript_FoughtSnorlax::
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route16_EventScript_SnorlaxNoPokeFlute::
	msgbox Route16_Text_MonSprawledOutInSlumber
	release
	end

Route16_Text_MonSprawledOutInSlumber::
    .string "Un Pokémon és escampat en un\n"
    .string "son profund i confortable.$"

Route16_EventScript_CyclingRoadSign::
	msgbox Route16_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route16_EventScript_RouteSign::
	msgbox Route16_Text_RouteSign, MSGBOX_SIGN
	end

Route16_Text_CyclingRoadSign::
    .string "Gaudiu del pendent!\n"
    .string "Carril Bici$"

Route16_Text_RouteSign::
    .string "Ruta 16\n"
    .string "Celadon City - Fuchsia City$"

Route16_EventScript_Hideo::
	trainerbattle_single REMATCHABLE_TRAINER_BIKER_HIDEO_1, Route16_Text_HideoIntro, Route16_Text_HideoDefeat, Route16_EventScript_RegisterHideoAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route16_EventScript_HideoRematch
	msgbox Route16_Text_HideoPostBattle, MSGBOX_DEFAULT
	release
	end

Route16_Text_HideoIntro::
    .string "Ei, m'acabes de donar un cop!$"

Route16_Text_HideoDefeat::
    .string "Kabum!$"

Route16_Text_HideoPostBattle::
    .string "Sempre estarem per aquí tant\n"
    .string "si t'agrada com si no.\p"
    .string "Pots desviar-te a Vermilion\n"
    .string "des de Fuchsia per la costa.$"

Route16_EventScript_RegisterHideoAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route16_Text_HideoRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_BIKER_HIDEO_1
	release
	end

Route16_Text_HideoRegister:
	.string "Ei, ja que has xocat amb la meva\n"
	.string "moto, m'ho hauràs de compensar.\p"
	.string "Acceptaré una revenja com a paga.$"

Route16_EventScript_HideoRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_BIKER_HIDEO_1, Route16_Text_HideoRematchIntro, Route16_Text_HideoDefeat
	msgbox Route16_Text_HideoRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_HideoRematchIntro::
	.string "T'he fet esperar, eh?$"

Route16_Text_HideoRematchPostBattle::
	.string "Mai es Game Over!$"


Route16_EventScript_Koji::
	trainerbattle_single REMATCHABLE_TRAINER_CUE_BALL_KOJI_1, Route16_Text_KojiIntro, Route16_Text_KojiDefeat, Route16_EventScript_RegisterKojiAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route16_EventScript_KojiRematch
	msgbox Route16_Text_KojiPostBattle, MSGBOX_DEFAULT
	release
	end

Route16_Text_KojiIntro::
    .string "Bona Bici!\n"
    .string "Dóna-me-la!$"

Route16_Text_KojiDefeat::
    .string "KO!$"

Route16_Text_KojiPostBattle::
    .string "Oblida-ho, qui necessita la\n"
    .string "teva bici!$"

Route16_EventScript_RegisterKojiAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route16_Text_KojiRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_CUE_BALL_KOJI_1
	release
	end

Route16_Text_KojiRegister:
	.string "Si no em donaràs la bici,\n"
	.string "doncs em quedaré el teu\l"
	.string "número de mòbil!$"

Route16_EventScript_KojiRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_CUE_BALL_KOJI_1, Route16_Text_KojiRematchIntro, Route16_Text_KojiDefeat
	msgbox Route16_Text_KojiRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_KojiRematchIntro::
	.string "Ei! Dóna'm la bici...\n"
	.string "Oh, ets tu, {PLAYER}!$"

Route16_Text_KojiRematchPostBattle::
	.string "Mai em podré permetre una bici\n"
	.string "així que en robaré una!$"

Route16_EventScript_Lao::
	trainerbattle_single TRAINER_BIKER_LAO, Route16_Text_LaoIntro, Route16_Text_LaoDefeat
	msgbox Route16_Text_LaoPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_LaoIntro::
    .string "Què vols?$"

Route16_Text_LaoDefeat::
    .string "No t'atreveixis a riure!$"

Route16_Text_LaoPostBattle::
    .string "Ens agrada estar aquí.\n"
    .string "Quin problema tens?$"

Route16_EventScript_Ruben::
	trainerbattle_single TRAINER_BIKER_RUBEN, Route16_Text_RubenIntro, Route16_Text_RubenDefeat
	msgbox Route16_Text_RubenPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_RubenIntro::
    .string "Ei!\n"
    .string "Passem-ho bé!$"

Route16_Text_RubenDefeat::
    .string "No em feu enfadar!$"

Route16_Text_RubenPostBattle::
    .string "M'ho passo bé molestant la gent\n"
    .string "amb els meus Pokémon pudents.\p"
    .string "Van molt bé per espantar.\n"
    .string "I a més, mosseguen.$"

Route16_EventScript_Luke::
	trainerbattle_single TRAINER_CUE_BALL_LUKE, Route16_Text_LukeIntro, Route16_Text_LukeDefeat
	msgbox Route16_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_LukeIntro::
    .string "Surt a jugar, ratolinet!$"

Route16_Text_LukeDefeat::
    .string "Petit rata!$"

Route16_Text_LukePostBattle::
    .string "Odio perdre!\n"
    .string "Fes-te perdedís!$"

Route16_EventScript_Camron::
	trainerbattle_single TRAINER_CUE_BALL_CAMRON, Route16_Text_CamronIntro, Route16_Text_CamronDefeat
	msgbox Route16_Text_CamronPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_CamronIntro::
    .string "Tinc gana i estic de mal humor!\n"
    .string "Necessito un sac de boxa!$"

Route16_Text_CamronDefeat::
    .string "Malament, malament, malament!$"

Route16_Text_CamronPostBattle::
    .string "Si he de tenir Pokémon, val més\n"
    .string "que siguin ferotges.\p"
    .string "Els faria servir per deixar els\n"
    .string "enemics fets miques.$"

Route16_EventScript_Jed::
	trainerbattle_double TRAINER_YOUNG_COUPLE_LEA_JED, Route16_Text_JedIntro, Route16_Text_JedDefeat, Route16_Text_JedNotEnoughMons
	msgbox Route16_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_JedIntro::
    .string "Jed: El nostre amor no té límits.\n"
    .string "Estem enamorats i ho demostrem!$"

Route16_Text_JedDefeat::
    .string "Jed: Oh, no!\n"
    .string "El meu amor m'ha vist perdre!$"

Route16_Text_JedPostBattle::
    .string "Jed: Escolta, Lea.\n"
    .string "Has d'estar menys pendent de mi.$"

Route16_EventScript_Lea::
	trainerbattle_double TRAINER_YOUNG_COUPLE_LEA_JED, Route16_Text_LeaIntro, Route16_Text_LeaDefeat, Route16_Text_LeaNotEnoughMons
	msgbox Route16_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_LeaIntro::
    .string "Lea: A vegades, la intensitat\n"
    .string "del nostre amor em fa por.$"

Route16_Text_LeaDefeat::
    .string "Lea: Ohh! Però en Jed està\n"
    .string "guapo fins i tot perdent!$"

Route16_Text_LeaPostBattle::
    .string "Lea: Ehehe, perdona.\n"
    .string "En Jed és tan guapo.$"

Route16_Text_JedNotEnoughMons::
    .string "Jed: Només tens un Pokémon?\n"
    .string "No tens amor al cor?$"

Route16_Text_LeaNotEnoughMons::
    .string "Lea: Oh, no portes dos\n"
    .string "Pokémon?\p"
    .string "No et sents sol, tu o\n"
    .string "el teu Pokémon?$"


@TODO: Change based on if a new snorlax is here
Route16_EventScript_BerryMan::
	lock
	faceplayer
	msgbox Route16_Text_SnorlaxEatsBerries, MSGBOX_NPC
	release
	end

Route16_Text_SnorlaxEatsBerries:
	.string "A vegades Snorlax entra al nostre\n"
	.string "Hort de Baies i se'ls menja tots!\p"
	.string "Després, fa una llarga migdiada.\p"
	.string "Ni el soroll del Carril Bici pot\n"
	.string "despertar-lo.$"

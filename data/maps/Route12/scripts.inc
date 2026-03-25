.set LOCALID_FUGITIVE, 16

Route12_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route12_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route12_OnResume
	.byte 0

Route12_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route12_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route12_EventScript_TryRemoveSnorlax
	call Common_EventScript_GetDayOrNight
	end

Route12_EventScript_RouteSign::
	msgbox Route12_Text_RouteSign, MSGBOX_SIGN
	end

Route12_Text_RouteSign::
    .string "Ruta 12 \n"
    .string "Nord cap a Lavender$"

Route12_EventScript_FishingSign::
	msgbox Route12_Text_SportfishingArea, MSGBOX_SIGN
	end

Route12_Text_SportfishingArea::
    .string "Zona de Pesca Esportiva$"

@Snorlax
Route12_EventScript_TryRemoveSnorlax::
	removeobject VAR_LAST_TALKED
	return

Route12_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_POKE_FLUTE, Route12_EventScript_SnorlaxNoPokeFlute
    checkitem ITEM_POKE_FLUTE
    goto_if_eq VAR_RESULT, FALSE, Route12_EventScript_SnorlaxNoPokeFlute
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route12_EventScript_DontUsePokeFlute
	call Common_EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 30, ITEM_NONE
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE12_SNORLAX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_WOKE_UP_ROUTE_12_SNORLAX
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED,Route12_EventScript_FoughtSnorlax
	release
	end

Route12_EventScript_DontUsePokeFlute::
	release
	end

Route12_EventScript_FoughtSnorlax::
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route12_EventScript_SnorlaxNoPokeFlute::
	msgbox Route12_Text_MonSprawledOutInSlumber
	release
	end

Route12_Text_MonSprawledOutInSlumber::
    .string "Un Pokémon és escampat en un\n"
    .string "son profund i confortable.$"

Text_PlayedPokeFlute::
    .string "{PLAYER} ha tocat la Poké Flauta.$"

@Trainers
Route12_EventScript_Ned::
	trainerbattle_single REMATCHABLE_TRAINER_FISHERMAN_NED_1, Route12_Text_NedIntro, Route12_Text_NedDefeat, Route12_EventScript_RegisterNedAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route12_EventScript_NedRematch
	msgbox Route12_Text_NedPostBattle, MSGBOX_DEFAULT
	release
	end

Route12_Text_NedIntro::
    .string "Sí!\n"
    .string "He pescat una cosa aquí!$"

Route12_Text_NedDefeat::
    .string "Tsc!\n"
    .string "Només un peixet…$"

Route12_Text_NedPostBattle::
    .string "Espera!\n"
    .string "Se m'ha enganxat el fil!$"

Route12_EventScript_RegisterNedAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route12_Text_NedRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_FISHERMAN_NED_1
	release
	end

Route12_Text_NedRegister:
	.string "Truca'm si mai vols anar\n"
	.string "a pescar.$"

Route12_EventScript_NedRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_FISHERMAN_NED_1, Route12_Text_NedRematchIntro, Route12_Text_NedDefeat
	msgbox Route12_Text_NedRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route12_Text_NedRematchIntro::
	.string "Uau!\n"
	.string "Aquesta serà una pesca grossa!$"

Route12_Text_NedRematchPostBattle::
	.string "Només un altre Magikarp.$"

Route12_EventScript_Luca::
    trainerbattle_single REMATCHABLE_TRAINER_ROCKER_LUCA_1, Route12_Text_LucaIntro, Route12_Text_LucaDefeat, Route12_EventScript_RegisterLucaAfterBattle
    specialvar VAR_RESULT, ShouldTryRematchBattle
    goto_if_eq VAR_RESULT, TRUE, Route12_EventScript_LucaRematch
    msgbox Route12_Text_LucaPostBattle, MSGBOX_DEFAULT
    release
    end

Route12_Text_LucaIntro::
    .string "L'electricitat és la meva\n"
    .string "especialitat.\p"
    .string "Però no en sé res dels Pokémon\n"
    .string "de mar.$"

Route12_Text_LucaDefeat::
    .string "Desconnectat!$"

Route12_Text_LucaPostBattle::
    .string "L'aigua condueix l'electricitat,\n"
    .string "així que fulmina els Pokémon\l"
    .string "de mar.$"

Route12_EventScript_RegisterLucaAfterBattle::
    special PlayerFaceTrainerAfterBattle
    waitmovement 0
    msgbox Route12_Text_LucaRegister, MSGBOX_DEFAULT
    register_matchcall REMATCHABLE_TRAINER_ROCKER_LUCA_1
    release
    end

Route12_Text_LucaRegister:
    .string "Quan m'hagi recarregat, fem\n"
    .string "la revenja.$"

Route12_EventScript_LucaRematch::
    trainerbattle_rematch REMATCHABLE_TRAINER_ROCKER_LUCA_1, Route12_Text_LucaRematchIntro, Route12_Text_LucaDefeat
    msgbox Route12_Text_LucaRematchPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_Text_LucaRematchIntro::
    .string "Encara no en sé res dels\n"
    .string "Pokémon de mar.$"

Route12_Text_LucaRematchPostBattle::
    .string "Fulminat!$"

Route12_EventScript_Chip::
	trainerbattle_single TRAINER_FISHERMAN_CHIP, Route12_Text_ChipIntro, Route12_Text_ChipDefeat
	msgbox Route12_Text_ChipPostBattle, MSGBOX_AUTOCLOSE
	end

Route12_Text_ChipIntro::
    .string "Paciència.\n"
    .string "Pescar és un joc d'espera.$"

Route12_Text_ChipDefeat::
    .string "Se m'ha escapat!$"

Route12_Text_ChipPostBattle::
    .string "Amb una canya millor, podria\n"
    .string "pescar Pokémon millors…$"

Route12_EventScript_Hank::
    trainerbattle_single TRAINER_FISHERMAN_HANK, Route12_Text_HankIntro, Route12_Text_HankDefeat
    msgbox Route12_Text_HankPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_Text_HankIntro::
    .string "El boig de la pesca contra el\n"
    .string "nen dels Pokémon!$"

Route12_Text_HankDefeat::
    .string "Ha estat massa!$"

Route12_Text_HankPostBattle::
    .string "Suposo que fas bé el que\n"
    .string "t'agrada.\p"
    .string "Bé, m'has guanyat als Pokémon,\n"
    .string "però no em guanyaràs pescant.$"

Route12_EventScript_Elliot::
    trainerbattle_single TRAINER_FISHERMAN_ELLIOT, Route12_Text_ElliotIntro, Route12_Text_ElliotDefeat
    msgbox Route12_Text_ElliotPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_Text_ElliotIntro::
    .string "M'encanta pescar, no m'entenguis\n"
    .string "malament.\p"
    .string "Però no em vindria malament\n"
    .string "tenir més feina.$"

Route12_Text_ElliotDefeat::
    .string "No és fàcil…$"

Route12_Text_ElliotPostBattle::
    .string "No passa res.\n"
    .string "Perdre ja no em molesta.$"

Route12_EventScript_Jes::
    trainerbattle_double TRAINER_YOUNG_COUPLE_GIA_JES, Route12_Text_JesIntro, Route12_Text_JesDefeat, Route12_Text_JesNotEnoughMons
    msgbox Route12_Text_JesPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_Text_JesIntro::
    .string "Jes: Si guanyo, li demanaré\n"
    .string "matrimoni a la Gia.$"

Route12_Text_JesDefeat::
    .string "Jes: Oh, si us plau, per què\n"
    .string "no ens heu deixat guanyar?$"

Route12_Text_JesPostBattle::
    .string "Jes: Oh, Gia, perdona'm,\n"
    .string "amor meu!$"

Route12_Text_JesNotEnoughMons::
    .string "Jes: La Gia i jo, serem junts\n"
    .string "per sempre.\p"
    .string "No combatrem si no tens\n"
    .string "dos Pokémon.$"

Route12_EventScript_Gia::
    trainerbattle_double TRAINER_YOUNG_COUPLE_GIA_JES, Route12_Text_GiaIntro, Route12_Text_GiaDefeat, Route12_Text_GiaNotEnoughMons
    msgbox Route12_Text_GiaPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_Text_GiaIntro::
    .string "Gia: Ei, Jes…\p"
    .string "Si guanyem, em casaré amb tu!$"

Route12_Text_GiaDefeat::
    .string "Gia: Oh, però per què?$"

Route12_Text_GiaPostBattle::
    .string "Gia: Jes, ximple!\n"
    .string "Ho has arruïnat!$"

Route12_Text_GiaNotEnoughMons::
    .string "Gia: No puc combatre sense\n"
    .string "el meu Jes!\p"
    .string "No tens un Pokémon més?$"

Route12_EventScript_Justin::
    trainerbattle_single TRAINER_CAMPER_JUSTIN, Route12_Text_JustinIntro, Route12_Text_JustinDefeat
    msgbox Route12_Text_JustinPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_Text_JustinIntro::
    .string "Busco una Pedra Lunar.\n"
    .string "N'has trobat cap?$"

Route12_Text_JustinDefeat::
    .string "Ai!$"

Route12_Text_JustinPostBattle::
    .string "Hauria pogut fer evolucionar\n"
    .string "el meu Pokémon amb una Pedra\l"
    .string "Lunar.\p"
    .string "Segur que hauria guanyat.$"

Route12_EventScript_Andrew::
    trainerbattle_single TRAINER_FISHERMAN_ANDREW, Route12_Text_AndrewIntro, Route12_Text_AndrewDefeat
    msgbox Route12_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_Text_AndrewIntro::
    .string "Què es pesca?\p"
    .string "Mai se sap què pots\n"
    .string "atrapar!$"

Route12_Text_AndrewDefeat::
    .string "S'ha escapat!$"

Route12_Text_AndrewPostBattle::
    .string "Que si Magikarp?\p"
    .string "Sí, en pesco tot el temps.\n"
    .string "Però, noi, que són febles.$"

Route12_EventScript_ItemIron::
    finditem ITEM_IRON, 1
    release
    end

Route12_EventScript_ItemTM48::
    finditem ITEM_TM48, 1
    release
    end

Route12_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end


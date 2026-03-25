Route25_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route25_OnResume
	.byte 0

Route25_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route25_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route25_EventScript_SeaCottageSign::
	msgbox Route25_Text_SeaCottageSign, MSGBOX_SIGN
	end

Route25_Text_SeaCottageSign::
    .string "Caseta del Mar\n"
    .string "Aquí viu en Bill!$"

Route25_EventScript_Man::
	msgbox Route25_Text_AreYouHereAlone, MSGBOX_NPC
	end

Route25_Text_AreYouHereAlone::
    .string "Hola, ets aquí sol?\p"
    .string "Si ets al cap de Cerulean…\n"
    .string "Hauria de ser en parella.$"

Route25_EventScript_Beauty::
	msgbox Route25_Text_MistyHighHopesAboutThisPlace, MSGBOX_NPC
	release
	end

Route25_Text_MistyHighHopesAboutThisPlace::
    .string "Aquest cap és un lloc famós\n"
    .string "per a cites.\p"
    .string "La Misty, la Líder de Gimnàs,\n"
    .string "té grans esperances en aquest\l"
    .string "lloc.$"

Route25_EventScript_Franklin::
	trainerbattle_single REMATCHABLE_TRAINER_HIKER_FRANKLIN_1, Route25_Text_FranklinIntro, Route25_Text_FranklinDefeat, Route25_EventScript_RegisterFranklinAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route25_EventScript_FranklinRematch
	msgbox Route25_Text_FranklinPostBattle, MSGBOX_DEFAULT
	release
	end

Route25_Text_FranklinIntro::
    .string "Acabo de baixar del Mt. Moon,\n"
    .string "però encara tinc energia!$"

Route25_Text_FranklinDefeat::
    .string "T'has esforçat!$"

Route25_Text_FranklinPostBattle::
    .string "Caram!\n"
    .string "Un Zubat em va mossegar allà.$"

Route25_EventScript_RegisterFranklinAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route25_Text_FranklinRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_HIKER_FRANKLIN_1
	release
	end

Route25_Text_FranklinRegister:
	.string "Hmm...\p"
	.string "Potser no estic tan descansat\n"
	.string "com pensava...\p"
	.string "Fem la revenja algun dia!$"

Route25_EventScript_FranklinRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_HIKER_FRANKLIN_1, Route25_Text_FranklinRematchIntro, Route25_Text_FranklinDefeat
	msgbox Route25_Text_FranklinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_FranklinRematchIntro::
	.string "Ei, {PLAYER}!\n"
	.string "Encara tinc energia!\p"
	.string "Fem una altra ronda!$"

Route25_Text_FranklinRematchPostBattle::
	.string "Potser encara estic marejat per\n"
	.string "la mossegada del Zubat!$"


Route25_EventScript_Joey::
	trainerbattle_single TRAINER_YOUNGSTER_JOEY, Route25_Text_JoeyIntro, Route25_Text_JoeyDefeat
	msgbox Route25_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_JoeyIntro::
    .string "Els entrenadors locals vénen\n"
    .string "aquí a practicar.$"

Route25_Text_JoeyDefeat::
    .string "No estàs malament.$"

Route25_Text_JoeyPostBattle::
    .string "Tots els Pokémon tenen febleses.\n"
    .string "Fins i tot els més forts.\p"
    .string "Per això el millor és criar\n"
    .string "Pokémon de tipus diferents.$"


Route25_EventScript_Wayne::
	trainerbattle_single TRAINER_HIKER_WAYNE, Route25_Text_WayneIntro, Route25_Text_WayneDefeat
	msgbox Route25_Text_WaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_WayneIntro::
    .string "Vas a veure en Bill?\n"
    .string "Primer, lluitem!$"

Route25_Text_WayneDefeat::
    .string "Ets alguna cosa.$"

Route25_Text_WaynePostBattle::
    .string "El camí de baix és una drecera\n"
    .string "cap a Ciutat Cerulean.$"

Route25_EventScript_Dan::
	trainerbattle_single TRAINER_YOUNGSTER_DAN, Route25_Text_DanIntro, Route25_Text_DanDefeat
	msgbox Route25_Text_DanPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_DanIntro::
    .string "El pare em va portar a una\n"
    .string "gran festa al S.S. Anne\l"
    .string "a Ciutat Vermilion.$"

Route25_Text_DanDefeat::
    .string "No estic enfadat!$"

Route25_Text_DanPostBattle::
    .string "Al S.S. Anne vaig veure\n"
    .string "entrenadors de tot el món.$"

Route25_EventScript_Kelsey::
	trainerbattle_single TRAINER_PICNICKER_KELSEY, Route25_Text_KelseyIntro, Route25_Text_KelseyDefeat
	msgbox Route25_Text_KelseyPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_KelseyIntro::
    .string "Hola!\n"
    .string "El meu xicot és genial!$"

Route25_Text_KelseyDefeat::
    .string "No estic en la millor forma…$"

Route25_Text_KelseyPostBattle::
    .string "M'agradaria que el meu xicot\n"
    .string "fos tan bo com tu.$"

Route25_EventScript_Nob::
	trainerbattle_single TRAINER_HIKER_NOB, Route25_Text_NobIntro, Route25_Text_NobDefeat
	msgbox Route25_Text_NobPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_NobIntro::
    .string "Vaig a veure la col·lecció d'un\n"
    .string "PokèManíac al cap.$"

Route25_Text_NobDefeat::
    .string "M'has enxampat bé!$"

Route25_Text_NobPostBattle::
    .string "El PokèManíac fa honor al\n"
    .string "seu nom.\p"
    .string "La seva col·lecció inclou moltes\n"
    .string "espècies rares de Pokémon.$"

Route25_EventScript_Flint::
	trainerbattle_single TRAINER_CAMPER_FLINT, Route25_Text_FlintIntro, Route25_Text_FlintDefeat
	msgbox Route25_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_FlintIntro::
    .string "Sóc un tio genial.\n"
    .string "Tinc xicota!$"

Route25_Text_FlintDefeat::
    .string "Oh, vaja…$"

Route25_Text_FlintPostBattle::
    .string "Bé.\n"
    .string "La meva xicota m'animarà.$"

Route25_EventScript_Chad::
	trainerbattle_single TRAINER_YOUNGSTER_CHAD, Route25_Text_ChadIntro, Route25_Text_ChadDefeat
	msgbox Route25_Text_ChadPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_ChadIntro::
    .string "Tenia un pressentiment…\n"
    .string "Sabia que havia de lluitar!$"

Route25_Text_ChadDefeat::
    .string "Sabia que perdria!$"

Route25_Text_ChadPostBattle::
    .string "Si el teu Pokémon es confon,\n"
    .string "canvia'l.\p"
    .string "És una bona tàctica.$"

Route25_EventScript_Haley::
	trainerbattle_single TRAINER_LASS_HALEY, Route25_Text_HaleyIntro, Route25_Text_HaleyDefeat
	msgbox Route25_Text_HaleyPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_HaleyIntro::
    .string "La meva amiga té molts Pokémon\n"
    .string "bufons. Tinc tanta enveja!$"

Route25_Text_HaleyDefeat::
    .string "Ja no tinc tanta enveja!$"

Route25_Text_HaleyPostBattle::
    .string "Vens del Mt. Moon?\n"
    .string "Em pots donar un Clefairy?$"





.set LOCALID_FUGITIVE, 12

Route20_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route20_OnResume
	.byte 0

Route20_OnTransition:
	call_if_unset FLAG_STOPPED_SEAFOAM_B3F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB3F
	call_if_unset FLAG_STOPPED_SEAFOAM_B4F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB4F
	call Common_EventScript_GetDayOrNight
	end

Route20_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route20_EventScript_ResetSeafoamBouldersForB3F::
	clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_1
	clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_2
	return

Route20_EventScript_ResetSeafoamBouldersForB4F::
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_3
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_4
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_5
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_6
	setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_2
	return

Route20_EventScript_SeafoamIslandsSign::
	msgbox Route20_Text_SeafoamIslands, MSGBOX_SIGN
	end

Route20_Text_SeafoamIslands::
    .string "Illes Seafoam$"

Route20_EventScript_Barry::
	trainerbattle_single TRAINER_SWIMMER_MALE_BARRY, Route20_Text_BarryIntro, Route20_Text_BarryDefeat
	msgbox Route20_Text_BarryPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_BarryIntro::
    .string "L'aigua és poc fonda aquí.\n"
    .string "Hi ha molta gent nedant.$"

Route20_Text_BarryDefeat::
    .string "Splash!$"

Route20_Text_BarryPostBattle::
    .string "M'agradaria anar sobre un Pokémon.\n"
    .string "Segur que no estàs cansat.$"

Route20_EventScript_Dean::
	trainerbattle_single TRAINER_SWIMMER_MALE_DEAN, Route20_Text_DeanIntro, Route20_Text_DeanDefeat
	msgbox Route20_Text_DeanPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_DeanIntro::
    .string "Mira el meu físic musculat!$"

Route20_Text_DeanDefeat::
    .string "Fluixet!$"

Route20_Text_DeanPostBattle::
    .string "Hauria d'haver musculat els\n"
    .string "meus Pokémon, no a mi!$"

Route20_EventScript_Darrin::
	trainerbattle_single TRAINER_SWIMMER_MALE_DARRIN, Route20_Text_DarrinIntro, Route20_Text_DarrinDefeat
	msgbox Route20_Text_DarrinPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_DarrinIntro::
    .string "Per què vas sobre un Pokémon?\n"
    .string "No saps nedar?$"

Route20_Text_DarrinDefeat::
    .string "Ai!\n"
    .string "Torpedat!$"

Route20_Text_DarrinPostBattle::
    .string "Anar sobre un Pokémon sí que\n"
    .string "sembla divertit!$"

Route20_EventScript_Slowbronite::
	finditem ITEM_SLOWBRONITE, 1
	release
	end

Route20_EventScript_Tiffany::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_TIFFANY, Route20_Text_TiffanyIntro, Route20_Text_TiffanyDefeat
	msgbox Route20_Text_TiffanyPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_TiffanyIntro::
    .string "M'encanta flotar amb els peixos\n"
    .string "entre les onades.$"

Route20_Text_TiffanyDefeat::
    .string "Ai!$"

Route20_Text_TiffanyPostBattle::
    .string "Vols flotar amb mi?$"

Route20_EventScript_Nora::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_NORA, Route20_Text_NoraIntro, Route20_Text_NoraDefeat
	msgbox Route20_Text_NoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_NoraIntro::
    .string "El meu xicot em va regalar\n"
    .string "perles grans.$"

Route20_Text_NoraDefeat::
    .string "Oh, no!\n"
    .string "Les meves perles eren dins!$"

Route20_Text_NoraPostBattle::
    .string "Les meves perles creixeran dins\n"
    .string "de Cloyster?$"

Route20_EventScript_Melissa::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_MELISSA, Route20_Text_MelissaIntro, Route20_Text_MelissaDefeat
	msgbox Route20_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_MelissaIntro::
    .string "Cinnabar, a l'oest, té un\n"
    .string "laboratori de Pokémon.\p"
    .string "El meu pare hi treballa.$"

Route20_Text_MelissaDefeat::
    .string "Espera!\n"
    .string "Se suposa que has d'esperar!$"

Route20_Text_MelissaPostBattle::
    .string "Cinnabar és una illa volcànica.\p"
    .string "He sentit que va sorgir del mar\n"
    .string "quan un volcà va erupcionar.$"

Route20_EventScript_Shirley::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_SHIRLEY, Route20_Text_ShirleyIntro, Route20_Text_ShirleyDefeat
	msgbox Route20_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_ShirleyIntro::
    .string "Seafoam és un lloc tranquil.\n"
    .string "Estic de vacances.$"

Route20_Text_ShirleyDefeat::
    .string "Para ja!$"

Route20_Text_ShirleyPostBattle::
    .string "Hi ha una caverna enorme sota\n"
    .string "aquesta illa.$"

Route20_EventScript_Missy::
	trainerbattle_single TRAINER_PICNICKER_MISSY, Route20_Text_MissyIntro, Route20_Text_MissyDefeat
	msgbox Route20_Text_MissyPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_MissyIntro::
    .string "He vingut nedant des de l'Illa\n"
    .string "Cinnabar. No ha estat fàcil.$"

Route20_Text_MissyDefeat::
    .string "Quina decepció!$"

Route20_Text_MissyPostBattle::
    .string "Els Pokémon han pres una\n"
    .string "mansió abandonada a Cinnabar.\p"
    .string "Ara l'anomenen la Mansió\n"
    .string "Pokémon.$"

Route20_EventScript_Irene::
	trainerbattle_single TRAINER_PICNICKER_IRENE, Route20_Text_IreneIntro, Route20_Text_IreneDefeat
	msgbox Route20_Text_IrenePostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_IreneIntro::
    .string "Tu també estàs de vacances?$"

Route20_Text_IreneDefeat::
    .string "Sense pietat!$"

Route20_Text_IrenePostBattle::
    .string "Seafoam era una sola illa en\n"
    .string "el passat llunyà.$"

Route20_EventScript_Roger::
	trainerbattle_single REMATCHABLE_TRAINER_DRAGON_TAMER_ROGER_1, Route20_Text_RogerIntro, Route20_Text_RogerDefeat, Route20_EventScript_RegisterRogerAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route20_EventScript_RogerRematch
	msgbox Route20_Text_RogerPostBattle, MSGBOX_DEFAULT
	release
	end

Route20_Text_RogerIntro::
    .string "No arribaràs mai a l'Alt\n"
    .string "Comandament amb aquest equip!$"

Route20_Text_RogerDefeat::
    .string "No! Ara mai coneixeré en Lance!$"

Route20_Text_RogerPostBattle::
    .string "Espera, vols dir que Gyarados\n"
    .string "no és de tipus Drac?$"

Route20_EventScript_RegisterRogerAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route20_Text_RogerRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_DRAGON_TAMER_ROGER_1
	release
	end

Route20_Text_RogerRegister:
	.string "Ha! T'he deixat guanyar...\p"
	.string "Truca'm quan vulguis un\n"
	.string "combat de debò.$"

Route20_EventScript_RogerRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_DRAGON_TAMER_ROGER_1, Route20_Text_RogerRematchIntro, Route20_Text_RogerDefeat
	msgbox Route20_Text_RogerRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_RogerRematchIntro::
	.string "T'esclafar amb els meus\n"
	.string "Pokémon Drac aquest cop!$"

Route20_Text_RogerRematchPostBattle::
	.string "Gyarados no és tipus Drac, però\n"
	.string "pot aprendre moviments de Drac!$"

Route20_EventScript_Camper::
	lock
	faceplayer
	msgbox Route20_Text_MistyTrainsHere
	release
	end

Route20_Text_MistyTrainsHere::
    .string "Entrenadors forts i Pokémon\n"
    .string "d'Aigua són habituals aquí.\p"
    .string "Diuen que Misty del Gimnàs\n"
    .string "de Cerulean entrena aquí.$"

Route20_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end

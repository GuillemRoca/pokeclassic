.set LOCALID_FUGITIVE, 9

Route21_South_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route21_South_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route21_South_OnResume
	.byte 0

Route21_South_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route21_South_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route21_South_EventScript_Johan::
	trainerbattle_single REMATCHABLE_TRAINER_JUGGLER_JOHAN_1, Route21_South_Text_JohanIntro, Route21_South_Text_JohanDefeat, Route21_South_EventScript_RegisterJohanAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route21_South_EventScript_JohanRematch
	msgbox Route21_South_Text_JohanPostBattle, MSGBOX_DEFAULT
	release
	end

Route21_South_Text_JohanIntro::
    .string "Mira com faig malabars amb\n"
    .string "totes aquestes Poké Balls!$"

Route21_South_Text_JohanDefeat::
    .string "Se m'han caigut les boles...$"

Route21_South_Text_JohanPostBattle::
    .string "Només els entrenadors més forts\n"
    .string "arriben a l'Alt Comandament.$"

Route21_South_EventScript_RegisterJohanAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route21_South_Text_JohanRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_JUGGLER_JOHAN_1
	release
	end

Route21_South_Text_JohanRegister:
	.string "M'he teletransportat aquí..\p"
	.string "però no em queden PP...\p"
	.string "Et puc trucar per tornar?$"

Route21_South_EventScript_JohanRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_JUGGLER_JOHAN_1, Route21_South_Text_JohanRematchIntro, Route21_South_Text_JohanDefeat
	msgbox Route21_South_Text_JohanRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_South_Text_JohanRematchIntro::
	.string "He estat practicant malabars!$"

Route21_South_Text_JohanRematchPostBattle::
	.string "Si no hagués deixat els estudis,\n"
	.string "podria treballar a Silph!\p"
	.string "Però hauria estat feliç si no\n"
	.string "estigués aquí fent malabars?\p"
	.string "Qui ho sap...$"


Route21_South_EventScript_Claude::
	trainerbattle_single TRAINER_FISHERMAN_CLAUDE, Route21_South_Text_ClaudeIntro, Route21_South_Text_ClaudeDefeat
	msgbox Route21_South_Text_ClaudePostBattle, MSGBOX_AUTOCLOSE
	end

Route21_South_Text_ClaudeIntro::
	.string "Ei, no espantis els peixos!$"

Route21_South_Text_ClaudeDefeat::
	.string "Perdona! Estic frustrat de\n"
	.string "no pescar res.$"

Route21_South_Text_ClaudePostBattle::
	.string "No he pescat res de res.\n"
	.string "Potser això és en realitat\l"
	.string "una piscina gegant?$"

Route21_South_EventScript_Nolan::
	trainerbattle_single TRAINER_FISHERMAN_NOLAN, Route21_South_Text_NolanIntro, Route21_South_Text_NolanDefeat
	msgbox Route21_South_Text_NolanPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_South_Text_NolanIntro::
	.string "Fes-me companyia fins que piqui.$"

Route21_South_Text_NolanDefeat::
	.string "Això ha cremat una mica de temps.$"

Route21_South_Text_NolanPostBattle::
	.string "Oh, espera!\n"
	.string "Tinc picada! Sí!$"

Route21_South_EventScript_Jack::
	trainerbattle_single TRAINER_SWIMMER_MALE_JACK, Route21_South_Text_JackIntro, Route21_South_Text_JackDefeat
	msgbox Route21_South_Text_JackPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_South_Text_JackIntro::
	.string "He atrapat els Pokémon al mar.$"

Route21_South_Text_JackDefeat::
	.string "Immersió!!\n"
	.string "Avall!!$"

Route21_South_Text_JackPostBattle::
	.string "On has atrapat els teus Pokémon?$"

Route21_South_EventScript_Jerome::
	trainerbattle_single TRAINER_SWIMMER_MALE_JEROME, Route21_South_Text_JeromeIntro, Route21_South_Text_JeromeDefeat
	msgbox Route21_South_Text_JeromePostBattle, MSGBOX_AUTOCLOSE
	end

Route21_South_Text_JeromeIntro::
	.string "Ara estic en un triatló.$"

Route21_South_Text_JeromeDefeat::
	.string "Buf…\n"
	.string "Buf… Buf…$"

Route21_South_Text_JeromePostBattle::
	.string "Estic destrossat! Però encara\n"
	.string "em queden la cursa de bici\l"
	.string "i la marató!$"

Route21_South_EventScript_Roland::
	trainerbattle_single TRAINER_SWIMMER_MALE_ROLAND, Route21_South_Text_RolandIntro, Route21_South_Text_RolandDefeat
	msgbox Route21_South_Text_RolandPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_South_Text_RolandIntro::
	.string "Ahh!\n"
	.string "Sent el sol i el vent!$"

Route21_South_Text_RolandDefeat::
	.string "Au!\n"
	.string "He perdut!$"

Route21_South_Text_RolandPostBattle::
	.string "Estic cremat pel sol!$"

Route21S_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end

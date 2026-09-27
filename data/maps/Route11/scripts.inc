.set LOCALID_FUGITIVE, 18

Route11_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route11_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route11_OnResume
	.byte 0

Route11_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route11_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route11_EventScript_DiglettsCaveSign::
	msgbox Route11_Text_DiglettsCave, MSGBOX_SIGN
	end

Route11_Text_DiglettsCave::
    .string "Cova Diglett$"

Route11_EventScript_Hugo::
	trainerbattle_single REMATCHABLE_TRAINER_GAMBLER_HUGO_1, Route11_Text_HugoIntro, Route11_Text_HugoDefeat, Route11_EventScript_RegisterHugoAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route11_EventScript_HugoRematch
	msgbox Route11_Text_HugoPostBattle, MSGBOX_DEFAULT
	release
	end

Route11_Text_HugoIntro::
    .string "Guanyar, perdre o empatar!$"

Route11_Text_HugoDefeat::
    .string "Atxa!\n"
    .string "No ha anat bé!$"

Route11_Text_HugoPostBattle::
    .string "Pokémon és vida!\n"
    .string "I viure és jugar!$"

Route11_EventScript_RegisterHugoAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route11_Text_HugoRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_GAMBLER_HUGO_1
	release
	end

Route11_Text_HugoRegister:
	.string "Ei, fem la revenja algun dia?\n"
	.string "Potser tindré més sort.$"

Route11_EventScript_HugoRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_GAMBLER_HUGO_1, Route11_Text_HugoRematchIntro, Route11_Text_HugoDefeat
	msgbox Route11_Text_HugoRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_HugoRematchIntro::
	.string "Guanyar, perdre o empatar!\n"
	.string "Ara, la revenja!$"

Route11_Text_HugoRematchPostBattle::
	.string "Au! Se m'ha acabat la ratxa.$"

Route11_EventScript_Jasper::
	trainerbattle_single TRAINER_GAMBLER_JASPER, Route11_Text_JasperIntro, Route11_Text_JasperDefeat
	msgbox Route11_Text_JasperPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_JasperIntro::
    .string "Competició!\n"
    .string "No en tinc mai prou!$"

Route11_Text_JasperDefeat::
    .string "Hi era a prop!$"

Route11_Text_JasperPostBattle::
    .string "No pots ser un covard al món\n"
    .string "dels Pokémon!$"

Route11_EventScript_Bernie::
	trainerbattle_single REMATCHABLE_TRAINER_ENGINEER_BERNIE_1, Route11_Text_BernieIntro, Route11_Text_BernieDefeat, Route11_EventScript_RegisterBernieAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route11_EventScript_BernieRematch
	msgbox Route11_Text_BerniePostBattle, MSGBOX_DEFAULT
	release
	end

Route11_Text_BernieIntro::
    .string "Compte amb els cables vius!$"

Route11_Text_BernieDefeat::
    .string "Uau!\n"
    .string "Quina espurna!$"

Route11_Text_BerniePostBattle::
    .string "Bé, millor que torni a la feina.$"

Route11_EventScript_RegisterBernieAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route11_Text_BernieRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_ENGINEER_BERNIE_1
	release
	end

Route11_Text_BernieRegister:
	.string "El proper cop que faci una pausa,\n"
	.string "fem la revenja.$"

Route11_EventScript_BernieRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_ENGINEER_BERNIE_1, Route11_Text_BernieRematchIntro, Route11_Text_BernieDefeat
	msgbox Route11_Text_BernieRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_BernieRematchIntro::
	.string "Uixi! Hora de la pausa.\n"
	.string "Fem la revenja?$"

Route11_Text_BernieRematchPostBattle::
	.string "Bé, de tornada a la rutina.$"

Route11_EventScript_Braxton::
	trainerbattle_single TRAINER_ENGINEER_BRAXTON, Route11_Text_BraxtonIntro, Route11_Text_BraxtonDefeat
	msgbox Route11_Text_BraxtonPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_BraxtonIntro::
    .string "Compte!\n"
    .string "Estic estirant cables!$"

Route11_Text_BraxtonDefeat::
    .string "Ha estat electritzant!$"

Route11_Text_BraxtonPostBattle::
    .string "Escampeu la veu d'estalviar\n"
    .string "energia!$"

Route11_EventScript_Eddie::
	trainerbattle_single TRAINER_YOUNGSTER_EDDIE, Route11_Text_EddieIntro, Route11_Text_EddieDefeat
	msgbox Route11_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_EddieIntro::
    .string "Va, però sense trampes!$"

Route11_Text_EddieDefeat::
    .string "Eh?\n"
    .string "Això no és just!$"

Route11_Text_EddiePostBattle::
    .string "Ho he donat tot.\n"
    .string "No me'n penedeixo.$"

Route11_EventScript_Dillon::
	trainerbattle_single TRAINER_YOUNGSTER_DILLON, Route11_Text_DillonIntro, Route11_Text_DillonDefeat
	msgbox Route11_Text_DillonPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_DillonIntro::
    .string "Acabo de ser entrenador.\n"
    .string "Però crec que puc guanyar.$"

Route11_Text_DillonDefeat::
    .string "Els meus Pokémon no han pogut…\n"
    .string "No han crescut prou?$"

Route11_Text_DillonPostBattle::
    .string "I ara què?\n"
    .string "Deixa'm en pau!$"

Route11_EventScript_Yasu::
	trainerbattle_single TRAINER_YOUNGSTER_YASU, Route11_Text_YasuIntro, Route11_Text_YasuDefeat
	msgbox Route11_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_YasuIntro::
    .string "Sóc el millor de la meva classe.\n"
    .string "Entreno cada matí.$"

Route11_Text_YasuDefeat::
    .string "Llamps!\n"
    .string "Els meus Pokémon han de ser\l"
    .string "més forts!$"

Route11_Text_YasuPostBattle::
    .string "Hi ha un Pokémon gras que baixa\n"
    .string "de les muntanyes.\p"
    .string "Segur que seria fort si\n"
    .string "l'atrapes.$"

Route11_EventScript_Dave::
	trainerbattle_single TRAINER_YOUNGSTER_DAVE, Route11_Text_DaveIntro, Route11_Text_DaveDefeat
	msgbox Route11_Text_DavePostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_DaveIntro::
    .string "He criat els meus Pokémon amb\n"
    .string "cura. Ja haurien d'estar a punt!$"

Route11_Text_DaveDefeat::
    .string "Adéu!\n"
    .string "Gràcies i adéu!$"

Route11_Text_DavePostBattle::
    .string "Tsc…\n"
    .string "Millor que en busqui de més forts!$"

Route11_EventScript_Dirk::
	trainerbattle_single TRAINER_GAMBLER_DIRK, Route11_Text_DirkIntro, Route11_Text_DirkDefeat
	msgbox Route11_Text_DirkPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_DirkIntro::
    .string "Fwahaha!\n"
    .string "No he perdut mai!$"

Route11_Text_DirkDefeat::
    .string "La meva primera derrota!$"

Route11_Text_DirkPostBattle::
    .string "Només has tingut sort, res més.$"

Route11_EventScript_Darian::
	trainerbattle_single TRAINER_GAMBLER_DARIAN, Route11_Text_DarianIntro, Route11_Text_DarianDefeat
	msgbox Route11_Text_DarianPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_DarianIntro::
    .string "No he guanyat mai…$"

Route11_Text_DarianDefeat::
    .string "Ja m'ho veia venir…$"

Route11_Text_DarianPostBattle::
    .string "He tingut mala sort, com sempre.$"


Route11_EventScript_ItemGreatBall::
	finditem ITEM_GREAT_BALL, 1
	release
	end

Route11_EventScript_ItemXDefend::
	finditem ITEM_X_DEFEND, 1
	release
	end

Route11_EventScript_ItemAwakening::
	finditem ITEM_AWAKENING, 1
	release
	end

Route11_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end

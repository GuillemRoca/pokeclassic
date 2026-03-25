.set LOCALID_FUGITIVE, 17

Route14_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route14_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route14_OnResume
	.byte 0

Route14_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route14_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route14_EventScript_RouteSign::
	msgbox Route14_Text_RouteSign, MSGBOX_SIGN
	end

Route14_Text_RouteSign::
    .string "Ruta 14\n"
    .string "Oest cap a Fuchsia City$"

Route14_EventScript_Malik::
	trainerbattle_single TRAINER_BIKER_MALIK, Route14_Text_MalikIntro, Route14_Text_MalikDefeat
	msgbox Route14_Text_MalikPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_MalikIntro::
    .string "Combat Pokémon?\n"
    .string "Genial! Baralla!$"

Route14_Text_MalikDefeat::
    .string "Escombrat!$"

Route14_Text_MalikPostBattle::
    .string "Ja saps qui guanyaria, tu i jo\n"
    .string "cara a cara!$"

Route14_EventScript_Lukas::
	trainerbattle_single TRAINER_BIKER_LUKAS, Route14_Text_LukasIntro, Route14_Text_LukasDefeat
	msgbox Route14_Text_LukasPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_LukasIntro::
    .string "Va, va.\n"
    .string "Anem, anem, anem!$"

Route14_Text_LukasDefeat::
    .string "Argh!\n"
    .string "He perdut! Fes-te perdedís!$"

Route14_Text_LukasPostBattle::
    .string "Què, què, què?\n"
    .string "Què més vols?$"


Route14_EventScript_Isaac::
	trainerbattle_single TRAINER_BIKER_ISAAC, Route14_Text_IsaacIntro, Route14_Text_IsaacDefeat
	msgbox Route14_Text_IsaacPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_IsaacIntro::
    .string "Necessito matar el temps.\n"
    .string "Calla i combateix.$"

Route14_Text_IsaacDefeat::
    .string "Què?\n"
    .string "Tu!?$"

Route14_Text_IsaacPostBattle::
    .string "Criar Pokémon és un pal, tio.$"

Route14_EventScript_Gerald::
	trainerbattle_single TRAINER_BIKER_GERALD, Route14_Text_GeraldIntro, Route14_Text_GeraldDefeat
	msgbox Route14_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_GeraldIntro::
    .string "Circulem per aquí per l'espai\n"
    .string "obert.$"

Route14_Text_GeraldDefeat::
    .string "Patacada!$"

Route14_Text_GeraldPostBattle::
    .string "Mola que hagis fet els teus\n"
    .string "Pokémon tan forts.\p"
    .string "La força fa la raó!\n"
    .string "I tu ho saps!$"

Route14_EventScript_Donald::
	trainerbattle_single TRAINER_BIRD_KEEPER_DONALD, Route14_Text_DonaldIntro, Route14_Text_DonaldDefeat
	msgbox Route14_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_DonaldIntro::
    .string "Has sentit la llegenda dels\n"
    .string "miratges alats?$"

Route14_Text_DonaldDefeat::
    .string "Per què?\n"
    .string "Per què he perdut?$"

Route14_Text_DonaldPostBattle::
    .string "Bé, els miratges alats són els\n"
    .string "Pokémon ocell llegendaris.\p"
    .string "N'hi ha tres: Articuno,\n"
    .string "Zapdos i Moltres.$"

Route14_EventScript_Benny::
	trainerbattle_single TRAINER_BIRD_KEEPER_BENNY, Route14_Text_BennyIntro, Route14_Text_BennyDefeat
	msgbox Route14_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_BennyIntro::
    .string "No m'anima gaire, però va.\n"
    .string "Endavant!$"

Route14_Text_BennyDefeat::
    .string "Ja m'ho sabia!$"

Route14_Text_BennyPostBattle::
    .string "Guanyar, perdre… És insignificant\n"
    .string "sota aquest cel immens.$"

Route14_EventScript_Carter::
	trainerbattle_single TRAINER_BIRD_KEEPER_CARTER, Route14_Text_CarterIntro, Route14_Text_CarterDefeat
	msgbox Route14_Text_CarterPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_CarterIntro::
    .string "Has de fer servir MTs per\n"
    .string "ensenyar bons moviments.$"

Route14_Text_CarterDefeat::
    .string "Encara no n'hi ha prou.$"

Route14_Text_CarterPostBattle::
    .string "Tens MOs, oi? Els Pokémon no\n"
    .string "oblidaran aquells moviments\l"
    .string "fàcilment.$"


Route14_EventScript_Mitch::
	trainerbattle_single TRAINER_BIRD_KEEPER_MITCH, Route14_Text_MitchIntro, Route14_Text_MitchDefeat
	msgbox Route14_Text_MitchPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_MitchIntro::
    .string "Els meus Pokémon ocell haurien\n"
    .string "d'estar a punt per combatre.$"

Route14_Text_MitchDefeat::
    .string "Encara no estan a punt!$"

Route14_Text_MitchPostBattle::
    .string "Els meus Pokémon ocell necessiten\n"
    .string "aprendre moviments millors.$"

Route14_EventScript_Beck::
	trainerbattle_single TRAINER_BIRD_KEEPER_BECK, Route14_Text_BeckIntro, Route14_Text_BeckDefeat
	msgbox Route14_Text_BeckPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_BeckIntro::
    .string "Venen MTs als Grans Magatzems\n"
    .string "de Celadon.\p"
    .string "Les MTs no són tan rares, però\n"
    .string "poca gent té MOs.$"

Route14_Text_BeckDefeat::
    .string "Ai, quina ràbia!$"

Route14_Text_BeckPostBattle::
    .string "Prova d'ensenyar al Pokémon un\n"
    .string "moviment del seu mateix tipus.\p"
    .string "Això augmenta la potència\n"
    .string "del moviment.$"


Route14_EventScript_Marlon::
	trainerbattle_single TRAINER_BIRD_KEEPER_MARLON, Route14_Text_MarlonIntro, Route14_Text_MarlonDefeat
	msgbox Route14_Text_MarlonPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_MarlonIntro::
    .string "Has ensenyat Volar als teus\n"
    .string "Pokémon ocell?\p"
    .string "Podràs volar pel cel amb ells!$"

Route14_Text_MarlonDefeat::
    .string "Abatut en flames!$"

Route14_Text_MarlonPostBattle::
    .string "Els Pokémon ocell són el meu\n"
    .string "amor. No vull criar res més.$"


Route14_EventScript_Kiri::
	trainerbattle_double TRAINER_TWINS_KIRI_JAN, Route14_Text_KiriIntro, Route14_Text_KiriDefeat, Route14_Text_KiriNotEnoughMons
	msgbox Route14_Text_KiriPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_KiriIntro::
    .string "Kiri: Jan, esforcem-nos molt,\n"
    .string "molt juntes.$"

Route14_Text_KiriDefeat::
    .string "Kiri: Snif…\n"
    .string "Hem perdut, oi?$"

Route14_Text_KiriPostBattle::
    .string "Kiri: Hem perdut per culpa meva?$"

Route14_Text_KiriNotEnoughMons::
    .string "Kiri: Podem combatre si tens\n"
    .string "dos Pokémon.$"


Route14_EventScript_Jan::
	trainerbattle_double TRAINER_TWINS_KIRI_JAN, Route14_Text_JanIntro, Route14_Text_JanDefeat, Route14_Text_JanNotEnoughMons
	msgbox Route14_Text_JanPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_JanIntro::
    .string "Jan: Kiri, endavant!\n"
    .string "Ens hi hem d'esforçar!$"

Route14_Text_JanDefeat::
    .string "Jan: Eeeh!\n"
    .string "No és just!$"

Route14_Text_JanPostBattle::
    .string "Jan: Kiri, no ploris!\n"
    .string "El proper cop ho farem millor.$"

Route14_Text_JanNotEnoughMons::
    .string "Jan: Vols combatre?\n"
    .string "No tens prou Pokémon.$"

Route14_EventScript_BigRoot::
    finditem ITEM_BIG_ROOT, 1
    release
    end

Route14_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end


.set LOCALID_FUGITIVE, 19

Route8_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route8_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route8_OnResume
	.byte 0

Route8_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route8_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route8_EventScript_UndergroundPathSign::
	msgbox Route8_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route8_Text_UndergroundPathSign::
    .string "Camí Subterrani\n"
    .string "Celadon City - Lavender Town$"

Route8_EventScript_Aidan::
	trainerbattle_single REMATCHABLE_TRAINER_SUPER_NERD_AIDAN_1, Route8_Text_AidanIntro, Route8_Text_AidanDefeat, Route8_EventScript_RegisterAidanAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route8_EventScript_AidanRematch
	msgbox Route8_Text_AidanPostBattle, MSGBOX_DEFAULT
	release
	end

Route8_Text_AidanIntro::
    .string "Sembles bo amb Pokémon, però com\n"
    .string "vas de química?$"

Route8_Text_AidanDefeat::
    .string "Au!\n"
    .string "Fusió nuclear!$"

Route8_Text_AidanPostBattle::
    .string "Se'm dóna millor l'escola!$"

Route8_EventScript_RegisterAidanAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route8_Text_AidanRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_SUPER_NERD_AIDAN_1
	release
	end

Route8_Text_AidanRegister:
	.string "Jo et faig classes de química si\n"
	.string "tu em fas classes de Pokémon.$"

Route8_EventScript_AidanRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_SUPER_NERD_AIDAN_1, Route8_Text_AidanRematchIntro, Route8_Text_AidanDefeat
	msgbox Route8_Text_AidanRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_AidanRematchIntro::
	.string "Ei, {PLAYER}!\n"
	.string "Han millorat les teves notes?$"

Route8_Text_AidanRematchPostBattle::
	.string "Hauria d'estudiar en comptes\n"
	.string "de jugar amb Pokémon!$"

Route8_EventScript_Julia::
	trainerbattle_single TRAINER_LASS_JULIA, Route8_Text_JuliaIntro, Route8_Text_JuliaDefeat
	msgbox Route8_Text_JuliaPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_JuliaIntro::
    .string "Quin és un Pokémon rodó, bufó\n"
    .string "i pelut?$"

Route8_Text_JuliaDefeat::
    .string "Para!\p"
    .string "No siguis tan dolent amb Clefairy!$"

Route8_Text_JuliaPostBattle::
    .string "He llegit que Clefairy evoluciona\n"
    .string "quan s'exposa a una Pedra Lunar.\p"
    .string "Ho vaig llegir a una revista\n"
    .string "Pokémon. Serà veritat?$"


Route8_EventScript_Paige::
	trainerbattle_single TRAINER_LASS_PAIGE, Route8_Text_PaigeIntro, Route8_Text_PaigeDefeat
	msgbox Route8_Text_PaigePostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_PaigeIntro::
    .string "M'agraden els Nidoran, els\n"
    .string "col·lecciono!$"

Route8_Text_PaigeDefeat::
    .string "Per què?\n"
    .string "Per què??$"

Route8_Text_PaigePostBattle::
    .string "Quan els Pokémon creixen, es tornen\n"
    .string "lletjos! No haurien d'evolucionar.$"

Route8_EventScript_Andrea::
	trainerbattle_single TRAINER_LASS_ANDREA, Route8_Text_AndreaIntro, Route8_Text_AndreaDefeat
	msgbox Route8_Text_AndreaPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_AndreaIntro::
    .string "Meowth és tan bufó, miau, miau,\n"
    .string "miau!$"

Route8_Text_AndreaDefeat::
    .string "Miaaau!$"

Route8_Text_AndreaPostBattle::
    .string "Crec que Pidgey i Rattata\n"
    .string "també són bufons!$"

Route8_EventScript_Megan::
	trainerbattle_single TRAINER_LASS_MEGAN, Route8_Text_MeganIntro, Route8_Text_MeganDefeat
	msgbox Route8_Text_MeganPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_MeganIntro::
    .string "Devem fer el bonic aquí plantades\n"
    .string "així.$"

Route8_Text_MeganDefeat::
    .string "Mira què has fet als meus pobres\n"
    .string "Pokémon bufons!$"

Route8_Text_MeganPostBattle::
    .string "La policia de Saffron no ens\n"
    .string "deixa passar.\p"
    .string "Sé que fan la seva feina, però\n"
    .string "em sembla injust.$"

Route8_EventScript_Glenn::
	trainerbattle_single TRAINER_SUPER_NERD_GLENN, Route8_Text_GlennIntro, Route8_Text_GlennDefeat
	msgbox Route8_Text_GlennPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_GlennIntro::
    .string "Has d'estar informat.\n"
    .string "Cal estratègia per guanyar!$"

Route8_Text_GlennDefeat::
    .string "No és lògic!$"

Route8_Text_GlennPostBattle::
    .string "Primer Grimer…i…\n"
    .string "…i…després…$"

Route8_EventScript_Leslie::
	trainerbattle_single TRAINER_SUPER_NERD_LESLIE, Route8_Text_LeslieIntro, Route8_Text_LeslieDefeat
	msgbox Route8_Text_LesliePostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_LeslieIntro::
    .string "L'escola és divertida, però els\n"
    .string "Pokémon també.$"

Route8_Text_LeslieDefeat::
    .string "M'has deixat clar que hauria\n"
    .string "de dedicar-me a estudiar.$"

Route8_Text_LesliePostBattle::
    .string "Tenia previst sortir a prendre\n"
    .string "l'aire, però…\p"
    .string "Estem atrapats aquí per culpa\n"
    .string "de les portes de Saffron.$"

Route8_EventScript_Stan::
	trainerbattle_single TRAINER_GAMBLER_STAN, Route8_Text_StanIntro, Route8_Text_StanDefeat
	msgbox Route8_Text_StanPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_StanIntro::
    .string "Molt bé!\n"
    .string "Juguem una partida!$"

Route8_Text_StanDefeat::
    .string "Llamps!\n"
    .string "M'he quedat curt!$"

Route8_Text_StanPostBattle::
    .string "Avui no ha anat bé.$"

Route8_EventScript_Rich::
	trainerbattle_single TRAINER_GAMBLER_RICH, Route8_Text_RichIntro, Route8_Text_RichDefeat
	msgbox Route8_Text_RichPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_RichIntro::
    .string "Sóc un jugador empedreït!$"

Route8_Text_RichDefeat::
    .string "He perdut la gran oportunitat!$"

Route8_Text_RichPostBattle::
    .string "Jugar i els Pokémon són com menjar\n"
    .string "cacauets! No puc parar!$"

Route8_EventScript_Eli::
	trainerbattle_double TRAINER_TWINS_ELI_ANNE, Route8_Text_EliIntro, Route8_Text_EliDefeat, Route8_Text_EliNotEnoughMons
	msgbox Route8_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_EliIntro::
    .string "Eli: El poder bessó és fantàstic.\n"
    .string "Ho sabies?$"

Route8_Text_EliDefeat::
    .string "Eli: Però…\n"
    .string "Hem usat el nostre poder bessó…$"

Route8_Text_EliPostBattle::
    .string "Eli: He atrapat els meus Pokémon\n"
    .string "amb l'Anne!$"

Route8_Text_EliNotEnoughMons::
    .string "Eli: No podem combatre si no\n"
    .string "tens dos Pokémon.$"

Route8_EventScript_Anne::
	trainerbattle_double TRAINER_TWINS_ELI_ANNE, Route8_Text_AnneIntro, Route8_Text_AnneDefeat, Route8_Text_AnneNotEnoughMons
	msgbox Route8_Text_AnnePostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_AnneIntro::
    .string "Anne: Et sorprendrem amb el\n"
    .string "nostre poder bessó!$"

Route8_Text_AnneDefeat::
    .string "Anne: El nostre poder bessó…$"

Route8_Text_AnnePostBattle::
    .string "Anne: Estic criant Pokémon amb\n"
    .string "l'Eli.$"

Route8_Text_AnneNotEnoughMons::
    .string "Anne: Hola, hola! Combatem!\n"
    .string "Però porta dos Pokémon.$"

Route8_EventScript_Ricardo::
	trainerbattle_single TRAINER_BIKER_RICARDO, Route8_Text_RicardoIntro, Route8_Text_RicardoDefeat
	msgbox Route8_Text_RicardoPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_RicardoIntro::
    .string "La meva moto va malament, tio.$"

Route8_Text_RicardoDefeat::
    .string "Ai, tio.\n"
    .string "No estic per això.$"

Route8_Text_RicardoPostBattle::
    .string "Se m'ha enganxat herba als\n"
    .string "radis, tio.$"

Route8_EventScript_Jaren::
	trainerbattle_single TRAINER_BIKER_JAREN, Route8_Text_JarenIntro, Route8_Text_JarenDefeat
	msgbox Route8_Text_JarenPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_JarenIntro::
    .string "Aparta't del camí o t'atropello!$"

Route8_Text_JarenDefeat::
    .string "Vas de debò, nano?$"

Route8_Text_JarenPostBattle::
    .string "No et creguis especial per\n"
    .string "això.$"

Route8_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end

Route9_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route9_OnResume
	.byte 0

Route9_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route9_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route9_EventScript_Alicia::
	trainerbattle_single REMATCHABLE_TRAINER_PICNICKER_ALICIA_1, Route9_Text_AliciaIntro, Route9_Text_AliciaDefeat, Route9_EventScript_RegisterAliciaAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route9_EventScript_AliciaRematch
	msgbox Route9_Text_AliciaPostBattle, MSGBOX_DEFAULT
	release
	end

Route9_Text_AliciaIntro::
    .string "Portes Pokémon amb tu!\n"
    .string "Ets meu!$"

Route9_Text_AliciaDefeat::
    .string "M'has enganyat…$"

Route9_Text_AliciaPostBattle::
    .string "El túnel que ve és completament\n"
    .string "fosc per dins.\p"
    .string "Necessitaràs FLASH per passar-hi.$"

Route9_EventScript_RegisterAliciaAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route9_Text_AliciaRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_PICNICKER_ALICIA_1
	release
	end

Route9_Text_AliciaRegister:
	.string "Enganyar-me ha estat lleig, però\n"
	.string "et perdonaré si em dones el teu\l"
	.string "número de mòbil.$"

Route9_EventScript_AliciaRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_PICNICKER_ALICIA_1, Route9_Text_AliciaRematchIntro, Route9_Text_AliciaDefeat
	msgbox Route9_Text_AliciaRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route9_Text_AliciaRematchIntro::
	.string "Hem de combatre de nou?\n"
	.string "Aquest cop, ets meu!$"

Route9_Text_AliciaRematchPostBattle::
	.string "M'has tornat a enganyar!$"


Route9_EventScript_Brent::
	trainerbattle_single TRAINER_BUG_CATCHER_BRENT, Route9_Text_BrentIntro, Route9_Text_BrentDefeat
	msgbox Route9_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
	end

Route9_Text_BrentIntro::
    .string "Em llevava d'hora cada dia per\n"
    .string "criar Pokémon des de capoll!$"

Route9_Text_BrentDefeat::
    .string "QUÈ?\p"
    .string "Quina pèrdua de temps!$"

Route9_Text_BrentPostBattle::
    .string "He de col·leccionar més que\n"
    .string "insectes per ser més fort…$"

Route9_EventScript_Conner::
    trainerbattle_single TRAINER_BUG_CATCHER_CONNER, Route9_Text_ConnerIntro, Route9_Text_ConnerDefeat
    msgbox Route9_Text_ConnerPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_Text_ConnerIntro::
    .string "Endavant, super Pokémon insecte!$"

Route9_Text_ConnerDefeat::
    .string "Els meus insectes…$"

Route9_Text_ConnerPostBattle::
    .string "Si no t'agraden els Pokémon\n"
    .string "insecte, em molestes!$"

Route9_EventScript_Chris::
    trainerbattle_single TRAINER_CAMPER_CHRIS, Route9_Text_ChrisIntro, Route9_Text_ChrisDefeat
    msgbox Route9_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_Text_ChrisIntro::
    .string "Qui és aquell que camina amb\n"
    .string "aquells Pokémon tan macos?$"

Route9_Text_ChrisDefeat::
    .string "KO!$"

Route9_Text_ChrisPostBattle::
    .string "Segueix caminant!$"

Route9_EventScript_Drew::
    trainerbattle_single TRAINER_CAMPER_DREW, Route9_Text_DrewIntro, Route9_Text_DrewDefeat
    msgbox Route9_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_Text_DrewIntro::
    .string "Agafo el Túnel Roca per anar\n"
    .string "a Lavender…$"

Route9_Text_DrewDefeat::
    .string "No estic a l'alçada…$"

Route9_Text_DrewPostBattle::
    .string "Tu també vas al Túnel Roca?$"

Route9_EventScript_Caitlin::
    trainerbattle_single TRAINER_PICNICKER_CAITLIN, Route9_Text_CaitlinIntro, Route9_Text_CaitlinDefeat
    msgbox Route9_Text_CaitlinPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_Text_CaitlinIntro::
    .string "No t'atreveixis a subestimar-me!$"

Route9_Text_CaitlinDefeat::
    .string "No!\n"
    .string "Ets massa fort.$"

Route9_Text_CaitlinPostBattle::
    .string "Tens talent, sens dubte.\n"
    .string "Bona sort!$"

Route9_EventScript_Alan::
    trainerbattle_single TRAINER_HIKER_ALAN, Route9_Text_AlanIntro, Route9_Text_AlanDefeat
    msgbox Route9_Text_AlanPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_Text_AlanIntro::
    .string "Hahahaha!\n"
    .string "Vine, que t'espero!$"

Route9_Text_AlanDefeat::
    .string "Hahahaha!\n"
    .string "M'has guanyat net!$"

Route9_Text_AlanPostBattle::
    .string "Hahahaha!\n"
    .string "La gent forta sempre riu!$"

Route9_EventScript_Brice::
    trainerbattle_single TRAINER_HIKER_BRICE, Route9_Text_BriceIntro, Route9_Text_BriceDefeat
    msgbox Route9_Text_BricePostBattle, MSGBOX_AUTOCLOSE
    end

Route9_Text_BriceIntro::
    .string "Hahaha!\n"
    .string "Ets un durillo!$"

Route9_Text_BriceDefeat::
    .string "Què dius?$"

Route9_Text_BricePostBattle::
    .string "Hahaha!\n"
    .string "Els nens han de ser durs!$"

Route9_EventScript_Jeremy::
    trainerbattle_single TRAINER_HIKER_JEREMY, Route9_Text_JeremyIntro, Route9_Text_JeremyDefeat
    msgbox Route9_Text_JeremyPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_Text_JeremyIntro::
    .string "Bwahaha!\n"
    .string "Genial! M'avorria, eh!$"

Route9_Text_JeremyDefeat::
    .string "Continua, eh!\p"
    .string "Oh, espera.\n"
    .string "No em queden Pokémon!$"

Route9_Text_JeremyPostBattle::
    .string "Has tingut valor d'enfrontar-te\n"
    .string "a mi, eh?$"

Route9_EventScript_RouteSign::
	msgbox Route9_Text_RouteSign, MSGBOX_SIGN
	end

Route9_Text_RouteSign::
    .string "Ruta 9\n"
    .string "Ciutat Cerúlia - Túnel Roca$"

Route9_EventScript_ItemBurnHeal::
	finditem ITEM_BURN_HEAL, 1
	release
	end

Route9_EventScript_ItemTM40::
    finditem ITEM_TM40, 1
    release
    end

.set LOCALID_FUGITIVE, 18

Route10_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route10_OnResume
	.byte 0

Route10_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route10_OnResume:
	call Common_EventScript_GetDayOrNight
	end


Route10_EventScript_NorthRockTunnelSign::
	msgbox Route10_Text_RockTunnelDetourToLavender, MSGBOX_SIGN
	end

Route10_Text_RockTunnelDetourToLavender::
    .string "Túnel Roca\n"
    .string "Drecera a Lavender Town$"

Route10_EventScript_SouthRockTunnelSign::
	msgbox Route10_Text_RockTunnel, MSGBOX_SIGN
	end

Route10_Text_RockTunnel::
    .string "Túnel Roca$"

Route10_EventScript_PowerPlantSign::
	msgbox Route10_Text_PowerPlant, MSGBOX_SIGN
	end

Route10_Text_PowerPlant::
    .string "Central Elèctrica$"

Route10_EventScript_Mark::
	trainerbattle_single REMATCHABLE_TRAINER_POKEMANIAC_MARK_1, Route10_Text_MarkIntro, Route10_Text_MarkDefeat, Route10_EventScript_RegisterMarkAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route10_EventScript_MarkRematch
	msgbox Route10_Text_MarkPostBattle, MSGBOX_DEFAULT
	release
	end

Route10_Text_MarkIntro::
    .string "Uau, has vingut fins aquí?\n"
    .string "Potser també ets un PokéManíac?\l"
    .string "Vols veure la meva col·lecció?$"

Route10_Text_MarkDefeat::
    .string "Bah.\n"
    .string "No estic enfadat!$"

Route10_Text_MarkPostBattle::
    .string "Tinc Pokémon més rars a casa!$"

Route10_EventScript_RegisterMarkAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route10_Text_MarkRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_POKEMANIAC_MARK_1
	release
	end

Route10_Text_MarkRegister:
	.string "Si em dones el teu número,\n"
	.string "t'ensenyaré la meva col·lecció\l"
	.string "de Pokémon algun dia.$"

Route10_EventScript_MarkRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_POKEMANIAC_MARK_1, Route10_Text_MarkRematchIntro, Route10_Text_MarkDefeat
	msgbox Route10_Text_MarkRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_Text_MarkRematchIntro::
	.string "Els meus Pokémon!\n"
	.string "Deixa que te'ls ensenyi!$"

Route10_Text_MarkRematchPostBattle::
	.string "Tu sí que ets un PokéManíac!$"


Route10_EventScript_Herman::
	trainerbattle_single TRAINER_POKEMANIAC_HERMAN, Route10_Text_HermanIntro, Route10_Text_HermanDefeat
	msgbox Route10_Text_HermanPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_Text_HermanIntro::
    .string "Ei, nano!\n"
    .string "Vols veure els meus Pokémon?$"

Route10_Text_HermanDefeat::
    .string "Oh, no!\n"
    .string "Els meus Pokémon!$"

Route10_Text_HermanPostBattle::
    .string "No m'agrades.\n"
    .string "No m'agrada ningú millor que jo!$"

Route10_EventScript_Heidi::
	trainerbattle_single TRAINER_PICNICKER_HEIDI, Route10_Text_HeidiIntro, Route10_Text_HeidiDefeat
	msgbox Route10_Text_HeidiPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_Text_HeidiIntro::
    .string "He anat a un Gimnàs Pokémon\n"
    .string "unes quantes vegades.\p"
    .string "…Però sempre perdo.$"

Route10_Text_HeidiDefeat::
    .string "Ohh!\n"
    .string "Després de tot l'entrenament!$"

Route10_Text_HeidiPostBattle::
    .string "He vist uns PokéManíacs\n"
    .string "per aquí.\p"
    .string "T'ho pots imaginar? Ells?\n"
    .string "Aquí dalt a la muntanya?$"

Route10_EventScript_Carol::
	trainerbattle_single TRAINER_PICNICKER_CAROL, Route10_Text_CarolIntro, Route10_Text_CarolDefeat
	msgbox Route10_Text_CarolPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_Text_CarolIntro::
    .string "Em sento una mica feble.\n"
    .string "Fa temps que no faig senderisme.$"

Route10_Text_CarolDefeat::
    .string "Estic massa cansada.\n"
    .string "No estava en forma.$"

Route10_Text_CarolPostBattle::
    .string "Els Pokémon d'aquí la muntanya\n"
    .string "són tan rodanxons…\p"
    .string "M'agradaria que hi hagués\n"
    .string "Pokémon roses amb flors!$"

Route10_EventScript_Clark::
	trainerbattle_single TRAINER_HIKER_CLARK, Route10_Text_ClarkIntro, Route10_Text_ClarkDefeat
	msgbox Route10_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_Text_ClarkIntro::
    .string "Ha-hahah-ah-ha!$"

Route10_Text_ClarkDefeat::
    .string "Ha-haha!\n"
    .string "No ric!\l"
    .string "Ha-hay al·lèrgia! Haha-ha-txís!$"

Route10_Text_ClarkPostBattle::
    .string "Haha-ha-txís!\n"
    .string "Ha-txís!\l"
    .string "Snif! Snif!$"

Route10_EventScript_Trent::
	trainerbattle_single TRAINER_HIKER_TRENT, Route10_Text_TrentIntro, Route10_Text_TrentDefeat
	msgbox Route10_Text_TrentPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_Text_TrentIntro::
    .string "Ah!\n"
    .string "Quin aire de muntanya més bo!$"

Route10_Text_TrentDefeat::
    .string "Això m'ha aclarit les idees!$"

Route10_Text_TrentPostBattle::
    .string "Em sento ple d'aire de muntanya!$"

Route10_EventScript_LightBall::
	finditem ITEM_LIGHT_BALL, 1
	release
	end

Route10_EventScript_BerryLass::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_HEALING_BERRY, Route10_EventScript_GotDailyBerry
	msgbox Route10_Text_BerryLass, MSGBOX_DEFAULT
	random 7
	call_if_eq VAR_RESULT, 0, Route10_EventScript_GiveOranBerry
	call_if_eq VAR_RESULT, 1, Route10_EventScript_GiveSitrusBerry
	call_if_eq VAR_RESULT, 2, Route10_EventScript_GiveFigyBerry
	call_if_eq VAR_RESULT, 3, Route10_EventScript_GiveWikiBerry
	call_if_eq VAR_RESULT, 4, Route10_EventScript_GiveMagoBerry
	call_if_eq VAR_RESULT, 5, Route10_EventScript_GiveAguavBerry
	call_if_eq VAR_RESULT, 6, Route10_EventScript_GiveIapapaBerry
	setflag FLAG_DAILY_HEALING_BERRY
	goto Route10_EventScript_GotDailyBerry
	end

Route10_EventScript_GiveOranBerry::
	giveitem ITEM_ORAN_BERRY, 1
	return

Route10_EventScript_GiveSitrusBerry::
	giveitem ITEM_SITRUS_BERRY, 1
	return

Route10_EventScript_GiveFigyBerry::
	giveitem ITEM_FIGY_BERRY, 1
	return

Route10_EventScript_GiveWikiBerry::
	giveitem ITEM_WIKI_BERRY, 1
	return

Route10_EventScript_GiveMagoBerry::
	giveitem ITEM_MAGO_BERRY, 1
	return

Route10_EventScript_GiveAguavBerry::
	giveitem ITEM_AGUAV_BERRY, 1
	return

Route10_EventScript_GiveIapapaBerry::
	giveitem ITEM_IAPAPA_BERRY, 1
	return

Route10_Text_BerryLass::
	.string "Mai saps quant trigaràs a trobar\n"
	.string "el proper Centre Pokémon.\p"
	.string "Les Baies et poden ajudar en\n"
	.string "un moment d'apur.$"

Route10_EventScript_GotDailyBerry::
	msgbox Route10_Text_BerryPrepared, MSGBOX_NPC
	release
	end

Route10_Text_BerryPrepared::
	.string "Sempre m'asseguro de portar\n"
	.string "Baies quan surto.\p"
	.string "Podríem dir que estic molt\n"
	.string "ben preparada.\p"
	.string "...\p"
	.string "Ho pilles?$"

Route10_RocketFugitive::
	trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE
	waitse
	fadescreen FADE_FROM_BLACK
	end

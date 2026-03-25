RocketHideout_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, RocketHideout_B1F_OnTransition
	.byte 0

RocketHideout_B1F_OnLoad::
	call_if_not_defeated TRAINER_TEAM_ROCKET_GRUNT_12 RocketHideout_B1F_EventScript_SetBarrier
	end

RocketHideout_B1F_OnTransition::
    call_if_set FLAG_HIDE_CELADON_ROCKETS, RocketHideout_B1F_EventScript_RemoveBarrier
	end

RocketHideout_B1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_8, RocketHideout_B1F_Text_Grunt1Intro, RocketHideout_B1F_Text_Grunt1Defeat
	msgbox RocketHideout_B1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_Text_Grunt1Intro::
    .string "Qui ets?\n"
    .string "Com has arribat aquí?$"

RocketHideout_B1F_Text_Grunt1Defeat::
    .string "Au!\n"
    .string "Derrotat!$"

RocketHideout_B1F_Text_Grunt1PostBattle::
    .string "Maleït siguis… Estàs menyspreant\n"
    .string "l'Equip Rocket, oi?$"

RocketHideout_B1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_9, RocketHideout_B1F_Text_Grunt2Intro, RocketHideout_B1F_Text_Grunt2Defeat
	msgbox RocketHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_Text_Grunt2Intro::
    .string "Has entrat a l'operació de\n"
    .string "l'EQUIP ROCKET? Quina barra!$"

RocketHideout_B1F_Text_Grunt2Defeat::
    .string "Bum!$"

RocketHideout_B1F_Text_Grunt2PostBattle::
    .string "No te'n sortiràs amb la teva,\n"
    .string "marrec!$"

RocketHideout_B1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_10, RocketHideout_B1F_Text_Grunt3Intro, RocketHideout_B1F_Text_Grunt3Defeat
	msgbox RocketHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_Text_Grunt3Intro::
    .string "Alerta d'intrús!$"

RocketHideout_B1F_Text_Grunt3Defeat::
    .string "No puc!$"

RocketHideout_B1F_Text_Grunt3PostBattle::
    .string "Cubone? Bah!\n"
    .string "No sé on és.$"

RocketHideout_B1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_11, RocketHideout_B1F_Text_Grunt4Intro, RocketHideout_B1F_Text_Grunt4Defeat
	msgbox RocketHideout_B1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_Text_Grunt4Intro::
    .string "Per què has vingut aquí?$"

RocketHideout_B1F_Text_Grunt4Defeat::
    .string "Això no pot ser!$"

RocketHideout_B1F_Text_Grunt4PostBattle::
    .string "D'acord, parlaré…\n"
    .string "Agafa l'ascensor per veure el Cap.$"

RocketHideout_B1F_EventScript_Grunt5::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_12, RocketHideout_B1F_Text_Grunt5Intro, RocketHideout_B1F_Text_Grunt5Defeat, RocketHideout_B1F_EventScript_DefeatedGrunt5
	msgbox RocketHideout_B1F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_Text_Grunt5Intro::
    .string "T'has perdut, ratolinet?$"

RocketHideout_B1F_Text_Grunt5Defeat::
    .string "Per què…?$"

RocketHideout_B1F_Text_Grunt5PostBattle::
    .string "Oh, no, el rebombori ha obert\n"
    .string "la porta!$"

RocketHideout_B1F_EventScript_DefeatedGrunt5::
	call RocketHideout_B1F_EventScript_RemoveBarrier
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	release
	end

RocketHideout_B1F_EventScript_SetBarrier::
	setmetatile 20, 19, METATILE_SilphCo_HideoutBarrier_TopLeft_Floor, 1
	setmetatile 21, 19, METATILE_SilphCo_HideoutBarrier_TopRight_Floor, 1
	setmetatile 20, 20, METATILE_SilphCo_HideoutBarrier_BottomLeft, 1
	setmetatile 21, 20, METATILE_SilphCo_HideoutBarrier_BottomRight, 1
	setmetatile 20, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	return

RocketHideout_B1F_EventScript_RemoveBarrier::
	setmetatile 20, 19, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 19, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 20, 20, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 20, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 20, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 21, METATILE_SilphCo_HideoutFloor, 0
	return


RocketHideout_B1F_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE, 1
	release
	end

RocketHideout_B1F_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION, 1
	release
	end


RocketHideout_Burglars_Text_GetTM::
    .string "L'Equip Rocket va deixar molt\n"
    .string "de botí quan van marxar.\p"
    .string "Aquí tens, agafa.\n"
    .string "N'hi ha de sobres!$"

RocketHideout_Burglars_TM13::
    trainerbattle_single TRAINER_BURGLAR_TYLER, RocketHideout_Burglars_Text_BurglarIntro1, RocketHideout_Burglars_Text_BurglarDefeat1
    goto_if_set FLAG_GOT_TM13, RocketHideout_Burglars_EventScript_GotTM13
    msgbox RocketHideout_Burglars_Text_GetTM, MSGBOX_AUTOCLOSE
    giveitem ITEM_TM13, 1
    setflag FLAG_GOT_TM13
RocketHideout_Burglars_EventScript_GotTM13::
    msgbox RocketHideout_Burglars_Text_BurglarPostBattle1, MSGBOX_AUTOCLOSE
    release
    end

RocketHideout_Burglars_Text_BurglarIntro1::
    .string "Ei! Jo hi he arribat primer.\n"
    .string "Qui ho troba se'l queda!$"

RocketHideout_Burglars_Text_BurglarDefeat1::
    .string "Qui perd, plora...$"

RocketHideout_Burglars_Text_BurglarPostBattle1::
    .string "Alguns dels meus col·legues\n"
    .string "també hi són. Era massa temptador!$"


RocketHideout_Burglars_TM23::
    trainerbattle_single TRAINER_BURGLAR_GREG, RocketHideout_Burglars_Text_BurglarIntro2, RocketHideout_Burglars_Text_BurglarDefeat2
    goto_if_set FLAG_GOT_TM23, RocketHideout_Burglars_EventScript_GotTM23
    msgbox RocketHideout_Burglars_Text_GetTM, MSGBOX_AUTOCLOSE
    giveitem ITEM_TM23, 1
    setflag FLAG_GOT_TM23
RocketHideout_Burglars_EventScript_GotTM23::
    msgbox RocketHideout_Burglars_Text_BurglarPostBattle2, MSGBOX_AUTOCLOSE
    release
    end

RocketHideout_Burglars_Text_BurglarIntro2::
    .string "A veure...què tenim per aquí?$"

RocketHideout_Burglars_Text_BurglarDefeat2::
    .string "No! Jo el volia!$"

RocketHideout_Burglars_Text_BurglarPostBattle2::
    .string "Mai saps què trobaràs quan\n"
    .string "entres en un lloc.$"


RocketHideout_Burglars_TM24::
    trainerbattle_single TRAINER_BURGLAR_TONY, RocketHideout_Burglars_Text_BurglarIntro3, RocketHideout_Burglars_Text_BurglarDefeat3
    goto_if_set FLAG_GOT_TM24, RocketHideout_Burglars_EventScript_GotTM24
    msgbox RocketHideout_Burglars_Text_GetTM, MSGBOX_AUTOCLOSE
    giveitem ITEM_TM24, 1
    setflag FLAG_GOT_TM24
RocketHideout_Burglars_EventScript_GotTM24::
    msgbox RocketHideout_Burglars_Text_BurglarPostBattle3, MSGBOX_AUTOCLOSE
    release
    end

RocketHideout_Burglars_Text_BurglarIntro3::
    .string "Uau, ei, estàs robant això?\n"
    .string "Això no és gaire bonic!$"

RocketHideout_Burglars_Text_BurglarDefeat3::
    .string "Per què ho has fet?$"

RocketHideout_Burglars_Text_BurglarPostBattle3::
    .string "Oh, jo? Jo no robo això.\n"
    .string "Només me'l deixo!$"


RocketHideout_Burglars_TM30::
    trainerbattle_single TRAINER_BURGLAR_JAKE, RocketHideout_Burglars_Text_BurglarIntro4, RocketHideout_Burglars_Text_BurglarDefeat4
    goto_if_set FLAG_GOT_TM30, RocketHideout_Burglars_EventScript_GotTM30
    msgbox RocketHideout_Burglars_Text_GetTM, MSGBOX_AUTOCLOSE
    giveitem ITEM_TM30, 1
    setflag FLAG_GOT_TM30
RocketHideout_Burglars_EventScript_GotTM30::
    msgbox RocketHideout_Burglars_Text_BurglarPostBattle4, MSGBOX_AUTOCLOSE
    release
    end

RocketHideout_Burglars_Text_BurglarIntro4::
    .string "A veure...què puc trobar\n"
    .string "aquí avui?$"

RocketHideout_Burglars_Text_BurglarDefeat4::
    .string "Res!$"

RocketHideout_Burglars_Text_BurglarPostBattle4::
    .string "Què? Trobar una feina honesta?\n"
    .string "Amb aquesta economia?$"

RocketHideout_Burglars_TM35::
    trainerbattle_single TRAINER_BURGLAR_KYLE, RocketHideout_Burglars_Text_BurglarIntro5, RocketHideout_Burglars_Text_BurglarDefeat5
    goto_if_set FLAG_GOT_TM35, RocketHideout_Burglars_EventScript_GotTM35
    msgbox RocketHideout_Burglars_Text_GetTM, MSGBOX_AUTOCLOSE
    giveitem ITEM_TM35, 1
    setflag FLAG_GOT_TM35
RocketHideout_Burglars_EventScript_GotTM35::
    msgbox RocketHideout_Burglars_Text_BurglarPostBattle5, MSGBOX_AUTOCLOSE
    release
    end

RocketHideout_Burglars_Text_BurglarIntro5::
    .string "Robar mola!$"

RocketHideout_Burglars_Text_BurglarDefeat5::
    .string "Perdre no!$"

RocketHideout_Burglars_Text_BurglarPostBattle5::
    .string "M'encanta robar.\n"
    .string "És l'única cosa que m'agrada!$"


RocketHideout_Burglars_TM36::
    trainerbattle_single TRAINER_BURGLAR_PETE, RocketHideout_Burglars_Text_BurglarIntro6, RocketHideout_Burglars_Text_BurglarDefeat6
    goto_if_set FLAG_GOT_TM36, RocketHideout_Burglars_EventScript_GotTM36
    msgbox RocketHideout_Burglars_Text_GetTM, MSGBOX_AUTOCLOSE
    giveitem ITEM_TM36, 1
    setflag FLAG_GOT_TM36
RocketHideout_Burglars_EventScript_GotTM36::
    msgbox RocketHideout_Burglars_Text_BurglarPostBattle6, MSGBOX_AUTOCLOSE
    release
    end

RocketHideout_Burglars_Text_BurglarIntro6::
    .string "Uau! Això sembla car!$"

RocketHideout_Burglars_Text_BurglarDefeat6::
    .string "Ah, bah, si és brossa!$"

RocketHideout_Burglars_Text_BurglarPostBattle6::
    .string "No semblo trobar mai res de bo.$"


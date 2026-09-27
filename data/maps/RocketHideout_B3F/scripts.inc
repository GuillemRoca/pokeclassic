RocketHideout_B3F_MapScripts::
	.byte 0

RocketHideout_B3F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_14, RocketHideout_B3F_Text_Grunt1Intro, RocketHideout_B3F_Text_Grunt1Defeat
	msgbox RocketHideout_B3F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_Text_Grunt1Intro::
    .string "Deixa de ficar-te en els\n"
    .string "assumptes de l'Equip Rocket!$"

RocketHideout_B3F_Text_Grunt1Defeat::
    .string "Ai!\n"
    .string "M'han tombat!$"

RocketHideout_B3F_Text_Grunt1PostBattle::
    .string "Cubone?\n"
    .string "Oh, el Pokémon que vam robar.\p"
    .string "És per aquí en algun lloc.$"

RocketHideout_B3F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_15, RocketHideout_B3F_Text_Grunt2Intro, RocketHideout_B3F_Text_Grunt2Defeat
	msgbox RocketHideout_B3F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_Text_Grunt2Intro::
    .string "Ens han avisat des de dalt que\n"
    .string "venies!$"

RocketHideout_B3F_Text_Grunt2Defeat::
    .string "Què?\n"
    .string "He perdut? No!$"

RocketHideout_B3F_Text_Grunt2PostBattle::
    .string "Endavant, ves-hi!\p"
    .string "Però no pots fer servir\n"
    .string "l'ascensor sense la Clau.$"

RocketHideout_B3F_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY, 1
	release
	end

RocketHideout_B3F_EventScript_ItemTM21::
	finditem ITEM_TM21, 1
	release
	end

RocketHideout_B3F_EventScript_ItemBlackGlasses::
	finditem ITEM_BLACK_GLASSES, 1
	release
	end

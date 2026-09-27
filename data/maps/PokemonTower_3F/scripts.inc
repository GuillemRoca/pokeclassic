PokemonTower_3F_MapScripts::
	.byte 0

PokemonTower_3F_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE, 1
	release
	end

PokemonTower_3F_EventScript_Patricia::
	trainerbattle_single TRAINER_CHANNELER_PATRICIA, PokemonTower_3F_Text_PatriciaIntro, PokemonTower_3F_Text_PatriciaDefeat
	msgbox PokemonTower_3F_Text_PatriciaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_Text_PatriciaIntro::
    .string "Fora d'aquí!\n"
    .string "Esperit maligne!$"

PokemonTower_3F_Text_PatriciaDefeat::
    .string "Uf!\n"
    .string "L'esperit ha marxat!$"

PokemonTower_3F_Text_PatriciaPostBattle::
    .string "Les altres de més amunt…\n"
    .string "Deuen haver estat posseïdes.$"

PokemonTower_3F_EventScript_Carly::
	trainerbattle_single TRAINER_CHANNELER_CARLY, PokemonTower_3F_Text_CarlyIntro, PokemonTower_3F_Text_CarlyDefeat
	msgbox PokemonTower_3F_Text_CarlyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_Text_CarlyIntro::
    .string "Kekeke…\n"
    .string "Kwaaah!$"

PokemonTower_3F_Text_CarlyDefeat::
    .string "Hmm?\n"
    .string "Què estic fent?$"

PokemonTower_3F_Text_CarlyPostBattle::
    .string "Perdona!\n"
    .string "Estava posseïda!$"

PokemonTower_3F_EventScript_Hope::
	trainerbattle_single TRAINER_CHANNELER_HOPE, PokemonTower_3F_Text_HopeIntro, PokemonTower_3F_Text_HopeDefeat
	msgbox PokemonTower_3F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_Text_HopeIntro::
    .string "Urrg… Awaa…\n"
    .string "Huhu… Graa…$"

PokemonTower_3F_Text_HopeDefeat::
    .string "Hwa!\n"
    .string "M'he salvat!$"

PokemonTower_3F_Text_HopePostBattle::
    .string "Aquesta experiència em canviarà\n"
    .string "per sempre.$"


PokemonTower_4F_MapScripts::
	.byte 0

PokemonTower_4F_EventScript_ItemElixir::
	finditem ITEM_ELIXIR, 1
	release
	end

PokemonTower_4F_EventScript_ItemAwakening::
	finditem ITEM_AWAKENING, 1
	release
	end

PokemonTower_4F_EventScript_ItemGreatBall::
	finditem ITEM_GREAT_BALL, 1
	release
	end

PokemonTower_4F_EventScript_Paula::
	trainerbattle_single TRAINER_CHANNELER_PAULA, PokemonTower_4F_Text_PaulaIntro, PokemonTower_4F_Text_PaulaDefeat
	msgbox PokemonTower_4F_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_Text_PaulaIntro::
    .string "Fantasma! No!\n"
    .string "Kwaaah!$"

PokemonTower_4F_Text_PaulaDefeat::
    .string "On és el fantasma?$"

PokemonTower_4F_Text_PaulaPostBattle::
    .string "Devia estar somiant…$"

PokemonTower_4F_EventScript_Laurel::
	trainerbattle_single TRAINER_CHANNELER_LAUREL, PokemonTower_4F_Text_LaurelIntro, PokemonTower_4F_Text_LaurelDefeat
	msgbox PokemonTower_4F_Text_LaurelPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_Text_LaurelIntro::
    .string "Sigues maleït amb mi!\n"
    .string "Kwaaah!$"

PokemonTower_4F_Text_LaurelDefeat::
    .string "Què!$"

PokemonTower_4F_Text_LaurelPostBattle::
    .string "No podem determinar la identitat\n"
    .string "dels fantasmes…$"

PokemonTower_4F_EventScript_Jody::
	trainerbattle_single TRAINER_CHANNELER_JODY, PokemonTower_4F_Text_JodyIntro, PokemonTower_4F_Text_JodyDefeat
	msgbox PokemonTower_4F_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_Text_JodyIntro::
    .string "Huhuhu…\n"
    .string "No em pegueu!$"

PokemonTower_4F_Text_JodyDefeat::
    .string "Eh?\n"
    .string "Qui? Què?$"

PokemonTower_4F_Text_JodyPostBattle::
    .string "Que els Pokémon difunts\n"
    .string "descansin en pau…$"

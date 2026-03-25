PokemonTower_5F_MapScripts::
	.byte 0

PokemonTower_5F_EventScript_ItemCleanseTag::
	finditem ITEM_CLEANSE_TAG, 1
	release
	end

PokemonTower_5F_EventScript_ItemNugget::
	finditem ITEM_NUGGET, 1
	release
	end

PokemonTower_5F_EventScript_Channeler::
	msgbox PokemonTower_5F_Text_RestHereInPurifiedSpace, MSGBOX_NPC
	end

PokemonTower_5F_Text_RestHereInPurifiedSpace::
    .string "Vine, nen!\n"
    .string "He purificat aquest espai.\l"
    .string "Pots descansar aquí.$"

PokemonTower_5F_EventScript_PurifiedZone::
	lockall
	fadescreen FADE_TO_WHITE
	special HealPlayerParty
	fadescreen FADE_FROM_WHITE
	msgbox PokemonTower_5F_Text_PurifiedZoneMonsFullyHealed
	setvar VAR_TEMP_1, 1
	releaseall
	end

PokemonTower_5F_Text_PurifiedZoneMonsFullyHealed::
    .string "Has entrat a la zona purificada\n"
    .string "i protegida.\p"
    .string "Els Pokémon de {PLAYER} s'han\n"
    .string "curat completament.$"

PokemonTower_5F_EventScript_ExitPurifiedZone::
	lockall
	setvar VAR_TEMP_1, 0
	releaseall
	end

PokemonTower_5F_EventScript_Tammy::
	trainerbattle_single TRAINER_CHANNELER_TAMMY, PokemonTower_5F_Text_TammyIntro, PokemonTower_5F_Text_TammyDefeat
	msgbox PokemonTower_5F_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_Text_TammyIntro::
    .string "Dóna…me…\n"
    .string "el…teu…tot…$"

PokemonTower_5F_Text_TammyDefeat::
    .string "Esbufec!$"

PokemonTower_5F_Text_TammyPostBattle::
    .string "Estava posseïda.$"

PokemonTower_5F_EventScript_Ruth::
	trainerbattle_single TRAINER_CHANNELER_RUTH, PokemonTower_5F_Text_RuthIntro, PokemonTower_5F_Text_RuthDefeat
	msgbox PokemonTower_5F_Text_RuthPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_Text_RuthIntro::
    .string "Tu…t'uniràs…\n"
    .string "a…nosaltres…$"

PokemonTower_5F_Text_RuthDefeat::
    .string "Quin malson!$"

PokemonTower_5F_Text_RuthPostBattle::
    .string "Estava posseïda.$"

PokemonTower_5F_EventScript_Karina::
	trainerbattle_single TRAINER_CHANNELER_KARINA, PokemonTower_5F_Text_KarinaIntro, PokemonTower_5F_Text_KarinaDefeat
	msgbox PokemonTower_5F_Text_KarinaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_Text_KarinaIntro::
    .string "Zombis!$"

PokemonTower_5F_Text_KarinaDefeat::
    .string "Ha?$"

PokemonTower_5F_Text_KarinaPostBattle::
    .string "He recuperat els sentits.$"

PokemonTower_5F_EventScript_Janae::
	trainerbattle_single TRAINER_CHANNELER_JANAE, PokemonTower_5F_Text_JanaeIntro, PokemonTower_5F_Text_JanaeDefeat
	msgbox PokemonTower_5F_Text_JanaePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_Text_JanaeIntro::
    .string "Urgah…\n"
    .string "Urff…$"

PokemonTower_5F_Text_JanaeDefeat::
    .string "Uuu!$"

PokemonTower_5F_Text_JanaePostBattle::
    .string "He caigut als esperits malignes\n"
    .string "malgrat el meu entrenament\l"
    .string "a la muntanya…$"

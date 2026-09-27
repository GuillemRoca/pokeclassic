LavenderTown_PokemonCenter_2F_MapScripts::
	.byte 0


LavenderTown_PokemonCenter_2F_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SILK_SCARF, LavenderTown_PokemonCenter_2F_EventScript_OldWoman2
	msgbox LavenderTown_PokemonCenter_2F_Text_SilkScarf, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_SILK_SCARF, 1
	setflag FLAG_GOT_SILK_SCARF
	release
	end

LavenderTown_PokemonCenter_2F_Text_SilkScarf::
	.string "Això era del meu Meowth...\n"
	.string "Sempre anava tan elegant...\p"
	.string "Crec que li agradaria que\n"
	.string "ho tinguessis tu...$"

LavenderTown_PokemonCenter_2F_EventScript_OldWoman2::
	lock
	faceplayer
	msgbox LavenderTown_PokemonCenter_2F_Text_FancyPants, MSGBOX_DEFAULT
	release
	end

LavenderTown_PokemonCenter_2F_Text_FancyPants::
	.string "Els Pokémon són més que mascotes.\n"
	.string "Són amics i família.$"

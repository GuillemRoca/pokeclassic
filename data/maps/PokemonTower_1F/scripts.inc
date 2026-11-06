PokemonTower_1F_MapScripts::
	.byte 0

PokemonTower_1F_EventScript_Channeler::
	msgbox PokemonTower_1F_Text_SenseSpiritsUpToMischief, MSGBOX_NPC
	end

PokemonTower_1F_Text_SenseSpiritsUpToMischief::
    .string "Soc una Canalitzadora.\p"
    .string "Hi ha esperits fent entremaliadures.\n"
    .string "Els sento a dalt de la torre.$"

PokemonTower_1F_EventScript_Woman1::
	msgbox PokemonTower_1F_Text_GrowlitheWhyDidYouDie, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_CueBall::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM42, PokemonTower_1F_EventScript_CueBall2
	msgbox PokemonTower_1F_Text_IDontNeedThis, MSGBOX_NPC
	giveitem ITEM_TM42, 1
	release
	end

PokemonTower_1F_Text_IDontNeedThis::
	.string "Oh...snif...\n"
	.string "Nuffle...et trobo a faltar!\p"
	.string "Aquí tens...no ho necessito...$"

PokemonTower_1F_EventScript_CueBall2::
	msgbox PokemonTower_1F_Text_BraveFace, MSGBOX_NPC
	release
	end

PokemonTower_1F_Text_BraveFace::
	.string "Sempre que combatíem, jo era\n"
	.string "capaç de posar bona cara\l"
	.string "pels meus Pokémon.\p"
	.string "Però ara, no puc mantenir\n"
	.string "la façana...$"

PokemonTower_1F_Text_GrowlitheWhyDidYouDie::
    .string "El meu Growlithe…\n"
    .string "Per què vas morir?$"


PokemonTower_1F_EventScript_BaldingMan::
	msgbox PokemonTower_1F_Text_CameToPrayForDepartedClefairy, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_Woman2::
	msgbox PokemonTower_1F_Text_ComeToPayRespects, MSGBOX_NPC
	release
	end

PokemonTower_1F_Text_CameToPrayForDepartedClefairy::
    .string "He vingut a pregar pel meu\n"
    .string "estimat Clefairy.\p"
    .string "Snif!\n"
    .string "Estic ple de llàgrimes…$"

PokemonTower_1F_Text_ComeToPayRespects::
    .string "Has vingut a retre homenatge?\p"
    .string "Beneït sigui el teu cor\n"
    .string "amant dels Pokémon.$"

PokemonTower_1F_EventScript_WorkerF::
	msgbox PokemonTower_1F_Text_ErectedInMemoryOfDeadMons, MSGBOX_NPC
	end

PokemonTower_1F_Text_ErectedInMemoryOfDeadMons::
    .string "La Torre Pokémon es va erigir\n"
    .string "en memòria dels Pokémon morts.$"

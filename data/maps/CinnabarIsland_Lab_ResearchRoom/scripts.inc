CinnabarIsland_Lab_ResearchRoom_MapScripts::
	.byte 0

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Scientist::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons, MSGBOX_NPC
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Computer::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_AmberPipe::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons::
    .string "Eevee pot evolucionar en un de\n"
    .string "tres tipus de Pokémon.$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail::
    .string "Hi ha un missatge de correu.\p"
    .string "… … …\p"
    .string "Hi ha tres Pokémon ocells\n"
    .string "llegendaris.\p"
    .string "Són Articuno, Zapdos i\n"
    .string "Moltres.\p"
    .string "El seu parador és desconegut.\p"
    .string "Planem explorar la caverna\n"
    .string "prop de Cerulean.\p"
    .string "De: Equip de Recerca Pokémon…$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe::
    .string "Una pipa d'ambre!$"

Route11_EastEntrance_1F_MapScripts::
	.byte 0

Route11_EastEntrance_1F_EventScript_TopGuard::
	msgbox Route11_EastEntrance_1F_Text_ManInLavenderRatesNames, MSGBOX_NPC
	end

Route11_EastEntrance_1F_Text_ManInLavenderRatesNames::
    .string "No trobes que és difícil pensar\n"
    .string "bons noms per als Pokémon?\p"
    .string "Sobretot si n'has atrapat\n"
    .string "un munt?\p"
    .string "A Lavender Town, hi ha un home\n"
    .string "que valora els malnoms Pokémon.\p"
    .string "Fins i tot pot ajudar-te a\n"
    .string "canviar el nom dels teus Pokémon.$"

Route11_EastEntrance_1F_EventScript_BottomGuard::
	msgbox Route11_EastEntrance_1F_Text_RockTunnelToReachLavender, MSGBOX_NPC
	end

Route11_EastEntrance_1F_Text_RockTunnelToReachLavender::
    .string "Si vols arribar a Lavender Town,\n"
    .string "agafa el Túnel Roca.\p"
    .string "Pots arribar-hi des de\n"
    .string "Cerulean City.$"

CeruleanCity_House5_MapScripts::
	.byte 0

CeruleanCity_House5_EventScript_BadgeGuy::
	msgbox CeruleanCity_House5_Text_BadgesHaveAmazingSecrets, MSGBOX_NPC
	release
	end

CeruleanCity_House5_Text_BadgesHaveAmazingSecrets::
	.string "Les Medalles són més que una\n"
	.string "insígnia bonica!\p"
	.string "Una Medalla certifica un Entrenador\n"
	.string "per usar certs Moviments Ocults,\l"
	.string "com Flash o Volar.\p"
	.string "Els Pokémon semblen entendre la\n"
	.string "seva importància també.\p"
	.string "Els Pokémon de nivell alt no\n"
	.string "t'obeiran si no tens prou medalles!$"

CeruleanCity_House5_EventScript_BadgeSign::
	msgbox CeruleanCity_House5_Text_BadgeSign, MSGBOX_SIGN
	release
	end

CeruleanCity_House5_Text_BadgeSign::
	.string "Lliga Pokémon Oficial\n"
	.string "Certificació d'Expert en Medalles$"

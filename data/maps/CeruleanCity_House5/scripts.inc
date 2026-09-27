CeruleanCity_House5_MapScripts::
	.byte 0

CeruleanCity_House5_EventScript_BadgeGuy::
	msgbox CeruleanCity_House5_Text_BadgesHaveAmazingSecrets, MSGBOX_NPC
	release
	end

CeruleanCity_House5_Text_BadgesHaveAmazingSecrets::
	.string "Les Medalles són més que una\n"
	.string "insígnia bonica!\p"
	.string "Una Medalla autoritza un Entrenador\n"
	.string "a usar alguns Moviments Ocults,\l"
	.string "com Llampec o Vol.\p"
	.string "Sembla que els Pokémon també\n"
	.string "en comprenen la importància.\p"
	.string "Els Pokémon de nivell alt no\n"
	.string "t'obeiran si no tens prou medalles!$"

CeruleanCity_House5_EventScript_BadgeSign::
	msgbox CeruleanCity_House5_Text_BadgeSign, MSGBOX_SIGN
	release
	end

CeruleanCity_House5_Text_BadgeSign::
	.string "Certificat oficial de la Lliga Pokémon\n"
	.string "Expert en Medalles$"

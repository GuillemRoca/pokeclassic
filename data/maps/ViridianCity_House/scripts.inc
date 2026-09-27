ViridianCity_House_MapScripts::
	.byte 0

ViridianCity_House_EventScript_BaldingMan::
	lock
	msgbox ViridianCity_House_Text_NicknamingIsFun, MSGBOX_NPC
	release
	end

ViridianCity_House_Text_NicknamingIsFun::
    .string "Inventar malnoms és divertit,\n"
    .string "però no és tan fàcil.\p"
    .string "Els noms enginyosos estan bé,\n"
    .string "però els simples són més fàcils\l"
    .string "de recordar.$"

ViridianCity_House_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox ViridianCity_House_Text_MyDaddyLovesMonsToo, MSGBOX_NPC
	release
	end

ViridianCity_House_Text_MyDaddyLovesMonsToo::
    .string "El meu papa també estima els\n"
    .string "Pokémon.$"

ViridianCity_House_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House_Text_Speary
	waitmoncry
	release
	end

ViridianCity_House_Text_Speary::
    .string "Speary: Tetweet!$"

ViridianCity_House_EventScript_NicknameSign::
	msgbox ViridianCity_House_Text_SpearowNameSpeary, MSGBOX_SIGN
	end

ViridianCity_House_Text_SpearowNameSpeary::
    .string "Spearow\n"
    .string "Nom: Speary$"

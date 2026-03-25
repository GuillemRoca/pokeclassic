SaffronCity_House_MapScripts::
	.byte 0

SaffronCity_House_EventScript_Lass::
	msgbox SaffronCity_House_Text_DontLookAtMyLetter, MSGBOX_NPC
	end

SaffronCity_House_EventScript_Youngster::
	msgbox SaffronCity_House_Text_GettingCopycatPokeDoll, MSGBOX_NPC
	end

SaffronCity_House_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox SaffronCity_House_Text_Pidgey
	waitmoncry
	release
	end

SaffronCity_House_EventScript_Letter::
	msgbox SaffronCity_House_Text_ExplainPPUp, MSGBOX_SIGN
	end

SaffronCity_House_Text_DontLookAtMyLetter::
    .string "…Gràcies per escriure.\n"
    .string "Espero veure't aviat!\p"
    .string "…Ei!\n"
    .string "No miris la meva carta!$"

SaffronCity_House_Text_Pidgey::
    .string "Pidgey: Kurukkoo!$"

SaffronCity_House_Text_GettingCopycatPokeDoll::
    .string "La Copiona és maca!\n"
    .string "Li compraré una Poké Doll.$"

SaffronCity_House_Text_ExplainPPUp::
    .string "Em van donar un PP Plus de regal.\p"
    .string "Serveix per augmentar els PP\n"
    .string "d'un moviment d'un Pokémon.\p"
    .string "L'hauria de fer servir en un\n"
    .string "moviment potent amb pocs PP.$"

VermilionCity_House3_MapScripts::
	.byte 0

VermilionCity_House3_EventScript_Boy::
	msgbox VermilionCity_House3_Text_PidgeyFlyLetterToSaffron, MSGBOX_NPC
	end

VermilionCity_House3_Text_PidgeyFlyLetterToSaffron::
    .string "Estic fent que el meu Pidgey porti\n"
    .string "una carta a Saffron, al nord.$"

VermilionCity_House3_EventScript_Lass::
	msgbox VermilionCity_House3_Text_SendMyPidgeyToUnionRoom, MSGBOX_NPC
	end

VermilionCity_House3_Text_SendMyPidgeyToUnionRoom::
    .string "La majoria de gent prefereix el\n"
    .string "correu electrònic, però jo\l"
    .string "prefereixo una carta clàssica!\p"
    .string "He entrenat el meu Pidgey per\n"
    .string "repartir correu!$"

VermilionCity_House3_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox VermilionCity_House3_Text_Pidgey
	waitmoncry
	release
	end

VermilionCity_House3_Text_Pidgey::
    .string "Pidgey: Kurukkoo!$"

VermilionCity_House3_EventScript_Letter::
	msgbox VermilionCity_House3_Text_DearPippiLetter, MSGBOX_SIGN
	end

VermilionCity_House3_Text_DearPippiLetter::
    .string "Benvolguda Pippi,\n"
    .string "espero veure't aviat.\p"
    .string "He sentit un rumor que el Team\n"
    .string "Rocket es dirigia a Saffron City.\p"
    .string "Vermilion sembla segura.$"

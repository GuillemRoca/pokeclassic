FuchsiaCity_House1_MapScripts::
	.byte 0

FuchsiaCity_House1_EventScript_Woman::
	msgbox FuchsiaCity_House1_Text_WardenIsOldHasFalseTeeth, MSGBOX_NPC
	end

FuchsiaCity_House1_Text_WardenIsOldHasFalseTeeth::
    .string "El Guardià de la Zona Safari és\n"
    .string "gran, però encara és molt actiu.\p"
    .string "Totes les seves dents són\n"
    .string "postisses, però.$"

FuchsiaCity_House1_EventScript_OldMan::
	lock
	faceplayer
	msgbox FuchsiaCity_House1_Text_BillIsMyGrandson
	release
	end

FuchsiaCity_House1_Text_BillIsMyGrandson::
    .string "Hmm?\n"
    .string "Has conegut en Bill?\p"
    .string "És el meu nét!\p"
    .string "Sempre li ha agradat col·leccionar\n"
    .string "coses, fins i tot de petit!$"

FuchsiaCity_House1_EventScript_LittleBoy::
	msgbox FuchsiaCity_House1_Text_BillFilesHisOwnMonData, MSGBOX_NPC
	end

FuchsiaCity_House1_Text_BillFilesHisOwnMonData::
    .string "En Bill arxiva les seves pròpies\n"
    .string "dades Pokémon al seu PC.\p"
    .string "Te les va ensenyar?$"

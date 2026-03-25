SSAnne_1F_Corridor_MapScripts::
	.byte 0

SSAnne_1F_Corridor_EventScript_WorkerM::
	msgbox SSAnne_1F_Corridor_Text_LeStrongSilentType, MSGBOX_NPC
	end

SSAnne_1F_Corridor_Text_LeStrongSilentType::
    .string "Bonjour!\n"
    .string "Sóc le cambrer d'aquest vaixell!\p"
    .string "Estaré encantat de servir-te\n"
    .string "el que vulguis!\p"
    .string "… … …\n"
    .string "Ah! Le fort i silenciós!$"

SSAnne_1F_Corridor_EventScript_Sailor::
	msgbox SSAnne_1F_Corridor_Text_PassengersAreRestless, MSGBOX_NPC
	end

SSAnne_1F_Corridor_Text_PassengersAreRestless::
    .string "Els passatgers estan inquiets\n"
    .string "per aquest llarg viatge.\p"
    .string "Pot ser que els més avorrits\n"
    .string "et desafiïn!$"

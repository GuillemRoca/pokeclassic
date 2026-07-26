CeladonCity_DepartmentStore_1F_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_1F_EventScript_Receptionist::
	msgbox CeladonCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_1F_Text_WelcomeToDeptStore::
    .string "Hola! Benvingut als Grans\n"
    .string "Magatzems de Celadon.\p"
    .string "El tauler de la dreta descriu\n"
    .string "la distribució de la botiga.$"

CeladonCity_DepartmentStore_1F_EventScript_LayoutSign::
	msgbox CeladonCity_DepartmentStore_1F_Text_FloorDescriptions, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_1F_Text_FloorDescriptions::
    .string "1F: Taulell d'Atenció\p"
    .string "2F: Mercat d'Entrenadors\p"
    .string "3F: Botiga de Videojocs\p"
    .string "4F: Regals del Savi\p"
    .string "5F: Parafarmàcia\p"
    .string "Terrat: Màquines Expenedores$"

CeladonCity_DepartmentStore_1F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_1F_Text_ServiceCounter, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_1F_Text_ServiceCounter::
    .string "1F: Taulell d'Atenció$"

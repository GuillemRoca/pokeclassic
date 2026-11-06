CeladonCity_DepartmentStore_1F_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_1F_EventScript_Receptionist::
	msgbox CeladonCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_1F_Text_WelcomeToDeptStore::
    .string "Hola! Benvingut als Grans\n"
    .string "Magatzems de Celadó.\p"
    .string "El tauler de la dreta descriu\n"
    .string "la distribució de la botiga.$"

CeladonCity_DepartmentStore_1F_EventScript_LayoutSign::
	msgbox CeladonCity_DepartmentStore_1F_Text_FloorDescriptions, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_1F_Text_FloorDescriptions::
    .string "P1: Taulell d'Atenció\p"
    .string "P2: Mercat d'Entrenadors\p"
    .string "P3: Botiga de Videojocs\p"
    .string "P4: Regals del Savi\p"
    .string "P5: Parafarmàcia\p"
    .string "Terrat: Màquines Expenedores$"

CeladonCity_DepartmentStore_1F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_1F_Text_ServiceCounter, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_1F_Text_ServiceCounter::
    .string "P1: Taulell d'Atenció$"

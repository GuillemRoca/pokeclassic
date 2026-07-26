CeladonCity_Hotel_MapScripts::
	.byte 0

CeladonCity_Hotel_EventScript_Receptionist::
	msgbox CeladonCity_Hotel_Text_ThisHotelIsForPeople, MSGBOX_NPC
	end

CeladonCity_Hotel_Text_ThisHotelIsForPeople::
    .string "Pokémon?\n"
    .string "No, això és un hotel per a gent.\p"
    .string "Estem plens, malauradament.$"

CeladonCity_Hotel_EventScript_Beauty::
	msgbox CeladonCity_Hotel_Text_OnVacationWithBrotherAndBoyfriend, MSGBOX_NPC
	end

CeladonCity_Hotel_Text_OnVacationWithBrotherAndBoyfriend::
    .string "Estic de vacances amb el meu\n"
    .string "germà i el meu xicot.\p"
    .string "Celadon és una ciutat molt bonica!$"

CeladonCity_Hotel_EventScript_BeautyBoyfriend::
	msgbox CeladonCity_Hotel_Text_WhyDidSheBringBrother, MSGBOX_NPC
	end

CeladonCity_Hotel_Text_WhyDidSheBringBrother::
    .string "Per què?\n"
    .string "Per què ha portat el seu germà?$"

CeladonCity_Hotel_EventScript_BeautyBrother::
	msgbox CeladonCity_Hotel_Text_SisBroughtMeOnVacation, MSGBOX_NPC
	end

CeladonCity_Hotel_Text_SisBroughtMeOnVacation::
    .string "Visca! Estic de vacances!\n"
    .string "La meva germana m'ha portat! Genial!$"

SaffronCity_CopycatsHouse_1F_MapScripts::
	.byte 0

SaffronCity_CopycatsHouse_1F_EventScript_CopycatsMom::
	msgbox SaffronCity_CopycatsHouse_1F_Text_DaughterIsSelfCentered, MSGBOX_NPC
	end

SaffronCity_CopycatsHouse_1F_EventScript_CopycatsDad::
	msgbox SaffronCity_CopycatsHouse_1F_Text_DaughterLikesToMimicPeople, MSGBOX_NPC
	end

SaffronCity_CopycatsHouse_1F_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	msgbox SaffronCity_CopycatsHouse_1F_Text_Chansey
	waitmoncry
	release
	end

SaffronCity_CopycatsHouse_1F_Text_DaughterIsSelfCentered::
    .string "La meva filla és tan egocèntrica.\n"
    .string "Té molt pocs amics.$"

SaffronCity_CopycatsHouse_1F_Text_DaughterLikesToMimicPeople::
    .string "A la meva filla li agrada imitar\n"
    .string "la gent. És bastant molest.\p"
    .string "La seva imitació li ha valgut el\n"
    .string "sobrenom de Copiona per aquí.$"

SaffronCity_CopycatsHouse_1F_Text_Chansey::
    .string "Chansey: Chaan! Sii!$"

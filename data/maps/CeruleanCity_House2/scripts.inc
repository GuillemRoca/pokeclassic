CeruleanCity_House2_MapScripts::
	.byte 0

@POSTGAME, let's clean their house up with a layout change or some metatile redraws.

CeruleanCity_House2_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECOVERED_STOLEN_TM, CeruleanCity_House2_EventScript_HikerGotTM28
	msgbox CeruleanCity_House2_Text_RocketsStoleTMForDig
	release
	end

CeruleanCity_House2_Text_RocketsStoleTMForDig::
    .string "Aquests miserables Rockets!\p"
    .string "Mira què han fet a casa meva!\p"
    .string "Han robat una MT per ensenyar\n"
    .string "als Pokémon a cavar forats!\p"
    .string "La volia usar amb un Mankey\n"
    .string "o un Sandshrew…\p"
    .string "Em va costar un ull de la cara!$"

CeruleanCity_House2_EventScript_HikerGotTM28::
	msgbox CeruleanCity_House2_Text_TeachDiglettDigWithoutTM
	release
	end

CeruleanCity_House2_Text_TeachDiglettDigWithoutTM::
    .string "El que s'ha perdut, s'ha perdut.\p"
    .string "He decidit ensenyar Excavar\n"
    .string "a Diglett sense cap MT.$"

CeruleanCity_House2_EventScript_Lass::
	msgbox CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood, MSGBOX_NPC
	end

CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood::
    .string "L'Equip Rocket deu estar intentant\n"
    .string "Excavar per fer de les seves!$"

CeruleanCity_House2_EventScript_WallHole::
	msgbox CeruleanCity_House2_Text_TeamRocketLeftWayOut, MSGBOX_SIGN
	end

CeruleanCity_House2_Text_TeamRocketLeftWayOut::
    .string "L'Equip Rocket ha deixat una\n"
    .string "sortida!$"


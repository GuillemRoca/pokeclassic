.set LOCALID_PORYGON, 2

CeladonCity_Condominiums_RoofRoom_MapScripts::
	.byte 0

CeladonCity_Condominiums_RoofRoom_EventScript_Maniac::
	goto_if_set FLAG_GOT_PORYGON, CeladonCity_Condominiums_RoofRoom_EventScript_AlreadyGotPorygon
	msgbox CeladonCity_Condominiums_RoofRoom_Text_CreatedMyOwnPokemon, MSGBOX_NPC
	end

CeladonCity_Condominiums_RoofRoom_Text_CreatedMyOwnPokemon::
	.string "Si els Pokémon es poden convertir\n"
	.string "en dades i guardar en un PC,\l"
	.string "hauríem de poder crear Pokémon\l"
	.string "artificialment, no?\p"
	.string "Aquesta era la meva hipòtesi - i\n"
	.string "la vaig demostrar creant Porygon!\p"
	.string "No em creus?\p"
	.string "Agafa la Poké Ball d'allà,\n"
	.string "pots quedar-te el meu Porygon!$"

CeladonCity_Condominiums_RoofRoom_EventScript_AlreadyGotPorygon::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_CanAPokemonBeHacked, MSGBOX_NPC
	release
	end

CeladonCity_Condominiums_RoofRoom_Text_CanAPokemonBeHacked::
	.string "Si podem convertir Pokémon en\n"
	.string "dades, vol dir que un Pokémon\l"
	.string "pot ser hackejat?$"

CeladonCity_Condominiums_RoofRoom_EventScript_TMsPamphlet::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_PamphletOnTMs, MSGBOX_SIGN
	end

CeladonCity_Condominiums_RoofRoom_Text_PamphletOnTMs::
    .string "És un correu sobre les MT.\p"
    .string "… …\p"
    .string "Hi ha cinquanta MT en total.\p"
    .string "També hi ha vuit MO que es\n"
    .string "poden usar al camp!\p"
    .string "SILPH CO.$"

CeladonCity_Condominiums_RoofRoom_EventScript_PorygonBall::
    setvar VAR_TEMP_1, SPECIES_PORYGON
    givemon SPECIES_PORYGON, 25, ITEM_NONE
    goto_if_eq VAR_RESULT, 0, CeladonCity_Condominiums_RoofRoom_EventScript_PorygonParty
    goto_if_eq VAR_RESULT, 1, CeladonCity_Condominiums_RoofRoom_EventScript_PorygonPC
    goto_if_eq VAR_RESULT, 2, CeladonCity_Condominiums_RoofRoom_EventScript_NoRoomForPorygon
    end

CeladonCity_Condominiums_RoofRoom_EventScript_PorygonParty::
    call CeladonCity_Condominiums_RoofRoom_EventScript_GetPorygon
    msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, CeladonCity_Condominiums_RoofRoom_EventScript_GotPorygon
    call Common_EventScript_GetGiftMonPartySlot
    call Common_EventScript_NameReceivedPartyMon
    goto CeladonCity_Condominiums_RoofRoom_EventScript_GotPorygon
    end

CeladonCity_Condominiums_RoofRoom_EventScript_GetPorygon::
    playfanfare MUS_LEVEL_UP
    message CeladonCity_Condominiums_RoofRoom_EventScript_Text_FoundPorygon
    waitmessage
    waitfanfare
    bufferspeciesname STR_VAR_1, SPECIES_PORYGON
    return

CeladonCity_Condominiums_RoofRoom_EventScript_Text_FoundPorygon::
    .string "{PLAYER} ha trobat una Poké Ball.\n"
    .string "Contenia un Porygon!$"

CeladonCity_Condominiums_RoofRoom_EventScript_GotPorygon::
    setflag FLAG_GOT_PORYGON
    removeobject LOCALID_PORYGON
    release
    end

CeladonCity_Condominiums_RoofRoom_EventScript_PorygonPC::
    call CeladonCity_Condominiums_RoofRoom_EventScript_GetPorygon
    msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, CeladonCity_Condominiums_RoofRoom_EventScript_TransferPorygon
    call Common_EventScript_NameReceivedBoxMon
    goto CeladonCity_Condominiums_RoofRoom_EventScript_TransferPorygon
    end

CeladonCity_Condominiums_RoofRoom_EventScript_TransferPorygon::
    call Common_EventScript_TransferredToPC
    goto CeladonCity_Condominiums_RoofRoom_EventScript_GotPorygon
    end

CeladonCity_Condominiums_RoofRoom_EventScript_NoRoomForPorygon::
    msgbox CeladonCity_Condominiums_RoofRoom_Text_NoRoomForMorePokemon, MSGBOX_DEFAULT
    release
    end

CeladonCity_Condominiums_RoofRoom_Text_NoRoomForMorePokemon::
    .string "Oh! No tens espai per a\n"
    .string "més Pokémon!$"

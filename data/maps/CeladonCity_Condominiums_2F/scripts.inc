CeladonCity_Condominiums_2F_MapScripts::
	.byte 0

CeladonCity_Condominiums_2F_EventScript_MeetingRoomSign::
	msgbox CeladonCity_Condominiums_2F_Text_GameFreakMeetingRoom, MSGBOX_SIGN
	end

CeladonCity_Condominiums_2F_Text_GameFreakMeetingRoom::
    .string "Sala de Reunions del Diari Pokémon$"

CeladonCity_Condominiums_2F_EventScript_PokemonJournalErika::
	msgbox PokemonJournal_Text_SpecialFeatureErika, MSGBOX_SIGN
	release
	end

PokemonJournal_Text_SpecialFeatureErika::
	.string "Diari Pokémon:\p"
	.string "Reportatge: Líder del Gimnàs\n"
	.string "de Celadon, Erika!\p"
	.string "Diuen que si espies el Gimnàs\n"
	.string "de Celadon, sovint pots veure\l"
	.string "l'Erika fent la migdiada.$"

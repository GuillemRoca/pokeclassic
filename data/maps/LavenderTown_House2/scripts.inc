LavenderTown_House2_MapScripts::
	.byte 0

LavenderTown_House2_EventScript_NameRater::
	lock
	faceplayer
	msgbox LavenderTown_House2_Text_WantMeToRateNicknames, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LavenderTown_House2_EventScript_ChooseMon
	compare VAR_RESULT, NO
	goto_if_eq LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_ChooseMon::
	msgbox LavenderTown_House2_Text_CritiqueWhichMonsNickname
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_lt LavenderTown_House2_EventScript_CheckCanRateMon
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_DontRateNickname::
	msgbox LavenderTown_House2_Text_ISeeComeVisitAgain
	release
	end

LavenderTown_House2_EventScript_CheckCanRateMon::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq LavenderTown_House2_EventScript_CantNicknameEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	compare VAR_RESULT, TRUE
	goto_if_eq LavenderTown_House2_EventScript_CantNicknameTradeMon
	specialvar VAR_RESULT, IsMonOTNameNotPlayers
	special BufferMonNickname
	compare VAR_RESULT, TRUE
	goto_if_eq LavenderTown_House2_EventScript_CantNicknameTradeMon
	msgbox LavenderTown_House2_Text_GiveItANicerName, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LavenderTown_House2_EventScript_ChooseNewNickname
	compare VAR_RESULT, NO
	goto_if_eq LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_CantNicknameEgg::
	msgbox LavenderTown_House2_Text_ThatIsMerelyAnEgg
	release
	end

LavenderTown_House2_EventScript_CantNicknameTradeMon::
	msgbox LavenderTown_House2_Text_TrulyImpeccableName
	release
	end

LavenderTown_House2_EventScript_ChooseNewNickname::
	msgbox LavenderTown_House2_Text_WhatShallNewNicknameBe
	call Common_EventScript_ChangePokemonNickname
	specialvar VAR_RESULT, NameRaterWasNicknameChanged
	special BufferMonNickname
	compare VAR_RESULT, TRUE
	goto_if_eq LavenderTown_House2_EventScript_ChoseNewNickname
	msgbox LavenderTown_House2_Text_FromNowOnShallBeKnownAsSameName
	release
	end

LavenderTown_House2_EventScript_ChoseNewNickname::
	msgbox LavenderTown_House2_Text_FromNowOnShallBeKnownAsName
	release
	end

LavenderTown_House2_Text_WantMeToRateNicknames::
    .string "Hola, hola!\n"
    .string "Soc el Valorador de Noms oficial!\p"
    .string "Vols que valori els malnoms\n"
    .string "dels teus Pokémon?$"

LavenderTown_House2_Text_CritiqueWhichMonsNickname::
    .string "Quin malnom de Pokémon hauria\n"
    .string "de valorar?$"

LavenderTown_House2_Text_GiveItANicerName::
    .string "{STR_VAR_1}, oi?\n"
    .string "És un malnom decent!\p"
    .string "Però, voldries que li posés\n"
    .string "un nom més bonic?\p"
    .string "Què me'n dius?$"

LavenderTown_House2_Text_WhatShallNewNicknameBe::
    .string "Ah, bé. Llavors, quin serà\n"
    .string "el nou malnom?$"

LavenderTown_House2_Text_FromNowOnShallBeKnownAsName::
    .string "Fet! A partir d'ara, aquest\n"
    .string "Pokémon es dirà {STR_VAR_1}!\p"
    .string "És un nom millor que l'anterior!\n"
    .string "Quina sort que tens!$"

LavenderTown_House2_Text_ISeeComeVisitAgain::
    .string "Ja veig.\n"
    .string "Torna a visitar-me.$"

LavenderTown_House2_Text_FromNowOnShallBeKnownAsSameName::
    .string "Fet! A partir d'ara, aquest\n"
    .string "Pokémon es dirà {STR_VAR_1}!\p"
    .string "Sembla igual que abans, però\n"
    .string "és molt superior!\p"
    .string "Quina sort que tens!$"

LavenderTown_House2_Text_TrulyImpeccableName::
    .string "{STR_VAR_1}, oi?\n"
    .string "És un nom realment impecable!\p"
    .string "Cuida bé de {STR_VAR_1}!$"

LavenderTown_House2_Text_ThatIsMerelyAnEgg::
    .string "Vinga, vinga.\n"
    .string "Això és només un ou!$"


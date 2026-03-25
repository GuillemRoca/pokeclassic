ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string "Hola, Entrenador!\n"
	.string "Tens un somriure meravellós.\p"
	.string "Tinc un hobby: col·leccionar perfils\n"
	.string "d'Entrenadors Pokémon.$"

ProfileMan_Text_MayISeeYourProfile:
	.string "Què, què me'n dius?\n"
	.string "Puc veure el teu perfil?$"

ProfileMan_Text_EasyChatExplanation:
	.string "Crea el teu perfil combinant\n"
	.string "quatre paraules o frases.\p"
	.string "Mira, et mostraré un exemple de\n"
	.string "perfil amb quatre fragments de text.\p"
	.string "Pots canviar aquests fragments\n"
	.string "per altres com vulguis per fer\l"
	.string "el teu propi perfil.\p"
	.string "Hi ha molts fragments de text\n"
	.string "que pots fer servir.\p"
	.string "Estan organitzats en grups com\n"
	.string "Pokémon, estils de vida i hobbies\l"
	.string "per facilitar-ne la cerca.\p"
	.string "Primer, tria el grup de fragments\n"
	.string "per mostrar una llista d'opcions.\p"
	.string "Després, tria l'opció que vulguis.\p"
	.string "Repeteix per als fragments restants\n"
	.string "i tindràs el teu propi perfil.$"

ProfileMan_Text_LetsSeeItThen:
	.string "Sí! Gràcies!\n"
	.string "Doncs, deixa'm veure'l.$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "Oh, de veritat que no?\p"
	.string "M'imagino que algú com tu tindria\n"
	.string "un perfil meravellós…$"

ProfileMan_Text_NotIntoItRightNow:
	.string "Oh? Ara no et ve de gust?\p"
	.string "Bé, qualsevol moment va bé!$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "Hola, Entrenador!\n"
	.string "Tens un somriure meravellós.$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string "Puc veure el teu nou perfil?$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "Sí! Gràcies!\p"
	.string "Espero que sigui encara millor que\n"
	.string "el perfil que em vas mostrar abans.$"

ProfileMan_Text_LikeProfileWayItIs:
	.string "Oh, t'agrada el teu perfil tal com és.\p"
	.string "No t'ho retrec, és un perfil\n"
	.string "meravellós tal com és ara.$"

ProfileMan_Text_FantasticProfile:
	.string "F-fantàstic!\p"
	.string "El teu perfil és meravellós!\n"
	.string "Realment diu molt de tu.\p"
	.string "Qualsevol que sentís aquest perfil\n"
	.string "quedaria captivat per tu!\p"
	.string "Gràcies!$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string "Oh?\n"
	.string "Saps la frase secreta!\p"
	.string "Això vol dir que ara ets membre\n"
	.string "del Club d'Esdeveniments Misteriosos!$"

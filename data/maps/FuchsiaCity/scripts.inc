FuchsiaCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FuchsiaCity_OnResume
	.byte 0

FuchsiaCity_OnTransition:
	call_if_eq VAR_FOSSIL_SELECTION, 2, FuchsiaCity_EventScript_SetOmanyteGfx
	call_if_ne VAR_FOSSIL_SELECTION, 2, FuchsiaCity_EventScript_SetKabutoGfx
	call Common_EventScript_GetDayOrNight
	end

FuchsiaCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end

FuchsiaCity_EventScript_SetOmanyteGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OMANYTE
	return

FuchsiaCity_EventScript_SetKabutoGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_KABUTO
	return

FuchsiaCity_EventScript_FossilMonSign::
	lockall
	goto_if_eq VAR_FOSSIL_SELECTION, 2, FuchsiaCity_EventScript_OmanyteSign
	setvar VAR_0x8004, SPECIES_KABUTO
	special SetSeenMon
	showmonpic SPECIES_KABUTO, 10, 3
	msgbox FuchsiaCity_Text_KabutoSign
	hidemonpic
	releaseall
	end

FuchsiaCity_Text_KabutoSign::
    .string "Nom: Kabuto\n"
    .string "Un Pokémon extremadament rar\l"
    .string "regenerat a partir d'un fòssil.$"

FuchsiaCity_EventScript_OmanyteSign::
	setvar VAR_0x8004, SPECIES_OMANYTE
	special SetSeenMon
	showmonpic SPECIES_OMANYTE, 10, 3
	msgbox FuchsiaCity_Text_OmanyteSign
	hidemonpic
	releaseall
	end

FuchsiaCity_Text_OmanyteSign::
    .string "Nom: Omanyte\n"
    .string "Un Pokémon extremadament rar\l"
    .string "regenerat a partir d'un fòssil.$"

FuchsiaCity_EventScript_GymSign::
	lockall
	msgbox FuchsiaCity_Text_GymSign
	releaseall
	end

FuchsiaCity_Text_GymSign::
    .string "Gimnàs Pokémon de Fuchsia\n"
    .string "Líder: Koga\l"
    .string "El Mestre Ninja Verinós$"

FuchsiaCity_EventScript_ChanseySign::
	lockall
	setvar VAR_0x8004, SPECIES_CHANSEY
	special SetSeenMon
	showmonpic SPECIES_CHANSEY, 10, 3
	msgbox FuchsiaCity_Text_ChanseySign
	hidemonpic
	releaseall
	end

FuchsiaCity_Text_ChanseySign::
    .string "Nom: Chansey\n"
    .string "Atrapar-ne un depèn de la sort.$"

FuchsiaCity_EventScript_VoltorbSign::
	lockall
	setvar VAR_0x8004, SPECIES_VOLTORB
	special SetSeenMon
	showmonpic SPECIES_VOLTORB, 10, 3
	msgbox FuchsiaCity_Text_VoltorbSign
	hidemonpic
	releaseall
	end

FuchsiaCity_Text_VoltorbSign::
    .string "Nom: Voltorb\n"
    .string "La imatge exacta d'una Poké Ball.$"

FuchsiaCity_EventScript_KangaskhanSign::
	lockall
	setvar VAR_0x8004, SPECIES_KANGASKHAN
	special SetSeenMon
	showmonpic SPECIES_KANGASKHAN, 10, 3
	msgbox FuchsiaCity_Text_KangaskhanSign
	hidemonpic
	releaseall
	end

FuchsiaCity_Text_KangaskhanSign::
    .string "Nom: Kangaskhan\p"
    .string "Un Pokémon maternal que cria\n"
    .string "les seves cries a la bossa\l"
    .string "de la panxa.$"

FuchsiaCity_EventScript_SlowpokeSign::
	lockall
	setvar VAR_0x8004, SPECIES_SLOWPOKE
	special SetSeenMon
	showmonpic SPECIES_SLOWPOKE, 10, 3
	msgbox FuchsiaCity_Text_SlowpokeSign
	hidemonpic
	releaseall
	end

FuchsiaCity_Text_SlowpokeSign::
    .string "Nom: Slowpoke\n"
    .string "Amigable i molt lent.$"

FuchsiaCity_EventScript_LaprasSign::
	lockall
	setvar VAR_0x8004, SPECIES_LAPRAS
	special SetSeenMon
	showmonpic SPECIES_LAPRAS, 10, 3
	msgbox FuchsiaCity_Text_LaprasSign
	hidemonpic
	releaseall
	end

FuchsiaCity_Text_LaprasSign::
    .string "Nom: Lapras\n"
    .string "Conegut com el rei dels mars.$"

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_CitySign, MSGBOX_SIGN
	end

FuchsiaCity_Text_CitySign::
    .string "Ciutat Fuchsia\n"
    .string "Contempla! És rosa passió!$"

FuchsiaCity_EventScript_SafariZoneSign::
	msgbox FuchsiaCity_Text_SafariZoneSign, MSGBOX_SIGN
	end

FuchsiaCity_Text_SafariZoneSign::
    .string "Paradís Pokémon\n"
    .string "Zona Safari$"

FuchsiaCity_EventScript_SafariGameSign::
	msgbox FuchsiaCity_Text_SafariGameSign, MSGBOX_SIGN
	end

FuchsiaCity_Text_SafariGameSign::
    .string "Joc Safari\n"
    .string "Atrapa Pokémon!$"

FuchsiaCity_EventScript_WardensHomeSign::
	msgbox FuchsiaCity_Text_WardensHomeSign, MSGBOX_SIGN
	end

FuchsiaCity_Text_WardensHomeSign::
    .string "Zona Safari\n"
    .string "Casa del Vigilant$"

FuchsiaCity_EventScript_LittleBoy::
	msgbox FuchsiaCity_Text_DidYouTrySafariGame, MSGBOX_NPC
	end

FuchsiaCity_Text_DidYouTrySafariGame::
    .string "Has provat el Joc Safari?\p"
    .string "Hi ha Pokémon rars que només\n"
    .string "es poden atrapar allà.$"


FuchsiaCity_EventScript_OldMan::
	msgbox FuchsiaCity_Text_SafariZoneZooInFront, MSGBOX_NPC
	end

FuchsiaCity_Text_SafariZoneZooInFront::
    .string "La Zona Safari té un zoo\n"
    .string "davant de l'entrada.\p"
    .string "Al darrere hi ha el Joc Safari\n"
    .string "per atrapar Pokémon.$"


FuchsiaCity_EventScript_Erik::
	msgbox FuchsiaCity_Text_WheresSara, MSGBOX_NPC
	end

FuchsiaCity_Text_WheresSara::
    .string "Erik: On és la Sara?\n"
    .string "Li he dit que ens veuríem aquí.$"

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_ItemBallInThere, MSGBOX_NPC
	end

FuchsiaCity_Text_ItemBallInThere::
    .string "Aquella bola d'objecte…\n"
    .string "La volies?\p"
    .string "Jo també!\n"
    .string "…Eh? Això és un Pokémon?$"

FuchsiaCity_EventScript_Lass::
	lock
	faceplayer
	msgbox FuchsiaCity_Text_MyFatherIsGymLeader
	release
	end

FuchsiaCity_Text_MyFatherIsGymLeader::
    .string "El meu pare és el Líder de\n"
    .string "Gimnàs d'aquesta ciutat.\p"
    .string "M'estic entrenant per fer servir\n"
    .string "Pokémon de Verí tan bé com\l"
    .string "el meu pare.$"


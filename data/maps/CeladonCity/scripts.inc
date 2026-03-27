.set LOCALID_FAT_MAN,   1
.set LOCALID_POLIWRATH, 2
.set LOCALID_FUGITIVE, 17

CeladonCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CeladonCity_OnResume
	.byte 0

CeladonCity_OnTransition:
	setflag FLAG_VISITED_CELADON_CITY
	call Common_EventScript_GetDayOrNight
	end

CeladonCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end

CeladonCity_EventScript_ItemEther::
	finditem ITEM_ETHER, 1
	release
	end

CeladonCity_EventScript_FatMan::
	lock
	faceplayer
	msgbox CeladonCity_Text_MyTrustedPalPoliwrath
	closemessage
	applymovement LOCALID_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 1
	release
	end

CeladonCity_Text_MyTrustedPalPoliwrath::
    .string "Aquest és el meu company de\n"
    .string "confiança, Poliwrath.\p"
    .string "Va evolucionar d'un Poliwhirl\n"
    .string "quan vaig usar una Pedra Aigua.$"

CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath
	closemessage
	waitmoncry
	applymovement LOCALID_POLIWRATH, Common_Movement_FaceOriginalDirection
	waitmovement 2
	release
	end

CeladonCity_Text_Poliwrath::
    .string "Poliwrath: Ribi ribit!$"

CeladonCity_EventScript_Boy::
	msgbox CeladonCity_Text_ScaldedTongueOnTea, MSGBOX_NPC
	end

CeladonCity_Text_ScaldedTongueOnTea::
    .string "Aaaagh, au…\n"
    .string "M'he cremat la llengua!\p"
    .string "Una senyora amable de la Mansió\n"
    .string "m'ha donat una mica de Te.\p"
    .string "Però estava bullint!\n"
    .string "He d'esperar que es refredi.$"

CeladonCity_EventScript_Woman::
	msgbox CeladonCity_Text_GameCornerIsBadForCitysImage, MSGBOX_NPC
	end

CeladonCity_Text_GameCornerIsBadForCitysImage::
    .string "Celadon s'enorgulleix dels seus\n"
    .string "esforços per mantenir la ciutat\l"
    .string "bonica.\p"
    .string "Per això la nova Sala de Jocs és\n"
    .string "dolenta per a la nostra imatge.$"

CeladonCity_EventScript_RocketGrunt1::
	msgbox CeladonCity_Text_KeepOutOfTeamRocketsWay, MSGBOX_NPC
	end

CeladonCity_Text_KeepOutOfTeamRocketsWay::
    .string "No et fiquis amb l'Equip Rocket!$"

CeladonCity_EventScript_RocketGrunt2::
	msgbox CeladonCity_Text_GetLostOrIllPunchYou, MSGBOX_NPC
	end

CeladonCity_Text_GetLostOrIllPunchYou::
    .string "Què mires?\n"
    .string "Fes el camp o te'n penediràs!$"

CeladonCity_EventScript_Breeder::
	goto_if_set FLAG_RESCUED_CUBONE, CeladonCity_EventScript_BreederRescuedCubone
	msgbox CeladonCity_Text_KidnappedPokemon, MSGBOX_NPC
	end

CeladonCity_Text_KidnappedPokemon::
    .string "Oh, què puc fer…\p"
    .string "L'Equip Rocket ha estat segrestant\n"
    .string "Pokémon.\p"
    .string "He perseguit un Reclu Rocket amb\n"
    .string "un Cubone des de Lavender!\p"
    .string "Van venir corrents cap aquí,\n"
    .string "n'estic segur.\p"
    .string "Però el vaig perdre de vista!\n"
    .string "On s'amaguen?$"

CeladonCity_EventScript_BreederRescuedCubone::
	msgbox CeladonCity_Text_RescuedCubone, MSGBOX_NPC
	end

CeladonCity_Text_RescuedCubone::
    .string "Oh! Has rescatat el Cubone del\n"
    .string "l'Equip Rocket?\p"
    .string "Això és meravellós!$"

CeladonCity_EventScript_OldMan::
	msgbox CeladonCity_Text_BlewItAllAtSlots, MSGBOX_NPC
	end

CeladonCity_Text_BlewItAllAtSlots::
    .string "Ai…\n"
    .string "M'ho he jugat tot a les slots!\p"
    .string "Sabia que hauria d'haver canviat\n"
    .string "les Monedes per premis!$"

CeladonCity_EventScript_Pervert::
    msgbox CeladonCity_Text_OwOwOw, MSGBOX_NPC
    end

CeladonCity_Text_OwOwOw::
    .string "Ei! No tant fort!\n"
    .string "Au au au!$"

CeladonCity_EventScript_Jenny::
    msgbox CeladonCity_Text_CaughtThisCreep, MSGBOX_NPC
    end

CeladonCity_Text_CaughtThisCreep::
    .string "Quiet, delinqüent.\n"
    .string "Véns amb mi.$"

CeladonCity_EventScript_Police::
    msgbox CeladonCity_Text_GettingComplaints, MSGBOX_NPC
    end

CeladonCity_Text_GettingComplaints::
    .string "Rebíem queixes constantment\n"
    .string "d'entrenadores del Gimnàs\l"
    .string "d'Erika sobre algú que les\l"
    .string "molestava.$"

CeladonCity_EventScript_GymSign::
	lockall
	msgbox CeladonCity_Text_GymSign
	releaseall
	end

CeladonCity_Text_GymSign::
    .string "Gimnàs Pokémon de Celadon\n"
    .string "Líder: Erika\l"
    .string "La Princesa Amant de la Natura!$"

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_CitySign, MSGBOX_SIGN
	end

CeladonCity_Text_CitySign::
    .string "Ciutat Celadon\n"
    .string "La Ciutat dels Somnis Irisats$"

CeladonCity_EventScript_DeptStoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_Text_DeptStoreSign::
    .string "Troba el que necessites als\n"
    .string "Grans Magatzems de Celadon!$"

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_Text_MansionSign::
    .string "Mansió Celadon$"

CeladonCity_EventScript_TrainerTips1::
	msgbox CeladonCity_Text_ExplainXAccuracyDireHit, MSGBOX_SIGN
	end

CeladonCity_Text_ExplainXAccuracyDireHit::
    .string "Consells d'Entrenador:\p"
    .string "X Accuracy augmenta la precisió\n"
    .string "de les tècniques.\p"
    .string "Dire Hit augmenta la probabilitat\n"
    .string "de cops crítics.\p"
    .string "Aconsegueix els teus objectes als\n"
    .string "Grans Magatzems de Celadon!$"

CeladonCity_EventScript_TrainerTips2::
	msgbox CeladonCity_Text_GuardSpecProtectsFromStatus, MSGBOX_SIGN
	end

CeladonCity_Text_GuardSpecProtectsFromStatus::
    .string "Consells d'Entrenador:\p"
    .string "Guard Spec. protegeix els Pokémon\n"
    .string "de moviments que redueixen\l"
    .string "estadístiques en combat.\p"
    .string "Aconsegueix els teus objectes als\n"
    .string "Grans Magatzems de Celadon!$"

CeladonCity_EventScript_PrizeExchangeSign::
	msgbox CeladonCity_Text_PrizeExchangeSign, MSGBOX_SIGN
	end

CeladonCity_Text_PrizeExchangeSign::
    .string "Monedes canviades per premis!\n"
    .string "Bescanvi de Premis$"

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_Text_GameCornerSign::
    .string "Sala de Jocs Rocket\n"
    .string "Enlaire cap a un Món de Riqueses!$"

CeladonCity_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end

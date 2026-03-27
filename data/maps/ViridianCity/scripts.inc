.set LOCALID_OFFICER, 1
.set LOCALID_OLD_MAN, 2

ViridianCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ViridianCity_OnResume
	.byte 0

ViridianCity_OnTransition:
	setflag FLAG_VISITED_VIRIDIAN_CITY
	call ViridianCity_CheckGymStatus
	call Common_EventScript_GetDayOrNight
	end

ViridianCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end

ViridianCity_CheckGymStatus::
	goto_if_unset FLAG_BADGE02_GET, Common_EventScript_Return
	goto_if_unset FLAG_BADGE03_GET, Common_EventScript_Return
	goto_if_unset FLAG_BADGE04_GET, Common_EventScript_Return
	goto_if_unset FLAG_BADGE05_GET, Common_EventScript_Return
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_Return
	goto_if_unset FLAG_BADGE07_GET, Common_EventScript_Return
	setvar VAR_VIRIDIAN_CITY_GYM, 1
	return

ViridianCity_EventScripts_TeamRocketRumor1::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachJenny
	waitmovement 0
	applymovement LOCALID_OFFICER, Movement_OfficerBlockPath1
	waitmovement 1
	goto ViridianCity_EventScripts_TeamRocketRumor

Movement_OfficerBlockPath1:
	walk_left
	face_down
	step_end

ViridianCity_EventScripts_TeamRocketRumor2::
	lockall
	setvar VAR_TEMP_1, 2
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachJenny
	waitmovement 0
	goto ViridianCity_EventScripts_TeamRocketRumor

ViridianCity_EventScripts_TeamRocketRumor3::
	lockall
	setvar VAR_TEMP_1, 3
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachJenny
	waitmovement 0
	applymovement LOCALID_OFFICER, Movement_OfficerBlockPath3
	waitmovement 1
	goto ViridianCity_EventScripts_TeamRocketRumor

Movement_OfficerBlockPath3:
	walk_right
	face_down
	step_end

Movement_PlayerApproachJenny:
	walk_up
	face_up
	step_end

ViridianCity_EventScripts_TeamRocketRumor::
	turnobject LOCALID_OFFICER, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_OFFICER, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_OFFICER, Common_Movement_Delay48
	waitmovement 1
	msgbox ViridianCity_Text_InvestigatingTeamRocket, MSGBOX_DEFAULT
	call_if_eq VAR_TEMP_1, 1, ViridianCity_EventScripts_ReturnJennyToPosition1
	call_if_eq VAR_TEMP_1, 3, ViridianCity_EventScripts_ReturnJennyToPosition2
	turnobject LOCALID_OFFICER, DIR_NORTH
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerStepsBack
	waitmovement 0
	releaseall
	end

ViridianCity_Text_InvestigatingTeamRocket:
	.string "Agent: Estem investigant un rumor\n"
	.string "que l'Equip Rocket ha estat vist\l"
	.string "en aquesta zona.\p"
	.string "No podem deixar passar ningú fins\n"
	.string "que completem la nostra cerca.$"

ViridianCity_EventScripts_ReturnJennyToPosition1::
	applymovement LOCALID_OFFICER, Movement_JennyStepsRight
	waitmovement 1
	return

Movement_JennyStepsRight:
	walk_right
	face_up
	step_end

ViridianCity_EventScripts_ReturnJennyToPosition2::
	applymovement LOCALID_OFFICER, Movement_JennyStepsLeft
	waitmovement 1
	return

Movement_JennyStepsLeft:
	walk_left
	face_up
	step_end

Movement_PlayerStepsBack:
	walk_down
	walk_down
	step_end


ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_CitySign, MSGBOX_SIGN
	end

ViridianCity_Text_CitySign::
    .string "Ciutat Viridian\n"
    .string "El Paradís Eternament Verd$"

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_Text_GymSign::
    .string "Gimnàs Pokémon de Viridian$"

ViridianCity_EventScript_TrainerTips1::
	msgbox ViridianCity_Text_CatchMonsForEasierBattles, MSGBOX_SIGN
	end

ViridianCity_Text_CatchMonsForEasierBattles::
    .string "Consells d'Entrenador:\p"
    .string "Atrapa Pokémon i amplia la teva\n"
    .string "col·lecció.\p"
    .string "Com més en tinguis, més fàcil\n"
    .string "serà combatre.$"

ViridianCity_EventScript_TrainerTips2::
	msgbox ViridianCity_Text_MovesLimitedByPP, MSGBOX_SIGN
	end

ViridianCity_Text_MovesLimitedByPP::
    .string "Consells d'Entrenador:\p"
    .string "Els moviments de combat dels\n"
    .string "Pokémon estan limitats pels\l"
    .string "Punts de Poder (PP).\p"
    .string "Per recuperar PP, fes descansar\n"
    .string "els teus Pokémon a un Centre\l"
    .string "Pokémon.$"

ViridianCity_EventScript_GymDoorLocked::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	delay 20
	msgbox ViridianCity_Text_GymDoorsAreLocked, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, ViridianCity_Movement_StepAside
	waitmovement 0
	releaseall
	end

ViridianCity_Text_GymDoorsAreLocked::
    .string "Les portes del Gimnàs de Viridian\n"
    .string "estan tancades…$"

ViridianCity_Movement_StepAside::
	walk_right
	step_end

ViridianCity_EventScript_OldMan::
	lock
	faceplayer
	goto_if_eq VAR_VIRIDIAN_CITY_GYM, 1, ViridianCity_EventScript_OldManGymLeaderReturned
	msgbox ViridianCity_Text_GymClosedWonderWhoLeaderIs, MSGBOX_DEFAULT
	turnobject LOCALID_OLD_MAN, DIR_NORTH
	waitmovement 2
	release
	end

ViridianCity_Text_GymClosedWonderWhoLeaderIs::
    .string "Aquest Gimnàs Pokémon sempre\n"
    .string "està tancat.\p"
    .string "Em pregunto qui és el líder?$"

ViridianCity_EventScript_OldManGymLeaderReturned::
	msgbox ViridianCity_Text_ViridiansGymLeaderReturned, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_ViridiansGymLeaderReturned::
    .string "El Líder del Gimnàs de Viridian\n"
    .string "ha tornat!$"

ViridianCity_EventScript_Boy::
	lock
	faceplayer
	msgbox ViridianCity_Text_CanCarryMonsAnywhere, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_CanCarryMonsAnywhere::
    .string "Aquestes Poké Balls a la cintura!\n"
    .string "Tens Pokémon, oi?\p"
    .string "És genial que puguis portar i\n"
    .string "usar Pokémon en qualsevol moment.$"

ViridianCity_EventScript_Woman::
	lock
	faceplayer
	msgbox ViridianCity_Text_GoShoppingInPewterOccasionally, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_GoShoppingInPewterOccasionally::
    .string "Vaig a comprar a Ciutat Pewter\n"
    .string "de tant en tant.\p"
    .string "Haig d'agafar el camí sinuós del\n"
    .string "Bosc Viridian quan hi vaig.$"

ViridianCity_EventScript_OldMan2::
	lock
	faceplayer
	msgbox ViridianCity_Text_UsedToGetGrumpy, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_UsedToGetGrumpy:
	.string "Abans em posava molt rondinaire\n"
	.string "quan no prenia el meu cafè.\p"
	.string "Bloquejava el camí i tot!\p"
	.string "Va ser tot un espectacle...\p"
	.string "Així que la meva néta em va fer\n"
	.string "deixar el cafè.\p"
	.string "Ara em refresco fent passejades!$"

ViridianCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox ViridianCity_Text_WantToKnowAboutCaterpillarMons, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ViridianCity_EventScript_YoungsterExplainCaterpillars
	compare VAR_RESULT, NO
	goto_if_eq ViridianCity_EventScript_YoungsterDeclineExplanation
	end

ViridianCity_Text_WantToKnowAboutCaterpillarMons::
    .string "Vols saber sobre els dos tipus\n"
    .string "de Pokémon eruga?$"

ViridianCity_EventScript_YoungsterExplainCaterpillars::
	lock
	faceplayer
	msgbox ViridianCity_Text_ExplainCaterpieWeedle, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_ExplainCaterpieWeedle::
    .string "Caterpie no té verí,\n"
    .string "però Weedle sí.\p"
    .string "Vigila que els teus Pokémon no\n"
    .string "siguin punxats pel Fibló Verinós\l"
    .string "de Weedle.$"

ViridianCity_EventScript_YoungsterDeclineExplanation::
	msgbox ViridianCity_Text_OhOkayThen, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_OhOkayThen::
    .string "Oh, d'acord!$"

ViridianCity_FindItem_Potion::
	finditem ITEM_POTION, 1
	end

ViridianCity_EventScript_BerryTreeGuy::
	lock
	faceplayer
	msgbox ViridianCity_Text_PlantingBerries, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_PlantingBerries::
	.string "Sembla que un Pokémon ha estat\n"
	.string "excavant al terra per aquí.\p"
	.string "La terra és bona i tova...\n"
	.string "Hauria de plantar-hi alguna cosa!$"


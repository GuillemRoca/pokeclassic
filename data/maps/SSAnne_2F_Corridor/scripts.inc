.set LOCALID_RIVAL, 2

SSAnne_2F_Corridor_MapScripts::
	.byte 0

SSAnne_2F_Corridor_EventScript_Sailor::
	msgbox SSAnne_2F_Corridor_Text_ThisShipIsLuxuryLiner, MSGBOX_NPC
	end

SSAnne_2F_Corridor_Text_ThisShipIsLuxuryLiner::
    .string "Aquest vaixell és un transatlàntic\n"
    .string "de luxe per a entrenadors!\p"
    .string "A cada port, fem festes amb\n"
    .string "entrenadors convidats.$"

SSAnne_2F_Corridor_EventScript_RivalTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto SSAnne_2F_Corridor_EventScript_RivalTrigger
	end

SSAnne_2F_Corridor_EventScript_RivalTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	goto SSAnne_2F_Corridor_EventScript_RivalTrigger
	end

SSAnne_2F_Corridor_EventScript_RivalTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	goto SSAnne_2F_Corridor_EventScript_RivalTrigger
	end

SSAnne_2F_Corridor_EventScript_RivalTrigger::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	playse SE_EXIT
	delay 5
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	addobject LOCALID_RIVAL
	delay 10
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 2
	delay 20
	call_if_eq VAR_TEMP_1, 0, SSAnne_2F_Corridor_EventScript_RivalApproachLeft
	call_if_eq VAR_TEMP_1, 1, SSAnne_2F_Corridor_EventScript_RivalApproachMid
	call_if_eq VAR_TEMP_1, 2, SSAnne_2F_Corridor_EventScript_RivalApproachRight
	msgbox SSAnne_2F_Corridor_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_RIVAL
	trainerbattle_no_intro TRAINER_RIVAL_SS_ANNE, SSAnne_2F_Corridor_Text_RivalDefeat
	msgbox SSAnne_2F_Corridor_Text_RivalPostBattle
	closemessage
	delay 10
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, SSAnne_2F_Corridor_EventScript_RivalExitLeft
	call_if_eq VAR_TEMP_1, 1, SSAnne_2F_Corridor_EventScript_RivalExitMid
	call_if_eq VAR_TEMP_1, 2, SSAnne_2F_Corridor_EventScript_RivalExitRight
	fadedefaultbgm
	removeobject LOCALID_RIVAL
	setvar VAR_SS_ANNE_STATE, 1
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	releaseall
	end

SSAnne_2F_Corridor_Text_RivalIntro::
    .string "{RIVAL}: Bonjour!\n"
    .string "{PLAYER}!\p"
    .string "No m'esperava trobar-te aquí!\n"
    .string "{PLAYER}, t'han convidat de veritat?\p"
    .string "Com va la teva Pokédex?\p"
    .string "Jo ja n'he capturat 40 tipus, amic.\n"
    .string "N'hi ha de diferents a tot arreu.\p"
    .string "Arrossega't per zones d'herba\n"
    .string "i busca'ls bé.$"

SSAnne_2F_Corridor_Text_RivalDefeat::
    .string "Bah!\p"
    .string "Almenys estàs criant bé els\n"
    .string "teus Pokémon!$"

SSAnne_2F_Corridor_Text_RivalPostBattle::
    .string "{RIVAL}: He sentit que hi ha un\n"
    .string "mestre del tall a bord.\p"
    .string "Però només era un vell marejat!\p"
    .string "Tall en si és molt útil.\n"
    .string "Sí, serà molt pràctic.\p"
    .string "Hauries d'anar a veure'l també.\n"
    .string "Ens veiem!$"

SSAnne_2F_Corridor_EventScript_RivalApproachLeft::
	applymovement LOCALID_RIVAL, SSAnne_2F_Corridor_Movement_RivalApproachLeft
	waitmovement 2
	return

SSAnne_2F_Corridor_Movement_RivalApproachLeft::
	walk_down
	walk_down
	walk_down
	step_end

SSAnne_2F_Corridor_EventScript_RivalApproachMid::
	applymovement LOCALID_RIVAL, SSAnne_2F_Corridor_Movement_RivalApproachMid
	applymovement OBJ_EVENT_ID_PLAYER, SSAnne_2F_Corridor_Movement_PlayerFaceRivalMid
	waitmovement 2
	return

SSAnne_2F_Corridor_Movement_RivalApproachMid::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

SSAnne_2F_Corridor_Movement_PlayerFaceRivalMid::
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

SSAnne_2F_Corridor_EventScript_RivalApproachRight::
	applymovement OBJ_EVENT_ID_PLAYER, SSAnne_2F_Corridor_Movement_PlayerFaceRivalRight
	applymovement LOCALID_RIVAL, SSAnne_2F_Corridor_Movement_RivalApproachRight
	waitmovement 2
	return

SSAnne_2F_Corridor_Movement_RivalApproachRight::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	delay_4
	step_end

SSAnne_2F_Corridor_Movement_PlayerFaceRivalRight::
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

SSAnne_2F_Corridor_EventScript_RivalExitLeft::
	applymovement LOCALID_RIVAL, SSAnne_2F_Corridor_Movement_RivalExitLeft
	waitmovement 2
	return

SSAnne_2F_Corridor_Movement_RivalExitLeft::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SSAnne_2F_Corridor_EventScript_RivalExitMid::
	applymovement LOCALID_RIVAL, SSAnne_2F_Corridor_Movement_RivalExitMid
	waitmovement 2
	return

SSAnne_2F_Corridor_Movement_RivalExitMid::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SSAnne_2F_Corridor_EventScript_RivalExitRight::
	applymovement LOCALID_RIVAL, SSAnne_2F_Corridor_Movement_RivalExitRight
	waitmovement 2
	return

SSAnne_2F_Corridor_Movement_RivalExitRight::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

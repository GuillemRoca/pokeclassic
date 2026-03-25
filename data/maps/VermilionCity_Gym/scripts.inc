.equ FOUND_FIRST_SWITCH, FLAG_TEMP_1
.equ SWITCH1_ID,         VAR_0x8004
.equ SWITCH2_ID,         VAR_0x8005
.equ TRASH_CAN_ID,       VAR_0x8008

VermilionCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VermilionCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Gym_OnTransition
	.byte 0

VermilionCity_Gym_OnLoad::
	call_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_SetOneBeamOff
	call_if_set FLAG_FOUND_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_SetBeamsOff
	end

VermilionCity_Gym_EventScript_SetOneBeamOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_HalfOn, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_HalfOn, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop_HalfOn, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_HalfOn, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_HalfOn, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_HalfOn, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_HalfOn, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom_HalfOn, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_HalfOn, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_HalfOn, 1
	return

VermilionCity_Gym_EventScript_SetBeamsOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Off, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_Off, 0
	setmetatile 5, 6, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_Off, 0
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_Off, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Off, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_Off, 0
	setmetatile 5, 7, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_Off, 0
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Off, 1
	return

VermilionCity_Gym_EventScript_SetBeamsOn::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_On, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_On, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_On, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_On, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_On, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_On, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_On, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_On, 1
	return

VermilionCity_Gym_OnTransition::
	call VermilionCity_Gym_EventScript_InitTrashCans
	call_if_unset FLAG_DAILY_SURGE_REMATCH, VermilionCity_Gym_ResetRematchFlags
	end

VermilionCity_Gym_EventScript_InitTrashCans::
	goto_if_set FLAG_FOUND_VERMILION_GYM_SWITCHES, Common_EventScript_Return
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	return

VermilionCity_Gym_ResetRematchFlags::
	cleartrainerflag LEADER_REMATCH_SURGE_ORIGINAL
	cleartrainerflag LEADER_REMATCH_SURGE_POSTGAME
	return

VermilionCity_Gym_EventScript_TrashCan1::
	lockall
	setvar TRASH_CAN_ID, 1
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan2::
	lockall
	setvar TRASH_CAN_ID, 2
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan3::
	lockall
	setvar TRASH_CAN_ID, 3
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan4::
	lockall
	setvar TRASH_CAN_ID, 4
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan5::
	lockall
	setvar TRASH_CAN_ID, 5
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan6::
	lockall
	setvar TRASH_CAN_ID, 6
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan7::
	lockall
	setvar TRASH_CAN_ID, 7
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan8::
	lockall
	setvar TRASH_CAN_ID, 8
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan9::
	lockall
	setvar TRASH_CAN_ID, 9
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan10::
	lockall
	setvar TRASH_CAN_ID, 10
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan11::
	lockall
	setvar TRASH_CAN_ID, 11
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan12::
	lockall
	setvar TRASH_CAN_ID, 12
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan13::
	lockall
	setvar TRASH_CAN_ID, 13
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan14::
	lockall
	setvar TRASH_CAN_ID, 14
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan15::
	lockall
	setvar TRASH_CAN_ID, 15
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan::
	copyvar SWITCH1_ID, VAR_TEMP_0
	copyvar SWITCH2_ID, VAR_TEMP_1
	goto_if_set FLAG_FOUND_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_LocksAlreadyOpen
	goto_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_TrySwitchTwo
	compare SWITCH1_ID, TRASH_CAN_ID
	goto_if_eq VermilionCity_Gym_EventScript_FoundSwitchOne
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchOne::
	msgbox VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened
	playse SE_PIN
	waitse
	call VermilionCity_Gym_EventScript_SetOneBeamOff
	special DrawWholeMapView
	setflag FOUND_FIRST_SWITCH
	releaseall
	end

VermilionCity_Gym_EventScript_TrySwitchTwo::
	compare SWITCH2_ID, TRASH_CAN_ID
	goto_if_eq VermilionCity_Gym_EventScript_FoundSwitchTwo
	msgbox VermilionCity_Gym_Text_OnlyTrashLocksWereReset
	clearflag FOUND_FIRST_SWITCH
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	call VermilionCity_Gym_EventScript_SetBeamsOn
	special DrawWholeMapView
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchTwo::
	msgbox VermilionCity_Gym_Text_SecondLockOpened
	closemessage
	call VermilionCity_Gym_EventScript_SetBeamsOff
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	setflag FLAG_FOUND_VERMILION_GYM_SWITCHES
	releaseall
	end

VermilionCity_Gym_EventScript_LocksAlreadyOpen::
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_Text_NopeOnlyTrashHere::
    .string "No!\n"
    .string "Aquí només hi ha escombraries.$"

VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened::
    .string "Ep! Hi ha un interruptor sota les\n"
    .string "escombraries! Activa'l!\p"
    .string "El primer pany elèctric s'ha obert!$"

VermilionCity_Gym_Text_SecondLockOpened::
    .string "El segon pany elèctric s'ha obert!\n"
    .string "La porta motoritzada s'ha obert!$"

VermilionCity_Gym_Text_OnlyTrashLocksWereReset::
    .string "No!\n"
    .string "Aquí només hi ha escombraries.\p"
    .string "Ep!\n"
    .string "Els panys elèctrics s'han reiniciat!$"


VermilionCity_Gym_EventScript_Surge::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE03_GET, VermilionCity_Gym_EventScript_ChallengeLeader
	goto_if_unset FLAG_GOT_SURGE_REWARD, VermilionCity_Gym_EventScript_GetTM
	goto_if_unset FLAG_DAILY_SURGE_REMATCH, VermilionCity_Gym_EventScript_RematchLeader
	goto VermilionCity_Gym_EventScript_LeaderPostBattle
	end

VermilionCity_Gym_EventScript_ChallengeLeader::
	msgbox VermilionCity_Gym_Text_LeaderSpeech, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_SURGE, VermilionCity_Gym_Text_LeaderIntro, VermilionCity_Gym_Text_LeaderDefeat, VermilionCity_Gym_EventScript_DefeatedLeaderGetBadge
	end

VermilionCity_Gym_Text_LeaderSpeech::
    .string "Ei, nano! Què et penses que fas\n"
    .string "aquí?\p"
    .string "No duraràs gaire en combat!\n"
    .string "No amb el teu poder tan feble!\p"
    .string "Et dic, nano, els Pokémon elèctrics\n"
    .string "em van salvar durant la guerra!$"

VermilionCity_Gym_Text_LeaderIntro::
 	.string "Van fullejar els meus enemics\n"
    .string "fins a la paràlisi!\p"
    .string "I et faré el mateix a tu!$"

VermilionCity_Gym_Text_LeaderDefeat::
    .string "Això sí que és un xoc!\p"
    .string "Ets de debò, nano!$"

VermilionCity_Gym_EventScript_DefeatedLeaderGetBadge::
	msgbox VermilionCity_Gym_Text_GetBadge, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	message VermilionCity_Gym_Text_ReceivedBadge
	waitfanfare
	waitmessage
	msgbox VermilionCity_Gym_Text_ExplainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE03_GET
	setflag FLAG_DAILY_SURGE_REMATCH
	settrainerflag TRAINER_SAILOR_DWAYNE
	settrainerflag TRAINER_ENGINEER_BAILY
	settrainerflag TRAINER_GENTLEMAN_TUCKER
	call_if_set FLAG_RECEIVED_HM05, VermilionCity_Gym_EventScript_QueueNextAideCall
	goto VermilionCity_Gym_EventScript_GetTM
	end

VermilionCity_Gym_EventScript_QueueNextAideCall::
	setflag FLAG_QUEUE_AIDE_CALL
	setflag FLAG_AIDE_LOCATION_2
	return

VermilionCity_Gym_Text_GetBadge::
    .string "D'acord, doncs, pren la Medalla Tro!$"

VermilionCity_Gym_Text_ReceivedBadge::
	.string "{PLAYER} ha rebut la Medalla\n"
    .string "Tro del Lt. Surge!$"

VermilionCity_Gym_Text_ExplainBadge::
    .string "La Medalla Tro habilita els teus\n"
    .string "Pokémon per usar Vol fora de\l"
    .string "combat.\p"
    .string "Si coneixen el moviment, podran\n"
    .string "moure's ràpid com un llamp!\p"
    .string "Ets especial, nano!$"

VermilionCity_Gym_EventScript_GetTM::
	msgbox VermilionCity_Gym_Text_TakeThisWithYou, MSGBOX_DEFAULT
	checkitemspace ITEM_TM34, 1
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_Gym_EventScript_NoRoomForTM
	playfanfare MUS_OBTAIN_TMHM
	msgbox VermilionCity_Gym_Text_ReceivedTM, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_TM34, 1
	setflag FLAG_GOT_SURGE_REWARD
	msgbox VermilionCity_Gym_Text_ExplainTM, MSGBOX_DEFAULT
	release
	end

VermilionCity_Gym_Text_TakeThisWithYou::
    .string "Pren això!$"

VermilionCity_Gym_Text_ReceivedTM::
    .string "{PLAYER} ha rebut el MT34\n"
    .string "del Lt. Surge.$"

VermilionCity_Gym_Text_ExplainTM::
    .string "El MT34 conté Ona de Xoc!\p"
    .string "Ensenya-la a un Pokémon Elèctric!$"

VermilionCity_Gym_EventScript_NoRoomForTM::
	msgbox VermilionCity_Gym_Text_NoRoomForTM, MSGBOX_DEFAULT
	release
	end

VermilionCity_Gym_Text_NoRoomForTM::
    .string "Nano, fes espai a la motxilla!$"

VermilionCity_Gym_EventScript_LeaderPostBattle::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, VermilionCity_Gym_EventScript_LeaderPostBattleGameClear
	msgbox VermilionCity_Gym_Text_LeaderPostBattle, MSGBOX_DEFAULT
	release
	end

VermilionCity_Gym_Text_LeaderPostBattle::
    .string "Un petit consell, nano!\p"
    .string "L'electricitat és molt poderosa!\p"
    .string "Però és inútil contra els Pokémon\n"
    .string "de tipus Terra!$"

VermilionCity_Gym_EventScript_LeaderPostBattleGameClear::
	msgbox VermilionCity_Gym_Text_PostBattleGameClear, MSGBOX_DEFAULT
	release
	end

VermilionCity_Gym_Text_PostBattleGameClear::
	.string "Sembla que encara hi ha un desnivell\n"
	.string "entre les nostres habilitats que\l"
	.string "haig de tancar, nano!\p"
	.string "És el primer cop que em sento\n"
	.string "així des que vaig començar com\l"
	.string "a Líder de Gimnàs de Vermilion.$"

VermilionCity_Gym_EventScript_RematchLeader::
	msgbox VermilionCity_Gym_Text_RematchLeader, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_Gym_EventScript_DeclineRematch
	goto_if_set FLAG_SYS_GAME_CLEAR, VermilionCity_Gym_EventScript_PostgameRematch
	goto VermilionCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

VermilionCity_Gym_Text_RematchLeader::
	.string "Ei, nano! Força xocant que hagis\n"
	.string "arribat tan lluny en el teu viatge!\p"
	.string "Segur que els Pokémon de tipus\n"
	.string "Elèctric t'han ajudat molt, oi?\p"
	.string "D'acord, doncs. Què tal una revenja\n"
	.string "per mostrar-me els Pokémon que has\l"
	.string "criat?$"

VermilionCity_Gym_EventScript_DeclineRematch::
	msgbox VermilionCity_Gym_Text_DeclineRematch, MSGBOX_DEFAULT
	release
	end

VermilionCity_Gym_Text_DeclineRematch::
	.string "Bah. Covard!$"

VermilionCity_Gym_EventScript_PostgameRematch::
	msgbox VermilionCity_Gym_Text_RematchMode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_Gym_EventScript_LeaderRematch_PostGameTeam
	goto VermilionCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

VermilionCity_Gym_Text_RematchMode::
	.string "Ara que ets el campió,\n"
	.string "vols anar amb tot?$"

VermilionCity_Gym_EventScript_LeaderRematch_OriginalTeam::
	trainerbattle_single LEADER_REMATCH_SURGE_ORIGINAL, VermilionCity_Gym_Text_RematchOriginal, VermilionCity_Gym_Text_RematchDefeat, VermilionCity_Gym_EventScript_DefeatedLeaderRematch
	end

VermilionCity_Gym_Text_RematchOriginal::
	.string "Ferms!\n"
	.string "Recorda, un combat Pokémon és una\l"
	.string "guerra!\p"
	.string "Som-hi, nano!$"

VermilionCity_Gym_EventScript_LeaderRematch_PostGameTeam::
	trainerbattle_single LEADER_REMATCH_SURGE_POSTGAME, VermilionCity_Gym_Text_RematchPostgame, VermilionCity_Gym_Text_RematchDefeat, VermilionCity_Gym_EventScript_DefeatedLeaderRematch
	end

VermilionCity_Gym_Text_RematchPostgame::
	.string "No cal presentar-se aquest cop!\n"
	.string "Entrenadors com nosaltres no\l"
	.string "necessitem paraules!\p"
	.string "Som-hi, nano!$"

VermilionCity_Gym_EventScript_DefeatedLeaderRematch::
	setflag FLAG_DAILY_SURGE_REMATCH
	goto VermilionCity_Gym_EventScript_LeaderPostBattle
	end

VermilionCity_Gym_Text_RematchDefeat::
	.string "Absolutament xocant!$"

VermilionCity_Gym_EventScript_Dwayne::
	trainerbattle_single TRAINER_SAILOR_DWAYNE, VermilionCity_Gym_Text_DwayneIntro, VermilionCity_Gym_Text_DwayneDefeat
	msgbox VermilionCity_Gym_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_Text_DwayneIntro::
    .string "Això no és lloc per a nens!\n"
    .string "Ni encara que siguis bo!$"

VermilionCity_Gym_Text_DwayneDefeat::
    .string "Uau!\n"
    .string "M'has sorprès!$"

VermilionCity_Gym_Text_DwaynePostBattle::
    .string "El Lt. Surge va instal·lar les\n"
    .string "trampes del gimnàs ell mateix.\p"
    .string "Va posar dobles panys a tot arreu.\n"
    .string "Deixa que et doni una pista.\p"
    .string "Quan obris el primer pany, el\n"
    .string "segon és just al costat.$"

VermilionCity_Gym_EventScript_Baily::
	trainerbattle_single TRAINER_ENGINEER_BAILY, VermilionCity_Gym_Text_BailyIntro, VermilionCity_Gym_Text_BailyDefeat
	msgbox VermilionCity_Gym_Text_BailyPostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_Text_BailyIntro::
    .string "Sóc prim, però em va bé amb\n"
    .string "l'electricitat!\p"
    .string "Per això em vaig unir a aquest\n"
    .string "gimnàs.$"

VermilionCity_Gym_Text_BailyDefeat::
    .string "Fregit!$"

VermilionCity_Gym_Text_BailyPostBattle::
    .string "D'acord, parlaré!\p"
    .string "El Lt. Surge va dir que va amagar\n"
    .string "interruptors dins d'alguna cosa.$"

VermilionCity_Gym_EventScript_Tucker::
	trainerbattle_single TRAINER_GENTLEMAN_TUCKER, VermilionCity_Gym_Text_TuckerIntro, VermilionCity_Gym_Text_TuckerDefeat
	msgbox VermilionCity_Gym_Text_TuckerPostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_Text_TuckerIntro::
    .string "Quan era a l'exèrcit, el Lt. Surge\n"
    .string "era el meu comandant.\p"
    .string "Era molt exigent.$"

VermilionCity_Gym_Text_TuckerDefeat::
    .string "Para!\n"
    .string "Ets molt bo!$"

VermilionCity_Gym_Text_TuckerPostBattle::
    .string "No és fàcil obrir aquella porta.\p"
    .string "El Lt. Surge sempre va ser famós\n"
    .string "per la seva cautela a l'exèrcit.$"


VermilionCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE03_GET, VermilionCity_Gym_EventScript_GymGuyPostVictory
	msgbox VermilionCity_Gym_Text_GymGuyAdvice
	release
	end

VermilionCity_Gym_Text_GymGuyAdvice::
    .string "Ei!\n"
    .string "Futur campió!\p"
    .string "El Lt. Surge té un sobrenom.\p"
    .string "La gent l'anomena el\n"
    .string "Lloctinent Llampec!\p"
    .string "És expert en Pokémon elèctrics.\p"
    .string "Els Pokémon d'Ocell i Aigua han\n"
    .string "d'anar amb compte amb els atacs\l"
    .string "Elèctrics!\p"
    .string "Vigila amb la paràlisi, també.\p"
    .string "El Lt. Surge és molt cautelós.\p"
    .string "S'ha tancat dins, així que no\n"
    .string "serà fàcil arribar-hi.$"

VermilionCity_Gym_EventScript_GymGuyPostVictory::
	msgbox VermilionCity_Gym_Text_GymGuyPostVictory
	release
	end

VermilionCity_Gym_Text_GymGuyPostVictory::
    .string "Uau!\n"
    .string "Aquell combat ha estat elèctric!$"

VermilionCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, VermilionCity_Gym_EventScript_GymStatuePostVictory
	msgbox VermilionCity_Gym_Text_GymStatue
	releaseall
	end

VermilionCity_Gym_Text_GymStatue::
    .string "Gimnàs Pokémon de Vermilion\n"
    .string "Líder: Lt. Surge\p"
    .string "Entrenadors guanyadors:\n"
    .string "{RIVAL}$"

VermilionCity_Gym_EventScript_GymStatuePostVictory::
	msgbox VermilionCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

VermilionCity_Gym_Text_GymStatuePlayerWon::
    .string "Gimnàs Pokémon de Vermilion\n"
    .string "Líder: Lt. Surge\p"
    .string "Entrenadors guanyadors:\n"
    .string "{RIVAL}, {PLAYER}$"

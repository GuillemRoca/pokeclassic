BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_E, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_E, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_0
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_STEVEN is used as a placeholder
BattlePyramid_TrainerBattle::
	trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_STEVEN, 0, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "Això és un missatge d'exemple.$"

gText_BattlePyramidConfirmRest::
	.string "La teva cerca a la Piràmide de\n"
	.string "Combat es desarà perquè puguis\l"
	.string "sortir ara. D'acord?$"

gText_BattlePyramidConfirmRetire::
	.string "Segur que vols abandonar la\n"
	.string "teva cerca a la Piràmide?$"

BattlePyramid_Text_ExitHintUp1::
	.string "La sortida d'aquest pis és\n"
	.string "en aquella direcció: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1::
	.string "La sortida d'aquest pis és\n"
	.string "en aquella direcció: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1::
	.string "La sortida d'aquest pis és\n"
	.string "en aquella direcció: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1::
	.string "La sortida d'aquest pis és\n"
	.string "en aquella direcció: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2::
	.string "La sortida d'aquest pis és\n"
	.string "en la direcció {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft2::
	.string "La sortida d'aquest pis és\n"
	.string "en la direcció {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight2::
	.string "La sortida d'aquest pis és\n"
	.string "en la direcció {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown2::
	.string "La sortida d'aquest pis és\n"
	.string "en la direcció {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp3::
	.string "La sortida és cap\n"
	.string "allà {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft3::
	.string "La sortida és cap\n"
	.string "allà {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight3::
	.string "La sortida és cap\n"
	.string "allà {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown3::
	.string "La sortida és cap\n"
	.string "allà {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp4::
	.string "En aquest pis, la sortida és\n"
	.string "en algun lloc en direcció {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft4::
	.string "En aquest pis, la sortida és\n"
	.string "en algun lloc en direcció {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight4::
	.string "En aquest pis, la sortida és\n"
	.string "en algun lloc en direcció {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown4::
	.string "En aquest pis, la sortida és\n"
	.string "en algun lloc en direcció {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp5::
	.string "La sortida?\n"
	.string "És cap allà {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft5::
	.string "La sortida?\n"
	.string "És cap allà {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight5::
	.string "La sortida?\n"
	.string "És cap allà {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown5::
	.string "La sortida?\n"
	.string "És cap allà {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp6::
	.string "Resulta que la sortida és\n"
	.string "en la direcció {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft6::
	.string "Resulta que la sortida és\n"
	.string "en la direcció {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight6::
	.string "Resulta que la sortida és\n"
	.string "en la direcció {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown6::
	.string "Resulta que la sortida és\n"
	.string "en la direcció {DOWN_ARROW}.$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "Busques objectes?\p"
	.string "Queden vuit objectes per\n"
	.string "trobar.$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "Busques objectes?\p"
	.string "Queden set objectes per\n"
	.string "trobar.$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "Busques objectes?\p"
	.string "Queden sis objectes per\n"
	.string "trobar.$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "Busques objectes?\p"
	.string "Queden cinc objectes per\n"
	.string "trobar.$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "Busques objectes?\p"
	.string "Queden quatre objectes per\n"
	.string "trobar.$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "Busques objectes?\p"
	.string "Queden tres objectes per\n"
	.string "trobar.$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "Busques objectes?\p"
	.string "Queden dos objectes per\n"
	.string "trobar.$"

BattlePyramid_Text_OneItemRemaining1::
	.string "Busques objectes?\p"
	.string "Queda un objecte per\n"
	.string "trobar.$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "Busques objectes?\p"
	.string "No queda res més per\n"
	.string "trobar!$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "Com que has guanyat, et diré\n"
	.string "un petit secret!\p"
	.string "Hi ha vuit objectes\n"
	.string "escampats per aquí.$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "Com que has guanyat, et diré\n"
	.string "un petit secret!\p"
	.string "Queden set objectes\n"
	.string "escampats per aquí.$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "Com que has guanyat, et diré\n"
	.string "un petit secret!\p"
	.string "Queden sis objectes\n"
	.string "escampats per aquí.$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "Com que has guanyat, et diré\n"
	.string "un petit secret!\p"
	.string "Queden cinc objectes\n"
	.string "escampats per aquí.$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "Com que has guanyat, et diré\n"
	.string "un petit secret!\p"
	.string "Queden quatre objectes\n"
	.string "escampats per aquí.$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "Com que has guanyat, et diré\n"
	.string "un petit secret!\p"
	.string "Queden tres objectes\n"
	.string "escampats per aquí.$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "Com que has guanyat, et diré\n"
	.string "un petit secret!\p"
	.string "Queden dos objectes\n"
	.string "escampats per aquí.$"

BattlePyramid_Text_OneItemRemaining2::
	.string "Com que has guanyat, et diré\n"
	.string "un petit secret!\p"
	.string "Només queda un objecte\n"
	.string "escampat per aquí.$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "Com que has guanyat, et diré\n"
	.string "un petit secret!\p"
	.string "No queda res més\n"
	.string "escampat per aquí.$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "Com van les teves provisions?\p"
	.string "Diria que queden vuit objectes\n"
	.string "per trobar en aquest pis.$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "Com van les teves provisions?\p"
	.string "Diria que queden set objectes\n"
	.string "per trobar en aquest pis.$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "Com van les teves provisions?\p"
	.string "Diria que queden sis objectes\n"
	.string "per trobar en aquest pis.$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "Com van les teves provisions?\p"
	.string "Diria que queden cinc objectes\n"
	.string "per trobar en aquest pis.$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "Com van les teves provisions?\p"
	.string "Diria que queden quatre objectes\n"
	.string "per trobar en aquest pis.$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "Com van les teves provisions?\p"
	.string "Diria que queden tres objectes\n"
	.string "per trobar en aquest pis.$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "Com van les teves provisions?\p"
	.string "Diria que queden dos objectes\n"
	.string "per trobar en aquest pis.$"

BattlePyramid_Text_OneItemRemaining3::
	.string "Com van les teves provisions?\p"
	.string "Diria que només queda un objecte\n"
	.string "per trobar en aquest pis.$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "Com van les teves provisions?\p"
	.string "Diria que no queden més objectes\n"
	.string "per trobar en aquest pis.\l"
	.string "Ves amb compte!$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "Ets fort, així que t'has guanyat\n"
	.string "una pista!\p"
	.string "Sembla que hi ha vuit objectes\n"
	.string "més a terra.$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "Ets fort, així que t'has guanyat\n"
	.string "una pista!\p"
	.string "Sembla que hi ha set objectes\n"
	.string "més a terra.$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "Ets fort, així que t'has guanyat\n"
	.string "una pista!\p"
	.string "Sembla que hi ha sis objectes\n"
	.string "més a terra.$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "Ets fort, així que t'has guanyat\n"
	.string "una pista!\p"
	.string "Sembla que hi ha cinc objectes\n"
	.string "més a terra.$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "Ets fort, així que t'has guanyat\n"
	.string "una pista!\p"
	.string "Sembla que hi ha quatre objectes\n"
	.string "més a terra.$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "Ets fort, així que t'has guanyat\n"
	.string "una pista!\p"
	.string "Sembla que hi ha tres objectes\n"
	.string "més a terra.$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "Ets fort, així que t'has guanyat\n"
	.string "una pista!\p"
	.string "Sembla que hi ha dos objectes\n"
	.string "més a terra.$"

BattlePyramid_Text_OneItemRemaining4::
	.string "Ets fort, així que t'has guanyat\n"
	.string "una pista!\p"
	.string "Sembla que només queda un\n"
	.string "objecte més a terra.$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "Ets fort, així que t'has guanyat\n"
	.string "una pista!\p"
	.string "Sembla que no queden més\n"
	.string "objectes a terra.$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "En aquest pis de la Piràmide,\n"
	.string "he sentit que hi ha vuit objectes…$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "En aquest pis de la Piràmide,\n"
	.string "he sentit que hi ha set objectes…$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "En aquest pis de la Piràmide,\n"
	.string "he sentit que hi ha sis objectes…$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "En aquest pis de la Piràmide,\n"
	.string "he sentit que hi ha cinc objectes…$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "En aquest pis de la Piràmide,\n"
	.string "he sentit que hi ha quatre objectes…$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "En aquest pis de la Piràmide,\n"
	.string "he sentit que hi ha tres objectes…$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "En aquest pis de la Piràmide,\n"
	.string "he sentit que hi ha dos objectes…$"

BattlePyramid_Text_OneItemRemaining5::
	.string "En aquest pis de la Piràmide,\n"
	.string "he sentit que hi ha un objecte…$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "En aquest pis de la Piràmide,\n"
	.string "he sentit que no hi ha objectes…$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "Has recollit algun objecte?\p"
	.string "Crec que queden vuit objectes\n"
	.string "més en aquest pis.$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "Has recollit algun objecte?\p"
	.string "Crec que queden set objectes\n"
	.string "més en aquest pis.$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "Has recollit algun objecte?\p"
	.string "Crec que queden sis objectes\n"
	.string "més en aquest pis.$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "Has recollit algun objecte?\p"
	.string "Crec que queden cinc objectes\n"
	.string "més en aquest pis.$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "Has recollit algun objecte?\p"
	.string "Crec que queden quatre objectes\n"
	.string "més en aquest pis.$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "Has recollit algun objecte?\p"
	.string "Crec que queden tres objectes\n"
	.string "més en aquest pis.$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "Has recollit algun objecte?\p"
	.string "Crec que queden dos objectes\n"
	.string "més en aquest pis.$"

BattlePyramid_Text_OneItemRemaining6::
	.string "Has recollit algun objecte?\p"
	.string "Crec que queda un objecte\n"
	.string "més en aquest pis.$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "Has recollit algun objecte?\p"
	.string "Crec que no queden més\n"
	.string "objectes en aquest pis.$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "Has estat genial!\p"
	.string "Però encara queden set\n"
	.string "Entrenadors forts a part de mi!$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "Has estat genial!\p"
	.string "Però encara queden sis\n"
	.string "Entrenadors forts a part de mi!$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "Has estat genial!\p"
	.string "Però encara queden cinc\n"
	.string "Entrenadors forts a part de mi!$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "Has estat genial!\p"
	.string "Però encara queden quatre\n"
	.string "Entrenadors forts a part de mi!$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "Has estat genial!\p"
	.string "Però encara queden tres\n"
	.string "Entrenadors forts a part de mi!$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "Has estat genial!\p"
	.string "Però encara queden dos\n"
	.string "Entrenadors forts a part de mi!$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "Has estat genial!\p"
	.string "Però encara queda un Entrenador\n"
	.string "fort a part de mi!$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "Has estat genial!\p"
	.string "No queda ningú que et\n"
	.string "pugui vèncer!$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "Quina ràbia!\p"
	.string "Però queden set Entrenadors!\n"
	.string "Algú t'humiliarà!$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "Quina ràbia!\p"
	.string "Però queden sis Entrenadors!\n"
	.string "Algú t'humiliarà!$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "Quina ràbia!\p"
	.string "Però queden cinc Entrenadors!\n"
	.string "Algú t'humiliarà!$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "Quina ràbia!\p"
	.string "Però queden quatre Entrenadors!\n"
	.string "Algú t'humiliarà!$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "Quina ràbia!\p"
	.string "Però queden tres Entrenadors!\n"
	.string "Algú t'humiliarà!$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "Quina ràbia!\p"
	.string "Però queden dos Entrenadors!\n"
	.string "Algú t'humiliarà!$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "Quina ràbia!\p"
	.string "Però queda un Entrenador!\n"
	.string "Segur que et derrotarà!$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "Quina ràbia!\p"
	.string "Però no queden més Entrenadors\n"
	.string "que puguin lluitar contra tu!$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "Força impressionant!\p"
	.string "Però queden set Entrenadors més\n"
	.string "en aquest pis. Podràs amb tots?$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "Força impressionant!\p"
	.string "Però queden sis Entrenadors més\n"
	.string "en aquest pis. Podràs amb tots?$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "Força impressionant!\p"
	.string "Però queden cinc Entrenadors més\n"
	.string "en aquest pis. Podràs amb tots?$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "Força impressionant!\p"
	.string "Però queden quatre Entrenadors\n"
	.string "més en aquest pis. Podràs amb tots?$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "Força impressionant!\p"
	.string "Però queden tres Entrenadors més\n"
	.string "en aquest pis. Podràs amb tots?$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "Força impressionant!\p"
	.string "Però queden dos Entrenadors més\n"
	.string "en aquest pis. Podràs amb tots dos?$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "Força impressionant!\p"
	.string "Però encara queda un Entrenador\n"
	.string "en aquest pis. Podràs guanyar?$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "Força impressionant!\p"
	.string "Has vençut tots els Entrenadors\n"
	.string "d'aquest pis.$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "Potser podries escombrar els\n"
	.string "set Entrenadors que queden aquí.$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "Potser podries escombrar els\n"
	.string "sis Entrenadors que queden aquí.$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "Potser podries escombrar els\n"
	.string "cinc Entrenadors que queden aquí.$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "Potser podries escombrar els\n"
	.string "quatre Entrenadors que queden aquí.$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "Potser podries escombrar els\n"
	.string "tres Entrenadors que queden aquí.$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "Potser podries escombrar els\n"
	.string "dos Entrenadors que queden aquí.$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "Potser podries completar la neteja\n"
	.string "amb l'Entrenador que queda aquí.$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "No queda ni una sola persona que\n"
	.string "et pugui derrotar ara…$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "Potser tens el que cal per vèncer\n"
	.string "els set Entrenadors experts que queden.$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "Potser tens el que cal per vèncer\n"
	.string "els sis Entrenadors experts que queden.$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "Potser tens el que cal per vèncer\n"
	.string "els cinc Entrenadors experts que queden.$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "Potser tens el que cal per vèncer\n"
	.string "els quatre Entrenadors experts restants.$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "Potser tens el que cal per vèncer\n"
	.string "els tres Entrenadors experts que queden.$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "Potser tens el que cal per vèncer\n"
	.string "els dos Entrenadors experts que queden.$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "Potser tens el que cal per vèncer\n"
	.string "l'Entrenador expert que queda.$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "Les teves habilitats són\n"
	.string "irreprotxables.\p"
	.string "No queden més Entrenadors aquí\n"
	.string "que tinguin cap opció de guanyar-te.$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "Podràs seguir guanyant contra\n"
	.string "els set Entrenadors restants?$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "Podràs seguir guanyant contra\n"
	.string "els sis Entrenadors restants?$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "Podràs seguir guanyant contra\n"
	.string "els cinc Entrenadors restants?$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "Podràs seguir guanyant contra\n"
	.string "els quatre Entrenadors restants?$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "Podràs seguir guanyant contra\n"
	.string "els tres Entrenadors restants?$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "Podràs seguir guanyant contra\n"
	.string "els dos Entrenadors restants?$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "Podràs seguir guanyant contra\n"
	.string "l'últim Entrenador que queda?$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "No queden Entrenadors que puguin\n"
	.string "plantar-te cara ara…$"

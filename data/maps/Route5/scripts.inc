.set LOCALID_DAYCARE_WOMAN, 1
.set LOCALID_FUGITIVE, 11

Route5_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route5_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, Route5_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route5_OnResume
	.byte 0

Route5_OnFrame::
	map_script_2 VAR_DAYCARE_EGG_PENDING, 1, Route5_EventScript_TryTurnDayCareWoman
	.2byte 0

Route5_EventScript_TryTurnDayCareWoman::
	turnobject LOCALID_DAYCARE_WOMAN, DIR_SOUTH
	setvar VAR_DAYCARE_EGG_PENDING, 0
	end

Route5_OnTransition:
	call_if_set FLAG_PENDING_DAYCARE_EGG, Route5_EventScript_TurnCareWoman
	call Common_EventScript_GetDayOrNight
	end

Route5_EventScript_TurnCareWoman::
	setobjectmovementtype LOCALID_DAYCARE_WOMAN, MOVEMENT_TYPE_FACE_DOWN
	setvar VAR_DAYCARE_EGG_PENDING, 0
	return

Route5_OnResume:
	call_if_set FLAG_PENDING_DAYCARE_EGG, Route5_EventScript_TurnCareWoman
	call Common_EventScript_GetDayOrNight
	end

Route5_EventScript_UndergroundPathSign::
	msgbox Route5_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route5_Text_UndergroundPathSign::
    .string "Pas Subterrani\n"

    .string "Cerulean City - Vermilion City$"


Route5_EventScript_DayCareSign::
	msgbox Route5_Text_DayCareSign, MSGBOX_SIGN
	end

Route5_Text_DayCareSign::
	.string "Guarderia Pokémon\n"

	.string "“Cuidem els teus Pokémon.”$"



@Daycare Woman
Route5_EventScript_DaycareWoman::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route5_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route5_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route5_EventScript_CheckOnTwoMons
	msgbox Route5_Text_GoInsideIfYoudLikeMeToRaiseMon, MSGBOX_NPC
	turnobject LOCALID_DAYCARE_WOMAN, DIR_NORTH
	release
	end

Route5_Text_GoInsideIfYoudLikeMeToRaiseMon:
	.string "Sóc voluntària a la Guarderia.\p"

	.string "Entrenadors de tot Kanto ens\n"

	.string "demanen que cuidem els seus\l"

	.string "Pokémon.\p"

	.string "Si vols que cuidem els teus\n"

	.string "Pokémon, entra a dins.$"


Route5_EventScript_DaycareEggWaiting::
	msgbox Route5_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_EventScript_DaycareAcceptEgg
	msgbox Route5_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route5_EventScript_DaycareAcceptEgg
	msgbox Route5_Text_IllKeepIt, MSGBOX_NPC
	clearflag FLAG_PENDING_DAYCARE_EGG
	setvar VAR_DAYCARE_EGG_PENDING, 0
	special RejectEggFromDayCare
	release
	end

Route5_Text_DoYouWantEgg:
	.string "Oh, ets tu!\p"

	.string "Estàvem cuidant els teus Pokémon,\n"

	.string "i quina sorpresa ens hem endut!\p"

	.string "El teu Pokémon tenia un Ou!\p"

	.string "No sabem com ha arribat aquí,\n"

	.string "però el teu Pokémon el tenia.\p"

	.string "Te'l vols endur?$"


Route5_Text_IWillKeepDoYouWantIt:
	.string "No te'l vols endur?\n"

	.string "Vols que el doni?$"


Route5_Text_IllKeepIt:
	.string "D'acord! Li trobarem una bona\n"

	.string "llar a aquest Ou.$"


Route5_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route5_EventScript_DaycareReceiveEgg
	msgbox Route5_Text_YouHaveNoRoomForIt, MSGBOX_NPC
	release
	end

Route5_Text_YouHaveNoRoomForIt:
	.string "No tens espai…\n"

	.string "Torna quan en tinguis.$"


Route5_EventScript_DaycareReceiveEgg::
	message Route5_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox Route5_Text_TakeGoodCareOfIt, MSGBOX_NPC
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	setvar VAR_DAYCARE_EGG_PENDING, 0
	turnobject LOCALID_DAYCARE_WOMAN, DIR_NORTH
	release
	end

Route5_Text_ReceivedEgg:
	.string "{PLAYER} ha rebut l'Ou de\n"

	.string "la Guarderia.$"


Route5_Text_TakeGoodCareOfIt:
	.string "Cuida'l bé!$"


Route5_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route5_Text_YourMonIsDoingFine, MSGBOX_NPC
	turnobject LOCALID_DAYCARE_WOMAN, DIR_NORTH
	release
	end

Route5_Text_YourMonIsDoingFine:
	.string "Oh, ets tu! M'alegro de veure't.\n"

	.string "El teu {STR_VAR_1} va bé.$"


Route5_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route5_Text_YourMonsAreDoingFine, MSGBOX_NPC
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	turnobject LOCALID_DAYCARE_WOMAN, DIR_NORTH
	release
	end

Route5_Text_YourMonsAreDoingFine:
	.string "Oh, ets tu! El teu {STR_VAR_1} i\n"

	.string "{STR_VAR_2} van bé.$"


Route5_EventScript_BerryGuy::
	lock
	faceplayer
	msgbox Route5_Text_FriendshipBerries MSGBOX_DEFAULT
	release
	end

Route5_Text_FriendshipBerries:
	.string "He sentit que hi ha baies que\n"

	.string "fan un Pokémon més amistós.$"


Route5_RocketFugitive::
	trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE
	waitse
	fadescreen FADE_FROM_BLACK
	end

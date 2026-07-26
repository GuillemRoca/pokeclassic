.set LOCALID_JENNY, 1

Route7_EastEntrance_MapScripts::
	.byte 0

@TODO: The Gate Guards are not the road block anymore, but giving them tea will be a new daily event. Reward is TBD.

Route7_EastEntrance_EventScript_Guard::
	goto_if_unset FLAG_DAILY_GUARD_TEA, Route7_EastEntrance_EventScript_GuardThirsty
	goto_if_unset FLAG_DELIVERED_ROCKET_PLANS, Route7_EastEntrance_EventScript_RoadsClosed
	msgbox Route7_EastEntrance_Text_HiHowsItGoing, MSGBOX_NPC
	end

Route7_EastEntrance_Text_HiHowsItGoing::
    .string "Hola, com va?$"

Route7_EastEntrance_EventScript_RoadsClosed::
	msgbox Route7_EastEntrance_Text_RoadsClosed, MSGBOX_NPC
	release
	end

Route7_EastEntrance_Text_RoadsClosed::
    .string "Ah, per cert, el camí és tancat.\p"
    .string "La Policia Internacional està\n"
    .string "buscant l'Equip Rocket!$"

Route7_EastEntrance_EventScript_GuardThirsty::
	msgbox Route7_EastEntrance_Text_ThirstyOnGuardDuty, MSGBOX_NPC
	checkitem ITEM_TEA
	goto_if_eq VAR_RESULT, FALSE, Route7_EastEntrance_EventScript_GuardSmallTalk
	msgbox Route7_EastEntrance_Text_ThatTeaLooksTasty, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route7_EastEntrance_EventScript_DenyGuard
	removeitem ITEM_TEA, 1
	setflag FLAG_DAILY_GUARD_TEA
	msgbox Route7_EastEntrance_Text_ThanksIllShareTeaWithGuards, MSGBOX_NPC
	random 3
	goto_if_eq VAR_RESULT, 0, GateGuard_GiveNugget
	goto_if_eq VAR_RESULT, 1, GateGuard_GiveStone
	goto_if_eq VAR_RESULT, 2, GateGuard_ResetSnorlax1
	goto_if_eq VAR_RESULT, 3, GateGuard_ResetSnorlax2
	end

Route7_EastEntrance_Text_ThirstyOnGuardDuty::
    .string "Estic de guàrdia.\n"
    .string "Ui, quina set que tinc!$"

Route7_EastEntrance_Text_ThatTeaLooksTasty::
    .string "Oh, aquell te…\n"
    .string "Té una pinta tan bona…$"

Route7_EastEntrance_Text_ThanksIllShareTeaWithGuards::
    .string "Eh? Me'l puc quedar?\n"
    .string "Gràcies!\l"
    .string "… …\l"
    .string "Glup, glup…\l"
    .string "… …\l"
    .string "Gulp…\l"
    .string "… …\l"
    .string "Això sí que m'ha anat bé!…\p"
    .string "Compartiré aquest te amb els\n"
    .string "altres guàrdies!$"

Route7_EastEntrance_EventScript_DenyGuard::
	msgbox Route7_EastEntrance_Text_ThatsAShame, MSGBOX_NPC
	release
	end

Route7_EastEntrance_Text_ThatsAShame::
	.string "Oh, quina llàstima.\n"
	.string "Bé m'aniria una beguda...$"

Route7_EastEntrance_EventScript_GuardSmallTalk::
	goto_if_unset FLAG_DELIVERED_ROCKET_PLANS, Route7_EastEntrance_EventScript_RoadsClosed
	release
	end

Route7_EastEntrance_EventScript_Jenny::
	msgbox Route7_EastEntrance_Text_TipAboutTeamRocket, MSGBOX_NPC
	checkitem ITEM_ROCKET_PLANS
	goto_if_eq VAR_RESULT, TRUE, Route7_EastEntrance_EventScript_DeliverRocketPlans
	release
	end

Route7_EastEntrance_Text_TipAboutTeamRocket::
	.string "Hem rebut una pista que el Team\n"
	.string "Rocket podria passar per aquí, així\l"
	.string "que no podem deixar passar ningú.$"

Route7_EastEntrance_EventScript_DeliverRocketPlans::
	removeitem ITEM_ROCKET_PLANS
	setflag FLAG_DELIVERED_ROCKET_PLANS
	playse SE_PIN
	applymovement LOCALID_JENNY, Common_Movement_ExclamationMark
	waitmovement 1
	msgbox Route7_EastEntrance_Text_DeliverRocketPlans, MSGBOX_NPC
	waitmessage
	closemessage
	applymovement LOCALID_JENNY, Route7_EastEntrance_Movement_JennyExit
	waitmovement 1
	playse SE_EXIT
	removeobject LOCALID_JENNY
	release
	end

Route7_EastEntrance_Text_DeliverRocketPlans::
	.string "Què? Has trobat plans del\n"
	.string "Equip Rocket?\p"
	.string "Més val que no sigui una broma.\p"
	.string "Els hauré de veure...\n"
	.string "... ... ...\p"
	.string "Semblen autèntics!\p"
	.string "He de portar-los a l'Inspector\n"
	.string "immediatament!$"

Route7_EastEntrance_Movement_JennyExit:
	face_right
	walk_in_place_faster_right
	delay_8
	step_end


.set LOCALID_JENNY, 1

Route5_SouthEntrance_MapScripts::
	.byte 0

@TODO: The Gate Guards are not the road block anymore, but giving them tea will be a new daily event. Reward is TBD.

Route5_SouthEntrance_EventScript_Guard::
	goto_if_unset FLAG_DAILY_GUARD_TEA, Route5_SouthEntrance_EventScript_GuardThirsty
	goto_if_unset FLAG_DELIVERED_ROCKET_PLANS, Route5_SouthEntrance_EventScript_RoadsClosed
	msgbox Route5_SouthEntrance_Text_HiHowsItGoing, MSGBOX_NPC
	end

Route5_SouthEntrance_Text_HiHowsItGoing::
    .string "Ei, com va?$"

Route5_SouthEntrance_EventScript_RoadsClosed::
	msgbox Route5_SouthEntrance_Text_RoadsClosed, MSGBOX_NPC
	release
	end

Route5_SouthEntrance_Text_RoadsClosed::
    .string "Ah, per cert, el camí és tancat.\p"
    .string "La Policia Internacional està\n"
    .string "a la caça de l'Equip Rocket!$"

Route5_SouthEntrance_EventScript_GuardThirsty::
	msgbox Route5_SouthEntrance_Text_ThirstyOnGuardDuty, MSGBOX_NPC
	checkitem ITEM_TEA
	goto_if_eq VAR_RESULT, FALSE, Route5_SouthEntrance_EventScript_GuardSmallTalk
	msgbox Route5_SouthEntrance_Text_ThatTeaLooksTasty, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route5_SouthEntrance_EventScript_DenyGuard
	removeitem ITEM_TEA, 1
	setflag FLAG_DAILY_GUARD_TEA
	msgbox Route5_SouthEntrance_Text_ThanksIllShareTeaWithGuards, MSGBOX_NPC
	random 3
	goto_if_eq VAR_RESULT, 0, GateGuard_GiveNugget
	goto_if_eq VAR_RESULT, 1, GateGuard_GiveStone
	goto_if_eq VAR_RESULT, 2, GateGuard_ResetSnorlax1
	goto_if_eq VAR_RESULT, 3, GateGuard_ResetSnorlax2
	end

Route5_SouthEntrance_Text_ThirstyOnGuardDuty::
    .string "Estic de guàrdia.\n"
    .string "Uf, tinc molta set, però!$"

Route5_SouthEntrance_Text_ThatTeaLooksTasty::
    .string "Oh, aquest te…\n"
    .string "Sembla molt bo…$"

Route5_SouthEntrance_Text_ThanksIllShareTeaWithGuards::
    .string "Eh? Me'l puc quedar?\n"
    .string "Gràcies!\l"
    .string "… …\l"
    .string "Glup, glup…\l"
    .string "… …\l"
    .string "Gulp…\l"
    .string "… …\l"
    .string "Això refresca de debò!…\p"
    .string "Compartiré aquest te amb els\n"
    .string "altres guàrdies!$"

Route5_SouthEntrance_EventScript_DenyGuard::
	msgbox Route5_SouthEntrance_Text_ThatsAShame, MSGBOX_NPC
	release
	end

Route5_SouthEntrance_Text_ThatsAShame::
	.string "Oh, quina llàstima.\n"
	.string "Bé m'aniria una beguda...$"

Route5_SouthEntrance_EventScript_GuardSmallTalk::
	goto_if_unset FLAG_DELIVERED_ROCKET_PLANS, Route5_SouthEntrance_EventScript_RoadsClosed
	release
	end

Route5_SouthEntrance_EventScript_Jenny::
	msgbox Route5_SouthEntrance_Text_TipAboutTeamRocket, MSGBOX_NPC
	checkitem ITEM_ROCKET_PLANS
	goto_if_eq VAR_RESULT, TRUE, Route5_SouthEntrance_EventScript_DeliverRocketPlans
	release
	end

Route5_SouthEntrance_Text_TipAboutTeamRocket::
	.string "Hem rebut una pista que l'Equip\n"
	.string "Rocket podria passar per aquí,\l"
	.string "així que no podem deixar\l"
	.string "passar ningú ara mateix.$"

Route5_SouthEntrance_EventScript_DeliverRocketPlans::
	removeitem ITEM_ROCKET_PLANS
	setflag FLAG_DELIVERED_ROCKET_PLANS
	playse SE_PIN
	applymovement LOCALID_JENNY, Common_Movement_ExclamationMark
	waitmovement 1
	msgbox Route5_SouthEntrance_Text_DeliverRocketPlans, MSGBOX_NPC
	waitmessage
	closemessage
	applymovement LOCALID_JENNY, Route5_SouthEntrance_Movement_JennyExit
	waitmovement 1
	playse SE_EXIT
	removeobject LOCALID_JENNY
	release
	end

Route5_SouthEntrance_Text_DeliverRocketPlans::
	.string "Què? Has trobat plans de\n"
	.string "l'Equip Rocket?\p"
	.string "Més val que no sigui una broma.\p"
	.string "Hauré de veure-ho…\n"
	.string "... ... ...\p"
	.string "Semblen autèntics!\p"
	.string "He de portar-los a l'Inspector\n"
	.string "immediatament!$"

Route5_SouthEntrance_Movement_JennyExit:
	face_down
	walk_in_place_faster_down
	delay_8
	step_end


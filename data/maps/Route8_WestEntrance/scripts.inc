.set LOCALID_JENNY, 1

Route8_WestEntrance_MapScripts::
	.byte 0

@TODO: The Gate Guards are not the road block anymore, but giving them tea will be a new daily event. Reward is TBD.

Route8_WestEntrance_EventScript_Guard::
	goto_if_unset FLAG_DAILY_GUARD_TEA, Route8_WestEntrance_EventScript_GuardThirsty
	goto_if_unset FLAG_DELIVERED_ROCKET_PLANS, Route8_WestEntrance_EventScript_RoadsClosed
	msgbox Route8_WestEntrance_Text_HiHowsItGoing, MSGBOX_NPC
	end

Route8_WestEntrance_Text_HiHowsItGoing::
    .string "Hola, com va?$"

Route8_WestEntrance_EventScript_RoadsClosed::
	msgbox Route8_WestEntrance_Text_RoadsClosed, MSGBOX_NPC
	release
	end

Route8_WestEntrance_Text_RoadsClosed::
    .string "Ah, per cert, el camí és tancat.\p"
    .string "La Policia Internacional està\n"
    .string "buscant el Team Rocket!$"

Route8_WestEntrance_EventScript_GuardThirsty::
	msgbox Route8_WestEntrance_Text_ThirstyOnGuardDuty, MSGBOX_NPC
	checkitem ITEM_TEA
	goto_if_eq VAR_RESULT, FALSE, Route8_WestEntrance_EventScript_GuardSmallTalk
	msgbox Route8_WestEntrance_Text_ThatTeaLooksTasty, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route8_WestEntrance_EventScript_DenyGuard
	removeitem ITEM_TEA, 1
	setflag FLAG_DAILY_GUARD_TEA
	msgbox Route8_WestEntrance_Text_ThanksIllShareTeaWithGuards, MSGBOX_NPC
	random 3
	goto_if_eq VAR_RESULT, 0, GateGuard_GiveNugget
	goto_if_eq VAR_RESULT, 1, GateGuard_GiveStone
	goto_if_eq VAR_RESULT, 2, GateGuard_ResetSnorlax1
	goto_if_eq VAR_RESULT, 3, GateGuard_ResetSnorlax2
	end

GateGuard_GiveNugget::
	msgbox GateGuard_Text_FoundThis, MSGBOX_NPC
	giveitem ITEM_NUGGET, 1
	release
	end

GateGuard_GiveStone::
	msgbox GateGuard_Text_FoundThis, MSGBOX_NPC
	giveitem ITEM_POWER_STONE, 1
	release
	end

GateGuard_Text_FoundThis::
	.string "Ei, ja que has compartit el teu\n"
	.string "te amb mi, per què no agafes\l"
	.string "això?\p"
	.string "Fa temps que és a Objectes\n"
	.string "Perduts. No crec que ningú\l"
	.string "el reclami!$"

GateGuard_ResetSnorlax1::
	goto_if_unset FLAG_HIDE_ROUTE12_SNORLAX, GateGuard_GiveNugget
	msgbox GateGuard_Text_SnorlaxLavender, MSGBOX_NPC
	clearflag FLAG_HIDE_ROUTE12_SNORLAX
	release
	end

GateGuard_Text_SnorlaxLavender:
	.string "Oh, ho has sentit?\p"
	.string "Han vist un Pokémon enorme\n"
	.string "dormint al camí prop de\l"
	.string "Lavender Town!\p"
	.string "M'agradaria fer migdiades\n"
	.string "així.$"

GateGuard_ResetSnorlax2::
	goto_if_unset FLAG_HIDE_ROUTE16_SNORLAX, GateGuard_GiveStone
	msgbox GateGuard_Text_SnorlaxCyclingRoad, MSGBOX_NPC
	clearflag FLAG_HIDE_ROUTE16_SNORLAX
	release
	end

GateGuard_Text_SnorlaxCyclingRoad::
	.string "Oh, ho has sentit?\p"
	.string "Han vist un Pokémon enorme\n"
	.string "dormint al camí prop de\l"
	.string "Celadon City!\p"
	.string "M'agradaria fer migdiades\n"
	.string "així.$"

Route8_WestEntrance_Text_ThirstyOnGuardDuty::
    .string "Estic de guàrdia.\n"
    .string "Ui, quina set que tinc!$"

Route8_WestEntrance_Text_ThatTeaLooksTasty::
    .string "Oh, aquell te…\n"
    .string "Té una pinta tan bona…$"

Route8_WestEntrance_Text_ThanksIllShareTeaWithGuards::
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

Route8_WestEntrance_EventScript_DenyGuard::
	msgbox Route8_WestEntrance_Text_ThatsAShame, MSGBOX_NPC
	release
	end

Route8_WestEntrance_Text_ThatsAShame::
	.string "Oh, quina llàstima.\n"
	.string "Bé m'aniria una beguda...$"

Route8_WestEntrance_EventScript_GuardSmallTalk::
	goto_if_unset FLAG_DELIVERED_ROCKET_PLANS, Route8_WestEntrance_EventScript_RoadsClosed
	release
	end

Route8_WestEntrance_EventScript_Jenny::
	msgbox Route8_WestEntrance_Text_TipAboutTeamRocket, MSGBOX_NPC
	checkitem ITEM_ROCKET_PLANS
	goto_if_eq VAR_RESULT, TRUE, Route8_WestEntrance_EventScript_DeliverRocketPlans
	release
	end

Route8_WestEntrance_Text_TipAboutTeamRocket::
	.string "Hem rebut una pista que el Team\n"
	.string "Rocket podria passar per aquí, així\l"
	.string "que no podem deixar passar ningú.$"

Route8_WestEntrance_EventScript_DeliverRocketPlans::
	removeitem ITEM_ROCKET_PLANS
	setflag FLAG_DELIVERED_ROCKET_PLANS
	playse SE_PIN
	applymovement LOCALID_JENNY, Common_Movement_ExclamationMark
	waitmovement 1
	msgbox Route8_WestEntrance_Text_DeliverRocketPlans, MSGBOX_NPC
	waitmessage
	closemessage
	applymovement LOCALID_JENNY, Route8_WestEntrance_Movement_JennyExit
	waitmovement 1
	playse SE_EXIT
	removeobject LOCALID_JENNY
	release
	end

Route8_WestEntrance_Text_DeliverRocketPlans::
	.string "Què? Has trobat plans del\n"
	.string "Team Rocket?\p"
	.string "Més val que no sigui una broma.\p"
	.string "Els hauré de veure...\n"
	.string "... ... ...\p"
	.string "Semblen autèntics!\p"
	.string "He de portar-los a l'Inspector\n"
	.string "immediatament!$"

Route8_WestEntrance_Movement_JennyExit:
	face_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	delay_8
	step_end


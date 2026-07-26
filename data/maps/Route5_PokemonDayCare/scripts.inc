.set LOCALID_DAYCARE_MAN, 1
.set LOCALID_VOLUNTEER, 2

Route5_PokemonDayCare_MapScripts::
	.byte 0

Route5_PokemonDayCare_EventScript_Clefairy::
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_NORMAL
	msgbox Route5_PokemonDayCare_Text_Clefairy, MSGBOX_NPC
	waitmoncry
	release
	end

Route5_PokemonDayCare_Text_Clefairy::
    .string "Clefairy: Fiififiii!$"

Route5_PokemonDayCare_EventScript_DaycareEmployee::
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route5_PokemonDayCare_EventScript_EggWaitingPartner
	msgbox Route5_PokemonDayCare_Text_Volunteers, MSGBOX_NPC
	turnobject LOCALID_VOLUNTEER, DIR_NORTH
	release
	end

Route5_PokemonDayCare_Text_Volunteers::
	.string "L'amo d'aquesta Guarderia ho\n"
	.string "feia tot sol, però ens deixa\l"
	.string "fer de voluntaris per passar\l"
	.string "temps amb els Pokémon!$"

Route5_PokemonDayCare_EventScript_EggWaitingPartner::
	msgbox Route5_PokemonDayCare_Text_PartnerWasLookingForYou, MSGBOX_DEFAULT
	turnobject LOCALID_VOLUNTEER, DIR_NORTH
	release
	end

Route5_PokemonDayCare_Text_PartnerWasLookingForYou:
	.string "Oh! La meva companya et buscava\n"
	.string "a fora!$"


Route5_PokemonDayCare_EventScript_EmployeesOnly::
	turnobject LOCALID_VOLUNTEER, DIR_EAST
	playse SE_PIN
	applymovement LOCALID_VOLUNTEER, Common_Movement_ExclamationMark
	msgbox Route5_PokemonDayCare_Text_EmployeesOnly, MSGBOX_NPC
	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepBack
	waitmovement 0
	turnobject LOCALID_VOLUNTEER, DIR_NORTH
	release
	end

Route5_PokemonDayCare_Text_EmployeesOnly::
	.string "Perdona!\p"
	.string "Només els empleats poden\n"
	.string "passar aquí darrere.$"

Movement_StepBack:
	walk_down
	step_end

Route5_PokemonDayCare_EventScript_DaycareMan::
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route5_PokemonDayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route5_PokemonDayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route5_PokemonDayCare_EventScript_TwoMonsInDaycare
	msgbox Route5_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route5_PokemonDayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route5_PokemonDayCare_EventScript_EggWaiting::
	msgbox Route5_PokemonDayCare_Text_SomeoneWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route5_PokemonDayCare_Text_SomeoneWasLookingForYou:
	.string "Oh! Ets tu!\p"
	.string "La voluntària de fora volia\n"
	.string "parlar amb tu!$"

Route5_PokemonDayCare_EventScript_OneMonInDaycare::
	msgbox Route5_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route5_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route5_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route5_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route5_PokemonDayCare_EventScript_ComeAgain
	end

Route5_PokemonDayCare_Text_GoodToSeeYou:
	.string "Ah, ets tu! M'alegro de veure't.\n"
	.string "Els teus Pokémon van bé!$"

Route5_PokemonDayCare_Text_TakeYourMonBack:
	.string "Vols recuperar algun dels\n"
	.string "teus Pokémon?$"

Route5_PokemonDayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route5_PokemonDayCare_EventScript_YourMonHasGrownXLevels
	return

Route5_PokemonDayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route5_PokemonDayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route5_PokemonDayCare_Text_YourMonHasGrownXLevels:
	.string "Fins ara, el teu {STR_VAR_1} ha\n"
	.string "pujat {STR_VAR_2} nivells.$"

Route5_PokemonDayCare_EventScript_DisplayLevelsGained2::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route5_PokemonDayCare_EventScript_YourOtherMonHasGrownXLevels
	return

Route5_PokemonDayCare_EventScript_YourOtherMonHasGrownXLevels::
	msgbox Route5_PokemonDayCare_Text_YourOtherMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route5_PokemonDayCare_Text_YourOtherMonHasGrownXLevels:
	.string "I el teu {STR_VAR_1} ha\n"
	.string "pujat {STR_VAR_2} nivells.$"

Route5_PokemonDayCare_Text_WeCanRaiseOneMore:
	.string "Sabies que podem cuidar dos\n"
	.string "dels teus Pokémon?\p"
	.string "Vols que en cuidem un més?$"

Route5_PokemonDayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route5_PokemonDayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route5_PokemonDayCare_EventScript_OnlyTwoAliveMons
	msgbox Route5_PokemonDayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route5_PokemonDayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route5_PokemonDayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route5_PokemonDayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
  	callnative UpdateFollowingPokemon
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route5_PokemonDayCare_EventScript_CanRaiseOneMore
	release
	end

Route5_PokemonDayCare_Text_WhichMonShouldWeRaise:
	.string "Quin Pokémon vols que et\n"
	.string "cuidem?$"

Route5_PokemonDayCare_Text_WellRaiseYourMon:
	.string "Genial! Cuidarem el teu\n"
	.string "{STR_VAR_1} una estona.\p"
	.string "No t'oblidis de tornar a buscar-lo!$"

Route5_PokemonDayCare_EventScript_OnlyOneMon::
	msgbox Route5_PokemonDayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route5_PokemonDayCare_Text_YouHaveJustOneMon:
	.string "Oh? Però si només tens un\n"
	.string "Pokémon.\p"
	.string "No et puc deixar sol!\n"
	.string "Torna un altre dia.$"

Route5_PokemonDayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route5_PokemonDayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route5_PokemonDayCare_Text_YoullBeLeftWithJustOne:
	.string "Si deixes aquest Pokémon amb\n"
	.string "mi, et quedaràs amb un de sol.\p"
	.string "Si vols un consell, hauries\n"
	.string "d'intentar capturar-ne més.$"

Route5_PokemonDayCare_EventScript_ComeAgain::
	msgbox Route5_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route5_PokemonDayCare_Text_ComeAgain:
	.string "Torna quan vulguis.$"

Route5_PokemonDayCare_EventScript_OnlyOneAliveMon::
	msgbox Route5_PokemonDayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route5_PokemonDayCare_Text_WhatWillYouBattleWith:
	.string "Oh! Si em deixes aquest Pokémon,\n"
	.string "amb què combatràs?\p"
	.string "Hauries de tornar un altre dia!$"

Route5_PokemonDayCare_EventScript_CanRaiseOneMore::
	msgbox Route5_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_EventScript_GiveMonToRaise
	goto Route5_PokemonDayCare_EventScript_ComeAgain
	end

Route5_PokemonDayCare_EventScript_TryRetrieveMon::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route5_PokemonDayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route5_PokemonDayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route5_PokemonDayCare_EventScript_ComeAgain
	goto Route5_PokemonDayCare_EventScript_CostPrompt
	end

Route5_PokemonDayCare_EventScript_NoRoom::
	msgbox Route5_PokemonDayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route5_PokemonDayCare_Text_YourTeamIsFull:
	.string "Oh! El teu equip Pokémon és ple.\n"
	.string "Vine quan tinguis espai.$"

Route5_PokemonDayCare_EventScript_CostPrompt::
	special GetDaycareCost
	msgbox Route5_PokemonDayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_EventScript_CheckEnoughMoney
	goto Route5_PokemonDayCare_EventScript_ComeAgain
	end

Route5_PokemonDayCare_Text_ItWillCostX:
	.string "Hem cuidat bé {STR_VAR_1},\n"
	.string "així que costarà ¥{STR_VAR_2}.$"

Route5_PokemonDayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route5_PokemonDayCare_EventScript_RetrieveMon
	msgbox Route5_PokemonDayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route5_PokemonDayCare_EventScript_RetrieveMon::
	call_if_eq VAR_FACING, DIR_SOUTH, Route5_PokemonDayCare_EventScript_GoRetrieveMonAlt
	call_if_ne VAR_FACING, DIR_SOUTH, Route5_PokemonDayCare_EventScript_GoRetrieveMon
	waitmovement 0
	faceplayer
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route5_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route5_PokemonDayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route5_PokemonDayCare_EventScript_AskRetrieveOtherMon
	goto Route5_PokemonDayCare_EventScript_ComeAgain
	end

Route5_PokemonDayCare_EventScript_GoRetrieveMon::
	applymovement LOCALID_DAYCARE_MAN, Route5_PokemonDayCare_Movement_RetrieveDaycareMon
	return

Route5_PokemonDayCare_EventScript_GoRetrieveMonAlt::
	applymovement LOCALID_DAYCARE_MAN, Route5_PokemonDayCare_Movement_RetrieveDaycareMonAlt
	return

Route5_PokemonDayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_up
	walk_up
	walk_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_down
	walk_down
	walk_down
	step_end

Route5_PokemonDayCare_Movement_RetrieveDaycareMonAlt:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_left
	walk_up
	walk_up
	walk_right
	walk_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_down
	walk_left
	walk_down
	walk_down
	walk_right
	step_end

Route5_PokemonDayCare_Text_HeresYourMon:
	.string "Perfecte!\n"
	.string "Aquí tens el teu Pokémon.$"

Route5_PokemonDayCare_Text_TookBackMon:
	.string "{PLAYER} ha recuperat {STR_VAR_1}\n"
	.string "de la Guarderia.$"

Route5_PokemonDayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route5_PokemonDayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route5_PokemonDayCare_EventScript_ComeAgain
	end

Route5_PokemonDayCare_Text_TakeOtherOneBackToo:
	.string "Vols recuperar l'altre\n"
	.string "també?$"

Route5_PokemonDayCare_Text_NotEnoughMoney:
	.string "No tens prou diners…$"

Route5_PokemonDayCare_EventScript_TwoMonsInDaycare::
	msgbox Route5_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route5_PokemonDayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route5_PokemonDayCare_EventScript_DisplayLevelsGained2
	msgbox Route5_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_EventScript_TryRetrieveMon
	msgbox Route5_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route5_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon:
	.string "Sóc l'amo de la Guarderia.\p"
	.string "Podem cuidar Pokémon per tu.\p"
	.string "Vols que en cuidem algun?$"

Route5_PokemonDayCare_Text_FineThenComeAgain:
	.string "Que vagi bé!$"

EventScript_EggHatch::
	lockall
	msgbox Text_EggHatchHuh, MSGBOX_DEFAULT
	special EggHatch
	waitstate
	releaseall
	end

Text_EggHatchHuh:
	.string "Eh?$"


Route5_PokemonDayCare_EventScript_GetDailyBerry::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_STATUS_BERRY, Route5_PokemonDayCare_EventScript_PlantBerries
	msgbox Route5_PokemonDayCare_Text_PokemonLoveBerries, MSGBOX_DEFAULT
	random 6
	call_if_eq VAR_RESULT, 0, Route5_PokemonDayCare_EventScript_GiveCheriBerry
	call_if_eq VAR_RESULT, 1, Route5_PokemonDayCare_EventScript_GiveChestoBerry
	call_if_eq VAR_RESULT, 2, Route5_PokemonDayCare_EventScript_GivePechaBerry
	call_if_eq VAR_RESULT, 3, Route5_PokemonDayCare_EventScript_GiveRawstBerry
	call_if_eq VAR_RESULT, 4, Route5_PokemonDayCare_EventScript_GiveAspearBerry
	call_if_eq VAR_RESULT, 5, Route5_PokemonDayCare_EventScript_GivePersimBerry
	setflag FLAG_DAILY_STATUS_BERRY
	goto Route5_PokemonDayCare_EventScript_PlantBerries
	end

Route5_PokemonDayCare_Text_PokemonLoveBerries::
	.string "Als Pokémon els encanten les baies!\p"
	.string "He trobat això mentre explorava\n"
	.string "amb el meu Pokémon.$"

Route5_PokemonDayCare_EventScript_GiveCheriBerry::
	giveitem ITEM_CHERI_BERRY, 1
	return

Route5_PokemonDayCare_EventScript_GiveChestoBerry::
	giveitem ITEM_CHESTO_BERRY, 1
	return

Route5_PokemonDayCare_EventScript_GivePechaBerry::
	giveitem ITEM_PECHA_BERRY, 1
	return

Route5_PokemonDayCare_EventScript_GiveRawstBerry::
	giveitem ITEM_RAWST_BERRY, 1
	return

Route5_PokemonDayCare_EventScript_GiveAspearBerry::
	giveitem ITEM_ASPEAR_BERRY, 1
	return

Route5_PokemonDayCare_EventScript_GivePersimBerry::
	giveitem ITEM_PERSIM_BERRY, 1
	return

Route5_PokemonDayCare_EventScript_PlantBerries::
	msgbox Route5_PokemonDayCare_Text_SoftSoil MSGBOX_NPC
	release
	end

Route5_PokemonDayCare_Text_SoftSoil::
	.string "Si la plantes en terra tova,\n"
	.string "potser creixerà!$"

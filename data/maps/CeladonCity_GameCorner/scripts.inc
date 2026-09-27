.set LOCALID_ENGINEER, 1
.set LOCALID_ROCKET, 11

.set COINS_PRICE_50,  1000
.set COINS_PRICE_500, 10000

CeladonCity_GameCorner_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GameCorner_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, GameCorner_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, GameCorner_OnResume
	.byte 0

GameCorner_OnLoad::
	call_if_unset FLAG_OPENED_ROCKET_HIDEOUT, GameCorner_EventScript_HideRocketHideout
	end

GameCorner_EventScript_HideRocketHideout::
	setmetatile 15, 2, METATILE_GameCorner_Floor_ShadeFull, 0
	setmetatile 16, 2, METATILE_GameCorner_Floor_ShadeFull, 0
	setmetatile 17, 2, METATILE_GameCorner_Floor_ShadeFull, 0
	setmetatile 16, 3, METATILE_GameCorner_PurpleWall_Floor, 1
	setmetatile 17, 3, METATILE_GameCorner_PurpleWall_Floor, 1
	return

GameCorner_OnTransition::
	call_if_unset FLAG_DAILY_COIN_REFRESH, GameCorner_RefreshCoins
	call_if_unset FLAG_DAILY_GAME_CORNER_SERVICE_DAY_CHECKED, GameCorner_CheckServiceDay
	end

GameCorner_OnResume::
	call_if_unset FLAG_DAILY_COIN_REFRESH, GameCorner_RefreshCoins
	call_if_unset FLAG_DAILY_GAME_CORNER_SERVICE_DAY_CHECKED, GameCorner_CheckServiceDay
	end

GameCorner_CheckServiceDay::
	clearflag FLAG_GAME_CORNER_SERVICE_DAY
	setflag FLAG_DAILY_GAME_CORNER_SERVICE_DAY_CHECKED
	random 10
	goto_if_lt VAR_RESULT, 9, Common_EventScript_Return
	setflag FLAG_GAME_CORNER_SERVICE_DAY
	clearflag FLAG_HIDE_GAME_CORNER_ENGINEER
	addobject LOCALID_ENGINEER
	return

GameCorner_EventScript_Engineer::
	msgbox GameCorner_Text_ServiceDay, MSGBOX_NPC
	release
	end

GameCorner_Text_ServiceDay::
	.string "Avui estic revisant les màquines!$"


GameCorner_RefreshCoins::
	setflag FLAG_DAILY_COIN_REFRESH
	random 12
	switch VAR_RESULT
	case 0 GameCorner_RefreshCoins_1
	case 1 GameCorner_RefreshCoins_2
	case 2 GameCorner_RefreshCoins_3
	case 3 GameCorner_RefreshCoins_4
	case 4 GameCorner_RefreshCoins_5
	case 5 GameCorner_RefreshCoins_6
	case 6 GameCorner_RefreshCoins_7
	case 7 GameCorner_RefreshCoins_8
	case 8 GameCorner_RefreshCoins_9
	case 9 GameCorner_RefreshCoins_10
	case 10 GameCorner_RefreshCoins_11
	case 11 GameCorner_RefreshCoins_12
	end

GameCorner_RefreshCoins_1::
	clearflag FLAG_FOUND_10_COINS_1
	end

GameCorner_RefreshCoins_2::
	clearflag FLAG_FOUND_10_COINS_2
	end

GameCorner_RefreshCoins_3::
	clearflag FLAG_FOUND_10_COINS_3
	end

GameCorner_RefreshCoins_4::
	clearflag FLAG_FOUND_10_COINS_4
	end

GameCorner_RefreshCoins_5::
	clearflag FLAG_FOUND_10_COINS_5
	end

GameCorner_RefreshCoins_6::
	clearflag FLAG_FOUND_10_COINS_6
	end

GameCorner_RefreshCoins_7::
	clearflag FLAG_FOUND_10_COINS_7
	end

GameCorner_RefreshCoins_8::
	clearflag FLAG_FOUND_10_COINS_8
	end

GameCorner_RefreshCoins_9::
	clearflag FLAG_FOUND_20_COINS_1
	end

GameCorner_RefreshCoins_10::
	clearflag FLAG_FOUND_20_COINS_2
	end

GameCorner_RefreshCoins_11::
	clearflag FLAG_FOUND_40_COINS
	end

GameCorner_RefreshCoins_12::
	clearflag FLAG_FOUND_100_COINS
	end

GameCorner_EventScript_CoinsClerk::
	lock
	faceplayer
	msgbox GameCorner_Text_ThisIsGameCorner, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NeedCoinCase
	message GameCorner_Text_WereYouLookingForCoins
	waitmessage
	showmoneybox 0, 0
	showcoinsbox 1, 6
	goto GameCorner_EventScript_ChooseCoinsDefault50

GameCorner_Text_ThisIsGameCorner:
	.string "Benvingut a la Sala de Jocs.$"

GameCorner_Text_WereYouLookingForCoins:
	.string "Buscaves Monedes?\p"
	.string "Són ¥1000 per 50 Monedes.\n"
	.string "En vols?$"

GameCorner_EventScript_NeedCoinCase::
	msgbox GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
	release
	end

GameCorner_Text_NeedCoinCaseForCoins:
	.string "Volies Monedes per als\n"
	.string "jocs?\p"
	.string "Oh! No tens un Moneder per\n"
	.string "guardar les Monedes.$"

GameCorner_EventScript_ChooseCoinsDefault50::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
	switch VAR_RESULT
	case 0, GameCorner_EventScript_Buy50Coins
	case 1, GameCorner_EventScript_Buy500Coins
	goto GameCorner_EventScript_CancelBuyCoins
	end

GameCorner_EventScript_Buy50Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_50
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NotEnoughMoney
	addcoins 50
	removemoney COINS_PRICE_50
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

GameCorner_EventScript_Buy500Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_500
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NotEnoughMoney
	addcoins 500
	removemoney COINS_PRICE_500
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

GameCorner_EventScript_NoRoomForCoins::
	msgbox GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

GameCorner_Text_CoinCaseIsFull:
	.string "Oh?\n"
	.string "El teu Moneder és ple.$"

GameCorner_EventScript_NotEnoughMoney::
	msgbox GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

GameCorner_Text_DontHaveEnoughMoney:
	.string "Hmm… Sembla que no tens\n"
	.string "prou diners…$"

GameCorner_Text_ThankYouHereAreYourCoins:
	.string "Moltes gràcies!\n"
	.string "Aquí tens les teves Monedes!$"

GameCorner_EventScript_CancelBuyCoins::
	msgbox GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

GameCorner_Text_DontNeedCoinsThen:
	.string "Oh… No necessites Monedes?$"

GameCorner_EventScript_SlotMachine0::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine1::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine2::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine3::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine4::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine5::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine6::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine7::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 7
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine8::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 8
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine9::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 9
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine10::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 10
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine11::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 11
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine12::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 12
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine13::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 13
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine14::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 14
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine15::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 15
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine16::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 16
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine17::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 17
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_NoCoinCase::
	msgbox GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
	releaseall
	end

GameCorner_Text_CantPlayWithNoCoinCase:
	.string "No pots jugar si no tens\n"
	.string "un Moneder.$"

GameCorner_EventScript_InfoClerk::
	msgbox GameCorner_Text_CanExchangeCoinsNextDoor, MSGBOX_NPC
	end

GameCorner_Text_CanExchangeCoinsNextDoor::
    .string "Benvingut!\p"
    .string "Pots canviar les teves Monedes\n"
    .string "per premis fabulosos al costat.$"

GameCorner_EventScript_UnusableSlotMachine1::
	msgbox GameCorner_Text_OutOfOrder, MSGBOX_SIGN
	end

GameCorner_Text_OutOfOrder::
    .string "FORA DE SERVEI\n"
    .string "Està espatlada.$"

GameCorner_EventScript_UnusableSlotMachine2::
	msgbox GameCorner_Text_OutToLunch, MSGBOX_SIGN
	end

GameCorner_Text_OutToLunch::
    .string "Ha anat a dinar\n"
    .string "Està reservada.$"

GameCorner_EventScript_UnusableSlotMachine3::
	msgbox GameCorner_Text_SomeonesKeys, MSGBOX_SIGN
	end

GameCorner_Text_SomeonesKeys::
    .string "Les claus d'algú!\n"
    .string "Tornarà.$"

GameCorner_EventScript_UnusableSlotMachine4::
	goto_if_set FLAG_GAME_CORNER_SERVICE_DAY, GameCorner_EventScript_WorkedOn
	msgbox GameCorner_Text_Hacked, MSGBOX_SIGN
	end

GameCorner_Text_Hacked::
    .string "Els Pokémon d'aquesta estan tots\n"
    .string "barrejats. L'han piratejat!\p"
    .string "Millor busca'n una altra.$"

GameCorner_EventScript_WorkedOn::
	msgbox GameCorner_Text_Console, MSGBOX_SIGN
	end

GameCorner_Text_Console::
    .string "L'Enginyer té el terminal obert.\n"
    .string "Millor no tocar-la!$"

GameCorner_EventScript_FaceSlotMachine::
	closemessage
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

GameCorner_EventScript_BaldingMan::
	lock
	faceplayer
	msgbox GameCorner_Text_RumoredTeamRocketRunsThisPlace
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_RumoredTeamRocketRunsThisPlace::
    .string "No ho diguis a ningú.\p"
    .string "Es diu que aquest lloc el porta\n"
    .string "l'Equip Rocket.$"

GameCorner_EventScript_Woman1::
	lock
	faceplayer
	msgbox GameCorner_Text_ThinkMachinesHaveDifferentOdds
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_ThinkMachinesHaveDifferentOdds::
    .string "Crec que aquestes màquines tenen\n"
    .string "probabilitats diferents.$"

GameCorner_EventScript_Woman2::
	lock
	faceplayer
	msgbox GameCorner_Text_WinOrLoseItsOnlyLuck
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_WinOrLoseItsOnlyLuck::
    .string "Aquestes escurabutxaques…\n"
    .string "Guanyar o perdre, tot és sort.$"

GameCorner_EventScript_Maniac::
	msgbox GameCorner_Text_RareMonsForCoins
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_RareMonsForCoins::
    .string "Ofereixen Pokémon rars a canvi\n"
    .string "de les teves Monedes.\p"
    .string "Però no aconsegueixo guanyar!$"

GameCorner_EventScript_OldMan::
	lock
	faceplayer
	msgbox GameCorner_Text_SoEasyToGetHooked
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_SoEasyToGetHooked::
    .string "Els jocs fan por!\n"
    .string "És tan fàcil enganxar-s'hi!$"

GameCorner_EventScript_Fisher::
	lock
	faceplayer
	goto_if_set FLAG_GOT_10_COINS_FROM_GAMBLER, GameCorner_EventScript_FisherAlreadyGotCoins
	msgbox GameCorner_Text_DoYouWantToPlay
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_GamblerNoCoinCase
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, (MAX_COINS + 1) - 10
	goto_if_ge GameCorner_EventScript_GamblerNoRoomForCoins
	addcoins 10
	msgbox GameCorner_Text_Received10CoinsFromMan
	playse SE_SHOP
	waitse
	setflag FLAG_GOT_10_COINS_FROM_GAMBLER
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_DoYouWantToPlay::
    .string "Nano, vols jugar?$"

GameCorner_Text_Received10CoinsFromMan::
    .string "{PLAYER} ha rebut 10 MONEDES\n"
    .string "de l'home.$"

GameCorner_EventScript_FisherAlreadyGotCoins::
	msgbox GameCorner_Text_WinsComeAndGo
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_WinsComeAndGo::
    .string "Les victòries van i vénen.\n"
    .string "Res no és segur.$"

GameCorner_EventScript_Scientist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_20_COINS_FROM_GAMBLER, GameCorner_EventScript_ScientistAlreadyGotCoins
	msgbox GameCorner_Text_WantSomeCoins
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_GamblerNoCoinCase
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, (MAX_COINS + 1) - 20
	goto_if_ge GameCorner_EventScript_GamblerNoRoomForCoins
	addcoins 20
	msgbox GameCorner_Text_Received20CoinsFromNiceGuy
	playse SE_SHOP
	waitse
	setflag FLAG_GOT_20_COINS_FROM_GAMBLER
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_WantSomeCoins::
    .string "Què passa?\n"
    .string "Vols unes monedes?$"

GameCorner_Text_Received20CoinsFromNiceGuy::
    .string "{PLAYER} ha rebut 20 monedes\n"
    .string "del noi amable.$"

GameCorner_EventScript_ScientistAlreadyGotCoins::
	msgbox GameCorner_Text_NeedMoreCoinsForMonIWant
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_NeedMoreCoinsForMonIWant::
    .string "Caram! Necessito més monedes\n"
    .string "per al Peluix Pokémon que vull!$"

GameCorner_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_20_COINS_FROM_GAMBLER_2, GameCorner_EventScript_GentlemanAlreadyGotCoins
	msgbox GameCorner_Text_HereAreSomeCoinsShoo, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_GamblerNoCoinCase
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, (MAX_COINS + 1) - 20
	goto_if_ge GameCorner_EventScript_GamblerNoRoomForCoins
	addcoins 20
	msgbox GameCorner_Text_Received20CoinsFromMan
	playse SE_SHOP
	waitse
	setflag FLAG_GOT_20_COINS_FROM_GAMBLER_2
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_HereAreSomeCoinsShoo::
    .string "Ei, què? Em desconcentres!\n"
    .string "Aquí tens monedes, fora d'aquí!$"

GameCorner_Text_Received20CoinsFromMan::
    .string "{PLAYER} ha rebut 20 monedes\n"
    .string "de l'home.$"

GameCorner_EventScript_GentlemanAlreadyGotCoins::
	msgbox GameCorner_Text_WatchReelsClosely
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_WatchReelsClosely::
    .string "El truc és mirar els rodets\n"
    .string "de prop.$"

GameCorner_EventScript_GamblerNoRoomForCoins::
	msgbox GameCorner_Text_DontNeedMyCoins
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_DontNeedMyCoins::
    .string "Hmm, ja tens moltes monedes.$"

GameCorner_EventScript_GamblerNoCoinCase::
	msgbox GameCorner_Text_DontHaveCoinCase
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_DontHaveCoinCase::
    .string "Ei! Vés a buscar el Moneder\n"
    .string "per poder guardar-les!$"


GameCorner_EventScript_Poster::
	lockall
	goto_if_unset FLAG_OPENED_ROCKET_HIDEOUT, GameCorner_EventScript_PosterButton
	releaseall
	end

GameCorner_EventScript_PosterButton::
	msgbox GameCorner_Text_SwitchBehindPosterPushIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GameCorner_EventScript_OpenRocketHideout
	msgbox GameCorner_Text_LeaveItAlone
	release
	end

GameCorner_Text_SwitchBehindPosterPushIt::
    .string "Ei!\p"
    .string "Un interruptor darrere el pòster!?\n"
    .string "Premem-lo!$"

GameCorner_Text_LeaveItAlone::
    .string "Pensant-ho bé, millor deixar-ho\p"
    .string "estar...$"

GameCorner_EventScript_OpenRocketHideout::
	playse SE_UNLOCK
	setmetatile 15, 2, METATILE_GameCorner_Floor_StairsTop, 0
	setmetatile 16, 2, METATILE_GameCorner_StairsTop, 1
	setmetatile 17, 2, METATILE_GameCorner_StairsBottom, 1
	setmetatile 16, 3, METATILE_GameCorner_PurpleWall_StairsTop, 1
	setmetatile 17, 3, METATILE_GameCorner_PurpleWall_stairsBottom, 1
	special DrawWholeMapView
	setflag FLAG_OPENED_ROCKET_HIDEOUT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_EAST
	goto GameCorner_EventScript_RocketAppears
	end

GameCorner_EventScript_RocketAppears::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	clearflag FLAG_HIDE_GAME_CORNER_ROCKET
	addobject LOCALID_ROCKET
	playse SE_DOOR
	waitse
	playse SE_PIN
	applymovement LOCALID_ROCKET, Common_Movement_ExclamationMark
	waitmovement 11
	waitse
	applymovement LOCALID_ROCKET, Movement_GCRocketAppears
	waitmovement 11
	goto GameCorner_EventScript_RocketBattle

Movement_GCRocketAppears:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GameCorner_EventScript_RocketBattle::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_7, GameCorner_Text_GruntIntro, GameCorner_Text_GruntDefeat, GameCorner_EventScript_DefeatedGrunt
	end

GameCorner_Text_GruntIntro::
    .string "Ei! Què fas!?\n"
    .string "No havies de prémer això!\p"
    .string "Vés-te'n, o ja veuràs!$"

GameCorner_Text_GruntDefeat::
    .string "Caram!$"

GameCorner_EventScript_DefeatedGrunt::
	msgbox GameCorner_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	applymovement LOCALID_ROCKET, Movement_GCGruntExit
	waitmovement 11
	playse SE_EXIT
	removeobject LOCALID_ROCKET
	release
	end

GameCorner_Text_GruntPostBattle::
    .string "Podrien descobrir l'Amagatall\n"
    .string "de l'Equip Rocket!\p"
    .string "Millor aviso el Cap!$"

Movement_GCGruntExit::
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

HiddenCoins_1::
	goto_if_set FLAG_FOUND_10_COINS_1, Common_EventScript_End
	call HiddenCoins_Get10Coins
	setflag FLAG_FOUND_10_COINS_1
	waitfanfare
	release
	end

HiddenCoins_2::
	goto_if_set FLAG_FOUND_10_COINS_2, Common_EventScript_End
	call HiddenCoins_Get10Coins
	setflag FLAG_FOUND_10_COINS_2
	waitfanfare
	release
	end

HiddenCoins_3::
	goto_if_set FLAG_FOUND_20_COINS_1, Common_EventScript_End
	call HiddenCoins_Get20Coins
	setflag FLAG_FOUND_20_COINS_1
	waitfanfare
	release
	end

HiddenCoins_4::
	goto_if_set FLAG_FOUND_10_COINS_3, Common_EventScript_End
	call HiddenCoins_Get10Coins
	setflag FLAG_FOUND_10_COINS_3
	waitfanfare
	release
	end

HiddenCoins_5::
	goto_if_set FLAG_FOUND_10_COINS_4, Common_EventScript_End
	call HiddenCoins_Get10Coins
	setflag FLAG_FOUND_10_COINS_4
	waitfanfare
	release
	end

HiddenCoins_6::
	goto_if_set FLAG_FOUND_20_COINS_2, Common_EventScript_End
	call HiddenCoins_Get20Coins
	setflag FLAG_FOUND_20_COINS_2
	waitfanfare
	release
	end

HiddenCoins_7::
	goto_if_set FLAG_FOUND_10_COINS_5, Common_EventScript_End
	call HiddenCoins_Get10Coins
	setflag FLAG_FOUND_10_COINS_5
	waitfanfare
	release
	end

HiddenCoins_8::
	goto_if_set FLAG_FOUND_10_COINS_6, Common_EventScript_End
	call HiddenCoins_Get10Coins
	setflag FLAG_FOUND_10_COINS_6
	waitfanfare
	release
	end

HiddenCoins_9::
	goto_if_set FLAG_FOUND_10_COINS_7, Common_EventScript_End
	call HiddenCoins_Get10Coins
	setflag FLAG_FOUND_10_COINS_7
	waitfanfare
	release
	end

HiddenCoins_10::
	goto_if_set FLAG_FOUND_40_COINS, Common_EventScript_End
	call HiddenCoins_Get40Coins
	setflag FLAG_FOUND_40_COINS
	waitfanfare
	release
	end

HiddenCoins_11::
	goto_if_set FLAG_FOUND_10_COINS_7, Common_EventScript_End
	call HiddenCoins_Get10Coins
	setflag FLAG_FOUND_10_COINS_7
	waitfanfare
	release
	end

HiddenCoins_12::
	goto_if_set FLAG_FOUND_100_COINS, Common_EventScript_End
	call HiddenCoins_Get100Coins
	setflag FLAG_FOUND_100_COINS
	waitfanfare
	release
	end

HiddenCoins_Get10Coins::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, HiddenCoins_NoCase
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 10), HiddenCoins_NoSpace
	playfanfare MUS_OBTAIN_ITEM
	msgbox HiddenCoins_Found10Coins, MSGBOX_AUTOCLOSE
	addcoins 10
	return

HiddenCoins_Get20Coins::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, HiddenCoins_NoCase
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 20), HiddenCoins_NoSpace
	playfanfare MUS_OBTAIN_ITEM
	msgbox HiddenCoins_Found20Coins, MSGBOX_AUTOCLOSE
	addcoins 20
	return

HiddenCoins_Get40Coins::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, HiddenCoins_NoCase
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 40), HiddenCoins_NoSpace
	playfanfare MUS_OBTAIN_ITEM
	msgbox HiddenCoins_Found40Coins, MSGBOX_AUTOCLOSE
	addcoins 40
	return

HiddenCoins_Get100Coins::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, HiddenCoins_NoCase
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 100), HiddenCoins_NoSpace
	playfanfare MUS_OBTAIN_ITEM
	msgbox HiddenCoins_Found100Coins, MSGBOX_AUTOCLOSE
	addcoins 100
	return

HiddenCoins_NoSpace::
	msgbox HiddenCoins_FoundCoinsNoSpace, MSGBOX_AUTOCLOSE
	release
	end

HiddenCoins_FoundCoinsNoSpace::
	.string "{PLAYER} ha trobat monedes\n"
	.string "escampades pel terra...\p"
	.string "Llàstima que el Moneder és ple!$"

HiddenCoins_NoCase::
	msgbox HiddenCoins_FoundCoinsNoCase, MSGBOX_AUTOCLOSE
	release
	end

HiddenCoins_FoundCoinsNoCase::
	.string "{PLAYER} ha trobat monedes\n"
	.string "escampades pel terra...\p"
	.string "Llàstima que no tens Moneder!$"

HiddenCoins_Found10Coins::
	.string "{PLAYER} ha trobat 10 monedes\n"
	.string "escampades pel terra!$"

HiddenCoins_Found20Coins::
	.string "{PLAYER} ha trobat 20 monedes\n"
	.string "escampades pel terra!$"

HiddenCoins_Found40Coins::
	.string "{PLAYER} ha trobat 40 monedes\n"
	.string "escampades pel terra!$"

HiddenCoins_Found100Coins::
	.string "{PLAYER} ha trobat 100 monedes\n"
	.string "escampades pel terra!$"

GameCorner_EventScript_Scott::
	lock
	faceplayer
	msgbox GameCorner_Text_GymGuide
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_GymGuide::
	.string "Ei! Tens coses millors a fer,\n"
	.string "futur campió!\p"
	.string "La Líder del Gimnàs Celadon és\n"
	.string "l'Erika! Fa servir Pokémon\l"
	.string "de tipus Planta!\p"
	.string "Pot semblar dòcil, però no\n"
	.string "t'hi confïis!$"

SafariZone_SecretHouse_MapScripts::
	.byte 0

SafariZone_SecretHouse_EventScript_Attendant::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM03, SafariZone_SecretHouse_EventScript_CheckDailyPrize
	msgbox SafariZone_SecretHouse_Text_CongratsYouveWon
	checkitemspace ITEM_HM03, 1
	goto_if_eq VAR_RESULT, FALSE, SafariZone_SecretHouse_EventScript_NoRoomForHM03
	playfanfare MUS_OBTAIN_TMHM
	message SafariZone_SecretHouse_Text_ReceivedHM03FromAttendant
	waitfanfare
	waitmessage
	additem ITEM_HM03, 1
	msgbox SafariZone_SecretHouse_Text_ExplainSurf
	setflag FLAG_RECEIVED_HM03
	setflag FLAG_DAILY_SAFARI_GAME_PRIZE
	release
	end

SafariZone_SecretHouse_Text_CongratsYouveWon::
    .string "Ah! Per fi!\p"
    .string "Ets la primera persona a arribar\n"
    .string "a la Casa Secreta!\p"
    .string "Tot i que vaig fer una campanya\n"
    .string "per a la nostra gran inauguració,\p"
    .string "em preocupava que ningú no\n"
    .string "guanyés el premi de la campanya.\p"
    .string "Felicitats!\n"
    .string "Has guanyat!$"

SafariZone_SecretHouse_Text_ExplainSurf::
    .string "La MO03 és Surf.\p"
    .string "Els Pokémon podran transportar-te\n"
    .string "per l'aigua amb ella.\p"
    .string "Tens molta sort per guanyar\n"
    .string "aquest premi fabulós!$"

SafariZone_SecretHouse_Text_ReceivedHM03FromAttendant::
    .string "{PLAYER} ha rebut la MO03\n"
    .string "de l'encarregat!$"

SafariZone_SecretHouse_EventScript_NoRoomForHM03::
	msgbox SafariZone_SecretHouse_Text_DontHaveRoomForPrize
	release
	end

SafariZone_SecretHouse_Text_DontHaveRoomForPrize::
    .string "No tens espai per a aquest\n"
    .string "premi fabulós!$"

@TODO: replace this prize with a BOTTLE CAP
SafariZone_SecretHouse_EventScript_CheckDailyPrize::
	goto_if_set FLAG_DAILY_SAFARI_GAME_PRIZE, SafariZone_SecretHouse_EventScript_ExplainDailyPrize
	msgbox SafariZone_SecretHouse_Text_WinDailyPrize
	giveitem ITEM_RARE_CANDY
	setflag FLAG_DAILY_SAFARI_GAME_PRIZE
	release
	end

SafariZone_SecretHouse_Text_WinDailyPrize::
	.string "Felicitats!\n"
    .string "Has arribat a la Casa Secreta-\p"
    .string "Oh! Ei, ets el guanyador del\n"
    .string "Gran Premi. Ja sabies el camí\l"
    .string "fins aquí, oi?\p"
    .string "Bé, encara pots optar al premi\n"
    .string "normal, així que aquí tens!$"

SafariZone_SecretHouse_EventScript_ExplainDailyPrize::
	msgbox SafariZone_SecretHouse_Text_ExplainDailyPrize
	release
	end

SafariZone_SecretHouse_Text_ExplainDailyPrize::
	.string "Ja vas rebre el gran premi per\n"
	.string "ser la primera persona a arribar\l"
	.string "a la Casa Secreta, però encara\l"
	.string "pots rebre un premi normal si\l"
	.string "tornes a arribar aquí!\p"
	.string "Només donem premis normals un\n"
	.string "cop al dia, però!\p"
	.string "Torna demà!$"

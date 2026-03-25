CeruleanCity_BikeShop_MapScripts::
	.byte 0

CeruleanCity_BikeShop_EventScript_Bicycle::
	msgbox CeruleanCity_BikeShop_Text_ShinyNewBicycle, MSGBOX_SIGN
	end

CeruleanCity_BikeShop_Text_ShinyNewBicycle::
    .string "Una Bicicleta nova i brillant!$"

CeruleanCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, CeruleanCity_BikeShop_EventScript_AlreadyGotBicycle
	goto_if_set FLAG_GOT_BIKE_VOUCHER, CeruleanCity_BikeShop_EventScript_ExchangeBikeVoucher
	showmoneybox 0, 0
	message CeruleanCity_BikeShop_Text_WelcomeToBikeShop
	waitmessage
	multichoice 14, 0, MULTI_BIKE, FALSE
	switch VAR_RESULT
	case 0, CeruleanCity_BikeShop_EventScript_TryPurchaseBicycle
	case 1, CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	end

CeruleanCity_BikeShop_Text_WelcomeToBikeShop::
    .string "Hola!\n"
    .string "Benvingut a la Botiga de Bicis.\p"
    .string "Tenim la Bici perfecta per\n"
    .string "a tu!$"

@ The Bicycle price / players money is never actually checked
CeruleanCity_BikeShop_EventScript_TryPurchaseBicycle::
	msgbox CeruleanCity_BikeShop_Text_SorryYouCantAffordIt
	goto CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	end

CeruleanCity_BikeShop_Text_SorryYouCantAffordIt::
    .string "Ho sento!\n"
    .string "No te la pots permetre!$"

CeruleanCity_BikeShop_EventScript_ClerkGoodbye::
	msgbox CeruleanCity_BikeShop_Text_ThankYouComeAgain
	hidemoneybox
	release
	end

CeruleanCity_BikeShop_Text_ThankYouComeAgain::
    .string "Gràcies!\n"
    .string "Torna quan vulguis!$"

CeruleanCity_BikeShop_EventScript_AlreadyGotBicycle::
	msgbox CeruleanCity_BikeShop_Text_HowDoYouLikeNewBicycle, MSGBOX_DEFAULT
	release
	end

CeruleanCity_BikeShop_Text_HowDoYouLikeNewBicycle::
    .string "Què tal la teva Bicicleta nova?\n"
    .string "T'agrada com es condueix?\p"
    .string "La pots portar pel Camí Ciclista\n"
    .string "i fins i tot per les coves!$"

CeruleanCity_BikeShop_EventScript_ExchangeBikeVoucher::
	checkitem ITEM_BIKE_VOUCHER, 1
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_BikeShop_EventScript_BringBikeVoucher
	msgbox CeruleanCity_BikeShop_Text_OhBikeVoucherHereYouGo, MSGBOX_DEFAULT
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message CeruleanCity_BikeShop_Text_ExchangedVoucherForBicycle
	waitmessage
	waitfanfare
	closemessage
	setflag FLAG_RECEIVED_BIKE
	additem ITEM_MACH_BIKE, 1
	removeitem ITEM_BIKE_VOUCHER
	msgbox CeruleanCity_BikeShop_Text_ThankYouComeAgain, MSGBOX_DEFAULT
	release
	end

CeruleanCity_BikeShop_Text_OhBikeVoucherHereYouGo::
    .string "Oh, això és…\p"
    .string "Un Val de Bici!\p"
    .string "D'acord!\n"
    .string "Aquí tens!$"

CeruleanCity_BikeShop_Text_ExchangedVoucherForBicycle::
    .string "{PLAYER} ha canviat el\n"
    .string "Val de Bici per una Bicicleta.$"

CeruleanCity_BikeShop_EventScript_BringBikeVoucher::
	msgbox CeruleanCity_BikeShop_Text_MakeRoomForBicycle, MSGBOX_DEFAULT
	release
	end

CeruleanCity_BikeShop_Text_MakeRoomForBicycle::
    .string "Què dius, nen?\p"
    .string "No pots dir-me que tens un Val\n"
    .string "de Bici, me l'has de portar!$"

CeruleanCity_BikeShop_EventScript_Woman::
	msgbox CeruleanCity_BikeShop_Text_CityBikeGoodEnoughForMe, MSGBOX_NPC
	end

CeruleanCity_BikeShop_Text_CityBikeGoodEnoughForMe::
    .string "Una bici de passeig és suficient\n"
    .string "per a mi.\p"
    .string "No necessito fer trucs.\p"
    .string "Al cap i a la fi, no pots fer\n"
    .string "un cavalló amb un cistell!$"

CeruleanCity_BikeShop_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, CeruleanCity_BikeShop_EventScript_YoungsterHaveBike
	msgbox CeruleanCity_BikeShop_Text_BikesCoolButExpensive
	release
	end

CeruleanCity_BikeShop_Text_BikesCoolButExpensive::
    .string "Aquestes bicis molen, però són\n"
    .string "molt cares!$"

CeruleanCity_BikeShop_EventScript_YoungsterHaveBike::
	msgbox CeruleanCity_BikeShop_Text_WowYourBikeIsCool
	release
	end

CeruleanCity_BikeShop_Text_WowYourBikeIsCool::
    .string "Uau.\n"
    .string "La teva BICI és genial!$"



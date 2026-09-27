BattleFrontier_ExchangeServiceCorner_MapScripts::
	.byte 0

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_MINT_LADY, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_MINT_LADY_2, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_ABILITY_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseAbilityItem
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK_2, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_POWER_ITEM_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChoosePowerItem
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_CANDY_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize::
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_BagFull
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	additem VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_MINT_LADY, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_MINT_LADY_2, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_ABILITY_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseAbilityItem
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK_2, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_POWER_ITEM_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChoosePowerItem
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_CANDY_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BagFull::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_AbilityClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_ABILITY_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseAbilityItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseAbilityItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_ABILITY_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_AbilityCapsule
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_AbilityPatch
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_AbilityCapsule::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmAbilityCapsule, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseAbilityItem
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_ABILITY_CAPSULE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmAbilityCapsule:
	.string "Has triat la Càpsula Habilitat.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_AbilityPatch::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmAbilityPatch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseAbilityItem
	setvar VAR_0x8008, 200
	setvar VAR_0x8009, ITEM_ABILITY_PATCH
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmAbilityPatch:
	.string "Has triat el Pedaç Habilitat.\n"
	.string "És correcte?$"


BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Protein
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_Calcium
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_Iron
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_Zinc
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Carbos
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_HPUp
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Protein::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmProtein, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_PROTEIN
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Calcium::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalcium, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CALCIUM
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Iron::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmIron, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_IRON
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Zinc::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmZinc, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_ZINC
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Carbos::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarbos, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CARBOS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HPUp::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPUp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_HP_UP
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LEFTOVERS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_WHITE_HERB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_QUICK_CLAW
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_MENTAL_HERB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_BRIGHT_POWDER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_CHOICE_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_KINGS_ROCK
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_FOCUS_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_SCOPE_LENS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Sailor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Girl::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Hola, aquesta és la Cantonada\n"
	.string "d'Intercanvi.\p"
	.string "Intercanviem els Punts de Combat\n"
	.string "que has acumulat per premis.\p"
	.string "Tria un premi de la llista.$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmProtein:
	.string "Has triat la Proteïna.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalcium:
	.string "Has triat el Calci.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmIron:
	.string "Has triat el Ferro.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmZinc:
	.string "Has triat el Zinc.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarbos:
	.string "Has triat el Carbos.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPUp:
	.string "Has triat el Més PS.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder:
	.string "Has triat la Pols Brillant.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb:
	.string "Has triat l'Herba Blanca.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw:
	.string "Has triat la Grapa Ràpida.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb:
	.string "Has triat l'Herba Mental.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand:
	.string "Has triat la Cinta Elecció.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock:
	.string "Has triat la Roca del Rei.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand:
	.string "Has triat la Cinta Focus.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens:
	.string "Has triat la Lent Mira.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers:
	.string "Has triat les Restes.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC:
	.string "Gràcies!\n"
	.string "T'ho enviarem al PC de casa.$"

BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize:
	.string "Aquí tens el teu premi!$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "Ho sento molt…\n"
	.string "No tens prou Punts de Combat…$"

BattleFrontier_ExchangeServiceCorner_Text_PCIsFull:
	.string "Ho sento molt…\n"
	.string "Sembla que el teu PC és ple…$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
	.string "Ho sento molt…\n"
	.string "No tens espai per guardar-ho…$"

BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "Moltes gràcies.\p"
	.string "Torna a visitar-nos quan hagis\n"
	.string "acumulat Punts de Combat.$"

BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "Si aconsegueixo els objectes d'aquí,\n"
	.string "els meus Pokémon seran més forts.\p"
	.string "Segur que sí!\n"
	.string "No hi ha cap dubte!$"

BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "Ho sabies?\p"
	.string "Si superes el teu rècord a les\n"
	.string "instal·lacions de Combat, et donen\l"
	.string "cada cop més Punts de Combat.$"

BattleFrontier_ExchangeServiceCorner_Text_ProteinDesc::
	.string "Puja l'Atac d'un\n"
	.string "Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_CalciumDesc::
	.string "Puja l'At. Esp. d'un\n"
	.string "Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_IronDesc::
	.string "Puja la Defensa d'un\n"
	.string "Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_ZincDesc::
	.string "Puja la Def. Esp. d'un\n"
	.string "Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_CarbosDesc::
	.string "Puja la Velocitat d'un\n"
	.string "Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_HPUpDesc::
	.string "Puja els PS d'un Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc::
	.string "Objecte equipable que restaura\n"
	.string "PS gradualment en combat.$"

BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc::
	.string "Objecte equipable que restaura\n"
	.string "estadístiques baixades.$"

BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc::
	.string "Objecte equipable que de vegades\n"
	.string "permet atacar primer.$"

BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc::
	.string "Objecte equipable que cura\n"
	.string "l'enamorament d'un Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc::
	.string "Objecte equipable que redueix\n"
	.string "la precisió del rival.$"

BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc::
	.string "Puja la potència d'un moviment,\n"
	.string "però només permet aquell.$"

BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc::
	.string "Objecte equipable que pot fer\n"
	.string "retrocedir el rival en ser colpejat.$"

BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc::
	.string "Objecte equipable que de vegades\n"
	.string "evita el debilitament.$"

BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc::
	.string "Objecte equipable que puja la\n"
	.string "probabilitat de cop crític.$"

BattleFrontier_ExchangeServiceCorner_Text_AbilityCapsuleDesc::
	.string "Canvia l'habilitat d'un Pokémon.$"
	.string "probabilitat de cop crític.$"

BattleFrontier_ExchangeServiceCorner_Text_AbilityPatchDesc::
	.string "Converteix l'habilitat d'un Pokémon\n"
	.string "en una habilitat rara.$"

BattleFrontier_ExchangeServiceCorner_EventScript_MintLady::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_MINT_LADY
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MintLady2::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_MINT_LADY_2
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_MINT_LADY
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_AdamantMint
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_BoldMint
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_BraveMint
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_CalmMint
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_CarefulMint
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_GentleMint
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_HastyMint
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_ImpishMint
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_JollyMint
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_LaxMint
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_LonelyMint
	case 11, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_LonelyMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLonelyMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_LONELY_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLonelyMint:
	.string "Has triat la Menta Solitària.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_LaxMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaxMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_LAX_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaxMint:
	.string "Has triat la Menta Mandrosa.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_JollyMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmJollyMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_JOLLY_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmJollyMint:
	.string "Has triat la Menta Alegre.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_ImpishMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmImpishMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_IMPISH_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmImpishMint:
	.string "Has triat la Menta Agosarada.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_HastyMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmHastyMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_HASTY_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmHastyMint:
	.string "Has triat la Menta Precipitada.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_AdamantMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmAdamantMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_ADAMANT_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmAdamantMint:
	.string "Has triat la Menta Ferma.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_BoldMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBoldMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_BOLD_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBoldMint:
	.string "Has triat la Menta Audaç.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_BraveMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBraveMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_BRAVE_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBraveMint:
	.string "Has triat la Menta Valenta.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_CalmMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalmMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_CALM_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalmMint:
	.string "Has triat la Menta Serena.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_CarefulMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarefulMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_CAREFUL_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarefulMint:
	.string "Has triat la Menta Cautelosa.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_GentleMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmGentleMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_GENTLE_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmGentleMint:
	.string "Has triat la Menta Amable.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_MINT_LADY_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_MildMint
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_ModestMint
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_NaiveMint
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_NaughtyMint
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_QuietMint
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_RashMint
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_RelaxedMint
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_SassyMint
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_SeriousMint
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_TimidMint
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TimidMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTimidMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_TIMID_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmTimidMint:
	.string "Has triat la Menta Tímida.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_SeriousMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSeriousMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_SERIOUS_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSeriousMint:
	.string "Has triat la Menta Seriosa.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_SassyMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSassyMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_SASSY_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSassyMint:
	.string "Has triat la Menta Descortesa.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_RelaxedMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmRelaxedMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_RELAXED_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmRelaxedMint:
	.string "Has triat la Menta Relaxada.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_RashMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmRashMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_RASH_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmRashMint:
	.string "Has triat la Menta Imprudent.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_QuietMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuietMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_QUIET_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuietMint:
	.string "Has triat la Menta Tranquil·la.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_NaughtyMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmNaughtyMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_NAUGHTY_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmNaughtyMint:
	.string "Has triat la Menta Murri.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_NaiveMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmNaiveMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_NAIVE_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmNaiveMint:
	.string "Has triat la Menta Ingènua.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_ModestMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmModestMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_MODEST_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmModestMint:
	.string "Has triat la Menta Modesta.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_MildMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMildMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_MILD_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMildMint:
	.string "Has triat la Menta Suau.\n"
	.string "És correcte?$"



BattleFrontier_ExchangeServiceCorner_Text_AdamantMintDesc::
 	.string "Encanta als Pokémon!\n"
    .string "Té un sabor Ferm.$"

BattleFrontier_ExchangeServiceCorner_Text_BoldMintDesc::
	.string "Encanta als Pokémon!\n"
    .string "Té un sabor Audaç.$"

BattleFrontier_ExchangeServiceCorner_Text_BraveMintDesc::
	.string "Encanta als Pokémon!\n"
    .string "Té un sabor Valent.$"

BattleFrontier_ExchangeServiceCorner_Text_CalmMintDesc::
	.string "Encanta als Pokémon!\n"
    .string "Té un sabor Serè.$"

BattleFrontier_ExchangeServiceCorner_Text_CarefulMintDesc::
	.string "Encanta als Pokémon!\n"
    .string "Té un sabor Cautelós.$"

BattleFrontier_ExchangeServiceCorner_Text_GentleMintDesc::
	.string "Encanta als Pokémon!\n"
    .string "Té un sabor Amable.$"

BattleFrontier_ExchangeServiceCorner_Text_HastyMintDesc::
	.string "Encanta als Pokémon!\n"
    .string "Té un sabor Precipitat.$"

BattleFrontier_ExchangeServiceCorner_Text_ImpishMintDesc::
	.string "Encanta als Pokémon!\n"
    .string  "Té un sabor Agosarat.$"

BattleFrontier_ExchangeServiceCorner_Text_JollyMintDesc::
	.string "Encanta als Pokémon!\n"
    .string "Té un sabor Alegre.$"

BattleFrontier_ExchangeServiceCorner_Text_LaxMintDesc::
	.string "Encanta als Pokémon!\n"
    .string "Té un sabor Mandrós.$"

BattleFrontier_ExchangeServiceCorner_Text_LonelyMintDesc::
	.string "Encanta als Pokémon!\n"
    .string "Té un sabor Solitari.$"

BattleFrontier_ExchangeServiceCorner_Text_MildMintDesc::
	.string "Encanta als Pokémon!\n"
    .string "Té un sabor Suau.$"

BattleFrontier_ExchangeServiceCorner_Text_ModestMintDesc::
    .string "Encanta als Pokémon!\n"
    .string "Té un sabor Modest.$"

BattleFrontier_ExchangeServiceCorner_Text_NaiveMintDesc::
	.string "Encanta als Pokémon!\n"
    .string "Té un sabor Ingenu.$"

BattleFrontier_ExchangeServiceCorner_Text_NaughtyMintDesc::
	.string "Encanta als Pokémon!\n"
    .string "Té un sabor Murri.$"

BattleFrontier_ExchangeServiceCorner_Text_QuietMintDesc::
	.string "Encanta als Pokémon!\n"
    .string "Té un sabor Tranquil.$"

BattleFrontier_ExchangeServiceCorner_Text_RashMintDesc::
	.string "Encanta als Pokémon!\n"
    .string "Té un sabor Imprudent.$"

BattleFrontier_ExchangeServiceCorner_Text_RelaxedMintDesc::
	.string "Encanta als Pokémon!\n"
    .string "Té un sabor Relaxat.$"

BattleFrontier_ExchangeServiceCorner_Text_SassyMintDesc::
	.string "Encanta als Pokémon!\n"
    .string "Té un sabor Descortès.$"

BattleFrontier_ExchangeServiceCorner_Text_SeriousMintDesc::
	.string "Encanta als Pokémon!\n"
    .string "Té un sabor Seriós.$"

BattleFrontier_ExchangeServiceCorner_Text_TimidMintDesc::
	.string "Encanta als Pokémon!\n"
    .string "Té un sabor Tímid.$"

BattleFrontier_ExchangeServiceCorner_Text_RazorFang::
    .string "Objecte equipable que pot fer\n"
    .string "retrocedir el rival en ser colpejat.$"

BattleFrontier_ExchangeServiceCorner_Text_RazorClaw::
    .string "Urpa grapada que puja la\n"
    .string "probabilitat de cop crític.$"

BattleFrontier_ExchangeServiceCorner_Text_ChoiceSpecs::
    .string "Puja l'At. Esp., però només\n"
    .string "permet un moviment.$"

BattleFrontier_ExchangeServiceCorner_Text_ChoiceScarf::
    .string "Puja la Velocitat, però només\n"
    .string "permet un moviment.$"

BattleFrontier_ExchangeServiceCorner_Text_MuscleBand::
    .string "Cinta que puja la potència\n"
    .string "dels moviments físics.$"

BattleFrontier_ExchangeServiceCorner_Text_LifeOrb::
    .string "Puja la potència dels moviments\n"
    .string "a canvi d'alguns PS per torn.$"

BattleFrontier_ExchangeServiceCorner_Text_PowerHerb::
    .string "Permet l'ús immediat d'un\n"
    .string "moviment que requereix càrrega.$"

BattleFrontier_ExchangeServiceCorner_Text_WiseGlasses::
    .string "Ulleres que pugen la potència\n"
    .string "dels moviments especials.$"

BattleFrontier_ExchangeServiceCorner_Text_RedCard::
    .string "Fa canviar el rival si\n"
    .string "colpeja el portador.$"


BattleFrontier_ExchangeServiceCorner_Text_PowerAnklet::
    .string "Objecte equipable que potencia\n"
    .string "guany Vel., però baixa Velocitat.$"

BattleFrontier_ExchangeServiceCorner_Text_PowerBracer::
    .string "Objecte equipable que potencia\n"
    .string "guany Atc., però baixa Velocitat.$"

BattleFrontier_ExchangeServiceCorner_Text_PowerBelt::
    .string "Objecte equipable que potencia\n"
    .string "guany Def., però baixa Velocitat.$"

BattleFrontier_ExchangeServiceCorner_Text_PowerBand::
    .string "Objecte equipable que potencia\n"
    .string "guany Def.Esp., baixa Velocitat.$"

BattleFrontier_ExchangeServiceCorner_Text_PowerWeight::
    .string "Objecte equipable que potencia\n"
    .string "guany PS, però baixa Velocitat.$"

BattleFrontier_ExchangeServiceCorner_Text_PowerLens::
    .string "Objecte equipable que potencia\n"
    .string "guany At.Esp., baixa Velocitat.$"

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk2::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK_2
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_RazorFang
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_RazorClaw
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceSpecs
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceScarf
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_MuscleBand
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_LifeOrb
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_PowerHerb
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_WiseGlasses
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_RedCard
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_RazorFang::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmRazorFang, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_RAZOR_FANG
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmRazorFang:
	.string "Has triat l'Ullal Esmolat.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_RazorClaw::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmRazorClaw, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_RAZOR_CLAW
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmRazorClaw:
	.string "Has triat la Grapa Esmolada.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceSpecs::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceSpecs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_CHOICE_SPECS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceSpecs:
	.string "Has triat les Ulleres Elecció.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceScarf::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceScarf, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_CHOICE_SCARF
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceScarf:
	.string "Has triat la Bufanda Elecció.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_MuscleBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMuscleBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_MUSCLE_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMuscleBand:
	.string "Has triat la Cinta Musculosa.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_LifeOrb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLifeOrb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LIFE_ORB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLifeOrb:
	.string "Has triat l'Esfera Vital.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_PowerHerb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, ITEM_POWER_HERB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerHerb:
	.string "Has triat l'Herba Potent.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_WiseGlasses::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmWiseGlasses, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_WISE_GLASSES
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmWiseGlasses:
	.string "Has triat les Ulleres Sàvies.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_RedCard::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmRedCard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, ITEM_RED_CARD
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmRedCard:
	.string "Has triat la Targeta Vermella.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_PowerItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_POWER_ITEM_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChoosePowerItem
	end


BattleFrontier_ExchangeServiceCorner_EventScript_ChoosePowerItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_POWER_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_PowerAnklet
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_PowerBracer
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_PowerBelt
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_PowerBand
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_PowerWeight
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_PowerLens
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PowerAnklet::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerAnklet, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChoosePowerItem
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, ITEM_POWER_ANKLET
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerAnklet:
	.string "Has triat el Turmell Potent.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_PowerBracer::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerBracer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChoosePowerItem
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, ITEM_POWER_BRACER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerBracer:
	.string "Has triat el Braçal Potent.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_PowerBelt::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerBelt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChoosePowerItem
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, ITEM_POWER_BELT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerBelt:
	.string "Has triat el Cinturó Potent.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_PowerBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChoosePowerItem
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, ITEM_POWER_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerBand:
	.string "Has triat la Banda Potent.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_PowerWeight::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerWeight, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChoosePowerItem
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, ITEM_POWER_WEIGHT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerWeight:
	.string "Has triat el Pes Potent.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_PowerLens::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerLens, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChoosePowerItem
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, ITEM_POWER_LENS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerLens:
	.string "Has triat la Lent Potent.\n"
	.string "És correcte?$"


BattleFrontier_ExchangeServiceCorner_EventScript_CandyClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_CANDY_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	end


BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_CANDY_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_HPCandy
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_ATKCandy
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_DEFCandy
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_SPATKCandy
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_SPDEFCandy
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_SPEEDCandy
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_MAXCandy
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_RESETCandy
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HPCandy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPCandy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_HP_CANDY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPCandy:
	.string "Has triat el Caramel PS.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_ATKCandy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmATKCandy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_ATK_CANDY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmATKCandy:
	.string "Has triat el Caramel Atac.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_DEFCandy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmDEFCandy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_DEF_CANDY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmDEFCandy:
	.string "Has triat el Caramel Defensa.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_SPATKCandy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSPATKCandy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_SPATK_CANDY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSPATKCandy:
	.string "Has triat el Caramel At.Esp.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_SPDEFCandy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSPDEFCandy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_SPDEF_CANDY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSPDEFCandy:
	.string "Has triat el Caramel Def.Esp.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_SPEEDCandy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSPEEDCandy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_SPEED_CANDY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSPEEDCandy:
	.string "Has triat el Caramel Velocitat.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_MAXCandy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMAXCandy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_MAX_CANDY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMAXCandy:
	.string "Has triat el Caramel Màxim.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_EventScript_RESETCandy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmRESETCandy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	setvar VAR_0x8008, 8
	setvar VAR_0x8009, ITEM_RESET_CANDY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmRESETCandy:
	.string "Has triat el Caramel Reinici.\n"
	.string "És correcte?$"

BattleFrontier_ExchangeServiceCorner_Text_HPCandy::
    .string "Puja els PS base d'un Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_ATKCandy::
    .string "Puja l'Atac base d'un Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_DEFCandy::
    .string "Puja la Defensa base d'un Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_SPATKCandy::
   .string  "Puja l'At. Esp. base d'un Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_SPDEFCandy::
    .string "Puja la Def. Esp. base d'un Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_SPEEDCandy::
   .string  "Puja la Velocitat base d'un Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_MAXCandy::
    .string "Maximitza les estad. base d'un Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_RESETCandy::
    .string "Neutralitza les estad. base d'un Pokémon.$"

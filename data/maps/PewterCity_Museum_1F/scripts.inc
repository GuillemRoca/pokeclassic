.set LOCALID_SCIENTIST1, 1
.set LOCALID_OLD_AMBER,  6

PewterCity_Museum_1F_MapScripts::
	.byte 0

PewterCity_Museum_1F_EventScript_EntranceTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterLeft
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_Movement_ApproachCounterLeft::
	walk_right
	walk_right
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_EventScript_EntranceTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterMid
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_Movement_ApproachCounterMid::
	walk_right
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_EventScript_EntranceTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterRight
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_Movement_ApproachCounterRight::
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_EventScript_EntranceTrigger::
	showmoneybox 0, 0
	msgbox PewterCity_Museum_1F_Text_Its50YForChildsTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Museum_1F_EventScript_TryPayForTicket
	msgbox PewterCity_Museum_1F_Text_ComeAgain, MSGBOX_DEFAULT
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ForcePlayerExit
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_Text_Its50YForChildsTicket::
    .string "Benvingut al nostre museu!\n"
    .string "Són ¥50 per a l'entrada infantil.\p"
    .string "Vols entrar?$"

PewterCity_Museum_1F_Text_ComeAgain::
    .string "Torna-hi un altre dia!$"

PewterCity_Museum_1F_Movement_ForcePlayerExit::
	walk_down
	step_end

PewterCity_Museum_1F_EventScript_TryPayForTicket::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Museum_1F_EventScript_NotEnoughMoney
	closemessage
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	waitse
	msgbox PewterCity_Museum_1F_Text_Right50YThankYou, MSGBOX_DEFAULT
	setvar VAR_PEWTER_CITY_MUSEUM_STATE, 1
	hidemoneybox
	releaseall
	end

PewterCity_Museum_1F_Text_Right50YThankYou::
    .string "Molt bé, ¥50!\n"
    .string "Gràcies!$"

PewterCity_Museum_1F_EventScript_NotEnoughMoney::
	msgbox PewterCity_Museum_1F_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ForcePlayerExit
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_Text_DontHaveEnoughMoney::
    .string "No tens prou diners.$"

PewterCity_Museum_1F_EventScript_Scientist1::
	lock
	faceplayer
	goto_if_ne VAR_FACING, DIR_EAST, PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
	msgbox PewterCity_Museum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_1F_Text_PleaseEnjoyYourself::
    .string "Gaudeix de la visita.$"

PewterCity_Museum_1F_EventScript_Scientist1BehindCounter::
	msgbox PewterCity_Museum_1F_Text_DoYouKnowWhatAmberIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Museum_1F_EventScript_AmberHasGeneticMatter
	msgbox PewterCity_Museum_1F_Text_AmberIsFossilizedSap, MSGBOX_DEFAULT
	turnobject LOCALID_SCIENTIST1, DIR_WEST
	waitmovement 1
	release
	end

PewterCity_Museum_1F_Text_DoYouKnowWhatAmberIs::
    .string "No pots colar-te per darrere!\n"
    .string "Bon intent, nen, però no.\p"
    .string "Bah, tant se val!\n"
    .string "Saps què és l'ambre?$"

PewterCity_Museum_1F_Text_AmberIsFossilizedSap::
    .string "L'ambre és en realitat saba,\n"
    .string "la cosa enganxosa dels arbres.\p"
    .string "La saba antiga es va fossilitzar\n"
    .string "amb el temps fins a ser ambre.$"

PewterCity_Museum_1F_EventScript_AmberHasGeneticMatter::
	msgbox PewterCity_Museum_1F_Text_AmberContainsGeneticMatter, MSGBOX_DEFAULT
	turnobject LOCALID_SCIENTIST1, DIR_WEST
	waitmovement 1
	release
	end

PewterCity_Museum_1F_Text_AmberContainsGeneticMatter::
    .string "L'ambre conté material genètic\n"
    .string "de Pokémon antics.\p"
    .string "Hi ha un laboratori que intenta\n"
    .string "ressuscitar Pokémon de l'ambre.$"

PewterCity_Museum_1F_EventScript_Scientist2::
	msgbox PewterCity_Museum_1F_Text_WeHaveTwoFossilsOnExhibit, MSGBOX_NPC
	end

PewterCity_Museum_1F_Text_WeHaveTwoFossilsOnExhibit::
    .string "Tenim dos fòssils de Pokémon\n"
    .string "prehistòrics rars en exhibició.$"

PewterCity_Museum_1F_EventScript_OldAmberScientist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_OLD_AMBER, PewterCity_Museum_1F_EventScript_AlreadyGotOldAmber
	msgbox PewterCity_Museum_1F_Text_WantYouToGetAmberExamined, MSGBOX_DEFAULT
	checkitemspace ITEM_OLD_AMBER, 1
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Museum_1F_EventScript_NoRoomForOldAmber
	setflag FLAG_GOT_OLD_AMBER
	removeobject LOCALID_OLD_AMBER
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox PewterCity_Museum_1F_Text_ReceivedOldAmber
	waitfanfare
	additem ITEM_OLD_AMBER, 1
	release
	end

PewterCity_Museum_1F_EventScript_AlreadyGotOldAmber::
	goto_if_set FLAG_GOT_AERODACTYL_REWARD, PewterCity_Museum_1F_EventScript_AlreadyGotReward
	goto_if_set FLAG_RESSURECTED_AERODACTYL, PewterCity_Museum_1F_EventScript_WowThatsAerodactyl
	msgbox PewterCity_Museum_1F_Text_GetOldAmberChecked, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_1F_Text_GetOldAmberChecked::
    .string "Xst!\n"
    .string "Fes examinar l'Ambre Antic!$"

PewterCity_Museum_1F_EventScript_WowThatsAerodactyl::
	msgbox PewterCity_Museum_1F_Text_WowThatsAerodactyl, MSGBOX_DEFAULT
	goto_if_eq VAR_FOSSIL_SELECTION, 1, PewterCity_Museum_1F_EventScript_GiveHelixFossil
	goto_if_eq VAR_FOSSIL_SELECTION, 2, PewterCity_Museum_1F_EventScript_GiveDomeFossil
	end

PewterCity_Museum_1F_EventScript_GiveHelixFossil::
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PewterCity_Museum_1F_Text_ObtainedHelixFossil
	waitfanfare
	waitmessage
	additem ITEM_HELIX_FOSSIL, 1
	goto PewterCity_Museum_1F_EventScript_GaveReward
	end

PewterCity_Museum_1F_Text_ObtainedHelixFossil::
    .string "Has obtingut el Fòssil Hèlix!$"

PewterCity_Museum_1F_EventScript_GiveDomeFossil::
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PewterCity_Museum_1F_Text_ObtainedDomeFossil
	waitfanfare
	waitmessage
	additem ITEM_DOME_FOSSIL, 1
	goto PewterCity_Museum_1F_EventScript_GaveReward
	end

PewterCity_Museum_1F_Text_ObtainedDomeFossil::
    .string "Has obtingut el Fòssil Domo!$"

PewterCity_Museum_1F_EventScript_GaveReward::
	setflag FLAG_GOT_AERODACTYL_REWARD
	release
	end

PewterCity_Museum_1F_Text_WowThatsAerodactyl::
    .string "Uau!\n"
    .string "Has ressuscitat el Pokémon?\p"
    .string "Sabia que contenia ADN!\p"
    .string "Gràcies per fer-m'ho saber.\n"
    .string "Pren això com a recompensa!$"

PewterCity_Museum_1F_EventScript_AlreadyGotReward::
	msgbox PewterCity_Museum_1F_Text_PowerOfScience, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_1F_Text_PowerOfScience::
    .string "És increïble el que podem fer\n"
    .string "amb el poder de la ciència!$"

PewterCity_Museum_1F_Text_WantYouToGetAmberExamined::
    .string "Xst! Escolta, necessito compartir\n"
    .string "un secret amb algú.\p"
    .string "Crec que aquest tros d'ambre\n"
    .string "conté ADN de Pokémon!\p"
    .string "Seria un descobriment científic\n"
    .string "revolucionari si es poguessin\l"
    .string "ressuscitar Pokémon a partir\l"
    .string "d'això.\p"
    .string "Però els meus col·legues ignoren\n"
    .string "el que dic.\p"
    .string "Així que tinc un favor a demanar!\p"
    .string "Vull que facis examinar això en\n"
    .string "un laboratori Pokémon.$"

PewterCity_Museum_1F_Text_ReceivedOldAmber::
    .string "{PLAYER} ha rebut l'Ambre Antic\n"
    .string "del científic.$"

PewterCity_Museum_1F_EventScript_NoRoomForOldAmber::
	msgbox PewterCity_Museum_1F_Text_DontHaveSpaceForThis, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_1F_Text_DontHaveSpaceForThis::
    .string "No tens espai per a això.$"

PewterCity_Museum_1F_EventScript_OldAmber::
	msgbox PewterCity_Museum_1F_Text_BeautifulPieceOfAmber, MSGBOX_NPC
	end

PewterCity_Museum_1F_Text_BeautifulPieceOfAmber::
    .string "Hi ha un bonic tros d'ambre\n"
    .string "d'un clar color daurat.$"

PewterCity_Museum_1F_EventScript_OldMan::
	msgbox PewterCity_Museum_1F_Text_ShouldBeGratefulForLongLife, MSGBOX_NPC
	end

PewterCity_Museum_1F_Text_ShouldBeGratefulForLongLife::
    .string "Hauria d'estar agraït per la meva\n"
    .string "llarga vida.\p"
    .string "Mai no hauria pensat que veuria\n"
    .string "els ossos d'un drac!$"

PewterCity_Museum_1F_EventScript_PokemonJournalBrock::
	msgbox PokemonJournal_Text_SpecialFeatureBrock, MSGBOX_SIGN
	release
	end

PokemonJournal_Text_SpecialFeatureBrock::
	.string "Diari Pokémon\p"
	.string "Especial: Brock, Líder del\n"
	.string "Gimnàs de Pewter!\p"
	.string "Brock rarament riu, però diuen\n"
	.string "que si comença no pot parar.$"


PewterCity_Museum_1F_EventScript_AerodactylFossil::
    lockall
    setvar VAR_0x8004, SPECIES_AERODACTYL
    setvar VAR_0x8005, 10
    setvar VAR_0x8006, 3
    special OpenMuseumFossilPic
    msgbox PewterCity_Museum_1F_Text_AerodactylFossil
    special CloseMuseumFossilPic
    releaseall
    end

PewterCity_Museum_1F_Text_AerodactylFossil::
    .string "Fòssil d'Aerodactyl\n"
    .string "Un Pokémon primitiu i rar.$"

PewterCity_Museum_1F_EventScript_KabutopsFossil::
    lockall
    setvar VAR_0x8004, SPECIES_KABUTOPS
    setvar VAR_0x8005, 10
    setvar VAR_0x8006, 3
    special OpenMuseumFossilPic
    msgbox PewterCity_Museum_1F_Text_KabutopsFossil
    special CloseMuseumFossilPic
    releaseall
    end

PewterCity_Museum_1F_Text_KabutopsFossil::
    .string "Fòssil de Kabutops\n"
    .string "Un Pokémon primitiu i rar.$"

SSAnne_Kitchen_MapScripts::
	.byte 0

SSAnne_Kitchen_EventScript_Chef1::
	msgbox SSAnne_Kitchen_Text_BusyOutOfTheWay, MSGBOX_NPC
	end

SSAnne_Kitchen_Text_BusyOutOfTheWay::
    .string "Tu, mon petit!\n"
    .string "Estem molt ocupats aquí!\l"
    .string "Fora del camí!$"

SSAnne_Kitchen_EventScript_Chef2::
	msgbox SSAnne_Kitchen_Text_SawOddBerryInTrash, MSGBOX_NPC
	end

SSAnne_Kitchen_Text_SawOddBerryInTrash::
    .string "He vist una baia estranya a les\n"
    .string "escombraries. Què devia ser?$"

SSAnne_Kitchen_EventScript_Chef3::
	msgbox SSAnne_Kitchen_Text_SoBusyImDizzy, MSGBOX_NPC
	end

SSAnne_Kitchen_Text_SoBusyImDizzy::
    .string "Estic tan ocupat que em marejo!\n"
    .string "M'has de deixar espai aquí!$"

SSAnne_Kitchen_EventScript_Chef4::
	lock
	faceplayer
	msgbox SSAnne_Kitchen_Text_IAmLeChefMainCourseIs
	random 3
	call_if_eq VAR_RESULT, 0, SSAnne_Kitchen_EventScript_SalmonDuSalad
	call_if_eq VAR_RESULT, 1, SSAnne_Kitchen_EventScript_EelsAuBarbecue
	call_if_eq VAR_RESULT, 2, SSAnne_Kitchen_EventScript_PrimeBeefsteak
	release
	end

SSAnne_Kitchen_Text_IAmLeChefMainCourseIs::
    .string "Ehem!\n"
    .string "En efecte, sóc le XEF!\p"
    .string "Le plat principal és$"

SSAnne_Kitchen_EventScript_SalmonDuSalad::
	msgbox SSAnne_Kitchen_Text_SalmonDuSalad
	return

SSAnne_Kitchen_Text_SalmonDuSalad::
    .string "Saumon du Salade!\p"
    .string "Les convidats potser es queixen\n"
    .string "que és peix un altre cop!$"

SSAnne_Kitchen_EventScript_EelsAuBarbecue::
	msgbox SSAnne_Kitchen_Text_EelsAuBarbecue
	return

SSAnne_Kitchen_Text_EelsAuBarbecue::
    .string "Anguiles au Barbecue!\p"
    .string "Les convidats es rebel·laran,\n"
    .string "em temo.$"

SSAnne_Kitchen_EventScript_PrimeBeefsteak::
	msgbox SSAnne_Kitchen_Text_PrimeBeefsteak
	return

SSAnne_Kitchen_Text_PrimeBeefsteak::
    .string "Bistec de Primera!\p"
    .string "Però, tinc prou filets du\n"
    .string "boeuf?$"

SSAnne_Kitchen_EventScript_Chef5::
	msgbox SSAnne_Kitchen_Text_PeelSpudsEveryDay, MSGBOX_NPC
	end

SSAnne_Kitchen_Text_PeelSpudsEveryDay::
    .string "La-la-la-la-la…\p"
    .string "Pelo patates cada dia!\n"
    .string "La-la…$"

SSAnne_Kitchen_EventScript_Chef6::
	msgbox SSAnne_Kitchen_Text_HearAboutSnorlaxItsAGlutton, MSGBOX_NPC
	end

SSAnne_Kitchen_Text_HearAboutSnorlaxItsAGlutton::
    .string "Has sentit parlar de Snorlax?\n"
    .string "És un golafre.\p"
    .string "Cap altre Pokémon menja i dorm\n"
    .string "com Snorlax!$"

SSAnne_Kitchen_EventScript_Chef7::
	msgbox SSAnne_Kitchen_Text_OnlyGetToPeelOnions, MSGBOX_NPC
	end

SSAnne_Kitchen_Text_OnlyGetToPeelOnions::
    .string "Snif… Snif…\p"
    .string "Només em deixen pelar cebes…\n"
    .string "Snif…$"

SSAnne_Kitchen_EventScript_ItemGreatBall::
	finditem ITEM_GREAT_BALL, 1
	release
	end

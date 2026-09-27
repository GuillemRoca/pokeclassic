CeladonCity_Restaurant_MapScripts::
	.byte 0
CeladonCity_Restaurant_EventScript_Chef::
	msgbox CeladonCity_Restaurant_Text_TakingBreakRightNow, MSGBOX_NPC
	end

CeladonCity_Restaurant_Text_TakingBreakRightNow::
    .string "Hola!\p"
    .string "Perdona, però estem fent una\n"
    .string "pausa ara mateix.$"

CeladonCity_Restaurant_EventScript_Woman::
	msgbox CeladonCity_Restaurant_Text_OftenGoToDrugstore, MSGBOX_NPC
	end

CeladonCity_Restaurant_Text_OftenGoToDrugstore::
    .string "Els meus Pokémon són febles,\n"
    .string "així que sovint he d'anar a la\l"
    .string "Parafarmàcia.$"

CeladonCity_Restaurant_EventScript_CoinCaseMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, CeladonCity_Restaurant_EventScript_AlreadyGotCoinCase
	msgbox CeladonCity_Restaurant_Text_TakeThisImBusted
	checkitemspace ITEM_COIN_CASE, 1
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Restaurant_EventScript_NoRoomForCoinCase
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message CeladonCity_Restaurant_Text_ReceivedCoinCaseFromMan
	waitfanfare
	waitmessage
	additem ITEM_COIN_CASE, 1
	setflag FLAG_RECEIVED_COIN_CASE
	release
	end

CeladonCity_Restaurant_Text_TakeThisImBusted::
    .string "Endavant! Riu-te'n!\n"
    .string "Estic completament arruïnat!\p"
    .string "S'han acabat les slots per a mi!\n"
    .string "Seguiré el bon camí!\p"
    .string "Té!\n"
    .string "Ja no necessitaré més això!$"

CeladonCity_Restaurant_Text_ReceivedCoinCaseFromMan::
    .string "{PLAYER} ha rebut un Estoig de\n"
    .string "Monedes de l'home.$"

CeladonCity_Restaurant_EventScript_NoRoomForCoinCase::
	msgbox CeladonCity_Restaurant_Text_MakeRoomForThis
	release
	end

CeladonCity_Restaurant_Text_MakeRoomForThis::
    .string "Fes espai per a això!$"

CeladonCity_Restaurant_EventScript_AlreadyGotCoinCase::
	msgbox CeladonCity_Restaurant_Text_ThoughtIdWinItBack
	release
	end

CeladonCity_Restaurant_Text_ThoughtIdWinItBack::
    .string "Sempre vaig pensar que ho\n"
    .string "recuperaria…$"

CeladonCity_Restaurant_EventScript_WorkerM::
	msgbox CeladonCity_Restaurant_Text_PsstBasementUnderGameCorner, MSGBOX_NPC
	end

CeladonCity_Restaurant_Text_PsstBasementUnderGameCorner::
    .string "Psst! Hi ha un soterrani secret\n"
    .string "sota la Sala de Jocs, pel que\l"
    .string "he sentit.$"

CeladonCity_Restaurant_EventScript_FatMan::
	msgbox CeladonCity_Restaurant_Text_ManLostItAllAtSlots, MSGBOX_NPC
	end

CeladonCity_Restaurant_Text_ManLostItAllAtSlots::
    .string "Nyam…\p"
    .string "L'home d'aquella taula s'ho ha\n"
    .string "jugat tot a les slots.$"

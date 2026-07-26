.set LOCALID_CAPTAIN, 1

SSAnne_CaptainsOffice_MapScripts::
	.byte 0

SSAnne_CaptainsOffice_EventScript_Captain::
	lock
	goto_if_set FLAG_RECEIVED_HM01, SSAnne_CaptainsOffice_EventScript_AlreadyGotCut
	msgbox SSAnne_CaptainsOffice_Text_CaptainIFeelSeasick
	message SSAnne_CaptainsOffice_Text_RubbedCaptainsBack
	waitmessage
	playfanfare MUS_HEAL
	waitfanfare
	delay 50
	applymovement LOCALID_CAPTAIN, Common_Movement_FacePlayer
	waitmovement 1
	checkitemspace ITEM_HM01, 1
	goto_if_eq VAR_RESULT, FALSE, SSAnne_CaptainsOffice_EventScript_NoRoomForCut
	msgbox SSAnne_CaptainsOffice_Text_ThankYouHaveHMForCut
	playfanfare MUS_OBTAIN_TMHM
	message SSAnne_CaptainsOffice_Text_ObtainedHM01FromCaptain
	waitfanfare
	waitmessage
	additem ITEM_HM01, 1
	msgbox SSAnne_CaptainsOffice_Text_ExplainCut
	setflag FLAG_RECEIVED_HM01
	setvar VAR_SS_ANNE_STATE, 2
	release
	end

SSAnne_CaptainsOffice_Text_CaptainIFeelSeasick::
    .string "Capità: Ooargh…\n"
    .string "Em trobo fatal…\l"
    .string "Urrp! Marejat…$"

SSAnne_CaptainsOffice_Text_RubbedCaptainsBack::
    .string "{PLAYER} va fregar l'esquena\n"
    .string "del Capità!\p"
    .string "Frega-frega…\n"
    .string "Frega-frega-frega…$"

SSAnne_CaptainsOffice_Text_ThankYouHaveHMForCut::
    .string "Capità: Uf! Gràcies!\n"
    .string "Em trobo molt millor ara.\p"
    .string "Vols veure la meva tècnica\n"
    .string "secreta de tall?\p"
    .string "Podria ensenyar-te la meva\n"
    .string "tècnica si no estigués tan\l"
    .string "malalt…\p"
    .string "Ja ho sé! Pots tenir això!\n"
    .string "Aquesta Màquina Oculta!\p"
    .string "Ensenya tall al teu Pokémon,\n"
    .string "i podràs veure'l tallar sempre!$"

SSAnne_CaptainsOffice_Text_ObtainedHM01FromCaptain::
    .string "{PLAYER} ha obtingut la MO01\n"
    .string "del Capità!$"

SSAnne_CaptainsOffice_Text_ExplainCut::
    .string "Amb tall, pots tallar arbres\n"
    .string "petits.\p"
    .string "Per què no ho proves amb els\n"
    .string "arbres de Ciutat Vermilion?$"

SSAnne_CaptainsOffice_EventScript_NoRoomForCut::
	msgbox SSAnne_CaptainsOffice_Text_YouHaveNoRoomForThis
	closemessage
	applymovement LOCALID_CAPTAIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SSAnne_CaptainsOffice_Text_YouHaveNoRoomForThis::
    .string "Oh, no!\n"
    .string "No tens espai per a això!\p"
    .string "Oh no, sento una altra onada\n"
    .string "que ve --- HURGH!!$"

SSAnne_CaptainsOffice_EventScript_AlreadyGotCut::
	applymovement LOCALID_CAPTAIN, Common_Movement_FacePlayer
	waitmovement 1
	msgbox SSAnne_CaptainsOffice_Text_SSAnneWillSetSailSoon
	release
	end

SSAnne_CaptainsOffice_Text_SSAnneWillSetSailSoon::
    .string "Capità: …Uf!\p"
    .string "Ara que ja no estic malalt,\n"
    .string "suposo que és l'hora.\p"
    .string "L'SS Anna zarparà aviat!\p"
    .string "Adéu, fins al nostre retorn a\n"
    .string "Ciutat Vermilion!$"

SSAnne_CaptainsOffice_EventScript_TrashCan::
	msgbox SSAnne_CaptainsOffice_Text_YuckShouldntHaveLooked, MSGBOX_SIGN
	end

SSAnne_CaptainsOffice_Text_YuckShouldntHaveLooked::
    .string "Ecs!\n"
    .string "No hauria d'haver mirat!$"

SSAnne_CaptainsOffice_EventScript_Book::
	msgbox SSAnne_CaptainsOffice_Text_HowToConquerSeasickness, MSGBOX_SIGN
	end

SSAnne_CaptainsOffice_Text_HowToConquerSeasickness::
    .string "Com Superar el Mareig…\n"
    .string "El Capità està llegint això!$"

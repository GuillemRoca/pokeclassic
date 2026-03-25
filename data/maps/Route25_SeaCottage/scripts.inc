.set LOCALID_BILL_HUMAN,    1
.set LOCALID_BILL_CLEFAIRY, 2
.set LOCALID_PIKACHU, 3

@VAR_SEA_COTTAGE_STATE
@0 = Nothing yet. Runs Pikachu event if starter is in party
@1 = Checked for Pikachu event
@2 = Bill is in Teleporter
@3 = Rescued Bill
@4 = Got Badge 2, but didn't get DexNav. Only set by Misty, if you have Badge 2 when rescuing Bill, this is skipped.
@5 = Received the call to come to Bill's. Set in Cerulean, if you already had Badge 2 when rescuing Bill this is also skipped.
@6 = Got DexNav

Route25_SeaCottage_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_SeaCottage_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route25_SeaCottage_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route25_SeaCottage_OnFrame
	.byte 0

Route25_SeaCottage_OnTransition::
	goto_if_ge VAR_SEA_COTTAGE_STATE, 3, Route25_SeaCottage_SetBillPosition
	end

Route25_SeaCottage_OnWarp:
	map_script_2 VAR_SEA_COTTAGE_STATE, 0, Route25_SeaCottage_CheckPartnerSceneSetups
	.2byte 0

Route25_SeaCottage_CheckPartnerSceneSetups::
	special IsPartnerInParty
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_End
	setflag FLAG_HIDE_FOLLOWER
	clearflag FLAG_HIDE_SEA_COTTAGE_PIKACHU
	addobject LOCALID_PIKACHU
	end

Route25_SeaCottage_SetBillPosition::
	setobjectxyperm LOCALID_BILL_HUMAN, 7,5
	end

Route25_SeaCottage_OnFrame:
	map_script_2 VAR_SEA_COTTAGE_STATE, 0, Route25_SeaCottage_PikachuLabScene
	.2byte 0

Route25_SeaCottage_PikachuLabScene::
	lock
	applymovement LOCALID_PIKACHU, Movement_PikachuScopesOutLab
	waitmovement 3
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	applymovement LOCALID_PIKACHU, Common_Movement_ExclamationMark
	waitmoncry
	applymovement LOCALID_PIKACHU, Movement_ReturnToPlayer
	waitmovement 3
	removeobject LOCALID_PIKACHU
	clearflag FLAG_HIDE_FOLLOWER
	setvar VAR_SEA_COTTAGE_STATE, 1
	release
	end

Movement_PikachuScopesOutLab::
	walk_up
	walk_up
	face_left
	delay_16
	face_right
	delay_16
	face_down
	emote_question_mark
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	emote_question_mark
	delay_16
	delay_16
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

Movement_ReturnToPlayer::
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

Route25_SeaCottage_EventScript_Bill::
	lock
	faceplayer
	goto_if_set FLAG_SYS_DETECTOR_MODE, Route25_SeaCottage_EventScript_BillGoLookAtPC
	goto_if_set FLAG_SYS_DEXNAV_GET, Route25_SeaCottage_EventScript_CheckDexNavEvent
	goto_if_set FLAG_GOT_SS_TICKET, Route25_SeaCottage_EventScript_GetDexNavOrSmallTalk
	goto_if_set FLAG_HELPED_BILL_IN_SEA_COTTAGE, Route25_SeaCottage_EventScript_BillGiveSSTicket
	goto Route25_SeaCottage_EventScript_BillAskForHelp
	end

Route25_SeaCottage_EventScript_CheckDexNavEvent::
	goto_if_unset FLAG_BADGE05_GET, Route25_SeaCottage_EventScript_BillGoLookAtPC
	goto Route25_SeaCottage_EventScript_GetDexNavUpgrade
	end

Route25_SeaCottage_EventScript_BillAskForHelp::
	msgbox Route25_SeaCottage_Text_ImBillHelpMeOutPal, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, Route25_SeaCottage_EventScript_DeclineHelpBill
	msgbox Route25_SeaCottage_Text_RunCellSeparationOnPC, MSGBOX_DEFAULT
	closemessage
	delay 10
	call_if_eq VAR_FACING, DIR_SOUTH, Route25_SeaCottage_EventScript_BillWalkToTeleporterSouth
	call_if_ne VAR_FACING, DIR_SOUTH, Route25_SeaCottage_EventScript_BillWalkToTeleporter
	opendoor 10, 3
	waitdooranim
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_BILL_CLEFAIRY, Route25_SeaCottage_Movement_BillEnterTeleporter
	waitmovement 2
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	removeobject LOCALID_BILL_CLEFAIRY
	playse SE_CONTEST_CURTAIN_FALL
	closedoor 10, 3
	waitdooranim
	setflag FLAG_BILL_IN_TELEPORTER
	setvar VAR_SEA_COTTAGE_STATE, 2
	release
	end

Route25_SeaCottage_Text_ImBillHelpMeOutPal::
    .string "Hola! Sóc un Pokémon…\n"
    .string "…No, no ho sóc!\p"
    .string "Digue'm Bill!\n"
    .string "Sóc un autèntic PokèManíac!\p"
    .string "Ei!\n"
    .string "Per què aquesta cara escèptica?\p"
    .string "No t'estic enganyant.\p"
    .string "He espifiat un experiment i m'he\n"
    .string "combinat amb un Pokémon!\p"
    .string "Què em dius?\n"
    .string "M'ajudes?$"

Route25_SeaCottage_EventScript_DeclineHelpBill::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_BILL_CLEFAIRY, Common_Movement_ExclamationMark
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	msgbox Route25_SeaCottage_Text_NoPlease, MSGBOX_DEFAULT
	return

Route25_SeaCottage_Text_NoPlease::
    .string "No!?\n"
    .string "No siguis tan fred!\p"
    .string "Vinga, has d'ajudar a algú\n"
    .string "en grans problemes!\p"
    .string "Què em dius?\n"
    .string "Si us plau?\l"
    .string "D'acord?\l"
    .string "Va!$"

Route25_SeaCottage_Text_RunCellSeparationOnPC::
    .string "Espera que entri al\n"
    .string "teletransportador.\p"
    .string "Quan ho faci, ves al meu PC i\n"
    .string "executa el Separador Cel·lular.$"

Route25_SeaCottage_EventScript_BillWalkToTeleporterSouth::
	applymovement LOCALID_BILL_CLEFAIRY, Route25_SeaCottage_Movement_BillWalkToTeleporterSouth
	waitmovement 2
	return

Route25_SeaCottage_Movement_BillWalkToTeleporterSouth::
	walk_right
	walk_up
	walk_up
	walk_left
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

Route25_SeaCottage_EventScript_BillWalkToTeleporter::
	applymovement LOCALID_BILL_CLEFAIRY, Route25_SeaCottage_Movement_BillWalkToTeleporter
	waitmovement 2
	return

Route25_SeaCottage_Movement_BillWalkToTeleporter::
	walk_up
	walk_up
	step_end

Route25_SeaCottage_Movement_BillEnterTeleporter::
	walk_up
	step_end

Route25_SeaCottage_EventScript_Computer::
	lockall
	goto_if_set FLAG_SYS_DEXNAV_GET, Route25_SeaCottage_EventScript_OpenBillsMonList
	goto_if_set FLAG_BILL_IN_TELEPORTER, Route25_SeaCottage_EventScript_RunCellSeparator
	msgbox Route25_SeaCottage_Text_TeleporterIsDisplayed
	releaseall
	end

Route25_SeaCottage_Text_TeleporterIsDisplayed::
    .string "Teleporter.exe es mostra al\n"
    .string "monitor del PC.$"

Route25_SeaCottage_EventScript_RunCellSeparator::
	fadeoutbgm 0
	msgbox Route25_SeaCottage_Text_InitiatedTeleportersCellSeparator
	closemessage
	clearflag FLAG_BILL_IN_TELEPORTER
	setvar VAR_SEA_COTTAGE_STATE, 3
	setflag FLAG_HELPED_BILL_IN_SEA_COTTAGE
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Route25_SeaCottage_Movement_CameraPanToTeleporters
	waitmovement 0
	delay 35
	playse SE_PIN
	waitse
	setvar VAR_0x8004, 0
	special AnimateTeleporterHousing
	delay 10
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	setvar VAR_0x8004, 1
	special AnimateTeleporterHousing
	playse SE_WARP_IN
	special AnimateTeleporterCable
	waitse
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	opendoor 3, 3
	waitdooranim
	fadeinbgm 0
	addobject LOCALID_BILL_HUMAN
	clearflag FLAG_HIDE_SEA_COTTAGE_BILL
	delay 50
	playfanfare MUS_LEVEL_UP
	applymovement LOCALID_BILL_HUMAN, Route25_SeaCottage_Movement_BillExitTeleporter
	waitmovement 1
	waitfanfare
	applymovement OBJ_EVENT_ID_CAMERA, Route25_SeaCottage_Movement_CameraPanBackFromTeleporters
	waitmovement 0
	playse SE_CONTEST_CURTAIN_FALL
	closedoor 3, 3
	waitdooranim
	applymovement LOCALID_BILL_HUMAN, Route25_SeaCottage_Movement_BillWalkToMiddleOfRoom
	waitmovement 1
	special RemoveCameraObject
	releaseall
	end

Route25_SeaCottage_Text_InitiatedTeleportersCellSeparator::
    .string "{PLAYER} ha obert Teleporter.exe!\n"
    .string "Ha iniciat el Separador Cel·lular.$"

Route25_SeaCottage_Movement_CameraPanToTeleporters::
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

Route25_SeaCottage_EventScript_PlayTeleporterBeepSE::
	playse SE_BALL
	waitse
	delay 20
	return

Route25_SeaCottage_Movement_BillExitTeleporter::
	walk_down
	step_end

Route25_SeaCottage_Movement_CameraPanBackFromTeleporters::
	delay_16
	delay_16
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

Route25_SeaCottage_Movement_BillWalkToMiddleOfRoom::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

Route25_SeaCottage_EventScript_BillGiveSSTicket::
	msgbox Route25_SeaCottage_Text_ThanksTakeThis, MSGBOX_DEFAULT
	checkitemspace ITEM_SS_TICKET, 1
	goto_if_eq VAR_RESULT, FALSE, Route25_SeaCottage_EventScript_NoRoomForSSTicket
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message Route25_SeaCottage_Text_ReceivedSSTicketFromBill
	waitfanfare
	waitmessage
	additem ITEM_SS_TICKET, 1
	setflag FLAG_GOT_SS_TICKET
	setflag FLAG_SYS_PC_BILL
	closemessage
	goto Route25_SeaCottage_EventScript_CheckRegisterBill
	end

Route25_SeaCottage_Text_ThanksTakeThis::
    .string "Bill: Visca!\n"
    .string "Gràcies, amic! Et dec una!\p"
    .string "I bé, has vingut a veure la\n"
    .string "meva col·lecció de Pokémon?\p"
    .string "No?\n"
    .string "Quina llàstima.\p"
    .string "T'ho he d'agrair…\n"
    .string "Potser això et servirà.$"

Route25_SeaCottage_Text_ReceivedSSTicketFromBill::
    .string "{PLAYER} ha rebut un bitllet\n"
    .string "del S.S. Anne d'en Bill.$"

Route25_SeaCottage_EventScript_NoRoomForSSTicket::
	msgbox Route25_SeaCottage_Text_YouveGotTooMuchStuff
	release
	end

Route25_SeaCottage_Text_YouveGotTooMuchStuff::
    .string "Portes massa coses a sobre!$"


Route25_SeaCottage_EventScript_GetDexNavOrSmallTalk::
	goto_if_unset FLAG_SYS_DEXNAV_GET, Route25_SeaCottage_EventScript_CheckRegisterBill
	goto Route25_SeaCottage_EventScript_BillGoToSSAnne
	end

Route25_SeaCottage_EventScript_CheckRegisterBill::
	goto_if_set FLAG_BADGE02_GET, Route25_SeaCottage_EventScript_RegisterBill
	goto Route25_SeaCottage_EventScript_BillGoToSSAnne
	end

Route25_SeaCottage_EventScript_BillGoToSSAnne::
	msgbox Route25_SeaCottage_Text_SSAnnePartyYouGoInstead, MSGBOX_DEFAULT
	release
	end

Route25_SeaCottage_Text_SSAnnePartyYouGoInstead::
    .string "Bill: El creuer S.S. Anne\n"
    .string "és a Ciutat Vermilion.\p"
    .string "He sentit que hi ha molts\n"
    .string "entrenadors a bord.\p"
    .string "Em van convidar a la seva festa,\n"
    .string "però no suporto les festes.\p"
    .string "Per què no hi vas tu en lloc meu?\n"
    .string "Vés i passa-ho bé.$"

Route25_SeaCottage_EventScript_RegisterBill::
	msgbox Route25_SeaCottage_Text_ReallyOweYouOne, MSGBOX_DEFAULT
	applymovement LOCALID_BILL_HUMAN, Common_Movement_ExclamationMark
	waitmovement 1
	msgbox Route25_SeaCottage_Text_IsThatAPokedex, MSGBOX_DEFAULT
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message Route25_SeaCottage_Text_GetDexNav
	waitfanfare
	waitmessage
	closemessage
	msgbox Route25_SeaCottage_Text_StillABeta, MSGBOX_DEFAULT
	setflag FLAG_SYS_DEXNAV_GET
	setvar VAR_SEA_COTTAGE_STATE, 6
	playfanfare MUS_REGISTER_MATCH_CALL
	message MatchCall_Text_RegisteredBill
	waitfanfare
	waitmessage
	closemessage
	setflag FLAG_REGISTERED_BILL
	goto Route25_SeaCottage_EventScript_ExplainDexNav
	end

Route25_SeaCottage_Text_ReallyOweYouOne::
	.string "Bill: Saps, et dec molt per\n"
	.string "ajudar-me amb l'accident del\l"
	.string "teletransportador.\p"
	.string "M'agradaria compensar-t'ho\n"
	.string "amb alguna cosa més que aquell\l"
	.string "bitllet del S.S. Anne...$"

Route25_SeaCottage_Text_IsThatAPokedex::
	.string "Oh! Això és una Pokédex?\p"
	.string "L'altre noi que va venir també\n"
	.string "en tenia una.\p"
	.string "Tens un PokéGear, oi?\p"
	.string "Deixa'm instal·lar-te una app\n"
	.string "que estic desenvolupant.$"

Route25_SeaCottage_Text_GetDexNav::
	.string "En Bill ha afegit l'app DexNav\n"
	.string "al PokéGear de {PLAYER}!$"

Route25_SeaCottage_Text_StillABeta::
	.string "Bill: Tècnicament encara està\n"
	.string "en fase Beta.\p"
	.string "Hi ha algunes funcions que\n"
	.string "m'agradaria afegir, però trigaré\l"
	.string "una mica.\p"
	.string "Ja sé! Et donaré el meu número\n"
	.string "de mòbil.\p"
	.string "Així em pots dir com va el\n"
	.string "DexNav, i jo t'aviso si tinc\l"
	.string "actualitzacions noves!$"

Route25_SeaCottage_EventScript_ExplainDexNav::
	msgbox Route25_SeaCottage_Text_ExplainDexNav, MSGBOX_DEFAULT
	release
	end

Route25_SeaCottage_Text_ExplainDexNav::
	.string "He après sobre la Pokédex per\n"
	.string "correu amb el Prof. Oak!\p"
	.string "El DexNav hauria de fer més\n"
	.string "interessant trobar Pokémon rars!\p"
	.string "Pots rastrejar tot tipus de\n"
	.string "Pokémon, però funciona millor\l"
	.string "quan té dades de la Pokédex\l"
	.string "per aprendre! Atrapa molts!$"

Route25_SeaCottage_EventScript_DontLeaveMe::
	lock
	playse SE_WALL_HIT
	waitse
	playse SE_WALL_HIT
	waitse
	playse SE_WALL_HIT
	waitse
	msgbox Route25_SeaCottage_Text_DontLeaveMe, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Movement_DontLeaveBills
	waitmovement 0
	release
	end

Route25_SeaCottage_Text_DontLeaveMe::
	.string "Bill: Ei! Has executat el programa?\p"
	.string "Hola?\n"
	.string "Hola!?\p"
	.string "No em deixis aquí dins!$"

Movement_DontLeaveBills:
	walk_up
	step_end


Route25_SeaCottage_EventScript_BillGoLookAtPC::
	msgbox Route25_SeaCottage_Text_CheckOutRareMonsOnPC, MSGBOX_NPC
	release
	end

Route25_SeaCottage_Text_CheckOutRareMonsOnPC::
    .string "Bill: Vols veure alguns dels\n"
    .string "meus Pokémon rars al meu PC?\p"
    .string "Vinga, mira el meu PC.$"

Route25_SeaCottage_EventScript_OpenBillsMonList::
	msgbox Route25_SeaCottage_Text_BillsFavoriteMonList
	goto Route25_SeaCottage_EventScript_BillsMonList
	end

Route25_SeaCottage_Text_BillsFavoriteMonList::
    .string "Llista de Pokémon preferits\n"
    .string "d'en Bill!$"

Route25_SeaCottage_EventScript_BillsMonList::
	message Route25_SeaCottage_Text_SeeWhichMon
	waitmessage
	multichoice 0, 0, MULTI_BILLS_POKEMON, FALSE
	switch VAR_RESULT
	case 0, Route25_SeaCottage_EventScript_ViewEevee
	case 1, Route25_SeaCottage_EventScript_ViewFlareon
	case 2, Route25_SeaCottage_EventScript_ViewJolteon
	case 3, Route25_SeaCottage_EventScript_ViewVaporeon
	case 4, Route25_SeaCottage_EventScript_ExitBillsMonList
	case MULTI_B_PRESSED, Route25_SeaCottage_EventScript_ExitBillsMonList
	end

Route25_SeaCottage_Text_SeeWhichMon::
    .string "Quin Pokémon vols veure?$"

Route25_SeaCottage_EventScript_ViewEevee::
	showmonpic SPECIES_EEVEE, 10, 3
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_EEVEE
	special SetSeenMon
	goto Route25_SeaCottage_EventScript_BillsMonList
	end

Route25_SeaCottage_EventScript_ViewFlareon::
	showmonpic SPECIES_FLAREON, 10, 3
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_FLAREON
	special SetSeenMon
	goto Route25_SeaCottage_EventScript_BillsMonList
	end

Route25_SeaCottage_EventScript_ViewJolteon::
	showmonpic SPECIES_JOLTEON, 10, 3
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_JOLTEON
	special SetSeenMon
	goto Route25_SeaCottage_EventScript_BillsMonList
	end

Route25_SeaCottage_EventScript_ViewVaporeon::
	showmonpic SPECIES_VAPOREON, 10, 3
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_VAPOREON
	special SetSeenMon
	goto Route25_SeaCottage_EventScript_BillsMonList
	end

Route25_SeaCottage_EventScript_ExitBillsMonList::
	releaseall
	end

Route25_SeaCottage_EventScript_GetDexNavUpgrade::
	msgbox Route25_SeaCottage_Text_HeyPlayerBeatGiovanni, MSGBOX_DEFAULT
	call_if_set FLAG_GAVE_BILL_IDEA, Route25_SeaCottage_EventScript_GaveBillIdea
	call_if_unset FLAG_GAVE_BILL_IDEA, Route25_SeaCottage_EventScript_BillHadIdea
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message Route25_SeaCottage_Text_GetDetectorMode
	waitfanfare
	waitmessage
	closemessage
	msgbox Route25_SeaCottage_Text_DetectorMode, MSGBOX_DEFAULT
	setflag FLAG_SYS_DETECTOR_MODE
	release
	end

Route25_SeaCottage_Text_HeyPlayerBeatGiovanni::
	.string "Bill: Ei, {PLAYER}!\n"
	.string "Gràcies per venir.\p"
	.string "He vist molt de xivarri sobre\n"
	.string "tu a internet!\p"
	.string "Són certs tots els rumors que\n"
	.string "he llegit a la xarxa?\p"
	.string "Has derrotat realment el Cap\n"
	.string "de l'Equip Rocket?\p"
	.string "Uau. Increïble.$"

Route25_SeaCottage_EventScript_GaveBillIdea::
	msgbox Route25_SeaCottage_Text_YourIdea, MSGBOX_DEFAULT
	return

Route25_SeaCottage_Text_YourIdea::
	.string "M'alegro que hagis trucat.\n"
	.string "Em vas donar una gran idea!\p"
	.string "Tota aquesta història del Giovanni\n"
	.string "i la seva base secreta... em va fer\l"
	.string "pensar en què més podria estar\l"
	.string "amagat al nostre voltant.\p"
	.string "Potser hi ha Pokémon rars just\n"
	.string "davant els nostres nassos!\p"
	.string "Crec que aquesta actualització\n"
	.string "ens ajudarà a esbrinar-ho!$"

Route25_SeaCottage_EventScript_BillHadIdea::
	msgbox Route25_SeaCottage_Text_MyIdea, MSGBOX_DEFAULT
	return

Route25_SeaCottage_Text_MyIdea::
	.string "En tot cas, m'alegro que hagis\n"
	.string "vingut. He estat treballant en\l"
	.string "millores per al DexNav.\p"
	.string "Crec que seran molt útils!$"

Route25_SeaCottage_Text_GetDetectorMode::
	.string "En Bill ha actualitzat el DexNav!\n"
	.string "S'ha activat el Mode Detector!$"

Route25_SeaCottage_Text_DetectorMode::
	.string "Bill: El Mode Detector t'ajuda a\n"
	.string "trobar Pokémon ocults a Kanto!\p"
	.string "Els Pokémon ocults poden saber\n"
	.string "nous moviments o tenir habilitats\l"
	.string "rares.\p"
	.string "És realment increïble!\n"
	.string "Vés a provar-ho!$"

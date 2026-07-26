.set LOCALID_MOM, 1
.set LOCALID_BILL, 2

PalletTown_PlayersHouse_1F_MapScripts::
	.byte 0

PalletTown_PlayersHouse_1F_EvenScripts_Mom::
	lock
	faceplayer
	goto_if_le VAR_ADVENTURE_BEGINS, 2, PalletTown_PlayersHouse_1F_EventScript_BetterHurry
	goto_if_eq VAR_ADVENTURE_BEGINS, 3, PlayersHouse_1F_EventScript_PokenavScene
	goto_if_eq VAR_SECRET_BATTLE_CLEAR, 2, PlayersHouse_1F_EventScript_BillVisiting
	goto_if_eq VAR_SECRET_BATTLE_CLEAR, 3, PlayersHouse_1F_EventScript_AnotherAdventure
	goto PalletTown_PlayersHouse_1F_EventScript_MomHeal
	end

PlayersHouse_1F_EventScript_BillVisiting::
	msgbox PalletTown_PlayersHouse_1F_Text_BillVisiting, MSGBOX_DEFAULT
	turnobject LOCALID_MOM, DIR_WEST
	release
	end

PalletTown_PlayersHouse_1F_Text_BillVisiting::
	.string "Mare: No sabia que coneixies\n"
	.string "el famós PokéManíac, reina!\p"
	.string "És tot un cavaller!$"

PlayersHouse_1F_EventScript_AnotherAdventure::
	.string "Pedres estranyes? Potencial ocult?\p"
	.string "Les aventures no s'acaben mai per a\n" 
	.string "vosaltres, entrenadors Pokémon!$"

PalletTown_PlayersHouse_1F_EventScript_BetterHurry::
	msgbox PalletTown_PlayersHouse_1F_Text_BetterHurry, MSGBOX_DEFAULT
	turnobject LOCALID_MOM, DIR_WEST
	release
	end

PalletTown_PlayersHouse_1F_Text_BetterHurry:
	.string "Mare: No et convé perdre't\n"
	.string "el Professor Oak!\p"
	.string "Val més que t'afanyis!$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
    .string "Fan una pel·lícula a la tele.\n"
    .string "Quatre nois caminen per les vies\l"
    .string "del tren.\p"
    .string "…Val més que jo també marxi.$"

EventScript_RunningShoesManual::
	msgbox PlayersHouse_1F_Text_RunningShoesManual, MSGBOX_SIGN
	end
	
PlayersHouse_1F_Text_RunningShoesManual:
	.string "És el manual d'instruccions de les\n"
	.string "Sabates de Córrer.\p"
	.string "“Prem el botó B per córrer mentre\n"
	.string "portes les Sabates de Córrer.\p"
	.string "Corda't les Sabates de Córrer i\n"
	.string "surt a la carretera corrent!”$"

PlayersHouse_1F_EventScript_PokenavScene::
	msgbox PalletTown_Text_DidYouMeetOak, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, Common_Movement_Heart
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	msgbox PalletTown_Text_WhatACutePokemon, MSGBOX_DEFAULT
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PalletTown_Text_ReceivedPokeGear
	waitmessage
	waitfanfare
	msgbox PalletTown_Text_CallMeSometime, MSGBOX_DEFAULT
	closemessage
	delay 30
	setflag FLAG_SYS_POKENAV_GET
	setvar VAR_ADVENTURE_BEGINS, 4
	turnobject LOCALID_MOM, DIR_WEST
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_MomHeal::
	msgbox PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare
	turnobject LOCALID_MOM, DIR_WEST
	release
	end

PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest::
    .string "Mare: {PLAYER}!\n"
    .string "Hauries de descansar una mica.$"

PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare::
    .string "Mare: Oh, molt bé! Tu i els teus\n"
    .string "Pokémon teniu molt bon aspecte.\l"
    .string "Aneu amb compte!$"

PlayersHouse_1F_EventScript_GameclearTrigger1::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto PlayersHouse_1F_EventScript_Gameclear

PlayersHouse_1F_EventScript_GameclearTrigger2::
	setvar VAR_TEMP_1, 2
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	goto PlayersHouse_1F_EventScript_Gameclear

PlayersHouse_1F_EventScript_DontLeaveYet::
	lockall
	turnobject LOCALID_MOM, DIR_SOUTH
	turnobject LOCALID_BILL, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	waitse
	msgbox PlayersHouse_1F_Text_Visitor, MSGBOX_DEFAULT
	waitmessage
	turnobject LOCALID_MOM, DIR_WEST
	turnobject LOCALID_BILL, DIR_EAST
	release
	end

PlayersHouse_1F_EventScript_Bill::
	lock
	goto_if_set FLAG_GOT_MEGA_RING, PlayersHouse_1F_EventScript_Bill2
	msgbox PlayersHouse_1F_Text_SomethingAmazing, MSGBOX_NPC
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox PlayersHouse_1F_Text_GetMegaRing, MSGBOX_DEFAULT
	additem ITEM_MEGA_RING, 1
	setflag FLAG_GOT_MEGA_RING
	msgbox PlayersHouse_1F_Text_FindMegaStones, MSGBOX_NPC
	setvar VAR_SECRET_BATTLE_CLEAR, 3
	release
	end

PlayersHouse_1F_Text_SomethingAmazing::
	.string "Ei, {PLAYER}!\n"
	.string "He descobert una cosa increïble!\p"
	.string "Estava investigant per a la meva\n"
	.string "col·lecció Pokémon quan un dels meus\l"
	.string "escàners ha detectat una lectura estranya.\p"
	.string "Sembla que alguns Pokémon poden tenir\n"
	.string "un potencial ocult que encara no\l"
	.string "hem vist.\p"
	.string "I aquesta lectura sembla ser la clau!\p"
	.string "Mira, he trobat l'origen de la lectura\n"
	.string "prop de la Casa del Mar\p"
	.string "Era una pedra estranya que no havia\n"
	.string "vist mai!\p"
	.string "Me la vaig endur al laboratori i vaig\n"
	.string "fer un aparell per treure'n el poder!\p"
	.string "Vull que te'l quedis!$"

PlayersHouse_1F_Text_GetMegaRing::
	.string "El Bill t'ha donat un Anell Mega!$"

PlayersHouse_1F_Text_FindMegaStones::
	.string "Segons les meves lectures, hi ha\n"
	.string "més pedres d'aquestes amagades\l"
	.string "per tot Kanto.\p"
	.string "Ara que tens l'Anell Mega,\n"
	.string "hauries de poder veure-les!\p"
	.string "Haurem de trobar una Pedra Mega\n"
	.string "per provar la meva teoria!$"

PlayersHouse_1F_EventScript_Bill2::
	msgbox PlayersHouse_1F_Text_MegaStones, MSGBOX_NPC
	release
	end

PlayersHouse_1F_Text_MegaStones::
	.string "Bill: Haurem de trobar una\n"
	.string "Pedra Mega per provar la teoria!$"

PlayersHouse_1F_Text_Visitor::
	.string "Mare: On vas, {PLAYER}?\p"
	.string "No vas a saludar\n"
	.string "el nostre convidat?$"

PlayersHouse_1F_EventScript_Gameclear::
	lockall
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	waitse
	call_if_eq VAR_TEMP_1, 1, PlayersHouse_1F_EventScript_MoveMomToStairs1
	call_if_eq VAR_TEMP_1, 2, PlayersHouse_1F_EventScript_MoveMomToStairs2
	waitmovement 1
	msgbox PlayersHouse_1F_Text_Gameclear, MSGBOX_DEFAULT
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox PlayersHouse_1F_Text_FollowerOptions, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	msgbox PlayersHouse_1F_Text_Gameclear2, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_Heart
	waitmovement 1
	waitse
	call_if_eq VAR_TEMP_1, 1, PlayersHouse_1F_EventScript_MoveMomToTable1
	call_if_eq VAR_TEMP_1, 2, PlayersHouse_1F_EventScript_MoveMomToTable2
	waitmovement 1
	setvar VAR_ADVENTURE_BEGINS, 8
	releaseall
	end

PlayersHouse_1F_Text_Gameclear::
	.string "Mare: Oh, {PLAYER}!\n"
	.string "Ja t'has llevat?\p"
	.string "Amb tot el que has estat fent\n"
	.string "pensava que necessitaries més descans.\p"
	.string "...\p"
	.string "Has crescut molt, {PLAYER}.\p"
	.string "Crec que els teus Pokémon també ho veuen.\p"
	.string "Et seguiran a tot arreu!$"

PlayersHouse_1F_Text_FollowerOptions::
	.string "L'opció Acompanyant del menú d'Opcions\n"
	.string "ja es pot posar en mode Qualsevol!\p"
	.string "Quan la tries, el teu primer\n"
	.string "Pokémon et seguirà pertot!$"

PlayersHouse_1F_Text_Gameclear2::
	.string "Mare: Que siguis el nou campió\n"
	.string "no vol dir que la teva història\l"
	.string "s'hagi acabat!\p"
	.string "Hi ha tot un món a fora\n"
	.string "per explorar amb els teus Pokémon!\p"
	.string "Estic molt orgullosa de tu, {PLAYER}!\n"
	.string "Ves a passar-t'ho bé amb els Pokémon!$"

PlayersHouse_1F_EventScript_MoveMomToStairs1::
	applymovement LOCALID_MOM, Movement_MoveMomToStairs1
	return

PlayersHouse_1F_EventScript_MoveMomToStairs2::
	applymovement LOCALID_MOM, Movement_MoveMomToStairs2
	return

PlayersHouse_1F_EventScript_MoveMomToTable1::
	applymovement LOCALID_MOM, Movement_MoveMomToTable1
	return

PlayersHouse_1F_EventScript_MoveMomToTable2::
	applymovement LOCALID_MOM, Movement_MoveMomToTable2
	return

Movement_MoveMomToStairs1::
	walk_up
	walk_up
	face_right
	step_end

Movement_MoveMomToStairs2::
	walk_right
	walk_right
	face_up
	step_end

Movement_MoveMomToTable1::
	walk_down
	walk_down
	face_left
	step_end

Movement_MoveMomToTable2::
	walk_left
	walk_left
	step_end


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
	.string "el famós PokéManíac, carinyo!\p"
	.string "És tot un cavaller!$"

PlayersHouse_1F_EventScript_AnotherAdventure::
	.string "Pedres estranyes? Potencial ocult?\p"
	.string "Les aventures no s'acaben mai\n"
	.string "per als entrenadors Pokémon!$"

PalletTown_PlayersHouse_1F_EventScript_BetterHurry::
	msgbox PalletTown_PlayersHouse_1F_Text_BetterHurry, MSGBOX_DEFAULT
	turnobject LOCALID_MOM, DIR_WEST
	release
	end

PalletTown_PlayersHouse_1F_Text_BetterHurry:
	.string "Mare: No voldràs perdre't\n"
	.string "el Professor Oak!\p"
	.string "Més val que t'afanyis!$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
    .string "Fan una pel·lícula a la TV.\n"
    .string "Quatre nois caminen per les vies\l"
    .string "del tren.\p"
    .string "…Millor que me'n vagi jo també.$"

EventScript_RunningShoesManual::
	msgbox PlayersHouse_1F_Text_RunningShoesManual, MSGBOX_SIGN
	end

PlayersHouse_1F_Text_RunningShoesManual:
	.string "És el manual d'instruccions de les\n"
	.string "Sabatilles de Córrer.\p"
	.string ""Prem el Botó B per córrer mentre\n"
	.string "portes les Sabatilles de Córrer.\p"
	.string "Posa't les Sabatilles de Córrer\n"
	.string "i surt a córrer!"$"

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
    .string "Mare: Oh, bé! Tu i els teus\n"
    .string "Pokémon teniu molt bona pinta.\l"
    .string "Cuida't!$"

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
	.string "col·lecció Pokémon, quan un dels\l"
	.string "meus escàners va captar un senyal.\p"
	.string "Sembla que alguns Pokémon poden\n"
	.string "tenir un potencial ocult que encara\l"
	.string "no hem vist.\p"
	.string "I aquest senyal sembla la clau!\p"
	.string "Mira, vaig trobar l'origen del senyal\n"
	.string "a prop de la Cabana del Mar.\p"
	.string "Era una pedra estranya que no havia\n"
	.string "vist mai!\p"
	.string "La vaig portar al laboratori i vaig\n"
	.string "construir un aparell per treure'n\l"
	.string "el poder!\p"
	.string "Vull que el tinguis!$"

PlayersHouse_1F_Text_GetMegaRing::
	.string "Bill t'ha donat un Mega Anell!$"

PlayersHouse_1F_Text_FindMegaStones::
	.string "Segons les meves lectures, hi ha\n"
	.string "més d'aquestes pedres amagades\l"
	.string "per Kanto.\p"
	.string "Ara que tens el Mega Anell,\n"
	.string "les hauríes de poder veure!\p"
	.string "Haurem de trobar una Mega Pedra\n"
	.string "per provar la meva teoria!$"

PlayersHouse_1F_EventScript_Bill2::
	msgbox PlayersHouse_1F_Text_MegaStones, MSGBOX_NPC
	release
	end

PlayersHouse_1F_Text_MegaStones::
	.string "Bill: Haurem de trobar una\n"
	.string "Mega Pedra per provar la teoria!$"

PlayersHouse_1F_Text_Visitor::
	.string "Mare: On vas, {PLAYER}?\p"
	.string "No saludaràs\n"
	.string "la nostra visita?$"

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
	.string "Després de tot el que has fet,\n"
	.string "pensava que necessitaries més repòs.\p"
	.string "...\p"
	.string "Has crescut molt, {PLAYER}.\p"
	.string "Crec que els teus Pokémon també\n"
	.string "ho veuen.\p"
	.string "Et seguiran a qualsevol lloc!$"

PlayersHouse_1F_Text_FollowerOptions::
	.string "L'opció de Seguidor a les Opcions\n"
	.string "ara es pot posar en mode Tots!\p"
	.string "Quan estigui seleccionat, el teu\n"
	.string "primer Pokémon et seguirà!$"

PlayersHouse_1F_Text_Gameclear2::
	.string "Mare: Que siguis el nou campió\n"
	.string "no vol dir que la teva història\l"
	.string "s'hagi acabat!\p"
	.string "Hi ha tot un món per explorar\n"
	.string "per a tu i els teus Pokémon!\p"
	.string "Estic molt orgullosa de tu,\n"
	.string "{PLAYER}!\l"
	.string "Ves a divertir-te amb els Pokémon!$"

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

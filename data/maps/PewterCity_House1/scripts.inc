.set LOCALID_NIDORAN, 3

PewterCity_House1_MapScripts::
	.byte 0

PewterCity_House1_EventScript_BaldingMan::
	msgbox PewterCity_House1_Text_TradeMonsAreFinicky, MSGBOX_NPC
	end

PewterCity_House1_Text_TradeMonsAreFinicky::
    .string "El nostre Pokémon és de fora, així\n"
    .string "que és capritxós i difícil.\p"
    .string "Un Pokémon de fora és un que\n"
    .string "obtens en un intercanvi.\p"
    .string "Creix ràpid, però pot ignorar un\n"
    .string "Entrenador inexpert en combat.\p"
    .string "Si tinguéssim algunes Medalles…$"

PewterCity_House1_EventScript_LittleBoy::
	lock
	msgbox PewterCity_House1_Text_NidoranSit
	call PewterCity_House1_EventScript_DoNidoranCry
	release
	end

PewterCity_House1_EventScript_Nidoran::
	lock
	faceplayer
	call PewterCity_House1_EventScript_DoNidoranCry
	applymovement LOCALID_NIDORAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PewterCity_House1_Text_NidoranSit::
    .string "Nidoran, asseu-te!$"

PewterCity_House1_EventScript_DoNidoranCry::
	waitse
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
	msgbox PewterCity_House1_Text_Nidoran
	waitmoncry
	return

PewterCity_House1_Text_Nidoran::
    .string "Nidoran♂: Baubau!$"

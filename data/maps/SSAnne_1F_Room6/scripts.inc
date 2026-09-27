SSAnne_1F_Room6_MapScripts::
	.byte 0

SSAnne_1F_Room6_EventScript_Woman::
	lock
	faceplayer
	msgbox SSAnne_1F_Room6_Text_TakeAShortRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_DeclineHeal
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed
	release
	end

SSAnne_1F_Room6_Text_TakeAShortRest::
    .string "Sembla que estàs cansat. Vols\n"
    .string "descansar una estona?$"

SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed::
    .string "M'alegro de veure que tothom\n"
    .string "està refrescat i animat.$"

SSAnne_1F_Room6_EventScript_DeclineHeal::
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeSomeone
	release
	end

SSAnne_1F_Room6_Text_SorryYouLookLikeSomeone::
    .string "Oh, perdona per preocupar-me tant.\n"
    .string "Em recordes al meu nét…$"

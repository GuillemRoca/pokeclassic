SSAnne_2F_Room1_MapScripts::
	.byte 0

SSAnne_2F_Room1_EventScript_Gentleman::
	lock
	faceplayer
	message SSAnne_2F_Room1_Text_SleepingMonLookedLikeThis
	waitmessage
	setvar VAR_0x8004, SPECIES_SNORLAX
	special SetSeenMon
	showmonpic SPECIES_SNORLAX, 10, 3
	waitbuttonpress
	hidemonpic
	release
	end

SSAnne_2F_Room1_Text_SleepingMonLookedLikeThis::
    .string "He viatjat per tot arreu, però en\n"
    .string "tots els meus viatges mai he vist\l"
    .string "cap Pokémon dormir com aquest!\p"
    .string "Era una cosa així!$"

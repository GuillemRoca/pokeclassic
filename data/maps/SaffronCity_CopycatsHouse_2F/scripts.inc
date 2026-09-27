SaffronCity_CopycatsHouse_2F_MapScripts::
	.byte 0

SaffronCity_CopycatsHouse_2F_EventScript_Doduo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DODUO, CRY_MODE_NORMAL
	msgbox SaffronCity_CopycatsHouse_2F_Text_Doduo
	waitmoncry
	release
	end

SaffronCity_CopycatsHouse_2F_Text_Doduo::
    .string "Doduo: Giiih!\p"
    .string "Bonic mirall, mira'm,\n"
    .string "mira que bonic que sóc?$"

SaffronCity_CopycatsHouse_2F_EventScript_Doll::
	lock
	msgbox SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll
	release
	end

SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll::
    .string "Això és un Pokémon rar!\n"
    .string "Eh? Només és una nina!$"

SaffronCity_CopycatsHouse_2F_EventScript_Copycat::
	lock
	faceplayer
	checkitem ITEM_POKE_DOLL, 1
	goto_if_eq VAR_RESULT, TRUE, MoveTutor_Mimic
	random 2
	call_if_eq VAR_RESULT, 0, SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale
	call_if_eq VAR_RESULT, 1, SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale
	return

SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale::
    .string "{PLAYER}: Hola!\n"
    .string "T'agraden els Pokémon?\p"
    .string "{PLAYER}: Eh, no, t'ho acabo de\n"
    .string "preguntar jo.\p"
    .string "{PLAYER}: Eh?\n"
    .string "Ets estranya!\p"
    .string "Copiona: Hmm? Que deixi d'imitar?\n"
    .string "Però si és la meva afició!$"

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale
	return

SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale::
    .string "{PLAYER}: Hola.\n"
    .string "T'han d'agradar els Pokémon.\p"
    .string "{PLAYER}: No, jo no.\n"
    .string "T'ho he preguntat jo.\p"
    .string "{PLAYER}: Com?\n"
    .string "Ets rara!\l"
    .string " \l"
    .string "Copiona: Hmm? Que deixi d'imitar?\l"
    .string "Però si és la meva afició!$"

SaffronCity_CopycatsHouse_2F_EventScript_Computer::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MySecrets, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_Text_MySecrets::
    .string "…\p"
    .string "Els Meus Secrets!\p"
    .string "Habilitat: Imitació!\n"
    .string "Afició: Col·leccionar nines!\l"
    .string "Pokémon Favorit: Clefairy!$"

SaffronCity_CopycatsHouse_2F_EventScript_Game::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket::
    .string "Un joc amb Mario portant una\n"
    .string "galleda al cap!$"

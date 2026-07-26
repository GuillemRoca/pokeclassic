.set LOCALID_CHAIRMAN, 1
.set LOCALID_WOMAN,   3
.set LOCALID_FAT_MAN, 4

VermilionCity_PokemonFanClub_MapScripts::
	.byte 0

VermilionCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BIKE_VOUCHER, VermilionCity_PokemonFanClub_EventScript_AlreadyHeardStory
	msgbox VermilionCity_PokemonFanClub_Text_DidYouComeToHearAboutMyMons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VermilionCity_PokemonFanClub_EventScript_ChairmanStory
	msgbox VermilionCity_PokemonFanClub_Text_ComeBackToHearStory
	release
	end

VermilionCity_PokemonFanClub_EventScript_AlreadyHeardStory::
	msgbox VermilionCity_PokemonFanClub_Text_DidntComeToSeeAboutMonsAgain
	call_if_unset FLAG_DAILY_FANCLUB_REWARD, VermilionCity_PokemonFanClub_DailyReward
	release
	end

VermilionCity_PokemonFanClub_Text_DidntComeToSeeAboutMonsAgain::
    .string "Hola, {PLAYER}!\p"

    .string "Has vingut a veure'm pels meus\n"

    .string "Pokémon, una altra vegada?\p"

    .string "No?\n"

    .string "Quina llàstima!$"


VermilionCity_PokemonFanClub_DailyReward::
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_lt VAR_RESULT, 4, Common_EventScript_Return
	checkitemspace ITEM_RARE_CANDY, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_Return
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	playse SE_PIN
	applymovement LOCALID_CHAIRMAN, Common_Movement_Heart
	waitse
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	msgbox VermilionCity_PokemonFanClub_Text_TruePokeFan, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY, 1
	setflag FLAG_DAILY_FANCLUB_REWARD
	return

VermilionCity_PokemonFanClub_Text_TruePokeFan::
	.string "Puc veure que tens molta cura\n"

	.string "dels teus Pokémon!\p"

	.string "Ets un autèntic PokéFan!\p"

	.string "Si us plau, pren això i\n"

	.string "comparteix-ho amb els teus\l"

	.string "Pokémon!$"


VermilionCity_PokemonFanClub_Text_DidYouComeToHearAboutMyMons::
    .string "Presideixo el Club de Fans Pokémon!\p"

    .string "Crio més de cent Pokémon!\p"

    .string "Sóc molt exigent quan es tracta\n"

    .string "de Pokémon! De debò que sí!\p"

    .string "Així que…\p"

    .string "Has vingut a escoltar coses sobre\n"

    .string "els meus Pokémon?$"


VermilionCity_PokemonFanClub_Text_ComeBackToHearStory::
    .string "Oh. Torna quan vulguis escoltar\n"

    .string "la meva història!$"


VermilionCity_PokemonFanClub_EventScript_ChairmanStory::
	msgbox VermilionCity_PokemonFanClub_Text_ChairmansStory
	checkitemspace ITEM_BIKE_VOUCHER, 1
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_PokemonFanClub_EventScript_NoRoomForBikeVoucher
	setflag FLAG_GOT_BIKE_VOUCHER
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox VermilionCity_PokemonFanClub_Text_ReceivedBikeVoucherFromChairman, MSGBOX_DEFAULT
	additem ITEM_BIKE_VOUCHER, 1
	waitfanfare
	msgbox VermilionCity_PokemonFanClub_Text_ExplainBikeVoucher
	release
	end

VermilionCity_PokemonFanClub_Text_ChairmansStory::
    .string "Bé!\n"

    .string "Doncs escolta!\p"

    .string "El meu Rapidash favorit…\p"

    .string "És…bufó…adorable…llest…\n"

    .string "a més…increïble…no creus?…\l"

    .string "oh sí…és…impressionant…\l"

    .string "amable…l'estimo!\p"

    .string "Abraçar-lo…quan dorm…calent\n"

    .string "i tendre…espectacular…\l"

    .string "fascinant…\l"

    .string "…Vaja! Mira quina hora és!\l"

    .string "T'he entretingut massa!\p"

    .string "Gràcies per escoltar-me!\n"

    .string "Vull que tinguis això!$"


VermilionCity_PokemonFanClub_EventScript_NoRoomForBikeVoucher::
	msgbox VermilionCity_PokemonFanClub_Text_MakeRoomForThis
	release
	end

VermilionCity_PokemonFanClub_Text_MakeRoomForThis::
    .string "Fes espai per a això!$"


VermilionCity_PokemonFanClub_Text_ReceivedBikeVoucherFromChairman::
    .string "{PLAYER} ha rebut un Val de Bici\n"

    .string "del President.$"


VermilionCity_PokemonFanClub_Text_ExplainBikeVoucher::
    .string "Porta el Val de Bici a la\n"

    .string "Botiga de Bicis de Cerulean.\p"

    .string "Canvia'l per una Bicicleta\n"

    .string "totalment gratis!\p"

    .string "No et preocupis, el meu Fearow\n"

    .string "favorit em porta volant on calgui.\p"

    .string "Així que no necessito cap\n"

    .string "Bicicleta.\p"

    .string "Espero que t'agradi anar en bici!$"


VermilionCity_PokemonFanClub_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, VermilionCity_PokemonFanClub_EventScript_WorkerFGameClear
	msgbox VermilionCity_PokemonFanClub_Text_ChairmanVeryVocalAboutPokemon
	release
	end

VermilionCity_PokemonFanClub_EventScript_WorkerFGameClear::
	msgbox VermilionCity_PokemonFanClub_Text_ChairmanReallyAdoresHisMons
	release
	end

VermilionCity_PokemonFanClub_Text_ChairmanReallyAdoresHisMons::
    .string "El nostre President de debò que\n"

    .string "adora els seus Pokémon.\p"

    .string "Però la persona que més agrada\n"

    .string "als Pokémon és la Daisy, crec.$"


VermilionCity_PokemonFanClub_Text_ChairmanVeryVocalAboutPokemon::
    .string "El nostre President és molt\n"

    .string "entusiasta amb els Pokémon.$"


VermilionCity_PokemonFanClub_EventScript_Woman::
	lock
	faceplayer
	goto_if_eq VAR_TEMP_1, 2, VermilionCity_PokemonFanClub_EventScript_WomanSpokeToFatMan
	msgbox VermilionCity_PokemonFanClub_Text_AdoreMySeel
	closemessage
	applymovement LOCALID_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_TEMP_1, 1
	release
	end

VermilionCity_PokemonFanClub_Text_AdoreMySeel::
    .string "Adoro el meu Seel!\n"

    .string "És tan adorable!\p"

    .string "Fa “Kyuuuh” quan\n"

    .string "l'abraço!$"


VermilionCity_PokemonFanClub_EventScript_WomanSpokeToFatMan::
	msgbox VermilionCity_PokemonFanClub_Text_SeelFarMoreAttractive
	closemessage
	applymovement LOCALID_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_TEMP_1, 0
	release
	end

VermilionCity_PokemonFanClub_Text_SeelFarMoreAttractive::
    .string "Oh, mare!\p"

    .string "El meu Seel és molt més atractiu.\n"

    .string "El doble, diria jo.$"


VermilionCity_PokemonFanClub_EventScript_FatMan::
	lock
	faceplayer
	goto_if_eq VAR_TEMP_1, 1, VermilionCity_PokemonFanClub_EventScript_FatManSpokeToWoman
	msgbox VermilionCity_PokemonFanClub_Text_AdmirePikachusTail
	closemessage
	applymovement LOCALID_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_TEMP_1, 2
	release
	end

VermilionCity_PokemonFanClub_Text_AdmirePikachusTail::
    .string "No vols admirar l'adorable cua\n"

    .string "del meu Pikachu?$"


VermilionCity_PokemonFanClub_EventScript_FatManSpokeToWoman::
	msgbox VermilionCity_PokemonFanClub_Text_PikachuTwiceAsCute
	closemessage
	applymovement LOCALID_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_TEMP_1, 0
	release
	end

VermilionCity_PokemonFanClub_Text_PikachuTwiceAsCute::
    .string "Bah!\p"

    .string "El meu Pikachu és el doble de\n"

    .string "bufó que aquell!$"


VermilionCity_PokemonFanClub_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VermilionCity_PokemonFanClub_Text_Pikachu
	waitmoncry
	release
	end

VermilionCity_PokemonFanClub_Text_Pikachu::
    .string "Pikachu: Chu! Pikachu!$"


VermilionCity_PokemonFanClub_EventScript_Seel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SEEL, CRY_MODE_NORMAL
	msgbox VermilionCity_PokemonFanClub_Text_Seel
	waitmoncry
	release
	end

VermilionCity_PokemonFanClub_Text_Seel::
    .string "Seel: Kyuoo!$"


VermilionCity_PokemonFanClub_EventScript_RulesSign1::
	msgbox VermilionCity_PokemonFanClub_Text_ListenPolitelyToOtherTrainers, MSGBOX_SIGN
	end

VermilionCity_PokemonFanClub_Text_ListenPolitelyToOtherTrainers::
    .string "Escoltem educadament els altres\n"

    .string "entrenadors!$"


VermilionCity_PokemonFanClub_EventScript_RulesSign2::
	msgbox VermilionCity_PokemonFanClub_Text_SomeoneBragsBragBack, MSGBOX_SIGN
	end

VermilionCity_PokemonFanClub_Text_SomeoneBragsBragBack::
    .string "Si algú presumeix, presumeix tu\n"

    .string "també!$"


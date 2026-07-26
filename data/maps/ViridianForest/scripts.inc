ViridianForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ViridianForest_OnResume
	.byte 0

ViridianForest_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

ViridianForest_OnResume:
	call Common_EventScript_GetDayOrNight
	end

ViridianForest_EventScript_Youngster::
	msgbox ViridianForest_Text_FriendsItchingToBattle, MSGBOX_NPC
	end

ViridianForest_Text_FriendsItchingToBattle::
    .string "He vingut aquí amb uns amics per\n"
    .string "atrapar Pokémon Insecte!\p"
    .string "Tots estan desitjant fer\n"
    .string "combats Pokémon!$"

ViridianForest_EventScript_Boy::
	msgbox ViridianForest_Text_RanOutOfPokeBalls, MSGBOX_NPC
	end

ViridianForest_Text_RanOutOfPokeBalls::
    .string "Estava llançant Poké Balls per\n"
    .string "atrapar Pokémon, i se m'han\l"
    .string "acabat.\p"
    .string "Per això mai no pots tenir\n"
    .string "massa Poké Balls.$"

ViridianForest_EventScript_Rick::
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, ViridianForest_Text_RickIntro, ViridianForest_Text_RickDefeat
	msgbox ViridianForest_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_RickIntro::
    .string "Ei! Tens Pokémon!\n"
    .string "Va!\l"
    .string "Lluitem!$"

ViridianForest_Text_RickDefeat::
    .string "No!\nEl Caterpie no ha pogut!$"

ViridianForest_Text_RickPostBattle::
    .string "Xut! Espantaràs els insectes.\n"
    .string "Un altre cop, d'acord?$"

ViridianForest_EventScript_Doug::
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat
	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_DougIntro::
    .string "Ei!\n"
    .string "No pots escaquejar-te si ets\l"
    .string "Entrenador Pokémon!$"

ViridianForest_Text_DougDefeat::
    .string "Eh?\n"
    .string "Se m'han acabat els Pokémon!$"

ViridianForest_Text_DougPostBattle::
    .string "Quina ràbia! Aniré a atrapar-ne\n"
    .string "de més forts!$"


ViridianForest_EventScript_Sammy::
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_SammyIntro::
    .string "Ei, espera!\n"
    .string "Quina pressa! Per què corres?$"

ViridianForest_Text_SammyDefeat::
    .string "Em renyo!\n"
    .string "Ets bo en això!$"

ViridianForest_Text_SammyPostBattle::
    .string "A vegades, pots trobar coses\n"
    .string "al terra.\p"
    .string "Estic buscant el que se m'ha\n"
    .string "caigut. Em pots ajudar?$"

ViridianForest_EventScript_Anthony::
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonyIntro, ViridianForest_Text_AnthonyDefeat
	msgbox ViridianForest_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_AnthonyIntro::
    .string "Potser sóc petit, però no\n"
    .string "m'agradarà si et contens!$"

ViridianForest_Text_AnthonyDefeat::
    .string "Oh, vaja.\n"
    .string "Res no ha sortit bé.$"

ViridianForest_Text_AnthonyPostBattle::
    .string "He perdut part de la meva paga…$"

ViridianForest_EventScript_Charlie::
	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieIntro, ViridianForest_Text_CharlieDefeat
	msgbox ViridianForest_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_CharlieIntro::
    .string "Sabies que els Pokémon evolucionen?$"

ViridianForest_Text_CharlieDefeat::
    .string "Oh!\n"
    .string "He perdut!$"

ViridianForest_Text_CharliePostBattle::
    .string "Els Pokémon Insecte evolucionen\n"
    .string "ràpid. Són molt divertits!$"


ViridianForest_EventScript_TrainerTips1::
	msgbox ViridianForest_Text_AvoidGrassyAreasWhenWeak, MSGBOX_SIGN
	end

ViridianForest_Text_AvoidGrassyAreasWhenWeak::
    .string "Consells d'Entrenador:\p"
    .string "Si els teus Pokémon estan febles\n"
    .string "i vols evitar combats, allunya't\l"
    .string "de les zones d'herba!$"

ViridianForest_EventScript_TrainerTips2::
	msgbox ViridianForest_Text_UseAntidoteForPoison, MSGBOX_SIGN
	end

ViridianForest_Text_UseAntidoteForPoison::
    .string "Consells d'Entrenador:\p"
    .string "Contra el verí, usa Antídot!\n"
    .string "Compra'ls a la Botiga Pokémon!$"

ViridianForest_EventScript_TrainerTips3::
	msgbox ViridianForest_Text_ContactOakViaPCToRatePokedex, MSGBOX_SIGN
	end

ViridianForest_Text_ContactOakViaPCToRatePokedex::
    .string "Consells d'Entrenador:\p"
    .string "Pots trucar al Prof. Oak amb\n"
    .string "el teu Mòbil per avaluar la\l"
    .string "teva Pokédex!$"

ViridianForest_EventScript_TrainerTips4::
	msgbox ViridianForest_Text_CantCatchOwnedMons, MSGBOX_SIGN
	end

ViridianForest_Text_CantCatchOwnedMons::
    .string "Consells d'Entrenador:\p"
    .string "No pots atrapar un Pokémon que\n"
    .string "pertanyi a algú altre.\p"
    .string "Llança Poké Balls només a\n"
    .string "Pokémon salvatges per atrapar-los!$"

ViridianForest_EventScript_TrainerTips5::
	msgbox ViridianForest_Text_WeakenMonsBeforeCapture, MSGBOX_SIGN
	end

ViridianForest_Text_WeakenMonsBeforeCapture::
    .string "Consells d'Entrenador:\p"
    .string "Debilita els Pokémon abans\n"
    .string "d'intentar atrapar-los!\p"
    .string "Quan estan sans, poden escapar!$"

ViridianForest_EventScript_ExitSign::
	msgbox ViridianForest_Text_LeavingViridianForest, MSGBOX_SIGN
	end

ViridianForest_Text_LeavingViridianForest::
    .string "Sortida del Bosc Viridian\n"
    .string "Ciutat Pewter Endavant$"

ViridianForest_EventScript_ItemPotion::
	finditem ITEM_POTION, 1
	end

ViridianForest_EventScript_ItemPotion2::
	finditem ITEM_POTION, 1
	end

ViridianForest_EventScript_ItemAntidote::
	finditem ITEM_ANTIDOTE, 1
	end

ViridianForest_EventScript_ItemPokeBall::
	finditem ITEM_POKE_BALL, 1
	end

ViridianForest_EventScript_Beedrillite::
    finditem ITEM_BEEDRILLITE, 1
    end

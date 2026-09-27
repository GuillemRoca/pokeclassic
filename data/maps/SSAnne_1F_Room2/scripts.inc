SSAnne_1F_Room2_MapScripts::
	.byte 0

SSAnne_1F_Room2_EventScript_Woman::
	msgbox SSAnne_1F_Room2_Text_CruisingAroundWorld, MSGBOX_NPC
	end

SSAnne_1F_Room2_Text_CruisingAroundWorld::
    .string "Estem fent un creuer pel món,\n"
    .string "els meus fills i jo.$"


SSAnne_1F_Room2_EventScript_Ann::
	trainerbattle_single TRAINER_LASS_ANN, SSAnne_1F_Room2_Text_AnnIntro, SSAnne_1F_Room2_Text_AnnDefeat
	msgbox SSAnne_1F_Room2_Text_AnnPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_Text_AnnIntro::
    .string "He col·leccionat aquests Pokémon\n"
    .string "d'arreu del món!$"

SSAnne_1F_Room2_Text_AnnDefeat::
    .string "Oh, no!\n"
    .string "He viatjat pel món per tenir-los!$"

SSAnne_1F_Room2_Text_AnnPostBattle::
    .string "Has fet mal als meus Pokémon!\p"
    .string "Exigeixo que els curis a un\n"
    .string "Centre Pokémon!$"


SSAnne_1F_Room2_EventScript_Tyler::
	trainerbattle_single TRAINER_YOUNGSTER_TYLER, SSAnne_1F_Room2_Text_TylerIntro, SSAnne_1F_Room2_Text_TylerDefeat
	msgbox SSAnne_1F_Room2_Text_TylerPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_Text_TylerIntro::
    .string "M'encanten els Pokémon!\n"
    .string "A tu també?$"

SSAnne_1F_Room2_Text_TylerDefeat::
    .string "Uau! \n"
    .string "Ets genial!$"

SSAnne_1F_Room2_Text_TylerPostBattle::
    .string "Escolta, escolta!\n"
    .string "Deixa'm ser el teu amic, va?\p"
    .string "Així podrem intercanviar Pokémon\n"
    .string "i fer coses.$"

SSAnne_1F_Room2_EventScript_ItemTM31::
    finditem ITEM_TM31, 1
    release
    end


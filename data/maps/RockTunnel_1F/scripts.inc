RockTunnel_1F_MapScripts::
	.byte 0

RockTunnel_1F_EventScript_RouteSign::
	msgbox RockTunnel_1F_Text_RouteSign, MSGBOX_SIGN
	end

RockTunnel_1F_EventScript_Lenny::
	trainerbattle_single TRAINER_HIKER_LENNY, RockTunnel_1F_Text_LennyIntro, RockTunnel_1F_Text_LennyDefeat
	msgbox RockTunnel_1F_Text_LennyPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_LennyIntro::
    .string "Aquest túnel és molt llarg, nen!$"

RockTunnel_1F_Text_LennyDefeat::
    .string "Doh!\n"
    .string "Has guanyat!$"

RockTunnel_1F_Text_LennyPostBattle::
    .string "Vigila amb els Onix.\n"
    .string "Apareixen de tant en tant.\p"
    .string "Els de nivell alt et poden\n"
    .string "estrènyer ben fort!$"

RockTunnel_1F_EventScript_Oliver::
	trainerbattle_single TRAINER_HIKER_OLIVER, RockTunnel_1F_Text_OliverIntro, RockTunnel_1F_Text_OliverDefeat
	msgbox RockTunnel_1F_Text_OliverPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_OliverIntro::
    .string "Hmm.\n"
    .string "Potser m'he perdut aquí dins…$"

RockTunnel_1F_Text_OliverDefeat::
    .string "Calma!\n"
    .string "Què estic fent?\l"
    .string "Per on se surt?$"

RockTunnel_1F_Text_OliverPostBattle::
    .string "Aquell Pokémon dormint a la Ruta\n"
    .string "12 m'ha obligat a fer aquest\l"
    .string "desviament.$"

RockTunnel_1F_EventScript_Lucas::
	trainerbattle_single TRAINER_HIKER_LUCAS, RockTunnel_1F_Text_LucasIntro, RockTunnel_1F_Text_LucasDefeat
	msgbox RockTunnel_1F_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_LucasIntro::
    .string "Els forasters com tu m'han de\n"
    .string "mostrar respecte!$"

RockTunnel_1F_Text_LucasDefeat::
    .string "Em rendeixo!$"

RockTunnel_1F_Text_LucasPostBattle::
    .string "Tens prou talent per fer rutes!$"

RockTunnel_1F_EventScript_Ashton::
	trainerbattle_single TRAINER_POKEMANIAC_ASHTON, RockTunnel_1F_Text_AshtonIntro, RockTunnel_1F_Text_AshtonDefeat
	msgbox RockTunnel_1F_Text_AshtonPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_AshtonIntro::
    .string "Combat Pokémon!\n"
    .string "Preparats, ja!$"

RockTunnel_1F_Text_AshtonDefeat::
    .string "Fi del joc!$"

RockTunnel_1F_Text_AshtonPostBattle::
    .string "Bah, atraparé un Zubat pel camí!$"

RockTunnel_1F_EventScript_Leah::
	trainerbattle_single TRAINER_PICNICKER_LEAH, RockTunnel_1F_Text_LeahIntro, RockTunnel_1F_Text_LeahDefeat
	msgbox RockTunnel_1F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_LeahIntro::
    .string "Iii!\p"
    .string "No intentis res estrany a\n"
    .string "la foscor!$"

RockTunnel_1F_Text_LeahDefeat::
    .string "Feia massa fosc…$"

RockTunnel_1F_Text_LeahPostBattle::
    .string "He vist un Machop en aquest túnel.$"

RockTunnel_1F_EventScript_Ariana::
	trainerbattle_single TRAINER_PICNICKER_ARIANA, RockTunnel_1F_Text_ArianaIntro, RockTunnel_1F_Text_ArianaDefeat
	msgbox RockTunnel_1F_Text_ArianaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_ArianaIntro::
    .string "Tens Pokémon!\n"
    .string "Comencem!$"

RockTunnel_1F_Text_ArianaDefeat::
    .string "Jugues dur!$"

RockTunnel_1F_Text_ArianaPostBattle::
    .string "Uf!\n"
    .string "Estic tota suada.$"

RockTunnel_1F_EventScript_Dana::
	trainerbattle_single TRAINER_PICNICKER_DANA, RockTunnel_1F_Text_DanaIntro, RockTunnel_1F_Text_DanaDefeat
	msgbox RockTunnel_1F_Text_DanaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_DanaIntro::
    .string "He arribat fins aquí buscant\n"
    .string "Pokémon salvatges.$"

RockTunnel_1F_Text_DanaDefeat::
    .string "No em queden Pokémon!$"

RockTunnel_1F_Text_DanaPostBattle::
    .string "Semblaves bufó i inofensiu.\n"
    .string "Quina equivocació!$"

RockTunnel_1F_Text_RouteSign::
    .string "Túnel Roca\n"
    .string "Ciutat Celeste - Poble Lavanda$"

RockTunnel_1F_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE, 1
	release
	end

RockTunnel_1F_EventScript_ItemPearl::
	finditem ITEM_PEARL, 1
	release
	end

RockTunnel_1F_EventScript_ItemRepel::
	finditem ITEM_REPEL, 1
	release
	end

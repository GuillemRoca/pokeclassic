RockTunnel_B1F_MapScripts::
	.byte 0

RockTunnel_B1F_EventScript_ItemRevive::
	finditem ITEM_REVIVE, 1
	release
	end

RockTunnel_B1F_EventScript_ItemPowerStone::
    finditem ITEM_POWER_STONE, 1
    release
    end

RockTunnel_B1F_EventScript_ItemMaxEther::
	finditem ITEM_MAX_ETHER, 1
	release
	end

RockTunnel_B1F_EventScript_Aerodactlyite::
    finditem ITEM_AERODACTYLITE, 1
    release
    end

RockTunnel_B1F_EventScript_Sofia::
	trainerbattle_single TRAINER_PICNICKER_SOFIA, RockTunnel_B1F_Text_SofiaIntro, RockTunnel_B1F_Text_SofiaDefeat
	msgbox RockTunnel_B1F_Text_SofiaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_SofiaIntro::
    .string "Saps com evitar perdre't\n"
    .string "a la muntanya?\p"
    .string "Pots doblegar branques com a\n"
    .string "marques del camí.$"

RockTunnel_B1F_Text_SofiaDefeat::
    .string "Ohhh!\n"
    .string "Ho he donat tot!$"

RockTunnel_B1F_Text_SofiaPostBattle::
    .string "Vull tornar a casa!$"

RockTunnel_B1F_EventScript_Martha::
	trainerbattle_single TRAINER_PICNICKER_MARTHA, RockTunnel_B1F_Text_MarthaIntro, RockTunnel_B1F_Text_MarthaDefeat
	msgbox RockTunnel_B1F_Text_MarthaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_MarthaIntro::
    .string "No vinc sovint per aquí, però\n"
    .string "combatré amb tu.$"

RockTunnel_B1F_Text_MarthaDefeat::
    .string "Oh!\n"
    .string "He perdut!$"

RockTunnel_B1F_Text_MarthaPostBattle::
    .string "M'agraden els Pokémon petits.\n"
    .string "Els grans fan massa por!$"

RockTunnel_B1F_EventScript_Dudley::
	trainerbattle_single TRAINER_HIKER_DUDLEY, RockTunnel_B1F_Text_DudleyIntro, RockTunnel_B1F_Text_DudleyDefeat
	msgbox RockTunnel_B1F_Text_DudleyPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_DudleyIntro::
    .string "Hahaha!\n"
    .string "Pots superar el meu poder?$"

RockTunnel_B1F_Text_DudleyDefeat::
    .string "Ups!\n"
    .string "Superat en força!$"

RockTunnel_B1F_Text_DudleyPostBattle::
    .string "Prefereixo la força perquè\n"
    .string "odio pensar.$"

RockTunnel_B1F_EventScript_Allen::
	trainerbattle_single TRAINER_HIKER_ALLEN, RockTunnel_B1F_Text_AllenIntro, RockTunnel_B1F_Text_AllenDefeat
	msgbox RockTunnel_B1F_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_AllenIntro::
    .string "Les meves tècniques Pokémon\n"
    .string "et faran plorar!$"

RockTunnel_B1F_Text_AllenDefeat::
    .string "Em rendeixo!\n"
    .string "Ets millor tècnic!$"

RockTunnel_B1F_Text_AllenPostBattle::
    .string "A les muntanyes sovint trobaràs\n"
    .string "Pokémon de tipus Roca.$"

RockTunnel_B1F_EventScript_Eric::
	trainerbattle_single TRAINER_HIKER_ERIC, RockTunnel_B1F_Text_EricIntro, RockTunnel_B1F_Text_EricDefeat
	msgbox RockTunnel_B1F_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_EricIntro::
    .string "Dona'm tot el que tens!$"

RockTunnel_B1F_Text_EricDefeat::
    .string "Endavant!$"

RockTunnel_B1F_Text_EricPostBattle::
    .string "Criaré els meus Pokémon per\n"
    .string "guanyar els teus, nen.$"

RockTunnel_B1F_EventScript_Cooper::
	trainerbattle_single TRAINER_POKEMANIAC_COOPER, RockTunnel_B1F_Text_CooperIntro, RockTunnel_B1F_Text_CooperDefeat
	msgbox RockTunnel_B1F_Text_CooperPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_CooperIntro::
    .string "Tens una Pokédex?\n"
    .string "Jo també en vull una.$"

RockTunnel_B1F_Text_CooperDefeat::
    .string "Caram!\n"
    .string "Quina enveja!$"

RockTunnel_B1F_Text_CooperPostBattle::
    .string "Quan acabis la teva Pokédex,\n"
    .string "me la pots donar?$"

RockTunnel_B1F_EventScript_Steve::
	trainerbattle_single TRAINER_POKEMANIAC_STEVE, RockTunnel_B1F_Text_SteveIntro, RockTunnel_B1F_Text_SteveDefeat
	msgbox RockTunnel_B1F_Text_StevePostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_SteveIntro::
    .string "Mmm… Saps sobre el cosplay\n"
    .string "Pokémon?$"

RockTunnel_B1F_Text_SteveDefeat::
    .string "Bé, és el que hi ha.$"

RockTunnel_B1F_Text_StevePostBattle::
    .string "El cosplay Pokémon és disfressar-se\n"
    .string "de Pokémon per diversió.\p"
    .string "Clefairy és un dels favorits.$"

RockTunnel_B1F_EventScript_Winston::
	trainerbattle_single TRAINER_POKEMANIAC_WINSTON, RockTunnel_B1F_Text_WinstonIntro, RockTunnel_B1F_Text_WinstonDefeat
	msgbox RockTunnel_B1F_Text_WinstonPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_WinstonIntro::
    .string "Dibuixo il·lustracions de Pokémon\n"
    .string "quan soc a casa.$"

RockTunnel_B1F_Text_WinstonDefeat::
    .string "Uf…\n"
    .string "Estic esgotat…$"

RockTunnel_B1F_Text_WinstonPostBattle::
    .string "Soc artista, no lluitador.\n"
    .string "Me'n vaig a casa a dibuixar.$"

RockTunnel_B1F_EventScript_HelmetGuy::
    lock
    goto_if_set FLAG_GOT_ROCKY_HELMET, RockTunnel_B1F_EventScript_HelmetGuy2
    msgbox RockTunnel_B1F_Text_Helmet, MSGBOX_NPC
    giveitem ITEM_ROCKY_HELMET, 1
    setflag FLAG_GOT_ROCKY_HELMET
    release
    end

RockTunnel_B1F_Text_Helmet::
    .string "Estava explorant el túnel quan\n"
    .string "un Geodude va usar Autodestrucció!\p"
    .string "Va causar un petit esfondrament.\n"
    .string "Sort que portava casc.\p"
    .string "Aquí tens, tu també n'hauries\n"
    .string "de portar un!$"

RockTunnel_B1F_EventScript_HelmetGuy2::
    lock
    msgbox RockTunnel_B1F_Text_Helmet2, MSGBOX_NPC
    release
    end

RockTunnel_B1F_Text_Helmet2::
    .string "De vegades, les roques contenen\n"
    .string "objectes. Però també podrien\l"
    .string "contenir Pokémon!$"

.set LOCALID_NURSE, 1
.set LOCALID_LOOKER, 5

CeladonCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_PokemonCenter_1F_OnTransition
	.byte 0

CeladonCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_CELADON_CITY
	end

CeladonCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

CeladonCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox CeladonCity_PokemonCenter_1F_Text_PokeFluteAwakensSleepingMons, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_1F_Text_PokeFluteAwakensSleepingMons::
    .string "La Poké Flauta desperta els\n"
    .string "Pokémon adormits. Ja ho saps.\p"
    .string "Ho fa amb un so que només\n"
    .string "ells poden sentir.$"

CeladonCity_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox CeladonCity_PokemonCenter_1F_Text_RodeHereFromFuchsia, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_1F_Text_RodeHereFromFuchsia::
    .string "He vingut des de Fuchsia.\p"
    .string "El Camí Ciclista és pujada,\n"
    .string "així que estic esgotada.$"

CeladonCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox CeladonCity_PokemonCenter_1F_Text_GoToCyclingRoadIfIHadBike, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_1F_Text_GoToCyclingRoadIfIHadBike::
    .string "Si tingués una Bici, aniria al\n"
    .string "Camí Ciclista!$"

CeladonCity_Looker::
	lock
	faceplayer
	goto_if_unset FLAG_LOOKER_EXPLAINED_QUESTS, CeladonCity_Looker_ExplainDaily
	goto_if_set FLAG_LOOKER_ASSIGNMENT_ACTIVE, Looker_CheckStatus
	goto_if_set FLAG_ROCKET_FUGITIVE_CAPTURED, Looker_DailyCompleted
	playse SE_POKENAV_CALL
	waitse
	playse SE_PIN
	applymovement LOCALID_LOOKER, Common_Movement_ExclamationMark
	waitse
	turnobject LOCALID_LOOKER, DIR_NORTH
	msgbox Looker_Text_PhoneCall, MSGBOX_NPC
	waitmessage
	playse SE_CLICK
	waitse
	call_if_eq VAR_FACING, DIR_EAST, Looker_FaceLeft
	call_if_eq VAR_FACING, DIR_WEST, Looker_FaceRight
	call_if_eq VAR_FACING, DIR_NORTH, Looker_FaceDown
	random 9
	goto_if_eq VAR_RESULT, 9, Looker_Fugitive_Saffron
	goto_if_eq VAR_RESULT, 8, Looker_Fugitive_Cinnabar
	goto_if_eq VAR_RESULT, 7, Looker_Fugitive_Fuchsia
	goto_if_eq VAR_RESULT, 6, Looker_Fugitive_Celadon
	goto_if_eq VAR_RESULT, 5, Looker_Fugitive_Vermilion
	goto_if_eq VAR_RESULT, 4, Looker_Fugitive_Lavender
	goto_if_eq VAR_RESULT, 3, Looker_Fugitive_Cerulean
	goto_if_eq VAR_RESULT, 2, Looker_Fugitive_Pewter
	goto_if_eq VAR_RESULT, 1, Looker_Fugitive_Viridian
	goto_if_eq VAR_RESULT, 0, Looker_Fugitive_Pallet
	end

Looker_Fugitive_Saffron::
	msgbox Looker_Text_SaffronCity, MSGBOX_NPC
	goto SetFugitive_Saffron
	end

SetFugitive_Saffron::
	random 3
	goto_if_eq VAR_RESULT, 3, Saffron_Fugitive_4
	goto_if_eq VAR_RESULT, 2, Saffron_Fugitive_3
	goto_if_eq VAR_RESULT, 1, Saffron_Fugitive_2
	goto_if_eq VAR_RESULT, 0, Saffron_Fugitive_1
	end

Saffron_Fugitive_4::
	clearflag FLAG_ROCKET_FUGITIVE_SAFFRON_4
	goto Looker_QuestBegin
	end

Saffron_Fugitive_3::
	clearflag FLAG_ROCKET_FUGITIVE_SAFFRON_3
	goto Looker_QuestBegin
	end

Saffron_Fugitive_2::
	clearflag FLAG_ROCKET_FUGITIVE_SAFFRON_2
	goto Looker_QuestBegin
	end

Saffron_Fugitive_1::
	clearflag FLAG_ROCKET_FUGITIVE_SAFFRON_1
	goto Looker_QuestBegin
	end

Looker_Text_SaffronCity::
	.string "Males notícies, {PLAYER}.\p"
	.string "Era la central.\p"
	.string "Hi ha informes d'un altre fugitiu\n"
	.string "Rocket a Kanto.\p"
	.string "La intel·ligència suggereix que\n"
	.string "és a prop de Ciutat Safrà.\p"
	.string "Enviaré el meu equip, però si\n"
	.string "ets per la zona, t'agrairia\l"
	.string "que ens ajudessis.$"

Looker_Fugitive_Cinnabar::
	msgbox Looker_Text_CinnabarIsland, MSGBOX_NPC
	call SetFugitive_Cinnabar
	release
	end

SetFugitive_Cinnabar::
	random 1
	goto_if_eq VAR_RESULT, 1, Cinnabar_Fugitive_2
	goto_if_eq VAR_RESULT, 0, Cinnabar_Fugitive_1
	end

Cinnabar_Fugitive_2::
	clearflag FLAG_ROCKET_FUGITIVE_CINNABAR_2
	goto Looker_QuestBegin
	end

Cinnabar_Fugitive_1::
	clearflag FLAG_ROCKET_FUGITIVE_CINNABAR_1
	goto Looker_QuestBegin
	end

Looker_Text_CinnabarIsland::
	.string "Males notícies, {PLAYER}.\p"
	.string "Era la central.\p"
	.string "Hi ha informes d'un altre fugitiu\n"
	.string "Rocket a Kanto.\p"
	.string "La intel·ligència suggereix que\n"
	.string "és a prop d'Illa Cinnabar.\p"
	.string "Enviaré el meu equip, però si\n"
	.string "ets per la zona, t'agrairia\l"
	.string "que ens ajudessis.$"

Looker_Fugitive_Fuchsia::
	msgbox Looker_Text_FuchsiaCity, MSGBOX_NPC
	call SetFugitive_Fuchsia
	release
	end

SetFugitive_Fuchsia::
	random 2
	goto_if_eq VAR_RESULT, 2, Fuchsia_Fugitive_3
	goto_if_eq VAR_RESULT, 1, Fuchsia_Fugitive_2
	goto_if_eq VAR_RESULT, 0, Fuchsia_Fugitive_1
	end

Fuchsia_Fugitive_3::
	clearflag FLAG_ROCKET_FUGITIVE_FUCHSIA_3
	goto Looker_QuestBegin
	end

Fuchsia_Fugitive_2::
	clearflag FLAG_ROCKET_FUGITIVE_FUCHSIA_2
	goto Looker_QuestBegin
	end

Fuchsia_Fugitive_1::
	clearflag FLAG_ROCKET_FUGITIVE_FUCHSIA_1
	goto Looker_QuestBegin
	end

Looker_Text_FuchsiaCity::
	.string "Males notícies, {PLAYER}.\p"
	.string "Era la central.\p"
	.string "Hi ha informes d'un altre fugitiu\n"
	.string "Rocket a Kanto.\p"
	.string "La intel·ligència suggereix que\n"
	.string "és a prop de Ciutat Fúcsia.\p"
	.string "Enviaré el meu equip, però si\n"
	.string "ets per la zona, t'agrairia\l"
	.string "que ens ajudessis.$"

Looker_Fugitive_Celadon::
	msgbox Looker_Text_CeladonCity, MSGBOX_NPC
	call SetFugitive_Celadon
	release
	end

SetFugitive_Celadon::
	random 1
	goto_if_eq VAR_RESULT, 1, Celadon_Fugitive_2
	goto_if_eq VAR_RESULT, 0, Celadon_Fugitive_1
	end

Celadon_Fugitive_2::
	clearflag FLAG_ROCKET_FUGITIVE_CELADON_2
	goto Looker_QuestBegin
	end

Celadon_Fugitive_1::
	clearflag FLAG_ROCKET_FUGITIVE_CELADON_1
	goto Looker_QuestBegin
	end

Looker_Text_CeladonCity::
	.string "Males notícies, {PLAYER}.\p"
	.string "Era la central.\p"
	.string "Hi ha informes d'un altre fugitiu\n"
	.string "Rocket a Kanto.\p"
	.string "La intel·ligència suggereix que\n"
	.string "és a prop de Ciutat Celadó.\p"
	.string "Enviaré el meu equip, però si\n"
	.string "ets per la zona, t'agrairia\l"
	.string "que ens ajudessis.$"

Looker_Fugitive_Vermilion::
	msgbox Looker_Text_VermilionCity, MSGBOX_NPC
	call SetFugitive_Vermilion
	release
	end

SetFugitive_Vermilion::
	random 2
	goto_if_eq VAR_RESULT, 2, Vermilion_Fugitive_3
	goto_if_eq VAR_RESULT, 1, Vermilion_Fugitive_2
	goto_if_eq VAR_RESULT, 0, Vermilion_Fugitive_1
	end

Vermilion_Fugitive_3::
	clearflag FLAG_ROCKET_FUGITIVE_VERMILION_3
	goto Looker_QuestBegin
	end

Vermilion_Fugitive_2::
	clearflag FLAG_ROCKET_FUGITIVE_VERMILION_2
	goto Looker_QuestBegin
	end

Vermilion_Fugitive_1::
	clearflag FLAG_ROCKET_FUGITIVE_VERMILION_1
	goto Looker_QuestBegin
	end

Looker_Text_VermilionCity::
	.string "Males notícies, {PLAYER}.\p"
	.string "Era la central.\p"
	.string "Hi ha informes d'un altre fugitiu\n"
	.string "Rocket a Kanto.\p"
	.string "La intel·ligència suggereix que\n"
	.string "és a prop de Ciutat Vermella.\p"
	.string "Enviaré el meu equip, però si\n"
	.string "ets per la zona, t'agrairia\l"
	.string "que ens ajudessis.$"

Looker_Fugitive_Lavender::
	msgbox Looker_Text_LavenderTown, MSGBOX_NPC
	call SetFugitive_Lavender
	release
	end

SetFugitive_Lavender::
	random 1
	goto_if_eq VAR_RESULT, 1, Lavender_Fugitive_2
	goto_if_eq VAR_RESULT, 0, Lavender_Fugitive_1
	end

Lavender_Fugitive_2::
	clearflag FLAG_ROCKET_FUGITIVE_LAVENDER_2
	goto Looker_QuestBegin
	end

Lavender_Fugitive_1::
	clearflag FLAG_ROCKET_FUGITIVE_LAVENDER_1
	goto Looker_QuestBegin
	end

Looker_Text_LavenderTown::
	.string "Males notícies, {PLAYER}.\p"
	.string "Era la central.\p"
	.string "Hi ha informes d'un altre fugitiu\n"
	.string "Rocket a Kanto.\p"
	.string "La intel·ligència suggereix que\n"
	.string "és a prop de Poble Lavanda.\p"
	.string "Enviaré el meu equip, però si\n"
	.string "ets per la zona, t'agrairia\l"
	.string "que ens ajudessis.$"

Looker_Fugitive_Cerulean::
	msgbox Looker_Text_CeruleanCity, MSGBOX_NPC
	call SetFugitive_Cerulean
	release
	end

SetFugitive_Cerulean::
	random 2
	goto_if_eq VAR_RESULT, 2, Cerulean_Fugitive_3
	goto_if_eq VAR_RESULT, 1, Cerulean_Fugitive_2
	goto_if_eq VAR_RESULT, 0, Cerulean_Fugitive_1
	end

Cerulean_Fugitive_3::
	clearflag FLAG_ROCKET_FUGITIVE_CERULEAN_3
	goto Looker_QuestBegin
	end

Cerulean_Fugitive_2::
	clearflag FLAG_ROCKET_FUGITIVE_CERULEAN_2
	goto Looker_QuestBegin
	end

Cerulean_Fugitive_1::
	clearflag FLAG_ROCKET_FUGITIVE_CERULEAN_1
	goto Looker_QuestBegin
	end

Looker_Text_CeruleanCity::
	.string "Males notícies, {PLAYER}.\p"
	.string "Era la central.\p"
	.string "Hi ha informes d'un altre fugitiu\n"
	.string "Rocket a Kanto.\p"
	.string "La intel·ligència suggereix que\n"
	.string "és a prop de Ciutat Cerúlia.\p"
	.string "Enviaré el meu equip, però si\n"
	.string "ets per la zona, t'agrairia\l"
	.string "que ens ajudessis.$"

Looker_Fugitive_Pewter::
	msgbox Looker_Text_PewterCity, MSGBOX_NPC
	call SetFugitive_Pewter
	release
	end

SetFugitive_Pewter::
	random 1
	goto_if_eq VAR_RESULT, 1, Pewter_Fugitive_2
	goto_if_eq VAR_RESULT, 0, Pewter_Fugitive_1
	end

Pewter_Fugitive_2::
	clearflag FLAG_ROCKET_FUGITIVE_PEWTER_2
	goto Looker_QuestBegin
	end

Pewter_Fugitive_1::
	clearflag FLAG_ROCKET_FUGITIVE_PEWTER_1
	goto Looker_QuestBegin
	end

Looker_Text_PewterCity::
	.string "Males notícies, {PLAYER}.\p"
	.string "Era la central.\p"
	.string "Hi ha informes d'un altre fugitiu\n"
	.string "Rocket a Kanto.\p"
	.string "La intel·ligència suggereix que\n"
	.string "és a prop de Ciutat Plateada.\p"
	.string "Enviaré el meu equip, però si\n"
	.string "ets per la zona, t'agrairia\l"
	.string "que ens ajudessis.$"

Looker_Fugitive_Viridian::
	msgbox Looker_Text_ViridianCity, MSGBOX_NPC
	call SetFugitive_Viridian
	release
	end

SetFugitive_Viridian::
	random 1
	goto_if_eq VAR_RESULT, 1, Viridian_Fugitive_2
	goto_if_eq VAR_RESULT, 0, Viridian_Fugitive_1
	end

Viridian_Fugitive_2::
	clearflag FLAG_ROCKET_FUGITIVE_VIRIDIAN_2
	goto Looker_QuestBegin
	end

Viridian_Fugitive_1::
	clearflag FLAG_ROCKET_FUGITIVE_VIRIDIAN_1
	goto Looker_QuestBegin
	end

Looker_Text_ViridianCity::
	.string "Males notícies, {PLAYER}.\p"
	.string "Era la central.\p"
	.string "Hi ha informes d'un altre fugitiu\n"
	.string "Rocket a Kanto.\p"
	.string "La intel·ligència suggereix que\n"
	.string "és a prop de Ciutat Viridiana.\p"
	.string "Enviaré el meu equip, però si\n"
	.string "ets per la zona, t'agrairia\l"
	.string "que ens ajudessis.$"

Looker_Fugitive_Pallet::
	msgbox Looker_Text_PalletTown, MSGBOX_NPC
	call SetFugitive_Pallet
	release
	end

SetFugitive_Pallet::
	random 1
	goto_if_eq VAR_RESULT, 1, Pallet_Fugitive_2
	goto_if_eq VAR_RESULT, 0, Pallet_Fugitive_1
	end

Pallet_Fugitive_2::
	clearflag FLAG_ROCKET_FUGITIVE_PALLET_2
	goto Looker_QuestBegin
	end

Pallet_Fugitive_1::
	clearflag FLAG_ROCKET_FUGITIVE_PALLET_1
	goto Looker_QuestBegin
	end

Looker_Text_PalletTown::
	.string "Males notícies, {PLAYER}.\p"
	.string "Era la central.\p"
	.string "Hi ha informes d'un altre fugitiu\n"
	.string "Rocket a Kanto.\p"
	.string "La intel·ligència suggereix que\n"
	.string "és a prop de Pallet Town.\p"
	.string "Enviaré el meu equip, però si\n"
	.string "ets per la zona, t'agrairia\l"
	.string "que ens ajudessis.$"

Looker_FaceLeft::
	turnobject LOCALID_LOOKER, DIR_WEST
	return

Looker_FaceRight::
	turnobject LOCALID_LOOKER, DIR_EAST
	return

Looker_FaceDown::
	turnobject LOCALID_LOOKER, DIR_SOUTH
	return

Looker_Text_PhoneCall::
	.string "Sóc Looker.\p"
	.string "...\n"
	.string "Sí...\l"
	.string "Què?!....\l"
	.string "Entès.$"


Looker_QuestBegin::
	setflag FLAG_DAILY_ROCKET_FUGITIVE
	setflag FLAG_LOOKER_ASSIGNMENT_ACTIVE
	clearflag FLAG_ROCKET_FUGITIVE_CAPTURED
	release
	end

Looker_CheckStatus::
	goto_if_set FLAG_ROCKET_FUGITIVE_CAPTURED, Looker_QuestComplete
	goto_if_unset FLAG_DAILY_ROCKET_FUGITIVE, Looker_QuestFailed
	msgbox Looker_Text_OnTheLoose, MSGBOX_NPC
	release
	end

Looker_QuestComplete::
	msgbox Looker_Text_Victory, MSGBOX_NPC
	call Looker_ResetFugitives
	goto Looker_Reward

Looker_DailyCompleted::
	msgbox Looker_Text_NeverStop, MSGBOX_NPC
	release
	end

Looker_Reward::
	random 2
	goto_if_eq VAR_RESULT, 0, Looker_Reward_Money
	goto_if_eq VAR_RESULT, 1, Looker_Reward_Stone
	goto_if_eq VAR_RESULT, 2, Looker_Reward_Candies

Looker_Reward_Money::
	giveitem ITEM_NUGGET, 4
	goto Looker_DailyCompleted

Looker_Reward_Stone::
	giveitem ITEM_POWER_STONE, 1
	goto Looker_DailyCompleted

Looker_Reward_Candies::
	giveitem ITEM_RARE_CANDY, 3
	goto Looker_DailyCompleted

Looker_Text_Victory::
	.string "Looker: Ho has aconseguit,\n"
	.string "{PLAYER}!\p"
	.string "Un membre menys de l'Equip\n"
	.string "Rocket en llibertat!\p"
	.string "La gent de Kanto et deu\n"
	.string "un favor.\p"
	.string "Tingues, agafa això com a\n"
	.string "recompensa!$"

Looker_Text_NeverStop::
	.string "L'Equip Rocket no pararà mai.\p"
	.string "Hem de treballar junts per\n"
	.string "aconseguir la pau!$"

Looker_Text_OnTheLoose::
	.string "Looker: Aquell fugitiu encara\n"
	.string "és en llibertat, {PLAYER}!\p"
	.string "No podem deixar escapar\n"
	.string "l'Equip Rocket!$"


Looker_QuestFailed::
	call Looker_ResetFugitives
	msgbox Looker_Text_TheyGotAway, MSGBOX_NPC
	release
	end

Looker_Text_TheyGotAway:
	.string "Looker: {PLAYER}!\p"
	.string "He rebut informació nova de la\n"
	.string "central! Sembla que el nostre\l"
	.string "fugitiu ha fugit de la regió.\p"
	.string "Em pregunto si l'Equip Rocket\n"
	.string "està construint un nou amagatall\l"
	.string "en un altre lloc...\p"
	.string "Bé, els atraparem la pròxima\n"
	.string "vegada.$"

Looker_ResetFugitives::
	clearflag FLAG_LOOKER_ASSIGNMENT_ACTIVE
	setflag FLAG_ROCKET_FUGITIVE_PALLET_1
	setflag FLAG_ROCKET_FUGITIVE_PALLET_2
	setflag FLAG_ROCKET_FUGITIVE_VIRIDIAN_1
	setflag FLAG_ROCKET_FUGITIVE_VIRIDIAN_2
	setflag FLAG_ROCKET_FUGITIVE_PEWTER_1
	setflag FLAG_ROCKET_FUGITIVE_PEWTER_2
	setflag FLAG_ROCKET_FUGITIVE_CERULEAN_1
	setflag FLAG_ROCKET_FUGITIVE_CERULEAN_2
	setflag FLAG_ROCKET_FUGITIVE_CERULEAN_3
	setflag FLAG_ROCKET_FUGITIVE_LAVENDER_1
	setflag FLAG_ROCKET_FUGITIVE_LAVENDER_2
	setflag FLAG_ROCKET_FUGITIVE_VERMILION_1
	setflag FLAG_ROCKET_FUGITIVE_VERMILION_2
	setflag FLAG_ROCKET_FUGITIVE_VERMILION_3
	setflag FLAG_ROCKET_FUGITIVE_CELADON_1
	setflag FLAG_ROCKET_FUGITIVE_CELADON_2
	setflag FLAG_ROCKET_FUGITIVE_FUCHSIA_1
	setflag FLAG_ROCKET_FUGITIVE_FUCHSIA_2
	setflag FLAG_ROCKET_FUGITIVE_FUCHSIA_3
	setflag FLAG_ROCKET_FUGITIVE_CINNABAR_1
	setflag FLAG_ROCKET_FUGITIVE_CINNABAR_2
	setflag FLAG_ROCKET_FUGITIVE_SAFFRON_1
	setflag FLAG_ROCKET_FUGITIVE_SAFFRON_2
	setflag FLAG_ROCKET_FUGITIVE_SAFFRON_3
	setflag FLAG_ROCKET_FUGITIVE_SAFFRON_4
	cleartrainerflag TRAINER_FUGITIVE_M
	cleartrainerflag TRAINER_FUGITIVE_F
	cleartrainerflag TRAINER_FUGITIVE_JESSIE_JAMES
	return


CeladonCity_Looker_ExplainDaily::
	msgbox Looker_Text_RocketFugitives, MSGBOX_NPC
	setflag FLAG_LOOKER_EXPLAINED_QUESTS
	goto CeladonCity_Looker

Looker_Text_RocketFugitives::
	.string "Looker: {PLAYER}!\p"
	.string "Gràcies a tu, l'Equip Rocket\n"
	.string "està en fuga!\p"
	.string "Hem desmantellat totes les seves\n"
	.string "operacions importants, però\l"
	.string "encara hi ha molts soldats fugits.\p"
	.string "Em quedaré a Kanto per intentar\n"
	.string "atrapar aquests fugitius.\p"
	.string "Espero poder comptar amb\n"
	.string "entrenadors com tu!$"

RocketFugitive_Text_Intro::
	.string "Fugitiu: No m'atrapareu\n"
	.string "mai amb vida!$"

RocketFugitive_Text_Defeat::
	.string "Fugitiu: D'acord! D'acord!\n"
	.string "Em rendeixo!$"

RocketFugitive_Text_PostBattle::
	.string "Fugitiu: Està bé!\p"
	.string "Em lliuraré.$"

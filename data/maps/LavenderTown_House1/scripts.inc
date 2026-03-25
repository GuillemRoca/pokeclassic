LavenderTown_House1_MapScripts::
	.byte 0

LavenderTown_House1_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_set FLAG_RESCUED_MR_FUJI, LavenderTown_House1_EventScript_CooltrainerFGhostGone
	goto_if_set FLAG_RESCUED_CUBONE, LavenderTown_House1_EventScript_CooltrainerSawCuboneReturn
	msgbox LavenderTown_House1_Text_RocketsKilledCubonesMother
	release
	end

LavenderTown_House1_Text_RocketsKilledCubonesMother::
    .string "Aquells Rockets horribles!\n"
    .string "No mereixen cap pietat!\p"
    .string "Van segrestar aquell Cubone i\n"
    .string "van matar la seva pobra mare…$"

LavenderTown_House1_EventScript_CooltrainerSawCuboneReturn::
	msgbox LavenderTown_House1_Text_CuboneReturnedToTower
	release
	end

LavenderTown_House1_Text_CuboneReturnedToTower::
	.string "Vaig veure el Cubone tornar a la\n"
	.string "Torre Pokémon!\p"
	.string "Semblava molt decidit!$"

LavenderTown_House1_EventScript_CooltrainerFGhostGone::
	msgbox LavenderTown_House1_Text_GhostOfPokemonTowerIsGone
	release
	end

LavenderTown_House1_Text_GhostOfPokemonTowerIsGone::
    .string "Així que el fantasma de la Torre\n"
    .string "Pokémon era la mare del Cubone?\p"
    .string "M'alegro que aquest Cubone hagi\n"
    .string "pogut calmar el seu esperit!$"

LavenderTown_House1_EventScript_Cubone::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CUBONE, CRY_MODE_NORMAL
	msgbox LavenderTown_House1_Text_Cubone
	waitmoncry
	release
	end

LavenderTown_House1_Text_Cubone::
    .string "CUBONE: Kyarugoo!$"

.set LOCALID_MRFUJI, 1

LavenderTown_VolunteerPokemonHouse_MapScripts::
	.byte 0

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POKE_FLUTE, LavenderTown_VolunteerPokemonHouse_EventScript_AlreadyHavePokeFlute
	msgbox LavenderTown_VolunteerPokemonHouse_Text_IdLikeYouToHaveThis
	checkitemspace ITEM_POKE_FLUTE, 1
	goto_if_eq VAR_RESULT, FALSE, LavenderTown_VolunteerPokemonHouse_EventScript_NoRoomForPokeFlute
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message LavenderTown_VolunteerPokemonHouse_Text_ReceivedPokeFluteFromMrFuji
	waitmessage
	waitfanfare
	additem ITEM_POKE_FLUTE, 1
	setflag FLAG_RECEIVED_POKE_FLUTE
	setvar VAR_POKEMON_TOWER_STATE, 4
	msgbox LavenderTown_VolunteerPokemonHouse_Text_ExplainPokeFlute
	release
	end

LavenderTown_VolunteerPokemonHouse_Text_IdLikeYouToHaveThis::
    .string "Sr. Fuji: {PLAYER}…\p"
    .string "La teva cerca amb la Pokédex\n"
    .string "requereix molta dedicació.\p"
    .string "Sense un amor profund pels\n"
    .string "Pokémon, la teva cerca podria\l"
    .string "fracassar.\p"
    .string "No sé si això t'ajudarà,\n"
    .string "però m'agradaria que ho tinguessis.$"

LavenderTown_VolunteerPokemonHouse_Text_ReceivedPokeFluteFromMrFuji::
    .string "{PLAYER} ha rebut una Poké Flauta\n"
    .string "del Sr. Fuji.$"

LavenderTown_VolunteerPokemonHouse_Text_ExplainPokeFlute::
    .string "En sentir la Poké Flauta,\n"
    .string "els Pokémon adormits es\l"
    .string "despertaran d'un bot.\p"
    .string "Prova d'usar-la amb Pokémon\n"
    .string "que bloquegen el camí dormint.$"

LavenderTown_VolunteerPokemonHouse_EventScript_AlreadyHavePokeFlute::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_HasPokeFluteHelpedYou
	release
	end

LavenderTown_VolunteerPokemonHouse_Text_HasPokeFluteHelpedYou::
    .string "Sr. Fuji: T'ha ajudat la meva\n"
    .string "Poké Flauta?$"

LavenderTown_VolunteerPokemonHouse_EventScript_NoRoomForPokeFlute::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MustMakeRoomForThis
	release
	end

LavenderTown_VolunteerPokemonHouse_Text_MustMakeRoomForThis::
    .string "Has de fer espai per a això!$"

LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFujiLooksAfterOrphanedMons, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_Text_MrFujiLooksAfterOrphanedMons::
    .string "Aquesta és la casa del Sr. Fuji.\p"
    .string "És molt amable.\p"
    .string "Cuida els Pokémon abandonats\n"
    .string "i orfes.$"

LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MonsNiceToHug, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_Text_MonsNiceToHug::
    .string "Són tan càlids!\n"
    .string "Els Pokémon són genials d'abraçar.$"

LavenderTown_VolunteerPokemonHouse_EventScript_Youngster::
	goto_if_set FLAG_RESCUED_MR_FUJI, LavenderTown_VolunteerPokemonHouse_EventScript_YoungsterFujiBack
	msgbox LavenderTown_VolunteerPokemonHouse_Text_WhereDidMrFujiGo, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_Text_WhereDidMrFujiGo::
    .string "Que estrany, el Sr. Fuji no és aquí.\n"
    .string "On deu haver anat?$"

LavenderTown_VolunteerPokemonHouse_EventScript_YoungsterFujiBack::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFujiWasPrayingForCubonesMother, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_Text_MrFujiWasPrayingForCubonesMother::
    .string "El Sr. Fuji havia estat pregant\n"
    .string "sol per la mare del Cubone.$"

LavenderTown_VolunteerPokemonHouse_EventScript_Nidorino::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDORINO, CRY_MODE_NORMAL
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Nidorino
	waitmoncry
	release
	end

LavenderTown_VolunteerPokemonHouse_Text_Nidorino::
    .string "Nidorino: Gaoo!$"

LavenderTown_VolunteerPokemonHouse_EventScript_Psyduck::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Psyduck
	waitmoncry
	release
	end

LavenderTown_VolunteerPokemonHouse_Text_Psyduck::
    .string "Psyduck: Gwappa!$"


LavenderTown_VolunteerPokemonHouse_EventScript_PokemonFanMagazine::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_GrandPrizeDrawingClipped, MSGBOX_SIGN
	end

LavenderTown_VolunteerPokemonHouse_Text_GrandPrizeDrawingClipped::
    .string "Revista Fan Pokémon\n"
    .string "Sorteig mensual del Gran Premi!\p"
    .string "El formulari de sol·licitud…\p"
    .string "No hi és! L'han retallat.\n"
    .string "Algú ja deu haver participat.$"

LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_PokemonMagazinesLineShelf, MSGBOX_SIGN
	end

LavenderTown_VolunteerPokemonHouse_Text_PokemonMagazinesLineShelf::
    .string "Hi ha revistes Pokémon al prestatge.\p"
    .string "Pokémon Insider…\p"
    .string "Pokémon Fan…$"

LavenderTown_VolunteerPokemonHouse_EventScript_GetReward::
	playse SE_PIN
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_MRFUJI, Common_Movement_QuestionMark
	waitmovement 1
	msgbox LavenderTown_VolunteerPokemonHouse_Text_GetReward, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ApproachFuji
	waitmovement 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

LavenderTown_VolunteerPokemonHouse_Text_GetReward::
	.string "Sr. Fuji: Oh, {PLAYER}, tinc\n"
	.string "una cosa per a tu.\p"
	.string "Vine un moment.$"

 Movement_ApproachFuji::
 	walk_up
 	walk_up
 	step_end

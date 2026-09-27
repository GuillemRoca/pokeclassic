@ Interact with cuttable tree
EventScript_CutTree::
	lockall
	goto_if_unset FLAG_BADGE01_GET, EventScript_CheckTreeCantCut
	checkpartymove MOVE_CUT
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckTreeCantCut
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_CUT
	msgbox Text_WantToCut, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

@ Use cut from party menu
EventScript_UseCut::
	lockall
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

EventScript_CutTreeDown::
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	releaseall
	end

Movement_CutTreeDown:
	cut_tree
	step_end

EventScript_CheckTreeCantCut::
	msgbox Text_CantCut, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelCut::
	closemessage
	releaseall
	end

Text_WantToCut:
	.string "Sembla que aquest arbre es pot\n"
	.string "Tallar!\p"
	.string "Vols Tallar-lo?$"

Text_MonUsedFieldMove:
	.string "{STR_VAR_1} ha usat {STR_VAR_2}!$"

Text_CantCut:
	.string "Sembla que aquest arbre es pot\n"
	.string "Tallar!$"

@ Interact with smashable rock
EventScript_RockSmash::
	lockall
	goto_if_unset FLAG_BADGE06_GET, EventScript_CantSmashRock
	checkpartymove MOVE_ROCK_SMASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
	msgbox Text_WantToSmash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

@ Use rock smash from party menu
EventScript_UseRockSmash::
	lockall
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

EventScript_SmashRock::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	random 4
	goto_if_eq VAR_RESULT, 3, EventScript_RockHasItem
	goto EventScript_SmashRockEncounter
	end

EventScript_SmashRockEncounter::
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	releaseall
	end

EventScript_EndSmash::
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	releaseall
	end

EventScript_RockHasItem::
	goto_if_set FLAG_SYS_GAME_CLEAR, EventScript_RockHasItemPostgame
	random 3
	goto_if_eq VAR_RESULT, 0, EventScript_RockItem_CommonTreasure
	goto_if_eq VAR_RESULT, 1, EventScript_RockItem_RareTreasure
	goto_if_eq VAR_RESULT, 2, EventScript_RockItem_Stone
	end

EventScript_RockHasItemPostgame::
	random 4
	goto_if_eq VAR_RESULT, 0, EventScript_RockItem_CommonTreasure
	goto_if_eq VAR_RESULT, 1, EventScript_RockItem_RareTreasure
	goto_if_eq VAR_RESULT, 2, EventScript_RockItem_Stone
	goto_if_eq VAR_RESULT, 3, EventScript_RockItem_Fossil
	end

EventScript_RockItem_CommonTreasure::
	random 2
	goto_if_eq VAR_RESULT, 0, EventScript_RockItem_Pearl
	goto_if_eq VAR_RESULT, 1, EventScript_RockItem_Stardust
	end

EventScript_RockItem_Pearl::
	giveitem ITEM_PEARL, 1
	goto EventScript_SmashRockEncounter

EventScript_RockItem_Stardust::
	giveitem ITEM_STARDUST, 1
	goto EventScript_SmashRockEncounter

EventScript_RockItem_RareTreasure::
	random 3
	goto_if_eq VAR_RESULT, 0, EventScript_RockItem_Nugget
	goto_if_eq VAR_RESULT, 1, EventScript_RockItem_BigPearl
	goto_if_eq VAR_RESULT, 2, EventScript_RockItem_StarPiece
	end

EventScript_RockItem_Nugget::
	giveitem ITEM_NUGGET, 1
	goto EventScript_SmashRockEncounter

EventScript_RockItem_BigPearl::
	giveitem ITEM_BIG_PEARL, 1
	goto EventScript_SmashRockEncounter

EventScript_RockItem_StarPiece::
	giveitem ITEM_STAR_PIECE, 1
	goto EventScript_SmashRockEncounter

EventScript_RockItem_Stone::
	random 2
	goto_if_eq VAR_RESULT, 0, EventScript_RockItem_MoonStone
	goto_if_eq VAR_RESULT, 1, EventScript_RockItem_PowerStone
	end

EventScript_RockItem_MoonStone::
	giveitem ITEM_MOON_STONE, 1
	goto EventScript_SmashRockEncounter

EventScript_RockItem_PowerStone::
	giveitem ITEM_POWER_STONE, 1
	goto EventScript_SmashRockEncounter

EventScript_RockItem_Fossil::
	random 3
	goto_if_eq VAR_RESULT, 0, EventScript_RockItem_HelixFossil
	goto_if_eq VAR_RESULT, 1, EventScript_RockItem_DomeFossil
	goto_if_eq VAR_RESULT, 2, EventScript_RockItem_OldAmber
	end

EventScript_RockItem_HelixFossil::
	giveitem ITEM_HELIX_FOSSIL, 1
	goto EventScript_SmashRockEncounter

EventScript_RockItem_DomeFossil::
	giveitem ITEM_DOME_FOSSIL, 1
	goto EventScript_SmashRockEncounter

EventScript_RockItem_OldAmber::
	giveitem ITEM_OLD_AMBER, 1
	goto EventScript_SmashRockEncounter

Movement_SmashRock:
	rock_smash_break
	step_end

EventScript_CantSmashRock::
	msgbox Text_CantSmash, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelSmash::
	closemessage
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	releaseall
	end

Text_WantToSmash:
	.string "Aquesta roca sembla trencadissa.\n"
	.string "Vols fer servir Destrossa Roques?$"

Text_CantSmash:
	.string "És una roca dura, però un Pokémon\n"
	.string "podria trencar-la.$"

EventScript_StrengthBoulder::
	lockall
	goto_if_unset FLAG_BADGE04_GET, EventScript_CantStrength
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
	checkpartymove MOVE_STRENGTH
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantStrength
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToStrength, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelStrength
	closemessage
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_UseStrength::
	lockall
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_ActivateStrength::
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_MonUsedStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CantStrength::
	msgbox Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CheckActivatedBoulder::
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelStrength::
	closemessage
	releaseall
	end

Text_WantToStrength:
	.string "És una gran roca, però un Pokémon\n"
	.string "podria empènyer-la.\p"
	.string "Vols fer servir Força?$"

Text_MonUsedStrength:
	.string "{STR_VAR_1} ha usat Força!\p"
	.string "La Força de {STR_VAR_1} permet\n"
	.string "moure les roques!$"

Text_CantStrength:
	.string "És una gran roca, però un Pokémon\n"
	.string "podria empènyer-la.$"

Text_StrengthActivated:
	.string "La Força permet moure\n"
	.string "les roques.$"

EventScript_UseWaterfall::
	lockall
	checkpartymove MOVE_WATERFALL
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantWaterfall
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToWaterfall, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndWaterfall
	msgbox Text_MonUsedWaterfall, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_WATERFALL
	goto EventScript_EndWaterfall

EventScript_CannotUseWaterfall::
	lockall

EventScript_CantWaterfall::
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT

EventScript_EndWaterfall::
	releaseall
	end

Text_CantWaterfall:
	.string "Una paret d'aigua cau amb\n"
	.string "un gran rugit.$"

Text_WantToWaterfall:
	.string "És una gran cascada.\n"
	.string "Vols fer servir Cascada?$"

Text_MonUsedWaterfall:
	.string "{STR_VAR_1} ha usat Cascada.$"

EventScript_UseDive::
	lockall
	checkpartymove MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantDive
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToDive, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndDive
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive
	end

EventScript_CantDive::
	msgbox Text_CantDive, MSGBOX_DEFAULT
	releaseall
	end

EventScript_EndDive::
	releaseall
	end

EventScript_UseDiveUnderwater::
	lockall
	checkpartymove MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSurface
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToSurface, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndSurface
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface
	end

EventScript_CantSurface::
	lockall
	msgbox Text_CantSurface, MSGBOX_DEFAULT
	goto EventScript_EndSurface
	end

EventScript_EndSurface::
	releaseall
	end

Text_CantDive:
	.string "El mar és profund aquí. Un Pokémon\n"
	.string "podria submergir-s'hi.$"

Text_WantToDive:
	.string "El mar és profund aquí.\n"
	.string "Vols fer servir Busseig?$"

Text_MonUsedDive:
	.string "{STR_VAR_1} ha usat Busseig.$"

Text_CantSurface:
	.string "La llum es filtra des de dalt.\n"
	.string "Un Pokémon podria emergir.$"

Text_WantToSurface:
	.string "La llum es filtra des de dalt.\n"
	.string "Vols fer servir Busseig?$"

EventScript_FailSweetScent::
	msgbox Text_FailSweetScent, MSGBOX_SIGN
	end

Text_FailSweetScent:
	.string "Sembla que no hi ha res aquí…$"

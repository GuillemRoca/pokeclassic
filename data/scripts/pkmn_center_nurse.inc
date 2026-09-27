Common_EventScript_PkmnCenterNurse::
	goto_if_set FLAG_IS_CHAMPION, EventScript_PkmnCenterNurse_ChampionHeal
	goto_if_set FLAG_SYS_GAME_CLEAR, EventScript_PkmnCenterNurse_GameClearHeal
	goto EventScript_PkmnCenterNurse_NormalHeal
	end

EventScript_PkmnCenterNurse_NormalHeal::
	msgbox gText_WouldYouLikeToRestYourPkmn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_HealPkmn
	goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterNurse_Goodbye
	end

gText_WouldYouLikeToRestYourPkmn::
    .string "Hola! Et donem la benvinguda\n"
    .string "al Centre Pokémon.\p"
    .string "Aquí deixem com nous els\n"
    .string "Pokémon cansats.\p"
    .string "Vols que curem els teus Pokémon?$"

EventScript_PkmnCenterNurse_GameClearHeal::
	msgbox gText_YouWantTheUsual, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_HealPkmn
	goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterNurse_Goodbye
	end

gText_YouWantTheUsual::
    .string "Quina alegria veure't, {PLAYER}!\n"
    .string "Vols el de sempre, oi?$"

EventScript_PkmnCenterNurse_ChampionHeal::
	applymovement VAR_0x800B, Common_Movement_ExclamationMark
	playse SE_PIN
	msgbox gText_ItsTheChampion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_HealPkmn
	goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterNurse_Goodbye
	end

gText_ItsTheChampion::
    .string "Oh! Ets {MASC}el Campió{FEM}la Campiona{ENDG}, {PLAYER}!\n"
    .string "Vols que curem els teus Pokémon?$"

EventScript_PkmnCenterNurse_HealPkmn::
	incrementgamestat GAME_STAT_USED_POKECENTER
	message gText_IllTakeYourPkmn
	waitmessage
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special HealPlayerParty
	call_if_unset FLAG_POKERUS_EXPLAINED, EventScript_PkmnCenterNurse_CheckPokerus
	msgbox gText_RestoredPkmnToFullHealth, MSGBOX_DEFAULT
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	goto EventScript_PkmnCenterNurse_Goodbye

gText_IllTakeYourPkmn::
    .string "D'acord, deixa'm els teus Pokémon\n"
    .string "un moment.$"

gText_RestoredPkmnToFullHealth::
    .string "Gràcies per esperar.\p"
    .string "Els teus Pokémon ja estan\n"
    .string "completament recuperats.$"

EventScript_PkmnCenterNurse_CheckPokerus::
	specialvar VAR_RESULT, IsPokerusInParty
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterNurse_ExplainPokerus
	return

EventScript_PkmnCenterNurse_ExplainPokerus::
	msgbox gText_PokerusExplanation, MSGBOX_DEFAULT
	setflag FLAG_POKERUS_EXPLAINED
	return

gText_PokerusExplanation::
	.string "Els teus Pokémon podrien estar\n"
	.string "infectats de Pokérus.\p"
	.string "Se'n sap poca cosa, a part que\n"
	.string "són formes de vida microscòpiques\l"
	.string "que s'enganxen als Pokémon.\p"
	.string "Diuen que, mentre estan infectats,\n"
	.string "els Pokémon es fan forts molt de pressa.$"

gText_WeHopeToSeeYouAgain::
    .string "Esperem veure't aviat!$"

Movement_PkmnCenterNurse_Bow:
	nurse_joy_bow
	delay_4
	step_end

EventScript_PkmnCenterNurse_Goodbye::
	msgbox gText_WeHopeToSeeYouAgain, MSGBOX_DEFAULT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

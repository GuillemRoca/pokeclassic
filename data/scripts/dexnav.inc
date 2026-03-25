EventScript_StartDexNavBattle::
	lock
	playse 0x15
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	dowildbattle    
	release
	end


EventScript_NotFoundNearby::
    msgbox sText_NotFoundNearby, MSGBOX_SIGN
    end
sText_NotFoundNearby:
    .string "No s'ha pogut trobar a prop.\n"
    .string "Prova de buscar en una altra zona!$"


EventScript_MovedTooFast::
    msgbox sText_TryMovingSlower, MSGBOX_SIGN
    end
sText_TryMovingSlower:
    .string "El Pokémon ha fugit!\n"
    .string "Prova de moure't més a poc a poc.$"


EventScript_PokemonGotAway::
    msgbox sText_PokemonGotAway, MSGBOX_SIGN
    end
sText_PokemonGotAway:
    .string "El Pokémon ha fugit!$"


EventScript_LostSignal::
    msgbox sText_LostSignal, MSGBOX_SIGN
    end
sText_LostSignal:
    .string "No hi ha reacció.\n"
    .string "S'ha perdut el senyal!$"


EventScript_TooDark::
    msgbox sText_TooDark, MSGBOX_SIGN
    end
sText_TooDark:
    .string "És massa fosc per buscar\nun Pokémon!$"

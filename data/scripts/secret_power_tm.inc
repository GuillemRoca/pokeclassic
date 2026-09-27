Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "Què és això?\n"
	.string "Què estic fent?\p"
	.string "Estic pensant en fer-me una habitació\n"
	.string "aquí amb un moviment Pokémon.\p"
	.string "Ja ho sé! Et donaré aquesta MT.\n"
	.string "La faràs servir per fer la teva?$"

Route111_Text_ExplainSecretPower:
	.string "Busca un arbre gran que sembli que\n"
	.string "podria deixar caure unes lianes.\p"
	.string "Utilitza Poder Secret davant l'arbre.\n"
	.string "Algunes lianes haurien de caure\l"
	.string "perquè puguis enfilar-t'hi.\p"
	.string "Trobaràs molt d'espai per posar-hi\n"
	.string "les teves coses preferides.\p"
	.string "Serà la teva pròpia habitació…\n"
	.string "Una Base Secreta!\p"
	.string "Tu també n'hauries de fer una.\p"
	.string "Una altra cosa, no cal que facis\n"
	.string "la teva Base Secreta en un arbre.\p"
	.string "Prova d'usar Poder Secret en parets\n"
	.string "de roca amb petites osques.\p"
	.string "Jo també buscaré altres llocs.\n"
	.string "D'acord, adéu!$"

Route111_Text_DontWantThis:
	.string "Oh, no ho vols?\n"
	.string "Si canvies d'opinió, digues-m'ho!$"

Route111_Text_DontHaveAnyRoom:
	.string "Oh, no tens espai per a això.\p"
	.string "Ho guardaré, així que torna a buscar-ho\n"
	.string "un altre dia, d'acord?$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM43
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

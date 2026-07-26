Roulette_EventScript_Table1::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Table2::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Play::
	special PlayRoulette
	waitstate
	end
	
Roulette_Text_PlayMinimumWagerIsX::
	.string "L'aposta mínima en aquesta taula\n"
	.string "és {STR_VAR_1}. Vols jugar?$"

Roulette_Text_NotEnoughCoins::
	.string "No tens prou Monedes.$"

Roulette_Text_SpecialRateTable::
	.string "Taula amb tarifa especial ara!$"

Roulette_Text_ControlsInstruction::
	.string "Fes l'aposta amb la Creueta\n"
	.string "i prem el Botó A.$"

Roulette_Text_ItsAHit::
	.string "Has encertat!$"

Roulette_Text_Jackpot::
	.string "Premi gros!$"

Roulette_Text_NothingDoing::
	.string "Res de res!$"

Roulette_Text_YouveWonXCoins::
	.string "Has guanyat {STR_VAR_1} Monedes!$"

Roulette_Text_NoCoinsLeft::
	.string "No queden Monedes…$"

Roulette_Text_KeepPlaying::
	.string "Vols seguir jugant?$"

Roulette_Text_BoardWillBeCleared::
	.string "El tauler de Ruleta es netejarà.$"

@ Unused
Roulette_Text_YouDontHaveACoinCase::
	.string "No tens un Moneder.$"

Roulette_Text_CoinCaseIsFull::
	.string "El teu Moneder és ple!\n"
	.string "Les Monedes es canvien per premis.$"

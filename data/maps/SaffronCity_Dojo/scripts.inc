.set LOCALID_BELT, 9

SaffronCity_Dojo_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_Dojo_OnTransition
	.byte 0

SaffronCity_Dojo_OnTransition::
	call_if_unset FLAG_DAILY_DOJO_RESET, SaffronCity_Dojo_Reset
	end

SaffronCity_Dojo_Reset::
	cleartrainerflag SPARRING_PARTNER_ATTACK
	clearflag FLAG_DOJO_ATTACK
	cleartrainerflag SPARRING_PARTNER_SPATTACK
	clearflag FLAG_DOJO_SPATTACK
	cleartrainerflag SPARRING_PARTNER_SPEED
	clearflag FLAG_DOJO_SPEED
	cleartrainerflag SPARRING_PARTNER_HP
	clearflag FLAG_DOJO_HP
	cleartrainerflag SPARRING_PARTNER_DEFENSE
	clearflag FLAG_DOJO_DEFENSE
	cleartrainerflag SPARRING_PARTNER_SPDEFENSE
	clearflag FLAG_DOJO_SPDEFENSE
	setflag FLAG_DAILY_DOJO_RESET
	return

SaffronCity_Dojo_OffenseMaster::
	lock
	faceplayer
	msgbox SaffronCity_Dojo_Text_IAmTheOffenseMaster, MSGBOX_DEFAULT
	goto_if_set FLAG_RECEIVED_HITMONCHAN, SaffronCity_Dojo_TrainWithMyPupils
	goto_if_unset FLAG_DOJO_OFFENSE_1, SaffronCity_Dojo_EventScript_DefeatMyPupils
	goto_if_unset FLAG_DOJO_OFFENSE_2, SaffronCity_Dojo_EventScript_DefeatMyPupils
	goto_if_unset FLAG_DOJO_OFFENSE_3, SaffronCity_Dojo_EventScript_DefeatMyPupils
	msgbox SaffronCityDojo_Text_ProvedYourselfOffensive, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_HITMONCHAN
	givemon SPECIES_HITMONCHAN, 25, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, SaffronCity_Dojo_EventScript_HitmonchanParty
	goto_if_eq VAR_RESULT, 1, SaffronCity_Dojo_EventScript_HitmonchanPC
	goto_if_eq VAR_RESULT, 2, SaffronCity_Dojo_EventScript_NoRoomForPokemon
	end

SaffronCity_Dojo_Text_IAmTheOffenseMaster::
	.string "Sóc el Mestre de l'Ofensiva.\p"
	.string "Els meus alumnes han dominat\n"
	.string "l'art de l'ofensiva, i els seus\l"
	.string "Pokémon ho reflecteixen.$"

SaffronCity_Dojo_EventScript_DefeatMyPupils::
	msgbox SaffronCity_Dojo_Text_DefeatThemAll, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_DefeatThemAll::
	.string "Si pots derrotar tots els meus\n"
	.string "alumnes, et recompensaré amb\l"
	.string "un Pokémon especial!$"

SaffronCity_Dojo_TrainWithMyPupils::
	msgbox SaffronCity_Dojo_Text_TrainWithMyPupilsOffense, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_TrainWithMyPupilsOffense::
	.string "Si entrenes amb els meus alumnes,\n"
	.string "tu també pots dominar l'art de\l"
	.string "l'Ofensiva.\p"
	.string "Pots entrenar amb ells cada dia.\n"
	.string "Però necessiten descansar.\p"
	.string "Mantenir-se hidratat és important\n"
	.string "per a l'entrenament.$"

SaffronCityDojo_Text_ProvedYourselfOffensive::
	.string "Així que has derrotat tots els\n"
	.string "meus alumnes.\p"
	.string "Veig que has demostrat que pots\n"
	.string "sobreviure a l'ofensiva més\l"
	.string "forta!\p"
	.string "Per això, t'has guanyat aquest\n"
	.string "Pokémon... Hitmonchan!$"

SaffronCity_Dojo_EventScript_HitmonchanParty::
	call SaffronCity_Dojo_EventScript_GetHitmonchan
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_GotHitmonchan
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SaffronCity_Dojo_EventScript_GotHitmonchan
	end

SaffronCity_Dojo_EventScript_GetHitmonchan::
	playfanfare MUS_LEVEL_UP
	message SaffronCity_Dojo_EventScript_Text_EarnedHitmonchan
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_HITMONCHAN
	return

SaffronCity_Dojo_EventScript_Text_EarnedHitmonchan::
	.string "{PLAYER} ha dominat l'art de\n"
	.string "l'Ofensiva i s'ha guanyat el\l"
	.string "Hitmonchan del Dojo!$"

SaffronCity_Dojo_EventScript_GotHitmonchan::
	setflag FLAG_RECEIVED_HITMONCHAN
	releaseall
	end

SaffronCity_Dojo_EventScript_HitmonchanPC::
	call SaffronCity_Dojo_EventScript_GetHitmonchan
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_TransferHitmonchan
	call Common_EventScript_NameReceivedBoxMon
	goto SaffronCity_Dojo_EventScript_TransferHitmonchan
	end

SaffronCity_Dojo_EventScript_TransferHitmonchan::
	call Common_EventScript_TransferredToPC
	goto SaffronCity_Dojo_EventScript_GotHitmonchan
	end

SaffronCity_Dojo_DefenseMaster::
	lock
	faceplayer
	msgbox SaffronCity_Dojo_Text_IAmTheDefenseMaster, MSGBOX_DEFAULT
	goto_if_set FLAG_RECEIVED_HITMONLEE, SaffronCity_Dojo_TrainWithMyPupilsDefense
	goto_if_unset FLAG_DOJO_DEFENSE_1, SaffronCity_Dojo_EventScript_DefeatMyPupils
	goto_if_unset FLAG_DOJO_DEFENSE_2, SaffronCity_Dojo_EventScript_DefeatMyPupils
	goto_if_unset FLAG_DOJO_DEFENSE_3, SaffronCity_Dojo_EventScript_DefeatMyPupils
	msgbox SaffronCityDojo_Text_ProvedYourselfDefensive, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_HITMONLEE
	givemon SPECIES_HITMONLEE, 25, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, SaffronCity_Dojo_EventScript_HitmonleeParty
	goto_if_eq VAR_RESULT, 1, SaffronCity_Dojo_EventScript_HitmonleePC
	goto_if_eq VAR_RESULT, 2, SaffronCity_Dojo_EventScript_NoRoomForPokemon
	end

SaffronCity_Dojo_Text_IAmTheDefenseMaster::
	.string "Sóc el Mestre de la Defensa.\p"
	.string "Els meus alumnes han dominat\n"
	.string "l'art de la defensa, i els seus\l"
	.string "Pokémon ho reflecteixen.$"

SaffronCity_Dojo_TrainWithMyPupilsDefense::
	msgbox SaffronCity_Dojo_Text_TrainWithMyPupilsDefense, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_TrainWithMyPupilsDefense::
	.string "Si entrenes amb els meus alumnes,\n"
	.string "tu també pots dominar l'art de\l"
	.string "la Defensa.\p"
	.string "Pots entrenar amb ells cada dia.\n"
	.string "Però necessiten descansar.\p"
	.string "Mantenir-se hidratat és important\n"
	.string "per a l'entrenament també.$"

SaffronCityDojo_Text_ProvedYourselfDefensive::
	.string "Així que has derrotat tots els\n"
	.string "meus alumnes.\p"
	.string "Veig que has demostrat que pots\n"
	.string "trencar la defensa més forta!\p"
	.string "Per això, t'has guanyat aquest\n"
	.string "Pokémon... Hitmonlee!$"

SaffronCity_Dojo_EventScript_HitmonleeParty::
	call SaffronCity_Dojo_EventScript_GetHitmonlee
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_GotHitmonlee
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SaffronCity_Dojo_EventScript_GotHitmonlee
	end

SaffronCity_Dojo_EventScript_GetHitmonlee::
	playfanfare MUS_LEVEL_UP
	message SaffronCity_Dojo_EventScript_Text_EarnedHitmonlee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_HITMONLEE
	return

SaffronCity_Dojo_EventScript_Text_EarnedHitmonlee::
	.string "{PLAYER} ha dominat l'art de la\n"
	.string "Defensa i s'ha guanyat el\l"
	.string "Hitmonlee del Dojo!$"

SaffronCity_Dojo_EventScript_GotHitmonlee::
	setflag FLAG_RECEIVED_HITMONLEE
	releaseall
	end

SaffronCity_Dojo_EventScript_HitmonleePC::
	call SaffronCity_Dojo_EventScript_GetHitmonlee
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_TransferHitmonlee
	call Common_EventScript_NameReceivedBoxMon
	goto SaffronCity_Dojo_EventScript_TransferHitmonlee
	end

SaffronCity_Dojo_EventScript_TransferHitmonlee::
	call Common_EventScript_TransferredToPC
	goto SaffronCity_Dojo_EventScript_GotHitmonlee
	end

SaffronCity_Dojo_EventScript_NoRoomForPokemon::
	msgbox SaffronCity_Dojo_Text_NoRoomForMorePokemon, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_NoRoomForMorePokemon::
    .string "Oh! No tens espai per a més\n"
    .string "Pokémon!$"

SaffronCity_Dojo_EventScript_Statue::
	msgbox SaffronCity_Dojo_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_Dojo_Text_FightingDojo::
    .string "Dojo de Lluita$"

SaffronCity_Dojo_EventScript_LeftScroll::
	msgbox SaffronCity_Dojo_Text_StrongOffense, MSGBOX_SIGN
	end

SaffronCity_Dojo_Text_StrongOffense::
    .string "Una ofensiva forta és\n"
    .string "la clau de la victòria!$"

SaffronCity_Dojo_EventScript_RightScroll::
	msgbox SaffronCity_Dojo_Text_StrongDefense, MSGBOX_SIGN
	end

SaffronCity_Dojo_Text_StrongDefense::
    .string "Una defensa forta és\n"
    .string "la clau de la supervivència!$"


SaffronCity_Dojo_EventScript_FreshWater::
	msgbox SaffronCity_Dojo_Text_SureAmThirsty, MSGBOX_DEFAULT
	checkitem ITEM_FRESH_WATER
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Dojo_EventScript_CouldUseADrink
	msgbox SaffronCity_Dojo_Text_CanIHaveThat, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_CouldUseADrink
	playse MUS_RG_HEAL
	waitse
	removeitem ITEM_FRESH_WATER
	return

SaffronCity_Dojo_EventScript_CouldUseADrink::
	msgbox SaffronCity_Dojo_Text_CouldUseADrink, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_SureAmThirsty:
	.string "L'entrenament Pokémon esgota!\p"
	.string "M'he de refrescar abans de\n"
	.string "poder fer una altra ronda...$"

SaffronCity_Dojo_Text_CanIHaveThat:
	.string "Oh! Tens Aigua Fresca!\p"
	.string "Me'n podries donar una mica?$"

SaffronCity_Dojo_Text_CouldUseADrink:
	.string "Bé que em caldria una beguda...$"

SaffronCity_Dojo_Text_HitsThatSpot:
	.string "Uau, gràcies!\p"
	.string "GLUP GLUP GLUP\p"
	.string "Ahhhhhhh....\p"
	.string "Això és el que necessitava!\p"
	.string "Em sento preparat per un altre\n"
	.string "combat!$"

SaffronCity_Dojo_EventScript_BattleLater::
	msgbox SaffronCity_Dojo_Text_BattleLater, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_PupilIntro:
	.string "D'acord! Et mostraré el que\n"
	.string "el meu sensei m'ha ensenyat!$"

SaffronCity_Dojo_Text_PupilDefeat:
	.string "No he estat a la teva alçada.$"

SaffronCity_Dojo_Text_AGoodWorkout:
	.string "Encara em queda molt per fer.\n"
	.string "Ha estat un bon entrenament.$"

SaffronCity_Dojo_Text_AttackPupil:
	.string "Estudio les arts del Mestre\n"
	.string "de l'Ofensiva!\p"
	.string "Els atacs físics són els\n"
	.string "moviments més poderosos, i seré\l"
	.string "el més fort de tot Kanto!\p"
	.string "Vols desafiar-me?$"

SaffronCity_Dojo_Text_DefensePupil:
	.string "Estudio les arts del Mestre\n"
	.string "de la Defensa!\p"
	.string "Els atacs físics no poden ni\n"
	.string "trencar la meva defensa, i seré\l"
	.string "el més fort de tot Kanto!\p"
	.string "Vols desafiar-me?$"

SaffronCity_Dojo_Text_SpAttackPupil:
	.string "Estudio les arts del Mestre\n"
	.string "de l'Ofensiva!\p"
	.string "Els atacs especials són els\n"
	.string "moviments més poderosos, i seré\l"
	.string "el més fort de tot Kanto!\p"
	.string "Vols desafiar-me?$"

SaffronCity_Dojo_Text_SpDefensePupil:
	.string "Estudio les arts del Mestre\n"
	.string "de la Defensa!\p"
	.string "Els atacs especials no poden ni\n"
	.string "trencar la meva defensa, i seré\l"
	.string "el més fort de tot Kanto!\p"
	.string "Vols desafiar-me?$"

SaffronCity_Dojo_Text_SpeedPupil:
	.string "Estudio les arts del Mestre\n"
	.string "de l'Ofensiva!\p"
	.string "La velocitat és el factor més\n"
	.string "important en combat, i seré\l"
	.string "el més fort de tot Kanto!\p"
	.string "Vols desafiar-me?$"

SaffronCity_Dojo_Text_HpPupil:
	.string "Estudio les arts del Mestre\n"
	.string "de la Defensa!\p"
	.string "Tenir més PS que l'oponent és\n"
	.string "el factor més important en\l"
	.string "combat, i seré el més fort\l"
	.string "de tot Kanto!\p"
	.string "Vols desafiar-me?$"

SaffronCity_Dojo_Text_BattleLater:
	.string "Si vols ser el millor, has de\n"
	.string "treballar-hi!$"

SaffronCity_Dojo_EventScript_AttackPupil::
	lock
	faceplayer
	goto_if_set FLAG_DOJO_ATTACK, SaffronCity_Dojo_EventScript_AttackPupilThirsty
	msgbox SaffronCity_Dojo_Text_AttackPupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_ATTACK, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledAttack
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_SpAttackPupil::
	lock
	faceplayer
	goto_if_set FLAG_DOJO_SPATTACK, SaffronCity_Dojo_EventScript_SpAttackPupilThirsty
	msgbox SaffronCity_Dojo_Text_SpAttackPupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_SPATTACK, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledSPAttack
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_SpeedPupil::
	lock
	faceplayer
	goto_if_set FLAG_DOJO_SPEED, SaffronCity_Dojo_EventScript_SpeedPupilThirsty
	msgbox SaffronCity_Dojo_Text_SpeedPupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_SPEED, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledSpeed
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_DefensePupil::
	lock
	faceplayer
	goto_if_set FLAG_DOJO_DEFENSE, SaffronCity_Dojo_EventScript_DefensePupilThirsty
	msgbox SaffronCity_Dojo_Text_DefensePupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_DEFENSE, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledDefense
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_SpDefensePupil::
	lock
	faceplayer
	goto_if_set FLAG_DOJO_SPDEFENSE, SaffronCity_Dojo_EventScript_DefensePupilThirsty
	msgbox SaffronCity_Dojo_Text_SpDefensePupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_SPDEFENSE, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledSPDefense
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_HpPupil::
	lock
	faceplayer
	goto_if_set FLAG_DOJO_HP, SaffronCity_Dojo_EventScript_HpPupilThirsty
	msgbox SaffronCity_Dojo_Text_HpPupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_HP, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledHP
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_AttackPupilThirsty::
	call SaffronCity_Dojo_EventScript_FreshWater
	clearflag FLAG_DOJO_ATTACK
	cleartrainerflag SPARRING_PARTNER_ATTACK
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	goto SaffronCity_Dojo_EventScript_AttackPupil
	end

SaffronCity_Dojo_EventScript_SpAttackPupilThirsty::
	call SaffronCity_Dojo_EventScript_FreshWater
	clearflag FLAG_DOJO_SPATTACK
	cleartrainerflag SPARRING_PARTNER_SPATTACK
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_EventScript_SpeedPupilThirsty::
	call SaffronCity_Dojo_EventScript_FreshWater
	clearflag FLAG_DOJO_SPEED
	cleartrainerflag SPARRING_PARTNER_SPEED
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_EventScript_DefensePupilThirsty::
	call SaffronCity_Dojo_EventScript_FreshWater
	clearflag FLAG_DOJO_DEFENSE
	cleartrainerflag SPARRING_PARTNER_DEFENSE
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_EventScript_SpDefensePupilThirsty::
	call SaffronCity_Dojo_EventScript_FreshWater
	clearflag FLAG_DOJO_SPDEFENSE
	cleartrainerflag SPARRING_PARTNER_SPDEFENSE
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_EventScript_HpPupilThirsty::
	call SaffronCity_Dojo_EventScript_FreshWater
	clearflag FLAG_DOJO_HP
	cleartrainerflag SPARRING_PARTNER_HP
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_BattledAttack::
	setflag FLAG_DOJO_ATTACK
	setflag FLAG_DOJO_OFFENSE_1
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledSPAttack::
	setflag FLAG_DOJO_SPATTACK
	setflag FLAG_DOJO_OFFENSE_2
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledSpeed::
	setflag FLAG_DOJO_SPEED
	setflag FLAG_DOJO_OFFENSE_3
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledDefense::
	setflag FLAG_DOJO_DEFENSE
	setflag FLAG_DOJO_DEFENSE_1
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledSPDefense::
	setflag FLAG_DOJO_SPDEFENSE
	setflag FLAG_DOJO_DEFENSE_2
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledHP::
	setflag FLAG_DOJO_HP
	setflag FLAG_DOJO_DEFENSE_3
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_ExpertBelt::
	msgbox SaffronCity_Dojo_Text_ExpertBelt, MSGBOX_DEFAULT
	goto_if_unset FLAG_RECEIVED_HITMONCHAN, SaffronCity_Dojo_Unworthy
	goto_if_unset FLAG_RECEIVED_HITMONLEE, SaffronCity_Dojo_Unworthy
	giveitem ITEM_EXPERT_BELT
	removeobject LOCALID_BELT
	release
	end

SaffronCity_Dojo_Text_ExpertBelt::
	.string "Aquest Cinturó demostra que ets\n"
	.string "un mestre dels combats Pokémon.$"

SaffronCity_Dojo_Unworthy::
	msgbox SaffronCity_Dojo_Text_Unworthy, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_Unworthy::
	.string "No et sents digne d'agafar-lo.$"


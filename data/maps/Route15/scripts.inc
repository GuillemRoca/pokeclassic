Route15_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route15_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route15_OnResume
	.byte 0

Route15_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route15_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route15_EventScript_Olivia::
	trainerbattle_single REMATCHABLE_TRAINER_BEAUTY_OLIVIA_1, Route15_Text_OliviaIntro, Route15_Text_OliviaDefeat, Route15_EventScript_RegisterOliviaAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route15_EventScript_OliviaRematch
	msgbox Route15_Text_OliviaPostBattle, MSGBOX_DEFAULT
	release
	end

Route15_Text_OliviaIntro::
    .string "Crio Pokémon per protecció\n"
    .string "perquè visc sola.$"

Route15_Text_OliviaDefeat::
    .string "Per a mi, Pokémon no va de\n"
    .string "guanyar o perdre.$"

Route15_Text_OliviaPostBattle::
    .string "M'encanta que els meus Pokémon\n"
    .string "em rebin quan arribo a casa.\p"
    .string "És molt reconfortant.$"

Route15_EventScript_RegisterOliviaAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_OliviaRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_BEAUTY_OLIVIA_1
	release
	end

Route15_Text_OliviaRegister:
	.string "Em dones el teu número?\p"
	.string "Et podria trucar si necessito\n"
	.string "més protecció.$"

Route15_EventScript_OliviaRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_BEAUTY_OLIVIA_1, Route15_Text_OliviaRematchIntro, Route15_Text_OliviaDefeat
	msgbox Route15_Text_OliviaRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_OliviaRematchIntro::
	.string "Encara visc sola, així que he\n"
	.string "d'entrenar els meus Pokémon.$"

Route15_Text_OliviaRematchPostBattle::
	.string "Potser hauria de buscar un altre\n"
	.string "pis...$"

Route15_EventScript_Grace::
	trainerbattle_single TRAINER_BEAUTY_GRACE, Route15_Text_GraceIntro, Route15_Text_GraceDefeat
	msgbox Route15_Text_GracePostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_GraceIntro::
    .string "Oh, ets molt bufó!\n"
    .string "Com un Pokémon adorable!$"

Route15_Text_GraceDefeat::
    .string "Semblaves tan bufó!$"

Route15_Text_GracePostBattle::
    .string "Et perdono.\n"
    .string "Ho puc suportar.\l"
    .string "Ja sóc gran.$"

Route15_EventScript_Ernest::
	trainerbattle_single TRAINER_BIKER_ERNEST, Route15_Text_ErnestIntro, Route15_Text_ErnestDefeat
	msgbox Route15_Text_ErnestPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_ErnestIntro::
    .string "Ei, nano! Vine!\n"
    .string "Acabo de treure'ls a un pringat!$"

Route15_Text_ErnestDefeat::
    .string "Per què no?$"

Route15_Text_ErnestPostBattle::
    .string "La vida és curta.\n"
    .string "Mola viure com un fora de la llei.\l"
    .string "Visca l'Equip Rocket!$"

Route15_EventScript_Alex::
	trainerbattle_single TRAINER_BIKER_ALEX, Route15_Text_AlexIntro, Route15_Text_AlexDefeat
	msgbox Route15_Text_AlexPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_AlexIntro::
    .string "Dóna'm tots els diners quan\n"
    .string "perdis, nano!$"

Route15_Text_AlexDefeat::
    .string "No pot ser veritat!$"

Route15_Text_AlexPostBattle::
    .string "Estava broma amb els diners.\n"
    .string "No m'agafis tan seriosament.$"

Route15_EventScript_Edwin::
	trainerbattle_single TRAINER_BIRD_KEEPER_EDWIN, Route15_Text_EdwinIntro, Route15_Text_EdwinDefeat
	msgbox Route15_Text_EdwinPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_EdwinIntro::
    .string "Quan xiulo, puc cridar Pokémon\n"
    .string "ocell.$"

Route15_Text_EdwinDefeat::
    .string "Au!\n"
    .string "Quin drama!$"

Route15_Text_EdwinPostBattle::
    .string "Potser no estic fet per combatre.\n"
    .string "No sóc del tipus adequat.$"

Route15_EventScript_Chester::
	trainerbattle_single TRAINER_BIRD_KEEPER_CHESTER, Route15_Text_ChesterIntro, Route15_Text_ChesterDefeat
	msgbox Route15_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_ChesterIntro::
    .string "Hmm? Els meus ocells tremolen!\n"
    .string "Ets bo, oi?$"

Route15_Text_ChesterDefeat::
    .string "Tal com pensava!$"

Route15_Text_ChesterPostBattle::
    .string "Això és obvi, ho hauries de\n"
    .string "saber, però…\p"
    .string "Moviments com Terratrèmol i\n"
    .string "Fissura no afecten Pokémon ocell.$"

Route15_EventScript_Yazmin::
	trainerbattle_single TRAINER_PICNICKER_YAZMIN, Route15_Text_YazminIntro, Route15_Text_YazminDefeat
	msgbox Route15_Text_YazminPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_YazminIntro::
    .string "Vols jugar amb els meus Pokémon?$"

Route15_Text_YazminDefeat::
    .string "He estat massa impacient!$"

Route15_Text_YazminPostBattle::
    .string "Aniré a entrenar amb gent\n"
    .string "més feble.$"

Route15_EventScript_Kindra::
	trainerbattle_single TRAINER_PICNICKER_KINDRA, Route15_Text_KindraIntro, Route15_Text_KindraDefeat
	msgbox Route15_Text_KindraPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_KindraIntro::
    .string "Acabo d'aconseguir Pokémon per\n"
    .string "intercanvi. Puc provar-los?$"

Route15_Text_KindraDefeat::
    .string "No n'hi ha prou!$"

Route15_Text_KindraPostBattle::
    .string "No pots canviar el malnom d'un\n"
    .string "Pokémon d'intercanvi.\p"
    .string "Només l'Entrenador Original pot\n"
    .string "canviar el malnom.$"

Route15_EventScript_Becky::
	trainerbattle_single TRAINER_PICNICKER_BECKY, Route15_Text_BeckyIntro, Route15_Text_BeckyDefeat
	msgbox Route15_Text_BeckyPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_BeckyIntro::
    .string "Sembles amable, així que crec\n"
    .string "que et puc guanyar.\p"
    .string "Ho provaré!$"

Route15_Text_BeckyDefeat::
    .string "No, error!$"

Route15_Text_BeckyPostBattle::
    .string "Em fan por els Motoristes. Tenen\n"
    .string "una pinta tan lletja i dolenta!$"

Route15_EventScript_Celia::
	trainerbattle_single TRAINER_PICNICKER_CELIA, Route15_Text_CeliaIntro, Route15_Text_CeliaDefeat
	msgbox Route15_Text_CeliaPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_CeliaIntro::
    .string "Què mola i està de moda?\n"
    .string "Intercanviar Pokémon!$"

Route15_Text_CeliaDefeat::
    .string "He dit intercanviar!$"

Route15_Text_CeliaPostBattle::
    .string "Intercanvio Pokémon amb les\n"
    .string "amigues tot el temps.$"

Route15_EventScript_Mya::
	trainerbattle_double TRAINER_CRUSH_KIN_RON_MYA, Route15_Text_MyaIntro, Route15_Text_MyaDefeat, Route15_Text_MyaNotEnoughMons
	msgbox Route15_Text_MyaPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_MyaIntro::
    .string "Mya: Ets perfecte.\n"
    .string "M'ajudes a entrenar el germanet?$"

Route15_Text_MyaDefeat::
    .string "Mya: Ron, t'has de concentrar!\n"
    .string "Posa atenció al que fas!$"

Route15_Text_MyaPostBattle::
    .string "Mya: D'acord, augmentarem\n"
    .string "l'entrenament!$"

Route15_Text_MyaNotEnoughMons::
    .string "Mya: Vols desafiar-nos?\n"
    .string "Necessitaràs dos Pokémon.$"

Route15_EventScript_Ron::
	trainerbattle_double TRAINER_CRUSH_KIN_RON_MYA, Route15_Text_RonIntro, Route15_Text_RonDefeat, Route15_Text_RonNotEnoughMons
	msgbox Route15_Text_RonPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_RonIntro::
    .string "Ron: La meva germana fa por\n"
    .string "quan perdem.$"

Route15_Text_RonDefeat::
    .string "Ron: Oh, no, no…\n"
    .string "Germana, ho sento!$"

Route15_Text_RonPostBattle::
    .string "Ron: Oh, puaj…\n"
    .string "M'agradaria tenir una germana\l"
    .string "amable…$"

Route15_Text_RonNotEnoughMons::
    .string "Ron: Volies combatre amb la meva\n"
    .string "germana i jo?\p"
    .string "Necessites dos Pokémon.$"

Route15_EventScript_RouteSign::
	msgbox Route15_Text_RouteSign, MSGBOX_SIGN
	end

Route15_Text_RouteSign::
    .string "Ruta 15\n"
    .string "Oest cap a Ciutat Fúcsia$"

Route15_EventScript_ItemTM18::
	finditem ITEM_TM18, 1
	release
	end

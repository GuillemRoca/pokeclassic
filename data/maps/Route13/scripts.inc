Route13_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route13_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route13_OnResume
	.byte 0

Route13_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route13_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route13_EventScript_TrainerTips1::
	msgbox Route13_Text_LookToLeftOfThatPost, MSGBOX_SIGN
	end

Route13_Text_LookToLeftOfThatPost::
    .string "Consells d'Entrenador:\p"
    .string "Mira, mira!\n"
    .string "Mira a l'esquerra d'aquell pal!$"

Route13_EventScript_TrainerTips2::
	msgbox Route13_Text_SelectToSwitchItems, MSGBOX_SIGN
	end

Route13_Text_SelectToSwitchItems::
    .string "Consells d'Entrenador:\p"
    .string "Fes servir Select per canviar\n"
    .string "objectes a la finestra.$"

Route13_EventScript_RouteSign::
	msgbox Route13_Text_RouteSign, MSGBOX_SIGN
	end

Route13_Text_RouteSign::
    .string "RUTA 13\n"
    .string "Nord cap al Pont del Silenci$"

Route13_EventScript_Lola::
	trainerbattle_single TRAINER_BEAUTY_LOLA, Route13_Text_LolaIntro, Route13_Text_LolaDefeat
	msgbox Route13_Text_LolaPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_LolaIntro::
    .string "Sí, jugaré amb tu, bonic.$"

Route13_Text_LolaDefeat::
    .string "Oh!\n"
    .string "Petita bèstia!$"

Route13_Text_LolaPostBattle::
    .string "Em pregunto què és més fort,\n"
    .string "un Pokémon mascle o femella?$"

Route13_EventScript_Sheila::
	trainerbattle_single TRAINER_BEAUTY_SHEILA, Route13_Text_SheilaIntro, Route13_Text_SheilaDefeat
	msgbox Route13_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_SheilaIntro::
    .string "Vols combatre amb Pokémon\n"
    .string "amb mi?$"

Route13_Text_SheilaDefeat::
    .string "Ja s'ha acabat?$"

Route13_Text_SheilaPostBattle::
    .string "En realitat no sé res de\n"
    .string "Pokémon.\p"
    .string "Els que tinc… els vaig triar\n"
    .string "per l'aspecte!$"

Route13_EventScript_Jared::
	trainerbattle_single TRAINER_BIKER_JARED, Route13_Text_JaredIntro, Route13_Text_JaredDefeat
	msgbox Route13_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_JaredIntro::
    .string "Què mires?$"

Route13_Text_JaredDefeat::
    .string "Llamps!\n"
    .string "S'ha fotut la marxa!$"

Route13_Text_JaredPostBattle::
    .string "Fes-te perdedís!$"

Route13_EventScript_Sebastian::
	trainerbattle_single TRAINER_BIRD_KEEPER_SEBASTIAN, Route13_Text_SebastianIntro, Route13_Text_SebastianDefeat
	msgbox Route13_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_SebastianIntro::
    .string "Els meus Pokémon ocell volen\n"
    .string "combatre amb tu!$"

Route13_Text_SebastianDefeat::
    .string "El meu combo Pidgey i Pidgeotto\n"
    .string "ha perdut?$"

Route13_Text_SebastianPostBattle::
    .string "Els meus Pokémon semblen contents\n"
    .string "tot i haver perdut.$"


Route13_EventScript_Perry::
	trainerbattle_single TRAINER_BIRD_KEEPER_PERRY, Route13_Text_PerryIntro, Route13_Text_PerryDefeat
	msgbox Route13_Text_PerryPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_PerryIntro::
    .string "No perdré.\n"
    .string "No quan el vent bufa a favor!$"

Route13_Text_PerryDefeat::
    .string "El vent ha girat!$"

Route13_Text_PerryPostBattle::
    .string "Estic destrossat.\n"
    .string "Suposo que volaré cap a casa.$"

Route13_EventScript_Robert::
	trainerbattle_single TRAINER_BIRD_KEEPER_ROBERT, Route13_Text_RobertIntro, Route13_Text_RobertDefeat
	msgbox Route13_Text_RobertPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_RobertIntro::
    .string "Sempre vaig amb Pokémon ocell.\n"
    .string "M'hi he dedicat en cos i ànima.$"

Route13_Text_RobertDefeat::
    .string "Sense energia!$"

Route13_Text_RobertPostBattle::
    .string "M'agradaria poder volar com\n"
    .string "Pidgey i Pidgeotto…$"

Route13_EventScript_Alma::
	trainerbattle_single TRAINER_PICNICKER_ALMA, Route13_Text_AlmaIntro, Route13_Text_AlmaDefeat
	msgbox Route13_Text_AlmaPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_AlmaIntro::
    .string "Vaig trobar un carbos en una\n"
    .string "cova mentre feia espeleologia.$"

Route13_Text_AlmaDefeat::
    .string "Oh, quina llàstima!\n"
    .string "He ficat la pota!$"

Route13_Text_AlmaPostBattle::
    .string "El Carbos va augmentar la\n"
    .string "velocitat del meu Pokémon.$"

Route13_EventScript_Susie::
	trainerbattle_single TRAINER_PICNICKER_SUSIE, Route13_Text_SusieIntro, Route13_Text_SusieDefeat
	msgbox Route13_Text_SusiePostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_SusieIntro::
    .string "Em diuen que sóc bona per ser\n"
    .string "una nena.$"

Route13_Text_SusieDefeat::
    .string "Ohh!\n"
    .string "He perdut!$"

Route13_Text_SusiePostBattle::
    .string "Vull ser una bona entrenadora.\n"
    .string "Entrenaré fort, ja ho veuràs.$"

Route13_EventScript_Valerie::
	trainerbattle_single TRAINER_PICNICKER_VALERIE, Route13_Text_ValerieIntro, Route13_Text_ValerieDefeat
	msgbox Route13_Text_ValeriePostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_ValerieIntro::
    .string "Uau!\n"
    .string "Les teves medalles són genials!$"

Route13_Text_ValerieDefeat::
    .string "No n'hi ha prou!$"

Route13_Text_ValeriePostBattle::
    .string "Has aconseguit les Medalles dels\n"
    .string "Líders de Gimnàs. Ho sé!$"

Route13_EventScript_Gwen::
	trainerbattle_single TRAINER_PICNICKER_GWEN, Route13_Text_GwenIntro, Route13_Text_GwenDefeat
	msgbox Route13_Text_GwenPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_GwenIntro::
    .string "Els meus Pokémon bufons volen\n"
    .string "conèixer-te.$"

Route13_Text_GwenDefeat::
    .string "Ben fet!\n"
    .string "Has guanyat del tot!$"

Route13_Text_GwenPostBattle::
    .string "Has de fer combatre els Pokémon\n"
    .string "per endurir-los.$"

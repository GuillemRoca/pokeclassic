MtMoon_1F_MapScripts::
	.byte 0

MtMoon_1F_EventScript_ZubatSign::
	msgbox MtMoon_1F_Text_ZubatIsABloodsucker, MSGBOX_SIGN
	end

MtMoon_1F_Text_ZubatIsABloodsucker::
    .string "Alerta!\n"
    .string "Zubat xucla la sang!$"

MtMoon_1F_EventScript_Macros::
	trainerbattle_single TRAINER_HIKER_MARCOS, MtMoon_1F_Text_MarcosIntro, MtMoon_1F_Text_MarcosDefeat
	msgbox MtMoon_1F_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_Text_MarcosIntro::
    .string "UAU!\n"
    .string "M'has espantat!\l"
    .string "…Oh, si només ets un nen!$"

MtMoon_1F_Text_MarcosDefeat::
    .string "Uau!\n"
    .string "Espantat un altre cop!$"

MtMoon_1F_Text_MarcosPostBattle::
    .string "Els nens com tu no haurien\n"
    .string "de rondar per aquí a les fosques.$"

MtMoon_1F_EventScript_Josh::
	trainerbattle_single TRAINER_YOUNGSTER_JOSH, MtMoon_1F_Text_JoshIntro, MtMoon_1F_Text_JoshDefeat
	msgbox MtMoon_1F_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_Text_JoshIntro::
    .string "Has vingut a explorar la cova\n"
    .string "també?$"

MtMoon_1F_Text_JoshDefeat::
    .string "Perdre fa ràbia!\n"
    .string "No mola gens.$"

MtMoon_1F_Text_JoshPostBattle::
    .string "He vingut fins aquí baix per\n"
    .string "impressionar les noies.$"


MtMoon_1F_EventScript_Miriam::
	trainerbattle_single TRAINER_LASS_MIRIAM, MtMoon_1F_Text_MiriamIntro, MtMoon_1F_Text_MiriamDefeat
	msgbox MtMoon_1F_Text_MiriamPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_Text_MiriamIntro::
    .string "Uau! Això és molt més gran del\n"
    .string "que pensava!$"

MtMoon_1F_Text_MiriamDefeat::
    .string "Oh!\n"
    .string "He perdut!$"

MtMoon_1F_Text_MiriamPostBattle::
    .string "Com se surt d'aquí?\n"
    .string "És tan gran que em podria perdre.$"

MtMoon_1F_EventScript_Iris::
	trainerbattle_single TRAINER_LASS_IRIS, MtMoon_1F_Text_IrisIntro, MtMoon_1F_Text_IrisDefeat
	msgbox MtMoon_1F_Text_IrisPostBattle, MSGBOX_AUTOCLOSE
	end


MtMoon_1F_Text_IrisIntro::
    .string "Què?\n"
    .string "Estic esperant que els meus amics\l"
    .string "em trobin aquí.$"

MtMoon_1F_Text_IrisDefeat::
    .string "He perdut?$"

MtMoon_1F_Text_IrisPostBattle::
    .string "He vingut perquè he sentit que\n"
    .string "hi ha fòssils molt rars aquí.$"

MtMoon_1F_EventScript_Jovan::
	trainerbattle_single TRAINER_SUPER_NERD_JOVAN, MtMoon_1F_Text_JovanIntro, MtMoon_1F_Text_JovanDefeat
	msgbox MtMoon_1F_Text_JovanPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_Text_JovanIntro::
    .string "Ei!\n"
    .string "No m'agafis per sorpresa!$"

MtMoon_1F_Text_JovanDefeat::
    .string "Els meus POKéMON no serveixen!$"

MtMoon_1F_Text_JovanPostBattle::
    .string "He de trobar POKéMON més forts.\n"
    .string "On deuen ser?$"

MtMoon_1F_EventScript_Kent::
	trainerbattle_single TRAINER_BUG_CATCHER_KENT, MtMoon_1F_Text_KentIntro, MtMoon_1F_Text_KentDefeat
	msgbox MtMoon_1F_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_Text_KentIntro::
    .string "Hi ha homes sospitosos a la cova.\n"
    .string "I tu, què?$"

MtMoon_1F_Text_KentDefeat::
    .string "M'has pillat!$"

MtMoon_1F_Text_KentPostBattle::
    .string "Els he vist!\n"
    .string "Segur que són de l'Equip Rocket!$"

MtMoon_1F_EventScript_Robby::
	trainerbattle_single TRAINER_BUG_CATCHER_ROBBY, MtMoon_1F_Text_RobbyIntro, MtMoon_1F_Text_RobbyDefeat
	msgbox MtMoon_1F_Text_RobbyPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_Text_RobbyIntro::
    .string "Has de travessar aquesta cova\n"
    .string "per arribar a Ciutat Celeste.$"

MtMoon_1F_Text_RobbyDefeat::
    .string "He perdut.$"

MtMoon_1F_Text_RobbyPostBattle::
    .string "Zubat és dur!\n"
    .string "Però si en captures un, podràs\l"
    .string "comptar-hi.$"

MtMoon_1F_EventScript_BaldingMan::
    msgbox MtMoon_1F_Text_BrockHelpsExcavateFossils, MSGBOX_NPC
    release
    end

MtMoon_1F_Text_BrockHelpsExcavateFossils::
    .string "Hola, estic excavant fòssils\n"
    .string "aquí al Mont Moon.\p"
    .string "De vegades, en Brock del Gimnàs\n"
    .string "de Pewter m'ajuda.$"

MtMoon_1F_EventScript_ItemParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL, 1
	end

MtMoon_1F_EventScript_ItemTM09::
	finditem ITEM_TM09, 1
	end

MtMoon_1F_EventScript_ItemPotion::
	finditem ITEM_POTION, 1
	end

MtMoon_1F_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY, 1
	end

MtMoon_1F_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE, 1
	end

MtMoon_1F_EventScript_ItemMoonStone::
	finditem ITEM_MOON_STONE, 1
	end

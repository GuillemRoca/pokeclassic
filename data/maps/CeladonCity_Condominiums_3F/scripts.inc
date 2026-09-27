CeladonCity_Condominiums_3F_MapScripts::
	.byte 0

CeladonCity_Condominiums_3F_EventScript_Programmer::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheProgrammer, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_Text_ImTheProgrammer::
    .string "Jo?\n"
    .string "Sóc el Fotògraf!$"

CeladonCity_Condominiums_3F_EventScript_GraphicArtist::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist::
    .string "Sóc el dissenyador gràfic!\n"
    .string "T'agrada el Diari Pokémon?$"

CeladonCity_Condominiums_3F_EventScript_Writer::
	msgbox CeladonCity_Condominiums_3F_Text_IWroteTheStory, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_Text_IWroteTheStory::
    .string "Jo escric els articles!\n"
    .string "No trobes que l'Erika és maca?\p"
    .string "La Misty també m'agrada molt!\n"
    .string "Oh, i la Sabrina, m'encanta!$"

CeladonCity_Condominiums_3F_EventScript_Designer::
	lock
	faceplayer
	specialvar VAR_RESULT, HasAllHoennMons
	compare VAR_RESULT, TRUE
	goto_if_eq CeladonCity_Condominiums_3F_EventScript_CompletedPokedex
	msgbox CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex
	release
	end

CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex::
    .string "Sóc l'Editor!\p"
    .string "Estàs treballant en la Pokédex?\n"
    .string "És cert?\p"
    .string "Completar la Pokédex és difícil,\n"
    .string "però no ho deixis!\p"
    .string "Quan acabis, vine a dir-m'ho!\p"
    .string "Escriurem un article sobre tu!$"

CeladonCity_Condominiums_3F_EventScript_CompletedPokedex::
	goto CeladonCity_Condominiums_3F_EventScript_ShowDiploma
	end

CeladonCity_Condominiums_3F_EventScript_ShowDiploma::
	message CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations
	waitmessage
	delay 60
	special ShowDiploma
	waitstate
	release
	end

CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations::
    .string "Uau! Excel·lent!\n"
    .string "Has completat la Pokédex!\l"
    .string "Felicitats!\l"
    .string "…$"

CeladonCity_Condominiums_3F_EventScript_DevelopmentRoomSign::
	msgbox CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom::
    .string "SEU DEL DIARI POKéMON$"

CeladonCity_Condominiums_3F_EventScript_Computer1::
	msgbox CeladonCity_Condominiums_3F_Text_ItsTheGameProgram, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_Text_ItsTheGameProgram::
    .string "És un reportatge sobre el Team\n"
    .string "Rocket!\p"
    .string "Sembla que tenien algú infiltrat\n"
    .string "a l'organització!$"

CeladonCity_Condominiums_3F_EventScript_Computer2::
	msgbox CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame::
    .string "Algú està jugant a un joc en\n"
    .string "comptes de treballar!$"

CeladonCity_Condominiums_3F_EventScript_Computer3::
	msgbox CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding::
    .string "És el proper número!\n"
    .string "El Professor Oak és a la portada!$"

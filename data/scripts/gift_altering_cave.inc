MysteryGiftScript_AlteringCave::
	setvaddress MysteryGiftScript_AlteringCave
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	vgoto_if_ne VAR_ALTERING_CAVE_WILD_SET, (NUM_ALTERING_CAVE_TABLES + 1), MysteryGiftScript_AlteringCave_
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
MysteryGiftScript_AlteringCave_:
	lock
	faceplayer
	vmessage sText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftAlteringCave:
	.string "Gràcies per utilitzar el sistema\n"
	.string "de Regal Misteriós.\p"
	.string "Sembla que hi ha un rumor sobre\n"
	.string "aparicions de Pokémon rars.\p"
	.string "Les aparicions provenen suposadament\n"
	.string "de la Cova Canviant a la Ruta 103.\p"
	.string "Potser valdria la pena que\n"
	.string "investiguessis aquest rumor.$"

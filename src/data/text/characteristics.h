static const u8 sCharacteristic00[] = _("Li encanta menjar.");
static const u8 sCharacteristic01[] = _("Orgullós de la seva força.");
static const u8 sCharacteristic02[] = _("Cos robust.");
static const u8 sCharacteristic03[] = _("Li agrada córrer.");
static const u8 sCharacteristic04[] = _("Molt curiós.");
static const u8 sCharacteristic05[] = _("De voluntat forta.");
static const u8 sCharacteristic06[] = _("Fa moltes migdiades.");	//Is "Often dozes off" in Gens 4 and 5
static const u8 sCharacteristic07[] = _("Li agrada rebolcar-se.");
static const u8 sCharacteristic08[] = _("Capaç d'aguantar cops.");
static const u8 sCharacteristic09[] = _("Atent als sorolls.");
static const u8 sCharacteristic10[] = _("Entremaliat.");
static const u8 sCharacteristic11[] = _("Una mica vanitós.");
static const u8 sCharacteristic12[] = _("S'adorm sovint.");			//Is "Often scatters things" in Gens 4 and 5
static const u8 sCharacteristic13[] = _("Una mica geniüt.");
static const u8 sCharacteristic14[] = _("Molt persistent.");
static const u8 sCharacteristic15[] = _("Impetuós i ximple.");
static const u8 sCharacteristic16[] = _("Molt astut.");
static const u8 sCharacteristic17[] = _("Molt desafiant.");
static const u8 sCharacteristic18[] = _("Ho escampa tot sovint.");
static const u8 sCharacteristic19[] = _("Li agrada lluitar.");
static const u8 sCharacteristic20[] = _("Bona resistència.");
static const u8 sCharacteristic21[] = _("Una mica pallasso.");
static const u8 sCharacteristic22[] = _("Sovint distret.");
static const u8 sCharacteristic23[] = _("Odia perdre.");
static const u8 sCharacteristic24[] = _("Li agrada relaxar-se.");
static const u8 sCharacteristic25[] = _("Geniüt.");
static const u8 sCharacteristic26[] = _("Molt perseverant.");
static const u8 sCharacteristic27[] = _("Fuig de seguida.");
static const u8 sCharacteristic28[] = _("Molt exigent.");
static const u8 sCharacteristic29[] = _("Una mica tossut.");

static const u8 sFlavorSpicy[] = _("Li agrada el menjar {COLOR 5}{SHADOW 6}picant{COLOR 7}{SHADOW 8}.");
static const u8 sFlavorDry[] = _("Li agrada el menjar {COLOR 5}{SHADOW 6}sec{COLOR 7}{SHADOW 8}.");
static const u8 sFlavorSweet[] = _("Li agrada el menjar {COLOR 5}{SHADOW 6}dolç{COLOR 7}{SHADOW 8}.");
static const u8 sFlavorBitter[] = _("Li agrada el menjar {COLOR 5}{SHADOW 6}amarg{COLOR 7}{SHADOW 8}.");
static const u8 sFlavorSour[] = _("Li agrada el menjar {COLOR 5}{SHADOW 6}àcid{COLOR 7}{SHADOW 8}.");
static const u8 sFlavorNeutral[] = _("Menja de tot content.");

const u8 *const gCharacteristicPointers[30] = 
{
    sCharacteristic00,
	sCharacteristic01,
    sCharacteristic02,
	sCharacteristic03,
    sCharacteristic04,
	sCharacteristic05,
    sCharacteristic06,
	sCharacteristic07,
    sCharacteristic08,
	sCharacteristic09,
    sCharacteristic10,
	sCharacteristic11,
    sCharacteristic12,
	sCharacteristic13,
    sCharacteristic14,
	sCharacteristic15,
    sCharacteristic16,
	sCharacteristic17,
    sCharacteristic18,
	sCharacteristic19,
    sCharacteristic20,
	sCharacteristic21,
    sCharacteristic22,
	sCharacteristic23,
    sCharacteristic24,
	sCharacteristic25,
    sCharacteristic26,
	sCharacteristic27,
    sCharacteristic28,
	sCharacteristic29,
};

const u8 *const gNatureFlavorPointers[25] =
{
	[NATURE_HARDY]   = sFlavorNeutral,
	[NATURE_LONELY]  = sFlavorSpicy,
	[NATURE_BRAVE]   = sFlavorSpicy,
	[NATURE_ADAMANT] = sFlavorSpicy,
	[NATURE_NAUGHTY] = sFlavorSpicy,
	[NATURE_BOLD]    = sFlavorSour,
	[NATURE_DOCILE]  = sFlavorNeutral,
	[NATURE_RELAXED] = sFlavorSour,
	[NATURE_IMPISH]  = sFlavorSour,
	[NATURE_LAX]     = sFlavorSour,
	[NATURE_TIMID]   = sFlavorSweet,
	[NATURE_HASTY]   = sFlavorSweet,
	[NATURE_SERIOUS] = sFlavorNeutral,
	[NATURE_JOLLY]   = sFlavorSweet,
	[NATURE_NAIVE]   = sFlavorSweet,
	[NATURE_MODEST]  = sFlavorDry,
	[NATURE_MILD]    = sFlavorDry,
	[NATURE_QUIET]   = sFlavorDry,
	[NATURE_BASHFUL] = sFlavorNeutral,
	[NATURE_RASH]    = sFlavorDry,
	[NATURE_CALM]    = sFlavorBitter,
	[NATURE_GENTLE]  = sFlavorBitter,
	[NATURE_SASSY]   = sFlavorBitter,
	[NATURE_CAREFUL] = sFlavorBitter,
	[NATURE_QUIRKY]  = sFlavorNeutral,
};

#define REGION_UNKNOWN	0
#define REGION_KANTO	1
#define REGION_HOENN	2
#define REGION_ORRE		3

//Battle Tower from Ruby/Sapphire
#define MAPSEC_BATTLE_TOWER					0xFC

//Orre met locations
#define MAPSEC_DISTANT_LAND					0x00
#define MAPSEC_OUTSKIRT_STAND				0x01
#define MAPSEC_PHENAC_CITY					0x02
#define MAPSEC_MAYORS_HOUSE					0x03
#define MAPSEC_PRE_GYM						0x04
#define MAPSEC_PHENAC_STADIUM				0x05
#define MAPSEC_PYRITE_TOWN					0x06
#define MAPSEC_PYRITE_BLDG					0x07
#define MAPSEC_PYRITE_CAVE					0x08
#define MAPSEC_MIRORS_HIDEOUT				0x09
#define MAPSEC_PYRITE_COLOSSEUM				0x10
#define MAPSEC_AGATE_VILLAGE				0x11
#define MAPSEC_RELIC_CAVE					0x12
#define MAPSEC_THE_UNDER					0x13
#define MAPSEC_THE_UNDER_SUBWAY				0x14
#define MAPSEC_UNDER_COLOSSEUM				0x15
#define MAPSEC_DEEP_COLOSSEUM				0x16
#define MAPSEC_FRONT_OF_LAB					0x17
#define MAPSEC_LABORATORY					0x18
#define MAPSEC_MT_BATTLE					0x19
#define MAPSEC_MTBTL_COLOSSEUM				0x20
#define MAPSEC_REALGAM_TOWER				0x21
#define MAPSEC_REALGAMTWR_DOME				0x22
#define MAPSEC_REALGAMTWR_LOBBY				0x23
#define MAPSEC_TOWER_COLOSSEUM				0x24
#define MAPSEC_ORRE_COLOSSEUM				0x25
#define MAPSEC_SNAGEM_HIDEOUT				0x26
#define MAPSEC_REALGAM_TOWER_2F				0x27
#define MAPSEC_CIPHER_LAB					0x28
#define MAPSEC_S_S_LIBRA					0x29
#define MAPSEC_CIPHER_KEY_LAIR				0x30
#define MAPSEC_CITADARK_ISLE				0x31
#define MAPSEC_ROCK							0x32
#define MAPSEC_OASIS						0x33
#define MAPSEC_CAVE							0x34
#define MAPSEC_POKEMON_HQ_LAB				0x35
#define MAPSEC_GATEON_PORT					0x36
#define MAPSEC_KAMINKOS_HOUSE				0x37

#define ORRE_MAPSEC_START					MAPSEC_DISTANT_LAND
#define ORRE_MAPSEC_END						MAPSEC_KAMINKOS_HOUSE
#define ORRE_MAPSEC_COUNT				    (ORRE_MAPSEC_END - ORRE_MAPSEC_START + 1)

#if CONFIG_DECAPITALIZE_MET_LOCATION_STRINGS
static const u8 sRegionString_Unknown[] = _("");
static const u8 sRegionString_Kanto[] = _(", Kanto");
static const u8 sRegionString_Hoenn[] = _("");
static const u8 sRegionString_Orre[] = _(", Orre");
#else
static const u8 sRegionString_Unknown[] = _("");
static const u8 sRegionString_Kanto[] = _(", KANTO");
static const u8 sRegionString_Hoenn[] = _("");
static const u8 sRegionString_Orre[] = _(", ORRE");
#endif

const u8 *const gRegionStringPointers[] =
{
	[REGION_UNKNOWN] = sRegionString_Unknown,
	[REGION_KANTO]   = sRegionString_Kanto,
	[REGION_HOENN]   = sRegionString_Hoenn,
	[REGION_ORRE]    = sRegionString_Orre,
};

const u8 gText_TrainerMemo_Standard[] = _(
    "Naturalesa {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}.\n"
    "\n"
    "{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 5}{DYNAMIC 1}\n"
    "Trobat al {LV_2}{DYNAMIC 3}.\n"
    "\n"
    "{DYNAMIC 6}\n"
    "{DYNAMIC 7}");
const u8 gText_TrainerMemo_Hatched[] = _(
    "Naturalesa {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}.\n"
    "\n"
    "{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 5}{DYNAMIC 1}\n"
    "Nascut al {LV_2}{DYNAMIC 3}.\n"
    "\n"
    "{DYNAMIC 6}\n"
    "{DYNAMIC 7}");
const u8 gText_TrainerMemo_Trade[] = _(
    "Naturalesa {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}.\n"
    "\n"
    "Obtingut en {DYNAMIC 0}un intercanvi{DYNAMIC 1}.\n"
    "\n"
    "\n"
    "{DYNAMIC 6}\n"
    "{DYNAMIC 7}");
const u8 gText_TrainerMemo_Fateful[] = _(
    "Naturalesa {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}.\n"
    "\n"
    "Obtingut en una\n"
    "{DYNAMIC 0}trobada del destí{DYNAMIC 1} al {LV_2}{DYNAMIC 3}.\n"
    "{DYNAMIC 6}\n"
    "{DYNAMIC 7}");
const u8 gText_TrainerMemo_Untrusted[] = _(
    "Naturalesa {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}.\n"
    "\n"
    "{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 5}{DYNAMIC 1}\n"
    "Sembla trobat al {LV_2}{DYNAMIC 3}.\n"
    "\n"
    "{DYNAMIC 6}\n"
    "{DYNAMIC 7}");
const u8 gText_TrainerMemo_HatchedUntrusted[] = _(
    "Naturalesa {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}.\n"
    "\n"
    "{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 5}{DYNAMIC 1}\n"
    "Sembla nascut al {LV_2}{DYNAMIC 3}.\n"
    "\n"
    "{DYNAMIC 6}\n"
    "{DYNAMIC 7}");
#if CONFIG_DECAPITALIZE_MET_LOCATION_STRINGS
const u8 gText_TrainerMemo_EggFromDayCare[] = _(
    "Un Ou de Pokémon estrany trobat\n"
    "per {DYNAMIC 0}la parella de la Guarderia{DYNAMIC 1}.\n"
    "\n"
    "\n"
    "“Vigilància de l'Ou”\n"
    "{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggTraded[] = _(
    "Un Ou de Pokémon peculiar\n"
    "obtingut en un intercanvi.\n"
    "\n"
    "\n"
    "“Vigilància de l'Ou”\n"
    "{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFateful[] = _(
    "Un Ou de Pokémon peculiar\n"
    "obtingut en {DYNAMIC 0}un lloc bonic{DYNAMIC 1}.\n"
    "\n"
    "\n"
    "“Vigilància de l'Ou”\n"
    "{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFatefulTraded[] = _(
    "Un Ou de Pokémon peculiar\n"
    "obtingut en un intercanvi.\n"
    "\n"
    "\n"
    "“Vigilància de l'Ou”\n"
    "{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromHotSprings[] = _(
    "Un Ou de Pokémon obtingut\n"
    "a {DYNAMIC 0}les fonts termals{DYNAMIC 1}.\n"
    "\n"
    "\n"
    "“Vigilància de l'Ou”\n"
    "{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromTraveler[] = _(
    "Un Ou de Pokémon estrany\n"
    "obtingut d'{DYNAMIC 0}un viatger{DYNAMIC 1}.\n"
    "\n"
    "\n"
    "“Vigilància de l'Ou”\n"
    "{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromKanto[] = _(
    "Un Ou de Pokémon estrany trobat\n"
    "per {DYNAMIC 0}la parella de la Guarderia{DYNAMIC 1}\n"
    "a la regió de {DYNAMIC 0}Kanto{DYNAMIC 1}.\n"
    "\n"
    "“Vigilància de l'Ou”\n"
    "{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromBrigette[] = _(
    "Un Ou de Pokémon obtingut\n"
    "de {DYNAMIC 0}Brigette{DYNAMIC 1}.\n"
    "\n"
    "\n"
    "“Vigilància de l'Ou”\n"
    "{DYNAMIC 2}");
const u8 gText_TrainerMemo_BadEgg[] = _(
    "Un Ou de Pokémon\n"
    "molt misteriós.\n"
    "\n"
    "\n"
    "“Vigilància de l'Ou”\n"
    "{DYNAMIC 2}");
const u8 gText_TrainerMemo_OldFriend[] = _(
    "Naturalesa {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1},\n"
    "\n"
    "vell amic de {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}\n"
    "d'{DYNAMIC 0}Orre{DYNAMIC 1}.\n"
    "\n"
    "{DYNAMIC 6}\n"
    "{DYNAMIC 7}");
const u8 gText_TrainerMemo_ReceivedFrom[] = _(
    "Naturalesa {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1},\n"
    "\n"
    "rebut de {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}\n"
    "a {DYNAMIC 0}Orre{DYNAMIC 1}.\n"
    "\n"
    "{DYNAMIC 6}\n"
    "{DYNAMIC 7}");
const u8 gText_TrainerMemo_ObtainedFromDad[] = _(
    "Naturalesa {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1},\n"
    "\n"
    "donat a {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1} pel seu pare\n"
    "a {DYNAMIC 0}Orre{DYNAMIC 1}.\n"
    "\n"
    "{DYNAMIC 6}\n"
    "{DYNAMIC 7}");

//Battle Tower from Ruby/Sapphire
const u8 gMapName_BattleTower[] = _("Torre de Combat");

//Orre met locations
static const u8 sMapName_DistantLand[] = _("Terra Llunyana");
static const u8 sMapName_OutskirtStand[] = _("Parada Afores");
static const u8 sMapName_PhenacCity[] = _("Ciutat de Phenac");
static const u8 sMapName_MayorsHouse[] = _("Casa de l'Alcalde");
static const u8 sMapName_PreGym[] = _("Pregimnàs");
static const u8 sMapName_PhenacStadium[] = _("Estadi de Phenac");
static const u8 sMapName_PyriteTown[] = _("Poble de Pyrite");
static const u8 sMapName_PyriteBldg[] = _("Edifici Pyrite");
static const u8 sMapName_PyriteCave[] = _("Cova de Pyrite");
static const u8 sMapName_MirorsHideout[] = _("Cau de Miror");
static const u8 sMapName_PyriteColosseum[] = _("Colisseu Pyrite");
static const u8 sMapName_AgateVillage[] = _("Vila d'Agate");
static const u8 sMapName_RelicCave[] = _("Cova de Relíquies");
static const u8 sMapName_TheUnder[] = _("El Subsòl");
static const u8 sMapName_TheUnderSubway[] = _("Metro del Subsòl");
static const u8 sMapName_UnderColosseum[] = _("Colisseu Subsòl");
static const u8 sMapName_DeepColosseum[] = _("Colisseu Profund");
static const u8 sMapName_FrontOfLab[] = _("Davant del Lab.");
static const u8 sMapName_Laboratory[] = _("Laboratori");
static const u8 sMapName_MtBattle[] = _("Mt. Combat");
static const u8 sMapName_MtBtlColosseum[] = _("Colisseu Mt.Comb");
static const u8 sMapName_RealgamTower[] = _("Torre Realgam");
static const u8 sMapName_RealgamTwrDome[] = _("Cúpula Realgam");
static const u8 sMapName_RealgamTwrLobby[] = _("Rebedor Realgam");
static const u8 sMapName_TowerColosseum[] = _("Colisseu Torre");
static const u8 sMapName_OrreColosseum[] = _("Colisseu d'Orre");
static const u8 sMapName_SnagemHideout[] = _("Cau de Snagem");
static const u8 sMapName_RealgamTower2F[] = _("Torre Realgam 2P");
static const u8 sMapName_CipherLab[] = _("Lab. Cipher");
static const u8 sMapName_SSLibra[] = _("S.S. Libra");
static const u8 sMapName_CipherKeyLair[] = _("Cau Clau Cipher");
static const u8 sMapName_CitadarkIsle[] = _("Illa Citadark");
static const u8 sMapName_Rock[] = _("Roca");
static const u8 sMapName_Oasis[] = _("Oasi");
static const u8 sMapName_Cave[] = _("Cova");
static const u8 sMapName_PokemonHQLab[] = _("Lab. Central Pkmn");
static const u8 sMapName_GateonPort[] = _("Port de Gateon");
static const u8 sMapName_KaminkosHouse[] = _("Casa de Kaminko");
#else
const u8 gText_TrainerMemo_EggFromDayCare[] = _("An odd POKéMON EGG found\nby {DYNAMIC 0}the DAY CARE couple{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggTraded[] = _("An peculiar POKéMON EGG\nobtained in a trade.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFateful[] = _("A peculiar POKéMON EGG\nobtained at {DYNAMIC 0}a nice place{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFatefulTraded[] = _("A peculiar POKéMON EGG\nobtained in a trade.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromHotSprings[] = _("A POKéMON EGG obtained\nat {DYNAMIC 0}the hot springs{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromTraveler[] = _("An odd POKéMON EGG\nobtained from {DYNAMIC 0}a traveler{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromKanto[] = _("An odd POKéMON EGG found\nby {DYNAMIC 0}the DAY CARE couple{DYNAMIC 1}\nin the {DYNAMIC 0}KANTO{DYNAMIC 1} region.\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromBrigette[] = _("A POKéMON EGG obtained\nfrom {DYNAMIC 0}BRIGETTE{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_BadEgg[] = _("A very mysterious\nPOKéMON EGG.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_OldFriend[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature,\n\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}'s old friend\nfrom {DYNAMIC 0}ORRE{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_ReceivedFrom[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature,\n\nreceived from {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}\nin {DYNAMIC 0}ORRE{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_ObtainedFromDad[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature,\n\ngiven to {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1} by his dad\nin {DYNAMIC 0}ORRE{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");


//Battle Tower from Ruby/Sapphire
const u8 gMapName_BattleTower[] = _("TORRE DE COMBAT");

//Orre met locations
static const u8 sMapName_DistantLand[] = _("TERRA LLUNYANA");
static const u8 sMapName_OutskirtStand[] = _("PARADA AFORES");
static const u8 sMapName_PhenacCity[] = _("CIUTAT DE PHENAC");
static const u8 sMapName_MayorsHouse[] = _("CASA DE L'ALCALDE");
static const u8 sMapName_PreGym[] = _("PREGIMNÀS");
static const u8 sMapName_PhenacStadium[] = _("ESTADI DE PHENAC");
static const u8 sMapName_PyriteTown[] = _("POBLE DE PYRITE");
static const u8 sMapName_PyriteBldg[] = _("EDIFICI PYRITE");
static const u8 sMapName_PyriteCave[] = _("COVA DE PYRITE");
static const u8 sMapName_MirorsHideout[] = _("CAU DE MIROR");
static const u8 sMapName_PyriteColosseum[] = _("COLISSEU PYRITE");
static const u8 sMapName_AgateVillage[] = _("VILA D'AGATE");
static const u8 sMapName_RelicCave[] = _("COVA DE RELÍQUIES");
static const u8 sMapName_TheUnder[] = _("EL SUBSÒL");
static const u8 sMapName_TheUnderSubway[] = _("METRO DEL SUBSÒL");
static const u8 sMapName_UnderColosseum[] = _("COLISSEU SUBSÒL");
static const u8 sMapName_DeepColosseum[] = _("COLISSEU PROFUND");
static const u8 sMapName_FrontOfLab[] = _("DAVANT DEL LAB.");
static const u8 sMapName_Laboratory[] = _("LABORATORI");
static const u8 sMapName_MtBattle[] = _("MT. COMBAT");
static const u8 sMapName_MtBtlColosseum[] = _("COLISSEU MT.COMB");
static const u8 sMapName_RealgamTower[] = _("TORRE REALGAM");
static const u8 sMapName_RealgamTwrDome[] = _("CÚPULA REALGAM");
static const u8 sMapName_RealgamTwrLobby[] = _("REBEDOR REALGAM");
static const u8 sMapName_TowerColosseum[] = _("COLISSEU TORRE");
static const u8 sMapName_OrreColosseum[] = _("COLISSEU D'ORRE");
static const u8 sMapName_SnagemHideout[] = _("CAU DE SNAGEM");
static const u8 sMapName_RealgamTower2F[] = _("TORRE REALGAM 2P");
static const u8 sMapName_CipherLab[] = _("LAB. CIPHER");
static const u8 sMapName_SSLibra[] = _("S.S. LIBRA");
static const u8 sMapName_CipherKeyLair[] = _("CAU CLAU CIPHER");
static const u8 sMapName_CitadarkIsle[] = _("ILLA CITADARK");
static const u8 sMapName_Rock[] = _("ROCA");
static const u8 sMapName_Oasis[] = _("OASI");
static const u8 sMapName_Cave[] = _("COVA");
static const u8 sMapName_PokemonHQLab[] = _("LAB. CENTRAL PKMN");
static const u8 sMapName_GateonPort[] = _("PORT DE GATEON");
static const u8 sMapName_KaminkosHouse[] = _("CASA DE KAMINKO");
#endif

const u8 *const gOrreMapNamePointers[] =
{
	[MAPSEC_DISTANT_LAND]               = sMapName_DistantLand,
	[MAPSEC_OUTSKIRT_STAND]             = sMapName_OutskirtStand,
	[MAPSEC_PHENAC_CITY]                = sMapName_PhenacCity,
	[MAPSEC_MAYORS_HOUSE]               = sMapName_MayorsHouse,
	[MAPSEC_PRE_GYM]                    = sMapName_PreGym,
	[MAPSEC_PHENAC_STADIUM]             = sMapName_PhenacStadium,
	[MAPSEC_PYRITE_TOWN]                = sMapName_PyriteTown,
	[MAPSEC_PYRITE_BLDG]                = sMapName_PyriteBldg,
	[MAPSEC_PYRITE_CAVE]                = sMapName_PyriteCave,
	[MAPSEC_MIRORS_HIDEOUT]             = sMapName_MirorsHideout,
	[MAPSEC_PYRITE_COLOSSEUM]           = sMapName_PyriteColosseum,
	[MAPSEC_AGATE_VILLAGE]              = sMapName_AgateVillage,
	[MAPSEC_RELIC_CAVE]                 = sMapName_RelicCave,
	[MAPSEC_THE_UNDER]                  = sMapName_TheUnder,
	[MAPSEC_THE_UNDER_SUBWAY]           = sMapName_TheUnderSubway,
	[MAPSEC_UNDER_COLOSSEUM]            = sMapName_UnderColosseum,
	[MAPSEC_DEEP_COLOSSEUM]             = sMapName_DeepColosseum,
	[MAPSEC_FRONT_OF_LAB]               = sMapName_FrontOfLab,
	[MAPSEC_LABORATORY]                 = sMapName_Laboratory,
	[MAPSEC_MT_BATTLE]                  = sMapName_MtBattle,
	[MAPSEC_MTBTL_COLOSSEUM]            = sMapName_MtBtlColosseum,
	[MAPSEC_REALGAM_TOWER]              = sMapName_RealgamTower,
	[MAPSEC_REALGAMTWR_DOME]            = sMapName_RealgamTwrDome,
	[MAPSEC_REALGAMTWR_LOBBY]           = sMapName_RealgamTwrLobby,
	[MAPSEC_TOWER_COLOSSEUM]            = sMapName_TowerColosseum,
	[MAPSEC_ORRE_COLOSSEUM]             = sMapName_OrreColosseum,
	[MAPSEC_SNAGEM_HIDEOUT]             = sMapName_SnagemHideout,
	[MAPSEC_REALGAM_TOWER_2F]           = sMapName_RealgamTower2F,
	[MAPSEC_CIPHER_LAB]                 = sMapName_CipherLab,
	[MAPSEC_S_S_LIBRA]                  = sMapName_SSLibra,
	[MAPSEC_CIPHER_KEY_LAIR]            = sMapName_CipherKeyLair,
	[MAPSEC_CITADARK_ISLE]              = sMapName_CitadarkIsle,
	[MAPSEC_ROCK]                       = sMapName_Rock,
	[MAPSEC_OASIS]                      = sMapName_Oasis,
	[MAPSEC_CAVE]                       = sMapName_Cave,
	[MAPSEC_POKEMON_HQ_LAB]             = sMapName_PokemonHQLab,
	[MAPSEC_GATEON_PORT]                = sMapName_GateonPort,
	[MAPSEC_KAMINKOS_HOUSE]             = sMapName_KaminkosHouse
};

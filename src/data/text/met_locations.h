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

const u8 gText_TrainerMemo_Standard[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} naturalesa.\n\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 5}{DYNAMIC 1}\nTrobat al {LV_2}{DYNAMIC 3}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_Hatched[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} naturalesa.\n\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 5}{DYNAMIC 1}\nNascut al {LV_2}{DYNAMIC 3}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_Trade[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} naturalesa.\n\nObtingut en {DYNAMIC 0}un intercanvi{DYNAMIC 1}.\n\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_Fateful[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} naturalesa.\n\nObtingut en una\n{DYNAMIC 0}trobada del destí{DYNAMIC 1} al {LV_2}{DYNAMIC 3}.\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_Untrusted[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} naturalesa.\n\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 5}{DYNAMIC 1}\nAparentment trobat al {LV_2}{DYNAMIC 3}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_HatchedUntrusted[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} naturalesa.\n\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 5}{DYNAMIC 1}\nAparentment nascut al {LV_2}{DYNAMIC 3}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
#if CONFIG_DECAPITALIZE_MET_LOCATION_STRINGS
const u8 gText_TrainerMemo_EggFromDayCare[] = _(“Un Ou Pokémon estrany trobat\nper {DYNAMIC 0}la parella de la Guarderia{DYNAMIC 1}.\n\n\n«La Guarda de l'Ou»\n{DYNAMIC 2}”);
const u8 gText_TrainerMemo_EggTraded[] = _(“Un Ou Pokémon peculiar\nobtingut en un intercanvi.\n\n\n«La Guarda de l'Ou»\n{DYNAMIC 2}”);
const u8 gText_TrainerMemo_EggFateful[] = _(“Un Ou Pokémon peculiar\nobtingut a {DYNAMIC 0}un lloc especial{DYNAMIC 1}.\n\n\n«La Guarda de l'Ou»\n{DYNAMIC 2}”);
const u8 gText_TrainerMemo_EggFatefulTraded[] = _(“Un Ou Pokémon peculiar\nobtingut en un intercanvi.\n\n\n«La Guarda de l'Ou»\n{DYNAMIC 2}”);
const u8 gText_TrainerMemo_EggFromHotSprings[] = _(“Un Ou Pokémon obtingut\na {DYNAMIC 0}les aigües termals{DYNAMIC 1}.\n\n\n«La Guarda de l'Ou»\n{DYNAMIC 2}”);
const u8 gText_TrainerMemo_EggFromTraveler[] = _(“Un Ou Pokémon estrany\nobtingut d'{DYNAMIC 0}un viatger{DYNAMIC 1}.\n\n\n«La Guarda de l'Ou»\n{DYNAMIC 2}”);
const u8 gText_TrainerMemo_EggFromKanto[] = _(“Un Ou Pokémon estrany trobat\nper {DYNAMIC 0}la parella de la Guarderia{DYNAMIC 1}\na la regió de {DYNAMIC 0}Kanto{DYNAMIC 1}.\n\n«La Guarda de l'Ou»\n{DYNAMIC 2}”);
const u8 gText_TrainerMemo_EggFromBrigette[] = _(“Un Ou Pokémon obtingut\nde la {DYNAMIC 0}Brigette{DYNAMIC 1}.\n\n\n«La Guarda de l'Ou»\n{DYNAMIC 2}”);
const u8 gText_TrainerMemo_BadEgg[] = _(“Un Ou Pokémon\nmolt misteriós.\n\n\n«La Guarda de l'Ou»\n{DYNAMIC 2}”);
const u8 gText_TrainerMemo_OldFriend[] = _(“{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} naturalesa,\n\nvell amic de {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}\nd'{DYNAMIC 0}Orre{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}”);
const u8 gText_TrainerMemo_ReceivedFrom[] = _(“{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} naturalesa,\n\nrebut de {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}\na {DYNAMIC 0}Orre{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}”);
const u8 gText_TrainerMemo_ObtainedFromDad[] = _(“{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} naturalesa,\n\ndonat a {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1} pel seu pare\na {DYNAMIC 0}Orre{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}”);

//Battle Tower from Ruby/Sapphire
const u8 gMapName_BattleTower[] = _(“Torre de Combat”);

//Orre met locations
static const u8 sMapName_DistantLand[] = _(“Una Terra Llunyana”);
static const u8 sMapName_OutskirtStand[] = _(“Outskirt Stand”);
static const u8 sMapName_PhenacCity[] = _(“Phenac City”);
static const u8 sMapName_MayorsHouse[] = _(“Casa del Batlle”);
static const u8 sMapName_PreGym[] = _(“Pre Gimnàs”);
static const u8 sMapName_PhenacStadium[] = _(“Phenac Stadium”);
static const u8 sMapName_PyriteTown[] = _(“Pyrite Town”);
static const u8 sMapName_PyriteBldg[] = _(“Pyrite Bldg”);
static const u8 sMapName_PyriteCave[] = _(“Pyrite Cave”);
static const u8 sMapName_MirorsHideout[] = _(“Amagatall Miror”);
static const u8 sMapName_PyriteColosseum[] = _(“Pyrite Colosseum”);
static const u8 sMapName_AgateVillage[] = _(“Agate Village”);
static const u8 sMapName_RelicCave[] = _(“Cova de les Relíquies”);
static const u8 sMapName_TheUnder[] = _(“The Under”);
static const u8 sMapName_TheUnderSubway[] = _(“Metro de The Under”);
static const u8 sMapName_UnderColosseum[] = _(“Under Colosseum”);
static const u8 sMapName_DeepColosseum[] = _(“Deep Colosseum”);
static const u8 sMapName_FrontOfLab[] = _(“Davant del Lab”);
static const u8 sMapName_Laboratory[] = _(“Laboratori”);
static const u8 sMapName_MtBattle[] = _(“Mt. Battle”);
static const u8 sMapName_MtBtlColosseum[] = _(“Mt.Btl Colosseum”);
static const u8 sMapName_RealgamTower[] = _(“Realgam Tower”);
static const u8 sMapName_RealgamTwrDome[] = _(“Realgamtwr Dome”);
static const u8 sMapName_RealgamTwrLobby[] = _(“Realgamtwr Lobby”);
static const u8 sMapName_TowerColosseum[] = _(“Tower Colosseum”);
static const u8 sMapName_OrreColosseum[] = _(“Orre Colosseum”);
static const u8 sMapName_SnagemHideout[] = _(“Snagem Hideout”);
static const u8 sMapName_RealgamTower2F[] = _(“Realgam Tower 2F”);
static const u8 sMapName_CipherLab[] = _(“Cipher Lab”);
static const u8 sMapName_SSLibra[] = _(“S.S. Libra”);
static const u8 sMapName_CipherKeyLair[] = _(“Cipher Key Lair”);
static const u8 sMapName_CitadarkIsle[] = _(“Citadark Isle”);
static const u8 sMapName_Rock[] = _(“Roca”);
static const u8 sMapName_Oasis[] = _(“Oasi”);
static const u8 sMapName_Cave[] = _(“Cova”);
static const u8 sMapName_PokemonHQLab[] = _(“Lab Central Pokémon”);
static const u8 sMapName_GateonPort[] = _(“Gateon Port”);
static const u8 sMapName_KaminkosHouse[] = _(“Casa d'en Kaminko”);
#else
const u8 gText_TrainerMemo_EggFromDayCare[] = _(“Un Ou Pokémon estrany trobat\nper {DYNAMIC 0}la parella de la Guarderia{DYNAMIC 1}.\n\n\n«La Guarda de l'Ou»\n{DYNAMIC 2}”);
const u8 gText_TrainerMemo_EggTraded[] = _(“Un Ou Pokémon peculiar\nobtingut en un intercanvi.\n\n\n«La Guarda de l'Ou»\n{DYNAMIC 2}”);
const u8 gText_TrainerMemo_EggFateful[] = _(“Un Ou Pokémon peculiar\nobtingut a {DYNAMIC 0}un lloc especial{DYNAMIC 1}.\n\n\n«La Guarda de l'Ou»\n{DYNAMIC 2}”);
const u8 gText_TrainerMemo_EggFatefulTraded[] = _(“Un Ou Pokémon peculiar\nobtingut en un intercanvi.\n\n\n«La Guarda de l'Ou»\n{DYNAMIC 2}”);
const u8 gText_TrainerMemo_EggFromHotSprings[] = _(“Un Ou Pokémon obtingut\na {DYNAMIC 0}les aigües termals{DYNAMIC 1}.\n\n\n«La Guarda de l'Ou»\n{DYNAMIC 2}”);
const u8 gText_TrainerMemo_EggFromTraveler[] = _(“Un Ou Pokémon estrany\nobtingut d'{DYNAMIC 0}un viatger{DYNAMIC 1}.\n\n\n«La Guarda de l'Ou»\n{DYNAMIC 2}”);
const u8 gText_TrainerMemo_EggFromKanto[] = _(“Un Ou Pokémon estrany trobat\nper {DYNAMIC 0}la parella de la Guarderia{DYNAMIC 1}\na la regió de {DYNAMIC 0}Kanto{DYNAMIC 1}.\n\n«La Guarda de l'Ou»\n{DYNAMIC 2}”);
const u8 gText_TrainerMemo_EggFromBrigette[] = _(“Un Ou Pokémon obtingut\nde la {DYNAMIC 0}Brigette{DYNAMIC 1}.\n\n\n«La Guarda de l'Ou»\n{DYNAMIC 2}”);
const u8 gText_TrainerMemo_BadEgg[] = _(“Un Ou Pokémon\nmolt misteriós.\n\n\n«La Guarda de l'Ou»\n{DYNAMIC 2}”);
const u8 gText_TrainerMemo_OldFriend[] = _(“{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} naturalesa,\n\nvell amic de {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}\nd'{DYNAMIC 0}Orre{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}”);
const u8 gText_TrainerMemo_ReceivedFrom[] = _(“{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} naturalesa,\n\nrebut de {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}\na {DYNAMIC 0}Orre{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}”);
const u8 gText_TrainerMemo_ObtainedFromDad[] = _(“{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} naturalesa,\n\ndonat a {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1} pel seu pare\na {DYNAMIC 0}Orre{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}”);


//Battle Tower from Ruby/Sapphire
const u8 gMapName_BattleTower[] = _(“Torre de Combat”);

//Orre met locations
static const u8 sMapName_DistantLand[] = _(“Una Terra Llunyana”);
static const u8 sMapName_OutskirtStand[] = _(“Outskirt Stand”);
static const u8 sMapName_PhenacCity[] = _(“Phenac City”);
static const u8 sMapName_MayorsHouse[] = _(“Casa del Batlle”);
static const u8 sMapName_PreGym[] = _(“Pre Gimnàs”);
static const u8 sMapName_PhenacStadium[] = _(“Phenac Stadium”);
static const u8 sMapName_PyriteTown[] = _(“Pyrite Town”);
static const u8 sMapName_PyriteBldg[] = _(“Pyrite Bldg”);
static const u8 sMapName_PyriteCave[] = _(“Pyrite Cave”);
static const u8 sMapName_MirorsHideout[] = _(“Amagatall Miror”);
static const u8 sMapName_PyriteColosseum[] = _(“Pyrite Colosseum”);
static const u8 sMapName_AgateVillage[] = _(“Agate Village”);
static const u8 sMapName_RelicCave[] = _(“Cova de les Relíquies”);
static const u8 sMapName_TheUnder[] = _(“The Under”);
static const u8 sMapName_TheUnderSubway[] = _(“Metro de The Under”);
static const u8 sMapName_UnderColosseum[] = _(“Under Colosseum”);
static const u8 sMapName_DeepColosseum[] = _(“Deep Colosseum”);
static const u8 sMapName_FrontOfLab[] = _(“Davant del Lab”);
static const u8 sMapName_Laboratory[] = _(“Laboratori”);
static const u8 sMapName_MtBattle[] = _(“Mt. Battle”);
static const u8 sMapName_MtBtlColosseum[] = _(“Mt.Btl Colosseum”);
static const u8 sMapName_RealgamTower[] = _(“Realgam Tower”);
static const u8 sMapName_RealgamTwrDome[] = _(“Realgamtwr Dome”);
static const u8 sMapName_RealgamTwrLobby[] = _(“Realgamtwr Lobby”);
static const u8 sMapName_TowerColosseum[] = _(“Tower Colosseum”);
static const u8 sMapName_OrreColosseum[] = _(“Orre Colosseum”);
static const u8 sMapName_SnagemHideout[] = _(“Snagem Hideout”);
static const u8 sMapName_RealgamTower2F[] = _(“Realgam Tower 2F”);
static const u8 sMapName_CipherLab[] = _(“Cipher Lab”);
static const u8 sMapName_SSLibra[] = _(“S.S. Libra”);
static const u8 sMapName_CipherKeyLair[] = _(“Cipher Key Lair”);
static const u8 sMapName_CitadarkIsle[] = _(“Citadark Isle”);
static const u8 sMapName_Rock[] = _(“Roca”);
static const u8 sMapName_Oasis[] = _(“Oasi”);
static const u8 sMapName_Cave[] = _(“Cova”);
static const u8 sMapName_PokemonHQLab[] = _(“Lab Central Pokémon”);
static const u8 sMapName_GateonPort[] = _(“Gateon Port”);
static const u8 sMapName_KaminkosHouse[] = _(“Casa d'en Kaminko”);
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

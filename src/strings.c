#include "global.h"
#include "strings.h"
#include "battle_pyramid_bag.h"
#include "item_menu.h"

ALIGNED(4)
const u8 gText_ExpandedPlaceholder_Empty[] = _("");
const u8 gText_ExpandedPlaceholder_Kun[] = _("");
const u8 gText_ExpandedPlaceholder_Chan[] = _("");
const u8 gText_ExpandedPlaceholder_Sapphire[] = _("Sapphire");
const u8 gText_ExpandedPlaceholder_Ruby[] = _("Ruby");
const u8 gText_ExpandedPlaceholder_Emerald[] = _("Emerald");
const u8 gText_ExpandedPlaceholder_Aqua[] = _("Aqua");
const u8 gText_ExpandedPlaceholder_Magma[] = _("Magma");
const u8 gText_ExpandedPlaceholder_Archie[] = _("Archie");
const u8 gText_ExpandedPlaceholder_Maxie[] = _("Maxie");
const u8 gText_ExpandedPlaceholder_Kyogre[] = _("Kyogre");
const u8 gText_ExpandedPlaceholder_Groudon[] = _("Groudon");
const u8 gText_ExpandedPlaceholder_Brendan[] = _("Brendan");
const u8 gText_ExpandedPlaceholder_May[] = _("May");
const u8 gText_EggNickname[] = _("Ou");
const u8 gText_Pokemon[] = _("Pokémon");
const u8 gText_MainMenuNewGame[] = _("Partida Nova");
const u8 gText_MainMenuContinue[] = _("Continuar");
const u8 gText_MainMenuOption[] = _("Opcions");
const u8 gText_MainMenuMysteryGift[] = _("Regal Misteriós");
const u8 gText_MainMenuMysteryGift2[] = _("Regal Misteriós");
const u8 gText_MainMenuMysteryEvents[] = _("Fets Misteriosos");
const u8 gText_WirelessNotConnected[] = _(
    "L'adaptador sense fils no\n"
    "està connectat.");
const u8 gText_MysteryGiftCantUse[] = _(
    "No es pot fer servir Regal Misteriós\n"
    "amb l'adaptador sense fils connectat.");
const u8 gText_MysteryEventsCantUse[] = _(
    "No es poden fer servir els Fets\n"
    "Misteriosos amb l'adaptador connectat.");
const u8 gText_UpdatingSaveExternalData[] = _(
    "S'actualitza la partida amb dades\n"
    "externes. Espera un moment."); // Unused
const u8 gText_SaveFileUpdated[] = _("La partida s'ha actualitzat."); // Unused
const u8 gText_SaveFileCorrupted[] = _(
    "La partida està malmesa. Es\n"
    "carregarà la partida anterior.");
const u8 gText_SaveFileErased[] = _(
    "La partida s'ha esborrat perquè\n"
    "estava malmesa o danyada.");
const u8 gJPText_No1MSubCircuit[] = _("1Mサブきばんが ささっていません！");
const u8 gText_BatteryRunDry[] = _(
    "La bateria interna s'ha esgotat.\n"
    "Encara pots jugar.\pPerò els fets basats en el rellotge\n"
    "ja no es produiran.");
const u8 gText_Player[] = _("Jugador"); // Unused
const u8 gText_Pokedex[] = _("Pokédex"); // Unused
const u8 gText_Time[] = _("Temps");
const u8 gText_Badges[] = _("Medalles"); // Unused
const u8 gText_AButton[] = _("Botó A"); // Unused
const u8 gText_BButton[] = _("Botó B"); // Unused
const u8 gText_RButton[] = _("Botó R"); // Unused
const u8 gText_LButton[] = _("Botó L"); // Unused
const u8 gText_Start[] = _("Start"); // Unused
const u8 gText_Select[] = _("Select"); // Unused
const u8 gText_ControlPad[] = _("+ Creueta"); // Unused
const u8 gText_LButtonRButton[] = _("Botó L  Botó R"); // Unused
const u8 gText_Controls[] = _("Controls"); // Unused
ALIGNED(4) const u8 gText_PickOk[] = _("{DPAD_UPDOWN}Tria {A_BUTTON}D'acord"); // Unused
ALIGNED(4) const u8 gText_Next[] = _("{A_BUTTON}Següent"); // Unused
ALIGNED(4) const u8 gText_NextBack[] = _("{A_BUTTON}Següent {B_BUTTON}Enrere"); // Unused
ALIGNED(4) const u8 gText_PickNextCancel[] = _("{DPAD_UPDOWN}Tria {A_BUTTON}Següent {B_BUTTON}Cancel·la");
ALIGNED(4) const u8 gText_PickCancel[] = _("{DPAD_UPDOWN}Tria {A_BUTTON}{B_BUTTON}Cancel·la");
ALIGNED(4) const u8 gText_AButtonExit[] = _("{A_BUTTON}Surt");
const u8 gText_BirchBoy[] = _("Noi");
const u8 gText_BirchGirl[] = _("Noia");
const u8 gText_DefaultNameStu[] = _("Stu");
const u8 gText_DefaultNameMilton[] = _("Milton");
const u8 gText_DefaultNameTom[] = _("Tom");
const u8 gText_DefaultNameKenny[] = _("Kenny");
const u8 gText_DefaultNameReid[] = _("Reid");
const u8 gText_DefaultNameJude[] = _("Jude");
const u8 gText_DefaultNameJaxson[] = _("Jaxson");
const u8 gText_DefaultNameEaston[] = _("Easton");
const u8 gText_DefaultNameWalker[] = _("Walker");
const u8 gText_DefaultNameTeru[] = _("Teru");
const u8 gText_DefaultNameJohnny[] = _("Johnny");
const u8 gText_DefaultNameBrett[] = _("Brett");
const u8 gText_DefaultNameSeth[] = _("Seth");
const u8 gText_DefaultNameTerry[] = _("Terry");
const u8 gText_DefaultNameCasey[] = _("Casey");
const u8 gText_DefaultNameDarren[] = _("Darren");
const u8 gText_DefaultNameLandon[] = _("Landon");
const u8 gText_DefaultNameCollin[] = _("Collin");
const u8 gText_DefaultNameStanley[] = _("Stanley");
const u8 gText_DefaultNameQuincy[] = _("Quincy");
const u8 gText_DefaultNameKimmy[] = _("Kimmy");
const u8 gText_DefaultNameTiara[] = _("Tiara");
const u8 gText_DefaultNameBella[] = _("Bella");
const u8 gText_DefaultNameJayla[] = _("Jayla");
const u8 gText_DefaultNameAllie[] = _("Allie");
const u8 gText_DefaultNameLianna[] = _("Lianna");
const u8 gText_DefaultNameSara[] = _("Sara");
const u8 gText_DefaultNameMonica[] = _("Monica");
const u8 gText_DefaultNameCamila[] = _("Camila");
const u8 gText_DefaultNameAubree[] = _("Aubree");
const u8 gText_DefaultNameRuthie[] = _("Ruthie");
const u8 gText_DefaultNameHazel[] = _("Hazel");
const u8 gText_DefaultNameNadine[] = _("Nadine");
const u8 gText_DefaultNameTanja[] = _("Tanja");
const u8 gText_DefaultNameYasmin[] = _("Yasmin");
const u8 gText_DefaultNameNicola[] = _("Nicola");
const u8 gText_DefaultNameLillie[] = _("Lillie");
const u8 gText_DefaultNameTerra[] = _("Terra");
const u8 gText_DefaultNameLucy[] = _("Lucy");
const u8 gText_DefaultNameHalie[] = _("Halie");

const u8 gText_RivalNameGary[] = _("Gary");
const u8 gText_RivalNameBlue[] = _("Blue");
const u8 gText_RivalNameJohn[] = _("John");
const u8 gText_RivalNameKaz[] = _("Kaz");
const u8 gText_RivalNameToru[] = _("Toru");
const u8 gText_RivalNameKene[] = _("Kene");
const u8 gText_RivalNameGeki[] = _("Geki");
const u8 gText_RivalNameSatoru[] = _("Satoru");
const u8 gText_RivalNameKen[] = _("Ken");

const u8 gText_ThisIsAPokemon[] = _("Aquest món…{PAUSE 96}\p");
const u8 gText_5MarksPokemon[] = _("Pokémon ?????");
const u8 gText_UnkHeight[] = _("{CLEAR_TO 0x0C}??'??”");
const u8 gText_UnkWeight[] = _("????.? lliures");
const u8 gText_EmptyPkmnCategory[] = _("                       Pokémon"); // Unused
const u8 gText_EmptyHeight[] = _("{CLEAR_TO 0x0C}    '    ”"); // Unused
const u8 gText_EmptyWeight[] = _("        .   lliures"); // Unused
const u8 gText_EmptyPokedexInfo1[] = _(""); // Unused
const u8 gText_CryOf[] = _("Crit de");
const u8 gText_EmptyPokedexInfo2[] = _(""); // Unused
const u8 gText_SizeComparedTo[] = _("Mida comparada amb ");
const u8 gText_PokedexRegistration[] = _("Registre al Pokédex completat.");
const u8 gText_HTHeight[] = _("AL");
const u8 gText_WTWeight[] = _("PE");
const u8 gText_SearchingPleaseWait[] = _(
    "S'està cercant…\n"
    "Espera un moment.");
const u8 gText_SearchCompleted[] = _("Cerca acabada.");
const u8 gText_NoMatchingPkmnWereFound[] = _(
    "No s'ha trobat cap Pokémon\n"
    "que hi coincideixi.");
const u8 gText_SearchForPkmnBasedOnParameters[] = _(
    "Cerca Pokémon segons els\n"
    "paràmetres triats.");
const u8 gText_SwitchPokedexListings[] = _("Canvia la llista del Pokédex.");
const u8 gText_ReturnToPokedex[] = _("Torna al Pokédex.");
const u8 gText_SelectPokedexMode[] = _("Tria el mode del Pokédex.");
const u8 gText_SelectPokedexListingMode[] = _("Tria el mode de llista del Pokédex.");
const u8 gText_ListByFirstLetter[] = _(
    "Ordena per la primera lletra del nom.\n"
    "Només Pokémon vistos.");
const u8 gText_ListByBodyColor[] = _(
    "Ordena per color del cos.\n"
    "Només Pokémon vistos.");
const u8 gText_ListByType[] = _(
    "Ordena per tipus.\n"
    "Només Pokémon capturats.");
const u8 gText_ExecuteSearchSwitch[] = _("Executa la cerca o el canvi.");
const u8 gText_DexHoennTitle[] = _("Dex de Kanto");
const u8 gText_DexNatTitle[] = _("Dex Nacional");
const u8 gText_DexSortNumericalTitle[] = _("Mode numèric");
const u8 gText_DexSortAtoZTitle[] = _("Mode A a Z");
const u8 gText_DexSortHeaviestTitle[] = _("Mode més pesat");
const u8 gText_DexSortLightestTitle[] = _("Mode més lleuger");
const u8 gText_DexSortTallestTitle[] = _("Mode més alt");
const u8 gText_DexSortSmallestTitle[] = _("Mode més petit");
const u8 gText_DexSearchAlphaABC[] = _("ABC");
const u8 gText_DexSearchAlphaDEF[] = _("DEF");
const u8 gText_DexSearchAlphaGHI[] = _("GHI");
const u8 gText_DexSearchAlphaJKL[] = _("JKL");
const u8 gText_DexSearchAlphaMNO[] = _("MNO");
const u8 gText_DexSearchAlphaPQR[] = _("PQR");
const u8 gText_DexSearchAlphaSTU[] = _("STU");
const u8 gText_DexSearchAlphaVWX[] = _("VWX");
const u8 gText_DexSearchAlphaYZ[] = _("YZ");
const u8 gText_DexSearchColorRed[] = _("Vermell");
const u8 gText_DexSearchColorBlue[] = _("Blue");
const u8 gText_DexSearchColorYellow[] = _("Groc");
const u8 gText_DexSearchColorGreen[] = _("Verd");
const u8 gText_DexSearchColorBlack[] = _("Negre");
const u8 gText_DexSearchColorBrown[] = _("Marró");
const u8 gText_DexSearchColorPurple[] = _("Lila");
const u8 gText_DexSearchColorGray[] = _("Gris");
const u8 gText_DexSearchColorWhite[] = _("Blanc");
const u8 gText_DexSearchColorPink[] = _("Rosa");
const u8 gText_DexHoennDescription[] = _("Pokédex de la regió de Kanto");
const u8 gText_DexNatDescription[] = _("Pokédex en edició nacional");
const u8 gText_DexSortNumericalDescription[] = _(
    "Els Pokémon s'ordenen segons el\n"
    "seu número.");
const u8 gText_DexSortAtoZDescription[] = _(
    "Els Pokémon vistos i capturats\n"
    "s'ordenen alfabèticament.");
const u8 gText_DexSortHeaviestDescription[] = _(
    "Els Pokémon capturats s'ordenen\n"
    "del més pesat al més lleuger.");
const u8 gText_DexSortLightestDescription[] = _(
    "Els Pokémon capturats s'ordenen\n"
    "del més lleuger al més pesat.");
const u8 gText_DexSortTallestDescription[] = _(
    "Els Pokémon capturats s'ordenen\n"
    "del més alt al més petit.");
const u8 gText_DexSortSmallestDescription[] = _(
    "Els Pokémon capturats s'ordenen\n"
    "del més petit al més alt.");
const u8 gText_DexEmptyString[] = _("");
const u8 gText_DexSearchDontSpecify[] = _("No ho especifiquis.");
const u8 gText_DexSearchTypeNone[] = _("Cap");
const u8 gText_SelectorArrow[] = _("▶");
const u8 gText_EmptySpace[] = _(" "); // Unused
const u8 gText_WelcomeToHOF[] = _("Benvingut al Saló de la Fama!");
const u8 gText_HOFDexRating[] = _(
    "Pokémon vistos: {STR_VAR_1}!\n"
    "Pokémon capturats: {STR_VAR_2}!\pValoració del Pokédex del Prof. Oak!\pProf. Oak: A veure…\p");
const u8 gText_HOFDexSaving[] = _(
    "S'està desant…\n"
    "No apaguis la consola.");
const u8 gText_HOFCorrupted[] = _(
    "Les dades del Saló de la Fama\n"
    "estan malmeses.");
const u8 gText_HOFNumber[] = _("Saló de la Fama núm. {STR_VAR_1}");
const u8 gText_LeagueChamp[] = _(
    "Campió de la Lliga!\n"
    "Enhorabona!");
const u8 gText_Number[] = _("Núm. ");
const u8 gText_Level[] = _("Niv. ");
const u8 gText_IdNumberSlash[] = _("Núm. ID /"); // Unused
const u8 gText_Name[] = _("Nom");
const u8 gText_IDNumber[] = _("Núm. ID");
const u8 gText_BirchInTrouble[] = _(
    "El Prof. Birch està en perill!\n"
    "Treu un Pokémon i salva'l!");
const u8 gText_ConfirmStarterChoice[] = _("Vols triar aquest Pokémon?");
const u8 gText_Pokemon4[] = _("Pokémon"); // Unused
const u8 gText_FlyToWhere[] = _("On vols volar?");
const u8 gMenuText_Use[] = _("Usar");
const u8 gMenuText_Toss[] = _("Llençar");
const u8 gMenuText_Register[] = _("Registrar");
const u8 gMenuText_RegisterL[] = _("Registrar L");
const u8 gMenuText_RegisterR[] = _("Registrar R");
const u8 gMenuText_Give[] = _("Donar");
const u8 gMenuText_CheckTag[] = _("Veure etiqueta");
const u8 gMenuText_Confirm[] = _("Confirmar");
const u8 gMenuText_Walk[] = _("Caminar");
const u8 gText_Cancel[] = _("Cancel·lar");
const u8 gText_Cancel2[] = _("Cancel·lar");
const u8 gMenuText_Show[] = _("Mostrar");
const u8 gText_EmptyString2[] = _("");
const u8 gText_Cancel7[] = _("Cancel·lar"); // Unused
const u8 gText_Item[] = _("Objecte");
const u8 gText_Mail[] = _("Carta");
const u8 gText_Take[] = _("Agafar");
const u8 gText_Store[] = _("Guardar");
const u8 gMenuText_Check[] = _("Comprovar");
const u8 gText_None[] = _("Cap");
const u8 gMenuText_Deselect[] = _("Desmarcar");
const u8 gText_ThreeMarks[] = _("???");
const u8 gText_FiveMarks[] = _("?????");
const u8 gText_Slash[] = _("/");
const u8 gText_OneDash[] = _("-");
const u8 gText_TwoDashes[] = _("--");
const u8 gText_ThreeDashes[] = _("---");
const u8 gText_MaleSymbol[] = _("♂");
const u8 gText_FemaleSymbol[] = _("♀");
const u8 gText_LevelSymbol[] = _("{LV}");
const u8 gText_NumberClear01[] = _("{NO}{CLEAR 0x01}");
const u8 gText_PlusSymbol[] = _("+"); // Unused
const u8 gText_RightArrow[] = _("{RIGHT_ARROW}"); // Unused
const u8 gText_IDNumber2[] = _("{ID}{NO}");
const u8 gText_Space[] = _(" ");
const u8 gText_SelectorArrow2[] = _("▶");
const u8 gText_GoBackPrevMenu[] = _(
    "Torna al menú\n"
    "anterior.");
const u8 gText_WhatWouldYouLike[] = _("Què vols fer?");
const u8 gMenuText_Give2[] = _("Donar");
const u8 gText_xVar1[] = _("×{STR_VAR_1}");
const u8 gText_Berry2[] = _(" Baia"); // Unused
const u8 gText_Coins[] = _("{STR_VAR_1} fitxes");
const u8 gText_CloseBag[] = _("Tanca la motxilla");
const u8 gText_Var1IsSelected[] = _(
    "S'ha triat\n"
    "{STR_VAR_1}.");
const u8 gText_CantWriteMail[] = _(
    "Aquí no pots escriure\n"
    "cartes.");
const u8 gText_NoPokemon[] = _(
    "No hi ha cap\n"
    "Pokémon.");
const u8 gText_MoveVar1Where[] = _(
    "On vols moure\n"
    "{STR_VAR_1}?");
const u8 gText_Var1CantBeHeld[] = _("No es pot portar {STR_VAR_1}.");
const u8 gText_Var1CantBeHeldHere[] = _(
    "Aquí no es pot portar\n"
    "{STR_VAR_1}.");
const u8 gText_DepositHowManyVar1[] = _(
    "Quants {STR_VAR_1}\n"
    "vols dipositar?");
const u8 gText_DepositedVar2Var1s[] = _(
    "S'han dipositat {STR_VAR_2}\n"
    "{STR_VAR_1}.");
const u8 gText_NoRoomForItems[] = _(
    "No hi ha espai per\n"
    "guardar objectes.");
const u8 gText_CantStoreImportantItems[] = _(
    "Els objectes importants\n"
    "no es poden guardar\n"
    "al PC!");
const u8 gText_TooImportantToToss[] = _(
    "Això és massa\n"
    "important per\n"
    "llençar-ho!");
const u8 gText_TossHowManyVar1s[] = _(
    "Quants {STR_VAR_1}\n"
    "vols llençar?");
const u8 gText_ThrewAwayVar2Var1s[] = _(
    "S'han llençat {STR_VAR_2}\n"
    "{STR_VAR_1}.");
const u8 gText_ConfirmTossItems[] = _(
    "Segur que vols\n"
    "llençar {STR_VAR_2}\n"
    "{STR_VAR_1}?");
const u8 gText_DadsAdvice[] = _(
    "Consell de l'Oak…\n"
    "{PLAYER}, cada cosa té el seu\lmoment i el seu lloc!{PAUSE_UNTIL_PRESS}");
const u8 gText_CantDismountBike[] = _("Aquí no pots baixar de la bici.{PAUSE_UNTIL_PRESS}");
const u8 gText_ItemFinderNearby[] = _(
    "Eh?\n"
    "El Cercaobjectes reacciona!\pHi ha un objecte enterrat per aquí!{PAUSE_UNTIL_PRESS}");
const u8 gText_ItemFinderOnTop[] = _(
    "Oh!\n"
    "El Cercaobjectes tremola molt!{PAUSE_UNTIL_PRESS}");
const u8 gText_ItemFinderNothing[] = _(
    "… … … …Res!\n"
    "No hi ha cap reacció.{PAUSE_UNTIL_PRESS}");
const u8 gText_CoinCase[] = _(
    "Les teves fitxes:\n"
    "{STR_VAR_1}{PAUSE_UNTIL_PRESS}");
const u8 gText_BootedUpTM[] = _("S'ha activat una MT.");
const u8 gText_BootedUpHM[] = _("S'ha activat una MO.");
const u8 gText_TMHMContainedVar1[] = _(
    "Contenia\n"
    "{STR_VAR_1}.\pVols ensenyar {STR_VAR_1}\n"
    "a un Pokémon?");
const u8 gText_PlayerUsedVar2[] = _(
    "{PLAYER} ha fet servir\n"
    "{STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
const u8 gText_RepelEffectsLingered[] = _(
    "Però l'efecte d'un Repel·lent\n"
    "encara durava.{PAUSE_UNTIL_PRESS}");
const u8 gText_UsedVar2WildLured[] = _(
    "{PLAYER} ha fet servir\n"
    "{STR_VAR_2}.\pAtraurà els Pokémon salvatges.{PAUSE_UNTIL_PRESS}");
const u8 gText_UsedVar2WildRepelled[] = _(
    "{PLAYER} ha fet servir\n"
    "{STR_VAR_2}.\pRepel·lirà els Pokémon salvatges.{PAUSE_UNTIL_PRESS}");
const u8 gText_BoxFull[] = _("La caixa és plena.{PAUSE_UNTIL_PRESS}");
const u8 gText_PowderQty[] = _("Quantitat de pols: {STR_VAR_1}{PAUSE_UNTIL_PRESS}");
const u8 gText_TheField[] = _("el terreny");
const u8 gText_TheBattle[] = _("el combat");
const u8 gText_ThePokemonList[] = _("la llista de Pokémon");
const u8 gText_TheShop[] = _("la botiga");
const u8 gText_ThePC[] = _("el PC");

const u8 *const gBagMenu_ReturnToStrings[] =
{
    [ITEMMENULOCATION_FIELD]               = gText_TheField,
    [ITEMMENULOCATION_BATTLE]              = gText_TheBattle,
    [ITEMMENULOCATION_PARTY]               = gText_ThePokemonList,
    [ITEMMENULOCATION_SHOP]                = gText_TheShop,
    [ITEMMENULOCATION_BERRY_TREE]          = gText_TheField,
    [ITEMMENULOCATION_BERRY_BLENDER_CRUSH] = gText_TheField,
    [ITEMMENULOCATION_ITEMPC]              = gText_ThePC,
    [ITEMMENULOCATION_FAVOR_LADY]          = gText_TheField,
    [ITEMMENULOCATION_QUIZ_LADY]           = gText_TheField,
    [ITEMMENULOCATION_APPRENTICE]          = gText_TheField,
    [ITEMMENULOCATION_WALLY]               = gText_TheBattle,
    [ITEMMENULOCATION_PCBOX]               = gText_ThePC
};

const u8 *const gPyramidBagMenu_ReturnToStrings[] =
{
    [PYRAMIDBAG_LOC_FIELD]       = gText_TheField,
    [PYRAMIDBAG_LOC_BATTLE]      = gText_TheBattle,
    [PYRAMIDBAG_LOC_PARTY]       = gText_ThePokemonList,
    [PYRAMIDBAG_LOC_CHOOSE_TOSS] = gText_TheField
};

const u8 gText_ReturnToVar1[] = _(
    "Torna a\n"
    "{STR_VAR_1}.");
const u8 gText_ItemsPocket[] = _("Objectes");
const u8 gText_PokeBallsPocket[] = _("Poké Balls");
const u8 gText_TMHMPocket[] = _("MTs i MOs");
const u8 gText_BerriesPocket[] = _("Baies");
const u8 gText_KeyItemsPocket[] = _("Objectes clau");
const u8 gText_MedicinePocket[] = _("Medicines");
const u8 gText_BattleItemsPocket[] = _("Objectes de combat");
const u8 gText_TreasuresPocket[] = _("Tresors");

const u8 *const gPocketNamesStringsTable[] =
{
    [ITEMS_POCKET] = gText_ItemsPocket,
    [MEDICINE_POCKET] = gText_MedicinePocket,
    [BALLS_POCKET] = gText_PokeBallsPocket,
    [BATTLEITEMS_POCKET] = gText_BattleItemsPocket,
    [BERRIES_POCKET] = gText_BerriesPocket,
    [TREASURES_POCKET] = gText_TreasuresPocket,
    [TMHM_POCKET]  = gText_TMHMPocket,
    [KEYITEMS_POCKET] = gText_KeyItemsPocket
};

const u8 gText_NumberItem_TMBerry[] = _("{NO}{STR_VAR_1}{CLEAR 0x07}{STR_VAR_2}");
const u8 gText_NumberItem_HM[] = _("{CLEAR_TO 0x11}{STR_VAR_1}{CLEAR 0x05}{STR_VAR_2}");
const u8 gText_SizeSlash[] = _("Mida /");
const u8 gText_FirmSlash[] = _("Fermesa /");
const u8 gText_Var1DotVar2[] = _("{STR_VAR_1}.{STR_VAR_2}”");

// Berry firmness strings
const u8 gBerryFirmnessString_VerySoft[] = _("Molt tova");
const u8 gBerryFirmnessString_Soft[] = _("Tova");
const u8 gBerryFirmnessString_Hard[] = _("Dura");
const u8 gBerryFirmnessString_VeryHard[] = _("Molt dura");
const u8 gBerryFirmnessString_SuperHard[] = _("Duríssima");

const u8 gText_NumberVar1Var2[] = _("{NO}{STR_VAR_1} {STR_VAR_2}");
const u8 gText_BerryTag[] = _("Etiqueta de baia");
const u8 gText_RedPokeblock[] = _("{POKEBLOCK} vermell");
const u8 gText_BluePokeblock[] = _("{POKEBLOCK} blau");
const u8 gText_PinkPokeblock[] = _("{POKEBLOCK} rosa");
const u8 gText_GreenPokeblock[] = _("{POKEBLOCK} verd");
const u8 gText_YellowPokeblock[] = _("{POKEBLOCK} groc");
const u8 gText_PurplePokeblock[] = _("{POKEBLOCK} lila");
const u8 gText_IndigoPokeblock[] = _("{POKEBLOCK} indi");
const u8 gText_BrownPokeblock[] = _("{POKEBLOCK} marró");
const u8 gText_LiteBluePokeblock[] = _("{POKEBLOCK} cel");
const u8 gText_OlivePokeblock[] = _("{POKEBLOCK} oliva");
const u8 gText_GrayPokeblock[] = _("{POKEBLOCK} gris");
const u8 gText_BlackPokeblock[] = _("{POKEBLOCK} negre");
const u8 gText_WhitePokeblock[] = _("{POKEBLOCK} blanc");
const u8 gText_GoldPokeblock[] = _("{POKEBLOCK} daurat");
const u8 gText_Spicy[] = _("Picant");
const u8 gText_Dry[] = _("Sec");
const u8 gText_Sweet[] = _("Dolç");
const u8 gText_Bitter[] = _("Amarg");
const u8 gText_Sour[] = _("Àcid");
const u8 gText_Tasty[] = _("Gustós"); // Unused
const u8 gText_Feel[] = _("Tacte"); // Unused
const u8 gText_StowCase[] = _("Guarda l'estoig.");
const u8 gText_LvVar1[] = _("{LV}{STR_VAR_1}");
const u8 gText_ThrowAwayVar1[] = _(
    "Vols llençar\n"
    "{STR_VAR_1}?");
const u8 gText_Var1ThrownAway[] = _(
    "S'ha llençat\n"
    "{STR_VAR_1}.");
const u8 gText_Var1AteTheVar2[] = _(
    "{STR_VAR_1} s'ha menjat\n"
    "{STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
const u8 gText_Var1HappilyAteVar2[] = _(
    "{STR_VAR_1} s'ha menjat\n"
    "{STR_VAR_2} ben content.{PAUSE_UNTIL_PRESS}");
const u8 gText_Var1DisdainfullyAteVar2[] = _(
    "{STR_VAR_1} s'ha menjat\n"
    "{STR_VAR_2} amb menyspreu.{PAUSE_UNTIL_PRESS}");
const u8 gText_ShopBuy[] = _("Comprar");
const u8 gText_ShopSell[] = _("Vendre");
const u8 gText_ShopQuit[] = _("Sortir");
const u8 gText_InBagVar1[] = _("A la motxilla: {STR_VAR_1}");
const u8 gText_QuitShopping[] = _("Deixa de comprar.");
const u8 gText_Var1CertainlyHowMany[] = _(
    "{STR_VAR_1}? Molt bé.\n"
    "Quants en vols?");
const u8 gText_Var1CertainlyHowMany2[] = _(
    "{STR_VAR_1}? Molt bé.\n"
    "Quants en vols?");
const u8 gText_Var1AndYouWantedVar2[] = _(
    "{STR_VAR_1}? I en volies {STR_VAR_2}?\n"
    "Són ¥{STR_VAR_3}.");
const u8 gText_Var1IsItThatllBeVar2[] = _(
    "{STR_VAR_1}, oi?\n"
    "Són ¥{STR_VAR_2}. El vols?");
const u8 gText_YouWantedVar1ThatllBeVar2[] = _(
    "En volies {STR_VAR_1}?\n"
    "Són ¥{STR_VAR_2}. Et va bé?");
const u8 gText_HereYouGoThankYou[] = _(
    "Aquí ho tens!\n"
    "Moltes gràcies.");
const u8 gText_ThankYouIllSendItHome[] = _(
    "Gràcies!\n"
    "T'ho enviaré al PC de casa.");
const u8 gText_ThanksIllSendItHome[] = _(
    "Gràcies!\n"
    "T'ho enviaré al PC de casa.");
const u8 gText_YouDontHaveMoney[] = _("No tens prou diners.{PAUSE_UNTIL_PRESS}");
const u8 gText_NoMoreRoomForThis[] = _(
    "No et queda espai per a aquest\n"
    "objecte.{PAUSE_UNTIL_PRESS}");
const u8 gText_SpaceForVar1Full[] = _("L'espai per a {STR_VAR_1} és ple.{PAUSE_UNTIL_PRESS}");
const u8 gText_AnythingElseICanHelp[] = _("Vols que t'ajudi amb res més?");
const u8 gText_CanIHelpWithAnythingElse[] = _("Et puc ajudar amb res més?");
const u8 gText_ThrowInPremierBall[] = _("T'hi afegeixo una Premier Ball.{PAUSE_UNTIL_PRESS}");
const u8 gText_CantBuyKeyItem[] = _(
    "{STR_VAR_2}? Ai, no.\n"
    "Això no ho puc comprar.{PAUSE_UNTIL_PRESS}");
const u8 gText_HowManyToSell[] = _(
    "{STR_VAR_2}?\n"
    "Quants en vols vendre?");
const u8 gText_ICanPayVar1[] = _(
    "Te'n puc pagar ¥{STR_VAR_1}.\n"
    "Et va bé?");
const u8 gText_TurnedOverVar1ForVar2[] = _(
    "Has lliurat {STR_VAR_2}\n"
    "i has rebut ¥{STR_VAR_1}.");
const u8 gText_PokedollarVar1[] = _("¥{STR_VAR_1}");
const u8 gText_Shift[] = _("Canviar");
const u8 gText_SendOut[] = _("Treure");
const u8 gText_Switch2[] = _("Bescanviar");
const u8 gText_Summary5[] = _("Resum");
const u8 gText_Moves[] = _("Moviments"); // Unused
const u8 gText_Enter[] = _("Entrar");
const u8 gText_NoEntry[] = _("No entrar");
const u8 gText_Take2[] = _("Agafar");
const u8 gText_Read2[] = _("Llegir");
const u8 gText_Trade4[] = _("Intercanviar");
const u8 gText_HP3[] = _("PS");
const u8 gText_SpAtk3[] = _("At. Esp.");
const u8 gText_SpDef3[] = _("Def. Esp.");
const u8 gText_WontHaveEffect[] = _("No tindrà cap efecte.{PAUSE_UNTIL_PRESS}");
const u8 gText_CantBeUsedOnPkmn[] = _(
    "Això no es pot fer servir amb\n"
    "aquest Pokémon.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnCantSwitchOut[] = _(
    "{STR_VAR_1} no pot sortir\n"
    "del combat!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnAlreadyInBattle[] = _(
    "{STR_VAR_1} ja està\n"
    "combatent!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnAlreadySelected[] = _(
    "{STR_VAR_1} ja s'ha\n"
    "triat.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnHasNoEnergy[] = _(
    "{STR_VAR_1} no té prou\n"
    "energia per combatre!{PAUSE_UNTIL_PRESS}");
const u8 gText_CantSwitchWithAlly[] = _(
    "No pots bescanviar el Pokémon de\n"
    "{STR_VAR_1} per un dels teus!{PAUSE_UNTIL_PRESS}");
const u8 gText_EggCantBattle[] = _("Un Ou no pot combatre!{PAUSE_UNTIL_PRESS}");
const u8 gText_CantUseUntilNewBadge[] = _(
    "No es pot fer servir fins que\n"
    "no obtinguis una Medalla nova.{PAUSE_UNTIL_PRESS}");
const u8 gText_NoMoreThanVar1Pkmn[] = _(
    "No hi poden entrar més de\n"
    "{STR_VAR_1} Pokémon.{PAUSE_UNTIL_PRESS}");
const u8 gText_SendMailToPC[] = _(
    "Vols enviar la carta retirada\n"
    "al teu PC?");
const u8 gText_MailSentToPC[] = _("La carta s'ha enviat al teu PC.{PAUSE_UNTIL_PRESS}");
const u8 gText_PCMailboxFull[] = _("La bústia del teu PC és plena.{PAUSE_UNTIL_PRESS}");
const u8 gText_MailMessageWillBeLost[] = _(
    "Si retires la carta, es perdrà\n"
    "el missatge. Hi estàs d'acord?");
const u8 gText_RemoveMailBeforeItem[] = _(
    "Cal retirar la carta abans de\n"
    "portar un objecte.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnWasGivenItem[] = _(
    "{STR_VAR_1} porta\n"
    "{STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnAlreadyHoldingItemSwitch[] = _(
    "{STR_VAR_1} ja porta\n"
    "un {STR_VAR_2}.\pVols bescanviar els dos\n"
    "objectes?");
const u8 gText_PkmnNotHolding[] = _(
    "{STR_VAR_1} no porta\n"
    "res.{PAUSE_UNTIL_PRESS}");
const u8 gText_ReceivedItemFromPkmn[] = _(
    "Has rebut {STR_VAR_2}\n"
    "de {STR_VAR_1}.{PAUSE_UNTIL_PRESS}");
const u8 gText_MailTakenFromPkmn[] = _(
    "S'ha retirat la carta del\n"
    "Pokémon.{PAUSE_UNTIL_PRESS}");
const u8 gText_SwitchedPkmnItem[] = _(
    "S'ha retirat {STR_VAR_2} i\n"
    "s'ha posat {STR_VAR_1}.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnHoldingItemCantHoldMail[] = _(
    "Aquest Pokémon porta un objecte.\n"
    "No pot portar cartes.{PAUSE_UNTIL_PRESS}");
const u8 gText_MailTransferredFromMailbox[] = _(
    "La carta s'ha transferit des de\n"
    "la bústia.{PAUSE_UNTIL_PRESS}");
const u8 gText_BagFullCouldNotRemoveItem[] = _(
    "La motxilla és plena. No s'ha pogut\n"
    "retirar l'objecte del Pokémon.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnLearnedMove3[] = _(
    "{STR_VAR_1} ha après\n"
    "{STR_VAR_2}!");
const u8 gText_PkmnCantLearnMove[] = _(
    "{STR_VAR_1} i {STR_VAR_2}\n"
    "no són compatibles.\pNo es pot aprendre\n"
    "{STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnNeedsToReplaceMove[] = _(
    "{STR_VAR_1} vol aprendre el\n"
    "moviment {STR_VAR_2}.\pPerò {STR_VAR_1} ja en\n"
    "sap quatre.\pVols esborrar un moviment i\n"
    "posar-hi {STR_VAR_2}?");
const u8 gText_StopLearningMove2[] = _(
    "Vols deixar d'ensenyar\n"
    "{STR_VAR_2}?");
const u8 gText_MoveNotLearned[] = _(
    "{STR_VAR_1} no ha après el\n"
    "moviment {STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
const u8 gText_WhichMoveToForget[] = _("Quin moviment vols oblidar?{PAUSE_UNTIL_PRESS}");
const u8 gText_12PoofForgotMove[] = _(
    "1, {PAUSE 15}2 i{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Puf!\p{STR_VAR_1} ha oblidat com\n"
    "fer servir {STR_VAR_2}.\pI…{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnAlreadyKnows[] = _(
    "{STR_VAR_1} ja sap\n"
    "{STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnHPRestoredByVar2[] = _(
    "{STR_VAR_1} ha recuperat\n"
    "{STR_VAR_2} PS.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnCuredOfPoison[] = _(
    "{STR_VAR_1} s'ha curat de\n"
    "l'enverinament.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnCuredOfParalysis[] = _(
    "{STR_VAR_1} s'ha curat de\n"
    "la paràlisi.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnWokeUp2[] = _("{STR_VAR_1} s'ha despertat.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnBurnHealed[] = _("{STR_VAR_1} s'ha curat la cremada.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnThawedOut[] = _("{STR_VAR_1} s'ha desglaçat.{PAUSE_UNTIL_PRESS}");
const u8 gText_PPWasRestored[] = _("S'han recuperat els PP.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnRegainhedHealth[] = _("{STR_VAR_1} ha recuperat la salut.{PAUSE_UNTIL_PRESS}"); // Unused
const u8 gText_PkmnBecameHealthy[] = _("{STR_VAR_1} s'ha posat bo.{PAUSE_UNTIL_PRESS}");
const u8 gText_MovesPPIncreased[] = _("Els PP de {STR_VAR_1} han pujat.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnElevatedToLvVar2[] = _(
    "{STR_VAR_1} ha pujat al\n"
    "niv. {STR_VAR_2}.");
const u8 gText_PkmnBaseVar2StatIncreased[] = _(
    "L'estadística {STR_VAR_2} base de\n"
    "{STR_VAR_1} ha pujat.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnCoreVar2StatIncreased[] = _(
    "L'estadística {STR_VAR_2} interna de\n"
    "{STR_VAR_1} ha pujat.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnCoreStatsIncreased[] = _(
    "Les estadístiques internes de\n"
    "{STR_VAR_1} han pujat.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnFriendlyBaseVar2Fell[] = _(
    "{STR_VAR_1} s'ha fet més amistós.\n"
    "El {STR_VAR_2} base ha baixat!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnFriendlyCoreVar2Fell[] = _(
    "{STR_VAR_1} s'ha fet més amistós.\n"
    "El {STR_VAR_2} intern ha baixat!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnFriendlyCoreNeutralized[] = _(
    "{STR_VAR_1} s'ha fet més amistós.\n"
    "Les estadístiques internes han caigut!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnAdoresBaseVar2Fell[] = _(
    "{STR_VAR_1} t'adora!\n"
    "El {STR_VAR_2} base ha baixat!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnFriendlyBaseVar2CantFall[] = _(
    "{STR_VAR_1} s'ha fet més amistós.\n"
    "El {STR_VAR_2} base no pot baixar!{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnSnappedOutOfConfusion[] = _(
    "{STR_VAR_1} ha sortit de la\n"
    "confusió.{PAUSE_UNTIL_PRESS}");
const u8 gText_PkmnGotOverInfatuation[] = _(
    "{STR_VAR_1} ha superat\n"
    "l'enamorament.{PAUSE_UNTIL_PRESS}");
const u8 gText_ThrowAwayItem[] = _(
    "Vols llençar\n"
    "{STR_VAR_1}?");
const u8 gText_ItemThrownAway[] = _(
    "S'ha llençat\n"
    "{STR_VAR_1}.{PAUSE_UNTIL_PRESS}");
const u8 gText_TeachWhichPokemon2[] = _("A quin Pokémon?"); // Unused
const u8 gText_ChoosePokemon[] = _("Tria un Pokémon.");
const u8 gText_MoveToWhere[] = _("On ho vols moure?");
const u8 gText_TeachWhichPokemon[] = _("A quin Pokémon?");
const u8 gText_UseOnWhichPokemon[] = _("Amb quin Pokémon?");
const u8 gText_GiveToWhichPokemon[] = _("A quin Pokémon?");
const u8 gText_DoWhatWithPokemon[] = _("Què vols fer amb aquest {PKMN}?");
const u8 gText_NothingToCut[] = _("Aquí no hi ha res a tallar.");
const u8 gText_CantSurfHere[] = _("Aquí no pots fer surf.");
const u8 gText_AlreadySurfing[] = _("Ja estàs fent surf.");
const u8 gText_CantUseHere[] = _("Aquí no ho pots fer servir.");
const u8 gText_RestoreWhichMove[] = _("Quin moviment vols recuperar?");
const u8 gText_BoostPp[] = _("De quin moviment vols pujar els PP?");
const u8 gText_DoWhatWithItem[] = _("Què vols fer amb l'objecte?");
const u8 gText_NoPokemonForBattle[] = _("No tens Pokémon per combatre!");
const u8 gText_ChoosePokemon2[] = _("Tria un Pokémon.");
const u8 gText_NotEnoughHp[] = _("No hi ha prou PS…");
const u8 gText_PokemonAreNeeded[] = _("Calen {STR_VAR_1} Pokémon.");
const u8 gText_PokemonCantBeSame[] = _("Els Pokémon no poden ser iguals.");
const u8 gText_NoIdenticalHoldItems[] = _("No pot haver-hi objectes iguals.");
const u8 gText_CurrentIsTooFast[] = _("El corrent és massa fort!");
const u8 gText_DoWhatWithMail[] = _("Què vols fer amb la carta?");
const u8 gText_ChoosePokemonCancel[] = _("Tria un Pokémon o cancel·la.");
const u8 gText_ChoosePokemonConfirm[] = _("Tria els Pokémon i confirma.");
const u8 gText_EnjoyCycling[] = _("Va, gaudim de la bici!");
const u8 gText_InUseAlready_PM[] = _("Això ja s'està fent servir.");
const u8 gText_AlreadyHoldingOne[] = _(
    "{STR_VAR_1} ja porta\n"
    "un {STR_VAR_2}.");
const u8 gText_NoUse[] = _("No serveix.");
const u8 gText_Able[] = _("Pot");
const u8 gText_First_PM[] = _("Primer");
const u8 gText_Second_PM[] = _("Segon");
const u8 gText_Third_PM[] = _("Tercer");
const u8 gText_Able2[] = _("Pot");
const u8 gText_NotAble[] = _("No pot");
const u8 gText_Able3[] = _("Pot!");
const u8 gText_NotAble2[] = _("No pot!");
const u8 gText_Learned[] = _("Après");
const u8 gText_Have[] = _("En té");
const u8 gText_DontHave[] = _("No en té");
const u8 gText_Fourth[] = _("Quart");
const u8 gText_PkmnCantParticipate[] = _("Aquest Pokémon no pot participar.{PAUSE_UNTIL_PRESS}");
const u8 gText_CancelParticipation[] = _("Vols cancel·lar la participació?");
const u8 gText_CancelBattle[] = _("Vols cancel·lar el combat?");
const u8 gText_ReturnToWaitingRoom[] = _("Vols tornar a la sala d'espera?");
const u8 gText_CancelChallenge[] = _("Vols cancel·lar el repte?");
const u8 gText_EscapeFromHere[] = _(
    "Vols escapar d'aquí i tornar\n"
    "a {STR_VAR_1}?");
const u8 gText_ReturnToHealingSpot[] = _(
    "Vols tornar a l'últim punt de\n"
    "curació fet servir a {STR_VAR_1}?");
const u8 gText_PauseUntilPress[] = _("{PAUSE_UNTIL_PRESS}");
const u8 gJPText_AreYouSureYouWantToSpinTradeMon[] = _("{STR_VAR_1}を ぐるぐるこうかんに\nだして よろしいですか？");
ALIGNED(4) const u8 gText_OnlyPkmnForBattle[] = _(
    "És el teu únic\n"
    "Pokémon per combatre.");
ALIGNED(4) const u8 gText_PkmnCantBeTradedNow[] = _(
    "Ara no es pot intercanviar\n"
    "aquest Pokémon.");
ALIGNED(4) const u8 gText_EggCantBeTradedNow[] = _("Ara no es pot intercanviar un Ou.");
ALIGNED(4) const u8 gText_OtherTrainersPkmnCantBeTraded[] = _(
    "Ara no es pot intercanviar el\n"
    "Pokémon de l'altre entrenador.");
ALIGNED(4) const u8 gText_OtherTrainerCantAcceptPkmn[] = _(
    "L'altre entrenador no pot acceptar\n"
    "aquest Pokémon ara.");
ALIGNED(4) const u8 gText_CantTradeWithTrainer[] = _(
    "Ara no pots intercanviar amb\n"
    "aquest entrenador.");
ALIGNED(4) const u8 gText_NotPkmnOtherTrainerWants[] = _(
    "Aquest no és el tipus de Pokémon\n"
    "que vol l'altre entrenador.");
ALIGNED(4) const u8 gText_ThatIsntAnEgg[] = _("Això no és un Ou.");
const u8 gText_Register[] = _("Registrar");
const u8 gText_Attack3[] = _("Atac");
const u8 gText_Defense3[] = _("Defensa");
const u8 gText_SpAtk4[] = _("At. Esp.");
const u8 gText_SpDef4[] = _("Def. Esp.");
const u8 gText_Speed2[] = _("Velocitat");
const u8 gText_HP4[] = _("PS");
const u8 gText_EmptyString8[] = _(""); // Unused
const u8 gText_OTSlash[] = _("EO/");
const u8 gText_RentalPkmn[] = _("Pokémon de lloguer");
const u8 gText_TypeSlash[] = _("Tipus/");
const u8 gText_Power[] = _("Potència");
const u8 gText_Accuracy2[] = _("Precisió");
const u8 gText_Appeal[] = _("Atractiu");
const u8 gText_Jam[] = _("Bloqueig");
const u8 gText_Status[] = _("Estat");
const u8 gText_ExpPoints[] = _("Punts Exp.");
const u8 gText_NextLv[] = _("Niv. següent");
const u8 gText_RibbonsVar1[] = _("Cintes: {STR_VAR_1}");
const u8 gText_EmptyString5[] = _("");
const u8 gText_Events[] = _("Fets"); // Unused
const u8 gText_Switch[] = _("Bescanviar");
const u8 gText_PkmnInfo[] = _("Info del Pokémon");
const u8 gText_PkmnSkills[] = _("Aptituds del Pokémon");
const u8 gText_BattleMoves[] = _("Moviments de combat");
const u8 gText_ContestMoves[] = _("Moviments de concurs");
const u8 gText_Info[] = _("Info");
const u8 gText_EggWillTakeALongTime[] = _(
    "Sembla que aquest Ou tardarà\n"
    "molt a trencar-se.");
const u8 gText_EggWillTakeSomeTime[] = _(
    "Què en sortirà?\n"
    "Encara tardarà una mica.");
const u8 gText_EggWillHatchSoon[] = _(
    "Es mou de tant en tant.\n"
    "Aviat es trencarà.");
const u8 gText_EggAboutToHatch[] = _(
    "Fa sorolls.\n"
    "Està a punt de trencar-se!");
const u8 gText_HMMovesCantBeForgotten2[] = _(
    "Ara no es poden oblidar\n"
    "els moviments MO.");
const u8 gText_XNatureMetAtYZ[] = _(
    "Naturalesa {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5},\n"
    "trobat al {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1},\n"
    "{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}.");
const u8 gText_XNatureHatchedAtYZ[] = _(
    "Naturalesa {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5},\n"
    "nascut al {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1},\n"
    "{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}.");
const u8 gText_XNatureObtainedInTrade[] = _(
    "Naturalesa {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5},\n"
    "obtingut en un intercanvi.");
const u8 gText_XNatureFatefulEncounter[] = _(
    "Naturalesa {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5},\n"
    "obtingut en una trobada\n"
    "del destí al {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}.");
const u8 gText_XNatureProbablyMetAt[] = _(
    "Naturalesa {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5},\n"
    "trobat potser al {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1},\n"
    "{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}.");
const u8 gText_XNature[] = _("Naturalesa {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}");
const u8 gText_XNatureMetSomewhereAt[] = _(
    "Naturalesa {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5},\n"
    "trobat en algun lloc al {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}.");
const u8 gText_XNatureHatchedSomewhereAt[] = _(
    "Naturalesa {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5},\n"
    "nascut en algun lloc al {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}.");
const u8 gText_OddEggFoundByCouple[] = _(
    "Un Ou de Pokémon estrany trobat\n"
    "per la parella de la Guarderia.");
const u8 gText_PeculiarEggNicePlace[] = _(
    "Un Ou de Pokémon peculiar\n"
    "obtingut en aquell lloc tan bonic.");
const u8 gText_PeculiarEggTrade[] = _(
    "Un Ou de Pokémon peculiar\n"
    "obtingut en un intercanvi.");
const u8 gText_EggFromHotSprings[] = _(
    "Un Ou de Pokémon obtingut\n"
    "a les fonts termals.");
const u8 gText_EggFromTraveler[] = _(
    "Un Ou de Pokémon estrany\n"
    "obtingut d'un viatger.");
const u8 gText_ApostropheSBase[] = _(" - Base");
const u8 gText_OkayToDeleteFromRegistry[] = _(
    "Vols esborrar {STR_VAR_1}\n"
    "del registre?");
const u8 gText_RegisteredDataDeleted[] = _("S'han esborrat les dades registrades.{PAUSE_UNTIL_PRESS}");
const u8 gText_NoRegistry[] = _("No hi ha cap registre.{PAUSE_UNTIL_PRESS}");
const u8 gText_DelRegist[] = _("Esb. registre");
const u8 gText_Var3Var1SlashVar2[] = _("{STR_VAR_3}{STR_VAR_1}/{STR_VAR_2}"); // Unused
const u8 gText_Decorate[] = _("Decorar");
const u8 gText_PutAway[] = _("Retirar");
const u8 gText_Toss2[] = _("Llençar");
const u8 gText_Color161Shadow161[] = _("{COLOR 161}{SHADOW 161}");
const u8 gText_PutOutSelectedDecorItem[] = _("Col·loca la decoració triada.");
const u8 gText_StoreChosenDecorInPC[] = _("Guarda la decoració triada al PC.");
const u8 gText_ThrowAwayUnwantedDecors[] = _("Llença les decoracions que no vols.");
const u8 gText_NoDecorations[] = _("No hi ha cap decoració.{PAUSE_UNTIL_PRESS}");
const u8 gText_Desk[] = _("Nina gran");
const u8 gText_Chair[] = _("Cadira");
const u8 gText_Plant[] = _("Planta");
const u8 gText_Ornament[] = _("Ornament");
const u8 gText_Mat[] = _("Estora");
const u8 gText_Poster[] = _("Pòster");
const u8 gText_Doll[] = _("Nina");
const u8 gText_Cushion[] = _("Coixí");
const u8 gText_Gold[] = _("Or");
const u8 gText_Silver[] = _("Plata");
const u8 gText_PlaceItHere[] = _("Vols posar-ho aquí?");
const u8 gText_CantBePlacedHere[] = _("Aquí no es pot posar.");
const u8 gText_CancelDecorating[] = _("Vols deixar de decorar?");
const u8 gText_InUseAlready[] = _("Això ja s'està fent servir.");
const u8 gText_NoMoreDecorations[] = _(
    "No hi caben més decoracions.\n"
    "El màxim que hi cap és {STR_VAR_1}.");
const u8 gText_NoMoreDecorations2[] = _(
    "No hi caben més decoracions.\n"
    "El màxim que hi cap és {STR_VAR_1}.");
const u8 gText_MustBePlacedOnDesk[] = _(
    "Aquí no es pot posar.\n"
    "Ha d'anar sobre una taula o similar."); // Unused
const u8 gText_CantPlaceInRoom[] = _(
    "Aquesta decoració no es pot posar\n"
    "a la teva habitació.");
const u8 gText_CantThrowAwayInUse[] = _(
    "Aquesta decoració s'està fent servir.\n"
    "No es pot llençar.");
const u8 gText_DecorationWillBeDiscarded[] = _(
    "Es llençarà {STR_VAR_1}.\n"
    "Hi estàs d'acord?");
const u8 gText_DecorationThrownAway[] = _("S'ha llençat la decoració.");
const u8 gText_StopPuttingAwayDecorations[] = _("Vols deixar de retirar decoracions?");
const u8 gText_NoDecorationHere[] = _("Aquí no hi ha cap decoració.");
const u8 gText_ReturnDecorationToPC[] = _("Vols tornar aquesta decoració al PC?");
const u8 gText_DecorationReturnedToPC[] = _("La decoració s'ha tornat al PC.");
const u8 gText_NoDecorationsInUse[] = _("No hi ha cap decoració en ús.{PAUSE_UNTIL_PRESS}");
const u8 gText_Tristan[] = _("Tristan");
const u8 gText_Philip[] = _("Philip");
const u8 gText_Dennis[] = _("Dennis");
const u8 gText_Roberto[] = _("Roberto");
const u8 gText_TurnOff[] = _("Apagar");
const u8 gText_Decoration[] = _("Decoració");
const u8 gText_ItemStorage[] = _("Magatzem d'objectes");
const u8 gText_Mailbox[] = _("Bústia");
const u8 gText_DepositItem[] = _("Dipositar objecte");
const u8 gText_WithdrawItem[] = _("Retirar objecte");
const u8 gText_TossItem[] = _("Llençar objecte");
const u8 gText_StoreItemsInPC[] = _("Guarda objectes al PC.");
const u8 gText_TakeOutItemsFromPC[] = _("Treu objectes del PC.");
const u8 gText_ThrowAwayItemsInPC[] = _("Llença objectes guardats al PC.");
const u8 gText_NoItems[] = _("No hi ha cap objecte.{PAUSE_UNTIL_PRESS}");
const u8 gText_NoRoomInBag[] = _(
    "Ja no queda espai\n"
    "a la motxilla.");
const u8 gText_WithdrawHowManyItems[] = _(
    "Quants {STR_VAR_1}\n"
    "vols retirar?");
const u8 gText_WithdrawXItems[] = _(
    "S'han retirat {STR_VAR_2}\n"
    "{STR_VAR_1}.");
const u8 gText_Read[] = _("Llegir");
const u8 gText_MoveToBag[] = _("Passa a la motxilla");
const u8 gText_Give2[] = _("Donar");
const u8 gText_NoMailHere[] = _("Aquí no hi ha cap carta.{PAUSE_UNTIL_PRESS}");
const u8 gText_WhatToDoWithVar1sMail[] = _(
    "Què vols fer amb la carta de\n"
    "{STR_VAR_1}?");
const u8 gText_MessageWillBeLost[] = _(
    "Es perdrà el missatge.\n"
    "Hi estàs d'acord?");
const u8 gText_BagIsFull[] = _("La motxilla és plena.{PAUSE_UNTIL_PRESS}");
const u8 gText_MailToBagMessageErased[] = _(
    "La carta ha tornat a la motxilla\n"
    "amb el missatge esborrat.{PAUSE_UNTIL_PRESS}");
const u8 gText_Dad[] = _("Dad");
const u8 gText_Mom[] = _("Mom");
const u8 gText_Wallace[] = _("Wallace");
const u8 gText_Steven[] = _("Steven");
const u8 gText_Brawly[] = _("Brawly");
const u8 gText_Winona[] = _("Winona");
const u8 gText_Phoebe[] = _("Phoebe");
const u8 gText_Glacia[] = _("Glacia");
const u8 gText_Petalburg[] = _("Petalburg");
const u8 gText_Slateport[] = _("Slateport");
const u8 gText_Littleroot[] = _("Littleroot"); // Unused. Given the context, Briney may at one point have been able to sail the player here
const u8 gText_Lilycove[] = _("Lilycove");     // Unused. Given the context, Briney may at one point have been able to sail the player here
const u8 gText_Dewford[] = _("Dewford");
const u8 gText_Enter2[] = _("Entrar");
const u8 gText_Info2[] = _("Info");
const u8 gText_WhatsAContest[] = _("Què és un concurs?");
const u8 gText_TypesOfContests[] = _("Tipus de concursos");
const u8 gText_Ranks[] = _("Rangs");
const u8 gText_Judging[] = _("Valoració"); //unused
const u8 gText_CoolnessContest[] = _("Concurs de Estil");
const u8 gText_BeautyContest[] = _("Concurs de Bellesa");
const u8 gText_CutenessContest[] = _("Concurs de Gràcia");
const u8 gText_SmartnessContest[] = _("Concurs d'Enginy");
const u8 gText_ToughnessContest[] = _("Concurs de Duresa");
const u8 gText_Decoration2[] = _("Decoració");
const u8 gText_PackUp[] = _("Plegar");
const u8 gText_Count[] = _("Recompte"); //unused
const u8 gText_Registry[] = _("Registre");
const u8 gText_Information[] = _("Informació");
const u8 gText_BikePrice[] = _("Bici ¥1.000.000");
const u8 gText_NoThanks[] = _("No, gràcies!");
const u8 gText_Psn[] = _("ENV");
const u8 gText_Par[] = _("PAR");
const u8 gText_Slp[] = _("ADO");
const u8 gText_Brn[] = _("CRE");
const u8 gText_Frz[] = _("GEL");
const u8 gText_Toxic[] = _("Tòxic"); // Unused
const u8 gText_Ok3[] = _("D'acord"); // Unused
const u8 gText_Quit[] = _("Sortir"); // Unused
const u8 gText_SawIt[] = _("Vist");
const u8 gText_NotYet[] = _("Encara no");
const u8 gText_Yes[] = _("Sí");
const u8 gText_No[] = _("No");
const u8 gText_Info4[] = _("Info"); // Unused
const u8 gText_SingleBattle[] = _("Combat individual");
const u8 gText_DoubleBattle[] = _("Combat doble");
const u8 gText_MultiBattle[] = _("Combat múltiple");
const u8 gText_MrBriney[] = _("Mr. Briney"); // Unused
const u8 gText_Challenge[] = _("Repte");
const u8 gText_Info3[] = _("Info");
const u8 gText_Lv50[] = _("Niv. 50");
const u8 gText_OpenLevel[] = _("Nivell obert");
const u8 gText_FreshWaterAndPrice[] = _("Aigua Fresca{CLEAR_TO 0x48}¥200");
const u8 gText_SodaPopAndPrice[] = _("Refresc{CLEAR_TO 0x48}¥300");
const u8 gText_LemonadeAndPrice[] = _("Llimonada{CLEAR_TO 0x48}¥350");
const u8 gText_FreshWater[] = _("Aigua Fresca");
const u8 gText_SodaPop[] = _("Refresc");
const u8 gText_Lemonade[] = _("Llimonada");
const u8 gText_HowToRide[] = _("Com muntar");
const u8 gText_HowToTurn[] = _("Com girar");
const u8 gText_SandySlopes[] = _("Pendents de sorra");
const u8 gText_Wheelies[] = _("Cavallets");
const u8 gText_BunnyHops[] = _("Bots de conill");
const u8 gText_Jump[] = _("Saltar");
const u8 gText_Satisfied[] = _("Satisfet");
const u8 gText_Dissatisfied[] = _("Insatisfet");
const u8 gText_DeepSeaTooth[] = _("Dent Abissal");
const u8 gText_DeepSeaScale[] = _("Escata Abiss.");
const u8 gText_BlueFlute2[] = _("Flauta Blava");
const u8 gText_YellowFlute2[] = _("Flauta Groga");
const u8 gText_RedFlute2[] = _("Flauta Verm.");
const u8 gText_WhiteFlute2[] = _("Flauta Blanca");
const u8 gText_BlackFlute2[] = _("Flauta Negra");
const u8 gText_GlassChair[] = _("Cadira de vidre");
const u8 gText_GlassDesk[] = _("Taula de vidre");
const u8 gText_TreeckoDollAndPrice[] =   _("Nina Treecko 1.000 fitxes");
const u8 gText_TorchicDollAndPrice[] =   _("Nina Torchic 1.000 fitxes");
const u8 gText_MudkipDollAndPrice[] =    _("Nina Mudkip   1.000 fitxes");

const u8 gText_MeowthDollAndPrice[] =      _("Meowth     500 fitxes");
const u8 gText_ClefairyDollAndPrice[] =    _("Clefairy   500 fitxes");
const u8 gText_JigglypuffDollAndPrice[] =  _("Jigglypuff 500 fitxes");
const u8 gText_DittoDollAndPrice[] =       _("Ditto      750 fitxes");
const u8 gText_PikachuDollAndPrice[] =     _("Pikachu    750 fitxes");

const u8 gText_RhydonDollAndPrice[] =    _("Rhydon    1.500 fitxes");
const u8 gText_LaprasDollAndPrice[] =    _("Lapras    1.500 fitxes");
const u8 gText_SnorlaxDollAndPrice[] =   _("Snorlax   1.500 fitxes");
const u8 gText_VenusaurDollAndPrice[] =  _("Venusaur  3.000 fitxes");
const u8 gText_CharizardDollAndPrice[] = _("Charizard 3.000 fitxes");
const u8 gText_BlastoiseDollAndPrice[] = _("Blastoise 3.000 fitxes");

const u8 gText_PokeballCushionAndPrice[] = _("Poké Ball 150 fitxes");
const u8 gText_WaterCushionAndPrice[] =    _("Aigua     250 fitxes");
const u8 gText_FireCushionAndPrice[] =     _("Foc       250 fitxes");
const u8 gText_LeafCushionAndPrice[] =     _("Herba     250 fitxes");
const u8 gText_PikachuCushionAndPrice[] =  _("Pika      350 fitxes");

const u8 gText_50CoinsAndPrice[] = _("  50 fitxes    ¥1.000");
const u8 gText_500CoinsAndPrice[] = _("500 fitxes  ¥10.000");
const u8 gText_Excellent2[] = _("Excel·lent");
const u8 gText_NotSoGood[] = _("No gaire bo");
const u8 gText_RedShard[] = _("Fragment Vermell");
const u8 gText_YellowShard[] = _("Fragment Groc");
const u8 gText_BlueShard[] = _("Fragment Blau");
const u8 gText_GreenShard[] = _("Fragment Verd");
const u8 gText_BattleFrontier[] = _("Frontera de Combat");
const u8 gText_Right[] = _("Dreta");
const u8 gText_Left[] = _("Esquerra");
const u8 gText_TM32AndPrice[] = _("MT32{CLEAR_TO 0x48}1.500 fitxes");
const u8 gText_TM29AndPrice[] = _("MT29{CLEAR_TO 0x48}3.500 fitxes");
const u8 gText_TM35AndPrice[] = _("MT35{CLEAR_TO 0x48}4.000 fitxes");
const u8 gText_TM24AndPrice[] = _("MT24{CLEAR_TO 0x48}4.000 fitxes");
const u8 gText_TM13AndPrice[] = _("MT13{CLEAR_TO 0x48}4.000 fitxes");
const u8 gText_Cool[] = _("Estil");
const u8 gText_Beauty[] = _("Bellesa");
const u8 gText_Cute[] = _("Gràcia");
const u8 gText_Smart[] = _("Enginy");
const u8 gText_Tough[] = _("Duresa");
const u8 gText_Normal[] = _("Normal");
const u8 gText_Super[] = _("Súper");
const u8 gText_Hyper[] = _("Híper");
const u8 gText_Master[] = _("Mestre");
const u8 gText_Cool2[] = _("Estil");
const u8 gText_Beauty2[] = _("Bellesa");
const u8 gText_Cute2[] = _("Gràcia");
const u8 gText_Smart2[] = _("Enginy");
const u8 gText_Tough2[] = _("Duresa");
const u8 gText_Items[] = _("Objectes");
const u8 gText_Key_Items[] = _("Objectes clau");
const u8 gText_Poke_Balls[] = _("Poké Balls");
const u8 gText_TMs_Hms[] = _("MTs i MOs");

const u8 gText_Berries2[] = _("Baies");
const u8 gText_SomeonesPC[] = _("El PC d'algú");
const u8 gText_LanettesPC[] = _("PC del Bill");

const u8 gText_Medicine[] = _("Medicines");
const u8 gText_BattleItems[] = _("Objectes de combat");
const u8 gText_Treasures[] = _("Tresors");

const u8 gText_PlayersPC[] = _("El PC de {PLAYER}");
const u8 gText_HallOfFame[] = _("Saló de la Fama");
const u8 gText_LogOff[] = _("Desconnectar");
const u8 gText_Opponent[] = _("Rival");
const u8 gText_Tourney_Tree[] = _("Quadre del torneig");
const u8 gText_ReadyToStart[] = _("A punt de començar");
const u8 gText_NormalRank[] = _("Rang normal");
const u8 gText_SuperRank[] = _("Rang súper");
const u8 gText_HyperRank[] = _("Rang híper");
const u8 gText_MasterRank[] = _("Rang mestre");
const u8 gText_Single2[] = _("Individual");
const u8 gText_Double2[] = _("Doble");
const u8 gText_Multi[] = _("Múltiple");
const u8 gText_MultiLink[] = _("Múltiple per enllaç");
const u8 gText_BattleBag[] = _("Motxilla de combat");
const u8 gText_HeldItem[] = _("Objecte portat");
const u8 gText_LinkContest[] = _("Concurs per enllaç");
const u8 gText_AboutE_Mode[] = _("Sobre el mode E");
const u8 gText_AboutG_Mode[] = _("Sobre el mode G");
const u8 gText_E_Mode[] = _("Mode E");
const u8 gText_G_Mode[] = _("Mode G");
const u8 gText_MenuOptionPokedex[] = _("Pokédex");
const u8 gText_MenuOptionPokemon[] = _("Pokémon");
const u8 gText_MenuOptionBag[] = _("Motxilla");
const u8 gText_MenuOptionPokenav[] = _("PokéGear");
const u8 gText_Blank[] = _("");
const u8 gText_MenuOptionSave[] = _("Desar");
const u8 gText_MenuOptionOption[] = _("Opcions");
const u8 gText_MenuOptionExit[] = _("Sortir");
const u8 gText_5BP[] = _("  5PC");
const u8 gText_10BP[] = _("10PC");
const u8 gText_15BP[] = _("15PC");
const u8 gText_RedTent[] = _("Tenda vermella");
const u8 gText_BlueTent[] = _("Tenda blava");
const u8 gText_SouthernIsland[] = _("Southern Island");
const u8 gText_BirthIsland[] = _("Birth Island");
const u8 gText_FarawayIsland[] = _("Faraway Island");
const u8 gText_NavelRock[] = _("Navel Rock");
const u8 gText_ClawFossil[] = _("Fòssil Urpa");
const u8 gText_RootFossil[] = _("Fòssil Arrel");
const u8 gText_HelixFossil[] = _("Fòssil Hèlix");
const u8 gText_DomeFossil[] = _("Fòssil Cúpula");
const u8 gText_OldAmber[] = _("Ambre Antic");
const u8 gText_No4[] = _("No");
const u8 gText_IllBattleNow[] = _("Combatré ara mateix!");
const u8 gText_IWon[] = _("He guanyat!");
const u8 gText_ILost[] = _("He perdut!");
const u8 gText_IWontTell[] = _("No ho penso dir.");
const u8 gText_NormalTagMatch[] = _("Combat en parella normal");
const u8 gText_VarietyTagMatch[] = _("Combat en parella variat");
const u8 gText_UniqueTagMatch[] = _("Combat en parella únic");
const u8 gText_ExpertTagMatch[] = _("Combat en parella expert");
const u8 gText_TradeCenter[] = _("Centre d'Intercanvi");
const u8 gText_Colosseum[] = _("Colisseu");
const u8 gText_RecordCorner[] = _("Racó de Registres");
const u8 gText_BerryCrush3[] = _("Trituradora de Baies");
const u8 gText_EmptyLinkService[] = _(""); // Maybe Spin Trade?
const u8 gText_PokemonJump[] = _("Salt Pokémon");
const u8 gText_DodrioBerryPicking[] = _("Recollida de Baies amb Dodrio");
const u8 gText_BecomeLeader[] = _("Fer-se líder");
const u8 gText_JoinGroup[] = _("Unir-se al grup");
const u8 gText_TwoStyles[] = _("Dos estils");
const u8 gText_Lv50_3[] = _("Niv. 50");
const u8 gText_OpenLevel2[] = _("Nivell obert");
const u8 gText_MonTypeAndNo[] = _("Tipus i núm. {PKMN}");
const u8 gText_HoldItems[] = _("Objectes portats");
const u8 gText_Symbols2[] = _("Símbols");
const u8 gText_Record3[] = _("Registre");
const u8 gText_BattlePts[] = _("PTS de combat");
const u8 gText_TowerInfo[] = _("Info de la torre");
const u8 gText_BattleMon[] = _("{PKMN} de combat");
const u8 gText_BattleSalon[] = _("Saló de combat");
const u8 gText_MultiLink2[] = _("Múltiple per enllaç");
const u8 gText_BattleRules[] = _("Regles de combat");
const u8 gText_JudgeMind[] = _("Jutge: ment");
const u8 gText_JudgeSkill[] = _("Jutge: destresa");
const u8 gText_JudgeBody[] = _("Jutge: cos");
const u8 gText_Matchup[] = _("Enfrontament");
const u8 gText_TourneyTree[] = _("Quadre del torneig");
const u8 gText_DoubleKO[] = _("KO doble");
const u8 gText_BasicRules[] = _("Regles bàsiques");
const u8 gText_SwapPartners[] = _("Canvi: company");
const u8 gText_SwapNumber[] = _("Canvi: número");
const u8 gText_SwapNotes[] = _("Canvi: notes");
const u8 gText_OpenLevel3[] = _("Nivell obert");
const u8 gText_BattleBasics[] = _("Bàsics del combat");
const u8 gText_PokemonNature[] = _("Naturalesa del Pokémon");
const u8 gText_PokemonMoves[] = _("Moviments del Pokémon");
const u8 gText_Underpowered[] = _("Massa feble");
const u8 gText_WhenInDanger[] = _("En cas de perill");
const u8 gText_PyramidPokemon[] = _("Piràmide: Pokémon");
const u8 gText_PyramidTrainers[] = _("Piràmide: entrenadors");
const u8 gText_PyramidMaze[] = _("Piràmide: laberint");
const u8 gText_BattleBag2[] = _("Motxilla de combat");
const u8 gText_PokenavAndBag[] = _("PokéGear i motxilla");
const u8 gText_HeldItems[] = _("Objectes portats");
const u8 gText_PokemonOrder[] = _("Ordre dels Pokémon");
const u8 gText_BattlePokemon[] = _("Pokémon de combat");
const u8 gText_BattleTrainers[] = _("Entrenadors de combat");
const u8 gText_GoOn[] = _("Continuar");
const u8 gText_Record2[] = _("Registre");
const u8 gText_Rest[] = _("Descansar");
const u8 gText_Retire[] = _("Retirar-se");
const u8 gText_99TimesPlus[] = _("99 vegades +");
const u8 gText_1MinutePlus[] = _("1 minut +");
const u8 gText_SpaceSeconds[] = _(" segons");
const u8 gText_SpaceTimes[] = _(" vegada(es)");
const u8 gText_Dot[] = _("."); // Unused
const u8 gText_BigGuy[] = _("Campió");
const u8 gText_BigGirl[] = _("Campiona");
const u8 gText_Son[] = _("fill");
const u8 gText_Daughter[] = _("filla");
const u8 gText_BlueFlute[] = _("Flauta Blava");
const u8 gText_YellowFlute[] = _("Flauta Groga");
const u8 gText_RedFlute[] = _("Flauta Verm.");
const u8 gText_WhiteFlute[] = _("Flauta Blanca");
const u8 gText_BlackFlute[] = _("Flauta Negra");
const u8 gText_PrettyChair[] = _("Cadira bonica");
const u8 gText_PrettyDesk[] = _("Taula bonica");
const u8 gText_1F[] = _("1F");
const u8 gText_2F[] = _("2F");
const u8 gText_3F[] = _("3F");
const u8 gText_4F[] = _("4F");
const u8 gText_5F[] = _("5F");
const u8 gText_6F[] = _("6F");
const u8 gText_7F[] = _("7F");
const u8 gText_8F[] = _("8F");
const u8 gText_9F[] = _("9F");
const u8 gText_10F[] = _("10F");
const u8 gText_11F[] = _("11F");
const u8 gText_B1F[] = _("B1F");
const u8 gText_B2F[] = _("B2F");
const u8 gText_B3F[] = _("B3F");
const u8 gText_B4F[] = _("B4F");
const u8 gText_Rooftop[] = _("Terrat");
const u8 gText_ElevatorNowOn[] = _("Ara a:");
const u8 gText_BP[] = _("PC");
const u8 gText_EnergyPowder50[] = _("Polsenergia{CLEAR_TO 114}{FONT_SMALL}50");
const u8 gText_EnergyRoot80[] = _("Arrel Energia{CLEAR_TO 114}{FONT_SMALL}80");
const u8 gText_HealPowder50[] = _("Pols Curativa{CLEAR_TO 114}{FONT_SMALL}50");
const u8 gText_RevivalHerb300[] = _("Herba Revif.{CLEAR_TO 108}{FONT_SMALL}300");
const u8 gText_Protein1000[] = _("Proteïna{CLEAR_TO 99}{FONT_SMALL}1.000");
const u8 gText_Iron1000[] = _("Ferro{CLEAR_TO 99}{FONT_SMALL}1.000");
const u8 gText_Carbos1000[] = _("Carbs{CLEAR_TO 99}{FONT_SMALL}1.000");
const u8 gText_Calcium1000[] = _("Calci{CLEAR_TO 99}{FONT_SMALL}1.000");
const u8 gText_Zinc1000[] = _("Zinc{CLEAR_TO 99}{FONT_SMALL}1.000");
const u8 gText_HPUp1000[] = _("Més PS{CLEAR_TO 99}{FONT_SMALL}1.000");
const u8 gText_PPUp3000[] = _("Més PP{CLEAR_TO 99}{FONT_SMALL}3.000");
const u8 gText_RankingHall[] = _("Sala de rànquings");
const u8 gText_ExchangeService[] = _("Servei d'intercanvi");
const u8 gText_LilycoveCity[] = _("Lilycove City");
const u8 gText_SlateportCity[] = _("Slateport City");
const u8 gText_CaveOfOrigin[] = _("Cave of Origin");
const u8 gText_MtPyre[] = _("Mt. Pyre");
const u8 gText_SkyPillar[] = _("Sky Pillar");
const u8 gText_DontRemember[] = _("No ho recordo");
const u8 gText_Exit[] = _("Sortir");
const u8 gText_ExitFromBox[] = _("Vols sortir de la caixa?");
const u8 gText_WhatDoYouWantToDo[] = _("Què vols fer?");
const u8 gText_PleasePickATheme[] = _("Tria un tema.");
const u8 gText_PickTheWallpaper[] = _("Tria el fons.");
const u8 gText_PkmnIsSelected[] = _("S'ha triat {DYNAMIC 0}.");
const u8 gText_JumpToWhichBox[] = _("A quina caixa vols anar?");
const u8 gText_DepositInWhichBox[] = _("A quina caixa vols dipositar?");
const u8 gText_PkmnWasDeposited[] = _("S'ha dipositat {DYNAMIC 0}.");
const u8 gText_BoxIsFull2[] = _("La caixa és plena.");
const u8 gText_ReleaseThisPokemon[] = _("Vols alliberar aquest Pokémon?");
const u8 gText_PkmnWasReleased[] = _("S'ha alliberat {DYNAMIC 0}.");
const u8 gText_ByeByePkmn[] = _("Adéu, {DYNAMIC 0}!");
const u8 gText_MarkYourPkmn[] = _("Marca el teu Pokémon.");
const u8 gText_ThatsYourLastPkmn[] = _("És el teu últim Pokémon!");
const u8 gText_YourPartysFull[] = _("Tens l'equip ple!");
const u8 gText_YoureHoldingAPkmn[] = _("Estàs agafant un Pokémon!");
const u8 gText_WhichOneWillYouTake[] = _("Quin vols agafar?");
const u8 gText_YouCantReleaseAnEgg[] = _("No pots alliberar un Ou.");
const u8 gText_ContinueBoxOperations[] = _("Vols continuar amb les caixes?");
const u8 gText_PkmnCameBack[] = _("{DYNAMIC 0} ha tornat!");
const u8 gText_WasItWorriedAboutYou[] = _("Estava preocupat per tu?");
const u8 gText_FourEllipsesExclamation[] = _("… … … … !");
const u8 gText_PleaseRemoveTheMail[] = _("Retira la carta, si et plau.");
const u8 gText_GiveToAPkmn[] = _("Vols donar-ho a un Pokémon?");
const u8 gText_PlacedItemInBag[] = _("S'ha posat l'objecte a la motxilla.");
const u8 gText_BagIsFull2[] = _("La motxilla és plena.");
const u8 gText_PutItemInBag[] = _("Vols posar l'objecte a la motxilla?");
const u8 gText_ItemIsNowHeld[] = _("Ara porta {DYNAMIC 0}.");
const u8 gText_ChangedToNewItem[] = _("S'ha canviat per {DYNAMIC 0}.");
const u8 gText_MailCantBeStored[] = _("Les cartes no es poden guardar!");
const u8 gPCText_Cancel[] = _("Cancel·lar");
const u8 gPCText_Store[] = _("Guardar");
const u8 gPCText_Withdraw[] = _("Retirar");
const u8 gPCText_Shift[] = _("Canviar");
const u8 gPCText_Move[] = _("Moure");
const u8 gPCText_Place[] = _("Col·locar");
const u8 gPCText_Summary[] = _("Resum");
const u8 gPCText_Release[] = _("Alliberar");
const u8 gPCText_Mark[] = _("Marcar");
const u8 gPCText_Name[] = _("Nom");
const u8 gPCText_Jump[] = _("Saltar");
const u8 gPCText_Wallpaper[] = _("Fons");
const u8 gPCText_Take[] = _("Agafar");
const u8 gPCText_Give[] = _("Donar");
const u8 gPCText_Switch[] = _("Bescanviar");
const u8 gPCText_Bag[] = _("Motxilla");
const u8 gPCText_Info[] = _("Info");
const u8 gPCText_Scenery1[] = _("Paisatge 1");
const u8 gPCText_Scenery2[] = _("Paisatge 2");
const u8 gPCText_Scenery3[] = _("Paisatge 3");
const u8 gPCText_Etcetera[] = _("Altres");
const u8 gPCText_Friends[] = _("Amics");
const u8 gPCText_Forest[] = _("Bosc");
const u8 gPCText_City[] = _("Ciutat");
const u8 gPCText_Desert[] = _("Desert");
const u8 gPCText_Savanna[] = _("Savana");
const u8 gPCText_Crag[] = _("Cingle");
const u8 gPCText_Volcano[] = _("Volcà");
const u8 gPCText_Snow[] = _("Neu");
const u8 gPCText_Cave[] = _("Cova");
const u8 gPCText_Beach[] = _("Platja");
const u8 gPCText_Seafloor[] = _("Fons marí");
const u8 gPCText_River[] = _("Riu");
const u8 gPCText_Sky[] = _("Cel");
const u8 gPCText_PolkaDot[] = _("Pics");
const u8 gPCText_Pokecenter[] = _("Centre Pokémon");
const u8 gPCText_Machine[] = _("Màquina");
const u8 gPCText_Simple[] = _("Senzill");
const u8 gText_WhatWouldYouLikeToDo[] = _("Què vols fer?"); // Unused
const u8 gText_WithdrawPokemon[] = _("Retirar Pokémon");
const u8 gText_DepositPokemon[] = _("Dipositar Pokémon");
const u8 gText_MovePokemon[] = _("Moure Pokémon");
const u8 gText_MoveItems[] = _("Moure objectes");
const u8 gText_SeeYa[] = _("Fins aviat!");
const u8 gText_WithdrawMonDescription[] = _(
    "Passa Pokémon de les caixes\n"
    "a l'equip.");
const u8 gText_DepositMonDescription[] = _(
    "Guarda a les caixes Pokémon\n"
    "de l'equip.");
const u8 gText_MoveMonDescription[] = _(
    "Organitza els Pokémon de les\n"
    "caixes i de l'equip.");
const u8 gText_MoveItemsDescription[] = _(
    "Mou objectes que porti qualsevol\n"
    "Pokémon d'una caixa o de l'equip.");
const u8 gText_SeeYaDescription[] = _("Torna al menú anterior.");
const u8 gText_JustOnePkmn[] = _("Només portes un Pokémon.");
const u8 gText_PartyFull[] = _("Tens l'equip ple!");
const u8 gText_Box[] = _("Caixa");
const u8 gText_CheckMapOfHoenn[] = _(
    "Consulta el mapa de la regió\n"
    "de Kanto.");
const u8 gText_CheckPokemonInDetail[] = _("Consulta els Pokémon en detall.");
const u8 gText_CallRegisteredTrainer[] = _("Truca a un entrenador registrat.");
const u8 gText_CheckObtainedRibbons[] = _("Consulta les Cintes obtingudes.");
const u8 gText_PutAwayPokenav[] = _("Guarda el PokéGear.");
const u8 gText_NoRibbonWinners[] = _("No hi ha guanyadors de Cintes.");
const u8 gText_NoTrainersRegistered[] = _("No hi ha cap entrenador registrat."); // Unused
const u8 gText_CheckPartyPokemonInDetail[] = _(
    "Consulta en detall els Pokémon\n"
    "de l'equip.");
const u8 gText_CheckAllPokemonInDetail[] = _("Consulta en detall tots els Pokémon.");
const u8 gText_ReturnToPokenavMenu[] = _("Torna al menú del PokéGear.");
const u8 gText_FindCoolPokemon[] = _("Cerca Pokémon guais.");
const u8 gText_FindBeautifulPokemon[] = _("Cerca Pokémon bonics.");
const u8 gText_FindCutePokemon[] = _("Cerca Pokémon adorables.");
const u8 gText_FindSmartPokemon[] = _("Cerca Pokémon llestos.");
const u8 gText_FindToughPokemon[] = _("Cerca Pokémon durs.");
const u8 gText_ReturnToConditionMenu[] = _("Torna al menú de condició.");
const u8 gText_NumberRegistered[] = _("Núm. registrats");
const u8 gText_NumberOfBattles[] = _("Núm. de combats");
const u8 gText_Detail[] = _("Detall"); // Unused
const u8 gText_Call2[] = _("Trucar"); // Unused
const u8 gText_UnusedExit[] = _("Sortir"); // Unused
const u8 gText_CantCallOpponentHere[] = _("Aquí no pots trucar al rival."); // Unused
const u8 gText_PokenavMatchCall_Strategy[] = _("Estratègia");
const u8 gText_PokenavMatchCall_TrainerPokemon[] = _("Pokémon de l'entrenador");
const u8 gText_PokenavMatchCall_SelfIntroduction[] = _("Presentació");
const u8 gText_Pokenav_ClearButtonList[] = _("{CLEAR 0x80}");
const u8 gText_PokenavMap_ZoomedOutButtons[] = _("{A_BUTTON}Ampliar {B_BUTTON}Cancel·la");
const u8 gText_PokenavMap_ZoomedInButtons[] = _("{A_BUTTON}Complet {B_BUTTON}Cancel·la");
const u8 gText_PokenavCondition_MonListButtons[] = _("{A_BUTTON}Condició {B_BUTTON}Cancel·la");
const u8 gText_PokenavCondition_MonStatusButtons[] = _("{A_BUTTON}Marques {B_BUTTON}Cancel·la");
const u8 gText_PokenavCondition_MarkingButtons[] = _("{A_BUTTON}Tria marca {B_BUTTON}Cancel·la");
const u8 gText_PokenavMatchCall_TrainerListButtons[] = _("{A_BUTTON}Menú {B_BUTTON}Cancel·la");
const u8 gText_PokenavMatchCall_CallMenuButtons[] = _("{A_BUTTON}D'acord {B_BUTTON}Cancel·la");
const u8 gText_PokenavMatchCall_CheckTrainerButtons[] = _("{B_BUTTON}Cancel·la");
const u8 gText_PokenavRibbons_MonListButtons[] = _("{A_BUTTON}Cintes {B_BUTTON}Cancel·la");
const u8 gText_PokenavRibbons_RibbonListButtons[] = _("{A_BUTTON}Comprova {B_BUTTON}Cancel·la");
const u8 gText_PokenavRibbons_RibbonCheckButtons[] = _("{B_BUTTON}Cancel·la");
const u8 gText_NatureSlash[] = _("Naturalesa/");
const u8 gText_TrainerCloseBy[] = _(
    "Aquest entrenador és a prop.\n"
    "Parla-hi en persona!");
const u8 gText_InParty[] = _("A l'equip");
const u8 gText_Number2[] = _("Núm. ");
const u8 gText_Ribbons[] = _("Cintes"); // Unused
const u8 gText_PokemonMaleLv[] = _("{DYNAMIC 0}{COLOR_HIGHLIGHT_SHADOW LIGHT_RED WHITE GREEN}♂{COLOR_HIGHLIGHT_SHADOW DARK_GRAY WHITE LIGHT_GRAY}/{LV}{DYNAMIC 1}"); // Unused
const u8 gText_PokemonFemaleLv[] = _("{DYNAMIC 0}{COLOR_HIGHLIGHT_SHADOW LIGHT_GREEN WHITE BLUE}♀{COLOR_HIGHLIGHT_SHADOW DARK_GRAY WHITE LIGHT_GRAY}/{LV}{DYNAMIC 1}"); // Unused
const u8 gText_PokemonNoGenderLv[] = _("{DYNAMIC 0}/{LV}{DYNAMIC 1}"); // Unused
const u8 gText_Unknown[] = _("Desconegut");
const u8 gText_Call[] = _("Trucar");
const u8 gText_Check[] = _("Comprovar");
const u8 gText_Cancel6[] = _("Cancel·lar");
const u8 gText_NumberIndex[] = _("Núm. {DYNAMIC 0}");
const u8 gText_RibbonsF700[] = _("Cintes {DYNAMIC 0}");
const u8 gText_PokemonMaleLv2[] = _("{DYNAMIC 0}{COLOR_HIGHLIGHT_SHADOW LIGHT_RED WHITE GREEN}♂{COLOR_HIGHLIGHT_SHADOW DARK_GRAY WHITE LIGHT_GRAY}/{LV}{DYNAMIC 1}{DYNAMIC 2}"); // Unused
const u8 gText_PokemonFemaleLv2[] = _("{DYNAMIC 0}{COLOR_HIGHLIGHT_SHADOW LIGHT_GREEN WHITE BLUE}♀{COLOR_HIGHLIGHT_SHADOW DARK_GRAY WHITE LIGHT_GRAY}/{LV}{DYNAMIC 1}{DYNAMIC 2}"); // Unused
const u8 gText_PokemonNoGenderLv2[] = _("{DYNAMIC 0}/{LV}{DYNAMIC 1}{DYNAMIC 2}"); // Unused
const u8 gText_CombineFourWordsOrPhrases[] = _("Combina quatre paraules o frases");
const u8 gText_AndMakeYourProfile[] = _("i crea el teu perfil.");
const u8 gText_CombineSixWordsOrPhrases[] = _("Combina sis paraules o frases");
const u8 gText_AndMakeAMessage[] = _("i crea un missatge.");
const u8 gText_FindWordsThatDescribeYour[] = _("Cerca paraules que descriguin");
const u8 gText_FeelingsRightNow[] = _("com et sents ara mateix.");
const u8 gText_WithFourPhrases[] = _("Amb quatre frases,"); // Unused
const u8 gText_CombineNineWordsOrPhrases[] = _("Combina nou paraules o frases");
const u8 gText_AndMakeAMessage2[] = _("i crea un missatge.");
const u8 gText_ChangeJustOneWordOrPhrase[] = _("Canvia només una paraula o frase");
const u8 gText_AndImproveTheBardsSong[] = _("i millora la cançó del Bard.");
const u8 gText_YourProfile[] = _("El teu perfil");
const u8 gText_YourFeelingAtTheBattlesStart[] = _("Com et sents en començar el combat");
const u8 gText_WhatYouSayIfYouWin[] = _("Què dius si guanyes un combat");
const u8 gText_WhatYouSayIfYouLose[] = _("Què dius si perds un combat");
const u8 gText_TheAnswer[] = _("La resposta");
const u8 gText_TheMailMessage[] = _("El missatge de la carta");
const u8 gText_TheMailSalutation[] = _("La salutació de la carta"); // Unused
const u8 gText_TheBardsSong2[] = _("La cançó nova");
const u8 gText_CombineTwoWordsOrPhrases[] = _("Combina dues paraules o frases");
const u8 gText_AndMakeATrendySaying[] = _("i crea una dita de moda.");
const u8 gText_TheTrendySaying[] = _("La dita de moda");
const u8 gText_IsAsShownOkay[] = _("queda així. Hi estàs d'acord?");
const u8 gText_CombineTwoWordsOrPhrases2[] = _("Combina dues paraules o frases");
const u8 gText_ToTeachHerAGoodSaying[] = _("per ensenyar-li una bona dita.");
const u8 gText_FindWordsWhichFit[] = _("Cerca paraules que encaixin");
const u8 gText_TheTrainersImage[] = _("amb la imatge de l'entrenador.");
const u8 gText_TheImage[] = _("La imatge:");
const u8 gText_OutOfTheListedChoices[] = _("D'entre les opcions de la llista,");
const u8 gText_SelectTheAnswerToTheQuiz[] = _("tria la resposta del qüestionari!");
const u8 gText_AndCreateAQuiz[] = _("i crea un qüestionari!");
const u8 gText_PickAWordOrPhraseAnd[] = _("Tria una paraula o frase i");
const u8 gText_SetTheQuizAnswer[] = _("posa-hi la resposta del qüestionari.");
const u8 gText_TheAnswerColon[] = _("La resposta:");
const u8 gText_TheQuizColon[] = _("El qüestionari:"); // Unused
const u8 gText_ApprenticePhrase[] = _("Frase de l'aprenent:");
const u8 gText_QuitEditing[] = _("Vols deixar d'editar?");
const u8 gText_StopGivingPkmnMail[] = _(
    "Vols deixar de donar la carta\n"
    "al Pokémon?");
const u8 gText_AndFillOutTheQuestionnaire[] = _("i omple el qüestionari.");
const u8 gText_LetsReplyToTheInterview[] = _("Contestem l'entrevista!");
const u8 gText_AllTextBeingEditedWill[] = _("Tot el text que s'està editant");
const u8 gText_BeDeletedThatOkay[] = _("s'esborrarà. Hi estàs d'acord?");
const u8 gText_QuitEditing2[] = _("Vols deixar d'editar?"); // Unused
const u8 gText_EditedTextWillNotBeSaved[] = _("El text editat no es desarà."); // Unused
const u8 gText_IsThatOkay[] = _("Hi estàs d'acord?"); // Unused
const u8 gText_PleaseEnterPhraseOrWord[] = _("Escriu una frase o una paraula."); // Unused
const u8 gText_EntireTextCantBeDeleted[] = _("No es pot esborrar tot el text.");
const u8 gText_OnlyOnePhrase[] = _("Només es pot canviar una frase.");
const u8 gText_OriginalSongWillBeUsed[] = _("Es farà servir la cançó original.");
const u8 gText_ThatsTrendyAlready[] = _("Això ja està de moda!"); // Unused
const u8 gText_CombineTwoWordsOrPhrases3[] = _("Combina dues paraules o frases.");
const u8 gText_QuitGivingInfo[] = _("Vols deixar de donar informació?"); // Unused
const u8 gText_StopGivingPkmnMail2[] = _(
    "Vols deixar de donar la carta\n"
    "al Pokémon?"); // Unused
const u8 gText_CreateAQuiz2[] = _("Crea un qüestionari!"); // Unused
const u8 gText_SetTheAnswer[] = _("Posa-hi la resposta!"); // Unused
const u8 gText_CancelSelection[] = _("Vols cancel·lar la selecció?"); // Unused
const u8 gText_Profile[] = _("Perfil");
const u8 gText_AtTheBattlesStart[] = _("En començar el combat:");
const u8 gText_UponWinningABattle[] = _("En guanyar un combat:");
const u8 gText_UponLosingABattle[] = _("En perdre un combat:");
const u8 gText_TheBardsSong[] = _("La cançó del Bard");
const u8 gText_WhatsHipAndHappening[] = _("Què es porta ara?");
const u8 gText_Interview[] = _("Entrevista");
const u8 gText_GoodSaying[] = _("Bona dita");
const u8 gText_FansQuestion[] = _("Pregunta d'un fan");
const u8 gJPText_WhatIsTheQuizAnswer[] = _("クイズの こたえは？"); // Unused
const u8 gText_ApprenticesPhrase[] = _("Frase de l'aprenent");
const u8 gText_Questionnaire[] = _("Qüestionari");
const u8 gText_YouCannotQuitHere[] = _("Aquí no pots sortir.");
const u8 gText_SectionMustBeCompleted[] = _("Cal completar aquesta secció.");
const u8 gText_F700sQuiz[] = _("Qüestionari de {DYNAMIC 0}");
const u8 gText_Lady[] = _("Senyora");
const u8 gText_AfterYouHaveReadTheQuiz[] = _("Quan hagis llegit la pregunta");
const u8 gText_QuestionPressTheAButton[] = _("del qüestionari, prem el botó A.");
const u8 gText_TheQuizAnswerIs[] = _("Quina és la resposta?");
const u8 gText_LikeToQuitQuiz[] = _("Vols deixar aquest repte de");
const u8 gText_ChallengeQuestionMark[] = _("qüestionari?");
const u8 gText_IsThisQuizOK[] = _("Et va bé aquest qüestionari?");
const u8 gText_CreateAQuiz[] = _("Crea un qüestionari!");
const u8 gText_SelectTheAnswer[] = _("Tria la resposta!");
const u8 gText_LyricsCantBeDeleted[] = _("La lletra no es pot esborrar.");
const u8 gText_PokemonLeague[] = _("Lliga Pokémon");
const u8 gText_PokemonCenter[] = _("Centre Pokémon");
const u8 gText_GetsAPokeBlockQuestion[] = _(" es menja un {POKEBLOCK}?");
const u8 gText_Coolness[] = _("L'estil ");
const u8 gText_Beauty3[] = _("La bellesa ");
const u8 gText_Cuteness[] = _("La gràcia ");
const u8 gText_Smartness[] = _("L'enginy ");
const u8 gText_Toughness[] = _("La duresa ");
const u8 gText_WasEnhanced[] = _("ha millorat!");
const u8 gText_NothingChanged[] = _("No ha canviat res!");
const u8 gText_WontEatAnymore[] = _("Ja no en vol menjar més…");
const u8 gText_SaveFailedCheckingBackup[] = _(
    "Error en desar. Es comprova la\n"
    "memòria de reserva… Espera.\n"
    "{COLOR RED}“Temps necessari: un minut”");
const u8 gText_BackupMemoryDamaged[] = _(
    "La memòria de reserva està\n"
    "danyada o la bateria s'ha esgotat.\n"
    "Pots jugar, però no desar.");
const u8 gText_GamePlayCannotBeContinued[] = _(
    "{COLOR RED}“No es pot continuar jugant.\n"
    "Es torna a la pantalla de títol…”");
const u8 gText_CheckCompleted[] = _(
    "Comprovació acabada.\n"
    "Es torna a intentar desar.\n"
    "Espera un moment.");
const u8 gText_SaveCompleteGameCannotContinue[] = _(
    "S'ha desat la partida.\n"
    "{COLOR RED}“No es pot continuar jugant.\n"
    "Es torna a la pantalla de títol.”");
const u8 gText_SaveCompletePressA[] = _(
    "S'ha desat la partida.\n"
    "{COLOR RED}“Prem el botó A.”");
const u8 gText_Ferry[] = _("Transbordador");
const u8 gText_SecretBase[] = _("Base Secreta");
const u8 gText_Hideout[] = _("Amagatall");
const u8 gText_ResetRTCConfirmCancel[] = _(
    "Reiniciar el rellotge?\n"
    "A: Confirmar, B: Cancel·lar");
const u8 gText_PresentTime[] = _("Hora actual del joc");
const u8 gText_PreviousTime[] = _("Hora anterior del joc");
const u8 gText_PleaseResetTime[] = _("Reinicia l'hora, si et plau.");
const u8 gText_ClockHasBeenReset[] = _(
    "S'ha reiniciat el rellotge.\n"
    "Es desaran les dades. Espera.");
const u8 gText_SaveCompleted[] = _("S'ha desat la partida.");
const u8 gText_SaveFailed[] = _("No s'ha pogut desar…");
const u8 gText_NoSaveFileCantSetTime[] = _(
    "No hi ha partida desada, així que\n"
    "no es pot ajustar l'hora.");
const u8 gText_InGameClockUsable[] = _(
    "Ja pots fer servir el sistema\n"
    "d'ajust del rellotge del joc.");
const u8 gText_Slots[] = _("Escurabutxaques");
const u8 gText_Roulette[] = _("Roulette");
const u8 gText_Good[] = _("Bo");
const u8 gText_VeryGood[] = _("Molt bo");
const u8 gText_Excellent[] = _("Excel·lent");
const u8 gText_SoSo[] = _("Regular");
const u8 gText_Bad[] = _("Dolent");
const u8 gText_TheWorst[] = _("El pitjor");
const u8 gText_Spicy2[] = _("picant");
const u8 gText_Dry2[] = _("sec");
const u8 gText_Sweet2[] = _("dolç");
const u8 gText_Bitter2[] = _("amarg");
const u8 gText_Sour2[] = _("àcid");
const u8 gText_Single[] = _("Individual");
const u8 gText_Double[] = _("Doble");
const u8 gText_Jackpot[] = _("premi gros");
const u8 gText_First[] = _("primer");
const u8 gText_Second[] = _("segon");
const u8 gText_Third[] = _("tercer");
const u8 gText_0Pts[] = _("0 pts");
const u8 gText_10Pts[] = _("10 pts");
const u8 gText_20Pts[] = _("20 pts");
const u8 gText_30Pts[] = _("30 pts");
const u8 gText_40Pts[] = _("40 pts");
const u8 gText_50Pts[] = _("50 pts");
const u8 gText_60Pts[] = _("60 pts");
const u8 gText_70Pts[] = _("70 pts");
const u8 gText_80Pts[] = _("80 pts");
const u8 gText_90Pts[] = _("90 pts");
const u8 gText_100Pts[] = _("100 pts");
const u8 gText_QuestionMark[] = _("?");

const u8 gText_RazorFang48BP[]= _("Ullal Afilat{CLEAR_TO 0x5E}48PC");
const u8 gText_RazorClaw48BP[]= _("Urpa Afilada{CLEAR_TO 0x5E}48PC");
const u8 gText_ChoiceSpecs48BP[]= _("Ulleres Tria{CLEAR_TO 0x5E}48PC");
const u8 gText_ChoiceScarf48BP[]= _("Mocador Tria{CLEAR_TO 0x5E}48PC");
const u8 gText_MuscleBand64BP[]= _("Cinta Múscul{CLEAR_TO 0x5E}48PC");
const u8 gText_LifeOrb48BP[]= _("Orbe Vital{CLEAR_TO 0x5E}48PC");
const u8 gText_PowerHerb32BP[]= _("Herba Poder{CLEAR_TO 0x5E}32PC");
const u8 gText_WiseGlasses48BP[]= _("Ull. Sàvies{CLEAR_TO 0x5E}48PC");
const u8 gText_RedCard16BP[]= _("Targeta Roja{CLEAR_TO 0x5E}16PC");

const u8 gText_PowerAnklet16BP[]= _("Anella Poder{CLEAR_TO 0x5E}16PC");
const u8 gText_PowerBracer16BP[]= _("Braçal Poder{CLEAR_TO 0x5E}16PC");
const u8 gText_PowerBelt16BP[]= _("Cinturó Poder{CLEAR_TO 0x5E}16PC");
const u8 gText_PowerBand16BP[]= _("Cinta Poder{CLEAR_TO 0x5E}16PC");
const u8 gText_PowerWeight16BP[]= _("Pes Poder{CLEAR_TO 0x5E}16PC");
const u8 gText_PowerLens16BP[] = _("Lent Poder{CLEAR_TO 0x5E}16PC");

const u8 gText_HPCandy24BP[]= _("Caramel PS{CLEAR_TO 0x5E}24PC");
const u8 gText_ATKCandy24BP[]= _("Caramel Atac{CLEAR_TO 0x5E}24PC");
const u8 gText_DEFCandy24BP[]= _("Caramel Def.{CLEAR_TO 0x5E}24PC");
const u8 gText_SPATKCandy24BP[]= _("Caram. At.Esp{CLEAR_TO 0x5E}24PC");
const u8 gText_SPDEFCandy24BP[]= _("Caram. Df.Esp{CLEAR_TO 0x5E}24PC");
const u8 gText_SPEEDCandy24BP[] = _("Caramel Vel.{CLEAR_TO 0x5E}24PC");
const u8 gText_MAXCandy64BP[] = _("Caramel Màx.{CLEAR_TO 0x5E}64PC");
const u8 gText_RESETCandy8BP[] = _("Caramel Zero{CLEAR_TO 0x5E}8PC");

const u8 gText_KissPoster16BP[] = _("Pòster Bes{CLEAR_TO 0x5E}16PC");
const u8 gText_KissCushion32BP[] = _("Coixí Bes{CLEAR_TO 0x5E}32PC");
const u8 gText_SmoochumDoll32BP[] = _("Nina Smoochum{CLEAR_TO 0x5E}32PC");
const u8 gText_TogepiDoll48BP[] = _("Nina Togepi{CLEAR_TO 0x5E}48PC");
const u8 gText_CyndaquilDoll80BP[] = _("Nina Cyndaquil{CLEAR_TO 0x5E}80PC");
const u8 gText_ChikoritaDoll80BP[] = _("Nina Chikorita{CLEAR_TO 0x5E}80PC");
const u8 gText_TotodileDoll80BP[] = _("Nina Totodile{CLEAR_TO 0x5E}80PC");
const u8 gText_Protein1BP[] = _("Proteïna{CLEAR_TO 0x64}1PC");
const u8 gText_Calcium1BP[] = _("Calci{CLEAR_TO 0x64}1PC");
const u8 gText_Iron1BP[] = _("Ferro{CLEAR_TO 0x64}1PC");
const u8 gText_Zinc1BP[] = _("Zinc{CLEAR_TO 0x64}1PC");
const u8 gText_Carbos1BP[] = _("Carbs{CLEAR_TO 0x64}1PC");
const u8 gText_HpUp1BP[] = _("Més PS{CLEAR_TO 0x64}1PC");
const u8 gText_Leftovers48BP[] = _("Restes{CLEAR_TO 0x5E}48PC");
const u8 gText_WhiteHerb48BP[] = _("Herba Blanca{CLEAR_TO 0x5E}48PC");
const u8 gText_QuickClaw48BP[] = _("Urpa Ràpida{CLEAR_TO 0x5E}48PC");
const u8 gText_MentalHerb48BP[] = _("Herba Mental{CLEAR_TO 0x5E}48PC");
const u8 gText_BrightPowder64BP[] = _("Pols Brillant{CLEAR_TO 0x5E}64PC");
const u8 gText_ChoiceBand64BP[] = _("Cinta Tria{CLEAR_TO 0x5E}64PC");
const u8 gText_KingsRock64BP[] = _("Roca Reial{CLEAR_TO 0x5E}64PC");
const u8 gText_FocusBand64BP[] = _("Cinta Focus{CLEAR_TO 0x5E}64PC");
const u8 gText_ScopeLens64BP[] = _("Lupa Precisió{CLEAR_TO 0x5E}64PC");
const u8 gText_Softboiled16BP[] = _("Ou Passat{CLEAR_TO 0x4E}16PC");
const u8 gText_SeismicToss24BP[] = _("Llanç Sísmic{CLEAR_TO 0x4E}24PC");
const u8 gText_DreamEater24BP[] = _("Menjasomnis{CLEAR_TO 0x4E}24PC");
const u8 gText_MegaPunch24BP[] = _("Megacop{CLEAR_TO 0x4E}24PC");
const u8 gText_MegaKick48BP[] = _("Megapuntada{CLEAR_TO 0x4E}48PC");
const u8 gText_BodySlam48BP[] = _("Cop de Cos{CLEAR_TO 0x4E}48PC");
const u8 gText_RockSlide48BP[] = _("AllauDeRoca{CLEAR_TO 0x4E}48PC");
const u8 gText_Counter48BP[] = _("Contraatac{CLEAR_TO 0x4E}48PC");
const u8 gText_ThunderWave48BP[] = _("Onada Tro{CLEAR_TO 0x4E}48PC");
const u8 gText_SwordsDance48BP[] = _("Dansa Espasa{CLEAR_TO 0x4E}48PC");
const u8 gText_DefenseCurl16BP[] = _("Enrotllar{CLEAR_TO 0x4E}16PC");
const u8 gText_Snore24BP[] = _("Roncar{CLEAR_TO 0x4E}24PC");
const u8 gText_MudSlap24BP[] = _("CopdeFang{CLEAR_TO 0x4E}24PC");
const u8 gText_Swift24BP[] = _("Rapidesa{CLEAR_TO 0x4E}24PC");
const u8 gText_IcyWind24BP[] = _("Vent Gelat{CLEAR_TO 0x4E}24PC");
const u8 gText_Endure48BP[] = _("Aguantar{CLEAR_TO 0x4E}48PC");
const u8 gText_PsychUp48BP[] = _("Autosuggest{CLEAR_TO 0x4E}48PC");
const u8 gText_IcePunch48BP[] = _("Cop de Gel{CLEAR_TO 0x4E}48PC");
const u8 gText_ThunderPunch48BP[] = _("CopElèctric{CLEAR_TO 0x4E}48PC");
const u8 gText_FirePunch48BP[] = _("Cop de Foc{CLEAR_TO 0x4E}48PC");
const u8 gText_PkmnFainted3[] = _(
    "{STR_VAR_1} s'ha debilitat…\p\n"
    "");
const u8 gText_Marco[] = _("Marco");
const u8 gText_TrainerCardName[] = _("Nom: ");
const u8 gText_TrainerCardIDNo[] = _("Núm. ID");
const u8 gText_TrainerCardMoney[] = _("Diners");
const u8 gText_PokeDollar[] = _("¥"); // Unused
const u8 gText_TrainerCardPokedex[] = _("Pokédex");
const u8 gText_EmptyString6[] = _("");
const u8 gText_Colon2[] = _(":");
const u8 gText_Points[] = _(" punts"); // Unused
const u8 gText_TrainerCardTime[] = _("Temps");
const u8 gJPText_BattlePoints[] = _("ゲ-ムポイント"); // Unused. Name presumed, translation is Game Points
const u8 gText_Var1sTrainerCard[] = _("Registres de la Torre de Combat");
const u8 gText_HallOfFameDebut[] = _("Debut al Saló de la Fama  ");
const u8 gText_LinkBattles[] = _("Combats per enllaç");
const u8 gText_LinkCableBattles[] = _("Combats per cable d'enllaç");
const u8 gText_WinsLosses[] = _("V:{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}  D:{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}");
const u8 gText_PokemonTrades[] = _("Intercanvis de Pokémon");
const u8 gText_UnionTradesAndBattles[] = _("Intercanvis i combats a la Unió");
const u8 gText_BerryCrush[] = _("Trituradora de Baies");
const u8 gText_WaitingTrainerFinishReading[] = _(
    "Esperant que l'altre entrenador\n"
    "acabi de llegir la teva fitxa.");
const u8 gText_PokeblocksWithFriends[] = _("{POKEBLOCK} amb amics");
const u8 gText_NumPokeblocks[] = _("{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}");
const u8 gText_WonContestsWFriends[] = _("Concursos guanyats amb amics");
const u8 gText_BattlePtsWon[] = _("Punts de Combat guanyats");
const u8 gText_NumBP[] = _("{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}PC");
const u8 gText_BattleTower[] = _("Torre de Combat");
const u8 gText_BattleTower2[] = _("Torre de Combat");
const u8 gText_BattleDome[] = _("Cúpula de Combat");
const u8 gText_BattlePalace[] = _("Palau de Combat");
const u8 gText_BattleFactory[] = _("Fàbrica de Combat");
const u8 gText_BattleArena[] = _("Arena de Combat");
const u8 gText_BattlePike[] = _("Camí de Combat");
const u8 gText_BattlePyramid[] = _("Piràmide de Combat");

const u8 gText_Tower50Singles[] = _("Individuals niv.50");
const u8 gText_Tower50Doubles[] = _("Dobles niv.50");
const u8 gText_TowerOpenSingles[] = _("Individuals oberts");
const u8 gText_TowerOpenDoubles[] = _("Dobles oberts");
const u8 gText_WinsStraight[] = _("V/{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}  Rècord/{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}");

ALIGNED(4) const u8 gText_FacilitySingle[] = _("{STR_VAR_1} individual");
ALIGNED(4) const u8 gText_FacilityDouble[] = _("{STR_VAR_1} doble");
ALIGNED(4) const u8 gText_FacilityMulti[] = _("{STR_VAR_1} múltiple");
ALIGNED(4) const u8 gText_FacilityLink[] = _("{STR_VAR_1} per enllaç");
ALIGNED(4) const u8 gText_Facility[] = _("{STR_VAR_1}");

const u8 gText_Give[] = _("Donar");
const u8 gText_NoNeed[] = _("No cal");
const u8 gText_ColorLightShadowDarkGray[] = _("{COLOR LIGHT_GRAY}{SHADOW DARK_GRAY}");
const u8 gText_ColorBlue[] = _("{COLOR BLUE}");
const u8 gText_ColorTransparent[] = _("{HIGHLIGHT TRANSPARENT}{COLOR TRANSPARENT}");
const u8 gText_CDot[] = _("C.");
const u8 gText_BDot[] = _("B.");
const u8 gText_AnnouncingResults[] = _("Es proclamen els resultats!");
const u8 gText_PreliminaryResults[] = _("Resultats preliminars!");
const u8 gText_Round2Results[] = _("Resultats de la ronda 2!");
const u8 gText_ContestantsMonWon[] = _("Ha guanyat {STR_VAR_2} de {STR_VAR_1}!");
const u8 gText_CommunicationStandby[] = _("En espera de comunicació…");
const u8 gText_ColorDarkGray[] = _("{COLOR DARK_GRAY}");
const u8 gText_ColorDynamic6WhiteDynamic5[] = _("{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR6 WHITE DYNAMIC_COLOR5}"); // Unused
const u8 gText_HealthboxNickname[] = _("{HIGHLIGHT DARK_GRAY}");
const u8 gText_EmptySpace2[] = _(" "); // Unused
const u8 gText_HealthboxGender_Male[] = _("{COLOR DYNAMIC_COLOR2}♂");
const u8 gText_HealthboxGender_Female[] = _("{COLOR DYNAMIC_COLOR1}♀");
const u8 gText_HealthboxGender_None[] = _("{COLOR DYNAMIC_COLOR2}");
const u8 gText_Upper[] = _("MAJ.");
const u8 gText_Lower[] = _("min.");
const u8 gText_Others[] = _("Altres");
const u8 gText_Symbols[] = _("Símbols");
const u8 gText_Register2[] = _("Registrar");
const u8 gText_Exit2[] = _("Sortir");
const u8 gText_QuitChatting[] = _("Vols deixar el xat?");
const u8 gText_RegisterTextWhere[] = _("On vols registrar el text?");
const u8 gText_RegisterTextHere[] = _("Vols registrar el text aquí?");
const u8 gText_InputText[] = _("Escriu el text.");
const u8 gText_F700JoinedChat[] = _("{DYNAMIC 0} s'ha unit al xat!");
const u8 gText_F700LeftChat[] = _("{DYNAMIC 0} ha deixat el xat.");
const u8 gJPText_PlayersXPokemon[] = _("{DYNAMIC 0}の{DYNAMIC 1}ひきめ:"); // Unused
const u8 gJPText_PlayersXPokmonDoesNotExist[] = _("{DYNAMIC 0}の{DYNAMIC 1}ひきめは いません"); // Unused
const u8 gText_ExitingChat[] = _("S'està sortint del xat…");
const u8 gText_LeaderLeftEndingChat[] = _(
    "El líder, {DYNAMIC 0}, ha marxat\n"
    "i s'ha acabat el xat.");
const u8 gText_RegisteredTextChangedOKToSave[] = _(
    "El text registrat ha canviat.\n"
    "Vols desar la partida?");
const u8 gText_AlreadySavedFile_Chat[] = _(
    "Ja hi ha una partida desada.\n"
    "La vols sobreescriure?");
const u8 gText_SavingDontTurnOff_Chat[] = _(
    "S'està desant…\n"
    "No apaguis la consola.");
const u8 gText_PlayerSavedGame_Chat[] = _("{DYNAMIC 0} ha desat la partida.");
const u8 gText_IfLeaderLeavesChatEnds[] = _(
    "Si el líder marxa, s'acabarà\n"
    "el xat. Hi estàs d'acord?");
const u8 gText_Hello[] = _("Hola");
const u8 gText_Pokemon2[] = _("Pokémon");
const u8 gText_Trade[] = _("Intercanviar");
const u8 gText_Battle[] = _("Combat");
const u8 gText_Lets[] = _("Va");
const u8 gText_Ok[] = _("D'acord!");
const u8 gText_Sorry[] = _("Perdó");
const u8 gText_YaySmileEmoji[] = _("Visca{EMOJI_BIGSMILE}");
const u8 gText_ThankYou[] = _("Gràcies");
const u8 gText_ByeBye[] = _("Adéu!");
const u8 gText_MatchCallSteven_Strategy[] = _("Ataca els punts febles!");
const u8 gText_MatchCallSteven_Pokemon[] = _("El Pokémon d'Acer definitiu.");
const u8 gText_MatchCallSteven_Intro1_BeforeMeteorFallsBattle[] = _("Escalaria fins i tot cascades");
const u8 gText_MatchCallSteven_Intro2_BeforeMeteorFallsBattle[] = _("per trobar una pedra rara!");
const u8 gText_MatchCallSteven_Intro1_AfterMeteorFallsBattle[] = _("Sóc el més fort i el més");
const u8 gText_MatchCallSteven_Intro2_AfterMeteorFallsBattle[] = _("enèrgic de tots!");

const u8 gText_HatchedFromEgg[] = _("{STR_VAR_1} ha sortit de l'Ou!");
const u8 gText_NicknameHatchPrompt[] = _(
    "Vols posar un sobrenom a\n"
    "{STR_VAR_1}, que acaba de néixer?");
ALIGNED(4) const u8 gText_ReadyPickBerry[] = _(
    "Preparat per triturar baies?\n"
    "Tria una baia per fer servir.\p");
ALIGNED(4) const u8 gText_WaitForAllChooseBerry[] = _(
    "Espera mentre cada membre\n"
    "tria una baia.");
ALIGNED(4) const u8 gText_EndedWithXUnitsPowder[] = _(
    "{PAUSE_MUSIC}{PLAY_BGM MUS_LEVEL_UP}Has obtingut {STR_VAR_1} unitats de\n"
    "Pols de Baia ben fina.{RESUME_MUSIC}\pEn total tens {STR_VAR_2} de\n"
    "Pols de Baia.\p");
ALIGNED(4) const u8 gText_RecordingGameResults[] = _(
    "S'estan desant els resultats a la\n"
    "partida.\lEspera un moment.");
ALIGNED(4) const u8 gText_PlayBerryCrushAgain[] = _("Vols tornar a jugar a triturar baies?");
ALIGNED(4) const u8 gText_YouHaveNoBerries[] = _(
    "No tens baies.\n"
    "Es cancel·larà el joc.");
ALIGNED(4) const u8 gText_MemberDroppedOut[] = _(
    "Un membre ha marxat.\n"
    "Es cancel·larà el joc.");
ALIGNED(4) const u8 gText_TimesUpNoGoodPowder[] = _(
    "S'ha acabat el temps.\pNo s'ha pogut fer bona Pols de\n"
    "Baia…\p");
ALIGNED(4) const u8 gText_CommunicationStandby2[] = _("En espera de comunicació…");
ALIGNED(4) const u8 gText_1DotBlueF700[] = _("1. {COLOR BLUE}{SHADOW LIGHT_BLUE}{DYNAMIC 0}");
ALIGNED(4) const u8 gText_1DotF700[] = _("1. {DYNAMIC 0}");
ALIGNED(4) const u8 gText_SpaceTimes2[] = _(" vegada(es)");
ALIGNED(4) const u8 gText_XDotY[] = _("{STR_VAR_1}.{STR_VAR_2}");
ALIGNED(4) const u8 gText_Var1Berry[] = _("Baia {STR_VAR_1}");
ALIGNED(4) const u8 gText_TimeColon[] = _("Temps:");
ALIGNED(4) const u8 gText_PressingSpeed[] = _("Velocitat de premuda:");
ALIGNED(4) const u8 gText_Silkiness[] = _("Finor:");
ALIGNED(4) const u8 gText_StrVar1[] = _("{STR_VAR_1}");
ALIGNED(4) const u8 gText_SpaceMin[] = _(" min. ");
ALIGNED(4) const u8 gText_XDotY2[] = _("{STR_VAR_1}.{STR_VAR_2}");
ALIGNED(4) const u8 gText_SpaceSec[] = _(" s");
ALIGNED(4) const u8 gText_XDotY3[] = _("{STR_VAR_1}.{STR_VAR_2}");
ALIGNED(4) const u8 gText_TimesPerSec[] = _(" vegades/s");
ALIGNED(4) const u8 gText_Var1Percent[] = _("{STR_VAR_1}%");
ALIGNED(4) const u8 gText_PressesRankings[] = _("Rànquing de premudes");
ALIGNED(4) const u8 gText_CrushingResults[] = _("Resultats de la trituració");
ALIGNED(4) const u8 gText_NeatnessRankings[] = _("Rànquing de netedat");
ALIGNED(4) const u8 gText_CoopRankings[] = _("Rànquing de cooperació");
ALIGNED(4) const u8 gText_PressingPowerRankings[] = _("Rànquing de força de premuda");
const u8 gText_BerryCrush2[] = _("Trituradora de Baies");
const u8 gText_PressingSpeedRankings[] = _("Rànquing de velocitat de premuda");
const u8 gText_Var1Players[] = _("{STR_VAR_1} jugadors");
const u8 gText_SymbolsEarned[] = _("Símbols obtinguts");
const u8 gText_BattleRecord[] = _("Registre de combats");
const u8 gText_BattlePoints[] = _("Punts de Combat");
const u8 gText_UnusedCancel[] = _("Cancel·lar"); // Unused
const u8 gText_EmptyString7[] = _("");
const u8 gText_CheckFrontierMap[] = _(
    "Consulta el mapa de la Frontera\n"
    "de Combat.");
const u8 gText_CheckTrainerCard[] = _("Consulta la Fitxa d'Entrenador.");
const u8 gText_ViewRecordedBattle[] = _("Mira el combat gravat.");
const u8 gText_PutAwayFrontierPass[] = _("Guarda el Passi de Frontera.");
const u8 gText_CurrentBattlePoints[] = _("Els teus Punts de Combat actuals.");
const u8 gText_CollectedSymbols[] = _("Els Símbols que has recollit.");
const u8 gText_BattleTowerAbilitySymbol[] = _("Torre de Combat - Símbol d'Aptitud");
const u8 gText_BattleDomeTacticsSymbol[] = _("Cúpula de Combat - Símbol de Tàctica");
const u8 gText_BattlePalaceSpiritsSymbol[] = _("Palau de Combat - Símbol d'Ànim");
const u8 gText_BattleArenaGutsSymbol[] = _("Arena de Combat - Símbol de Coratge");
const u8 gText_BattleFactoryKnowledgeSymbol[] = _("Fàbrica de Combat - Símbol de Saber");
const u8 gText_BattlePikeLuckSymbol[] = _("Camí de Combat - Símbol de Sort");
const u8 gText_BattlePyramidBraveSymbol[] = _("Piràmide de Combat - Símbol de Valor");
const u8 gText_ThereIsNoBattleRecord[] = _("No hi ha cap registre de combats.");
const u8 gText_BattleTower3[] = _("Torre de Combat");
const u8 gText_BattleDome2[] = _("Cúpula de Combat");
const u8 gText_BattlePalace2[] = _("Palau de Combat");
const u8 gText_BattleArena2[] = _("Arena de Combat");
const u8 gText_BattleFactory2[] = _("Fàbrica de Combat");
const u8 gText_BattlePike2[] = _("Camí de Combat");
const u8 gText_BattlePyramid2[] = _("Piràmide de Combat");
const u8 gText_BattleTowerDesc[] = _(
    "Derrota els rivals i arriba al cim!\n"
    "Es posarà a prova la teva aptitud.");
const u8 gText_BattleDomeDesc[] = _(
    "Continua guanyant al torneig!\n"
    "Es posarà a prova la teva tàctica.");
const u8 gText_BattlePalaceDesc[] = _(
    "Mira com combaten els teus Pokémon!\n"
    "Es posarà a prova el teu ànim.");
const u8 gText_BattleArenaDesc[] = _(
    "Guanya combats amb Pokémon en equip!\n"
    "Es posarà a prova el teu coratge.");
const u8 gText_BattleFactoryDesc[] = _(
    "Guanya amb Pokémon de lloguer!\n"
    "Es posarà a prova el teu saber.");
const u8 gText_BattlePikeDesc[] = _(
    "Tria un de tres camins per combatre!\n"
    "Es posarà a prova la teva sort.");
const u8 gText_BattlePyramidDesc[] = _(
    "Arriba al cim explorant!\n"
    "Es posarà a prova el teu valor.");
const u8 gText_ContinueMenuPlayer[] = _("Jugador");
const u8 gText_ContinueMenuTime[] = _("Temps");
const u8 gText_ContinueMenuPokedex[] = _("Pokédex");
const u8 gText_ContinueMenuBadges[] = _("Medalles");
const u8 gText_Powder[] = _("Pols");
const u8 gText_BerryPickingRecords[] = _("Registres de recollida amb Dodrio");
const u8 gText_BerriesPicked[] = _("Baies recollides:");
const u8 gText_BestScore[] = _("Millor puntuació:");
const u8 gText_BerriesInRowFivePlayers[] = _(
    "Baies recollides seguides amb\n"
    "cinc jugadors:");
const u8 gText_BerryPickingResults[] = _(
    "Es proclamen els resultats de la\n"
    "recollida de baies!");
const u8 gText_10P30P50P50P[] = _("{CLEAR_TO 0x03}10P{CLEAR_TO 0x2B}30P{CLEAR_TO 0x53}50P{CLEAR_TO 0x77}{EMOJI_MINUS}50P");
const u8 gText_AnnouncingRankings[] = _("Es proclamen els rànquings!");
const u8 gText_AnnouncingPrizes[] = _("Es proclamen els premis!");
const u8 gText_1Colon[] = _("1:");
const u8 gText_2Colon[] = _("2:");
const u8 gText_3Colon[] = _("3:");
const u8 gText_4Colon[] = _("4:");
const u8 gText_5Colon[] = _("5:");
const u8 gText_FirstPlacePrize[] = _(
    "El guanyador del primer lloc rep\n"
    "aquest {DYNAMIC 0}!");
const u8 gText_CantHoldAnyMore[] = _("Ja no en pots portar més!");
const u8 gText_FilledStorageSpace[] = _("S'ha omplert l'espai d'emmagatzematge.");
const u8 gText_WantToPlayAgain[] = _("Vols tornar a jugar?");
const u8 gText_SomeoneDroppedOut[] = _(
    "Algú ha marxat.\n"
    "Es cancel·larà l'enllaç.");
const u8 gText_SpacePoints[] = _(" punts");
const u8 gText_CommunicationStandby3[] = _("En espera de comunicació…");
const u8 gText_SpacePoints2[] = _(" punts");
const u8 gText_SpaceTimes3[] = _(" vegada(es)");
const u8 gText_PkmnJumpRecords[] = _("Registres de Salt Pokémon");
const u8 gText_JumpsInARow[] = _("Salts seguits:");
const u8 gText_BestScore2[] = _("Millor puntuació:");
const u8 gText_ExcellentsInARow[] = _("Excel·lents seguits:");
const u8 gText_AwesomeWonF701F700[] = _(
    "Quina puntuació! Has\n"
    "guanyat {DYNAMIC 1} {DYNAMIC 0}!");
const u8 gText_FilledStorageSpace2[] = _("S'ha omplert l'espai d'emmagatzematge.");
const u8 gText_CantHoldMore[] = _("Ja no en pots portar més!");
const u8 gText_WantToPlayAgain2[] = _("Vols tornar a jugar?");
const u8 gText_SomeoneDroppedOut2[] = _(
    "Algú ha marxat.\n"
    "Es cancel·larà l'enllaç.");
const u8 gText_CommunicationStandby4[] = _("En espera de comunicació…");
const u8 gText_LinkContestResults[] = _(
    "Resultats del concurs per enllaç\n"
    "de {PLAYER}");
const u8 gText_1st[] = _("1r");
const u8 gText_2nd[] = _("2n");
const u8 gText_3rd[] = _("3r");
const u8 gText_4th[] = _("4t");
const u8 gText_Friend[] = _("Amic");
const u8 gText_Pokemon3[] = _("Pokémon"); // Unused
const u8 gJPText_MysteryGift[] = _("ふしぎなもらいもの");
const u8 gJPText_DecideStop[] = _("{A_BUTTON}けってい {B_BUTTON}やめる");
const u8 gJPText_ReceiveMysteryGiftWithEReader[] = _("カードeリーダー{PLUS}　で\nふしぎなもらいものを　よみこみます");
const u8 gJPText_SelectConnectFromEReaderMenu[] = _("カードeリーダー{PLUS}の　メニューから\n‘つうしん'を　えらび");
const u8 gJPText_SelectConnectWithGBA[] = _("‘ゲームボーイアドバンスとつうしん'\nを　せんたく　してください");
const u8 gJPText_SelectConnectAndPressA[] = _("カードeリーダー{PLUS}の　‘つうしん'を\nえらんで　Aボタンを　おしてください"); // Unused
const u8 gJPText_LinkIsIncorrect[] = _("せつぞくが　まちがっています");
const u8 gJPText_CardReadingHasBeenHalted[] = _("カードの　よみこみを\nちゅうし　しました");
const u8 gJPText_UnableConnectWithEReader[] = _("カードeリーダー{PLUS}と\nつうしん　できません"); // Unused
const u8 gJPText_Connecting[] = _("つうしん　ちゅう　です");
const u8 gJPText_ConnectionErrorCheckLink[] = _("つうしん　エラーです\nせつぞくを　たしかめて　ください");
const u8 gJPText_ConnectionErrorTryAgain[] = _("つうしん　エラーです\nはじめから　やりなおして　ください"); // Link error
const u8 gJPText_AllowEReaderToLoadCard[] = _("カードeリーダー{PLUS}　に\nカードを　よみこませて　ください");
const u8 gJPText_ConnectionComplete[] = _("つうしん　しゅうりょう！");
const u8 gJPText_NewTrainerHasComeToHoenn[] = _("あらたな　トレーナーが\nホウエンに　やってきた！");
const u8 gJPText_PleaseWaitAMoment[] = _("しばらく　おまちください");
const u8 gJPText_WriteErrorUnableToSaveData[] = _("かきこみ　エラー　です\nデータが　ほぞん　できませんでした");
const u8 gText_Red[] = _("Vermell");
const u8 gText_Blue[] = _("Blue");
const u8 gText_3Dashes[] = _("---");
const u8 gText_SingleBattleRoomResults[] = _(
    "Resultats de {PLAYER} a la Sala\n"
    "de Combat Individual");
const u8 gText_DoubleBattleRoomResults[] = _(
    "Resultats de {PLAYER} a la Sala\n"
    "de Combat Doble");
const u8 gText_MultiBattleRoomResults[] = _(
    "Resultats de {PLAYER} a la Sala\n"
    "de Combat Múltiple");
const u8 gText_LinkMultiBattleRoomResults[] = _(
    "Resultats de {PLAYER} a la Sala de\n"
    "Combat Múltiple per Enllaç");
const u8 gText_SingleBattleTourneyResults[] = _(
    "Resultats de {PLAYER} al Torneig\n"
    "de Combat Individual");
const u8 gText_DoubleBattleTourneyResults[] = _(
    "Resultats de {PLAYER} al Torneig\n"
    "de Combat Doble");
const u8 gText_SingleBattleHallResults[] = _(
    "Resultats de {PLAYER} a la Sala\n"
    "de Combat Individual");
const u8 gText_DoubleBattleHallResults[] = _(
    "Resultats de {PLAYER} a la Sala\n"
    "de Combat Doble");
const u8 gText_BattleChoiceResults[] = _(
    "Resultats de Tria de Combat\n"
    "de {PLAYER}");
const u8 gText_SetKOTourneyResults[] = _(
    "Resultats del Torneig de KO\n"
    "de {PLAYER}");
const u8 gText_BattleSwapSingleResults[] = _(
    "Resultats de Canvi de Combat\n"
    "Individual de {PLAYER}");
const u8 gText_BattleSwapDoubleResults[] = _(
    "Resultats de Canvi de Combat\n"
    "Doble de {PLAYER}");
const u8 gText_BattleQuestResults[] = _(
    "Resultats de la Cerca de Combat\n"
    "de {PLAYER}");
const u8 gText_Lv502[] = _("Niv. 50");
const u8 gText_OpenLv[] = _("Niv. obert");
const u8 gText_WinStreak[] = _("Ratxa de victòries: {STR_VAR_1}");
const u8 gText_Current[] = _("Actual");
const u8 gText_Record[] = _("Registre");
const u8 gText_Prev[] = _("Ant.");
const u8 gText_RentalSwap[] = _("Lloguer/Canvi");
const u8 gText_Total[] = _("Total");
const u8 gText_ClearStreak[] = _("Ratxa de superats: {STR_VAR_1}");
const u8 gText_Championships[] = _("Campionats: {STR_VAR_1}");
const u8 gText_RoomsCleared[] = _("Sales superades: {STR_VAR_1}");
const u8 gText_TimesCleared[] = _("Vegades superat:{CLEAR 0x05}{STR_VAR_1}");
const u8 gText_KOsInARow[] = _("KO seguits: {STR_VAR_1}");
const u8 gText_TimesVar1[] = _("Vegades: {STR_VAR_1}");
const u8 gText_FloorsCleared[] = _("Plantes superades: {STR_VAR_1}");

ALIGNED(4) const u8 gText_RecordsLv50[] = _("Niv. 50");
ALIGNED(4) const u8 gText_RecordsOpenLevel[] = _("Nivell obert");
ALIGNED(4) const u8 gText_FrontierFacilityWinStreak[] = _("Ratxa de victòries: {STR_VAR_2}");
ALIGNED(4) const u8 gText_FrontierFacilityClearStreak[] = _("Ratxa de superats: {STR_VAR_2}");
ALIGNED(4) const u8 gText_FrontierFacilityRoomsCleared[] = _("Sales superades: {STR_VAR_2}");
ALIGNED(4) const u8 gText_FrontierFacilityKOsStreak[] = _("KO seguits: {STR_VAR_2}");
ALIGNED(4) const u8 gText_FrontierFacilityFloorsCleared[] = _("Plantes superades: {STR_VAR_2}");
ALIGNED(4) const u8 gText_123Dot[][3] = {_("1."), _("2."), _("3.")};

const u8 gText_SavingDontTurnOff2[] = _(
    "S'està desant…\n"
    "No apaguis la consola.");
const u8 gText_BlenderMaxSpeedRecord[] = _(
    "Batedora de Baies\n"
    "rècord de velocitat màxima!");
const u8 gText_234Players[] = _(
    "2 jugadors\n"
    "3 jugadors\n"
    "4 jugadors");
const u8 gText_YesNo[] = _(
    "Sí\n"
    "No");
const u8 gText_SelectorArrow3[] = _("▶");
const u8 gText_Peekaboo[] = _("CUCUT!");
const u8 gText_CommErrorCheckConnections[] = _(
    "Error de comunicació…\n"
    "Comprova totes les connexions i\n"
    "apaga i engega la consola.");
const u8 gText_CommErrorEllipsis[] = _("Error de comunicació…");
const u8 gText_MoveCloserToLinkPartner[] = _(
    "Acosta't als teus companys d'enllaç.\n"
    "Evita obstacles entre vosaltres.");
const u8 gText_ABtnRegistrationCounter[] = _("Botó A: Taulell de registre");
const u8 gText_ABtnTitleScreen[] = _("Botó A: Pantalla de títol");
const u8 gText_Option[] = _("Opcions");
const u8 gText_TextSpeed[] = _("Velocitat del text");
const u8 gText_BattleScene[] = _("Escena de combat");
const u8 gText_BattleStyle[] = _("Estil de combat");
const u8 gText_Sound[] = _("So");
const u8 gText_Frame[] = _("Marc");
const u8 gText_Follower[] = _("Acompanyant");
const u8 gText_FollowerPika[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Company");
const u8 gText_FollowerAny[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Qualsevol");
const u8 gText_FollowerNone[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Cap");
const u8 gText_OptionMenuCancel[] = _("Cancel·lar");
const u8 gText_ButtonMode[] = _("Mode de botons");
const u8 gText_TextSpeedSlow[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Lenta");
const u8 gText_TextSpeedMid[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Mitjana");
const u8 gText_TextSpeedFast[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Ràpida");
const u8 gText_BattleSceneOn[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Sí");
const u8 gText_BattleSceneOff[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}No");
const u8 gText_BattleStyleShift[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Canvi");
const u8 gText_BattleStyleSet[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Fix");
const u8 gText_SoundMono[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Mono");
const u8 gText_SoundStereo[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Estèreo");
const u8 gText_FrameType[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Tipus");
const u8 gText_FrameTypeNumber[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}");
const u8 gText_ButtonTypeNormal[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Normal");
const u8 gText_ButtonTypeLR[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}LR");
const u8 gText_ButtonTypeLEqualsA[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}L=A");
const u8 gText_NumPlayerLink[] = _("Enllaç de {STR_VAR_1}J");
const u8 gText_BronzeCard[] = _("Bronze");
const u8 gText_CopperCard[] = _("Coure");
const u8 gText_SilverCard[] = _("Plata");
const u8 gText_GoldCard[] = _("Or");
const u8 gText_Day[] = _("Dia");
const u8 gText_Colon3[] = _(":");
const u8 gText_Confirm2[] = _("Confirmar");
const u8 gText_Days[] = _("Dies"); // Unused
const u8 gText_TimeColon2[] = _("Temps:"); // Unused
const u8 gText_GameTime[] = _("Temps de joc"); // Unused
const u8 gText_RTCTime[] = _("Hora del rellotge"); // Unused
const u8 gText_UpdatedTime[] = _("Hora actualitzada"); // Unused
const u8 gText_MenuPokedex[] = _("Pokédex");
const u8 gText_MenuPokemon[] = _("Pokémon");
const u8 gText_MenuBag[] = _("Motxilla");
const u8 gText_MenuPokenav[] = _("PokéGear");
const u8 gText_MenuPlayer[] = _("{PLAYER}");
const u8 gText_MenuSave[] = _("Desar");
const u8 gText_MenuOption[] = _("Opcions");
const u8 gText_MenuExit[] = _("Sortir");
const u8 gText_MenuRetire[] = _("Retirar-se");
const u8 gText_MenuRest[] = _("Descansar");
const u8 gText_SafariBallStock[] = _(
    "Safari Balls\n"
    "Existències: {STR_VAR_1}");
const u8 gText_MenuDexNav[] = _("DexNav");
const u8 gText_BattlePyramidFloor[] = _(
    "Piràmide de Combat\n"
    "{STR_VAR_1}");
const u8 gText_Floor1[] = _("Planta 1");
const u8 gText_Floor2[] = _("Planta 2");
const u8 gText_Floor3[] = _("Planta 3");
const u8 gText_Floor4[] = _("Planta 4");
const u8 gText_Floor5[] = _("Planta 5");
const u8 gText_Floor6[] = _("Planta 6");
const u8 gText_Floor7[] = _("Planta 7");
const u8 gText_Peak[] = _("Cim");
const u8 gText_LinkStandby2[] = _(
    "Enllaç en espera…\n"
    "… … Botó B: Cancel·lar");
const u8 gText_PressAToLoadEvent[] = _(
    "Prem el botó A per carregar el fet.\n"
    "… … Botó B: Cancel·lar");
const u8 gText_LoadingEvent[] = _("S'està carregant el fet…");
const u8 gText_DontRemoveCableTurnOff[] = _(
    "No treguis el cable d'enllaç.\n"
    "No apaguis la consola.");
const u8 gText_EventSafelyLoaded[] = _("El fet s'ha carregat correctament.");
const u8 gText_LoadErrorEndingSession[] = _(
    "Error de càrrega.\n"
    "S'acaba la sessió.");
const u8 gJPText_Player[] = _("プレイヤー"); // Unused
const u8 gJPText_Sama[] = _("さま"); // Unused
const u8 gText_DexHoenn[] = _("Kanto");
const u8 gText_DexNational[] = _("Nacional");
const u8 gText_PokedexDiploma[] = _(
    "JUGADOR: {CLEAR 0x10}{COLOR RED}{SHADOW LIGHT_RED}{PLAYER}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\n"
    "\n"
    "Aquest document certifica\n"
    "que has completat\n"
    "correctament el teu Pokédex.\n"
    "\n"
    "{COLOR RED}{SHADOW LIGHT_RED}RetroGBA - PokéClassic");
const u8 gJPText_GameFreak[] = _("{COLOR RED}{SHADOW LIGHT_RED}ゲ-ムフリ-ク"); // Unused
const u8 gText_DiplomaEmpty[] = _("{COLOR RED}{SHADOW LIGHT_RED}"); // Unused
const u8 gText_Hoenn[] = _("Hoenn");
const u8 gText_Kanto[] = _("Kanto");
const u8 gText_Johto[] = _("Johto");
const u8 gText_Sinnoh[] = _("Sinnoh");
const u8 gText_OhABite[] = _("Oh! Ha picat!");
const u8 gText_PokemonOnHook[] = _("Hi ha un Pokémon a l'ham!{PAUSE_UNTIL_PRESS}");
const u8 gText_NotEvenANibble[] = _("No ha picat gens…{PAUSE_UNTIL_PRESS}");
const u8 gText_ItGotAway[] = _("S'ha escapat…{PAUSE_UNTIL_PRESS}");
const u8 gText_XWillBeSentToY[] = _(
    "{STR_VAR_2} s'enviarà\n"
    "a {STR_VAR_1}.");
const u8 gText_ByeByeVar1[] = _("Adéu, {STR_VAR_2}!");
const u8 gText_XSentOverY[] = _("{STR_VAR_1} t'ha enviat {STR_VAR_3}.");
const u8 gText_TakeGoodCareOfX[] = _("Cuida bé {STR_VAR_3}!");

// Easy chat group names
const u8 gEasyChatGroupName_Pokemon[] = _("Pokémon");
const u8 gEasyChatGroupName_Trainer[] = _("Entrenador");
const u8 gEasyChatGroupName_Status[] = _("Estat");
const u8 gEasyChatGroupName_Battle[] = _("Combat");
const u8 gEasyChatGroupName_Greetings[] = _("Salutacions");
const u8 gEasyChatGroupName_People[] = _("Persones");
const u8 gEasyChatGroupName_Voices[] = _("Veus");
const u8 gEasyChatGroupName_Speech[] = _("Parla");
const u8 gEasyChatGroupName_Endings[] = _("Finals");
const u8 gEasyChatGroupName_Feelings[] = _("Sentiments");
const u8 gEasyChatGroupName_Conditions[] = _("Condicions");
const u8 gEasyChatGroupName_Actions[] = _("Accions");
const u8 gEasyChatGroupName_Lifestyle[] = _("Estil de vida");
const u8 gEasyChatGroupName_Hobbies[] = _("Aficions");
const u8 gEasyChatGroupName_Time[] = _("Temps");
const u8 gEasyChatGroupName_Misc[] = _("Divers");
const u8 gEasyChatGroupName_Adjectives[] = _("Adjectius");
const u8 gEasyChatGroupName_Events[] = _("Fets");
const u8 gEasyChatGroupName_Move1[] = _("Moviment 1");
const u8 gEasyChatGroupName_Move2[] = _("Moviment 2");
const u8 gEasyChatGroupName_TrendySaying[] = _("Dita de moda");
const u8 gEasyChatGroupName_Pokemon2[] = _("Pokémon2");

const u8 gText_ThreeQuestionMarks[] = _("???");
const u8 gText_MaxHP[] = _("PS màx.");
const u8 gText_Attack[] = _("Atac");
const u8 gText_Defense[] = _("Defensa");
const u8 gText_Speed[] = _("Velocitat");
const u8 gText_SpAtk[] = _("At. Esp.");
const u8 gText_SpDef[] = _("Def. Esp.");
const u8 gText_Plus[] = _("{PLUS}");
const u8 gText_Dash[] = _("-");
const u8 gText_FromSpace[] = _("De ");
const u8 gText_MixingRecords[] = _("S'estan barrejant els registres…");
const u8 gText_RecordMixingComplete[] = _(
    "Barreja de registres acabada.\n"
    "Gràcies per esperar.");
const u8 gText_YourName[] = _("Com et dius?");
const u8 gText_BoxName[] = _("Nom de la caixa?");
const u8 gText_PkmnsNickname[] = _("Sobrenom de {STR_VAR_1}?");
const u8 gText_TellHimTheWords[] = _("Digues-li les paraules.");
const u8 gText_MoveOkBack[] = _("{DPAD_NONE}Mou  {A_BUTTON}D'acord  {B_BUTTON}Enrere");
const u8 gText_CallCantBeMadeHere[] = _("Des d'aquí no es pot trucar.");
const u8 gText_ContestLady_Handsome[] = _("Handsome");
const u8 gText_ContestLady_Vinny[] = _("Vinny");
const u8 gText_ContestLady_Moreme[] = _("Moreme");
const u8 gText_ContestLady_Ironhard[] = _("Ironhard");
const u8 gText_ContestLady_Muscle[] = _("Muscle");
const u8 gText_ContestLady_Coolness[] = _("estil");
const u8 gText_ContestLady_Beauty[] = _("bellesa");
const u8 gText_ContestLady_Cuteness[] = _("gràcia");
const u8 gText_ContestLady_Smartness[] = _("enginy");
const u8 gText_ContestLady_Toughness[] = _("duresa");
const u8 gText_QuizLady_Lady[] = _("Senyora");
const u8 gText_FavorLady_Slippery[] = _("llefiscós");
const u8 gText_FavorLady_Roundish[] = _("rodonet");
const u8 gText_FavorLady_Whamish[] = _("contundent");
const u8 gText_FavorLady_Shiny[] = _("lluent");
const u8 gText_FavorLady_Sticky[] = _("enganxós");
const u8 gText_FavorLady_Pointy[] = _("punxegut");
const u8 gText_RentalPkmn2[] = _("Pokémon de lloguer");
const u8 gText_SelectFirstPkmn[] = _("Tria el primer Pokémon.");
const u8 gText_SelectSecondPkmn[] = _("Tria el segon Pokémon.");
const u8 gText_SelectThirdPkmn[] = _("Tria el tercer Pokémon.");
const u8 gText_Rent[] = _("Llogar");
const u8 gText_Summary[] = _("Resum");
const u8 gText_Others2[] = _("Altres");
const u8 gText_Deselect[] = _("Desmarcar");
const u8 gText_TheseThreePkmnOkay[] = _("Et van bé aquests tres Pokémon?");
const u8 gText_Yes2[] = _("Sí");
const u8 gText_No2[] = _("No");
const u8 gText_CantSelectSamePkmn[] = _("No pots triar el mateix {PKMN}.");
const u8 gText_PkmnSwap[] = _("Canvi de Pokémon");
const u8 gText_SelectPkmnToSwap[] = _("Tria el Pokémon per canviar.");
const u8 gText_SelectPkmnToAccept[] = _("Tria el Pokémon que acceptes.");
const u8 gText_Swap[] = _("Canviar");
const u8 gText_Summary2[] = _("Resum");
const u8 gText_Rechoose[] = _("Tornar a triar");
const u8 gText_QuitSwapping[] = _("Vols deixar de canviar?");
const u8 gText_Yes3[] = _("Sí");
const u8 gText_No3[] = _("No");
const u8 gText_PkmnForSwap[] = _("{PKMN} per canviar");
const u8 gText_Cancel3[] = _("Cancel·lar");
const u8 gText_Swap2[] = _("Canviar"); // Unused
const u8 gText_Accept[] = _("Acceptar"); // Unused
const u8 gText_AcceptThisPkmn[] = _("Acceptes aquest Pokémon?");
const u8 gText_4Spaces[] = _("    "); // Unused
const u8 gText_SamePkmnInPartyAlready[] = _("Ja tens el mateix {PKMN} a l'equip.");
const u8 gText_DecimalPoint[] = _(".");
const u8 gText_SavingPlayer[] = _("Jugador");
const u8 gText_SavingBadges[] = _("Medalles");
const u8 gText_SavingPokedex[] = _("Pokédex");
const u8 gText_SavingTime[] = _("Temps");
const u8 gText_WirelessCommStatus[] = _("Estat de la comunicació sense fils");
const u8 gText_PeopleTrading[] = _("Persones intercanviant:");
const u8 gText_PeopleBattling[] = _("Persones combatent:");
const u8 gText_PeopleInUnionRoom[] = _("Persones a la Sala d'Unió:");
const u8 gText_PeopleCommunicating[] = _("Persones comunicant-se:");
const u8 gText_F700Players[] = _("{DYNAMIC 0} jugadors");
const u8 gText_F701Players[] = _("{DYNAMIC 1} jugadors");
const u8 gText_F702Players[] = _("{DYNAMIC 2} jugadors");
const u8 gText_F703Players[] = _("{DYNAMIC 3} jugadors");

const u8 *const gTextTable_Players[] = {
    gText_F700Players,
    gText_F701Players,
    gText_F702Players,
    gText_F703Players
};

ALIGNED(4) const u8 gText_WonderCards[] = _("Cartes Prodigi");
ALIGNED(4) const u8 gText_WonderNews[] = _("Notícies Prodigi");
ALIGNED(4) const u8 gText_WirelessCommunication[] = _("Comunicació sense fils");
ALIGNED(4) const u8 gText_Friend2[] = _("Amic");
ALIGNED(4) const u8 gText_Exit3[] = _("Sortir");
ALIGNED(4) const u8 gText_Receive[] = _("Rebre");
ALIGNED(4) const u8 gText_Send[] = _("Enviar");
ALIGNED(4) const u8 gText_Toss[] = _("Llençar");
ALIGNED(4) const u8 gText_VarietyOfEventsImportedWireless[] = _(
    "S'importaran diversos fets per\n"
    "comunicació sense fils.");
ALIGNED(4) const u8 gText_WonderCardsInPossession[] = _(
    "Llegeix les Cartes Prodigi que\n"
    "tens.");
ALIGNED(4) const u8 gText_ReadNewsThatArrived[] = _("Llegeix les notícies que han arribat.");
ALIGNED(4) const u8 gText_ReturnToTitle[] = _("Torna a la pantalla de títol.");
ALIGNED(4) const u8 gText_DontHaveCardNewOneInput[] = _(
    "No tens cap Carta Prodigi, així\n"
    "que s'introduirà una de nova.");
ALIGNED(4) const u8 gText_DontHaveNewsNewOneInput[] = _(
    "No tens cap Notícia Prodigi, així\n"
    "que s'introduirà una de nova.");
ALIGNED(4) const u8 gText_WhereShouldCardBeAccessed[] = _(
    "D'on vols obtenir la Carta\n"
    "Prodigi?");
ALIGNED(4) const u8 gText_WhereShouldNewsBeAccessed[] = _(
    "D'on vols obtenir la Notícia\n"
    "Prodigi?");
ALIGNED(4) const u8 gText_CommunicationStandbyBButtonCancel[] = _(
    "En espera de comunicació…\n"
    "Botó B: Cancel·lar"); // Unused
ALIGNED(4) const u8 gText_Communicating[] = _("S'està comunicant…");
ALIGNED(4) const u8 gText_CommunicationCompleted[] = _("Comunicació acabada.");
ALIGNED(4) const u8 gText_CommunicationError[] = _("Error de comunicació.");
ALIGNED(4) const u8 gText_CommunicationCanceled[] = _("S'ha cancel·lat la comunicació.");
ALIGNED(4) const u8 gText_ThrowAwayWonderCard[] = _(
    "Vols llençar la Carta Prodigi\n"
    "i introduir-ne una de nova?");
ALIGNED(4) const u8 gText_HaventReceivedCardsGift[] = _(
    "Encara no has rebut el regal de la\n"
    "carta. Vols introduir-ne una de nova?");
ALIGNED(4) const u8 gText_WonderCardReceivedFrom[] = _(
    "Has rebut una Carta Prodigi\n"
    "de {STR_VAR_1}.");
ALIGNED(4) const u8 gText_WonderNewsReceivedFrom[] = _(
    "Has rebut una Notícia Prodigi\n"
    "de {STR_VAR_1}.");
ALIGNED(4) const u8 gText_WonderCardReceived[] = _(
    "Has rebut una Carta Prodigi\n"
    "nova.");
ALIGNED(4) const u8 gText_WonderNewsReceived[] = _(
    "Has rebut una Notícia Prodigi\n"
    "nova.");
ALIGNED(4) const u8 gText_NewStampReceived[] = _("Has rebut un Segell nou.");
ALIGNED(4) const u8 gText_NewTrainerReceived[] = _("Ha arribat un entrenador nou.");
ALIGNED(4) const u8 gText_AlreadyHadCard[] = _(
    "Ja tenies aquesta\n"
    "Carta Prodigi.");
ALIGNED(4) const u8 gText_AlreadyHadNews[] = _(
    "Ja tenies aquesta\n"
    "Notícia Prodigi.");
ALIGNED(4) const u8 gText_AlreadyHadStamp[] = _(
    "Ja tenies aquest\n"
    "Segell.");
ALIGNED(4) const u8 gText_NoMoreRoomForStamps[] = _(
    "Ja no hi ha lloc per a més\n"
    "Segells.");
ALIGNED(4) const u8 gText_RecordUploadedViaWireless[] = _(
    "El teu registre s'ha enviat per\n"
    "comunicació sense fils.");
ALIGNED(4) const u8 gText_CantAcceptCardFromTrainer[] = _(
    "No pots acceptar una Carta Prodigi\n"
    "d'aquest entrenador.");
ALIGNED(4) const u8 gText_CantAcceptNewsFromTrainer[] = _(
    "No pots acceptar Notícies Prodigi\n"
    "d'aquest entrenador.");
ALIGNED(4) const u8 gText_NothingSentOver[] = _("No s'ha enviat res…");
ALIGNED(4) const u8 gText_WhatToDoWithCards[] = _(
    "Què vols fer amb les\n"
    "Cartes Prodigi?");
ALIGNED(4) const u8 gText_WhatToDoWithNews[] = _(
    "Què vols fer amb les\n"
    "Notícies Prodigi?");
ALIGNED(4) const u8 gText_SendingWonderCard[] = _("S'envia la teva Carta Prodigi…");
ALIGNED(4) const u8 gText_SendingWonderNews[] = _("S'envia la teva Notícia Prodigi…");
ALIGNED(4) const u8 gText_WonderCardSentTo[] = _(
    "La teva Carta Prodigi s'ha enviat\n"
    "a {STR_VAR_1}.");
ALIGNED(4) const u8 gText_WonderNewsSentTo[] = _(
    "La teva Notícia Prodigi s'ha\n"
    "enviat a {STR_VAR_1}.");
ALIGNED(4) const u8 gText_StampSentTo[] = _("S'ha enviat un Segell a {STR_VAR_1}.");
ALIGNED(4) const u8 gText_GiftSentTo[] = _("S'ha enviat un Regal a {STR_VAR_1}.");
ALIGNED(4) const u8 gText_OtherTrainerHasCard[] = _(
    "L'altre entrenador ja té la\n"
    "mateixa Carta Prodigi.");
ALIGNED(4) const u8 gText_OtherTrainerHasNews[] = _(
    "L'altre entrenador ja té la\n"
    "mateixa Notícia Prodigi.");
ALIGNED(4) const u8 gText_OtherTrainerHasStamp[] = _(
    "L'altre entrenador ja té el\n"
    "mateix Segell.");
ALIGNED(4) const u8 gText_OtherTrainerCanceled[] = _(
    "L'altre entrenador ha cancel·lat\n"
    "la comunicació.");
ALIGNED(4) const u8 gText_CantSendGiftToTrainer[] = _(
    "No pots enviar un Regal Misteriós\n"
    "a aquest entrenador.");
ALIGNED(4) const u8 gText_IfThrowAwayCardEventWontHappen[] = _(
    "Si llences la carta, el seu fet\n"
    "no passarà. Hi estàs d'acord?");
ALIGNED(4) const u8 gText_OkayToDiscardNews[] = _(
    "Vols descartar aquesta\n"
    "notícia?");
ALIGNED(4) const u8 gText_HaventReceivedGiftOkayToDiscard[] = _(
    "Encara no has rebut el regal.\n"
    "El vols descartar?");
ALIGNED(4) const u8 gText_DataWillBeSaved[] = _(
    "Es desaran les dades.\n"
    "Espera un moment.");
ALIGNED(4) const u8 gText_SaveCompletedPressA[] = _(
    "S'ha desat la partida.\n"
    "Prem el botó A.");
ALIGNED(4) const u8 gText_WonderCardThrownAway[] = _("S'ha llençat la Carta Prodigi.");
ALIGNED(4) const u8 gText_WonderNewsThrownAway[] = _("S'ha llençat la Notícia Prodigi.");
ALIGNED(4) const u8 gText_MysteryGift[] = _("Regal Misteriós");
ALIGNED(4) const u8 gText_PickOKExit[] = _("{DPAD_UPDOWN}Tria {A_BUTTON}D'acord {B_BUTTON}Surt");
ALIGNED(4) const u8 gText_PickOKCancel[] = _("{DPAD_UPDOWN}Tria {A_BUTTON}D'acord {B_BUTTON}Cancel·la");
const u8 gText_PlayersBattleResults[] = _("Resultats de combat de {PLAYER}");
const u8 gText_TotalRecordWLD[] = _("Registre total V:{STR_VAR_1} D:{STR_VAR_2} E:{STR_VAR_3}");
const u8 gText_WinLoseDraw[] = _("{CLEAR_TO 0x53}Vict.{CLEAR_TO 0x80}Derr.{CLEAR_TO 0xB0}Emp.");
const u8 gText_CommunicationStandby5[] = _("En espera de comunicació…");
const u8 gText_QuitTheGame[] = _("Vols sortir del joc?");
const u8 gText_YouveGot9999Coins[] = _("Ja tens 9.999 fitxes.");
const u8 gText_YouveRunOutOfCoins[] = _(
    "T'has quedat sense fitxes.\n"
    "Fi del joc!");
const u8 gText_YouDontHaveThreeCoins[] = _("No tens tres fitxes.");
const u8 gText_ReelTimeHelp[] = _(
    "Temps de Rodets\n"
    "Ara pots apuntar i encertar\n"
    "les marques!\n"
    "El Temps de Rodets dura les\n"
    "tirades que t'hagin donat.\n"
    "S'acaba amb un Gran Premi.");
const u8 gDaycareText_GetAlongVeryWell[] = _(
    "Sembla que es porten\n"
    "molt bé.");
const u8 gDaycareText_GetAlong[] = _("Sembla que es porten bé.");
const u8 gDaycareText_DontLikeOther[] = _(
    "Sembla que no s'agraden\n"
    "gaire.");
const u8 gDaycareText_PlayOther[] = _(
    "Els dos prefereixen jugar amb\n"
    "altres Pokémon que entre ells.");
const u8 gText_NewLine2[] = _("\n");
const u8 gText_Exit4[] = _("Sortir");
const u8 gText_Lv[] = _("{LV}");
const u8 gText_TimeBoard[] = _("Marcador de temps");
const u8 gText_TimeCleared[] = _("Temps aconseguit ");
const u8 gText_XMinYDotZSec[] = _("{STR_VAR_1} min {STR_VAR_2},{STR_VAR_3} s");
const u8 gText_TrainerHill1F[] = _("1F");
const u8 gText_TrainerHill2F[] = _("2F");
const u8 gText_TrainerHill3F[] = _("3F");
const u8 gText_TrainerHill4F[] = _("4F");
const u8 gText_TeachWhichMoveToPkmn[] = _(
    "Quin moviment vols ensenyar a\n"
    "{STR_VAR_1}?");
const u8 gText_MoveRelearnerTeachMoveConfirm[] = _("Vols ensenyar {STR_VAR_2}?");
const u8 gText_MoveRelearnerPkmnLearnedMove[] = _(
    "{STR_VAR_1} ha après\n"
    "{STR_VAR_2}!");
const u8 gText_MoveRelearnerPkmnTryingToLearnMove[] = _(
    "{STR_VAR_1} intenta aprendre\n"
    "{STR_VAR_2}.\pPerò {STR_VAR_1} no pot saber més\n"
    "de quatre moviments.\pVols esborrar un moviment antic per\n"
    "fer lloc a {STR_VAR_2}?");
const u8 gText_MoveRelearnerStopTryingToTeachMove[] = _(
    "Vols deixar d'ensenyar\n"
    "{STR_VAR_2}?");
const u8 gText_MoveRelearnerAndPoof[] = _("{PAUSE 32}1, {PAUSE 15}2 i {PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Puf!\p");
const u8 gText_MoveRelearnerPkmnForgotMoveAndLearnedNew[] = _("{STR_VAR_1} ha oblidat {STR_VAR_3}.\pI…\p{STR_VAR_1} ha après {STR_VAR_2}.");
const u8 gText_MoveRelearnedPkmnDidNotLearnMove[] = _(
    "{STR_VAR_1} no ha après el\n"
    "moviment {STR_VAR_2}."); // Unused
const u8 gText_MoveRelearnerGiveUp[] = _(
    "Vols deixar d'ensenyar un\n"
    "moviment nou a {STR_VAR_1}?");
const u8 gText_MoveRelearnerWhichMoveToForget[] = _(
    "Quin moviment vols\n"
    "oblidar?\p");
const u8 gText_MoveRelearnerBattleMoves[] = _("Moviments de combat");
const u8 gText_MoveRelearnerContestMovesTitle[] = _("Moviments de concurs");
const u8 gText_MoveRelearnerType[] = _("Tipus/"); // Unused
const u8 gText_MoveRelearnerPP[] = _("PP/");
const u8 gText_MoveRelearnerPower[] = _("Potència/");
const u8 gText_MoveRelearnerAccuracy[] = _("Precisió/");
const u8 gText_MoveRelearnerAppeal[] = _("Atractiu");
const u8 gText_MoveRelearnerJam[] = _("Bloqueig");
const u8 gText_Kira[] = _("Kira");
const u8 gText_Amy[] = _("Amy");
const u8 gText_John[] = _("John");
const u8 gText_Roy[] = _("Roy");
const u8 gText_Gabby[] = _("Gabby");
const u8 gText_Anna[] = _("Anna");
const u8 gText_ClearAllSaveData[] = _(
    "Vols esborrar totes les dades\n"
    "desades?");
const u8 gText_ClearingData[] = _(
    "S'esborren les dades…\n"
    "Espera un moment.");
const u8 gText_IsThisTheCorrectTime[] = _("És aquesta l'hora correcta?");
const u8 gText_Confirm3[] = _("Confirmar");
const u8 gText_Cancel4[] = _("Cancel·lar");

//Updated Match Call
const u8 gText_ProfOakMatchCallDesc[] = _("Prof. {PKMN}");
const u8 gText_ProfOakMatchCallName[] = _("Prof. Oak");
const u8 gText_MatchCallOak_Strategy[] = _("Prefereixo estudiar.");
const u8 gText_MatchCallOak_Pokemon[] = _("Respecto tots els Pokémon.");
const u8 gText_MatchCallOak_Intro1[] = _("Completar el Pokédex");
const u8 gText_MatchCallOak_Intro2[] = _("és el somni de la meva vida!");

const u8 gText_MomMatchCallDesc[] = _("Tranquil i amable");
const u8 gText_MomMatchCallName[] = _("Mom");

const u8 gText_AideMatchCallDesc[] = _("Ajudant del Prof.");
const u8 gText_AideMatchCallName[] = _("Cedar");

const u8 gText_RivalMatchCallDesc[] = _("Veí impertinent");
const u8 gText_MatchCallRival_Strategy[] = _("Tinc ganes de combatre.");
const u8 gText_MatchCallRival_Pokemon[] = _(
    "Faré servir qualsevol Pokémon\n"
    "per guanyar!");
const u8 gText_MatchCallRival_Intro1[] = _("Si veig un entrenador fort,");
const u8 gText_MatchCallRival_Intro2[] = _("em vindran ganes de lluitar!");

const u8 gText_ScottMatchCallDesc[] = _("Noi del gimnàs");
const u8 gText_ScottMatchCallName[] = _("Scott");
const u8 gText_MatchCallScott_Strategy[] = _("Ensenya'm un bon combat!");
const u8 gText_MatchCallScott_Pokemon[] = _("Jo no entreno Pokémon.");
const u8 gText_MatchCallScott_Intro1[] = _("Recorro Kanto buscant els");
const u8 gText_MatchCallScott_Intro2[] = _("entrenadors més forts!");

const u8 gText_LookerMatchCallDesc[] = _("Inspector");
const u8 gText_LookerMatchCallName[] = _("Looker");
const u8 gText_MatchCallLooker_Strategy[] = _("Vaig a la caça de l'Equip Rocket!");
const u8 gText_MatchCallLooker_Pokemon[] = _("M'agraden els Pokémon lleials.");
const u8 gText_MatchCallLooker_Intro1[] = _("No deixaré que l'Equip Rocket");
const u8 gText_MatchCallLooker_Intro2[] = _("s'escapi de la justícia!");

const u8 gText_BillMatchCallDesc[] = _("PokéManíac");
const u8 gText_BillMatchCallName[] = _("Bill");
const u8 gText_MatchCallBill_Strategy[] = _("Sóc un autèntic Pokémaníac!");
const u8 gText_MatchCallBill_Pokemon[] = _("Em vaig convertir en un Pokémon.");
const u8 gText_MatchCallBill_Intro1[] = _("Invento coses per ajudar");
const u8 gText_MatchCallBill_Intro2[] = _("els Pokémon i les persones!");

//
const u8 gText_CommStandbyAwaitingOtherPlayer[] = _(
    "En espera de comunicació…\n"
    "Esperant que un altre jugador triï.");
const u8 gText_BattleWasRefused[] = _("S'ha rebutjat el combat.{PAUSE 60}");
const u8 gText_RefusedBattle[] = _("Has rebutjat el combat.{PAUSE 60}");
const u8 gText_NoWeather[] = _("Sense clima"); // Below are unused debug names for weather types
const u8 gText_Sunny[] = _("Assolellat"); // Unused
const u8 gText_Sunny2[] = _("Assolellat2"); // Unused
const u8 gText_Rain[] = _("Pluja"); // Unused
const u8 gText_Snow[] = _("Neu"); // Unused
const u8 gText_Lightning[] = _("Llamps"); // Unused
const u8 gText_Fog[] = _("Boira"); // Unused
const u8 gText_VolcanoAsh[] = _("Cendra volcànica"); // Unused
const u8 gText_Sandstorm[] = _("Tempesta de sorra"); // Unused
const u8 gText_Fog2[] = _("Boira2"); // Unused
const u8 gText_Seafloor[] = _("Fons marí"); // Unused
const u8 gText_Cloudy[] = _("Ennuvolat"); // Unused
const u8 gText_Sunny3[] = _("Assolellat3"); // Unused
const u8 gText_HeavyRain[] = _("Pluja intensa"); // Unused
const u8 gText_Seafloor2[] = _("Fons marí2"); // Unused
const u8 gText_DelAll[] = _("Esb. tot");
const u8 gText_Cancel5[] = _("Cancel·lar");
const u8 gText_Ok2[] = _("D'acord");
const u8 gText_Quiz[] = _("Qüestionari");
const u8 gText_Answer[] = _("Resposta");
const u8 gText_PokeBalls[] = _("Poké Balls");
const u8 gText_Berry[] = _("Baia");
const u8 gText_Berries[] = _("Baies");

const u8 gText_FirstDrawer[] = _("Primer");
const u8 gText_SecondDrawer[] = _("Segon");
const u8 gText_ThirdDrawer[] = _("Tercer");
const u8 gText_FourthDrawer[] = _("Quart");

const u8 gText_RedCostume[] = _("Vermell");
const u8 gText_LeafCostume[] = _("Verd");
const u8 gText_EthanCostume[] = _("Or");
const u8 gText_LyraCostume[] = _("Plata");
const u8 gText_KrisCostume[] = _("Crystal");
const u8 gText_BrendanCostume[] = _("Ruby");
const u8 gText_MayCostume[] = _("Sapphire");
const u8 gText_LucasCostume[] = _("Diamond");
const u8 gText_DawnCostume[] = _("Pearl");
const u8 gText_LucasPlatinumCostume[] = _("Platinum 1");
const u8 gText_DawnPlatinumCostume[] = _("Platinum 2");

const u8 gText_DexNavDescription[] = _("Cerca Pokémon salvatges.");

const u8 gText_ReadPoison[] = _("Verí");
const u8 gText_ReadSleep[] = _("Son");
const u8 gText_ReadParalysis[] = _("Paràlisi");
const u8 gText_ReadBurn[] = _("Cremada");
const u8 gText_ReadFreeze[] = _("Gel");

const u8 gText_Eevee[] = _("Eevee");
const u8 gText_Flareon[] = _("Flareon");
const u8 gText_Jolteon[] = _("Jolteon");
const u8 gText_Vaporeon[] = _("Vaporeon");

const u8 gText_AbilityCapsuleBP[] = _("Càps. Habil.{CLEAR_TO 0x64}50PC");
const u8 gText_AbilityPatchBP[] = _("Pegat Habil.{CLEAR_TO 0x64}200PC");

const u8 gText_AdamantMintBP[] = _("Menta Ferma{CLEAR_TO 0x64}50PC");
const u8 gText_BoldMintBP[] = _("Menta Audaç{CLEAR_TO 0x64}50PC");
const u8 gText_BraveMintBP[] = _("Menta Valenta{CLEAR_TO 0x64}50PC");
const u8 gText_CalmMintBP[] = _("Menta Calmada{CLEAR_TO 0x64}50PC");
const u8 gText_CarefulMintBP[] = _("Menta Curosa{CLEAR_TO 0x64}50PC");
const u8 gText_GentleMintBP[] = _("Menta Amable{CLEAR_TO 0x64}50PC");
const u8 gText_HastyMintBP[] = _("Menta Precip.{CLEAR_TO 0x64}50PC");
const u8 gText_ImpishMintBP[] = _("Menta Pícara{CLEAR_TO 0x64}50PC");
const u8 gText_JollyMintBP[] = _("Menta Alegre{CLEAR_TO 0x64}50PC");
const u8 gText_LaxMintBP[] = _("Menta Fluixa{CLEAR_TO 0x64}50PC");
const u8 gText_LonelyMintBP[] = _("Menta Solit.{CLEAR_TO 0x64}50PC");
const u8 gText_MildMintBP[] = _("Menta Suau{CLEAR_TO 0x64}50PC");
const u8 gText_ModestMintBP[] = _("Menta Modesta{CLEAR_TO 0x64}50PC");
const u8 gText_NaiveMintBP[] = _("Menta Ingènua{CLEAR_TO 0x64}50PC");
const u8 gText_NaughtyMintBP[] = _("Menta Murri{CLEAR_TO 0x64}50PC");
const u8 gText_QuietMintBP[] = _("Menta Tranq.{CLEAR_TO 0x64}50PC");
const u8 gText_RashMintBP[] = _("Menta Impuls.{CLEAR_TO 0x64}50PC");
const u8 gText_RelaxedMintBP[] = _("Menta Relax.{CLEAR_TO 0x64}50PC");
const u8 gText_SassyMintBP[] = _("Menta Descar.{CLEAR_TO 0x64}50PC");
const u8 gText_SeriousMintBP[] = _("Menta Seriosa{CLEAR_TO 0x64}50PC");
const u8 gText_TimidMintBP[] = _("Menta Tímida{CLEAR_TO 0x64}50PC");

//Infinite TMs
const u8 gText_SoldOut[] = _(
    "Em sap greu, però aquest objecte\n"
    "està exhaurit.\p");
const u8 gText_SoldOut2[] = _("EXHAURIT");

//Exp
const u8 gOtherText_ExpShareOn[] = _(
    "S'ha activat el Repartiexp.\pL'equip rebrà una part dels\n"
    "Punts d'Experiència.{PAUSE_UNTIL_PRESS}");
const u8 gOtherText_ExpShareOff[] = _(
    "S'ha desactivat el Repartiexp.\pL'equip ja no rebrà cap part dels\n"
    "Punts d'Experiència.{PAUSE_UNTIL_PRESS}");

//LGPE Premier Balls
const u8 gText_ThrowInPremierBalls[] = _("T'hi afegeixo unes Premier Balls.{PAUSE_UNTIL_PRESS}");


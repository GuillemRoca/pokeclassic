#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_z_move.h"
#include "data.h"
#include "event_data.h"
#include "frontier_util.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "menu.h"
#include "palette.h"
#include "recorded_battle.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "trainer_hill.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/battle_dome.h"
#include "constants/battle_string_ids.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/opponents.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/trainer_hill.h"
#include "constants/weather.h"

struct BattleWindowText
{
    u8 fillValue;
    u8 fontId;
    u8 x;
    u8 y;
    u8 letterSpacing;
    u8 lineSpacing;
    u8 speed;
    u8 fgColor;
    u8 bgColor;
    u8 shadowColor;
};

static void ChooseMoveUsedParticle(u8 *textPtr);
static void ChooseTypeOfMoveUsedString(u8 *dst);

static EWRAM_DATA u16 sBattlerAbilities[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA struct BattleMsgData *gBattleMsgDataPtr = NULL;

// todo: make some of those names less vague: attacker/target vs pkmn, etc.

static const u8 sText_Trainer1LoseText[] = _("{B_TRAINER1_LOSE_TEXT}");
static const u8 sText_PkmnGainedEXP[] = _(
    "{B_BUFF1} ha guanyat{B_BUFF2}\n"
    "{B_BUFF3} Punts d'Exp.!\p");
static const u8 sText_EmptyString4[] = _("");
static const u8 sText_ABoosted[] = _(" uns augmentats");
static const u8 sText_PkmnGrewToLv[] = _(
    "{B_BUFF1} ha pujat al\n"
    "NIV. {B_BUFF2}!{WAIT_SE}\p");
static const u8 sText_PkmnLearnedMove[] = _(
    "{B_BUFF1} ha après\n"
    "{B_BUFF2}!{WAIT_SE}\p");
static const u8 sText_TryToLearnMove1[] = _(
    "{B_BUFF1} intenta aprendre\n"
    "{B_BUFF2}.\p");
static const u8 sText_TryToLearnMove2[] = _(
    "Però {B_BUFF1} no pot saber\n"
    "més de quatre moviments.\p");
static const u8 sText_TryToLearnMove3[] = _(
    "Vols esborrar un moviment per\n"
    "fer lloc a {B_BUFF2}?");
static const u8 sText_PkmnForgotMove[] = _(
    "{B_BUFF1} ha oblidat\n"
    "{B_BUFF2}.\p");
static const u8 sText_StopLearningMove[] = _(
    "{PAUSE 32}Vols deixar d'aprendre\n"
    "{B_BUFF2}?");
static const u8 sText_DidNotLearnMove[] = _(
    "{B_BUFF1} no ha après\n"
    "{B_BUFF2}.\p");
static const u8 sText_UseNextPkmn[] = _("Vols fer servir el següent Pokémon?");
static const u8 sText_AttackMissed[] = _(
    "L'atac de {B_ATK_NAME_WITH_PREFIX}\n"
    "ha fallat!");
static const u8 sText_PkmnProtectedItself[] = _(
    "{B_DEF_NAME_WITH_PREFIX}\n"
    "s'ha protegit!");
static const u8 sText_AvoidedDamage[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha evitat\n"
    "el dany amb {B_DEF_ABILITY}!");
static const u8 sText_PkmnMakesGroundMiss[] = _(
    "{B_DEF_NAME_WITH_PREFIX} fa fallar els\n"
    "moviments Terra amb {B_DEF_ABILITY}!");
static const u8 sText_PkmnAvoidedAttack[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha evitat\n"
    "l'atac!");
static const u8 sText_ItDoesntAffect[] = _(
    "No afecta\n"
    "{B_DEF_NAME_WITH_PREFIX}…");
static const u8 sText_AttackerFainted[] = _(
    "{B_ATK_NAME_WITH_PREFIX}\n"
    "s'ha debilitat!\p");
static const u8 sText_TargetFainted[] = _(
    "{B_DEF_NAME_WITH_PREFIX}\n"
    "s'ha debilitat!\p");
static const u8 sText_PlayerGotMoney[] = _(
    "{B_PLAYER_NAME} ha guanyat ¥{B_BUFF1}\n"
    "per la victòria!\p");
static const u8 sText_PlayerLostToEnemyTrainer[] = _(
    "{B_PLAYER_NAME} no té cap POKéMON\n"
    "en condicions!\pHa perdut contra\n"
    "{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PlayerPaidPrizeMoney[] = _(
    "{B_PLAYER_NAME} ha pagat ¥{B_BUFF1} de\n"
    "premi…\p… … … …\p{B_PLAYER_NAME} s'ha desmaiat!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PlayerPaidPrizeMoneyNoWhiteout[] = _(
    "{B_PLAYER_NAME} ha pagat ¥{B_BUFF1} de\n"
    "premi…\p… … … …{PAUSE_UNTIL_PRESS}");
static const u8 sText_PlayerWhiteout[] = _(
    "{B_PLAYER_NAME} no té cap POKéMON\n"
    "en condicions!\p");
#if B_WHITEOUT_MONEY >= GEN_4
static const u8 sText_PlayerWhiteout2[] = _("{B_PLAYER_NAME} s'ha espantat i ha perdut ¥{B_BUFF1}…\p… … … …\p{B_PLAYER_NAME} s'ha desmaiat!{PAUSE_UNTIL_PRESS}");
#else
static const u8 sText_PlayerWhiteout2[] = _("{B_PLAYER_NAME} s'ha desmaiat!{PAUSE_UNTIL_PRESS}");
#endif
static const u8 sText_PlayerDroppedMoneyNoWhiteout[] = _("{B_PLAYER_NAME} s'ha espantat i ha perdut ¥{B_BUFF1}…\p… … … …{PAUSE_UNTIL_PRESS}");
static const u8 sText_PlayerWhiteout3[] = _("{B_PLAYER_NAME} ha perdut el combat!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PreventsEscape[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} impedeix\n"
    "la fugida amb {B_SCR_ACTIVE_ABILITY}!\p");
static const u8 sText_CantEscape2[] = _("No es pot escapar!\p");
static const u8 sText_AttackerCantEscape[] = _("{B_ATK_NAME_WITH_PREFIX} no pot escapar!");
static const u8 sText_HitXTimes[] = _("Ha encertat {B_BUFF1} vegada(es)!");
static const u8 sText_PkmnFellAsleep[] = _(
    "{B_EFF_NAME_WITH_PREFIX}\n"
    "s'ha adormit!");
static const u8 sText_PkmnMadeSleep[] = _(
    "{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "ha adormit {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAlreadyAsleep[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ja\n"
    "està adormit!");
static const u8 sText_PkmnAlreadyAsleep2[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ja\n"
    "està adormit!");
static const u8 sText_PkmnWasntAffected[] = _(
    "{B_DEF_NAME_WITH_PREFIX}\n"
    "no se'n ha vist afectat!");
static const u8 sText_PkmnWasPoisoned[] = _(
    "{B_EFF_NAME_WITH_PREFIX}\n"
    "s'ha enverinat!");
static const u8 sText_PkmnPoisonedBy[] = _(
    "{B_BUFF1} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "ha enverinat {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtByPoison[] = _(
    "El verí fa mal a\n"
    "{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAlreadyPoisoned[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ja està\n"
    "enverinat.");
static const u8 sText_PkmnBadlyPoisoned[] = _(
    "{B_EFF_NAME_WITH_PREFIX} està greument\n"
    "enverinat!");
static const u8 sText_PkmnEnergyDrained[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha perdut\n"
    "energia!");
static const u8 sText_PkmnWasBurned[] = _("{B_EFF_NAME_WITH_PREFIX} s'ha cremat!");
static const u8 sText_PkmnBurnedBy[] = _(
    "{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "ha cremat {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtByBurn[] = _(
    "La cremada fa mal a\n"
    "{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAlreadyHasBurn[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ja\n"
    "està cremat.");
static const u8 sText_PkmnWasFrozen[] = _(
    "{B_EFF_NAME_WITH_PREFIX} s'ha\n"
    "congelat!");
static const u8 sText_PkmnFrozenBy[] = _(
    "{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "ha congelat {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnIsFrozen[] = _(
    "{B_ATK_NAME_WITH_PREFIX} està\n"
    "congelat!");
static const u8 sText_PkmnWasDefrosted[] = _(
    "{B_DEF_NAME_WITH_PREFIX} s'ha\n"
    "desglaçat!");
static const u8 sText_PkmnWasDefrosted2[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha\n"
    "desglaçat!");
static const u8 sText_PkmnWasDefrostedBy[] = _(
    "{B_CURRENT_MOVE} ha desglaçat\n"
    "{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnWasParalyzed[] = _(
    "{B_EFF_NAME_WITH_PREFIX} està paralitzat!\n"
    "Potser no es podrà moure!");
static const u8 sText_PkmnWasParalyzedBy[] = _(
    "{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "ha paralitzat {B_EFF_NAME_WITH_PREFIX}!\lPotser no es podrà moure!");
static const u8 sText_PkmnIsParalyzed[] = _(
    "{B_ATK_NAME_WITH_PREFIX} està paralitzat!\n"
    "No es pot moure!");
static const u8 sText_PkmnIsAlreadyParalyzed[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ja\n"
    "està paralitzat!");
static const u8 sText_PkmnHealedParalysis[] = _(
    "{B_DEF_NAME_WITH_PREFIX} s'ha\n"
    "curat de la paràlisi!");
static const u8 sText_PkmnDreamEaten[] = _(
    "S'ha menjat el somni de\n"
    "{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_StatsWontIncrease[] = _(
    "{B_BUFF1} de {B_ATK_NAME_WITH_PREFIX}\n"
    "no pot pujar més!");
static const u8 sText_StatsWontDecrease[] = _(
    "{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}\n"
    "no pot baixar més!");
static const u8 sText_TeamStoppedWorking[] = _(
    "{B_BUFF1} del teu equip\n"
    "ha deixat de funcionar!");
static const u8 sText_FoeStoppedWorking[] = _(
    "{B_BUFF1} de l'equip rival\n"
    "ha deixat de funcionar!");
static const u8 sText_PkmnIsConfused[] = _(
    "{B_ATK_NAME_WITH_PREFIX} està\n"
    "confós!");
static const u8 sText_PkmnHealedConfusion[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha sortit\n"
    "de la confusió!");
static const u8 sText_PkmnWasConfused[] = _(
    "{B_EFF_NAME_WITH_PREFIX} s'ha\n"
    "confós!");
static const u8 sText_PkmnAlreadyConfused[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ja\n"
    "està confós!");
static const u8 sText_PkmnFellInLove[] = _(
    "{B_DEF_NAME_WITH_PREFIX}\n"
    "s'ha enamorat!");
static const u8 sText_PkmnInLove[] = _(
    "{B_ATK_NAME_WITH_PREFIX} està enamorat\n"
    "de {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnImmobilizedByLove[] = _(
    "L'amor ha immobilitzat\n"
    "{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnBlownAway[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha sortit\n"
    "volant!");
static const u8 sText_PkmnChangedType[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha convertit\n"
    "en tipus {B_BUFF1}!");
static const u8 sText_PkmnFlinched[] = _("{B_ATK_NAME_WITH_PREFIX} s'ha esglaiat!");
static const u8 sText_PkmnRegainedHealth[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha recuperat\n"
    "salut!");
static const u8 sText_PkmnHPFull[] = _(
    "{B_DEF_NAME_WITH_PREFIX} té\n"
    "els PS al màxim!");
static const u8 sText_PkmnRaisedSpDef[] = _(
    "{B_CURRENT_MOVE} de {B_ATK_PREFIX2}\n"
    "ha pujat la Def. Esp.!");
static const u8 sText_PkmnRaisedSpDefALittle[] = _(
    "{B_CURRENT_MOVE} de {B_ATK_PREFIX2}\n"
    "ha pujat una mica la Def. Esp.!");
static const u8 sText_PkmnRaisedDef[] = _(
    "{B_CURRENT_MOVE} de {B_ATK_PREFIX2}\n"
    "ha pujat la Defensa!");
static const u8 sText_PkmnRaisedDefALittle[] = _(
    "{B_CURRENT_MOVE} de {B_ATK_PREFIX2}\n"
    "ha pujat una mica la Defensa!");
static const u8 sText_PkmnCoveredByVeil[] = _(
    "L'equip de {B_ATK_PREFIX2} està\n"
    "cobert per un vel!");
static const u8 sText_PkmnUsedSafeguard[] = _(
    "L'equip de {B_DEF_NAME_WITH_PREFIX} està\n"
    "protegit per Salvaguarda!");
static const u8 sText_PkmnSafeguardExpired[] = _(
    "L'equip de {B_ATK_PREFIX3} ja no\n"
    "està protegit per Salvaguarda!");
static const u8 sText_PkmnWentToSleep[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha\n"
    "adormit!");
static const u8 sText_PkmnSleptHealthy[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha dormit\n"
    "i s'ha recuperat!");
static const u8 sText_PkmnWhippedWhirlwind[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha aixecat\n"
    "un remolí!");
static const u8 sText_PkmnTookSunlight[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha absorbit\n"
    "llum del sol!");
static const u8 sText_PkmnLoweredHead[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha abaixat\n"
    "el cap!");
static const u8 sText_PkmnIsGlowing[] = _("{B_ATK_NAME_WITH_PREFIX} brilla!");
static const u8 sText_PkmnFlewHigh[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha volat\n"
    "ben amunt!");
static const u8 sText_PkmnDugHole[] = _("{B_ATK_NAME_WITH_PREFIX} ha cavat un forat!");
static const u8 sText_PkmnHidUnderwater[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha amagat\n"
    "sota l'aigua!");
static const u8 sText_PkmnSprangUp[] = _("{B_ATK_NAME_WITH_PREFIX} ha fet un bot!");
static const u8 sText_PkmnInSnapTrap[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha quedat\n"
    "atrapat en un parany!");
static const u8 sText_PkmnSqueezedByBind[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha constret\n"
    "{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnTrappedInVortex[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha quedat\n"
    "atrapat al remolí!");
static const u8 sText_PkmnTrappedBySandTomb[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha quedat\n"
    "atrapat per Tomba Sorra!");
static const u8 sText_PkmnWrappedBy[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha embolicat\n"
    "{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnClamped[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha atrapat\n"
    "{B_DEF_NAME_WITH_PREFIX} amb tenalles!");
static const u8 sText_PkmnHurtBy[] = _(
    "{B_BUFF1} fa mal a\n"
    "{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnFreedFrom[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha alliberat\n"
    "de {B_BUFF1}!");
static const u8 sText_PkmnCrashed[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha continuat\n"
    "i s'ha estavellat!");
const u8 gText_PkmnShroudedInMist[] = _(
    "{B_ATK_PREFIX2} s'ha\n"
    "embolcallat de Boira!");
static const u8 sText_PkmnProtectedByMist[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} està protegit\n"
    "per la Boira!");
const u8 gText_PkmnGettingPumped[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'està\n"
    "animant!");
static const u8 sText_PkmnHitWithRecoil[] = _(
    "{B_ATK_NAME_WITH_PREFIX} rep\n"
    "dany de retrocés!");
static const u8 sText_PkmnProtectedItself2[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha\n"
    "protegit!");
static const u8 sText_PkmnBuffetedBySandstorm[] = _(
    "La tempesta de sorra colpeja\n"
    "{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPeltedByHail[] = _(
    "La calamarsa colpeja\n"
    "{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnsXWoreOff[] = _(
    "{B_BUFF1} de {B_ATK_PREFIX1}\n"
    "s'ha esgotat!");
static const u8 sText_PkmnSeeded[] = _("{B_DEF_NAME_WITH_PREFIX} ha rebut una llavor!");
static const u8 sText_PkmnEvadedAttack[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha esquivat\n"
    "l'atac!");
static const u8 sText_PkmnSappedByLeechSeed[] = _(
    "Llavor Xucla drena la salut de\n"
    "{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnFastAsleep[] = _(
    "{B_ATK_NAME_WITH_PREFIX} dorm\n"
    "profundament.");
static const u8 sText_PkmnWokeUp[] = _("{B_ATK_NAME_WITH_PREFIX} s'ha despertat!");
static const u8 sText_PkmnUproarKeptAwake[] = _(
    "Però l'Aldarull de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "l'ha mantingut despert!");
static const u8 sText_PkmnWokeUpInUproar[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha despertat\n"
    "amb l'Aldarull!");
static const u8 sText_PkmnCausedUproar[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha causat\n"
    "un Aldarull!");
static const u8 sText_PkmnMakingUproar[] = _(
    "{B_ATK_NAME_WITH_PREFIX} està fent\n"
    "un Aldarull!");
static const u8 sText_PkmnCalmedDown[] = _("{B_ATK_NAME_WITH_PREFIX} s'ha calmat.");
static const u8 sText_PkmnCantSleepInUproar[] = _(
    "Però {B_DEF_NAME_WITH_PREFIX} no pot\n"
    "dormir amb un Aldarull!");
static const u8 sText_PkmnStockpiled[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha emmagatzemat\n"
    "{B_BUFF1}!");
static const u8 sText_PkmnCantStockpile[] = _(
    "{B_ATK_NAME_WITH_PREFIX} no pot\n"
    "emmagatzemar més!");
static const u8 sText_PkmnCantSleepInUproar2[] = _(
    "Però {B_DEF_NAME_WITH_PREFIX} no pot\n"
    "dormir amb un Aldarull!");
static const u8 sText_UproarKeptPkmnAwake[] = _(
    "Però l'Aldarull ha mantingut\n"
    "{B_DEF_NAME_WITH_PREFIX} despert!");
static const u8 sText_PkmnStayedAwakeUsing[] = _(
    "{B_DEF_NAME_WITH_PREFIX} s'ha mantingut\n"
    "despert amb {B_DEF_ABILITY}!");
static const u8 sText_PkmnStoringEnergy[] = _(
    "{B_ATK_NAME_WITH_PREFIX} està\n"
    "acumulant energia!");
static const u8 sText_PkmnUnleashedEnergy[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha deixat\n"
    "anar l'energia!");
static const u8 sText_PkmnFatigueConfusion[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha confós\n"
    "per la fatiga!");
static const u8 sText_PlayerPickedUpMoney[] = _(
    "{B_PLAYER_NAME} ha recollit\n"
    "¥{B_BUFF1}!\p");
static const u8 sText_PkmnUnaffected[] = _(
    "{B_DEF_NAME_WITH_PREFIX} no\n"
    "se'n veu afectat!");
static const u8 sText_PkmnTransformedInto[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha transformat\n"
    "en {B_BUFF1}!");
static const u8 sText_PkmnMadeSubstitute[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha creat\n"
    "un Substitut!");
static const u8 sText_PkmnHasSubstitute[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ja\n"
    "té un Substitut!");
static const u8 sText_SubstituteDamaged[] = _(
    "El Substitut ha rebut el dany\n"
    "per {B_DEF_NAME_WITH_PREFIX}!\p");
static const u8 sText_PkmnSubstituteFaded[] = _(
    "El Substitut de {B_DEF_NAME_WITH_PREFIX}\n"
    "ha desaparegut!\p");
static const u8 sText_PkmnMustRecharge[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha de\n"
    "recuperar forces!");
static const u8 sText_PkmnRageBuilding[] = _(
    "La Ràbia de {B_DEF_NAME_WITH_PREFIX}\n"
    "va creixent!");
static const u8 sText_PkmnMoveWasDisabled[] = _(
    "{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}\n"
    "ha quedat anul·lat!");
static const u8 sText_PkmnMoveDisabledNoMore[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ja no\n"
    "està anul·lat!");
static const u8 sText_PkmnGotEncore[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha rebut\n"
    "una Repetició!");
static const u8 sText_PkmnEncoreEnded[] = _(
    "La Repetició de {B_ATK_NAME_WITH_PREFIX}\n"
    "s'ha acabat!");
static const u8 sText_PkmnTookAim[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha apuntat\n"
    "a {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSketchedMove[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha esbossat\n"
    "{B_BUFF1}!");
static const u8 sText_PkmnTryingToTakeFoe[] = _(
    "{B_ATK_NAME_WITH_PREFIX} intenta\n"
    "endur-se el rival amb ell!");
static const u8 sText_PkmnTookFoe[] = _(
    "{B_DEF_NAME_WITH_PREFIX} s'ha endut\n"
    "{B_ATK_NAME_WITH_PREFIX} amb ell!");
static const u8 sText_PkmnReducedPP[] = _(
    "{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}\n"
    "ha baixat {B_BUFF2}!");
static const u8 sText_PkmnStoleItem[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha robat\n"
    "{B_LAST_ITEM} a {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_TargetCantEscapeNow[] = _(
    "Ara {B_DEF_NAME_WITH_PREFIX}\n"
    "no pot escapar!");
static const u8 sText_PkmnFellIntoNightmare[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha caigut\n"
    "en un Malson!");
static const u8 sText_PkmnLockedInNightmare[] = _(
    "{B_ATK_NAME_WITH_PREFIX} està atrapat\n"
    "en un Malson!");
static const u8 sText_PkmnLaidCurse[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha sacrificat PS i ha\n"
    "llançat una Maledicció a {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAfflictedByCurse[] = _(
    "{B_ATK_NAME_WITH_PREFIX} pateix\n"
    "la Maledicció!");
static const u8 sText_SpikesScattered[] = _(
    "S'han escampat Punxes per tot\n"
    "el costat del rival!");
static const u8 sText_PkmnHurtBySpikes[] = _(
    "Les Punxes fan mal a\n"
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnIdentified[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha identificat\n"
    "{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPerishCountFell[] = _(
    "El compte final de {B_ATK_NAME_WITH_PREFIX}\n"
    "ha baixat a {B_BUFF1}!");
static const u8 sText_PkmnBracedItself[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha\n"
    "preparat per aguantar!");
static const u8 sText_PkmnEnduredHit[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha aguantat\n"
    "el cop!");
static const u8 sText_MagnitudeStrength[] = _("Magnitud {B_BUFF1}!");
static const u8 sText_PkmnCutHPMaxedAttack[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha sacrificat PS i\n"
    "ha maximitzat l'Atac!");
static const u8 sText_PkmnCopiedStatChanges[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha copiat els canvis\n"
    "d'estadístiques de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnGotFree[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha alliberat de\n"
    "{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnShedLeechSeed[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha tret\n"
    "Llavor Xucla!");
static const u8 sText_PkmnBlewAwaySpikes[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha escampat\n"
    "les Punxes!");
static const u8 sText_PkmnFledFromBattle[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha fugit\n"
    "del combat!");
static const u8 sText_PkmnForesawAttack[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha previst\n"
    "un atac!");
static const u8 sText_PkmnTookAttack[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha rebut\n"
    "l'atac {B_BUFF1}!");
static const u8 sText_PkmnChoseXAsDestiny[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha triat\n"
    "{B_CURRENT_MOVE} com a destí!");
static const u8 sText_PkmnAttack[] = _("Atac de {B_BUFF1}!");
static const u8 sText_PkmnCenterAttention[] = _(
    "{B_DEF_NAME_WITH_PREFIX} s'ha convertit\n"
    "en el centre d'atenció!");
static const u8 sText_PkmnChargingPower[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha començat\n"
    "a acumular poder!");
static const u8 sText_NaturePowerTurnedInto[] = _(
    "Poder Natural s'ha convertit en\n"
    "{B_CURRENT_MOVE}!");
static const u8 sText_PkmnStatusNormal[] = _(
    "L'estat de {B_ATK_NAME_WITH_PREFIX}\n"
    "ha tornat a la normalitat!");
static const u8 sText_PkmnSubjectedToTorment[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha estat\n"
    "sotmès a Turment!");
static const u8 sText_PkmnTighteningFocus[] = _(
    "{B_ATK_NAME_WITH_PREFIX} es concentra\n"
    "amb força!");
static const u8 sText_PkmnFellForTaunt[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha caigut\n"
    "en la Mofa!");
static const u8 sText_PkmnReadyToHelp[] = _(
    "{B_ATK_NAME_WITH_PREFIX} està a punt\n"
    "d'ajudar {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSwitchedItems[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha bescanviat\n"
    "els objectes amb el rival!");
static const u8 sText_PkmnObtainedX[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha obtingut\n"
    "{B_BUFF1}.");
static const u8 sText_PkmnObtainedX2[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha obtingut\n"
    "{B_BUFF2}.");
static const u8 sText_PkmnObtainedXYObtainedZ[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha obtingut\n"
    "{B_BUFF1}.\p{B_DEF_NAME_WITH_PREFIX} ha obtingut\n"
    "{B_BUFF2}.");
static const u8 sText_PkmnCopiedFoe[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha copiat\n"
    "{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnMadeWish[] = _("{B_ATK_NAME_WITH_PREFIX} ha fet un Desig!");
static const u8 sText_PkmnWishCameTrue[] = _(
    "El Desig de {B_BUFF1}\n"
    "s'ha complert!");
static const u8 sText_PkmnPlantedRoots[] = _("{B_ATK_NAME_WITH_PREFIX} ha arrelat!");
static const u8 sText_PkmnAbsorbedNutrients[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha absorbit\n"
    "nutrients amb les arrels!");
static const u8 sText_PkmnAnchoredItself[] = _(
    "{B_DEF_NAME_WITH_PREFIX} s'ha ancorat\n"
    "amb les arrels!");
static const u8 sText_PkmnWasMadeDrowsy[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha fet venir\n"
    "son a {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnKnockedOff[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha fet caure\n"
    "{B_LAST_ITEM} de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSwappedAbilities[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha bescanviat\n"
    "les habilitats amb el rival!");
static const u8 sText_PkmnSealedOpponentMove[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha segellat\n"
    "els moviments del rival!");
static const u8 sText_PkmnWantsGrudge[] = _(
    "{B_ATK_NAME_WITH_PREFIX} vol que el\n"
    "rival li guardi Rancúnia!");
static const u8 sText_PkmnLostPPGrudge[] = _(
    "{B_BUFF1} de {B_ATK_NAME_WITH_PREFIX} ha perdut\n"
    "tots els PP per la Rancúnia!");
static const u8 sText_PkmnShroudedItself[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha\n"
    "embolcallat de {B_CURRENT_MOVE}!");
static const u8 sText_PkmnMoveBounced[] = _(
    "Capa Màgica ha rebotat {B_CURRENT_MOVE}\n"
    "de {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnWaitsForTarget[] = _(
    "{B_ATK_NAME_WITH_PREFIX} espera que un\n"
    "objectiu es mogui!");
static const u8 sText_PkmnSnatchedMove[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha arrabassat el\n"
    "moviment de {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_ElectricityWeakened[] = _(
    "El poder de l'electricitat\n"
    "s'ha afeblit!");
static const u8 sText_FireWeakened[] = _(
    "El poder del foc\n"
    "s'ha afeblit!");
static const u8 sText_XFoundOneY[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha trobat\n"
    "un {B_LAST_ITEM}!");
static const u8 sText_SoothingAroma[] = _(
    "Un aroma relaxant s'ha estès\n"
    "per la zona!");
static const u8 sText_ItemsCantBeUsedNow[] = _("Ara no es poden fer servir objectes.{PAUSE 64}");
static const u8 sText_ForXCommaYZ[] = _(
    "Per a {B_SCR_ACTIVE_NAME_WITH_PREFIX},\n"
    "{B_LAST_ITEM} {B_BUFF1}");
static const u8 sText_PkmnUsedXToGetPumped[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha fet servir\n"
    "{B_LAST_ITEM} per animar-se!");
static const u8 sText_PkmnLostFocus[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha perdut la\n"
    "concentració i no s'ha pogut moure!");
static const u8 sText_PkmnWasDraggedOut[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha estat\n"
    "tret a fora!\p");
static const u8 sText_TheWallShattered[] = _("El mur s'ha trencat!");
static const u8 sText_ButNoEffect[] = _("Però no ha tingut cap efecte!");
static const u8 sText_PkmnHasNoMovesLeft[] = _(
    "{B_ACTIVE_NAME_WITH_PREFIX} no li\n"
    "queden moviments!\p");
static const u8 sText_PkmnMoveIsDisabled[] = _(
    "{B_CURRENT_MOVE} de {B_ACTIVE_NAME_WITH_PREFIX}\n"
    "està anul·lat!\p");
static const u8 sText_PkmnCantUseMoveTorment[] = _(
    "{B_ACTIVE_NAME_WITH_PREFIX} no pot repetir el\n"
    "mateix moviment pel Turment!\p");
static const u8 sText_PkmnCantUseMoveTaunt[] = _(
    "{B_ACTIVE_NAME_WITH_PREFIX} no pot usar\n"
    "{B_CURRENT_MOVE} després de la Mofa!\p");
static const u8 sText_PkmnCantUseMoveSealed[] = _(
    "{B_ACTIVE_NAME_WITH_PREFIX} no pot usar\n"
    "{B_CURRENT_MOVE}, que està segellat!\p");
static const u8 sText_PkmnCantUseMoveThroatChop[] = _(
    "{B_ACTIVE_NAME_WITH_PREFIX} no pot usar\n"
    "{B_CURRENT_MOVE} per Cop de Gola!\p");
static const u8 sText_PkmnMadeItRain[] = _(
    "{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "ha fet ploure!");
static const u8 sText_PkmnRaisedSpeed[] = _(
    "{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "li ha pujat la Velocitat!");
static const u8 sText_PkmnProtectedBy[] = _(
    "{B_DEF_ABILITY} ha protegit\n"
    "{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPreventsUsage[] = _(
    "{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\n"
    "impedeix que {B_ATK_NAME_WITH_PREFIX}\lusi {B_CURRENT_MOVE}!");
static const u8 sText_PkmnRestoredHPUsing[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha recuperat PS\n"
    "amb {B_DEF_ABILITY}!");
static const u8 sText_PkmnsXMadeYUseless[] = _(
    "{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\n"
    "ha fet inútil {B_CURRENT_MOVE}!");
static const u8 sText_PkmnChangedTypeWith[] = _(
    "{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\n"
    "l'ha fet de tipus {B_BUFF1}!");
static const u8 sText_PkmnPreventsParalysisWith[] = _(
    "{B_DEF_ABILITY} de {B_EFF_NAME_WITH_PREFIX}\n"
    "impedeix la paràlisi!");
static const u8 sText_PkmnPreventsRomanceWith[] = _(
    "{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\n"
    "impedeix l'enamorament!");
static const u8 sText_PkmnPreventsPoisoningWith[] = _(
    "{B_DEF_ABILITY} de {B_EFF_NAME_WITH_PREFIX}\n"
    "impedeix l'enverinament!");
static const u8 sText_PkmnPreventsConfusionWith[] = _(
    "{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\n"
    "impedeix la confusió!");
static const u8 sText_PkmnRaisedFirePowerWith[] = _(
    "{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\n"
    "li ha pujat el poder de Foc!");
static const u8 sText_PkmnAnchorsItselfWith[] = _(
    "{B_DEF_NAME_WITH_PREFIX} s'ancora\n"
    "amb {B_DEF_ABILITY}!");
static const u8 sText_PkmnCutsAttackWith[] = _(
    "{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "baixa l'Atac de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPreventsStatLossWith[] = _(
    "{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "impedeix perdre estadístiques!");
static const u8 sText_PkmnHurtsWith[] = _(
    "{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\n"
    "ha fet mal a {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnTraced[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha calcat\n"
    "{B_BUFF2} de {B_BUFF1}!");
static const u8 sText_PkmnsXPreventsBurns[] = _(
    "{B_EFF_ABILITY} de {B_EFF_NAME_WITH_PREFIX}\n"
    "impedeix les cremades!");
static const u8 sText_PkmnsXBlocksY[] = _(
    "{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\n"
    "bloqueja {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXBlocksY2[] = _(
    "{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "bloqueja {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXRestoredHPALittle2[] = _(
    "{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX}\n"
    "li ha recuperat una mica de PS!");
static const u8 sText_PkmnsXWhippedUpSandstorm[] = _(
    "{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "ha aixecat una tempesta de sorra!");
static const u8 sText_PkmnsXIntensifiedSun[] = _(
    "{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "ha intensificat els raigs del sol!");
static const u8 sText_PkmnsXPreventsYLoss[] = _(
    "{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "impedeix perdre {B_BUFF1}!");
static const u8 sText_PkmnsXInfatuatedY[] = _(
    "{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\n"
    "ha enamorat {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnsXMadeYIneffective[] = _(
    "{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\n"
    "ha fet ineficaç {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXCuredYProblem[] = _(
    "{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "li ha curat {B_BUFF1}!");
static const u8 sText_ItSuckedLiquidOoze[] = _(
    "Ha xuclat el\n"
    "Llot Líquid!");
static const u8 sText_PkmnTransformed[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} s'ha transformat!");
static const u8 sText_PkmnsXTookAttack[] = _(
    "{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\n"
    "ha rebut l'atac!");
const u8 gText_PkmnsXPreventsSwitching[] = _(
    "{B_LAST_ABILITY} de {B_BUFF1}\n"
    "impedeix el canvi!\p");
static const u8 sText_PreventedFromWorking[] = _(
    "{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\n"
    "ha impedit que {B_BUFF1} de\l{B_SCR_ACTIVE_NAME_WITH_PREFIX} funcionés!");
static const u8 sText_PkmnsXMadeItIneffective[] = _(
    "{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "ho ha fet ineficaç!");
static const u8 sText_PkmnsXPreventsFlinching[] = _(
    "{B_EFF_ABILITY} de {B_EFF_NAME_WITH_PREFIX}\n"
    "impedeix l'esglai!");
static const u8 sText_PkmnsXPreventsYsZ[] = _(
    "{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX}\n"
    "impedeix que {B_DEF_ABILITY} de\l{B_DEF_NAME_WITH_PREFIX} funcioni!");
static const u8 sText_PkmnsXCuredItsYProblem[] = _(
    "{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "li ha curat {B_BUFF1}!");
static const u8 sText_PkmnsXHadNoEffectOnY[] = _(
    "{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "no ha afectat {B_EFF_NAME_WITH_PREFIX}!");
const u8 gText_StatSharply[] = _("molt ");
const u8 gText_StatRose[] = _("amunt!");
static const u8 sText_StatHarshly[] = _("molt ");
static const u8 sText_StatFell[] = _("avall!");
static const u8 sText_AttackersStatRose[] = _(
    "{B_BUFF1} de {B_ATK_NAME_WITH_PREFIX}\n"
    "{B_BUFF2}");
const u8 gText_DefendersStatRose[] = _(
    "{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}\n"
    "{B_BUFF2}");
static const u8 sText_UsingItemTheStatOfPkmnRose[] = _(
    "Amb {B_LAST_ITEM}, {B_BUFF1}\n"
    "de {B_SCR_ACTIVE_NAME_WITH_PREFIX} {B_BUFF2}");
static const u8 sText_AttackersStatFell[] = _(
    "{B_BUFF1} de {B_ATK_NAME_WITH_PREFIX}\n"
    "{B_BUFF2}");
static const u8 sText_DefendersStatFell[] = _(
    "{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}\n"
    "{B_BUFF2}");
static const u8 sText_StatsWontIncrease2[] = _(
    "Les estadístiques de {B_ATK_NAME_WITH_PREFIX}\n"
    "no poden pujar més!");
static const u8 sText_StatsWontDecrease2[] = _(
    "Les estadístiques de {B_DEF_NAME_WITH_PREFIX}\n"
    "no poden baixar més!");
static const u8 sText_CriticalHit[] = _("Un cop crític!");
static const u8 sText_OneHitKO[] = _("KO d'un sol cop!");
static const u8 sText_123Poof[] = _("{PAUSE 32}1, {PAUSE 15}2 i{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Puf!\p");
static const u8 sText_AndEllipsis[] = _("I…\p");
static const u8 sText_HMMovesCantBeForgotten[] = _(
    "Ara no es poden oblidar\n"
    "els moviments MO.\p");
static const u8 sText_NotVeryEffective[] = _("No és gaire eficaç…");
static const u8 sText_SuperEffective[] = _("És molt eficaç!");
static const u8 sText_GotAwaySafely[] = _("{PLAY_SE SE_FLEE}Has fugit sense problemes!\p");
static const u8 sText_PkmnFledUsingIts[] = _(
    "{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} ha fugit\n"
    "amb {B_LAST_ITEM}!\p");
static const u8 sText_PkmnFledUsing[] = _(
    "{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} ha fugit\n"
    "amb {B_ATK_ABILITY}!\p");
static const u8 sText_WildPkmnFled[] = _("{PLAY_SE SE_FLEE}{B_BUFF1} salvatge ha fugit!");
static const u8 sText_PlayerDefeatedLinkTrainer[] = _(
    "Has derrotat\n"
    "{B_LINK_OPPONENT1_NAME}!");
static const u8 sText_TwoLinkTrainersDefeated[] = _(
    "Has vençut {B_LINK_OPPONENT1_NAME}\n"
    "i {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_PlayerLostAgainstLinkTrainer[] = _(
    "Has perdut contra\n"
    "{B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerLostToTwo[] = _(
    "Has perdut contra {B_LINK_OPPONENT1_NAME}\n"
    "i {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_PlayerBattledToDrawLinkTrainer[] = _(
    "Has empatat contra\n"
    "{B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerBattledToDrawVsTwo[] = _(
    "Has empatat contra\n"
    "{B_LINK_OPPONENT1_NAME} i {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_WildFled[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} ha fugit!");
static const u8 sText_TwoWildFled[] = _(
    "{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} i\n"
    "{B_LINK_OPPONENT2_NAME} han fugit!");
static const u8 sText_NoRunningFromTrainers[] = _(
    "No! No pots fugir del combat\n"
    "contra un entrenador!\p");
static const u8 sText_CantEscape[] = _("No es pot escapar!\p");
static const u8 sText_DontLeaveBirch[] = _("Prof. Birch: No em deixis així!\p");
static const u8 sText_ButNothingHappened[] = _("Però no ha passat res!");
static const u8 sText_ButItFailed[] = _("Però ha fallat!");
static const u8 sText_ItHurtConfusion[] = _(
    "S'ha fet mal a si mateix\n"
    "per la confusió!");
static const u8 sText_MirrorMoveFailed[] = _("El Reflex Mirall ha fallat!");
static const u8 sText_StartedToRain[] = _("Ha començat a ploure!");
static const u8 sText_DownpourStarted[] = _("Ha començat un xàfec!"); // corresponds to DownpourText in pokegold and pokecrystal and is used by Rain Dance in GSC
static const u8 sText_RainContinues[] = _("Continua plovent.");
static const u8 sText_DownpourContinues[] = _("El xàfec continua."); // unused
static const u8 sText_RainStopped[] = _("Ha parat de ploure.");
static const u8 sText_SandstormBrewed[] = _("S'ha format una tempesta de sorra!");
static const u8 sText_SandstormRages[] = _("La tempesta de sorra brama.");
static const u8 sText_SandstormSubsided[] = _("La tempesta de sorra ha parat.");
static const u8 sText_SunlightGotBright[] = _("La llum del sol s'ha intensificat!");
static const u8 sText_SunlightStrong[] = _("La llum del sol és forta.");
static const u8 sText_SunlightFaded[] = _("La llum del sol s'ha afeblit.");
static const u8 sText_StartedHail[] = _("Ha començat a calamarsejar!");
static const u8 sText_HailContinues[] = _("Continua calamarsejant.");
static const u8 sText_HailStopped[] = _("Ha parat de calamarsejar.");
static const u8 sText_FailedToSpitUp[] = _(
    "Però no ha pogut escopir\n"
    "res!");
static const u8 sText_FailedToSwallow[] = _(
    "Però no ha pogut empassar\n"
    "res!");
static const u8 sText_WindBecameHeatWave[] = _(
    "El vent s'ha convertit en\n"
    "una Onada de Calor!");
static const u8 sText_StatChangesGone[] = _(
    "S'han eliminat tots els canvis\n"
    "d'estadístiques!");
static const u8 sText_CoinsScattered[] = _("S'han escampat monedes arreu!");
static const u8 sText_TooWeakForSubstitute[] = _(
    "Estava massa feble per crear\n"
    "un Substitut!");
static const u8 sText_SharedPain[] = _(
    "Els combatents han compartit\n"
    "el dolor!");
static const u8 sText_BellChimed[] = _("Ha sonat una campana!");
static const u8 sText_FaintInThree[] = _(
    "Tots els Pokémon afectats es\n"
    "debilitaran en tres torns!");
static const u8 sText_NoPPLeft[] = _(
    "No queden PP per a\n"
    "aquest moviment!\p");
static const u8 sText_ButNoPPLeft[] = _(
    "Però no quedaven PP per\n"
    "al moviment!");
static const u8 sText_PkmnIgnoresAsleep[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha ignorat les\n"
    "ordres mentre dormia!");
static const u8 sText_PkmnIgnoredOrders[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha ignorat\n"
    "les ordres!");
static const u8 sText_PkmnBeganToNap[] = _("{B_ATK_NAME_WITH_PREFIX} s'ha posat a dormir!");
static const u8 sText_PkmnLoafing[] = _(
    "{B_ATK_NAME_WITH_PREFIX} està\n"
    "fent el gandul!");
static const u8 sText_PkmnWontObey[] = _(
    "{B_ATK_NAME_WITH_PREFIX} no vol\n"
    "obeir!");
static const u8 sText_PkmnTurnedAway[] = _("{B_ATK_NAME_WITH_PREFIX} ha girat la cara!");
static const u8 sText_PkmnPretendNotNotice[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha fet\n"
    "com si no ho sentís!");
static const u8 sText_EnemyAboutToSwitchPkmn[] = _(
    "{B_TRAINER1_CLASS} {B_TRAINER1_NAME} està\n"
    "a punt d'usar {B_BUFF2}.\pVol canviar de Pokémon,\n"
    "{B_PLAYER_NAME}?");
static const u8 sText_PkmnLearnedMove2[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha après\n"
    "{B_BUFF1}!");
static const u8 sText_PlayerDefeatedLinkTrainerTrainer1[] = _(
    "Has derrotat\n"
    "{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!\p");
static const u8 sText_CreptCloser[] = _(
    "{B_PLAYER_NAME} s'ha acostat a\n"
    "{B_OPPONENT_MON1_NAME}!");
static const u8 sText_CantGetCloser[] = _("{B_PLAYER_NAME} no pot acostar-se més!");
static const u8 sText_PkmnWatchingCarefully[] = _(
    "{B_OPPONENT_MON1_NAME} està observant\n"
    "amb atenció!");
static const u8 sText_PkmnCuriousAboutX[] = _(
    "{B_OPPONENT_MON1_NAME} sent curiositat\n"
    "per {B_BUFF1}!");
static const u8 sText_PkmnEnthralledByX[] = _(
    "{B_OPPONENT_MON1_NAME} està encisat\n"
    "per {B_BUFF1}!");
static const u8 sText_PkmnIgnoredX[] = _(
    "{B_OPPONENT_MON1_NAME} ha ignorat\n"
    "completament {B_BUFF1}!");
static const u8 sText_ThrewPokeblockAtPkmn[] = _(
    "{B_PLAYER_NAME} ha llançat un {POKEBLOCK}\n"
    "a {B_OPPONENT_MON1_NAME}!");
static const u8 sText_OutOfSafariBalls[] = _(
    "{PLAY_SE SE_DING_DONG}Locutor: T'has quedat sense\n"
    "Safari Balls! Fi del joc!\p");
static const u8 sText_OpponentMon1Appeared[] = _("Ha aparegut {B_OPPONENT_MON1_NAME}!\p");
static const u8 sText_WildPkmnAppeared[] = _("Ha aparegut {B_OPPONENT_MON1_NAME} salvatge!\p");
static const u8 sText_LegendaryPkmnAppeared[] = _("Ha aparegut {B_OPPONENT_MON1_NAME} salvatge!\p");
static const u8 sText_WildPkmnAppearedPause[] = _("Ha aparegut {B_OPPONENT_MON1_NAME} salvatge!{PAUSE 127}");
static const u8 sText_TwoWildPkmnAppeared[] = _(
    "Han aparegut {B_OPPONENT_MON1_NAME} i\n"
    "{B_OPPONENT_MON2_NAME} salvatges!\p");
static const u8 sText_Trainer1WantsToBattle[] = _(
    "{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\n"
    "vol combatre!\p");
static const u8 sText_LinkTrainerWantsToBattle[] = _(
    "{B_LINK_OPPONENT1_NAME}\n"
    "vol combatre!");
static const u8 sText_TwoLinkTrainersWantToBattle[] = _(
    "{B_LINK_OPPONENT1_NAME} i {B_LINK_OPPONENT2_NAME}\n"
    "volen combatre!");
static const u8 sText_Trainer1SentOutPkmn[] = _(
    "{B_TRAINER1_CLASS} {B_TRAINER1_NAME} ha tret\n"
    "{B_OPPONENT_MON1_NAME}!");
static const u8 sText_Trainer1SentOutTwoPkmn[] = _(
    "{B_TRAINER1_CLASS} {B_TRAINER1_NAME} ha tret\n"
    "{B_OPPONENT_MON1_NAME} i {B_OPPONENT_MON2_NAME}!");
static const u8 sText_Trainer1SentOutPkmn2[] = _(
    "{B_TRAINER1_CLASS} {B_TRAINER1_NAME} ha tret\n"
    "{B_BUFF1}!");
static const u8 sText_LinkTrainerSentOutPkmn[] = _(
    "{B_LINK_OPPONENT1_NAME} ha tret\n"
    "{B_OPPONENT_MON1_NAME}!");
static const u8 sText_LinkTrainerSentOutTwoPkmn[] = _(
    "{B_LINK_OPPONENT1_NAME} ha tret\n"
    "{B_OPPONENT_MON1_NAME} i {B_OPPONENT_MON2_NAME}!");
static const u8 sText_TwoLinkTrainersSentOutPkmn[] = _(
    "{B_LINK_OPPONENT1_NAME} ha tret {B_LINK_OPPONENT_MON1_NAME}!\n"
    "{B_LINK_OPPONENT2_NAME} ha tret {B_LINK_OPPONENT_MON2_NAME}!");
static const u8 sText_LinkTrainerSentOutPkmn2[] = _(
    "{B_LINK_OPPONENT1_NAME} ha tret\n"
    "{B_BUFF1}!");
static const u8 sText_LinkTrainerMultiSentOutPkmn[] = _(
    "{B_LINK_SCR_TRAINER_NAME} ha tret\n"
    "{B_BUFF1}!");
static const u8 sText_GoPkmn[] = _("Vinga, {B_PLAYER_MON1_NAME}!");
static const u8 sText_GoTwoPkmn[] = _(
    "Vinga, {B_PLAYER_MON1_NAME} i\n"
    "{B_PLAYER_MON2_NAME}!");
static const u8 sText_GoPkmn2[] = _("Vinga, {B_BUFF1}!");
static const u8 sText_DoItPkmn[] = _("Endavant, {B_BUFF1}!");
static const u8 sText_GoForItPkmn[] = _("A per ells, {B_BUFF1}!");
static const u8 sText_YourFoesWeakGetEmPkmn[] = _(
    "El rival està feble!\n"
    "A per ell, {B_BUFF1}!");
static const u8 sText_LinkPartnerSentOutPkmnGoPkmn[] = _(
    "{B_LINK_PARTNER_NAME} ha tret {B_LINK_PLAYER_MON2_NAME}!\n"
    "Vinga, {B_LINK_PLAYER_MON1_NAME}!");
static const u8 sText_PkmnThatsEnough[] = _(
    "{B_BUFF1}, ja n'hi ha prou!\n"
    "Torna!");
static const u8 sText_PkmnComeBack[] = _("{B_BUFF1}, torna!");
static const u8 sText_PkmnOkComeBack[] = _(
    "{B_BUFF1}, molt bé!\n"
    "Torna!");
static const u8 sText_PkmnGoodComeBack[] = _(
    "{B_BUFF1}, bona feina!\n"
    "Torna!");
static const u8 sText_Trainer1WithdrewPkmn[] = _(
    "{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\n"
    "ha retirat {B_BUFF1}!");
static const u8 sText_LinkTrainer1WithdrewPkmn[] = _(
    "{B_LINK_OPPONENT1_NAME} ha retirat\n"
    "{B_BUFF1}!");
static const u8 sText_LinkTrainer2WithdrewPkmn[] = _(
    "{B_LINK_SCR_TRAINER_NAME} ha retirat\n"
    "{B_BUFF1}!");
static const u8 sText_WildPkmnPrefix[] = _("Salvatge ");
static const u8 sText_FoePkmnPrefix[] = _("Rival ");
static const u8 sText_EmptyString8[] = _("");
static const u8 sText_FoePkmnPrefix2[] = _("Rival");
static const u8 sText_AllyPkmnPrefix[] = _("Aliat");
static const u8 sText_FoePkmnPrefix3[] = _("Rival");
static const u8 sText_AllyPkmnPrefix2[] = _("Aliat");
static const u8 sText_FoePkmnPrefix4[] = _("Rival");
static const u8 sText_AllyPkmnPrefix3[] = _("Aliat");
static const u8 sText_AttackerUsedX[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha usat\n"
    "{B_BUFF3}!");
static const u8 sText_ExclamationMark[] = _("!");
static const u8 sText_ExclamationMark2[] = _("!");
static const u8 sText_ExclamationMark3[] = _("!");
static const u8 sText_ExclamationMark4[] = _("!");
static const u8 sText_ExclamationMark5[] = _("!");

static const u8 sText_HP2[] = _("PS");
static const u8 sText_Attack2[] = _("Atac");
static const u8 sText_Defense2[] = _("Defensa");
static const u8 sText_Speed[] = _("Velocitat");
static const u8 sText_SpAtk2[] = _("At. Esp.");
static const u8 sText_SpDef2[] = _("Def. Esp.");

static const u8 sText_Accuracy[] = _("precisió");
static const u8 sText_Evasiveness[] = _("evasió");

const u8 * const gStatNamesTable[NUM_BATTLE_STATS] =
{
    gText_HP3, gText_Attack, gText_Defense,
    gText_Speed, gText_SpAtk, gText_SpDef,
    sText_Accuracy, sText_Evasiveness
};

static const u8 sText_PokeblockWasTooSpicy[] = _("era massa picant!");
static const u8 sText_PokeblockWasTooDry[] = _("era massa sec!");
static const u8 sText_PokeblockWasTooSweet[] = _("era massa dolç!");
static const u8 sText_PokeblockWasTooBitter[] = _("era massa amarg!");
static const u8 sText_PokeblockWasTooSour[] = _("era massa àcid!");

const u8 * const gPokeblockWasTooXStringTable[FLAVOR_COUNT] =
{
    [FLAVOR_SPICY]  = sText_PokeblockWasTooSpicy,
    [FLAVOR_DRY]    = sText_PokeblockWasTooDry,
    [FLAVOR_SWEET]  = sText_PokeblockWasTooSweet,
    [FLAVOR_BITTER] = sText_PokeblockWasTooBitter,
    [FLAVOR_SOUR]   = sText_PokeblockWasTooSour
};

static const u8 sText_PlayerUsedItem[] = _(
    "{B_PLAYER_NAME} ha fet servir\n"
    "{B_LAST_ITEM}!");
static const u8 sText_WallyUsedItem[] = _(
    "El Professor Oak ha fet servir\n"
    "{B_LAST_ITEM}!");
static const u8 sText_Trainer1UsedItem[] = _(
    "{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\n"
    "ha fet servir {B_LAST_ITEM}!");
static const u8 sText_TrainerBlockedBall[] = _("L'entrenador ha bloquejat la Ball!");
static const u8 sText_DontBeAThief[] = _("No siguis lladre!");
static const u8 sText_ItDodgedBall[] = _(
    "Ha esquivat la Ball!\n"
    "Aquest Pokémon no es pot capturar!");
static const u8 sText_YouMissedPkmn[] = _("No has encertat el Pokémon!");
static const u8 sText_PkmnBrokeFree[] = _(
    "Oh, no!\n"
    "El Pokémon s'ha escapat!");
static const u8 sText_ItAppearedCaught[] = _(
    "Vaja!\n"
    "Semblava que estava capturat!");
static const u8 sText_AarghAlmostHadIt[] = _(
    "Ai!\n"
    "Gairebé el tenies!");
static const u8 sText_ShootSoClose[] = _(
    "Llàstima!\n"
    "Hi era a punt!");
static const u8 sText_GotchaPkmnCaught[] = _(
    "Ben fet!\n"
    "Has capturat {B_DEF_NAME}!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p");
static const u8 sText_GotchaPkmnCaught2[] = _(
    "Ben fet!\n"
    "Has capturat {B_DEF_NAME}!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}");
static const u8 sText_GiveNicknameCaptured[] = _(
    "Vols posar un sobrenom a\n"
    "{B_DEF_NAME}, que has capturat?");
static const u8 sText_PkmnSentToPC[] = _(
    "{B_DEF_NAME} s'ha enviat al\n"
    "PC {B_PC_CREATOR_NAME}.");
static const u8 sText_Someones[] = _("d'algú");
static const u8 sText_Lanettes[] = _("del Bill");
static const u8 sText_PkmnDataAddedToDex[] = _(
    "Les dades de {B_OPPONENT_MON1_NAME}\n"
    "s'han afegit al Pokédex.\p");
static const u8 sText_ItIsRaining[] = _("Està plovent.");
static const u8 sText_SandstormIsRaging[] = _("Hi ha una tempesta de sorra.");
static const u8 sText_BoxIsFull[] = _(
    "La caixa és plena!\n"
    "No pots capturar-ne més!\p");
static const u8 sText_EnigmaBerry[] = _("Baia Enigma");
static const u8 sText_BerrySuffix[] = _(" Baia");
static const u8 sText_PkmnsItemCuredParalysis[] = _(
    "{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "ha curat la paràlisi!");
static const u8 sText_PkmnsItemCuredPoison[] = _(
    "{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "ha curat el verí!");
static const u8 sText_PkmnsItemHealedBurn[] = _(
    "{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "ha curat la cremada!");
static const u8 sText_PkmnsItemDefrostedIt[] = _(
    "{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "l'ha desglaçat!");
static const u8 sText_PkmnsItemWokeIt[] = _(
    "{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "l'ha despertat!");
static const u8 sText_PkmnsItemSnappedOut[] = _(
    "{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "l'ha tret de la confusió!");
static const u8 sText_PkmnsItemCuredProblem[] = _(
    "{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "li ha curat {B_BUFF1}!");
static const u8 sText_PkmnsItemNormalizedStatus[] = _(
    "{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "li ha normalitzat l'estat!");
static const u8 sText_PkmnsItemRestoredHealth[] = _(
    "{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "li ha recuperat la salut!");
static const u8 sText_PkmnsItemRestoredPP[] = _(
    "{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "ha recuperat els PP de {B_BUFF1}!");
static const u8 sText_PkmnsItemRestoredStatus[] = _(
    "{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "li ha restaurat l'estat!");
static const u8 sText_PkmnsItemRestoredHPALittle[] = _(
    "{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "li ha recuperat una mica de PS!");
static const u8 sText_ItemAllowsOnlyYMove[] = _(
    "{B_LAST_ITEM} només permet\n"
    "fer servir {B_CURRENT_MOVE}!\p");
static const u8 sText_PkmnHungOnWithX[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha aguantat\n"
    "amb {B_LAST_ITEM}!");
const u8 gText_EmptyString3[] = _("");
static const u8 sText_YouThrowABallNowRight[] = _(
    "Fixa-t'hi bé, {B_PLAYER_NAME}.\n"
    "Així es captura un Pokémon!");
                                                   
// early declaration of strings
static const u8 sText_PkmnIncapableOfPower[];
static const u8 sText_GlintAppearsInEye[];
static const u8 sText_PkmnGettingIntoPosition[];
static const u8 sText_PkmnBeganGrowlingDeeply[];
static const u8 sText_PkmnEagerForMore[];
static const u8 sText_DefeatedOpponentByReferee[];
static const u8 sText_LostToOpponentByReferee[];
static const u8 sText_TiedOpponentByReferee[];
static const u8 sText_QuestionForfeitMatch[];
static const u8 sText_ForfeitedMatch[];
static const u8 sText_Trainer1WinText[];
static const u8 sText_Trainer2WinText[];
static const u8 sText_TwoInGameTrainersDefeated[];
static const u8 sText_Trainer2LoseText[];

// New battle strings.
static const s8 sText_EnduredViaSturdy[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha aguantat\n"
    "el cop amb {B_DEF_ABILITY}!");
static const s8 sText_PowerHerbActivation[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha carregat del tot\n"
    "gràcies a {B_LAST_ITEM}!");
static const s8 sText_HurtByItem[] = _(
    "{B_LAST_ITEM} ha fet mal a\n"
    "{B_ATK_NAME_WITH_PREFIX}!");
static const s8 sText_BadlyPoisonedByItem[] = _(
    "{B_LAST_ITEM} ha enverinat greument\n"
    "{B_EFF_NAME_WITH_PREFIX}!");
static const s8 sText_BurnedByItem[] = _(
    "{B_LAST_ITEM} ha cremat\n"
    "{B_EFF_NAME_WITH_PREFIX}!");
static const s8 sText_TargetAbilityActivates[] = _("{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX} s'activa!");
static const u8 sText_GravityIntensified[] = _("La gravetat s'ha intensificat!");
static const u8 sText_TargetIdentified[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha estat\n"
    "identificat!");
static const u8 sText_TargetWokeUp[] = _("{B_DEF_NAME_WITH_PREFIX} s'ha despertat!");
static const u8 sText_PkmnStoleAndAteItem[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha robat i menjat\n"
    "{B_LAST_ITEM} de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_TailWindBlew[] = _(
    "Bufa vent de cua darrere\n"
    "{B_ATK_TEAM2} equip!");
static const u8 sText_PkmnWentBack[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha tornat amb\n"
    "{B_ATK_TRAINER_CLASS} {B_ATK_TRAINER_NAME}");
static const u8 sText_PkmnCantUseItemsAnymore[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ja no pot\n"
    "fer servir objectes!");
static const u8 sText_PkmnFlung[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha llançat\n"
    "{B_LAST_ITEM}!");
static const u8 sText_PkmnPreventedFromHealing[] = _(
    "S'ha impedit que {B_DEF_NAME_WITH_PREFIX}\n"
    "es curi!");
static const u8 sText_PkmnSwitchedAtkAndDef[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha intercanviat\n"
    "l'Atac i la Defensa!");
static const u8 sText_PkmnsAbilitySuppressed[] = _(
    "L'habilitat de {B_DEF_NAME_WITH_PREFIX}\n"
    "ha quedat suprimida!");
static const u8 sText_ShieldedFromCriticalHits[] = _(
    "{B_CURRENT_MOVE} ha protegit {B_ATK_TEAM2}\n"
    "equip dels cops crítics!");
static const u8 sText_SwitchedAtkAndSpAtk[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha intercanviat amb\n"
    "l'objectiu els canvis d'Atac i\pAt. Esp.!");
static const u8 sText_SwitchedDefAndSpDef[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha intercanviat amb\n"
    "l'objectiu els canvis de Defensa i\pDef. Esp.!");
static const u8 sText_PkmnAcquiredAbility[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha adquirit\n"
    "{B_DEF_ABILITY}!");
static const u8 sText_PoisonSpikesScattered[] = _(
    "S'han escampat Punxes Tòxiques\n"
    "als peus de l'equip rival!");
static const u8 sText_PkmnSwitchedStatChanges[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha intercanviat els canvis\n"
    "d'estadístiques amb l'objectiu!");
static const u8 sText_PkmnSurroundedWithVeilOfWater[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha envoltat\n"
    "d'un vel d'aigua!");
static const u8 sText_PkmnLevitatedOnElectromagnetism[] = _(
    "{B_ATK_NAME_WITH_PREFIX} levita per\n"
    "electromagnetisme!");
static const u8 sText_PkmnTwistedDimensions[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha retorçat\n"
    "les dimensions!");
static const u8 sText_PointedStonesFloat[] =_(
    "Pedres punxegudes floten en l'aire\n"
    "al voltant de {B_DEF_TEAM2} equip!");
static const u8 sText_CloakedInMysticalMoonlight[] =_(
    "S'ha cobert de llum lunar\n"
    "mística!");
static const u8 sText_TrappedBySwirlingMagma[] =_(
    "{B_DEF_NAME_WITH_PREFIX} ha quedat\n"
    "atrapat en magma giratori!");
static const u8 sText_VanishedInstantly[] =_(
    "{B_ATK_NAME_WITH_PREFIX} ha desaparegut\n"
    "a l'instant!");
static const u8 sText_ProtectedTeam[] =_(
    "{B_CURRENT_MOVE} ha protegit\n"
    "{B_ATK_TEAM2} equip!");
static const u8 sText_SharedItsGuard[] =_(
    "{B_ATK_NAME_WITH_PREFIX} ha compartit la\n"
    "seva defensa amb l'objectiu!");
static const u8 sText_SharedItsPower[] =_(
    "{B_ATK_NAME_WITH_PREFIX} ha compartit el\n"
    "seu poder amb l'objectiu!");
static const u8 sText_SwapsDefAndSpDefOfAllPkmn[] =_(
    "S'ha creat una zona on la Defensa\n"
    "i la Def. Esp. es canvien!");
static const u8 sText_BecameNimble[] =_("{B_ATK_NAME_WITH_PREFIX} s'ha tornat àgil!");
static const u8 sText_HurledIntoTheAir[] =_(
    "{B_DEF_NAME_WITH_PREFIX} ha sortit\n"
    "disparat enlaire!");
static const u8 sText_HeldItemsLoseEffects[] =_(
    "S'ha creat una zona on els\n"
    "objectes perden els efectes!");
static const u8 sText_FellStraightDown[] =_(
    "{B_DEF_NAME_WITH_PREFIX} ha caigut\n"
    "de ple!");
static const u8 sText_TargetChangedType[] =_(
    "{B_DEF_NAME_WITH_PREFIX} s'ha convertit\n"
    "en tipus {B_BUFF1}!");
static const u8 sText_PkmnAcquiredSimple[] =_(
    "{B_DEF_NAME_WITH_PREFIX} ha adquirit\n"
    "Senzillesa!");
static const u8 sText_KindOffer[] =_(
    "{B_DEF_NAME_WITH_PREFIX}\n"
    "ha acceptat l'oferta!");
static const u8 sText_ResetsTargetsStatLevels[] =_(
    "S'han tret els canvis d'estadístiques\n"
    "de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_AllySwitchPosition[] =_(
    "{B_ATK_NAME_WITH_PREFIX} i\n"
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} han canviat de lloc!");
static const u8 sText_RestoreTargetsHealth[] =_("{B_DEF_NAME_WITH_PREFIX} ha recuperat PS!");
static const u8 sText_TookPkmnIntoTheSky[] =_(
    "{B_ATK_NAME_WITH_PREFIX} s'ha endut\n"
    "{B_DEF_NAME_WITH_PREFIX} al cel!");
static const u8 sText_FreedFromSkyDrop[] =_(
    "{B_DEF_NAME_WITH_PREFIX} s'ha alliberat\n"
    "de Caiguda Cel!");
static const u8 sText_PostponeTargetMove[] =_(
    "El moviment de {B_DEF_NAME_WITH_PREFIX}\n"
    "s'ha endarrerit!");
static const u8 sText_ReflectTargetsType[] =_(
    "El tipus de {B_ATK_NAME_WITH_PREFIX} ha\n"
    "canviat per igualar {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_TransferHeldItem[] =_(
    "{B_DEF_NAME_WITH_PREFIX} ha rebut {B_LAST_ITEM}\n"
    "de {B_ATK_NAME_WITH_PREFIX}");
static const u8 sText_EmbargoEnds[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ja pot\n"
    "tornar a fer servir objectes!");
static const u8 sText_Electromagnetism[] = _("electromagnetisme");
static const u8 sText_BufferEnds[] = _(
    "{B_BUFF1} de {B_ATK_NAME_WITH_PREFIX}\n"
    "s'ha esgotat!");
static const u8 sText_ThroatChopEnds[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ja pot tornar a\n"
    "fer servir moviments de so!");
static const u8 sText_TelekinesisEnds[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha alliberat\n"
    "de la telecinesi!");
static const u8 sText_TailwindEnds[] = _(
    "El vent de cua de {B_ATK_TEAM1}\n"
    "equip s'ha esgotat!");
static const u8 sText_LuckyChantEnds[] = _(
    "El Cant de Sort de {B_ATK_TEAM1}\n"
    "equip s'ha esgotat!");
static const u8 sText_TrickRoomEnds[] = _(
    "Les dimensions retorçades han tornat\n"
    "a la normalitat!");
static const u8 sText_WonderRoomEnds[] = _(
    "Sala Prodigi s'ha esgotat i la Defensa\n"
    "i la Def. Esp. han tornat a la normalitat!");
static const u8 sText_MagicRoomEnds[] = _(
    "Sala Màgica s'ha esgotat i els\n"
    "objectes tornen a la normalitat!");
static const u8 sText_MudSportEnds[] = _(
    "L'efecte de Bany de Fang\n"
    "s'ha esvaït.");
static const u8 sText_WaterSportEnds[] = _(
    "L'efecte de Bany d'Aigua\n"
    "s'ha esvaït.");
static const u8 sText_GravityEnds[] = _("La gravetat ha tornat a la normalitat!");
static const u8 sText_AquaRingHeal[] = _(
    "Anell Aigua ha recuperat els PS\n"
    "de {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_TargetAbilityRaisedStat[] = _(
    "{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\n"
    "li ha pujat {B_BUFF1}!");
static const u8 sText_TargetAbilityLoweredStat[] = _(
    "{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\n"
    "li ha baixat {B_BUFF1}!");
static const u8 sText_AttackerAbilityRaisedStat[] = _(
    "{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX}\n"
    "li ha pujat {B_BUFF1}!");
static const u8 sText_ScriptingAbilityRaisedStat[] = _(
    "{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "li ha pujat {B_BUFF1}!");
static const u8 sText_AuroraVeilEnds[] = _(
    "{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\n"
    "s'ha esgotat!");
static const u8 sText_ElectricTerrainEnds[] = _(
    "L'electricitat ha desaparegut\n"
    "del camp de batalla.");
static const u8 sText_MistyTerrainEnds[] = _(
    "La boira ha desaparegut\n"
    "del camp de batalla.");
static const u8 sText_PsychicTerrainEnds[] = _(
    "L'estranyesa ha desaparegut\n"
    "del camp de batalla.");
static const u8 sText_GrassyTerrainEnds[] = _(
    "L'herba ha desaparegut\n"
    "del camp de batalla.");
static const u8 sText_TargetsStatWasMaxedOut[] = _(
    "{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX} ha\n"
    "maximitzat {B_BUFF1}!");
static const u8 sText_PoisonHealHpUp[] = _(
    "L'enverinament ha curat una mica\n"
    "{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_BadDreamsDmg[] = _(
    "{B_ATK_ABILITY} turmenta\n"
    "{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_MoldBreakerEnters[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} trenca el motlle!");
static const u8 sText_TeravoltEnters[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} irradia\n"
    "una aura explosiva!");
static const u8 sText_TurboblazeEnters[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} irradia\n"
    "una aura ardent!");
static const u8 sText_SlowStartEnters[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} no s'engega!");
static const u8 sText_SlowStartEnd[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha posat\n"
    "les piles per fi!");
static const u8 sText_SolarPowerHpDrop[] = _(
    "{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX}\n"
    "es fa notar!");
static const u8 sText_AftermathDmg[] = _("{B_ATK_NAME_WITH_PREFIX} rep dany!");
static const u8 sText_AnticipationActivates[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha tremolat\n"
    "d'anticipació!");
static const u8 sText_ForewarnActivates[] = _(
    "{B_SCR_ACTIVE_ABILITY} ha avisat {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "de {B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_IceBodyHpGain[] = _(
    "{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX}\n"
    "l'ha curat una mica!");
static const u8 sText_SnowWarningHail[] = _("Ha començat a calamarsejar!");
static const u8 sText_FriskActivates[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha escorcollat {B_DEF_NAME_WITH_PREFIX}\n"
    "i ha trobat {B_LAST_ITEM}!");
static const u8 sText_UnnerveEnters[] = _(
    "L'equip rival està massa nerviós\n"
    "per menjar baies!");
static const u8 sText_HarvestBerry[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha collit\n"
    "{B_LAST_ITEM}!");
static const u8 sText_LastAbilityRaisedBuff1[] = _(
    "{B_LAST_ABILITY} de {B_ATK_NAME_WITH_PREFIX}\n"
    "li ha pujat {B_BUFF1}!");
static const u8 sText_MagicBounceActivates[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha fet rebotar\n"
    "{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_ProteanTypeChange[] = _(
    "{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX} l'ha\n"
    "convertit en tipus {B_BUFF1}!");
static const u8 sText_SymbiosisItemPass[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha passat {B_LAST_ITEM}\n"
    "a {B_SCR_ACTIVE_NAME_WITH_PREFIX} amb {B_ATK_ABILITY}!");
static const u8 sText_StealthRockDmg[] = _(
    "Les pedres punxegudes han ferit\n"
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_ToxicSpikesAbsorbed[] = _(
    "Les punxes tòxiques han desaparegut\n"
    "dels peus de l'equip rival!");
static const u8 sText_ToxicSpikesPoisoned[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} s'ha enverinat!");
static const u8 sText_StickyWebSwitchIn[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha quedat\n"
    "atrapat en una Xarxa Viscosa!");
static const u8 sText_HealingWishCameTrue[] = _(
    "El desig de cura s'ha complert\n"
    "per a {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_HealingWishHealed[] = _("{B_ATK_NAME_WITH_PREFIX} ha recuperat salut!");
static const u8 sText_LunarDanceCameTrue[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha cobert\n"
    "de llum lunar mística!");
static const u8 sText_CursedBodyDisabled[] = _(
    "{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX} ha anul·lat\n"
    "{B_BUFF1} de {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_AttackerAquiredAbility[] = _("{B_ATK_NAME_WITH_PREFIX} ha adquirit {B_LAST_ABILITY}!");
static const u8 sText_TargetStatWontGoHigher[] = _(
    "{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}\n"
    "no pot pujar més!");
static const u8 sText_PkmnMoveBouncedViaAbility[] = _(
    "{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX} ha\n"
    "fet rebotar {B_CURRENT_MOVE} de\l{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_ImposterTransform[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha transformat en\n"
    "{B_DEF_NAME_WITH_PREFIX} amb {B_LAST_ABILITY}!");
static const u8 sText_NotDoneYet[] = _("Aquest efecte encara no està fet!\p");
static const u8 sText_PkmnBlewAwayToxicSpikes[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha escampat\n"
    "les Punxes Tòxiques!");
static const u8 sText_PkmnBlewAwayStickyWeb[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha escampat\n"
    "la Xarxa Viscosa!");
static const u8 sText_PkmnBlewAwayStealthRock[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha escampat\n"
    "les Roques Trampa!");
static const u8 sText_StickyWebUsed[] = _(
    "Una xarxa viscosa s'estén pel terra\n"
    "al voltant de {B_DEF_TEAM2} equip!");
static const u8 sText_QuashSuccess[] = _("El moviment de {B_ATK_NAME_WITH_PREFIX} s'ha endarrerit!");
static const u8 sText_IonDelugeOn[] = _(
    "Un diluvi d'ions banya\n"
    "el camp de batalla!");
static const u8 sText_TopsyTurvySwitchedStats[] = _(
    "S'han invertit tots els canvis\n"
    "d'estadístiques de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_TerrainBecomesMisty[] = _(
    "La boira ha envoltat\n"
    "el camp de batalla!");
static const u8 sText_TerrainBecomesGrassy[] = _(
    "L'herba ha crescut i cobreix\n"
    "el camp de batalla!");
static const u8 sText_TerrainBecomesElectric[] = _(
    "Un corrent elèctric recorre\n"
    "el camp de batalla!");
static const u8 sText_TerrainBecomesPsychic[] = _("El camp de batalla s'ha tornat estrany!");
static const u8 sText_TargetElectrified[] = _(
    "Els moviments de {B_DEF_NAME_WITH_PREFIX}\n"
    "s'han electrificat!");
static const u8 sText_AssaultVestDoesntAllow[] = _(
    "Els efectes de {B_LAST_ITEM} impedeixen\n"
    "fer servir moviments d'estat!\p");
static const u8 sText_GravityPreventsUsage[] = _(
    "{B_ATK_NAME_WITH_PREFIX} no pot usar {B_CURRENT_MOVE}\n"
    "per la gravetat!\p");
static const u8 sText_HealBlockPreventsUsage[] = _(
    "S'ha impedit que {B_ATK_NAME_WITH_PREFIX}\n"
    "es curi!\p");
static const u8 sText_MegaEvoReacting[] = _(
    "{B_LAST_ITEM} de {B_ATK_NAME_WITH_PREFIX} reacciona\n"
    "a l'Anell Mega de {B_ATK_TRAINER_NAME}!");
static const u8 sText_FerventWishReached[] = _(
    "El desig fervent de {B_ATK_TRAINER_NAME}\n"
    "ha arribat a {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_MegaEvoEvolved[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha Megaevolucionat a\n"
    "Mega {B_BUFF1}!");
static const u8 sText_drastically[] = _("moltíssim ");
static const u8 sText_severely[] = _("moltíssim ");
static const u8 sText_Infestation[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha infestat\n"
    "{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_NoEffectOnTarget[] = _(
    "No ha tingut cap efecte\n"
    "en {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_BurstingFlames[] = _(
    "Les flames esclatants han\n"
    "ferit {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_BestowItemGiving[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha rebut {B_LAST_ITEM}\n"
    "de {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_ThirdTypeAdded[] = _(
    "S'ha afegit el tipus {B_BUFF1}\n"
    "a {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_FellForFeint[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha caigut\n"
    "en el fingiment!");
static const u8 sText_PokemonCannotUseMove[] = _(
    "{B_ATK_NAME_WITH_PREFIX} no pot\n"
    "usar {B_CURRENT_MOVE}!");
static const u8 sText_CoveredInPowder[] = _("{B_DEF_NAME_WITH_PREFIX} està cobert de pols!");
static const u8 sText_PowderExplodes[] = _(
    "Quan la flama ha tocat la pols del\n"
    "Pokémon, ha explotat!");
static const u8 sText_BelchCantUse[] = _("No es pot fer servir Rot!\p");
static const u8 sText_SpectralThiefSteal[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha robat les millores\n"
    "d'estadístiques de l'objectiu!");
static const u8 sText_GravityGrounding[] = _(
    "{B_DEF_NAME_WITH_PREFIX} no pot mantenir-se\n"
    "enlaire per la gravetat!");
static const u8 sText_MistyTerrainPreventsStatus[] = _(
    "{B_DEF_NAME_WITH_PREFIX} s'envolta\n"
    "d'una boira protectora!");
static const u8 sText_GrassyTerrainHeals[] = _(
    "El camp herbós cura\n"
    "{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_ElectricTerrainPreventsSleep[] = _(
    "{B_DEF_NAME_WITH_PREFIX} s'envolta\n"
    "d'un camp electrificat!");
static const u8 sText_PsychicTerrainPreventsPriority[] = _(
    "{B_DEF_NAME_WITH_PREFIX} s'envolta\n"
    "d'un camp psíquic!");
static const u8 sText_SafetyGogglesProtected[] = _(
    "{B_DEF_NAME_WITH_PREFIX} no se'n veu afectat\n"
    "gràcies a {B_LAST_ITEM}!");
static const u8 sText_FlowerVeilProtected[] = _(
    "{B_DEF_NAME_WITH_PREFIX} s'ha envoltat\n"
    "d'un vel de pètals!");
static const u8 sText_SweetVeilProtected[] = _(
    "{B_DEF_NAME_WITH_PREFIX} s'ha envoltat\n"
    "d'un vel de dolçor!");
static const u8 sText_AromaVeilProtected[] = _(
    "{B_DEF_NAME_WITH_PREFIX} està protegit\n"
    "per un vel aromàtic!");
static const u8 sText_CelebrateMessage[] = _("Enhorabona, {B_PLAYER_NAME}!");
static const u8 sText_UsedInstructedMove[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha usat el moviment\n"
    "indicat per {B_BUFF1}!");
static const u8 sText_LaserFocusMessage[] = _(
    "{B_ATK_NAME_WITH_PREFIX}\n"
    "s'ha concentrat intensament!");
static const u8 sText_GemActivates[] = _(
    "{B_LAST_ITEM} ha reforçat\n"
    "el poder de {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_BerryDmgReducing[] = _(
    "{B_LAST_ITEM} ha reduït el dany\n"
    "a {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_TargetAteItem[] = _("{B_DEF_NAME_WITH_PREFIX} s'ha menjat {B_LAST_ITEM}!");
static const u8 sText_AirBalloonFloat[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} flota en l'aire\n"
    "amb {B_LAST_ITEM}!");
static const u8 sText_AirBalloonPop[] = _("{B_LAST_ITEM} de {B_DEF_NAME_WITH_PREFIX} ha esclatat!");
static const u8 sText_IncinerateBurn[] = _(
    "{B_LAST_ITEM} de {B_EFF_NAME_WITH_PREFIX}\n"
    "s'ha cremat!");
static const u8 sText_BugBite[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha robat i menjat\n"
    "{B_LAST_ITEM} de {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_IllusionWoreOff[] = _("La Il·lusió de {B_DEF_NAME_WITH_PREFIX} s'ha esgotat!");
static const u8 sText_AttackerCuredTargetStatus[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha curat\n"
    "{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_AttackerLostFireType[] = _("{B_ATK_NAME_WITH_PREFIX} s'ha consumit del tot!");
static const u8 sText_HealerCure[] = _(
    "{B_LAST_ABILITY} de {B_ATK_NAME_WITH_PREFIX}\n"
    "ha curat {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_ReceiverAbilityTakeOver[] = _(
    "{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "ha estat presa!");
static const u8 sText_PkmnAbsorbingPower[] = _("{B_ATK_NAME_WITH_PREFIX} absorbeix poder!");
static const u8 sText_NoOneWillBeAbleToRun[] = _(
    "Ningú no podrà fugir durant\n"
    "el torn següent!");
static const u8 sText_DestinyKnotActivates[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} s'ha enamorat\n"
    "per {B_LAST_ITEM}!");
static const u8 sText_CloakedInAFreezingLight[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha cobert\n"
    "d'una llum glaçada!");
static const u8 sText_StatWasNotLowered[] = _(
    "{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}\n"
    "no ha baixat!");
static const u8 sText_AuraFlaredToLife[] = _("L'aura de {B_DEF_NAME_WITH_PREFIX} s'ha encès!");
static const u8 sText_AirLockActivates[] = _(
    "Els efectes del clima\n"
    "han desaparegut.");
static const u8 sText_PressureActivates[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} exerceix la seva\n"
    "pressió!");
static const u8 sText_DarkAuraActivates[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} irradia\n"
    "una aura fosca!");
static const u8 sText_FairyAuraActivates[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} irradia\n"
    "una aura de fada!");
static const u8 sText_AuraBreakActivates[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha invertit les\n"
    "aures de tots els altres Pokémon!");
static const u8 sText_ComatoseActivates[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} té son!");
static const u8 sText_ScreenCleanerActivates[] = _(
    "S'han eliminat totes les barreres\n"
    "del camp!");
static const u8 sText_FetchedPokeBall[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha trobat\n"
    "un {B_LAST_ITEM}!");
static const u8 sText_BattlerAbilityRaisedStat[] = _(
    "{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\n"
    "li ha pujat {B_BUFF1}!");
static const u8 sText_ASandstormKickedUp[] = _("S'ha aixecat una tempesta de sorra!");
static const u8 sText_PkmnsWillPerishIn3Turns[] = _(
    "Els dos Pokémon es debilitaran\n"
    "en tres torns!");
static const u8 sText_AbilityRaisedStatDrastically[] = _(
    "{B_DEF_ABILITY} ha pujat moltíssim\n"
    "{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_AsOneEnters[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} té dues Habilitats!");
static const u8 sText_CuriousMedicineEnters[] = _(
    "S'han reiniciat els canvis\n"
    "d'estadístiques de {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_CanActFaster[] = _(
    "{B_ATK_NAME_WITH_PREFIX} pot actuar més ràpid\n"
    "gràcies a {B_BUFF1}!");
static const u8 sText_MicleBerryActivates[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha pujat la precisió del\n"
    "seu proper moviment amb {B_LAST_ITEM}!");
static const u8 sText_PkmnShookOffTheTaunt[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} s'ha tret\n"
    "la mofa de sobre!");
static const u8 sText_PkmnGotOverItsInfatuation[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha superat\n"
    "l'enamorament!");
static const u8 sText_ZPowerSurrounds[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'envolta\n"
    "del seu Poder Z!");
static const u8 sText_ZPowerUnleashed[] = _(
    "{B_ATK_NAME_WITH_PREFIX} deixa anar\n"
    "el seu Moviment Z a tota potència!");
static const u8 sText_ZMoveResetsStats[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha tornat les\n"
    "estadístiques baixades a la normalitat\lamb el seu Poder Z!");
static const u8 sText_ZMoveAllStatsUp[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha pujat totes\n"
    "les estadístiques amb el seu Poder Z!");
static const u8 sText_ZMoveBoostCrit[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha pujat el seu\n"
    "ratio de crítics amb el seu Poder Z!");
static const u8 sText_ZMoveRestoreHp[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha recuperat\n"
    "PS amb el seu Poder Z!");
static const u8 sText_ZMoveStatUp[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha pujat les\n"
    "estadístiques amb el Poder Z!");
static const u8 sText_ZMoveHpSwitchInTrap[] = _("El Poder Z ha recuperat els PS de {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_TerrainReturnedToNormal[] = _(
    "El camp ha tornat a la\n"
    "normalitat!");
static const u8 sText_ItemCannotBeRemoved[] = _("L'objecte de {B_ATK_NAME_WITH_PREFIX} no es pot treure!");
static const u8 sText_StickyBarbTransfer[] = _(
    "{B_LAST_ITEM} s'ha enganxat a\n"
    "{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnBurnHealed[] = _(
    "La cremada de {B_DEF_NAME_WITH_PREFIX}\n"
    "s'ha curat.");
static const u8 sText_RedCardActivate[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha mostrat {B_LAST_ITEM}\n"
    "a {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_EjectButtonActivate[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} surt del combat\n"
    "amb {B_LAST_ITEM}!");
static const u8 sText_AttackerGotOverInfatuation[] =_(
    "{B_ATK_NAME_WITH_PREFIX} ha superat\n"
    "l'enamorament!");
static const u8 sText_TormentedNoMore[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ja no\n"
    "està turmentat!");
static const u8 sText_HealBlockedNoMore[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha curat\n"
    "de l'anticura!");
static const u8 sText_AttackerBecameFullyCharged[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha carregat del tot\n"
    "pel vincle amb el seu entrenador!\p");
static const u8 sText_AttackerBecameAshSpecies[] = _("{B_ATK_NAME_WITH_PREFIX} s'ha convertit en Ash-{B_BUFF1}!\p");
static const u8 sText_ExtremelyHarshSunlight[] = _(
    "La llum del sol s'ha tornat\n"
    "extremament intensa!");
static const u8 sText_ExtremeSunlightFaded[] = _("La llum del sol extrema s'ha afeblit.{PAUSE 64}");
static const u8 sText_MoveEvaporatedInTheHarshSunlight[] = _(
    "L'atac de tipus Aigua s'ha evaporat\n"
    "amb la llum del sol intensa!");
static const u8 sText_ExtremelyHarshSunlightWasNotLessened[] = _(
    "La llum del sol extremament intensa\n"
    "no s'ha afeblit gens!");
static const u8 sText_HeavyRain[] = _("Ha començat a ploure amb força!");
static const u8 sText_HeavyRainLifted[] = _("La pluja intensa ha parat!{PAUSE 64}");
static const u8 sText_MoveFizzledOutInTheHeavyRain[] = _(
    "L'atac de tipus Foc s'ha apagat\n"
    "amb la pluja intensa!");
static const u8 sText_NoReliefFromHeavyRain[] = _(
    "No hi ha manera d'aturar\n"
    "aquesta pluja intensa!");
static const u8 sText_MysteriousAirCurrent[] = _(
    "Un corrent d'aire misteriós\n"
    "protegeix els Pokémon Volador!");
static const u8 sText_StrongWindsDissipated[] = _(
    "Els vents forts misteriosos\n"
    "s'han dissipat!{PAUSE 64}");
static const u8 sText_MysteriousAirCurrentBlowsOn[] = _(
    "El corrent d'aire misteriós\n"
    "bufa igualment!");
static const u8 sText_AttackWeakenedByStrongWinds[] = _(
    "Els vents forts misteriosos\n"
    "han afeblit l'atac!");
static const u8 sText_StuffCheeksCantSelect[] = _(
    "No es pot triar Omplir Galtes\n"
    "sense una baia!\p");
static const u8 sText_PkmnRevertedToPrimal[] = _(
    "Regressió Primigènia de {B_ATK_NAME_WITH_PREFIX}!\n"
    "Ha tornat a la forma primigènia!");
static const u8 sText_ButPokemonCantUseTheMove[] = _(
    "Però {B_ATK_NAME_WITH_PREFIX} no pot\n"
    "usar el moviment!");
static const u8 sText_ButHoopaCantUseIt[] = _(
    "Però Hoopa no ho pot fer servir\n"
    "tal com està ara!");
static const u8 sText_BrokeThroughProtection[] = _(
    "Ha traspassat la protecció de\n"
    "{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_AbilityAllowsOnlyMove[] = _(
    "{B_ATK_ABILITY} només permet\n"
    "fer servir {B_CURRENT_MOVE}!\p");
static const u8 sText_SwappedAbilities[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ha bescanviat Habilitats\n"
    "amb el seu objectiu!");
static const u8 sText_PastelVeilProtected[] = _(
    "{B_DEF_NAME_WITH_PREFIX} està protegit\n"
    "per un vel pastel!");
static const u8 sText_PastelVeilEnters[] = _(
    "{B_DEF_NAME_WITH_PREFIX} s'ha curat\n"
    "de l'enverinament!");
static const u8 sText_BattlerTypeChangedTo[] = _(
    "El tipus de {B_BUFF1}\n"
    "ha canviat a {B_BUFF2}!");
static const u8 sText_BothCanNoLongerEscape[] = _("Cap dels dos Pokémon pot fugir!");
static const u8 sText_CantEscapeDueToUsedMove[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ja no pot escapar\n"
    "perquè ha usat {B_CURRENT_MOVE}!");
static const u8 sText_PkmnBecameWeakerToFire[] = _(
    "{B_DEF_NAME_WITH_PREFIX} s'ha tornat\n"
    "més feble al foc!");
static const u8 sText_PkmnAboutToBeAttackedByItsItem[] = _(
    "{B_DEF_NAME_WITH_PREFIX} està a punt\n"
    "de rebre l'atac de {B_BUFF1}!");
static const u8 sText_CantEscapeBecauseOfCurrentMove[] = _(
    "{B_DEF_NAME_WITH_PREFIX} ja no pot escapar\n"
    "per culpa de {B_CURRENT_MOVE}!");
static const u8 sText_NeutralizingGasEnters[] = _("El Gas Neutralitzant ha omplert la zona!");
static const u8 sText_NeutralizingGasOver[] = _(
    "Els efectes del Gas Neutralitzant\n"
    "s'han esgotat!");
static const u8 sText_PkmnTookTargetHigh[] = _(
    "{B_ATK_NAME_WITH_PREFIX} s'ha endut {B_DEF_NAME_WITH_PREFIX}\n"
    "enlaire!");
static const u8 sText_TargetTooHeavy[] = _(
    "Però l'objectiu era\n"
    "massa pesat!");
static const u8 sText_MeteorBeamCharging[] = _(
    "{B_ATK_NAME_WITH_PREFIX} desborda\n"
    "d'energia espacial!");
static const u8 sText_HeatingUpBeak[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha començat\n"
    "a escalfar-se el bec!");
static const u8 sText_CourtChange[] = _(
    "{B_ATK_NAME_WITH_PREFIX} ha intercanviat els efectes\n"
    "de combat de cada costat!");


const u8 *const gBattleStringsTable[BATTLESTRINGS_COUNT] =
{
    [STRINGID_ZPOWERSURROUNDS - BATTLESTRINGS_TABLE_START] = sText_ZPowerSurrounds,
    [STRINGID_ZMOVEUNLEASHED - BATTLESTRINGS_TABLE_START] = sText_ZPowerUnleashed,
    [STRINGID_ZMOVERESETSSTATS - BATTLESTRINGS_TABLE_START] = sText_ZMoveResetsStats,
    [STRINGID_ZMOVEALLSTATSUP - BATTLESTRINGS_TABLE_START] = sText_ZMoveAllStatsUp,
    [STRINGID_ZMOVEZBOOSTCRIT - BATTLESTRINGS_TABLE_START] = sText_ZMoveBoostCrit,
    [STRINGID_ZMOVERESTOREHP - BATTLESTRINGS_TABLE_START] = sText_ZMoveRestoreHp,
    [STRINGID_ZMOVESTATUP - BATTLESTRINGS_TABLE_START] = sText_ZMoveStatUp,
    [STRINGID_ZMOVEHPTRAP - BATTLESTRINGS_TABLE_START] = sText_ZMoveHpSwitchInTrap,
    [STRINGID_PLAYERLOSTTOENEMYTRAINER - BATTLESTRINGS_TABLE_START] = sText_PlayerLostToEnemyTrainer,
    [STRINGID_PLAYERPAIDPRIZEMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerPaidPrizeMoney,
    [STRINGID_PLAYERPAIDPRIZEMONEYNOWHITEOUT - BATTLESTRINGS_TABLE_START] = sText_PlayerPaidPrizeMoneyNoWhiteout,
    [STRINGID_COURTCHANGE - BATTLESTRINGS_TABLE_START] = sText_CourtChange,
    [STRINGID_HEATUPBEAK - BATTLESTRINGS_TABLE_START] = sText_HeatingUpBeak,
    [STRINGID_METEORBEAMCHARGING - BATTLESTRINGS_TABLE_START] = sText_MeteorBeamCharging,
    [STRINGID_PKMNINSNAPTRAP - BATTLESTRINGS_TABLE_START] = sText_PkmnInSnapTrap,
    [STRINGID_NEUTRALIZINGGASOVER - BATTLESTRINGS_TABLE_START] = sText_NeutralizingGasOver,
    [STRINGID_NEUTRALIZINGGASENTERS - BATTLESTRINGS_TABLE_START] = sText_NeutralizingGasEnters,
    [STRINGID_BATTLERTYPECHANGEDTO - BATTLESTRINGS_TABLE_START] = sText_BattlerTypeChangedTo,
    [STRINGID_PASTELVEILENTERS - BATTLESTRINGS_TABLE_START] = sText_PastelVeilEnters,
    [STRINGID_PASTELVEILPROTECTED - BATTLESTRINGS_TABLE_START] = sText_PastelVeilProtected,
    [STRINGID_SWAPPEDABILITIES - BATTLESTRINGS_TABLE_START] = sText_SwappedAbilities,
    [STRINGID_ABILITYALLOWSONLYMOVE - BATTLESTRINGS_TABLE_START] = sText_AbilityAllowsOnlyMove,
    [STRINGID_BROKETHROUGHPROTECTION - BATTLESTRINGS_TABLE_START] = sText_BrokeThroughProtection,
    [STRINGID_BUTPOKEMONCANTUSETHEMOVE - BATTLESTRINGS_TABLE_START] = sText_ButPokemonCantUseTheMove,
    [STRINGID_BUTHOOPACANTUSEIT - BATTLESTRINGS_TABLE_START] = sText_ButHoopaCantUseIt,
    [STRINGID_PKMNREVERTEDTOPRIMAL - BATTLESTRINGS_TABLE_START] = sText_PkmnRevertedToPrimal,
    [STRINGID_STUFFCHEEKSCANTSELECT - BATTLESTRINGS_TABLE_START] = sText_StuffCheeksCantSelect,
    [STRINGID_ATTACKWEAKENEDBSTRONGWINDS - BATTLESTRINGS_TABLE_START] = sText_AttackWeakenedByStrongWinds,
    [STRINGID_MYSTERIOUSAIRCURRENTBLOWSON - BATTLESTRINGS_TABLE_START] = sText_MysteriousAirCurrentBlowsOn,
    [STRINGID_STRONGWINDSDISSIPATED - BATTLESTRINGS_TABLE_START] = sText_StrongWindsDissipated,
    [STRINGID_MYSTERIOUSAIRCURRENT - BATTLESTRINGS_TABLE_START] = sText_MysteriousAirCurrent,
    [STRINGID_NORELIEFROMHEAVYRAIN - BATTLESTRINGS_TABLE_START] = sText_NoReliefFromHeavyRain,
    [STRINGID_MOVEFIZZLEDOUTINTHEHEAVYRAIN - BATTLESTRINGS_TABLE_START] = sText_MoveFizzledOutInTheHeavyRain,
    [STRINGID_HEAVYRAINLIFTED - BATTLESTRINGS_TABLE_START] = sText_HeavyRainLifted,
    [STRINGID_HEAVYRAIN - BATTLESTRINGS_TABLE_START] = sText_HeavyRain,
    [STRINGID_EXTREMELYHARSHSUNLIGHTWASNOTLESSENED - BATTLESTRINGS_TABLE_START] = sText_ExtremelyHarshSunlightWasNotLessened,
    [STRINGID_MOVEEVAPORATEDINTHEHARSHSUNLIGHT - BATTLESTRINGS_TABLE_START] = sText_MoveEvaporatedInTheHarshSunlight,
    [STRINGID_EXTREMESUNLIGHTFADED - BATTLESTRINGS_TABLE_START] = sText_ExtremeSunlightFaded,
    [STRINGID_EXTREMELYHARSHSUNLIGHT - BATTLESTRINGS_TABLE_START] = sText_ExtremelyHarshSunlight,
    [STRINGID_ATTACKERBECAMEASHSPECIES - BATTLESTRINGS_TABLE_START] = sText_AttackerBecameAshSpecies,
    [STRINGID_ATTACKERBECAMEFULLYCHARGED - BATTLESTRINGS_TABLE_START] = sText_AttackerBecameFullyCharged,
    [STRINGID_HEALBLOCKEDNOMORE - BATTLESTRINGS_TABLE_START] = sText_HealBlockedNoMore,
    [STRINGID_TORMENTEDNOMORE - BATTLESTRINGS_TABLE_START] = sText_TormentedNoMore,
    [STRINGID_ATKGOTOVERINFATUATION - BATTLESTRINGS_TABLE_START] = sText_AttackerGotOverInfatuation,
    [STRINGID_EJECTBUTTONACTIVATE - BATTLESTRINGS_TABLE_START] = sText_EjectButtonActivate,
    [STRINGID_REDCARDACTIVATE - BATTLESTRINGS_TABLE_START] = sText_RedCardActivate,
    [STRINGID_PKMNBURNHEALED - BATTLESTRINGS_TABLE_START] = sText_PkmnBurnHealed,
    [STRINGID_STICKYBARBTRANSFER - BATTLESTRINGS_TABLE_START] = sText_StickyBarbTransfer,
    [STRINGID_ITEMCANNOTBEREMOVED - BATTLESTRINGS_TABLE_START] = sText_ItemCannotBeRemoved,
    [STRINGID_PKMNGOTOVERITSINFATUATION - BATTLESTRINGS_TABLE_START] = sText_PkmnGotOverItsInfatuation,
    [STRINGID_PKMNSHOOKOFFTHETAUNT - BATTLESTRINGS_TABLE_START] = sText_PkmnShookOffTheTaunt,
    [STRINGID_MICLEBERRYACTIVATES - BATTLESTRINGS_TABLE_START] = sText_MicleBerryActivates,
    [STRINGID_CANACTFASTERTHANKSTO - BATTLESTRINGS_TABLE_START] = sText_CanActFaster,
    [STRINGID_CURIOUSMEDICINEENTERS - BATTLESTRINGS_TABLE_START] = sText_CuriousMedicineEnters,
    [STRINGID_ASONEENTERS - BATTLESTRINGS_TABLE_START] = sText_AsOneEnters,
    [STRINGID_ABILITYRAISEDSTATDRASTICALLY - BATTLESTRINGS_TABLE_START] = sText_AbilityRaisedStatDrastically,
    [STRINGID_PKMNSWILLPERISHIN3TURNS - BATTLESTRINGS_TABLE_START] = sText_PkmnsWillPerishIn3Turns,
    [STRINGID_ASANDSTORMKICKEDUP - BATTLESTRINGS_TABLE_START] = sText_ASandstormKickedUp,
    [STRINGID_BATTLERABILITYRAISEDSTAT - BATTLESTRINGS_TABLE_START] = sText_BattlerAbilityRaisedStat,
    [STRINGID_FETCHEDPOKEBALL - BATTLESTRINGS_TABLE_START] = sText_FetchedPokeBall,
    [STRINGID_STATWASNOTLOWERED - BATTLESTRINGS_TABLE_START] = sText_StatWasNotLowered,
    [STRINGID_CLOAKEDINAFREEZINGLIGHT - BATTLESTRINGS_TABLE_START] = sText_CloakedInAFreezingLight,
    [STRINGID_DESTINYKNOTACTIVATES - BATTLESTRINGS_TABLE_START] = sText_DestinyKnotActivates,
    [STRINGID_NOONEWILLBEABLETORUNAWAY - BATTLESTRINGS_TABLE_START] = sText_NoOneWillBeAbleToRun,
    [STRINGID_PKNMABSORBINGPOWER - BATTLESTRINGS_TABLE_START] = sText_PkmnAbsorbingPower,
    [STRINGID_RECEIVERABILITYTAKEOVER - BATTLESTRINGS_TABLE_START] = sText_ReceiverAbilityTakeOver,
    [STRINGID_SCRIPTINGABILITYSTATRAISE - BATTLESTRINGS_TABLE_START] = sText_ScriptingAbilityRaisedStat,
    [STRINGID_HEALERCURE - BATTLESTRINGS_TABLE_START] = sText_HealerCure,
    [STRINGID_ATTACKERLOSTFIRETYPE - BATTLESTRINGS_TABLE_START] = sText_AttackerLostFireType,
    [STRINGID_ATTACKERCUREDTARGETSTATUS - BATTLESTRINGS_TABLE_START] = sText_AttackerCuredTargetStatus,
    [STRINGID_ILLUSIONWOREOFF - BATTLESTRINGS_TABLE_START] = sText_IllusionWoreOff,
    [STRINGID_BUGBITE - BATTLESTRINGS_TABLE_START] = sText_BugBite,
    [STRINGID_INCINERATEBURN - BATTLESTRINGS_TABLE_START] = sText_IncinerateBurn,
    [STRINGID_AIRBALLOONPOP - BATTLESTRINGS_TABLE_START] = sText_AirBalloonPop,
    [STRINGID_AIRBALLOONFLOAT - BATTLESTRINGS_TABLE_START] = sText_AirBalloonFloat,
    [STRINGID_TARGETATEITEM - BATTLESTRINGS_TABLE_START] = sText_TargetAteItem,
    [STRINGID_BERRYDMGREDUCES - BATTLESTRINGS_TABLE_START] = sText_BerryDmgReducing,
    [STRINGID_GEMACTIVATES - BATTLESTRINGS_TABLE_START] = sText_GemActivates,
    [STRINGID_LASERFOCUS - BATTLESTRINGS_TABLE_START] = sText_LaserFocusMessage,
    [STRINGID_THROATCHOPENDS - BATTLESTRINGS_TABLE_START] = sText_ThroatChopEnds,
    [STRINGID_PKMNCANTUSEMOVETHROATCHOP - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveThroatChop,
    [STRINGID_USEDINSTRUCTEDMOVE - BATTLESTRINGS_TABLE_START] = sText_UsedInstructedMove,
    [STRINGID_CELEBRATEMESSAGE - BATTLESTRINGS_TABLE_START] = sText_CelebrateMessage,
    [STRINGID_AROMAVEILPROTECTED - BATTLESTRINGS_TABLE_START] = sText_AromaVeilProtected,
    [STRINGID_SWEETVEILPROTECTED - BATTLESTRINGS_TABLE_START] = sText_SweetVeilProtected,
    [STRINGID_FLOWERVEILPROTECTED - BATTLESTRINGS_TABLE_START] = sText_FlowerVeilProtected,
    [STRINGID_SAFETYGOGGLESPROTECTED - BATTLESTRINGS_TABLE_START] = sText_SafetyGogglesProtected,
    [STRINGID_SPECTRALTHIEFSTEAL - BATTLESTRINGS_TABLE_START] = sText_SpectralThiefSteal,
    [STRINGID_BELCHCANTSELECT - BATTLESTRINGS_TABLE_START] = sText_BelchCantUse,
    [STRINGID_TRAINER1LOSETEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer1LoseText,
    [STRINGID_PKMNGAINEDEXP - BATTLESTRINGS_TABLE_START] = sText_PkmnGainedEXP,
    [STRINGID_PKMNGREWTOLV - BATTLESTRINGS_TABLE_START] = sText_PkmnGrewToLv,
    [STRINGID_PKMNLEARNEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnLearnedMove,
    [STRINGID_TRYTOLEARNMOVE1 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove1,
    [STRINGID_TRYTOLEARNMOVE2 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove2,
    [STRINGID_TRYTOLEARNMOVE3 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove3,
    [STRINGID_PKMNFORGOTMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnForgotMove,
    [STRINGID_STOPLEARNINGMOVE - BATTLESTRINGS_TABLE_START] = sText_StopLearningMove,
    [STRINGID_DIDNOTLEARNMOVE - BATTLESTRINGS_TABLE_START] = sText_DidNotLearnMove,
    [STRINGID_PKMNLEARNEDMOVE2 - BATTLESTRINGS_TABLE_START] = sText_PkmnLearnedMove2,
    [STRINGID_ATTACKMISSED - BATTLESTRINGS_TABLE_START] = sText_AttackMissed,
    [STRINGID_PKMNPROTECTEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedItself,
    [STRINGID_STATSWONTINCREASE2 - BATTLESTRINGS_TABLE_START] = sText_StatsWontIncrease2,
    [STRINGID_AVOIDEDDAMAGE - BATTLESTRINGS_TABLE_START] = sText_AvoidedDamage,
    [STRINGID_ITDOESNTAFFECT - BATTLESTRINGS_TABLE_START] = sText_ItDoesntAffect,
    [STRINGID_ATTACKERFAINTED - BATTLESTRINGS_TABLE_START] = sText_AttackerFainted,
    [STRINGID_TARGETFAINTED - BATTLESTRINGS_TABLE_START] = sText_TargetFainted,
    [STRINGID_PLAYERGOTMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerGotMoney,
    [STRINGID_PLAYERWHITEOUT - BATTLESTRINGS_TABLE_START] = sText_PlayerWhiteout,
    [STRINGID_PLAYERWHITEOUT2 - BATTLESTRINGS_TABLE_START] = sText_PlayerWhiteout2,
    [STRINGID_PLAYERWHITEOUT3 - BATTLESTRINGS_TABLE_START] = sText_PlayerWhiteout3,
    [STRINGID_PLAYERDROPPEDMONEYNOWHITEOUT - BATTLESTRINGS_TABLE_START] = sText_PlayerDroppedMoneyNoWhiteout,
    [STRINGID_PREVENTSESCAPE - BATTLESTRINGS_TABLE_START] = sText_PreventsEscape,
    [STRINGID_HITXTIMES - BATTLESTRINGS_TABLE_START] = sText_HitXTimes,
    [STRINGID_PKMNFELLASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnFellAsleep,
    [STRINGID_PKMNMADESLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeSleep,
    [STRINGID_PKMNALREADYASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyAsleep,
    [STRINGID_PKMNALREADYASLEEP2 - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyAsleep2,
    [STRINGID_PKMNWASNTAFFECTED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasntAffected,
    [STRINGID_PKMNWASPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasPoisoned,
    [STRINGID_PKMNPOISONEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnPoisonedBy,
    [STRINGID_PKMNHURTBYPOISON - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByPoison,
    [STRINGID_PKMNALREADYPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyPoisoned,
    [STRINGID_PKMNBADLYPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnBadlyPoisoned,
    [STRINGID_PKMNENERGYDRAINED - BATTLESTRINGS_TABLE_START] = sText_PkmnEnergyDrained,
    [STRINGID_PKMNWASBURNED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasBurned,
    [STRINGID_PKMNBURNEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnBurnedBy,
    [STRINGID_PKMNHURTBYBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByBurn,
    [STRINGID_PKMNWASFROZEN - BATTLESTRINGS_TABLE_START] = sText_PkmnWasFrozen,
    [STRINGID_PKMNFROZENBY - BATTLESTRINGS_TABLE_START] = sText_PkmnFrozenBy,
    [STRINGID_PKMNISFROZEN - BATTLESTRINGS_TABLE_START] = sText_PkmnIsFrozen,
    [STRINGID_PKMNWASDEFROSTED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrosted,
    [STRINGID_PKMNWASDEFROSTED2 - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrosted2,
    [STRINGID_PKMNWASDEFROSTEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrostedBy,
    [STRINGID_PKMNWASPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasParalyzed,
    [STRINGID_PKMNWASPARALYZEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasParalyzedBy,
    [STRINGID_PKMNISPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsParalyzed,
    [STRINGID_PKMNISALREADYPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsAlreadyParalyzed,
    [STRINGID_PKMNHEALEDPARALYSIS - BATTLESTRINGS_TABLE_START] = sText_PkmnHealedParalysis,
    [STRINGID_PKMNDREAMEATEN - BATTLESTRINGS_TABLE_START] = sText_PkmnDreamEaten,
    [STRINGID_STATSWONTINCREASE - BATTLESTRINGS_TABLE_START] = sText_StatsWontIncrease,
    [STRINGID_STATSWONTDECREASE - BATTLESTRINGS_TABLE_START] = sText_StatsWontDecrease,
    [STRINGID_TEAMSTOPPEDWORKING - BATTLESTRINGS_TABLE_START] = sText_TeamStoppedWorking,
    [STRINGID_FOESTOPPEDWORKING - BATTLESTRINGS_TABLE_START] = sText_FoeStoppedWorking,
    [STRINGID_PKMNISCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsConfused,
    [STRINGID_PKMNHEALEDCONFUSION - BATTLESTRINGS_TABLE_START] = sText_PkmnHealedConfusion,
    [STRINGID_PKMNWASCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasConfused,
    [STRINGID_PKMNALREADYCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyConfused,
    [STRINGID_PKMNFELLINLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnFellInLove,
    [STRINGID_PKMNINLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnInLove,
    [STRINGID_PKMNIMMOBILIZEDBYLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnImmobilizedByLove,
    [STRINGID_PKMNBLOWNAWAY - BATTLESTRINGS_TABLE_START] = sText_PkmnBlownAway,
    [STRINGID_PKMNCHANGEDTYPE - BATTLESTRINGS_TABLE_START] = sText_PkmnChangedType,
    [STRINGID_PKMNFLINCHED - BATTLESTRINGS_TABLE_START] = sText_PkmnFlinched,
    [STRINGID_PKMNREGAINEDHEALTH - BATTLESTRINGS_TABLE_START] = sText_PkmnRegainedHealth,
    [STRINGID_PKMNHPFULL - BATTLESTRINGS_TABLE_START] = sText_PkmnHPFull,
    [STRINGID_PKMNRAISEDSPDEF - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpDef,
    [STRINGID_PKMNRAISEDDEF - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedDef,
    [STRINGID_PKMNCOVEREDBYVEIL - BATTLESTRINGS_TABLE_START] = sText_PkmnCoveredByVeil,
    [STRINGID_PKMNUSEDSAFEGUARD - BATTLESTRINGS_TABLE_START] = sText_PkmnUsedSafeguard,
    [STRINGID_PKMNSAFEGUARDEXPIRED - BATTLESTRINGS_TABLE_START] = sText_PkmnSafeguardExpired,
    [STRINGID_PKMNWENTTOSLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnWentToSleep,
    [STRINGID_PKMNSLEPTHEALTHY - BATTLESTRINGS_TABLE_START] = sText_PkmnSleptHealthy,
    [STRINGID_PKMNWHIPPEDWHIRLWIND - BATTLESTRINGS_TABLE_START] = sText_PkmnWhippedWhirlwind,
    [STRINGID_PKMNTOOKSUNLIGHT - BATTLESTRINGS_TABLE_START] = sText_PkmnTookSunlight,
    [STRINGID_PKMNLOWEREDHEAD - BATTLESTRINGS_TABLE_START] = sText_PkmnLoweredHead,
    [STRINGID_PKMNISGLOWING - BATTLESTRINGS_TABLE_START] = sText_PkmnIsGlowing,
    [STRINGID_PKMNFLEWHIGH - BATTLESTRINGS_TABLE_START] = sText_PkmnFlewHigh,
    [STRINGID_PKMNDUGHOLE - BATTLESTRINGS_TABLE_START] = sText_PkmnDugHole,
    [STRINGID_PKMNSQUEEZEDBYBIND - BATTLESTRINGS_TABLE_START] = sText_PkmnSqueezedByBind,
    [STRINGID_PKMNTRAPPEDINVORTEX - BATTLESTRINGS_TABLE_START] = sText_PkmnTrappedInVortex,
    [STRINGID_PKMNWRAPPEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWrappedBy,
    [STRINGID_PKMNCLAMPED - BATTLESTRINGS_TABLE_START] = sText_PkmnClamped,
    [STRINGID_PKMNHURTBY - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtBy,
    [STRINGID_PKMNFREEDFROM - BATTLESTRINGS_TABLE_START] = sText_PkmnFreedFrom,
    [STRINGID_PKMNCRASHED - BATTLESTRINGS_TABLE_START] = sText_PkmnCrashed,
    [STRINGID_PKMNSHROUDEDINMIST - BATTLESTRINGS_TABLE_START] = gText_PkmnShroudedInMist,
    [STRINGID_PKMNPROTECTEDBYMIST - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedByMist,
    [STRINGID_PKMNGETTINGPUMPED - BATTLESTRINGS_TABLE_START] = gText_PkmnGettingPumped,
    [STRINGID_PKMNHITWITHRECOIL - BATTLESTRINGS_TABLE_START] = sText_PkmnHitWithRecoil,
    [STRINGID_PKMNPROTECTEDITSELF2 - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedItself2,
    [STRINGID_PKMNBUFFETEDBYSANDSTORM - BATTLESTRINGS_TABLE_START] = sText_PkmnBuffetedBySandstorm,
    [STRINGID_PKMNPELTEDBYHAIL - BATTLESTRINGS_TABLE_START] = sText_PkmnPeltedByHail,
    [STRINGID_PKMNSEEDED - BATTLESTRINGS_TABLE_START] = sText_PkmnSeeded,
    [STRINGID_PKMNEVADEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnEvadedAttack,
    [STRINGID_PKMNSAPPEDBYLEECHSEED - BATTLESTRINGS_TABLE_START] = sText_PkmnSappedByLeechSeed,
    [STRINGID_PKMNFASTASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnFastAsleep,
    [STRINGID_PKMNWOKEUP - BATTLESTRINGS_TABLE_START] = sText_PkmnWokeUp,
    [STRINGID_PKMNUPROARKEPTAWAKE - BATTLESTRINGS_TABLE_START] = sText_PkmnUproarKeptAwake,
    [STRINGID_PKMNWOKEUPINUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnWokeUpInUproar,
    [STRINGID_PKMNCAUSEDUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnCausedUproar,
    [STRINGID_PKMNMAKINGUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnMakingUproar,
    [STRINGID_PKMNCALMEDDOWN - BATTLESTRINGS_TABLE_START] = sText_PkmnCalmedDown,
    [STRINGID_PKMNCANTSLEEPINUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnCantSleepInUproar,
    [STRINGID_PKMNSTOCKPILED - BATTLESTRINGS_TABLE_START] = sText_PkmnStockpiled,
    [STRINGID_PKMNCANTSTOCKPILE - BATTLESTRINGS_TABLE_START] = sText_PkmnCantStockpile,
    [STRINGID_PKMNCANTSLEEPINUPROAR2 - BATTLESTRINGS_TABLE_START] = sText_PkmnCantSleepInUproar2,
    [STRINGID_UPROARKEPTPKMNAWAKE - BATTLESTRINGS_TABLE_START] = sText_UproarKeptPkmnAwake,
    [STRINGID_PKMNSTAYEDAWAKEUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnStayedAwakeUsing,
    [STRINGID_PKMNSTORINGENERGY - BATTLESTRINGS_TABLE_START] = sText_PkmnStoringEnergy,
    [STRINGID_PKMNUNLEASHEDENERGY - BATTLESTRINGS_TABLE_START] = sText_PkmnUnleashedEnergy,
    [STRINGID_PKMNFATIGUECONFUSION - BATTLESTRINGS_TABLE_START] = sText_PkmnFatigueConfusion,
    [STRINGID_PLAYERPICKEDUPMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerPickedUpMoney,
    [STRINGID_PKMNUNAFFECTED - BATTLESTRINGS_TABLE_START] = sText_PkmnUnaffected,
    [STRINGID_PKMNTRANSFORMEDINTO - BATTLESTRINGS_TABLE_START] = sText_PkmnTransformedInto,
    [STRINGID_PKMNMADESUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeSubstitute,
    [STRINGID_PKMNHASSUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_PkmnHasSubstitute,
    [STRINGID_SUBSTITUTEDAMAGED - BATTLESTRINGS_TABLE_START] = sText_SubstituteDamaged,
    [STRINGID_PKMNSUBSTITUTEFADED - BATTLESTRINGS_TABLE_START] = sText_PkmnSubstituteFaded,
    [STRINGID_PKMNMUSTRECHARGE - BATTLESTRINGS_TABLE_START] = sText_PkmnMustRecharge,
    [STRINGID_PKMNRAGEBUILDING - BATTLESTRINGS_TABLE_START] = sText_PkmnRageBuilding,
    [STRINGID_PKMNMOVEWASDISABLED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveWasDisabled,
    [STRINGID_PKMNMOVEISDISABLED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveIsDisabled,
    [STRINGID_PKMNMOVEDISABLEDNOMORE - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveDisabledNoMore,
    [STRINGID_PKMNGOTENCORE - BATTLESTRINGS_TABLE_START] = sText_PkmnGotEncore,
    [STRINGID_PKMNENCOREENDED - BATTLESTRINGS_TABLE_START] = sText_PkmnEncoreEnded,
    [STRINGID_PKMNTOOKAIM - BATTLESTRINGS_TABLE_START] = sText_PkmnTookAim,
    [STRINGID_PKMNSKETCHEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSketchedMove,
    [STRINGID_PKMNTRYINGTOTAKEFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnTryingToTakeFoe,
    [STRINGID_PKMNTOOKFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnTookFoe,
    [STRINGID_PKMNREDUCEDPP - BATTLESTRINGS_TABLE_START] = sText_PkmnReducedPP,
    [STRINGID_PKMNSTOLEITEM - BATTLESTRINGS_TABLE_START] = sText_PkmnStoleItem,
    [STRINGID_TARGETCANTESCAPENOW - BATTLESTRINGS_TABLE_START] = sText_TargetCantEscapeNow,
    [STRINGID_PKMNFELLINTONIGHTMARE - BATTLESTRINGS_TABLE_START] = sText_PkmnFellIntoNightmare,
    [STRINGID_PKMNLOCKEDINNIGHTMARE - BATTLESTRINGS_TABLE_START] = sText_PkmnLockedInNightmare,
    [STRINGID_PKMNLAIDCURSE - BATTLESTRINGS_TABLE_START] = sText_PkmnLaidCurse,
    [STRINGID_PKMNAFFLICTEDBYCURSE - BATTLESTRINGS_TABLE_START] = sText_PkmnAfflictedByCurse,
    [STRINGID_SPIKESSCATTERED - BATTLESTRINGS_TABLE_START] = sText_SpikesScattered,
    [STRINGID_PKMNHURTBYSPIKES - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtBySpikes,
    [STRINGID_PKMNIDENTIFIED - BATTLESTRINGS_TABLE_START] = sText_PkmnIdentified,
    [STRINGID_PKMNPERISHCOUNTFELL - BATTLESTRINGS_TABLE_START] = sText_PkmnPerishCountFell,
    [STRINGID_PKMNBRACEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnBracedItself,
    [STRINGID_PKMNENDUREDHIT - BATTLESTRINGS_TABLE_START] = sText_PkmnEnduredHit,
    [STRINGID_MAGNITUDESTRENGTH - BATTLESTRINGS_TABLE_START] = sText_MagnitudeStrength,
    [STRINGID_PKMNCUTHPMAXEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnCutHPMaxedAttack,
    [STRINGID_PKMNCOPIEDSTATCHANGES - BATTLESTRINGS_TABLE_START] = sText_PkmnCopiedStatChanges,
    [STRINGID_PKMNGOTFREE - BATTLESTRINGS_TABLE_START] = sText_PkmnGotFree,
    [STRINGID_PKMNSHEDLEECHSEED - BATTLESTRINGS_TABLE_START] = sText_PkmnShedLeechSeed,
    [STRINGID_PKMNBLEWAWAYSPIKES - BATTLESTRINGS_TABLE_START] = sText_PkmnBlewAwaySpikes,
    [STRINGID_PKMNFLEDFROMBATTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnFledFromBattle,
    [STRINGID_PKMNFORESAWATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnForesawAttack,
    [STRINGID_PKMNTOOKATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnTookAttack,
    [STRINGID_PKMNATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnAttack,
    [STRINGID_PKMNCENTERATTENTION - BATTLESTRINGS_TABLE_START] = sText_PkmnCenterAttention,
    [STRINGID_PKMNCHARGINGPOWER - BATTLESTRINGS_TABLE_START] = sText_PkmnChargingPower,
    [STRINGID_NATUREPOWERTURNEDINTO - BATTLESTRINGS_TABLE_START] = sText_NaturePowerTurnedInto,
    [STRINGID_PKMNSTATUSNORMAL - BATTLESTRINGS_TABLE_START] = sText_PkmnStatusNormal,
    [STRINGID_PKMNHASNOMOVESLEFT - BATTLESTRINGS_TABLE_START] = sText_PkmnHasNoMovesLeft,
    [STRINGID_PKMNSUBJECTEDTOTORMENT - BATTLESTRINGS_TABLE_START] = sText_PkmnSubjectedToTorment,
    [STRINGID_PKMNCANTUSEMOVETORMENT - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveTorment,
    [STRINGID_PKMNTIGHTENINGFOCUS - BATTLESTRINGS_TABLE_START] = sText_PkmnTighteningFocus,
    [STRINGID_PKMNFELLFORTAUNT - BATTLESTRINGS_TABLE_START] = sText_PkmnFellForTaunt,
    [STRINGID_PKMNCANTUSEMOVETAUNT - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveTaunt,
    [STRINGID_PKMNREADYTOHELP - BATTLESTRINGS_TABLE_START] = sText_PkmnReadyToHelp,
    [STRINGID_PKMNSWITCHEDITEMS - BATTLESTRINGS_TABLE_START] = sText_PkmnSwitchedItems,
    [STRINGID_PKMNCOPIEDFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnCopiedFoe,
    [STRINGID_PKMNMADEWISH - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeWish,
    [STRINGID_PKMNWISHCAMETRUE - BATTLESTRINGS_TABLE_START] = sText_PkmnWishCameTrue,
    [STRINGID_PKMNPLANTEDROOTS - BATTLESTRINGS_TABLE_START] = sText_PkmnPlantedRoots,
    [STRINGID_PKMNABSORBEDNUTRIENTS - BATTLESTRINGS_TABLE_START] = sText_PkmnAbsorbedNutrients,
    [STRINGID_PKMNANCHOREDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnAnchoredItself,
    [STRINGID_PKMNWASMADEDROWSY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasMadeDrowsy,
    [STRINGID_PKMNKNOCKEDOFF - BATTLESTRINGS_TABLE_START] = sText_PkmnKnockedOff,
    [STRINGID_PKMNSWAPPEDABILITIES - BATTLESTRINGS_TABLE_START] = sText_PkmnSwappedAbilities,
    [STRINGID_PKMNSEALEDOPPONENTMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSealedOpponentMove,
    [STRINGID_PKMNCANTUSEMOVESEALED - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveSealed,
    [STRINGID_PKMNWANTSGRUDGE - BATTLESTRINGS_TABLE_START] = sText_PkmnWantsGrudge,
    [STRINGID_PKMNLOSTPPGRUDGE - BATTLESTRINGS_TABLE_START] = sText_PkmnLostPPGrudge,
    [STRINGID_PKMNSHROUDEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnShroudedItself,
    [STRINGID_PKMNMOVEBOUNCED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveBounced,
    [STRINGID_PKMNWAITSFORTARGET - BATTLESTRINGS_TABLE_START] = sText_PkmnWaitsForTarget,
    [STRINGID_PKMNSNATCHEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSnatchedMove,
    [STRINGID_PKMNMADEITRAIN - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeItRain,
    [STRINGID_PKMNRAISEDSPEED - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpeed,
    [STRINGID_PKMNPROTECTEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedBy,
    [STRINGID_PKMNPREVENTSUSAGE - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsUsage,
    [STRINGID_PKMNRESTOREDHPUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnRestoredHPUsing,
    [STRINGID_PKMNCHANGEDTYPEWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnChangedTypeWith,
    [STRINGID_PKMNPREVENTSPARALYSISWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsParalysisWith,
    [STRINGID_PKMNPREVENTSROMANCEWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsRomanceWith,
    [STRINGID_PKMNPREVENTSPOISONINGWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsPoisoningWith,
    [STRINGID_PKMNPREVENTSCONFUSIONWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsConfusionWith,
    [STRINGID_PKMNRAISEDFIREPOWERWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedFirePowerWith,
    [STRINGID_PKMNANCHORSITSELFWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnAnchorsItselfWith,
    [STRINGID_PKMNCUTSATTACKWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnCutsAttackWith,
    [STRINGID_PKMNPREVENTSSTATLOSSWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsStatLossWith,
    [STRINGID_PKMNHURTSWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtsWith,
    [STRINGID_PKMNTRACED - BATTLESTRINGS_TABLE_START] = sText_PkmnTraced,
    [STRINGID_STATSHARPLY - BATTLESTRINGS_TABLE_START] = gText_StatSharply,
    [STRINGID_STATROSE - BATTLESTRINGS_TABLE_START] = gText_StatRose,
    [STRINGID_STATHARSHLY - BATTLESTRINGS_TABLE_START] = sText_StatHarshly,
    [STRINGID_STATFELL - BATTLESTRINGS_TABLE_START] = sText_StatFell,
    [STRINGID_ATTACKERSSTATROSE - BATTLESTRINGS_TABLE_START] = sText_AttackersStatRose,
    [STRINGID_DEFENDERSSTATROSE - BATTLESTRINGS_TABLE_START] = gText_DefendersStatRose,
    [STRINGID_ATTACKERSSTATFELL - BATTLESTRINGS_TABLE_START] = sText_AttackersStatFell,
    [STRINGID_DEFENDERSSTATFELL - BATTLESTRINGS_TABLE_START] = sText_DefendersStatFell,
    [STRINGID_CRITICALHIT - BATTLESTRINGS_TABLE_START] = sText_CriticalHit,
    [STRINGID_ONEHITKO - BATTLESTRINGS_TABLE_START] = sText_OneHitKO,
    [STRINGID_123POOF - BATTLESTRINGS_TABLE_START] = sText_123Poof,
    [STRINGID_ANDELLIPSIS - BATTLESTRINGS_TABLE_START] = sText_AndEllipsis,
    [STRINGID_NOTVERYEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_NotVeryEffective,
    [STRINGID_SUPEREFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_SuperEffective,
    [STRINGID_GOTAWAYSAFELY - BATTLESTRINGS_TABLE_START] = sText_GotAwaySafely,
    [STRINGID_WILDPKMNFLED - BATTLESTRINGS_TABLE_START] = sText_WildPkmnFled,
    [STRINGID_NORUNNINGFROMTRAINERS - BATTLESTRINGS_TABLE_START] = sText_NoRunningFromTrainers,
    [STRINGID_CANTESCAPE - BATTLESTRINGS_TABLE_START] = sText_CantEscape,
    [STRINGID_DONTLEAVEBIRCH - BATTLESTRINGS_TABLE_START] = sText_DontLeaveBirch,
    [STRINGID_BUTNOTHINGHAPPENED - BATTLESTRINGS_TABLE_START] = sText_ButNothingHappened,
    [STRINGID_BUTITFAILED - BATTLESTRINGS_TABLE_START] = sText_ButItFailed,
    [STRINGID_ITHURTCONFUSION - BATTLESTRINGS_TABLE_START] = sText_ItHurtConfusion,
    [STRINGID_MIRRORMOVEFAILED - BATTLESTRINGS_TABLE_START] = sText_MirrorMoveFailed,
    [STRINGID_STARTEDTORAIN - BATTLESTRINGS_TABLE_START] = sText_StartedToRain,
    [STRINGID_DOWNPOURSTARTED - BATTLESTRINGS_TABLE_START] = sText_DownpourStarted,
    [STRINGID_RAINCONTINUES - BATTLESTRINGS_TABLE_START] = sText_RainContinues,
    [STRINGID_DOWNPOURCONTINUES - BATTLESTRINGS_TABLE_START] = sText_DownpourContinues,
    [STRINGID_RAINSTOPPED - BATTLESTRINGS_TABLE_START] = sText_RainStopped,
    [STRINGID_SANDSTORMBREWED - BATTLESTRINGS_TABLE_START] = sText_SandstormBrewed,
    [STRINGID_SANDSTORMRAGES - BATTLESTRINGS_TABLE_START] = sText_SandstormRages,
    [STRINGID_SANDSTORMSUBSIDED - BATTLESTRINGS_TABLE_START] = sText_SandstormSubsided,
    [STRINGID_SUNLIGHTGOTBRIGHT - BATTLESTRINGS_TABLE_START] = sText_SunlightGotBright,
    [STRINGID_SUNLIGHTSTRONG - BATTLESTRINGS_TABLE_START] = sText_SunlightStrong,
    [STRINGID_SUNLIGHTFADED - BATTLESTRINGS_TABLE_START] = sText_SunlightFaded,
    [STRINGID_STARTEDHAIL - BATTLESTRINGS_TABLE_START] = sText_StartedHail,
    [STRINGID_HAILCONTINUES - BATTLESTRINGS_TABLE_START] = sText_HailContinues,
    [STRINGID_HAILSTOPPED - BATTLESTRINGS_TABLE_START] = sText_HailStopped,
    [STRINGID_FAILEDTOSPITUP - BATTLESTRINGS_TABLE_START] = sText_FailedToSpitUp,
    [STRINGID_FAILEDTOSWALLOW - BATTLESTRINGS_TABLE_START] = sText_FailedToSwallow,
    [STRINGID_WINDBECAMEHEATWAVE - BATTLESTRINGS_TABLE_START] = sText_WindBecameHeatWave,
    [STRINGID_STATCHANGESGONE - BATTLESTRINGS_TABLE_START] = sText_StatChangesGone,
    [STRINGID_COINSSCATTERED - BATTLESTRINGS_TABLE_START] = sText_CoinsScattered,
    [STRINGID_TOOWEAKFORSUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_TooWeakForSubstitute,
    [STRINGID_SHAREDPAIN - BATTLESTRINGS_TABLE_START] = sText_SharedPain,
    [STRINGID_BELLCHIMED - BATTLESTRINGS_TABLE_START] = sText_BellChimed,
    [STRINGID_FAINTINTHREE - BATTLESTRINGS_TABLE_START] = sText_FaintInThree,
    [STRINGID_NOPPLEFT - BATTLESTRINGS_TABLE_START] = sText_NoPPLeft,
    [STRINGID_BUTNOPPLEFT - BATTLESTRINGS_TABLE_START] = sText_ButNoPPLeft,
    [STRINGID_PLAYERUSEDITEM - BATTLESTRINGS_TABLE_START] = sText_PlayerUsedItem,
    [STRINGID_WALLYUSEDITEM - BATTLESTRINGS_TABLE_START] = sText_WallyUsedItem,
    [STRINGID_TRAINERBLOCKEDBALL - BATTLESTRINGS_TABLE_START] = sText_TrainerBlockedBall,
    [STRINGID_DONTBEATHIEF - BATTLESTRINGS_TABLE_START] = sText_DontBeAThief,
    [STRINGID_ITDODGEDBALL - BATTLESTRINGS_TABLE_START] = sText_ItDodgedBall,
    [STRINGID_YOUMISSEDPKMN - BATTLESTRINGS_TABLE_START] = sText_YouMissedPkmn,
    [STRINGID_PKMNBROKEFREE - BATTLESTRINGS_TABLE_START] = sText_PkmnBrokeFree,
    [STRINGID_ITAPPEAREDCAUGHT - BATTLESTRINGS_TABLE_START] = sText_ItAppearedCaught,
    [STRINGID_AARGHALMOSTHADIT - BATTLESTRINGS_TABLE_START] = sText_AarghAlmostHadIt,
    [STRINGID_SHOOTSOCLOSE - BATTLESTRINGS_TABLE_START] = sText_ShootSoClose,
    [STRINGID_GOTCHAPKMNCAUGHT - BATTLESTRINGS_TABLE_START] = sText_GotchaPkmnCaught,
    [STRINGID_GOTCHAPKMNCAUGHT2 - BATTLESTRINGS_TABLE_START] = sText_GotchaPkmnCaught2,
    [STRINGID_GIVENICKNAMECAPTURED - BATTLESTRINGS_TABLE_START] = sText_GiveNicknameCaptured,
    [STRINGID_PKMNSENTTOPC - BATTLESTRINGS_TABLE_START] = sText_PkmnSentToPC,
    [STRINGID_PKMNDATAADDEDTODEX - BATTLESTRINGS_TABLE_START] = sText_PkmnDataAddedToDex,
    [STRINGID_ITISRAINING - BATTLESTRINGS_TABLE_START] = sText_ItIsRaining,
    [STRINGID_SANDSTORMISRAGING - BATTLESTRINGS_TABLE_START] = sText_SandstormIsRaging,
    [STRINGID_CANTESCAPE2 - BATTLESTRINGS_TABLE_START] = sText_CantEscape2,
    [STRINGID_PKMNIGNORESASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoresAsleep,
    [STRINGID_PKMNIGNOREDORDERS - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoredOrders,
    [STRINGID_PKMNBEGANTONAP - BATTLESTRINGS_TABLE_START] = sText_PkmnBeganToNap,
    [STRINGID_PKMNLOAFING - BATTLESTRINGS_TABLE_START] = sText_PkmnLoafing,
    [STRINGID_PKMNWONTOBEY - BATTLESTRINGS_TABLE_START] = sText_PkmnWontObey,
    [STRINGID_PKMNTURNEDAWAY - BATTLESTRINGS_TABLE_START] = sText_PkmnTurnedAway,
    [STRINGID_PKMNPRETENDNOTNOTICE - BATTLESTRINGS_TABLE_START] = sText_PkmnPretendNotNotice,
    [STRINGID_ENEMYABOUTTOSWITCHPKMN - BATTLESTRINGS_TABLE_START] = sText_EnemyAboutToSwitchPkmn,
    [STRINGID_CREPTCLOSER - BATTLESTRINGS_TABLE_START] = sText_CreptCloser,
    [STRINGID_CANTGETCLOSER - BATTLESTRINGS_TABLE_START] = sText_CantGetCloser,
    [STRINGID_PKMNWATCHINGCAREFULLY - BATTLESTRINGS_TABLE_START] = sText_PkmnWatchingCarefully,
    [STRINGID_PKMNCURIOUSABOUTX - BATTLESTRINGS_TABLE_START] = sText_PkmnCuriousAboutX,
    [STRINGID_PKMNENTHRALLEDBYX - BATTLESTRINGS_TABLE_START] = sText_PkmnEnthralledByX,
    [STRINGID_PKMNIGNOREDX - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoredX,
    [STRINGID_THREWPOKEBLOCKATPKMN - BATTLESTRINGS_TABLE_START] = sText_ThrewPokeblockAtPkmn,
    [STRINGID_OUTOFSAFARIBALLS - BATTLESTRINGS_TABLE_START] = sText_OutOfSafariBalls,
    [STRINGID_PKMNSITEMCUREDPARALYSIS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredParalysis,
    [STRINGID_PKMNSITEMCUREDPOISON - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredPoison,
    [STRINGID_PKMNSITEMHEALEDBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemHealedBurn,
    [STRINGID_PKMNSITEMDEFROSTEDIT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemDefrostedIt,
    [STRINGID_PKMNSITEMWOKEIT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemWokeIt,
    [STRINGID_PKMNSITEMSNAPPEDOUT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemSnappedOut,
    [STRINGID_PKMNSITEMCUREDPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredProblem,
    [STRINGID_PKMNSITEMRESTOREDHEALTH - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredHealth,
    [STRINGID_PKMNSITEMRESTOREDPP - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredPP,
    [STRINGID_PKMNSITEMRESTOREDSTATUS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredStatus,
    [STRINGID_PKMNSITEMRESTOREDHPALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredHPALittle,
    [STRINGID_ITEMALLOWSONLYYMOVE - BATTLESTRINGS_TABLE_START] = sText_ItemAllowsOnlyYMove,
    [STRINGID_PKMNHUNGONWITHX - BATTLESTRINGS_TABLE_START] = sText_PkmnHungOnWithX,
    [STRINGID_EMPTYSTRING3 - BATTLESTRINGS_TABLE_START] = gText_EmptyString3,
    [STRINGID_PKMNSXPREVENTSBURNS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsBurns,
    [STRINGID_PKMNSXBLOCKSY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXBlocksY,
    [STRINGID_PKMNSXRESTOREDHPALITTLE2 - BATTLESTRINGS_TABLE_START] = sText_PkmnsXRestoredHPALittle2,
    [STRINGID_PKMNSXWHIPPEDUPSANDSTORM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXWhippedUpSandstorm,
    [STRINGID_PKMNSXPREVENTSYLOSS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsYLoss,
    [STRINGID_PKMNSXINFATUATEDY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXInfatuatedY,
    [STRINGID_PKMNSXMADEYINEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeYIneffective,
    [STRINGID_PKMNSXCUREDYPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXCuredYProblem,
    [STRINGID_ITSUCKEDLIQUIDOOZE - BATTLESTRINGS_TABLE_START] = sText_ItSuckedLiquidOoze,
    [STRINGID_PKMNTRANSFORMED - BATTLESTRINGS_TABLE_START] = sText_PkmnTransformed,
    [STRINGID_ELECTRICITYWEAKENED - BATTLESTRINGS_TABLE_START] = sText_ElectricityWeakened,
    [STRINGID_FIREWEAKENED - BATTLESTRINGS_TABLE_START] = sText_FireWeakened,
    [STRINGID_PKMNHIDUNDERWATER - BATTLESTRINGS_TABLE_START] = sText_PkmnHidUnderwater,
    [STRINGID_PKMNSPRANGUP - BATTLESTRINGS_TABLE_START] = sText_PkmnSprangUp,
    [STRINGID_HMMOVESCANTBEFORGOTTEN - BATTLESTRINGS_TABLE_START] = sText_HMMovesCantBeForgotten,
    [STRINGID_XFOUNDONEY - BATTLESTRINGS_TABLE_START] = sText_XFoundOneY,
    [STRINGID_PLAYERDEFEATEDTRAINER1 - BATTLESTRINGS_TABLE_START] = sText_PlayerDefeatedLinkTrainerTrainer1,
    [STRINGID_SOOTHINGAROMA - BATTLESTRINGS_TABLE_START] = sText_SoothingAroma,
    [STRINGID_ITEMSCANTBEUSEDNOW - BATTLESTRINGS_TABLE_START] = sText_ItemsCantBeUsedNow,
    [STRINGID_FORXCOMMAYZ - BATTLESTRINGS_TABLE_START] = sText_ForXCommaYZ,
    [STRINGID_USINGITEMSTATOFPKMNROSE - BATTLESTRINGS_TABLE_START] = sText_UsingItemTheStatOfPkmnRose,
    [STRINGID_PKMNUSEDXTOGETPUMPED - BATTLESTRINGS_TABLE_START] = sText_PkmnUsedXToGetPumped,
    [STRINGID_PKMNSXMADEYUSELESS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeYUseless,
    [STRINGID_PKMNTRAPPEDBYSANDTOMB - BATTLESTRINGS_TABLE_START] = sText_PkmnTrappedBySandTomb,
    [STRINGID_EMPTYSTRING4 - BATTLESTRINGS_TABLE_START] = sText_EmptyString4,
    [STRINGID_ABOOSTED - BATTLESTRINGS_TABLE_START] = sText_ABoosted,
    [STRINGID_PKMNSXINTENSIFIEDSUN - BATTLESTRINGS_TABLE_START] = sText_PkmnsXIntensifiedSun,
    [STRINGID_PKMNMAKESGROUNDMISS - BATTLESTRINGS_TABLE_START] = sText_PkmnMakesGroundMiss,
    [STRINGID_YOUTHROWABALLNOWRIGHT - BATTLESTRINGS_TABLE_START] = sText_YouThrowABallNowRight,
    [STRINGID_PKMNSXTOOKATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnsXTookAttack,
    [STRINGID_PKMNCHOSEXASDESTINY - BATTLESTRINGS_TABLE_START] = sText_PkmnChoseXAsDestiny,
    [STRINGID_PKMNLOSTFOCUS - BATTLESTRINGS_TABLE_START] = sText_PkmnLostFocus,
    [STRINGID_USENEXTPKMN - BATTLESTRINGS_TABLE_START] = sText_UseNextPkmn,
    [STRINGID_PKMNFLEDUSINGITS - BATTLESTRINGS_TABLE_START] = sText_PkmnFledUsingIts,
    [STRINGID_PKMNFLEDUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnFledUsing,
    [STRINGID_PKMNWASDRAGGEDOUT - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDraggedOut,
    [STRINGID_PREVENTEDFROMWORKING - BATTLESTRINGS_TABLE_START] = sText_PreventedFromWorking,
    [STRINGID_PKMNSITEMNORMALIZEDSTATUS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemNormalizedStatus,
    [STRINGID_TRAINER1USEDITEM - BATTLESTRINGS_TABLE_START] = sText_Trainer1UsedItem,
    [STRINGID_BOXISFULL - BATTLESTRINGS_TABLE_START] = sText_BoxIsFull,
    [STRINGID_PKMNAVOIDEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnAvoidedAttack,
    [STRINGID_PKMNSXMADEITINEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeItIneffective,
    [STRINGID_PKMNSXPREVENTSFLINCHING - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsFlinching,
    [STRINGID_PKMNALREADYHASBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyHasBurn,
    [STRINGID_STATSWONTDECREASE2 - BATTLESTRINGS_TABLE_START] = sText_StatsWontDecrease2,
    [STRINGID_PKMNSXBLOCKSY2 - BATTLESTRINGS_TABLE_START] = sText_PkmnsXBlocksY2,
    [STRINGID_PKMNSXWOREOFF - BATTLESTRINGS_TABLE_START] = sText_PkmnsXWoreOff,
    [STRINGID_PKMNRAISEDDEFALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedDefALittle,
    [STRINGID_PKMNRAISEDSPDEFALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpDefALittle,
    [STRINGID_THEWALLSHATTERED - BATTLESTRINGS_TABLE_START] = sText_TheWallShattered,
    [STRINGID_PKMNSXPREVENTSYSZ - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsYsZ,
    [STRINGID_PKMNSXCUREDITSYPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXCuredItsYProblem,
    [STRINGID_ATTACKERCANTESCAPE - BATTLESTRINGS_TABLE_START] = sText_AttackerCantEscape,
    [STRINGID_PKMNOBTAINEDX - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedX,
    [STRINGID_PKMNOBTAINEDX2 - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedX2,
    [STRINGID_PKMNOBTAINEDXYOBTAINEDZ - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedXYObtainedZ,
    [STRINGID_BUTNOEFFECT - BATTLESTRINGS_TABLE_START] = sText_ButNoEffect,
    [STRINGID_PKMNSXHADNOEFFECTONY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXHadNoEffectOnY,
    [STRINGID_TWOENEMIESDEFEATED - BATTLESTRINGS_TABLE_START] = sText_TwoInGameTrainersDefeated,
    [STRINGID_TRAINER2LOSETEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer2LoseText,
    [STRINGID_PKMNINCAPABLEOFPOWER - BATTLESTRINGS_TABLE_START] = sText_PkmnIncapableOfPower,
    [STRINGID_GLINTAPPEARSINEYE - BATTLESTRINGS_TABLE_START] = sText_GlintAppearsInEye,
    [STRINGID_PKMNGETTINGINTOPOSITION - BATTLESTRINGS_TABLE_START] = sText_PkmnGettingIntoPosition,
    [STRINGID_PKMNBEGANGROWLINGDEEPLY - BATTLESTRINGS_TABLE_START] = sText_PkmnBeganGrowlingDeeply,
    [STRINGID_PKMNEAGERFORMORE - BATTLESTRINGS_TABLE_START] = sText_PkmnEagerForMore,
    [STRINGID_DEFEATEDOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_DefeatedOpponentByReferee,
    [STRINGID_LOSTTOOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_LostToOpponentByReferee,
    [STRINGID_TIEDOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_TiedOpponentByReferee,
    [STRINGID_QUESTIONFORFEITMATCH - BATTLESTRINGS_TABLE_START] = sText_QuestionForfeitMatch,
    [STRINGID_FORFEITEDMATCH - BATTLESTRINGS_TABLE_START] = sText_ForfeitedMatch,
    [STRINGID_PKMNTRANSFERREDSOMEONESPC - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredSomeonesPC,
    [STRINGID_PKMNTRANSFERREDLANETTESPC - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredLanettesPC,
    [STRINGID_PKMNBOXSOMEONESPCFULL - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredSomeonesPCBoxFull,
    [STRINGID_PKMNBOXLANETTESPCFULL - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredLanettesPCBoxFull,
    [STRINGID_TRAINER1WINTEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer1WinText,
    [STRINGID_TRAINER2WINTEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer2WinText,
    [STRINGID_ENDUREDSTURDY - BATTLESTRINGS_TABLE_START] = sText_EnduredViaSturdy,
    [STRINGID_POWERHERB - BATTLESTRINGS_TABLE_START] = sText_PowerHerbActivation,
    [STRINGID_HURTBYITEM - BATTLESTRINGS_TABLE_START] = sText_HurtByItem,
    [STRINGID_PSNBYITEM - BATTLESTRINGS_TABLE_START] = sText_BadlyPoisonedByItem,
    [STRINGID_BRNBYITEM - BATTLESTRINGS_TABLE_START] = sText_BurnedByItem,
    [STRINGID_DEFABILITYIN - BATTLESTRINGS_TABLE_START] = sText_TargetAbilityActivates,
    [STRINGID_GRAVITYINTENSIFIED - BATTLESTRINGS_TABLE_START] = sText_GravityIntensified,
    [STRINGID_TARGETIDENTIFIED - BATTLESTRINGS_TABLE_START] = sText_TargetIdentified,
    [STRINGID_TARGETWOKEUP - BATTLESTRINGS_TABLE_START] = sText_TargetWokeUp,
    [STRINGID_PKMNSTOLEANDATEITEM - BATTLESTRINGS_TABLE_START] = sText_PkmnStoleAndAteItem,
    [STRINGID_TAILWINDBLEW - BATTLESTRINGS_TABLE_START] = sText_TailWindBlew,
    [STRINGID_PKMNWENTBACK - BATTLESTRINGS_TABLE_START] = sText_PkmnWentBack,
    [STRINGID_PKMNCANTUSEITEMSANYMORE - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseItemsAnymore,
    [STRINGID_PKMNFLUNG - BATTLESTRINGS_TABLE_START] = sText_PkmnFlung,
    [STRINGID_PKMNPREVENTEDFROMHEALING - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventedFromHealing,
    [STRINGID_PKMNSWITCHEDATKANDDEF - BATTLESTRINGS_TABLE_START] = sText_PkmnSwitchedAtkAndDef,
    [STRINGID_PKMNSABILITYSUPPRESSED - BATTLESTRINGS_TABLE_START] = sText_PkmnsAbilitySuppressed,
    [STRINGID_SHIELDEDFROMCRITICALHITS - BATTLESTRINGS_TABLE_START] = sText_ShieldedFromCriticalHits,
    [STRINGID_SWITCHEDATKANDSPATK - BATTLESTRINGS_TABLE_START] = sText_SwitchedAtkAndSpAtk,
    [STRINGID_SWITCHEDDEFANDSPDEF - BATTLESTRINGS_TABLE_START] = sText_SwitchedDefAndSpDef,
    [STRINGID_PKMNACQUIREDABILITY - BATTLESTRINGS_TABLE_START] = sText_PkmnAcquiredAbility,
    [STRINGID_POISONSPIKESSCATTERED - BATTLESTRINGS_TABLE_START] = sText_PoisonSpikesScattered,
    [STRINGID_PKMNSWITCHEDSTATCHANGES - BATTLESTRINGS_TABLE_START] = sText_PkmnSwitchedStatChanges,
    [STRINGID_PKMNSURROUNDEDWITHVEILOFWATER - BATTLESTRINGS_TABLE_START] = sText_PkmnSurroundedWithVeilOfWater,
    [STRINGID_PKMNLEVITATEDONELECTROMAGNETISM - BATTLESTRINGS_TABLE_START] = sText_PkmnLevitatedOnElectromagnetism,
    [STRINGID_PKMNTWISTEDDIMENSIONS - BATTLESTRINGS_TABLE_START] = sText_PkmnTwistedDimensions,
    [STRINGID_POINTEDSTONESFLOAT - BATTLESTRINGS_TABLE_START] = sText_PointedStonesFloat,
    [STRINGID_CLOAKEDINMYSTICALMOONLIGHT - BATTLESTRINGS_TABLE_START] = sText_CloakedInMysticalMoonlight,
    [STRINGID_TRAPPEDBYSWIRLINGMAGMA - BATTLESTRINGS_TABLE_START] = sText_TrappedBySwirlingMagma,
    [STRINGID_VANISHEDINSTANTLY - BATTLESTRINGS_TABLE_START] = sText_VanishedInstantly,
    [STRINGID_PROTECTEDTEAM - BATTLESTRINGS_TABLE_START] = sText_ProtectedTeam,
    [STRINGID_SHAREDITSGUARD - BATTLESTRINGS_TABLE_START] = sText_SharedItsGuard,
    [STRINGID_SHAREDITSPOWER - BATTLESTRINGS_TABLE_START] = sText_SharedItsPower,
    [STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON - BATTLESTRINGS_TABLE_START] = sText_SwapsDefAndSpDefOfAllPkmn,
    [STRINGID_BECAMENIMBLE - BATTLESTRINGS_TABLE_START] = sText_BecameNimble,
    [STRINGID_HURLEDINTOTHEAIR - BATTLESTRINGS_TABLE_START] = sText_HurledIntoTheAir,
    [STRINGID_HELDITEMSLOSEEFFECTS - BATTLESTRINGS_TABLE_START] = sText_HeldItemsLoseEffects,
    [STRINGID_FELLSTRAIGHTDOWN - BATTLESTRINGS_TABLE_START] = sText_FellStraightDown,
    [STRINGID_TARGETCHANGEDTYPE  - BATTLESTRINGS_TABLE_START] = sText_TargetChangedType,
    [STRINGID_PKMNACQUIREDSIMPLE - BATTLESTRINGS_TABLE_START] = sText_PkmnAcquiredSimple,
    [STRINGID_EMPTYSTRING5 - BATTLESTRINGS_TABLE_START] = sText_EmptyString4,
    [STRINGID_KINDOFFER - BATTLESTRINGS_TABLE_START] = sText_KindOffer,
    [STRINGID_RESETSTARGETSSTATLEVELS - BATTLESTRINGS_TABLE_START] = sText_ResetsTargetsStatLevels,
    [STRINGID_EMPTYSTRING6 - BATTLESTRINGS_TABLE_START] = sText_EmptyString4,
    [STRINGID_ALLYSWITCHPOSITION - BATTLESTRINGS_TABLE_START] = sText_AllySwitchPosition,
    [STRINGID_RESTORETARGETSHEALTH - BATTLESTRINGS_TABLE_START] = sText_RestoreTargetsHealth,
    [STRINGID_TOOKPJMNINTOTHESKY - BATTLESTRINGS_TABLE_START] = sText_TookPkmnIntoTheSky,
    [STRINGID_FREEDFROMSKYDROP - BATTLESTRINGS_TABLE_START] = sText_FreedFromSkyDrop,
    [STRINGID_POSTPONETARGETMOVE - BATTLESTRINGS_TABLE_START] = sText_PostponeTargetMove,
    [STRINGID_REFLECTTARGETSTYPE - BATTLESTRINGS_TABLE_START] = sText_ReflectTargetsType,
    [STRINGID_TRANSFERHELDITEM - BATTLESTRINGS_TABLE_START] = sText_TransferHeldItem,
    [STRINGID_EMBARGOENDS - BATTLESTRINGS_TABLE_START] = sText_EmbargoEnds,
    [STRINGID_ELECTROMAGNETISM - BATTLESTRINGS_TABLE_START] = sText_Electromagnetism,
    [STRINGID_BUFFERENDS - BATTLESTRINGS_TABLE_START] = sText_BufferEnds,
    [STRINGID_TELEKINESISENDS - BATTLESTRINGS_TABLE_START] = sText_TelekinesisEnds,
    [STRINGID_TAILWINDENDS - BATTLESTRINGS_TABLE_START] = sText_TailwindEnds,
    [STRINGID_LUCKYCHANTENDS - BATTLESTRINGS_TABLE_START] = sText_LuckyChantEnds,
    [STRINGID_TRICKROOMENDS - BATTLESTRINGS_TABLE_START] = sText_TrickRoomEnds,
    [STRINGID_WONDERROOMENDS - BATTLESTRINGS_TABLE_START] = sText_WonderRoomEnds,
    [STRINGID_MAGICROOMENDS - BATTLESTRINGS_TABLE_START] = sText_MagicRoomEnds,
    [STRINGID_MUDSPORTENDS - BATTLESTRINGS_TABLE_START] = sText_MudSportEnds,
    [STRINGID_WATERSPORTENDS - BATTLESTRINGS_TABLE_START] = sText_WaterSportEnds,
    [STRINGID_GRAVITYENDS - BATTLESTRINGS_TABLE_START] = sText_GravityEnds,
    [STRINGID_AQUARINGHEAL - BATTLESTRINGS_TABLE_START] = sText_AquaRingHeal,
    [STRINGID_AURORAVEILENDS - BATTLESTRINGS_TABLE_START] = sText_AuroraVeilEnds,
    [STRINGID_ELECTRICTERRAINENDS - BATTLESTRINGS_TABLE_START] = sText_ElectricTerrainEnds,
    [STRINGID_MISTYTERRAINENDS - BATTLESTRINGS_TABLE_START] = sText_MistyTerrainEnds,
    [STRINGID_PSYCHICTERRAINENDS - BATTLESTRINGS_TABLE_START] = sText_PsychicTerrainEnds,
    [STRINGID_GRASSYTERRAINENDS - BATTLESTRINGS_TABLE_START] = sText_GrassyTerrainEnds,
    [STRINGID_TARGETABILITYSTATRAISE - BATTLESTRINGS_TABLE_START] = sText_TargetAbilityRaisedStat,
    [STRINGID_TARGETSSTATWASMAXEDOUT - BATTLESTRINGS_TABLE_START] = sText_TargetsStatWasMaxedOut,
    [STRINGID_ATTACKERABILITYSTATRAISE - BATTLESTRINGS_TABLE_START] = sText_AttackerAbilityRaisedStat,
    [STRINGID_POISONHEALHPUP - BATTLESTRINGS_TABLE_START] = sText_PoisonHealHpUp,
    [STRINGID_BADDREAMSDMG - BATTLESTRINGS_TABLE_START] = sText_BadDreamsDmg,
    [STRINGID_MOLDBREAKERENTERS - BATTLESTRINGS_TABLE_START] = sText_MoldBreakerEnters,
    [STRINGID_TERAVOLTENTERS - BATTLESTRINGS_TABLE_START] = sText_TeravoltEnters,
    [STRINGID_TURBOBLAZEENTERS - BATTLESTRINGS_TABLE_START] = sText_TurboblazeEnters,
    [STRINGID_SLOWSTARTENTERS - BATTLESTRINGS_TABLE_START] = sText_SlowStartEnters,
    [STRINGID_SLOWSTARTEND - BATTLESTRINGS_TABLE_START] = sText_SlowStartEnd,
    [STRINGID_SOLARPOWERHPDROP - BATTLESTRINGS_TABLE_START] = sText_SolarPowerHpDrop,
    [STRINGID_AFTERMATHDMG - BATTLESTRINGS_TABLE_START] = sText_AftermathDmg,
    [STRINGID_ANTICIPATIONACTIVATES - BATTLESTRINGS_TABLE_START] = sText_AnticipationActivates,
    [STRINGID_FOREWARNACTIVATES - BATTLESTRINGS_TABLE_START] = sText_ForewarnActivates,
    [STRINGID_ICEBODYHPGAIN - BATTLESTRINGS_TABLE_START] = sText_IceBodyHpGain,
    [STRINGID_SNOWWARNINGHAIL - BATTLESTRINGS_TABLE_START] = sText_SnowWarningHail,
    [STRINGID_FRISKACTIVATES - BATTLESTRINGS_TABLE_START] = sText_FriskActivates,
    [STRINGID_UNNERVEENTERS - BATTLESTRINGS_TABLE_START] = sText_UnnerveEnters,
    [STRINGID_HARVESTBERRY - BATTLESTRINGS_TABLE_START] = sText_HarvestBerry,
    [STRINGID_LASTABILITYRAISEDSTAT - BATTLESTRINGS_TABLE_START] = sText_LastAbilityRaisedBuff1,
    [STRINGID_MAGICBOUNCEACTIVATES - BATTLESTRINGS_TABLE_START] = sText_MagicBounceActivates,
    [STRINGID_PROTEANTYPECHANGE - BATTLESTRINGS_TABLE_START] = sText_ProteanTypeChange,
    [STRINGID_SYMBIOSISITEMPASS - BATTLESTRINGS_TABLE_START] = sText_SymbiosisItemPass,
    [STRINGID_STEALTHROCKDMG - BATTLESTRINGS_TABLE_START] = sText_StealthRockDmg,
    [STRINGID_TOXICSPIKESABSORBED - BATTLESTRINGS_TABLE_START] = sText_ToxicSpikesAbsorbed,
    [STRINGID_TOXICSPIKESPOISONED - BATTLESTRINGS_TABLE_START] = sText_ToxicSpikesPoisoned,
    [STRINGID_STICKYWEBSWITCHIN - BATTLESTRINGS_TABLE_START] = sText_StickyWebSwitchIn,
    [STRINGID_HEALINGWISHCAMETRUE - BATTLESTRINGS_TABLE_START] = sText_HealingWishCameTrue,
    [STRINGID_HEALINGWISHHEALED - BATTLESTRINGS_TABLE_START] = sText_HealingWishHealed,
    [STRINGID_LUNARDANCECAMETRUE - BATTLESTRINGS_TABLE_START] = sText_LunarDanceCameTrue,
    [STRINGID_CUSEDBODYDISABLED - BATTLESTRINGS_TABLE_START] = sText_CursedBodyDisabled,
    [STRINGID_ATTACKERACQUIREDABILITY - BATTLESTRINGS_TABLE_START] = sText_AttackerAquiredAbility,
    [STRINGID_TARGETABILITYSTATLOWER - BATTLESTRINGS_TABLE_START] = sText_TargetAbilityLoweredStat,
    [STRINGID_TARGETSTATWONTGOHIGHER - BATTLESTRINGS_TABLE_START] = sText_TargetStatWontGoHigher,
    [STRINGID_PKMNMOVEBOUNCEDABILITY - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveBouncedViaAbility,
    [STRINGID_IMPOSTERTRANSFORM - BATTLESTRINGS_TABLE_START] = sText_ImposterTransform,
    [STRINGID_ASSAULTVESTDOESNTALLOW - BATTLESTRINGS_TABLE_START] = sText_AssaultVestDoesntAllow,
    [STRINGID_GRAVITYPREVENTSUSAGE - BATTLESTRINGS_TABLE_START] = sText_GravityPreventsUsage,
    [STRINGID_HEALBLOCKPREVENTSUSAGE - BATTLESTRINGS_TABLE_START] = sText_HealBlockPreventsUsage,
    [STRINGID_NOTDONEYET - BATTLESTRINGS_TABLE_START] = sText_NotDoneYet,
    [STRINGID_STICKYWEBUSED - BATTLESTRINGS_TABLE_START] = sText_StickyWebUsed,
    [STRINGID_QUASHSUCCESS - BATTLESTRINGS_TABLE_START] = sText_QuashSuccess,
    [STRINGID_PKMNBLEWAWAYTOXICSPIKES - BATTLESTRINGS_TABLE_START] = sText_PkmnBlewAwayToxicSpikes,
    [STRINGID_PKMNBLEWAWAYSTICKYWEB - BATTLESTRINGS_TABLE_START] = sText_PkmnBlewAwayStickyWeb,
    [STRINGID_PKMNBLEWAWAYSTEALTHROCK - BATTLESTRINGS_TABLE_START] = sText_PkmnBlewAwayStealthRock,
    [STRINGID_IONDELUGEON - BATTLESTRINGS_TABLE_START] = sText_IonDelugeOn,
    [STRINGID_TOPSYTURVYSWITCHEDSTATS - BATTLESTRINGS_TABLE_START] = sText_TopsyTurvySwitchedStats,
    [STRINGID_TERRAINBECOMESMISTY - BATTLESTRINGS_TABLE_START] = sText_TerrainBecomesMisty,
    [STRINGID_TERRAINBECOMESGRASSY - BATTLESTRINGS_TABLE_START] = sText_TerrainBecomesGrassy,
    [STRINGID_TERRAINBECOMESELECTRIC - BATTLESTRINGS_TABLE_START] = sText_TerrainBecomesElectric,
    [STRINGID_TERRAINBECOMESPSYCHIC - BATTLESTRINGS_TABLE_START] = sText_TerrainBecomesPsychic,
    [STRINGID_TARGETELECTRIFIED - BATTLESTRINGS_TABLE_START] = sText_TargetElectrified,
    [STRINGID_MEGAEVOREACTING - BATTLESTRINGS_TABLE_START] = sText_MegaEvoReacting,
    [STRINGID_FERVENTWISHREACHED - BATTLESTRINGS_TABLE_START] = sText_FerventWishReached,
    [STRINGID_MEGAEVOEVOLVED - BATTLESTRINGS_TABLE_START] = sText_MegaEvoEvolved,
    [STRINGID_DRASTICALLY - BATTLESTRINGS_TABLE_START] = sText_drastically,
    [STRINGID_SEVERELY - BATTLESTRINGS_TABLE_START] = sText_severely,
    [STRINGID_INFESTATION - BATTLESTRINGS_TABLE_START] = sText_Infestation,
    [STRINGID_NOEFFECTONTARGET - BATTLESTRINGS_TABLE_START] = sText_NoEffectOnTarget,
    [STRINGID_BURSTINGFLAMESHIT - BATTLESTRINGS_TABLE_START] = sText_BurstingFlames,
    [STRINGID_BESTOWITEMGIVING - BATTLESTRINGS_TABLE_START] = sText_BestowItemGiving,
    [STRINGID_THIRDTYPEADDED - BATTLESTRINGS_TABLE_START] = sText_ThirdTypeAdded,
    [STRINGID_FELLFORFEINT - BATTLESTRINGS_TABLE_START] = sText_FellForFeint,
    [STRINGID_POKEMONCANNOTUSEMOVE - BATTLESTRINGS_TABLE_START] = sText_PokemonCannotUseMove,
    [STRINGID_COVEREDINPOWDER - BATTLESTRINGS_TABLE_START] = sText_CoveredInPowder,
    [STRINGID_POWDEREXPLODES - BATTLESTRINGS_TABLE_START] = sText_PowderExplodes,
    [STRINGID_GRAVITYGROUNDING - BATTLESTRINGS_TABLE_START] = sText_GravityGrounding,
    [STRINGID_MISTYTERRAINPREVENTS - BATTLESTRINGS_TABLE_START] = sText_MistyTerrainPreventsStatus,
    [STRINGID_GRASSYTERRAINHEALS - BATTLESTRINGS_TABLE_START] = sText_GrassyTerrainHeals,
    [STRINGID_ELECTRICTERRAINPREVENTS - BATTLESTRINGS_TABLE_START] = sText_ElectricTerrainPreventsSleep,
    [STRINGID_PSYCHICTERRAINPREVENTS - BATTLESTRINGS_TABLE_START] = sText_PsychicTerrainPreventsPriority,
    [STRINGID_AURAFLAREDTOLIFE - BATTLESTRINGS_TABLE_START] = sText_AuraFlaredToLife,
    [STRINGID_AIRLOCKACTIVATES - BATTLESTRINGS_TABLE_START] = sText_AirLockActivates,
    [STRINGID_PRESSUREENTERS - BATTLESTRINGS_TABLE_START] = sText_PressureActivates,
    [STRINGID_DARKAURAENTERS - BATTLESTRINGS_TABLE_START] = sText_DarkAuraActivates,
    [STRINGID_FAIRYAURAENTERS - BATTLESTRINGS_TABLE_START] = sText_FairyAuraActivates,
    [STRINGID_AURABREAKENTERS - BATTLESTRINGS_TABLE_START] = sText_AuraBreakActivates,
    [STRINGID_COMATOSEENTERS - BATTLESTRINGS_TABLE_START] = sText_ComatoseActivates,
    [STRINGID_SCREENCLEANERENTERS - BATTLESTRINGS_TABLE_START] = sText_ScreenCleanerActivates,
    [STRINGID_BOTHCANNOLONGERESCAPE - BATTLESTRINGS_TABLE_START] = sText_BothCanNoLongerEscape,
    [STRINGID_CANTESCAPEDUETOUSEDMOVE - BATTLESTRINGS_TABLE_START] = sText_CantEscapeDueToUsedMove,
    [STRINGID_PKMNBECAMEWEAKERTOFIRE - BATTLESTRINGS_TABLE_START] = sText_PkmnBecameWeakerToFire,
    [STRINGID_ABOUTTOUSEPOLTERGEIST - BATTLESTRINGS_TABLE_START] = sText_PkmnAboutToBeAttackedByItsItem,
    [STRINGID_CANTESCAPEBECAUSEOFCURRENTMOVE - BATTLESTRINGS_TABLE_START] = sText_CantEscapeBecauseOfCurrentMove,
    [STRINGID_PKMNTOOKTARGETHIGH - BATTLESTRINGS_TABLE_START] = sText_PkmnTookTargetHigh,
    [STRINGID_TARGETTOOHEAVY - BATTLESTRINGS_TABLE_START] = sText_TargetTooHeavy,
};

const u16 gZEffectStringIds[] = 
{
    [B_MSG_Z_RESET_STATS] = STRINGID_ZMOVERESETSSTATS,
    [B_MSG_Z_ALL_STATS_UP]= STRINGID_ZMOVEALLSTATSUP,
    [B_MSG_Z_BOOST_CRITS] = STRINGID_ZMOVEZBOOSTCRIT,
    [B_MSG_Z_FOLLOW_ME]   = STRINGID_PKMNCENTERATTENTION,
    [B_MSG_Z_RECOVER_HP]  = STRINGID_ZMOVERESTOREHP,
    [B_MSG_Z_STAT_UP]     = STRINGID_ZMOVESTATUP,
    [B_MSG_Z_HP_TRAP]     = STRINGID_ZMOVEHPTRAP,
};

const u16 gMentalHerbCureStringIds[] = 
{
    [B_MSG_MENTALHERBCURE_INFATUATION] = STRINGID_ATKGOTOVERINFATUATION,
    [B_MSG_MENTALHERBCURE_TAUNT]       = STRINGID_BUFFERENDS,
    [B_MSG_MENTALHERBCURE_ENCORE]      = STRINGID_PKMNENCOREENDED,
    [B_MSG_MENTALHERBCURE_TORMENT]     = STRINGID_TORMENTEDNOMORE,
    [B_MSG_MENTALHERBCURE_HEALBLOCK]   = STRINGID_HEALBLOCKEDNOMORE,
    [B_MSG_MENTALHERBCURE_DISABLE]     = STRINGID_PKMNMOVEDISABLEDNOMORE,
};

const u16 gTerrainStringIds[] =
{
    STRINGID_TERRAINBECOMESMISTY, STRINGID_TERRAINBECOMESGRASSY, STRINGID_TERRAINBECOMESELECTRIC, STRINGID_TERRAINBECOMESPSYCHIC, STRINGID_TERRAINREMOVED,
};

const u16 gTerrainEndingStringIds[] = 
{
    STRINGID_MISTYTERRAINENDS, STRINGID_GRASSYTERRAINENDS, STRINGID_ELECTRICTERRAINENDS, STRINGID_PSYCHICTERRAINENDS
};

const u16 gTerrainPreventsStringIds[] =
{
    [B_MSG_TERRAINPREVENTS_MISTY]    = STRINGID_MISTYTERRAINPREVENTS,
    [B_MSG_TERRAINPREVENTS_ELECTRIC] = STRINGID_ELECTRICTERRAINPREVENTS,
    [B_MSG_TERRAINPREVENTS_PSYCHIC]  = STRINGID_PSYCHICTERRAINPREVENTS
};

const u16 gMagicCoatBounceStringIds[] =
{
    STRINGID_PKMNMOVEBOUNCED, STRINGID_PKMNMOVEBOUNCEDABILITY
};

const u16 gHealingWishStringIds[] =
{
    STRINGID_HEALINGWISHCAMETRUE, STRINGID_LUNARDANCECAMETRUE
};

const u16 gDmgHazardsStringIds[] =
{
    STRINGID_PKMNHURTBYSPIKES, STRINGID_STEALTHROCKDMG
};

const u16 gSwitchInAbilityStringIds[] =
{
    [B_MSG_SWITCHIN_MOLDBREAKER] = STRINGID_MOLDBREAKERENTERS,
    [B_MSG_SWITCHIN_TERAVOLT] = STRINGID_TERAVOLTENTERS,
    [B_MSG_SWITCHIN_TURBOBLAZE] = STRINGID_TURBOBLAZEENTERS,
    [B_MSG_SWITCHIN_SLOWSTART] = STRINGID_SLOWSTARTENTERS,
    [B_MSG_SWITCHIN_UNNERVE] = STRINGID_UNNERVEENTERS,
    [B_MSG_SWITCHIN_ANTICIPATION] = STRINGID_ANTICIPATIONACTIVATES,
    [B_MSG_SWITCHIN_FOREWARN] = STRINGID_FOREWARNACTIVATES,
    [B_MSG_SWITCHIN_PRESSURE] = STRINGID_PRESSUREENTERS,
    [B_MSG_SWITCHIN_DARKAURA] = STRINGID_DARKAURAENTERS,
    [B_MSG_SWITCHIN_FAIRYAURA] = STRINGID_FAIRYAURAENTERS,
    [B_MSG_SWITCHIN_AURABREAK] = STRINGID_AURABREAKENTERS,
    [B_MSG_SWITCHIN_COMATOSE] = STRINGID_COMATOSEENTERS,
    [B_MSG_SWITCHIN_SCREENCLEANER] = STRINGID_SCREENCLEANERENTERS,
    [B_MSG_SWITCHIN_ASONE] = STRINGID_ASONEENTERS,
    [B_MSG_SWITCHIN_CURIOUS_MEDICINE] = STRINGID_CURIOUSMEDICINEENTERS,
    [B_MSG_SWITCHIN_PASTEL_VEIL] = STRINGID_PASTELVEILENTERS,
    [B_MSG_SWITCHIN_NEUTRALIZING_GAS] = STRINGID_NEUTRALIZINGGASENTERS,
};

const u16 gMissStringIds[] =
{
    [B_MSG_MISSED]      = STRINGID_ATTACKMISSED,
    [B_MSG_PROTECTED]   = STRINGID_PKMNPROTECTEDITSELF,
    [B_MSG_AVOIDED_ATK] = STRINGID_PKMNAVOIDEDATTACK,
    [B_MSG_AVOIDED_DMG] = STRINGID_AVOIDEDDAMAGE,
    [B_MSG_GROUND_MISS] = STRINGID_PKMNMAKESGROUNDMISS
};

const u16 gNoEscapeStringIds[] =
{
    [B_MSG_CANT_ESCAPE]          = STRINGID_CANTESCAPE,
    [B_MSG_DONT_LEAVE_BIRCH]     = STRINGID_DONTLEAVEBIRCH,
    [B_MSG_PREVENTS_ESCAPE]      = STRINGID_PREVENTSESCAPE,
    [B_MSG_CANT_ESCAPE_2]        = STRINGID_CANTESCAPE2,
    [B_MSG_ATTACKER_CANT_ESCAPE] = STRINGID_ATTACKERCANTESCAPE
};

const u16 gMoveWeatherChangeStringIds[] =
{
    [B_MSG_STARTED_RAIN]      = STRINGID_STARTEDTORAIN,
    [B_MSG_STARTED_DOWNPOUR]  = STRINGID_DOWNPOURSTARTED, // Unused
    [B_MSG_WEATHER_FAILED]    = STRINGID_BUTITFAILED,
    [B_MSG_STARTED_SANDSTORM] = STRINGID_SANDSTORMBREWED,
    [B_MSG_STARTED_SUNLIGHT]  = STRINGID_SUNLIGHTGOTBRIGHT,
    [B_MSG_STARTED_HAIL]      = STRINGID_STARTEDHAIL,
};

const u16 gSandStormHailContinuesStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_SANDSTORMRAGES,
    [B_MSG_HAIL]      = STRINGID_HAILCONTINUES
};

const u16 gSandStormHailDmgStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_PKMNBUFFETEDBYSANDSTORM,
    [B_MSG_HAIL]      = STRINGID_PKMNPELTEDBYHAIL
};

const u16 gSandStormHailEndStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_SANDSTORMSUBSIDED,
    [B_MSG_HAIL]      = STRINGID_HAILSTOPPED
};

const u16 gRainContinuesStringIds[] =
{
    [B_MSG_RAIN_CONTINUES]     = STRINGID_RAINCONTINUES,
    [B_MSG_DOWNPOUR_CONTINUES] = STRINGID_DOWNPOURCONTINUES,
    [B_MSG_RAIN_STOPPED]       = STRINGID_RAINSTOPPED
};

const u16 gProtectLikeUsedStringIds[] =
{
    [B_MSG_PROTECTED_ITSELF] = STRINGID_PKMNPROTECTEDITSELF2,
    [B_MSG_BRACED_ITSELF]    = STRINGID_PKMNBRACEDITSELF,
    [B_MSG_PROTECT_FAILED]   = STRINGID_BUTITFAILED,
    [B_MSG_PROTECTED_TEAM]   = STRINGID_PROTECTEDTEAM,
};

const u16 gReflectLightScreenSafeguardStringIds[] =
{
    [B_MSG_SIDE_STATUS_FAILED]     = STRINGID_BUTITFAILED,
    [B_MSG_SET_REFLECT_SINGLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_REFLECT_DOUBLE]     = STRINGID_PKMNRAISEDDEFALITTLE,
    [B_MSG_SET_LIGHTSCREEN_SINGLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_LIGHTSCREEN_DOUBLE] = STRINGID_PKMNRAISEDSPDEFALITTLE,
    [B_MSG_SET_SAFEGUARD]          = STRINGID_PKMNCOVEREDBYVEIL,
};

const u16 gLeechSeedStringIds[] =
{
    [B_MSG_LEECH_SEED_SET]   = STRINGID_PKMNSEEDED,
    [B_MSG_LEECH_SEED_MISS]  = STRINGID_PKMNEVADEDATTACK,
    [B_MSG_LEECH_SEED_FAIL]  = STRINGID_ITDOESNTAFFECT,
    [B_MSG_LEECH_SEED_DRAIN] = STRINGID_PKMNSAPPEDBYLEECHSEED,
    [B_MSG_LEECH_SEED_OOZE]  = STRINGID_ITSUCKEDLIQUIDOOZE,
};

const u16 gRestUsedStringIds[] =
{
    [B_MSG_REST]          = STRINGID_PKMNWENTTOSLEEP,
    [B_MSG_REST_STATUSED] = STRINGID_PKMNSLEPTHEALTHY
};

const u16 gUproarOverTurnStringIds[] =
{
    [B_MSG_UPROAR_CONTINUES] = STRINGID_PKMNMAKINGUPROAR,
    [B_MSG_UPROAR_ENDS]      = STRINGID_PKMNCALMEDDOWN
};

const u16 gStockpileUsedStringIds[] =
{
    [B_MSG_STOCKPILED]     = STRINGID_PKMNSTOCKPILED,
    [B_MSG_CANT_STOCKPILE] = STRINGID_PKMNCANTSTOCKPILE,
};

const u16 gWokeUpStringIds[] =
{
    [B_MSG_WOKE_UP]        = STRINGID_PKMNWOKEUP,
    [B_MSG_WOKE_UP_UPROAR] = STRINGID_PKMNWOKEUPINUPROAR
};

const u16 gSwallowFailStringIds[] =
{
    [B_MSG_SWALLOW_FAILED]  = STRINGID_FAILEDTOSWALLOW,
    [B_MSG_SWALLOW_FULL_HP] = STRINGID_PKMNHPFULL
};

const u16 gUproarAwakeStringIds[] =
{
    [B_MSG_CANT_SLEEP_UPROAR]  = STRINGID_PKMNCANTSLEEPINUPROAR2,
    [B_MSG_UPROAR_KEPT_AWAKE]  = STRINGID_UPROARKEPTPKMNAWAKE,
    [B_MSG_STAYED_AWAKE_USING] = STRINGID_PKMNSTAYEDAWAKEUSING,
};

const u16 gStatUpStringIds[] =
{
    [B_MSG_ATTACKER_STAT_ROSE] = STRINGID_ATTACKERSSTATROSE,
    [B_MSG_DEFENDER_STAT_ROSE] = STRINGID_DEFENDERSSTATROSE,
    [B_MSG_STAT_WONT_INCREASE] = STRINGID_STATSWONTINCREASE,
    [B_MSG_STAT_ROSE_EMPTY]    = STRINGID_EMPTYSTRING3,
    [B_MSG_STAT_ROSE_ITEM]     = STRINGID_USINGITEMSTATOFPKMNROSE,
    [B_MSG_USED_DIRE_HIT]     = STRINGID_PKMNUSEDXTOGETPUMPED,
};

const u16 gStatDownStringIds[] =
{
    [B_MSG_ATTACKER_STAT_FELL] = STRINGID_ATTACKERSSTATFELL,
    [B_MSG_DEFENDER_STAT_FELL] = STRINGID_DEFENDERSSTATFELL,
    [B_MSG_STAT_WONT_DECREASE] = STRINGID_STATSWONTDECREASE,
    [B_MSG_STAT_FELL_EMPTY]    = STRINGID_EMPTYSTRING3,
};

// Index read from sTWOTURN_STRINGID
const u16 gFirstTurnOfTwoStringIds[] =
{
    [B_MSG_TURN1_RAZOR_WIND]    = STRINGID_PKMNWHIPPEDWHIRLWIND,
    [B_MSG_TURN1_SOLAR_BEAM]    = STRINGID_PKMNTOOKSUNLIGHT,
    [B_MSG_TURN1_SKULL_BASH]    = STRINGID_PKMNLOWEREDHEAD,
    [B_MSG_TURN1_SKY_ATTACK]    = STRINGID_PKMNISGLOWING,
    [B_MSG_TURN1_FLY]           = STRINGID_PKMNFLEWHIGH,
    [B_MSG_TURN1_DIG]           = STRINGID_PKMNDUGHOLE,
    [B_MSG_TURN1_DIVE]          = STRINGID_PKMNHIDUNDERWATER,
    [B_MSG_TURN1_BOUNCE]        = STRINGID_PKMNSPRANGUP,
    [B_MSG_TURN1_PHANTOM_FORCE] = STRINGID_VANISHEDINSTANTLY,
    [B_MSG_TURN1_GEOMANCY]      = STRINGID_PKNMABSORBINGPOWER,
    [B_MSG_TURN1_FREEZE_SHOCK]  = STRINGID_CLOAKEDINAFREEZINGLIGHT,
    [B_MSG_TURN1_SKY_DROP]      = STRINGID_PKMNTOOKTARGETHIGH,
    [B_MSG_TURN1_METEOR_BEAM]   = STRINGID_METEORBEAMCHARGING,
};

// Index copied from move's index in sTrappingMoves
const u16 gWrappedStringIds[NUM_TRAPPING_MOVES] =
{
    [B_MSG_WRAPPED_BIND]        = STRINGID_PKMNSQUEEZEDBYBIND,     // MOVE_BIND
    [B_MSG_WRAPPED_WRAP]        = STRINGID_PKMNWRAPPEDBY,          // MOVE_WRAP
    [B_MSG_WRAPPED_FIRE_SPIN]   = STRINGID_PKMNTRAPPEDINVORTEX,    // MOVE_FIRE_SPIN
    [B_MSG_WRAPPED_CLAMP]       = STRINGID_PKMNCLAMPED,            // MOVE_CLAMP
    [B_MSG_WRAPPED_WHIRLPOOL]   = STRINGID_PKMNTRAPPEDINVORTEX,    // MOVE_WHIRLPOOL
    [B_MSG_WRAPPED_SAND_TOMB]   = STRINGID_PKMNTRAPPEDBYSANDTOMB,  // MOVE_SAND_TOMB
    [B_MSG_WRAPPED_MAGMA_STORM] = STRINGID_TRAPPEDBYSWIRLINGMAGMA, // MOVE_MAGMA_STORM
    [B_MSG_WRAPPED_INFESTATION] = STRINGID_INFESTATION,            // MOVE_INFESTATION
    [B_MSG_WRAPPED_SNAP_TRAP]   = STRINGID_PKMNINSNAPTRAP,         // MOVE_SNAP_TRAP
};

const u16 gMistUsedStringIds[] =
{
    [B_MSG_SET_MIST]    = STRINGID_PKMNSHROUDEDINMIST,
    [B_MSG_MIST_FAILED] = STRINGID_BUTITFAILED
};

const u16 gFocusEnergyUsedStringIds[] =
{
    [B_MSG_GETTING_PUMPED]      = STRINGID_PKMNGETTINGPUMPED,
    [B_MSG_FOCUS_ENERGY_FAILED] = STRINGID_BUTITFAILED
};

const u16 gTransformUsedStringIds[] =
{
    [B_MSG_TRANSFORMED]      = STRINGID_PKMNTRANSFORMEDINTO,
    [B_MSG_TRANSFORM_FAILED] = STRINGID_BUTITFAILED
};

const u16 gSubstituteUsedStringIds[] =
{
    [B_MSG_SET_SUBSTITUTE]    = STRINGID_PKMNMADESUBSTITUTE,
    [B_MSG_SUBSTITUTE_FAILED] = STRINGID_TOOWEAKFORSUBSTITUTE
};

const u16 gGotPoisonedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPOISONED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNPOISONEDBY
};

const u16 gGotParalyzedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPARALYZED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNWASPARALYZEDBY
};

const u16 gFellAsleepStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLASLEEP,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNMADESLEEP,
};

const u16 gGotBurnedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASBURNED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNBURNEDBY
};

const u16 gGotFrozenStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASFROZEN,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNFROZENBY
};

const u16 gGotDefrostedStringIds[] =
{
    [B_MSG_DEFROSTED]         = STRINGID_PKMNWASDEFROSTED2,
    [B_MSG_DEFROSTED_BY_MOVE] = STRINGID_PKMNWASDEFROSTEDBY
};

const u16 gKOFailedStringIds[] =
{
    [B_MSG_KO_MISS]       = STRINGID_ATTACKMISSED,
    [B_MSG_KO_UNAFFECTED] = STRINGID_PKMNUNAFFECTED
};

const u16 gAttractUsedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLINLOVE,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNSXINFATUATEDY
};

const u16 gAbsorbDrainStringIds[] =
{
    [B_MSG_ABSORB]      = STRINGID_PKMNENERGYDRAINED,
    [B_MSG_ABSORB_OOZE] = STRINGID_ITSUCKEDLIQUIDOOZE
};

const u16 gSportsUsedStringIds[] =
{
    [B_MSG_WEAKEN_ELECTRIC] = STRINGID_ELECTRICITYWEAKENED,
    [B_MSG_WEAKEN_FIRE]     = STRINGID_FIREWEAKENED
};

const u16 gPartyStatusHealStringIds[] =
{
    [B_MSG_BELL]                     = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_ATTACKER] = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_PARTNER]  = STRINGID_BELLCHIMED,
    [B_MSG_BELL_BOTH_SOUNDPROOF]     = STRINGID_BELLCHIMED,
    [B_MSG_SOOTHING_AROMA]           = STRINGID_SOOTHINGAROMA
};

const u16 gFutureMoveUsedStringIds[] =
{
    [B_MSG_FUTURE_SIGHT] = STRINGID_PKMNFORESAWATTACK,
    [B_MSG_DOOM_DESIRE]  = STRINGID_PKMNCHOSEXASDESTINY
};

const u16 gBallEscapeStringIds[] =
{
    [BALL_NO_SHAKES]     = STRINGID_PKMNBROKEFREE,
    [BALL_1_SHAKE]       = STRINGID_ITAPPEAREDCAUGHT,
    [BALL_2_SHAKES]      = STRINGID_AARGHALMOSTHADIT,
    [BALL_3_SHAKES_FAIL] = STRINGID_SHOOTSOCLOSE
};

// Overworld weathers that don't have an associated battle weather default to "It is raining."
const u16 gWeatherStartsStringIds[] =
{
    [WEATHER_NONE]               = STRINGID_ITISRAINING,
    [WEATHER_SUNNY_CLOUDS]       = STRINGID_ITISRAINING,
    [WEATHER_SUNNY]              = STRINGID_ITISRAINING,
    [WEATHER_RAIN]               = STRINGID_ITISRAINING,
    [WEATHER_SNOW]               = STRINGID_STARTEDHAIL,
    [WEATHER_RAIN_THUNDERSTORM]  = STRINGID_ITISRAINING,
    [WEATHER_FOG_HORIZONTAL]     = STRINGID_ITISRAINING,
    [WEATHER_VOLCANIC_ASH]       = STRINGID_ITISRAINING,
    [WEATHER_SANDSTORM]          = STRINGID_SANDSTORMISRAGING,
    [WEATHER_FOG_DIAGONAL]       = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER]         = STRINGID_ITISRAINING,
    [WEATHER_SHADE]              = STRINGID_ITISRAINING,
    [WEATHER_DROUGHT]            = STRINGID_SUNLIGHTSTRONG,
    [WEATHER_DOWNPOUR]           = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER_BUBBLES] = STRINGID_ITISRAINING,
    [WEATHER_ABNORMAL]           = STRINGID_ITISRAINING
};

const u16 gInobedientStringIds[] =
{
    [B_MSG_LOAFING]            = STRINGID_PKMNLOAFING,
    [B_MSG_WONT_OBEY]          = STRINGID_PKMNWONTOBEY,
    [B_MSG_TURNED_AWAY]        = STRINGID_PKMNTURNEDAWAY,
    [B_MSG_PRETEND_NOT_NOTICE] = STRINGID_PKMNPRETENDNOTNOTICE,
    [B_MSG_INCAPABLE_OF_POWER] = STRINGID_PKMNINCAPABLEOFPOWER
};

const u16 gSafariGetNearStringIds[] =
{
    [B_MSG_CREPT_CLOSER]    = STRINGID_CREPTCLOSER,
    [B_MSG_CANT_GET_CLOSER] = STRINGID_CANTGETCLOSER
};

const u16 gSafariPokeblockResultStringIds[] =
{
    [B_MSG_MON_CURIOUS]    = STRINGID_PKMNCURIOUSABOUTX,
    [B_MSG_MON_ENTHRALLED] = STRINGID_PKMNENTHRALLEDBYX,
    [B_MSG_MON_IGNORED]    = STRINGID_PKMNIGNOREDX
};

const u16 gTrainerItemCuredStatusStringIds[] =
{
    [AI_HEAL_CONFUSION] = STRINGID_PKMNSITEMSNAPPEDOUT,
    [AI_HEAL_PARALYSIS] = STRINGID_PKMNSITEMCUREDPARALYSIS,
    [AI_HEAL_FREEZE]    = STRINGID_PKMNSITEMDEFROSTEDIT,
    [AI_HEAL_BURN]      = STRINGID_PKMNSITEMHEALEDBURN,
    [AI_HEAL_POISON]    = STRINGID_PKMNSITEMCUREDPOISON,
    [AI_HEAL_SLEEP]     = STRINGID_PKMNSITEMWOKEIT
};

const u16 gBerryEffectStringIds[] =
{
    [B_MSG_CURED_PROBLEM]     = STRINGID_PKMNSITEMCUREDPROBLEM,
    [B_MSG_NORMALIZED_STATUS] = STRINGID_PKMNSITEMNORMALIZEDSTATUS
};

const u16 gBRNPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNSXPREVENTSBURNS,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gPRLZPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNPREVENTSPARALYSISWITH,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gPSNPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNPREVENTSPOISONINGWITH,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gItemSwapStringIds[] =
{
    [B_MSG_ITEM_SWAP_TAKEN] = STRINGID_PKMNOBTAINEDX,
    [B_MSG_ITEM_SWAP_GIVEN] = STRINGID_PKMNOBTAINEDX2,
    [B_MSG_ITEM_SWAP_BOTH]  = STRINGID_PKMNOBTAINEDXYOBTAINEDZ
};

const u16 gFlashFireStringIds[] =
{
    [B_MSG_FLASH_FIRE_BOOST]    = STRINGID_PKMNRAISEDFIREPOWERWITH,
    [B_MSG_FLASH_FIRE_NO_BOOST] = STRINGID_PKMNSXMADEYINEFFECTIVE
};

const u16 gCaughtMonStringIds[] =
{
    [B_MSG_SENT_SOMEONES_PC]  = STRINGID_PKMNTRANSFERREDSOMEONESPC,
    [B_MSG_SENT_LANETTES_PC]  = STRINGID_PKMNTRANSFERREDLANETTESPC,
    [B_MSG_SOMEONES_BOX_FULL] = STRINGID_PKMNBOXSOMEONESPCFULL,
    [B_MSG_LANETTES_BOX_FULL] = STRINGID_PKMNBOXLANETTESPCFULL,
};

const u16 gRoomsStringIds[] =
{
    STRINGID_PKMNTWISTEDDIMENSIONS, STRINGID_TRICKROOMENDS,
    STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON, STRINGID_WONDERROOMENDS,
    STRINGID_HELDITEMSLOSEEFFECTS, STRINGID_MAGICROOMENDS,
    STRINGID_EMPTYSTRING3
};

const u16 gStatusConditionsStringIds[] =
{
    STRINGID_PKMNWASPOISONED, STRINGID_PKMNBADLYPOISONED, STRINGID_PKMNWASBURNED, STRINGID_PKMNWASPARALYZED, STRINGID_PKMNFELLASLEEP
};

const u8 gText_PkmnIsEvolving[] = _(
    "Què?\n"
    "{STR_VAR_1} està evolucionant!");
const u8 gText_CongratsPkmnEvolved[] = _(
    "Enhorabona! El teu {STR_VAR_1}\n"
    "ha evolucionat a {STR_VAR_2}!{WAIT_SE}\p");
const u8 gText_PkmnStoppedEvolving[] = _(
    "Eh? {STR_VAR_1}\n"
    "ha deixat d'evolucionar!\p");
const u8 gText_EllipsisQuestionMark[] = _("……?\p");
const u8 gText_WhatWillPkmnDo[] = _(
    "Què farà\n"
    "{B_ACTIVE_NAME2}?");
const u8 gText_WhatWillPkmnDo2[] = _(
    "Què farà\n"
    "{B_PLAYER_NAME}?");
const u8 gText_WhatWillWallyDo[] = _(
    "El Professor Oak\n"
    "està pensant...");
const u8 gText_LinkStandby[] = _("{PAUSE 16}Enllaç en espera…");
const u8 gText_BattleMenu[] = _(
    "Lluitar{CLEAR_TO 56}Motxilla\n"
    "Pokémon{CLEAR_TO 56}Fugir");
const u8 gText_SafariZoneMenu[] = _(
    "Ball{CLEAR_TO 56}{POKEBLOCK}\n"
    "Acostar{CLEAR_TO 56}Fugir");
const u8 gText_MoveInterfacePP[] = _("PP ");
const u8 gText_MoveInterfaceType[] = _("Tipus/");
const u8 gText_MoveInterfacePpType[] = _(
    "{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}PP\n"
    "Tipus/");
const u8 gText_MoveInterfaceDynamicColors[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_WhichMoveToForget4[] = _(
    "{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Quin moviment vols\n"
    "oblidar?");
const u8 gText_BattleYesNoChoice[] = _(
    "{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Sí\n"
    "No");
const u8 gText_BattleSwitchWhich[] = _(
    "{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Quin vols\n"
    "bescanviar?");
const u8 gText_BattleSwitchWhich2[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_BattleSwitchWhich3[] = _("{UP_ARROW}");
const u8 gText_BattleSwitchWhich4[] = _("{ESCAPE 4}");
const u8 gText_BattleSwitchWhich5[] = _("-");

static const u8 sText_HP[] = _("PS");
static const u8 sText_Attack[] = _("Atac");
static const u8 sText_Defense[] = _("Defensa");
static const u8 sText_SpAtk[] = _("At. Esp.");
static const u8 sText_SpDef[] = _("Def. Esp.");

// Unused
static const u8 * const sStatNamesTable2[] =
{
    gText_HP3, gText_SpAtk, gText_Attack,
    gText_SpDef, gText_Defense, gText_Speed
};

const u8 gText_SafariBalls[] = _("{HIGHLIGHT DARK_GRAY}Safari Balls");
const u8 gText_SafariBallLeft[] = _("{HIGHLIGHT DARK_GRAY}Queden: ${HIGHLIGHT DARK_GRAY}");
const u8 gText_Sleep[] = _("la son");
const u8 gText_Poison[] = _("el verí");
const u8 gText_Burn[] = _("la cremada");
const u8 gText_Paralysis[] = _("la paràlisi");
const u8 gText_Ice[] = _("el gel");
const u8 gText_Confusion[] = _("la confusió");
const u8 gText_Love[] = _("l'amor");
const u8 gText_SpaceAndSpace[] = _(" i ");
const u8 gText_CommaSpace[] = _(", ");
const u8 gText_Space2[] = _(" ");
const u8 gText_LineBreak[] = _("\l");
const u8 gText_NewLine[] = _("\n");
const u8 gText_Are[] = _("són");
const u8 gText_Are2[] = _("són");
const u8 gText_BadEgg[] = _("Ou Dolent");
const u8 gText_BattleWallyName[] = _("Professor Oak");
const u8 gText_Win[] = _("{HIGHLIGHT TRANSPARENT}Vict.");
const u8 gText_Loss[] = _("{HIGHLIGHT TRANSPARENT}Derr.");
const u8 gText_Draw[] = _("{HIGHLIGHT TRANSPARENT}Emp.");
static const u8 sText_SpaceIs[] = _(" és");
static const u8 sText_ApostropheS[] = _("'s");

// For displaying names of invalid moves
static const u8 sATypeMove_Table[NUMBER_OF_MON_TYPES][17] =
{
    [TYPE_NORMAL]   = _("un mov. Normal"),
    [TYPE_FIGHTING] = _("un mov. Lluita"),
    [TYPE_FLYING]   = _("un mov. Volador"),
    [TYPE_POISON]   = _("un mov. Verí"),
    [TYPE_GROUND]   = _("un mov. Terra"),
    [TYPE_ROCK]     = _("un mov. Roca"),
    [TYPE_BUG]      = _("un mov. Insecte"),
    [TYPE_GHOST]    = _("un mov. Fantasma"),
    [TYPE_STEEL]    = _("un mov. Acer"),
    [TYPE_MYSTERY]  = _("un mov. ???"),
    [TYPE_FIRE]     = _("un mov. Foc"),
    [TYPE_WATER]    = _("un mov. Aigua"),
    [TYPE_GRASS]    = _("un mov. Planta"),
    [TYPE_ELECTRIC] = _("un mov. Elèctric"),
    [TYPE_PSYCHIC]  = _("un mov. Psíquic"),
    [TYPE_ICE]      = _("un mov. Gel"),
    [TYPE_DRAGON]   = _("un mov. Drac"),
    [TYPE_DARK]     = _("un mov. Sinistre"),
    [TYPE_FAIRY]     = _("un mov. Fada")
};

const u8 gText_BattleTourney[] = _("Torneig de Combat");
static const u8 sText_Round1[] = _("Ronda 1");
static const u8 sText_Round2[] = _("Ronda 2");
static const u8 sText_Semifinal[] = _("Semifinal");
static const u8 sText_Final[] = _("Final");

const u8 *const gRoundsStringTable[DOME_ROUNDS_COUNT] =
{
    [DOME_ROUND1]    = sText_Round1,
    [DOME_ROUND2]    = sText_Round2,
    [DOME_SEMIFINAL] = sText_Semifinal,
    [DOME_FINAL]     = sText_Final
};

const u8 gText_TheGreatNewHope[] = _("La gran nova esperança!\p");
const u8 gText_WillChampinshipDreamComeTrue[] = _(
    "Es complirà el somni\n"
    "del campionat?!\p");
const u8 gText_AFormerChampion[] = _("Un antic campió!\p");
const u8 gText_ThePreviousChampion[] = _("L'anterior campió!\p");
const u8 gText_TheUnbeatenChampion[] = _("El campió invicte!\p");
const u8 gText_PlayerMon1Name[] = _("{B_PLAYER_MON1_NAME}");
const u8 gText_Vs[] = _("VS");
const u8 gText_OpponentMon1Name[] = _("{B_OPPONENT_MON1_NAME}");
const u8 gText_Mind[] = _("Ment");
const u8 gText_Skill[] = _("Destresa");
const u8 gText_Body[] = _("Cos");
const u8 gText_Judgement[] = _("{B_BUFF1}{CLEAR 13}Veredicte{CLEAR 13}{B_BUFF2}");
static const u8 sText_TwoTrainersSentPkmn[] = _(
    "{B_TRAINER1_CLASS} {B_TRAINER1_NAME} ha tret\n"
    "{B_OPPONENT_MON1_NAME}!\p{B_TRAINER2_CLASS} {B_TRAINER2_NAME} ha tret\n"
    "{B_OPPONENT_MON2_NAME}!");
static const u8 sText_Trainer2SentOutPkmn[] = _(
    "{B_TRAINER2_CLASS} {B_TRAINER2_NAME} ha tret\n"
    "{B_BUFF1}!");
static const u8 sText_TwoTrainersWantToBattle[] = _(
    "{B_TRAINER1_CLASS} {B_TRAINER1_NAME} i\n"
    "{B_TRAINER2_CLASS} {B_TRAINER2_NAME}\lvolen combatre!\p");
static const u8 sText_InGamePartnerSentOutZGoN[] = _(
    "{B_PARTNER_CLASS} {B_PARTNER_NAME} ha tret\n"
    "{B_PLAYER_MON2_NAME}!\lVinga, {B_PLAYER_MON1_NAME}!");
static const u8 sText_TwoInGameTrainersDefeated[] = _(
    "{B_TRAINER1_CLASS} {B_TRAINER1_NAME} i\n"
    "{B_TRAINER2_CLASS} {B_TRAINER2_NAME}\lhan estat derrotats!\p");
static const u8 sText_Trainer2LoseText[] = _("{B_TRAINER2_LOSE_TEXT}");
static const u8 sText_PkmnIncapableOfPower[] = _(
    "Sembla que {B_ATK_NAME_WITH_PREFIX} no pot\n"
    "fer servir el seu poder!");
static const u8 sText_GlintAppearsInEye[] = _(
    "Una llumeta apareix als\n"
    "ulls de {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnGettingIntoPosition[] = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX} s'està posant\n"
    "en posició!");
static const u8 sText_PkmnBeganGrowlingDeeply[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha començat a rugir greument!");
static const u8 sText_PkmnEagerForMore[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} en vol més!");

const u16 gBattlePalaceFlavorTextTable[] =
{
    [B_MSG_GLINT_IN_EYE]   = STRINGID_GLINTAPPEARSINEYE,
    [B_MSG_GETTING_IN_POS] = STRINGID_PKMNGETTINGINTOPOSITION,
    [B_MSG_GROWL_DEEPLY]   = STRINGID_PKMNBEGANGROWLINGDEEPLY,
    [B_MSG_EAGER_FOR_MORE] = STRINGID_PKMNEAGERFORMORE,
};

static const u8 sText_RefIfNothingIsDecided[] = _(
    "Àrbitre: Si no es decideix en\n"
    "3 torns, passarem a la valoració!");
static const u8 sText_RefThatsIt[] = _(
    "Àrbitre: Prou! Ara passarem a la\n"
    "valoració per decidir el guanyador!");
static const u8 sText_RefJudgeMind[] = _(
    "Àrbitre: Categoria 1, Ment!\n"
    "El Pokémon amb més coratge!\p");
static const u8 sText_RefJudgeSkill[] = _(
    "Àrbitre: Categoria 2, Destresa!\n"
    "El Pokémon que usa millor els moviments!\p");
static const u8 sText_RefJudgeBody[] = _(
    "Àrbitre: Categoria 3, Cos!\n"
    "El Pokémon amb més vitalitat!\p");
static const u8 sText_RefPlayerWon[] = _(
    "Àrbitre: Veredicte: {B_BUFF1} a {B_BUFF2}!\n"
    "Guanya {B_PLAYER_MON1_NAME} de {B_PLAYER_NAME}!\p");
static const u8 sText_RefOpponentWon[] = _(
    "Àrbitre: Veredicte: {B_BUFF1} a {B_BUFF2}!\n"
    "Guanya {B_OPPONENT_MON1_NAME} de {B_TRAINER1_NAME}!\p");
static const u8 sText_RefDraw[] = _(
    "Àrbitre: Veredicte: 3 a 3!\n"
    "Hi ha empat!\p");
static const u8 sText_DefeatedOpponentByReferee[] = _(
    "{B_PLAYER_MON1_NAME} ha derrotat\n"
    "{B_OPPONENT_MON1_NAME} per decisió arbitral!");
static const u8 sText_LostToOpponentByReferee[] = _(
    "{B_PLAYER_MON1_NAME} ha perdut contra\n"
    "{B_OPPONENT_MON1_NAME} per decisió arbitral!");
static const u8 sText_TiedOpponentByReferee[] = _(
    "{B_PLAYER_MON1_NAME} ha empatat amb\n"
    "{B_OPPONENT_MON1_NAME} per decisió arbitral!");
static const u8 sText_RefCommenceBattle[] = _(
    "Àrbitre: {B_PLAYER_MON1_NAME} VS {B_OPPONENT_MON1_NAME}!\n"
    "Comenceu a combatre!");

const u8 * const gRefereeStringsTable[] =
{
    [B_MSG_REF_NOTHING_IS_DECIDED] = sText_RefIfNothingIsDecided,
    [B_MSG_REF_THATS_IT]           = sText_RefThatsIt,
    [B_MSG_REF_JUDGE_MIND]         = sText_RefJudgeMind,
    [B_MSG_REF_JUDGE_SKILL]        = sText_RefJudgeSkill,
    [B_MSG_REF_JUDGE_BODY]         = sText_RefJudgeBody,
    [B_MSG_REF_PLAYER_WON]         = sText_RefPlayerWon,
    [B_MSG_REF_OPPONENT_WON]       = sText_RefOpponentWon,
    [B_MSG_REF_DRAW]               = sText_RefDraw,
    [B_MSG_REF_COMMENCE_BATTLE]    = sText_RefCommenceBattle,
};

static const u8 sText_QuestionForfeitMatch[] = _(
    "Vols abandonar el combat\n"
    "i plegar ara?");
static const u8 sText_ForfeitedMatch[] = _("{B_PLAYER_NAME} ha abandonat el combat!");
static const u8 sText_Trainer1WinText[] = _("{B_TRAINER1_WIN_TEXT}");
static const u8 sText_Trainer2WinText[] = _("{B_TRAINER2_WIN_TEXT}");
static const u8 sText_Trainer1Fled[] = _("{PLAY_SE SE_FLEE}{B_TRAINER1_CLASS} {B_TRAINER1_NAME} ha fugit!");
static const u8 sText_PlayerLostAgainstTrainer1[] = _(
    "Has perdut contra\n"
    "{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
static const u8 sText_PlayerBattledToDrawTrainer1[] = _(
    "Has empatat contra\n"
    "{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
const u8 gText_RecordBattleToPass[] = _(
    "Vols gravar el combat al teu\n"
    "Passi de Frontera?");
const u8 gText_BattleRecordedOnPass[] = _(
    "El resultat del combat de {B_PLAYER_NAME}\n"
    "s'ha gravat al Passi de Frontera.");
static const u8 sText_LinkTrainerWantsToBattlePause[] = _(
    "{B_LINK_OPPONENT1_NAME}\n"
    "vol combatre!{PAUSE 49}");
static const u8 sText_TwoLinkTrainersWantToBattlePause[] = _(
    "{B_LINK_OPPONENT1_NAME} i {B_LINK_OPPONENT2_NAME}\n"
    "volen combatre!{PAUSE 49}");
static const u8 sText_Your1[] = _("El teu");
static const u8 sText_Opposing1[] = _("El rival");
static const u8 sText_Your2[] = _("el teu");
static const u8 sText_Opposing2[] = _("el rival");

// This is four lists of moves which use a different attack string in Japanese
// to the default. See the documentation for ChooseTypeOfMoveUsedString for more detail.
static const u16 sGrammarMoveUsedTable[] =
{
    MOVE_SWORDS_DANCE, MOVE_STRENGTH, MOVE_GROWTH,
    MOVE_HARDEN, MOVE_MINIMIZE, MOVE_SMOKESCREEN,
    MOVE_WITHDRAW, MOVE_DEFENSE_CURL, MOVE_EGG_BOMB,
    MOVE_SMOG, MOVE_BONE_CLUB, MOVE_FLASH, MOVE_SPLASH,
    MOVE_ACID_ARMOR, MOVE_BONEMERANG, MOVE_REST, MOVE_SHARPEN,
    MOVE_SUBSTITUTE, MOVE_MIND_READER, MOVE_SNORE,
    MOVE_PROTECT, MOVE_SPIKES, MOVE_ENDURE, MOVE_ROLLOUT,
    MOVE_SWAGGER, MOVE_SLEEP_TALK, MOVE_HIDDEN_POWER,
    MOVE_PSYCH_UP, MOVE_EXTREME_SPEED, MOVE_FOLLOW_ME,
    MOVE_TRICK, MOVE_ASSIST, MOVE_INGRAIN, MOVE_KNOCK_OFF,
    MOVE_CAMOUFLAGE, MOVE_ASTONISH, MOVE_ODOR_SLEUTH,
    MOVE_GRASS_WHISTLE, MOVE_SHEER_COLD, MOVE_MUDDY_WATER,
    MOVE_IRON_DEFENSE, MOVE_BOUNCE, 0,

    MOVE_TELEPORT, MOVE_RECOVER, MOVE_BIDE, MOVE_AMNESIA,
    MOVE_FLAIL, MOVE_TAUNT, MOVE_BULK_UP, 0,

    MOVE_MEDITATE, MOVE_AGILITY, MOVE_MIMIC, MOVE_DOUBLE_TEAM,
    MOVE_BARRAGE, MOVE_TRANSFORM, MOVE_STRUGGLE, MOVE_SCARY_FACE,
    MOVE_CHARGE, MOVE_WISH, MOVE_BRICK_BREAK, MOVE_YAWN,
    MOVE_FEATHER_DANCE, MOVE_TEETER_DANCE, MOVE_MUD_SPORT,
    MOVE_FAKE_TEARS, MOVE_WATER_SPORT, MOVE_CALM_MIND, 0,

    MOVE_POUND, MOVE_SCRATCH, MOVE_VISE_GRIP,
    MOVE_WING_ATTACK, MOVE_FLY, MOVE_BIND, MOVE_SLAM,
    MOVE_HORN_ATTACK, MOVE_WRAP, MOVE_THRASH, MOVE_TAIL_WHIP,
    MOVE_LEER, MOVE_BITE, MOVE_GROWL, MOVE_ROAR,
    MOVE_SING, MOVE_PECK, MOVE_ABSORB, MOVE_STRING_SHOT,
    MOVE_EARTHQUAKE, MOVE_FISSURE, MOVE_DIG, MOVE_TOXIC,
    MOVE_SCREECH, MOVE_METRONOME, MOVE_LICK, MOVE_CLAMP,
    MOVE_CONSTRICT, MOVE_POISON_GAS, MOVE_BUBBLE,
    MOVE_SLASH, MOVE_SPIDER_WEB, MOVE_NIGHTMARE, MOVE_CURSE,
    MOVE_FORESIGHT, MOVE_CHARM, MOVE_ATTRACT, MOVE_ROCK_SMASH,
    MOVE_UPROAR, MOVE_SPIT_UP, MOVE_SWALLOW, MOVE_TORMENT,
    MOVE_FLATTER, MOVE_ROLE_PLAY, MOVE_ENDEAVOR, MOVE_TICKLE,
    MOVE_COVET, 0
};

static const u8 sDummyWeirdStatusString[] = {EOS, EOS, EOS, EOS, EOS, EOS, EOS, EOS, 0, 0};

static const struct BattleWindowText sTextOnWindowsInfo_Normal[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 1,
        .fgColor = TEXT_COLOR_WHITE,
        .bgColor = TEXT_DYNAMIC_COLOR_6,
        .shadowColor = TEXT_COLOR_GREEN,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_COLOR_WHITE,
        .bgColor = TEXT_DYNAMIC_COLOR_6,
        .shadowColor = TEXT_COLOR_GREEN,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_3,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_2,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_3,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_2,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_COLOR_WHITE,
        .bgColor = TEXT_COLOR_TRANSPARENT,
        .shadowColor = TEXT_COLOR_DARK_GRAY,
    },
    [B_WIN_VS_PLAYER] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_VS_OPPONENT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_COLOR_WHITE,
        .bgColor = TEXT_COLOR_TRANSPARENT,
        .shadowColor = TEXT_COLOR_GREEN,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_COLOR_WHITE,
        .bgColor = TEXT_COLOR_TRANSPARENT,
        .shadowColor = TEXT_COLOR_GREEN,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .fillValue = PIXEL_FILL(0x0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_COLOR_WHITE,
        .bgColor = TEXT_COLOR_TRANSPARENT,
        .shadowColor = TEXT_COLOR_GREEN,
    },
};

static const struct BattleWindowText sTextOnWindowsInfo_Arena[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 1,
        .fgColor = TEXT_COLOR_WHITE,
        .bgColor = TEXT_DYNAMIC_COLOR_6,
        .shadowColor = TEXT_COLOR_GREEN,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_COLOR_WHITE,
        .bgColor = TEXT_DYNAMIC_COLOR_6,
        .shadowColor = TEXT_COLOR_GREEN,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_3,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_2,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_3,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_2,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_COLOR_WHITE,
        .bgColor = TEXT_COLOR_TRANSPARENT,
        .shadowColor = TEXT_COLOR_DARK_GRAY,
    },
    [ARENA_WIN_PLAYER_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_COLOR_WHITE,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [ARENA_WIN_VS] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [ARENA_WIN_OPPONENT_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [ARENA_WIN_MIND] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [ARENA_WIN_SKILL] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [ARENA_WIN_BODY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [ARENA_WIN_JUDGEMENT_TITLE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [ARENA_WIN_JUDGEMENT_TEXT] = {
        .fillValue = PIXEL_FILL(0x1),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 1,
        .fgColor = TEXT_COLOR_DARK_GRAY,
        .bgColor = TEXT_COLOR_WHITE,
        .shadowColor = TEXT_COLOR_LIGHT_GRAY,
    },
};

static const struct BattleWindowText *const sBattleTextOnWindowsInfo[] =
{
    [B_WIN_TYPE_NORMAL] = sTextOnWindowsInfo_Normal,
    [B_WIN_TYPE_ARENA]  = sTextOnWindowsInfo_Arena
};

static const u8 sRecordedBattleTextSpeeds[] = {8, 4, 1, 0};

void BufferStringBattle(u16 stringID)
{
    s32 i;
    const u8 *stringPtr = NULL;

    gBattleMsgDataPtr = (struct BattleMsgData*)(&gBattleResources->bufferA[gActiveBattler][4]);
    gLastUsedItem = gBattleMsgDataPtr->lastItem;
    gLastUsedAbility = gBattleMsgDataPtr->lastAbility;
    gBattleScripting.battler = gBattleMsgDataPtr->scrActive;
    gBattleStruct->field_52 = gBattleMsgDataPtr->unk1605E;
    gBattleStruct->hpScale = gBattleMsgDataPtr->hpScale;
    gPotentialItemEffectBattler = gBattleMsgDataPtr->itemEffectBattler;
    gBattleStruct->stringMoveType = gBattleMsgDataPtr->moveType;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        sBattlerAbilities[i] = gBattleMsgDataPtr->abilities[i];
    }
    for (i = 0; i < TEXT_BUFF_ARRAY_COUNT; i++)
    {
        gBattleTextBuff1[i] = gBattleMsgDataPtr->textBuffs[0][i];
        gBattleTextBuff2[i] = gBattleMsgDataPtr->textBuffs[1][i];
        gBattleTextBuff3[i] = gBattleMsgDataPtr->textBuffs[2][i];
    }

    switch (stringID)
    {
    case STRINGID_INTROMSG: // first battle msg
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    stringPtr = sText_TwoTrainersWantToBattle;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_TwoLinkTrainersWantToBattlePause;
                    else
                        stringPtr = sText_TwoLinkTrainersWantToBattle;
                }
                else
                {
                    if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                        stringPtr = sText_Trainer1WantsToBattle;
                    else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_LinkTrainerWantsToBattlePause;
                    else
                        stringPtr = sText_LinkTrainerWantsToBattle;
                }
            }
            else
            {
                if (BATTLE_TWO_VS_ONE_OPPONENT)
                    stringPtr = sText_Trainer1WantsToBattle;
                else if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER))
                    stringPtr = sText_TwoTrainersWantToBattle;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersWantToBattle;
                else
                    stringPtr = sText_Trainer1WantsToBattle;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
                stringPtr = sText_LegendaryPkmnAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && IsValidForBattle(&gEnemyParty[gBattlerPartyIndexes[gActiveBattler ^ BIT_FLANK]])) // interesting, looks like they had something planned for wild double battles
                stringPtr = sText_TwoWildPkmnAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
                stringPtr = sText_WildPkmnAppearedPause;
            else
                stringPtr = sText_WildPkmnAppeared;
        }
        break;
    case STRINGID_INTROSENDOUT: // poke first send-out
        if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && IsValidForBattle(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler ^ BIT_FLANK]]))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                    stringPtr = sText_InGamePartnerSentOutZGoN;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_GoTwoPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_LinkPartnerSentOutPkmnGoPkmn;
                else
                    stringPtr = sText_GoTwoPkmn;
            }
            else
            {
                stringPtr = sText_GoPkmn;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && IsValidForBattle(&gEnemyParty[gBattlerPartyIndexes[gActiveBattler ^ BIT_FLANK]]))
            {
                if (BATTLE_TWO_VS_ONE_OPPONENT)
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_TwoLinkTrainersSentOutPkmn;
                else if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                    stringPtr = sText_LinkTrainerSentOutTwoPkmn;
                else
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
            }
            else
            {
                if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK)))
                    stringPtr = sText_Trainer1SentOutPkmn;
                else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                    stringPtr = sText_Trainer1SentOutPkmn;
                else
                    stringPtr = sText_LinkTrainerSentOutPkmn;
            }
        }
        break;
    case STRINGID_RETURNMON: // sending poke to ball msg
        if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        {
            if (*(&gBattleStruct->hpScale) == 0)
                stringPtr = sText_PkmnThatsEnough;
            else if (*(&gBattleStruct->hpScale) == 1 || gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                stringPtr = sText_PkmnComeBack;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_PkmnOkComeBack;
            else
                stringPtr = sText_PkmnGoodComeBack;
        }
        else
        {
            if (gTrainerBattleOpponent_A == TRAINER_LINK_OPPONENT || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_LinkTrainer2WithdrewPkmn;
                else
                    stringPtr = sText_LinkTrainer1WithdrewPkmn;
            }
            else
            {
                stringPtr = sText_Trainer1WithdrewPkmn;
            }
        }
        break;
    case STRINGID_SWITCHINMON: // switch-in msg
        if (GetBattlerSide(gBattleScripting.battler) == B_SIDE_PLAYER)
        {
            if (*(&gBattleStruct->hpScale) == 0 || gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                stringPtr = sText_GoPkmn2;
            else if (*(&gBattleStruct->hpScale) == 1)
                stringPtr = sText_DoItPkmn;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_GoForItPkmn;
            else
                stringPtr = sText_YourFoesWeakGetEmPkmn;
        }
        else
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                        stringPtr = sText_LinkTrainerMultiSentOutPkmn;
                    else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_LinkTrainerSentOutPkmn2;
                }
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    stringPtr = sText_Trainer1SentOutPkmn2;
                }
            }
        }
        break;
    case STRINGID_USEDMOVE: // pokemon used a move msg
        if (gBattleStruct->zmove.active && gBattleStruct->zmove.activeSplit != SPLIT_STATUS)
            StringCopy(gBattleTextBuff3, GetZMoveName(gBattleMsgDataPtr->currentMove));
        else if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT)
            StringCopy(gBattleTextBuff3, sATypeMove_Table[*(&gBattleStruct->stringMoveType)]);
        else
            StringCopy(gBattleTextBuff3, gMoveNames[gBattleMsgDataPtr->currentMove]);

        stringPtr = sText_AttackerUsedX;
        break;
    case STRINGID_BATTLEEND: // battle end
        if (gBattleTextBuff1[0] & B_OUTCOME_LINK_BATTLE_RAN)
        {
            gBattleTextBuff1[0] &= ~(B_OUTCOME_LINK_BATTLE_RAN);
            if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTextBuff1[0] == B_OUTCOME_LOST || gBattleTextBuff1[0] == B_OUTCOME_DREW)
                stringPtr = sText_GotAwaySafely;
            else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                stringPtr = sText_TwoWildFled;
            else
                stringPtr = sText_WildFled;
        }
        else
        {
            if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                        stringPtr = sText_TwoInGameTrainersDefeated;
                    else
                        stringPtr = sText_TwoLinkTrainersDefeated;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostToTwo;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawVsTwo;
                    break;
                }
            }
            else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainerTrainer1;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstTrainer1;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawTrainer1;
                    break;
                }
            }
            else
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainer;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstLinkTrainer;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawLinkTrainer;
                    break;
                }
            }
        }
        break;
    case STRINGID_TRAINERSLIDE:
        stringPtr = gBattleStruct->trainerSlideMsg;
        break;
    default: // load a string from the table
        if (stringID >= BATTLESTRINGS_COUNT)
        {
            gDisplayedStringBattle[0] = EOS;
            return;
        }
        else
        {
            stringPtr = gBattleStringsTable[stringID - BATTLESTRINGS_TABLE_START];
        }
        break;
    }

    BattleStringExpandPlaceholdersToDisplayedString(stringPtr);
}

u32 BattleStringExpandPlaceholdersToDisplayedString(const u8* src)
{
    BattleStringExpandPlaceholders(src, gDisplayedStringBattle);
}

static const u8* TryGetStatusString(u8 *src)
{
    u32 i;
    u8 status[8];
    u32 chars1, chars2;
    u8* statusPtr;

    memcpy(status, sDummyWeirdStatusString, 8);

    statusPtr = status;
    for (i = 0; i < 8; i++)
    {
        if (*src == EOS) break; // one line required to match -g
        *statusPtr = *src;
        src++;
        statusPtr++;
    }

    chars1 = *(u32*)(&status[0]);
    chars2 = *(u32*)(&status[4]);

    for (i = 0; i < ARRAY_COUNT(gStatusConditionStringsTable); i++)
    {
        if (chars1 == *(u32*)(&gStatusConditionStringsTable[i][0][0])
            && chars2 == *(u32*)(&gStatusConditionStringsTable[i][0][4]))
            return gStatusConditionStringsTable[i][1];
    }
    return NULL;
}

static void GetBattlerNick(u32 battlerId, u8 *dst)
{
    struct Pokemon *mon, *illusionMon;

    if (GET_BATTLER_SIDE(battlerId) == B_SIDE_PLAYER)
        mon = &gPlayerParty[gBattlerPartyIndexes[battlerId]];
    else
        mon = &gEnemyParty[gBattlerPartyIndexes[battlerId]];

    illusionMon = GetIllusionMonPtr(battlerId);
    if (illusionMon != NULL)
        mon = illusionMon;
    GetMonData(mon, MON_DATA_NICKNAME, dst);
    StringGet_Nickname(dst);
}

#define HANDLE_NICKNAME_STRING_CASE(battlerId)                          \
    if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)                     \
    {                                                                   \
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)                     \
            toCpy = sText_FoePkmnPrefix;                                \
        else                                                            \
            toCpy = sText_WildPkmnPrefix;                               \
        while (*toCpy != EOS)                                           \
        {                                                               \
            dst[dstID] = *toCpy;                                        \
            dstID++;                                                    \
            toCpy++;                                                    \
        }                                                               \
    }                                                                   \
    GetBattlerNick(battlerId, text);                                    \
    toCpy = text;

static const u8 *BattleStringGetOpponentNameByTrainerId(u16 trainerId, u8 *text, u8 multiplayerId, u8 battlerId)
{
    const u8 *toCpy;

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
    {
        u32 i;
        for (i = 0; i < ARRAY_COUNT(gBattleResources->secretBase->trainerName); i++)
            text[i] = gBattleResources->secretBase->trainerName[i];
        text[i] = EOS;
        ConvertInternationalString(text, gBattleResources->secretBase->language);
        toCpy = text;
    }
    else if (trainerId == TRAINER_UNION_ROOM)
    {
        toCpy = gLinkPlayers[multiplayerId ^ BIT_SIDE].name;
    }
    else if (trainerId == TRAINER_LINK_OPPONENT)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            toCpy = gLinkPlayers[GetBattlerMultiplayerId(battlerId)].name;
        else
            toCpy = gLinkPlayers[GetBattlerMultiplayerId(battlerId) & BIT_SIDE].name;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        CopyFrontierBrainTrainerName(text);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
    {
        GetFrontierTrainerName(text, trainerId);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
    {
        GetTrainerHillTrainerName(text, trainerId);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
    {
        GetEreaderTrainerName(text);
        toCpy = text;
    }
    else
    {
        toCpy = gTrainers[trainerId].trainerName;
        if (toCpy[0] == B_BUFF_PLACEHOLDER_BEGIN && toCpy[1] == B_TXT_RIVAL_NAME)
                        toCpy = GetExpandedPlaceholder(PLACEHOLDER_ID_RIVAL);
    }

    return toCpy;
}

static const u8 *BattleStringGetOpponentName(u8 *text, u8 multiplayerId, u8 battlerId)
{
    const u8 *toCpy;

    switch (GetBattlerPosition(battlerId))
    {
    case B_POSITION_OPPONENT_LEFT:
        toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent_A, text, multiplayerId, battlerId);
        break;
    case B_POSITION_OPPONENT_RIGHT:
        if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_MULTI) && !BATTLE_TWO_VS_ONE_OPPONENT)
            toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent_B, text, multiplayerId, battlerId);
        else
            toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent_A, text, multiplayerId, battlerId);
        break;
    }

    return toCpy;
}

static const u8 *BattleStringGetPlayerName(u8 *text, u8 battlerId)
{
    const u8 *toCpy;

    switch (GetBattlerPosition(battlerId))
    {
    case B_POSITION_PLAYER_LEFT:
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            toCpy = gLinkPlayers[0].name;
        else
            toCpy = gSaveBlock2Ptr->playerName;
        break;
    case B_POSITION_PLAYER_RIGHT:
        if (gBattleTypeFlags & BATTLE_TYPE_LINK && gBattleTypeFlags & (BATTLE_TYPE_RECORDED | BATTLE_TYPE_MULTI))
        {
            toCpy = gLinkPlayers[2].name;
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        {
            GetFrontierTrainerName(text, gPartnerTrainerId);
            toCpy = text;
        }
        else
        {
            toCpy = gSaveBlock2Ptr->playerName;
        }
        break;
    }

    return toCpy;
}

static const u8 *BattleStringGetTrainerName(u8 *text, u8 multiplayerId, u8 battlerId)
{
    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        return BattleStringGetPlayerName(text, battlerId);
    else
        return BattleStringGetOpponentName(text, multiplayerId, battlerId);
}

static const u8 *BattleStringGetOpponentClassByTrainerId(u16 trainerId)
{
    const u8 *toCpy;

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
        toCpy = gTrainerClassNames[GetSecretBaseTrainerClass()];
    else if (trainerId == TRAINER_UNION_ROOM)
        toCpy = gTrainerClassNames[GetUnionRoomTrainerClass()];
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
        toCpy = gTrainerClassNames[GetFrontierBrainTrainerClass()];
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        toCpy = gTrainerClassNames[GetFrontierOpponentClass(trainerId)];
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
        toCpy = gTrainerClassNames[GetTrainerHillOpponentClass(trainerId)];
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
        toCpy = gTrainerClassNames[GetEreaderTrainerClassId()];
    else
        toCpy = gTrainerClassNames[gTrainers[trainerId].trainerClass];

    return toCpy;
}

u32 BattleStringExpandPlaceholders(const u8 *src, u8 *dst)
{
    u32 dstID = 0; // if they used dstID, why not use srcID as well?
    const u8 *toCpy = NULL;
    u8 text[30];
    u8 multiplayerId;
    s32 i;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        multiplayerId = gRecordedBattleMultiplayerId;
    else
        multiplayerId = GetMultiplayerId();

    while (*src != EOS)
    {
        toCpy = NULL;
        if (*src == PLACEHOLDER_BEGIN)
        {
            src++;
            switch (*src)
            {
            case B_TXT_BUFF1:
                if (gBattleTextBuff1[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff1, gStringVar1);
                    toCpy = gStringVar1;
                }
                else
                {
                    toCpy = TryGetStatusString(gBattleTextBuff1);
                    if (toCpy == NULL)
                        toCpy = gBattleTextBuff1;
                }
                break;
            case B_TXT_BUFF2:
                if (gBattleTextBuff2[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff2, gStringVar2);
                    toCpy = gStringVar2;
                }
                else
                    toCpy = gBattleTextBuff2;
                break;
            case B_TXT_BUFF3:
                if (gBattleTextBuff3[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff3, gStringVar3);
                    toCpy = gStringVar3;
                }
                else
                    toCpy = gBattleTextBuff3;
                break;
            case B_TXT_COPY_VAR_1:
                toCpy = gStringVar1;
                break;
            case B_TXT_COPY_VAR_2:
                toCpy = gStringVar2;
                break;
            case B_TXT_COPY_VAR_3:
                toCpy = gStringVar3;
                break;
            case B_TXT_PLAYER_MON1_NAME: // first player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON1_NAME: // first enemy poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_PLAYER_MON2_NAME: // second player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON2_NAME: // second enemy poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON1_NAME: // link first player poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id, text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON1_NAME: // link first opponent poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 1, text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON2_NAME: // link second player poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 2, text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON2_NAME: // link second opponent poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 3, text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX_MON1: // Unused, to change into sth else.
                break;
            case B_TXT_ATK_PARTNER_NAME: // attacker partner name
                GetBattlerNick(BATTLE_PARTNER(gBattlerAttacker), text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX: // attacker name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerAttacker)
                break;
            case B_TXT_DEF_NAME_WITH_PREFIX: // target name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerTarget)
                break;
            case B_TXT_DEF_NAME: // target name
                GetBattlerNick(gBattlerTarget, text);
                toCpy = text;
                break;
            case B_TXT_ACTIVE_NAME: // active name
                GetBattlerNick(gActiveBattler, text);
                toCpy = text;
                break;
            case B_TXT_ACTIVE_NAME2: // active battlerId name with prefix, no illusion
                if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
                    GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_NICKNAME, text);
                else
                    GetMonData(&gEnemyParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_EFF_NAME_WITH_PREFIX: // effect battlerId name with prefix
                HANDLE_NICKNAME_STRING_CASE(gEffectBattler)
                break;
            case B_TXT_ACTIVE_NAME_WITH_PREFIX: // active battlerId name with prefix
                HANDLE_NICKNAME_STRING_CASE(gActiveBattler)
                break;
            case B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX: // scripting active battlerId name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattleScripting.battler)
                break;
            case B_TXT_CURRENT_MOVE: // current move name
                if (gBattleStruct->zmove.active)
                    toCpy = GetZMoveName(gBattleMsgDataPtr->currentMove);
                else if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT)
                    toCpy = sATypeMove_Table[gBattleStruct->stringMoveType];
                else
                    toCpy = gMoveNames[gBattleMsgDataPtr->currentMove];
                break;
            case B_TXT_LAST_MOVE: // originally used move name
                if (gBattleStruct->zmove.active)
                    toCpy = GetZMoveName(gBattleMsgDataPtr->originallyUsedMove);
                else if (gBattleMsgDataPtr->originallyUsedMove >= MOVES_COUNT)
                    toCpy = sATypeMove_Table[gBattleStruct->stringMoveType];
                else
                    toCpy = gMoveNames[gBattleMsgDataPtr->originallyUsedMove];
                break;
            case B_TXT_LAST_ITEM: // last used item
                if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                {
                    if (gLastUsedItem == ITEM_ENIGMA_BERRY)
                    {
                        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
                        {
                            if ((gBattleScripting.multiplayerId != 0 && (gPotentialItemEffectBattler & BIT_SIDE))
                                || (gBattleScripting.multiplayerId == 0 && !(gPotentialItemEffectBattler & BIT_SIDE)))
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                            {
                                toCpy = sText_EnigmaBerry;
                            }
                        }
                        else
                        {
                            if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                                toCpy = sText_EnigmaBerry;
                        }
                    }
                    else
                    {
                        CopyItemName(gLastUsedItem, text);
                        toCpy = text;
                    }
                }
                else
                {
                    CopyItemName(gLastUsedItem, text);
                    toCpy = text;
                }
                break;
            case B_TXT_LAST_ABILITY: // last used ability
                toCpy = gAbilityNames[gLastUsedAbility];
                break;
            case B_TXT_ATK_ABILITY: // attacker ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattlerAttacker]];
                break;
            case B_TXT_DEF_ABILITY: // target ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattlerTarget]];
                break;
            case B_TXT_SCR_ACTIVE_ABILITY: // scripting active ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattleScripting.battler]];
                break;
            case B_TXT_EFF_ABILITY: // effect battlerId ability
                toCpy = gAbilityNames[sBattlerAbilities[gEffectBattler]];
                break;
            case B_TXT_TRAINER1_CLASS: // trainer class name
                toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent_A);
                break;
            case B_TXT_TRAINER1_NAME: // trainer1 name
                toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent_A, text, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
                break;
            case B_TXT_LINK_PLAYER_NAME: // link player name
                toCpy = gLinkPlayers[multiplayerId].name;
                break;
            case B_TXT_LINK_PARTNER_NAME: // link partner name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT1_NAME: // link opponent 1 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT2_NAME: // link opponent 2 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id)))].name;
                break;
            case B_TXT_LINK_SCR_TRAINER_NAME: // link scripting active name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(gBattleScripting.battler)].name;
                break;
            case B_TXT_PLAYER_NAME: // player name
                toCpy = BattleStringGetPlayerName(text, GetBattlerAtPosition(B_POSITION_PLAYER_LEFT));
                break;
            case B_TXT_TRAINER1_LOSE_TEXT: // trainerA lose text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerALoseText();
                }
                break;
            case B_TXT_TRAINER1_WIN_TEXT: // trainerA win text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_26: // ?
                if (GetBattlerSide(gBattleScripting.battler) != B_SIDE_PLAYER)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        toCpy = sText_FoePkmnPrefix;
                    else
                        toCpy = sText_WildPkmnPrefix;
                    while (*toCpy != EOS)
                    {
                        dst[dstID] = *toCpy;
                        dstID++;
                        toCpy++;
                    }
                    GetMonData(&gEnemyParty[gBattleStruct->field_52], MON_DATA_NICKNAME, text);
                }
                else
                {
                    GetMonData(&gPlayerParty[gBattleStruct->field_52], MON_DATA_NICKNAME, text);
                }
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_PC_CREATOR_NAME: // lanette pc
                if (FlagGet(FLAG_SYS_PC_BILL))
                    toCpy = sText_Lanettes;
                else
                    toCpy = sText_Someones;
                break;
            case B_TXT_ATK_PREFIX2:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_DEF_PREFIX2:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_ATK_PREFIX1:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_DEF_PREFIX1:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_ATK_PREFIX3:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_DEF_PREFIX3:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_TRAINER2_CLASS:
                toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent_B);
                break;
            case B_TXT_TRAINER2_NAME:
                toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent_B, text, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT));
                break;
            case B_TXT_TRAINER2_LOSE_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerBLoseText();
                }
                break;
            case B_TXT_TRAINER2_WIN_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_PARTNER_CLASS:
                toCpy = gTrainerClassNames[GetFrontierOpponentClass(gPartnerTrainerId)];
                break;
            case B_TXT_PARTNER_NAME:
                toCpy = BattleStringGetPlayerName(text, GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT));
                break;
            case B_TXT_RIVAL_NAME:
                toCpy = gSaveBlock2Ptr->rivalName;
                break;
            case B_TXT_ATK_TRAINER_NAME:
                toCpy = BattleStringGetTrainerName(text, multiplayerId, gBattlerAttacker);
                break;
            case B_TXT_ATK_TRAINER_CLASS:
                switch (GetBattlerPosition(gBattlerAttacker))
                {
                case B_POSITION_PLAYER_RIGHT:
                    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                        toCpy = gTrainerClassNames[GetFrontierOpponentClass(gPartnerTrainerId)];
                    break;
                case B_POSITION_OPPONENT_LEFT:
                    toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent_A);
                    break;
                case B_POSITION_OPPONENT_RIGHT:
                    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && !BATTLE_TWO_VS_ONE_OPPONENT)
                        toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent_B);
                    else
                        toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent_A);
                    break;
                }
                break;
            case B_TXT_ATK_TEAM1:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_ATK_TEAM2:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            case B_TXT_DEF_TEAM1:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_DEF_TEAM2:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            }

            if (toCpy != NULL)
            {
                while (*toCpy != EOS)
                {
                    dst[dstID] = *toCpy;
                    dstID++;
                    toCpy++;
                }
            }

            if (*src == B_TXT_TRAINER1_LOSE_TEXT || *src == B_TXT_TRAINER2_LOSE_TEXT
                || *src == B_TXT_TRAINER1_WIN_TEXT || *src == B_TXT_TRAINER2_WIN_TEXT)
            {
                dst[dstID] = EXT_CTRL_CODE_BEGIN;
                dstID++;
                dst[dstID] = EXT_CTRL_CODE_PAUSE_UNTIL_PRESS;
                dstID++;
            }
        }
        else
        {
            dst[dstID] = *src;
            dstID++;
        }
        src++;
    }

    dst[dstID] = *src;
    dstID++;

    return dstID;
}

static void IllusionNickHack(u32 battlerId, u32 partyId, u8 *dst)
{
    s32 id, i;
    // we know it's gEnemyParty
    struct Pokemon *mon = &gEnemyParty[partyId], *partnerMon;

    if (GetMonAbility(mon) == ABILITY_ILLUSION)
    {
        if (IsBattlerAlive(BATTLE_PARTNER(battlerId)))
            partnerMon = &gEnemyParty[gBattlerPartyIndexes[BATTLE_PARTNER(battlerId)]];
        else
            partnerMon = mon;

        // Find last alive non-egg pokemon.
        for (i = PARTY_SIZE - 1; i >= 0; i--)
        {
            id = i;
            if (GetMonData(&gEnemyParty[id], MON_DATA_SANITY_HAS_SPECIES)
                && GetMonData(&gEnemyParty[id], MON_DATA_HP)
                && &gEnemyParty[id] != mon
                && &gEnemyParty[id] != partnerMon)
            {
                GetMonData(&gEnemyParty[id], MON_DATA_NICKNAME, dst);
                return;
            }
        }
    }

    GetMonData(mon, MON_DATA_NICKNAME, dst);
}

void ExpandBattleTextBuffPlaceholders(const u8 *src, u8 *dst)
{
    u32 srcID = 1;
    u32 value = 0;
    u8 text[12];
    u16 hword;

    *dst = EOS;
    while (src[srcID] != B_BUFF_EOS)
    {
        switch (src[srcID])
        {
        case B_BUFF_STRING: // battle string
            hword = T1_READ_16(&src[srcID + 1]);
            StringAppend(dst, gBattleStringsTable[hword - BATTLESTRINGS_TABLE_START]);
            srcID += 3;
            break;
        case B_BUFF_NUMBER: // int to string
            switch (src[srcID + 1])
            {
            case 1:
                value = src[srcID + 3];
                break;
            case 2:
                value = T1_READ_16(&src[srcID + 3]);
                break;
            case 4:
                value = T1_READ_32(&src[srcID + 3]);
                break;
            }
            ConvertIntToDecimalStringN(dst, value, STR_CONV_MODE_LEFT_ALIGN, src[srcID + 2]);
            srcID += src[srcID + 1] + 3;
            break;
        case B_BUFF_MOVE: // move name
            StringAppend(dst, gMoveNames[T1_READ_16(&src[srcID + 1])]);
            srcID += 3;
            break;
        case B_BUFF_TYPE: // type name
            StringAppend(dst, gTypeNames[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_MON_NICK_WITH_PREFIX: // poke nick with prefix
            if (GetBattlerSide(src[srcID + 1]) == B_SIDE_PLAYER)
            {
                GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, text);
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                    StringAppend(dst, sText_FoePkmnPrefix);
                else
                    StringAppend(dst, sText_WildPkmnPrefix);

                GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, text);
            }
            StringGet_Nickname(text);
            StringAppend(dst, text);
            srcID += 3;
            break;
        case B_BUFF_STAT: // stats
            StringAppend(dst, gStatNamesTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_SPECIES: // species name
            GetSpeciesName(dst, T1_READ_16(&src[srcID + 1]));
            srcID += 3;
            break;
        case B_BUFF_MON_NICK: // poke nick without prefix
            if (src[srcID + 2] == gBattlerPartyIndexes[src[srcID + 1]])
            {
                GetBattlerNick(src[srcID + 1], dst);
            }
            else if (gBattleScripting.illusionNickHack) // for STRINGID_ENEMYABOUTTOSWITCHPKMN
            {
                gBattleScripting.illusionNickHack = 0;
                IllusionNickHack(src[srcID + 1], src[srcID + 2], dst);
                StringGet_Nickname(dst);
            }
            else
            {
                if (GetBattlerSide(src[srcID + 1]) == B_SIDE_PLAYER)
                    GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                else
                    GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                StringGet_Nickname(dst);
            }
            srcID += 3;
            break;
        case B_BUFF_NEGATIVE_FLAVOR: // flavor table
            StringAppend(dst, gPokeblockWasTooXStringTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_ABILITY: // ability names
            StringAppend(dst, gAbilityNames[T1_READ_16(&src[srcID + 1])]);
            srcID += 3;
            break;
        case B_BUFF_ITEM: // item name
            hword = T1_READ_16(&src[srcID + 1]);
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (hword == ITEM_ENIGMA_BERRY)
                {
                    if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                    {
                        StringCopy(dst, gEnigmaBerries[gPotentialItemEffectBattler].name);
                        StringAppend(dst, sText_BerrySuffix);
                    }
                    else
                    {
                        StringAppend(dst, sText_EnigmaBerry);
                    }
                }
                else
                {
                    CopyItemName(hword, dst);
                }
            }
            else
            {
                CopyItemName(hword, dst);
            }
            srcID += 3;
            break;
        }
    }
}

// Loads one of two text strings into the provided buffer. This is functionally
// unused, since the value loaded into the buffer is not read; it loaded one of
// two particles (either "?" or "?") which works in tandem with ChooseTypeOfMoveUsedString
// below to effect changes in the meaning of the line.
static void ChooseMoveUsedParticle(u8* textBuff)
{
    s32 counter = 0;
    u32 i = 0;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == 0)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    if (counter >= 0)
    {
        if (counter <= 2)
            StringCopy(textBuff, sText_SpaceIs); // is
        else if (counter <= MAX_MON_MOVES)
            StringCopy(textBuff, sText_ApostropheS); // 's
    }
}

// Appends "!" to the text buffer `dst`. In the original Japanese this looked
// into the table of moves at sGrammarMoveUsedTable and varied the line accordingly.
//
// sText_ExclamationMark was a plain "!", used for any attack not on the list.
// It resulted in the translation "<NAME>'s <ATTACK>!".
//
// sText_ExclamationMark2 was "? ????!". This resulted in the translation
// "<NAME> used <ATTACK>!", which was used for all attacks in English.
//
// sText_ExclamationMark3 was "??!". This was used for those moves whose
// names were verbs, such as Recover, and resulted in translations like "<NAME>
// recovered itself!".
//
// sText_ExclamationMark4 was "? ??!" This resulted in a translation of
// "<NAME> did an <ATTACK>!".
//
// sText_ExclamationMark5 was " ????!" This resulted in a translation of
// "<NAME>'s <ATTACK> attack!".
static void ChooseTypeOfMoveUsedString(u8* dst)
{
    s32 counter = 0;
    s32 i = 0;

    while (*dst != EOS)
        dst++;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == MOVE_NONE)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    switch (counter)
    {
    case 0:
        StringCopy(dst, sText_ExclamationMark);
        break;
    case 1:
        StringCopy(dst, sText_ExclamationMark2);
        break;
    case 2:
        StringCopy(dst, sText_ExclamationMark3);
        break;
    case 3:
        StringCopy(dst, sText_ExclamationMark4);
        break;
    case 4:
        StringCopy(dst, sText_ExclamationMark5);
        break;
    }
}

void BattlePutTextOnWindow(const u8 *text, u8 windowId)
{
    const struct BattleWindowText *textInfo = sBattleTextOnWindowsInfo[gBattleScripting.windowsType];
    bool32 copyToVram;
    struct TextPrinterTemplate printerTemplate;
    u8 speed;

    if (windowId & B_WIN_COPYTOVRAM)
    {
        windowId &= ~B_WIN_COPYTOVRAM;
        copyToVram = FALSE;
    }
    else
    {
        FillWindowPixelBuffer(windowId, textInfo[windowId].fillValue);
        copyToVram = TRUE;
    }

    printerTemplate.currentChar = text;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = textInfo[windowId].fontId;
    printerTemplate.x = textInfo[windowId].x;
    printerTemplate.y = textInfo[windowId].y;
    printerTemplate.currentX = printerTemplate.x;
    printerTemplate.currentY = printerTemplate.y;
    printerTemplate.letterSpacing = textInfo[windowId].letterSpacing;
    printerTemplate.lineSpacing = textInfo[windowId].lineSpacing;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = textInfo[windowId].fgColor;
    printerTemplate.bgColor = textInfo[windowId].bgColor;
    printerTemplate.shadowColor = textInfo[windowId].shadowColor;

    if (printerTemplate.x == 0xFF)
    {
        u32 width = GetBattleWindowTemplatePixelWidth(gBattleScripting.windowsType, windowId);
        s32 alignX = GetStringCenterAlignXOffsetWithLetterSpacing(printerTemplate.fontId, printerTemplate.currentChar, width, printerTemplate.letterSpacing);
        printerTemplate.x = printerTemplate.currentX = alignX;
    }

    if (windowId == ARENA_WIN_JUDGEMENT_TEXT)
        gTextFlags.useAlternateDownArrow = FALSE;
    else
        gTextFlags.useAlternateDownArrow = TRUE;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED))
        gTextFlags.autoScroll = TRUE;
    else
        gTextFlags.autoScroll = FALSE;

    if (windowId == B_WIN_MSG || windowId == ARENA_WIN_JUDGEMENT_TEXT)
    {
        if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            speed = 1;
        else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            speed = sRecordedBattleTextSpeeds[GetTextSpeedInRecordedBattle()];
        else
            speed = GetPlayerTextSpeedDelay();

        gTextFlags.canABSpeedUpPrint = 1;
    }
    else
    {
        speed = textInfo[windowId].speed;
        gTextFlags.canABSpeedUpPrint = 0;
    }

    AddTextPrinter(&printerTemplate, speed, NULL);

    if (copyToVram)
    {
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }
}

void SetPpNumbersPaletteInMoveSelection(void)
{
    struct ChooseMoveStruct *chooseMoveStruct = (struct ChooseMoveStruct*)(&gBattleResources->bufferA[gActiveBattler][4]);
    const u16 *palPtr = gPPTextPalette;
    u8 var = GetCurrentPpToMaxPpState(chooseMoveStruct->currentPp[gMoveSelectionCursor[gActiveBattler]],
                         chooseMoveStruct->maxPp[gMoveSelectionCursor[gActiveBattler]]);

    gPlttBufferUnfaded[92] = palPtr[(var * 2) + 0];
    gPlttBufferUnfaded[91] = palPtr[(var * 2) + 1];

    CpuCopy16(&gPlttBufferUnfaded[92], &gPlttBufferFaded[92], sizeof(u16));
    CpuCopy16(&gPlttBufferUnfaded[91], &gPlttBufferFaded[91], sizeof(u16));
}

u8 GetCurrentPpToMaxPpState(u8 currentPp, u8 maxPp)
{
    if (maxPp == currentPp)
    {
        return 3;
    }
    else if (maxPp <= 2)
    {
        if (currentPp > 1)
            return 3;
        else
            return 2 - currentPp;
    }
    else if (maxPp <= 7)
    {
        if (currentPp > 2)
            return 3;
        else
            return 2 - currentPp;
    }
    else
    {
        if (currentPp == 0)
            return 2;
        if (currentPp <= maxPp / 4)
            return 1;
        if (currentPp > maxPp / 2)
            return 3;
    }

    return 0;
}

struct TrainerSlide
{
    u16 trainerId;
    const u8 *msgLastSwitchIn;
    const u8 *msgLastLowHp;
    const u8 *msgFirstDown;
};

static const struct TrainerSlide sTrainerSlides[] =
{
    /* Put any trainer slide-in messages inside this array.
    Example:
    {
        .trainerId = TRAINER_FLAG,
        .msgLastSwitchIn = sText_AarghAlmostHadIt,
        .msgLastLowHp = sText_BoxIsFull,
        .msgFirstDown = sText_123Poof,
    },
    */
};

static u32 GetEnemyMonCount(bool32 onlyAlive)
{
    u32 i, count = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u32 species = GetMonData(&gEnemyParty[i], MON_DATA_SPECIES2, NULL);
        if (species != SPECIES_NONE
            && species != SPECIES_EGG
            && (!onlyAlive || GetMonData(&gEnemyParty[i], MON_DATA_HP, NULL)))
            count++;
    }

    return count;
}

static bool32 IsBattlerHpLow(u32 battler)
{
    if ((gBattleMons[battler].hp * 100) / gBattleMons[battler].maxHP < 25)
        return TRUE;
    else
        return FALSE;
}

bool32 ShouldDoTrainerSlide(u32 battlerId, u32 trainerId, u32 which)
{
    s32 i;

    if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER) || GetBattlerSide(battlerId) != B_SIDE_OPPONENT)
        return FALSE;

    for (i = 0; i < ARRAY_COUNT(sTrainerSlides); i++)
    {
        if (trainerId == sTrainerSlides[i].trainerId)
        {
            gBattleScripting.battler = battlerId;
            switch (which)
            {
            case TRAINER_SLIDE_LAST_SWITCHIN:
                if (sTrainerSlides[i].msgLastSwitchIn != NULL && GetEnemyMonCount(TRUE) == 1)
                {
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgLastSwitchIn;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_LAST_LOW_HP:
                if (sTrainerSlides[i].msgLastLowHp != NULL
                    && GetEnemyMonCount(TRUE) == 1
                    && IsBattlerHpLow(battlerId)
                    && !gBattleStruct->trainerSlideLowHpMsgDone)
                {
                    gBattleStruct->trainerSlideLowHpMsgDone = TRUE;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgLastLowHp;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_FIRST_DOWN:
                if (sTrainerSlides[i].msgFirstDown != NULL && GetEnemyMonCount(TRUE) == GetEnemyMonCount(FALSE) - 1)
                {
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgFirstDown;
                    return TRUE;
                }
                break;
            }
            break;
        }
    }

    return FALSE;
}

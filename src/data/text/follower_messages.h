extern const u8 EventScript_FollowerIsShivering[];
extern const u8 EventScript_FollowerNostalgia[];
extern const u8 EventScript_FollowerHopping[];
extern const u8 EventScript_FollowerJumpOnPlayer[];
extern const u8 EventScript_FollowerCuddling[];
extern const u8 EventScript_FollowerShiverCuddling[];
extern const u8 EventScript_FollowerGetCloser[];
extern const u8 EventScript_FollowerPokingPlayer[];
extern const u8 EventScript_FollowerLookAround[];
extern const u8 EventScript_FollowerLookAway[];
extern const u8 EventScript_FollowerLookAwayBark[];
extern const u8 EventScript_FollowerLookAwayPoke[];
extern const u8 EventScript_FollowerPokeGround[];
extern const u8 EventScript_FollowerStartled[];
extern const u8 EventScript_FollowerFastHopping[];
extern const u8 EventScript_FollowerDizzy[];
extern const u8 EventScript_FollowerLookAroundScared[];
extern const u8 EventScript_FollowerDance[];

// 'Generic', unconditional happy messages
static const u8 sHappyMsg00[] = _("{STR_VAR_1} ha començat a picar-te\nla panxa.");
static const u8 sHappyMsg01[] = _("{STR_VAR_1} és feliç però vergonyós.");
static const u8 sHappyMsg02[] = _("{STR_VAR_1} ve content al teu costat.");
static const u8 sHappyMsg03[] = _("{STR_VAR_1} sembla tranquil.");
static const u8 sHappyMsg04[] = _("{STR_VAR_1} sembla sentir-se molt\nbé caminant amb tu!");
static const u8 sHappyMsg05[] = _("{STR_VAR_1} irradies salut.");
static const u8 sHappyMsg06[] = _("{STR_VAR_1} sembla molt feliç.");
static const u8 sHappyMsg07[] = _("{STR_VAR_1} s'ha esforçat molt.");
static const u8 sHappyMsg08[] = _("{STR_VAR_1} s'impregna dels aromes\nde l'aire del voltant.");
static const u8 sHappyMsg09[] = _("{STR_VAR_1} salta d'alegria!");
static const u8 sHappyMsg10[] = _("{STR_VAR_1} segueix sentint-se genial!");
static const u8 sHappyMsg11[] = _("El teu Pokémon ha ensumat\nuna olor de fum.");
static const u8 sHappyMsg12[] = _("{STR_VAR_1} et pica a la panxa.");
static const u8 sHappyMsg13[] = _("El teu Pokémon s'ha estirat\ni s'ha relaxat.");
static const u8 sHappyMsg14[] = _("{STR_VAR_1} sembla que vol\nanar al davant!");
static const u8 sHappyMsg15[] = _("{STR_VAR_1} s'esforça per\nseguir-te el ritme.");
static const u8 sHappyMsg16[] = _("{STR_VAR_1} s'arrecera a tu\namb entusiasme!");
static const u8 sHappyMsg17[] = _("{STR_VAR_1} rebosa de vida!");
static const u8 sHappyMsg18[] = _("{STR_VAR_1} sembla molt feliç!");
static const u8 sHappyMsg19[] = _("{STR_VAR_1} és tan feliç que\nno pot estar quiet!");
static const u8 sHappyMsg20[] = _("{STR_VAR_1} ha fet un cap lent.");
static const u8 sHappyMsg21[] = _("{STR_VAR_1} té moltes ganes!");
static const u8 sHappyMsg22[] = _("{STR_VAR_1} camina i escolta\nels sons del voltant.");
static const u8 sHappyMsg23[] = _("{STR_VAR_1} sembla molt interessat.");
static const u8 sHappyMsg24[] = _("{STR_VAR_1} s'esforça per\ncontinuar avançant.");
static const u8 sHappyMsg25[] = _("{STR_VAR_1} et mira radiant!");
static const u8 sHappyMsg26[] = _("{STR_VAR_1} et fa una mirada feliç\ni un somriure.");
static const u8 sHappyMsg27[] = _("El teu Pokémon ensuma\nl'aroma de les flors.");
static const u8 sHappyMsg28[] = _("{STR_VAR_1} sembla molt content\nde veure't!");
static const u8 sHappyMsg29[] = _("{STR_VAR_1} s'ha girat cap aquí\ni ha somrigut.");
static const u8 sHappyMsg30[] = _("{STR_VAR_1} s'ha arreconat a tu\namb entusiasme!");
  // Conditional messages begin here, index 31
static const u8 sHappyMsg31[] = _("El teu Pokémon sembla feliç\npel bon temps.");

const struct FollowerMsgInfo gFollowerHappyMessages[] = {
    {sHappyMsg00, EventScript_FollowerPokingPlayer},
    {sHappyMsg01}, {sHappyMsg02}, {sHappyMsg03}, {sHappyMsg04}, {sHappyMsg05}, {sHappyMsg06}, {sHappyMsg07},
    {sHappyMsg08, EventScript_FollowerLookAround},
    {sHappyMsg09, EventScript_FollowerHopping},
    {sHappyMsg10}, {sHappyMsg11},
    {sHappyMsg12, EventScript_FollowerPokingPlayer},
    {sHappyMsg13, EventScript_FollowerLookAround},
    {sHappyMsg14}, {sHappyMsg15},
    {sHappyMsg16, EventScript_FollowerCuddling},
    {sHappyMsg17}, {sHappyMsg18},
    {sHappyMsg19, EventScript_FollowerFastHopping},
    {sHappyMsg20}, {sHappyMsg21}, {sHappyMsg22}, {sHappyMsg23}, {sHappyMsg24}, {sHappyMsg25}, {sHappyMsg26}, {sHappyMsg27}, {sHappyMsg28}, {sHappyMsg29},
    {sHappyMsg30, EventScript_FollowerCuddling},
    {sHappyMsg31},
};

// Unconditional neutral messages
static const u8 sNeutralMsg00[] = _("{STR_VAR_1} pica el terra\nmetòdicament.");
static const u8 sNeutralMsg01[] = _("{STR_VAR_1} fa guàrdia.");
static const u8 sNeutralMsg02[] = _("{STR_VAR_1} mira pacientment\nel no-res.");
static const u8 sNeutralMsg03[] = _("{STR_VAR_1} camina sense rumb.");
static const u8 sNeutralMsg04[] = _("El teu Pokémon ha badallat\nfort!");
static const u8 sNeutralMsg05[] = _("El teu Pokémon mira al voltant\nneguitós.");
static const u8 sNeutralMsg06[] = _("{STR_VAR_1} et mira i somriu.");
static const u8 sNeutralMsg07[] = _("{STR_VAR_1} mira al voltant\nneguitós.");
static const u8 sNeutralMsg08[] = _("{STR_VAR_1} ha llançat un crit\nde combat.");
static const u8 sNeutralMsg09[] = _("{STR_VAR_1} ha ballat una\ndansa meravellosa!");
static const u8 sNeutralMsg10[] = _("{STR_VAR_1} té moltes ganes.");
static const u8 sNeutralMsg11[] = _("{STR_VAR_1} mira fixament\na la llunyania.");
static const u8 sNeutralMsg12[] = _("{STR_VAR_1} està alerta!");
static const u8 sNeutralMsg13[] = _("{STR_VAR_1} ha mirat a la llunyania\ni ha bordat!");

const struct FollowerMsgInfo gFollowerNeutralMessages[] = {
    {sNeutralMsg00, EventScript_FollowerPokeGround},
    {sNeutralMsg01},
    {sNeutralMsg02, EventScript_FollowerLookAway},
    {sNeutralMsg03, EventScript_FollowerLookAround},
    {sNeutralMsg04},
    {sNeutralMsg05, EventScript_FollowerLookAround},
    {sNeutralMsg06}, {sNeutralMsg07}, {sNeutralMsg08},
    {sNeutralMsg09, EventScript_FollowerDance},
    {sNeutralMsg10},
    {sNeutralMsg11, EventScript_FollowerLookAway},
    {sNeutralMsg12},
    {sNeutralMsg13, EventScript_FollowerLookAwayBark},
};

// Unconditional sad messages
static const u8 sSadMsg00[] = _("{STR_VAR_1} està marejat.");
static const u8 sSadMsg01[] = _("{STR_VAR_1} t'està trepitjant\nels peus!");
static const u8 sSadMsg02[] = _("{STR_VAR_1} sembla una mica cansat.");
  // Conditional messages begin, index 3
static const u8 sSadMsg03[] = _("{STR_VAR_1} no és feliç.");
static const u8 sSadMsg04[] = _("{STR_VAR_1} està a punt de caure!\n");
static const u8 sSadMsg05[] = _("{STR_VAR_1} sembla que s'anirà\na caure!");
static const u8 sSadMsg06[] = _("{STR_VAR_1} s'esforça molt per\nseguir-te el ritme...");

const struct FollowerMsgInfo gFollowerSadMessages[] = {
    {sSadMsg00, EventScript_FollowerDizzy},
    {sSadMsg01}, {sSadMsg02},
    {sSadMsg03}, {sSadMsg04}, {sSadMsg05}, {sSadMsg06},
};

// Unconditional upset messages
static const u8 sUpsetMsg00[] = _("{STR_VAR_1} sembla disgustat\nd'alguna manera...");
static const u8 sUpsetMsg01[] = _("{STR_VAR_1} fa una cara\nde disgust.");
static const u8 sUpsetMsg02[] = _(".....El teu Pokémon sembla\ntenir una mica de fred.");
  // Conditional messages, index 3
static const u8 sUpsetMsg03[] = _("{STR_VAR_1} s'aixopluga entre\nl'herba de la pluja.");

const struct FollowerMsgInfo gFollowerUpsetMessages[] = {
    {sUpsetMsg00}, {sUpsetMsg01},
    {sUpsetMsg02, EventScript_FollowerIsShivering},
    {sUpsetMsg03},
};

// Unconditional angry messages
static const u8 sAngryMsg00[] = _("{STR_VAR_1} ha rugit!");
static const u8 sAngryMsg01[] = _("{STR_VAR_1} fa una cara com\nsi estigués enfadat!");
static const u8 sAngryMsg02[] = _("{STR_VAR_1} sembla enfadat\nper alguna raó.");
static const u8 sAngryMsg03[] = _("El teu Pokémon s'ha girat d'esquena\namb una expressió desafiant.\p");
static const u8 sAngryMsg04[] = _("{STR_VAR_1} ha cridat.");

const struct FollowerMsgInfo gFollowerAngryMessages[] = {
    {sAngryMsg00}, {sAngryMsg01}, {sAngryMsg02},
    {sAngryMsg03, EventScript_FollowerLookAway},
    {sAngryMsg04},
};

// Unconditional pensive messages
static const u8 sPensiveMsg00[] = _("{STR_VAR_1} mira fixament\ncap avall.");
static const u8 sPensiveMsg01[] = _("{STR_VAR_1} inspecciona l'àrea.");
static const u8 sPensiveMsg02[] = _("{STR_VAR_1} s'inclina cap avall.");
static const u8 sPensiveMsg03[] = _("{STR_VAR_1} lluita per\nno adormir-se...");
static const u8 sPensiveMsg04[] = _("{STR_VAR_1} sembla que\ncamina sense rumb.");
static const u8 sPensiveMsg05[] = _("{STR_VAR_1} mira al voltant\ndistrètament.");
static const u8 sPensiveMsg06[] = _("{STR_VAR_1} ha badallat molt fort!");
static const u8 sPensiveMsg07[] = _("{STR_VAR_1} es relaxa còmodament.");
static const u8 sPensiveMsg08[] = _("{STR_VAR_1} et mira fixament\nsense apartar els ulls.");
static const u8 sPensiveMsg09[] = _("{STR_VAR_1} et mira intensament\na la cara.");
static const u8 sPensiveMsg10[] = _("{STR_VAR_1} centra tota\nla seva atenció en tu.");
static const u8 sPensiveMsg11[] = _("{STR_VAR_1} mira fixament\ncap a les profunditats.");
static const u8 sPensiveMsg12[] = _("{STR_VAR_1} ensuma\nel terra.");
static const u8 sPensiveMsg13[] = _("El teu Pokémon mira fixament\nel no-res.");
static const u8 sPensiveMsg14[] = _("{STR_VAR_1} s'ha concentrat\namb una mirada aguda!");
static const u8 sPensiveMsg15[] = _("{STR_VAR_1} s'està concentrant.");
static const u8 sPensiveMsg16[] = _("{STR_VAR_1} s'ha girat cap aquí\ni ha fet que sí.");
static const u8 sPensiveMsg17[] = _("{STR_VAR_1} sembla una mica nerviós...");
static const u8 sPensiveMsg18[] = _("{STR_VAR_1} mira les teves\npetjades.");
static const u8 sPensiveMsg19[] = _("{STR_VAR_1} et mira fixament\nals ulls.");

const struct FollowerMsgInfo gFollowerPensiveMessages[] = {
    {sPensiveMsg00},
    {sPensiveMsg01, EventScript_FollowerLookAround},
    {sPensiveMsg02}, {sPensiveMsg03}, {sPensiveMsg04},
    {sPensiveMsg05, EventScript_FollowerLookAround},
    {sPensiveMsg06}, {sPensiveMsg07}, {sPensiveMsg08}, {sPensiveMsg09}, {sPensiveMsg10},
    {sPensiveMsg11, EventScript_FollowerLookAway},
    {sPensiveMsg12, EventScript_FollowerPokeGround},
    {sPensiveMsg13, EventScript_FollowerLookAway},
    {sPensiveMsg14}, {sPensiveMsg15}, {sPensiveMsg16}, {sPensiveMsg17}, {sPensiveMsg18}, {sPensiveMsg19},
};

// All 'love' messages are unconditional
static const u8 sLoveMsg00[] = _("{STR_VAR_1} de sobte ha começat\na caminar més a prop!");
static const u8 sLoveMsg01[] = _("Les galtes de {STR_VAR_1}\nes tornen rosades!");
static const u8 sLoveMsg02[] = _("Vaja! {STR_VAR_1} de sobte\net ha abraçat!");
static const u8 sLoveMsg03[] = _("Vaja! {STR_VAR_1} de sobte\nté ganes de jugar!");
static const u8 sLoveMsg04[] = _("{STR_VAR_1} et frega\ncontra les cames!");
static const u8 sLoveMsg05[] = _("{STR_VAR_1} s'ha posat vermell.");
static const u8 sLoveMsg06[] = _("Ah! {STR_VAR_1} t'acotxa!");
static const u8 sLoveMsg07[] = _("{STR_VAR_1} et mira\namb adoració!");
static const u8 sLoveMsg08[] = _("{STR_VAR_1} s'ha acostat a tu.");
static const u8 sLoveMsg09[] = _("{STR_VAR_1} et segueix de ben a prop.");

const struct FollowerMsgInfo gFollowerLoveMessages[] = {
    {sLoveMsg00, EventScript_FollowerGetCloser},
    {sLoveMsg01},
    {sLoveMsg02, EventScript_FollowerCuddling},
    {sLoveMsg03},
    {sLoveMsg04, EventScript_FollowerCuddling},
    {sLoveMsg05},
    {sLoveMsg06, EventScript_FollowerCuddling},
    {sLoveMsg07},
    {sLoveMsg08, EventScript_FollowerGetCloser},
    {sLoveMsg09},
};

// Unconditional surprised messages
static const u8 sSurpriseMsg00[] = _("{STR_VAR_1} corre perill\nde caure!");
static const u8 sSurpriseMsg01[] = _("{STR_VAR_1} t'ha topat!");
static const u8 sSurpriseMsg02[] = _("{STR_VAR_1} encara no sembla\nacomodat al seu nom.");
static const u8 sSurpriseMsg03[] = _("{STR_VAR_1} s'inclina cap avall.");
static const u8 sSurpriseMsg04[] = _("El teu Pokémon ha ensopegat\ni gairebé ha caigut!");
static const u8 sSurpriseMsg05[] = _("{STR_VAR_1} sent alguna cosa\ni udola!");
static const u8 sSurpriseMsg06[] = _("{STR_VAR_1} sembla renovat!");
static const u8 sSurpriseMsg07[] = _("{STR_VAR_1} de sobte s'ha girat\ni ha começat a bordar!");
static const u8 sSurpriseMsg08[] = _("{STR_VAR_1} de sobte s'ha girat!");
static const u8 sSurpriseMsg09[] = _("El teu Pokémon s'ha sorprès\nque li parlessis de sobte!");
static const u8 sSurpriseMsg10[] = _("Snif snif, fa una olor\nmolt bona!");
static const u8 sSurpriseMsg11[] = _("{STR_VAR_1} se sent renovat.");
static const u8 sSurpriseMsg12[] = _("{STR_VAR_1} vacil·la i sembla\nque anirà a caure.");
static const u8 sSurpriseMsg13[] = _("{STR_VAR_1} corre perill\nde caure.");
static const u8 sSurpriseMsg14[] = _("{STR_VAR_1} camina\namb precaució.");
static const u8 sSurpriseMsg15[] = _("{STR_VAR_1} es posa tens\nde nerviosisme.");
static const u8 sSurpriseMsg16[] = _("{STR_VAR_1} ha notat alguna cosa\nrara i s'ha sorprès!");
static const u8 sSurpriseMsg17[] = _("{STR_VAR_1} s'ha espantat i\ns'ha arreconat a tu!");
static const u8 sSurpriseMsg18[] = _("{STR_VAR_1} nota una presència\ninusual...");
static const u8 sSurpriseMsg19[] = _("{STR_VAR_1} es posa tens\nde nerviosisme.");
  // Conditional messages, index 20
static const u8 sSurpriseMsg20[] = _("{STR_VAR_1} sembla molt sorprès\nque estigui plovent!");

const struct FollowerMsgInfo gFollowerSurpriseMessages[] = {
    {sSurpriseMsg00},
    {sSurpriseMsg01, EventScript_FollowerPokingPlayer},
    {sSurpriseMsg02}, {sSurpriseMsg03}, {sSurpriseMsg04}, {sSurpriseMsg05}, {sSurpriseMsg06},
    {sSurpriseMsg07, EventScript_FollowerLookAwayBark},
    {sSurpriseMsg08, EventScript_FollowerLookAway},
    {sSurpriseMsg09},
    {sSurpriseMsg10, EventScript_FollowerLookAround},
    {sSurpriseMsg11}, {sSurpriseMsg12}, {sSurpriseMsg13}, {sSurpriseMsg14}, {sSurpriseMsg15}, {sSurpriseMsg16},
    {sSurpriseMsg17, EventScript_FollowerCuddling},
    {sSurpriseMsg18},
    {sSurpriseMsg19, EventScript_FollowerLookAround},
    {sSurpriseMsg20},
};

// Unconditional curious messages
static const u8 sCuriousMsg00[] = _("El teu Pokémon mira al voltant\nneguitós buscant alguna cosa.");
static const u8 sCuriousMsg01[] = _("El teu Pokémon no mirava on\nanava i ha topat amb tu!");
static const u8 sCuriousMsg02[] = _("Snif, snif! Hi ha alguna cosa\na prop?");
static const u8 sCuriousMsg03[] = _("{STR_VAR_1} fa rodar una pedrola\njuganer.");
static const u8 sCuriousMsg04[] = _("{STR_VAR_1} camina sense rumb\nbuscant alguna cosa.");
static const u8 sCuriousMsg05[] = _("{STR_VAR_1} t'ensuma.");
static const u8 sCuriousMsg06[] = _("{STR_VAR_1} sembla una mica\nindecís...");

const struct FollowerMsgInfo gFollowerCuriousMessages[] = {
    {sCuriousMsg00, EventScript_FollowerLookAround},
    {sCuriousMsg01, EventScript_FollowerPokingPlayer},
    {sCuriousMsg02}, {sCuriousMsg03},
    {sCuriousMsg04, EventScript_FollowerLookAround},
    {sCuriousMsg05}, {sCuriousMsg06},
};

// Unconditional music messages
static const u8 sMusicMsg00[] = _("{STR_VAR_1} fa gala\nde la seva agilitat!");
static const u8 sMusicMsg01[] = _("{STR_VAR_1} es mou\namb alegria!");
static const u8 sMusicMsg02[] = _("Vaja! {STR_VAR_1} de sobte\nha começat a ballar d'alegria!");
static const u8 sMusicMsg03[] = _("{STR_VAR_1} et segueix\namb constància!");
static const u8 sMusicMsg04[] = _("{STR_VAR_1} sembla que vol\njugar amb tu.");
static const u8 sMusicMsg05[] = _("{STR_VAR_1} salta content.");
static const u8 sMusicMsg06[] = _("{STR_VAR_1} canta i tarareja.");
static const u8 sMusicMsg07[] = _("{STR_VAR_1} et mossega els peus!");
static const u8 sMusicMsg08[] = _("{STR_VAR_1} es gira i et mira.");
static const u8 sMusicMsg09[] = _("{STR_VAR_1} s'esforça per mostrar\nla seva gran força!");
static const u8 sMusicMsg10[] = _("Vaja! {STR_VAR_1} de sobte\nha ballat d'alegria!");
static const u8 sMusicMsg11[] = _("{STR_VAR_1} és molt animat!");
static const u8 sMusicMsg12[] = _("{STR_VAR_1} salta d'un costat\na l'altre despreocupat!");
static const u8 sMusicMsg13[] = _("El teu Pokémon sembla ensumar\nuna olor nostàlgicament familiar...");
// Conditional music messages, index 14
static const u8 sMusicMsg14[] = _("{STR_VAR_1} és molt feliç\npela pluja.");

const struct FollowerMsgInfo gFollowerMusicMessages[] = {
    {sMusicMsg00, EventScript_FollowerLookAround},
    {sMusicMsg01},
    {sMusicMsg02, EventScript_FollowerDance},
    {sMusicMsg03},
    {sMusicMsg04, EventScript_FollowerHopping},
    {sMusicMsg05, EventScript_FollowerHopping},
    {sMusicMsg06}, {sMusicMsg07}, {sMusicMsg08}, {sMusicMsg09},
    {sMusicMsg10, EventScript_FollowerDance},
    {sMusicMsg11},
    {sMusicMsg12, EventScript_FollowerHopping},
    {sMusicMsg13, EventScript_FollowerNostalgia},
    {sMusicMsg14}
};


static const u8 sPoisonedMsg00[] = _("{STR_VAR_1} tremola pels\nefectes del verí.");

const struct FollowerMsgInfo gFollowerPoisonedMessages[] = {
    {sPoisonedMsg00, EventScript_FollowerIsShivering},
};

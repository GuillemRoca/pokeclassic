ALIGNED(4) static const u8 sText_EmptyString[] = _("");
ALIGNED(4) static const u8 sText_Colon[] = _(":");
ALIGNED(4) static const u8 sText_ID[] = _("{ID}");
ALIGNED(4) static const u8 sText_PleaseStartOver[] = _("Please start over from the beginning.");
ALIGNED(4) static const u8 sText_WirelessSearchCanceled[] = _("The Wireless Communication\nSystem search has been canceled.");
ALIGNED(4) static const u8 sText_AwaitingCommunucation2[] = _("Awaiting communication\nfrom another player."); // Unused
ALIGNED(4) static const u8 sText_AwaitingCommunication[] = _("{STR_VAR_1}! Awaiting\ncommunication from another player.");
ALIGNED(4) static const u8 sText_AwaitingLinkPressStart[] = _("{STR_VAR_1}! Awaiting link!\nPress Start when everyone's ready.");
ALIGNED(4) static const u8 sJPText_SingleBattle[] = _("シングルバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_DoubleBattle[] = _("ダブルバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_MultiBattle[] = _("マルチバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_TradePokemon[] = _("ポケモンこうかんを かいさいする");
ALIGNED(4) static const u8 sJPText_Chat[] = _("チャットを かいさいする");
ALIGNED(4) static const u8 sJPText_DistWonderCard[] = _("ふしぎなカードをくばる");
ALIGNED(4) static const u8 sJPText_DistWonderNews[] = _("ふしぎなニュースをくばる");
ALIGNED(4) static const u8 sJPText_DistMysteryEvent[] = _("ふしぎなできごとを かいさいする"); // Unused
ALIGNED(4) static const u8 sJPText_HoldPokemonJump[] = _("なわとびを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldBerryCrush[] = _("きのみマッシャーを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldBerryPicking[] = _("きのみどりを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldSpinTrade[] = _("ぐるぐるこうかんを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldSpinShop[] = _("ぐるぐるショップを かいさいする");

// Unused
static const u8 *const sJPLinkGroupActionTexts[] = {
    sJPText_SingleBattle,
    sJPText_DoubleBattle,
    sJPText_MultiBattle,
    sJPText_TradePokemon,
    sJPText_Chat,
    sJPText_DistWonderCard,
    sJPText_DistWonderNews,
    sJPText_DistWonderCard,
    sJPText_HoldPokemonJump,
    sJPText_HoldBerryCrush,
    sJPText_HoldBerryPicking,
    sJPText_HoldBerryPicking,
    sJPText_HoldSpinTrade,
    sJPText_HoldSpinShop
};

static const u8 sText_1PlayerNeeded[] = _("1 player\nneeded.");
static const u8 sText_2PlayersNeeded[] = _("2 players\nneeded.");
static const u8 sText_3PlayersNeeded[] = _("3 players\nneeded.");
static const u8 sText_4PlayersNeeded[] = _("4 players\nneeded.");
static const u8 sText_2PlayerMode[] = _("2-Player\nMode");
static const u8 sText_3PlayerMode[] = _("3-Player\nMode");
static const u8 sText_4PlayerMode[] = _("4-Player\nMode");
static const u8 sText_5PlayerMode[] = _("5-Player\nMode");

static const u8 *const sPlayersNeededOrModeTexts[][5] = {
    // 2 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode
    },
    // 4 players required
    {
        sText_3PlayersNeeded,
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_4PlayerMode
    },
    // 2-5 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 3-5 players required
    {
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 2-4 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode
    }
};

ALIGNED(4) static const u8 sText_BButtonCancel[] = _("{B_BUTTON}Cancel");
ALIGNED(4) static const u8 sJPText_SearchingForParticipants[] = _("ため\nさんかしゃ ぼしゅうちゅう です！"); // Unused, may have been cut off
ALIGNED(4) static const u8 sText_PlayerContactedYouForXAccept[] = _("{STR_VAR_2} contacted you for\n{STR_VAR_1}. Accept?");
ALIGNED(4) static const u8 sText_PlayerContactedYouShareX[] = _("{STR_VAR_2} contacted you.\nWill you share {STR_VAR_1}?");
ALIGNED(4) static const u8 sText_PlayerContactedYouAddToMembers[] = _("{STR_VAR_2} contacted you.\nAdd to the members?");
ALIGNED(4) static const u8 sText_AreTheseMembersOK[] = _("{STR_VAR_1}!\nAre these members Ok?");
ALIGNED(4) static const u8 sText_CancelModeWithTheseMembers[] = _("Cancel {STR_VAR_1} Mode\nwith these members?");
ALIGNED(4) static const u8 sText_AnOKWasSentToPlayer[] = _("An “Ok” was sent\nto {STR_VAR_1}.");
ALIGNED(4) static const u8 sText_OtherTrainerUnavailableNow[] = _("The other Trainer doesn't appear\nto be available now…\p");
ALIGNED(4) static const u8 sText_CantTransmitTrainerTooFar[] = _("You can't transmit with a Trainer\nwho is too far away.\p");
ALIGNED(4) static const u8 sText_TrainersNotReadyYet[] = _("The other Trainer(s) is/are not\nready yet.\p");

static const u8 *const sCantTransmitToTrainerTexts[] = {
    [UR_TRADE_PLAYER_NOT_READY - 1]  = sText_CantTransmitTrainerTooFar,
    [UR_TRADE_PARTNER_NOT_READY - 1] = sText_TrainersNotReadyYet
};

ALIGNED(4) static const u8 sText_ModeWithTheseMembersWillBeCanceled[] = _("The {STR_VAR_1} Mode with\nthese members will be canceled.{PAUSE 60}");
ALIGNED(4) static const u8 sText_MemberNoLongerAvailable[] = _("There is a member who can no\nlonger remain available.\p");

static const u8 *const sPlayerUnavailableTexts[] = {
    sText_OtherTrainerUnavailableNow,
    sText_MemberNoLongerAvailable
};

ALIGNED(4) static const u8 sText_TrainerAppearsUnavailable[] = _("L'altre Entrenador sembla\nno estar disponible…\p");
ALIGNED(4) static const u8 sText_PlayerSentBackOK[] = _("{STR_VAR_1} ha enviat un “D'acord”!");
ALIGNED(4) static const u8 sText_PlayerOKdRegistration[] = _("{STR_VAR_1} ha acceptat el teu\nregistre com a membre.");
ALIGNED(4) static const u8 sText_PlayerRepliedNo[] = _("{STR_VAR_1} ha respost “No…”\p");
ALIGNED(4) static const u8 sText_AwaitingOtherMembers[] = _("{STR_VAR_1}!\nEsperant altres membres!");
ALIGNED(4) static const u8 sText_QuitBeingMember[] = _("Deixar de ser membre?");
ALIGNED(4) static const u8 sText_StoppedBeingMember[] = _("Has deixat de ser membre.\p");

static const u8 *const sPlayerDisconnectedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_MemberNoLongerAvailable,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_TrainerAppearsUnavailable,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = sText_StoppedBeingMember
};

ALIGNED(4) static const u8 sText_WirelessLinkEstablished[] = _("La connexió del Sistema Sense\nFil s'ha establert.");
ALIGNED(4) static const u8 sText_WirelessLinkDropped[] = _("La connexió del Sistema Sense\nFil s'ha perdut…");
ALIGNED(4) static const u8 sText_LinkWithFriendDropped[] = _("La connexió amb el teu amic\ns'ha perdut…");
ALIGNED(4) static const u8 sText_PlayerRepliedNo2[] = _("{STR_VAR_1} ha respost “No…”");

static const u8 *const sLinkDroppedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_LinkWithFriendDropped,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_LinkWithFriendDropped,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo2,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = NULL
};

ALIGNED(4) static const u8 sText_DoYouWantXMode[] = _("Vols el mode\n{STR_VAR_2}?");
ALIGNED(4) static const u8 sText_DoYouWantXMode2[] = _("Vols el mode\n{STR_VAR_2}?");

// Unused
static const u8 *const sDoYouWantModeTexts[] = {
    sText_DoYouWantXMode,
    sText_DoYouWantXMode2
};

ALIGNED(4) static const u8 sText_CommunicatingPleaseWait[] = _("Comunicant…\nSi us plau, espera."); // Unused
ALIGNED(4) static const u8 sText_AwaitingPlayersResponseAboutTrade[] = _("Esperant la resposta de {STR_VAR_1}\nsobre l'intercanvi…");
ALIGNED(4) static const u8 sText_Communicating[] = _("Comunicant{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
                                                     "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_CommunicatingWithPlayer[] = _("Comunicant amb {STR_VAR_1}{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
                                                               "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_PleaseWaitAWhile[] = _("Si us plau, espera{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
                                                        "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");

static const u8 *const sCommunicatingWaitTexts[] = {
    sText_Communicating,
    sText_CommunicatingWithPlayer,
    sText_PleaseWaitAWhile
};

ALIGNED(4) static const u8 sText_HiDoSomethingMale[] = _("Ep! Hi ha alguna cosa que\nvulguis fer?");
ALIGNED(4) static const u8 sText_HiDoSomethingFemale[] = _("Hola!\nVols fer alguna cosa?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainMale[] = _("{STR_VAR_1}: Ep, ens tornem a veure!\nQuè vols fer ara?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainFemale[] = _("{STR_VAR_1}: Oh! {PLAYER}, hola!\nVols fer alguna cosa?");

static const u8 *const sHiDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_HiDoSomethingMale,
        sText_HiDoSomethingFemale
    }, {
        sText_HiDoSomethingAgainMale,
        sText_HiDoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_DoSomethingMale[] = _("Vols fer alguna cosa?");
ALIGNED(4) static const u8 sText_DoSomethingFemale[] = _("Vols fer alguna cosa?");
ALIGNED(4) static const u8 sText_DoSomethingAgainMale[] = _("{STR_VAR_1}: Què vols fer\nara?");
ALIGNED(4) static const u8 sText_DoSomethingAgainFemale[] = _("{STR_VAR_1}: Vols fer alguna altra cosa?"); // Unused

// Unused
static const u8 *const sDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_DoSomethingMale,
        sText_DoSomethingFemale
    }, {
        sText_DoSomethingAgainMale,
        sText_DoSomethingAgainMale // was probably supposed to be sText_DoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_SomebodyHasContactedYou[] = _("Algú t'ha contactat.{PAUSE 60}");
ALIGNED(4) static const u8 sText_PlayerHasContactedYou[] = _("{STR_VAR_1} t'ha contactat.{PAUSE 60}");

static const u8 *const sPlayerContactedYouTexts[] = {
    sText_SomebodyHasContactedYou,
    sText_PlayerHasContactedYou
};

ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer[] = _("Esperant resposta de\nl'altre Entrenador…");
ALIGNED(4) static const u8 sText_AwaitingResponseFromPlayer[] = _("Esperant resposta de\n{STR_VAR_1}…");

static const u8 *const sAwaitingResponseTexts[] = {
    sText_AwaitingResponseFromTrainer,
    sText_AwaitingResponseFromPlayer
};

ALIGNED(4) static const u8 sText_ShowTrainerCard[] = _("L'altre Entrenador t'ha ensenyat\nla seva Targeta d'Entrenador.\pVols ensenyar la teva\nTargeta d'Entrenador?");
ALIGNED(4) static const u8 sText_BattleChallenge[] = _("L'altre Entrenador et desafia\na un combat.\pAcceptes el desafiament\nde combat?");
ALIGNED(4) static const u8 sText_ChatInvitation[] = _("L'altre Entrenador et convida\na xatejar.\pAcceptes la invitació\na xatejar?");
ALIGNED(4) static const u8 sText_OfferToTradeMon[] = _("Hi ha una oferta per intercanviar\nel teu Nv. {DYNAMIC 0} {DYNAMIC 1}\pa canvi d'un\nNv. {DYNAMIC 2} {DYNAMIC 3}.\pAcceptes l'oferta\nd'intercanvi?");
ALIGNED(4) static const u8 sText_OfferToTradeEgg[] = _("Hi ha una oferta per intercanviar\nel teu Ou registrat.\lAcceptes l'oferta d'intercanvi?");
ALIGNED(4) static const u8 sText_ChatDropped[] = _("El xat s'ha tancat.\p");
ALIGNED(4) static const u8 sText_OfferDeclined1[] = _("Has rebutjat l'oferta.\p");
ALIGNED(4) static const u8 sText_OfferDeclined2[] = _("Has rebutjat l'oferta.\p");
ALIGNED(4) static const u8 sText_ChatEnded[] = _("El xat ha acabat.\p");

// Unused
static const u8 *const sInvitationTexts[] = {
    sText_ShowTrainerCard,
    sText_BattleChallenge,
    sText_ChatInvitation,
    sText_OfferToTradeMon
};

ALIGNED(4) static const u8 sText_JoinChatMale[] = _("Ei! Ara estem en un xat.\nVols unir-t'hi?");
ALIGNED(4) static const u8 sText_PlayerJoinChatMale[] = _("{STR_VAR_1}: Ei, {PLAYER}!\nAra estem xatejant.\lVols unir-t'hi?");
ALIGNED(4) static const u8 sText_JoinChatFemale[] = _("Hola! Ara estem en un xat.\nVols unir-t'hi?");
ALIGNED(4) static const u8 sText_PlayerJoinChatFemale[] = _("{STR_VAR_1}: Hola, {PLAYER}!\nAra estem en un xat.\lVols unir-t'hi?");

static const u8 *const sJoinChatTexts[][GENDER_COUNT] = {
    {
        sText_JoinChatMale,
        sText_JoinChatFemale
    }, {
        sText_PlayerJoinChatMale,
        sText_PlayerJoinChatFemale
    }
};

ALIGNED(4) static const u8 sText_TrainerAppearsBusy[] = _("……\nL'Entrenador sembla ocupat…\p");
ALIGNED(4) static const u8 sText_WaitForBattleMale[] = _("Un combat, eh?\nD'acord, dona'm una mica de temps.");
ALIGNED(4) static const u8 sText_WaitForChatMale[] = _("Vols xatejar, eh?\nÉs clar, espera una mica.");
ALIGNED(4) static const u8 sText_ShowTrainerCardMale[] = _("És clar! Com a salutació,\naquí tens la meva Targeta.");
ALIGNED(4) static const u8 sText_WaitForBattleFemale[] = _("Un combat? És clar, però necessito\ntemps per preparar-me.");
ALIGNED(4) static const u8 sText_WaitForChatFemale[] = _("Volies xatejar?\nD'acord, però espera un moment.");
ALIGNED(4) static const u8 sText_ShowTrainerCardFemale[] = _("Com a presentació, et mostraré\nla meva Targeta d'Entrenador.");

static const u8 *const sText_WaitOrShowCardTexts[GENDER_COUNT][4] = {
    {
        sText_WaitForBattleMale,
        sText_WaitForChatMale,
        NULL,
        sText_ShowTrainerCardMale
    }, {
        sText_WaitForBattleFemale,
        sText_WaitForChatFemale,
        NULL,
        sText_ShowTrainerCardFemale
    }
};

ALIGNED(4) static const u8 sText_WaitForChatMale2[] = _("Vols xatejar, eh?\nÉs clar, espera una mica."); // Unused
ALIGNED(4) static const u8 sText_DoneWaitingBattleMale[] = _("Gràcies per esperar!\nComencem el combat!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatMale[] = _("D'acord!\nXatejem!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingBattleFemale[] = _("Perdona per l'espera!\nComencem!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatFemale[] = _("Perdona per l'espera!\nXatejem.{PAUSE 60}");
ALIGNED(4) static const u8 sText_TradeWillBeStarted[] = _("L'intercanvi començarà.{PAUSE 60}");
ALIGNED(4) static const u8 sText_BattleWillBeStarted[] = _("El combat començarà.{PAUSE 60}");
ALIGNED(4) static const u8 sText_EnteringChat[] = _("Entrant al xat…{PAUSE 60}");

static const u8 *const sStartActivityTexts[][GENDER_COUNT][3] = {
    {
        {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }, {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }
    }, {
        {
            sText_DoneWaitingBattleMale,
            sText_DoneWaitingChatMale,
            sText_TradeWillBeStarted
        }, {
            sText_DoneWaitingBattleFemale,
            sText_DoneWaitingChatFemale,
            sText_TradeWillBeStarted
        }
    }
};

ALIGNED(4) static const u8 sText_BattleDeclinedMale[] = _("Perdona! Els meus Pokémon no\nsemblen estar gaire bé ara.\lCombatem un altre dia.\p");
ALIGNED(4) static const u8 sText_BattleDeclinedFemale[] = _("Ho sento molt, però els meus\nPokémon no es troben bé…\pCombatem un altre dia.\p");

static const u8 *const sBattleDeclinedTexts[GENDER_COUNT] = {
    sText_BattleDeclinedMale,
    sText_BattleDeclinedFemale
};

ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedMale[] = _("Eh? La meva Targeta…\nOn l'he posat?\lPerdona! Te la ensenyaré un altre dia!\p");
ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedFemale[] = _("Oh? On he posat la meva\nTargeta d'Entrenador?…\lPerdona! Te la ensenyaré més tard!\p");

static const u8 *const sShowTrainerCardDeclinedTexts[GENDER_COUNT] = {
    sText_ShowTrainerCardDeclinedMale,
    sText_ShowTrainerCardDeclinedFemale
};

ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingMale[] = _("Si vols fer alguna cosa amb mi,\nnomés has de cridar-me!\p");
ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingFemale[] = _("Si vols fer alguna cosa amb mi,\nno siguis tímid.\p");

static const u8 *const sIfYouWantToDoSomethingTexts[GENDER_COUNT] = {
    sText_IfYouWantToDoSomethingMale,
    sText_IfYouWantToDoSomethingFemale
};

ALIGNED(4) static const u8 sText_TrainerBattleBusy[] = _("Ui! Perdona, he de fer una\naltra cosa.\lUn altre dia, d'acord?\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower1[] = _("Per combatre, necessites dos\nPokémon per sota del\lNv. 30.\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower2[] = _("Per combatre, necessites dos\nPokémon per sota del Nv. 30.\p");

ALIGNED(4) static const u8 sText_DeclineChatMale[] = _("Ah, d'acord.\nVine quan vulguis, eh?\p");
ALIGNED(4) static const u8 stext_DeclineChatFemale[] = _("Oh…\nVine quan vulguis.\p");

// Response from partner when player declines chat
static const u8 *const sDeclineChatTexts[GENDER_COUNT] = {
    sText_DeclineChatMale,
    stext_DeclineChatFemale
};

ALIGNED(4) static const u8 sText_ChatDeclinedMale[] = _("Oh, perdona!\nAra mateix no puc.\lXatejem un altre dia.\p");
ALIGNED(4) static const u8 sText_ChatDeclinedFemale[] = _("Oh, ho sento.\nTinc massa coses a fer ara.\lXatejem un altre dia.\p");

// Response from partner when they decline chat
static const u8 *const sChatDeclinedTexts[GENDER_COUNT] = {
    sText_ChatDeclinedMale,
    sText_ChatDeclinedFemale
};

ALIGNED(4) static const u8 sText_YoureToughMale[] = _("Uau!\nEs nota que ets molt fort!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveMale[] = _("Has usat aquell moviment?\nBona estratègia!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseMale[] = _("Molt bé!\nAixò m'ha sorprès!\p");
ALIGNED(4) static const u8 sText_SwitchedMonsMale[] = _("Oh! Com pots usar aquell\nPokémon en aquesta situació?\p");
ALIGNED(4) static const u8 sText_YoureToughFemale[] = _("Aquell Pokémon…\nEstà molt ben criat!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveFemale[] = _("Això és!\nAquest és el moviment correcte!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseFemale[] = _("Genial!\nPots combatre així?\p");
ALIGNED(4) static const u8 sText_SwitchedMonsFemale[] = _("Tens un timing exquisit per\ncanviar de Pokémon!\p");

static const u8 *const sBattleReactionTexts[GENDER_COUNT][4] = {
    {
        sText_YoureToughMale,
        sText_UsedGoodMoveMale,
        sText_BattleSurpriseMale,
        sText_SwitchedMonsMale
    },
    {
        sText_YoureToughFemale,
        sText_UsedGoodMoveFemale,
        sText_BattleSurpriseFemale,
        sText_SwitchedMonsFemale
    }
};

ALIGNED(4) static const u8 sText_LearnedSomethingMale[] = _("Oh, ja veig!\nAixò és instructiu!\p");
ALIGNED(4) static const u8 sText_ThatsFunnyMale[] = _("No diguis més coses gracioses!\nEm fa mal de tant riure!\p");
ALIGNED(4) static const u8 sText_RandomChatMale1[] = _("Oh?\nAixò va passar.\p");
ALIGNED(4) static const u8 sText_RandomChatMale2[] = _("Hmhm… Què?\nAixò és el que dius?\p");
ALIGNED(4) static const u8 sText_LearnedSomethingFemale[] = _("De debò?\nNo ho sabia.\p");
ALIGNED(4) static const u8 sText_ThatsFunnyFemale[] = _("Ahaha!\nDe què va això?\p");
ALIGNED(4) static const u8 sText_RandomChatFemale1[] = _("Sí, exacte!\nAixò és el que volia dir.\p");
ALIGNED(4) static const u8 sText_RandomChatFemale2[] = _("En altres paraules…\nSí! Correcte!\p");

static const u8 *const sChatReactionTexts[GENDER_COUNT][4] = {
    {
        sText_LearnedSomethingMale,
        sText_ThatsFunnyMale,
        sText_RandomChatMale1,
        sText_RandomChatMale2
    },
    {
        sText_LearnedSomethingFemale,
        sText_ThatsFunnyFemale,
        sText_RandomChatFemale1,
        sText_RandomChatFemale2
    }
};

ALIGNED(4) static const u8 sText_ShowedTrainerCardMale1[] = _("Només ensenyo la meva Targeta\ncom a salutació.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardMale2[] = _("Espero conèixer-te millor!\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale1[] = _("Ens ensenyem les Targetes per\nconèixer-nos.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale2[] = _("Encantada de conèixer-te.\nNo siguis un desconegut!\p");

static const u8 *const sTrainerCardReactionTexts[GENDER_COUNT][2] = {
    {
        sText_ShowedTrainerCardMale1,
        sText_ShowedTrainerCardMale2
    },
    {
        sText_ShowedTrainerCardFemale1,
        sText_ShowedTrainerCardFemale2
    }
};

ALIGNED(4) static const u8 sText_MaleTraded1[] = _("Sííí!\nDe veritat volia aquest Pokémon!\p");
ALIGNED(4) static const u8 sText_MaleTraded2[] = _("Per fi, un intercanvi m'ha donat\nel Pokémon que volia fa temps.\p");
ALIGNED(4) static const u8 sText_FemaleTraded1[] = _("Ara estic intercanviant Pokémon.\p");
ALIGNED(4) static const u8 sText_FemaleTraded2[] = _("Per fi tinc el Pokémon que volia\ngràcies a un intercanvi!\p");

static const u8 *const sTradeReactionTexts[GENDER_COUNT][4] = {
    {
        sText_MaleTraded1,
        sText_MaleTraded2
    },
    {
        sText_FemaleTraded1,
        sText_FemaleTraded2
    }
};

ALIGNED(4) static const u8 sText_XCheckedTradingBoard[] = _("{STR_VAR_1} ha consultat el\nTauler d'Intercanvi.\p");
ALIGNED(4) static const u8 sText_RegisterMonAtTradingBoard[] = _("Benvingut al Tauler d'Intercanvi.\pPots registrar el teu Pokémon\ni oferir-lo per intercanviar.\pVols registrar un dels\nteus Pokémon?");
ALIGNED(4) static const u8 sText_TradingBoardInfo[] = _("Aquest Tauler d'Intercanvi serveix\n"
                                                        "per oferir Pokémon a intercanviar.\p"
                                                        "Només has de registrar un\n"
                                                        "Pokémon per intercanviar.\p"
                                                        "Un altre Entrenador pot oferir un\n"
                                                        "Pokémon a canvi.\p"
                                                        "Esperem que registris Pokémon\n"
                                                        "i els intercanviïs amb molts\l"
                                                        "altres Entrenadors.\p"
                                                        "Vols registrar un dels\nteus Pokémon?");
ALIGNED(4) static const u8 sText_ThankYouForRegistering[] = _("Hem registrat el teu Pokémon per\nintercanviar al Tauler.\pGràcies per usar el servei!\p"); // unused
ALIGNED(4) static const u8 sText_NobodyHasRegistered[] = _("Ningú ha registrat cap Pokémon\nper intercanviar al Tauler.\p\n"); // unused
ALIGNED(4) static const u8 sText_ChooseRequestedMonType[] = _("Tria el tipus de Pokémon\nque vols rebre a l'intercanvi.\n");
ALIGNED(4) static const u8 sText_WhichMonWillYouOffer[] = _("Quin dels teus Pokémon\noferiràs a l'intercanvi?\p");
ALIGNED(4) static const u8 sText_RegistrationCanceled[] = _("El registre s'ha cancel·lat.\p");
ALIGNED(4) static const u8 sText_RegistraionCompleted[] = _("El registre s'ha completat.\p");
ALIGNED(4) static const u8 sText_TradeCanceled[] = _("L'intercanvi s'ha cancel·lat.\p");
ALIGNED(4) static const u8 sText_CancelRegistrationOfMon[] = _("Cancel·lar el registre del teu\nNv. {STR_VAR_2} {STR_VAR_1}?");
ALIGNED(4) static const u8 sText_CancelRegistrationOfEgg[] = _("Cancel·lar el registre del\nteu Ou?");
ALIGNED(4) static const u8 sText_RegistrationCanceled2[] = _("El registre s'ha cancel·lat.\p");
ALIGNED(4) static const u8 sText_TradeTrainersWillBeListed[] = _("Es llistaran els Entrenadors que\nvolen fer un intercanvi."); // unused
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith2[] = _("Tria l'Entrenador amb qui\nvols intercanviar Pokémon."); // unused
ALIGNED(4) static const u8 sText_AskTrainerToMakeTrade[] = _("Vols demanar a {STR_VAR_1} que\nfaci un intercanvi?");
ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer2[] = _("Esperant resposta de\nl'altre Entrenador…"); // unused
ALIGNED(4) static const u8 sText_NotRegisteredAMonForTrade[] = _("No has registrat cap Pokémon\nper intercanviar.\p"); // unused
ALIGNED(4) static const u8 sText_DontHaveTypeTrainerWants[] = _("No tens cap Pokémon de tipus\n{STR_VAR_2} que {STR_VAR_1} vulgui.\p");
ALIGNED(4) static const u8 sText_DontHaveEggTrainerWants[] = _("No tens cap Ou que\n{STR_VAR_1} vulgui.\p");
ALIGNED(4) static const u8 sText_PlayerCantTradeForYourMon[] = _("{STR_VAR_1} no pot intercanviar\nel teu Pokémon ara.\p");
ALIGNED(4) static const u8 sText_CantTradeForPartnersMon[] = _("No pots intercanviar\nel Pokémon de {STR_VAR_1} ara.\p");

// Unused
static const u8 *const sCantTradeMonTexts[] = {
    sText_PlayerCantTradeForYourMon,
    sText_CantTradeForPartnersMon
};

ALIGNED(4) static const u8 sText_TradeOfferRejected[] = _("La teva oferta ha estat rebutjada.\p");
ALIGNED(4) static const u8 sText_EggTrade[] = _("Intercanvi d'Ou");
ALIGNED(4) static const u8 sText_ChooseJoinCancel[] = _("{DPAD_UPDOWN}Triar  {A_BUTTON}Unir-se  {B_BUTTON}Cancel·lar");
ALIGNED(4) static const u8 sText_ChooseTrainer[] = _("Tria un Entrenador.");
ALIGNED(4) static const u8 sText_ChooseTrainerSingleBattle[] = _("Tria un Entrenador per\nun Combat Individual.");
ALIGNED(4) static const u8 sText_ChooseTrainerDoubleBattle[] = _("Tria un Entrenador per\nun Combat Doble.");
ALIGNED(4) static const u8 sText_ChooseLeaderMultiBattle[] = _("Tria el Líder\nper un Combat Múltiple.");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith[] = _("Tria l'Entrenador amb qui\nvols intercanviar.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderCards[] = _("Tria l'Entrenador que\ncomparteix Targetes Misterioses.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderNews[] = _("Tria l'Entrenador que\ncomparteix Notícies Misterioses.");
ALIGNED(4) static const u8 sText_ChooseLeaderPokemonJump[] = _("Salt Pokémon!\nTria el Líder.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryCrush[] = _("Trencabaies!\nTria el Líder.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryPicking[] = _("Recol·lecció de Baies Dodrio!\nTria el Líder.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryBlender[] = _("Barrejador de Baies!\nTria el Líder.");
ALIGNED(4) static const u8 sText_ChooseLeaderRecordCorner[] = _("Racó de Rècords!\nTria el Líder.");
ALIGNED(4) static const u8 sText_ChooseLeaderCoolContest[] = _("Concurs de Frescor!\nTria el Líder.");
ALIGNED(4) static const u8 sText_ChooseLeaderBeautyContest[] = _("Concurs de Bellesa!\nTria el Líder.");
ALIGNED(4) static const u8 sText_ChooseLeaderCuteContest[] = _("Concurs de Dolçor!\nTria el Líder.");
ALIGNED(4) static const u8 sText_ChooseLeaderSmartContest[] = _("Concurs d'Enginy!\nTria el Líder.");
ALIGNED(4) static const u8 sText_ChooseLeaderToughContest[] = _("Concurs de Duresa!\nTria el Líder.");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerLv50[] = _("Torre de Combat Nv. 50!\nTria el Líder.");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerOpenLv[] = _("Torre de Combat Nv. Lliure!\nTria el Líder.");

static const u8 *const sChooseTrainerTexts[NUM_LINK_GROUP_TYPES] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = sText_ChooseTrainerSingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sText_ChooseTrainerDoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sText_ChooseLeaderMultiBattle,
    [LINK_GROUP_TRADE]             = sText_ChooseTrainerToTradeWith,
    [LINK_GROUP_POKEMON_JUMP]      = sText_ChooseLeaderPokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sText_ChooseLeaderBerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sText_ChooseLeaderBerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sText_ChooseTrainerToShareWonderCards,
    [LINK_GROUP_WONDER_NEWS]       = sText_ChooseTrainerToShareWonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = NULL,
    [LINK_GROUP_UNION_ROOM_INIT]   = NULL,
    [LINK_GROUP_UNK_11]            = NULL,
    [LINK_GROUP_RECORD_CORNER]     = sText_ChooseLeaderRecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sText_ChooseLeaderBerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sText_ChooseLeaderCoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sText_ChooseLeaderBeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sText_ChooseLeaderCuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sText_ChooseLeaderSmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sText_ChooseLeaderToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sText_ChooseLeaderBattleTowerLv50,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sText_ChooseLeaderBattleTowerOpenLv
};

ALIGNED(4) static const u8 sText_SearchingForWirelessSystemWait[] = _("Cercant el Sistema de Comunicació\nSense Fil. Espera...");
ALIGNED(4) static const u8 sText_MustHaveTwoMonsForDoubleBattle[] = _("Per un Combat Doble, necessites\nalmenys dos Pokémon.\p"); // Unused
ALIGNED(4) static const u8 sText_AwaitingPlayersResponse[] = _("Esperant la resposta de {STR_VAR_1}…");
ALIGNED(4) static const u8 sText_PlayerHasBeenAskedToRegisterYouPleaseWait[] = _("S'ha demanat a {STR_VAR_1} que et\nregistri com a membre. Espera.");
ALIGNED(4) static const u8 sText_AwaitingResponseFromWirelessSystem[] = _("Esperant resposta del Sistema\nde Comunicació Sense Fil.");
ALIGNED(4) static const u8 sText_PleaseWaitForOtherTrainersToGather[] = _("Espera que altres Entrenadors\nes reuneixin i estiguin a punt."); // Unused
ALIGNED(4) static const u8 sText_NoCardsSharedRightNow[] = _("Ara no es comparteixen\nTargetes.");
ALIGNED(4) static const u8 sText_NoNewsSharedRightNow[] = _("Ara no es comparteixen\nNotícies.");

static const u8 *const sNoWonderSharedTexts[] = {
    sText_NoCardsSharedRightNow,
    sText_NoNewsSharedRightNow
};

ALIGNED(4) static const u8 sText_Battle[] = _("Combat");
ALIGNED(4) static const u8 sText_Chat2[] = _("Xat");
ALIGNED(4) static const u8 sText_Greetings[] = _("Salutacions");
ALIGNED(4) static const u8 sText_Exit[] = _("Sortir");
ALIGNED(4) static const u8 sText_Exit2[] = _("Sortir");
ALIGNED(4) static const u8 sText_Info[] = _("Info");
ALIGNED(4) static const u8 sText_NameWantedOfferLv[] = _("Nom{CLEAR_TO 0x3C}Vols{CLEAR_TO 0x6E}Oferta{CLEAR_TO 0xC6}NV.");
ALIGNED(4) static const u8 sText_SingleBattle[] = _("Combat Individual");
ALIGNED(4) static const u8 sText_DoubleBattle[] = _("Combat Doble");
ALIGNED(4) static const u8 sText_MultiBattle[] = _("Combat Múltiple");
ALIGNED(4) static const u8 sText_PokemonTrades[] = _("Intercanvis Pokémon");
ALIGNED(4) static const u8 sText_Chat[] = _("Xat");
ALIGNED(4) static const u8 sText_Cards[] = _("Targetes");
ALIGNED(4) static const u8 sText_WonderCards[] = _("Targetes Misterioses");
ALIGNED(4) static const u8 sText_WonderNews[] = _("Notícies Misterioses");
ALIGNED(4) static const u8 sText_PokemonJump[] = _("Salt Pokémon");
ALIGNED(4) static const u8 sText_BerryCrush[] = _("Trencabaies");
ALIGNED(4) static const u8 sText_BerryPicking[] = _("Recol·lecció Baies");
ALIGNED(4) static const u8 sText_Search[] = _("Cercar");
ALIGNED(4) static const u8 sText_BerryBlender[] = _("Barrejador Baies");
ALIGNED(4) static const u8 sText_RecordCorner[] = _("Racó de Rècords");
ALIGNED(4) static const u8 sText_CoolContest[] = _("Concurs Frescor");
ALIGNED(4) static const u8 sText_BeautyContest[] = _("Concurs Bellesa");
ALIGNED(4) static const u8 sText_CuteContest[] = _("Concurs Dolçor");
ALIGNED(4) static const u8 sText_SmartContest[] = _("Concurs Enginy");
ALIGNED(4) static const u8 sText_ToughContest[] = _("Concurs Duresa");
ALIGNED(4) static const u8 sText_BattleTowerLv50[] = _("Torre Combat NV. 50");
ALIGNED(4) static const u8 sText_BattleTowerOpenLv[] = _("Torre Combat Nv. Lliure");
ALIGNED(4) static const u8 sText_ItsNormalCard[] = _("És una Targeta Normal.");
ALIGNED(4) static const u8 sText_ItsBronzeCard[] = _("És una Targeta de Bronze!");
ALIGNED(4) static const u8 sText_ItsCopperCard[] = _("És una Targeta de Coure!");
ALIGNED(4) static const u8 sText_ItsSilverCard[] = _("És una Targeta de Plata!");
ALIGNED(4) static const u8 sText_ItsGoldCard[] = _("És una Targeta d'Or!");

static const u8 *const sCardColorTexts[] = {
    sText_ItsNormalCard,
    sText_ItsBronzeCard,
    sText_ItsCopperCard,
    sText_ItsSilverCard,
    sText_ItsGoldCard
};

ALIGNED(4) static const u8 sText_TrainerCardInfoPage1[] = _("Aquesta és la Targeta de\n{DYNAMIC 0} {DYNAMIC 1}…\l{DYNAMIC 2}\pPokédex: {DYNAMIC 3}\nTemps:   {DYNAMIC 4}:{DYNAMIC 5}\p");
ALIGNED(4) static const u8 sText_TrainerCardInfoPage2[] = _("Combats: Vict.: {DYNAMIC 0}  Derrotes: {DYNAMIC 2}\nIntercanvis: {DYNAMIC 3}\p”{DYNAMIC 4} {DYNAMIC 5}\n{DYNAMIC 6} {DYNAMIC 7}”\p");
ALIGNED(4) static const u8 sText_GladToMeetYouMale[] = _("{DYNAMIC 1}: Encantat de conèixer-te!{PAUSE 60}");
ALIGNED(4) static const u8 sText_GladToMeetYouFemale[] = _("{DYNAMIC 1}: Encantada de conèixer-te!{PAUSE 60}");

static const u8 *const sGladToMeetYouTexts[GENDER_COUNT] = {
    sText_GladToMeetYouMale,
    sText_GladToMeetYouFemale
};

ALIGNED(4) static const u8 sText_FinishedCheckingPlayersTrainerCard[] = _("Has acabat de veure la Targeta\nde {DYNAMIC 1}.{PAUSE 60}");

static const u8 *const sLinkGroupActivityNameTexts[] = {
    [ACTIVITY_NONE]              = sText_EmptyString,
    [ACTIVITY_BATTLE_SINGLE]     = sText_SingleBattle,
    [ACTIVITY_BATTLE_DOUBLE]     = sText_DoubleBattle,
    [ACTIVITY_BATTLE_MULTI]      = sText_MultiBattle,
    [ACTIVITY_TRADE]             = sText_PokemonTrades,
    [ACTIVITY_CHAT]              = sText_Chat,
    [ACTIVITY_WONDER_CARD_DUP]   = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS_DUP]   = sText_WonderNews,
    [ACTIVITY_CARD]              = sText_Cards,
    [ACTIVITY_POKEMON_JUMP]      = sText_PokemonJump,
    [ACTIVITY_BERRY_CRUSH]       = sText_BerryCrush,
    [ACTIVITY_BERRY_PICK]        = sText_BerryPicking,
    [ACTIVITY_SEARCH]            = sText_Search,
    [ACTIVITY_SPIN_TRADE]        = sText_EmptyString,
    [ACTIVITY_BATTLE_TOWER_OPEN] = sText_BattleTowerOpenLv,
    [ACTIVITY_RECORD_CORNER]     = sText_RecordCorner,
    [ACTIVITY_BERRY_BLENDER]     = sText_BerryBlender,
    [ACTIVITY_ACCEPT]            = sText_EmptyString,
    [ACTIVITY_DECLINE]           = sText_EmptyString,
    [ACTIVITY_NPCTALK]           = sText_EmptyString,
    [ACTIVITY_PLYRTALK]          = sText_EmptyString,
    [ACTIVITY_WONDER_CARD]       = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS]       = sText_WonderNews,
    [ACTIVITY_CONTEST_COOL]      = sText_CoolContest,
    [ACTIVITY_CONTEST_BEAUTY]    = sText_BeautyContest,
    [ACTIVITY_CONTEST_CUTE]      = sText_CuteContest,
    [ACTIVITY_CONTEST_SMART]     = sText_SmartContest,
    [ACTIVITY_CONTEST_TOUGH]     = sText_ToughContest,
    [ACTIVITY_BATTLE_TOWER]      = sText_BattleTowerLv50
};

static const struct WindowTemplate sWindowTemplate_BButtonCancel = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 30,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x0008
};

// Minimum and maximum number of players for a link group
// A minimum of 0 means the min and max are equal
#define LINK_GROUP_CAPACITY(min, max)(((min) << 12) | ((max) << 8))
#define GROUP_MAX(capacity)(capacity & 0x0F)
#define GROUP_MIN(capacity)(capacity >> 4)
#define GROUP_MIN2(capacity)(capacity & 0xF0) // Unnecessary to have both, but needed to match

static const u32 sLinkGroupToActivityAndCapacity[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI      | LINK_GROUP_CAPACITY(0, 4),
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE             | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP      | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH       | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK        | LINK_GROUP_CAPACITY(3, 5),
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY    | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER      | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN | LINK_GROUP_CAPACITY(0, 2)
};

static const struct WindowTemplate sWindowTemplate_PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_5PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_NumPlayerMode = {
    .bg = 0,
    .tilemapLeft = 16,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00c6
};

static const struct ListMenuItem sPossibleGroupMembersListMenuItems[] = {
    { sText_EmptyString, 0 },
    { sText_EmptyString, 1 },
    { sText_EmptyString, 2 },
    { sText_EmptyString, 3 },
    { sText_EmptyString, 4 }
};

static const struct ListMenuTemplate sListMenuTemplate_PossibleGroupMembers = {
    .items = sPossibleGroupMembersListMenuItems,
    .moveCursorFunc = NULL,
    .itemPrintFunc = ItemPrintFunc_PossibleGroupMembers,
    .totalItems = ARRAY_COUNT(sPossibleGroupMembersListMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 0,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 1
};

static const struct WindowTemplate sWindowTemplate_GroupList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 17,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_PlayerNameAndId = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00ee
};

static const struct ListMenuItem sUnionRoomGroupsMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

static const struct ListMenuTemplate sListMenuTemplate_UnionRoomGroups = {
    .items = sUnionRoomGroupsMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ListMenuItemPrintFunc_UnionRoomGroups,
    .totalItems = ARRAY_COUNT(sUnionRoomGroupsMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 1,
    .fontId = 1,
    .cursorKind = 0
};

static const struct WindowTemplate sWindowTemplate_InviteToActivity = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 5,
    .width = 16,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sInviteToActivityMenuItems[] = {
    { sText_Greetings, ACTIVITY_CARD | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Battle,    ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Chat2,     ACTIVITY_CHAT | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Exit,      ACTIVITY_NONE | IN_UNION_ROOM }
};

static const struct ListMenuTemplate sListMenuTemplate_InviteToActivity = {
    .items = sInviteToActivityMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sInviteToActivityMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

static const struct WindowTemplate sWindowTemplate_RegisterForTrade = {
    .bg = 0,
    .tilemapLeft = 18,
    .tilemapTop = 7,
    .width = 16,
    .height = 6,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sRegisterForTradeListMenuItems[] = {
    { gText_Register, 1 },
    { sText_Info, 2 },
    { sText_Exit, 3 }
};

static const struct ListMenuTemplate sListMenuTemplate_RegisterForTrade = {
    .items = sRegisterForTradeListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sRegisterForTradeListMenuItems),
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

static const struct WindowTemplate sWindowTemplate_TradingBoardRequestType = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 1,
    .width = 16,
    .height = 12,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sTradingBoardTypes[NUMBER_OF_MON_TYPES] = {
    { gTypeNames[TYPE_NORMAL],   TYPE_NORMAL         },
    { gTypeNames[TYPE_FIRE],     TYPE_FIRE           },
    { gTypeNames[TYPE_WATER],    TYPE_WATER          },
    { gTypeNames[TYPE_ELECTRIC], TYPE_ELECTRIC       },
    { gTypeNames[TYPE_GRASS],    TYPE_GRASS          },
    { gTypeNames[TYPE_ICE],      TYPE_ICE            },
    { gTypeNames[TYPE_GROUND],   TYPE_GROUND         },
    { gTypeNames[TYPE_ROCK],     TYPE_ROCK           },
    { gTypeNames[TYPE_FLYING],   TYPE_FLYING         },
    { gTypeNames[TYPE_PSYCHIC],  TYPE_PSYCHIC        },
    { gTypeNames[TYPE_FIGHTING], TYPE_FIGHTING       },
    { gTypeNames[TYPE_POISON],   TYPE_POISON         },
    { gTypeNames[TYPE_BUG],      TYPE_BUG            },
    { gTypeNames[TYPE_GHOST],    TYPE_GHOST          },
    { gTypeNames[TYPE_DRAGON],   TYPE_DRAGON         },
    { gTypeNames[TYPE_STEEL],    TYPE_STEEL          },
    { gTypeNames[TYPE_DARK],     TYPE_DARK           },
    { sText_Exit,                NUMBER_OF_MON_TYPES }
};

static const struct ListMenuTemplate sMenuTemplate_TradingBoardRequestType = {
    .items = sTradingBoardTypes,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sTradingBoardTypes),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

static const struct WindowTemplate sWindowTemplate_TradingBoardHeader = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 28,
    .height = 2,
    .paletteNum = 13,
    .baseBlock = 0x0001
};

static const struct WindowTemplate sWindowTemplate_TradingBoardMain = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sTradeBoardListMenuItems[] = {
    { sText_EmptyString, -3 },
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_Exit2,  8 }
};

static const struct ListMenuTemplate sTradeBoardListMenuTemplate = {
    .items = sTradeBoardListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = TradeBoardListMenuItemPrintFunc,
    .totalItems = ARRAY_COUNT(sTradeBoardListMenuItems),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 14,
    .fillValue = 15,
    .cursorShadowPal = 13,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

// Unused
static const struct WindowTemplate sWindowTemplate_Unused = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sEmptyListMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

// Unused
static const struct ListMenuTemplate sEmptyListMenuTemplate = {
    .items = sEmptyListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ItemPrintFunc_EmptyList,
    .totalItems = ARRAY_COUNT(sEmptyListMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 1,
    .fontId = 1,
    .cursorKind = 0
};

static const struct RfuPlayerData sUnionRoomPlayer_DummyRfu = {0};

ALIGNED(4) static const u8 sAcceptedActivityIds_SingleBattle[]    = {ACTIVITY_BATTLE_SINGLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_DoubleBattle[]    = {ACTIVITY_BATTLE_DOUBLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_MultiBattle[]     = {ACTIVITY_BATTLE_MULTI, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Trade[]           = {ACTIVITY_TRADE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_PokemonJump[]     = {ACTIVITY_POKEMON_JUMP, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryCrush[]      = {ACTIVITY_BERRY_CRUSH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryPicking[]    = {ACTIVITY_BERRY_PICK, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderCard[]      = {ACTIVITY_WONDER_CARD, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderNews[]      = {ACTIVITY_WONDER_NEWS, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Resume[]          = {
    IN_UNION_ROOM | ACTIVITY_NONE,
    IN_UNION_ROOM | ACTIVITY_BATTLE_SINGLE,
    IN_UNION_ROOM | ACTIVITY_TRADE,
    IN_UNION_ROOM | ACTIVITY_CHAT,
    IN_UNION_ROOM | ACTIVITY_CARD,
    IN_UNION_ROOM | ACTIVITY_ACCEPT,
    IN_UNION_ROOM | ACTIVITY_DECLINE,
    IN_UNION_ROOM | ACTIVITY_NPCTALK,
    IN_UNION_ROOM | ACTIVITY_PLYRTALK,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_Init[]            = {ACTIVITY_SEARCH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Unk11[]           = {
    ACTIVITY_BATTLE_SINGLE,
    ACTIVITY_BATTLE_DOUBLE,
    ACTIVITY_BATTLE_MULTI,
    ACTIVITY_TRADE,
    ACTIVITY_POKEMON_JUMP,
    ACTIVITY_BERRY_CRUSH,
    ACTIVITY_BERRY_PICK,
    ACTIVITY_WONDER_CARD,
    ACTIVITY_WONDER_NEWS,
    ACTIVITY_SPIN_TRADE,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_RecordCorner[]    = {ACTIVITY_RECORD_CORNER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryBlender[]    = {ACTIVITY_BERRY_BLENDER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CoolContest[]     = {ACTIVITY_CONTEST_COOL, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BeautyContest[]   = {ACTIVITY_CONTEST_BEAUTY, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CuteContest[]     = {ACTIVITY_CONTEST_CUTE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_SmartContest[]    = {ACTIVITY_CONTEST_SMART, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_ToughContest[]    = {ACTIVITY_CONTEST_TOUGH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTower[]     = {ACTIVITY_BATTLE_TOWER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTowerOpen[] = {ACTIVITY_BATTLE_TOWER_OPEN, 0xff};

static const u8 *const sAcceptedActivityIds[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = sAcceptedActivityIds_SingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sAcceptedActivityIds_DoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sAcceptedActivityIds_MultiBattle,
    [LINK_GROUP_TRADE]             = sAcceptedActivityIds_Trade,
    [LINK_GROUP_POKEMON_JUMP]      = sAcceptedActivityIds_PokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sAcceptedActivityIds_BerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sAcceptedActivityIds_BerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sAcceptedActivityIds_WonderCard,
    [LINK_GROUP_WONDER_NEWS]       = sAcceptedActivityIds_WonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = sAcceptedActivityIds_Resume,
    [LINK_GROUP_UNION_ROOM_INIT]   = sAcceptedActivityIds_Init,
    [LINK_GROUP_UNK_11]            = sAcceptedActivityIds_Unk11,
    [LINK_GROUP_RECORD_CORNER]     = sAcceptedActivityIds_RecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sAcceptedActivityIds_BerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sAcceptedActivityIds_CoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sAcceptedActivityIds_BeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sAcceptedActivityIds_CuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sAcceptedActivityIds_SmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sAcceptedActivityIds_ToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sAcceptedActivityIds_BattleTower,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sAcceptedActivityIds_BattleTowerOpen
};

static const u8 sLinkGroupToURoomActivity[NUM_LINK_GROUP_TYPES + 2] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE,
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE,
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI,
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE,
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP,
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH,
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK,
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_WONDER_CARD,
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_WONDER_NEWS,
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE,
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE,
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE,
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER,
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER,
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE,
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL,
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY,
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE,
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART,
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH,
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN
};

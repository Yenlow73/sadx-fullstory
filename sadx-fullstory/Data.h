#pragma once
#include <fstream>
#include <map>
#define STAGE_TRIGGERS 4
#define TOTAL_STAGES 196

void Init_Progression();
void Init_Stages();

void SaveProgression();
void ReadConfig(bool isInsideGame);
bool CheckandPlayCutscene();

void SetStageAct(char stage, char act);
void GoToNextLevel_hook(char stage, char act);

void SetStageOnFrames();
void CheckCompletion();
void PauseMenuFix();

extern std::string modpath;

extern bool earlyGamma;
extern bool allUpgrades;
extern bool permanentEntrances;
extern bool SonicChaos6;
extern bool TikalOrder;
extern int OutroCharacter;
extern int CreditCharacter;

extern int STLevelsCharacter;
extern int Chaos4Character;
extern int EggHornetCharacter;

extern bool AdventureFieldsEnabled;
extern bool BigGameplayEnabled;

extern bool TailsDayTimeEnabled;
extern bool UnusedCutsceneEnabled;

extern bool TitleLogoEnabled;


extern bool jetAnklet;
extern bool lightSpeedShoes;
extern bool crystalRing;

extern bool isPlayerInsideTrigger[];
extern bool isAdventureField;
extern bool quitSelected;
extern bool enteredStage;
extern bool isInsideStage;
extern bool isinsideAdventure;

extern bool showTriggers;

extern int storyComplete;
extern int triggerIndex;

extern int currentStage;
extern int previousStage;
extern int nextStage;
extern int previousAct;

extern int triggerStageIndex[];

extern const int ADVENTUREFIELDSSIZE;

extern PVMEntry texTbl_ev004D[];

struct Stage
{
	bool isCutscene;
	bool controlAfterCutscene;
	bool hasCutsceneTrigger;
	bool displayCard;
	int8_t character;
	int level;
	int act;
	int timeofDay;
	int cutsceneID;
};

struct Trigger
{
	int stageIndex;
	int pointX;
	int pointY;
	int pointZ;
	int radius;
};

extern Trigger triggers[];
extern Stage stages[];
extern std::map<int, int> triggerPoints;

extern int adventureFields[];

enum MasterEmeraldStates 
{
	MasterEmerald_Broken = 1,
	MasterEmerald_PartiallyRestored = 2,
	MasterEmerald_FullyRestored = 3
};

enum LevelsChars
{
	LevelsChars_SonicTails,
	LevelsChars_Sonic,
	LevelsChars_Tails
};

enum Chaos4Chars
{
	Chaos4Chars_Sonic,
	Chaos4Chars_Tails,
	Chaos4Chars_Knuckles
};

enum OutroChars
{
	OutroChars_Sonic,
	OutroChars_Tails
};

enum CreditChars
{
	CreditChars_Sonic,
	CreditChars_Final
};

enum TriggerNums
{
	Trigger_ChaoGarden,
	Trigger_Stage1,
	Trigger_Stage2,
	Trigger_Stage3
};

enum StationSquareActs
{
	StationSquare_CityHall,
	StationSquare_Station,
	StationSquare_Sewers,
	StationSquare_StationArea,
	StationSquare_Hotel,
	StationSquare_TwinklePark
};

enum MysticRuinsActs
{
	MysticRuins_Station,
	MysticRuins_AngelIsland,
	MysticRuins_Jungle,
	MysticRuins_FinalEgg
};

enum EggCarrierInsideActs
{
	EggCarrierInside_Arsenal,
	EggCarrierInside_Main,
	EggCarrierInside_HedgehogHammer,
	EggCarrierInside_PrisonHall,
	EggCarrierInside_WaterTank,
	EggCarrierInside_WarpHall
};

enum EggCarrierOutsideActs
{
	EggCarrierOutside_Runway,
	EggCarrierOutside_Bridge,
	EggCarrierOutside_Deck,
	EggCarrierOutside_CaptainRoom,
	EggCarrierOutside_PrivateRoom,
	EggCarrierOutside_Pool,
	EggCarrierOutside_Transforming,
};

enum PastActs
{
	Past_Shrine,
	Past_Altar,
	Past_AltarFire,
};

enum FMVs
{
	FMV_PerfectChaos = 1,
	FMV_AngelIslandFalling = 2,
	FMV_AngelIslandRising = 3,
	FMV_EggCarrierStationSquare = 4,
	FMV_EggCarrierAngelIsland = 5,
	FMV_EggCarrierSky = 6,
	FMV_EggCarrierFalling = 7,
	FMV_EggCarrierRising = 8,
};

enum TriggerDescriptions
{
	Trigger_Sonic_ToEggHornet,
	Trigger_Event_Knuck_InThePast,
	Trigger_Event_Knuck_BackToThePresent,
	Trigger_Event_Gamma_Intro,
	Trigger_Gamma_ToBeta,
	Trigger_Event_Big_SearchingForFroggy,
	Trigger_Knuckles_ToSonic,
	Trigger_Event_SonicAndTails_Depart_Knuckles,
	Trigger_Event_Knuck_BackToThePast,
	Trigger_Event_Tails_WakeUpFromDream,
	Trigger_Event_Tails_EntersThePast,
	Trigger_Event_Amy_MeetingBirdie,
	Trigger_Event_Amy_FindsSonic,
	Trigger_Event_Tails_MeetsBig,
	Trigger_Sonic_ToCasinoArea,
	Trigger_Event_Gamma_EntersThePast,
	Trigger_Event_Knuck_PartialRestoration,
	Trigger_Event_Amy_EntersThePast,
	Trigger_Event_SonicAndTailsOnTheEggCarrier,
	Trigger_Event_Knuck_EnteringEggmanBase,
	Trigger_Event_Sonic_EggCarrierTransforms,
	Trigger_Event_Knuck_BackToThePastAgain,
	Trigger_Event_Big_GoesToThePast,
	Trigger_Event_Big_ReadyToLeaveTheEggCarrier,
	Trigger_Event_Knuck_ReturningToThePresent,
	Trigger_Event_Sonic_TravelsToThePast,
	Trigger_Amy_ToEggBase,
	Trigger_Event_Gamma_E105Rescued,
	Trigger_Event_Final_TailsFindsSonic,
	Trigger_Event_Final_SonicHeadsToThePast,
    Trigger_Event_Final_EchidnasFaceChaos,
	Trigger_Event_Final_SonicChecksOnTikal,
	Trigger_Event_Final_SonicWakesUp,
	Trigger_StationSquare_ChaoGarden,
	Trigger_MysticRuins_ChaoGarden,
	Trigger_EggCarrier_ChaoGarden,
	Trigger_EmeraldCoast,
	Trigger_WindyValley,
	Trigger_IceCap,
	Trigger_SpeedHighway,
	Trigger_RedMountain,
	Trigger_Casinopolis
};

enum LevelLayouts
{
	FirstLayout,
	SecondLayout,
	ThirdLayout,
	FourthLayout
};

enum Scenes
{
	Scene_Sonic_Intro = 1,
	Scene_Sonic_Defeats_Chaos0 = 2,
	Scene_Sonic_Sees_Tails_Crash = 3,
	Scene_SonicAndTails_Poolside = 6,
	Scene_SonicAndEggman_Meet = 7,
	Scene_SonicAndTails_Meet_Chaos1 = 8,
	Scene_SonicAndTails_Gassed_At_Casinopolis = 9,
	Scene_Sonic_Chaos4_Emerges = 11,
	Scene_SonicAndTails_Depart_Knuckles = 12,
	Scene_SonicAndTails_Tornado1Takeoff = 13,
	Scene_Sonic_Falls_StationSquare = 17,
	Scene_Sonic_Meets_Amy = 18,
	Scene_SonicAndAmy_EnterTwinklePark = 19,
	Scene_Sonic_SearchesFor_Amy = 20,
	Scene_Sonic_Finds_AmyAndZero = 21,
	Scene_Sonic_Loses_Amy = 22,
	Scene_SonicAndTails_HeadForEggCarrier = 23,
	Scene_Sonic_vs_Gamma = 26,
	Scene_Sonic_HeadsAfterEggman = 27,
	Scene_Sonic_FindsChaos6 = 28,
	Scene_Sonic_FollowsEggman = 29,
	Scene_Sonic_LandsInMysticRuins = 30,
	Scene_Sonic_FindsTheMural = 32,
	Scene_Sonic_TravelsToThePast = 33,
	Scene_Sonic_Meets_Tikal = 34,
	Scene_Sonic_SpotsEggman = 35,
	Scene_Sonic_FinalBossMeeting = 36,
	Scene_Sonic_Outro = 38,
	Scene_Sonic_vs_Knuckles = 40,
	Scene_Sonic_Tornado2Transform = 41,
	Scene_SonicAndTails_WakeUp = 42,
	Scene_Sonic_MeetsChaos0 = 43,
	Scene_Tails_Intro = 48,
	Scene_Tails_SavedBySonic = 49,
	Scene_TailsAndSonic_Poolside = 50,
	Scene_TailsAndEggman_Meet = 51,
	Scene_Tails_Chaos1 = 52,
	Scene_TailsAndSonic_GassedAtCasinopolis = 53,
	Scene_Tails_vs_Knuckles = 56,
	Scene_Tails_Chaos4Emerges = 57,
	Scene_TailsAndSonic_DepartKnuckles = 58,
	Scene_TailsAndSonic_Tornado1Takeoff = 59,
	Scene_Tails_Flashback = 62,
	Scene_Tails_WakeUpFromDream = 64,
	Scene_Tails_ChasesFroggy = 66,
	Scene_Tails_EntersThePast = 68,
	Scene_Tails_MeetsTikal = 69,
	Scene_Tails_MeetsBig = 70,
	Scene_Tails_Tornado2Takeoff = 71,
	Scene_Tails_CatchesUpWithSonic = 72,
	Scene_Tails_vs_Gamma = 75,
	Scene_Tails_LeavesWithAmy = 76,
	Scene_Tails_EggmanLaunchesMissile = 77,
	Scene_Tails_HeadsAfterTheMissile = 78,
	Scene_Tails_FinalBossEncounter = 80,
	Scene_Tails_AfterFinalBoss = 81,
	Scene_Tails_Outro = 82,
	Scene_Tails_Tornado2Transform = 83,
	Scene_Tails_Tornado2Landing = 84,
	Scene_Tails_GoesToPast = 85,
	Scene_TailsAndSonic_WakeUpAfterCasinopolis = 86,
	Scene_Amy_PreIntro = 88,
	Scene_Amy_Intro = 96,
	Scene_Amy_MeetingBirdie = 97,
	Scene_Amy_FindsSonic = 98,
	Scene_AmyAndSonic_VisitTwinklePark = 99,
	Scene_Amy_KidnappedByZero = 100,
	Scene_Amy_TalkingToGamma = 101,
	Scene_Amy_GoesToPast = 102,
	Scene_Amy_EntersThePast = 103,
	Scene_Amy_MeetsTikal = 104,
	Scene_Amy_EggmanTakesBirdie = 105,
	Scene_Amy_LeavesWithTails = 106,
	Scene_Amy_ReturningFromThePast = 108,
	Scene_Amy_FindingBirdiesFamily = 109,
	Scene_Amy_DiscoveringTheEggBase = 110,
	Scene_Amy_ChasedByZeroAgain = 111,
	Scene_Amy_BackToTheEggCarrier = 112,
	Scene_Amy_FinalBoss = 113,
	Scene_Amy_Outro = 114,
	Scene_Amy_KidnappedToMysticRuins = 117,
	Scene_Knuck_Intro = 128,
	Scene_Knuck_OnTheuntForPieces = 130,
	Scene_Knuck_HeadingToThePast = 131,
	Scene_Knuck_InThePast = 132,
	Scene_Knuck_TikalCrisis = 133,
	Scene_Knuck_BackToThePresent = 134,
	Scene_Knuck_Chaos2Battle = 135,
	Scene_Knuck_IsTrickedByEggman = 136,
	Scene_Knuck_ChasingAfterSonic = 137,
	Scene_Knuck_vs_Sonic = 138,
	Scene_Knuck_Chaos4Battle = 139,
	Scene_Knuck_Departs = 140,
	Scene_Knuck_GoesToPast = 141,
	Scene_Knuck_BackToThePast = 142,
	Scene_Knuck_TikalCrisis2 = 143,
	Scene_Knuck_PartialRestoration = 145,
	Scene_Knuck_FollowingGamma = 146,
	Scene_Knuck_EnteringEggmanBase = 148,
	Scene_Knuck_GoesToPastAgain = 149,
	Scene_Knuck_BackToThePastAgain = 150,
	Scene_Knuck_TikalAftermath = 151,
	Scene_Knuck_ReturningToThePresent = 152,
	Scene_Knuck_Chaos6Battle = 153,
	Scene_Knuck_AllShardCollected = 154,
	Scene_Knuck_ReturningToAngelIsland = 155,
	Scene_Knuck_RestoringTheMasterEmerald = 157,
	Scene_Knuck_Outro = 159,
	Scene_Knuck_FollowingEggman = 160,
	Scene_Gamma_Intro = 176,
	Scene_Gamma_EnterFinalEgg = 177,
	Scene_Gamma_AfterFinalEgg = 178,
	Scene_Gamma_EggmanDisappointed = 179,
	Scene_Gamma_FightWithBeta = 180,
	Scene_Gamma_DefeatsBeta = 181,
	Scene_Gamma_TheHuntForFroggy = 183,
	Scene_Gamma_GoesToPast = 184,
	Scene_Gamma_EntersThePast = 185,
	Scene_Gamma_MeetsTikal = 186,
	Scene_Gamma_ReturnToTheEggCarrier = 187,
	Scene_Gamma_HeadToBeta = 188,
	Scene_Gamma_Beta = 189,
	Scene_Gamma_LeavesBeta = 190,
	Scene_Gamma_AmyJailCell = 191,
	Scene_Gamma_HeadingToTheRear = 192,
	Scene_Gamma_EmergesToFightSonic = 193,
	Scene_Gamma_AfterSonicBattle = 194,
	Scene_Gamma_ObjectiveChanged = 195,
	Scene_Gamma_RememberingHisBrothers = 197,
	Scene_Gamma_Outro = 199,
	Scene_Big_Intro = 208,
	Scene_Big_SearchingForFroggy = 209,
	Scene_Big_FroggyGoesToSewers = 210,
	Scene_Big_TailsDropsFroggy = 211,
	Scene_Big_GammaTakesFroggy = 212,
	Scene_Big_EntersHotShelter = 216,
	Scene_Big_FroggyInsideHotShelter = 217,
	Scene_Big_SavesFroggy = 218,
	Scene_Big_GoesToThePast = 219,
	Scene_Big_MeetsTikal = 220,
	Scene_Big_ReadyToLeaveTheEggCarrier = 221,
	Scene_Big_Chaos6TakesFroggy = 222,
	Scene_Big_SonicSavesFroggy = 223,
	Scene_Big_TakesTheTornado2 = 224,
	Scene_Big_Outro = 226,
	Scene_Froggy_HeadsToBeach = 227,
	Scene_Final_Tornado2Crash = 240,
	Scene_Final_EggmanInMysticRuins = 242,
	Scene_Final_KnucklesAtTheMasterEmerald = 243,
	Scene_Final_TailsFindsSonic = 244,
	Scene_Final_SonicFindsKnuxAndEggman = 245,
	Scene_Final_SonicHeadsToThePast = 246,
	Scene_Final_TikalsPlea = 247,
	Scene_Final_TikalSealsChaos = 248,
	Scene_Final_SonicWakesUp = 249,
	Scene_Final_SonicAndTailsReachTornado2 = 250,
	Scene_Final_SonicChecksOnTikal = 251,
	Scene_Final_PerfectChaosReveal = 253,
	Scene_Final_Outro = 254,
	Scene_Final_TheyBringSonicTheEmeralds = 255,
	Scene_SonicAndTailsOnTheEggCarrier = 256,
	Scene_Sonic_SkyChaseAttack = 257,
	Scene_Sonic_EggCarrierTransforms = 258,
	Scene_Sonic_SkyDeckEntrance = 259,
	Scene_Sonic_AfterSkyDeck = 260,
	Scene_Sonic_ChangingTheEggCarrierBack = 262,
	Scene_Sonic_EggCarrierTransformsBack = 263,
	Scene_TailsAndSonic_LandOnTheEggCarrier = 272,
	Scene_Tails_SkyChaseAttack = 273,
	Scene_Tails_EggCarrierTransforms = 274,
	Scene_Tails_SkyDeckEntrance = 275,
	Scene_Tails_AfterSkyDeck = 276,
	Scene_Knuck_EggCarrierTransforms1 = 288,
	Scene_Knuck_EggCarrierTransforms2 = 289,
	Scene_Knuck_EggCarrierSensingTheEmerald = 290,
	Scene_Amy_HedgehogHammer = 304,
	Scene_Amy_WinsHedgehogHammer = 305,
	Scene_Gamma_GoFindTheJetBooster = 320,
	Scene_Gamma_HeadingToHotShelter = 321,
	Scene_Gamma_E105Rescued = 322,
	Scene_Big_EggCarrierTransformsBack = 336,
	Scene_Final_EchidnasFaceChaos = 352,
	Scene_Sonic_CrystalRingGet = 357,
	Scene_Sonic_LSDashShoesGet = 358,
	Scene_Sonic_AncientLightGet = 359,
	Scene_Tails_JetAnkletGet = 360,
	Scene_Tails_RhythmBadgeGet = 361,
	Scene_Knuck_FightingGlovesGet = 362,
	Scene_Knuck_ShovelClawGet = 363,
	Scene_Amy_LongHammerGet = 364,
	Scene_Amy_WarriorFeatherGet = 365,
	Scene_Gamma_LaserBlasterGet = 366,
	Scene_Gamma_JetBoosterGet = 367,
	Scene_Big_PowerRodGet = 368,
	Scene_Big_LifeBeltGet = 369,
	Scene_Sonic_IceStone = 374,
	Scene_Tails_IceStone = 375,
	Scene_Big_IceStone = 376,
	Scene_Sonic_Card = 377,
	Scene_Sonic_WestRock = 378,
	Scene_Tails_WestRock = 379,
	Scene_Big_WestRock = 380,
	Scene_Sonic_EggCarrierRedMountain = 384
};

enum StageDescriptions
{
	Event_Knuck_Intro,
	Event_Big_Intro,
	Event_Sonic_Intro,
	Sonic_Chaos0,
	Event_Tails_Intro,
	Event_Sonic_Sees_Tails_Crash,
	Sonic_EmeraldCoast,
	Tails_EmeraldCoast,
	Event_Tails_SavedBySonic,
	Event_SonicAndTails_Poolside,
	Tails_ToMysticRuins,
	Sonic_ToEggHornet,
	Event_SonicAndEggman_Meet,
	Sonic_EggHornet,
	Tails_EggHornet,
	Event_SonicAndTails_Meet_Chaos1,
	Sonic_WindyValley,
	Tails_WindyValley,
	Sonic_ToStationSquare,
	Event_Knuck_OnTheHuntForPieces,
	Knuck_SpeedHighway,
	Sonic_ToCasinopolis,
	Sonic_Casinopolis,
	Tails_Casinopolis,
	Knuck_ToCasinopolis,
	Knuck_Casinopolis,
	Event_SonicAndTails_Gassed_At_Casinopolis,
	Event_Knuck_InThePast,
	Event_Knuck_TikalCrisis,
	Event_Knuck_BackToThePresent,
	Event_Knuck_FollowingEggman,
	Event_Knuck_Chaos2Battle,
	Knuck_Chaos2,	
	Event_Gamma_Intro,
	Event_Gamma_EnterFinalEgg,
	Event_Gamma_EggmanIsDisappointed,
	Gamma_FinalEgg,
	Gamma_ToBeta,
	Event_Gamma_AfterFinalEgg,
	Event_Gamma_FightWithBeta,
	Gamma_E101,
	Event_Gamma_DefeatsBeta,
	Event_Sonic_IceStone,
	Event_SonicAndTails_WakeUp,
	Sonic_ToIceCap,	
	Sonic_IceCap,
	Tails_IceCap,
	Event_Big_SearchingForFroggy,
	Event_Big_FroggyGoesToSewers,
	Big_TwinklePark,
	Big_ToMysticRuins,
	Knuck_ToRedMountain,
	Knuck_RedMountain,
	Knuck_ToSonic,
	Event_Knuckles_vs_Sonic,
	Sonic_vs_Knuckles,
	Event_Sonic_Chaos4_Emerges,
	Sonic_Chaos4,
	Event_SonicAndTails_Depart_Knuckles,
	Event_SonicAndTails_Tornado1Takeoff,
	Sonic_SkyChase1,	
	Big_ToIceCap,
	Knuck_ToLostWorld,
	Knuck_LostWorld,
	Event_Knuck_BackToThePast,
	Event_Knuck_TikalCrisis2,
	Event_Tails_Flashback,
	Event_Tails_WakeUpFromDream,
	Event_Tails_ChasesFroggy,
	Tails_SandHill,
	Event_Tails_EntersThePast,
	Event_Tails_MeetsTikal,
	Event_Sonic_Falls_StationSquare,
	Event_Amy_Intro,
	Event_Amy_MeetingBirdie,
	Event_Amy_FindsSonic,
	Event_AmyAndSonic_VisitTwinklePark,
	Amy_TwinklePark,
	Event_Tails_MeetsBig,
	Event_Tails_Tornado2Takeoff,
	Big_IceCap,
	Big_ToStationSquare,
	Sonic_TwinklePark,
	Event_Sonic_SearchesFor_Amy,
	Event_Sonic_Card,
	Sonic_SpeedHighway,
	Event_Gamma_TheHuntForFroggy,
	Event_Amy_KidnappedByZero,
	Sonic_ToCasinoArea,
	Event_Sonic_Finds_AmyAndZero,
	Event_Big_FroggyGoesToTheBeach,
	Gamma_ToEmeraldCoast,
	Gamma_EmeraldCoast,
	Event_Gamma_EntersThePast,
	Event_Gamma_MeetsTikal,
	Big_EmeraldCoast,
	Event_Knuck_PartialRestoration,
	Event_Knuck_FollowingGamma,
	Event_Sonic_Loses_Amy,
	Sonic_RedMountain,
	Sonic_SkyChase2,
	Event_Gamma_ReturnToTheEggCarrier,
	Event_Gamma_HeadToBeta,
	Event_Gamma_Beta,
	Event_Gamma_LeavesBeta,
	Event_Amy_TalkingToGamma,
	Event_Amy_HedgehogHammer,
	Event_Amy_WinsHedgehogHammer,
	Amy_HotShelter,
	Event_Amy_EntersThePast,
	Event_Amy_MeetsTikal,
	Event_Sonic_Tornado2Transform,
	Event_SonicAndTailsOnTheEggCarrier,
	Event_Sonic_SkyChaseAttack,
	Event_Knuck_EnteringEggmanBase,
	Event_Knuck_EggCarrierTransforms1,
	EggCarrierTransforms,
	Event_Knuck_EggCarrierTransforms2,
	Event_Knuck_EggCarrierSensingTheEmerald,
	Event_Sonic_EggCarrierTransforms,
	Event_Sonic_SkyDeckEntrance,
	Tails_SkyDeck,
	Sonic_SkyDeck,
	Event_Big_EntersHotShelter,
	Big_HotShelter,
	Event_Big_GoesToThePast,
	Event_Big_MeetsTikal,
	Knuck_SkyDeck,
	Event_Knuck_BackToThePastAgain,
	Event_Knuck_TikalAftermath,
	Event_Amy_ReturningFromThePast,
	Event_Sonic_AfterSkyDeck,
	Gamma_ToEggCarrierMain, 
	Event_Gamma_GoFindTheJetBooster,
	Event_Gamma_HeadingToTheRear,
	Sonic_vs_Gamma,
	Event_Sonic_HeadsAfterEggman,
	Event_Amy_LeavesWithTails,
	Event_Sonic_ChangingTheEggCarrierBack,
	Event_Sonic_EggCarrierTransformsBack,
	Event_Big_ReadyToLeaveTheEggCarrier,
	Event_Knuck_ReturningToThePresent,
	Event_Knuck_ToChaos6,
	Big_Chaos6,
	Sonic_Chaos6,
	Event_Big_TakesTheTornado2,
	Knuck_Chaos6,
	Event_Knuck_ReturningToAngelIsland,
	Event_Sonic_LandsInMysticRuins,
	Sonic_LostWorld,
	Event_Sonic_TravelsToThePast,
	Event_Sonic_Meets_Tikal,
	Event_Big_Outro,
	Event_Gamma_ObjectiveChanged,
	Gamma_WindyValley,
	Gamma_ToRedMountain,
	Gamma_RedMountain,
	Event_Tails_EggmanLaunchesMissile,
	Event_Tails_HeadsAfterTheMissile,
	Tails_SpeedHighway,
	Amy_ToEggBase,
	Event_Amy_DiscoveringTheEggBase,
	Amy_FinalEgg,
	Event_Tails_FinalBossEncounter,
	Tails_EggWalker,
	Event_Tails_AfterFinalBoss,
	Event_Gamma_RememberingHisBrothers,
	Event_Sonic_SpotsEggman,
	Sonic_FinalEgg,
	Event_Gamma_HeadingToHotShelter,
	Gamma_ToHotShelter,
	Gamma_HotShelter,
	Sonic_EggViper,
	Event_Sonic_Outro,
	Event_Gamma_E105Rescued,
	Gamma_Betamk,
	Event_Gamma_Outro,
	Event_Knuck_RestoringTheMasterEmerald,
	Event_Amy_BackToTheEggCarrier,
	Event_Amy_FinalBoss,
	Amy_Zero,
	Event_Amy_Outro,
	Event_Knuck_Outro,
	Event_Final_Tornado2Crash,
	Event_Final_EggmanInMysticRuins,
	Event_Final_KnucklesAtTheMasterEmerald,
	Event_Final_TailsFindsSonic,
	Event_Final_SonicFindsKnuxAndEggman,
	Event_Final_SonicHeadsToThePast,
	Event_Final_TikalsPlea,
	Event_Final_EchidnasFaceChaos,
	Event_Final_SonicChecksOnTikal,
	Event_Final_TikalSealsChaos,
	Event_Final_SonicWakesUp,
	Event_Final_SonicAndTailsReachTornado2,
	Sonic_Chaos7,
	StationSquare_ChaoGarden,
	MysticRuins_ChaoGarden,
	EggCarrier_ChaoGarden,
	Amy_LongHammer,
};

enum FieldDescriptions
{	
	Field_Sonic_Sees_Tails_Crash = 5,
	Field_SonicAndTails_Poolside = 7,
	Field_Tails_ToMysticRuins = 8,
	Field_Sonic_ToEggHornet = 9,
	Field_SonicAndTails_Meet_Chaos1 = 12,
	Field_Sonic_ToStationSquare = 15,
	Field_Knuck_OnTheHuntForPieces = 16,
	Field_Sonic_ToCasinopolis = 18,
	Field_Knuck_ToCasinopolis = 21,
	Field_Knuck_BackToThePresent = 26,
	Field_Knuck_FollowingEggman = 27,
	Field_SonicAndTails_WakeUp = 30,
	Field_Sonic_ToIceCap = 31,
	Field_Big_SearchingForFroggy = 32,
	Field_Big_FroggyGoesToSewers = 33,
	Field_Big_ToMysticRuins = 35,
	Field_Big_ToIceCap = 36,
	Field_Gamma_Intro = 37,
	Field_Gamma_ToBeta = 40,
	Field_Knuck_ToRedMountain = 45,
	Field_Sonic_ToVSKnuckles = 49,
	Field_SonicAndTails_Depart_Knuckles = 53,
	Field_Knuck_ToLostWorld = 54,
	Field_Tails_WakeUpFromDream = 61,
	Field_Tails_ChasesFroggy = 62,
	Field_Amy_MeetingBirdie = 68,
	Field_Amy_FindsSonic = 69,
	Field_Tails_MeetsBig = 74,
	Field_Big_ToStationSquare = 76,
	Field_Sonic_SearchesFor_Amy = 78,
	Field_Sonic_ToCasinoArea = 81,
	Field_Sonic_Finds_AmyAndZero = 82,
	Field_Big_FroggyGoesToTheBeach = 83,
	Field_Gamma_ToEmeraldCoast = 84,
	Field_Knuck_PartialRestoration = 89,
	Field_Sonic_Loses_Amy = 91,
	Field_SonicAndTailsOnTheEggCarrier = 99,
	Field_Knuck_EggCarrierTransforms2 = 104,
	Field_Sonic_EggCarrierTransforms = 105,
	Field_Amy_TalkingToGamma = 109,
	Field_Big_EntersHotShelter = 115,
	Field_Sonic_AfterSkyDeck = 120,
	//Field_Event_Gamma_GoFindTheJetBooster = 124,
	Field_Gamma_ToSonic = 126,
	Field_Sonic_ChangingTheEggCarrierBack = 127,
	Field_Big_ReadyToLeaveTheEggCarrier = 129,
	Field_Knuck_ReturningToThePresent = 133,
	Field_Sonic_LandsInMysticRuins = 137,
	Field_Gamma_ObjectiveChanged = 142,
	Field_Gamma_ToRedMountain = 144,
	Field_Amy_ToEggBase = 150,
	Field_Amy_DiscoveringTheEggBase = 151,
	Field_Gamma_RememberingHisBrothers = 156,
	Field_Sonic_SpotsEggman = 157,
	Field_Gamma_HeadingToHotShelter = 159,
	Field_Gamma_ToHotShelter = 160,
	Field_Gamma_E105Rescued = 166,
	Field_Amy_BackToTheEggCarrier = 170,
	Field_Amy_LongHammer = 171,
	Field_Final_TailsFindsSonic = 179,
	Field_Final_SonicWakesUp = 185
};
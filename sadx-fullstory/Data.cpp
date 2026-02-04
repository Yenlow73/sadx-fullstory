#include "pch.h"
#include <map>

bool SonicChaos6 = true;
bool allUpgrades = true;
bool permanentEntrances = true;
bool earlyGamma = false;
bool TikalOrder = false;
int OutroCharacter = 0;
int CreditCharacter = 0;

int STLevelsCharacter = 0;
int Chaos4Character = 0;
int EggHornetCharacter = 1;

bool AdventureFieldsEnabled = false;
bool BigGameplayEnabled = true;

bool TailsDayTimeEnabled = true;
bool UnusedCutsceneEnabled = false;

bool TitleLogoEnabled = true;

bool jetAnklet = false;
bool lightSpeedShoes = false;
bool crystalRing = false;

bool isPlayerInsideTrigger[STAGE_TRIGGERS] = { false, false, false, false };
bool isAdventureField = false;
bool quitSelected = false;
bool enteredStage = false;
bool isInsideStage = false;
bool isinsideAdventure = false;

int storyComplete = -1;
int triggerIndex = 0;

int currentStage = -1;
int previousStage = -1;
int nextStage = -1;
int previousAct = 0;

int triggerStageIndex[STAGE_TRIGGERS] = {0, 0, 0, 0};

const int ADVENTUREFIELDSSIZE = 43;

PVMEntry texTbl_ev004D[ ] = {
	( char* ) ( "EV_EGGMOBLE0" ), &EV_EGGMOBLE0_TEXLIST,
	( char* ) ( "VER2_WING" ), &VER2_WING_TEXLIST,
	( char* ) ( "EGG_MISSILE" ), &EGG_MISSILE_TEXLIST,
	( char* ) ( "VER1_WING" ),&VER1_WING_TEXLIST,
	( char* ) ( "LOCKET" ),&texlist_locket,
	( char* ) ( "ICM006D" ),&texlist_icm006D,
	0
};

int adventureFields[] =
{
	Event_Sonic_Sees_Tails_Crash,
	Tails_ToMysticRuins,
	Sonic_ToCasinopolis,
	Knuck_ToCasinopolis,
	Event_Knuck_FollowingEggman,
	Event_SonicAndTails_WakeUp,
	Event_Amy_MeetingBirdie,
	Event_Amy_FindsSonic,
	Event_Sonic_SearchesFor_Amy,
	Sonic_ToCasinoArea,
	Event_Sonic_Finds_AmyAndZero,
	Event_Big_FroggyGoesToTheBeach,
	Gamma_ToEmeraldCoast,
	Sonic_ToEggHornet,
	Event_SonicAndTails_Meet_Chaos1,
	Sonic_ToStationSquare,
	Sonic_ToIceCap,
	Big_ToIceCap,
	Knuck_ToRedMountain,
	Knuck_ToSonic,
	Event_SonicAndTails_Depart_Knuckles,
	Knuck_ToLostWorld,
	Event_Tails_WakeUpFromDream,
	Event_Tails_ChasesFroggy,
	Event_Tails_MeetsBig,
	Big_ToStationSquare,
	Event_Knuck_PartialRestoration,
	Event_Sonic_Loses_Amy,
	Event_Gamma_ObjectiveChanged,
	Gamma_ToRedMountain,
	Amy_ToEggBase,
	Event_Amy_DiscoveringTheEggBase,
	Event_Gamma_RememberingHisBrothers,
	Event_Amy_BackToTheEggCarrier,
	Event_Final_TailsFindsSonic,
	Event_Final_SonicWakesUp,
	Event_Amy_WinsHedgehogHammer,
	Event_Big_EntersHotShelter,
	Event_Sonic_AfterSkyDeck,
	Event_Gamma_GoFindTheJetBooster,
	Event_Gamma_HeadingToTheRear,
	Event_Big_ReadyToLeaveTheEggCarrier,
	Gamma_ToHotShelter
};

Trigger triggers[] =
{
	{Sonic_ToEggHornet, 1260, 126, 927, 700},
	{Event_Knuck_InThePast, 0, 0, 1220, 400},
	{Event_Knuck_BackToThePresent, -370, 0, 1635, 10},
	{Event_Gamma_Intro, 0, 108, -148, 60},
	{Gamma_ToBeta, -94, 0, -24, 60},
	{Event_Big_SearchingForFroggy, 510, 0, 880, 10},
	{Knuck_ToSonic, 60, 72, 363, 120},
	{Event_SonicAndTails_Depart_Knuckles, 1260, 126, 927, 700},
	{Event_Knuck_BackToThePast, 0, 90, 60, 60},
	{Event_Tails_WakeUpFromDream, -1147, 35, -238, 120},
	{Event_Tails_EntersThePast, -13, 0, 484, 120},
	{Event_Amy_MeetingBirdie, -444, 0, 1510, 10},
	{Event_Amy_FindsSonic, 320, 0, 1610, 60},
	{Event_Tails_MeetsBig, 1260, 126, 927, 700},
	{Sonic_ToCasinoArea, -444, 0, 1510, 15},
	{Event_Gamma_EntersThePast, 0, 0, 386, 120},
	{Event_Knuck_PartialRestoration, 69, 0, -1633, 240},
	{Event_Amy_EntersThePast, 0, 0, 386, 120},
	{Event_SonicAndTailsOnTheEggCarrier, 0, 742, -162, 400},
	{Event_Knuck_EnteringEggmanBase, 0, 742, -162, 1200},
	{Event_Sonic_EggCarrierTransforms, 0, 748, 382, 45},
	{Event_Knuck_BackToThePastAgain, 0, 0, 440, 120},
	{Event_Big_GoesToThePast, 0, 0, 380, 120},
	{Event_Big_ReadyToLeaveTheEggCarrier, 0, 750, -393, 200},
	{Event_Knuck_ReturningToThePresent, 0, 733, 1049, 10},
	{Event_Sonic_TravelsToThePast, 0, 0, 420, 120},
	{Amy_ToEggBase, 78, 0, -1615, 240},
	{Event_Gamma_E105Rescued, 0, 750, -390, 400},
	{Event_Final_TailsFindsSonic, -25, -260, 2616, 200},
	{Event_Final_SonicHeadsToThePast, 0, 0, 420, 480},
	{Event_Final_EchidnasFaceChaos, 0, 0, 420, 120},
	{Event_Final_SonicChecksOnTikal, 0, 90, 60, 120},
	{Event_Final_SonicWakesUp, -1094, 354, 369, 10},
	{StationSquare_ChaoGarden, -400, 0, 1700, 25 },
	{MysticRuins_ChaoGarden, 1688, 0, -83, 240},
	{EggCarrier_ChaoGarden, -6, 5, 18, 60},
	//{Sonic_EmeraldCoast, 668, 70, -106, 200},
	{Sonic_EmeraldCoast, -550, -10, 2100, 200},
	{Sonic_WindyValley, 668, 70, -186, 240},
	{Sonic_IceCap, -1447, 80, 359, 240},
	{Knuck_SpeedHighway, 269, 0, 252, 240},
	{Knuck_RedMountain, -2042, -350, 1652, 240},
	{Sonic_Casinopolis, -687, 0, 914, 240},
};

Stage stages[] =
{
	// Day 0, Night

	// Chaos breaks free, shattering the Master Emerald
	{true, false, false, false, Characters_Knuckles, STAGE_MR, MysticRuins_AngelIsland, TimesOfDay_Night, Scene_Knuck_Intro},

	// Froggy absorbs Chaos' tail after touching it, swallows Emerald #7 and runs off
	{true, false, false, true, Characters_Big, STAGE_MR, MysticRuins_Jungle, TimesOfDay_Night, Scene_Big_Intro},

	// Sonic fights Chaos 0
	{true, false, false, true, Characters_Sonic, STAGE_SS_AFT, StationSquare_StationArea, TimesOfDay_Night, Scene_Sonic_Intro},
	{false, false, false, false, Characters_Sonic, STAGE_CHAOS0},

	// Day 1, Day

	// Tails crashes his plane
	{true, false, false, false, Characters_Tails, STAGE_SS_AFT, StationSquare_StationArea, TimesOfDay_Day, Scene_Tails_Intro},

	// Sonic goes to Emerald Coast, rescues Tails and they go to Mystic Ruins
	{true, true, false, false, Characters_Sonic, STAGE_SS_AFT, StationSquare_Hotel, TimesOfDay_Day, Scene_Sonic_Sees_Tails_Crash},
	{false, false, false, true, Characters_Sonic, STAGE_BEACH},
	{true, false, false, false, Characters_Tails, STAGE_BEACH, SecondLayout, TimesOfDay_Day, Scene_Tails_SavedBySonic},
	{true, false, false, false, Characters_Tails, STAGE_BEACH, SecondLayout, TimesOfDay_Day, Scene_Tails_SavedBySonic},
	{true, false, false, true, Characters_Sonic, STAGE_SS_AFT, StationSquare_Hotel, TimesOfDay_Day, Scene_SonicAndTails_Poolside},
	{false, false, false, false, Characters_Tails, STAGE_SS_AFT, StationSquare_Hotel, TimesOfDay_Day},

	// Sonic and Tails fight the Egg Hornet
	{false, false, true, true, Characters_Sonic, STAGE_MR, MysticRuins_Station, TimesOfDay_Day},
	{true, false, false, false, Characters_Sonic, STAGE_MR, MysticRuins_Station, TimesOfDay_Day, Scene_SonicAndEggman_Meet},
	{false, false, false, false, Characters_Sonic, STAGE_EGGMOBILE1},
	{false, false, false, false, Characters_Tails, STAGE_EGGMOBILE1},

	// Chaos gets Emerald #1
	{true, true, false, false, Characters_Sonic, STAGE_MR, MysticRuins_Station, TimesOfDay_Day, Scene_SonicAndTails_Meet_Chaos1},

	// Sonic and Tails go find Emerald #2 in Windy Valley and they go back to Station Square
	{false, false, false, true, Characters_Sonic, STAGE_WINDY, FirstLayout},
	{false, false, false, false, Characters_Tails, STAGE_WINDY, ThirdLayout},
	{false, false, false, true, Characters_Sonic, STAGE_MR, FirstLayout, TimesOfDay_Day},

	// Knuckles recovers some shards from Speed Highway
	{true, true, false, true, Characters_Knuckles, STAGE_SS_AFT, StationSquare_StationArea, TimesOfDay_Day, Scene_Knuck_OnTheuntForPieces},
	{false, false, false, true, Characters_Knuckles, STAGE_HIGHWAY, ThirdLayout},

	// Day 1, Night

	// Sonic gets the Light Speed Shoes and finds Emerald #3 in Casinopolis
	{false, false, false, true, Characters_Sonic, STAGE_SS_AFT, StationSquare_StationArea, TimesOfDay_Evening},
	{false, false, false, true, Characters_Sonic, STAGE_CASINO},
	{false, false, false, false, Characters_Tails, STAGE_CASINO, SecondLayout},

	// Knuckles recovers some shards from Casinopolis
	{false, false, false, true, Characters_Knuckles, STAGE_SS_AFT, StationSquare_CityHall, TimesOfDay_Night},
	{false, false, false, true, Characters_Knuckles, STAGE_CASINO},

	// Eggman steals Emerald #3 and knocks Sonic and Tails out
	{true, false, false, true, Characters_Sonic, STAGE_SS_AFT, StationSquare_Station, TimesOfDay_Night, Scene_SonicAndTails_Gassed_At_Casinopolis},

	// Knuckles gets transported to the past and comes back to Station Square
	{true, true, true, true, Characters_Knuckles, STAGE_PAST, Past_Shrine, TimesOfDay_Day, Scene_Knuck_InThePast},
	{true, false, false, false, Characters_Knuckles, STAGE_PAST, Past_Shrine, TimesOfDay_Day, Scene_Knuck_TikalCrisis},
	{true, true, false, true, Characters_Knuckles, STAGE_SS_AFT, StationSquare_Station, TimesOfDay_Night, Scene_Knuck_BackToThePresent},

	// Knuckles spots Eggman in the hotel lobby and fights Chaos 2
	{true, true, false, false, Characters_Knuckles, STAGE_SS_AFT, StationSquare_Hotel, TimesOfDay_Night, Scene_Knuck_FollowingEggman},
	{true, true, false, false, Characters_Knuckles, STAGE_CHAOS2, FirstLayout, TimesOfDay_Night, Scene_Knuck_Chaos2Battle},
	{false, false, false, false, Characters_Knuckles, STAGE_CHAOS2},

	// Day 2, Day 

	// Gamma is activated, finishes Eggman's training course and fights E-101 Beta
	{true, true, true, true, Characters_Gamma, STAGE_MR, MysticRuins_FinalEgg, TimesOfDay_Day, Scene_Gamma_Intro},
	{true, false, false, false, Characters_Gamma, STAGE_MR, MysticRuins_FinalEgg, TimesOfDay_Day, Scene_Gamma_EnterFinalEgg},
	{ true, false, false, false, Characters_Gamma, STAGE_MR, MysticRuins_FinalEgg, TimesOfDay_Day, Scene_Gamma_EggmanDisappointed },
	{false, false, false, true, Characters_Gamma, STAGE_FINAL, ThirdLayout},
	{false, false, true, true, Characters_Gamma, STAGE_MR, MysticRuins_FinalEgg, TimesOfDay_Day},
	{true, false, false, false, Characters_Gamma, STAGE_MR, MysticRuins_FinalEgg, TimesOfDay_Day, Scene_Gamma_AfterFinalEgg},
	{true, false, false, false, Characters_Gamma, STAGE_MR, MysticRuins_FinalEgg, TimesOfDay_Day, Scene_Gamma_FightWithBeta},
	{false, false, false, false, Characters_Gamma, STAGE_E101},
	{true, false, false, false, Characters_Gamma, STAGE_MR, MysticRuins_FinalEgg, TimesOfDay_Day, Scene_Gamma_DefeatsBeta},

	// Sonic and Tails go to the Mystic Ruins and they go to Ice cap to get Emerald #4
	{true, false, false, true, Characters_Sonic, STAGE_SS_AFT, StationSquare_Station, TimesOfDay_Evening, Scene_Sonic_IceStone},
	{true, true, false, false, Characters_Sonic, STAGE_SS_AFT, StationSquare_Station, TimesOfDay_Evening, Scene_SonicAndTails_WakeUp},
	{true, true, false, true, Characters_Sonic, STAGE_MR, MysticRuins_Station, TimesOfDay_Day, Scene_Sonic_WestRock},
	//{false, false, false, false, Characters_Sonic, STAGE_MR, MysticRuins_Station, TimesOfDay_Day},
	{ false, false, false, true, Characters_Sonic, STAGE_SNOW },
	{ false, false, false, false, Characters_Tails, STAGE_SNOW, ThirdLayout },

	// Big arrives in town, chases Froggy to Twinkle Park, and goes to Mystic Ruins
	{true, true, false, true, Characters_Big, STAGE_SS_AFT, StationSquare_StationArea, TimesOfDay_Day, Scene_Big_SearchingForFroggy},
	{true, true, false, false, Characters_Big, STAGE_SS_AFT, StationSquare_CityHall, TimesOfDay_Day, Scene_Big_FroggyGoesToSewers},
	{false, false, false, true, Characters_Big, STAGE_TWINKLEPARK, SecondLayout},
	{ false, false, false, false, Characters_Big, STAGE_SS_AFT, StationSquare_TwinklePark, TimesOfDay_Day },

	// Knuckles recovers some shards from Red Mountain and meets Sonic
	{true, true, false, true, Characters_Knuckles, STAGE_MR, MysticRuins_Station, TimesOfDay_Day, Scene_Knuck_ChasingAfterSonic},
	{false, false, false, true, Characters_Knuckles, STAGE_MOUNTAIN, ThirdLayout},
	{ false, false, true, true, Characters_Knuckles, STAGE_MR, MysticRuins_AngelIsland, TimesOfDay_Day },
	{ true, false, false, false, Characters_Knuckles, STAGE_MR, MysticRuins_Station, TimesOfDay_Day, Scene_Knuck_vs_Sonic },

	// Sonic fights Knuckles (oh no) and fights Chaos 4, Eggman flees to the Egg Carrier
	{ true, true, true, false, Characters_Sonic, STAGE_MR, MysticRuins_Station, TimesOfDay_Day, Scene_Sonic_vs_Knuckles },
	{true, false, false, false, Characters_Sonic, STAGE_MR, MysticRuins_Station, TimesOfDay_Day, Scene_Sonic_Chaos4_Emerges },
	{false, false, false, false, Characters_Sonic, STAGE_CHAOS4},
	{true, true, true, false, Characters_Sonic, STAGE_MR, MysticRuins_Station, TimesOfDay_Day, Scene_SonicAndTails_Depart_Knuckles },

	// Sonic and Tails go to Sky Chase 1 and are shot down and got separated in the crash
	{true, false, false, false, Characters_Sonic, STAGE_MR, MysticRuins_Station, TimesOfDay_Day, Scene_SonicAndTails_Tornado1Takeoff },
	{ false, false, false, true, Characters_Sonic, STAGE_SHOOTING },

	// Big goes to Ice Cap, does not find Froggy
	{ false, false, false, true, Characters_Big, STAGE_MR, MysticRuins_Station, TimesOfDay_Day },

	// Knuckles recovers some shards from Lost World and gets transported to the past again
	{false, false, false, false, Characters_Knuckles, STAGE_MR, MysticRuins_Jungle, TimesOfDay_Day},
	{false, false, false, true, Characters_Knuckles, STAGE_RUIN, SecondLayout},
	{true, true, true, true, Characters_Knuckles, STAGE_PAST, Past_Altar, TimesOfDay_Day, Scene_Knuck_BackToThePast },
	{true, false, false, false, Characters_Knuckles, STAGE_PAST, Past_Altar, TimesOfDay_Day, Scene_Knuck_TikalCrisis2 },

	// Tails dreams about Sonic, goes to Sand Hill to catch Froggy and gets transported to the past
	{ true, false, false, true, Characters_Tails, STAGE_MR, MysticRuins_Jungle, TimesOfDay_Day, Scene_Tails_Flashback },
	{ true, true, true, false, Characters_Tails, STAGE_MR, MysticRuins_Station, TimesOfDay_Evening, Scene_Tails_WakeUpFromDream },
	{ true, true, false, false, Characters_Tails, STAGE_MR, MysticRuins_Jungle, TimesOfDay_Evening, Scene_Tails_ChasesFroggy },
	{ false, false, false, true, Characters_Tails, STAGE_SANDBOARD },
	{ true, true, true, true, Characters_Tails, STAGE_PAST, MysticRuins_Station, TimesOfDay_Day, Scene_Tails_EntersThePast },
	{ true, false, false, false, Characters_Tails, STAGE_PAST, MysticRuins_Station, TimesOfDay_Day, Scene_Tails_MeetsTikal },

	// Sonic falls back to Station Square
	{true, false, false, true, Characters_Sonic, STAGE_SS_AFT, StationSquare_Hotel, TimesOfDay_Day, Scene_Sonic_Falls_StationSquare },

	// Day 2, Evening

	// Amy buys groceries and meets Flicky and Zero, tracks down Sonic and goes to Twinkle Park
	{true, false, false, false, Characters_Amy, STAGE_SS_AFT, StationSquare_CityHall, TimesOfDay_Day, Scene_Amy_Intro },
	{true, true, true, false, Characters_Amy, STAGE_SS_AFT, StationSquare_CityHall, TimesOfDay_Evening, Scene_Amy_MeetingBirdie },
	{true, true, true, false, Characters_Amy, STAGE_SS_AFT, StationSquare_Station, TimesOfDay_Evening, Scene_Amy_FindsSonic },
	{true, false, false, false, Characters_Amy, STAGE_SS_AFT, StationSquare_StationArea, TimesOfDay_Evening, Scene_AmyAndSonic_VisitTwinklePark },

	// Day 2, Night

	// Amy tries to escape Zero in Twinkle Park
	{false, false, false, true, Characters_Amy, STAGE_TWINKLEPARK, SecondLayout},

	// Big runs into Tails in the Mystic Ruins, Froggy escapes
	{true, true, true, true, Characters_Tails, STAGE_MR, MysticRuins_Station, TimesOfDay_Night, Scene_Tails_MeetsBig },
	// Tails uses Emerald #5 to power the Tornado 2
	{ true, false, false, false, Characters_Tails, STAGE_MR, MysticRuins_Station, TimesOfDay_Night, Scene_Tails_Tornado2Takeoff }, // 74

	// Big attempts to catch Froggy in Ice Cap Zone and goes to Station Square
	{ false, false, false, true, Characters_Big, STAGE_SNOW, FourthLayout },
	{ false, false, false, true, Characters_Big, STAGE_MR, MysticRuins_AngelIsland, TimesOfDay_Night },
	
	// Sonic goes to Twinkle Park, loses Amy and goes looking for her in Speed Highway
	{ false, false, false, true, Characters_Sonic, STAGE_TWINKLEPARK }, 
	{true, true, false, true, Characters_Sonic, STAGE_SS_AFT, StationSquare_TwinklePark, TimesOfDay_Night, Scene_Sonic_SearchesFor_Amy },
	{ true, true, false, false, Characters_Sonic, STAGE_SS_AFT, StationSquare_StationArea, TimesOfDay_Night, Scene_Sonic_Card },
	{false, false, false, true, Characters_Sonic, STAGE_HIGHWAY},

	// The E-100 robots are given their assignment to find Froggy
	{ true, false, false, true, Characters_Gamma, LevelIDs_EggCarrierInside, EggCarrierInside_Main, TimesOfDay_Day, Scene_Gamma_TheHuntForFroggy },

	// Day 3, Day

	// Amy eventually gets captured by Zero
	{true, false, false, true, Characters_Amy, STAGE_SS_AFT, StationSquare_StationArea, TimesOfDay_Day, Scene_Amy_KidnappedByZero },

	// Sonic follows Zero and goes to Mystic Ruins
	{false, false, true, false, Characters_Sonic, STAGE_SS_AFT, StationSquare_CityHall, TimesOfDay_Day },
	{true, false, false, false, Characters_Sonic, STAGE_SS_AFT, StationSquare_Station, TimesOfDay_Day, Scene_Sonic_Finds_AmyAndZero },

	// Big follows Froggy to the Emerald Coast
	{true, true, false, false, Characters_Big, STAGE_SS_AFT, StationSquare_StationArea, TimesOfDay_Day, Scene_Froggy_HeadsToBeach },

	// Gamma catches Froggy in Emerald Coast and gets transported to the past 
	{ false, false, false, true, Characters_Gamma, STAGE_SS_AFT, StationSquare_StationArea, TimesOfDay_Day },
	{ false, false, false, true, Characters_Gamma, STAGE_BEACH },
	{ true, true, true, false, Characters_Gamma, STAGE_PAST, Past_Altar, TimesOfDay_Day, Scene_Gamma_EntersThePast },
	{ true, false, false, false, Characters_Gamma, STAGE_PAST, Past_Altar, TimesOfDay_Day, Scene_Gamma_MeetsTikal },

	// Big catches Froggy but Gamma snatches it
	{false, false, false, true, Characters_Big, STAGE_BEACH, ThirdLayout},

	// Knuckles partially restores the Master Emerald and spots Gamma returning to the Egg Carrier
	{true, true, true, true, Characters_Knuckles, STAGE_MR, MysticRuins_AngelIsland, TimesOfDay_Day, Scene_Knuck_PartialRestoration },
	{true, false, false, false, Characters_Knuckles, STAGE_MR, MysticRuins_Jungle, TimesOfDay_Day, Scene_Knuck_FollowingGamma },

	// Sonic loses Amy, goes to Red Mountain and Sonic and Tails fly to the Egg Carrier
	{true, true, false, false, Characters_Sonic, STAGE_MR, MysticRuins_Station, TimesOfDay_Day, Scene_Sonic_Loses_Amy },
	{false, false, false, true, Characters_Sonic, STAGE_MOUNTAIN},
	{ false, false, false, true, Characters_Sonic, STAGE_SHOOTING2 },

	// EGG CARRIER

	// Gamma gets a new assignment and accidentaly finds Beta
	{true, false, true, true, Characters_Gamma, LevelIDs_EggCarrierInside, EggCarrierInside_Main, TimesOfDay_Day, Scene_Gamma_ReturnToTheEggCarrier },
	{true, false, false, false, Characters_Gamma, LevelIDs_EggCarrierInside, EggCarrierInside_Main, TimesOfDay_Day, Scene_Gamma_HeadToBeta },
	{true, false, false, false, Characters_Gamma, LevelIDs_EggCarrierInside, EggCarrierInside_HedgehogHammer, TimesOfDay_Day, Scene_Gamma_Beta },
	{true, false, false, false, Characters_Gamma, LevelIDs_EggCarrierInside, EggCarrierInside_Main, TimesOfDay_Day, Scene_Gamma_LeavesBeta },

	// Amy gets released, plays Hedgehog Hammer, goes to Hot Shelter and gets transported to the past
	{ true, true, false, false, Characters_Amy, LevelIDs_EggCarrierInside, EggCarrierInside_PrisonHall, TimesOfDay_Day, Scene_Amy_TalkingToGamma },
	{ true, true, false, false, Characters_Amy, LevelIDs_EggCarrierInside, EggCarrierInside_HedgehogHammer, TimesOfDay_Day, Scene_Amy_HedgehogHammer },
	{ true, true, false, false, Characters_Amy, LevelIDs_EggCarrierInside, EggCarrierInside_HedgehogHammer, TimesOfDay_Day, Scene_Amy_WinsHedgehogHammer },
	{ false, false, false, true, Characters_Amy, STAGE_SHELTER},
	{ true, true, true, true, Characters_Amy, STAGE_PAST, Past_Shrine, TimesOfDay_Day, Scene_Amy_EntersThePast },
	{ true, false, false, false, Characters_Amy, STAGE_PAST, Past_Altar, TimesOfDay_Day, Scene_Amy_MeetsTikal },

	// Sonic & Tails enter the Egg Carrier and the Egg Carrier is about to transform
	{true, false, false, false, Characters_Sonic, LevelIDs_EggCarrierOutside, EggCarrierOutside_Runway, TimesOfDay_Day, Scene_Sonic_Tornado2Transform },
	{ true, true, true, false, Characters_Sonic, LevelIDs_EggCarrierOutside, EggCarrierOutside_Runway, TimesOfDay_Day, Scene_SonicAndTailsOnTheEggCarrier },
	{true, false, false, false, Characters_Sonic, LevelIDs_EggCarrierOutside, EggCarrierOutside_Runway, TimesOfDay_Day, Scene_Sonic_SkyChaseAttack },

	// Knuckles enters the Egg Carrier, the Egg Carrier transforms, and Knuckles goes to Sky Deck
	{ true, true, true, false, Characters_Knuckles, LevelIDs_EggCarrierOutside, EggCarrierOutside_Runway, TimesOfDay_Day, Scene_Knuck_EnteringEggmanBase },
	{ true, false, false, false, Characters_Knuckles, LevelIDs_EggCarrierOutside, EggCarrierOutside_Runway, TimesOfDay_Day, Scene_Knuck_EggCarrierTransforms1 },
	{false, false, false, false, Characters_Knuckles, LevelIDs_EggCarrierOutside, EggCarrierOutside_Transforming },
	{ true, true, false, false, Characters_Knuckles, LevelIDs_EggCarrierOutside, EggCarrierOutside_Deck, TimesOfDay_Day, Scene_Knuck_EggCarrierTransforms2 },
	{ true, true, false, false, Characters_Knuckles, LevelIDs_EggCarrierOutside, EggCarrierOutside_Pool, TimesOfDay_Day, Scene_Knuck_EggCarrierSensingTheEmerald },

	// Sonic and tails go to Sky Deck
	{ true, true, true, false, Characters_Sonic, LevelIDs_EggCarrierOutside, EggCarrierOutside_Bridge, TimesOfDay_Day, Scene_Sonic_EggCarrierTransforms },
	{ true, true, false, false, Characters_Sonic, LevelIDs_EggCarrierOutside, EggCarrierOutside_Bridge, TimesOfDay_Day, Scene_Sonic_SkyDeckEntrance },
	{ false, false, false, true, Characters_Tails, STAGE_SKYDECK },
	{ false, false, false, false, Characters_Sonic, STAGE_SKYDECK },

	// Big fishes up Froggy from the Hot Shelter and gets transported to the past
	{ true, true, false, true, Characters_Big, LevelIDs_EggCarrierInside, EggCarrierInside_Main, TimesOfDay_Day, Scene_Big_EntersHotShelter },
	{ false, false, false, true, Characters_Big, STAGE_SHELTER },
	{ true, true, true, true, Characters_Big, STAGE_PAST, Past_Altar, TimesOfDay_Day, Scene_Big_GoesToThePast },
	{ true, false, false, false, Characters_Big, STAGE_PAST, Past_Altar, TimesOfDay_Day, Scene_Big_MeetsTikal },

	// Knuckles recovers the final shards from Sky Deck and  gets transported to the past for the third time
	{ false, false, false, true, Characters_Knuckles, STAGE_SKYDECK, ThirdLayout },
	{ true, true, true, true, Characters_Knuckles, STAGE_PAST, Past_AltarFire, TimesOfDay_Day, Scene_Knuck_BackToThePastAgain },
	{ true, false, false, false, Characters_Knuckles, STAGE_PAST, Past_AltarFire, TimesOfDay_Day, Scene_Knuck_TikalAftermath },

	// Amy, Sonic and Tails go to the bridge
	{ true, false, false, true, Characters_Amy, LevelIDs_EggCarrierOutside, EggCarrierOutside_Pool, TimesOfDay_Day, Scene_Amy_ReturningFromThePast },
	{ true, true, false, false, Characters_Sonic, LevelIDs_EggCarrierInside, EggCarrierInside_Main, TimesOfDay_Day, Scene_Sonic_AfterSkyDeck },

	// Gamma gets the Jet Booster and goes to the bridge 
	{ false, false, false, false, Characters_Gamma, LevelIDs_EggCarrierInside, EggCarrierInside_HedgehogHammer, TimesOfDay_Day },
	{ true, true, false, false, Characters_Gamma, LevelIDs_EggCarrierInside, EggCarrierInside_Main, TimesOfDay_Day, Scene_Gamma_GoFindTheJetBooster },
	{ true, true, false, false, Characters_Gamma, LevelIDs_EggCarrierInside, EggCarrierInside_Main, TimesOfDay_Day, Scene_Gamma_HeadingToTheRear },

	// Eggman steals Flicky, Sonic fights Gamma, Amy breaks up the fight, flees the ship with Tails and Gamma flies away
	{ true, true, true, false, Characters_Sonic, LevelIDs_EggCarrierOutside, EggCarrierOutside_Deck, TimesOfDay_Day, Scene_Sonic_vs_Gamma },
	{true, false, false, false, Characters_Sonic, LevelIDs_EggCarrierOutside, EggCarrierOutside_Deck, TimesOfDay_Day, Scene_Sonic_HeadsAfterEggman },
	{true, false, false, false, Characters_Amy, LevelIDs_EggCarrierOutside, EggCarrierOutside_Deck, TimesOfDay_Day, Scene_Amy_LeavesWithTails },

	// Sonic finds the switch to transform the Egg Carrier
	{ true, true, false, false, Characters_Sonic, LevelIDs_EggCarrierOutside, EggCarrierOutside_Deck, TimesOfDay_Day, Scene_Sonic_ChangingTheEggCarrierBack },
	{ true, false, false, false, Characters_Sonic, LevelIDs_EggCarrierOutside, EggCarrierOutside_CaptainRoom, TimesOfDay_Day, Scene_Sonic_EggCarrierTransformsBack },

	// Big goes to the bridge
	{ true, true, false, false, Characters_Big, LevelIDs_EggCarrierInside, EggCarrierInside_Main, TimesOfDay_Day, Scene_Big_ReadyToLeaveTheEggCarrier },

	// Knuckles goes to the bridge
	{ true, true, true, false, Characters_Knuckles, LevelIDs_EggCarrierOutside, EggCarrierOutside_Pool, TimesOfDay_Day, Scene_Knuck_ReturningToThePresent },
	{ true, false, false, false, Characters_Knuckles, LevelIDs_EggCarrierOutside, EggCarrierOutside_Runway, TimesOfDay_Day, Scene_Knuck_AllShardCollected },

	// Big fishes Froggy out of Chaos 6
	{false, false, false, false, Characters_Big, STAGE_CHAOS6},
	
	// Sonic fights Chaos 6
	{false, false, false, false, Characters_Sonic, STAGE_CHAOS6},

	// Big flees the ship in the Tornado 2
	{ true, false, false, true, Characters_Big, LevelIDs_EggCarrierOutside, EggCarrierOutside_Runway, TimesOfDay_Day, Scene_Big_TakesTheTornado2 },

	// Knuckles defeats Chaos 6 once and for all, gets 6 Chaos Emeralds and heads home
	{false, false, false, false, Characters_Knuckles, STAGE_CHAOS6, SecondLayout},
	{true, false, false, false, Characters_Knuckles, LevelIDs_EggCarrierOutside, EggCarrierOutside_Runway, TimesOfDay_Day, Scene_Knuck_ReturningToAngelIsland },

	// EGG CARRIER SINKS

	// Sonic searches for Eggman in the Lost World and gets transported to the past
	{ true, true, false, true, Characters_Sonic, STAGE_MR, MysticRuins_Jungle, TimesOfDay_Day, Scene_Sonic_LandsInMysticRuins },
	{ false, false, false, true, Characters_Sonic, STAGE_RUIN },
	{ true, true, true, true, Characters_Sonic, STAGE_PAST, Past_AltarFire, TimesOfDay_Day, Scene_Sonic_TravelsToThePast },
	{ true, false, false, false, Characters_Sonic, STAGE_PAST, Past_AltarFire, TimesOfDay_Day, Scene_Sonic_Meets_Tikal },

	// Big heads home with Froggy 
	{ true, false, false, true, Characters_Big, STAGE_MR, MysticRuins_Jungle, TimesOfDay_Day, Scene_Big_Outro },

	// Gamma embarks on its mission and destroys E-103 in Windy Valley
	{ true, true, false, false, Characters_Gamma, STAGE_MR, MysticRuins_Station, TimesOfDay_Day, Scene_Gamma_ObjectiveChanged },
	{false, false, false, true, Characters_Gamma, STAGE_WINDY },

	// Day 3, Evening

	// Gamma destroys E-104 in Red Mountain
	{ false, false, false, true, Characters_Gamma, STAGE_MR, MysticRuins_Station, TimesOfDay_Evening },
	{ false, false, false, true, Characters_Gamma, STAGE_MOUNTAIN, SecondLayout },

	// Tails and Amy land in Station Square, Amy goes to Mystic Ruins and Tails goes to Speed Highway to stop Eggman from destroying Station Square
	{ true, false, false, true, Characters_Tails, STAGE_SS_AFT, StationSquare_StationArea, TimesOfDay_Evening, Scene_Tails_EggmanLaunchesMissile },
	{ true, false, false, false, Characters_Tails, STAGE_SS_AFT, StationSquare_StationArea, TimesOfDay_Evening, Scene_Tails_HeadsAfterTheMissile },
	{false, false, false, true, Characters_Tails, STAGE_HIGHWAY},

	// Day 3, Night

	// Amy starts searching for Flicky's family and goes to Final Egg
	{false, false, true, true, Characters_Amy, STAGE_MR, MysticRuins_Station, TimesOfDay_Night},
	{ true, true, false, false, Characters_Amy, STAGE_MR, MysticRuins_Jungle, TimesOfDay_Night, Scene_Amy_DiscoveringTheEggBase },
	{false, false, false, true, Characters_Amy, STAGE_FINAL},

	// Tails fights Egg Walker and defeats Eggman, but he flees
	{true, false, false, true, Characters_Tails, STAGE_SS_AFT, StationSquare_Station, TimesOfDay_Night, Scene_Tails_FinalBossEncounter },
	{false, false, false, false, Characters_Tails, STAGE_EGGMOBILE2},
	{true, false, false, false, Characters_Tails, STAGE_SS_AFT, StationSquare_Station, TimesOfDay_Night, Scene_Tails_AfterFinalBoss },

	// Gamma goes to Egg Carrier to rescue E-104
	{ true, true, false, true, Characters_Gamma, STAGE_MR, MysticRuins_AngelIsland, TimesOfDay_Night, Scene_Gamma_RememberingHisBrothers },

	// Day 4, Day

	// Sonic spots Eggman and goes to the Final Egg
	{ true, true, false, false, Characters_Sonic, STAGE_MR, MysticRuins_Jungle, TimesOfDay_Evening, Scene_Sonic_SpotsEggman },
	{false, false, false, true, Characters_Sonic, STAGE_FINAL},

	// Gamma searches for E-104 in the Egg Carrier and goes to Hot Shelter
	{ true, true, false, true, Characters_Gamma, LevelIDs_EggCarrierOutside, EggCarrierOutside_Runway, TimesOfDay_Day, Scene_Gamma_HeadingToHotShelter },
	{ false, false, false, false, Characters_Gamma, LevelIDs_EggCarrierInside, EggCarrierInside_Main, TimesOfDay_Day },
	{ false, false, false, true, Characters_Gamma, STAGE_SHELTER, ThirdLayout },

	// Sonic fights Egg Viper and defeats Eggman and reunites with Tails in the Mystic Ruins
	{false, false, false, false, Characters_Sonic, STAGE_EGGMOBILE3 },
	{ true, false, false, true, Characters_Sonic, STAGE_MR, MysticRuins_Station, TimesOfDay_Day, Scene_Sonic_Outro },
	//{ true, false, false, false, Characters_Tails, STAGE_MR, MysticRuins_Station, TimesOfDay_Day, Scene_Tails_Outro },

	// Gamma fights Beta and destroys it and itself, freeing Flicky's family
	{true, true, true, true, Characters_Gamma, LevelIDs_EggCarrierOutside, EggCarrierOutside_Runway, TimesOfDay_Day, Scene_Gamma_E105Rescued },
	{false, false, false, false, Characters_Gamma, STAGE_E101_R},
	{true, false, false, false, Characters_Gamma, LevelIDs_EggCarrierOutside, EggCarrierOutside_Bridge, TimesOfDay_Day, Scene_Gamma_Outro },

	// Knuckles puts the Master Emerald back together and Angel Island takes flight once more
	{ true, false, false, true, Characters_Knuckles, STAGE_MR, MysticRuins_AngelIsland, TimesOfDay_Day, Scene_Knuck_RestoringTheMasterEmerald },

	// Amy goes to the Egg Carrier, reunites Flicky and his family and destroys Zero, and says goodbye to the Flickies
	{true, true, false, false, Characters_Amy, STAGE_MR, MysticRuins_FinalEgg, TimesOfDay_Day, Scene_Amy_BackToTheEggCarrier },
	{true, false, false, true, Characters_Amy, LevelIDs_EggCarrierOutside, EggCarrierOutside_Bridge, TimesOfDay_Day, Scene_Amy_FinalBoss },
	{false, false, false, false, Characters_Amy, STAGE_EGGMANROBO},
	{true, false, false, false, Characters_Amy, LevelIDs_EggCarrierOutside, EggCarrierOutside_Bridge, TimesOfDay_Day, Scene_Amy_Outro },

	// Knuckles finally rests for a bit
	{ true, false, false, true, Characters_Knuckles, STAGE_MR, MysticRuins_AngelIsland, TimesOfDay_Day, Scene_Knuck_Outro },

	// Tornado 2 is parked at Big's house
	{true, false, false, false, Characters_Sonic, STAGE_MR, MysticRuins_Jungle, TimesOfDay_Day, Scene_Final_Tornado2Crash },

	// Eggman yells at Chaos 0
	{ true, false, false, false, Characters_Sonic, STAGE_MR, MysticRuins_Jungle, TimesOfDay_Day, Scene_Final_EggmanInMysticRuins },

	// Angel Island falls
	{ true, false, false, false, Characters_Sonic, STAGE_MR, MysticRuins_AngelIsland, TimesOfDay_Day, Scene_Final_KnucklesAtTheMasterEmerald },

	// Tails finds Sonic and they go to Angel Island to find Knuckles and Eggman
	{ true, true, true, false, Characters_Sonic, STAGE_MR, MysticRuins_Station, TimesOfDay_Day, Scene_Final_TailsFindsSonic },
	{ true, false, false, false, Characters_Sonic, STAGE_MR, MysticRuins_AngelIsland, TimesOfDay_Day, Scene_Final_SonicFindsKnuxAndEggman },

	// Sonic goes to the past for the final time
	{ true, true, true, false, Characters_Sonic, STAGE_PAST, Past_AltarFire, TimesOfDay_Day, Scene_Final_SonicHeadsToThePast },
	{ true, false, false, false, Characters_Sonic, STAGE_PAST, Past_AltarFire, TimesOfDay_Day, Scene_Final_TikalsPlea },
	{ true, true, true, false, Characters_Sonic, STAGE_PAST, Past_AltarFire, TimesOfDay_Day, Scene_Final_EchidnasFaceChaos },
	{ true, true, true, false, Characters_Sonic, STAGE_PAST, Past_AltarFire, TimesOfDay_Day, Scene_Final_SonicChecksOnTikal },
	{ true, false, false, false, Characters_Sonic, STAGE_PAST, Past_AltarFire, TimesOfDay_Day, Scene_Final_TikalSealsChaos },

	// Sonic wakes up and goes to the Tornado 2
	{ true, true, true, true, Characters_Sonic, STAGE_MR, MysticRuins_AngelIsland, TimesOfDay_Day, Scene_Final_SonicWakesUp },
	{ true, false, false, false, Characters_Sonic, STAGE_MR, MysticRuins_Jungle, TimesOfDay_Day, Scene_Final_SonicAndTailsReachTornado2 },

	// Super Sonic defeats Perfect Chaos
	{false, false, false, false, Characters_Sonic, STAGE_CHAOS7},

	// Chao Garden stages
	{false, false, false, false, Characters_Sonic, STAGE_AL_GARDEN00_SS},
	{false, false, false, false, Characters_Sonic, STAGE_AL_GARDEN02_MR},
	{false, false, false, false, Characters_Sonic, STAGE_AL_GARDEN01_EC},

	// Amy gets the Long Hammer upgrade
	{ false, false, false, true, Characters_Amy, LevelIDs_EggCarrierInside, EggCarrierInside_Main, TimesOfDay_Day },
	
};

std::map<int, int> triggerPoints = {
	{Sonic_ToEggHornet,Trigger_Sonic_ToEggHornet},
	{Event_Knuck_InThePast,Trigger_Event_Knuck_InThePast},
	{Event_Knuck_BackToThePresent,Trigger_Event_Knuck_BackToThePresent},
	{Event_Gamma_Intro,Trigger_Event_Gamma_Intro},
	{Gamma_ToBeta,Trigger_Gamma_ToBeta},
	{Event_Big_SearchingForFroggy,Trigger_Event_Big_SearchingForFroggy},
	{Knuck_ToSonic,Trigger_Knuckles_ToSonic},
	{Event_SonicAndTails_Depart_Knuckles,Trigger_Event_SonicAndTails_Depart_Knuckles},
	{Event_Knuck_BackToThePast,Trigger_Event_Knuck_BackToThePast},
	{Event_Tails_WakeUpFromDream,Trigger_Event_Tails_WakeUpFromDream},
	{Event_Tails_EntersThePast,Trigger_Event_Tails_EntersThePast},
	{Event_Amy_MeetingBirdie,Trigger_Event_Amy_MeetingBirdie},
	{Event_Amy_FindsSonic,Trigger_Event_Amy_FindsSonic},
	{Event_Tails_MeetsBig,Trigger_Event_Tails_MeetsBig},
	{Sonic_ToCasinoArea,Trigger_Sonic_ToCasinoArea},
	{Event_Gamma_EntersThePast,Trigger_Event_Gamma_EntersThePast},
	{Event_Knuck_PartialRestoration,Trigger_Event_Knuck_PartialRestoration},
	{Event_Amy_EntersThePast,Trigger_Event_Amy_EntersThePast},
	{Event_SonicAndTailsOnTheEggCarrier,Trigger_Event_SonicAndTailsOnTheEggCarrier},
	{Event_Knuck_EnteringEggmanBase,Trigger_Event_Knuck_EnteringEggmanBase},
	{Event_Sonic_EggCarrierTransforms,Trigger_Event_Sonic_EggCarrierTransforms},
	{Event_Knuck_BackToThePastAgain,Trigger_Event_Knuck_BackToThePastAgain},
	{Event_Big_GoesToThePast,Trigger_Event_Big_GoesToThePast},
	{Event_Big_ReadyToLeaveTheEggCarrier,Trigger_Event_Big_ReadyToLeaveTheEggCarrier},
	{Event_Knuck_ReturningToThePresent,Trigger_Event_Knuck_ReturningToThePresent},
	{Event_Sonic_TravelsToThePast,Trigger_Event_Sonic_TravelsToThePast},
	{Amy_ToEggBase,Trigger_Amy_ToEggBase},
	{Event_Gamma_E105Rescued,Trigger_Event_Gamma_E105Rescued},
	{Event_Final_TailsFindsSonic,Trigger_Event_Final_TailsFindsSonic},
	{Event_Final_SonicHeadsToThePast,Trigger_Event_Final_SonicHeadsToThePast},
	{Event_Final_EchidnasFaceChaos,Trigger_Event_Final_EchidnasFaceChaos},
	{Event_Final_SonicChecksOnTikal,Trigger_Event_Final_SonicChecksOnTikal},
	{Event_Final_SonicWakesUp,Trigger_Event_Final_SonicWakesUp}
};

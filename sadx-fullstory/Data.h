#pragma once
#include <fstream>
#include <map>
#include <unordered_map>
#include <Include/ninja.h>
#include <Include/SADXModLoader.h>
#include <vector>
#include <optional>

typedef void(__cdecl* SET_SHADER_FLAGS)(uint32_t, bool);
typedef void(__cdecl* PALETTE_FROM_RGB)(int, unsigned char, unsigned char, unsigned char, bool, bool);
typedef void(__cdecl* SET_BLEND_FACTOR)(float);
typedef void(__cdecl* SET_DIFFUSE_BLEND)(int, int);

void Init_Progression();
void Init_Stages();
void Init_StageOnFrames();

void SaveProgression();
void ApplyVisualSettings();
void CreateSave();

void SetNextStage(char stage, char act);

int GetStageIndex(const std::string& name);
void SetStageOnFrames();
void CheckandPlayCutscene();
void SetCompletion();
void SetStuffInsidePause();
void ResetLighting();
bool IsPointInsideSphere(NJS_VECTOR* center, NJS_VECTOR* pos, float radius);
bool IsAdventureField(int level, bool includePast);

void LoadProgression();

void LoadEnums();
void LoadFieldStages();
void LoadSettingStages();
void LoadStages();

extern std::string modpath;

enum LanternFlags : uint32_t 
{
    LFLAG_BLEND          = 1 << 4,  // 16: Enable palette blending
    LFLAG_FOG            = 1 << 5,  // 32: Enable standard fog
    LFLAG_RANGE_FOG      = 1 << 6,  // 64: Enable distance-based fog
    LFLAG_PALETTE_FOG    = 1 << 7,  // 128: Use Specular row for Fog Color
};

enum FadeSetting 
{
	ColorBlack = 0,
    DefaultMax = 85,
    DefaultPeak = 30,
    OutInMax = 55,
    OutInPeak = 30,   
    InMax = 85,
    InPeak = 60,
    AlphaStep = 8
};

enum StoryState
{
	Story_NotStarted = -1,
	Story_Started = 0,
	Story_Completed = 1
};

enum MasterEmeraldState
{
	MasterEmerald_Broken = 1,
	MasterEmerald_PartiallyRestored = 2,
	MasterEmerald_FullyRestored = 3
};

enum FadeMode
{
    Fade_OutIn, 
    Fade_In,   
    Fade_Out,
	Fade_NoFade
};

enum StageChar
{
	Char_SonicTails,
	Char_Sonic,
	Char_Tails,
	Char_Knuckles
};

enum CreditsChar
{
	CreditsChar_Sonic,
	CreditsChar_Final
};

enum GammaChar
{
	GammaChar_SonicAmy,
	GammaChar_Gamma
};

enum FMV
{
	FMV_Default,
	FMV_PerfectChaos,
	FMV_AngelIslandFalling,
	FMV_AngelIslandRising,
	FMV_EggCarrierStationSquare,
	FMV_EggCarrierAngelIsland,
	FMV_EggCarrierSky,
	FMV_EggCarrierFalling,
	FMV_EggCarrierRising,
};

struct SessionState
{
	bool quitSelected = false;
	bool enteredFieldStage = false;
	bool isInsideAdventure = false;
	bool cutscenePlayed = false;
	bool displayCardAfterLoad = true;
	
	int storyStatus = -1;
	int currentSave = -1;
	int currentStage = -1;
	int previousAct = -1;
	int gameMode = -1;

	int currentDay = 0;
	int currentTime = 0;

	NJS_VECTOR lastPlayerPosition = {0, 0, 0};

	bool frameBufferEnabled = false;
	bool isInsideTrigger = false;
	bool isInBossFight = false;
	bool bossSpawned = false;
	bool drawSpheres = false;
	bool startPositionSet = false;
	bool creditsModified = false;
	bool setupStage = false;

	int frameDelay = 30;
	int frameCounter = 0;

	int fadeMode = 0;
	int outroSceneID = -1;
};

struct ModsEnabled
{
	bool dreamcastConversion = false;
	bool lanternEngine = false;
	bool betterTailsAI = false;
	bool aventuraDeSonic = false;
};

struct PlayerUpgrades
{
	bool jetAnklet = false;
	bool lightSpeedShoes = false;
	bool crystalRing = false;
};

struct LanternAPI 
{
	bool lightingChanged = false;

    SET_SHADER_FLAGS set_shader_flags = nullptr;
    PALETTE_FROM_RGB palette_from_rgb = nullptr;
    SET_BLEND_FACTOR set_diffuse_blend_factor = nullptr;
    SET_DIFFUSE_BLEND set_diffuse_blend = nullptr;
};

struct LanternFunction 
{
    void** target;
    const char* name;
};

struct ModSettings 
{
	int sonicTailsChar = Char_SonicTails;
	int chaos4Char = Char_Sonic;
	int eggHornetChar = Char_Sonic;

	int sonicVSGammaChar = GammaChar_SonicAmy;
	int victoryChar = Char_Sonic;
	int creditsChar = CreditsChar_Final;
	bool unusedCutsceneEnabled = false;
	
	bool skipBigGameplay = false;
	bool earlyGammaEnabled = false;
	bool skipTikalFlashbacks = false;
	bool fieldsDisabled = false;

	bool dynamicStagesEnabled = true;
	bool pauseInfoEnabled = true;
	bool titleLogoEnabled = true;
};

struct SceneTrigger
{
	int stageIndex;
	NJS_VECTOR position;
	int radius;
};

struct ConditionTrigger
{
	int stage = -1;
    int act = -1;       
	int flag = -1;
};

struct FieldStage 
{
	int field;
	int level;
    NJS_VECTOR position;
    float radius; 
    std::vector<std::string> excludedStages;
	std::unordered_map<int, int> characterActs;	
	std::vector<int> eventTrue, eventFalse;
};

struct CharStartPosition 
{
    NJS_VECTOR position;
    int rotationY;
};

struct SplitText 
{
    std::string line1;
    std::string line2;
};

struct RGBColor
{
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};

struct TextureSwap 
{
    std::string source;
    std::string destination;
};

struct StagePreset 
{
	RGBColor diffuse;
	uint32_t fog;

	std::vector<TextureSwap> textures;
};

struct SettingStages
{
    std::vector<std::string> sonicStages;
    std::vector<std::string> tailsStages;
    std::vector<std::string> bigStages;
    std::vector<std::string> gammaUnusedCutscene;
    std::vector<std::string> tikalFlashbacks;
    std::vector<std::string> gammaIntroStages;
	std::vector<std::string> fieldStages;
};

struct Stage
{
	std::string name;

	int id;
	int8_t character;
	int level;
	int act;
	int timeofDay;
	int cutsceneID;

	bool displayCard;
	bool controlAfterCutscene;

	std::string objective[6]; 

	std::vector<int> eventTrue, eventFalse;
    std::vector<int> cutsceneTrue, cutsceneFalse;
	
	std::optional<SceneTrigger> sceneTrigger;
	std::optional<ConditionTrigger> conditionTrigger;
    std::optional<CharStartPosition> startPosition;
	std::optional<StagePreset> stagePreset;
};

extern std::vector<FieldStage> fieldStages;
extern std::vector<Stage> stages;
extern std::vector<LanternFunction> lanternFunctions;

extern std::unordered_map<std::string, int> stage;
extern std::unordered_map<std::string, int> scene;
extern std::unordered_map<std::string, int> flag;
extern std::unordered_map<std::string, int> act;
extern std::unordered_map<std::string, int> timeofDay;

extern const std::unordered_map<int, unsigned int> timeColors;
extern const std::unordered_map<int, unsigned int> characterColors;

extern const std::unordered_map<std::string, void(__cdecl*)(int)> sceneFunctions;

extern const char* const dayTimes[6][4];

extern SessionState session;
extern ModSettings settings;
extern LanternAPI lanternAPI;
extern PlayerUpgrades playerUpgrades;
extern ModsEnabled modsEnabled;
extern SettingStages settingStages;

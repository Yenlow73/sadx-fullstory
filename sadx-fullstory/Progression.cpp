#include "pch.h"

using json = nlohmann::json;
using namespace std;

Trampoline* DeleteSave_t = nullptr;
static Trampoline* WriteAdventureData_t = nullptr;

bool checkIfFileExists(const char* filename)
{
	FILE* file;
	errno_t err;

	if ((err = fopen_s(&file, filename, "r")) != 0) return false;
	else 
	{
		fclose(file);
		return true;
	}
}

string GetSavePath(int slot) 
{
    return modpath + "\\SAVEDATA\\FullStorySave" + to_string(slot) + ".json";
}

void WriteFile(const json& j) 
{
    std::ofstream file(GetSavePath(CurrentSaveSlot));
    if (file.is_open()) 
	{
        file << std::setw(4) << j;
        file.close();
    }
}

void SetStageIndex()
{
    stage.clear();
    for (int i = 0; i < stages.size(); i++)
    {
        stages[i].id = i;
        stage[stages[i].name] = i;
    }
}

void RemoveStages(const std::vector<int>& settingStages)
{
    stages.erase
    (
        std::remove_if(stages.begin(), stages.end(), [&settingStages](const Stage& stg) 
        {
            return std::find(settingStages.begin(), settingStages.end(), stg.id) != settingStages.end();
        }), 
        stages.end()
    );
}

bool MoveStagesToIndex(const std::vector<int>& settingStages, size_t index)
{
    if (settingStages.empty()) return true;

    if (index >= stages.size())
    {
        PrintDebug("[Full Story] MoveStagesToIndex: Destination index out of bounds.\n");
        return false;
    }

    size_t currentIndex = index;

    for (int stageID : settingStages)
    {
        auto it = std::find_if(stages.begin(), stages.end(), [stageID](const Stage& stage) {
            return stage.id == stageID;
        });

        if (it == stages.end()) continue;

        size_t sourceIndex = std::distance(stages.begin(), it);

        if (sourceIndex == currentIndex)
        {
            currentIndex++;
            continue;
        }

        if (sourceIndex < currentIndex)
        {
            std::rotate(stages.begin() + sourceIndex, stages.begin() + sourceIndex + 1, stages.begin() + currentIndex + 1);
        }
        else
        {
            std::rotate(stages.begin() + currentIndex, stages.begin() + sourceIndex, stages.begin() + sourceIndex + 1);
            currentIndex++;
        }
    }

    return true;
}

void ApplySettings()
{
	if (settings.eggHornetChar == Char_Tails)
	{
		stages[stage["Sonic_ToEggHornet"]].character = Characters_Tails;
		stages[stage["Event_SonicAndTailsMeetEggman"]].character = Characters_Tails;
		stages[stage["Event_SonicAndTailsMeetEggman"]].cutsceneID = scene["Scene_TailsAndEggman_Meet"];
		stages[stage["Boss_EggHornet"]].character = Characters_Tails;
	}

	if (settings.chaos4Char == Char_Tails)
	{		
		stages[stage["Event_Chaos4_Emerges"]].character = Characters_Tails;
		stages[stage["Event_Chaos4_Emerges"]].cutsceneID = scene["Scene_Tails_Chaos4Emerges"];
		stages[stage["Boss_Chaos4"]].character = Characters_Tails;
	}
	else if (settings.chaos4Char == Char_Knuckles)
	{
		stages[stage["Event_Chaos4_Emerges"]].character = Characters_Knuckles;
		stages[stage["Event_Chaos4_Emerges"]].cutsceneID = scene["Scene_Knuck_Chaos4Battle"];
		stages[stage["Boss_Chaos4"]].character = Characters_Knuckles;
	}

	if (settings.sonicVSGammaChar == GammaChar_Gamma)
	{
		stages[stage["Event_Sonic_vs_Gamma_Aftermath"]].character = Characters_Gamma;
		stages[stage["Event_Sonic_vs_Gamma_Aftermath"]].cutsceneID = scene["Scene_Gamma_AfterSonicBattle"];
	}

	if (settings.victoryChar == Char_Tails)
	{
		stages[stage["Event_Sonic_Outro"]].character = Characters_Tails;
		stages[stage["Event_Sonic_Outro"]].cutsceneID = scene["Scene_Tails_Outro"];
	}

	if (settings.fieldsDisabled)
	{
		stages[stage["Event_SonicAndTailsMeetEggman"]].displayCard = true;
		stages[stage["Event_Knuck_vs_Sonic"]].displayCard = true;
		stages[stage["Event_Amy_KidnappedByZero"]].displayCard = true;
		stages[stage["Event_Amy_DiscoveringTheEggBase"]].displayCard = true;
	}

	if (!settings.skipBigGameplay)
	{
		stages[stage["Gamma_ToEmeraldCoast"]].displayCard = true;
		stages[stage["Event_Knuck_EggCarrierSensingTheEmerald"]].displayCard = false;		
	}

	std::vector<int> stagesFromSettings;

    auto appendStagesByID = [&](const std::vector<std::string>& stages) 
    {
        for (const std::string& name : stages)
        {
            int stageIndex = GetStageIndex(name);
            if (stageIndex >= 0) stagesFromSettings.push_back(stageIndex);
        }
    };

    if (settings.sonicTailsChar == Char_Sonic) appendStagesByID(settingStages.tailsStages);
    if (settings.sonicTailsChar == Char_Tails) appendStagesByID(settingStages.sonicStages);
    if (settings.skipBigGameplay)              appendStagesByID(settingStages.bigStages);
    if (!settings.unusedCutsceneEnabled)       appendStagesByID(settingStages.gammaUnusedCutscene);
    if (settings.skipTikalFlashbacks)          appendStagesByID(settingStages.tikalFlashbacks);
    if (settings.fieldsDisabled)               appendStagesByID(settingStages.fieldStages);

    RemoveStages(stagesFromSettings);
	SetStageIndex();

	stagesFromSettings.clear();
    if (settings.earlyGammaEnabled) appendStagesByID(settingStages.gammaIntroStages);

    MoveStagesToIndex(stagesFromSettings, 0);
	SetStageIndex();

    PrintDebug("[Full Story] Settings applied.\n");
}

void ApplyVisualSettings()
{
	INIReader reader(modpath + "\\config.ini");

	if (reader.ParseError() < 0) return;

	settings.dynamicStagesEnabled = reader.GetBoolean("Visuals", "DynamicStagesEnabled", true);
	settings.titleLogoEnabled = reader.GetBoolean("Visuals", "TitleLogoEnabled", true);
	settings.pauseInfoEnabled = reader.GetBoolean("Visuals", "PauseInfoEnabled", true);
}

void CreateSave()
{
	string savePath = GetSavePath(CurrentSaveSlot);

	json j;	

	INIReader reader(modpath + "\\config.ini");

	if (reader.ParseError() < 0) 
	{
		PrintDebug("[Full Story] Could not load 'config.ini', setting default settings\n");
	}
	else
	{
		PrintDebug("[Full Story] Reading settings\n");

		settings.sonicTailsChar = reader.GetInteger("Characters", "STLevelsCharacter", Char_SonicTails);
		settings.eggHornetChar = reader.GetInteger("Characters", "EggHornetCharacter", Char_Sonic);
		settings.chaos4Char = reader.GetInteger("Characters", "Chaos4Character", Char_Sonic);	

		
		settings.sonicVSGammaChar = reader.GetInteger("Cutscenes", "SonicvsGammaCharacter", GammaChar_SonicAmy);
		settings.victoryChar = reader.GetInteger("Cutscenes", "VictoryCharacter", Char_Sonic);
		settings.creditsChar = reader.GetInteger("Cutscenes", "CreditsCharacter", CreditsChar_Final);
		settings.unusedCutsceneEnabled = reader.GetBoolean("Cutscenes", "UnusedCutsceneEnabled", false);

		settings.skipBigGameplay = reader.GetBoolean("Gameplay", "BigGameplayDisabled", false);
		settings.earlyGammaEnabled = reader.GetBoolean("Gameplay", "EarlyGammaEnabled", false);	
		settings.skipTikalFlashbacks = reader.GetBoolean("Gameplay", "TikalFlashbacksDisabled", false);
		settings.fieldsDisabled = reader.GetBoolean("Gameplay", "FieldsDisabled", false);
	}

	j["stage"] = session.currentStage;
	j["story"] = session.storyStatus;
	j["saveFile"] = CurrentSaveSlot;

	j["STLevelsCharacter"] = settings.sonicTailsChar;
	j["EggHornetCharacter"] = settings.eggHornetChar;
	j["Chaos4Character"] = settings.chaos4Char;

	j["SonicvsGammaCharacter"] = settings.sonicVSGammaChar;
	j["VictoryCharacter"] = settings.victoryChar;
	j["CreditsCharacter"] = settings.creditsChar;
	j["UnusedCutsceneEnabled"] = (int)settings.unusedCutsceneEnabled;

	j["BigGameplayDisabled"] = (int)settings.skipBigGameplay;			
	j["EarlyGammaEnabled"] = (int)settings.earlyGammaEnabled;
	j["TikalFlashbacksDisabled"] = (int)settings.skipTikalFlashbacks;
	j["FieldsDisabled"] = (int)settings.fieldsDisabled;

	j["jetAnklet"] = (int)playerUpgrades.jetAnklet;
	j["lightSpeedShoes"] = (int)playerUpgrades.lightSpeedShoes;
	j["crystalRing"] = (int)playerUpgrades.crystalRing;

	WriteFile(j);

	ApplySettings();

	return;
}

void SaveProgression()
{
	// Prevents the game from saving while in Twinkle Circuit
	if (session.currentStage == stage["StationSquare_TwinkleCircuit"] && session.isInsideAdventure) return;

	string savePath = GetSavePath(CurrentSaveSlot);

	json j;

	std::ifstream saveInfo(savePath);

	if (!saveInfo.is_open())
	{
		PrintDebug("[Full Story] Could not open file for saving.");
		return;
	}

	saveInfo >> j;
	saveInfo.close();

	j["stage"] = session.currentStage;
	j["story"] = session.storyStatus;
	j["jetAnklet"] = (int)EventFlagArray[EventFlags_Tails_JetAnklet];
	j["lightSpeedShoes"] = (int)EventFlagArray[EventFlags_Sonic_LightShoes];
	j["crystalRing"] = (int)EventFlagArray[EventFlags_Sonic_CrystalRing];

	WriteFile(j);

	PrintDebug("[Full Story] Successfully saved progression - Stage %d out of %d (%d%% complete)\n", 
		session.currentStage + 2, stages.size() + 1, ((session.currentStage + 2) * 100 / (stages.size() + 1)));

	return;
}

void LoadProgression()
{
	if (GameState != GameModes_StartCredits && GameMode != GameModes_Menu || !FileSelTp) return;

	string savePath = GetSavePath(CurrentSaveSlot);

	json j;

	if (!checkIfFileExists(savePath.c_str()))
	{
		PrintDebug("[Full Story] Creating a new save file...\n");
		session.currentStage = Story_NotStarted;
		session.storyStatus = Story_Started;
		CreateSave();
		return;
	}

	std::ifstream file(savePath);
	file >> j;
	file.close();

	session.currentStage = (int)j["stage"];
	session.storyStatus = (int)j["story"];

	settings.sonicTailsChar = (int)j["STLevelsCharacter"];
	settings.eggHornetChar = (int)j["EggHornetCharacter"];
	settings.chaos4Char = (int)j["Chaos4Character"];

	if (j.contains("SonicvsGammaCharacter")) settings.sonicVSGammaChar = (int)j["SonicvsGammaCharacter"];
	if (j.contains("VictoryCharacter")) settings.victoryChar = (int)j["VictoryCharacter"];
	if (j.contains("CreditsCharacter")) settings.creditsChar = (int)j["CreditsCharacter"];
	settings.unusedCutsceneEnabled = (int)j["UnusedCutsceneEnabled"];

	if (j.contains("BigGameplayDisabled")) settings.skipBigGameplay = (int)j["BigGameplayDisabled"];		
	if (j.contains("EarlyGammaEnabled")) settings.earlyGammaEnabled = (int)j["EarlyGammaEnabled"];
	if (j.contains("TikalFlashbacksDisabled")) settings.skipTikalFlashbacks = (int)j["TikalFlashbacksDisabled"];
	if (j.contains("FieldsDisabled")) settings.fieldsDisabled = (int)j["FieldsDisabled"];
	

	playerUpgrades.jetAnklet = (int)j["jetAnklet"];
	playerUpgrades.lightSpeedShoes = (int)j["lightSpeedShoes"];
	playerUpgrades.crystalRing = (int)j["crystalRing"];

	if (session.storyStatus == Story_Completed)
	{
		PrintDebug("[Full Story] Story Complete\n");
	}
	else
	{
		PrintDebug("[Full Story] Successfully loaded save slot %d on Stage %d\n", CurrentSaveSlot, session.currentStage + 2);
	}

	ApplySettings();

	return;
}

void LoadSave_r() 
{
	j_LoadSave();
	LoadProgression();
}

void DeleteProgression() 
{
	if (GameState != GameModes_StartCredits && GameMode != GameModes_Menu)
		return;

	const char* deleteMSG = "[Full Story] Deleted Full Story progression on save: %d \n";

	int slotNumber = CurrentSaveSlot;
	string savePath = GetSavePath(slotNumber);

	if (checkIfFileExists(savePath.c_str()))
	{
		if (DeleteFileA(savePath.c_str()))
		{
			PrintDebug(deleteMSG, CurrentSaveSlot);
		}
	}
	
	session.currentSave = -1;

	return;
}

void DeleteSave_r()
{
	DeleteProgression();
	auto original = reinterpret_cast<decltype(DeleteSave_r)*>(DeleteSave_t->Target());
	original();
}

void __fastcall WriteAdventureDataToSaveFile_r(SaveFileData* data, void* edx)
{
    auto original = reinterpret_cast<void(__thiscall*)(SaveFileData*)>(WriteAdventureData_t->Target());
    original(data);

	if (session.isInsideAdventure && session.storyStatus < Story_Completed)
    {
        data->LastCharacter = Characters_Sonic; // Fixes the "Hedgehog Hammer" text

        if (data->LastLevel == LevelIDs_EggCarrierInside)
        {
            data->LastLevel = LevelIDs_EggCarrierOutside; 
        }
    }
}

void Init_Progression()
{
	DeleteSave_t = new Trampoline((int)DeleteSave, (int)DeleteSave + 0x6, DeleteSave_r);
	WriteAdventureData_t = new Trampoline((int)WriteAdventureDataToSaveFile, (int)WriteAdventureDataToSaveFile + 0x5, (void*)WriteAdventureDataToSaveFile_r);
}

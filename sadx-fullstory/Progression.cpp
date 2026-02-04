#include "pch.h"

using json = nlohmann::json;
using namespace std;

Trampoline* DeleteSave_t;

void ReadConfig(bool isInsideGame)
{
	string savePath = modpath + "\\SAVEDATA\\";
	string saveNumber = to_string(CurrentSaveSlot);
	string saveFullPath = savePath + "FullStorySave" + saveNumber + ".json";

	json j;	

	INIReader reader(modpath + "\\config.ini");

	if (reader.ParseError() < 0) 
	{
		PrintDebug("\n[Full Story] Could not load 'config.ini', setting default settings\n");
	}
	else if (isInsideGame)
	{
		PrintDebug("[Full Story] Reading settings\n");

		STLevelsCharacter = reader.GetInteger("Gameplay", "STLevelsCharacter", LevelsChars_SonicTails);
		EggHornetCharacter = reader.GetInteger("Gameplay", "EggHornetCharacter", LevelsChars_Sonic);
		Chaos4Character = reader.GetInteger("Gameplay", "Chaos4Character", Chaos4Chars_Sonic);	

		BigGameplayEnabled = reader.GetBoolean("Gameplay", "BigGameplayEnabled", true);
		UnusedCutsceneEnabled = reader.GetBoolean("Gameplay", "UnusedCutsceneEnabled", false);
	}
	else
	{
		PrintDebug("\n[Full Story] Reading logo setting\n");
		TitleLogoEnabled = reader.GetBoolean("Misc", "TitleLogoEnabled", true);
	}

	if (isInsideGame)
	{
		j["stage"] = currentStage;
		j["story"] = storyComplete;
		j["saveFile"] = CurrentSaveSlot;

		j["STLevelsCharacter"] = STLevelsCharacter;
		j["EggHornetCharacter"] = EggHornetCharacter;
		j["Chaos4Character"] = Chaos4Character;

		j["BigGameplayEnabled"] = (int)BigGameplayEnabled;		
		j["UnusedCutsceneEnabled"] = (int)UnusedCutsceneEnabled;

		j["jetAnklet"] = (int)jetAnklet;
		j["lightSpeedShoes"] = (int)lightSpeedShoes;
		j["crystalRing"] = (int)crystalRing;


		std::ofstream file(saveFullPath);
		file << std::setw(4) << j;
		file.close();
	}

	return;
}

void SaveProgression()
{
	const char* saveOK = "[Full Story] Successfully saved progression - Stage %d (%d%% complete)\n";

	string savePath = modpath + "\\SAVEDATA\\";
	string saveNumber = to_string(CurrentSaveSlot);
	string saveFullPath = savePath + "FullStorySave" + saveNumber + ".json";

	json j;

	std::ifstream saveInfo(saveFullPath);

	if (!saveInfo.is_open())
	{
		PrintDebug("[Full Story] Could not open file for reading.");
		return;
	}

	saveInfo >> j; // Parse the JSON data directly from the stream
	saveInfo.close();

	j["stage"] = currentStage;
	j["story"] = storyComplete;
	j["jetAnklet"] = (int)EventFlagArray[EventFlags_Tails_JetAnklet];
	j["lightSpeedShoes"] = (int)EventFlagArray[EventFlags_Sonic_LightShoes];
	j["crystalRing"] = (int)EventFlagArray[EventFlags_Sonic_CrystalRing];

	std::ofstream file(saveFullPath);
	file << std::setw(4) << j;
	file.close();


	PrintDebug(saveOK, currentStage + 2, ((currentStage + 1) * 100 / TOTAL_STAGES));
		

	return;
}

void LoadProgression()
{
	if (GameState != 21 && GameMode != 12 || !FileSelTp)
		return;

	const char* loadOK = "[Full Story] Successfully loaded save on Stage %d\n";
	string savePath = modpath + "\\SAVEDATA\\";


	string saveNumber = to_string(CurrentSaveSlot);
	string saveFullPath = savePath + "FullStorySave" + saveNumber + ".json";

	json j;

	if (checkIfFileExists(saveFullPath.c_str()))
	{
		std::ifstream file(saveFullPath);
		file >> j;
		file.close();

		currentStage = (int)j["stage"];
		storyComplete = (int)j["story"];
		CurrentSaveSlot = (int)j["saveFile"];

		STLevelsCharacter = (int)j["STLevelsCharacter"];
		EggHornetCharacter = (int)j["EggHornetCharacter"];
		Chaos4Character = (int)j["Chaos4Character"];

		BigGameplayEnabled = (int)j["BigGameplayEnabled"];
		UnusedCutsceneEnabled = (int)j["UnusedCutsceneEnabled"];

		jetAnklet = (int)j["jetAnklet"];
		lightSpeedShoes = (int)j["lightSpeedShoes"];
		crystalRing = (int)j["crystalRing"];
		PrintDebug(loadOK, currentStage + 2);

		if (storyComplete)
		{
			PrintDebug("[Full Story] Story Complete\n");
		}
	}
	else
	{
		currentStage = -1;
		storyComplete = -1;
	}

	return;
}

void LoadSave_r() 
{
	j_LoadSave();
	LoadProgression();
}

void DeleteProgression() 
{

	if (GameState != 21 && GameMode != 12)
		return;

	const char* deleteMSG = "[Full Story] Deleted Full Story progression on save: %d \n";
	string savePath = modpath + "\\SAVEDATA\\";

	string saveNumber = to_string(CurrentSaveSlot);
	string saveFileFullPath = savePath + "FullStorySave" + saveNumber + ".json";
	LPCSTR delSave = saveFileFullPath.c_str();

	if (checkIfFileExists(saveFileFullPath.c_str()))
	{
		if (DeleteFileA(delSave))
		{
			PrintDebug(deleteMSG, CurrentSaveSlot);
		}
	}
	return;
}

void DeleteSave_r()
{
	DeleteProgression();
	auto original = reinterpret_cast<decltype(DeleteSave_r)*>(DeleteSave_t->Target());
	original();
}

void Init_Progression()
{
	WriteCall((void*)0x4db0b3, SaveProgression);

	WriteCall((void*)0x503782, LoadSave_r);
	WriteCall((void*)0x5037fc, LoadSave_r);
	WriteJump((void*)0x5053DD, LoadSave_r);

	DeleteSave_t = new Trampoline((int)DeleteSave, (int)DeleteSave + 0x6, DeleteSave_r);
}

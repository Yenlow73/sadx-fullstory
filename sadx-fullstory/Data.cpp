#include "pch.h"
#include <map>
#include <fstream>

using json = nlohmann::json;
using namespace std;

SessionState session;
ModSettings settings;
LanternAPI lanternAPI;
PlayerUpgrades playerUpgrades;
ModsEnabled modsEnabled;
SettingStages settingStages;

unordered_map<string, int> level;
unordered_map<string, int> act;
unordered_map<string, int> character;
unordered_map<string, int> timeofDay;
unordered_map<string, int> flag;
unordered_map<string, int> stage;
unordered_map<string, int> scene;

vector<Stage> stages;
vector<FieldStage> fieldStages;

const unordered_map<int, unsigned int> timeColors = 
{
    {0, 0xFFFFFFAA}, // Morning
    {1, 0xFF00FFFF}, // Day
    {2, 0xFFFF8000}, // Evening
    {3, 0xFF8080FF}  // Night
};

const unordered_map<int, unsigned int> characterColors = 
{
    {Characters_Sonic,    0xFF82B1FF},
    {Characters_Tails,    0xFFFFF59D},
    {Characters_Knuckles, 0xFFFF8A80},
    {Characters_Amy,      0xFFF48FB1},
    {Characters_Gamma,    0xFFCFD8DC},
    {Characters_Big,      0xFFCE93D8}
};

const char* const dayTimes[6][4] = 
{
    { "Asa", "Hiru", "Yugaata", "Yoru" },
	{ "Morning", "Day", "Evening", "Night" },
	{ "Matin", "Jour", "Soir", "Nuit" },
	{ "Manana", "Dia", "Tarde", "Noche" },
	{ "Morgen", "Tag", "Abend", "Nacht" },
	{ "Manha", "Dia", "Tarde", "Noite" }
};

vector<LanternFunction> lanternFunctions = 
{
    { (void**)&lanternAPI.set_shader_flags, "set_shader_flags" },
    { (void**)&lanternAPI.palette_from_rgb, "palette_from_rgb" },
    { (void**)&lanternAPI.set_diffuse_blend_factor, "set_diffuse_blend_factor" },
    { (void**)&lanternAPI.set_diffuse_blend, "set_diffuse_blend" }
 };

const unordered_map<string, void(__cdecl*)(int)> sceneFunctions = 
{
    {"Scene_SonicAndTails_Meet_Chaos1", ev0008_s_chaos1},
    {"Scene_TailsAndSonic_Poolside", ev0032_t_meetingsonic},
    {"Scene_Big_SearchingForFroggy", ev00D1_b_stationsquare},
    {"Scene_Tails_Chaos4Emerges", ev0039_t_beforechaos4},
    {"Scene_Gamma_GoesToPast", ev00B8_e_emeraldcoast},
    {"Scene_Knuck_EggCarrierSensingTheEmerald", ev0122_k_outsideskydeck},
    {"Scene_Sonic_vs_Gamma", ev001A_s_eggmantakesbirdie},
    {"Scene_Amy_LeavesWithTails", ev006A_a_escapecarrier},
    {"Scene_Knuck_Chaos6Battle", ev0099_k_beforechaos6},
    {"Scene_Tails_EggmanLaunchesMissile", ev004D_t_missile},
    {"Scene_Final_KnucklesAtTheMasterEmerald", ev00F3_l_knuckles},
    {"Scene_Final_SonicWakesUp", ev00F9_l_snoozecruise}
};

void LoadMapList(const json& item, const string& key, vector<int>& targetVector, const unordered_map<string, int>& map)
{
    if (!item.contains(key) || !item[key].is_array()) return;

    for (const auto& entry : item[key])
    {
        string name = entry.get<string>();
        auto it = map.find(name);

        if (it != map.end()) 
        {
            targetVector.push_back(it->second);
        }
    }
}

optional<json> LoadJSONFile(const string fileName) 
{
    string fullPath = modpath + "\\data\\" + fileName;
    ifstream file(fullPath);

    if (!file.is_open()) 
    {
        PrintDebug("[Full Story] Error: Could not open %s\n", fullPath.c_str());
        return nullopt;
    }

    json data;

    try 
    {
        file >> data;
        return data;
    }
    catch (json::parse_error& e) 
    {
        PrintDebug("[Full Story] JSON Parse Error in %s: %s\n", fileName.c_str(), e.what());
        return nullopt;
    }
}

int LoadMap(const json& section, unordered_map<string, int>& targetMap)
{
    targetMap.clear();

    for (auto& [key, value] : section.items())
    {
        targetMap[key] = value.get<int>();
    }

    return targetMap.size();
}

void LoadEnums() 
{
    auto data = LoadJSONFile("enums.json");
    if (!data) return;

    int enumsCount = 0;

    enumsCount += LoadMap((*data)["scenes"], scene);
    enumsCount += LoadMap((*data)["flags"], flag);
    enumsCount += LoadMap((*data)["levels"], level);
    enumsCount += LoadMap((*data)["acts"], act);
    enumsCount += LoadMap((*data)["characters"], character);
    enumsCount += LoadMap((*data)["times of day"], timeofDay);


    PrintDebug("[Full Story] Successfully loaded %d enums.\n", enumsCount);
}

void LoadStages() 
{
    auto data = LoadJSONFile("stages.json");
    if (!data) return;

    auto objectiveData = LoadJSONFile("objectives.json");

    stages.clear();

    int index = 0;

    for (auto& item : *data) 
	{
        Stage newStage;

        newStage.name = item.value("name", "Unknown_Stage");
        newStage.id = index;
        stage[newStage.name] = index;

		newStage.character = item.contains("character") ? (int8_t)character[item["character"]] : Characters_Sonic;
		newStage.level = item.contains("level") ? level[item["level"]] : 0;
        newStage.act = item.contains("act") ? act[item["act"]] : 0;
		newStage.timeofDay = item.contains("timeofDay") ? timeofDay[item.value("timeofDay", "Day")] : TimesOfDay_Day;    
		newStage.cutsceneID = item.contains("cutscene") ? scene[item["cutscene"]] : -1;
      
        newStage.controlAfterCutscene = item.value("controlAfterCutscene", false);
        newStage.displayCard = item.value("displayCard", false);

        if (objectiveData && objectiveData->contains(newStage.name))
		{
            auto& objectives = (*objectiveData)[newStage.name];

            const char* languageKeys[6] = { "jp", "en", "fr", "es", "de", "pt" };

            for (int i = 0; i < 6; ++i)
            {
                newStage.objective[i] = objectives.value(languageKeys[i], ""); 
            }   
        }

        LoadMapList(item, "eventTrue", newStage.eventTrue, flag);
        LoadMapList(item, "eventFalse", newStage.eventFalse, flag);
        LoadMapList(item, "cutsceneTrue", newStage.cutsceneTrue, scene);
        LoadMapList(item, "cutsceneFalse", newStage.cutsceneFalse, scene);
        
        if (item.contains("sceneTrigger")) 
		{
            auto& sceneTrigger = item["sceneTrigger"];
            SceneTrigger newTrigger;

            newTrigger.position.x = sceneTrigger["position"].value("x", 0);
            newTrigger.position.y = sceneTrigger["position"].value("y", 0);
            newTrigger.position.z = sceneTrigger["position"].value("z", 0);
            newTrigger.radius = sceneTrigger.value("radius", 120);

            newStage.sceneTrigger = newTrigger;
        }
        
        if (item.contains("conditionTrigger")) 
		{
            auto& conditionTrigger = item["conditionTrigger"];
            ConditionTrigger newTrigger;

            newTrigger.act = conditionTrigger.contains("act") ? act[conditionTrigger["act"]] : -1;
            newTrigger.flag = conditionTrigger.contains("flag") ? flag[conditionTrigger["flag"]] : -1;

            newStage.conditionTrigger = newTrigger;
        }
        
        if (item.contains("startPosition")) 
		{
            auto& startPosition = item["startPosition"];
            CharStartPosition newPosition;

            newPosition.position.x = startPosition["position"].value("x", 0);
            newPosition.position.y = startPosition["position"].value("y", 0);
            newPosition.position.z = startPosition["position"].value("z", 0);

            newPosition.rotationY = startPosition.value("rotation", 0);

            newStage.startPosition = newPosition;
        }
        

        if (item.contains("stagePreset"))
        {
            auto& stagePreset = item["stagePreset"];
            StagePreset newPreset;

            if (stagePreset.contains("diffuse")) 
            {
                newPreset.diffuse.red = stagePreset["diffuse"].value("red", 0);
                newPreset.diffuse.green = stagePreset["diffuse"].value("green", 0);
                newPreset.diffuse.blue = stagePreset["diffuse"].value("blue", 0);
            }

            if (stagePreset.contains("textures"))
            {
                for (auto& entry : stagePreset["textures"])
                {
                    TextureSwap textureSwap;

                    textureSwap.source = entry.value("source", "");
                    textureSwap.destination = entry.value("destination", "");

                    newPreset.textures.push_back(textureSwap);
                }
            }

            newStage.stagePreset = newPreset;
        }

        stages.push_back(newStage);
        index++;
    }

    PrintDebug("[Full Story] Successfully loaded %d stages.\n", stages.size());
}

void LoadFieldStages() 
{
    auto data = LoadJSONFile("fieldStages.json");
    if (!data) return;

    fieldStages.clear();

    for (auto& item : *data) 
	{
        FieldStage newFieldStage;

		newFieldStage.field = level[item["field"]];
        newFieldStage.level = level[item["level"]];

        if (item.contains("position"))
		{
            newFieldStage.position.x = item["position"].value("x", 0);
            newFieldStage.position.y = item["position"].value("y", 0);
            newFieldStage.position.z = item["position"].value("z", 0);
        }
        
        newFieldStage.radius = item.value("radius", 240.0f);

        if (item.contains("excludedStages") && item["excludedStages"].is_array())
        {
            for (const auto& stageName : item["excludedStages"])
            {
                if (stageName.is_string())
                {
                    newFieldStage.excludedStages.push_back(stageName.get<std::string>());
                }
            }
        }

        if (item.contains("acts") && item["acts"].is_object())
        {
            for (auto& [charName, actNameElement] : item["acts"].items())
            {
                if (actNameElement.is_string())
                {
                    std::string actName = actNameElement.get<std::string>();

                    if (character.count(charName) && act.count(actName))
                    {
                        int charID = character[charName];
                        int actID = act[actName];
                        
                        newFieldStage.characterActs[charID] = actID;
                    }
                }
            }
        }

        LoadMapList(item, "eventTrue", newFieldStage.eventTrue, flag);
        LoadMapList(item, "eventFalse", newFieldStage.eventFalse, flag);

        fieldStages.push_back(newFieldStage);
    }

    PrintDebug("[Full Story] Successfully loaded %d global field stages.\n", fieldStages.size());
}

void LoadSettingStages()
{
    auto data = LoadJSONFile("settingStages.json");

    if (!data) 
    {
        PrintDebug("[Full Story] Could not read settings.json\n");
        return;
    }

    auto loadJSONArray = [&](const std::string& key, std::vector<std::string>& targetVector) {
        targetVector.clear(); 
        if (data->contains(key) && (*data)[key].is_array()) 
        {
            for (const auto& element : (*data)[key]) 
            {
                if (element.is_string()) 
                {
                    targetVector.push_back(element.get<std::string>());
                }
            }
        }
    };

    loadJSONArray("sonicStages",         settingStages.sonicStages);
    loadJSONArray("tailsStages",         settingStages.tailsStages);
    loadJSONArray("bigStages",           settingStages.bigStages);
    loadJSONArray("gammaUnusedCutscene", settingStages.gammaUnusedCutscene);
    loadJSONArray("tikalFlashbacks",     settingStages.tikalFlashbacks);
    loadJSONArray("gammaIntroStages",    settingStages.gammaIntroStages);
    loadJSONArray("fieldStages",         settingStages.fieldStages);

    PrintDebug("[Full Story] Successfully loaded data from settings.json.\n");
}
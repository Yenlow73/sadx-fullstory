#include "pch.h"

std::string modpath;

void CheckMods()
{
	modsEnabled.aventuraDeSonic = GetModuleHandle(L"ads1.dll") != NULL || GetModuleHandle(L"ptbr21.dll") != NULL;
	modsEnabled.dreamcastConversion = GetModuleHandle(L"DCMods_Main.dll") != NULL;
	modsEnabled.betterTailsAI = GetModuleHandle(L"SADX-Better-Tails-AI.dll") != NULL;

	HMODULE lanternModule = GetModuleHandle(L"sadx-dc-lighting.dll");
		
	if (lanternModule == nullptr) return;
	
	for (const auto& lanternFunction : lanternFunctions) 
	{
        *lanternFunction.target = GetProcAddress(lanternModule, lanternFunction.name);
    }

	modsEnabled.lanternEngine = true;
}

void SetLogo(const HelperFunctions& helper)
{
	if (!settings.titleLogoEnabled) return;

	if (modsEnabled.dreamcastConversion)
	{
		helper.ReplaceFile("system\\AVA_GTITLE0_DC_HD.PVM", "system\\AVA_GTITLE0_DC_HD.PVMX");
	}
	else
	{
		helper.ReplaceFile("system\\AVA_GTITLE0_E.PVM", "system\\textures\\AVA_GTITLE0_E.PVM");
	}
}

void SetCustomCutscenes()
{
	for (auto const& [name, func] : sceneFunctions)
    {
        CutsceneDataList[scene[name]]->Function = func;
    }

	CutsceneDataList[scene["Scene_Final_KnucklesAtTheMasterEmerald"]]->Textures = texTbl_ev00F3;
	CutsceneDataList[scene["Scene_Tails_EggmanLaunchesMissile"]]->Textures = texTbl_ev004D;
}

extern "C" 
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		modpath = path;

		ApplyVisualSettings();
		CheckMods();
		SetLogo(helperFunctions);

		LoadEnums();
		LoadFieldStages();
		LoadSettingStages();
		SetCustomCutscenes();

		Init_Progression();
		Init_Stages();
		Init_StageOnFrames();
	}
	
	__declspec(dllexport) void __cdecl OnFrame(const HelperFunctions& helperFunctions)
	{
		SetStageOnFrames();
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}
#include "pch.h"

std::string modpath;

bool dreamcastModLoaded = false;

extern "C" {

	__declspec( dllexport ) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		modpath = path;

		dreamcastModLoaded = GetModuleHandle(L"DCMods_Main.dll") != NULL;

		ReadConfig(false);

		if (TitleLogoEnabled)
		{
			if (dreamcastModLoaded)
			{
				helperFunctions.ReplaceFile("system\\AVA_GTITLE0_DC_HD.PVM", "system\\textures\\AVA_GTITLE0_DC_HD.PVMX");
			}
			else
			{
				helperFunctions.ReplaceFile("system\\AVA_GTITLE0_E.PVM", "system\\textures\\AVA_GTITLE0_E.PVM");
			}		
		}

		// Load Modified Cutscenes
		CutsceneDataList[0x004D]->Function = ev004D_t_missile;
		CutsceneDataList[0x004D]->Textures = texTbl_ev004D;
		CutsceneDataList[0x00F9]->Function = ev00F9_l_snoozecruise;

		Init_Progression();
		Init_Stages();
	}
	
	__declspec(dllexport) void __cdecl OnFrame()
	{
		SetStageOnFrames();
		CheckCompletion();

		if (GameState == 16)
			PauseMenuFix();
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}
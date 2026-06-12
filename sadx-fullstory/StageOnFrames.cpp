#include "pch.h"

#define GAMESTATE_PAUSE 16
#define COLOR_WHITE 0xFFFFFFFF
#define MR_TRAIN_VOICELINE 1657

static Trampoline* LoadPVM_t = nullptr;
static Trampoline* PlayVoice_t = nullptr;

const uint32_t LANTERNFLAGS = LFLAG_BLEND | LFLAG_FOG | LFLAG_RANGE_FOG | LFLAG_PALETTE_FOG;

float fogTable[1024];

void GoNext()
{
	GameState = 17;
	GameStateHandler_Adventure();
}

void AdventureToMenu(bool direction)
{
	if (direction)
	{
		session.gameMode = GameMode;		
		GameMode = GameModes_Adventure_Field;
	}
	else GameMode = (GameModes)session.gameMode;

	session.quitSelected = direction;
	session.displayCardAfterLoad = direction;
	session.isInsideAdventure = !direction;
}

bool IsPointInsideSphere(NJS_VECTOR* center, NJS_VECTOR* pos, float radius) 
{
	float dx = center->x - pos->x;
    float dy = center->y - pos->y;
    float dz = center->z - pos->z;

    float distanceSquared = (dx * dx) + (dy * dy) + (dz * dz);
	float radiusSquared = radius * radius;

	return distanceSquared <= radiusSquared;
}

unsigned int SetColor(int index, bool time) 
{
    const auto& colorMap = time ? timeColors : characterColors;

    auto it = colorMap.find(index);

    return (it != colorMap.end()) ? it->second : COLOR_WHITE;
}

void FadeScreen(ObjectMaster* obj)
{
    EntityData1* data = obj->Data1;

    const int colorBlack = 0x00000000;
    ScreenFade_Color = *(NJS_COLOR*)&colorBlack;

    int maxTime = DefaultMax;
    int peakTime = DefaultPeak;
    
    if (session.fadeMode == Fade_OutIn) 
	{
        maxTime = OutInMax;
        peakTime = OutInPeak;
    } 
	else if (session.fadeMode == Fade_In) 
	{
        maxTime = InMax;
        peakTime = InPeak; 
    }

	int step = (int)AlphaStep;

    if (++data->InvulnerableTime >= maxTime)
    {
        CheckThingButThenDeleteObject(obj);
    }
	else
	{
		switch (session.fadeMode)
		{
		case Fade_OutIn:
			if (data->InvulnerableTime < peakTime) data->CharID += step;
			else data->CharID -= step;
			break;
		case Fade_In:
			if (data->InvulnerableTime < peakTime) data->CharID = -step;		
			else data->CharID -= step;
			break;
		case Fade_Out:
			if (data->InvulnerableTime < peakTime) data->CharID += step;
			else data->CharID = -step;	
			break;
		}

		ScreenFade_Color.argb.a = data->CharID;
		ScreenFade_DrawColor();
	}
}

std::string StripAccents(const std::string& input)
{
    static const std::vector<std::pair<std::string, std::string>> utf8Map =
	{
        {"\xC3\xA1", "a"}, {"\xC3\xA0", "a"}, {"\xC3\xA2", "a"}, {"\xC3\xA3", "a"}, // á, à, â, ã
        {"\xC3\x81", "A"}, {"\xC3\x80", "A"}, {"\xC3\x82", "A"}, {"\xC3\x83", "A"}, // Á, À, Â, Ã
        {"\xC3\xA9", "e"}, {"\xC3\xAA", "e"}, {"\xC3\x89", "E"}, {"\xC3\x8A", "E"}, // é, ê, É, Ê
        {"\xC3\xAD", "i"}, {"\xC3\x8D", "I"}, {"\xC3\xB3", "o"}, {"\xC3\xB4", "o"}, // í, Í, ó, ô
        {"\xC3\xB5", "o"}, {"\xC3\x93", "O"}, {"\xC3\x94", "O"}, {"\xC3\x95", "O"}, // õ, Ó, Ô, Õ
        {"\xC3\xBA", "u"}, {"\xC3\xBC", "u"}, {"\xC3\x9A", "U"}, {"\xC3\x9C", "U"}, // ú, ü, Ú, Ü
        {"\xC3\xA7", "c"}, {"\xC3\x87", "C"}                                        // ç, Ç
    };

    std::string result = input;

    for (const auto& pair : utf8Map) 
	{
        size_t pos = 0;

        while ((pos = result.find(pair.first, pos)) != std::string::npos) 
		{
            result.replace(pos, pair.first.length(), pair.second);
            pos += pair.second.length();
        }
    }

    return result;
}

SplitText SplitStringInTwo(const std::string& text) 
{
    const size_t maxLength = 26;
    if (text.length() <= maxLength) 
    {
        return { text, "" };
    }

    size_t midpoint = text.length() / 2 > maxLength ? maxLength : text.length() / 2;
    size_t splitPos = text.find(' ', midpoint);

    if (splitPos == std::string::npos) 
    {
        splitPos = text.rfind(' ', midpoint); 
    }

    if (splitPos != std::string::npos) 
    {
        return { text.substr(0, splitPos), text.substr(splitPos + 1) };
    }

    return { text, "" };
}

void SetCompletion()
{
	session.storyStatus = Story_Completed;
	PrintDebug("[Full Story] Story Complete\n");

	for (int flag = EventFlags_SonicUnlockedAdventure; flag <= EventFlags_SuperSonicAdventureComplete; flag++)
	{
		EventFlagArray[flag] = true;
	}

	if(settings.creditsChar == CreditsChar_Final) SelectedCharacter = 6; // Force Super Sonic for the credits

	SaveProgression();
}

void PlayCutscene(long flag) 
{
	flt_3B18244 = 0;
	EventCutscene_Load2(flag);
	EventCutscene_Exec2();
	CreateElementalTask(LoadObj_Data1, 5, SeqTaskFadeIn);
	return;
}

void CutsceneManager(ObjectMaster* obj) 
{
	if (!IsIngame())
		return;

	EntityData1* data = obj->Data1;

	std::vector<int> setupStages =
	{
		GetStageIndex("Event_Knuck_Intro"),
		GetStageIndex("Event_SonicAndTailsMeetEggman"),
		GetStageIndex("Event_Chaos4_Emerges"),
		GetStageIndex("Event_Sonic_vs_Gamma_Aftermath")
	};

	switch (data->Action)
	{
	case 0:

		if (session.setupStage)
		{
			session.setupStage = false;
		}
		else for (int stage : setupStages) if (session.currentStage == stage) 
		{
			session.setupStage = true;
			if(session.currentStage == GetStageIndex("Event_Knuck_Intro") 
				&& !settings.earlyGammaEnabled) session.setupStage = false;
		}

		if (session.setupStage)
		{
			session.currentStage = session.currentStage - 1;
			session.fadeMode = Fade_In;
			ObjectMaster* fadeScreen = LoadObject(LoadObj_Data1, 1, FadeScreen);

			PrintDebug("[Full Story] Resetting stage...\n");
		}
		else PlayCutscene(stages[session.currentStage].cutsceneID);

		data->Action = 1;

		break;
	case 1:
		if (EV_MainThread_ptr) return;

		bool goToNextStage = !stages[session.currentStage].controlAfterCutscene ||
			(settings.skipBigGameplay && stages[session.currentStage].character == Characters_Big) ||
			(settings.fieldsDisabled && IsAdventureField(stages[session.currentStage].level, true));

		if (goToNextStage)
		{
			DisableController(0);
			PauseEnabled = 0;
			if (++data->Index == 6) 
			{
				j_SetNextLevelAndAct_CutsceneMode(1, 0);
				CheckThingButThenDeleteObject(obj);
			}
		}

		break;
	}
}

void SetCutscene()
{
	session.cutscenePlayed = true;
	ObjectMaster* cutscene = LoadObject((LoadObj)2, 1, CutsceneManager);
}

void GoToNextStageByCondition()
{
	ConditionTrigger trigger = stages[session.currentStage].conditionTrigger.value();

	if (trigger.act > -1)
	{
		if(trigger.act != CurrentAct) return;
	}
	
	if (trigger.flag > -1)
	{
		if (trigger.flag == FLAG_SONIC_EC_TRANSFORM ? 
			EventFlagArray[trigger.flag] : !EventFlagArray[trigger.flag]) return;
	}

	if (session.currentStage == GetStageIndex("Event_Amy_HedgehogHammer") ||
		session.currentStage == GetStageIndex("Gamma_ToEggCarrierMain") ||
		session.currentStage == GetStageIndex("Event_Gamma_GoFindTheJetBooster") ||
		session.currentStage == GetStageIndex("Event_Sonic_ChangingTheEggCarrierBack")) SetNextStage(0, 0);
	else GoNext();
}

void SetBossFight()
{
	if (!session.isInBossFight) return;

	if (playertwp[0])
	{		
		if (!session.bossSpawned)
		{
			PrintDebug("[Full Story] Setting boss fight...\n");
			LoadCharacterBoss(session.currentStage == GetStageIndex("Sonic_vs_Knuckles") ? 0 : 1);
			session.bossSpawned = true; 
		}
		else if (BossCharacter == -1 && session.bossSpawned) // If the player wins, set the next stage
		{		
			session.isInBossFight = false;
			session.bossSpawned = false;	

			GoNext();
		}
	} 
	else
	{	// If the player loses, reset position
		session.startPositionSet = false; 
		session.bossSpawned = false; 
	}
}

void GoToNextStageByTrigger()
{
	int currentStage = session.currentStage;

	if (session.isInsideTrigger)
	{
		if (session.frameCounter > session.frameDelay || currentStage == GetStageIndex("Event_Sonic_EggCarrierTransforms"))
		{
			session.isInsideTrigger = false;
			session.frameCounter = 0;

			if (session.currentStage == GetStageIndex("Event_Sonic_EggCarrierTransforms")) SetNextStage(0, 0);
			else GoNext();
		}
		else session.frameCounter++;

		return;
	}

	if (!IsControlEnabled()) return;

	if (!session.frameBufferEnabled && IsControlEnabled())
	{
		session.frameBufferEnabled = true;
		return;
	}

	SceneTrigger trigger = stages[currentStage].sceneTrigger.value();

	if (session.drawSpheres) DrawCollisionSphere(&trigger.position, (float)trigger.radius);

	if (!IsPointInsideSphere(&trigger.position, &playertwp[0]->pos, (float)trigger.radius)) return;

	if (currentStage == GetStageIndex("Event_Tails_EntersThePast") && CurrentAct != act["Shrine"]) return;

	if (CurrentAct != act["Altar"]) 
	{
		if (currentStage == GetStageIndex("Event_Amy_EntersThePast") || 
			currentStage == GetStageIndex("Event_Gamma_EntersThePast") || 
			currentStage == GetStageIndex("Event_Big_GoesToThePast")) return;
	}

	session.isInsideTrigger = true;
	session.frameCounter = 0;

	if (currentStage == GetStageIndex("Event_Sonic_EggCarrierTransforms")) return;

	session.fadeMode = (currentStage == GetStageIndex("Sonic_ToEggHornet") || 
		currentStage == GetStageIndex("Event_Gamma_E105Rescued")) ? Fade_Out : Fade_OutIn;

    ObjectMaster* flashScreen = LoadObject(LoadObj_Data1, 1, FadeScreen);
}

void SetStuffInsideStage()
{
	if (playertwp[0] == nullptr) return;

	if (session.currentStage == GetStageIndex("Event_Final_TailsFindsSonic") || 
		session.currentStage == GetStageIndex("Event_Final_SonicWakesUp"))
	{
		if (EventFlagArray[MRVAR_MASTEREMERALD_STATE] != MasterEmerald_FullyRestored)
		{
			PrintDebug("[Full Story] Setting Master Emerald state\n");
			EventFlagArray[MRVAR_MASTEREMERALD_STATE] = MasterEmerald_FullyRestored;
		}
	}
	else if (session.currentStage == GetStageIndex("Knuck_ToRedMountain"))
	{
		if (EventFlagArray[MRVAR_MASTEREMERALD_STATE] != MasterEmerald_Broken)
		{
			PrintDebug("[Full Story] Setting Master Emerald state\n");
			EventFlagArray[MRVAR_MASTEREMERALD_STATE] = MasterEmerald_Broken;
		}
	}

	if (stages[session.currentStage].timeofDay != GetTimeOfDay())
	{
		PrintDebug("[Full Story] Setting time of day\n");
		SetTimeOfDay(stages[session.currentStage].timeofDay);
	}
	
	if (stages[session.currentStage].level == STAGE_SS_AFT)
	{
		EventFlagArray[EventFlags_TailsUnlockedAdventure] = false;
	}
	
	if (session.currentStage == GetStageIndex("Event_SonicAndTails_Poolside") && CurrentAct == act["Station Area"] && 
		EventFlagArray[FLAG_MILES_SS_HOTEL_FRONT])
	{   
		EventFlagArray[FLAG_MILES_SS_HOTEL_FRONT] = false; // Avoid triggering Sonic's cutscene
	}

	if (session.currentStage == GetStageIndex("Sonic_ToCasinopolis") && CurrentAct != act["Sewers"]
		&& EventFlagArray[EventFlags_Sonic_LightShoes] && stages[session.currentStage].timeofDay != TimesOfDay_Night)
	{
		stages[session.currentStage].timeofDay = TimesOfDay_Night;
		session.currentTime = 3; // Night
	}

	if (session.currentStage == GetStageIndex("Sonic_SpeedHighway") && CurrentAct == act["Act 3"] && session.currentDay == 2)
	{
		session.currentDay = 3;
		session.currentTime = 0; // Morning
	}

	if (session.currentStage == GetStageIndex("Event_Tails_HeadsAfterTheMissile") && CurrentSong == MusicIDs_s_square)
	{
		PlayMusic(MusicIDs_evtbgm01);
	}	

	if (session.currentStage == GetStageIndex("Event_Gamma_HeadingToHotShelter") && CurrentSong == MusicIDs_EggCarrier)
	{
		PlayMusic(MusicIDs_EggCarrierTheOcean);
	}
}

void ResetLighting()
{
	lanternAPI.set_shader_flags(LANTERNFLAGS, false);
	lanternAPI.set_diffuse_blend_factor(0.0f);

	lanternAPI.lightingChanged = false;

	PrintDebug("[Full Story] Lighting values has been reset to defaults.\n");
}

void SetStageLighting()
{
	if (session.enteredFieldStage) return;

	int currentStage = session.currentStage;

	if (currentStage != GetStageIndex("Big_IceCap") && FogTable != nullptr)
	{
		// Remove the fog (can't figure out how to change the fog color properly)
		njGenerateFogTable3(fogTable, 1.0f, 1000.f);
		njSetFogTable(fogTable);
	}

	if (lanternAPI.lightingChanged) return;

	PrintDebug("[Full Story] Setting custom lighting...\n");
	StagePreset preset = stages[session.currentStage].stagePreset.value();

	lanternAPI.set_shader_flags(LANTERNFLAGS, true);

	lanternAPI.palette_from_rgb(7, preset.diffuse.red, preset.diffuse.green, preset.diffuse.blue, false, true); 	

	float blendFactor = (currentStage >= GetStageIndex("Tails_SandHill") && 
		currentStage <= GetStageIndex("Event_Tails_MeetsTikal")) || 
		currentStage == GetStageIndex("Big_EmeraldCoast") ? 0.65f : 0.9f;

	lanternAPI.set_diffuse_blend(0, 7);
	lanternAPI.set_diffuse_blend(2, 7);
	lanternAPI.set_diffuse_blend_factor(blendFactor);

	// Remove Specular lighting	at night time
	if (currentStage == GetStageIndex("Event_Knuck_InThePast") || currentStage == GetStageIndex("Event_Knuck_TikalCrisis"))
	{	
		lanternAPI.palette_from_rgb(1, 0, 0, 0, true, true); 
		lanternAPI.palette_from_rgb(2, 0, 0, 0, true, true); 
	}

	lanternAPI.lightingChanged = true;	
}

void SetStartPosition()
{
	if (!session.startPositionSet && playertwp[0])
	{
		CharStartPosition startPos = stages[session.currentStage].startPosition.value();
		SetPositionP(0, startPos.position.x, startPos.position.y, startPos.position.z);
		SetRotationP(0, 0, startPos.rotationY, 0);
		session.startPositionSet = true;
	}
}

void SaveLastPosition()
{
	session.lastPlayerPosition = playertwp[0]->pos;
}

void DrawFieldTriggers()
{
	for (const auto& fieldStage : fieldStages)
	{
		if (fieldStage.field != stages[session.currentStage].level) continue;

		DrawCollisionSphere((NJS_VECTOR*)&fieldStage.position, (float)fieldStage.radius);
	}	
}

int __cdecl LoadPVM_r(const char* filename, NJS_TEXLIST* texlist)
{
    auto original = reinterpret_cast<int(__cdecl*)(const char*, NJS_TEXLIST*)>(LoadPVM_t->Target());

	if (session.isInsideAdventure && settings.dynamicStagesEnabled && 
		stages[session.currentStage].stagePreset.has_value() && !session.enteredFieldStage)
	{
		StagePreset preset = stages[session.currentStage].stagePreset.value();
		for (TextureSwap texture : preset.textures)
		{
			if (filename && _stricmp(filename, texture.source.c_str()) == 0 &&
				(modsEnabled.lanternEngine ||  _stricmp(filename, "SS_BG") == 0))
			{
				PrintDebug("[Full Story] Swapping texture: %s -> %s\n", filename, texture.destination.c_str());
				return original(texture.destination.c_str(), texlist);
			}
		}
	}

    return original(filename, texlist);
}

void __cdecl PlayVoice_r(int voice_id)
{
	// Disable Mystic Ruins announcer voice while in battle
	if (session.currentStage == GetStageIndex("Sonic_vs_Knuckles") && voice_id == MR_TRAIN_VOICELINE) return;

    auto original = (void(__cdecl*)(int))PlayVoice_t->Target();
    original(voice_id);
}

void SetStuffInsidePause()
{
	if (GameMode == GameModes_Trial || GameMode == GameModes_Mission || session.storyStatus >= Story_Completed) return;

	if (!session.quitSelected && PauseSelection == 3) AdventureToMenu(true);

	if (session.enteredFieldStage || !settings.pauseInfoEnabled) return;

    static int savedStage = -1;
    static int savedLanguage = -1;
    static int savedTime = -1;
    static int savedDay = -1;
    static SplitText splitText;
    static char timeofDay[64] = "";

    int currentLanguage = modsEnabled.aventuraDeSonic ? 5 : Language; // 5 is Portuguese (Aventura de Sonic)
        
	if (session.currentStage != savedStage || currentLanguage != savedLanguage || 
        session.currentTime != savedTime || session.currentDay != savedDay)
    {
        savedStage = session.currentStage;
        savedLanguage = currentLanguage; 
        savedTime = session.currentTime;
        savedDay = session.currentDay;

		std::string stripDay = StripAccents(dayTimes[savedLanguage][1]);
		std::string stripTime = StripAccents(dayTimes[savedLanguage][session.currentTime]);	
		snprintf(timeofDay, sizeof(timeofDay), "%s %d, %s", stripDay.c_str(), session.currentDay, stripTime.c_str());

        const std::string& objectiveText = stages[session.currentStage].objective[savedLanguage];
		std::string stripObjective = StripAccents(objectiveText);
        splitText = SplitStringInTwo(stripObjective);
    }

	SetDebugFontColor(SetColor(session.currentTime, true));
	SetDebugFontSize(14.0f * (float)VerticalResolution / 480.0f);
	DisplayDebugString(NJM_LOCATION(2, 6), timeofDay);	

    SetDebugFontColor(SetColor(stages[session.currentStage].character, false));
	SetDebugFontSize(10.0f * (float)VerticalResolution / 480.0f);

	if (!splitText.line1.empty()) DisplayDebugStringFormatted(NJM_LOCATION(3, 12), splitText.line1.c_str());
    if (!splitText.line2.empty()) DisplayDebugStringFormatted(NJM_LOCATION(3, 13), splitText.line2.c_str());

    SetDebugFontColor(COLOR_WHITE);
}

void SetStageOnFrames()
{
	if (session.storyStatus >= Story_Completed) return;

	if (GameState == GAMESTATE_PAUSE) SetStuffInsidePause();
	else if (session.quitSelected && IsIngame()) AdventureToMenu(false);

	if (!IsIngame() || !session.isInsideAdventure || session.enteredFieldStage) return;

	if (CurrentCutsceneID == session.outroSceneID) 
	{
		SetCompletion();
		return;
	}

	if (session.currentStage < 0) return;

	bool needsLighting = settings.dynamicStagesEnabled && modsEnabled.lanternEngine 
		&& stages[session.currentStage].stagePreset.has_value()
		&& !IsAdventureField(stages[session.currentStage].level, false);

	if (needsLighting) SetStageLighting();

	if (stages[session.currentStage].cutsceneID > -1 && !session.cutscenePlayed) SetCutscene();

	SetStuffInsideStage();

	if (!IsAdventureField(CurrentLevel, true)) return;
		
	if (stages[session.currentStage].startPosition.has_value()) SetStartPosition();
		
	if (playertwp[0] && IsControlEnabled()) SaveLastPosition();
				
	if (session.currentStage == GetStageIndex("Sonic_vs_Knuckles") || 
		session.currentStage == GetStageIndex("Sonic_vs_Gamma")) SetBossFight();

	if (session.drawSpheres && IsControlEnabled()) DrawFieldTriggers();

	if (stages[session.currentStage].sceneTrigger.has_value()) GoToNextStageByTrigger();
	
	if (stages[session.currentStage].conditionTrigger.has_value()) GoToNextStageByCondition();
}

void Init_StageOnFrames()
{
	LoadPVM_t = new Trampoline((int)LoadPVM, (int)LoadPVM + 0x5, LoadPVM_r);
    PlayVoice_t = new Trampoline((int)PlayVoice, (int)PlayVoice + 0x5, PlayVoice_r);
}

#include "pch.h"
#include <iostream>

bool IsAdventureField(int level, bool includePast)
{
	return (level >= LevelIDs_StationSquare && level <= (includePast ? LevelIDs_Past : LevelIDs_MysticRuins));
}

int GetStageIndex(const std::string& name)
{
    auto it = stage.find(name);
    if (it != stage.end()) return it->second;
    return -2;
}

void SetStageFromAdventureField()
{
	if (session.currentStage < 0) return;

	std::vector<int> excludedFieldStages = 
	{		
		GetStageIndex("Event_Tails_SavedBySonic"),   
		GetStageIndex("Event_SonicAndTails_Gassed_At_Casinopolis"),       
		GetStageIndex("Event_Sonic_Falls_StationSquare"),
		GetStageIndex("Event_Gamma_TheHuntForFroggy"),	
		GetStageIndex("Event_Gamma_ReturnToTheEggCarrier"), 
		GetStageIndex("Event_Gamma_HeadToBeta"), 
		GetStageIndex("Event_Gamma_Beta"), 
		GetStageIndex("Event_Gamma_LeavesBeta"),
		GetStageIndex("Event_Amy_HedgehogHammer")
	};

	if (!session.isInsideAdventure) session.enteredFieldStage = false;
	
    if (session.enteredFieldStage)
    {  
		PrintDebug("[Full Story] Setting the player back to the Adventure Field\n");
        session.currentStage = session.currentStage - 1;
		stages[session.currentStage + 1].act = session.previousAct;

        session.enteredFieldStage = false;
		session.cutscenePlayed = true;
		session.startPositionSet = true;

        return;
    }
	else
	{
		session.startPositionSet = false;
		session.cutscenePlayed = false;
	}

	if (!IsAdventureField(stages[session.currentStage].level, false)) return;
		
	if(!session.isInsideAdventure || settings.fieldsDisabled) return;

    for (auto& fieldStage : fieldStages)
    {
    	if (fieldStage.field != stages[session.currentStage].level) continue;

    	if (!IsPointInsideSphere((NJS_VECTOR*)&fieldStage.position, 
			&session.lastPlayerPosition, (float)fieldStage.radius)) continue;    

		for (std::string name : fieldStage.excludedStages) excludedFieldStages.push_back(GetStageIndex(name));
		for (int stage : excludedFieldStages) if (session.currentStage == stage) return;
		
		session.enteredFieldStage = true;
		
		session.previousAct = CurrentAct;

		CurrentLevel = fieldStage.level;        
		CurrentAct = fieldStage.characterActs.count(CurrentCharacter) ? 
				fieldStage.characterActs.at(CurrentCharacter) : 0;


		for (int flag : fieldStage.eventTrue)  EventFlagArray[flag] = true;
		for (int flag : fieldStage.eventFalse) EventFlagArray[flag] = false;

        PrintDebug("[Full Story] Setting stage from Adventure Field\n");
            
        break;
    }
}

void SetFlags()
{
	int nextStage = session.currentStage + 1;

	session.isInsideAdventure = true;
	session.frameBufferEnabled = false;
	session.isInBossFight = nextStage == GetStageIndex("Sonic_vs_Knuckles") ||
							nextStage == GetStageIndex("Sonic_vs_Gamma");

	if (lanternAPI.lightingChanged) ResetLighting();

	for (int flag = EventFlags_TailsUnlockedAdventure; flag <= EventFlags_BigUnlockedAdventure; flag++)
	{
		EventFlagArray[flag] = false;
	}

	if (nextStage > 0)
	{
		int lastScene = stages[session.currentStage].cutsceneID;			
		if (lastScene > -1 && !CutsceneFlagArray[lastScene]) CutsceneFlagArray[lastScene] = true;
	}

	for (int flag : stages[nextStage].eventTrue)         EventFlagArray[flag] = true;
	for (int flag : stages[nextStage].eventFalse)        EventFlagArray[flag] = false;
	for (int sceneID : stages[nextStage].cutsceneTrue)   CutsceneFlagArray[sceneID] = true;
	for (int sceneID : stages[nextStage].cutsceneFalse)  CutsceneFlagArray[sceneID] = false;

	if (nextStage == GetStageIndex("Event_Tails_Flashback"))
	{
		if (EventFlagArray[EventFlags_Tails_JetAnklet])
		{
			EventFlagArray[EventFlags_Tails_JetAnklet] = false;
			playerUpgrades.jetAnklet = true;
		}
		if (EventFlagArray[EventFlags_Sonic_LightShoes])
		{
			EventFlagArray[EventFlags_Sonic_LightShoes] = false;
			playerUpgrades.lightSpeedShoes = true;
		}
		if (EventFlagArray[EventFlags_Sonic_CrystalRing])
		{
			EventFlagArray[EventFlags_Sonic_CrystalRing] = false;
			playerUpgrades.crystalRing = true;
		}
	}
	else if (nextStage == GetStageIndex("Event_Tails_WakeUpFromDream"))
	{
		if (playerUpgrades.jetAnklet)        EventFlagArray[EventFlags_Tails_JetAnklet] = true;
		if (playerUpgrades.lightSpeedShoes)  EventFlagArray[EventFlags_Sonic_LightShoes] = true;
		if (playerUpgrades.crystalRing)      EventFlagArray[EventFlags_Sonic_CrystalRing] = true;
	}

	if (settings.fieldsDisabled)
	{
		if (nextStage >= GetStageIndex("Sonic_Casinopolis"))            EventFlagArray[EventFlags_Sonic_LightShoes] = true;
		if (nextStage >= GetStageIndex("Knuck_RedMountain"))            EventFlagArray[EventFlags_Knuckles_ShovelClaw] = true;
		if (nextStage >= GetStageIndex("Event_Gamma_HeadingToTheRear")) EventFlagArray[EventFlags_Gamma_JetBooster] = true;
	}

	if (modsEnabled.betterTailsAI && !session.enteredFieldStage)
	{
		bool noTailsStage = nextStage <= GetStageIndex("Sonic_EmeraldCoast") || nextStage == GetStageIndex("Sonic_vs_Knuckles") ||
		(nextStage >= GetStageIndex("Big_ToIceCap") && nextStage <= GetStageIndex("Event_SonicAndTailsOnTheEggCarrier")) ||
		(nextStage >= GetStageIndex("Event_Sonic_vs_Gamma") && nextStage <= GetStageIndex("Event_Final_KnucklesAtTheMasterEmerald")) ||
		(nextStage >= GetStageIndex("Event_Final_SonicHeadsToThePast") && nextStage <= GetStageIndex("Event_Final_TikalSealsChaos"));

		// Disabling this flag prevents spawning Tails
		EventFlagArray[EventFlags_Sonic_EmeraldCoastClear] = !noTailsStage;
	}
}

void CheckandPlayFMV()
{
    if (session.cutscenePlayed) return;

    static std::unordered_map<int, int> FMVMap = 
	{
		{ GetStageIndex("Event_Knuck_Intro"),               FMV_EggCarrierAngelIsland },
        { GetStageIndex("Event_Big_Intro"),                 FMV_AngelIslandFalling },
        { GetStageIndex("Event_Sonic_IceStone"),            FMV_EggCarrierRising },
        { GetStageIndex("Event_Amy_MeetingBirdie"),         FMV_EggCarrierStationSquare },
        { GetStageIndex("Event_Sonic_Loses_Amy"),           FMV_EggCarrierRising },
        { GetStageIndex("Event_Sonic_LandsInMysticRuins"),  FMV_EggCarrierFalling },
        { GetStageIndex("Event_Amy_FinalBoss"),             FMV_AngelIslandRising },
        { GetStageIndex("Event_Final_EggmanInMysticRuins"), FMV_AngelIslandFalling },
        { GetStageIndex("Final_Chaos7"),                    FMV_PerfectChaos }
    };

    auto it = FMVMap.find(session.currentStage + 1);

	if (it != FMVMap.end())
	{
		if (settings.earlyGammaEnabled && it->first == GetStageIndex("Event_Knuck_Intro"))
		{
			 MsMovie(session.setupStage ? it->second : FMV_EggCarrierRising);
		}
		else MsMovie(it->second);
	}
}

void CheckandPlayCutscene()
{
	if (stages[session.currentStage + 1].cutsceneID == -1) return;
	SeqRun();
}

void SetStageData()
{
	LastLevel = CurrentLevel;
	LastAct = CurrentAct;

	CurrentCharacter = stages[session.currentStage + 1].character;
	CurrentLevel = stages[session.currentStage + 1].level;
	CurrentAct = stages[session.currentStage + 1].act;

	SetTimeOfDay(stages[session.currentStage + 1].timeofDay);
}

void SaveGame()
{
	static std::vector<int> excludedStages = 
	{
        GetStageIndex("Sonic_ToIceCap"),
        GetStageIndex("Sonic_vs_Knuckles"),
        GetStageIndex("Event_Tails_MeetsTikal"),
        GetStageIndex("Event_Amy_WinsHedgehogHammer"),
        GetStageIndex("Event_Knuck_EggCarrierTransforms1"),
        GetStageIndex("EggCarrierTransforms"),
        GetStageIndex("Event_Knuck_EggCarrierTransforms2"),
        GetStageIndex("Event_Sonic_SkyDeckEntrance"),
        GetStageIndex("Sonic_vs_Gamma")
    };

	for (int stage : excludedStages) if (session.currentStage + 1 == stage) return;
	
	if (!session.enteredFieldStage) SaveProgression();
}

void LoadGame()
{	
	if (session.currentSave != CurrentSaveSlot)
	{
		session = SessionState();
		session.currentSave = CurrentSaveSlot;		
		session.outroSceneID = scene["Scene_Final_Outro"];

		LoadStages();
		LoadProgression();

		if (session.currentStage + 1 == GetStageIndex("Knuck_ToRedMountain") && EventFlagArray[FLAG_KNUCKLES_MR_SHOVELCLAW])
		{
			EventFlagArray[FLAG_KNUCKLES_MR_ENTRANCE_MOUNTAIN] = true; // Open Knuckles Red Mountain to avoid softlock
		}		
	}
	else if (session.quitSelected)
	{
		session.currentStage = session.currentStage - 1;

		// Send the player back to Station Square to get the Ice Stone
		if (session.currentStage + 1 == GetStageIndex("Sonic_ToIceCap"))
		{
			session.currentStage = session.currentStage - 1;
		}

		session.quitSelected = false;
	}
}

void SetCurrentDay()
{
	if (!settings.pauseInfoEnabled) return;

    int thresholds[] = 
	{
        GetStageIndex("Event_Tails_Intro"),                 
        GetStageIndex("Knuck_SpeedHighway"),                
        GetStageIndex(settings.sonicTailsChar == Char_Tails ? "Tails_Casinopolis" : "Sonic_Casinopolis"),              
        GetStageIndex(settings.earlyGammaEnabled ? "Event_Sonic_IceStone" : "Event_Gamma_Intro"),
        GetStageIndex("Event_SonicAndTails_WakeUp"),                   
        GetStageIndex("Event_Sonic_Falls_StationSquare"),   
        GetStageIndex("Event_Tails_MeetsBig"),            
        GetStageIndex("Event_Gamma_TheHuntForFroggy"),      
        GetStageIndex(settings.fieldsDisabled ? "Gamma_EmeraldCoast" : "Gamma_ToEmeraldCoast"),              
        GetStageIndex(settings.fieldsDisabled ? "Gamma_RedMountain" : "Gamma_ToRedMountain"),              
        GetStageIndex(settings.fieldsDisabled ? "Event_Amy_DiscoveringTheEggBase" : "Amy_ToEggBase"),               
        GetStageIndex("Event_Sonic_SpotsEggman"),          
		GetStageIndex("Event_Gamma_HeadingToHotShelter")
    };	

    int timeIndex = -1;
	int currentTime = -1;
	int nextStage = session.currentStage + 1;

    for (int i = 0; i < (sizeof(thresholds) / sizeof(thresholds[0])); ++i) 
	{
		if (nextStage >= thresholds[i]) timeIndex = i + 1;
        else break;
    }

    if (nextStage == GetStageIndex("Sonic_ToCasinopolis")) 
	{
        timeIndex = (stages[nextStage].timeofDay == TimesOfDay_Evening) ? 2 : 3;
    }

	if (settings.earlyGammaEnabled && nextStage >= GetStageIndex("Event_Gamma_Intro") && 
		nextStage <= GetStageIndex("Event_Gamma_DefeatsBeta"))
	{
        session.currentDay = 0;
		currentTime = 1; // Day
    }
	else
	{
		session.currentDay = (timeIndex == -1) ? 0 : (timeIndex / 4) + 1;
		currentTime = (timeIndex == -1) ? 3 : (timeIndex % 4);
	}

	session.currentTime = currentTime;
}

bool IsFullStoryActive() 
{
    return (session.storyStatus < Story_Completed && GameMode != GameModes_Movie && 
            GameMode != GameModes_Mission && GameMode != GameModes_CharSel && 
		    GameMode < GameModes_StartCredits);
}

bool PreventStageSkip()
{
	if (!session.isInsideAdventure) return false;

	std::vector<ConditionTrigger> skipPreventions = 
	{
		{GetStageIndex("Event_SonicAndTails_Poolside"), act["Station Area"], -1},
		{GetStageIndex("Event_Knuck_OnTheHuntForPieces"), act["Station Area"], -1},
		{GetStageIndex("Sonic_ToCasinopolis"), act["Station Area"], -1},
		{GetStageIndex("Knuck_ToCasinopolis"), act["Station Area"], -1},
		{GetStageIndex("Event_SonicAndTails_WakeUp"), act["Station Area"], -1},
		{GetStageIndex("Sonic_ToIceCap"), act["Station (MR)"], -1},
		{GetStageIndex("Knuck_ToRedMountain"), act["Station (MR)"], -1},
		{GetStageIndex("Event_Big_FroggyGoesToTheBeach"), act["Station Area"], -1}
	};

	for (auto& trigger : skipPreventions)
	{
		if (session.currentStage == trigger.stage && CurrentAct == trigger.act && !settings.fieldsDisabled)
		{
			PrintDebug("[Full Story] Preventing stage skip\n");
			return true;		
		}
	}

	return false;
}

void SetNextStage(char stage, char act)
{
	LoadGame();

	if (IsFullStoryActive())
	{		
		if(PreventStageSkip()) return;
		
		PrintDebug("[Full Story] Setting stage...\n");

		SetStageFromAdventureField();
		
		if (session.enteredFieldStage) return;
			
		SaveGame();

		SetFlags();
		SetStageData();
		SetCurrentDay();
		
		CheckandPlayFMV();
		CheckandPlayCutscene();

		session.currentStage = session.currentStage + 1;
		return;
	}

	// Trial Mode fix
	if (session.storyStatus == Story_Completed && GameMode == GameModes_Menu)
	{
		if (ValueMenu == 14 || ValueMenu == 238 || ValueMenu == 212 || ValueMenu == 138 || ValueMenu == 257)
			SetNextStage((char)CurrentLevel, (char)CurrentAct);
	}

	return SetLevelAndAct(Uint8(stage), (Uint8)(act));
}

bool ShowTitleCard()
{
	if (stages[session.currentStage].displayCard || session.displayCardAfterLoad)
	{
		if (stages[session.currentStage].displayCard) session.displayCardAfterLoad = false;
		return true;
	}

	if (settings.sonicTailsChar == Char_Tails)
    {
        if (session.currentStage == GetStageIndex("Tails_WindyValley") || 
			session.currentStage == GetStageIndex("Tails_Casinopolis") || 
			session.currentStage == GetStageIndex("Tails_IceCap")) return true;
    }

	if (session.currentStage == GetStageIndex("Sonic_SkyDeck") && settings.sonicTailsChar == Char_Sonic) return true;

	return false;
}

int LoadTitleCardTexture_r(int minDispTime) 
{
    if (ShowTitleCard() || !IsFullStoryActive()) 
	{      
        return LoadTitleCardTexture(minDispTime);
    }

    return 0;
}

void GameOver_R()
{
	session.currentStage = session.currentStage - 1;
	session.isInBossFight = false;
	session.bossSpawned = false;
}

void Init_Stages()
{
	// Hack functions which teleport the player to the next stage
	WriteCall((void*)0x41709d, SetNextStage);
	WriteCall((void*)0x417b47, SetNextStage);
	WriteCall((void*)0x41348f, SetNextStage);
	WriteCall((void*)0x41342a, SetNextStage);
	WriteCall((void*)0x4134a2, SetNextStage);

	// Remove SetLevelAndAct when loading adventure data
	WriteData<5>((void*)0x4134f3, 0x90);
	WriteData<1>((void*)0x413502, 0x08);

	WriteCall((void*)0x417bed, GameOver_R);
	WriteCall((void*)0x41717d, GameOver_R);

	WriteJump(j_LoadTitleCardTexture, LoadTitleCardTexture_r);
}
#include "pch.h"

#define SMALL_DELAY 30

NJS_VECTOR triggerPoint;
int triggerRadius = 60;

NJS_VECTOR triggerStagePoint;
int triggerStageRadius;

bool controlCharacter = false;

bool frameBufferEnabled = false;
bool isInsideTrigger = false;
bool isConditionTrue = false;
bool isInBossFight = false;

bool printPosition = false;
bool printInfo = false;
bool drawSpheres = false;

const int frameLimit = 60;

int actionStageTrigger = 0;
int frameDelay = SMALL_DELAY;
int frameCounter = 0;
int timeofDay = 0;

void CheckCompletion()
{
	if (CurrentCutsceneID == Scene_Final_Outro && storyComplete < 1)
	{
		storyComplete = 1;
		PrintDebug("[Full Story] Story Complete\n");

		EventFlagArray[EventFlags_SonicUnlockedAdventure] = true;
		EventFlagArray[EventFlags_TailsUnlockedAdventure] = true;
		EventFlagArray[EventFlags_KnucklesUnlockedAdventure] = true;
		EventFlagArray[EventFlags_AmyUnlockedAdventure] = true;
		EventFlagArray[EventFlags_BigUnlockedAdventure] = true;
		EventFlagArray[EventFlags_GammaUnlockedAdventure] = true;
		EventFlagArray[EventFlags_SuperSonicUnlockedAdventure] = true;

		EventFlagArray[EventFlags_SonicAdventureComplete] = true;
		EventFlagArray[EventFlags_TailsAdventureComplete] = true;
		EventFlagArray[EventFlags_KnucklesAdventureComplete] = true;
		EventFlagArray[EventFlags_AmyAdventureComplete] = true;
		EventFlagArray[EventFlags_BigAdventureComplete] = true;
		EventFlagArray[EventFlags_GammaAdventureComplete] = true;
		EventFlagArray[EventFlags_SuperSonicAdventureComplete] = true;

		EventFlagArray[EventFlags_Sonic_HotelOpen] = true;
		EventFlagArray[FLAG_SONIC_TRAIN] = true;
		EventFlagArray[FLAG_SONIC_RAFT] = true;
		EventFlagArray[FLAG_SONIC_EC_SINK] = true;

		SaveProgression();
	}
}

bool CheckandPlayCutscene()
{
	if (stages[currentStage].isCutscene)
	{
		GameMode = GameModes_Adventure_Field;
		LastLevel = CurrentLevel;
		LastAct = CurrentAct;

		SeqRun();
			
		return true;
	}

	return false;
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

	switch (data->Action)
	{
	case 0:
		if ( currentStage == Sonic_vs_Knuckles || currentStage == Event_Sonic_HeadsAfterEggman || currentStage == Tails_EmeraldCoast )
		{
			ObjectMaster* fadeScreen = LoadObject(LoadObj_Data1, 1, FadeScreen);
		}
		else
		{
			PlayCutscene(stages[currentStage].cutsceneID);
		}
		data->Action = 1;
		break;
	case 1:

		if (EV_MainThread_ptr)
			return;

		if (stages[currentStage].character == Characters_Big && !BigGameplayEnabled)
		{
			controlCharacter = false;
		}
		else
		{
			controlCharacter = stages[currentStage].controlAfterCutscene;
		}

		if (!controlCharacter)
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

void LoadCutsceneObject()
{
	if (stages[currentStage].isCutscene)
	{
		ObjectMaster* cutscene = LoadObject((LoadObj)2, 1, CutsceneManager);
		stages[currentStage].isCutscene = false;
	}
}

void CheckFieldTriggers()
{
	if (isAdventureField)
	{
		for (int i = 0; i < STAGE_TRIGGERS; i++)
		{
			triggerStagePoint.x = triggers[triggerStageIndex[i]].pointX;
			triggerStagePoint.y = triggers[triggerStageIndex[i]].pointY;
			triggerStagePoint.z = triggers[triggerStageIndex[i]].pointZ;
			triggerStageRadius = triggers[triggerStageIndex[i]].radius;

			isPlayerInsideTrigger[i] = IsPointInsideSphere(&triggerStagePoint, &playertwp[0]->pos, (float)triggerStageRadius);

			if (drawSpheres)
			{
				DrawCollisionSphere(&triggerStagePoint, (float)triggerStageRadius);
			}	
			
		}	
	}
}

void SetStageByCondition()
{
	isConditionTrue = (currentStage == Event_Knuck_BackToThePresent && CurrentAct == StationSquare_Hotel)
		|| (currentStage == Event_Big_SearchingForFroggy && CurrentAct == StationSquare_CityHall)
		|| (currentStage == Event_Amy_MeetingBirdie && CurrentAct == StationSquare_Station)
		|| (currentStage == Event_Sonic_SearchesFor_Amy && CurrentAct == StationSquare_StationArea)
		|| (currentStage == Sonic_ToCasinoArea && CurrentAct == StationSquare_Station)
		|| (currentStage == Event_Amy_TalkingToGamma && CurrentAct == EggCarrierInside_HedgehogHammer )
		|| (currentStage == Event_Amy_HedgehogHammer && EventFlagArray[FLAG_AMY_EC_MOGURATATAKI])
		|| (currentStage == EggCarrierTransforms && EventFlagArray[ FLAG_KNUCKLES_EC_TRANSFORM ] )
		|| (currentStage == Event_Knuck_EggCarrierTransforms2 && CurrentAct == EggCarrierOutside_Pool)
		|| (currentStage == Gamma_ToEggCarrierMain && CurrentAct == EggCarrierInside_Main)
		|| (currentStage == Event_Gamma_GoFindTheJetBooster && CurrentAct == EggCarrierInside_Main && EventFlagArray[FLAG_E102_EC_BOOSTER])
		|| (currentStage == Event_Sonic_ChangingTheEggCarrierBack && !EventFlagArray[FLAG_SONIC_EC_TRANSFORM])
		|| (currentStage == Event_Knuck_ReturningToThePresent && CurrentAct == EggCarrierOutside_Runway)
		|| (currentStage == Event_Final_SonicWakesUp && CurrentAct == MysticRuins_Jungle);	
		

	if (isConditionTrue)
	{
		frameBufferEnabled = false;
		isConditionTrue = false;
		SetStageAct(0, 0);
	}
}

void SetStageByTrigger()
{
	// Go to next stage after boss fight is completed
	if ((currentStage == Sonic_vs_Knuckles || currentStage == Sonic_vs_Gamma) && isInBossFight)
	{
		if (BossCharacter == -1)
		{
			isInBossFight = false;
			frameBufferEnabled = false;
			SetStageAct(0, 0);		
		}
	}

	if (isInsideTrigger)
	{
		if (currentStage == Event_Sonic_EggCarrierTransforms)
		{
			frameDelay = 0;
		}
		else
		{
			frameDelay = SMALL_DELAY;
		}
		

		if (frameCounter > frameDelay)
		{
			isInsideTrigger = false;
			frameBufferEnabled = false;

			frameCounter = 0;

			SetStageAct(0, 0);		
		}
		else
		{
			frameCounter++;
		}
	}
	else if (stages[currentStage].hasCutsceneTrigger)
	{
		if (!frameBufferEnabled && IsControlEnabled())
		{
			//PrintDebug("[Full Story] Setting frame buffer\n");
			frameBufferEnabled = true;
		}
		else if (frameBufferEnabled && IsControlEnabled())
		{

			if (currentStage == Event_Sonic_HeadsAfterEggman || currentStage == Event_Knuck_EnteringEggmanBase)
			{
				frameBufferEnabled = false;
				SetStageAct(0, 0);
			}
			else if (currentStage == Sonic_vs_Knuckles && !isInBossFight)
			{
				LoadCharacterBoss(0);			
				isInBossFight = true;
			}
			else if (currentStage == Sonic_vs_Gamma && !isInBossFight)
			{
				LoadCharacterBoss(1);			
				isInBossFight = true;
			}
			else
			{
				if ((int)triggerPoint.x != triggers[triggerIndex].pointX ||
					(int)triggerPoint.y != triggers[triggerIndex].pointY ||
					(int)triggerPoint.z != triggers[triggerIndex].pointZ ||
					(int)triggerRadius != triggers[triggerIndex].radius)
				{
					triggerPoint.x = triggers[triggerIndex].pointX;
					triggerPoint.y = triggers[triggerIndex].pointY;
					triggerPoint.z = triggers[triggerIndex].pointZ;
					triggerRadius = triggers[triggerIndex].radius;
				}

				if (drawSpheres)
				{
					DrawCollisionSphere(&triggerPoint, (float)triggerRadius);
				}

				if (IsPointInsideSphere(&triggerPoint, &playertwp[0]->pos, (float)triggerRadius))
				{
					if (currentStage == Event_Tails_EntersThePast)
					{
						if (CurrentAct == Past_Shrine)
						{
							isInsideTrigger = true;
							frameCounter = 0;
							ObjectMaster* flashScreen = LoadObject(LoadObj_Data1, 1, FlashScreen);
						}
					}
					else if (currentStage == Event_Amy_EntersThePast || currentStage == Event_Gamma_EntersThePast ||
						 currentStage == Event_Big_GoesToThePast)
					{
						if (CurrentAct == Past_Altar)
						{
							isInsideTrigger = true;
							frameCounter = 0;
							ObjectMaster* flashScreen = LoadObject(LoadObj_Data1, 1, FlashScreen);
						}
					}
					else
					{
						isInsideTrigger = true;
						frameCounter = 0;

						if (currentStage != Event_Sonic_EggCarrierTransforms)
						{
							ObjectMaster* flashScreen = LoadObject(LoadObj_Data1, 1, FlashScreen);
						}
					}													
				}
			}
		}
	}
}

void FixStuff()
{
	// Fix Master Emerald State
	if (currentStage == Event_Final_TailsFindsSonic || currentStage == Event_Final_SonicWakesUp)
	{
		if (EventFlagArray[MRVAR_MASTEREMERALD_STATE] != MasterEmerald_FullyRestored)
		{
			PrintDebug("[Full Story] Setting Master Emerald state\n");
			EventFlagArray[MRVAR_MASTEREMERALD_STATE] = MasterEmerald_FullyRestored;
		}
	}
	else if (currentStage == Knuck_ToRedMountain)
	{
		if (EventFlagArray[MRVAR_MASTEREMERALD_STATE] != MasterEmerald_Broken)
		{
			PrintDebug("[Full Story] Setting Master Emerald state\n");
			EventFlagArray[MRVAR_MASTEREMERALD_STATE] = MasterEmerald_Broken;
		}
	}

	// Fix Time of Day
	if (currentStage == Sonic_ToCasinopolis)
	{
		if (CurrentAct != StationSquare_Sewers && EventFlagArray[EventFlags_Sonic_LightShoes])
		{
			stages[currentStage].timeofDay = TimesOfDay_Night;
		}
	}

	if (currentStage == Event_Tails_WakeUpFromDream || currentStage == Event_Tails_ChasesFroggy)
	{
		if (TailsDayTimeEnabled)
		{
			stages[currentStage].timeofDay = TimesOfDay_Day;
		}
	}

	if (stages[currentStage].timeofDay != GetTimeOfDay())
	{
		PrintDebug("[Full Story] Setting time of day\n");
		SetTimeOfDay(stages[currentStage].timeofDay);
	}

	// Disable Tails Unlock
	if (stages[currentStage].level == STAGE_SS_AFT)
	{
		EventFlagArray[EventFlags_TailsUnlockedAdventure] = false;
	}

	// Avoid triggering Sonic's cutscene
	if (currentStage == Tails_ToMysticRuins && CurrentAct == StationSquare_StationArea && EventFlagArray[FLAG_MILES_SS_HOTEL_FRONT])
	{
		EventFlagArray[FLAG_MILES_SS_HOTEL_FRONT] = false;
	}

	// Fix selecting the quit button and unpausing
	if (quitSelected && ControlEnabled)
	{
		isinsideAdventure = true;
		quitSelected = false;
	}
}

void SetStageOnFrames()
{

	if (!IsIngame() || storyComplete == 1)
		return;

	if (printInfo)
	{
		if (frameCounter > frameLimit)
		{
			PrintDebug("[Full Story] quit = %d, entStage = %d, inStage = %d\n", quitSelected, enteredStage, isInsideStage);
			PrintDebug("[Full Story] currAct = %d, prevAct = %d, curChar = %d\n", CurrentAct, previousAct, CurrentCharacter);
			PrintDebug("[Full Story] curStage = %d, prevStage = %d, nextStage = %d\n", currentStage, previousStage, nextStage);
			frameCounter = 0;
		}
		else frameCounter++;
	}

	if (printPosition )
	{
		if (frameCounter > frameDelay)
		{
			PrintDebug("[Full Story] x = %d, y = %d, z = %d\n", ( int ) playertwp[ 0 ]->pos.x, ( int ) playertwp[ 0 ]->pos.y, ( int ) playertwp[ 0 ]->pos.z);
			frameCounter = 0;
		}
		else frameCounter++;
	}

	if (CurrentLevel >= LevelIDs_StationSquare && CurrentLevel <= LevelIDs_Past)
	{
		LoadCutsceneObject();
		CheckFieldTriggers();	
		SetStageByCondition();
		SetStageByTrigger();	
	}

	FixStuff();

	return;
}

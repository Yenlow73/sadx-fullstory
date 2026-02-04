#include "pch.h"
#include <iostream>

static Trampoline* LoadLevel_t = nullptr;

void SetStageFromPause()
{
	if (quitSelected && currentStage > -1)
	{	
		if (!isInsideStage)
		{
			if (currentStage == Sonic_ToIceCap || currentStage == Event_Sonic_SkyDeckEntrance)
			{
				currentStage--;
			}
			
			currentStage--;
		}
		quitSelected = false;
	}
}

void SetStageFromTriggers()
{
	if (enteredStage)
	{
		nextStage = previousStage;
		enteredStage = false;
	}
	else 
	{
		enteredStage = false;

		for (int i = 0; i < STAGE_TRIGGERS; i++)
		{
			if (isPlayerInsideTrigger[i] && isAdventureField)
			{								
				if (isPlayerInsideTrigger[Trigger_ChaoGarden])
				{				
					if (stages[currentStage].level == STAGE_SS_AFT)
					{
						nextStage = StationSquare_ChaoGarden;
						enteredStage = true;
					}
					else if (stages[currentStage].level == STAGE_MR)
					{
						nextStage = MysticRuins_ChaoGarden;
						enteredStage = true;
					}
					else if (stages[currentStage].level == LevelIDs_EggCarrierInside)
					{
						if (CurrentAct == EggCarrierInside_WarpHall)
						{
							nextStage = EggCarrier_ChaoGarden;
							enteredStage = true;
						}
					}
				}
				else
				{
					if (stages[currentStage].level == STAGE_SS_AFT)
					{
						if (i == Trigger_Stage1)
						{		
							nextStage = Knuck_SpeedHighway;	
							enteredStage = true;
						}
						else if (i == Trigger_Stage2)
						{	
							if (stages[currentStage].character == Characters_Sonic && currentStage != Sonic_ToCasinopolis)
							{
								nextStage = Sonic_Casinopolis;
								enteredStage = true;
							}
							else if (stages[currentStage].character == Characters_Knuckles && currentStage != Knuck_ToCasinopolis
								&& currentStage != Event_Knuck_BackToThePresent)
							{
								nextStage = Knuck_Casinopolis;
								enteredStage = true;
							}																
						}
						else if (i == Trigger_Stage3)
						{
							if (stages[currentStage].character == Characters_Sonic && currentStage != Event_Sonic_Sees_Tails_Crash)
							{
								nextStage = Sonic_EmeraldCoast;
								enteredStage = true;
							}
						}
					}
					else if (stages[currentStage].level == STAGE_MR)
					{
						if (i == Trigger_Stage1) 
						{						
							if (stages[currentStage].character == Characters_Tails)
							{
								nextStage = Tails_WindyValley;
								enteredStage = true;
							}
							else if (stages[currentStage].character == Characters_Gamma)
							{
								if (currentStage != Event_Gamma_ObjectiveChanged)
								{
									nextStage = Gamma_WindyValley;
									enteredStage = true;
								}
							}
							else if (currentStage != Event_SonicAndTails_Meet_Chaos1)
							{								
								nextStage = Sonic_WindyValley;
								enteredStage = true;
							}																
						}
						else if (i == Trigger_Stage2)
						{		
							if (stages[currentStage].character == Characters_Big && currentStage != Big_ToIceCap)
							{
								nextStage = Big_IceCap;
								enteredStage = true;
							}
							else if (stages[currentStage].character == Characters_Tails)
							{
								nextStage = Tails_IceCap;
								enteredStage = true;
							}
							else if (stages[currentStage].character == Characters_Sonic && currentStage != Sonic_ToIceCap)
							{
								nextStage = Sonic_IceCap;
								enteredStage = true;
							}							
						}		
						else if (i == Trigger_Stage3)
						{
							if (stages[currentStage].character == Characters_Knuckles)
							{
								if (currentStage != Knuck_ToRedMountain)
								{
									nextStage = Knuck_RedMountain;
									enteredStage = true;
								}
							}
							else if (stages[currentStage].character == Characters_Gamma)
							{
								if (currentStage != Gamma_ToRedMountain)
								{
									nextStage = Gamma_RedMountain;
									enteredStage = true;
								}
							}
							else if (currentStage != Event_Sonic_Loses_Amy)
							{
								nextStage = Sonic_RedMountain;
								enteredStage = true;
							}					
						}
					}
				}		
			}			
		}

		if (!enteredStage)
		{
			if (currentStage == Amy_ToEggBase && CurrentAct == MysticRuins_Station)
			{
				nextStage = Amy_LongHammer;
				enteredStage = true;
			}
		}

		if (enteredStage)
		{
			PrintDebug("[Full Story] Setting stage from adventure field\n");
			previousStage = currentStage;
			previousAct = CurrentAct;
		}
	}
}

void SetStageFromSettings()
{
	switch (nextStage)
	{
		case Sonic_EggHornet:
			if (EggHornetCharacter == LevelsChars_Tails)
			{
				PrintDebug("[Full Story] Skipping Sonic Egg Hornet\n");
				nextStage++;
			}
			break;
		case Tails_EggHornet:
			if (EggHornetCharacter == LevelsChars_Sonic)
			{
				PrintDebug("[Full Story] Skipping Tails Egg Hornet\n");
				nextStage++;
			}
			break;
		case Sonic_WindyValley:
			if (STLevelsCharacter == LevelsChars_Tails && !enteredStage)
			{
				PrintDebug("[Full Story] Skipping Sonic Level\n");
				nextStage++;
			}
			break;
		case Tails_WindyValley:
			if (STLevelsCharacter == LevelsChars_Sonic && !enteredStage)
			{
				PrintDebug("[Full Story] Skipping Tails Level\n");
				nextStage++;
			}
			break;
		case Sonic_Casinopolis:
			if (STLevelsCharacter == LevelsChars_Tails && !enteredStage)
			{
				PrintDebug("[Full Story] Skipping Sonic Level\n");
				nextStage++;
			}
			break;
		case Tails_Casinopolis:
			if (STLevelsCharacter == LevelsChars_Sonic && !enteredStage)
			{
				PrintDebug("[Full Story] Skipping Tails Level\n");
				nextStage++;
			}
			break;
		case Event_Gamma_EggmanIsDisappointed:
			if (!UnusedCutsceneEnabled)
			{
				PrintDebug("[Full Story] Skipping unused cutscene\n");
				nextStage++;
			}
			break;
		case Sonic_IceCap:
			if ( STLevelsCharacter == LevelsChars_Tails && !enteredStage )
			{
				PrintDebug("[Full Story] Skipping Sonic Level\n");
				nextStage++;
			}
			break;
		case Tails_IceCap:
			if ( STLevelsCharacter == LevelsChars_Sonic && !enteredStage )
			{
				PrintDebug("[Full Story] Skipping Tails Level\n");
				nextStage++;
			}
			break;
		case Big_TwinklePark:
			if (!BigGameplayEnabled)
			{
				PrintDebug("[Full Story] Skipping Big's Gameplay\n");
				nextStage = Knuck_ToRedMountain;
			}
			break;
		case Big_ToIceCap:
			if (!BigGameplayEnabled)
			{
				PrintDebug("[Full Story] Skipping Big's Gameplay\n");
				nextStage = Knuck_ToLostWorld;
			}
			break;
		case Big_IceCap:
			if (!BigGameplayEnabled)
			{
				PrintDebug("[Full Story] Skipping Big's Gameplay\n");
				nextStage =  Sonic_TwinklePark;
			}
			break;
		case Event_Sonic_SearchesFor_Amy:
			if (EventFlagArray[EventFlags_Sonic_SpeedHighwayClear])
			{
				PrintDebug("[Full Story] Skipping to Amy's Cutscene\n");
				nextStage = Event_Amy_KidnappedByZero;
			}
			break;
		case Big_EmeraldCoast:
			if (!BigGameplayEnabled)
			{
				PrintDebug("[Full Story] Skipping Big's Gameplay\n");
				nextStage++;
			}
			break;
		case Tails_SkyDeck:
			if (STLevelsCharacter == LevelsChars_Sonic)
			{
				PrintDebug("[Full Story] Skipping Tails Level\n");
				nextStage++;
			}
			break;
		case Sonic_SkyDeck:
			if (STLevelsCharacter == LevelsChars_Tails)
			{
				PrintDebug("[Full Story] Skipping Sonic Level\n");
				nextStage++;
			}
			break;
		case Big_HotShelter:
			if (!BigGameplayEnabled)
			{
				PrintDebug("[Full Story] Skipping Big's Gameplay\n");
				nextStage = Knuck_SkyDeck;
			}
			break;
		case Big_Chaos6:
			if (!BigGameplayEnabled)
			{
				PrintDebug("[Full Story] Skipping Big's Gameplay\n");
				nextStage++;
			}
			break;
	}
	
}

void SetStageTriggers()
{
	if (stages[nextStage].hasCutsceneTrigger)
	{
		PrintDebug("[Full Story] Setting cutscene trigger\n");
		triggerIndex = triggerPoints[nextStage];
	}

	isAdventureField = contains(adventureFields, ADVENTUREFIELDSSIZE, nextStage);

	if (isAdventureField)
	{
		if (stages[nextStage].level == STAGE_SS_AFT)
		{
			PrintDebug("[Full Story] Setting Station Square triggers\n");
			triggerStageIndex[Trigger_ChaoGarden] = Trigger_StationSquare_ChaoGarden;
			triggerStageIndex[Trigger_Stage1] = Trigger_SpeedHighway;
			triggerStageIndex[Trigger_Stage2] = Trigger_Casinopolis;
			triggerStageIndex[Trigger_Stage3] = Trigger_EmeraldCoast;
		}
		else if (stages[nextStage].level == STAGE_MR)
		{
			PrintDebug("[Full Story] Setting Mystic Ruins triggers\n");
			triggerStageIndex[Trigger_ChaoGarden] = Trigger_MysticRuins_ChaoGarden;
			triggerStageIndex[Trigger_Stage1] = Trigger_WindyValley;
			triggerStageIndex[Trigger_Stage2] = Trigger_IceCap;
			triggerStageIndex[Trigger_Stage3] = Trigger_RedMountain;
		}
		else if (stages[nextStage].level == LevelIDs_EggCarrierInside)
		{
			PrintDebug("[Full Story] Setting Egg Carrier triggers\n");
			triggerStageIndex[Trigger_ChaoGarden] = Trigger_EggCarrier_ChaoGarden;
		}
	}
}

void SetStoryFlags()
{
	EventFlagArray[EventFlags_TailsUnlockedAdventure] = false;
	EventFlagArray[EventFlags_KnucklesUnlockedAdventure] = false;
	EventFlagArray[EventFlags_AmyUnlockedAdventure] = false;
	EventFlagArray[EventFlags_BigUnlockedAdventure] = false;
	EventFlagArray[EventFlags_GammaUnlockedAdventure] = false;

	switch (nextStage)
	{
	case Event_Sonic_Sees_Tails_Crash:
		EventFlagArray[ FLAG_MILES_SS_HOTEL_FRONT ] = true;
		EventFlagArray[ EventFlags_Sonic_TrainOpen ] = false;
		break;
	case Tails_ToMysticRuins:
		EventFlagArray[FLAG_MILES_SS_HOTEL_BACK] = false;
		EventFlagArray[FLAG_MILES_SS_HOTEL_FRONT] = true;
		EventFlagArray[FLAG_MILES_SS_HOTEL_POOL] = true;
		EventFlagArray[FLAG_MILES_SS_STATION_BACK] = false;
		EventFlagArray[FLAG_MILES_SS_STATION_FRONT] = true;
		EventFlagArray[EventFlags_Tails_TrainOpen] = true;
		break;
	case Sonic_ToEggHornet:
		EventFlagArray[EventFlags_Sonic_TrainOpen] = false;
		break;
	case Event_SonicAndTails_Meet_Chaos1:
		EventFlagArray[EventFlags_Sonic_EggHornetClear] = true;
		EventFlagArray[EventFlags_Tails_EggHornetClear] = true;
		break;
	case Sonic_ToStationSquare:
		EventFlagArray[EventFlags_Sonic_TrainOpen] = true;
		EventFlagArray[EventFlags_Sonic_WindyValleyClear] = true;
		EventFlagArray[EventFlags_Tails_WindyValleyClear] = true;
		break;
	case Sonic_ToCasinopolis:
		EventFlagArray[FLAG_SONIC_SS_BARRICADE] = true;
		EventFlagArray[FLAG_SONIC_SS_ENTRANCE_SEWER] = true;
		EventFlagArray[FLAG_SONIC_SS_EXIT_SEWER] = true;
		EventFlagArray[EventFlags_Sonic_HotelToCasinoOpen] = true;
		EventFlagArray[EventFlags_Sonic_HotelOpen] = true;
		EventFlagArray[EventFlags_Sonic_StationToCasinoOpen] = true;
		EventFlagArray[EventFlags_Sonic_StationOpen] = true;
		EventFlagArray[EventFlags_Sonic_TrainOpen] = false;
		break;
	case Knuck_ToCasinopolis:
		EventFlagArray[FLAG_KNUCKLES_TRAIN] = false;
		EventFlagArray[FLAG_KNUCKLES_SS_HOTEL_BACK] = true;
		EventFlagArray[FLAG_KNUCKLES_SS_HOTEL_FRONT] = true;
		EventFlagArray[FLAG_KNUCKLES_SS_ENTRANCE_CASINO] = permanentEntrances;	
		break;
	case Event_Knuck_BackToThePresent:
		EventFlagArray[FLAG_KNUCKLES_SS_HOTEL_BACK] = true;
		break;
	case Event_Knuck_FollowingEggman:
		EventFlagArray[FLAG_KNUCKLES_TRAIN] = false;
		EventFlagArray[FLAG_KNUCKLES_SS_HOTEL_BACK] = true;
		EventFlagArray[FLAG_KNUCKLES_SS_HOTEL_FRONT] = true;
		EventFlagArray[FLAG_KNUCKLES_SS_ENTRANCE_CHAOS2] = true;
		break;
	case Event_Sonic_IceStone:
		EventFlagArray[ EventFlags_Sonic_IceStoneAvailable ] = true;
		break;
	case Event_SonicAndTails_WakeUp:
		EventFlagArray[EventFlags_Sonic_CasinopolisClear] = true;
		EventFlagArray[EventFlags_Tails_CasinopolisClear ] = true;
		EventFlagArray[EventFlags_Sonic_IceStoneAvailable] = true;
		EventFlagArray[EventFlags_Sonic_StationToCasinoOpen] = true;
		EventFlagArray[EventFlags_Sonic_TrainOpen] = true;
		break;
	case Sonic_ToIceCap:
		EventFlagArray[EventFlags_Sonic_TrainOpen] = false;
		EventFlagArray[FLAG_SONIC_MR_WESTROCK] = true;
		EventFlagArray[ FLAG_MILES_MR_WESTROCK ] = true;
		EventFlagArray[ FLAG_KNUCKLES_MR_WESTROCK ] = true;
		EventFlagArray[ FLAG_BIG_MR_WESTROCK ] = true;
		EventFlagArray[ FLAG_E102_MR_WESTROCK ] = true;
		break;
	case Big_ToMysticRuins:
		EventFlagArray[FLAG_BIG_SS_STATION_FRONT] = true;
		EventFlagArray[FLAG_BIG_TRAIN] = true;
		EventFlagArray[FLAG_BIG_SS_ICESTONE] = !permanentEntrances;
		EventFlagArray[ FLAG_BIG_MR_ENTRANCE_ICECAP ] = true;
		EventFlagArray[FLAG_BIG_SS_TPARK_ELEVATOR] = true;
		break;
	case Knuck_ToRedMountain:
		EventFlagArray[FLAG_KNUCKLES_MR_ISLANDDOOR] = true;
		EventFlagArray[FLAG_KNUCKLES_MR_WESTROCK] = true;
		break;
	case Knuck_ToSonic:
		EventFlagArray[EventFlags_Sonic_IceCapClear] = true;
		EventFlagArray[ EventFlags_Tails_IceCapClear ] = true;
		EventFlagArray[ FLAG_KNUCKLES_MR_ISLANDDOOR ] = true;
		EventFlagArray[ FLAG_KNUCKLES_MR_WESTROCK ] = true;
		EventFlagArray[FLAG_SONIC_MR_ICESTONE] = true;
		break;
	case Sonic_Chaos4:
		EventFlagArray[EventFlags_Sonic_Chaos4Clear] = true;
		break;
	case Event_SonicAndTails_Depart_Knuckles:
		EventFlagArray[FLAG_SONIC_TRAIN] = false;
		EventFlagArray[FLAG_SONIC_MR_WESTROCK] = true;
		EventFlagArray[FLAG_SONIC_MBOSS_KNUCKLES] = true;
		EventFlagArray[ FLAG_MILES_MBOSS_KNUCKLES ] = true;
		EventFlagArray[ FLAG_KNUCKLES_MBOSS_SONIC ] = true;
		break;
	case Knuck_ToLostWorld:
		EventFlagArray[EventFlags_KnucklesUnlockedAdventure] = false;
		EventFlagArray[FLAG_KNUCKLES_TRAIN] = false;
		EventFlagArray[FLAG_KNUCKLES_MR_TRUCK] = true;	
		EventFlagArray[EventFlags_Knuckles_Chaos4Clear] = false;
		break;
	case Event_Tails_Flashback:
		if (EventFlagArray[EventFlags_Tails_JetAnklet])
		{
			EventFlagArray[EventFlags_Tails_JetAnklet] = false;
			jetAnklet = true;
		}
		if (EventFlagArray[EventFlags_Sonic_LightShoes])
		{
			EventFlagArray[EventFlags_Sonic_LightShoes] = false;
			lightSpeedShoes = true;
		}
		if (EventFlagArray[EventFlags_Sonic_CrystalRing])
		{
			EventFlagArray[EventFlags_Sonic_CrystalRing] = false;
			crystalRing = true;
		}
		break;
	case Event_Tails_WakeUpFromDream:
		if (jetAnklet)
			EventFlagArray[EventFlags_Tails_JetAnklet] = true;
		if (lightSpeedShoes)
			EventFlagArray[EventFlags_Sonic_LightShoes] = true;
		if (crystalRing)
			EventFlagArray[EventFlags_Sonic_CrystalRing] = true;

		EventFlagArray[FLAG_MILES_MR_WINDYSTONE] = permanentEntrances;
		EventFlagArray[FLAG_MILES_TRAIN] = false;
		EventFlagArray[FLAG_MILES_MR_TRUCK] = true;
		EventFlagArray[FLAG_MILES_MR_ENTRANCE_ICECAP] = permanentEntrances;
		EventFlagArray[FLAG_MILES_MR_WESTROCK] = true;
		EventFlagArray[EventFlags_Tails_Chaos4Clear] = false;
		EventFlagArray[FLAG_MILES_MBOSS_KNUCKLES] = true;
		EventFlagArray[ EventFlags_Tails_WindyValleyClear ] = true;
		break;
	case Event_Amy_MeetingBirdie:
		EventFlagArray[FLAG_AMY_SS_HOTEL_FRONT] = true;
		EventFlagArray[FLAG_AMY_SS_HOTEL_BACK] = true;
		break;
	case Event_Amy_FindsSonic:
		EventFlagArray[FLAG_AMY_SS_HOTEL_FRONT] = true;
		EventFlagArray[FLAG_AMY_SS_HOTEL_BACK] = true;
		break;
	case Event_Tails_MeetsBig:
		EventFlagArray[FLAG_MILES_MR_WINDYSTONE] = true;
		EventFlagArray[FLAG_MILES_MR_TRUCK] = false;
		EventFlagArray[FLAG_MILES_TRAIN] = false;
		break;
	case Big_ToIceCap:
		EventFlagArray[FLAG_BIG_MR_TRUCK] = true;
		EventFlagArray[FLAG_BIG_MR_WESTROCK] = true;
		EventFlagArray[FLAG_BIG_TRAIN] = false;
		EventFlagArray[FLAG_BIG_MR_ICESTONE] = permanentEntrances;	
		EventFlagArray[ FLAG_BIG_SS_ICESTONE ] = permanentEntrances;
		EventFlagArray[ FLAG_BIG_MR_ENTRANCE_ICECAP ] = true;
		break;
	case Big_ToStationSquare:
		EventFlagArray[FLAG_BIG_MR_TRUCK] = true;
		EventFlagArray[ FLAG_BIG_MR_ICESTONE ] = permanentEntrances;
		EventFlagArray[FLAG_BIG_MR_WESTROCK] = true;
		EventFlagArray[ FLAG_BIG_MR_ENTRANCE_ICECAP ] = true;
		EventFlagArray[FLAG_BIG_TRAIN] = true;
		break;
	case Event_Sonic_Card:
		EventFlagArray[EventFlags_Sonic_HotelOpen] = false;
		EventFlagArray[EventFlags_Sonic_StationOpen] = false;
		EventFlagArray[EventFlags_Sonic_TrainOpen] = false;
		EventFlagArray[FLAG_SONIC_SS_TPARK_ELEVATOR] = true;
		EventFlagArray[FLAG_SONIC_SS_CARD] = true;
		break;
	case Sonic_ToCasinoArea:
		EventFlagArray[EventFlags_Sonic_HotelOpen] = true;
		EventFlagArray[EventFlags_Sonic_HotelToCasinoOpen] = true;
		EventFlagArray[EventFlags_Sonic_StationOpen] = false;
		EventFlagArray[FLAG_SONIC_SS_TPARK_ELEVATOR] = false;
		EventFlagArray[FLAG_SONIC_SS_ENTRANCE_CASINO] = false;
		break;
	case Event_Sonic_Finds_AmyAndZero:
		EventFlagArray[EventFlags_Sonic_StationToCasinoOpen] = true;
		EventFlagArray[EventFlags_Sonic_TrainOpen] = true;
		EventFlagArray[FLAG_SONIC_SS_ENTRANCE_CASINO] = false;
		break;
	case Event_Big_FroggyGoesToTheBeach:
		EventFlagArray[FLAG_BIG_SS_HOTEL_FRONT] = true;
		EventFlagArray[FLAG_BIG_SS_HOTEL_POOL] = true;
		EventFlagArray[FLAG_BIG_TRAIN] = false;
		EventFlagArray[FLAG_BIG_SS_STATION_FRONT] = true;
		EventFlagArray[FLAG_BIG_MR_ICESTONE] = true;
		break;
	case Gamma_ToEmeraldCoast:
		EventFlagArray[FLAG_E102_SS_HOTEL_FRONT] = true;
		break;
	case Event_Knuck_PartialRestoration:
		EventFlagArray[FLAG_KNUCKLES_MR_ENTRANCE_MOUNTAIN] = permanentEntrances;
		EventFlagArray[FLAG_KNUCKLES_MR_APPEAR_FINALEGG] = true;
		EventFlagArray[FLAG_KNUCKLES_MR_TRUCK] = true;
		EventFlagArray[ FLAG_KNUCKLES_MR_ISLANDDOOR ] = true;
		EventFlagArray[ FLAG_KNUCKLES_MR_WESTROCK ] = true;
		break;
	case Event_Sonic_Loses_Amy:
		EventFlagArray[FLAG_SONIC_MR_WESTROCK] = true;
		EventFlagArray[FLAG_SONIC_TRAIN] = false;
		EventFlagArray[FLAG_SONIC_MR_ISLANDDOOR] = true;
		EventFlagArray[EventFlags_Sonic_RedMountainOpen] = permanentEntrances;
		EventFlagArray[EventFlags_Sonic_IceCapOpen] = permanentEntrances;
		EventFlagArray[EventFlags_Sonic_WindyValleyOpen] = permanentEntrances;
		break;
	case Event_Sonic_Tornado2Transform:
		EventFlagArray[FLAG_SONIC_EC_TORNADO2_LOST] = true;
		break;
	case Event_SonicAndTailsOnTheEggCarrier:
		EventFlagArray[FLAG_SONIC_EC_TORNADO2_LOST] = false;
		break;
	case Event_Knuck_EggCarrierTransforms2:
		EventFlagArray[FLAG_KNUCKLES_EC_PALMSWITCH] = true;
		break;
	case Event_Sonic_AfterSkyDeck:
		EventFlagArray[FLAG_SONIC_EC_EGGLIFT] = true;
		EventFlagArray[EventFlags_Sonic_SkyDeckClear] = true;
		EventFlagArray[ EventFlags_Tails_SkyDeckClear ] = true;
		break;
	case Event_Gamma_GoFindTheJetBooster:
		EventFlagArray[FLAG_E102_EC_EGGLIFT] = false;
		EventFlagArray[FLAG_E102_EC_MONORAIL] = false;
		EventFlagArray[FLAG_E102_EC_TRANSFORM] = true;
		EventFlagArray[EventFlags_Gamma_EmeraldCoastClear] = true;
		break;
	case Event_Gamma_HeadingToTheRear:
		EventFlagArray[FLAG_E102_EC_EGGLIFT] = true;
		break;
	case Event_Sonic_ChangingTheEggCarrierBack:
		EventFlagArray[FLAG_SONIC_EC_EGGLIFT] = false;
		break;
	case Event_Big_ReadyToLeaveTheEggCarrier:
		EventFlagArray[FLAG_BIG_EC_MONORAIL] = true;
		break;
	case Event_Knuck_ReturningToThePresent:
		EventFlagArray[FLAG_KNUCKLES_EC_PALMSWITCH] = true;
		EventFlagArray[FLAG_KNUCKLES_EC_TRANSFORM] = false;
		break;
	case Event_Big_Outro:
		EventFlagArray[EventFlags_BigAdventureComplete] = true;
		break;
	case Event_Gamma_ObjectiveChanged:
		EventFlagArray[FLAG_E102_MR_WESTROCK] = true;
		EventFlagArray[ FLAG_E102_MR_ISLANDDOOR ] = false;
		EventFlagArray[EventFlags_Gamma_WindyValleyOpen] = permanentEntrances;
		break;
	case Gamma_ToRedMountain:
		EventFlagArray[FLAG_E102_MR_ISLANDDOOR] = true;
		EventFlagArray[FLAG_E102_MR_WESTROCK] = true;
		EventFlagArray[FLAG_E102_MR_ENTRANCE_MOUNTAIN] = permanentEntrances;
		break;
	case Amy_ToEggBase:
		EventFlagArray[FLAG_AMY_RAFT] = true;
		EventFlagArray[FLAG_AMY_MR_TRUCK] = true;
		EventFlagArray[FLAG_AMY_MR_APPEAR_FINALEGG] = true;
		break;
	case Event_Amy_DiscoveringTheEggBase:
		EventFlagArray[FLAG_AMY_MR_APPEAR_FINALEGG] = true;
		break;
	case Event_Gamma_RememberingHisBrothers:
		EventFlagArray[FLAG_E102_MR_ISLANDDOOR] = true;
		EventFlagArray[FLAG_E102_MR_WESTROCK] = true;
		EventFlagArray[FLAG_E102_RAFT] = true;
		break;
	case Event_Sonic_SpotsEggman:
		EventFlagArray[FLAG_SONIC_MR_APPEAR_FINALEGG] = true;
		EventFlagArray[EventFlags_Sonic_FinalEggOpen] = permanentEntrances;
		break;
	case Event_Gamma_HeadingToHotShelter:
		EventFlagArray[EventFlags_Gamma_EggCarrierSunk] = true;
		EventFlagArray[FLAG_E102_EC_EGGLIFT] = true;
		break;
	case Gamma_ToHotShelter:
		EventFlagArray[FLAG_E102_EC_HOTSHELTER] = true;
		EventFlagArray[FLAG_E102_EC_EGGLIFT] = false;
		break;
	case Event_Gamma_E105Rescued:
		EventFlagArray[EventFlags_TailsAdventureComplete] = true;
		EventFlagArray[EventFlags_Gamma_EggCarrierSunk] = true;
		EventFlagArray[FLAG_E102_EC_EGGLIFT] = false;
		break;
	case Event_Gamma_Outro:
		EventFlagArray[EventFlags_Gamma_EggCarrierSunk] = true;
		EventFlagArray[EventFlags_GammaAdventureComplete] = true;
		break;
	case Event_Amy_BackToTheEggCarrier:
		EventFlagArray[FLAG_AMY_RAFT] = true;
		EventFlagArray[FLAG_AMY_MR_TRUCK] = true;
		break;
	case Amy_LongHammer:
		EventFlagArray[FLAG_AMY_EC_EGGLIFT] = true;
		EventFlagArray[EventFlags_Amy_EggCarrierSunk] = true;
		break;
	case Event_Amy_FinalBoss:
		EventFlagArray[EventFlags_Amy_EggCarrierSunk] = true;
		break;
	case Event_Amy_Outro:
		EventFlagArray[EventFlags_Amy_EggCarrierSunk] = true;
		EventFlagArray[EventFlags_AmyAdventureComplete] = true;
		break;
	case Event_Knuck_Outro:
		EventFlagArray[EventFlags_KnucklesAdventureComplete] = true;
		break;
	case Event_Final_TailsFindsSonic:
		EventFlagArray[FLAG_SONIC_MR_TRUCK] = false;
		EventFlagArray[FLAG_SONIC_TRAIN] = false;
		break;
	case Event_Final_SonicWakesUp:
		EventFlagArray[FLAG_SONIC_MR_TRUCK] = true;
		EventFlagArray[FLAG_SONIC_TRAIN] = false;
		break;
	case StationSquare_ChaoGarden:
		EventFlagArray[FLAG_SONIC_ARRIVE_IN_EC] = false;
		EventFlagArray[FLAG_SONIC_ARRIVE_IN_MR] = false;
		EventFlagArray[FLAG_MILES_ARRIVE_IN_EC] = false;
		EventFlagArray[FLAG_MILES_ARRIVE_IN_MR] = false;
		EventFlagArray[FLAG_KNUCKLES_ARRIVE_IN_EC] = false;
		EventFlagArray[FLAG_KNUCKLES_ARRIVE_IN_MR] = false;
		EventFlagArray[FLAG_AMY_ARRIVE_IN_EC] = false;
		EventFlagArray[FLAG_AMY_ARRIVE_IN_MR] = false;
		EventFlagArray[FLAG_BIG_ARRIVE_IN_EC] = false;
		EventFlagArray[FLAG_BIG_ARRIVE_IN_MR] = false;
		EventFlagArray[FLAG_E102_ARRIVE_IN_EC] = false;
		EventFlagArray[FLAG_E102_ARRIVE_IN_MR] = false;
		break;
	case MysticRuins_ChaoGarden:
		EventFlagArray[FLAG_SONIC_ARRIVE_IN_EC] = false;
		EventFlagArray[FLAG_SONIC_ARRIVE_IN_SS] = false;
		EventFlagArray[FLAG_MILES_ARRIVE_IN_EC] = false;
		EventFlagArray[FLAG_MILES_ARRIVE_IN_SS] = false;
		EventFlagArray[FLAG_KNUCKLES_ARRIVE_IN_EC] = false;
		EventFlagArray[FLAG_KNUCKLES_ARRIVE_IN_SS] = false;
		EventFlagArray[FLAG_AMY_ARRIVE_IN_EC] = false;
		EventFlagArray[FLAG_AMY_ARRIVE_IN_SS] = false;
		EventFlagArray[FLAG_BIG_ARRIVE_IN_EC] = false;
		EventFlagArray[FLAG_BIG_ARRIVE_IN_SS] = false;
		EventFlagArray[FLAG_E102_ARRIVE_IN_EC] = false;
		EventFlagArray[FLAG_E102_ARRIVE_IN_SS] = false;
		break;
	case EggCarrier_ChaoGarden:
		EventFlagArray[FLAG_SONIC_ARRIVE_IN_MR] = false;
		EventFlagArray[FLAG_SONIC_ARRIVE_IN_SS] = false;
		EventFlagArray[FLAG_MILES_ARRIVE_IN_MR] = false;
		EventFlagArray[FLAG_MILES_ARRIVE_IN_SS] = false;
		EventFlagArray[FLAG_KNUCKLES_ARRIVE_IN_MR] = false;
		EventFlagArray[FLAG_KNUCKLES_ARRIVE_IN_SS] = false;
		EventFlagArray[FLAG_AMY_ARRIVE_IN_MR] = false;
		EventFlagArray[FLAG_AMY_ARRIVE_IN_SS] = false;
		EventFlagArray[FLAG_BIG_ARRIVE_IN_MR] = false;
		EventFlagArray[FLAG_BIG_ARRIVE_IN_SS] = false;
		EventFlagArray[FLAG_E102_ARRIVE_IN_MR] = false;
		EventFlagArray[FLAG_E102_ARRIVE_IN_SS] = false;
		break;
	}
}

void SetCutsceneFlags()
{
	switch (nextStage)
	{
		case Tails_ToMysticRuins:
			CutsceneFlagArray[Scene_Tails_Intro] = true;
			CutsceneFlagArray[Scene_Tails_SavedBySonic] = true;
			CutsceneFlagArray[Scene_Sonic_Sees_Tails_Crash] = true;
			CutsceneFlagArray[Scene_TailsAndSonic_Poolside] = true;
			CutsceneFlagArray[Scene_SonicAndTails_Poolside] = true;
			break;
		case Event_SonicAndTails_Meet_Chaos1:
			CutsceneFlagArray[Scene_TailsAndEggman_Meet] = true;
			CutsceneFlagArray[Scene_Tails_Chaos1] = true;
			break;
		case Event_SonicAndTails_WakeUp:
			CutsceneFlagArray[Scene_TailsAndSonic_GassedAtCasinopolis] = true;
			CutsceneFlagArray[Scene_TailsAndSonic_WakeUpAfterCasinopolis] = true;
			break;
		case Sonic_ToIceCap:
			CutsceneFlagArray[ Scene_Sonic_WestRock ] = true;
			CutsceneFlagArray[Scene_Tails_WestRock] = true;
			CutsceneFlagArray[Scene_Big_WestRock] = true;
			CutsceneFlagArray[Scene_Sonic_IceStone] = true;
			CutsceneFlagArray[Scene_Tails_IceStone] = true;
			CutsceneFlagArray[Scene_Big_IceStone] = true;
			break;
		case Event_SonicAndTails_Depart_Knuckles:
			CutsceneFlagArray[Scene_TailsAndEggman_Meet] = true;
			CutsceneFlagArray[Scene_Tails_Chaos1] = true;
			CutsceneFlagArray[Scene_TailsAndSonic_GassedAtCasinopolis] = true;
			CutsceneFlagArray[Scene_Sonic_vs_Knuckles] = true;
			CutsceneFlagArray[Scene_Tails_vs_Knuckles] = true;
			CutsceneFlagArray[Scene_Tails_Chaos4Emerges] = true;
			CutsceneFlagArray[Scene_Knuck_Chaos4Battle] = true;
			CutsceneFlagArray[Scene_Knuck_Departs] = true;
			CutsceneFlagArray[Scene_TailsAndSonic_DepartKnuckles] = true;
			break;
		case Event_SonicAndTails_Tornado1Takeoff:		
			CutsceneFlagArray[Scene_TailsAndSonic_Tornado1Takeoff] = true;
			break;
		case Event_AmyAndSonic_VisitTwinklePark:
			CutsceneFlagArray[Scene_Sonic_Meets_Amy] = true;
			CutsceneFlagArray[Scene_SonicAndAmy_EnterTwinklePark] = true;
			break;
		case Event_Tails_MeetsBig:
			CutsceneFlagArray[Scene_Big_TailsDropsFroggy] = true;
			break;
		case Sonic_ToCasinoArea:
			CutsceneFlagArray[Scene_Gamma_TheHuntForFroggy] = true;
			break;
		/*case Big_EmeraldCoast:
			CutsceneFlagArray[ Scene_Big_GammaTakesFroggy ] = true;
			break;*/
		case Event_Sonic_Loses_Amy:
			CutsceneFlagArray[Scene_Amy_KidnappedByZero] = true;
			CutsceneFlagArray[Scene_Amy_KidnappedToMysticRuins] = true;
			break;
		case Event_Sonic_SkyDeckEntrance:
			CutsceneFlagArray[Scene_Sonic_Tornado2Transform] = true;
			CutsceneFlagArray[ Scene_TailsAndSonic_LandOnTheEggCarrier ] = true;
			CutsceneFlagArray[ Scene_Tails_Tornado2Landing ] = true;
			CutsceneFlagArray[Scene_Tails_CatchesUpWithSonic] = true;
			CutsceneFlagArray[Scene_Tails_SkyChaseAttack] = true;
			CutsceneFlagArray[Scene_TailsAndSonic_LandOnTheEggCarrier] = true;
			CutsceneFlagArray[Scene_Tails_SkyDeckEntrance] = true;
			CutsceneFlagArray[ Scene_Tails_EggCarrierTransforms ] = true;
			break;	
		case Gamma_ToEggCarrierMain:
			CutsceneFlagArray[Scene_Gamma_Intro] = true;
			CutsceneFlagArray[Scene_Gamma_TheHuntForFroggy] = true;
			CutsceneFlagArray[ Scene_Gamma_ReturnToTheEggCarrier ] = true;
			CutsceneFlagArray[ Scene_Gamma_HeadToBeta ] = true;
			CutsceneFlagArray[ Scene_Gamma_Beta ] = true;
			CutsceneFlagArray[ Scene_Gamma_LeavesBeta ] = true;
			CutsceneFlagArray[ Scene_Gamma_AmyJailCell ] = true;
			CutsceneFlagArray[Scene_Amy_TalkingToGamma] = true;
			CutsceneFlagArray[ Scene_Amy_HedgehogHammer ] = true;
			CutsceneFlagArray[ Scene_Amy_WinsHedgehogHammer ] = true;
			break;
		case Sonic_vs_Gamma:
			CutsceneFlagArray[ Scene_Gamma_Intro ] = true;
			CutsceneFlagArray[ Scene_Gamma_TheHuntForFroggy ] = true;
			CutsceneFlagArray[ Scene_Gamma_AmyJailCell ] = true;
			break;
		case Event_Sonic_ChangingTheEggCarrierBack:
			CutsceneFlagArray[ Scene_Tails_AfterSkyDeck ] = true;
			CutsceneFlagArray[ Scene_Gamma_HeadingToTheRear ] = true;
			CutsceneFlagArray[ Scene_Sonic_vs_Gamma ] = true;
			CutsceneFlagArray[ Scene_Tails_vs_Gamma ] = true;
			CutsceneFlagArray[ Scene_Gamma_EmergesToFightSonic ] = true;
			CutsceneFlagArray[ Scene_Sonic_HeadsAfterEggman ] = true;
			CutsceneFlagArray[ Scene_Tails_LeavesWithAmy ] = true;
			CutsceneFlagArray[ Scene_Gamma_AfterSonicBattle ] = true;
			CutsceneFlagArray[Scene_Amy_EntersThePast] = true;
			CutsceneFlagArray[Scene_Amy_MeetsTikal] = true;
			CutsceneFlagArray[Scene_Amy_EggmanTakesBirdie] = true;
			CutsceneFlagArray[Scene_Amy_LeavesWithTails] = true;
			break;
		case Big_Chaos6:
			CutsceneFlagArray[ Scene_Sonic_EggCarrierTransformsBack ] = true;
			CutsceneFlagArray[ Scene_Big_EggCarrierTransformsBack ] = true;
			CutsceneFlagArray[ Scene_Big_ReadyToLeaveTheEggCarrier ] = true;
			CutsceneFlagArray[Scene_Sonic_FindsChaos6] = true;
			break;
		case Event_Knuck_ReturningToAngelIsland:
			CutsceneFlagArray[ Scene_Tails_AfterSkyDeck ] = true;
			CutsceneFlagArray[ Scene_Gamma_HeadingToTheRear ] = true;
			CutsceneFlagArray[ Scene_Sonic_vs_Gamma ] = true;
			CutsceneFlagArray[ Scene_Tails_vs_Gamma ] = true;
			CutsceneFlagArray[ Scene_Gamma_EmergesToFightSonic ] = true;
			CutsceneFlagArray[ Scene_Sonic_HeadsAfterEggman ] = true;
			CutsceneFlagArray[ Scene_Tails_LeavesWithAmy ] = true;
			CutsceneFlagArray[ Scene_Gamma_AfterSonicBattle ] = true;
			CutsceneFlagArray[ Scene_Amy_EntersThePast ] = true;
			CutsceneFlagArray[ Scene_Amy_MeetsTikal ] = true;
			CutsceneFlagArray[ Scene_Amy_EggmanTakesBirdie ] = true;
			CutsceneFlagArray[ Scene_Amy_LeavesWithTails ] = true;
			CutsceneFlagArray[ Scene_Knuck_ReturningToThePresent ] = true;
			CutsceneFlagArray[ Scene_Sonic_FollowsEggman ] = true;
			break;
		case Event_Big_Outro:
			CutsceneFlagArray[Scene_Big_TakesTheTornado2] = true;
			break;
		case Event_Tails_EggmanLaunchesMissile:
			CutsceneFlagArray[Scene_Amy_FindingBirdiesFamily] = true;
			break;
		case Event_Gamma_E105Rescued:
			CutsceneFlagArray[Scene_Tails_Outro] = true;
			break;
		case Event_Final_Tornado2Crash:		
			CutsceneFlagArray[Scene_Knuck_Outro] = true;
			CutsceneFlagArray[ Scene_Amy_Outro ] = true;
			break;
	}
}

void CheckandPlayFMV()
{
	if (!isInsideStage)
	{
		switch (nextStage)
		{
		case Event_Knuck_Intro:
			MsMovie(FMV_EggCarrierAngelIsland);
			break;
		case Event_Big_Intro:
			MsMovie(FMV_AngelIslandFalling);
			break;
		case Event_Big_SearchingForFroggy:
			MsMovie(FMV_EggCarrierRising);
			break;
		case Event_Amy_MeetingBirdie:
			MsMovie(FMV_EggCarrierStationSquare);
			break;
		case Event_Sonic_Loses_Amy:
			if (!BigGameplayEnabled)
			{
				MsMovie(FMV_EggCarrierRising);
			}
			break;
		case Event_Sonic_LandsInMysticRuins:
			MsMovie(FMV_EggCarrierFalling);
			break;
		case Event_Amy_FinalBoss:
			MsMovie(FMV_AngelIslandRising);
			break;
		case Event_Final_EggmanInMysticRuins:
			MsMovie(FMV_AngelIslandFalling);
			break;
		case Sonic_Chaos7:
			MsMovie(FMV_PerfectChaos);
			break;
		}
	}
}

void SetStageInfo()
{
	if (enteredStage)
	{
		CurrentAct = stages[nextStage].act;
		isInsideStage = true;
	}
	else if (isInsideStage)
	{
		CurrentCharacter = stages[nextStage].character;
		CurrentAct = previousAct;
		isInsideStage = false;
	}
	else
	{
		CurrentCharacter = stages[nextStage].character;
		CurrentAct = stages[nextStage].act;
	}

	if (nextStage == Sonic_Chaos4)
	{
		PrintDebug("[Full Story] Setting Chaos 4 character\n");

		if (Chaos4Character == Chaos4Chars_Tails)
		{
			CurrentCharacter = Characters_Tails;
		}
		else if (Chaos4Character == Chaos4Chars_Knuckles)
		{
			CurrentCharacter = Characters_Knuckles;
		}
	}

	CurrentLevel = stages[nextStage].level;
	LastLevel = CurrentLevel;

	SetTimeOfDay(stages[nextStage].timeofDay);
}

void SaveGame()
{
	// Save unless inside an adventure field, during Egg Carrier Transformation or while carrying the Ice Stone
	if (!enteredStage && !isInsideStage 
		&& nextStage != Event_Knuck_EggCarrierTransforms1 && nextStage != EggCarrierTransforms
		&& nextStage != Sonic_ToIceCap && nextStage != Event_Amy_WinsHedgehogHammer
		&& nextStage != Event_Tails_MeetsTikal
		&& nextStage != Event_Sonic_SkyDeckEntrance )
	{
		SaveProgression();
	}
}

void SetStageAct(char stage, char act)
{
	if (storyComplete < 1 && GameMode != GameModes_Movie && GameMode != GameModes_Mission 
		&& GameMode != GameModes_CharSel && GameMode < GameModes_StartCredits)
	{
		PrintDebug("[Full Story] Setting stage...\n");

		if (nextStage > -1 && currentStage != nextStage)
		{
			PrintDebug("[Full Story] Fixing stage index\n");
			currentStage = nextStage;
		}

		if (storyComplete == -1)
		{
			storyComplete = 0;
			ReadConfig(true);
		}

		SetStageFromPause();

		nextStage = currentStage + 1;

		SetStageFromTriggers();
		SetStageFromSettings();
		
		currentStage = nextStage - 1;

		SaveGame();

		SetStageTriggers();
		SetStoryFlags();
		SetCutsceneFlags();
		CheckandPlayFMV();
		SetStageInfo();
		CheckandPlayCutscene();

		currentStage++;

		return;
	}

	// Trial Mode Fix
	if (storyComplete == 1)
	{
		if (GameMode == GameModes_Menu)
		{
			if (ValueMenu == 14 || ValueMenu == 238 || ValueMenu == 212 || ValueMenu == 138 || ValueMenu == 257)
				SetStageAct((char)CurrentLevel, (char)CurrentAct);
		}
	}

	return SetLevelAndAct(Uint8(stage), (Uint8)(act));
}

void GoToNextLevel_hook(char stage, char act)
{
	if (storyComplete < 1 && GameMode != GameModes_Movie && GameMode != GameModes_Mission 
		&& GameMode != GameModes_CharSel && GameMode < GameModes_StartCredits)
	{	
		if ((currentStage == Tails_ToMysticRuins && CurrentAct == StationSquare_StationArea) 
			|| (currentStage == Event_Knuck_OnTheHuntForPieces && CurrentAct == StationSquare_StationArea)
			|| (currentStage == Sonic_ToCasinopolis && CurrentAct == StationSquare_StationArea)
			|| (currentStage == Knuck_ToCasinopolis && CurrentAct == StationSquare_StationArea) 
			|| (currentStage == Sonic_ToIceCap && CurrentAct == MysticRuins_Station)
			|| (currentStage == Knuck_ToRedMountain && CurrentAct == MysticRuins_Station)
			|| (currentStage == Gamma_Betamk && !EventFlagArray[EventFlags_Gamma_E101mkIIClear]) 
			|| (currentStage == Sonic_Chaos4 && !EventFlagArray[EventFlags_Sonic_Chaos4Clear]))
		{
			PrintDebug("[Full Story] Preventing stage skip\n");
			return;
		}

		PrintDebug("[Full Story] Going to next level\n");

		return SetStageAct(stage, act);
	}

	return GoToNextLevel();
}

void PauseMenuFix()
{
	// Set gamemode to adventure when the player selects quit option, so it goes back to the title screen properly.
	if (GameMode != GameModes_Trial)
	{
		if (PauseSelection == 3)
		{
			GameMode = GameModes_Adventure_Field;
			isinsideAdventure = false;
			quitSelected = true;
		}
	}
}

void GameOver_R()
{
	quitSelected = true;
}

int LoadTitleCardTexture_r(int minDispTime)
{
	bool showTitleCard = false;

	if (stages[currentStage].displayCard || !isinsideAdventure)
	{
		showTitleCard = true;
	}

	if (currentStage == Tails_WindyValley || currentStage == Tails_Casinopolis || 
		currentStage == Tails_IceCap)
	{
		if (STLevelsCharacter == LevelsChars_Tails)
		{
			showTitleCard = true;
		}
	}

	if (currentStage == Sonic_SkyDeck)
	{
		if (STLevelsCharacter == LevelsChars_Sonic)
		{
			showTitleCard = true;
		}
	}

	if (showTitleCard)
	{
		isinsideAdventure = true;
		return LoadTitleCardTexture(minDispTime);
	}

	return 0;
}

void Init_Stages()
{
	// Hack many functions which teleport the player to the next stage.
	WriteCall((void*)0x41709d, GoToNextLevel_hook);
	WriteCall((void*)0x417b47, GoToNextLevel_hook);

	// Hook SetLevelAndAct when loading adventure data 
	WriteCall((void*)0x41348f, SetStageAct);
	WriteCall((void*)0x41342a, SetStageAct);
	WriteCall((void*)0x4134a2, SetStageAct);

	// Remove SetLevelAndAct when loading adventure data (fixes wrong warp)
	WriteData<5>((void*)0x4134f3, 0x90);
	WriteData<1>((void*)0x413502, 0x08);

	WriteCall((void*)0x417bed, GameOver_R);
	WriteCall((void*)0x41717d, GameOver_R);

	WriteJump(j_LoadTitleCardTexture, LoadTitleCardTexture_r);
}

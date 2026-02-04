#include "pch.h"

bool contains(int* a, size_t n, int x)
{
	for (size_t i = 0; i < n; i++)
		if (a[i] == x) return true;
	return false;
}

float GetDistance(NJS_VECTOR* orig, NJS_VECTOR* dest)
{
	return sqrtf(powf(dest->x - orig->x, 2) + powf(dest->y - orig->y, 2) + powf(dest->z - orig->z, 2));
}

bool IsPointInsideSphere(NJS_VECTOR* center, NJS_VECTOR* pos, float radius) 
{
	return GetDistance(center, pos) <= radius;
}

int checkIfFileExists(const char* filename)
{
	FILE* file;
	errno_t err;

	if ((err = fopen_s(&file, filename, "r")) != 0)
	{
		return 0;
	}
	else {
		fclose(file);
		return 1;
	}
}

void FlashScreen(ObjectMaster* obj) {

	EntityData1* data = obj->Data1;

	int color = 0x00000000;
	ScreenFade_Color = *(NJS_COLOR*)&color;
	int charIDValue = 0;

	if (++data->InvulnerableTime >= 55)
	{
		CheckThingButThenDeleteObject(obj);
	}
	else
	{		
		if (data->InvulnerableTime < 30)
		{
			data->CharID += 8;
		}
		else
		{
			data->CharID -= 8;
		}

		ScreenFade_Color.argb.a = data->CharID;

		//PrintDebug("[Full Story] = %d\n", (int)data->CharID);

		ScreenFade_DrawColor();
	}
}

void FadeScreen(ObjectMaster* obj) {

	EntityData1* data = obj->Data1;

	int color = 0x00000000;
	ScreenFade_Color = *(NJS_COLOR*)&color;
	int charIDValue = 0;

	if (++data->InvulnerableTime >= 85)
	{
		CheckThingButThenDeleteObject(obj);
	}
	else
	{
		if (data->InvulnerableTime < 60)
		{
			data->CharID = -8;		
		}
		else
		{
			data->CharID -= 8;
		}

		ScreenFade_Color.argb.a = data->CharID;

		//PrintDebug("[Full Story] = %d\n", (int)data->CharID);

		ScreenFade_DrawColor();
	}
}
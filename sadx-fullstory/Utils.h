#pragma once
#include "pch.h"

bool contains(int* a, size_t n, int x);
float GetDistance(NJS_VECTOR* orig, NJS_VECTOR* dest);
bool IsPointInsideSphere(NJS_VECTOR* center, NJS_VECTOR* pos, float radius);
int checkIfFileExists(const char* filename);
void FlashScreen(ObjectMaster* obj);
void FadeScreen(ObjectMaster* obj);
void SetSelectedCharacter(int charID);
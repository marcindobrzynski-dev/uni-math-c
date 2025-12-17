#pragma once

#include <stdbool.h>

#define MAX_FIRST_NAME_LENGTH 50
#define START_ACTION_NUMBER 1
#define END_ACTION_NUMBER 4

int readVectorFromUser(float** vector, int* size, int* capacity, bool isLastVector, int maxVectorLength);
void showVectorItems(const float* vector, int size, bool isLastVector);
float calculateDotProduct(const float* a, const float* b, int size);
void clearVector(void** ptr);

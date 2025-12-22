#pragma once

#include <stdbool.h>

#define MAX_FIRST_NAME_LENGTH 50
#define START_ACTION_NUMBER 1
#define END_ACTION_NUMBER 4
#define MAX_VECTOR_LENGTH 3

float* initializeBasicVector(int capacity);
int readVectorFromUser(float** vector, int* size, int* capacity, char vectorName, int maxVectorLength);
float* prepareVector(int* size, int* capacity, char vectorName, int maxVectorLength);
void showVectorItems(const float* vector, int size, char vectorName);
float calculateDotProduct(const float* a, const float* b, int size);
void clearVector(void** ptr);

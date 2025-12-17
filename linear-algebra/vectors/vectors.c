#include <stdio.h>
#include <stdlib.h>
#include "vectors.h"

int readVectorFromUser(float** vector, int* size, int* capacity, bool isLastVector, int maxVectorLength) {
	char vectorName = isLastVector ? 'b' : 'a';
	float input;

	printf("---Enter the numbers of vector %c (enter letter to end)---\n", vectorName);

	while ((maxVectorLength <= 0 || *size < maxVectorLength) &&
		printf("Number [%d]: ", *size) &&
		scanf_s("%f", &input) == 1) {
		if (*size == *capacity) {
			*capacity *= 2;
			float* temp = (float*)realloc(*vector, *capacity * sizeof(float));

			if (temp == NULL) {
				clearVector((void**)vector);

				return EXIT_FAILURE;
			}

			*vector = temp;
		}

		(*vector)[*size] = input;
		(*size)++;
	}

	while (getchar() != '\n');

	return EXIT_SUCCESS;
}

void showVectorItems(const float* vector, int size, bool isLastVector) {
	char vectorName = isLastVector ? 'b' : 'a';

	printf("\nCollected %d numbers. Your vector %c:\n", size, vectorName);
	printf("%c = [", vectorName);
	for (int i = 0; i < size; i++) {
		printf("%.2f", *(vector + i));

		if (i < size - 1) {
			printf(", ");
		}
	}
	printf("]\n");
}

float calculateDotProduct(const float* a, const float* b, int size) {
	float result = 0.0f;

	for (int i = 0; i < size; i++) {
		result += a[i] * b[i];
	}

	return result;
}

void clearVector(void** ptr) {
	if (ptr != NULL && *ptr != NULL) {
		free(*ptr);
		*ptr = NULL;
	}
}

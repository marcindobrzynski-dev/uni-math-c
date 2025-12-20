#include <stdio.h>
#include <stdlib.h>
#include "vectors.h"
#include "utils.h"

int main() {
	puts("###--- Vectors ---###");
	puts("Topic: Dot, vector and mixed product\n");

	char* firstName = (char*)malloc(MAX_FIRST_NAME_LENGTH * sizeof(char));

	if (firstName == NULL) {
		return EXIT_FAILURE;
	}

	printf("What's your name? ");
	scanf_s("%49s", firstName, MAX_FIRST_NAME_LENGTH);

	short int actionNumber = 0;

	do {
		system("cls");

		printf("Hello, %s!\n\n", firstName);

		show_menu();

		printf("Your choice: ");

		if (scanf_s("%hd", &actionNumber) != 1) {
			while (getchar() != '\n');

			actionNumber = 0;

			continue;
		}

		switch (actionNumber) {
		case 1: {
			system("cls");

			int capacity_a = 2;
			int size_a = 0;
			float* vector_a = (float*)malloc(capacity_a * sizeof(float));

			if (readVectorFromUser(&vector_a, &size_a, &capacity_a, false, 0) != EXIT_SUCCESS) {
				clearVector((void**)&vector_a);

				return EXIT_FAILURE;
			}

			printf("\n");

			int capacity_b = 2;
			int size_b = 0;
			float* vector_b = (float*)malloc(capacity_b * sizeof(float));

			if (readVectorFromUser(&vector_b, &size_b, &capacity_b, true, size_a) != EXIT_SUCCESS) {
				clearVector((void**)&vector_a);
				clearVector((void**)&vector_b);

				return EXIT_FAILURE;
			}

			showVectorItems(vector_a, size_a, false);
			showVectorItems(vector_b, size_b, true);

			if (size_a == size_b) {
				float result = calculateDotProduct(vector_a, vector_b, size_a);
				printf("\nThe scalar product of vectors a and b = %.2f\n\n", result);
			}
			else {
				puts("\nError: Vectors must have the same length!");
			}

			clearVector((void**)&vector_a);
			clearVector((void**)&vector_b);

			system("pause");

			break;
		}
		case 2: {
			system("cls");

			int vector_length = 3;

			int size_a = 0;
			int capacity_a = 2;
			float* vector_a = (float*)malloc(vector_length * sizeof(float));

			if (readVectorFromUser(&vector_a, &size_a, &capacity_a, false, vector_length) != EXIT_SUCCESS) {
				clearVector(&vector_a);

				return EXIT_FAILURE;
			}

			printf("\n");

			int size_b = 0;
			int capacity_b = 2;
			float* vector_b = (float*)malloc(vector_length * sizeof(float));

			if (readVectorFromUser(&vector_b, &size_b, &capacity_b, false, vector_length) != EXIT_SUCCESS) {
				clearVector(&vector_a);
				clearVector(&vector_b);

				return EXIT_FAILURE;
			}

			if (size_a == 3 && size_b == 3) {
				float result_a = (vector_a[1] * vector_b[2]) - (vector_a[2] * vector_b[1]);
				float result_b = -((vector_a[0] * vector_b[2]) - (vector_a[2] * vector_b[0]));
				float result_c = (vector_a[0] * vector_b[1]) - (vector_a[1] * vector_b[0]);

				printf("\nThe cross product of vectors a and b = [%.2f, %.2f, %.2f]\n\n", result_a, result_b, result_c);
			}
			else {
				printf("\nThe cross product requires exactly 3 coordinates!\n\n");
			}

			clearVector((void**)&vector_a);
			clearVector((void**)&vector_b);

			system("pause");

			break;
		}
		case 3: {
			break;
		}
		case 4: {
			printf("\nExiting program... Goodbye % s!\n", firstName);

			break;
		}
		default: {
			puts("Invalid option! Try again.");

			system("pause");

			break;
		}
		}
	} while (actionNumber != 4);

	clearVector((void**)&firstName);

	return EXIT_SUCCESS;
}

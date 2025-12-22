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

			int capacity_a = 2, size_a = 0;
			float* vector_a = prepareVector(&size_a, &capacity_a, 'a', 0);

			printf("\n");

			int capacity_b = 2, size_b = 0;
			float* vector_b = prepareVector(&size_b, &capacity_b, 'b', size_a);

			showVectorItems(vector_a, size_a, 'a');
			showVectorItems(vector_b, size_b, 'b');

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

			int size_a = 0, capacity_a = 2;
			float* vector_a = prepareVector(&size_a, &capacity_a, 'a', MAX_VECTOR_LENGTH);

			printf("\n");

			int size_b = 0, capacity_b = 2;
			float* vector_b = prepareVector(&size_b, &capacity_b, 'b', MAX_VECTOR_LENGTH);

			showVectorItems(vector_a, size_a, 'a');
			showVectorItems(vector_b, size_b, 'b');

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
			system("cls");

			int capacity_a = 2, size_a = 0;
			float* vector_a = prepareVector(&size_a, &capacity_a, 'a', MAX_VECTOR_LENGTH);

			printf("\n");

			int capacity_b = 2, size_b = 0;
			float* vector_b = prepareVector(&size_b, &capacity_b, 'b', MAX_VECTOR_LENGTH);

			printf("\n");

			int capacity_c = 2, size_c = 0;
			float* vector_c = prepareVector(&size_c, &capacity_c, 'c', MAX_VECTOR_LENGTH);

			showVectorItems(vector_a, size_a, 'a');
			showVectorItems(vector_b, size_b, 'b');
			showVectorItems(vector_c, size_c, 'c');

			if (size_a == 3 && size_b == 3 && size_c == 3) {
				float result =
					vector_a[0] * vector_b[1] * vector_c[2] +
					vector_a[1] * vector_b[2] * vector_c[0] +
					vector_a[2] * vector_b[0] * vector_c[1] -
					(vector_a[1] * vector_b[0] * vector_c[2] +
					vector_a[0] * vector_b[2] * vector_c[1] +
					vector_a[2] * vector_b[1] * vector_c[0]);

				printf("\nThe mixed product of vectors a, b, c = %.2f\n\n", result);
			}
			else {
				printf("\nThe mixed product requires exactly 3 coordinates!\n\n");
			}

			clearVector((void**)&vector_a);
			clearVector((void**)&vector_b);
			clearVector((void**)&vector_c);

			system("pause");

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

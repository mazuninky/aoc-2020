#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

#define CAPACITY_INCREMENT 5

typedef struct vector_struct {
	int size;
	int capacity;
	int * items;
} Vector;

Vector * vector_create(int capacity) {
	Vector * vector = malloc(sizeof(Vector));
	vector->items = malloc(sizeof(int) * capacity);
	vector->size = 0;
	vector->capacity = capacity;
	return vector;
}

int vector_get(Vector * vector, int position) {
	return vector->items[position];
}

void vector_add(Vector * vector, int item) {
	if(vector->capacity == vector->size) {
		vector->capacity += CAPACITY_INCREMENT;
		vector->items = realloc(vector->items, vector->capacity * sizeof(int));
	}

	vector->items[vector->size] = item;
	vector->size += 1;
}

void free_vector(Vector * vector) {
	free(vector->items);
	free(vector);
}

#define free_resources_part() free(line); fclose(stream); free(number_mask); free_vector(vector);

int main() {
	char const* const fileName = "input.txt";
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

    stream = fopen(fileName, "r");
	if(stream == NULL) {
		printf("Can't open the file %s\n", fileName);   
		return EXIT_FAILURE;
	}

	long number;
	char *end;
	int offset;
	Vector * vector = vector_create(50);
	bool * number_mask = calloc(2020, sizeof(bool));
 	while ((nread = getline(&line, &len, stream)) != -1) {
		errno = 0;
		
		number = strtol(line, &end, 10);
		if(errno == ERANGE) {
			printf("Error during read number from %s\n", fileName);
			free_resources_part()
			return EXIT_FAILURE;
		}

		vector_add(vector, number);	
		number_mask[number] = true;
	}

	int length = vector->size;
	int offest;
	for(int i = 0; i < length; ++i) {
		for(int j = 0; j < length - i; ++j) {
			if(i == j) {
				continue;
			}

			offest = 2020 - vector_get(vector, i) - vector_get(vector, j);
			if(offest > 0 && number_mask[offest]) {
				printf("Answer is %d\n", vector_get(vector, i) * vector_get(vector, j) * offest);
				free_resources_part();
				return EXIT_SUCCESS;
			}
		}
	}

	printf("Can't find a answer\n");
	free_resources_part()
    return EXIT_SUCCESS;
}
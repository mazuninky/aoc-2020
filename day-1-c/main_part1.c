#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define free_resources() free(line); fclose(stream); free(offset_vector);

// O(N)
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
	
	int * offset_vector = calloc(1010, sizeof(int));
	if(offset_vector == NULL) {
		printf("Error during memmory allocation for offset_vector\n");
		free(line); 
		fclose(stream);
		return EXIT_FAILURE;
	}

	long number;
	char *end;
	int offset;
 	while ((nread = getline(&line, &len, stream)) != -1) {
		errno = 0;
		
		number = strtol(line, &end, 10);
		if(errno == ERANGE) {
			printf("Error during read number from %s\n", fileName);
			free_resources()
			return EXIT_FAILURE;
		}

		// Business logic
		offset = labs(1010 - number);
		offset_vector[offset] += 1;
		if(offset_vector[offset] == 2) {
			printf("Answer is %i\n", (1010 - offset) * (1010 + offset));
			free_resources()
			return EXIT_SUCCESS;
		}
	}

	printf("Can't find a answer\n");
	free_resources()
    return EXIT_SUCCESS;
}
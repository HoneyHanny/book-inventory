#include <stdio.h>

#include "file.h"

int Write(Book* books, int n) {
	FILE* fptr = fopen("data.txt", "w");
	if (fptr == NULL) {
		// perror("Error opening data.txt file.\n");
		// fprintf(stderr, "Error opening data.txt file.\n", 20);
		printf("Error opening data.txt file.\n");
		return 1;
	}

	fwrite(books, sizeof(Book), n, fptr);

	fclose(fptr);
	return 0;
}

int Read(Book* books, int* n) {
	FILE* fptr = fopen("data.txt", "r");
	if (fptr == NULL) {
		// perror("Error opening data.txt file.\n");
		// fprintf(stderr, "Error opening data.txt file.\n", 20);
		printf("Error opening data.txt file.\n");
		return 1;
	}
	*n = 0;

	fread(books, sizeof(Book), *n, fptr);

	fclose(fptr);
	return 0;
}

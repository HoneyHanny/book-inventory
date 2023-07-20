#include <stdio.h>
#include <stdlib.h>

#include "result.h"

int Compare(const void* a, const void* b) {
	return ((Book*)a)->rank - ((Book*)b)->rank;
}

void InitResults(Result* results, int n) {
	for (int i = 0; i < n; i++)
		results[i] = { 0, NULL };
}

void RankResults(Result* results, int n) {
	if (results == NULL)
		return;
	
	qsort(results, n, sizeof(Result), Compare);
}

void DisplayResults(Results* results, int n) {
	printf("ID\tTitle\tGenre\tAuthor");
	for (int i = 0; i < n; i++) {
		printf("%d\t%s\t%s\t%s",
			   results[i].id,
			   results[i].title,
			   results[i].genre,
			   results[i].author);
	}
}

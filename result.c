#include <stdlib.h>

#include "results.h"

int Compare(const void* a, const void* b) {
	return (*(Result*)b.rank - *(Result*)a.rank);
}

void InitResults(Result* results, int n) {
	for (int i = 0; i < n; i++) {
		results[i].rank = 0;
		results[i].book = NULL;
	}
}

void RankResults(Result* results, int n) {
	if (results == NULL)
		return;

	qsort(results, n, sizeof(Result), Compare);
}

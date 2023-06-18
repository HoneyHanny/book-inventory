#include <stdlib.h>

#include "result.h"

int Compare(const void* a, const void* b) {
	return (*(Result*)a.rank - *(Result*)a.rank);
}

void RankResults(Result results[5]) {
	if (results == NULL)
		return;

	qsort(results, 5, sizeof(Result), Compare);
}

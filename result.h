#ifndef RESULT_H
#define RESULT_H

#include "book.h"

#define MAX_RESULTS 10

typedef struct tResult {
	int rank;
	Book* book;
} Result;

int Compare(const void* a, const void* b);
void InitResults(Result* results, int n);
void RankResults(Result* results, int n);
void DisplayResults(Result* results, int n);

#endif // RESULT_H

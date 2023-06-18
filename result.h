#ifndef RESULT_H
#define RESULT_H

typedef struct {
	int rank;
	Book* book;
} Result;

int Compare(const void* a, const void* b);
void InitResults(Result* results, int n);
void RankResults(Result results[5]);

#endif // RESULT_H

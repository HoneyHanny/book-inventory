#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <conio.h>
#include <windows.h>

#include "tools.h"
#include "book.h"
#include "list.h"

// void Gotoxy(int x, int y) {
// 	COORD coord;
// 	coord.X = x;
// 	coord.Y = y;
// 	// SetConsoleCursorPosition(GetConsoleInstance(), coord);
// }

// void Getoxy(int* x, int* y) {
// 	
// }

void DisplayMainMenu() {
	printf("Book Management System\n");
	printf("[1] Add Book\n");
	printf("[2] Remove Book\n");
	printf("[3] Update Book\n");
	printf("[4] View Library\n");
	printf("[5] Search Book\n");
	printf("[6] Exit\n");
}

void RemoveElement(void* arr, int count, int index, int size) {
	if (index < 0 || index >= count)
		return;

	char* ptr = (char*)arr + (index * size);

	for (int i = index; i < count - 1; i++) {
		char* current = (char*)arr + (i * size);
        char* next = (char*)arr + ((i + 1) * size);
        memcpy(current, next, size);
	}
}

char* MallocString(char* str) {
	char* newStr = (char*)malloc(sizeof(char) * (strlen(str)));
	strcpy(newStr, str);
	return newStr;
}

char ChooseOption(int count) {
	int optInt;
	char optChar;

	do {
		optChar = getch();
		optInt = optChar - '0';
	} while (optInt > count || optInt < 1);

	return optChar;
}

char* EnterString() {
	char str[MAX_STR_LEN];
	scanf("%s", str);
	return MallocString(str);
}

void DisplayLibrary(List* list) {
	printf("ID\tTitle\tAuthor\tGenre\n");
	Book* books = GetAllBooks(&(*list));
	for (int i = 0; i < list->count; i++)
		printf("%d\t%s\t%s\t%s\n",
			   books[i].id,
			   books[i].title,
			   books[i].author,
			   books[i].genre);
	free(books);
}

// TODO: (6/15/2023 7:18:28 PM) Use exact and partial match algorithm
// ChatGPT Link: https://chat.openai.com/share/c1b63ebb-df83-4354-bd88-0134c7bb3d85
// Youtube Link: https://www.youtube.com/watch?v=cCdn7Cy6TfE
// cpp reference website
Result* SearchBook(List* list, char* search) {
	int count = 0;
	int tokCount = 0;
	int n = list->count;

	char* delimiters = " ,.-/\\";
	char searchcpy[100];
	char* token;
	char tokens[100][100];
	strcpy(searchcpy, search);

	Result tempResult = {
		0,
		NULL
	};

	Book* books = GetAllBooks(&(*list));
	Result* results = (Result*)malloc(sizeof(Result) * MAX_RESULTS);
	InitResults(results, MAX_RESULTS);

	// search top MAX_RESULTS
	// display max MAX_RESULTS

	// tokenizer
	// strtok();
	
	token = strtok(searchcpy, delimiters);
	strcpy(tokens[tokCount], token);
	tokCount++;
	while (token != NULL) {
		printf(" %s \n", token);
		token = strtok(NULL, delimiters);
		strcpy(tokens[tokCount], token);
		tokCount++;
	}

	// +-----------+
	// |   TITLE   |
	// +-----------+
	
	// exact
	// strcmp();
	for (int i = 0; i < n; i++) {
		if (strcmp(books[i].title, search)) {
			results[count].book = &books[i];
			results[count].rank = INT_MAX;
			count++;
			RemoveElement(books, list->count, i, sizeof(Book));
			n--;
			i--;
			if (count == MAX_RESULTS)
				goto fetchFinished;
		}
	}

	// partial
	// strstr();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < tokCount; j++) {
			if (strstr(books[i].title, tokens[j]) != NULL) {
				if (tempResult.book == NULL)
					tempResult.book = &books[i];
				tempResult.rank += 5;
			}
		}
		if (tempResult.book != NULL) {
			RemoveElement(books, list->count, i, sizeof(Book));
			n--;
			i--;
			results[count] = tempResult;
			count++;
			if (count == MAX_RESULTS)
				goto fetchFinished;
		}
		tempResult.rank = 0;
		tempResult.book = NULL;
	}

	// +------------+
	// |   AUTHOR   |
	// +------------+
	
	// exact
	// strcmp();
	tempResult.rank = 0;
	tempResult.book = NULL;

	for (int i = 0; i < n; i++) {
		if (strcmp(books[i].author, search)) {
			results[count].book = &books[i];
			results[count].rank = INT_MAX;
			count++;
			RemoveElement(books, list->count, i, sizeof(Book));
			n--;
			i--;
			if (count == MAX_RESULTS)
				goto fetchFinished;
		}
	}
	
	// partial
	// strstr();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < tokCount; j++) {
			if (strstr(books[i].author, tokens[j]) != NULL) {
				if (tempResult.book == NULL)
					tempResult.book = &books[i];
				tempResult.rank += 5;
			}
		}
		if (tempResult.book != NULL) {
			RemoveElement(books, list->count, i, sizeof(Book));
			n--;
			i--;
			results[count] = tempResult;
			count++;
			if (count == MAX_RESULTS)
				goto fetchFinished;
		}
		tempResult.rank = 0;
		tempResult.book = NULL;
	}

fetchFinished:
	RankResults(results, MAX_RESULTS);
	free(books);

	return results;
}

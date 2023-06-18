#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "result.h"
#include "tools.h"
#include "book.h"

void DisplayMainMenu() {
	printf("Book Management System\n");
	printf("[1] Add Book\n");
	printf("[2] Remove Book\n");
	printf("[3] Update Book\n");
	printf("[4] View Library\n");
	printf("[5] Search Book\n");
	printf("[6] Search Author\n");
	printf("[7] Exit\n");
}

char ChooseOption(int count) {
	int optInt;
	char optChar;

	do {
		optChar = getch();
		optInt = optChar - '0';
	} while (optInt > count && optInt < 1);

	return optChar;
}

void DisplayLibrary(List* list) {
	printf("ID\tTitle\tAuthor\tGenre\n");
	Book* books = GetAllBooks(&(*list));
	for (int i = 0; i < list->count; i++)
		printf("%d\t%s\t%s\t%s\n",
			   books[i]->id,
			   books[i]->title,
			   books[i]->author,
			   books[i]->genre);
	free(books);
}

// TODO: (6/15/2023 7:18:28 PM) Use exact and partial match algorithm
// ChatGPT Link: https://chat.openai.com/share/c1b63ebb-df83-4354-bd88-0134c7bb3d85
// cpp reference website
void SearchBook(List* list, char* search) {
	int count = 0;
	int tokCount = 0;

	Book* books = GetAllBooks(&(*list));
	Result results[5];
	InitResults(results, 5);

	// search top 5
	// display max 5

	// delimiter
	// ,.-
	// tokenizer
	// strtok();

	char* delimiters = " ,.-";
	char* searchpy;
	strcpy(searchcpy, search);

	char* token = strtok(searchcpy, delimiter);
	tokCount++;
	while (token != NULL) {
		printf(" %s \n", token);
		token = strtok(NULL, delimiter);
		tokCount++;
	}
	
	// exact
	// strcmp();
	for (int i = 0; i < list->count; i++) {
		if (strcmp(books[i]->title, search)) {
			results[count].book = &books[i];
			results[count].rank = INT_MAX;
			count++;
		}
	}

	// partial
	// strstr();
	Result tempResult = {
		rank = 0;
		book = NULL;
	};

	for (int i = 0; i < list->count; i++) {
		for (int j = 0; j < tokCount; j++) {
			if (strstr(book[i].title, tokens[j]) != NULL) {
				if (book == NULL)
					tempResult.book = &book[i];
				tempResult.rank += 5;
			}
		}
	}

	// rank and move to results
	// move books to results
	// highest rank : first index
	// print results

	RankResults(results, 5);
	free(books);

	// return results as:
	// results list struct?
	// pointer?
}

#ifndef BOOK_H
#define BOOK_H

#include "tools.h"

#define EMPTY_BOOK -1

typedef struct tList List;

typedef struct tBook {
	int id;
	char title[MAX_STR_LEN];
	char author[MAX_STR_LEN];
	char genre[MAX_STR_LEN];
} Book;

Book* NewBook();
void AddBook(List* list, Book book);
void RemoveBook(List* list, int id);
void UpdateBook(List* list, int id, Book updatedBook);
Book GetBook(List* list, int id);
Book* GetAllBooks(List* list);

#endif // BOOK_H

#ifndef BOOK_H
#define BOOK_H

typedef struct {
	int id
	char title[100];
	char author[100];
	char genre[100];
} Book;

Book* NewBook();
void AddBook(List* list, Book book);
void RemoveBook(List* list, int id);
void UpdateBook(List* list, int id);
Book GetBook(List* list, int id);
Book* GetAllBooks(List* list);

#endif // BOOK_H

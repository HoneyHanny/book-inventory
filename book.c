#include <stdlib.h>

#include "book.h"
#include "list.h"

Book* NewBook() {
	return (Book)malloc(sizeof(Book));
}

void AddBook(List* list, Book book) {
	Add(&(*list), NewNode(book));
}

void RemoveBook(List* list, int id) {
	Remove(&(*list), id);
}

void UpdateBook(List* list, int id, Book updatedBook) {
	Update(&(*list), id, updatedBook);
}

Book GetBook(List* list, int id) {
	return Get(&(*list), id);
}

Book* GetAllBooks(List* list) {
	return GetAll(&(*list));
}

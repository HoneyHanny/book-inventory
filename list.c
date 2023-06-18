#include <stdlib.h>

#include "list.h"

Node* CheckId(List* list, int id) {
	Node* temp = list->head;
	while (temp != NULL)
		if (temp->id == id)
			return temp;
	return NULL;
}

void Add(List* list, Node* node) {
	list->tail->next = node;
	list->tail = node;
	list->count++;
}

void Remove(List* list, int id) {
	Node* node = Get(&(*list), id);
	Node* temp = list->head;
	while (temp != NULL) {
		if (node == temp) {

			if (temp == list->head) {
				list->head = temp->next;
				if (list->head != NULL)
					list->head->prev = NULL;
			} else if (temp == list->tail) {
				list->tail = temp->prev;
				if (list->tail != NULL)
					list->tail->next = NULL;
			} else {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}

			list->count--;
			free(temp);
			break;
		}
	}
}

void Update(List* list, int id, Book updatedBook) {
	Node* temp = list->head;
	while (temp != NULL)
		if (id == temp->id)
			temp->book = updatedBook;
}

Book Get(List* list, int id) {
	Node* temp = list->head;
	while (temp != NULL)
		if (id == temp->id)
			return temp->book;
	return NULL;
}

Book* GetAll(List* list, Node node) {
	if (list->count = 0)
		return NULL;
	Book* books = (Book*)calloc(list->count, sizeof(Book));
	Node* temp = list->head;
	for (int i = 0; temp != NULL; i++)
		books[i] = temp->book;
	return books;
}

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "book.h"
#include "list.h"
#include "node.h"
#include "file.h"

Node* CheckId(List* list, int id) {
	Node* temp = list->head;
	while (temp != NULL)
		if (temp->book.id == id)
			return temp;
	return NULL;
}

// TODO: (6/21/2023 12:34:16 PM) Add file handling
void Add(List* list, Node* node) {
	if (list->count == 0) {
		list->head = node;
		list->tail = node;
		list->count++;
		return;
	}

	list->tail->next = node;
	list->tail = node;
	list->count++;
	Write(GetAll(list), list->count);
}

void Remove(List* list, int id) {
	Book book = Get(list, id);

	if (book.id == -1)
		return;

	Node* temp = list->head;
	while (temp != NULL) {
		if (book.id == temp->book.id) {
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

	Write(GetAll(list), list->count);
}

void Update(List* list, int id, Book updatedBook) {
	Node* temp = list->head;
	Book book = Get(list, id);
	if (book.id == -1)
		return;
	while (temp != NULL)
		if (id == temp->book.id)
			temp->book = updatedBook;

	Write(GetAll(list), list->count);
}

Book Get(List* list, int id) {
	Node* temp = list->head;
	while (temp != NULL)
		if (id == temp->book.id)
			return temp->book;
	return (Book){ -1, "", "", "" };
}

Book* GetAll(List* list) {
	if (list->count == 0)
		return NULL;
	Book* books = (Book*)calloc(list->count, sizeof(Book));
	Node* temp = list->head;
	for (int i = 0; temp != NULL; i++) {
		books[i] = temp->book;
		temp = temp->next;
	}
	return books;
}

// makes the array into list
void ToList(List* list, Book* books, int n) {
	if (books == NULL || list == NULL || n == 0)
		return;

	for (int i = 0; i < n; i++) {
		Node* newNode = NewNode(books[i]);
	
		if (i == 0)
			list->head = newNode;
		else
			Add(list, newNode);
	}
}

List* MakeList(Book* books, int n) {
	if (books == NULL || n == 0)
		return NULL;

	List* list = (List*)malloc(sizeof(List));
	

	for (int i = 0; i < n; i++) {
		Node* newNode = NewNode(books[i]);

		if (i == 0)
			list->head = newNode;
		else
			Add(list, newNode);
	}
}

#ifndef LIST_H
#define LIST_H

#include "node.h"

typedef struct {
	Book* head;
	Book* tail;
	int count;
} List;

Node* CheckId(List* list, int id);
void Add(List* list, Node* node);
void Remove(List* list, int id);
void Update(List* list, int id, Book updatedBook);
Book Get(List* list, int id);
Book* GetAll(List* list);

#endif // LIST_H

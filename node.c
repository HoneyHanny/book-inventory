#include <stdlib.h>
#include "node.h"

Node* NewNode(Book book) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->book = book;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

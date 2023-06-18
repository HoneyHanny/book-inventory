#include <stdlib.h>
#include "node.h"

Node* NewNode(Book book) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->rpev = NULL;
	return newNode;
}

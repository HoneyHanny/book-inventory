#ifndef NODE_H
#define NODE_H

#include "book.h"

typedef struct tNode {
	Book book;
	struct tNode* next;
	struct tNode* prev;
} Node;

Node* NewNode(Book book);

#endif // NODE_H

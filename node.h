#ifndef NODE_H
#define NODE_H

typedef struct {
	Book book;
	Node* next;
	Node* prev;
} Node;

Node NewNode(Book book);

#endif // NODE_H

#ifndef LIST_H
#define LIST_H

typedef struct tNode Node;
typedef struct tBook Book;

typedef struct tList {
	Node* head;
	Node* tail;
	int count;
} List;

Node* CheckId(List* list, int id);
void Add(List* list, Node* node);
void Remove(List* list, int id);
void Update(List* list, int id, Book updatedBook);
Book Get(List* list, int id);
Book* GetAll(List* list);
void ToList(List* list, Book* books, int n);
List* MakeList(Book* books, int n);

#endif // LIST_H

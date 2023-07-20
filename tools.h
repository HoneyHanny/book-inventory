#ifndef TOOLS_H
#define TOOLS_H

#define MAX_STR_LEN 100

#include "list.h"
#include "result.h"

typedef struct tResult Result;

// void Gotoxy(int x, int y);
// void Getoxy(int* x, int* y);
void DisplayMainMenu();
void RemoveElement(void* arr, int count, int index, int size);
char* MallocString(char* str);
char ChooseOption(int count);
char* EnterString();
void DisplayLibrary(List* list);
Result* SearchBook(List* list, char* search);

#endif // TOOLS_H

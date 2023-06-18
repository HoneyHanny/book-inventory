#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "book.h"
#include "tools.h"

int main(void) {

	char opt;
	List list = {
		head = NULL;
		tail = NULL;
		count = 0;
	};

	unsigned char running = 0;
	while (running) {
		DisplayMainMenu();
		opt = ChooseOption(6);

		switch (opt) {
			case '1':
				Book book;
				printf("Enter book details:\n");
				printf("Title: ");
				scanf("%s", &book.title);
				printf("Author: ");
				scanf("%s", &book.author);
				printf("Genre: ");
				scanf("%s", &book.genre);

				AddBook(&list, book);
				break;

			case '2':
				int id;
				printf("Enter book id: ");
				printf("%d", &id);
				RemoveBook(&list, id);	
				break;

			case '3':
				int id;
				printf("Enter book id: ");
				printf("%d", &id);
				UpdateBook(&list, id);	
				break;

			case '4':
				DisplayLibrary(&list);
				break;

			case '5':
				// search book
				break;

			case '6':
				// search author
				break;

			case '7':
				running = 1;	
				break;
		}
	}

	return 0;
}

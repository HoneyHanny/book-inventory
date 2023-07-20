#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "file.h"
#include "result.h"
#include "list.h"
#include "book.h"
#include "tools.h"


// TODO: (7/13/2023 7:31:11 PM) add symbols in telescope
// https://github.com/nvim-telescope/telescope-symbols.nvim

int main(void) {

	// TODO: (7/13/2023 3:28:22 PM) make randomizer for id
	srand(time(0));

	// TODO: (6/21/2023 11:16:28 PM) read from file and add to list
	
	Book book, updatedBook;
	int id;
	char* search = NULL;
	char opt;
	List list = {
		NULL,
		NULL,
		0
	};
	Book* readBooks = NULL;
	Result* results = NULL;
	int running = 1;

	if (!Read(readBooks, &list.count))
		ToList(&list, readBooks, list.count);
	
	while (running) {
		DisplayMainMenu();
		opt = ChooseOption(6);

		switch (opt) {
			case '1':
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
				id = 0;
				printf("Enter book id: ");
				scanf("%d", &id);
				RemoveBook(&list, id);	
				break;

			case '3':
				id = 0;
				printf("Enter book id: ");
				scanf("%d", &id);
				UpdateBook(&list, id, updatedBook);	
				break;

			case '4':
				DisplayLibrary(&list);
				break;

			case '5':
				// search book
				search = EnterString();
				results = SearchBook(&list, search);
				DisplayResults(results, MAX_RESULTS);
				free(results);
				free(search);
				break;

			case '6':
				printf("Exiting...\n");
				running = 0;	
				break;
		}
	}

	return 0;
}

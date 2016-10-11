/*
 * main.c
 * Main program code
 *
 * Interactively asks for a command, then appropriate argument
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "trie.h"
#include "input.h"

int main(void){
	// Head of trie
	trie* head;
	head = NULL;

	char* option;

	// Continue until user types in quit
	while(true){

		// Ask for option
		free(option);
		printf("add, search, or delete: ");
		option = getString();

		// add
		if(strcmp(option, "add") == 0){
			printf("Word to add: ");
			char* word;
			word = getString();
			// Add the word; inform user if the word could not
			// be added
			if(add(word, &head) < 0){
				printf("Could not add word.\n");
			}
			free(word);
		}

		// search
		else if(strcmp(option, "search") == 0){
			printf("Word to search: ");
			char* word;
			word = getString();
			// Search for the word
			if(search(word, head)){
				printf("Word was found.\n");
			}
			else{
				printf("Word was not found.\n");
			}
			free(word);
		}

		// delete
		else if(strcmp(option, "delete") == 0){
			printf("Word to delete: ");
			char* word;
			word = getString();

			// Check if the word exists
			if(!(search(word, head))){
				printf("Word not in tree.\n");
			}
			else{
				delete(word, &head);
			}
			free(word);
		}

		// list
		else if(strcmp(option, "list") == 0){
			list(head);
		}

		// clear
		else if(strcmp(option, "clear") == 0){
			cleartrie(&head);
		}
		
		// quit
		else if(strcmp(option, "quit") == 0){
			printf("Exiting...\n");
			break;
		}

		// invalid option
		else{
			printf("Invalid option\n");
		}
	}

	free(option);
	cleartrie(&head);

	return 0;
}

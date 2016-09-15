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

int main(void){
	// Head of trie
	trie* head;
	head = NULL;

	char option[7];

	// Continue until user types in quit
	while(true){

		// Ask for option
		printf("add, search, or delete: ");
		scanf("%s", option);

		// add
		if(strcmp(option, "add") == 0){
			printf("Word to add: ");
			char word[100];
			scanf("%s", word);

			// Add the word; inform user if the word could not
			// be added
			if(add(word, &head) < 0){
				printf("Could not add word.\n");
			}
		}

		// search
		else if(strcmp(option, "search") == 0){
			printf("Word to search: ");
			char word[100];
			scanf("%s", word);

			// Search for the word
			if(search(word, head)){
				printf("Word was found.\n");
			}
			else{
				printf("Word was not found.\n");
			}
		}

		// delete
		else if(strcmp(option, "delete") == 0){
			printf("Word to delete: ");
			char word[100];
			scanf("%s", word);

			// Check if the word exists
			if(!(search(word, head))){
				printf("Word not in tree.\n");
			}
			else{
				delete(word, &head);
			}
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

	cleartrie(&head);

	return 0;
}

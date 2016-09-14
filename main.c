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
	// Make head of trie
	trie* head = malloc(sizeof(trie));
	if(head == NULL){
		printf("Could not allocate memory. Exiting...\n");
		return(1);
	}

	// Initialize values in head
	for(int i = 0; i < 26; i++){
		head->letter[i] = NULL;
	}
	head->isWord = false;

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
			if(add(word, head) < 0){
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

	free(head);

	return 0;
}

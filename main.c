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

	while(true){
		printf("add or search: ");
		scanf("%s", option);

		if(strcmp(option, "add") == 0){
			printf("Word to add: ");
			char word[100];
			scanf("%s", word);
			add(word, head);
		}
		else if(strcmp(option, "search") == 0){
			printf("Word to search: ");
			char word[100];
			scanf("%s", word);
			search(word, head);
		}
		else if(strcmp(option, "quit") == 0){
			printf("Exiting...\n");
			break;
		}
		else{
			printf("Invalid option\n");
		}
	}

	free(head);

	return 0;
}

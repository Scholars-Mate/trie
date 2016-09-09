/*
 * trie.c
 *
 * Includes functions for manipulating the trie
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trie.h"

int add(char* word, trie* head){
	// Traversal pointer
	trie* trav = head;

	// Legnth of string
	int length = strlen(word);

	// Iterate through each letter in word
	for(int i = 0; i < length; i++){
		// Convert character to array index
		int ai = tolower(word[i]) - 'a';

		// If the letter does not have a pointer
		if(trav->letter[ai] == NULL){

			// Give the letter a pointer, check that memory was
			// allocated, move trav to the new trie, and initialize
			// values to NULL and false
			trav->letter[ai] = malloc(sizeof(trie));
			if(trav->letter[ai] == NULL){
				printf("Could not allocate memory.\n");
				return(-1);
			}
			trav = trav->letter[ai];
			for(int k = 0; k < 26; k++){
				trav->letter[k] = NULL;
			}
			trav->isWord = false;
		}

		// Otherwise, move trav to the next trie
		else{
			trav = trav->letter[ai];
		}
	}

	// Should be at the last trie, set isWord to true
	trav->isWord = true;

	// Return number of characters in word
	return(length);
}

void search(char* word, trie* head){
	//TODO
}

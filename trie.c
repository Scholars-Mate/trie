/*
 * trie.c
 *
 * Includes functions for manipulating the trie
 */ 

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trie.h"

/*
 * This function will a word to the trie indicated by head
 * On success, it will return the length of the word
 * Else, it will return a negative value
 */
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

/*
 * This function will search the trie for the word
 * If found, it will return true (1)
 * Else, it will return false (0)
 */
int search(char* word, trie* head){
	// Traversal pointer
	trie* trav = head;

	// Length of word
	int length = strlen(word);

	// Iterate through each letter in word
	for(int i = 0; i < length; i++){

		// Convert letter to array index
		int ai = tolower(word[i]) - 'a';

		// If the pointer is NULL, the word does is not in trie
		if(trav->letter[ai] == NULL){
			return(false);
		}

		// Otherwise, move trav to the next trie
		trav = trav->letter[ai];
	}

	// Should be at end of word, check if "isWord" is true
	if(trav->isWord){
		return(true);
	}
	else{
		return(false);
	}
}

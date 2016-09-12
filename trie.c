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

/*
 * Function to delete word from trie
 * Return values are currently for internal use.
 * -1 denotes that the pointer should be set to NULL
 * -2 denotes that the pointer should be left untouched
 */
int delete(char* word, trie* head){
	// Length of word
	int length = strlen(word);

	// Check for end of word
	if(length == 0){
		for(int i = 0; i < 26; i++){

			// If there are more words branching off this trie,
			// we cannot remove this node
			if(head->letter[i] != NULL){
				head->isWord = false;
				return(-2);
			}
		}
		
		// Otherwise, free the head, and signal that the pointer should
		// be set to NULL
		free(head);
		return(-1);
	}
	else{
		// Recursively call delete with new arguments
		char newword[length];
		for(int i = 0; i < length; i++){
			newword[i] = word[i + 1];
		}
		trie* newhead = head->letter[(tolower(word[0]) - 'a')];
		if(delete(newword, newhead) == -1){
			head->letter[(tolower(word[0]) - 'a')] = NULL;
		}
	}

	// Cannot remove node if there are other words branching from here
	for(int i = 0; i < 26; i++){
		if(head->letter[i] != NULL){
			return(-2);
		}
	}

	// Cannot remove node if it is used to signal presence of word
	if(head->isWord){
		return(-2);
	}

	// Otherwise, remove the node and signal that the pointer should be set
	// to NULL
	free(head);
	return(-1);
}	

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

/*
 * This function will a word to the trie indicated by head
 * On success, it will return the length of the word
 * Else, it will return a negative value
 */
int add(char* word, trie** head){
	// Check for NULL pointer
	if(*head == NULL){
		*head = calloc(1, sizeof(trie));
		if(*head == NULL){
			return(-1);
		}
	}

	// Traversal pointer
	trie* trav = *head;

	// Legnth of string
	int length = strlen(word);

	// Iterate through each letter in word
	for(int i = 0; i < length; i++){
		// Convert character to array index
		int ai = tolower(word[i]) - 'a';

		// If the letter does not have a pointer
		if(trav->letter[ai] == NULL){
			// Give the letter a pointer, check that memory was
			// allocated, and move trav to the new trie
			trav->letter[ai] = calloc(1, sizeof(trie));
			if(trav->letter[ai] == NULL){
				return(-1);
			}
			trav = trav->letter[ai];
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
	// Check if head is a NULL pointer
	if(head == NULL){
		return(false);
	}

	// Length of word
	int length = strlen(word);

	// Iterate through each letter in word
	for(int i = 0; i < length; i++){

		// Convert letter to array index
		int ai = tolower(word[i]) - 'a';

		// If the pointer is NULL, the word does is not in trie
		if(head->letter[ai] == NULL){
			return(false);
		}

		// Otherwise, move head to the next trie
		head = head->letter[ai];
	}

	// Should be at end of word, check if "isWord" is true
	if(head->isWord){
		return(true);
	}
	else{
		return(false);
	}
}

/*
 * Function to delete word from trie
 * A return value of 0 indicates no errors
 * A positive nonzero return value indicates some error
 */
int delete(char* word, trie** head){
	// Length of word
	int length = strlen(word);

	// Traversal pointers
	trie** trav[length];
	int ai = tolower(word[0]) - 'a';
	trav[0] = &((*head)->letter[ai]);

	// Get array of traversal pointers
	for(int i = 0; i < length - 1; i++){
		ai = tolower(word[i + 1]) - 'a';
		trav[i + 1] = (&(*trav[i])->letter[ai]);
	}

	// Unset word
	(*trav[length - 1])->isWord = false;

	// Free memory if possible
	bool ok = true;
	for(int i = length - 1; i >= 0; i--){
		for(int j = 0; j < 26; j++){
			if((*trav[i])->letter[j] != NULL){
				ok = false;
				break;
			}
		}
		if((*trav[i])->isWord){
			ok = false;
		}
		if(ok){
			free(*trav[i]);
			*trav[i] = NULL;
		}
		else{
			break;
		}
	}
	return(0);
}

/*
 * This function will check for a NULL pointer and call
 * the recursive function rlist to list all the words in the trie
 * Returns 0 on success and a nonzero number on error
 */
int list(trie* head){
	// Check for head being a NULL pointer
	if(head == NULL){
		printf("No words in trie.\n");
		return(0);
	}

	// Empty variable for word
	char word = 0;

	// Call recursive function
	rlist(&word, head);

	return(0);
}

/*
 * This function will recursively list the words in the trie given by head
 */
int rlist(char* word, trie* head){
	// Length of word
	int length = strlen(word);

	// Print the word if the trie is signaling the end of a word
	if(head->isWord == true){
		printf("%s\n", word);
	}

	// Iterate through each letter
	for(int i = 0; i < 26; i++){
		if(head->letter[i] != NULL){
			// Recursively call rlist with new arguments
			char newword[length + 2];
			strcpy(newword, word);
			newword[length] = i + 'a';
			newword[length + 1] = 0;
			rlist(newword, head->letter[i]);
		}
	}
	return(0);
}

/*
 * This function will recursively clear the trie pointed at by head
 * Return 0 on success
 */
int cleartrie(trie** head){
	// Check for NULL pointer
	if(*head == NULL){
		return(-1);
	}

	for(int i = 0; i < 26; i++){
		if((*head)->letter[i] != NULL){
			cleartrie(&((*head)->letter[i]));
		}
	}
	free(*head);
	*head = NULL;

	return(0);
}

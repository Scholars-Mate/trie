/* Functions involved with recieving input */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"

char* getString(void){
	char* input = malloc(sizeof(char) * 16);
	if(input == NULL){
		return(NULL);
	}

	for(int i = 0, letter = 0, arraySize = 16;
	    (letter = getchar()) != '\n' && feof(stdin) == 0; i++){
		if(i + 1 == arraySize){
			input = realloc(input, sizeof(char) * (arraySize *= 2));
			if(input == NULL){
				return(NULL);
			}
		}

		input[i] = letter;
	}

	return(input);
}

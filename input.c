/* Functions involved with recieving input */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"

char* getString(void){
	char* input = malloc(sizeof(char) * 16);
	if(input == NULL){
		return(NULL);
	}

	int arrayIndex = 0;
	int letter = 0;
	int arraySize = 16;

	while((letter = getchar()) != '\n' && feof(stdin) == 0){
		if(arrayIndex + 1 == arraySize){
			input = realloc(input, sizeof(char) * (arraySize *= 2));
			if(input == NULL){
				return(NULL);
			}
		}

		input[arrayIndex] = letter;
		arrayIndex++;
	}

	input[arrayIndex] = '\0';

	return(input);
}

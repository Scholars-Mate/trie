/* trie.h */

#include <stdbool.h>

// struct used to store trie
typedef struct trie{
                 struct trie* letter[26];
		 bool isWord;
         } trie;

// Prototypes
int add();
void search();

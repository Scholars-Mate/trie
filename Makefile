trie: main.o trie.o
	gcc -Wall -Werror -pedantic -std=c11 main.o trie.o -o trie

main.o: main.c
	gcc -Wall -Werror -pedantic -std=c11 -c main.c

trie.o: trie.c
	gcc -Wall -Werror -pedantic -std=c11 -c trie.c

clean:
	rm -rf *.o trie

trie: main.o trie.o input.o
	gcc -Wall -Werror -pedantic -std=c11 main.o trie.o input.o -o trie

main.o: main.c
	gcc -Wall -Werror -pedantic -std=c11 -c main.c

trie.o: trie.c
	gcc -Wall -Werror -pedantic -std=c11 -c trie.c

input.o: input.c
	gcc -Wall -Werror -pedantic -std=c11 -c input.c

clean:
	rm -rf *.o trie

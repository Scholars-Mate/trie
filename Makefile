trie: main.o trie.o
	clang main.o trie.o -o trie

main.o: main.c
	clang -c main.c

trie.o: trie.c
	clang -c trie.c

clean:
	rm -rf *.o trie

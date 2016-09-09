trie: main.o trie.o
	cc main.o trie.o -o trie

main.o: main.c
	cc -c main.c

trie.o: trie.c
	cc -c trie.c

clean:
	rm -rf *.o trie

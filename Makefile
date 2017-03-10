CC=@gcc
MAKEOPTS=-Wall -Werror -pedantic -std=c11
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)

trie: $(OBJECTS)
	@echo "[CC]" $@
	$(CC) -o $@ $(MAKEOPTS) $^

%.o: %.c
	@echo "[CC]" $@
	$(CC) -c $< $(MAKEOPTS)

clean:
	rm -rf *.o trie

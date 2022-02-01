CC=clang
CFLAGS=-std=c99 -Wall -g

array.out: array.c array.h
	$(CC) $(CFLAGS) array.c -o array.out

.PHONY: clean
clean: 
	@ rm *.out
	@ rm -r *.dSYM\
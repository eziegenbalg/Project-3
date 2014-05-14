

all:
	gcc -c -o tree.o tree.c
	gcc -c -o purple_malloc.o purple_malloc.c
	gcc -o purple_malloc purple_malloc.o tree.o

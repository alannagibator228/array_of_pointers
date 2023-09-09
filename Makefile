all: ArrayOfPointer

ArrayOfPointer: main.o func.o
	gcc main.o func.o -o ArrayOfPointer -lm -lasan -fsanitize=address -ggdb3
main.o: main.c
	gcc -c main.c -o main.o -lm -lasan -fsanitize=address -ggdb3

func.o: func.c
	gcc -c func.c -o func.o -lm -lasan -fsanitize=address -ggdb3
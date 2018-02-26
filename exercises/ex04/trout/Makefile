trout: util.o trout.o main.o
	gcc -Wall -g -o trout trout.o util.o main.o

main.o: main.c
	gcc -Wall -c main.c	

util.o: util.h util.c
	gcc -Wall -c util.c

trout.o: trout.h trout.c
	gcc -Wall -c trout.c

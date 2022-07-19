#Makefile

all: add-nbo

add-nbo: main.o
	g++ -o add-nbo main.o

main.o : sum.h main.c

clean:
	rm -f add-nbo
	rm -f *.o

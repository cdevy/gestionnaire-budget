CC=gcc
CFLAGS=-Wall -Wextra -g
LDFLAGS=-lm
EXEC=compte

all: $(EXEC)

compte: compte.o main.o
	$(CC) -o compte compte.o main.o $(LDFLAGS)

compte.o: compte.c
	$(CC) -o compte.o -c compte.c $(CFLAGS)

main.o: main.c compte.h
	$(CC) -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

				

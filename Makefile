CC=gcc
CFLAGS=-Wall -Wextra -g
LDFLAGS=-lm
EXEC=projet

all:: $(EXEC)

projet: compte.o utils.o main.o application.o categorie.o
	$(CC) -o projet compte.o utils.o main.o application.o categorie.o $(LDFLAGS)

application.o: application.c application.h utils.h compte.h categorie.h
	$(CC) $(CFLAGS) -o application.o -c -include utils.h -include compte.h -include categorie.h application.c

categorie.o: categorie.c categorie.h
	$(CC) $(CFLAGS) -o categorie.o -c categorie.c

compte.o: compte.c compte.h utils.h
	$(CC) $(CFLAGS) -o compte.o -c -include utils.h compte.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -o utils.o -c utils.c

main.o: main.c compte.h utils.h
	$(CC) $(CFLAGS) -o main.o -c main.c $(CFLAGS)

.PHONY: clean mrproper

clean::
	rm -rf *.o

mrproper:: clean
	rm -rf $(EXEC)

				

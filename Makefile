CC=gcc
CFLAGS=-Wall -Wextra -g
LDFLAGS=-lm
EXEC=projet

all:: $(EXEC)

projet: compte.o utils.o main.o application.o categorie.o operation.o statistiques.o graphiques.o gnuplot_i/src/gnuplot_i.o
	$(CC) -o projet compte.o utils.o main.o application.o categorie.o operation.o statistiques.o graphiques.o $(LDFLAGS)

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -o utils.o -c utils.c

categorie.o: categorie.c categorie.h
	$(CC) $(CFLAGS) -o categorie.o -c categorie.c

operation.o: operation.c operation.h categorie.h
	$(CC) $(CFLAGS) -o operation.o -include categorie.h -c operation.c

compte.o: compte.c compte.h utils.h categorie.h operation.h
	$(CC) $(CFLAGS) -o compte.o -include operation.h -include utils.h -include categorie.h -c compte.c

statistiques.o: statistiques.c statistiques.h compte.h operation.h categorie.h
	$(CC) $(CFLAGS) -o statistiques.o -include compte.h -include operation.h -include categorie.h -c statistiques.c

graphiques.o: graphiques.c graphiques.h statistiques.h operation.h categorie.h gnuplot_i/src/gnuplot_i.c
	$(CC) $(CFLAGS) -o graphiques.o -include categorie.h -include statistiques.h -include gnuplot_i/src/gnuplot_i.c -c graphiques.c

application.o: application.c application.h utils.h compte.h categorie.h statistiques.h graphiques.h
	$(CC) $(CFLAGS) -o application.o -include compte.h -include utils.h -include categorie.h -include statistiques.h -include graphiques.h -c application.c

main.o: main.c compte.h application.h
	$(CC) $(CFLAGS) -o main.o -include application.h -include compte.h -c main.c $(CFLAGS)

.PHONY: clean mrproper

clean::
	rm -rf *.o

mrproper:: clean
	rm -rf $(EXEC)
			

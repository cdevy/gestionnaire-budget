#include <stdio.h>
#include <stdlib.h>
#include "compte.h"

Flux* nouveau_flux(char* date, double debit, double credit) {
    Flux* f = (Flux*) malloc(sizeof(Flux));
    if (f != NULL) {
	strcpy(f->date, date);
	f->debit = debit;
	f->credit = credit; 
    }
    return f;
}

Flux* recherche_flux(Compte* c, char* date) {
    Flux* f = c->flux;
    while(f != NULL) {
	if (!strcmp(f->date, date)) { // 0 si les chaines sont egales
	    return f; 
	}
        f = f->next;
    }
    return NULL;
}

void sauvegarde_flux(Compte* compte) {
    char nomFlux[20] = "flux ";
    char noCpte[10] = "";
    sprintf(noCpte, "%ld", compte->numero);
    nomFlux = strcat(strcat(nomFlux, noCpte),".txt");
    FILE* fichier = fopen(nomFlux, "a+");
    if (fichier != NULL) {
        Flux* f = compte->flux;
	while (f != NULL) {
	    fprintf(fichier, "%s %f %f", f->date, f->credit, f->debit); 
	    f = f->next;
	}
        fclose(fichier);
    }
}

#ifndef FLUX_H_INCLUDED
#define FLUX_H_INCLUDED

#include "compte.h" 

/*
Permet de gérer les flux rentrees/sorties d'un compte donne
*/

typedef struct Flux Flux;

struct Flux {
    char date[8];
    double credit;
    double debit; /* negatif ! */
    Flux* next;
};

Flux* recherche_flux(Compte* c, char* date);

void sauvegarde_flux(Compte* compte);

#endif

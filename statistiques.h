#ifndef STATISTIQUES_H_INCLUDED
#define STATISTIQUES_H_INCLUDED

#include "compte.h"
#include "categorie.h"
#include "operation.h"

/*
Permet de donner des statistiques journalieres et mensuelles
*/

int menu_stats();

void depenses(Compte* c);

void rentrees(Compte* c);

void balance(Compte* c);

double depenses_categorie(Compte* c, Categorie cat);

double rentrees_categorie(Compte* c, Categorie cat);

double balanceJour(Operation* list, int jour);

double balanceJourCategorie(Operation* list, int jour, Categorie cat);

double balanceMois(Operation* list);
	
double balanceMoisCategorie(Operation* list, Categorie cat);

#endif

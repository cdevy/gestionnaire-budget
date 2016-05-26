#ifndef STATISTIQUES_H_INCLUDED
#define STATISTIQUES_H_INCLUDED

#include "compte.h"
#include "categorie.h"

/*
Permet de donner des statistiques mensuelles (avec graphiques)
*/

typedef enum Type_graph {BATON, ROND, TRAIT} Type_graph;

int menu_stats();

void depenses(Compte* c);

void rentrees(Compte* c);

void balance(Compte* c);

double depenses_categorie(Compte* c, Categorie cat, int affichage);

double rentrees_categorie(Compte* c, Categorie cat, int affichage);

#endif

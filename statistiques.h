#ifndef STATISTIQUES_H_INCLUDED
#define STATISTIQUES_H_INCLUDED

#include "compte.h" 

/*
Permet de donner des statistiques mensuelles (avec graphiques)
*/

typedef struct Type_graph = {BATON, ROND, TRAIT} Type_graph;

void statistiques(Compte* c);

void depenses_mensuelles(Compte* c, Type_graph type);

void rentrees_mensuelles(Compte* c, Type_graph type);

void balance_mensuelle(Compte* c, Type_graph type);

void depense_categorie(Compte* c, Categorie* cat, Type_graph type);

#endif

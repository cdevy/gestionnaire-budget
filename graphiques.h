#ifndef GRAPHIQUES_H_INCLUDED
#define GRAPHIQUES_H_INCLUDED

#include "categorie.h"
#include "operation.h"

/*
Permet d'afficher les graphiques lies aux statistiques
*/

void afficheBalanceMois(Operation* list);

void afficheBalanceMoisCategorie(Operation* list, Categorie cat);

void afficheBalanceCategories(Operation* list);

#endif

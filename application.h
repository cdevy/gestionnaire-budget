#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include "compte.h"

/*
Gestion de l'interface utilisateur
*/

int menu();

Comptes gestion_menu(Comptes liste, int action);

Comptes gestion_comptes(Comptes liste, int choix);

Comptes gestion_informations(Comptes liste, int choix);

Comptes gestion_transactions(Comptes liste, int choix);

Comptes gestion_stats(Comptes liste, int choix);

long numero_compte();

#endif

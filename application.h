#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

/*
Gestion de l'interface utilisateur
*/

int menu();

void gestion_menu(Comptes liste, int action);

void gestion_comptes(Comptes liste, int choix);

void gestion_informations(Comptes liste, int choix);

void gestion_transactions(Comptes liste, int choix);

#endif

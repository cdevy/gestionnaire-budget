#ifndef COMPTE_H_INCLUDED
#define COMPTE_H_INCLUDED

#include "operation.h"
//#include "flux.h"
#define NB_CAT 9

/*
Definit un compte
Permet de sauvegarder les operations liees a un compte
*/

typedef struct Compte Compte;

struct Compte {
    char* nom;
    long numero; /* 10 chiffres */
    char* proprietaire;
    char* banque;
    char* agence;
    double solde;
    char* nomFichier;
    double budgetsMax[NB_CAT];
    Operation* liste_op;
    //Flux* flux;
    Compte* next;
};

typedef Compte* Comptes;

Comptes initialiser();

Compte* nouveau_compte(char* nom, long numero, char* proprietaire, char* banque, char* agence, double solde);

Comptes ajouter(Comptes liste, Compte* c);

Comptes suppression(Comptes liste, Compte* compte);

void free_compte(Compte* c);

void affiche_solde(Compte* compte);

void informations(Compte* compte);

void affiche_budgetsMax(Compte* compte);

void sauvegarde(Compte* compte);

int depot(Compte* c, double valeur);

int retrait(Compte* c, double valeur);

Compte* compte(Comptes liste, long numero);

Comptes lire_liste(Comptes liste);

void sauvegarder_liste(Comptes liste);

#endif

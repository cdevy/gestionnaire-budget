#ifndef COMPTE_H_INCLUDED
#define COMPTE_H_INCLUDED

/*
Définit un compte
Permet de sauvegarder les opérations liées à un compte
*/

typedef struct {
    char* nom;
    long numero;
    char* proprietaire;
    char* banque;
    char* agence;
    double solde;
} Compte;

Compte* nouveau_compte(char* nom, long numero, char* proprietaire, char* banque, char* agence, double solde);

void suppression(Compte* compte);

void affiche_solde(Compte* compte);

void affiche_operations(Compte* compte); // à voir plus tard

void informations(Compte* compte);

void sauvegarde(Compte* compte);


#endif // COMPTE_H_INCLUDED

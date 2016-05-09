#ifndef COMPTE_H_INCLUDED
#define COMPTE_H_INCLUDED

/*
Définit un compte
Permet de charger des opérations à partir d'un relevé
Permet de créer un relevé
*/

typedef struct Compte Compte;

struct Compte {
    char nom[20];
    long numero;
    char proprietaire[30];
    char banque[20];
    char agence[20];
    double solde;
};

Compte nouveau_compte(char nom[20], long numero, char proprietaire[30], char banque[20], char agance[20], double solde);

void suppression(Compte compte);

void affiche_solde(Compte compte);

void affiche_operations(Compte compte); // à voir plus tard

void informations(Compte compte);

void sauvegarder(Compte compte);


#endif // COMPTE_H_INCLUDED

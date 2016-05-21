#ifndef COMPTE_H_INCLUDED
#define COMPTE_H_INCLUDED

/*
D�finit un compte
Permet de sauvegarder les op�rations li�es � un compte
*/

typedef struct {
    char* nom;
    long numero; // 10 chiffres !
    char* proprietaire;
    char* banque;
    char* agence;
    double solde;
    char* nomFichier;
} Compte;

Compte* nouveau_compte(char* nom, long numero, char* proprietaire, char* banque, char* agence, double solde);

void suppression(Compte* compte);

void affiche_solde(Compte* compte);

void affiche_operations(Compte* compte); // � voir plus tard

void informations(Compte* compte);

void sauvegarde(Compte* compte);

char* nom_fichier(Compte* compte);

long taille_double(double d);

long taille_long(long l); 

void depot(Compte* c, double valeur);

void retrait(Compte* c, double valeur);

void transaction(Compte* debiteur, Compte* crediteur, double valeur);

#endif // COMPTE_H_INCLUDED

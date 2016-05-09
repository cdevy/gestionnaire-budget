#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "compte.h"

Compte nouveau_compte(char nom[20], long numero, char proprietaire[30], char banque[20], char agence[20], double solde) {
    Compte c;
    strcpy(c.nom, nom);
    c.numero = numero;
    strcpy(c.proprietaire, proprietaire);
    strcpy(c.banque, banque);
    strcpy(c.agence, agence);
    c.solde = solde;
    return c;
}

void affiche_solde(Compte compte) {
    printf("Le solde de ce compte est de : %f€\n", compte.solde);
}

void informations(Compte compte) {
    printf("Numero : %ld\nNom du compte : %s\nProprietaire : %s\nBanque : %s\nAgence : %s\nSolde actuel : %f\n", compte.numero, compte.nom, compte.proprietaire, compte.banque, compte.agence, compte.solde);
}

void sauvegarde(Compte compte) {
    FILE* fichier = NULL;
    char nomCpte[20];
    strcpy(nomCpte, compte.nom);
    char noCpte[20];
    sprintf(noCpte, "%ld", compte.numero);
    char *nom_fichier = strcat(strcat(strcat(nomCpte, " "), noCpte),".txt");
    fichier = fopen(nom_fichier, "r+"); // si le fichier n'existe pas, il est créé ; sinon, il est remplacé
    if (fichier != NULL) {
	time_t t;
    	time(&t);
	fprintf(fichier, "Mise à jour : %s\n", ctime(&t));
	fprintf(fichier, "Compte : %ld (%s), Proprietaire : %s, Banque : %s, Agence : %s\n", compte.numero, compte.nom, compte.proprietaire, compte.banque, compte.agence);
	fprintf(fichier, "\nSolde actuel : %f€\n", compte.solde);
	fclose(fichier);
    }
}

int main() {
    Compte c = nouveau_compte("Compte courant", 338292124, "Charlotte DEVY", "Societe Generale", "St-Gratien", 100.00);
    affiche_solde(c);
    printf("\n");
    informations(c);
    sauvegarde(c);
    return 0;
}


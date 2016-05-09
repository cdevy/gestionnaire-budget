#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void sauvegarder(Compte compte) {
	FILE* fichier = NULL;
	char noCpte[256];
	sprintf(noCpte, "%ld", compte.numero);
    	fichier = fopen(strcat(strcat(strcat(compte.nom, " "), noCpte),".txt"), "w");
 	if (fichier != NULL) {
           	fputc('A', fichier);
		fclose(fichier);
    	}
}

int main() {
	Compte c = nouveau_compte("Compte courant", 338292124, "Charlotte DEVY", "Societe Generale", "St-Gratien", 100.00);
	affiche_solde(c);
	printf("\n");
	informations(c);
	sauvegarder(c);
	return 0;
}


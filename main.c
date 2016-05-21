#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "compte.h"
#include "application.h"

int main () {
    int fin; /* 0 : faux, 1 : vrai */
    do {
        int action = menu();
        gestion_menu(action);
	printf("\nVoulez-vous quitter l'application ?\n0.Non\n1.Oui\n");
	scanf("%d", &fin);
    } while (fin == 0);

    /* Tests fichier compte.c */
    /*
    Compte* c1 = nouveau_compte("Compte courant", 1338292124, "Charlotte DEVY", "Societe Generale", "St-Gratien", 100);
    if (c1 != NULL) {
        informations(c1);
        sauvegarde(c1);
        printf("\n");
    }
    Compte* c2 = nouveau_compte("Livret A", 3300002124, "Charlotte DEVY", "Societe Generale", "St-Gratien", 20000);
    if (c2 != NULL) {
        informations(c2);
        sauvegarde(c2);
        printf("\n");
    }
    printf("Depot de 250€ sur le compte n° %ld (%f) :\n", c1->numero, c1->solde);
    depot(c1, 250);
    affiche_solde(c1);
    printf("Retrait de 1500€ du compte n° %ld (%f) :\n", c2->numero, c2->solde);
    retrait(c2, 1500);
    affiche_solde(c2);
    printf("Transaction de 3000€ du compte n° %ld (%f) au compte n° %ld (%f) :\n", c2->numero, c2->solde, c1->numero, c1->solde);
    transaction(c2, c1, 3000);
    affiche_solde(c1);
    affiche_solde(c2);
    suppression(c1);
    suppression(c2);
    */
    return 0;
}

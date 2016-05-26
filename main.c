#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "compte.h"
#include "application.h"
#include "categorie.h"

int main () {
    Comptes liste = initialiser();

    /* Lecture liste de comptes */
    liste = lire_liste(liste);
    
    int fin = 0; /* 0 : faux, 1 : vrai */
    do {
        int action = menu();
        liste = gestion_menu(liste, action);
	printf("\nVoulez-vous quitter l'application ?\n0.Non\n1.Oui\n");
	scanf("%d", &fin);
	printf("\n");
    } while (fin == 0);

    /* Sauvegarde liste de comptes */
    liste = sauvegarder_liste(liste);

    /* Tests fichier compte.c */
    
    Compte* c1 = nouveau_compte("Compte courant", 1338292124, "Charlotte DEVY", "Societe Generale", "St-Gratien", 100);
    if (c1 != NULL) {
	affiche_solde(c1);
        informations(c1);
        sauvegarde(c1);
        printf("\n");
    }
    liste = ajouter(liste, c1);/*
    Compte* c2 = nouveau_compte("Livret A", 3300002124, "Charlotte DEVY", "Societe Generale", "St-Gratien", 20000);
    if (c2 != NULL) {
	affiche_solde(c2);
        informations(c2);
        sauvegarde(c2);
        printf("\n");
    }
    liste = ajouter(liste, c2);
    printf("Depot de 250€ sur le compte n° %ld (%f) :\n", c1->numero, c1->solde);
    depot(c1, 250);
    affiche_solde(c1);
    printf("Retrait de 1500€ du compte n° %ld (%f) :\n", c2->numero, c2->solde);
    retrait(c2, 1500);
    affiche_solde(c2);
    printf("Virement de 3000€ du compte n° %ld (%f) au compte n° %ld (%f) :\n", c2->numero, c2->solde, c1->numero, c1->solde);
    virement(c2, c1, 3000);
    affiche_solde(c1);
    affiche_solde(c2);
    affiche_solde(compte(liste, 1338292124));
    printf("La liste contient %d comptes\n", nb_comptes(liste));
    printf("Le compte portant ce numero ce trouve à l'adresse %p\n", compte(liste, 1338292124));
    informations(compte(liste, 1338292124));
    FILE* fichier = fopen("sauvegarde comptes.txt", "w+");
    if (fichier != NULL) {
	fprintf(fichier, "Numero, Nom, Proprietaire, Banque, Agence, Solde\n");
	while (liste != NULL) {
	    fprintf(fichier, "%ld, %s, %s, %s, %s, %f€\n", liste->numero, liste->nom, liste->proprietaire, liste->banque, liste->agence, liste->solde);
	    liste = liste->next;
	}
        fclose(fichier);
    }*/
 
    c1->liste_op = nouvelle_operation("26/05/16", "essai", DEBIT, -50, NULL);;
    suppression(liste, c1);
    //suppression(liste, c2);
    */

    /* Tests fichier categorie.c */
    /*
    affiche_categories(1);
    printf("\n");
    affiche_sousCategories(QUOTIDIEN, 1);
    printf("\n");
    affiche_sousCategories(LOISIRS, 1);
    printf("\n");
    affiche_sousCategories(SANTE, 1);
    printf("\n");
    affiche_sousCategories(HABITATION, 1);
    printf("\n");
    affiche_sousCategories(TRANSPORTS, 1);
    printf("\n");
    affiche_sousCategories(IMPOTS_SOLIDARITE, 1);
    printf("\n");
    affiche_sousCategories(PROFESSIONNEL, 1);
    printf("\n");
    affiche_sousCategories(EPARGNE, 1);
    printf("\n");
    affiche_sousCategories(DIVERS, 1);
    printf("\n");
    gestion_categories();
    printf("\n");
    */

    return 0;
}

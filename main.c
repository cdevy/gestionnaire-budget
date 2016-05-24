#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "compte.h"
#include "application.h"
#define TAILLE_LIGNE 49

int main () {
    Comptes liste = initialiser();

    /* Lecture liste de comptes */
    long numero;
    char nom[30];
    char proprietaire[30]; 
    char banque[30];
    char agence[30];
    double solde;
    FILE* fichier = fopen("sauvegarde comptes.txt", "r");
    if (fichier != NULL) {
	char premiere_ligne[49];
        fgets(premiere_ligne, TAILLE_LIGNE, fichier);
	printf("%s", nom);
	if (premiere_ligne != NULL) {
	    while(fscanf(fichier, "%ld, %[^\n]s, %[^\n]s, %[^\n]s, %[^\n]s, %lf€", &numero, nom, proprietaire, banque, agence, &solde) != EOF) { 
	        fscanf(fichier, "%ld, %s, %s, %s, %s, %lf€", &numero, nom, proprietaire, banque, agence, &solde);
	        printf("%ld, %s, %s, %s, %s, %lf€\n", numero, nom, proprietaire, banque, agence, solde);
	        Compte* c = nouveau_compte(nom, numero, proprietaire, banque, agence, solde);
	        if (c != NULL) {
		    liste = ajouter(liste, c);
	        } else {
		    printf("Erreur : le compte n'a pas pu etre ajoute");
	        }
	    }
	}
        fclose(fichier);
    }
    
    int fin = 0; // 0 : faux, 1 : vrai
    do {
        int action = menu();
        liste = gestion_menu(liste, action);
	printf("\nVoulez-vous quitter l'application ?\n0.Non\n1.Oui\n");
	vider_buffer();
	scanf("%d", &fin);
	printf("\n");
    } while (fin == 0);

    /* Sauvegarde liste de comptes */
    fichier = fopen("sauvegarde comptes.txt", "w+");
    if (fichier != NULL) {
	fprintf(fichier, "Numero, Nom, Proprietaire, Banque, Agence, Solde\n");
	while (liste != NULL) {
	    fprintf(fichier, "%ld, %s, %s, %s, %s, %f€\n", liste->numero, liste->nom, liste->proprietaire, liste->banque, liste->agence, liste->solde);
	    liste = liste->next;
	}
        fclose(fichier);
    }
  
    /*
    char* proprietaire = (char*) malloc(30*sizeof(char));
    printf("Nom du proprietaire :");
    scanf("%s", proprietaire);
    printf("%s", proprietaire);

    fgets(proprietaire, 30, stdin);
    printf("%s", proprietaire);
    */

    /* Tests fichier compte.c */
    /*
    Compte* c1 = nouveau_compte("Compte courant", 1338292124, "Charlotte DEVY", "Societe Generale", "St-Gratien", 100);
    if (c1 != NULL) {
	affiche_solde(c1);
        informations(c1);
        sauvegarde(c1);
        printf("\n");
    }
    liste = ajouter(liste, c1);
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
    }
    suppression(liste, c1);
    suppression(liste, c2);
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

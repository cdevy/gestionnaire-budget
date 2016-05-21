#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "compte.h"
#include "application.h"

int menu() {
    int choix;
    printf("Quelle action souhaitez-vous effectuer ?\n1. Creer/supprimer un compte\n2. Voir les informations liees a un compte\n3. Realiser une transaction\n");
    scanf("%d", &choix);
    printf("\n");
    return choix;
}

void gestion_menu(int action) {
    int choix;
    switch (action) {
	case 1:
	    printf("Entrez votre choix :\n1. Creer un compte\n2. Supprimer un compte\nTapez 0 pour revenir au menu precedent\n");
            scanf("%d", &choix);
	    printf("\n");
	    gestion_comptes(choix);
	    break;
	case 2:
	    printf("Entrez le numero du compte (10 chiffres)\nTapez 0 pour revenir au menu precedent\n");
            scanf("%d", &choix);
	    printf("\n");
	    if (taille_long((long) choix) == 10) {
		printf("...\n");
	    } else if (choix == 0) {
		choix = menu();
		gestion_menu(choix);
	    } else {
		printf("L'action choisie n'existe pas\n");
	    }
	    break;
	case 3:
	    printf("Entrez le type de transaction :\n1.Retrait\n2.Depot\n3.Virement entre comptes\nTapez 0 pour revenir au menu precedent\n");
            scanf("%d", &choix);
	    printf("\n");
	    gestion_transactions(choix);
	    break;
	default:
	    printf("L'action choisie n'existe pas\n");

	    break;
    }
    printf("\n");
}

void gestion_comptes(int choix) {
    int action;
    switch (choix) {
	case 0:
	    action = menu();
	    gestion_menu(action);
	    break;
	case 1:
	    printf("Entrez les informations suivantes :\n");
	    long numero;
	    printf("Numero du compte (10 chiffres) :");
            scanf("%ld", &numero);
	    if (taille_long(numero) != 10) {
		printf("Numero de compte invalide\n");
		break;
	    }
	    char* nom = (char*) malloc(30*sizeof(char));
	    printf("Nom du compte :");
	    vider_buffer();
            scanf("%s", nom);
	    char* proprietaire = (char*) malloc(30*sizeof(char));
	    printf("Nom du proprietaire :");
	    vider_buffer();
            scanf("%s", proprietaire);
	    char* banque = (char*) malloc(30*sizeof(char));
   	    printf("Nom de la banque :");
	    vider_buffer();
            scanf("%s", banque);
	    char* agence = (char*) malloc(30*sizeof(char));
    	    printf("Localisation de l'agence (ville) :");
	    vider_buffer();
            scanf("%s", agence);
	    double solde;
    	    printf("Solde initial :");
       	    scanf("%lf", &solde);
	    Compte* c = nouveau_compte(nom, numero, proprietaire, banque, agence, solde);
	    if (c != NULL) {
		printf("Le compte a bien ete cree");
	    } else {
		printf("Le compte n'a pas pu être cree");
	    }
    	    printf("\n");
	    free(nom);
	    free(proprietaire);
	    free(banque);
	    free(agence);
	    break;
	case 2:
	    printf("...\n");
	    break;
	default:
    	    printf("L'action choisie n'existe pas\n");
    	    break;
    }
}

void gestion_transactions(int choix) {
    int action;
    switch (choix) {
	case 0:
	    action = menu();
	    gestion_menu(action);
	    break;
	case 1:    
	    printf("...\n");
	    break;
	case 2:
	    printf("...\n");	    
	    break;
	case 3:
	    printf("...\n");	    
	    break;
	default:
    	    printf("L'action choisie n'existe pas\n");
    	    break;
    }
}

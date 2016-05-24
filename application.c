#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "compte.h"
#include "categorie.h"
#include "application.h"

int menu() {
    int choix;
    printf("Quelle action souhaitez-vous effectuer ?\n1. Creer/supprimer un compte\n2. Voir les informations liees a un compte\n3. Realiser une transaction\n4. Categoriser une operation\n");
    scanf("%d", &choix);
    printf("\n");
    return choix;
}

Comptes gestion_menu(Comptes liste, int action) {
    int choix;
    Comptes liste2 = liste;
    switch (action) {
	case 1:
	    printf("Entrez votre choix :\n1. Creer un compte\n2. Supprimer un compte\nTapez 0 pour revenir au menu precedent\n");
            scanf("%d", &choix);
	    printf("\n");
	    liste2 = gestion_comptes(liste, choix);
	    break;
	case 2:
	    printf("Entrez votre choix :\n1. Afficher le solde d'un compte\n2. Afficher le RIB d'un compte\nTapez 0 pour revenir au menu precedent\n");
            scanf("%d", &choix);
	    printf("\n");
	    gestion_informations(liste, choix);
	    break;
	case 3:
	    printf("Entrez le type de transaction :\n1.Retrait\n2.Depot\n3.Virement entre comptes\nTapez 0 pour revenir au menu precedent\n");
            scanf("%d", &choix);
	    printf("\n");
	    gestion_transactions(liste, choix);
	    break;
	case 4:
	    gestion_categories();
	    break;
	default:
	    printf("L'action choisie n'existe pas\n");
	    break;
    }
    printf("\n");
    return liste2;
}

Comptes gestion_comptes(Comptes liste, int choix) {
    int action;
    long numero;
    Comptes liste2 = liste;
    switch (choix) {
	case 0:
	    action = menu();
	    gestion_menu(liste, action);
	    break;
	case 1:
	    printf("Entrez les informations suivantes :\n");
	    printf("Numero du compte (10 chiffres) :");
            scanf("%ld", &numero);
	    vider_buffer();
	    if (taille_long(numero) != 10) {
		printf("Le numero de compte est invalide\n");
		break;
	    }
	    char nom[30];
	    printf("Nom du compte :");
            fgets(nom, 30, stdin);
	    traiter(nom);
	    char proprietaire[30];
	    printf("Nom du proprietaire :");
	    fgets(proprietaire, 30, stdin);
	    traiter(proprietaire);
	    char banque[30];
   	    printf("Nom de la banque :");
	    fgets(banque, 30, stdin);
	    traiter(banque);
	    char agence[30];
    	    printf("Localisation de l'agence (ville) :");
	    fgets(agence, 30, stdin);
	    traiter(agence);
	    double solde;
    	    printf("Solde initial :");
       	    scanf("%lf", &solde);
	    Compte* c = nouveau_compte(nom, numero, proprietaire, banque, agence, solde);
	    if (c != NULL) {
		liste2 = ajouter(liste, c);
		printf("Le compte a bien ete cree");
	    } else {
		printf("Le compte n'a pas pu etre cree");
	    }
    	    printf("\n");
	    break;
	case 2:
    	    printf("Entrez le numero (10 chiffres) du compte a supprimer :");
       	    scanf("%ld", &numero);
	    if (compte(liste, numero) != NULL) {
		liste2 = suppression(liste, compte(liste, numero));
		printf("Le compte a bien ete cree");
	    } else {
		printf("Le compte n'a pas pu etre supprime");		
	    }
	    break;
	default:
    	    printf("L'action choisie n'existe pas\n");
    	    break;
    }
    return liste2; 
}

void gestion_informations(Comptes liste, int choix) {
    long numero;
    int action;
    switch (choix) {
	case 0:
	    action = menu();
	    gestion_menu(liste, action);
	    break;
	case 1:
	    printf("Entrez le numero du compte (10 chiffres) :\n");
            scanf("%ld", &numero);
    	    if (taille_long(numero) == 10) {
	        if (compte(liste, numero) != NULL) {
		    affiche_solde(compte(liste, numero));
	        } else {
		    printf("Le compte n'existe pas");		
	        }
	    } else {
		printf("Le numero de compte est invalide\n");
	    }
	    break;
	case 2:
	    printf("Entrez le numero du compte (10 chiffres) :\n");
            scanf("%ld", &numero);
    	    if (taille_long(numero) == 10) {
	        if (compte(liste, numero) != NULL) {
		    informations(compte(liste, numero));
	        } else {
		    printf("Le compte n'existe pas");		
	        }
	    } else {
		printf("Le numero de compte est invalide\n");
	    }
	    break;
	default:
    	    printf("L'action choisie n'existe pas\n");
    	    break;
    }
}

void gestion_transactions(Comptes liste, int choix) {
    int action;
    double valeur;
    long numero;
    switch (choix) {
	case 0:
	    action = menu();
	    gestion_menu(liste, action);
	    break;
	case 1:
    	    printf("Entrez le numero (10 chiffres) du compte a debiter :");
	    vider_buffer();
       	    scanf("%ld", &numero);
	    if (taille_long(numero) != 10) {
		printf("Numero de compte invalide\n");
		break;
	    }
    	    printf("Entrez le montant a debiter :");
	    vider_buffer();
       	    scanf("%lf", &valeur);
	    if (retrait(compte(liste, numero), valeur)) {
		retrait(compte(liste, numero), valeur);
		printf("Le retrait a bien ete effectue");
	    } else {
		printf("Le retrait n'a pas pu etre effectue");
	    }  
	    break;
	case 2:
    	    printf("Entrez le numero (10 chiffres) du compte a crediter :");
	    vider_buffer();
       	    scanf("%ld", &numero);
	    if (taille_long(numero) != 10) {
		printf("Numero de compte invalide\n");
		break;
	    }
    	    printf("Entrez le montant a crediter :");
	    vider_buffer();
       	    scanf("%lf", &valeur);
	    if (depot(compte(liste, numero), valeur)) {
		depot(compte(liste, numero), valeur);
		printf("Le depot a bien ete effectue");
	    } else {
		printf("Le depot n'a pas pu etre effectue");
	    }	    
	    break;
	case 3:
    	    printf("Entrez le numero (10 chiffres) du compte a debiter :");
	    vider_buffer();
       	    scanf("%ld", &numero);
	    if (taille_long(numero) != 10) {
		printf("Le numero de compte est invalide\n");
		break;
	    }
	    long numero2;
    	    printf("Entrez le numero (10 chiffres) du compte a crediter :");
	    vider_buffer();
       	    scanf("%ld", &numero2);
	    if (taille_long(numero2) != 10) {
		printf("Le numero de compte est invalide\n");
		break;
	    }
    	    printf("Entrez le montant de la transaction :");
	    vider_buffer();
       	    scanf("%lf", &valeur);
	    if (virement(compte(liste, numero), compte(liste, numero2), valeur)) {
		virement(compte(liste, numero), compte(liste, numero2), valeur);
		printf("Le virement a bien ete effectue");
	    } else {
		printf("Le virement n'a pas pu etre effectue");
	    }	    
	    break;
	default:
    	    printf("L'action choisie n'existe pas\n");
    	    break;
    }
}

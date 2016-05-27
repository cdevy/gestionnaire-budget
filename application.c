#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "compte.h"
#include "categorie.h"
#include "application.h"
#include "statistiques.h"

int menu() {
    int choix;
    printf("Quelle action souhaitez-vous effectuer ?\n1. Creer/supprimer un compte\n2. Afficher la liste des comptes\n3. Consulter l'etat d'un compte\n4. Importer un releve de compte\n");
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
	    printf("Ci-dessous la liste des comptes enregistres :\n");
    	    Compte* c2 = liste;
     	    while(c2 != NULL) {
		printf("%ld  %s  %s\n", c2->numero, c2->nom, c2->proprietaire); 
                c2 = c2->next;
   	    }
	    break;
	case 3:
	    printf("Entrez votre choix :\n1. Afficher le solde d'un compte\n2. Afficher les informations liees a un compte\n3. Afficher les statistiques mensuelles d'un compte\n4. Afficher le budget maximal par categorie\nTapez 0 pour revenir au menu precedent\n");
            scanf("%d", &choix);
	    printf("\n");
	    gestion_informations(liste, choix);
	    break;
	case 4:
    	    printf("Entrez le numero (10 chiffres) du compte (Tapez 0 pour revenir au menu precedent) : ");
	    long numero;
       	    scanf("%ld", &numero);
	    if (numero == 0) {
	        choix = menu();
	        gestion_menu(liste, choix);
	    } else if (taille_long(numero) != 10) {
		printf("Le numero de compte est invalide\n");
	    } else if (compte(liste, numero) != NULL) {
	        char nomFichier[32];
		printf("Entrez le nom du fichier a importer (.csv ou .txt) : ");
		vider_buffer();
       	        fgets(nomFichier, 32, stdin);
	        traiter(nomFichier);
		compte(liste, numero)->liste_op = ParserOperation (nomFichier);
		gestion_op(compte(liste, numero));
		printf("Le releve a bien ete importe au compte\n");
	    } else {
		printf("Le releve n'a pas pu etre importe au compte\n");		
	    }
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
	    printf("Numero du compte (10 chiffres) (Tapez 0 pour revenir au menu precedent) : ");
            scanf("%ld", &numero);
	    if (numero == 0) {
		return gestion_menu(liste2, 1);
	    } else if (taille_long(numero) != 10) {
		printf("Le numero de compte est invalide\n");
		return liste2;
	    }
	    if(compte(liste, numero) != NULL) {
		printf("Ce numero correspond a un autre compte\n");
		return liste2;
	    }
	    vider_buffer();
	    char nom[30];
	    printf("Nom du compte : ");
            fgets(nom, 30, stdin);
	    traiter(nom);
	    char proprietaire[30];
	    printf("Nom du proprietaire : ");
	    fgets(proprietaire, 30, stdin);
	    traiter(proprietaire);
	    char banque[30];
   	    printf("Nom de la banque : ");
	    fgets(banque, 30, stdin);
	    traiter(banque);
	    char agence[30];
    	    printf("Localisation de l'agence (ville) : ");
	    fgets(agence, 30, stdin);
	    traiter(agence);
	    double solde;
    	    printf("Solde initial : ");
       	    scanf("%lf", &solde);
	    Compte* c = nouveau_compte(nom, numero, proprietaire, banque, agence, solde);
	    if (c != NULL) {
		liste2 = ajouter(liste, c);
		printf("Le compte a bien ete cree\n");
	    } else {
		printf("Le compte n'a pas pu etre cree\n");
	    }
	    break;
	case 2:
    	    printf("Entrez le numero (10 chiffres) du compte a supprimer (Tapez 0 pour revenir au menu precedent) : ");
       	    scanf("%ld", &numero);
	    if (numero == 0) {
		return gestion_menu(liste2, 1);
	    } else if (taille_long(numero) != 10) {
		printf("Le numero de compte est invalide\n");
	    } else if (compte(liste, numero) != NULL) {
		liste2 = suppression(liste, compte(liste, numero));
		printf("Le compte a bien ete supprime\n");
	    } else {
		printf("Le compte n'a pas pu etre supprime\n");		
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
	    printf("Entrez le numero du compte (10 chiffres) (Tapez 0 pour revenir au menu precedent) : ");
            scanf("%ld", &numero);
	    if (numero == 0) {
		gestion_menu(liste, 2);
		break;
	    } else if (taille_long(numero) == 10) {
	        if (compte(liste, numero) != NULL) {
		    affiche_solde(compte(liste, numero));
	        } else {
		    printf("Le compte n'existe pas\n");		
	        }
	    } else {
		printf("Le numero de compte est invalide\n");
	    }
	    break;
	case 2:
	    printf("Entrez le numero du compte (10 chiffres) (Tapez 0 pour revenir au menu precedent) : ");
            scanf("%ld", &numero);
	    if (numero == 0) {
		gestion_menu(liste, 2);
		break;
	    } else if (taille_long(numero) == 10) {
	        if (compte(liste, numero) != NULL) {
		    informations(compte(liste, numero));
	        } else {
		    printf("Le compte n'existe pas\n");		
	        }
	    } else {
		printf("Le numero de compte est invalide\n");
	    }
	    break;
	case 3:
	    action = menu_stats();
	    gestion_stats(liste, action);
	    break;
	case 4:
	    printf("Entrez le numero du compte (10 chiffres) (Tapez 0 pour revenir au menu precedent) : ");
            scanf("%ld", &numero);
	    if (numero == 0) {
		gestion_menu(liste, 2);
		break;
	    } else if (taille_long(numero) == 10) {
	        if (compte(liste, numero) != NULL) {
		    affiche_budgetsMax(compte(liste, numero));
	        } else {
		    printf("Le compte n'existe pas\n");		
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
    	    printf("Entrez le numero (10 chiffres) du compte a debiter (Tapez 0 pour revenir au menu precedent) : ");;
       	    scanf("%ld", &numero);
	    if (numero == 0) {
		gestion_menu(liste, 3);
		break;
	    } else if (taille_long(numero) != 10) {
		printf("Le numero de compte est invalide\n");
		break;
	    }
    	    printf("Entrez le montant a debiter :");
	    vider_buffer();
       	    scanf("%lf", &valeur);
	    if (retrait(compte(liste, numero), valeur)) {
		retrait(compte(liste, numero), valeur);
		printf("Le retrait a bien ete effectue\n");
	    } else {
		printf("Le retrait n'a pas pu etre effectue\n");
	    }  
	    break;
	case 2:
    	    printf("Entrez le numero (10 chiffres) du compte a crediter (Tapez 0 pour revenir au menu precedent) : ");
       	    scanf("%ld", &numero);
	    if (numero == 0) {
		gestion_menu(liste, 3);
		break;
	    } else if (taille_long(numero) != 10) {
		printf("Le numero de compte est invalide\n");
		break;
	    }
    	    printf("Entrez le montant a crediter :");
	    vider_buffer();
       	    scanf("%lf", &valeur);
	    if (depot(compte(liste, numero), valeur)) {
		depot(compte(liste, numero), valeur);
		printf("Le depot a bien ete effectue\n");
	    } else {
		printf("Le depot n'a pas pu etre effectue\n");
	    }	    
	    break;
	default:
    	    printf("L'action choisie n'existe pas");
    	    break;
    }
}

void gestion_stats(Comptes liste, int choix) {
    int action;
    long numero;
    switch (choix) {
	case 0:
	    gestion_menu(liste, 3);
	    break;
	case 1:
	    printf("Entrez le numero du compte (10 chiffres) (Tapez 0 pour revenir au menu precedent) : ");
            scanf("%ld", &numero);
	    if (numero == 0) {
		gestion_menu(liste, 3);
		break;
	    } else if (taille_long(numero) == 10) {
	        if (compte(liste, numero) != NULL) {
		    depenses(compte(liste, numero));
	        } else {
		    printf("Le compte n'existe pas\n");		
	        }
	    } else {
		printf("Le numero de compte est invalide\n");
	    }
	    break;
	case 2:
	    printf("Entrez le numero du compte (10 chiffres) (Tapez 0 pour revenir au menu precedent) : ");
            scanf("%ld", &numero);
	    if (numero == 0) {
		gestion_menu(liste, 3);
		break;
	    } else if (taille_long(numero) == 10) {
	        if (compte(liste, numero) != NULL) {
		    rentrees(compte(liste, numero));
	        } else {
		    printf("Le compte n'existe pas\n");		
	        }
	    } else {
		printf("Le numero de compte est invalide\n");
	    }
	    break;
	case 3:
	    printf("Entrez le numero du compte (10 chiffres) (Tapez 0 pour revenir au menu precedent) : ");
            scanf("%ld", &numero);
	    if (numero == 0) {
		gestion_menu(liste, 3);
		break;
	    } else if (taille_long(numero) == 10) {
	        if (compte(liste, numero) != NULL) {
		    balance(compte(liste, numero));
	        } else {
		    printf("Le compte n'existe pas\n");		
	        }
	    } else {
		printf("Le numero de compte est invalide\n");
	    }
	    break;
	case 4:
	    printf("Entrez le numero du compte (10 chiffres) (Tapez 0 pour revenir au menu precedent) : ");
            scanf("%ld", &numero);
	    if (numero == 0) {
		gestion_menu(liste, 3);
		break;
	    } else if (taille_long(numero) == 10) {
	        if (compte(liste, numero) != NULL) {
		    printf("Choisissez parmi les categories suivantes :\n");
		    affiche_categories(0);
            	    scanf("%d", &action);
		    depenses_categorie(compte(liste, numero), action-1, 1);
	        } else {
		    printf("Le compte n'existe pas\n");		
	        }
	    } else {
		printf("Le numero de compte est invalide\n");
	    }
	    break;
	case 5:
	    printf("Entrez le numero du compte (10 chiffres) (Tapez 0 pour revenir au menu precedent) : ");
            scanf("%ld", &numero);
	    if (numero == 0) {
		gestion_menu(liste, 3);
		break;
	    } else if (taille_long(numero) == 10) {
	        if (compte(liste, numero) != NULL) {
		    printf("Choisissez parmi les categories suivantes :\n");
		    affiche_categories(0);
            	    scanf("%d", &action);
		    rentrees_categorie(compte(liste, numero), action-1, 1);
	        } else {
		    printf("Le compte n'existe pas\n");		
	        }
	    } else {
		printf("Le numero de compte est invalide\n");
	    }
	    break;
	default:
    	    printf("L'action choisie n'existe pas");
    	    break;
    }
}

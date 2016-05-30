#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "compte.h"
#include "categorie.h"
#include "application.h"
#include "statistiques.h"
#include "graphiques.h"

int menu() {
    int choix;
    printf("Quelle action souhaitez-vous effectuer ?\n1. Créer ou supprimer un compte\n2. Afficher la liste des comptes\n3. Consulter l'etat d'un compte\n4. Importer un releve de compte\n5. Afficher les statistiques liees a un compte\n");
    scanf("%d", &choix);
    printf("\n");
    return choix;
}

Comptes gestion_menu(Comptes liste, int action) {
    int choix;
    Comptes liste2 = liste;
    long numero = 0;
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
	    printf("Entrez votre choix :\n1. Afficher le solde d'un compte\n2. Afficher les informations liees a un compte\n3. Afficher/Modifier le budget maximal des categories\nTapez 0 pour revenir au menu precedent\n");
            scanf("%d", &choix);
	    printf("\n");
	    gestion_informations(liste, choix);
	    break;
	case 4:
    	    numero = numero_compte();
	    if (numero == 0) {
	        printf("\n");
	        choix = menu();
	        gestion_menu(liste, choix);
	    } else if (numero != -1) {
	        char nomFichier[32];
		printf("Entrez le nom du fichier a importer (.csv ou .txt) : ");
		vider_buffer();
       	        fgets(nomFichier, 32, stdin);
	        traiter(nomFichier, 0);
		compte(liste, numero)->liste_op = ParserOperation(nomFichier);
		gestion_op(compte(liste, numero));
		printf("Le releve a bien ete importe au compte\n");
	    }
	    break;
	case 5:
	    printf("IMPORTANT : vous devez avoir importe un releve pour afficher les statistiques d'un compte ! \nEntrez votre choix :\n1. Depenses mensuelles\n2. Rentrees mensuelles\n3. Balance mensuelle\nTapez 0 pour revenir au menu precedent\n");
            scanf("%d", &choix);
	    printf("\n");
	    gestion_stats(liste, choix);
	    break;
	default:
	    printf("L'action choisie n'existe pas");
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
	    liste2 = gestion_menu(liste2, action);
	    break;
	case 1:
	    printf("Entrez les informations suivantes :\n");
	    printf("Numero du compte (10 chiffres) (Tapez 0 pour revenir au menu precedent) : ");
    	    scanf("%ld", &numero);
    	    if (numero != 0) {
		if (taille_long(numero) != 10) {
	    	    printf("Le numero de compte est invalide\n");
		    return liste2;
	        } else if (compte(liste, numero) != NULL) {
			printf("Ce numero correspond a un autre compte\n");
			return liste2;	
	    	}
    	    } else {
		return gestion_menu(liste2, 1);
	    }
	    vider_buffer();
	    char nom[30];
	    printf("Nom du compte : ");
            fgets(nom, 30, stdin);
	    traiter(nom, 0);
	    char proprietaire[30];
	    printf("Nom du proprietaire : ");
	    fgets(proprietaire, 30, stdin);
	    traiter(proprietaire, 0);
	    char banque[30];
   	    printf("Nom de la banque : ");
	    fgets(banque, 30, stdin);
	    traiter(banque, 0);
	    char agence[30];
    	    printf("Localisation de l'agence (ville) : ");
	    fgets(agence, 30, stdin);
	    traiter(agence, 0);
	    double solde;
    	    printf("Solde initial : ");
       	    scanf("%lf", &solde);
	    Compte* c = nouveau_compte(nom, numero, proprietaire, banque, agence, solde);
	    if (c != NULL) {
		liste2 = ajouter(liste2, c);
		printf("Le compte a bien ete cree\n");
	    } else {
		printf("Le compte n'a pas pu etre cree\n");
	    }
	    break;
	case 2:
    	    numero = numero_compte(liste2);
	    if (numero == 0) {
		liste2 = gestion_menu(liste2, 1);
	    } else if (numero != -1) {
		liste2 = suppression(liste2, compte(liste2, numero));
		printf("Le compte a bien ete supprime\n");		
	    }
	    break;
	default:
    	    printf("L'action choisie n'existe pas\n");
    	    break;
    }
    return liste2; 
}

Comptes gestion_informations(Comptes liste, int choix) {
    long numero;
    int action;
    Comptes liste2 = liste;
    switch (choix) {
	case 0:
	    action = menu();
	    liste2 = gestion_menu(liste2, action);
	    break;
	case 1:
	    numero = numero_compte(liste2);
	    if (numero == 0) {
		liste2 = gestion_menu(liste2, 2);
	    } else if (numero != -1) {
		affiche_solde(compte(liste2, numero));
	    }
	    break;
	case 2:
	    numero = numero_compte(liste2);
	    if (numero == 0) {
		liste2 = gestion_menu(liste2, 2);
	    } else if (numero != -1) {
		informations(compte(liste2, numero));
	    }
	    break;
	case 3:
	    numero = numero_compte(liste2);
	    if (numero == 0) {
		liste2 = gestion_menu(liste2, 2);
		printf("\n");
	    } else if (numero != -1) {
		affiche_budgetsMax(compte(liste2, numero));
		printf("\nPour quelle categorie souhaitez-vous modifier le budget maximal ? (Tapez 0 pour revenir au menu precedent)\n");
	        affiche_categories();
		scanf("%d", &action);
		if (action == 0) {
		    liste2 = gestion_menu(liste2, 3);
		} else if (action > 9) {
		    printf("La categorie choisie n'existe pas\n");
		} else {
		    printf("\nEntrez le nouveau budget maximal : ");
	            double max;
		    scanf("%lf", &max);
		    compte(liste2, numero)->budgetsMax[action-1] = max;
		}
	    }
	    break;
	default:
    	    printf("L'action choisie n'existe pas\n");
    	    break;
    }
    return liste2;
}

Comptes gestion_stats(Comptes liste, int choix) {
    long numero;
    Comptes liste2 = liste;
    switch (choix) {
	case 0:
	    liste2 = gestion_menu(liste2, 3);
	    break;
	case 1:
	    numero = numero_compte(liste2);
	    if (numero == 0) {
		liste2 = gestion_menu(liste2, 3);
	    } else if (numero != -1) {
		depenses(compte(liste2, numero));
	    }
	    break;
	case 2:
	    numero = numero_compte(liste2);
	    if (numero == 0) {
		liste2 = gestion_menu(liste2, 3);
	    } else if (numero != -1) {
		rentrees(compte(liste2, numero));
	    }
	    break;
	case 3:
	    numero = numero_compte(liste2);
	    if (numero == 0) {
		liste2 = gestion_menu(liste2, 3);
	    } else if (numero != -1) {
		Compte* c = compte(liste2, numero);
		balance(c);
		afficheBalanceMois(c->liste_op);
		printf("\nEntrez votre choix :\n1. Graphique de la balance mensuelle des categories\n2. Graphique de la balance mensuelle pour une categorie donnee\nTapez 0 pour revenir au menu precedent\n");
		int choix;
		scanf("%d", &choix);
		switch (choix) {
			case 0:
				liste2 = gestion_menu(liste2, 5);
				break;		
			case 1:
				afficheBalanceCategories(c->liste_op);
				break;
			case 2:
				printf("Choisissez parmi les catégories :\n");
				affiche_categories();
				scanf("%d", &choix);
				afficheBalanceMoisCategorie(c->liste_op, choix-1);
				break;
			default:
				printf("L'action choisie n'existe pas");
				break;
		}
	    }
	    break;
	default:
    	    printf("L'action choisie n'existe pas");
    	    break;
    }
    return liste2;
}

long numero_compte(Comptes liste) {
    long numero;
    printf("Entrez le numero du compte (10 chiffres) (Tapez 0 pour revenir au menu precedent) : ");
    scanf("%ld", &numero);
    if (numero != 0) {
	if (taille_long(numero) != 10) {
	    printf("Le numero de compte est invalide\n");
	    numero = -1;
        } else {
	    if (compte(liste, numero) == NULL) {
		printf("Le compte n'existe pas\n");
	        numero = -1;	
	    }
	}
    }
    return numero;
}

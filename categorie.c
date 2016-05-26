#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "categorie.h"

#define NB_CAT 9
#define NB_MAX_SSCAT 7

void affiche_categories(int affichage) {
    if (affichage) {
	printf("Les categories sont :\n");
    }
    printf("1.Vie Quotidienne\n2.Loisirs\n3.Sante\n4.Habitation\n5.Transports\n6.Impots & Solidarite\n7.Professionel\n8.Epargne\n9.Divers\n");
}

void affiche_sousCategories(Categorie cat, int affichage) {
    switch (cat) {
	case QUOTIDIEN:
	    if (affichage) {
			printf("Les sous-categories de Vie Quotidienne sont :\n");
	    }
	    printf("1.Alimentation\n2.Habillement\n3.Banque\n29.Divers\n");
	    break;
	case LOISIRS:
	    if (affichage) {
			printf("Les sous-categories de Loisirs sont :\n");
	    }
	    printf("4.Culture\n5.Presse\n6.Restaurants & Sorties\n7.Week-ends & Vacances\n8.Cadeaux\n29.Divers\n");    	    
	    break;
	case SANTE:
	    if (affichage) {
			printf("Les sous-categories de Sante sont :\n");
	    }
	    printf("9.Medecins\n10.Pharmacie\n11.Securite sociale & Mutuelles\n29.Divers\n");    	    
	    break;
	case HABITATION:
	    if (affichage) {
			printf("Les sous-categories de Habitation sont :\n");
	    }
	    printf("12.Loyer\n13.Gaz & Electricite\n14.Eau\n15.Telephonie & Internet\n16.Assurances\n6.Divers\n");     	    
	    break;
	case TRANSPORTS:
	    if (affichage) {
			printf("Les sous-categories de Habitation sont :\n");
	    }
	    printf("17.Abonnements\n18.Billets\n19.Parking\n20.Carburant\n21.Entretien\n16.Assurances\n29.Divers\n");    	    
	    break;
	case IMPOTS_SOLIDARITE:
	    if (affichage) {
			printf("Les sous-categories de Impots & Solidarite sont :\n");
	    }
	    printf("22.Impot sur le revenu\n23.Taxes foncieres\n24.Taxe d'habitation\n25.Dons\n29.Divers\n");    	    
	    break;
	case PROFESSIONNEL:
	    if (affichage) {
			printf("Les sous-categories de Professionnel sont :\n");
	    }
	    printf("26.Materiel\n27.Repas\n28.Voyages\n29.Divers\n");   
	    break;
	case EPARGNE:
    	printf("La categorie Epargne n'a pas de sous-categories, entrez 0\n");    	    
	    break;
	case DIVERS:
    	printf("La categorie Divers n'a pas de sous-categories, entrez 0\n");    	    
	    break;
	default:
		break;
    }
}

void gestion_categories() {
    int choix;
    printf("Choisissez parmi les categories suivantes :\n");
    affiche_categories(0);
    scanf("%d", &choix);
    printf("\n");
    switch (choix) {
	case 1:
	    printf("Choisissez parmi les sous-categories suivantes :\n");
    	affiche_sousCategories(QUOTIDIEN, 0);
	    scanf("%d", &choix);
	    break;
	case 2:
	    printf("Choisissez parmi les sous-categories suivantes :\n");
	    affiche_sousCategories(LOISIRS, 0);   
	    scanf("%d", &choix);	    
	    break;
	case 3:
	    printf("Choisissez parmi les sous-categories suivantes :\n");
	    affiche_sousCategories(SANTE, 0);  
	    scanf("%d", &choix);  	    
	    break;
	case 4:
	    printf("Choisissez parmi les sous-categories suivantes :\n");
	    affiche_sousCategories(HABITATION, 0); 
	    scanf("%d", &choix);   	    
	    break;
	case 5:
	    printf("Choisissez parmi les sous-categories suivantes :\n");
	    affiche_sousCategories(TRANSPORTS, 0); 
	    scanf("%d", &choix);   	    
	    break;
	case 6:
	    printf("Choisissez parmi les sous-categories suivantes :\n");
	    affiche_sousCategories(IMPOTS_SOLIDARITE, 0);   
	    scanf("%d", &choix); 	    
	    break;
	case 7:
	    printf("Choisissez parmi les sous-categories suivantes :\n");
 	    affiche_sousCategories(PROFESSIONNEL, 0);   
	    scanf("%d", &choix);	    
	    break;
	case 8:
	    affiche_sousCategories(EPARGNE, 0);
	    break;
	case 9:
	    affiche_sousCategories(DIVERS, 0);    	    
	    break;
	default:
    	    printf("La categorie choisie n'existe pas\n");
    	    break;
    }
}

char* nom_cat(Categorie cat) {
    char* nom = NULL;
    switch (cat) {
	case QUOTIDIEN:
	    nom = "Vie Quotidienne";
	    break;
	case LOISIRS:
	    nom = "Loisirs";    	    
	    break;
	case SANTE:
	    nom = "Sante";    	    
	    break;
	case HABITATION: 
	    nom = "Habitation";  	    
	    break;
	case TRANSPORTS: 
	    nom = "Transports";  	    
	    break;
	case IMPOTS_SOLIDARITE:
	    nom = "Impots & Solidarite";   	    
	    break;
	case PROFESSIONNEL: 
	    nom = "Professionnel";  
	    break;
	case EPARGNE: 
	    nom = "Epargne";   	    
	    break;
	case DIVERS:
	    nom = "Divers";    	    
	    break;
	case AUCUN:
	    nom = "Aucune";    	    
	    break;
	default:
    	    printf("La categorie n'existe pas\n");
    	    break;
    }
    return nom;
}

char* nom_sousCat(SousCategorie sscat) {
    char* nom = NULL;
    switch (sscat) {
	case ALIMENTATION:
	    nom = "Alimentation";
	    break;
	case BANQUE:
	    nom = "Banque";    	    
	    break;
	case CULTURE:
	    nom = "Culture";    	    
	    break;
	case PRESSE: 
	    nom = "Presse";  	    
	    break;
	case RESTAURANTS_SORTIES: 
	    nom = "Restaurants & Sorties";  	    
	    break;
	case WEEKENDS_VACANCES:
	    nom = "Week-ends & Vacances";   	    
	    break;
	case CADEAUX: 
	    nom = "Cadeaux";  
	    break;
	case MEDECINS: 
	    nom = "Medecins";   	    
	    break;
	case PHARMACIE: 
	    nom = "Pharmacie";   	    
	    break;
	case SECU_MUTUELLES: 
	    nom = "Sécurite sociale & Mutuelles";   	    
	    break;
	case LOYER: 
	    nom = "Loyer";   	    
	    break;
	case GAZ_ELECTRICITE: 
	    nom = "Gaz & Electricite";   	    
	    break;
	case EAU: 
	    nom = "Eau";   	    
	    break;
	case TELEPHONIE_INTERNET: 
	    nom = "Telephonie & Internet";   	    
	    break;
	case ASSURANCES: 
	    nom = "Assurances";   	    
	    break;
	case ABONNEMENTS: 
	    nom = "Abonnements";   	    
	    break;
	case BILLETS: 
	    nom = "Billets";   	    
	    break;
	case PARKING: 
	    nom = "Parking";   	    
	    break;
	case CARBURANT: 
	    nom = "Carburant";   	    
	    break;
	case ENTRETIEN: 
	    nom = "Entretien";   	    
	    break;
	case IR: 
	    nom = "Impot sur le Revenu";   	    
	    break;
	case FONCIER: 
	    nom = "Taxes foncieres";   	    
	    break;
	case HABITATION2: 
	    nom = "Taxe d'habitation";   	    
	    break;
	case DONS: 
	    nom = "Dons";   	    
	    break;
	case MATERIEL: 
	    nom = "Materiel";   	    
	    break;
	case REPAS: 
	    nom = "Repas";   	    
	    break;
	case VOYAGES: 
	    nom = "Voyages";   	    
	    break;
	case DIVERS2:
	    nom = "Divers";    	    
	    break;
	case AUCUN2:
	    nom = "Aucune";    	    
	    break;
	default:
    	    printf("La categorie n'existe pas\n");
    	    break;
    }
    return nom;
}


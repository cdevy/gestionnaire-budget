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
	    printf("1.Alimentation\n2.Habillement\n3.Banque\n4.Divers\n");
	    break;
	case LOISIRS:
	    if (affichage) {
		printf("Les sous-categories de Loisirs sont :\n");
	    }
	    printf("1.Culture\n2.Presse\n3.Restaurants & Sorties\n4.Week-ends & Vacances\n5.Cadeaux\n6.Divers\n");    	    
	    break;
	case SANTE:
	    if (affichage) {
		printf("Les sous-categories de Sante sont :\n");
	    }
	    printf("1.Medecins\n2.Pharmacie\n3.Securite sociale & Mutuelles\n4.Divers\n");    	    
	    break;
	case HABITATION:
	    if (affichage) {
		printf("Les sous-categories de Habitation sont :\n");
	    }
	    printf("1.Loyer\n2.Gaz & Electricite\n3.Eau\n4.Telephonie & Internet\n5.Assurances\n6.Divers\n");     	    
	    break;
	case TRANSPORTS:
	    if (affichage) {
		printf("Les sous-categories de Habitation sont :\n");
	    }
	    printf("1.Abonnements\n2.Billets\n3.Parking\n4.Carburant\n5.Entretien\n6.Assurances\n7.Divers\n");    	    
	    break;
	case IMPOTS_SOLIDARITE:
	    if (affichage) {
		printf("Les sous-categories de Impots & Solidarite sont :\n");
	    }
	    printf("1.Impot sur le revenu\n2.Taxes foncieres\n3.Taxe d'habitation\n4.Dons\n5.Divers\n");    	    
	    break;
	case PROFESSIONNEL:
	    if (affichage) {
		printf("Les sous-categories de Professionnel sont :\n");
	    }
	    printf("1.Materiel\n2.Repas\n3.Voyages\n4.Divers\n");   
	    break;
	case EPARGNE:
    	    printf("La categorie Epargne n'a pas de sous-categories\n");    	    
	    break;
	case DIVERS:
    	    printf("La categorie Divers n'a pas de sous-categories\n");    	    
	    break;
	default:
    	    printf("La categorie n'existe pas\n");
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
	default:
    	    printf("La categorie n'existe pas\n");
    	    break;
    }
    return nom;
}


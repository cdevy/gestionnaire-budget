#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "categorie.h"

Categorie** initialiser_categories(int taille) {
    Categorie** categories = (Categorie*) malloc(sizeof(Categorie)*taille); 
    int nbCategories = 0;
    return categories;  
}

Categorie* ajout_categorie(char* nom, int taille) {
    Categorie* c = (Categorie*) malloc(sizeof(Categorie));
    if (c != NULL) {
        c->nom = (char *) malloc((strlen(nom) + 1)*sizeof(char));
        strcpy(c->nom, nom);
        SousCategorie* sousCategories = (SousCategorie*) malloc(sizeof(SousCategorie)*taille);
        c->nbSsCategories = 0;
	nbCategories ++;
    } else {
	free(c);
    }
    return c;
}

SousCategorie* ajout_sousCategorie(Categorie* c, char* nom) {
    SousCategorie* ssc = (SousCategorie*) malloc(sizeof(SousCategorie));
    if (ssc != NULL) {
        ssc->nom = (char *) malloc((strlen(nom) + 1)*sizeof(char));
        strcpy(ssc->nom, nom);
	c->sousCategories[c->nbSsCategories] = ssc;
        c->nbSsCategories ++;
    } else {
	free(ssc);
    }
    return ssc;
}

void affiche_categories() {
    /* affiche menu */
}

void budget_max(Categorie c) {
}

int main() {
    Categorie* categories = initialiser_categories(10);
    if (categories != NULL) {
	categories[nbCategories] = ajout_categorie("Vie quotidienne", 5);
	ajout_ss_categorie(categories[0], "Alimentation");
	ajout_ss_categorie(categories[0], "Habillement");
	printf("La liste contient %d categorie(s).\n", nbCategories);
	printf("La premiere categorie est : %s et contient %d sous-categories.\n", categories[0]->nom, categories[0]->nbSsCategories);
	printf("Les sous-categories de c1 sont : %s et %s.\n", (categories[0]->sousCategories[0])->nom, (categories[0]->sousCategories[1])->nom;
	/*categories[1] = ajout_categorie(liste, "Loisirs", 5);*/
    }
    return 0;
}


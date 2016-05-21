#ifndef CATEGORIE_H_INCLUDED
#define CATEGORIE_H_INCLUDED

/*
Definit les categories et sous-categories
Permet de classer les operations et de fixer un budget par categorie
*/

typedef struct Categories {
    Categorie* categories;
    int nbCategories; /* nb de categories creees */
} Categories;

typedef struct Categorie {
    char* nom;
    double budgetMax;
    SousCategorie* sousCategories;
    int nbSsCategories; /* nb de sous-categories creees */
} Categorie;

typedef struct SousCategorie {
    char* nom;
    double budgetMax;
} SousCategorie;

Categorie* ajout_categorie(char*, int taille);

SousCategorie* ajout_sousCategorie(Categorie* c, char* nom);

void affiche_categories();

double budget_max(Categorie c);

void setBudget_max(Categorie c, double max);

void affiche_operations(SousCategorie ssc);

#endif

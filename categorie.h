#ifndef CATEGORIE_H_INCLUDED
#define CATEGORIE_H_INCLUDED

/*
Definit les categories et sous-categories
Permet de classer les operations et de fixer un budget par categorie
*/

typedef enum Categorie {QUOTIDIEN, LOISIRS, SANTE, HABITATION, TRANSPORTS, IMPOTS_SOLIDARITE, PROFESSIONNEL, EPARGNE, DIVERS} Categorie;

typedef enum SousCategorie1 {ALIMENTATION, HABILLEMENT, BANQUE, DIVERS1} SousCategorie1;

typedef enum SousCategorie2 {CULTURE, PRESSE, RESTAURANTS_SORTIES, WEEKENDS_VACANCES, CADEAUX, DIVERS2} SousCategorie2;

typedef enum SousCategorie3 {MEDECINS, PHARMACIE, SECU_MUTUELLES, DIVERS3} SousCategorie3;

typedef enum SousCategorie4 {LOYER, GAZ_ELECTRICITE, EAU, TELEPHONIE_INTERNET, ASSURANCES4, DIVERS4} SousCategorie4;

typedef enum SousCategorie5 {ABONNEMENTS, BILLETS, PARKING, CARBURANT, ENTRETIEN, ASSURANCES5, DIVERS5} SousCategorie5;

typedef enum SousCategorie6 {IR, FONCIER, HABITATION6, DONS, DIVERS6} SousCategorie6;

typedef enum SousCategorie7 {MATERIEL, REPAS, VOYAGES, DIVERS7} SousCategorie7;

void gestion_categories();

void affiche_categories(int affichage);

void affiche_sousCategories(Categorie cat, int affichage);

double budget_max(Categorie cat);

void setBudget_max(Categorie cat, double max);

//void affiche_operations(Categorie cat);

#endif

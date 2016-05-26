#ifndef CATEGORIE_H_INCLUDED
#define CATEGORIE_H_INCLUDED

/*
Definit les categories et sous-categories
Permet de classer les operations et de fixer un budget par categorie
*/

typedef enum Categorie {QUOTIDIEN, LOISIRS, SANTE, HABITATION, TRANSPORTS, IMPOTS_SOLIDARITE, PROFESSIONNEL, EPARGNE, DIVERS, AUCUN} Categorie;

typedef enum SousCategorie {ALIMENTATION, HABILLEMENT, BANQUE, CULTURE, PRESSE, RESTAURANTS_SORTIES, WEEKENDS_VACANCES, CADEAUX, MEDECINS, PHARMACIE, SECU_MUTUELLES, LOYER, GAZ_ELECTRICITE, EAU, TELEPHONIE_INTERNET, ASSURANCES, ABONNEMENTS, BILLETS, PARKING, CARBURANT, ENTRETIEN, IR, FONCIER, HABITATION2, DONS, MATERIEL, REPAS, VOYAGES, DIVERS2, AUCUN2} SousCategorie;

void gestion_categories();

void affiche_categories(int affichage);

void affiche_sousCategories(Categorie cat, int affichage);

char* nom_cat(Categorie cat);

char* nom_sousCat(SousCategorie sscat);

//void affiche_operations(Categorie cat);

#endif

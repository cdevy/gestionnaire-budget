#ifndef CATEGORIE_H_INCLUDED
#define CATEGORIE_H_INCLUDED

/*
D�finit les cat�gories et sous-cat�gories
*/

typedef struct Categorie Categorie;
typedef struct SousCategorie SousCategorie;

struct Categorie {
    char nom[32];
};

struct SousCategorie {
    char nom[32];
    Categorie categorie;
};

void budget_max(Categorie c);

void affiche_operations(Categorie c);

void affiche_operations(SousCategorie ssc);

#endif // CATEGORIE_H_INCLUDED

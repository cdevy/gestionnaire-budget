#include <stdio.h>
#include <stdlib.h>
#include "statistiques.h"
#include "compte.h"
#include "operation.h"
#include "categorie.h"
#define NB_CAT 9

int menu_stats() {
    int choix;
    printf("Entrez votre choix :\n1.Depenses mensuelles\n2.Rentrees mensuelles\n3.Balance mensuelle\n4.Depenses mensuelles d'une categorie\n5.Rentrees mensuelles d'une categorie\nTapez 0 pour revenir au menu precedent\n");
    scanf("%d", &choix);
    printf("\n");
    return choix;
}

void depenses(Compte* c) {
    Operation* op = c->liste_op;
    double depenses = 0;
    while (op != NULL) {
	if (op->type == DEBIT) {
	    depenses += op->valeur;
	}
	op = op->next;
    }
    printf("Vous avez depense %f€ ce mois-ci dont :\n", depenses);
    int i;
    double depensesCat = 0;
    for (i=0; i<NB_CAT; i++) {
	depensesCat = depenses_categorie(c, i, 0)*100/depenses;
	printf("%f en %s\n", depenses, nom_cat(i));
    }
}

void rentrees(Compte* c) {
    Operation* op = c->liste_op;
    double rentrees = 0;
    while (op != NULL) {
	if (op->type == CREDIT) {
	    rentrees += op->valeur;
	}
	op = op->next;
    }
    printf("Vous avez gagne %f€ ce mois-ci dont :\n", rentrees);
    int i;
    double rentreesCat = 0;
    for (i=0; i<NB_CAT; i++) {
	rentreesCat = rentrees_categorie(c, i, 0)*100/rentrees;
	printf("%f en %s\n", rentrees, nom_cat(i));
    }
}

void balance(Compte* c) {
    Operation* op = c->liste_op;
    double balance = 0;
    while (op != NULL) {
	switch (op->type) {
	    case DEBIT:
		balance -= op->valeur;
		break;
	    case CREDIT:
		balance += op->valeur;
		break;
	    default:
		printf("Erreur : type inconnu");
		break;
	}
	op = op->next;
    }
    printf("Votre balance mensuelle est de %f€\n", balance);
}

double depenses_categorie(Compte* c, Categorie cat, int affichage) {
    Operation* op = c->liste_op;
    double depenses = 0;
    while (op != NULL) {
	if (op->type == DEBIT) {
	    depenses += op->valeur;
	}
	op = op->next;
    }
    if (affichage) {
        printf("Vous avez depense ce mois-ci %f€ en %s\n", depenses, nom_cat(cat));
    }
    return depenses;
}

double rentrees_categorie(Compte* c, Categorie cat, int affichage) {
    Operation* op = c->liste_op;
    double rentrees = 0;
    while (op != NULL) {
	if (op->type == CREDIT) {
	    rentrees += op->valeur;
	}
	op = op->next;
    }
    if (affichage) {
        printf("Vous avez gagne ce mois-ci %f€ en %s\n", rentrees, nom_cat(cat));
    }
    return rentrees;
}

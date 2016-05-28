#include <stdio.h>
#include <stdlib.h>
#include "statistiques.h"
#include "compte.h"
#include "operation.h"
#include "categorie.h"
#define NB_CAT 9

int menu_stats() {
    int choix;
    printf("Entrez votre choix :\n1.Depenses mensuelles\n2.Rentrees mensuelles\n3.Balance mensuelle\nTapez 0 pour revenir au menu precedent\n");
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
    if (depenses == 0) {
        printf("Vous n'avez rien depense ce mois-ci\n");
    } else {
        printf("Vous avez depense %f€ ce mois-ci dont :\n", depenses);
        int i;
        double depensesCat = 0;
        double pourcent = 0;
        for (i=0; i<NB_CAT; i++) {
	    depensesCat = depenses_categorie(c, i);
	    pourcent = depenses_categorie(c, i)*100/depenses;
	    printf("%.2f€ en %s (soit %.2f%%)\n", depensesCat, nom_cat(i), pourcent);
        }
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
    if (rentrees == 0) {
        printf("Vous n'avez rien gagne ce mois-ci\n");
    } else {
        printf("Vous avez gagne %f€ ce mois-ci dont :\n", rentrees);
        int i;
        double rentreesCat = 0;
        double pourcent = 0;
        for (i=0; i<NB_CAT; i++) {
	    rentreesCat = rentrees_categorie(c, i);
	    pourcent = rentrees_categorie(c, i)*100/rentrees;
	    printf("%.2f€ en %s (soit %.2f%%)\n", rentreesCat, nom_cat(i), pourcent);
        }
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

double depenses_categorie(Compte* c, Categorie cat) {
    Operation* op = c->liste_op;
    double depenses = 0;
    while (op != NULL) {
	if (op->type == DEBIT && op->categorie == cat) {
	    depenses += op->valeur;
	}
	op = op->next;
    }
    return depenses;
}

double rentrees_categorie(Compte* c, Categorie cat) {
    Operation* op = c->liste_op;
    double rentrees = 0;
    while (op != NULL) {
	if (op->type == CREDIT && op->categorie == cat) {
	    rentrees += op->valeur;
	}
	op = op->next;
    }
    return rentrees;
}

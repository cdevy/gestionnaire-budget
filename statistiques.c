#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statistiques.h"
#include "compte.h"
#include "operation.h"
#include "categorie.h"

#define NB_CAT 9

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
        int i;
        double balanceCat = 0;
        for (i=0; i<NB_CAT; i++) {
	    balanceCat = rentrees_categorie(c, i) - depenses_categorie(c, i);
	    printf("%.2f€ en %s\n", balanceCat, nom_cat(i));
	}
}

double depenses_categorie(Compte* c, Categorie cat) {
	Operation* op = c->liste_op;
	double max = c->budgetsMax[cat];
	double depenses = 0;
	while (op != NULL) {
		if (op->type == DEBIT && op->categorie == cat) {
	    		depenses += op->valeur;
		}
		op = op->next;
    	}
	/* S'il existe un budget max, alerte s'il est depasse */
	if (max != -1 && depenses >= max) {
	    printf("ALERTE : Le budget max de la categorie %s a ete depasse !\n", nom_cat(cat));
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

double balanceJour(Operation* list, int jour) {
	if (jour <0 || jour >31) {
		printf("Ce jour n'existe pas ! Vous devez entrer un entier entre 1 et 31...");
		exit(0);
	} else {
		double result = 0;
		Operation *i;
		for(i=list;i!=NULL;i=i->next) {
			char tmp[3];
			tmp[0] = i->date[0];
			tmp[1] = i->date[1];
			tmp[2] = '\0';
			int j = atoi(tmp);
			if (jour == j) {
				switch (i-> type){
					case DEBIT:
						result -= i->valeur;
						break;
					case CREDIT:
						result += i->valeur; 
						break;
					default:
						break;
				}
			}
		}
		return result;
	}
	return 0;
}

double balanceJourCategorie(Operation* list, int jour, Categorie cat) {
	if (jour <0 || jour >31) {
		printf("Ce jour n'existe pas ! Vous devez rentrer un entier entre 1 et 31...");
		exit(0);
	} else {
		double result = 0;
		Operation *i;
		for(i=list;i!=NULL;i=i->next) {
			char tmp[3];
			tmp[0] = i->date[0];
			tmp[1] = i->date[1];
			tmp[2] = '\0';
			int j = atoi(tmp);
			if (jour == j && i->categorie == cat) {
				switch (i-> type){
					case DEBIT:
						result -= i->valeur;
						break;
					case CREDIT:
						result += i->valeur; 
						break;
					default:
						break;
				}
			}
		}
		return result;
	}
	return 0;
}

double balanceMois(Operation* list) {
	double result = 0;
	Operation *i;
	for(i=list; i!=NULL; i=i->next) {
		switch (i-> type){
			case DEBIT:
				result -= i->valeur;
				break;
			case CREDIT:
				result += i->valeur; 
				break;
			default:
				break;
		}
	}
	return result;
}

double balanceMoisCategorie(Operation* list, Categorie cat) {
	double result = 0;
	Operation *i;
	for(i=list; i!=NULL; i=i->next) {
		if (i->categorie == cat) {
			switch (i-> type) {
				case DEBIT:
					result -= i->valeur;
					break;
				case CREDIT:
					result += i->valeur; 
					break;
				default:
					break;
			}
		}
	}
	return result;
}

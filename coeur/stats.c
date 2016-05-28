#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include "operation.h"
#include "operation.c"

double depensesJour(Operation* list, int jour) {
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

double depensesJourCategorie(Operation* list, int jour, Categorie cat) {
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

double depensesMois(Operation* list) {
	double result = 0;
	Operation *i;
	for(i=list;i!=NULL;i=i->next) {
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

double depensesMoisCategorie(Operation* list, Categorie cat) {
	double result = 0;
	Operation *i;
	for(i=list;i!=NULL;i=i->next) {
		if (i->categorie == cat) {
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

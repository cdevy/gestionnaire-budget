#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include "operation.h"
#include "operation.c"

double depensesParMois(Operation* list, int mois) {
	if (mois <0 || mois >12) {
		printf("Ce mois n'existe pas ! Vous devez entrer un entier entre 1 et 12...");
		exit(0);
	} else {
		double result = 0;
		Operation *i;
		int j,m,a;
		for(i=list;i!=NULL;i=i->next) {
			sscanf(i->date,"%i/%i/%i",&j,&m,&a);
			if (mois == m) {
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

double depensesParCategorieParMois(Operation* list, int mois, Categorie cat) {
	if (mois <0 || mois >12) {
		printf("Ce mois n'existe pas ! Vous devez rentrer un entier entre 1 et 12...");
		exit(0);
	} else {
		double result = 0;
		Operation *i;
		int j,m,a;
		for(i=list;i!=NULL;i=i->next) {
			sscanf(i->date,"%i/%i/%i",&j,&m,&a);
			if (mois == m && i->categorie == cat) {
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


int main (void){
	Operation * o = ParserOperation("test.csv");
	if (o != NULL){
		afficheOperations(o);
	}
	int test;
	printf("\nRentrez le mois dont vous souhaitez consulter vos dépenses sous la forme d'un entier : ");
	scanf("%d",&test);
	double r = depensesParMois(o,test);
	printf("\nLes dépenses du mois %d sont de :%.2f", test, r);
	return EXIT_SUCCESS;
}

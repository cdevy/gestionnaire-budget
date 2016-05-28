#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include "operation.h"
#include "stats.c"

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

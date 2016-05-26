#include <stdio.h>
#include <stdlib.h>
#include "statistiques.h"
#include "compte.h"
#include "operation.h"

void statistiques(Compte* c) {
    Operation* op = c->liste_op;
    double depenses = 0;
    double rentrees = 0;
    while (op != NULL) {
	switch (op->type) {
	    case DEBIT:
		depenses = depenses + op->valeur;
		break;
	    case CREDIT:
		rentrees = rentrees + op->valeur;
		break;
	    default:
		printf("Erreur : type inconnu");
		break;
	}
	op = op->next;
    }
    printf("Vous avez depense %f€ et gagne %f€ ce mois-ci", depenses, rentrees);
}

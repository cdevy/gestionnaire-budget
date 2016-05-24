#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "categorie.h"
#include "operation.h"

Operation* nouvelle_operation(char D[9], char t[32], Type_operation type, double valeur, Operation *suivant) {
    Operation *o = (Operation*) malloc(sizeof(Operation));
    strcpy(o -> date, D);
    strcpy(o -> titre, t);
    o -> type = type;
    o -> valeur = valeur;
    o -> categorie = AUCUN;
    o -> sousCategorie = AUCUN2;
    o -> next = suivant;
    return o;
}

void retirer_operation(Operation *op, Operation *list) {
	Operation *i, *tmp;
	for(i=list;i!=NULL;i=i->next) { //on parcourt chacun des éléments de la LinkedList grâce aux pointeurs car les pointeurs c'est kakoii
		if((i->next)==op){
			tmp = i->next;
			i->next = i->next->next;
			free(tmp);
		}
	}
}

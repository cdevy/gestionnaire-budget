#include "operation.h"

Operation* nouvelle_operation(char D[9], char t[32], double d, double c, Categorie cat, Operation *suivant) {
    Operation *o = (Operation*) malloc(sizeof(Operation));
    strcpy(o -> date, D);
    strcpy(o -> titre, t);
    o -> debit = d;
    o -> credit = c;
    o -> categorie = cat;
    o -> next = suivant;
    return o;
}

void retirer_operation(Operation *op, Operation *list) {
	Operation *i, *tmp;
	if(list==op){
		tmp = list;
		list = list->next;
		free(tmp);
		
	} else {
		for(i=list;i!=NULL;i=i->next) { //on parcourt chacun des éléments de la LinkedList grâce aux pointeurs car les pointeurs c'est kakoii
			if((i->next)==op){
				tmp = i->next;
				i->next = i->next->next;
				free(tmp);
			}
		}
	}
}

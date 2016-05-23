#ifndef OPERATION_H_INCLUDED
#define OPERATION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "categorie.h"

/*
Définit une opération
*/
//voir pour faire l'enumeration debit credit !


typedef struct Operation Operation;

struct Operation {
    char date[9];
    char titre[32];
    double debit;
    double credit;
    Categorie categorie;
    Operation *next; //pointe vers la prochaine opération 
};

Operation* nouvelle_operation(char D[9], char t[32], double d, double c, Categorie cat, Operation *suivant);

void retirer_operation(Operation *op,Operation *list);
#endif // OPERATION_H_INCLUDED

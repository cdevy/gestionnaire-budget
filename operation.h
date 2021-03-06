#ifndef OPERATION_H_INCLUDED
#define OPERATION_H_INCLUDED
#include "categorie.h"

typedef enum Type_operation {DEBIT, CREDIT} Type_operation;

typedef struct Operation Operation;

struct Operation {
    char date[9];
    char titre[32];
    Type_operation type;
    double valeur;
    Categorie categorie;
    SousCategorie sousCategorie;
    Operation *next; //pointe vers la prochaine operation 	
};	

Operation* nouvelle_operation(char* D, char* t, Type_operation type, double valeur, Categorie cat, SousCategorie sousCat,Operation *suivant);
	
void retirer_operation(Operation *op, Operation *list);

Operation* ParserOperation (const char * nomDuFichier);

void afficheOperations(Operation *list);

#endif

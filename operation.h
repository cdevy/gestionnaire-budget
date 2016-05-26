#ifndef OPERATION_H_INCLUDED
#define OPERATION_H_INCLUDED

#include "categorie.h"

/*
Définit une opération
*/

typedef enum Type_operation {DEBIT, CREDIT} Type_operation;
typedef struct Operation Operation;

struct Operation {
    char* date;
    char* titre;
    Type_operation type;
    double valeur;
    Categorie categorie;
    SousCategorie sousCategorie;
    Operation *next; //pointe vers la prochaine operation 
};

typedef enum
{
   DATE,
   TITRE,
   TYPEOPERATION,
   VALEUR,
   NB_TYPE
}Operation_type;

Operation* nouvelle_operation(char D[9], char t[32], Type_operation type, double valeur, Operation *suivant);

void retirer_operation(Operation *op,Operation *list);

Operation* ParserOperation (const char * nomDuFichier);

void freeOperation (Operation ** p);
#endif // OPERATION_H_INCLUDED

#ifndef OPERATION_H_INCLUDED
#define OPERATION_H_INCLUDED

/*
Définit une opération
*/

typedef enum Type_operation {debit, credit} Type_operation;

typedef struct Operation {
    Date date;
    char titre[32];
    Type_operation type;
    double valeur;
    Categorie categorie;
    SousCategorie sousCategorie;
} Operation;

void ajout(Operation op, Categorie c);

void enleve(Operation op, Categorie c);


#endif // OPERATION_H_INCLUDED

#ifndef OPERATION_H_INCLUDED
#define OPERATION_H_INCLUDED

/*
D�finit une op�ration
*/

typedef struct Operation Operation;

struct Operation {
    Date date;
    char titre[32];
    double debit;
    double credit;
    Categorie categorie;
    SousCategorie sousCategorie;
};

void ajout(Operation op, Categorie c);

void enleve(Operation op, Categorie c);


#endif // OPERATION_H_INCLUDED

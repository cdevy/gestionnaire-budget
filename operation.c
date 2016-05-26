#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operation.h"
#include "categorie.h"


#define DELIM ","
#define BUFF_SIZE 1024


Operation* nouvelle_operation(char* D, char* t, Type_operation type, float valeur, Categorie cat, SousCategorie sousCat, Operation *suivant) {
    Operation *o = (Operation*) malloc(sizeof(Operation));
    strcpy(o -> date, D);
    strcpy(o -> titre, t);
	o -> type = type;
    o -> valeur = valeur;
    o -> categorie = cat;
    o -> sousCategorie = sousCat;
    o -> next = suivant;
    return o;
}


void retirer_operation(Operation *op, Operation *list) {
	Operation *i, *tmp;
	for(i=list;i!=NULL;i=i->next) {
		if((i->next)==op){
			tmp = i->next;
			i->next = i->next->next;
			free(tmp);
		}
	}
}


Operation* ParserOperation (const char * nomDuFichier){
	FILE*  fichier  = NULL;
	char*  date = NULL;
	char*  titre = NULL;
	char*  type = NULL;
	char*  valeur = NULL;
	char   buff [BUFF_SIZE];
	Type_operation type1 = DEBIT ;
	float val =0;
	Operation* op = NULL;

	fichier = fopen(nomDuFichier, "r");

    if (fichier != NULL){
		while(fgets (buff, BUFF_SIZE, fichier)!=NULL){
			char * p = buff;
			date = strtok(p, DELIM);
			titre = strtok(NULL, DELIM);
			type = strtok(NULL, DELIM);
			if (strcmp(type,"DEBIT")==0){
				type1 = DEBIT;
			}else{
				type1 = CREDIT;
			}
			valeur = strtok(NULL, DELIM);
			val = atof(valeur);
			op = nouvelle_operation(date, titre, type1, val, 0, 0, op);
		}
    } else {
		printf("Je n'arrive pas à ouvrir le fichier.");
	}
    fclose (fichier);
	return op;
}


void afficheOperations(Operation *list){
	Operation *i;
	for(i=list;i!=NULL;i=i->next) {
		char* t;
		switch (i-> type){
			case DEBIT:
				t="DEBIT"; 
				break;
			case CREDIT:
				t="CREDIT"; 
				break;
			default:
				break;
		}
		printf ("Date : %s Titre : %s Type : %s Valeur : %.2f Catégorie : %s Sous catégorie : %s\n",
						i->date,i->titre,t,i->valeur,nom_cat(i->categorie),nom_sousCat(i->sousCategorie));
	}
}	

/*
int main (void){
	Operation * o = ParserOperation("test.csv");
	if (o != NULL){
		afficheOperations(o);
	}
	gestion_categories();
	return EXIT_SUCCESS;
}*/



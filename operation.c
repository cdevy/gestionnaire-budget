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
		if ((fgets (buff, BUFF_SIZE, fichier)) != NULL){
			fgets (buff, BUFF_SIZE, fichier);
			char * p = buff;
			date = strtok(p, DELIM);
			printf("%s \n",date);
			titre = strtok(NULL, DELIM);
			printf("%s \n",titre);
			type = strtok(NULL, DELIM);
			if (strcmp(type,"DEBIT")==0){
				type1 = DEBIT;
			}else{
				type1 = CREDIT;
			}
			printf("%d \n",type1);
			valeur = strtok(NULL, DELIM);
			val = atof(valeur);
			printf("%f \n",val);
			op = nouvelle_operation(date, titre, type1, val,0 ,0 , NULL);
		}
    } else {
		printf("Je n'arrive pas à ouvrir le fichier.");
	}
    fclose (fichier);
	return op;
}


int main (void){
   Operation * o = ParserOperation("test.csv");
   if (o != NULL){
      printf ("Date : %s Titre : %s Type : %d Valeur : %f\n", o -> date, o -> titre, o-> type, o -> valeur);
      free(o);
   }
   return EXIT_SUCCESS;
}


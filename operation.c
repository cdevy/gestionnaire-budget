#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operation.h"


#define DELIM ","
#define BUFF_SIZE 1024


Operation* nouvelle_operation(char* D, char* t, Type_operation type, double valeur, Operation *suivant) {
    Operation *o = (Operation*) malloc(sizeof(Operation));
    strcpy(o -> date, D);
    strcpy(o -> titre, t);
    o -> type = type;
    o -> valeur = valeur;
    //o -> categorie = AUCUN;
    //o -> sousCategorie = AUCUN2;
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
	Operation* o = NULL;
	FILE*  fichier  = NULL;
	char*  date = NULL;
	char*  titre = NULL;
	char*  type = NULL;
	char*  valeur = NULL;
	char   buff [BUFF_SIZE];
	Type_operation type1 = DEBIT ;
	double val =0;
	Operation* op = NULL;

	fichier = fopen(nomDuFichier, "r");

    if (fichier != NULL){
		if ((fgets (buff, BUFF_SIZE, fichier)) != NULL){
			fgets (buff, BUFF_SIZE, fichier);
			char * p = buff;
			int i = 0;
			o = (Operation *)malloc(sizeof (Operation));
			
			if (o != NULL){
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
				  printf("%s \n",type);
				  valeur = strtok(NULL, DELIM);
				  printf("%s \n",valeur);
				  
				  //val = atof(valeur);
				  //op = nouvelle_operation(date, titre, type1, val, NULL);
         }
      }
      fclose (fichier);
   }
   else{
        
        printf("Impossible d'ouvrir le fichier %s", nomDuFichier);
    }
   return o;
}

void freeOperation (Operation ** p){
   if (p != NULL && *p != NULL){
      free ((*p)->date);
      free ((*p)->titre);
      free (*p);
      *p = NULL;
   }
}


int main (void){
   Operation * o = ParserOperation("test.csv");
   if (o != NULL){
      printf ("Date : %s Titre : %s Type : %s Valeur : %d\n", o -> date, o -> titre, o-> type, o -> valeur);
      freeOperation (& o);
   }
   return EXIT_SUCCESS;
}


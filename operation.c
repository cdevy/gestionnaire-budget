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


char * str_dup (const char * str)
{
   char * dup = NULL;
   if (str != NULL)
   {
      size_t size = strlen (str) + 1;
      dup = malloc (size);
      if (dup != NULL)
      {
         memcpy (dup, str, size);
      }
   }
   return dup;
}


Operation* ParserOperation (const char * nomDuFichier){
	int  categorie;
	int  sousCategorie;
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
				
				  titre = strtok(NULL, DELIM);
				
				  type = strtok(NULL, DELIM);
				  if (strcmp(type,"DEBIT")==0){
								type1 = DEBIT;
							}else{
								type1 = CREDIT;
							}
				
				  valeur = strtok(NULL, DELIM);
				  val = atof(valeur);
				  op = nouvelle_operation(date, titre, type1, val, NULL);
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


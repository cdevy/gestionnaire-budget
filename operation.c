#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "categorie.h"
#include "operation.h"


#define DELIM ";"
#define BUFF_SIZE 128


Operation* nouvelle_operation(char* D, char* t, Type_operation type, double valeur, Operation *suivant) {
    Operation *o = (Operation*) malloc(sizeof(Operation));
    strcpy(o -> date, D);
    strcpy(o -> titre, t);
    o -> type = type;
    o -> valeur = valeur;
    o -> categorie = QUOTIDIEN;
    o -> sousCategorie = ALIMENTATION;
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


static char * str_dup (const char * str)
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



static Operation* ParserOperation (const char * nomDuFichier){
	char*  categorie;
	char*  sousCategorie;
	Operation* o = NULL;
	FILE*  fichier  = NULL;
	char*  token = NULL;
	char   buff [BUFF_SIZE];

	fichier = fopen(nomDuFichier, "r");


    if (fichier != NULL){
		if ((fgets (buff, BUFF_SIZE, fichier)) != NULL){
			char * p = buff;
			int i = 0;
			
			o = (Operation *)malloc(sizeof (* o));
			
			if (o != NULL){
				while ((token = strtok(p, DELIM)) != NULL){
					if (i == 0){ p = NULL; }
					char * tmp;
					double valeur;
					switch (i){
						case DATE:
							o -> date = str_dup (token);
							break;
                     
						case TITRE:
							o -> titre = str_dup (token);
							break;

						case TYPEOPERATION:
							tmp = str_dup (token);
							if (strcmp(tmp,"DEBIT")==0){
								o -> type = DEBIT;
							}else{
								o -> type = CREDIT;
							}
							break;
                     
						case VALEUR:
							valeur = strtol (token, NULL, 10);
							o -> valeur = valeur;              
							break;
							
						default:
							break;
               }
               printf("veuillez entrer une catégorie \n");
			   scanf("%s", &categorie);
			   o -> categorie = categorie;
			   printf("veuillez entrer une sous catégorie \n");
			   scanf("%s", &sousCategorie);
			   o -> sousCategorie = sousCategorie;
               i++;
            }
         }
      }
      fclose (fichier);
   }
   else{
        
        printf("Impossible d'ouvrir le fichier %s", nomDuFichier);
    }
   return o;
}


static void freeOperation (Operation ** p){
   if (p != NULL && *p != NULL){
      free ((*p)->date);
      free ((*p)->titre);
      free ((*p)->type);
      free ((*p)->valeur);
      free (*p);
      *p = NULL;
   }
}


int main (void){
   Operation * o = ParserOperation("Relevé.csv");
   if (o != NULL){
      printf ("Date : %s Titre : %s Type : %s Valeur : %d\n", o -> date, o -> titre, o-> type, o -> valeur);
      freeOperation (& o);
   }
   return EXIT_SUCCESS;
}


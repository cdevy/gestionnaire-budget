#include <stdlib.h>
#include <stdio.h>


//Une fois qu'on a terminé de travailler sur le fichier, on ferme le fichier.


int main(int argc, char **argv)
{
	const char* nomDuFichier;
	scanf("veuillez entrer le chemin de votre relever de compte %d", nomDuFichier); 
	
	
	//On appelle la fonction d'ouverture de fichier fopen qui nous renvoie un pointeur sur le fichier.	
    FILE* fichier = NULL;
    fichier = fopen(nomDuFichier, "r");
	
	
	//On vérifie si le fichier existe en testant la valeur du pointeur qu'on a reçu. 
	//Si le pointeur est différent de NULL,
	//alors on peut lire dans le fichier
    if (fichier != NULL)
    {
        
  
        
        fclose(fichier);
    }
    
    //Si le pointeur vaut NULL, c'est que l'ouverture du fichier n'a pas fonctionné
    else
    {
        // Message d'erreur
        printf("Impossible d'ouvrir le fichier %d", nomDuFichier);
    }

    return 0;
}


FILE *fichier;
        char tampon[BUFSIZ];
        int actuel = 0;
        int c;
 
 
        fichier = fopen ("test.txt", "r");
        if (!fichier) {
                return EXIT_FAILURE;
        }
 
        while ((c = fgetc (fichier)) != EOF) {
                if (c == ';' || c == '\n') {
                        printf ("%ld\n", strtol (tampon, NULL, 10));
                        actuel = 0;
                        memset (tampon, 0, sizeof tampon);
                } else {
                        tampon[actuel++] = c;
                }
        }
 
	


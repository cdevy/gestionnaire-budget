#include <stdlib.h>
#include <stdio.h>



//Une fois qu'on a terminé de travailler sur le fichier, on ferme le fichier.


int main(int argc, char **argv)
{
	char* nomDuFichier;
	//printf("veuillez entrer le chemin de votre relever de compte \n");
	//scanf("%s", &nomDuFichier); 
	
	char* contenu;
	//On appelle la fonction d'ouverture de fichier fopen qui nous renvoie un pointeur sur le fichier.	
    FILE* fichier = NULL;
    fichier = fopen("jc", "r");
	
	
	//On vérifie si le fichier existe en testant la valeur du pointeur qu'on a reçu. 
	//Si le pointeur est différent de NULL,
	//alors on peut lire dans le fichier
    if (fichier != NULL)
    {
        
		fscanf(fichier, "%s", contenu);
		printf("Qu'est ce qu'on veut ?? %s \n", contenu);
		fscanf(fichier, "%s", contenu);
		printf("Qu'est ce qu'on veut pas ?? %s \n", contenu);
        fclose(fichier);
    }
    
    //Si le pointeur vaut NULL, c'est que l'ouverture du fichier n'a pas fonctionné
    else
    {
        // Message d'erreur
        printf("Impossible d'ouvrir le fichier %s", nomDuFichier);
    }

    return 0;
}

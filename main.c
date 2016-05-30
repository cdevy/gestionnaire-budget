#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compte.h"
#include "application.h"
#include "utils.h"

int main () {
    Comptes liste = initialiser();

    /* Lecture liste de comptes */
    liste = lire_liste();
    
    int fin = 0; /* 0 : faux, 1 : vrai */
    do {
        int action = menu();
        liste = gestion_menu(liste, action);
	printf("\nVoulez-vous quitter l'application ?\n0.Non\n1.Oui\n");
	vider_buffer();
	scanf("%d", &fin);
	printf("\n");
    } while (fin == 0);

    /* Sauvegarde liste de comptes */
    sauvegarder_liste(liste);

    return 0;
}

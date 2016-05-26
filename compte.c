#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"
#include "compte.h"

#define TAILLE_LIGNE 63

Comptes initialiser() {
    Comptes liste = NULL;
    return liste;
}

Compte* nouveau_compte(char* nom, long numero, char* proprietaire, char* banque, char* agence, double solde) {
    Compte* c = (Compte*) malloc(sizeof(Compte));
    if (c != NULL) {
        if (solde < 0 || taille_long(numero) != 10) {
	    printf("Erreur : parametres invalides\n");
	    free(c);
	    return NULL;
	}
	/* Allocations mémoires des attributs */
        c->nom = (char *) malloc((strlen(nom) + 1)*sizeof(char));
        c->proprietaire = (char *) malloc((strlen(proprietaire) + 1)*sizeof(char));
        c->banque = (char *) malloc((strlen(banque) + 1)*sizeof(char));
        c->agence = (char *) malloc((strlen(agence) + 1)*sizeof(char));
        strcpy(c->nom, nom);
        c->numero = numero;
        strcpy(c->proprietaire, proprietaire);
        strcpy(c->banque, banque);
        strcpy(c->agence, agence);
        c->solde = solde;
	char noCpte[10] = "";
	sprintf(noCpte, "%ld", c->numero);
        c->nomFichier = (char*) malloc(45);
	strcpy(c->nomFichier, c->nom);
	c->nomFichier = strcat(strcat(strcat(c->nomFichier, " "), noCpte),".txt");
	int i;
    	for (i=0; i<NB_CAT; i++) {
	    c->budgetsMax[i] = -1;
    	}
	/* Création du fichier de sauvegarde s'il n'existe pas encore */
	if (fopen(c->nomFichier, "r") == NULL) {
            FILE* fichier = fopen(c->nomFichier, "w");
            fprintf(fichier, "Compte : %ld (%s)\nProprietaire : %s\nBanque : %s\nAgence : %s\n", c->numero, c->nom, c->proprietaire, c->banque, c->agence);
            fclose(fichier);
	}
    } else {
    	free(c);
    }
    return c;
}

Comptes ajouter(Comptes liste, Compte* c) { /* ajoute un compte a la fin de la liste */
    c->next = NULL;
    if(liste == NULL) {
        return c;
    } else {
        Compte* temp = liste;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = c;
        return liste;
    }
}

Comptes suppression(Comptes liste, Compte* compte) {
    if(liste == NULL) {
        return NULL;
    }
    if(liste == compte) {
        Compte* temp = liste->next;
	free_compte(compte);
        return temp;
    } else {
        liste->next = suppression(liste->next, compte);
        return liste;
    }
}

void free_compte(Compte* compte) {
    free(compte->nom);
    free(compte->proprietaire);
    free(compte->banque);
    free(compte->agence);
    free(compte->nomFichier);
    free(compte->next);
    free(compte);
}

void affiche_solde(Compte* compte) {
    printf("Le solde du compte n° %ld (%s) est de : %f€\n", compte->numero, compte->nom, compte->solde);
}

void informations(Compte* compte) {
    printf("Numero : %ld\nNom du compte : %s\nProprietaire : %s\nBanque : %s\nAgence : %s\n", compte->numero, compte->nom, compte->proprietaire, compte->banque, compte->agence);
}

void affiche_budgetsMax(Compte* compte) {
    char cat[NB_CAT][20] = {"Vie Quotidienne", "Loisirs", "Sante", "Habitation", "Transports", "Impots & Solidarite", "Professionel", "Epargne", "Divers"};
    printf("Ci-dessous le budget maximal pour chaque catégorie du compte n° %ld (%s)\n", compte->numero, compte->nom);
    int i;
    for (i=0; i<NB_CAT; i++) {
	if (compte->budgetsMax[i] != -1) {
	    printf("%s : %f€\n", cat[i], compte->budgetsMax[i]);
	} else {
	    printf("%s : aucun\n", cat[i]);
	}
    }
}

void sauvegarde(Compte* compte) {
    FILE* fichier = fopen(compte->nomFichier, "w+");
    if (fichier != NULL) {
	time_t t;
    	time(&t);
        fprintf(fichier, "Compte : %ld (%s)\nProprietaire : %s\nBanque : %s\nAgence : %s\n", compte->numero, compte->nom, compte->proprietaire, compte->banque, compte->agence);
	fprintf(fichier, "\nSolde actuel : %f€ mis à jour le %s\n", compte->solde, ctime(&t));
        fclose(fichier);
    }
}

int depot(Compte* c, double valeur) { /* valeur >=0 */
    if (c != NULL && valeur >=0) {
	c->solde = (c->solde) + valeur;
	return 1;
    }
    return 0;
}

int retrait(Compte* c, double valeur) { /* valeur >=0 */
    if (c != NULL && valeur>=0 && (c->solde) >= valeur) {
	c->solde = (c->solde) - valeur;
	return 1;
    }
    return 0;
}

int virement(Compte* debiteur, Compte* crediteur, double valeur) { /* valeur >=0 */
    if (debiteur != NULL && crediteur != NULL) {
	if (retrait(debiteur, valeur) && depot(crediteur, valeur)) {
	    retrait(debiteur, valeur);
	    depot(crediteur, valeur);   
	    return 1;
	}
    }
    return 0;
}

Compte* compte(Comptes liste, long numero) {
    Compte* c = liste;
    while(c != NULL) {
	if (c->numero == numero) {
	    return c; 
	}
        c = c->next;
    }
    return NULL;
}

int nb_comptes(Comptes liste) {
    if (liste == NULL) {
	return 0;
    }
    Compte* c = liste;
    int nb = 0;
    while(c != NULL) {
        c = c->next;
	nb++;
    }
    return nb;
}

Comptes lire_liste(Comptes liste) {
    long numero;
    char nom[30];
    char proprietaire[30]; 
    char banque[30];
    char agence[30];
    double solde;
    double budgetsMax[NB_CAT];
    Comptes liste2 = liste;
    FILE* fichier = fopen("sauvegarde comptes.txt", "r");
    if (fichier != NULL) {
	char premiere_ligne[TAILLE_LIGNE];
        fgets(premiere_ligne, TAILLE_LIGNE, fichier);
	if (premiere_ligne != NULL) {
	    while(!feof(fichier)) { 
	        fscanf(fichier, "%ld, %[^','], %[^','], %[^','], %[^','], %lf€, [ %lf %lf %lf %lf %lf %lf %lf %lf %lf ]\n", &numero, nom, proprietaire, banque, agence, &solde, &budgetsMax[0], &budgetsMax[1], &budgetsMax[2], &budgetsMax[3], &budgetsMax[4], &budgetsMax[5], &budgetsMax[6], &budgetsMax[7], &budgetsMax[8]);
	        Compte* c = nouveau_compte(nom, numero, proprietaire, banque, agence, solde);
		int i;
    	        for (i=0; i<NB_CAT; i++) {
	    	    c->budgetsMax[i] = budgetsMax[i];
    	        }
	        if (c != NULL) {
		    liste2 = ajouter(liste2, c);
	        } else {
		    printf("Erreur : le compte n'a pas pu etre ajoute");
	        }
	    }
	}
        fclose(fichier);
    }
    return liste2;
}

Comptes sauvegarder_liste(Comptes liste) {
    Comptes liste2 = liste;
    FILE* fichier = fopen("sauvegarde comptes.txt", "w+");
    if (fichier != NULL) {
	fprintf(fichier, "Numero, Nom, Proprietaire, Banque, Agence, Solde, Budgets max\n");
	while (liste2 != NULL) {
	    fprintf(fichier, "%ld, %s, %s, %s, %s, %f€, [ ", liste2->numero, liste2->nom, liste2->proprietaire, liste2->banque, liste2->agence, liste2->solde);
	    int i;
    	    for (i=0; i<NB_CAT; i++) {
	    	fprintf(fichier, "%f ", liste2->budgetsMax[i]);
    	    }
	    fprintf(fichier, "]\n");
	    liste2 = liste2->next;
	}
        fclose(fichier);
    }
    return liste2;
}


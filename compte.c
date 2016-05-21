#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "compte.h"

Compte* nouveau_compte(char* nom, long numero, char* proprietaire, char* banque, char* agence, double solde) {
    Compte* c = (Compte*) malloc(sizeof(Compte));
    if (c != NULL) {
        if (solde < 0 || taille_long(numero) != 10) {
	    printf("Erreur : parametres invalides");
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
	char noCpte[10];
	sprintf(noCpte, "%ld", c->numero);
        c->nomFichier = (char*) malloc(25);
	strcpy(c->nomFichier, c->nom);
	c->nomFichier = strcat(strcat(strcat(c->nomFichier, " "), noCpte),".txt");
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

void suppression(Compte* compte) {
    free(compte->nom);
    free(compte->proprietaire);
    free(compte->banque);
    free(compte->agence);
    free(compte->nomFichier);
    free(compte);
}

void affiche_solde(Compte* compte) {
    printf("Le solde du compte n° %ld (%s) est de : %f€\n", compte->numero, compte->nom, compte->solde);
}

void informations(Compte* compte) {
    printf("Numero : %ld\nNom du compte : %s\nProprietaire : %s\nBanque : %s\nAgence : %s\nSolde actuel : %f€\n", compte->numero, compte->nom, compte->proprietaire, compte->banque, compte->agence, compte->solde);
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

/*
long taille_double(double d) {
    double res = 1 + log10(d); 
    return (long) res;
}
*/

long taille_long(long l) {
    double res = 1 + log10(l); 
    return (long) res;
}


void depot(Compte* c, double valeur) { // valeur >=0
    if (c != NULL) {
	c->solde = (c->solde) + valeur;
    }
}

void retrait(Compte* c, double valeur) { // valeur >=0
    if (c != NULL) {
	c->solde = (c->solde) - valeur;
    }
}

void transaction(Compte* debiteur, Compte* crediteur, double valeur) { // valeur >=0
    if (debiteur != NULL && crediteur != NULL) {
	retrait(debiteur, valeur);
	depot(crediteur, valeur);
    }
}

int main() {
    Compte* c1 = nouveau_compte("Compte courant", 1338292124, "Charlotte DEVY", "Societe Generale", "St-Gratien", 100);
    if (c1 != NULL) {
        informations(c1);
        sauvegarde(c1);
        printf("\n");
    }
    Compte* c2 = nouveau_compte("Livret A", 3300002124, "Charlotte DEVY", "Societe Generale", "St-Gratien", 20000);
    if (c2 != NULL) {
        informations(c2);
        sauvegarde(c2);
        printf("\n");
    }
    printf("Depot de 250€ sur le compte n° %ld (%f) :\n", c1->numero, c1->solde);
    depot(c1, 250);
    affiche_solde(c1);
    printf("Retrait de 1500€ du compte n° %ld (%f) :\n", c2->numero, c2->solde);
    retrait(c2, 1500);
    affiche_solde(c2);
    printf("Transaction de 3000€ du compte n° %ld (%f) au compte n° %ld (%f) :\n", c2->numero, c2->solde, c1->numero, c1->solde);
    transaction(c2, c1, 3000);
    affiche_solde(c1);
    affiche_solde(c2);
    suppression(c1);
    suppression(c2);
    return 0;
}


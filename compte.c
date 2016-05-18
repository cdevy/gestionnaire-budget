#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "compte.h"

Compte* nouveau_compte(char* nom, long numero, char* proprietaire, char* banque, char* agence, double solde) {
    Compte* c = (Compte*) malloc(sizeof(Compte));
    if (c != NULL) {
        c->nom = (char *) malloc((strlen(nom) + 1)*sizeof(char)); //10
        c->proprietaire = (char *) malloc((strlen(proprietaire) + 1)*sizeof(char));
        c->banque = (char *) malloc((strlen(banque) + 1)*sizeof(char));
        c->agence = (char *) malloc((strlen(agence) + 1)*sizeof(char));
        strcpy(c->nom, nom);
        c->numero = numero;
        strcpy(c->proprietaire, proprietaire);
        strcpy(c->banque, banque);
        strcpy(c->agence, agence);
        c->solde = solde;
    } else { //20
    	free(c);
    }
    return c;
}

void suppression(Compte* compte) {
    free(compte->nom);
    free(compte->proprietaire);
    free(compte->banque);
    free(compte->agence); //30
    free(compte);
}

void affiche_solde(Compte* compte) {
    printf("Le solde de ce compte est de : %f€\n", compte->solde);
}

void informations(Compte* compte) {
    printf("Numero : %ld\nNom du compte : %s\nProprietaire : %s\nBanque : %s\nAgence : %s\nSolde actuel : %f€\n", compte->numero, compte->nom, compte->proprietaire, compte->banque, compte->agence, compte->solde);
}
 //40
void sauvegarde(Compte* compte) {
    FILE* fichier = NULL;
    char* nomCpte = strdup(compte->nom);
    char noCpte[10];
    sprintf(noCpte, "%ld", compte->numero);
    char* nom_fichier = strdup(strcat(strcat(strcat(nomCpte, " "), noCpte),".txt"));
    printf("%s", nom_fichier);
    fichier = fopen(nom_fichier, "a+"); // erreur à cette ligne !! si le fichier n'existe pas, il est créé ; sinon, il est remplacé
    if (fichier != NULL) { //50
	time_t t;
    	time(&t);
	fprintf(fichier, "Mise à jour : %s\n", ctime(&t));
	fprintf(fichier, "Compte : %ld (%s), Proprietaire : %s, Banque : %s, Agence : %s\n", compte->numero, compte->nom, compte->proprietaire, compte->banque, compte->agence); //erreur
	fprintf(fichier, "\nSolde actuel : %f€\n", compte->solde);
        fclose(fichier);
    }
    free(nomCpte);
    free(nom_fichier);
}

int main() {
    Compte* c = nouveau_compte("Compte courant", 338292124, "Charlotte DEVY", "Societe Generale", "St-Gratien", 100.00);
    if (c != NULL) {
        affiche_solde(c);
        printf("\n");
        informations(c);
        sauvegarde(c); //70
        suppression(c);
    }
    return 0;
}


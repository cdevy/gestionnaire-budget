#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"
#include "compte.h"
#include "categorie.h"
#include "operation.h"

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
        c->nom = (char*) malloc((strlen(nom) + 1)*sizeof(char));
        c->proprietaire = (char *) malloc((strlen(proprietaire) + 1)*sizeof(char));
        c->banque = (char*) malloc((strlen(banque) + 1)*sizeof(char));
        c->agence = (char*) malloc((strlen(agence) + 1)*sizeof(char));
	c->nomFichier = (char*) malloc(50*sizeof(char));

        strcpy(c->nom, nom);
        c->numero = numero;
        strcpy(c->proprietaire, proprietaire);
        strcpy(c->banque, banque);
        strcpy(c->agence, agence);
        c->solde = solde;
	char noCpte[10] = "";
	sprintf(noCpte, "%ld", c->numero);
	strcpy(c->nomFichier, nom);
	strcat(strcat(strcat(c->nomFichier, "_"), noCpte),".txt");
	traiter(c->nomFichier, 1);
	int i;
    	for (i=0; i<NB_CAT; i++) {
	    c->budgetsMax[i] = -1;
    	}
	c-> liste_op = NULL;
        c->next = NULL;
	/* Création du fichier de sauvegarde des operations s'il n'existe pas encore */
	if (fopen(c->nomFichier, "r") == NULL) {
            FILE* fichier = fopen(c->nomFichier, "w");
            fprintf(fichier, "Compte : %ld (%s)\nProprietaire : %s\nBanque : %s\nAgence : %s\nSolde initial : %.2f\n", c->numero, c->nom, c->proprietaire, c->banque, c->agence, c->solde);
	    time_t t;
    	    time(&t);
	    fprintf(fichier, "\nCompte créé le %s\n", ctime(&t));
            fclose(fichier);
	}
    } else {
    	free(c);
    }
    return c;
}

Comptes ajouter(Comptes liste, Compte* c) { /* ajoute un compte a la fin de la liste */
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
	FILE* fichier = fopen(compte->nomFichier, "a+");
        if (fichier != NULL) {
	    time_t t;
    	    time(&t);
	    fprintf(fichier, "\nCompte cloturé le %s\n", ctime(&t));
        }
        fclose(fichier);
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
    free(compte);
}

void affiche_solde(Compte* compte) {
    printf("Le solde du compte n° %ld (%s) est de : %.2f€", compte->numero, compte->nom, compte->solde);
}

void informations(Compte* compte) {
    printf("Numero : %ld\nNom du compte : %s\nProprietaire : %s\nBanque : %s\nAgence : %s\n", compte->numero, compte->nom, compte->proprietaire, compte->banque, compte->agence);
}

void affiche_budgetsMax(Compte* compte) {
    char cat[NB_CAT][20] = {"Vie Quotidienne", "Loisirs", "Sante", "Habitation", "Transports", "Impots & Solidarite", "Professionel", "Epargne", "Divers"};
    printf("Ci-dessous le budget maximal pour chaque catégorie du compte n° %ld (%s) :\n", compte->numero, compte->nom);
    int i;
    for (i=0; i<NB_CAT; i++) {
	if (compte->budgetsMax[i] != -1) {
	    printf("%s : %.2f€\n", cat[i], compte->budgetsMax[i]);
	} else {
	    printf("%s : aucun\n", cat[i]);
	}
    }
}

void sauvegarde(Compte* c) {
    FILE* fichier = fopen(c->nomFichier, "a+");
    if (fichier != NULL) {
	time_t t;
    	time(&t);
        Operation* op = c->liste_op;
	while (op != NULL) {
	    fprintf(fichier, "Date : %s, Titre : %s, ", op->date, op->titre);
	    if (op->type == DEBIT) {
		fprintf(fichier, "Type : DEBIT, "); 
	    } else {
		fprintf(fichier, "Type : CREDIT, "); 
	    }
	    fprintf(fichier, "Valeur : %.2f€, Categorie : %s, Sous-categorie : %s\n", op->valeur, nom_cat(op->categorie), nom_sousCat(op->sousCategorie)); 
	    op = op->next;
	}
	fprintf(fichier, "\nSolde actuel : %.2f€ mis à jour le %s\n", c->solde, ctime(&t));
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

void gestion_op(Compte* c) {
    if (c != NULL) {
    	if(c->liste_op != NULL) {
        	Operation* liste = c->liste_op;
        	while(liste->next != NULL) {
		    if (liste->type == DEBIT) {
			retrait(c, liste->valeur);
		    } else {
			depot(c, liste->valeur);
		    }
        	    liste = liste->next;
        	}
	}
    }	
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

Comptes lire_liste() {
    long numero;
    char nom[30];
    char proprietaire[30]; 
    char banque[30];
    char agence[30];
    double solde;
    double budgetsMax[NB_CAT];
    Comptes liste = NULL;
    FILE* fichier = fopen("sauvegarde_comptes.txt", "r");
    if (fichier != NULL) {
	char premiere_ligne[TAILLE_LIGNE];
        fgets(premiere_ligne, TAILLE_LIGNE, fichier);
	if (premiere_ligne != NULL) {
	    while(!feof(fichier)) { 
	        fscanf(fichier, "%ld, %[^','], %[^','], %[^','], %[^','], %lf, [ %lf %lf %lf %lf %lf %lf %lf %lf %lf ]\n", &numero, nom, proprietaire, banque, agence, &solde, &budgetsMax[0], &budgetsMax[1], &budgetsMax[2], &budgetsMax[3], &budgetsMax[4], &budgetsMax[5], &budgetsMax[6], &budgetsMax[7], &budgetsMax[8]);
	        Compte* c = nouveau_compte(nom, numero, proprietaire, banque, agence, solde);
	        if (c != NULL) {
		    int i;
    	            for (i=0; i<NB_CAT; i++) {
	    	        c->budgetsMax[i] = budgetsMax[i];
    	            }
		    liste = ajouter(liste, c);
	        } else {
		    printf("Erreur : le compte n'a pas pu etre ajoute");
	        }
	    }
	}
        fclose(fichier);
    }
    return liste;
}

void sauvegarder_liste(Comptes liste) {
    Compte* c = liste;
    FILE* fichier = fopen("sauvegarde_comptes.txt", "w+");
    if (fichier != NULL) {
	fprintf(fichier, "Numero, Nom, Proprietaire, Banque, Agence, Solde, Budgets max\n");
	while (c != NULL) {
	    sauvegarde(c);
	    fprintf(fichier, "%ld, %s, %s, %s, %s, %.2f, [ ", c->numero, c->nom, c->proprietaire, c->banque, c->agence, c->solde);
	    int i;
    	    for (i=0; i<NB_CAT; i++) {
	    	fprintf(fichier, "%.2f ", c->budgetsMax[i]);
    	    }
	    fprintf(fichier, "]\n");
	    c = c->next;
	}
        fclose(fichier);
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>	
#include "operation.h"
#include "categorie.h"
#include "statistiques.h"
#include "gnuplot_i/src/gnuplot_i.h"

void afficheBalanceMois(Operation* list) {
    gnuplot_ctrl *h;
    double x[32];
    double y[32];
    int i;
    Operation * op;
    h = gnuplot_init() ;
    for (i=0 ; i<32 ; i++) {
        x[i] = i+1;
        y[i] = 0;
    }
    for (op = list; op!=NULL; op=op->next) {
		char tmp[3];
		tmp[0] = op->date[0];
		tmp[1] = op->date[1];
		tmp[2] = '\0';
		int j = atoi(tmp);
		switch (op-> type){
			case DEBIT:
				y[j] -= op->valeur;
				break;
			case CREDIT:
				y[j] += op->valeur; 
				break;
			default:
				break;
		}
	}
    gnuplot_setstyle(h,"linespoints");
    gnuplot_plot_xy(h, x, y, 31, "Graphique des depenses/rentrees du mois") ;
    int arret = 0;
    printf("Entrez 1 pour continuer\n");
    while(arret == 0) {
	scanf("%d", &arret);
    }
    gnuplot_close(h);
    gnuplot_write_xy_csv("Donnees_depenses_mois.csv",x,y,32,NULL);
}

void afficheBalanceMoisCategorie(Operation* list, Categorie cat) {
    gnuplot_ctrl *h;
    double x[32];
    double y[32];
    int i;
    Operation * op;
    h = gnuplot_init() ;
    for (i=0 ; i<32 ; i++) {
        x[i] = i+1;
        y[i] = 0;
    }
    for (op = list; op!=NULL; op=op->next) {
		if (op->categorie == cat ) {
			char tmp[3];
			tmp[0] = op->date[0];
			tmp[1] = op->date[1];
			tmp[2] = '\0';
			int j = atoi(tmp);
			switch (op-> type){
					case DEBIT:
						y[j] -= op->valeur;
						break;
					case CREDIT:
						y[j] += op->valeur; 
						break;
					default:
						break;
			}
		}
	}
    gnuplot_setstyle(h,"linespoints");
    gnuplot_plot_xy(h, x, y, 31, "Graphique des depenses/rentrees du mois pour la categorie choisie") ;
    int arret = 0;
    printf("Entrez 1 pour continuer\n");
    while(arret == 0) {
	scanf("%d", &arret);
    }
    gnuplot_close(h);
    gnuplot_write_xy_csv("Donnees_depenses_mois_categorie.csv",x,y,32,NULL);
}


void afficheBalanceCategories(Operation* list) {
    gnuplot_ctrl *h;
    double x[9];
    double y[9];
    int i;
    Operation * op;
    h = gnuplot_init();
    for (i=0 ; i<9 ; i++) {
        x[i] = i;
        y[i] = 0;
    }
    for (op = list; op!=NULL; op=op->next) {
	if (op->categorie<0 && op->categorie>8 ) {
		printf("La valeur que vous avez rentre à Categorie n'est pas bonne, veuillez tout recommencer.");
		exit(0);
	} else {
		switch (op-> type){
			case DEBIT:
				y[op -> categorie] -= op->valeur;
				break;
			case CREDIT:
				y[op -> categorie] += op->valeur; 
				break;
			default:
				break;
		}
	}
    }
    gnuplot_set_xlabel(h,"Vie Quotidienne  Loisirs  Sante  Habitation  Transports  Impots & Solidarite  Professionel  Epargne Divers");
    gnuplot_setstyle(h,"boxes");
    gnuplot_plot_xy(h, x, y, 9, "Graphique des depenses/rentrees du mois pour chaque categorie") ;
    int arret = 0;
    printf("Entrez 1 pour continuer\n");
    while(arret == 0) {
	scanf("%d", &arret);
    }
    gnuplot_close(h);
    gnuplot_write_xy_csv("Donnees_depenses_categorie.csv",x,y,9,NULL);
}

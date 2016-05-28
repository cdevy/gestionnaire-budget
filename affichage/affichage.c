#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include "operation.h"
#include "stats.c"
#include "gnuplot_i/src/gnuplot_i.h"
#include "gnuplot_i/src/gnuplot_i.c"

void afficheDepensesMois(Operation* list) {
	gnuplot_ctrl *h;
    double x[32];
    double y[32];
    int i;
    Operation * op;
    h = gnuplot_init() ;
    for (i=0 ; i<32 ; i++) {
        x[i] = i;
        y[i] = 0;
    }
    for (op = list;op!=NULL;op=op->next) {
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
    gnuplot_plot_xy(h, x, y, 31, "Graphe des dépenses du mois") ;
    sleep(10);
    gnuplot_close(h);
    gnuplot_write_xy_csv("Données_depenses_mois.csv",x,y,32,NULL);
}

void afficheDepensesMoisCategorie(Operation* list, Categorie cat) {
	gnuplot_ctrl *h;
    double x[32];
    double y[32];
    int i;
    Operation * op;
    h = gnuplot_init() ;
    for (i=0 ; i<32 ; i++) {
        x[i] = i;
        y[i] = 0;
    }
    for (op = list;op!=NULL;op=op->next) {
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
    gnuplot_plot_xy(h, x, y, 31, "Graphe des dépenses du mois pour une catégorie") ;
    sleep(5);
    gnuplot_close(h);
    gnuplot_write_xy_csv("Données_depenses_mois_categorie.csv",x,y,32,NULL);
}


void afficheDepensesCategorie(Operation* list) {
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
	for (op = list;op!=NULL;op=op->next) {
		if (op->categorie != NULL && op->categorie<0 && op->categorie>8 ) {
			printf("La valeur que vous avez rentré à Catégorie n'est pas bonne, veuillez tout recommencer.");
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
    gnuplot_setstyle(h,"bares");
    gnuplot_plot_xy(h, x, y, 9, "Graphe des dépenses du mois pour chaque catégorie") ;
    sleep(5);
    gnuplot_close(h);
    gnuplot_write_xy_csv("Données_depenses_categorie.csv",x,y,9,NULL);
}

int main(int argc, char **argv) {
	Operation * o = ParserOperation("test.csv");
	if (o != NULL){
		afficheOperations(o);
	}
	double r = depensesMois(o);
	printf("\nLa balance est de :%.2f\n", r);
	afficheDepensesCategorie(o);
	return EXIT_SUCCESS;
}

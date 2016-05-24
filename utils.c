#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "utils.h"

long taille_double(double d) {
    double res = 1 + log10(d); 
    return (long) res;
}

long taille_long(long l) {
    double res = 1 + log10(l); 
    return (long) res;
}

void vider_buffer() {
    int c;
    while ((c = getchar ()) != '\n' && c != EOF);
}

void traiter(char* chaine) {
    char* p = strchr(chaine, '\n');
    if (p) {
	*p = 0;
    }
}

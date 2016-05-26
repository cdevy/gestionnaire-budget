#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operation.h"
#include "categorie.h"
#include "operation.c"



int main()
{
	char D[9] = "12/12/12";
	char D2[9] = "10/10/10";
	char t[32] = "virement op1";
	char t2[32] = "virement op2";
	Operation *u,*v,*w,*z;
	u = nouvelle_operation(D2, t2, "DEBIT", -50, NULL);
	v = nouvelle_operation(D, t, "DEBIT", -10, u);
	printf("Affichage des deux opréations de la linked liste :\n");
	
	printf("Affichage de op1 :\n");
	printf("%s \n",v->date);
	printf("%s \n",v->titre);
	printf("%p \n\n",v->next);
	printf("Affichage de op2 :\n");
	printf("%s \n",v->next->date);
	printf("%s \n",v->next->titre);
	printf("%p \n\n",v->next->next);
	
	printf("Affichage des opréations de la linked liste après avoir retiré op2 :\n");
	retirer_operation(u,v);
	printf("%s \n",v->date);
	printf("%s \n",v->titre);
	printf("%p \n\n",v->next);	
	
	printf("Affichage des opréations de la linked liste après avoir retiré op1 :\n");
	w = nouvelle_operation(D2, t2, "CREDIT", 200, NULL);
	z = nouvelle_operation(D, t, "CREDIT", 50, w);
	retirer_operation(z,z);
	printf("%s \n",z->date);
	printf("%s \n",z->titre);
	printf("%p \n\n",z->next);
	
	return 0;
}


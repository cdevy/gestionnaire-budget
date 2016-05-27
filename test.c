#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operation.h"
#include "operation.c"


int main()
{
	char D[9] = "12/12/12";
	char D2[9] = "10/10/10";
	char t[32] = "virement op1";
	char t2[32] = "virement op2";
	Operation *u,*v,*w,*z;
	u = nouvelle_operation(D2, t2, 0, -50, 0,0, NULL);
	v = nouvelle_operation(D, t, 0, -10, 0,0, u);
	Operation* a = ajouter_Operation_fin(NULL, nouvelle_operation(D2, t2,0,50,QUOTIDIEN,ALIMENTATION, NULL));
	Operation* b = ajouter_Operation_fin(a, nouvelle_operation(D, t,0,50,QUOTIDIEN,ALIMENTATION, NULL));
	printf("operation fin :\n");
	printf("%s \n",a->date);
	printf("%s \n",a->titre);
	printf("%p \n\n",a->next);
	
	
	printf("operation fin :\n");
	printf("%s \n",b->date);
	printf("%s \n",b->titre);
	printf("%p \n\n",b->next);
	

	printf("operation fin :\n");
	printf("%s \n",a ->next->date);
	printf("%s \n",a ->next->titre);
	printf("%p \n\n",a ->next->next);	
	/*printf("Affichage des deux opréations de la linked liste :\n");
	
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
	w = nouvelle_operation(D2, t2, 0, 200, 0,0, NULL);
	z = nouvelle_operation(D, t, 0, 50, 0,0, w);
	retirer_operation(z,z);
	printf("%s \n",z->date);
	printf("%s \n",z->titre);
	printf("%p \n\n",z->next);*/
	
	return 0;
}


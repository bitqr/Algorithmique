#include<stdio.h>
#include<stdlib.h>
#include"ABR.h"

ABR * arbre_rechercher(ABR *x, int k){
	 if(x == NULL || x->cle == k)
	 	return x;
	if(k < x->cle)
		return arbre_rechercher(x->gauche,k);
	else 
		return arbre_rechercher(x->droite,k);
}


ABR * creer_abr(int cle, ABR *g, ABR *d){
	ABR * x = (ABR *)malloc(sizeof(ABR));
	x->cle = cle; 
	x->droite = d;
	x->gauche = g;
	return x;
}

int main(int argc, char **argv){
	ABR *x; ABR *x1; ABR *x2; ABR *f1; ABR *f2; ABR *f3;
	f1 = creer_abr(2,NULL,NULL);
	f2 = creer_abr(5,NULL,NULL);
	f3 = creer_abr(8,NULL,NULL);
	x1 = creer_abr(3,f1,f2);
	x2 = creer_abr(7,NULL,f3);
	x = creer_abr(5,x1,x2);
	x->p = NULL; x1->p = x; x2->p = x; f1->p = x1; f2->p = x1; f3->p = x2;
	
	printf("Le minimum est %d\n",arbre_minimum_recursif(x)->cle);
	printf("Le maximum est %d\n",arbre_maximum_recursif(x)->cle);
	printf("Le minimum est %d\n",arbre_minimum(x)->cle);
	printf("Le maximum est %d\n",arbre_maximum(x)->cle);
	printf("Entrez la cle a rechercher\n");
	int k;
	fscanf(stderr,"%d",&k);
	ABR * res = arbre_rechercher(x,k);
	if(res != NULL){
	printf("Element de cle %d trouve\n",res->cle);
	printf("Le successeur de %d est %d\n",k,arbre_successeur(res)->cle);
	printf("Le predecesseur de %d est %d\n",k,arbre_predecesseur(res)->cle);
	}
	else 
	printf("Element de cle %d non trouve\n",k);
	printf("Une autre cle svp\n");
	fscanf(stderr,"%d",&k);
	ABR *resit = arbre_rechercher_iteratif(x,k);
	if(resit != NULL)
	printf("Element de cle %d trouve\n",resit->cle);
	else 
	printf("Element de cle %d non trouve\n",k);
	return 0;
}




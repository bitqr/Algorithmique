#include<stdio.h>
#include<stdlib.h>
#include"HachageChaine.h"

LSC * rechercher_hachage_chainee(LSC **T,int k,int m){
	int ind = h(k,m);
	LSC * x = T[ind];
	while(x != NULL && x->cle != k)
		x = x->suiv;
	if(x == NULL){
		fprintf(stderr,"L'element %d est absent\n",k);
		exit(EXIT_FAILURE);
		}
	else {
		fprintf(stdout,"L'element %d est trouve\n",x->cle);
		return x;
		}
}



#include<stdio.h>
#include<stdlib.h>
#include"HachageChaine.h"

LSC * rechercher_hachage_chainee(LSC **T,int k,int m){
	int ind = h(k,m);
	LSC * x = T[ind];
	while(x != NULL && x->cle != k)
		x = x->suiv;
	if(x == NULL){
		fprintf(stderr,"L'élément %d est absent\n",k);
		exit(EXIT_FAILURE);
	}
	else {
		fprintf(stdout,"L'élément %d est trouvé\n",x->cle);
		return x;
	}
}


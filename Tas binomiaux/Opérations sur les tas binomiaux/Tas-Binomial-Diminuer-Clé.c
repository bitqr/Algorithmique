#include"TASBIN.h"

void tas_binomial_diminuer_cle(TAS_BINOMIAL *T, NOEUD_TAS_BINOMIAL *x, int k){
	if(k>x->cle){
		fprintf(stderr,"La nouvelle clé est plus grande que la clé courante\n");
		exit(EXIT_FAILURE);
	}
	x->cle=k;
	NOEUD_TAS_BINOMIAL *y=x;
	NOEUD_TAS_BINOMIAL *z=y->p;
	while(z!=NIL && y->cle<z->cle){
		int temp=z->cle;
		z->cle=y->cle;
		y->cle=temp;
		//Si y et z ont des champs satellites, on les permute aussi.
		y=z;
		z=y->p;
	}
}



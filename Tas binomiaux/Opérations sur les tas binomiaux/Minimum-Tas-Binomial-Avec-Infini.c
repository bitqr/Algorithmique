#include"TASBIN.h"

NOEUD_TAS_BINOMIAL *minimum_tas_binomial_avec_infini(TAS_BINOMIAL *T){
	NOEUD_TAS_BINOMIAL *y=NIL;
	NOEUD_TAS_BINOMIAL *x=T->tete;
	int min=INFINI;
	while(x!=NIL){
		if(x->cle<=min){
			min=x->cle;
			y=x;
		}
		x=x->frere;
	}
	return y;
}


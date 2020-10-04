#include"TASBIN.h"

NOEUD_TAS_BINOMIAL *fusionner_tas_binomiaux(TAS_BINOMIAL *T1, TAS_BINOMIAL *T2){
	NOEUD_TAS_BINOMIAL *x1=T1->tete;
	NOEUD_TAS_BINOMIAL *x2=T2->tete;
	if(x1==NIL)
		return x2;
	if(x2==NIL)
		return x1;
	NOEUD_TAS_BINOMIAL *h;
	if(x1->degre<=x2->degre){
		h=x1;
		x1=x1->frere;
	}
	else{
		h=x2;
		x2=x2->frere;
	}
	NOEUD_TAS_BINOMIAL *courant=h;
	while(x1!=NIL && x2!=NIL){
		if(x1->degre<=x2->degre){
			courant->frere=x1;
			x1=x1->frere;
		}
		else{
			courant->frere=x2;
			x2=x2->frere;
		}
		courant=courant->frere;
	}
	if(x1==NIL)
		courant->frere=x2;
	else
		courant->frere=x1;
	return h;
}



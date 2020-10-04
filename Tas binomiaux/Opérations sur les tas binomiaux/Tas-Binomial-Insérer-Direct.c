#include"TASBIN.h"

void tas_binomial_inserer_direct(TAS_BINOMIAL *T, NOEUD_TAS_BINOMIAL *x){
	x->p=NIL;
	x->frere=NIL;
	x->enfant=NIL;
	x->degre=0;
	NOEUD_TAS_BINOMIAL *y=T->tete;
	if(y==NIL || y->degre!=0){
		x->frere=y;
		T->tete=x;
	}
	else{
		while(x!=NIL && y->degre==x->degre){
			if(x->cle<=y->cle){
				T->tete=x;
				lien_binomial(y,x);
				y=x;
			}
			else{
				if(x->degre!=0){
					y->frere=x->frere;
				}
				lien_binomial(x,y);
			}
			x=y->frere;
		}
	}
}



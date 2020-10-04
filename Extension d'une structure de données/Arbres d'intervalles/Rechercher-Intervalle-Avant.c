#include"ARN_INT.h"

NOEUD *rechercher_intervalle_avant(ARN *T, INTERVALLE *i){
	NOEUD *x = T->racine;
	NOEUD *z = T->nil;
	while(x != T->nil){
		if(x->Int->debut > i->fin || x->Int->fin < i->debut){
			if(x->gauche != T->nil && x->gauche->max >= i->debut)
				x = x->gauche;
			else
				x = x->droite;
		}
		else{
			if(z == T->nil || x->cle < z->cle)
				z = x;
			x = x->gauche;
		}
	}
	return z;
}


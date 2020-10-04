#include"TAS_2_3_4.h"

void diminuer_cle(TAS_2_3_4 *T, NOEUD_TAS_2_3_4 *x, int k){
	x->cle=k;
	while(x!=T->racine){
		x=x->p;
		if(x->petit>k){
			x->petit=k;
		}
	}
}



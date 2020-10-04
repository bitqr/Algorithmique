#include"ARN_INT.h"

INTERVALLE *creeInt(int debut, int fin){
	INTERVALLE *i = (INTERVALLE *)malloc(sizeof(INTERVALLE));
	i->debut = debut;
	i->fin = fin;
	return i;
}

NOEUD *rechercher_intervalle_ouvert(ARN *T, INTERVALLE *i){
	NOEUD *x = T->racine;
	while(x != T->nil && (i->fin <= x->Int->debut || x->Int->fin <= i->debut)){
		if(x->gauche != T->nil && x->gauche->max > i->debut)
			x = x->gauche;
		else	
			x = x->droite;
	}
	return x;
}

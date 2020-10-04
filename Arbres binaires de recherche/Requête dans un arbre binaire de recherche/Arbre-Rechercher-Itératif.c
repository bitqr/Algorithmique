#include<stdio.h>
#include<stdlib.h>
#include"ABR.h"


ABR * arbre_rechercher_iteratif(ABR *x, int k){
	while(x != NULL && k != x->cle)
		if(k < x->cle)
			x = x->gauche;
		else
			x = x->droite;
	return x;
}




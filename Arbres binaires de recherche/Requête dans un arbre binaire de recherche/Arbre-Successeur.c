#include<stdio.h>
#include<stdlib.h>
#include"ABR.h"


ABR * arbre_successeur(ABR *x){
	if(x->droite != NULL)
		return arbre_minimum(x->droite);
	ABR * y = x->p;
	while(y != NULL && x == y->droite){
		x = y;
		y = y->p;
		}
	return y;
}







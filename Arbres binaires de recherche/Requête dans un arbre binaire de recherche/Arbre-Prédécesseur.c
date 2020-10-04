#include<stdio.h>
#include<stdlib.h>
#include"ABR.h"


ABR * arbre_predecesseur(ABR *x){
	if(x->gauche != NULL)
		return arbre_maximum(x->gauche);
	ABR *y = x->p;
	while(y != NULL && x == y->gauche){
		x = y;
		y = y->p;
		}
	return y;
}





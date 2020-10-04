#include<stdio.h>
#include<stdlib.h>
#include"ABR.h"

ABR * arbre_minimum(ABR *x){
	while(x->gauche)
		x = x->gauche;
	return x;
}



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



ABR * arbre_supprimer(ABR *T, ABR *z){
	ABR *y; ABR *x;
	if(z->gauche == NULL || z->droite == NULL)
		y = z;
	else 
		y = arbre_successeur(z);
	if(y->gauche != NULL)
		x = y->gauche;
	else
		x = y->droite;
	if(x)
		x->p = y->p;
	if(y->p == NULL)
		T = x;
	else 
		if(y == y->p->gauche)
			y->p->gauche = x;
		else 
			y->p->droite = x;
	if(y != z)
		z->cle = y->cle;
	return y;
}





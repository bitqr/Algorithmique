#include<stdio.h>
#include<stdlib.h>
#include"HachageChaine.h"

void supprimer_hachage_chainee(LSC **T,LSC *x,int m){
	int c = x->cle;
	int ind = h(c,m);
	LSC * t = T[ind];
	if(t == x)
		T[ind] = t->suiv;
	else{
		while(t->suiv != x && t != NULL)
			t = t->suiv;
		if(t != NULL)
			t->suiv = t->suiv->suiv;
	}
}


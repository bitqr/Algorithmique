#include<stdio.h>
#include<stdlib.h>
#include"ListesChainees.h"

LSCC * rechercher(LSCC * L, int k){
	while(L->suiv->cle != k && L->suiv != L->tete)
		L = L->suiv;
	if(L->suiv->cle == k)
		return L->suiv;
	return NULL;
}


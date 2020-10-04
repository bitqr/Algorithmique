#include"Hachage.h"
#include<stdlib.h>
#include<stdio.h>

void inserer_adressage_direct(OBJET ** T,OBJET *x){
	T[x->cle] = x;
}


#include"ABR.h"
#include<stdlib.h>


ABR * arbre_minimum_recursif(ABR *x){
	if(x == NULL || x->gauche == NULL)
		return x;
	else 
		return arbre_minimum_recursif(x->gauche);
}





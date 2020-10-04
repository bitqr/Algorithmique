#include<stdlib.h>
#include<stdio.h>
#include"ArbreBinaireRecherche.h"

void parcours_prefixe(ABR *x){
	if(x!=NULL){
		printf("%d\t",x->cle);
		parcours_prefixe(x->gauche);
		parcours_prefixe(x->droite);
		}
}


#include<stdio.h>
#include<stdlib.h>
#include"Arborescence.h"



void afficher_arbre_4(ARBREBINAIRE *A){
	if(A != NULL){
		PILE *p = creer_pile(3);
		empiler(p,A);
		ARBREBINAIRE *b;
		while(!pile_vide(p)){
			b = p->tableau[p->sommet];
			printf("%d\t",depiler(p)->cle);
			if(b->droit != NULL) empiler(p,b->droit);
			if(b->gauche != NULL) empiler(p,b->gauche);
		}
	}
}


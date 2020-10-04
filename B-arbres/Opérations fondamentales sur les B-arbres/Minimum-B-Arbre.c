#include"B_ARBRE.h"

int minimum_B_arbre(B_ARBRE *T){
	NOEUD_B_ARBRE *r=T->racine;
	if(r->n==0){
		fprintf(stderr,"Erreur, arbre vide.\n");
		exit(EXIT_FAILURE);	
	}
	while(r->feuille==FAUX){
		lireDisque(r->c[0]);
		r=r->c[0];
	}
	return r->cle[0];
}




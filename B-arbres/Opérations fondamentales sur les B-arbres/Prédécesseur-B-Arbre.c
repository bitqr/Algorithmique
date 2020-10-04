#include"B_ARBRE.h"

int predecesseur_B_arbre(B_ARBRE *T, int k){
	NOEUD_B_ARBRE *r=T->racine;
	while(r->feuille==FAUX){
		int i=r->n;
		while(i>=1 && r->cle[i-1]>k){
			i=i-1;
		}
		if(i>=1 && k==r->cle[i-1]){
			lireDisque(r->c[i-1]);
			NOEUD_B_ARBRE *x=r->c[i-1];
			while(x->feuille==FAUX){
				lireDisque(x->c[x->n]);
				x=x->c[x->n];
			}
			return x->cle[x->n-1];
		}
		if(i>=1){
			lireDisque(r->c[i]);
			NOEUD_B_ARBRE *x=r->c[i];
			while(x->feuille==FAUX){
				lireDisque(x->c[0]);
			}
			if(x->cle[0]==k)
				return r->cle[i-1];
			else
				r=r->c[i];
		}
		else
			r=r->c[0];
	}
	int i=r->n;
	while(i>=1 && r->cle[i-1]>k){
		i=i-1;	
	}
	if(i>1){
		return r->cle[i-2];	
	}
	else{
		fprintf(stderr,"Erreur, pas de predecesseur : c'est la cle minimale.\n");
		exit(EXIT_FAILURE);
	}
}




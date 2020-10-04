#include"B_ARBRE.h"

void inserer_B_arbre_incomplet(NOEUD_B_ARBRE *x, int k){
	int i=x->n;
	if(x->feuille){
		int *nouveauCle = (int *)malloc((x->n+1)*sizeof(int));
		while(i>=1 && k<x->cle[i-1]){
			nouveauCle[i]=x->cle[i-1];
			i=i-1;
		}
		nouveauCle[i]=k;
		int j;
		for(j>=1;j<=i;j++)
			nouveauCle[j-1]=x->cle[j-1];
		x->cle=nouveauCle;
		x->n=x->n+1;
		ecrireDisque(x);
	}
	else{
		while(i>=1 && k<x->cle[i-1]){
			i=i-1;		
		}
		i=i+1;
		lireDisque(x->c[i-1]);
		if(x->c[i-1]->n==2*t-1){
			partager_enfant_B_arbre(x,i,x->c[i-1]);
			if(k>x->cle[i-1])
				i=i+1;		
		}
		inserer_B_arbre_incomplet(x->c[i-1],k);
	}
}


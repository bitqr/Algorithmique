#include"B_ARBRE.h"

void partager_enfant_B_arbre(NOEUD_B_ARBRE *x, int i, NOEUD_B_ARBRE *y){
	NOEUD_B_ARBRE *z=allouerNoeud();
	z->feuille=y->feuille;
	z->n=t-1;
	z->cle=(int *)malloc(z->n*sizeof(int));
	z->c=(NOEUD_B_ARBRE **)malloc((z->n+1)*sizeof(NOEUD_B_ARBRE *));
	NOEUD_B_ARBRE **nouveauCx=(NOEUD_B_ARBRE **)malloc((x->n+2)*sizeof(NOEUD_B_ARBRE *));
	int *nouveauClex=(int *)malloc((x->n+1)*sizeof(int));	
	int j;
	for(j=1;j<=t-1;j++)
		z->cle[j-1]=y->cle[j+t-1];
	if(!y->feuille){
		for(j=1;j<=t;j++)
			z->c[j-1]=y->c[j+t-1];	
	}
	y->n=t-1;
	for(j=x->n+1;j>=i+1;j--)
		nouveauCx[j]=x->c[j-1];
	nouveauCx[i]=z;
	for(j=1;j<=i;j++)
		nouveauCx[j-1]=x->c[j-1];
	x->c=nouveauCx;
	for(j=x->n;j>=i;j--)
		nouveauClex[j]=x->cle[j-1];
	nouveauClex[i-1]=y->cle[t-1];
	for(j=1;j<=i-1;j++)
		nouveauClex[j-1]=x->cle[j-1];
	x->cle=nouveauClex;
	x->n=x->n+1;
	ecrireDisque(y);
	ecrireDisque(z);
	ecrireDisque(x);
}


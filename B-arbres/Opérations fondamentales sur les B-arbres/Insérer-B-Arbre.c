#include"B_ARBRE.h"

void inserer_B_arbre(B_ARBRE *T, int k){
	NOEUD_B_ARBRE *r=T->racine;
	if(r->n==2*t-1){
		NOEUD_B_ARBRE *s=allouerNoeud();
		T->racine=s;
		s->feuille=FAUX;
		s->n=0;
		s->c=(NOEUD_B_ARBRE **)malloc((s->n+1)*sizeof(NOEUD_B_ARBRE *));
		s->c[0]=r;
		partager_enfant_B_arbre(s,1,r);
		inserer_B_arbre_incomplet(s,k);
	}
	else
		inserer_B_arbre_incomplet(r,k);
}


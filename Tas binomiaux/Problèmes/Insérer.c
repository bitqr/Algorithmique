#include"TAS_2_3_4.h"

void inserer(TAS_2_3_4 *T, int k){
	NOEUD_TAS_2_3_4 *r = T->racine;
	if(r->n==0){
		r->n=1;
		r->cle=k;
	}
	else{
		if(r->feuille){
			NOEUD_TAS_2_3_4 *s=allouerNoeud();
			s->n=1;
			s->c=(NOEUD_TAS_2_3_4 **)malloc(2*sizeof(NOEUD_TAS_2_3_4 *));
			s->c[0]=r;
			s->feuille=FAUX;
			T->racine=s;
			r->p=s;
			s->hauteur=1;
			NOEUD_TAS_2_3_4 *s2=allouerNoeud();
			s->c[1]=s2;
			s2->n=1;
			s2->feuille=VRAI;
			s2->cle=k;
			s2->p=s;
			if(k<r->cle){
				s->petit=k;
			}
			else{
				s->petit=r->cle;
			}
		}
		else{
			if(r->n==3){
				NOEUD_TAS_2_3_4 *s=allouerNoeud();
				T->racine=s;
				s->hauteur=r->hauteur+1;
				s->feuille=FAUX;
				r->p=s;
				s->petit=r->petit;
				if(k<r->petit){
					s->petit=k;
				}
				s->n=0;
				s->c=(NOEUD_TAS_2_3_4 **)malloc(2*sizeof(NOEUD_TAS_2_3_4 *));
				s->c[0]=r;
				partager(r);
			}
			inserer_incomplet(r,k);
		}
	}
}

void partager(NOEUD_TAS_2_3_4 *x){
	x->p->n=x->p->n+1;
	NOEUD_TAS_2_3_4 *y=allouerNoeud();
	x->p->c=(NOEUD_TAS_2_3_4 **)realloc(x->p->c,(x->p->n+1)*sizeof(NOEUD_TAS_2_3_4 *));
	x->p->c[x->p->n]=y;
	y->p=x->p;
	y->n=1;
	y->feuille=FAUX;
	y->c=(NOEUD_TAS_2_3_4 **)malloc(2*sizeof(NOEUD_TAS_2_3_4 *));
	y->c[0]=x->c[2];
	y->c[1]=x->c[3];
	y->c[0]->p=y;
	y->c[1]->p=y;
	if(x->c[0]->feuille){
		if(y->c[0]->cle<y->c[1]->cle){
			y->petit=y->c[0]->cle;
		}
		else{
			y->petit=y->c[1]->cle;
		}
	}
	else{
		if(y->c[0]->petit<y->c[1]->petit){
			y->petit=y->c[0]->petit;
		}
		else{
			y->petit=y->c[1]->petit;
		}
	}
	x->n=1;
	if(x->c[0]->feuille){
		if(x->c[0]->cle<x->c[1]->cle){
			x->petit=x->c[0]->cle;
		}
		else{
			x->petit=x->c[1]->cle;
		}
	}
	else{
		if(x->c[0]->petit<x->c[1]->petit){
			x->petit=x->c[0]->petit;
		}
		else{
			x->petit=x->c[1]->petit;
		}
	}
}

void inserer_incomplet(NOEUD_TAS_2_3_4 *x, int k){
	if(k<x->petit){
		x->petit=k;
	}
	if(x->c[0]->feuille){
		x->n=x->n+1;
		NOEUD_TAS_2_3_4 *y=allouerNoeud();
		x->c=(NOEUD_TAS_2_3_4 **)realloc(x->c,(x->n+1)*sizeof(NOEUD_TAS_2_3_4 *));
		x->c[x->n]=y;
		y->p=x;
		y->feuille=VRAI;
		y->cle=k;
		y->n=1;
	}
	else{
		if(x->c[0]->n==3){
			partager(x->c[0]);
		}
		inserer_incomplet(x->c[0],k);
	}
}

NOEUD_TAS_2_3_4 *allouerNoeud(){
	return (NOEUD_TAS_2_3_4 *)malloc(sizeof(NOEUD_TAS_2_3_4));
}




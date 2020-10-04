#include"TAS_2_3_4.h"

TAS_2_3_4 *union_tas_2_3_4(TAS_2_3_4 *T1, TAS_2_3_4 *T2){
	NOEUD_TAS_2_3_4 *r1=T1->racine;
	NOEUD_TAS_2_3_4 *r2=T2->racine;
	TAS_2_3_4 *T=(TAS_2_3_4 *)malloc(sizeof(TAS_2_3_4));
	int h1=r1->hauteur;
	int h2=r2->hauteur;
	if(r1->n==0){
		T->racine=T2->racine;
		free(T1);
		free(T2);
		return T;
	}
	if(r2->n==0){
		T->racine=T1->racine;
		free(T1);
		free(T2);
		return T;
	}
	if(h1==h2){
		NOEUD_TAS_2_3_4 *r=allouerNoeud();
		T->racine=r;
		r->feuille=FAUX;
		r->n=1;
		r->c=(NOEUD_TAS_2_3_4 **)malloc(2*sizeof(NOEUD_TAS_2_3_4 *));
		r->c[0]=r1;
		r->c[1]=r2;
		r->hauteur=h1+1;
		r->c[0]->p=r;
		r->c[1]->p=r;
		if(r->c[0]->feuille){
			if(r1->cle<r2->cle){
				r->petit=r1->cle;
			}
			else{
				r->petit=r2->cle;
			}
		}
		else{
			if(r1->petit<r2->petit){
				r->petit=r1->petit;
			}
			else{
				r->petit=r2->petit;
			}
		}
		free(T1);
		free(T2);
		return T;
	}
	else{
		if(h1>h2){
			if(r1->n==3){
				NOEUD_TAS_2_3_4 *s1=allouerNoeud();
				s1->feuille=FAUX;
				s1->n=0;
				s1->c=(NOEUD_TAS_2_3_4 **)malloc(2*sizeof(NOEUD_TAS_2_3_4 *));
				s1->c[0]=r1;
				r1->p=s1;
				s1->hauteur=h1+1;
				T1->racine=s1;
				s1->petit=r1->petit;
				partager(r1);
				union_incomplet(s1,r2,h1-h2+1);
			}
			else{
				union_incomplet(r1,r2,h1-h2);
			}
			T->racine=T1->racine;
		}
		else{
			if(r2->n==3){
				NOEUD_TAS_2_3_4 *s2=allouerNoeud();
				s2->feuille=FAUX;
				s2->n=0;
				s2->c=(NOEUD_TAS_2_3_4 **)malloc(2*sizeof(NOEUD_TAS_2_3_4 *));
				s2->c[0]=r2;
				r2->p=s2;
				s2->hauteur=h2+1;
				T2->racine=s2;
				s2->petit=r2->petit;
				partager(r2);
				union_incomplet(s2,r1,h2-h1+1);
			}
			else{
				union_incomplet(r2,r1,h2-h1);
			}
			T->racine=T2->racine;
		}
		free(T1);
		free(T2);
		return T;
	}
}

void union_incomplet(NOEUD_TAS_2_3_4 *x1, NOEUD_TAS_2_3_4 *x2, int h){
	if(x2->feuille && x2->cle<x1->petit){
		x1->petit=x2->cle;
	}
	if(!x2->feuille && x2->petit<x1->petit){
		x1->petit=x2->petit;
	}
	if(h==1){
		x1->n=x1->n+1;
		x1->c=(NOEUD_TAS_2_3_4 **)realloc(x1->c,(x1->n+1)*sizeof(NOEUD_TAS_2_3_4 *));
		x1->c[x1->n]=x2;
		x2->p=x1;
	}
	else{
		if(x1->c[0]->n==3){
			partager(x1->c[0]);
		}
		union_incomplet(x1->c[0],x2,h-1);
	}
}





#include"TAS_2_3_4.h"

void supprimer(TAS_2_3_4 *T, NOEUD_TAS_2_3_4 *x){
	if(x==T->racine){
		x->n=0;
	}
	else{
		if(x->p->n>=2){
			int i=0;
			while(i<=x->p->n && x->p->c[i]!=x){
				i=i+1;
			}
			while(i<x->p->n){
				x->p->c[i]=x->p->c[i+1];
				i=i+1;
			}
			x->p->n=x->p->n-1;
			if(x->p->petit==x->cle){
				x->p->petit=x->p->c[0]->cle;
				int i;
				for(i=1;i<=x->p->n;i++){
					if(x->p->c[i]->cle<x->p->petit){
						x->p->petit=x->p->c[i]->cle;
					}
				}
				NOEUD_TAS_2_3_4 *y=x->p;
				while(y!=T->racine){
					y=y->p;
					y->petit=y->c[0]->petit;
					int i;
					for(i=1;i<=y->n;i++){
						if(y->c[i]->petit<y->petit){
							y->petit=y->c[i]->petit;
						}
					}
				}
			}
		}
		else{
			NOEUD_TAS_2_3_4 *y;
			if(x==x->p->c[0]){
				y=x->p->c[1];
			}
			else{
				y=x->p->c[0];
			}
			x->p->n=x->p->n-1;
			x->p->c[0]=y;
			x->p->petit=y->cle;
			supprimer_interne(T,x->p);
		}
	}
}

void supprimer_interne(TAS_2_3_4 *T, NOEUD_TAS_2_3_4 *x){
	if(x==T->racine){
		T->racine=x->c[0];
		x->c[0]->hauteur=x->hauteur-1;
	}
	else{
		NOEUD_TAS_2_3_4 *y=x->p;
		int i=0;
		while(i<=y->n && y->c[i]->n<=1){
			i=i+1;
		}
		if(i<=y->n){
			NOEUD_TAS_2_3_4 *z=y->c[i];
			x->c[1]=z->c[z->n];
			z->n=z->n-1;
			if(x->c[1]->feuille && z->petit==x->c[1]->cle){
				z->petit=z->c[0]->cle;
				for(i=1;i<=z->n;i++){
					if(z->petit>z->c[i]->cle){
						z->petit=z->c[i]->cle;
					}
				}
			}
			if(!x->c[1]->feuille && z->petit==x->c[1]->petit){
				z->petit=z->c[0]->petit;
				for(i=1;i<=z->n;i++){
					if(z->petit>z->c[i]->petit){
						z->petit=z->c[i]->petit;
					}
				}
			}
			if(x->c[1]->feuille && x->c[1]->cle<x->petit){
				x->petit=x->c[1]->cle;
			}
			if(!x->c[1]->feuille && x->c[1]->petit<x->petit){
				x->petit=x->c[1]->petit;
			}
			x->n=x->n+1;
			x->c[1]->p=x;
		}
		else{
			NOEUD_TAS_2_3_4 *z;
			if(y->c[0]==x){
				z=y->c[1];
			}
			else{
				z=y->c[0];
			}
			z->n=z->n+1;
			NOEUD_TAS_2_3_4 **nC=(NOEUD_TAS_2_3_4 **)malloc((z->n+1)*sizeof(NOEUD_TAS_2_3_4 *));
			int i;
			for(i=0;i<z->n;i++){
				nC[i]=z->c[i];
			}
			nC[z->n]=x->c[0];
			z->c=nC;
			if(x->petit<z->petit){
				z->petit=x->petit;
			}
			x->c[0]->p=z;
			i=0;
			while(i<=y->n && y->c[i]!=x){
				i=i+1;
			}
			while(i<=y->n){
				y->c[i]=y->c[i+1];
				i=i+1;
			}
			y->n=y->n-1;
			if(y->n==0){
				supprimer_interne(T,y);
			}
		}
	}
}




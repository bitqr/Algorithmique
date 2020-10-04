#include"ARBRE_2_3_4.h"
#include<stdlib.h>

void supprimer_arbre_2_3_4_avec_hauteur(ARBRE_2_3_4 *T, int k){
	NOEUD_ARBRE_2_3_4 *r=T->racine;
	int j=r->n;
	while(j>=1 && k<r->cle[j-1]){
		j=j-1;
	}
	if(j>=1 && k==r->cle[j-1]){
		if(r->feuille){
			int i;
			for(i=j;i<=r->n-1;i++){
				r->cle[i-1]=r->cle[i];
			}
			r->n=r->n-1;
			ecrireDisque(r);
		}
		else{
			lireDisque(r->c[j-1]);
			if(r->c[j-1]->n>=2){
				int k1=supprimer_cle_maximale_arbre_2_3_4_avec_hauteur(r->c[j-1]);
				r->cle[j-1]=k1;
				ecrireDisque(r);
			}
			else{
				lireDisque(r->c[j]);
				if(r->c[j]->n>=2){
					int k1=supprimer_cle_minimale_arbre_2_3_4_avec_hauteur(r->c[j]);
					r->cle[j-1]=k1;
					ecrireDisque(r);
				}
				else{
					int *nCle=(int *)malloc(2*sizeof(int));
					nCle[1]=r->c[j]->cle[0];
					nCle[0]=k;
					r->c[j]->cle=nCle;
					int *nouvCle=(int *)malloc(3*sizeof(int));
					nouvCle[0]=r->c[j-1]->cle[0];
					nouvCle[1]=r->c[j]->cle[0];
					nouvCle[2]=r->c[j]->cle[1];
					r->c[j-1]->cle=nouvCle;
					r->c[j-1]->n=3;
					if(!r->c[j-1]->feuille){
						NOEUD_ARBRE_2_3_4 **nC=(NOEUD_ARBRE_2_3_4 **)malloc(4*sizeof(NOEUD_ARBRE_2_3_4 *));
						nC[0]=r->c[j-1]->c[0];
						nC[1]=r->c[j-1]->c[1];
						nC[2]=r->c[j-1]->c[2];
						nC[3]=r->c[j-1]->c[3];
						r->c[j-1]->c=nC;
					}
					int i;
					for(i=j;i<=r->n-1;i++){
						r->cle[i-1]=r->cle[i];
						r->c[i]=r->c[i+1];
					}
					r->n=r->n-1;
					if(r->n==0){
						T->racine=r->c[j-1];
					}
					else{
						ecrireDisque(r);
					}
					supprimer_arbre_2_3_4_avec_hauteur_incomplet(r->c[j-1],k);
				}
			}
		}
	}
	else{
		if(r->feuille){
			fprintf(stderr,"La clé est introuvable\n");
		}
		else{
			j=j+1;
			lireDisque(r->c[j-1]);
			if(r->c[j-1]->n==1){
				if(j>=2){
					lireDisque(r->c[j-2]);
					if(r->c[j-2]->n>=2){
						supprimer_arbre_2_3_4_avec_frere_gauche(r,j);
					}
					else{
						if(j<=r->n){
							lireDisque(r->c[j]);
							if(r->c[j]->n>=2){
								supprimer_arbre_2_3_4_avec_frere_droit(r,j);
							}
							else{
								supprimer_arbre_2_3_4_fusion_frere_gauche(T,j);
								j=j-1;
							}
						}
						else{
							supprimer_arbre_2_3_4_fusion_frere_gauche(T,j);
							j=j-1;
						}
					}
				}
				else{
					if(r->c[1]->n>=2){
						supprimer_arbre_2_3_4_avec_frere_droit(r,j);
					}
					else{
						supprimer_arbre_2_3_4_fusion_frere_droit(T,j);
					}
				}
			}	
			supprimer_arbre_2_3_4_avec_hauteur_incomplet(r->c[j-1],k);
		}
	}
}

int supprimer_cle_maximale_arbre_2_3_4_avec_hauteur(NOEUD_ARBRE_2_3_4 *x){
	if(x->feuille){
		if(x->n==0){
			fprintf(stderr,"Pas de clé à supprimer\n");
			exit(EXIT_FAILURE);
		}
		else{
			int k=x->cle[x->n-1];
			x->n=x->n-1;
			ecrireDisque(x);
			return k;		
		}
	}
	else{
		lireDisque(x->c[x->n]);
		int j=x->n+1;
		if(x->c[j-1]->n==1){
			lireDisque(x->c[j-2]);
			if(x->c[j-2]->n>=2){
				supprimer_arbre_2_3_4_avec_frere_gauche(x,j);
			}
			else{
				supprimer_arbre_2_3_4_fusion_frere_gauche_incomplet(x,j);
				j=x->n;
			}
		}
		return supprimer_cle_maximale_arbre_2_3_4_avec_hauteur(x->c[j-1]);
	}
}

void supprimer_arbre_2_3_4_avec_frere_gauche(NOEUD_ARBRE_2_3_4 *x, int j){
	int *nCle=(int *)malloc(2*sizeof(int));
	nCle[1]=x->c[j-1]->cle[0];
	nCle[0]=x->cle[j-2];
	x->c[j-1]->cle=nCle;
	if(!x->c[j-1]->feuille){
		NOEUD_ARBRE_2_3_4 **nC=(NOEUD_ARBRE_2_3_4 **)malloc(3*sizeof(NOEUD_ARBRE_2_3_4 *));
		nC[2]=x->c[j-1]->c[1];
		nC[1]=x->c[j-1]->c[0];
		nC[0]=x->c[j-2]->c[x->c[j-2]->n];
		x->c[j-1]->c=nC;
	}
	x->c[j-1]->n=x->c[j-1]->n+1;
	x->cle[j-2]=x->c[j-2]->cle[x->c[j-2]->n-1];
	x->c[j-2]->n=x->c[j-2]->n-1;
	ecrireDisque(x);
	ecrireDisque(x->c[j-2]);
	ecrireDisque(x->c[j-1]);
}

void supprimer_arbre_2_3_4_fusion_frere_gauche_incomplet(NOEUD_ARBRE_2_3_4 *x, int j){
	int *nCle=(int *)malloc(3*sizeof(int));
	nCle[0]=x->c[j-2]->cle[0];
	nCle[1]=x->cle[j-2];
	nCle[2]=x->c[j-1]->cle[0];
	x->c[j-2]->cle=nCle;
	if(!x->c[j-2]->feuille){
		NOEUD_ARBRE_2_3_4 **nC=(NOEUD_ARBRE_2_3_4 **)malloc(4*sizeof(NOEUD_ARBRE_2_3_4 *));
		nC[0]=x->c[j-2]->c[0];
		nC[1]=x->c[j-2]->c[1];
		nC[2]=x->c[j-1]->c[0];
		nC[3]=x->c[j-1]->c[1];
		x->c[j-2]->c=nC;
	}
	x->c[j-2]->n=3;
	int i;
	for(i=j-1;i<=x->n-1;i++){
		x->cle[i-1]=x->cle[i];
		x->c[i]=x->c[i+1];
	}
	x->n=x->n-1;
	ecrireDisque(x);
	ecrireDisque(x->c[j-2]);
}

int supprimer_cle_minimale_arbre_2_3_4_avec_hauteur(NOEUD_ARBRE_2_3_4 *x){
	if(x->feuille){
		if(x->n==0){
			fprintf(stderr,"Pas de clé à supprimer\n");
			exit(EXIT_FAILURE);
		}
		else{
			int k=x->cle[0];
			int j;
			for(j=1;j<=x->n-1;j++){
				x->cle[j-1]=x->cle[j];
			}
			x->n=x->n-1;
			ecrireDisque(x);
			return k;
		}
	}
	else{
		lireDisque(x->c[0]);
		if(x->c[0]->n==1){
			lireDisque(x->c[1]);
			if(x->c[1]->n>=2){
				supprimer_arbre_2_3_4_avec_frere_droit(x,1);
			}
			else{
				supprimer_arbre_2_3_4_fusion_frere_droit_incomplet(x,1);
			}
		}
		return supprimer_cle_minimale_arbre_2_3_4_avec_hauteur(x->c[0]);
	}
}

void supprimer_arbre_2_3_4_avec_frere_droit(NOEUD_ARBRE_2_3_4 *x, int j){
	int *nCle=(int *)malloc(2*sizeof(int));
	nCle[0]=x->c[j-1]->cle[0];
	nCle[1]=x->cle[j-1];
	x->c[j-1]->cle=nCle;
	if(!x->c[j-1]->feuille){
		NOEUD_ARBRE_2_3_4 **nC=(NOEUD_ARBRE_2_3_4 **)malloc(3*sizeof(NOEUD_ARBRE_2_3_4 *));
		nC[0]=x->c[j-1]->c[0];
		nC[1]=x->c[j-1]->c[1];
		nC[2]=x->c[j]->c[0];
		x->c[j-1]->c=nC;
	}
	x->c[j-1]->n=x->c[j-1]->n+1;
	x->cle[j-1]=x->c[j]->cle[0];
	int i;
	for(i=1;i<=x->c[j]->n-1;i++){
		x->c[j]->cle[i-1]=x->c[j]->cle[i];
	}
	if(!x->c[j]->feuille){
		for(i=1;i<=x->c[j]->n;i++){
			x->c[j]->c[i-1]=x->c[j]->c[i];
		}
	}
	x->c[j]->n=x->c[j]->n-1;
	ecrireDisque(x);
	ecrireDisque(x->c[j]);
	ecrireDisque(x->c[j-1]);
}

void supprimer_arbre_2_3_4_fusion_frere_droit_incomplet(NOEUD_ARBRE_2_3_4 *x, int j){
	int *nCle=(int *)malloc(3*sizeof(int));
	nCle[0]=x->c[j-1]->cle[0];
	nCle[1]=x->cle[j-1];
	nCle[2]=x->c[j]->cle[0];
	x->c[j-1]->cle=nCle;
	if(!x->c[j-1]->feuille){
		NOEUD_ARBRE_2_3_4 **nC=(NOEUD_ARBRE_2_3_4 **)malloc(4*sizeof(NOEUD_ARBRE_2_3_4 *));
		nC[0]=x->c[j-1]->c[0];
		nC[1]=x->c[j-1]->c[1];
		nC[2]=x->c[j]->c[0];
		nC[3]=x->c[j]->c[1];
		x->c[j-1]->c=nC;
	}
	x->c[j-1]->n=3;
	int i;
	for(i=j;i<=x->n-1;i++){
		x->cle[i-1]=x->cle[i];
		x->c[i]=x->c[i+1];
	}
	x->n=x->n-1;
	ecrireDisque(x);
	ecrireDisque(x->c[j-1]);
}

void supprimer_arbre_2_3_4_fusion_frere_gauche(ARBRE_2_3_4 *T, int j){
	NOEUD_ARBRE_2_3_4 *r=T->racine;
	int *nCle=(int *)malloc(3*sizeof(int));
	nCle[0]=r->c[j-2]->cle[0];
	nCle[1]=r->cle[j-2];
	nCle[2]=r->c[j-1]->cle[0];
	r->c[j-2]->cle=nCle;
	if(!r->c[j-2]->feuille){
		NOEUD_ARBRE_2_3_4 **nC=(NOEUD_ARBRE_2_3_4 **)malloc(4*sizeof(NOEUD_ARBRE_2_3_4 *));
		nC[0]=r->c[j-2]->c[0];
		nC[1]=r->c[j-2]->c[1];
		nC[2]=r->c[j-1]->c[0];
		nC[3]=r->c[j-1]->c[1];
		r->c[j-2]->c=nC;
	}
	r->c[j-2]->n=3;
	int i;
	for(i=j-1;i<=r->n-1;i++){
		r->cle[i-1]=r->cle[i];
		r->c[i]=r->c[i+1];
	}
	r->n=r->n-1;
	if(r->n==0){
		T->racine=r->c[j-2];
	}
	else{
		ecrireDisque(r);
	}
	ecrireDisque(r->c[j-2]);
}

void supprimer_arbre_2_3_4_fusion_frere_droit(ARBRE_2_3_4 *T, int j){
	NOEUD_ARBRE_2_3_4 *r=T->racine;
	int *nCle=(int *)malloc(3*sizeof(int));
	nCle[0]=r->c[j-1]->cle[0];
	nCle[1]=r->cle[j-1];
	nCle[2]=r->c[j]->cle[0];	
	r->c[j-1]->cle=nCle;
	if(!r->c[j-1]->feuille){
		NOEUD_ARBRE_2_3_4 **nC=(NOEUD_ARBRE_2_3_4 **)malloc(4*sizeof(NOEUD_ARBRE_2_3_4 *));
		nC[0]=r->c[j-1]->c[0];
		nC[1]=r->c[j-1]->c[1];
		nC[2]=r->c[j]->c[0];
		nC[3]=r->c[j]->c[1];
		r->c[j-1]->c=nC;
	}
	r->c[j-1]->n=3;
	int i;
	for(i=j;i<=r->n-1;i++){
		r->cle[i-1]=r->cle[i];
		r->c[i]=r->c[i+1];
	}
	r->n=r->n-1;
	if(r->n==0){
		T->racine=r->c[j-1];
	}
	else{
		ecrireDisque(r);
	}
	ecrireDisque(r->c[j-1]);
}

void supprimer_arbre_2_3_4_avec_hauteur_incomplet(NOEUD_ARBRE_2_3_4 *x, int k){
	int j=x->n;
	while(j>=1 && k<x->cle[j-1]){
		j=j-1;
	}
	if(j>=1 && k==x->cle[j-1]){
		if(x->feuille){
			int i;
			for(i=j;i<=x->n-1;i++){
				x->cle[i-1]=x->cle[i];
			}
			x->n=x->n-1;
			ecrireDisque(x);
		}
		else{
			lireDisque(x->c[j-1]);
			if(x->c[j-1]->n>=2){
				int k1=supprimer_cle_maximale_arbre_2_3_4_avec_hauteur(x->c[j-1]);
				x->cle[j-1]=k1;
				ecrireDisque(x);
			}
			else{
				lireDisque(x->c[j]);
				if(x->c[j]->n>=2){
					int k1=supprimer_cle_minimale_arbre_2_3_4_avec_hauteur(x->c[j]);
					x->cle[j-1]=k1;
					ecrireDisque(x);
				}
				else{
					int *nCle=(int *)malloc(2*sizeof(int));
					nCle[1]=x->c[j]->cle[0];
					nCle[0]=k;
					x->c[j]->cle=nCle;
					int *nouvCle=(int *)malloc(3*sizeof(int));
					nouvCle[0]=x->c[j-1]->cle[0];
					nouvCle[1]=x->c[j]->cle[0];
					nouvCle[2]=x->c[j]->cle[1];
					x->c[j-1]->cle=nouvCle;
					x->c[j-1]->n=3;
					if(!x->c[j-1]->feuille){
						NOEUD_ARBRE_2_3_4 **nC=(NOEUD_ARBRE_2_3_4 **)malloc(4*sizeof(NOEUD_ARBRE_2_3_4 *));
						nC[0]=x->c[j-1]->c[0];
						nC[1]=x->c[j-1]->c[1];
						nC[2]=x->c[j-1]->c[2];
						nC[3]=x->c[j-1]->c[3];
						x->c[j-1]->c=nC;
					}
					int i;
					for(i=j;i<=x->n-1;i++){
						x->cle[i-1]=x->cle[i];
						x->c[i]=x->c[i+1];
					}
					x->n=x->n-1;
					ecrireDisque(x);
					supprimer_arbre_2_3_4_avec_hauteur_incomplet(x->c[j-1],k);
				}
			}
		}
	}
	else{
		if(x->feuille){
			fprintf(stderr,"La clé est introuvable\n");
		}
		else{
			j=j+1;
			lireDisque(x->c[j-1]);
			if(x->c[j-1]->n==1){
				if(j>=2){
					lireDisque(x->c[j-2]);
					if(x->c[j-2]->n>=2){
						supprimer_arbre_2_3_4_avec_frere_gauche(x,j);
					}
					else{
						if(j<=x->n){
							lireDisque(x->c[j]);
							if(x->c[j]->n>=2){
								supprimer_arbre_2_3_4_avec_frere_droit(x,j);
							}
							else{
								supprimer_arbre_2_3_4_fusion_frere_gauche_incomplet(x,j);
								j=j-1;
							}
						}
						else{
							supprimer_arbre_2_3_4_fusion_frere_gauche_incomplet(x,j);
							j=j-1;
						}
					}
				}
				else{
					if(x->c[1]->n>=2){
						supprimer_arbre_2_3_4_avec_frere_droit(x,j);
					}
					else{
						supprimer_arbre_2_3_4_fusion_frere_droit_incomplet(x,j);
					}
				}
			}	
			supprimer_arbre_2_3_4_avec_hauteur_incomplet(x->c[j-1],k);
		}
	}
}






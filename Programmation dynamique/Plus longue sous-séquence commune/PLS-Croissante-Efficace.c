#include"PLSC.h"


void rn_inserer_correction(ARN * T, NOEUD *z){
	NOEUD *y;
	while(z->p->couleur == ROUGE){
		if(z->p == z->p->p->gauche){ 
			y = z->p->p->droite;
			if(y->couleur == ROUGE){ 
				z->p->couleur = NOIR; //Cas 1
				y->couleur = NOIR; //Cas 1
				z->p->p->couleur = ROUGE; //Cas 1
				z = z->p->p; //Cas 1
				}
			else{ 
				if(z == z->p->droite){ 
					z = z->p; //Cas 2
					rotation_gauche(T,z); //Cas 2
					}
				z->p->couleur = NOIR; //Cas 3
				z->p->p->couleur = ROUGE; //Cas 3
				rotation_droite(T,z->p->p); //Cas 3
				}
			}
		else{
			y = z->p->p->gauche;
			if(y->couleur == ROUGE){ 
				z->p->couleur = NOIR; //Cas 1
				y->couleur = NOIR; //Cas 1
				z->p->p->couleur = ROUGE; //Cas 1
				z = z->p->p; //Cas 1
				}
			else{ 
				if(z == z->p->gauche){ 
					z = z->p; //Cas 2
					rotation_droite(T,z); //Cas 2
					}
				z->p->couleur = NOIR; //Cas 3
				z->p->p->couleur = ROUGE; //Cas 3
				rotation_gauche(T,z->p->p); //Cas 3
				}
			}
		}
		T->racine->couleur = NOIR;
}


void rn_inserer(ARN *T, NOEUD *z){
	NOEUD *y = T->nil;
	NOEUD *x = T->racine;
	while(x != T->nil){
		y = x;
		if(z->cle < x->cle)
			x = x->gauche;
		else
			x = x->droite;
		}
	z->p = y;
	if(y == T->nil)
		T->racine = z;
	else
		if(z->cle < y->cle)
			y->gauche = z;
		else
			y->droite = z;
	z->gauche = T->nil;
	z->droite = T->nil;
	z->couleur = ROUGE;
	rn_inserer_correction(T,z);
}

void rotation_gauche(ARN *T, NOEUD *x){
	NOEUD *y = x->droite; //initialise y.
	x->droite = y->gauche; //sous-arbre gauche de y devient sous-arbre droit de x.
	if(y->gauche != T->nil)
		y->gauche->p = x;
	y->p = x->p; //relie parent de x Ã y.
	if(x->p == T->nil)
		T->racine = y;
	else 
		if(x == x->p->gauche)
			x->p->gauche = y;
		else 
			x->p->droite = y;
	y->gauche = x; //place x Ã gauche de y.
	x->p = y;
}


NOEUD *creerNoeudRN(int cle, NOEUD *g, NOEUD *d, int couleur){
	NOEUD * node = (NOEUD *) malloc(sizeof(NOEUD));
	node->cle = cle;
	node->gauche = g;
	node->droite = d;
	node->couleur = couleur;
	return node;
}

ARN * creerARN(NOEUD *racine, NOEUD *nil){
	ARN * a = (ARN *)malloc(sizeof(ARN));
	a->racine = racine;
	a->nil = nil;
	return a;
}

void rotation_droite(ARN *T, NOEUD *x){
	NOEUD *y = x->gauche; //initialise y.
	x->gauche = y->droite; //sous-arbre droit de y devient sous-arbre gauche de x.
	if(y->droite != T->nil)
		y->droite->p = x;
	y->p = x->p; //relie parent de x Ã y.
	if(x->p == T->nil)
		T->racine = y;
	else 
		if(x == x->p->gauche)
			x->p->gauche = y;
		else 
			x->p->droite = y;
	y->droite = x; //place x Ã droite de y.
	x->p = y;
	
}


void imprimer_suite(int *P, SEQUENCE *X, int ind){
	if(P[ind] != -1){
		imprimer_suite(P,X,P[ind]);
		printf("%d ",X->entiers[P[ind]]);
	}
}

int plus_proche_inferieur(SEQUENCE *X, int *M, int e, int f, int c){
	if((e==-1 && f==-1) || (e==-1 && X->entiers[M[f]] > c) || (f==-1 && X->entiers[M[e]] > c))
		return -1;
	if(e==-1 && X->entiers[M[f]] <= c)
		return f;
	if(f==-1 && X->entiers[M[e]] <= c)
		return e;
	if(X->entiers[M[e]] < X->entiers[M[f]]){
		if(X->entiers[M[f]] <= c)
			return f;
		else{
			if(X->entiers[M[e]] <= c)
				return e;
			else return -1;
		}
	}
	else{
		if(X->entiers[M[e]] <= c)
			return e;
		else{
			if(X->entiers[M[f]] <= c)
				return f;
			else return -1;
		}
	}
}

int recherche_idoine(ARN *A, int *M, NOEUD *x, SEQUENCE *X, int c){
	if(x == A->nil)
		return -1;
	if(X->entiers[M[x->cle]] == c)
		return x->cle;
	else
		if(X->entiers[M[x->cle]] < c){
			if(x->droite == A->nil )
				return x->cle;
			else{
				int e = recherche_idoine(A,M,x->droite,X,c);
				return plus_proche_inferieur(X,M,e,x->cle,c);
			}
		}
		else{
			if(x->gauche == A->nil)
				return (X->entiers[M[x->cle]] == c)?x->cle:-1;
			else{
				int e = recherche_idoine(A,M,x->gauche,X,c);
				return plus_proche_inferieur(X,M,e,x->cle,c);
			}
		
		}
}

void pls_croissante_efficace(SEQUENCE* X){
	int n = X->longueur;
	int *M = (int *)malloc(n*sizeof(int));
	int *P = (int *)malloc(n*sizeof(int));
	M[0] = 0;
	P[0] = -1;
	int L = 0;
	NOEUD *nl = (NOEUD *)malloc(sizeof(NOEUD));
	nl->couleur = NOIR;
	NOEUD *r = creerNoeudRN(0,nl,nl,NOIR);
	ARN * A = creerARN(nl,nl);
	rn_inserer(A,r);
	int i,j;
	for(i=1;i<n;i++){
		j = recherche_idoine(A,M,A->racine,X,X->entiers[i]);
		//printf("%d\n",j);
		P[i] = (j>=0)?M[j]:-1;
		if((j==L) || (X->entiers[i] < X->entiers[M[j+1]])){
			if(j==L){
				NOEUD *z = (NOEUD *)malloc(sizeof(NOEUD));
				z->cle = j+1;
				rn_inserer(A,z);
			}
			M[j+1] = i;
			L = (L < j+1)?j+1:L;
		}
	}
	imprimer_suite(P,X,M[L]);
	printf("%d\n\n\n", X->entiers[M[L]]);
}




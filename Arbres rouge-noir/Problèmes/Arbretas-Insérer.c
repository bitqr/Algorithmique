#include"AT.h"


void rotation_gauche(ARBRETAS *T, NOEUD *x){
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


NOEUD *creerNoeudARBRETAS(int cle, int priorite, NOEUD *g, NOEUD *d){
	NOEUD * node = (NOEUD *) malloc(sizeof(NOEUD));
	node->cle = cle;
	node->gauche = g;
	node->droite = d;
	node->priorite = priorite;
	return node;
}

ARBRETAS * creerARBRETAS(NOEUD *racine, NOEUD *nil){
	ARBRETAS * a = (ARBRETAS *)malloc(sizeof(ARBRETAS));
	a->racine = racine;
	a->nil = nil;
	return a;
}


void rotation_droite(ARBRETAS *T, NOEUD *x){
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


void parcoursPrefixeAT(NOEUD *x,NOEUD *nl){
	if(x != nl){
		printf("%d(%d)\t",x->cle,x->priorite);
		parcoursPrefixeAT(x->gauche,nl);
		parcoursPrefixeAT(x->droite,nl);
		}
}

void arbretas_inserer(ARBRETAS *T, NOEUD *z){
	NOEUD *x = T->racine;
	NOEUD *y = T->nil;
	while(x != T->nil){
		y = x;
		if(z->cle < x->cle)
			x = x->gauche;
		else
			x = x->droite;
	}
	if(y != T->nil)
		if(y->cle < z->cle)
			y->droite = z;
		else
			y->gauche = z;
	z->p = y;
	x = z;
	while(x->p != T->nil && x->priorite < x->p->priorite){
		if(x == x->p->gauche)
			rotation_droite(T,x->p);
		else
			rotation_gauche(T,x->p);
	}
	if(x->p == T->nil)
		T->racine = x;
}


int main(int argc, char **argv){
	NOEUD *nl;
	NOEUD *I = creerNoeudARBRETAS(9,73,nl,nl);
	NOEUD *K = creerNoeudARBRETAS(11,65,I,nl);
	NOEUD *H = creerNoeudARBRETAS(8,5,nl,K);
	NOEUD *E = creerNoeudARBRETAS(5,23,nl,nl);
	NOEUD *A = creerNoeudARBRETAS(1,10,nl,nl);
	NOEUD *B = creerNoeudARBRETAS(2,7,A,E);
	NOEUD *G = creerNoeudARBRETAS(7,4,B,H);
	A->p = E->p = B; I->p = K; K->p = H; H->p = B->p = G; G->p = nl;
	ARBRETAS *T = creerARBRETAS(G,nl);
	parcoursPrefixeAT(T->racine,T->nil);
	printf("\n\n");
	NOEUD *z = creerNoeudARBRETAS(3,25,nl,nl);
	arbretas_inserer(T,z);
	parcoursPrefixeAT(T->racine,T->nil);
	printf("\n\n");
	NOEUD *z1 = creerNoeudARBRETAS(4,9,nl,nl);
	arbretas_inserer(T,z1);
	parcoursPrefixeAT(T->racine,T->nil);
	printf("\n\n");
	NOEUD *z2 = creerNoeudARBRETAS(6,2,nl,nl);
	arbretas_inserer(T,z2);
	parcoursPrefixeAT(T->racine,T->nil);
	printf("\n\n");
	return 0;
}



	


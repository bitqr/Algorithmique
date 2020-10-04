#include"ARN.h"

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


NOEUD *creerNoeud(int cle, NOEUD *g, NOEUD *d){
	NOEUD * node = (NOEUD *) malloc(sizeof(NOEUD));
	node->cle = cle;
	node->gauche = g;
	node->droite = d;
	return node;
}

ARN * creerARN(NOEUD *racine, NOEUD *nil){
	ARN * a = (ARN *)malloc(sizeof(ARN));
	a->racine = racine;
	a->nil = nil;
	return a;
}

void parcoursInfixe(NOEUD *x){
	if(x != NULL){
		parcoursInfixe(x->gauche);
		printf("%d\t",x->cle);
		parcoursInfixe(x->droite);
		}
}

void parcoursPrefixe(NOEUD *x){
	if(x != NULL){
		printf("%d\t",x->cle);
		parcoursPrefixe(x->gauche);
		parcoursPrefixe(x->droite);
		}
}




int main(int argc, char ** argv){
	NOEUD * nl;
	NOEUD * f1 = creerNoeud(9,nl,nl);
	NOEUD * f2 = creerNoeud(18,nl,nl);
	NOEUD * f3 = creerNoeud(33,nl,nl);
	NOEUD * f4 = creerNoeud(36,nl,nl);
	NOEUD * f12 = creerNoeud(15,f1,f2);
	NOEUD * f34 = creerNoeud(35,f3,f4);
	NOEUD * r = creerNoeud(28,f12,f34);
	r->p = nl; f1->p = f2->p = f12; f3->p = f4->p = f34; f12->p = f34->p = r;
	ARN * T = creerARN(r,nl);
	parcoursPrefixe(T->racine);
	printf("\nApres rotation gauche de la racine:\n");
	rotation_gauche(T,T->racine);
	parcoursPrefixe(T->racine);
	printf("\nApres rotation droite de la racine:\n");
	rotation_droite(T,T->racine);
	parcoursPrefixe(T->racine);
	return 0;
}



		
		
	

#include"ARN.h"

NOEUD * arbre_minimum(NOEUD *x, NOEUD *nl){
	while(x->gauche != nl)
		x = x->gauche;
	return x;
}

NOEUD * arbre_successeur(NOEUD *x, NOEUD *nl){
	if(x->droite != nl)
		return arbre_minimum(x->droite,nl);
	NOEUD * y = x->p;
	while(y != nl && x == y->droite){
		x = y;
		y = y->p;
	}
	return y;
}

NOEUD * rn_supprimer(ARN *T, NOEUD *z){
	NOEUD *y; NOEUD *x;
	if(z->gauche == T->nil || z->droite == T->nil)
		y = z;
	else 
		y = arbre_successeur(z,T->nil);
	if(y->gauche != T->nil)
		x = y->gauche;
	else
		x = y->droite;
	x->p = y->p;
	if(y->p == T->nil)
		T->racine = x;
	else 
		if(y == y->p->gauche)
			y->p->gauche = x;
		else 
			y->p->droite = x;
	if(y != z){
		z->cle = y->cle;
		z->couleur = y->couleur;
	}
	if(y->couleur == NOIR)
		rn_supprimer_correction(T,x);
	return y;
}

void rotation_droite(ARN *T, NOEUD *x){
	NOEUD *y = x->gauche; //initialise y.
	x->gauche = y->droite; //sous-arbre droit de y devient sous-arbre gauche de x.
	if(y->droite != T->nil)
		y->droite->p = x;
	y->p = x->p; //relie parent de x � y.
	if(x->p == T->nil)
		T->racine = y;
	else 
		if(x == x->p->gauche)
			x->p->gauche = y;
		else 
			x->p->droite = y;
	y->droite = x; //place x � droite de y.
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

void rotation_gauche(ARN *T, NOEUD *x){
	NOEUD *y = x->droite; //initialise y.
	x->droite = y->gauche; //sous-arbre gauche de y devient sous-arbre droit de x.
	if(y->gauche != T->nil)
		y->gauche->p = x;
	y->p = x->p; //relie parent de x � y.
	if(x->p == T->nil)
		T->racine = y;
	else 
		if(x == x->p->gauche)
			x->p->gauche = y;
		else 
			x->p->droite = y;
	y->gauche = x; //place x � gauche de y.
	x->p = y;
}

void parcoursPrefixeRN(NOEUD *x,NOEUD *nl){
	if(x != nl){
		printf("%d(",x->cle);
		if(x->couleur == ROUGE)
			printf("ROUGE)\n");
		else
			printf("NOIR)\n");
		parcoursPrefixeRN(x->gauche,nl);
		parcoursPrefixeRN(x->droite,nl);
	}
}

int main(int argc, char ** argv){
	NOEUD *nl = (NOEUD *)malloc(sizeof(NOEUD));
	nl->couleur = NOIR;
	NOEUD *f1 = creerNoeudRN(1,nl,nl,NOIR);
	NOEUD *f2 = creerNoeudRN(5,nl,nl,ROUGE);
	NOEUD *f3 = creerNoeudRN(8,nl,nl,ROUGE);
	NOEUD *f4 = creerNoeudRN(15,nl,nl,ROUGE);
	NOEUD *f23 = creerNoeudRN(7,f2,f3,NOIR);
	NOEUD *f123 = creerNoeudRN(2,f1,f23,ROUGE);
	NOEUD *f5 = creerNoeudRN(14,nl,f4,NOIR);
	NOEUD *x = creerNoeudRN(11,f123,f5,NOIR);
	f1->p = f23->p = f123; f2->p = f3->p = f23; f4->p = f5; f5->p = f123->p = x; x->p = nl;
	ARN *T = creerARN(x,nl);
	parcoursPrefixeRN(T->racine,T->nil);
	printf("\n");
	rn_supprimer(T,f4);
	printf("Apres suppression de %d: \n", f4->cle);
	parcoursPrefixeRN(T->racine,T->nil);
	printf("\n");
	rn_supprimer(T,f5);
	printf("Apres suppression de %d: \n", f5->cle);
	parcoursPrefixeRN(T->racine,T->nil);
	printf("\n");
	return 0;
}


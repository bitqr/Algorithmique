#include"ARN.h"

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
	NOEUD *z = (NOEUD *)malloc(sizeof(NOEUD));
	z->cle = 4;
	rn_inserer(T,z);
	printf("Apres insertion de %d: \n", z->cle);
	parcoursPrefixeRN(T->racine,T->nil);
	printf("\n");
	return 0;
}



		
		


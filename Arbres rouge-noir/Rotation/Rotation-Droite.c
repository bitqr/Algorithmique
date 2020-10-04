#include"ARN.h"

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




#include"ARN_INT.h"

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
	int m = x->gauche->max > x->droite->max?x->gauche->max:x->droite->max; 
	x->max = m > x->max?m:x->max;
	m = y->gauche->max > y->droite->max?y->gauche->max:y->droite->max; 
	y->max = m > y->max?m:y->max;
}

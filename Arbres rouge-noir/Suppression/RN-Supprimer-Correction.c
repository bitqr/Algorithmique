#include"ARN.h"

void rn_supprimer_correction(ARN *T, NOEUD *x){
	NOEUD *w;
	while(x != T->racine && x->couleur == NOIR){
		if(x == x->p->gauche){
			w = x->p->droite;
			if(w->couleur == ROUGE){
				w->couleur = NOIR; //Cas 1
				x->p->couleur = ROUGE; //Cas 1
				rotation_gauche(T,x->p); //Cas 1
				w = x->p->droite; //Cas 1
			}
			if(w->gauche->couleur == NOIR && w->droite->couleur == NOIR){
				w->couleur = ROUGE; //Cas 2
				x = x->p; //Cas 2
			}
			else{
				if(w->droite->couleur == NOIR){ 
					w->gauche->couleur = NOIR; //Cas 3
					w->couleur = ROUGE; //Cas 3
					rotation_droite(T,w); //Cas 3
					w = x->p->droite; //Cas 3
				}
				w->couleur = x->p->couleur; //Cas 4
				x->p->couleur = NOIR; //Cas 4
				w->droite->couleur = NOIR; //Cas 4
				rotation_gauche(T,x->p); //Cas 4
				x = T->racine; //Cas 4
			}
		}
		else{
			w = x->p->gauche;
			if(w->couleur == ROUGE){
				w->couleur = NOIR; //Cas 1
				x->p->couleur = ROUGE; //Cas 1
				rotation_droite(T,x->p); //Cas 1
				w = x->p->gauche; //Cas 1
			}
			if(w->gauche->couleur == NOIR && w->droite->couleur == NOIR){
				w->couleur = ROUGE; //Cas 2
				x = x->p; //Cas 2
			}
			else{
				if(w->gauche->couleur == NOIR){ 
					w->droite->couleur = NOIR; //Cas 3
					w->couleur = ROUGE; //Cas 3
					rotation_gauche(T,w); //Cas 3
					w = x->p->gauche; //Cas 3
				}
				w->couleur = x->p->couleur; //Cas 4
				x->p->couleur = NOIR; //Cas 4
				w->gauche->couleur = NOIR; //Cas 4
				rotation_droite(T,x->p); //Cas 4
				x = T->racine; //Cas 4
			}
		}
	}
	x->couleur = NOIR;
}


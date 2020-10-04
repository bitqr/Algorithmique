#include"ARN_INT.h"

NOEUD_VLSI *rn_minimum(ARN_VLSI *T, NOEUD_VLSI *x){
	if(x == T->nil || x->gauche == T->nil)
		return x;
	else
		return rn_minimum(T,x->gauche);
}

NOEUD_VLSI *rn_maximum(ARN_VLSI *T, NOEUD_VLSI *x){
	if(x == T->nil || x->droite == T->nil)
		return x;
	else
		return rn_maximum(T,x->droite);
}

NOEUD_VLSI *rn_successeur(ARN_VLSI *T, NOEUD_VLSI *x){
	if(x->droite != T->nil)
		return rn_minimum(T,x->droite);
	NOEUD_VLSI *y = x->p;
	while(y != T->nil && x == y->droite){
		x = y;
		y = y->p;
	}
	return y;
}


void afficherRect(ARN_VLSI *T, NOEUD_VLSI *n){
	if(n != T->nil)
		printf("%d %d %d %d\n\n",n->rect->minx,n->rect->miny,n->rect->maxx,n->rect->maxy);
}

int recoupement(ARN_VLSI *T, NOEUD_VLSI *n){
	NOEUD_VLSI *x = T->racine;
	while(x != T->nil){
		if(x != n && ( (x->intx->debut >= n->intx->debut 
		&& x->intx->debut <= n->intx->fin && x->inty->debut <= n->inty->fin 
		&& n->inty->debut <= x->inty->fin) || ( (n->intx->debut >= x->intx->debut 
		&& n->intx->debut <= x->intx->fin && x->inty->debut <= n->inty->fin 
		&& n->inty->debut <= x->inty->fin) ) ) )
				return 1;
		if(x->droite == T->nil || x->droite->rect->minx > n->intx->fin 
		|| x->cle > n->intx->fin || x->droite->rect->miny > n->inty->fin 
		|| x->droite->rect->maxy < n->inty->debut)
			x = x->gauche;
		else
			x = x->droite;
		}
	return 0;
}

void ppref(ARN_VLSI *T,NOEUD_VLSI *n){
	if(n != T->nil){
		printf("%d %d %d %d\n\n",n->rect->minx,n->rect->miny,n->rect->maxx,n->rect->maxy);
		ppref(T,n->gauche);
		ppref(T,n->droite);
		}
}

	
int recoupement_vlsi(ARN_VLSI *T){
	NOEUD_VLSI * m = rn_minimum(T,T->racine);
	while(m != T->nil){
		if(recoupement(T,m) == 1)
			return 1;
		m = rn_successeur(T,m);
		afficherRect(T,m);
		}
	return 0;
}


NOEUD_VLSI *creerNoeudVLSI(INTERVALLE *intx, INTERVALLE *inty, NOEUD_VLSI *g, NOEUD_VLSI *d, int couleur){
	NOEUD_VLSI *node = (NOEUD_VLSI *)malloc(sizeof(NOEUD_VLSI));
	node->cle = intx->debut;
	node->gauche = g;
	node->droite = d;
	node->couleur = couleur;
	node->intx = intx;
	node->inty = inty;
	RECTANGLE *r = (RECTANGLE *)malloc(sizeof(RECTANGLE));
	int m = g->rect->minx < d->rect->minx?g->rect->minx:d->rect->minx;
	r->minx = m < intx->debut?m:intx->debut;
	m = g->rect->miny < d->rect->miny?g->rect->miny:d->rect->miny;
	r->miny = m < inty->debut?m:inty->debut;
	m = g->rect->maxx > d->rect->maxx?g->rect->maxx:d->rect->maxx;
	r->maxx = m > intx->fin?m:intx->fin;
	m = g->rect->maxy > d->rect->maxy?g->rect->maxy:d->rect->maxy;
	r->maxy = m > inty->fin?m:inty->fin;
	node->rect = r;
	return node;
}

ARN_VLSI * creerARN_VLSI(NOEUD_VLSI *racine, NOEUD_VLSI *nil){
	ARN_VLSI * a = (ARN_VLSI *)malloc(sizeof(ARN_VLSI));
	a->racine = racine;
	a->nil = nil;
	return a;
}


int main(int argc, char **argv){
	NOEUD_VLSI *nl = (NOEUD_VLSI *)malloc(sizeof(NOEUD_VLSI));
	nl->rect = (RECTANGLE *)malloc(sizeof(RECTANGLE));
	nl->rect->minx = nl->rect->miny = INFINI;
	nl->rect->maxx = nl->rect->maxy = MINFINI;
	
	NOEUD_VLSI *f1 = creerNoeudVLSI(creeInt(3,6),creeInt(2,8),nl,nl,NOIR);
	NOEUD_VLSI *f2 = creerNoeudVLSI(creeInt(7,9),creeInt(7,10),nl,nl,ROUGE);
	NOEUD_VLSI *f = creerNoeudVLSI(creeInt(10,12),creeInt(5,7),nl,nl,ROUGE);
	NOEUD_VLSI *f3 = creerNoeudVLSI(creeInt(11,14),creeInt(1,3),f,nl,NOIR);
	NOEUD_VLSI *f4 = creerNoeudVLSI(creeInt(11,13),creeInt(10,12),nl,nl,ROUGE);
	NOEUD_VLSI *n2= creerNoeudVLSI(creeInt(7,8),creeInt(2,3),nl,f2,NOIR);
	NOEUD_VLSI *n4 = creerNoeudVLSI(creeInt(13,15),creeInt(8,9),f4,nl,NOIR);
	NOEUD_VLSI *n12 = creerNoeudVLSI(creeInt(4,6),creeInt(9,10),f1,n2,ROUGE);
	NOEUD_VLSI *n34 = creerNoeudVLSI(creeInt(11,13),creeInt(4,7),f3,n4,ROUGE);
	NOEUD_VLSI *rac = creerNoeudVLSI(creeInt(8,9),creeInt(4,5),n12,n34,NOIR);

	f1->p = n2 ->p = n12; f2->p = n2; f3->p = n4->p = n34; f4->p = n4; 
	n12->p = n34->p = rac; rac->p = nl;f->p = f3;
	
	ARN_VLSI *T = creerARN_VLSI(rac,nl);
	
	//ppref(T,T->racine);
	
	int r = recoupement_vlsi(T);
	
	if(r==1)
		printf("Il y a au moins un recoupement de circuits dans cette puce VLSI\n\n");
	else
		printf("Il n'y a aucun recoupement de circuits dans cette puce VLSI\n\n");
	
	return 0;
}




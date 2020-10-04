#include"ABRP.h"
#define K 5

NOEUD *creerNoeudABRP(int cle, NOEUD *g, NOEUD *d){
	NOEUD * node = (NOEUD *) malloc(sizeof(NOEUD));
	node->cle = cle;
	node->gauche = g;
	node->droite = d;
	return node;
}

ABRP * creerABRP(NOEUD *racine, NOEUD *nil){
	ABRP * a = (ABRP *)malloc(sizeof(ABRP));
	a->racine = racine;
	a->nil = nil;
	return a;
}


void parcoursPrefixeABRP(NOEUD *x,NOEUD *nl){
	if(x != nl){
		printf("%d\t",x->cle);
		parcoursPrefixeABRP(x->gauche,nl);
		parcoursPrefixeABRP(x->droite,nl);
		}
}

ABRP * arbre_persistant_inserer(ABRP *T, int k){
	NOEUD *x = T->racine;
	NOEUD *n = (NOEUD *)malloc(sizeof(NOEUD));
	if(x == T->nil){
		n->cle = k;
		n->gauche = n->droite = T->nil;
		return creerABRP(n,T->nil);
		}
	n->cle = x->cle;
	ABRP * Tprim = creerABRP(n,T->nil);
	while(x != T->nil){ 
		NOEUD *nf = (NOEUD *)malloc(sizeof(NOEUD));
		if(k < x->cle){
			n->droite = x->droite;
			if(x->gauche != T->nil)
				nf->cle = x->gauche->cle;
			else{
				nf->cle = k;
				nf->gauche = nf->droite = Tprim->nil;
				}
			n->gauche = nf;
			x = x->gauche;
			}
		else{
			n->gauche = x->gauche;
			if(x->droite != T->nil)
				nf->cle = x->droite->cle;
			else{
				nf->cle = k;
				nf->gauche = nf->droite = Tprim->nil;
				}
			n->droite = nf;
			x = x->droite;
			}
		n = nf;
		}
	return Tprim;
}



int main(int argc, char ** argv){
	NOEUD *nl = (NOEUD *)malloc(sizeof(NOEUD));
	NOEUD *f1 = creerNoeudABRP(2,nl,nl);
	NOEUD *f2 = creerNoeudABRP(7,nl,nl);
	NOEUD *f4 = creerNoeudABRP(10,nl,nl);
	NOEUD *f123 = creerNoeudABRP(3,f1,nl);
	NOEUD *f5 = creerNoeudABRP(8,f2,f4);
	NOEUD *x = creerNoeudABRP(4,f123,f5);
	ABRP *T = creerABRP(x,nl);
	parcoursPrefixeABRP(T->racine,T->nil);
	printf("\n");
	ABRP *Tprim = arbre_persistant_inserer(T,K);
	printf("Apres insertion de %d: \n", K);
	parcoursPrefixeABRP(Tprim->racine,Tprim->nil);
	printf("\n");
	return 0;
}



		

#include"ARN.h"


NOEUD * recuperer_rang(NOEUD *x, int i){
	int r = x->gauche->taille + 1;
	if(i==r)
		return x;
	else
		if(i < r)
			return recuperer_rang(x->gauche,i);
		else
			return recuperer_rang(x->droite,i-r);
}


NOEUD *creerNoeudRN(int cle, NOEUD *g, NOEUD *d, int couleur){
	NOEUD * node = (NOEUD *) malloc(sizeof(NOEUD));
	node->cle = cle;
	node->taille = 1+ g->taille + d->taille;
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


int main(int argc, char **argv){
	NOEUD *nl = (NOEUD *) malloc(sizeof(NOEUD));
	nl->taille = 0;
	NOEUD * x11111 = creerNoeudRN(3,nl,nl,ROUGE);
	NOEUD * x2122 = creerNoeudRN(39,nl,nl,ROUGE);	
	NOEUD * x2121 = creerNoeudRN(35,nl,nl,ROUGE);
	NOEUD * x1212 = creerNoeudRN(20,nl,nl,ROUGE);
	NOEUD * x1121 = creerNoeudRN(14,nl,nl,ROUGE);
	NOEUD * x1112 = creerNoeudRN(12,nl,nl,NOIR);
	NOEUD * x1111 = creerNoeudRN(7,x11111,nl,NOIR);
	NOEUD * x212 = creerNoeudRN(38,x2121,x2122,NOIR);
	NOEUD * x211 = creerNoeudRN(28,nl,nl,NOIR);
	NOEUD * x122 = creerNoeudRN(21,nl,nl,NOIR);
	NOEUD * x121 = creerNoeudRN(19,nl,x1212,NOIR);
	NOEUD * x112 = creerNoeudRN(16,x1121,nl,NOIR);
	NOEUD * x111 = creerNoeudRN(10,x1111,x1112,ROUGE);
	NOEUD * x22 = creerNoeudRN(47,nl,nl,NOIR);
	NOEUD * x21 = creerNoeudRN(30,x211,x212,ROUGE);
	NOEUD * x11 = creerNoeudRN(14,x111,x112,NOIR);
	NOEUD * x12 = creerNoeudRN(21,x121,x122,NOIR);
	NOEUD * x1 = creerNoeudRN(17,x11,x12,ROUGE);
	NOEUD * x2 = creerNoeudRN(41,x21,x22,NOIR);
	NOEUD * x = creerNoeudRN(26,x1,x2,NOIR);
	x11111->p = x1111; x1111->p = x1112->p = x111; x1121->p = x112;
	x1212->p = x121; x121->p = x122->p = x12; x2121->p = x2122->p = x212;
	x211->p = x212->p = x21; x21->p = x22->p = x2; x111->p = x112->p = x11;
	x11->p = x12->p = x1; x1->p = x2->p = x; x->p = nl;
	ARN *T = creerARN(x,nl);
	int i;
	for(i=1;i<= T->racine->taille;i++)
		printf("Le noeud de rang %d a pour cle %d\n\n",determiner_rang(T,recuperer_rang(T->racine,i)),recuperer_rang_iteratif(T->racine,i)->cle);
	printf("La cle %d est de rang %d\n\n",35,rechercher_rang_cle(T->racine,35));
	return 0;
}







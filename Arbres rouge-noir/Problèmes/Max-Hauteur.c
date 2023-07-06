#include "ARN.h"

#define H 2

NOEUD *max_hauteur(ARN *T, int h)
{
	NOEUD *x = T->racine;
	int y = T->hn;
	while (y > h)
	{
		x = x->droite;
		if (x->couleur == NOIR)
		{
			y--;
		}
	}
	if (y == 1)
	{
		if (x->droite != T->nil)
		{
			fprintf(stderr, "Erreur, y n'est pas noir!\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			return x;
		}
	}
	do
	{
		x = x->droite;
	} while (x->couleur != NOIR);
	return x;
}

NOEUD *creerNoeudRN(int cle, NOEUD *g, NOEUD *d, int couleur)
{
	NOEUD *node = (NOEUD *)malloc(sizeof(NOEUD));
	node->cle = cle;
	node->gauche = g;
	node->droite = d;
	node->couleur = couleur;
	return node;
}

ARN *creerARN(NOEUD *racine, NOEUD *nil)
{
	ARN *a = (ARN *)malloc(sizeof(ARN));
	a->racine = racine;
	a->nil = nil;
	return a;
}

int main(int argc, char **argv)
{
	NOEUD *nl = (NOEUD *)malloc(sizeof(NOEUD));
	nl->couleur = NOIR;
	NOEUD *f1 = creerNoeudRN(1, nl, nl, NOIR);
	NOEUD *f2 = creerNoeudRN(5, nl, nl, ROUGE);
	NOEUD *f3 = creerNoeudRN(8, nl, nl, ROUGE);
	NOEUD *f4 = creerNoeudRN(15, nl, nl, ROUGE);
	NOEUD *f23 = creerNoeudRN(7, f2, f3, NOIR);
	NOEUD *f123 = creerNoeudRN(2, f1, f23, ROUGE);
	NOEUD *f5 = creerNoeudRN(14, nl, f4, NOIR);
	NOEUD *x = creerNoeudRN(11, f123, f5, NOIR);
	f1->p = f23->p = f123;
	f2->p = f3->p = f23;
	f4->p = f5;
	f5->p = f123->p = x;
	x->p = nl;
	ARN *T = creerARN(x, nl);
	T->hn = 2;
	printf("Recherche de y: %d\n", max_hauteur(T, H)->cle);
	printf("\n");
	free(T);
	return 0;
}

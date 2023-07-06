#include "AVL.h"

void rotation_gauche(AVL *T, NOEUD *x)
{
	NOEUD *y = x->droite;  // initialise y.
	x->droite = y->gauche; // sous-arbre gauche de y devient sous-arbre droit de x.
	if (y->gauche != T->nil)
	{
		y->gauche->p = x;
	}
	y->p = x->p; // relie parent de x à y.
	if (x->p == T->nil)
	{
		T->racine = y;
	}
	else if (x == x->p->gauche)
	{
		x->p->gauche = y;
	}
	else
	{
		x->p->droite = y;
	}
	y->gauche = x; // place x à gauche de y.
	x->p = y;
}

NOEUD *creerNoeudAVL(int cle, int h, NOEUD *g, NOEUD *d)
{
	NOEUD *node = (NOEUD *)malloc(sizeof(NOEUD));
	node->cle = cle;
	node->gauche = g;
	node->droite = d;
	node->h = h;
	return node;
}

AVL *creerAVL(NOEUD *racine, NOEUD *nil)
{
	AVL *a = (AVL *)malloc(sizeof(AVL));
	a->racine = racine;
	a->nil = nil;
	return a;
}

void rotation_droite(AVL *T, NOEUD *x)
{
	NOEUD *y = x->gauche;  // initialise y.
	x->gauche = y->droite; // sous-arbre droit de y devient sous-arbre gauche de x.
	if (y->droite != T->nil)
	{
		y->droite->p = x;
	}
	y->p = x->p; // relie parent de x à y.
	if (x->p == T->nil)
	{
		T->racine = y;
	}
	else if (x == x->p->gauche)
	{
		x->p->gauche = y;
	}
	else
	{
		x->p->droite = y;
	}
	y->droite = x; // place x à droite de y.
	x->p = y;
}

void parcoursPrefixeAVL(NOEUD *x, NOEUD *nl)
{
	if (x != nl)
	{
		printf("%d(%d)\t", x->cle, x->h);
		parcoursPrefixeAVL(x->gauche, nl);
		parcoursPrefixeAVL(x->droite, nl);
	}
}

int max(int a, int b)
{
	return a > b ? a : b;
}

void equilibre(AVL *T, NOEUD *x)
{
	NOEUD *y;
	NOEUD *z;
	if (x->droite->h - x->gauche->h > 1)
	{
		y = x->droite;
		if (y->droite->h >= y->gauche->h)
		{
			z = x->droite;
			rotation_gauche(T, x);
			x->h = 1 + max(x->gauche->h, x->droite->h);
			z->h = 1 + max(z->gauche->h, z->droite->h);
		}
		else
		{
			z = y->gauche;
			rotation_droite(T, y);
			y->h = 1 + max(y->gauche->h, y->droite->h);
			z->h = 1 + max(z->gauche->h, z->droite->h);
			z = x->droite;
			rotation_gauche(T, x);
			x->h = 1 + max(x->gauche->h, x->droite->h);
			z->h = 1 + max(z->gauche->h, z->droite->h);
		}
	}
	if (x->droite->h - x->gauche->h < -1)
	{
		y = x->gauche;
		if (y->gauche->h >= y->droite->h)
		{
			z = x->gauche;
			rotation_droite(T, x);
			x->h = 1 + max(x->gauche->h, x->droite->h);
			z->h = 1 + max(z->gauche->h, z->droite->h);
		}
		else
		{
			z = y->droite;
			rotation_gauche(T, y);
			y->h = 1 + max(y->gauche->h, y->droite->h);
			z->h = 1 + max(z->gauche->h, z->droite->h);
			z = x->gauche;
			rotation_droite(T, x);
			x->h = 1 + max(x->gauche->h, x->droite->h);
			z->h = 1 + max(z->gauche->h, z->droite->h);
		}
	}
}

int main(int argc, char **argv)
{
	NOEUD *nl = creerNoeudAVL(0, 0, NULL, NULL);
	NOEUD *x121 = creerNoeudAVL(13, 0, nl, nl);
	NOEUD *x12 = creerNoeudAVL(15, 1, x121, nl);
	NOEUD *x11 = creerNoeudAVL(7, 0, nl, nl);
	NOEUD *x1 = creerNoeudAVL(10, 2, x11, x12);
	NOEUD *x2122 = creerNoeudAVL(28, 0, nl, nl);
	NOEUD *x211 = creerNoeudAVL(22, 0, nl, nl);
	NOEUD *x212 = creerNoeudAVL(27, 1, nl, x2122);
	NOEUD *x21 = creerNoeudAVL(25, 2, x211, x212);
	NOEUD *x2212 = creerNoeudAVL(34, 0, nl, nl);
	NOEUD *x221 = creerNoeudAVL(33, 1, nl, x2212);
	NOEUD *x22212 = creerNoeudAVL(44, 0, nl, nl);
	NOEUD *x2221 = creerNoeudAVL(40, 1, nl, x22212);
	NOEUD *x2222 = creerNoeudAVL(60, 0, nl, nl);
	NOEUD *x222 = creerNoeudAVL(48, 2, x2221, x2222);
	NOEUD *x22 = creerNoeudAVL(36, 3, x221, x222);
	NOEUD *x2 = creerNoeudAVL(29, 4, x21, x22);
	NOEUD *x = creerNoeudAVL(17, 5, x1, x2);
	x121->p = x12;
	x12->p = x11->p = x1;
	x1->p = x2->p = x;
	x22->p = x21->p = x2;
	x211->p = x212->p = x21;
	x222->p = x221->p = x22;
	x2122->p = x212;
	x2212->p = x221;
	x2221->p = x2222->p = x222;
	x22212->p = x2221;
	x->p = nl;
	AVL *T = creerAVL(x, nl);
	parcoursPrefixeAVL(T->racine, T->nil);
	printf("\n\n");
	equilibre(T, T->racine);
	parcoursPrefixeAVL(T->racine, T->nil);
	printf("\n\n");
	NOEUD *z = creerNoeudAVL(20, 0, T->nil, T->nil);
	avl_inserer(T, T->racine, z);
	parcoursPrefixeAVL(T->racine, T->nil);
	printf("\n\n");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "PROB.h"

NOEUD *minimum(ABR *A, NOEUD *x)
{
	while (x->gauche != A->nil)
	{
		x = x->gauche;
	}
	return x;
}

NOEUD *successeur(ABR *A, NOEUD *x)
{
	if (x->droit != A->nil)
		return minimum(A, x->droit);
	NOEUD *y = x->p;
	while (y != A->nil && x == y->droit)
	{
		x = y;
		y = y->p;
	}
	return y;
}

ABR *construire_arbre(NOEUD **T, int a, int b)
{
	if (a <= b)
	{
		int m = (a + b) / 2;
		ABR *E1 = construire_arbre(T, a, m - 1);
		ABR *E2 = construire_arbre(T, m + 1, b);
		E1->racine->p = T[m];
		E2->racine->p = T[m];
		T[m]->gauche = E1->racine;
		T[m]->droit = E2->racine;
		T[m]->taille = E1->racine->taille + E2->racine->taille + 1;
		ABR *E = (ABR *)malloc(sizeof(ABR));
		E->racine = T[m];
		E->nil = E1->nil;
		return E;
	}
	else
	{
		ABR *E = (ABR *)malloc(sizeof(ABR));
		E->racine = T[0]->gauche;
		E->nil = E->racine;
		return E;
	}
}

ABR *equilibrer(ABR *A)
{
	NOEUD *x = A->racine;
	int n = x->taille;
	if (n >= 1)
	{
		NOEUD **T = (NOEUD **)malloc(n * sizeof(NOEUD *));
		T[0] = minimum(A, A->racine);
		int i;
		for (i = 1; i < n; i++)
		{
			T[i] = successeur(A, T[i - 1]);
		}
		ABR *E = construire_arbre(T, 0, n - 1);
		return E;
	}
	else
		return A;
}

void afficherArbre(ABR *A, NOEUD *x)
{
	if (x != A->nil)
	{
		afficherArbre(A, x->gauche);
		printf("Noeud %d : taille %d\n", x->cle, x->taille);
		afficherArbre(A, x->droit);
	}
}

NOEUD *creerNoeud(int cle, NOEUD *g, NOEUD *d)
{
	NOEUD *x = (NOEUD *)malloc(sizeof(NOEUD));
	x->cle = cle;
	x->droit = d;
	x->gauche = g;
	return x;
}

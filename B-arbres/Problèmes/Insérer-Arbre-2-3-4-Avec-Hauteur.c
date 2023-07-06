#include "ARBRE_2_3_4.h"

void inserer_arbre_2_3_4_avec_hauteur(ARBRE_2_3_4 *T, int k)
{
	NOEUD_ARBRE_2_3_4 *r = T->racine;
	if (r->n == 3)
	{
		NOEUD_ARBRE_2_3_4 *s = allouerNoeud();
		T->racine = s;
		s->feuille = FAUX;
		s->n = 0;
		s->c = (NOEUD_ARBRE_2_3_4 **)malloc(sizeof(NOEUD_ARBRE_2_3_4 *));
		s->c[0] = r;
		s->hauteur = r->hauteur + 1;
		partager_enfant_arbre_2_3_4_avec_hauteur(s, 1, r);
		inserer_arbre_2_3_4_avec_hauteur_incomplet(s, k);
	}
	else
		inserer_arbre_2_3_4_avec_hauteur_incomplet(r, k);
}

void partager_enfant_arbre_2_3_4_avec_hauteur(NOEUD_ARBRE_2_3_4 *x, int i, NOEUD_ARBRE_2_3_4 *y)
{
	NOEUD_ARBRE_2_3_4 *z = allouerNoeud();
	z->feuille = y->feuille;
	z->hauteur = y->hauteur;
	z->n = 1;
	z->cle = (int *)malloc(sizeof(int));
	z->cle[0] = y->cle[2];
	if (!y->feuille)
	{
		z->c = (NOEUD_ARBRE_2_3_4 **)malloc(2 * sizeof(NOEUD_ARBRE_2_3_4 *));
		z->c[0] = y->c[2];
		z->c[1] = y->c[3];
	}
	y->n = 1;
	int j;
	NOEUD_ARBRE_2_3_4 **nouveauCx = (NOEUD_ARBRE_2_3_4 **)malloc((x->n + 2) * sizeof(NOEUD_ARBRE_2_3_4 *));
	for (j = x->n + 1; j >= i + 1; j--)
	{
		nouveauCx[j] = x->c[j - 1];
	}
	nouveauCx[i] = z;
	for (j = 0; j <= i - 1; j++)
		nouveauCx[j] = x->c[j];
	x->c = nouveauCx;
	int *nouveauClex = (int *)malloc((x->n + 1) * sizeof(int));
	for (j = x->n; j >= i; j--)
	{
		nouveauClex[j] = x->cle[j - 1];
	}
	nouveauClex[i - 1] = y->cle[1];
	for (j = 0; j <= i - 2; j++)
	{
		nouveauClex[j] = x->cle[j];
	}
	x->cle = nouveauClex;
	x->n = x->n + 1;
	ecrireDisque(y);
	ecrireDisque(z);
	ecrireDisque(x);
}

void inserer_arbre_2_3_4_avec_hauteur_incomplet(NOEUD_ARBRE_2_3_4 *x, int k)
{
	int i = x->n;
	if (x->feuille)
	{
		int *nouveauClex = (int *)malloc((x->n + 1) * sizeof(int));
		while (i >= 1 && k < x->cle[i - 1])
		{
			nouveauClex[i] = x->cle[i - 1];
			i = i - 1;
		}
		nouveauClex[i] = k;
		int j;
		for (j = 0; j <= i - 1; j++)
			nouveauClex[j] = x->cle[j];
		x->n = x->n + 1;
		x->cle = nouveauClex;
		ecrireDisque(x);
	}
	else
	{
		while (i >= 1 && k < x->cle[i - 1])
		{
			i = i - 1;
		}
		i = i + 1;
		lireDisque(x->c[i - 1]);
		if (x->c[i - 1]->n == 3)
		{
			partager_enfant_arbre_2_3_4_avec_hauteur(x, i, x->c[i - 1]);
			if (k > x->cle[i - 1])
				i = i + 1;
		}
		inserer_arbre_2_3_4_avec_hauteur_incomplet(x->c[i - 1], k);
	}
}

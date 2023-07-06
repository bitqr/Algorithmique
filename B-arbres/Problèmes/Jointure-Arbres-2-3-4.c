#include "ARBRE_2_3_4.h"

ARBRE_2_3_4 *jointure_arbres_2_3_4(ARBRE_2_3_4 *T1, int k, ARBRE_2_3_4 *T2)
{
	NOEUD_ARBRE_2_3_4 *r1 = T1->racine;
	NOEUD_ARBRE_2_3_4 *r2 = T2->racine;
	int h1 = r1->hauteur;
	int h2 = r2->hauteur;
	if (r1->n == 0)
	{
		inserer_arbre_2_3_4_avec_hauteur(T2, k);
		return T2;
	}
	if (r2->n == 0)
	{
		inserer_arbre_2_3_4_avec_hauteur(T1, k);
		return T1;
	}
	if (h1 == h2)
	{
		NOEUD_ARBRE_2_3_4 *x = allouerNoeud();
		x->n = 1;
		x->cle = (int *)malloc(sizeof(int));
		x->cle[0] = k;
		x->hauteur = r1->hauteur + 1;
		x->feuille = FAUX;
		x->c = (NOEUD_ARBRE_2_3_4 **)malloc(2 * sizeof(NOEUD_ARBRE_2_3_4 *));
		x->c[0] = r1;
		x->c[1] = r2;
		ARBRE_2_3_4 *T = (ARBRE_2_3_4 *)malloc(sizeof(ARBRE_2_3_4));
		T->racine = x;
		ecrireDisque(x);
		return T;
	}
	if (h1 > h2)
	{
		inserer_hauteur(k, T1, h2 + 1, T2);
		return T1;
	}
	else
	{
		inserer_hauteur(k, T2, h1 + 1, T1);
		return T2;
	}
}

void inserer_hauteur(int k, ARBRE_2_3_4 *T1, int h, ARBRE_2_3_4 *T2)
{
	NOEUD_ARBRE_2_3_4 *r1 = T1->racine;
	if (r1->n == 3)
	{
		NOEUD_ARBRE_2_3_4 *s = allouerNoeud();
		T1->racine = s;
		s->feuille = FAUX;
		s->n = 0;
		s->c = (NOEUD_ARBRE_2_3_4 **)malloc(sizeof(NOEUD_ARBRE_2_3_4 *));
		s->c[0] = r1;
		s->hauteur = r1->hauteur + 1;
		partager_enfant_arbre_2_3_4_avec_hauteur(s, 1, r1);
		inserer_hauteur_incomplet(k, s, h, T2->racine);
	}
	else
		inserer_hauteur_incomplet(k, r1, h, T2->racine);
}

void inserer_hauteur_incomplet(int k, NOEUD_ARBRE_2_3_4 *x1, int h, NOEUD_ARBRE_2_3_4 *x2)
{
	int i;
	if (k <= x1->cle[0])
		i = 1;
	else
		i = x1->n + 1;
	if (x1->hauteur == h)
	{
		int j;
		if (i == 1)
		{
			int *nCle = (int *)malloc((x1->n + 1) * sizeof(int));
			for (j = x1->n; j >= 1; j--)
			{
				nCle[j] = x1->cle[j - 1];
			}
			nCle[0] = k;
			x1->n = x1->n + 1;
			x1->cle = nCle;
			if (!x1->feuille)
			{
				NOEUD_ARBRE_2_3_4 **nC = (NOEUD_ARBRE_2_3_4 **)malloc((x1->n + 1) * sizeof(NOEUD_ARBRE_2_3_4 *));
				for (j = x1->n; j >= 1; j--)
				{
					nC[j] = x1->c[j - 1];
				}
				nC[0] = x2;
				x1->c = nC;
			}
		}
		else
		{
			int *nCle = (int *)malloc((x1->n + 1) * sizeof(int));
			for (j = 1; j <= x1->n; j++)
			{
				nCle[j - 1] = x1->cle[j - 1];
			}
			nCle[x1->n] = k;
			x1->n = x1->n + 1;
			x1->cle = nCle;
			if (!x1->feuille)
			{
				NOEUD_ARBRE_2_3_4 **nC = (NOEUD_ARBRE_2_3_4 **)malloc((x1->n + 1) * sizeof(NOEUD_ARBRE_2_3_4 *));
				for (j = 1; j <= x1->n; j++)
				{
					nC[j - 1] = x1->c[j - 1];
				}
				nC[x1->n] = x2;
				x1->c = nC;
			}
		}
		ecrireDisque(x1);
	}
	else
	{
		lireDisque(x1->c[i - 1]);
		if (x1->c[i - 1]->n == 3)
		{
			partager_enfant_arbre_2_3_4_avec_hauteur(x1, i, x1->c[i - 1]);
			if (k > x1->cle[i - 1])
				i = i + 1;
		}
		inserer_hauteur_incomplet(k, x1->c[i - 1], h, x2);
	}
}

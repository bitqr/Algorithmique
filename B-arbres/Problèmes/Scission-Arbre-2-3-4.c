#include "ARBRE_2_3_4.h"

COUPLE_ARBRES_APRES_SCISSION scission_arbre_2_3_4(ARBRE_2_3_4 *T, int k)
{
	ARBRE_2_3_4 *A = creer_arbre_2_3_4();
	ARBRE_2_3_4 *B = creer_arbre_2_3_4();

	PILE *K1 = creerPile(T->racine->hauteur + 1);
	PILE *K2 = creerPile(T->racine->hauteur + 1);
	PILE_ARBRE_2_3_4 *T1 = creerPileArbre234(T->racine->hauteur + 1);
	PILE_ARBRE_2_3_4 *T2 = creerPileArbre234(T->racine->hauteur + 1);
	partager_avec_chemin(T->racine, k, K1, T1, K2, T2);
	if (!pileVideArbre234(T1))
	{
		free(A);
		A = depilerArbre234(T1);
	}
	if (!pileVideArbre234(T2))
	{
		free(B);
		B = depilerArbre234(T2);
	}
	while (!pileVide(K1))
	{
		int k1 = depiler(K1);
		ARBRE_2_3_4 *A1 = depilerArbre234(T1);
		A = jointure_arbres_2_3_4(A, k1, A1);
	}
	while (!pileVide(K2))
	{
		int k2 = depiler(K2);
		ARBRE_2_3_4 *A2 = depilerArbre234(T2);
		B = jointure_arbres_2_3_4(B, k2, A2);
	}
	free(T1);
	free(T2);
	free(K1);
	free(K2);
	COUPLE_ARBRES_APRES_SCISSION c;
	c.arbre1 = A;
	c.arbre2 = B;
	free(A);
	free(B);
	return c;
}

ARBRE_2_3_4 *creer_arbre_2_3_4()
{
	ARBRE_2_3_4 *T = (ARBRE_2_3_4 *)malloc(sizeof(ARBRE_2_3_4));
	NOEUD_ARBRE_2_3_4 *x = allouerNoeud();
	x->feuille = VRAI;
	x->n = 0;
	x->hauteur = 0;
	ecrireDisque(x);
	T->racine = x;
	return T;
}

PILE *creerPile(int taille)
{
	PILE *P = (PILE *)malloc(sizeof(PILE));
	int *t = (int *)malloc(taille * sizeof(int));
	P->sommet = -1;
	P->taille = taille;
	P->tableau = t;
	return P;
}

PILE_ARBRE_2_3_4 *creerPileArbre234(int taille)
{
	PILE_ARBRE_2_3_4 *P = (PILE_ARBRE_2_3_4 *)malloc(sizeof(PILE_ARBRE_2_3_4));
	ARBRE_2_3_4 **t = (ARBRE_2_3_4 **)malloc(taille * sizeof(ARBRE_2_3_4 *));
	P->sommet = -1;
	P->taille = taille;
	P->tableau = t;
	return P;
}

void partager_avec_chemin(NOEUD_ARBRE_2_3_4 *x, int k, PILE *K1, PILE_ARBRE_2_3_4 *T1, PILE *K2, PILE_ARBRE_2_3_4 *T2)
{
	int i = 1;
	while (i <= x->n && x->cle[i - 1] < k)
	{
		i = i + 1;
	}
	if (i <= x->n && x->cle[i - 1] == k)
	{
		ARBRE_2_3_4 *A = creer_arbre_2_3_4();
		ARBRE_2_3_4 *B = creer_arbre_2_3_4();
		if (i > 1)
		{
			NOEUD_ARBRE_2_3_4 *z = allouerNoeud();
			z->cle = (int *)malloc((i - 1) * sizeof(int));
			int j;
			for (j = 1; j <= i - 1; j++)
			{
				z->cle[j - 1] = x->cle[j - 1];
			}
			if (!x->feuille)
			{
				z->c = (NOEUD_ARBRE_2_3_4 **)malloc(i * sizeof(NOEUD_ARBRE_2_3_4 *));
				for (j = 1; j <= i; j++)
				{
					z->c[j - 1] = x->c[j - 1];
				}
			}
			z->feuille = x->feuille;
			z->hauteur = x->hauteur;
			z->n = i - 1;
			A->racine = z;
			ecrireDisque(z);
		}
		else
		{
			if (!x->feuille)
			{
				A->racine = x->c[0];
			}
		}
		empilerArbre234(T1, A);
		if (i < x->n)
		{
			NOEUD_ARBRE_2_3_4 *y = allouerNoeud();
			y->cle = (int *)malloc((x->n - i) * sizeof(int));
			int j;
			for (j = 1; j <= x->n - i; j++)
			{
				y->cle[j - 1] = x->cle[j + i - 1];
			}
			if (!x->feuille)
			{
				y->c = (NOEUD_ARBRE_2_3_4 **)malloc((x->n - i + 1) * sizeof(NOEUD_ARBRE_2_3_4 *));
				for (j = 1; j <= x->n - i + 1; j++)
				{
					y->c[j - 1] = x->c[j + i - 1];
				}
			}
			y->feuille = x->feuille;
			y->hauteur = x->hauteur;
			y->n = x->n - i;
			B->racine = y;
			ecrireDisque(y);
		}
		else
		{
			if (!x->feuille)
			{
				B->racine = x->c[x->n];
			}
		}
		empilerArbre234(T2, B);
	}
	else
	{
		if (x->feuille)
		{
			fprintf(stderr, "clé introuvable pour la scission\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			lireDisque(x, i - 1);
			if (i > 1)
			{
				empiler(K1, x->cle[i - 2]);
				ARBRE_2_3_4 *A = creer_arbre_2_3_4();
				if (i > 2)
				{
					NOEUD_ARBRE_2_3_4 *z = allouerNoeud();
					z->cle = (int *)malloc((i - 2) * sizeof(int));
					int j;
					for (j = 1; j <= i - 2; j++)
					{
						z->cle[j - 1] = x->cle[j - 1];
					}
					if (!x->feuille)
					{
						z->c = (NOEUD_ARBRE_2_3_4 **)malloc((i - 1) * sizeof(NOEUD_ARBRE_2_3_4 *));
						for (j = 1; j <= i - 1; j++)
						{
							z->c[j - 1] = x->c[j - 1];
						}
					}
					z->feuille = x->feuille;
					z->hauteur = x->hauteur;
					z->n = i - 2;
					A->racine = z;
					ecrireDisque(z);
				}
				else
				{
					if (!x->feuille)
					{
						A->racine = x->c[0];
					}
				}
				empilerArbre234(T1, A);
			}
			if (i <= x->n)
			{
				empiler(K2, x->cle[i - 1]);
				ARBRE_2_3_4 *B = creer_arbre_2_3_4();
				if (i < x->n)
				{
					NOEUD_ARBRE_2_3_4 *y = allouerNoeud();
					y->cle = (int *)malloc((x->n - i) * sizeof(int));
					int j;
					for (j = 1; j <= x->n - i; j++)
					{
						y->cle[j - 1] = x->cle[j + i - 1];
					}
					if (!x->feuille)
					{
						y->c = (NOEUD_ARBRE_2_3_4 **)malloc((x->n - i + 1) * sizeof(NOEUD_ARBRE_2_3_4 *));
						for (j = 1; j <= x->n - i + 1; j++)
						{
							y->c[j - 1] = x->c[j + i - 1];
						}
					}
					y->feuille = x->feuille;
					y->hauteur = x->hauteur;
					y->n = x->n - i;
					B->racine = y;
					ecrireDisque(y);
				}
				else
				{
					if (!x->feuille)
					{
						B->racine = x->c[x->n];
					}
				}
				empilerArbre234(T2, B);
			}
			partager_avec_chemin(x->c[i - 1], k, K1, T1, K2, T2);
		}
	}
}

void empilerArbre234(PILE_ARBRE_2_3_4 *P, ARBRE_2_3_4 *T)
{
	P->sommet++;
	P->tableau[P->sommet] = T;
}

void empiler(PILE *P, int k)
{
	P->sommet++;
	P->tableau[P->sommet] = k;
}

int pileVideArbre234(PILE_ARBRE_2_3_4 *P)
{
	return (P->sommet == -1);
}

int pileVide(PILE *P)
{
	return (P->sommet == -1);
}

ARBRE_2_3_4 *depilerArbre234(PILE_ARBRE_2_3_4 *P)
{
	if (pileVideArbre234(P))
	{
		fprintf(stderr, "Erreur, débordement négatif!\n");
		exit(EXIT_FAILURE);
	}
	P->sommet--;
	return P->tableau[P->sommet + 1];
}

int depiler(PILE *P)
{
	if (pileVide(P))
	{
		fprintf(stderr, "Erreur, débordement négatif!\n");
		exit(EXIT_FAILURE);
	}
	P->sommet--;
	return P->tableau[P->sommet + 1];
}

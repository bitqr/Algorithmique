#include "TAS_2_3_4.h"

TAS_BINOMIAL *creer_tas_binomial()
{
	TAS_BINOMIAL *T = (TAS_BINOMIAL *)malloc(sizeof(TAS_BINOMIAL));
	T->tete = NIL;
	return T;
}

TAS_BINOMIAL_ARETES *creerTasBinomialAretes()
{
	TAS_BINOMIAL_ARETES *T = (TAS_BINOMIAL_ARETES *)malloc(sizeof(TAS_BINOMIAL_ARETES));
	T->tete = NIL;
	return T;
}

NOEUD_TAS_BINOMIAL *fusionner_tas_binomiaux(TAS_BINOMIAL *T1, TAS_BINOMIAL *T2)
{
	NOEUD_TAS_BINOMIAL *x1 = T1->tete;
	NOEUD_TAS_BINOMIAL *x2 = T2->tete;
	if (x1 == NIL)
	{
		return x2;
	}
	if (x2 == NIL)
	{
		return x1;
	}
	NOEUD_TAS_BINOMIAL *h;
	if (x1->degre <= x2->degre)
	{
		h = x1;
		x1 = x1->frere;
	}
	else
	{
		h = x2;
		x2 = x2->frere;
	}
	NOEUD_TAS_BINOMIAL *courant = h;
	while (x1 != NIL && x2 != NIL)
	{
		if (x1->degre <= x2->degre)
		{
			courant->frere = x1;
			x1 = x1->frere;
		}
		else
		{
			courant->frere = x2;
			x2 = x2->frere;
		}
		courant = courant->frere;
	}
	if (x1 == NIL)
	{
		courant->frere = x2;
	}
	else
	{
		courant->frere = x1;
	}
	return h;
}

NOEUD_TAS_BINOMIAL_ARETE *fusionnerTasBinomiauxAretes(TAS_BINOMIAL_ARETES *T1, TAS_BINOMIAL_ARETES *T2)
{
	NOEUD_TAS_BINOMIAL_ARETE *x1 = T1->tete;
	NOEUD_TAS_BINOMIAL_ARETE *x2 = T2->tete;
	if (x1 == NIL)
	{
		return x2;
	}
	if (x2 == NIL)
	{
		return x1;
	}
	NOEUD_TAS_BINOMIAL_ARETE *h;
	if (x1->degre <= x2->degre)
	{
		h = x1;
		x1 = x1->frere;
	}
	else
	{
		h = x2;
		x2 = x2->frere;
	}
	NOEUD_TAS_BINOMIAL_ARETE *courant = h;
	while (x1 != NIL && x2 != NIL)
	{
		if (x1->degre <= x2->degre)
		{
			courant->frere = x1;
			x1 = x1->frere;
		}
		else
		{
			courant->frere = x2;
			x2 = x2->frere;
		}
		courant = courant->frere;
	}
	if (x1 == NIL)
	{
		courant->frere = x2;
	}
	else
	{
		courant->frere = x1;
	}
	return h;
}

void lien_binomial(NOEUD_TAS_BINOMIAL *y, NOEUD_TAS_BINOMIAL *z)
{
	y->p = z;
	y->frere = z->enfant;
	z->enfant = y;
	z->degre = z->degre + 1;
}

void lienBinomial(NOEUD_TAS_BINOMIAL_ARETE *y, NOEUD_TAS_BINOMIAL_ARETE *z)
{
	y->p = z;
	y->frere = z->enfant;
	z->enfant = y;
	z->degre = z->degre + 1;
}

TAS_BINOMIAL *union_tas_binomiaux(TAS_BINOMIAL *T1, TAS_BINOMIAL *T2)
{
	TAS_BINOMIAL *T = creer_tas_binomial();
	T->tete = fusionner_tas_binomiaux(T1, T2);
	if (T->tete == NIL)
	{
		return T;
	}
	NOEUD_TAS_BINOMIAL *avant_x = NIL;
	NOEUD_TAS_BINOMIAL *x = T->tete;
	NOEUD_TAS_BINOMIAL *apres_x = x->frere;
	while (apres_x != NIL)
	{
		if ((x->degre != apres_x->degre) || (apres_x->frere != NIL && apres_x->frere->degre == x->degre))
		{
			avant_x = x; // Cas 1 et 2
			x = apres_x; // Cas 1 et 2
		}
		else if (x->cle <= apres_x->cle)
		{
			x->frere = apres_x->frere; // Cas 3
			lien_binomial(apres_x, x); // Cas 3
		}
		else
		{
			if (avant_x == NIL) // Cas 4
			{
				T->tete = apres_x;
			} // Cas 4
			else
			{
				avant_x->frere = apres_x;
			}						   // Cas 4
			lien_binomial(x, apres_x); // Cas 4
			x = apres_x;			   // Cas 4
		}
		apres_x = x->frere;
	}
	return T;
}

TAS_BINOMIAL_ARETES *unionTasBinomiauxAretes(TAS_BINOMIAL_ARETES *T1, TAS_BINOMIAL_ARETES *T2)
{
	TAS_BINOMIAL_ARETES *T = creerTasBinomialAretes();
	T->tete = fusionnerTasBinomiauxAretes(T1, T2);
	if (T->tete == NIL)
	{
		return T;
	}
	NOEUD_TAS_BINOMIAL_ARETE *avant_x = NIL;
	NOEUD_TAS_BINOMIAL_ARETE *x = T->tete;
	NOEUD_TAS_BINOMIAL_ARETE *apres_x = x->frere;
	while (apres_x != NIL)
	{
		if ((x->degre != apres_x->degre) || (apres_x->frere != NIL && apres_x->frere->degre == x->degre))
		{
			avant_x = x; // Cas 1 et 2
			x = apres_x; // Cas 1 et 2
		}
		else if (x->cle <= apres_x->cle)
		{
			x->frere = apres_x->frere; // Cas 3
			lienBinomial(apres_x, x);  // Cas 3
		}
		else
		{
			if (avant_x == NIL) // Cas 4
			{
				T->tete = apres_x;
			} // Cas 4
			else
			{
				avant_x->frere = apres_x;
			}						  // Cas 4
			lienBinomial(x, apres_x); // Cas 4
			x = apres_x;			  // Cas 4
		}
		apres_x = x->frere;
	}
	return T;
}

void tas_binomial_inserer(TAS_BINOMIAL **T, NOEUD_TAS_BINOMIAL *x)
{
	TAS_BINOMIAL *T1 = creer_tas_binomial();
	x->p = NIL;
	x->enfant = NIL;
	x->frere = NIL;
	x->degre = 0;
	T1->tete = x;
	*T = union_tas_binomiaux(*T, T1);
	free(T1);
}

void insererTasBinomialAretes(TAS_BINOMIAL_ARETES **T, NOEUD_TAS_BINOMIAL_ARETE *x)
{
	TAS_BINOMIAL_ARETES *T1 = creerTasBinomialAretes();
	x->p = NIL;
	x->enfant = NIL;
	x->frere = NIL;
	x->degre = 0;
	T1->tete = x;
	*T = unionTasBinomiauxAretes(*T, T1);
	free(T1);
}

NOEUD_TAS_BINOMIAL_ARETE *tasBinomialAretesExtraireMin(TAS_BINOMIAL_ARETES **T)
{
	NOEUD_TAS_BINOMIAL_ARETE *x = NIL;
	if ((*T)->tete != NIL)
	{
		NOEUD_TAS_BINOMIAL_ARETE *y = (*T)->tete;
		x = y;
		double min = y->cle;
		y = y->frere;
		while (y != NIL)
		{
			if (y->cle < min)
			{
				min = y->cle;
				x = y;
			}
			y = y->frere;
		}
		if (x == (*T)->tete)
		{
			(*T)->tete = x->frere;
		}
		else
		{
			y = (*T)->tete;
			while (y->frere != x)
			{
				y = y->frere;
			}
			y->frere = x->frere;
		}
	}
	TAS_BINOMIAL_ARETES *T1 = creerTasBinomialAretes();
	if (x != NIL)
	{
		NOEUD_TAS_BINOMIAL_ARETE *e = x->enfant;
		if (x->degre != 0)
		{
			NOEUD_TAS_BINOMIAL_ARETE *apres_e = e->frere;
			e->frere = NIL;
			e->p = NIL;
			while (apres_e != NIL)
			{
				NOEUD_TAS_BINOMIAL_ARETE *temp = apres_e->frere;
				apres_e->frere = e;
				apres_e->p = NIL;
				e = apres_e;
				apres_e = temp;
			}
		}
		T1->tete = e;
	}
	*T = unionTasBinomiauxAretes(*T, T1);
	free(T1);
	return x;
}

ARETE *ACM(GRAPHE *G)
{
	ARETE *E = (ARETE *)malloc((G->n - 1) * sizeof(ARETE));
	int *P = (int *)malloc(G->n * sizeof(int));
	int i, j;
	TAS_BINOMIAL **S = (TAS_BINOMIAL **)malloc(G->n * sizeof(TAS_BINOMIAL *));
	NOEUD_TAS_BINOMIAL **x = (NOEUD_TAS_BINOMIAL **)malloc(G->n * sizeof(NOEUD_TAS_BINOMIAL *));
	TAS_BINOMIAL_ARETES **A = (TAS_BINOMIAL_ARETES **)malloc(G->n * sizeof(TAS_BINOMIAL_ARETES *));
	for (i = 0; i < G->n; i++)
	{
		S[i] = creer_tas_binomial();
		x[i] = (NOEUD_TAS_BINOMIAL *)malloc(sizeof(NOEUD_TAS_BINOMIAL));
		x[i]->cle = i;
		x[i]->degre = 0;
		x[i]->frere = NIL;
		x[i]->p = NIL;
		x[i]->enfant = NIL;
		tas_binomial_inserer(&S[i], x[i]);
		A[i] = creerTasBinomialAretes();
		for (j = 0; j < G->degres[i]; j++)
		{
			NOEUD_TAS_BINOMIAL_ARETE *y = (NOEUD_TAS_BINOMIAL_ARETE *)malloc(sizeof(NOEUD_TAS_BINOMIAL_ARETE));
			y->arete = G->aretes[G->incidentes[i][j]];
			y->cle = y->arete.w;
			y->degre = 0;
			y->frere = NIL;
			y->p = NIL;
			y->enfant = NIL;
			insererTasBinomialAretes(&A[i], y);
		}
		P[i] = i;
	}
	int compteur = G->n;
	free(x);
	free(S);
	i = 0;
	while (compteur > 1)
	{
		ARETE a = tasBinomialAretesExtraireMin(&A[i])->arete;
		if (P[a.u] != P[a.v])
		{
			if (P[a.u] == i)
			{
				j = a.v;
			}
			else
			{
				j = a.u;
			}
			P[j] = i;
			E[G->n - compteur] = a;
			A[i] = unionTasBinomiauxAretes(A[i], A[j]);
			compteur--;
		}
	}
	free(P);
	free(A);
	return E;
}

void afficherGraphe(GRAPHE *G)
{
	int i, j;
	for (i = 0; i < G->n; i++)
	{
		printf("\nSommet (%d), de degré %d :\n", i, G->degres[i]);
		for (j = 0; j < G->degres[i]; j++)
		{
			ARETE a = G->aretes[G->incidentes[i][j]];
			if (a.v == i)
			{
				printf("\t ---- (%d), w = %f\n", a.u, a.w);
			}
			else
			{
				printf("\t ---- (%d), w = %f\n", a.v, a.w);
			}
		}
	}
}

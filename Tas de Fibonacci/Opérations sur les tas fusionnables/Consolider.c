#include "TASFIB.h"

void consolider(TAS_FIBONACCI *T)
{
	int i;
	int D = log(T->n) / log(2);
	NOEUD_TAS_FIBONACCI **A = (NOEUD_TAS_FIBONACCI **)malloc((D + 1) * sizeof(NOEUD_TAS_FIBONACCI *));
	for (i = 0; i <= D; i++)
	{
		A[i] = NIL;
	}
	NOEUD_TAS_FIBONACCI *a = T->min;
	int racines = 0;
	if (a != NIL)
	{
		a = a->droite;
		racines = 1;
		while (a != T->min)
		{
			racines++;
			a = a->droite;
		}
	}
	int j = 0;
	NOEUD_TAS_FIBONACCI *w = T->min;
	while (j < racines)
	{
		j++;
		NOEUD_TAS_FIBONACCI *x = w;
		int d = x->degre;
		w = w->droite;
		while (A[d] != NIL)
		{
			NOEUD_TAS_FIBONACCI *y = A[d];
			if (x->cle > y->cle)
			{
				permuter(&x, &y);
			}
			relier_tas_fib(T, y, x);
			A[d] = NIL;
			d = d + 1;
		}
		A[d] = x;
	}
	T->min = NIL;
	for (i = 0; i <= D; i++)
	{
		if (A[i] != NIL)
		{
			ajouterNoeudListeRacines(A[i], T->min);
			if (T->min == NIL || A[i]->cle < T->min->cle)
			{
				T->min = A[i];
			}
		}
	}
	free(A);
}

void permuter(NOEUD_TAS_FIBONACCI **x, NOEUD_TAS_FIBONACCI **y)
{
	NOEUD_TAS_FIBONACCI *t = *x;
	*x = *y;
	*y = t;
}

void ajouterNoeudListeRacines(NOEUD_TAS_FIBONACCI *x, NOEUD_TAS_FIBONACCI *r)
{
	if (r == NIL)
	{
		x->gauche = x;
		x->droite = x;
	}
	else
	{
		r->gauche->droite = x;
		x->gauche = r->gauche;
		x->droite = r;
		r->gauche = x;
	}
}

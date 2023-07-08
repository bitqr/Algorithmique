#include "TASFIB.h"

void supprimer_tas_fib(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x)
{
	diminuer_cle_tas_fib(T, x, -INFINI);
	extraire_min_tas_fib(T);
}

NOEUD_TAS_FIBONACCI *extraire_min_tas_fib(TAS_FIBONACCI *T)
{
	NOEUD_TAS_FIBONACCI *z = T->min;
	if (z != NIL)
	{
		NOEUD_TAS_FIBONACCI *x = z->enfant;
		NOEUD_TAS_FIBONACCI *y = x;
		if (x != NIL)
		{
			x->p = NIL;
			x = x->droite;
			while (x != y)
			{
				x->p = NIL;
				x = x->droite;
			}
			concatenerListes(x, z);
		}
		supprimerRacine(z);
		if (z == z->droite)
			T->min = NIL;
		else
		{
			T->min = z->droite;
			consolider(T);
		}
		T->n = T->n - 1;
	}
	return z;
}

void concatenerListes(NOEUD_TAS_FIBONACCI *x, NOEUD_TAS_FIBONACCI *r)
{
	if (r == NIL)
	{
		r = x;
		printf("Nouvelle racine: %d\n", r->cle);
	}
	else
	{
		NOEUD_TAS_FIBONACCI *y = r->gauche;
		NOEUD_TAS_FIBONACCI *z = x->gauche;
		z->droite = r;
		r->gauche = z;
		y->droite = x;
		x->gauche = y;
	}
}

void supprimerRacine(NOEUD_TAS_FIBONACCI *x)
{
	x->gauche->droite = x->droite;
	x->droite->gauche = x->gauche;
}

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

void relier_tas_fib(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *y, NOEUD_TAS_FIBONACCI *x)
{
	supprimerRacine(y);
	y->p = x;
	if (x->enfant == NIL)
	{
		y->gauche = y;
		y->droite = y;
	}
	else
	{
		NOEUD_TAS_FIBONACCI *z = x->enfant->gauche;
		y->droite = x->enfant;
		x->enfant->gauche = y;
		z->droite = y;
		y->gauche = z;
	}
	x->enfant = y;
	x->degre = x->degre + 1;
	y->marque = FAUX;
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

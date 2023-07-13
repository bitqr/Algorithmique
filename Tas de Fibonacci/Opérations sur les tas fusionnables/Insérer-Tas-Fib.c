#include "TASFIB.h"

void inserer_tas_fib(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x)
{
	x->degre = 0;
	x->p = NIL;
	x->enfant = NIL;
	x->gauche = x;
	x->droite = x;
	x->marque = FAUX;
	concatenerListes(x, T->min);
	if (T->min == NIL || x->cle < T->min->cle)
		T->min = x;
	T->n++;
}

void concatenerListes(NOEUD_TAS_FIBONACCI *x, NOEUD_TAS_FIBONACCI *r)
{
	if (r == NIL)
	{
		r = x;
		printf("Concaténation avec liste vide de %d\n", r->cle);
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

int afficherArbreTasFibonacci(NOEUD_TAS_FIBONACCI *x, int profondeur)
{
	int c = 0;
	if (x != NIL)
	{
		int i;
		for (i = 1; i <= profondeur; i++)
		{
			printf("\t");
		}
		printf("Noeud (%d)", x->cle);
		if (x->marque != FAUX)
		{
			printf(" marqué ");
		}
		else
		{
			printf(" non marqué ");
		}
		NOEUD_TAS_FIBONACCI *x1 = x->enfant;
		if (x1 != NIL)
		{
			printf("d'enfant(s) ");
		}
		else
		{
			printf("sans enfants.");
		}
		int d = 0;
		c++;
		while (d < x->degre)
		{
			if (x1 != NIL)
			{
				printf("%d ", x1->cle);
				x1 = x1->droite;
				d++;
			}
		}
		printf("\n");
		x1 = x->enfant;
		d = 0;
		while (d < x->degre)
		{
			c += afficherArbreTasFibonacci(x1, profondeur + 1);
			x1 = x1->droite;
			d++;
		}
	}
	return c;
}

void afficherTasFibonacci(TAS_FIBONACCI *T)
{
	if (T->n == 0)
	{
		printf("Tas vide.\n");
	}
	else
	{
		printf("Le tas a %d noeud(s)\n", T->n);
		NOEUD_TAS_FIBONACCI *x = T->min;
		int c = 0;
		while (c < T->n)
		{
			printf("Arbre dont la racine est de degré %d :\n", x->degre);
			c += afficherArbreTasFibonacci(x, 1);
			x = x->droite;
			printf("\n");
		}
	}
}

NOEUD_TAS_FIBONACCI *creerNoeudTasFibonacci(int cle, NOEUD_TAS_FIBONACCI *enfant, NOEUD_TAS_FIBONACCI *pere, NOEUD_TAS_FIBONACCI *g, NOEUD_TAS_FIBONACCI *d, int m, int dg)
{
	NOEUD_TAS_FIBONACCI *x = (NOEUD_TAS_FIBONACCI *)malloc(sizeof(NOEUD_TAS_FIBONACCI));
	x->cle = cle;
	x->gauche = g;
	x->droite = d;
	x->p = pere;
	x->marque = m;
	x->degre = dg;
	return x;
}

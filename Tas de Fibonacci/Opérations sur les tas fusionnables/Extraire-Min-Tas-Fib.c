#include "TASFIB.h"

NOEUD_TAS_FIBONACCI *extraire_min_tas_fib(TAS_FIBONACCI *T)
{
	NOEUD_TAS_FIBONACCI *z = T->min;
	if (z != NIL)
	{
		NOEUD_TAS_FIBONACCI *x = z->enfant;
		NOEUD_TAS_FIBONACCI *y = x;
		if (x != NIL)
		{
			do
			{
				x->p = NIL;
				x = x->droite;

			} while (x != y);
			concatenerListes(x, z);
		}
		supprimerRacine(z);
		if (z == z->droite)
		{
			T->min = NIL;
		}
		else
		{
			T->min = z->droite;
			consolider(T);
		}
		T->n--;
	}
	return z;
}

void supprimerRacine(NOEUD_TAS_FIBONACCI *x)
{
	x->gauche->droite = x->droite;
	x->droite->gauche = x->gauche;
}

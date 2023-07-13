#include "TASFIB.h"

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

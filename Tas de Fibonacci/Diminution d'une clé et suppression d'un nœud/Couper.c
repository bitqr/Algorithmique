#include "TASFIB.h"

void couper(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x, NOEUD_TAS_FIBONACCI *y)
{
	supprimerEnfant(x, y);
	ajouterListeRacines(T, x);
	x->p = NIL;
	x->marque = FAUX;
}

void supprimerEnfant(NOEUD_TAS_FIBONACCI *x, NOEUD_TAS_FIBONACCI *y)
{
	if (x == y->enfant)
	{
		y->enfant = x->droite;
	}
	x->gauche->droite = x->droite;
	y->degre--;
	if (y->degre == 0)
	{
		y->enfant = NIL;
	}
}

void ajouterListeRacines(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x)
{
	NOEUD_TAS_FIBONACCI *r = T->min;
	if (r == NIL)
	{
		x->gauche = x;
		x->droite = x;
		T->min = x;
	}
	else
	{
		r->gauche->droite = x;
		x->gauche = r->gauche;
		x->droite = r;
		r->gauche = x;
	}
}

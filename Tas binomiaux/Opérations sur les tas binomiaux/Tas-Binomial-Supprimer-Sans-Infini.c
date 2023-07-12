#include "TASBIN.h"

void tas_binomial_supprimer_sans_infini(TAS_BINOMIAL **T, NOEUD_TAS_BINOMIAL *x)
{
	NOEUD_TAS_BINOMIAL *y = x;
	NOEUD_TAS_BINOMIAL *z = y->p;
	while (z != NIL)
	{
		int temp = y->cle;
		y->cle = z->cle;
		z->cle = temp;
		y = z;
		z = y->p;
	}
	if (y == (*T)->tete)
	{
		(*T)->tete = y->frere;
	}
	else
	{
		z = (*T)->tete;
		while (z->frere != y)
		{
			z = z->frere;
		}
		z->frere = y->frere;
	}
	TAS_BINOMIAL *T1 = creer_tas_binomial();
	NOEUD_TAS_BINOMIAL *e = y->enfant;
	if (y->degre != 0)
	{
		NOEUD_TAS_BINOMIAL *apres_e = e->frere;
		e->frere = NIL;
		e->p = NIL;
		while (apres_e != NIL)
		{
			NOEUD_TAS_BINOMIAL *temp = apres_e->frere;
			apres_e->frere = e;
			apres_e->p = NIL;
			e = apres_e;
			apres_e = temp;
		}
	}
	T1->tete = e;
	*T = union_tas_binomiaux(*T, T1);
}

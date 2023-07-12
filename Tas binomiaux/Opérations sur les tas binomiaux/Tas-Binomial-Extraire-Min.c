#include "TASBIN.h"

NOEUD_TAS_BINOMIAL *tas_binomial_extraire_min(TAS_BINOMIAL **T)
{
	NOEUD_TAS_BINOMIAL *x = NIL;
	if ((*T)->tete != NIL)
	{
		NOEUD_TAS_BINOMIAL *y = (*T)->tete;
		x = y;
		int min = y->cle;
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
	TAS_BINOMIAL *T1 = creer_tas_binomial();
	if (x != NIL)
	{
		NOEUD_TAS_BINOMIAL *e = x->enfant;
		if (x->degre != 0)
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
	}
	*T = union_tas_binomiaux(*T, T1);
	return x;
}

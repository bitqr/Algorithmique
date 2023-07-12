#include "TASBIN.h"

void tas_binomial_inserer(TAS_BINOMIAL **T, NOEUD_TAS_BINOMIAL *x)
{
	TAS_BINOMIAL *T1 = creer_tas_binomial();
	x->p = NIL;
	x->enfant = NIL;
	x->frere = NIL;
	x->degre = 0;
	T1->tete = x;
	*T = union_tas_binomiaux(*T, T1);
}

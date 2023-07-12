#include "TASBIN.h"

TAS_BINOMIAL *creer_tas_binomial()
{
	TAS_BINOMIAL *T = (TAS_BINOMIAL *)malloc(sizeof(TAS_BINOMIAL));
	T->tete = NIL;
	return T;
}

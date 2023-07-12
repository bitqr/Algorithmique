#include "TASBIN.h"

TAS_BINOMIAL *union_tas_binomiaux(TAS_BINOMIAL *T1, TAS_BINOMIAL *T2)
{
	TAS_BINOMIAL *T = creer_tas_binomial();
	T->tete = fusionner_tas_binomiaux(T1, T2);
	if (T->tete == NIL)
		return T;
	NOEUD_TAS_BINOMIAL *avant_x = NIL;
	NOEUD_TAS_BINOMIAL *x = T->tete;
	NOEUD_TAS_BINOMIAL *apres_x = x->frere;
	while (apres_x != NIL)
	{
		if (x->degre != apres_x->degre || (apres_x->frere != NIL && apres_x->frere->degre == x->degre))
		{
			avant_x = x; // Cas 1 et 2
			x = apres_x; // Cas 1 et 2
		}
		else if (x->cle <= apres_x->cle)
		{
			x->frere = apres_x->frere; // Cas 3
			lien_binomial(apres_x, x); // Cas 3
		}
		else
		{
			if (avant_x == NIL) // Cas 4
			{
				T->tete = apres_x;
			} // Cas 4
			else
			{
				avant_x->frere = apres_x;
			}						   // Cas 4
			lien_binomial(x, apres_x); // Cas 4
			x = apres_x;			   // Cas 4
		}
		apres_x = x->frere;
	}
	return T;
}

NOEUD_TAS_BINOMIAL *creerNoeudTasBinomial(int cle, NOEUD_TAS_BINOMIAL *parent, NOEUD_TAS_BINOMIAL *fils, int degre, NOEUD_TAS_BINOMIAL *frere)
{
	NOEUD_TAS_BINOMIAL *x = (NOEUD_TAS_BINOMIAL *)malloc(sizeof(NOEUD_TAS_BINOMIAL));
	x->cle = cle;
	x->p = parent;
	x->enfant = fils;
	x->degre = degre;
	x->frere = frere;
	return x;
}

void afficherTasBinomial(TAS_BINOMIAL *T)
{
	NOEUD_TAS_BINOMIAL *x = T->tete;
	while (x != NIL)
	{
		printf("Arbre binomial B_%d:\n", x->degre);
		afficherArbreBinomial(x, 1);
		x = x->frere;
		printf("\n");
	}
}

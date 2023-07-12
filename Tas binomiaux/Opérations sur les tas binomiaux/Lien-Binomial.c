#include "TASBIN.h"

void lien_binomial(NOEUD_TAS_BINOMIAL *y, NOEUD_TAS_BINOMIAL *z)
{
	y->p = z;
	y->frere = z->enfant;
	z->enfant = y;
	z->degre = z->degre + 1;
}

void afficherArbreBinomial(NOEUD_TAS_BINOMIAL *x, int profondeur)
{
	if (x != NIL)
	{
		int i;
		for (i = 1; i <= profondeur; i++)
		{
			printf("\t");
		}
		printf("Noeud (%d) ", x->cle);
		NOEUD_TAS_BINOMIAL *x1 = x->enfant;
		if (x1 != NIL)
		{
			printf("d'enfant(s) ");
		}
		else
		{
			printf("sans enfants.");
		}
		while (x1 != NIL)
		{
			printf("%d ", x1->cle);
			x1 = x1->frere;
		}
		printf("\n");
		x1 = x->enfant;
		while (x1 != NIL)
		{
			afficherArbreBinomial(x1, profondeur + 1);
			x1 = x1->frere;
		}
	}
}

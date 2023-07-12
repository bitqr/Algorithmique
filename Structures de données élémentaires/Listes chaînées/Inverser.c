#include <stdio.h>
#include <stdlib.h>
#include "ListesChainees.h"

void inverser(LSCC *L)
{
	LSCC *y;
	LSCC *z;
	LSCC *w;
	LSCC *tx = L->tete;
	while (L->suiv != L->tete)
		L = L->suiv;
	L->tete = L;
	LSCC *lx = L;
	L = tx;
	while (L != lx)
	{
		L->tete = lx;
		L = L->suiv;
	}
	z = L->suiv->suiv;
	y = L->suiv;
	y->suiv = L;
	L = z;
	while (L->suiv != L->tete)
	{
		z = L->suiv->suiv;
		w = L->suiv;
		L->suiv = y;
		y = L;
		L = w;
	}
	L->suiv = y;
	z->suiv = L;
	L = L->tete;
	printf("Liste inversee:\n");
	afficherLSCC(L);
}

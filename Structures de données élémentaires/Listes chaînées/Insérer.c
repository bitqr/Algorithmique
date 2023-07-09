#include <stdio.h>
#include <stdlib.h>
#include "ListesChainees.h"

LSCC *creerElement(int x)
{
	LSCC *lx = (LSCC *)malloc(sizeof(LSCC));
	lx->cle = x;
	return lx;
}

void afficherLSCC(LSCC *L)
{
	while (L->suiv != L->tete)
	{
		printf("%d\t", L->cle);
		L = L->suiv;
	}
	printf("%d\n", L->cle);
	L = L->tete;
	printf("La tête de la liste est %d\n", L->cle);
}

void inserer(LSCC *L, int x)
{
	LSCC *lx = creerElement(x);
	lx->suiv = L->tete;
	lx->tete = lx;
	while (L->suiv != L->tete)
	{
		L->tete = lx;
		L = L->suiv;
	}
	L->tete = lx;
	L->suiv = lx;
	L = L->suiv;
	printf("Liste après insertion:\n");
	afficherLSCC(L);
}

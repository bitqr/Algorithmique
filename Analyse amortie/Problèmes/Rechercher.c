#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "PROB.h"

int rechercher(TABLEAUDICHOTOMIQUEDYNAMIQUE *A, int x)
{
	int trouve = NIL;
	int j = 0;
	int i = 1;
	int s = 0;
	while ((trouve == NIL) && (j <= A->tailleBinaire - 1))
	{
		if (A->representationBinaire[j] == 1)
		{
			int a = 0;
			int b = i - 1;
			int m = (a + b) / 2;
			while (A->val[j][m] != x && b - a > 1)
			{
				if (A->val[j][m] < x)
				{
					a = m;
				}
				else
				{
					b = m;
				}
				m = (a + b) / 2;
			}
			if ((A->val[j][m] == x) || (A->val[j][b] == x))
			{
				trouve = m;
				s += trouve;
			}
			else
			{
				s += i;
			}
		}
		j++;
		i = 2 * i;
	}
	if (trouve != NIL)
	{
		trouve = s;
	}
	return trouve;
}

TABLEAUDICHOTOMIQUEDYNAMIQUE *creerTableauDichotomiqueDynamiqueVide()
{
	TABLEAUDICHOTOMIQUEDYNAMIQUE *A = (TABLEAUDICHOTOMIQUEDYNAMIQUE *)malloc(sizeof(TABLEAUDICHOTOMIQUEDYNAMIQUE));
	A->longueur = 0;
	A->tailleBinaire = 0;
	return A;
}

void afficherTableauDichotomiqueDynamique(TABLEAUDICHOTOMIQUEDYNAMIQUE *A)
{
	int i, j;
	for (i = 0; i < A->tailleBinaire; i++)
	{
		if (A->representationBinaire[i] == 1)
		{
			for (j = 0; j < pow(2, i); j++)
			{
				printf("%d\t", A->val[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n\n");
}

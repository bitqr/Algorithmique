#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "PROB.h"

void supprimer(TABLEAUDICHOTOMIQUEDYNAMIQUE *A, int x)
{
	int r = rechercher(A, x);
	if (r != NIL)
	{
		int d = 0;
		int i = 1;
		int s = 0;
		while (r + 1 > s)
		{
			if (A->representationBinaire[d] == 1)
				s += i;
			d++;
			i *= 2;
		}
		i /= 2;
		d--;
		s -= i;
		int c = 0;
		int i1 = 1;
		while (A->representationBinaire[c] == 0)
		{
			A->representationBinaire[c] = 1;
			c++;
			i1 *= 2;
		}
		int ii = r - s;
		A->representationBinaire[c] = 0;
		if (c != d)
		{
			A->val[d][ii] = A->val[c][i1 - 1];
			while (ii > 0 && A->val[d][ii] < A->val[d][ii - 1])
			{
				int tmp = A->val[d][ii - 1];
				A->val[d][ii - 1] = A->val[d][ii];
				A->val[d][ii] = tmp;
				ii = ii - 1;
			}
			while (ii < i - 1 && A->val[d][ii] > A->val[d][ii + 1])
			{
				int tmp = A->val[d][ii + 1];
				A->val[d][ii + 1] = A->val[d][ii];
				A->val[d][ii] = tmp;
				ii = ii + 1;
			}
		}
		else
		{
			while (ii < i - 1)
			{
				A->val[d][ii] = A->val[d][ii + 1];
				ii++;
			}
		}
		int l, m, j = 0;
		i = 1;
		for (l = 0; l <= c - 1; l++)
		{
			for (m = 0; m <= i - 1; m++)
			{
				A->val[l][m] = A->val[c][j];
				j++;
			}
			i *= 2;
		}
		if (c == A->tailleBinaire)
		{
			A->tailleBinaire--;
			int newSize = A->tailleBinaire;
			if (newSize == 0)
			{
				newSize++;
			}
			A->representationBinaire = (int *)realloc(A->representationBinaire, newSize * sizeof(int));
			A->val = (int **)realloc(A->val, newSize * sizeof(int *));
		}
		A->longueur--;
	}
	else
	{
		fprintf(stderr, "Elément %d introuvable.\n\n", x);
	}
}

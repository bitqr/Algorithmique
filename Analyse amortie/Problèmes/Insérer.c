#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "PROB.h"

void inserer(TABLEAUDICHOTOMIQUEDYNAMIQUE *A, int x)
{
	if (A->longueur != 0)
	{
		if (A->representationBinaire[0] == 0)
		{
			A->representationBinaire[0] = 1;
			A->val[0][0] = x;
		}
		else
		{
			int j = 0;
			int i = 1;
			while (A->representationBinaire[j] == 1 && j <= A->tailleBinaire - 1)
			{
				A->representationBinaire[j] = 0;
				j++;
				i = 2 * i;
			}

			if (j == A->tailleBinaire)
			{
				A->tailleBinaire++;
				A->representationBinaire = realloc(A->representationBinaire, A->tailleBinaire * sizeof(int));
				A->val = (int **)realloc(A->val, A->tailleBinaire * sizeof(int *));
				A->val[j] = (int *)malloc(i * sizeof(int));
			}

			int r, s, t, cle, it;
			int b = i / 2 - 1;
			for (r = 0; r <= b; r++)
			{
				A->val[j][r] = A->val[j - 1][r];
			}
			i = 1;
			for (r = 0; r <= j - 2; r++)
			{
				it = 0;
				for (s = 0; s <= i - 1; s++)
				{
					cle = A->val[r][s];
					while (it <= b && A->val[j][it] < cle)
					{
						it++;
					}
					t = b;
					while (t >= it)
					{
						A->val[j][t + 1] = A->val[j][t];
						t--;
					}
					A->val[j][it] = cle;
					b++;
				}
				i = 2 * i;
			}

			it = 0;
			while (it <= b && A->val[j][it] < x)
			{
				it++;
			}
			t = b;
			while (t >= it)
			{
				A->val[j][t + 1] = A->val[j][t];
				t--;
			}
			A->val[j][it] = x;

			A->representationBinaire[j] = 1;
		}
		A->longueur++;
	}
	else
	{
		A->longueur = 1;
		A->representationBinaire = (int *)malloc(sizeof(int));
		A->representationBinaire[0] = 1;
		A->tailleBinaire = 1;
		A->val = (int **)malloc(sizeof(int *));
		A->val[0] = (int *)malloc(sizeof(int));
		A->val[0][0] = x;
	}
}

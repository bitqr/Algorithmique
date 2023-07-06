#include "PROB.h"

int *rendu(TABLEAU C, int n)
{
	int k = C.longueur;
	int i, j, l;
	int **S = (int **)malloc((n + 1) * sizeof(int *));
	for (i = 0; i < n + 1; i++)
	{
		S[i] = (int *)malloc(k * sizeof(int));
	}
	for (i = 0; i < n + 1; i++)
		S[i][0] = i;
	for (i = 0; i < n + 1; i++)
	{
		for (j = 1; j < k; j++)
		{
			if (i < C.tab[j])
			{
				S[i][j] = S[i][j - 1];
			}
			else if (S[i][j - 1] <= 1 + S[i - C.tab[j]][j])
			{
				S[i][j] = S[i][j - 1];
			}
			else
			{
				S[i][j] = 1 + S[i - C.tab[j]][j];
			}
		}
	}
	int *T = (int *)malloc(k * sizeof(int));
	for (l = 0; l < k; l++)
		T[l] = 0;
	i = n;
	j = k - 1;
	while (i != 0)
	{
		if (j == 0 || S[i][j] != S[i][j - 1])
		{
			i = i - C.tab[j];
			T[j]++;
		}
		else
		{
			j--;
		}
	}
	free(S);
	return T;
}

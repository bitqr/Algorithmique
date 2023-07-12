#include "PLSC.h"

int recensement(int **c, int i, int j, SEQUENCE *X, SEQUENCE *Y)
{
	if (c[i][j] > -INFINI)
	{
		return c[i][j];
	}
	if (i == 0 || j == 0)
	{
		c[i][j] = 0;
	}
	else
	{
		if (X->table[i - 1] == Y->table[j - 1])
		{
			c[i][j] = recensement(c, i - 1, j - 1, X, Y) + 1;
		}
		else
		{
			if (recensement(c, i - 1, j, X, Y) >= recensement(c, i, j - 1, X, Y))
			{
				c[i][j] = c[i - 1][j];
			}
			else
			{
				c[i][j] = c[i][j - 1];
			}
		}
	}
	return c[i][j];
}

int longueur_plsc_recensement(SEQUENCE *X, SEQUENCE *Y)
{
	int m = X->longueur;
	int n = Y->longueur;
	int i, j;
	int **c = initTables(m + 1, n + 1);
	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
			c[i][j] = -INFINI;
		}
	}
	int a = recensement(c, m, n, X, Y);
	afficherTables(c, m + 1, n + 1);
	return a;
}

#include "Mat.h"

int recuperer_chaine(DIM *p, int i, int j, int **m)
{
	int k, q;
	if (m[i][j] < INFINI)
	{
		return m[i][j];
	}
	if (i == j)
	{
		m[i][j] = 0;
	}
	else
	{
		for (k = i; k < j; k++)
		{
			q = recuperer_chaine(p, i, k, m) +
				recuperer_chaine(p, k + 1, j, m) +
				p->p[i] * p->p[j + 1] * p->p[k + 1];
			if (q < m[i][j])
			{
				m[i][j] = q;
			}
		}
	}
	return m[i][j];
}

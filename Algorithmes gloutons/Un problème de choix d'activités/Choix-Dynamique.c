#include "PCA.h"

int **creerMatriceEntiers(int m, int n)
{
	int **e = (int **)malloc(m * sizeof(int *));
	int i, j;
	for (i = 0; i < m; i++)
		e[i] = (int *)malloc(n * sizeof(int));
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			e[i][j] = -1;
	return e;
}

int calcul_solution(int **c, int *s, int *f, int i, int j)
{
	if (c[i][j] != -1)
		return c[i][j];
	int m, max = 0;
	for (m = i + 1; m <= j - 1; m++)
		if (s[m] >= f[i] && f[m] <= s[j] && max < 1 + calcul_solution(c, s, f, i, m) + calcul_solution(c, s, f, m, j))
			max = 1 + c[i][m] + c[m][j];
	c[i][j] = max;
	return c[i][j];
}

int choix_dynamique(int *s, int *f, int n)
{
	int **c = creerMatriceEntiers(n + 2, n + 2);
	int i, j, m, max;
	int result = calcul_solution(c, s, f, 0, n + 1);
	free(c);
	return result;
}

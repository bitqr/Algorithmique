#include "VDCB.h"

int *solution_ordonnancement(CHOIX **C, int n, int T, int *t)
{
	int *s = (int *)malloc(n * sizeof(int));
	int i, j, k = 0, max = 0;
	for (i = 0; i <= T; i++)
		if (C[n][i].profit > max)
		{
			max = C[n][i].profit;
			k = i;
		}
	for (i = n - 1; i >= 0; i--)
	{
		s[i] = C[i + 1][k].tache;
		k = k - t[C[i + 1][k].tache - 1];
	}
	return s;
}

int *ordonnancement(int *t, int *d, int *p, int n)
{
	int T = 0;
	int i;
	for (i = 0; i < n; i++)
		T += t[i];
	CHOIX **C = (CHOIX **)malloc((n + 1) * sizeof(CHOIX *));
	for (i = 0; i <= n; i++)
	{
		C[i] = (CHOIX *)malloc((T + 1) * sizeof(CHOIX));
	}
	for (i = 0; i <= n; i++)
	{
		C[i][0].tache = 0;
		C[i][0].temps = -1;
		C[i][0].profit = 0;
	}
	for (i = 0; i <= N; i++)
	{
		C[0][i].tache = 0;
		C[0][i].temps = 0;
		C[0][i].profit = 0;
	}
	int j, k, b, c, max, dp;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= T; j++)
		{
			max = 0;
			C[i][j].tache = 0;
			C[i][j].temps = -1;
			C[i][j].profit = 0;
			for (k = 0; k < n; k++)
			{
				if (j - t[k] >= 0 && C[i - 1][j - t[k]].temps != -1)
				{
					b = i;
					c = j - t[k];
					while ((b - 1) != 0 && (C[b - 1][c].tache != k + 1))
					{
						b--;
						c = c - t[C[b][c].tache - 1];
					}
					if (C[b - 1][c].tache != k + 1)
					{
						dp = (j <= d[k]) ? p[k] : 0;
						if (max < dp + C[i - 1][j - t[k]].profit)
						{
							max = dp + C[i - 1][j - t[k]].profit;
							C[i][j].tache = k + 1;
							C[i][j].temps = C[i - 1][j - t[k]].temps + t[k];
							C[i][j].profit = max;
						}
					}
				}
			}
		}
	}
	return solution_ordonnancement(C, n, T, t);
}

void afficherTable(int *s, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\t", s[i]);
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	int t[NORDO] = {2, 3, 1, 4, 3, 2, 4};
	int d[NORDO] = {5, 6, 8, 8, 12, 7, 9};
	int p[NORDO] = {3, 6, 4, 20, 10, 1, 5};
	int *s = ordonnancement(t, d, p, NORDO);
	int i;
	printf("Considérons l'instance de problème suivante:\n\n");
	afficherTable(t, NORDO);
	afficherTable(d, NORDO);
	afficherTable(p, NORDO);
	printf("\n\n\n\n");
	printf("L'ordonnancement optimal pour ce problème est le suivant:\n\n");
	afficherTable(s, NORDO);
	printf("\n\n");
	return 0;
}

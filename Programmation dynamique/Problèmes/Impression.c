#include "VDCB.h"

void afficher_couts(int **c, int n, int e)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < e; j++)
		{
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}
}

int **impression(int *l, int capacite, int **S, int n)
{
	int i, j, E, k, r;
	int **C = (int **)malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
	{
		C[i] = (int *)malloc(capacite * sizeof(int));
		for (j = 0; j < capacite; j++)
		{
			C[i][j] = 0;
		}
	}
	for (j = 0; j < capacite; j++)
	{
		C[n - 1][j] = (l[n - 1] <= j + 1) ? 0 : (j + 2) * (j + 2) * (j + 2);
		S[n - 1][j] = (l[n - 1] <= j + 1) ? 0 : 1;
	}
	for (j = n - 2; j >= 0; j--)
	{
		for (E = capacite - 1; E >= 0; E--)
		{
			if (E == capacite - 1)
			{
				if (l[j] == capacite && capacite >= 2)
				{
					C[j][E] = C[j + 1][capacite - 2];
					S[j][E] = 2;
				}
				else
				{
					if (l[j] == capacite - 1 && capacite >= 1)
					{
						C[j][E] = 1 + C[j + 1][capacite - 1];
						S[j][E] = 2;
					}
					else if (E - l[j] - 1 >= 0)
					{
						C[j][E] = C[j + 1][E - l[j] - 1];
						S[j][E] = 0;
					}
				}
			}
			else
			{
				if (l[j] < E + 1 && capacite >= 1)
				{
					k = (E + 2) * (E + 2) * (E + 2) + C[j][capacite - 1];
					r = C[j + 1][(E == l[j]) ? capacite - 1 : E - l[j] - 1];
					C[j][E] = (k < r) ? k : (E == l[j]) ? (1 + r)
														: r;
					S[j][E] = (k < r) ? 1 : (E == l[j]) ? 2
														: 0;
				}
				else if (capacite >= 1)
				{
					if (l[j] == E + 1)
					{
						k = (E + 2) * (E + 2) * (E + 2) + C[j][capacite - 1];
						r = C[j + 1][capacite - 2];
						C[j][E] = (k < r) ? k : r;
						S[j][E] = (k < r) ? 1 : 2;
					}
					else
					{
						C[j][E] = (E + 2) * (E + 2) * (E + 2) + C[j][capacite - 1];
						S[j][E] = 1;
					}
				}
			}
		}
	}
	return C;
}

int main(int argc, char **argv)
{
	int mots[N2] = {2, 4, 3, 4, 2, 6, 5, 2, 10, 3, 8, 7, 3, 5, 2};
	int i, j;
	int **S = (int **)malloc(N2 * sizeof(int *));
	for (i = 0; i < N2; i++)
	{
		S[i] = (int *)malloc(M * sizeof(int));
	}
	for (i = 0; i < N2; i++)
	{
		for (j = 0; j < M; j++)
		{
			S[i][j] = 0;
		}
	}
	int **C = impression(mots, M, S, N2);
	afficher_couts(C, N2, M);
	printf("\n\nLe coût optimal est de %d\n\n", C[0][M - 1]);
	return 0;
}

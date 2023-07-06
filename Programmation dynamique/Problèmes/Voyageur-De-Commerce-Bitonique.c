#include "VDCB.h"

POINT **creerPoints(float *entree, int n)
{
	int m = n / 2;
	int i, j = 0;
	POINT **sortie = (POINT **)malloc(m * sizeof(POINT *));
	for (i = 0; i < n; i += 2)
	{
		sortie[j] = (POINT *)malloc(sizeof(POINT));
		sortie[j]->x = entree[i];
		sortie[j]->y = entree[i + 1];
		j++;
	}
	return sortie;
}

float distance_euclidienne(POINT *a, POINT *b)
{
	return sqrt((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
}

float **matrice_distances(POINT **entree, int n)
{
	int i, j;
	float **m = (float **)malloc(n * sizeof(float *));
	for (i = 0; i < n; i++)
		m[i] = (float *)malloc(n * sizeof(float));
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i >= j)
				m[i][j] = 0;
			else
				m[i][j] = distance_euclidienne(entree[i], entree[j]);
	return m;
}

void afficher_couts(float **c, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			if (c[i][j] == 0)
				printf(" \t");
			else
				printf("%.2f\t", c[i][j]);
		printf("\n");
	}
}

float voyageur_de_commerce_bitonique(POINT **points, float **dist, int **S, int n)
{
	int i, j;
	float k, l;
	float **C = (float **)malloc(n * sizeof(float *));
	for (i = 0; i < n; i++)
	{
		C[i] = (float *)malloc(n * sizeof(float));
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			C[i][j] = 0;
		}
	}
	for (j = n - 1; j >= 0; j--)
	{
		for (i = j - 1; i >= 0; i--)
		{
			if (j == n - 1)
			{
				C[i][j] = dist[i][j];
				S[i][j] = i + 1;
			}
			else
			{
				k = dist[j][j + 1] + C[i][j + 1];
				l = dist[i][j + 1] + C[j][j + 1];
				C[i][j] = (k < l) ? k : l;
				S[i][j] = (k < l) ? j + 1 : i + 1;
			}
		}
	}
	k = dist[0][1] + C[0][1];
	return k;
}

int main(int argc, char **argv)
{
	float entree[2 * N] = {0, 6, 1, 0, 2, 3, 5, 4, 6, 1, 7, 5, 8, 2};
	POINT **sortie = creerPoints(entree, 2 * N);
	float **dist = matrice_distances(sortie, N);
	printf("\n\n");
	printf("Distances entre toutes les paires de points\n");
	afficher_couts(dist, N);
	printf("\n\n");
	int i, j;
	int **S = (int **)malloc(N * sizeof(int *));
	for (i = 0; i < N; i++)
		S[i] = (int *)malloc(N * sizeof(int));
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			S[i][j] = 0;
	float ct = voyageur_de_commerce_bitonique(sortie, dist, S, N);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d\t", S[i][j]);
		printf("\n");
	}

	printf("\n\n");

	printf("Le cout d'une tournée bitonique optimale est de %.2f...\n\n", ct);
	return 0;
}

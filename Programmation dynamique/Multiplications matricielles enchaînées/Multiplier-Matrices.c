#include "Mat.h"

MATRICE *creerMatrice(int nl, int nc)
{
	int **m = (int **)malloc(nl * sizeof(int *));
	int i;
	for (i = 0; i < nl; i++)
		m[i] = (int *)malloc(nc * sizeof(int));
	MATRICE *mat = (MATRICE *)malloc(sizeof(MATRICE));
	mat->lignes = nl;
	mat->colonnes = nc;
	mat->tab = m;
	return mat;
}

MATRICE *multiplier_matrices(MATRICE *A, MATRICE *B)
{
	if (A->colonnes != B->lignes)
	{
		fprintf(stderr, "dimensions incompatibles\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		MATRICE *C = creerMatrice(A->lignes, B->colonnes);
		int i, j, k;
		for (i = 0; i < A->lignes; i++)
			for (j = 0; j < B->colonnes; j++)
			{
				(C->tab)[i][j] = 0;
				for (k = 0; k < A->colonnes; k++)
					(C->tab)[i][j] = (C->tab)[i][j] + A->tab[i][k] * B->tab[k][j];
			}
		return C;
	}
}

void afficherMatrice(MATRICE *A)
{
	int i, j;
	for (i = 0; i < A->lignes; i++)
	{
		for (j = 0; j < A->colonnes; j++)
			printf("%d\t", A->tab[i][j]);
		printf("\n");
	}
}

int main(int argc, char **argv)
{
	MATRICE *A = creerMatrice(2, 2);
	A->tab[0][0] = 2;
	A->tab[0][1] = 8;
	A->tab[1][0] = 1;
	A->tab[1][1] = 1;
	MATRICE *B = creerMatrice(2, 3);
	B->tab[0][0] = 4;
	B->tab[0][1] = 3;
	B->tab[0][2] = 0;
	B->tab[1][0] = 1;
	B->tab[1][1] = 1;
	B->tab[1][2] = 1;

	MATRICE *C = multiplier_matrices(A, B);
	afficherMatrice(C);
	printf("\n\n");

	return 0;
}

#include "Glouton.h"

void permuterReels(double *A, int i, int j)
{
	double tmp = A[i];
	A[i] = A[j];
	A[j] = tmp;
}

int partitionReels(double *A, int p, int r)
{
	double x = A[r];
	int i = p - 1;
	int j;
	for (j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			i++;
			permuterReels(A, i, j);
		}
	}
	permuterReels(A, i + 1, r);
	return i + 1;
}

void tri_rapideReels(double *A, int p, int r)
{
	if (p < r)
	{
		int q = partitionReels(A, p, r);
		tri_rapideReels(A, p, q - 1);
		tri_rapideReels(A, q + 1, r);
	}
}

double *enveloppe(double *x, int n)
{
	if (x == NULL || n == 0)
		return NULL;
	double *E = (double *)calloc(n, sizeof(double));
	tri_rapideReels(x, 0, n - 1);
	int i, k = 1;
	E[0] = x[0];
	double extremiteCourante = x[0];
	for (i = 1; i < n; i++)
	{
		if (x[i] > extremiteCourante + 1)
		{
			E[k] = x[i];
			extremiteCourante = x[i];
			k++;
		}
	}
	printf("On trouve %d intervalles\n\n", k);
	return E;
}

int main(int argc, char **argv)
{
	double x[N2] = {-1.3, 0, 0.75, -2.4, 1.65, 3.45, 3.3, 6.38, 2.95, 1.2};
	double *x2 = NULL;
	double *E = enveloppe(x, N2);
	int i = 0;
	if (E == NULL)
		printf("L'ensemble est vide\n\n");
	else
	{
		while (E[i] < E[i + 1])
		{
			printf("[%.2f,%.2f]\n", E[i], E[i] + 1);
			i++;
		}
		printf("[%.2f,%.2f]\n", E[i], E[i] + 1);
	}
	return 0;
}

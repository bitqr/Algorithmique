#include "Ordo.h"

void plus_rapide_chemin(int a[2][N], int t[2][N - 1], int *e, int *x, int n, int *f_opt, int *l_opt)
{
	int *f1 = (int *)calloc(n, sizeof(int));
	int *f2 = (int *)calloc(n, sizeof(int));
	int *l1 = (int *)calloc(N, sizeof(int));
	int *l2 = (int *)calloc(N, sizeof(int));
	f1[0] = e[0] + a[0][0];
	f2[0] = e[1] + a[1][0];
	int j;
	for (j = 1; j < n; j++)
	{
		if (f1[j - 1] + a[0][j] <= f2[j - 1] + t[1][j - 1] + a[0][j])
		{
			f1[j] = f1[j - 1] + a[0][j];
			*(l1 + j) = 1;
		}
		else
		{
			f1[j] = f2[j - 1] + t[1][j - 1] + a[0][j];
			*(l1 + j) = 2;
		}
		if (f2[j - 1] + a[1][j] <= f1[j - 1] + t[0][j - 1] + a[1][j])
		{
			f2[j] = f2[j - 1] + a[1][j];
			*(l2 + j) = 2;
		}
		else
		{
			f2[j] = f1[j - 1] + t[0][j - 1] + a[1][j];
			*(l2 + j) = 1;
		}
	}
	if (f1[n - 1] + x[0] <= f2[n - 1] + x[1])
	{
		*f_opt = f1[n - 1] + x[0];
		*l_opt = 1;
	}
	else
	{
		*f_opt = f2[n - 1] + x[1];
		*l_opt = 2;
	}
}

int main(int argc, char **argv)
{
	int e[2] = {2, 4};
	int x[2] = {3, 2};
	int a[2][N] = {{7, 9, 3, 4, 8, 4}, {8, 5, 6, 4, 5, 7}};
	int t[2][N - 1] = {{2, 3, 1, 3, 4}, {2, 1, 2, 2, 1}};
	int f_opt = 0;
	int l_opt = 0;
	plus_rapide_chemin(a, t, e, x, N, &f_opt, &l_opt);
	printf("La solution optimale est f* = %d et l* = %d\n\n", f_opt, l_opt);
	int l1[N] = {0, 1, 2, 1, 1, 2};
	int l2[N] = {0, 1, 2, 1, 2, 2};
	afficher_postes(l1, l2, N, &l_opt);
	return 0;
}

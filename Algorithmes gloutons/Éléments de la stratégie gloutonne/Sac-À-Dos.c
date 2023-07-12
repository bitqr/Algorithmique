#include "Glouton.h"

int *sac_a_dos(int *V, int *w, int W, int n)
{
	pre_tri(V, w, n);
	int cout = 0;
	int i;
	int *S = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		if (W >= w[i])
		{
			S[i] = 1;
			W -= w[i];
			cout += V[i];
		}
		else
		{
			S[i] = 0;
		}
	}
	printf("Le coût est de %d\n\n", cout);
	return S;
}

int main(int argc, char **argv)
{
	int V[N] = {13, 17, 4, 7, 1, 2, 14, 10, 11, 8};
	int w[N] = {6, 3, 12, 11, 19, 15, 4, 7, 6, 10};
	int *S = sac_a_dos(V, w, WW, N);
	int i;
	for (i = 0; i < N; i++)
	{
		if (S[i] == 1)
		{
			printf("On prend l'objet de poids %d et de valeur %d\n", w[i], V[i]);
		}
	}
	printf("\n");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 7

int *creer_candidates(int n)
{
	int i;
	int *tab = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		tab[i] = rand() % 1000;
	}
	return tab;
}

int *permuter_alea(int *t, int n)
{
	int i, r, tmp;
	for (i = 0; i < n; i++)
	{
		r = rand() % n;
		tmp = t[r];
		t[r] = t[i];
		t[i] = tmp;
	}
	return t;
}

int interviewer(int *t, int n) { return t[n]; }

void embaucher(int n) { printf("La secrétaire %d est embauchée\n\n\n", n); }

void embauche_secretaire(int n)
{
	int i, j;
	int *t1 = creer_candidates(n);
	for (i = 0; i < n; i++)
		printf("%d\t", t1[i]);
	printf("\n\n\n");
	int *t = permuter_alea(t1, n);
	for (i = 0; i < n; i++)
		printf("%d\t", t[i]);
	printf("\n\n\n");
	int meilleure = 0; /*candidate 0 est une candidate fictive, moins qualifiée
						  que quiconque */
	for (i = 0; i < n; i++)
	{
		j = interviewer(t, i);
		if (j > t[meilleure])
		{
			meilleure = i;
			embaucher(i + 1);
		}
	}
	printf("La candidate embauchée est finalement la secrétaire numéro %d\n\n\n",
		   meilleure + 1);
}

int main()
{
	int i, j;
	srand(time(NULL));
	embauche_secretaire(N);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "ListeCompacte.h"

int libre = 7;
int L = 3;
int succ[TAILLE] = {4, -1, 5, 2, 1, -1, 8, 6};
int cle[TAILLE] = {20, 50, 4, 36, 18, -1, -1, -1};
int pred[TAILLE] = {5, 4, -1, 1, 3, -1, -1, -1};

int Random(int a, int b)
{
	int i;
	if (a == 0 && b == 1)
	{
		return rand() % 2;
	}
	int acc = 0;
	for (i = a; i < b; i++)
	{
		acc += Random(0, 1);
	}
	return a + acc;
}

int recherche_liste_compact_2(int L, int n, int k, int t)
{
	int i = L, j, q;
	for (q = 1; q <= t; q++)
	{
		j = Random(1, n);
		if (cle[i - 1] < cle[j - 1] && cle[j - 1] <= k)
		{
			i = j;
			if (cle[i - 1] == k)
			{
				return i;
			}
		}
	}
	while (i != -1 && cle[i - 1] < k)
	{
		i = succ[i - 1];
	}
	if (i == -1 || cle[i - 1] > k)
	{
		return -1;
	}
	else
	{
		return i;
	}
}

int main(int argc, char **argv)
{
	printf("%d\n", recherche_liste_compact_2(L, N, K, T));
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "AdressageOuvert.h"

int inserer_hachage_modifie(int *T, int m, int k)
{
	int i = 0, j;
	do
	{
		j = h(k, i, m);
		if (T[j] == -1 || T[j] == SUPPRIMEE)
		{
			T[j] = k;
			return j;
		}
		else
		{
			i++;
		}
	} while (i != m);
	fprintf(stderr, "débordement de la table de hachage\n");
	exit(EXIT_FAILURE);
}

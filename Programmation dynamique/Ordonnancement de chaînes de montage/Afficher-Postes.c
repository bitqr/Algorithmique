#include "Ordo.h"

void afficher_postes(int *l1, int *l2, int n, int *l_opt)
{
	int i = *l_opt;
	printf("chaine %d, poste %d \n", i, n);
	int j;
	for (j = n; j >= 2; j--)
	{
		if (i == 1)
		{
			i = l1[j - 1];
		}
		else
		{
			i = l2[j - 1];
		}
		printf("chaîne %d, poste %d \n", i, j - 1);
	}
}

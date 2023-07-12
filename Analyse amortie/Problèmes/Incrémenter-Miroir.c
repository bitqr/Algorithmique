#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "PROB.h"

void incrementer_miroir(TABLEAU *A)
{
	int i = 0;
	int k = A->longueur;
	while ((i < k) && (A->val[k - 1 - i] == 1))
	{
		A->val[k - 1 - i] = 0;
		i++;
	}
	if (i < k)
	{
		A->val[k - 1 - i] = 1;
	}
}

TABLEAU *inventerTableau(unsigned int l)
{
	TABLEAU *tab = (TABLEAU *)malloc(sizeof(TABLEAU));
	tab->longueur = l;
	tab->val = (int *)calloc(l, sizeof(int));
	return tab;
}

void ecrireTableau(TABLEAU *A)
{
	int i;
	for (i = 0; i < A->longueur; i++)
	{
		printf("%d", A->val[A->longueur - i - 1]);
	}
	printf("\n\n");
}

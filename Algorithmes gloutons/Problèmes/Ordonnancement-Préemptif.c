#include "PROB.h"

LISTE_CHAINEE *creerElement(int cle)
{
	LISTE_CHAINEE *L = (LISTE_CHAINEE *)malloc(sizeof(LISTE_CHAINEE));
	L->cle = cle;
	L->suiv = NULL;
	return L;
}

LISTE_CHAINEE *ordonnancement_preemptif(int *A, int *P, int *R, int n)
{
	int D = 0;
	LISTE_CHAINEE *L = creerElement(-1);
	L->tete = L;
	int i, exec = 0, t = 0, min, imin;
	for (i = 0; i < n; i++)
	{
		D += P[i];
	}
	while (exec < D)
	{
		min = D + 1;
		imin = -1;
		for (i = 0; i < n; i++)
		{
			if (t >= R[i] && P[i] != 0)
			{
				if (P[i] < min)
				{
					min = P[i];
					imin = i;
				}
			}
		}
		if (min != D + 1)
		{
			L->suiv = creerElement(imin + 1);
			L->suiv->tete = L->tete;
			P[imin]--;
			exec++;
		}
		else
		{
			L->suiv = creerElement(0);
			L->suiv->tete = L->tete;
		}
		L = L->suiv;
		t++;
	}
	return L->tete->suiv;
}

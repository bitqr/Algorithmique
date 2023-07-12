#include "ARN.h"

int rechercher_rang_cle(NOEUD *x, int k)
{
	if (x->cle == k)
	{
		return x->gauche->taille + 1;
	}
	else if (x->cle > k)
	{
		return rechercher_rang_cle(x->gauche, k);
	}
	else
	{
		return 1 + x->gauche->taille + rechercher_rang_cle(x->droite, k);
	}
}

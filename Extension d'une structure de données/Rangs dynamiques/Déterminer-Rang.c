#include "ARN.h"

int determiner_rang(ARN *T, NOEUD *x)
{
	int r = x->gauche->taille + 1;
	NOEUD *y = x;
	while (y != T->racine)
	{
		if (y == y->p->droite)
		{
			r += y->p->gauche->taille + 1;
		}
		y = y->p;
	}
	return r;
}

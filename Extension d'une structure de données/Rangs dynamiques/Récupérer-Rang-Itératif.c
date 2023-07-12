#include "ARN.h"

NOEUD *recuperer_rang_iteratif(NOEUD *x, int i)
{
	NOEUD *y = x;
	int r = y->gauche->taille + 1;
	while (i != r)
	{
		if (i < r)
		{
			y = y->gauche;
		}
		else
		{
			y = y->droite;
			i = i - r;
		}
		r = y->gauche->taille + 1;
	}
	return y;
}

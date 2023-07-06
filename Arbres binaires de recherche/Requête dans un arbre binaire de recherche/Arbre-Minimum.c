#include <stdio.h>
#include <stdlib.h>
#include "ABR.h"

ABR *arbre_minimum(ABR *x)
{
	while (x->gauche)
	{
		x = x->gauche;
	}
	return x;
}

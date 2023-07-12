#include "ABR.h"
#include <stdlib.h>

ABR *arbre_maximum_recursif(ABR *x)
{
	if (x == NULL || x->droite == NULL)
	{
		return x;
	}
	else
	{
		return arbre_maximum_recursif(x->droite);
	}
}

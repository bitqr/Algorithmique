#include <stdio.h>
#include <stdlib.h>
#include "ABR.h"

ABR *arbre_maximum(ABR *x)
{
	while (x->droite)
		x = x->droite;
	return x;
}

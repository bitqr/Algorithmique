#include <stdio.h>
#include <stdlib.h>
#include "ImplementationObjets.h"

void liberer_objet_2(int x, int *unique, int *libre2)
{
	unique[x - 2] = *libre2;
	*libre2 = x;
}

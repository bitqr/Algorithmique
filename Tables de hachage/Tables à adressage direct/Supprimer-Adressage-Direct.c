#include "Hachage.h"
#include <stdlib.h>
#include <stdio.h>

void supprimer_adressage_direct(OBJET **T, OBJET *x)
{
	T[x->cle] = NULL;
}

#include <stdlib.h>
#include <stdio.h>
#include "ArbreBinaireRecherche.h"

void parcours_postfixe(ABR *x)
{
	if (x != NULL)
	{
		parcours_postfixe(x->gauche);
		parcours_postfixe(x->droite);
		printf("%d\t", x->cle);
	}
}

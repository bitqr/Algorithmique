#include <stdio.h>
#include <stdlib.h>
#include "Arborescence.h"

void afficher_arbre_3(ARBRE *A)
{
	if (A)
	{
		printf("%d\t", A->cle);
		afficher_arbre_3(A->frered);
		afficher_arbre_3(A->filsg);
	}
}

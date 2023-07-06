#include <stdio.h>
#include <stdlib.h>
#include "ABR.h"

void arbre_inserer_recursif(ABR *T, ABR *z)
{
	if (T == NULL)
	{
		T = z;
		if (T)
		{
			printf("Nouvelle racine : %d\n", T->cle);
		}
	}
	else
	{
		if (z->cle <= T->cle)
			if (T->gauche == NULL)
			{
				T->gauche = z;
				z->p = T;
			}
			else
				arbre_inserer_recursif(T->gauche, z);
		else if (T->droite == NULL)
		{
			T->droite = z;
			z->p = T;
		}
		else
			arbre_inserer_recursif(T->droite, z);
	}
}

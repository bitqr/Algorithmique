#include <stdio.h>
#include <stdlib.h>
#include "ArbreBinaireRecherche.h"

void parcours_infixe(ABR *x)
{
	if (x != NULL)
	{
		parcours_infixe(x->gauche);
		printf("%d\t", x->cle);
		parcours_infixe(x->droite);
	}
}

ABR *creer_abr(int cle, ABR *p, ABR *g, ABR *d)
{
	ABR *x = (ABR *)malloc(sizeof(ABR));
	x->cle = cle;
	x->p = p;
	x->droite = d;
	x->gauche = g;
	return x;
}

int main(int argc, char **argv)
{
	ABR *x = NULL;
	ABR *x1 = NULL;
	ABR *x2 = NULL;
	ABR *y1 = creer_abr(2, x1, NULL, NULL);
	ABR *y2 = creer_abr(5, x1, NULL, NULL);
	ABR *y3 = creer_abr(8, x2, NULL, NULL);
	x1 = creer_abr(3, x, y1, y2);
	y1->p = x1;
	y2->p = x1;
	x2 = creer_abr(7, x, NULL, y3);
	y3->p = x2;
	x = creer_abr(5, NULL, x1, x2);

	parcours_infixe(x);
	printf("\n");
	parcours_infixe_non_recursif(x);
	printf("\n");
	parcours_prefixe(x);
	printf("\n");
	parcours_postfixe(x);
	printf("\n");
	return 0;
}

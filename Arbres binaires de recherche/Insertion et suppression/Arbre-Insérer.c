#include <stdio.h>
#include <stdlib.h>
#include "ABR.h"

ABR *creer_abr(int cle, ABR *g, ABR *d)
{
	ABR *x = (ABR *)malloc(sizeof(ABR));
	x->cle = cle;
	x->droite = d;
	x->gauche = g;
	return x;
}

void parcours_infixe(ABR *x)
{
	if (x != NULL)
	{
		parcours_infixe(x->gauche);
		printf("%d\n", x->cle);
		parcours_infixe(x->droite);
	}
}

void arbre_inserer(ABR *T, ABR *z)
{
	ABR *y = NULL;
	ABR *x = T;
	while (x)
	{
		y = x;
		if (z->cle < x->cle)
			x = x->gauche;
		else
			x = x->droite;
	}
	z->p = y;
	if (y == NULL)
	{
		T = z; // arbre T était vide
		printf("Nouvelle racine: %d\n", T->cle);
	}
	else if (z->cle < y->cle)
	{
		printf("Insertion à gauche\n");
		y->gauche = z;
	}
	else
	{
		printf("Insertion à droite\n");
		y->droite = z;
	}
}

int main(int argc, char **argv)
{
	ABR *x;
	ABR *x1;
	ABR *x2;
	ABR *f1;
	ABR *f2;
	ABR *f3;
	ABR *f4;
	ABR *f5;
	f1 = creer_abr(2, NULL, NULL);
	f2 = creer_abr(9, NULL, NULL);
	f3 = creer_abr(19, NULL, NULL);
	f5 = creer_abr(17, NULL, NULL);
	f4 = creer_abr(15, NULL, f5);
	x1 = creer_abr(5, f1, f2);
	x2 = creer_abr(18, f4, f3);
	x = creer_abr(12, x1, x2);
	x->p = NULL;
	x1->p = x;
	x2->p = x;
	f1->p = x1;
	f2->p = x1;
	f3->p = x2;
	f4->p = x2;
	f5->p = f4;
	ABR *z = creer_abr(13, NULL, NULL);
	ABR *w = creer_abr(27, NULL, NULL);
	ABR *T = x;
	parcours_infixe(T);
	printf("\n");
	printf("Insertion de %d \n", z->cle);
	arbre_inserer(T, z);
	printf("Père de %d : %d\n", z->cle, z->p->cle);
	parcours_infixe(T);
	printf("\n");
	printf("Suppression de %d\n", f1->cle);
	arbre_supprimer(T, f1);
	parcours_infixe(T);
	printf("\n");
	printf("Suppression de %d\n", f4->cle);
	arbre_supprimer(T, f4);
	parcours_infixe(T);
	printf("\n");
	printf("Insertion de %d \n", w->cle);
	arbre_inserer_recursif(T, w);
	printf("Père de %d : %d\n", w->cle, w->p->cle);
	parcours_infixe(T);
	printf("\n");
	return 0;
}

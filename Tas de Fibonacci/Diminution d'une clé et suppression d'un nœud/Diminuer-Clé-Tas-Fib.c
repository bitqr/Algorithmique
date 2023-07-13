#include "TASFIB.h"

void diminuer_cle_tas_fib(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x, int k)
{
	if (k > x->cle)
	{
		printf("nouvelle clé plus grande que clé courante");
		exit(EXIT_FAILURE);
	}
	x->cle = k;
	NOEUD_TAS_FIBONACCI *y = x->p;
	if (y != NIL && x->cle < y->cle)
	{
		couper(T, x, y);
		coupe_en_cascade(T, y);
	}
	if (x->cle < T->min->cle)
	{
		T->min = x;
	}
}

NOEUD_TAS_FIBONACCI *creerNoeudTasFibonacci(int cle, NOEUD_TAS_FIBONACCI *enfant, NOEUD_TAS_FIBONACCI *pere, NOEUD_TAS_FIBONACCI *g, NOEUD_TAS_FIBONACCI *d, int m, int dg)
{
	NOEUD_TAS_FIBONACCI *x = (NOEUD_TAS_FIBONACCI *)malloc(sizeof(NOEUD_TAS_FIBONACCI));
	x->cle = cle;
	x->gauche = g;
	x->droite = d;
	x->p = pere;
	x->marque = m;
	x->degre = dg;
	return x;
}

int afficherArbreTasFibonacci(NOEUD_TAS_FIBONACCI *x, int profondeur)
{
	int c = 0;
	if (x != NIL)
	{
		int i;
		for (i = 1; i <= profondeur; i++)
		{
			printf("\t");
		}
		printf("Noeud (%d)", x->cle);
		if (x->marque != FAUX)
		{
			printf(" marqué ");
		}
		else
		{
			printf(" non marqué ");
		}
		NOEUD_TAS_FIBONACCI *x1 = x->enfant;
		if (x1 != NIL)
		{
			printf("d'enfant(s) ");
		}
		else
		{
			printf("sans enfants.");
		}
		int d = 0;
		c++;
		while (d < x->degre)
		{
			if (x1 != NIL)
			{
				printf("%d ", x1->cle);
				x1 = x1->droite;
				d++;
			}
		}
		printf("\n");
		x1 = x->enfant;
		d = 0;
		while (d < x->degre)
		{
			c += afficherArbreTasFibonacci(x1, profondeur + 1);
			x1 = x1->droite;
			d++;
		}
	}
	return c;
}

void afficherTasFibonacci(TAS_FIBONACCI *T)
{
	if (T->n == 0)
	{
		printf("Tas vide.\n");
	}
	else
	{
		printf("Le tas a %d noeud(s)\n", T->n);
		NOEUD_TAS_FIBONACCI *x = T->min;
		int c = 0;
		while (c < T->n)
		{
			printf("Arbre dont la racine est de degré %d :\n", x->degre);
			c += afficherArbreTasFibonacci(x, 1);
			x = x->droite;
			printf("\n");
		}
	}
}

int main(int argc, char **argv)
{
	printf("\n\nCréation du tas de Fibonacci T : \n");
	TAS_FIBONACCI *T = (TAS_FIBONACCI *)malloc(sizeof(TAS_FIBONACCI));
	T->n = 0;
	T->min = NIL;
	if (T->min == NIL)
	{
		printf("T est vide.\n");
	}
	printf("T a %d noeud(s).\n\n\n", T->n);
	NOEUD_TAS_FIBONACCI *x1 = creerNoeudTasFibonacci(7, NIL, NIL, NIL, NIL, FAUX, 3);
	NOEUD_TAS_FIBONACCI *x2 = creerNoeudTasFibonacci(18, NIL, NIL, x1, NIL, VRAI, 2);
	NOEUD_TAS_FIBONACCI *x3 = creerNoeudTasFibonacci(38, NIL, NIL, x2, x1, FAUX, 1);
	NOEUD_TAS_FIBONACCI *x4 = creerNoeudTasFibonacci(24, NIL, x1, NIL, NIL, FAUX, 2);
	NOEUD_TAS_FIBONACCI *x5 = creerNoeudTasFibonacci(17, NIL, x1, x4, NIL, FAUX, 1);
	NOEUD_TAS_FIBONACCI *x6 = creerNoeudTasFibonacci(23, NIL, x1, x5, x4, FAUX, 0);
	NOEUD_TAS_FIBONACCI *x7 = creerNoeudTasFibonacci(21, NIL, x2, NIL, NIL, FAUX, 1);
	NOEUD_TAS_FIBONACCI *x8 = creerNoeudTasFibonacci(39, NIL, x2, x7, x7, VRAI, 0);
	NOEUD_TAS_FIBONACCI *x9 = creerNoeudTasFibonacci(41, NIL, x3, NIL, NIL, FAUX, 0);
	NOEUD_TAS_FIBONACCI *x10 = creerNoeudTasFibonacci(26, NIL, x4, NIL, NIL, VRAI, 1);
	NOEUD_TAS_FIBONACCI *x11 = creerNoeudTasFibonacci(46, NIL, x4, x10, x10, FAUX, 0);
	NOEUD_TAS_FIBONACCI *x12 = creerNoeudTasFibonacci(30, NIL, x5, NIL, NIL, FAUX, 0);
	NOEUD_TAS_FIBONACCI *x13 = creerNoeudTasFibonacci(52, NIL, x7, NIL, NIL, FAUX, 0);
	NOEUD_TAS_FIBONACCI *x14 = creerNoeudTasFibonacci(35, NIL, x10, NIL, NIL, FAUX, 0);
	x1->droite = x2;
	x1->gauche = x3;
	x1->enfant = x4;
	x2->droite = x3;
	x2->enfant = x7;
	x3->enfant = x9;
	x4->droite = x5;
	x4->gauche = x6;
	x4->enfant = x10;
	x5->droite = x6;
	x5->enfant = x12;
	x7->droite = x8;
	x7->gauche = x8;
	x7->enfant = x13;
	x9->droite = x9;
	x9->gauche = x9;
	x10->droite = x11;
	x10->gauche = x11;
	x10->enfant = x14;
	x12->droite = x12;
	x12->gauche = x12;
	x13->droite = x13;
	x13->gauche = x13;
	x14->droite = x14;
	x14->gauche = x14;
	T->n = 14;
	T->min = x1;
	printf("\n\nTas de Fibonacci T avant diminution de la clé 46 à 15 :\n\n");
	afficherTasFibonacci(T);
	diminuer_cle_tas_fib(T, x11, 15);
	printf("\n\nTas de Fibonacci T après diminution de la clé 46 à 15 :\n\n");
	afficherTasFibonacci(T);
	diminuer_cle_tas_fib(T, x14, 5);
	printf("\n\nTas de Fibonacci T après diminution de la clé 35 à 5 :\n\n");
	afficherTasFibonacci(T);
	supprimer_tas_fib(T, x6);
	printf("\n\nTas de Fibonacci T après suppression de la clé 23 :\n\n");
	afficherTasFibonacci(T);
	return 0;
}

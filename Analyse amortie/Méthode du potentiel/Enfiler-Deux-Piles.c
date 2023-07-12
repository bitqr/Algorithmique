#include "DEUXPILES.h"

PILE *creer_pile(int taille)
{
	PILE *P = (PILE *)malloc(sizeof(PILE));
	int *t = (int *)malloc(taille * sizeof(int));
	P->sommet = -1;
	P->taille = taille;
	P->tableau = t;
	return P;
}

FILEDEUXPILES *creer_file_deux_piles(int longueur)
{
	FILEDEUXPILES *F = (FILEDEUXPILES *)malloc(sizeof(FILEDEUXPILES));
	F->p = creer_pile(longueur);
	F->q = creer_pile(longueur);
	F->longueur = longueur;
	return F;
}

void empiler(PILE *P, int x)
{
	P->sommet++;
	P->tableau[P->sommet] = x;
}

void enfiler_deux_piles(FILEDEUXPILES *F, int x)
{
	if (F->p->sommet + F->q->sommet + 2 >= F->longueur)
	{
		fprintf(stderr, "débordement\n");
	}
	else
	{
		empiler(F->q, x);
	}
}

void afficher_file_deux_piles(FILEDEUXPILES *F)
{
	printf("Les éléments de la file sont, de la tête à la queue : \n\n");
	int i;
	for (i = F->p->sommet; i >= 0; i--)
	{
		printf("%d\t", F->p->tableau[i]);
	}
	for (i = 0; i <= F->q->sommet; i++)
	{
		printf("%d\t", F->q->tableau[i]);
	}
	printf("\n\n");
}

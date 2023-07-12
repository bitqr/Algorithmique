#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct tas
{
	int longueur; /* limite sous laquelle le tableau peut contenir des nombres valides */
	int taille;	  /* limite des nombres compris dans le tas */
	int *tableau; /* tableau contenant les éléments du tas */
} TAS;

typedef TAS *P_TAS;

int gauche(int i)
{
	return 2 * i + 1;
}

P_TAS creer_tas(int longueur, int taille)
{
	P_TAS t = (P_TAS)malloc(sizeof(TAS));
	t->longueur = longueur;
	t->taille = taille;
	int *tab = (int *)malloc(longueur * sizeof(int));
	t->tableau = tab;
	return t;
}

int main()
{
	P_TAS tas = creer_tas(N, N);
	int tab[N] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
	tas->tableau = tab;
	int i;
	for (i = 0; i < N; i++)
	{
		if (i > (N - 1) / 2)
		{
			printf("L'élément %d n'a pas de fils gauche\n\n\n", tas->tableau[i]);
		}
		else
		{
			printf("Le fils gauche de l'élément %d est l'élément %d \n\n\n", tas->tableau[i], tas->tableau[gauche(i)]);
		}
	}
	free(tas);
	return 0;
}

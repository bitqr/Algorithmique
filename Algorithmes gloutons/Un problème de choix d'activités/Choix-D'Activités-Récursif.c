#include "PCA.h"

FILES *creer_file_vide(int taille)
{
	FILES *F = (FILES *)malloc(sizeof(FILES));
	int *t = (int *)malloc(taille * sizeof(int));
	F->tete = 0;
	F->longueur = taille;
	F->queue = 0;
	F->tableau = t;
	return F;
}

void afficherMatriceEntiers(int **e, int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d\t", e[i][j]);
		}
		printf("\n");
	}
}

void afficher_file(FILES *F)
{
	if (F->tete == F->queue)
		printf("La liste est vide\n\n");
	else
	{
		int i = F->queue - 1;
		printf("Les activités retenues sont : \n\n");
		while (i >= F->tete)
		{
			printf("a%d\t", F->tableau[i]);
			i--;
			i = i % F->longueur;
		}
		printf("\n\n");
	}
}

FILES *enfiler(FILES *F, int x)
{
	F->tableau[F->queue] = x;
	if (F->queue + 1 == F->longueur)
	{
		F->queue = 0;
	}
	else
	{
		F->queue++;
	}
	return F;
}

FILES *choix_d_activites_recursif(int *s, int *f, int i, int n)
{
	int m = i + 1;
	while (m <= n && s[m] < f[i])
	{ // trouver première activité de S_(i,n+1)
		m++;
	}
	if (m <= n)
	{
		return enfiler(choix_d_activites_recursif(s, f, m, n), m);
	}
	else
	{
		return creer_file_vide(n);
	}
}

int main(int argc, char **argv)
{
	int s[N + 1] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
	int f[N + 1] = {0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
	FILES *P = choix_d_activites_recursif(s, f, 0, N);
	afficher_file(P);
	printf("\n\n");
	TABLEAU *S = (TABLEAU *)malloc(sizeof(TABLEAU));
	S->valeurs = (int *)malloc((N + 1) * sizeof(int));
	TABLEAU *F = (TABLEAU *)malloc(sizeof(TABLEAU));
	F->valeurs = (int *)malloc((N + 1) * sizeof(int));
	S->longueur = N + 1;
	F->longueur = N + 1;
	int i;
	for (i = 0; i <= N; i++)
	{
		S->valeurs[i] = s[i];
		F->valeurs[i] = f[i];
	}
	FILES *A = choix_d_activites_glouton(S, F);
	afficher_file(A);
	printf("\n\n");
	int m = choix_dynamique(s, f, N);
	printf("Le nombre maximal d'activités possibles à réaliser est de %d\n\n", m);
	int *Couleurs = coloration_salles(s, f, N);
	for (i = 0; i < N; i++)
	{
		printf("L'activité %d se déroulera dans la salle %d\n", i + 1, Couleurs[i]);
	}

	return 0;
}

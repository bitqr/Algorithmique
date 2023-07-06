#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "PROB.h"

int rev(int k, int a)
{
	int i;
	int d = 1;
	for (i = 0; i < k - 1; i++)
		d = d * 2;
	int *Bin = (int *)malloc(k * sizeof(int));
	for (i = 0; i < k; i++)
	{
		Bin[i] = a / d;
		a = a % d;
		d = d / 2;
	}
	d = 1;
	int reva = 0;
	for (i = 0; i < k; i++)
	{
		reva = reva + Bin[i] * d;
		d = 2 * d;
	}
	return reva;
}

int *permutation_miroir(int *A, int k)
{
	int i;
	int n = pow(2, k);
	int *B = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		B[i] = A[rev(k, i)];
	return B;
}

void afficherTableau(int *A, int n)
{
	int i;
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", A[i]);
	}
	printf("\n");
}

int *creerTableau(int n, int limite)
{
	int *A = (int *)malloc(n * sizeof(int));
	int i;
	for (i = 0; i < n; i++)
	{
		A[i] = rand() % limite;
	}
	return A;
}

int main(int argc, char **argv)
{
	int n = pow(2, K);
	int *A = creerTableau(n, L);
	int *B = permutation_miroir(A, K);
	printf("Voici le tableau d'origine :\n\n");
	afficherTableau(A, n);

	printf("\nVoici le tableau après permutation miroir :\n\n");
	afficherTableau(B, n);

	TABLEAU *C = inventerTableau(K);
	printf("Bonjour et bienvenue! Je vais afficher les résultats d'incrémentations miroir successives d'un entier en base 2, modulo 2^%d\n\n", C->longueur);
	int i;
	printf("Le nombre initial :\n");
	ecrireTableau(C);
	for (i = 0; i < n; i++)
	{
		incrementer_miroir(C);
		ecrireTableau(C);
	}

	TABLEAUDICHOTOMIQUEDYNAMIQUE *AD = creerTableauDichotomiqueDynamiqueVide();
	AD->longueur = 9;
	AD->tailleBinaire = 4;
	AD->representationBinaire = (int *)malloc(AD->tailleBinaire * sizeof(int));
	AD->representationBinaire[0] = 1;
	AD->representationBinaire[1] = 0;
	AD->representationBinaire[2] = 0;
	AD->representationBinaire[3] = 1;
	AD->val = (int **)malloc(AD->tailleBinaire * sizeof(int *));
	int puiss = 1;
	for (i = 0; i < AD->tailleBinaire; i++)
	{
		AD->val[i] = (int *)malloc(puiss * sizeof(int));
		puiss = 2 * puiss;
	}
	AD->val[0][0] = 57;
	AD->val[3][0] = 2;
	AD->val[3][1] = 26;
	AD->val[3][2] = 67;
	AD->val[3][3] = 145;
	AD->val[3][4] = 235;
	AD->val[3][5] = 816;
	AD->val[3][6] = 901;
	AD->val[3][7] = 945;

	printf("Voici un tableau dichotomique dynamique : \n\n");
	afficherTableauDichotomiqueDynamique(AD);

	int x = rechercher(AD, 68);
	int y = rechercher(AD, 57);
	int z = rechercher(AD, 908);
	int t = rechercher(AD, 816);

	if (x == NIL)
		printf("\n\nL'élément 68 n'existe pas dans ce tableau.\n");
	else
		printf("\n\nL'élément 68 existe dans ce tableau (indice %d).\n", x);

	if (y == NIL)
		printf("\n\nL'élément 57 n'existe pas dans ce tableau.\n");
	else
		printf("\n\nL'élément 57 existe dans ce tableau (indice %d).\n", y);

	if (z == NIL)
		printf("\n\nL'élément 908 n'existe pas dans ce tableau.\n");
	else
		printf("\n\nL'élément 908 existe dans ce tableau (indice %d).\n", z);

	if (t == NIL)
		printf("\n\nL'élément 816 n'existe pas dans ce tableau.\n\n");
	else
		printf("\n\nL'élément 816 existe dans ce tableau (indice %d).\n\n", t);

	TABLEAUDICHOTOMIQUEDYNAMIQUE *ADD = creerTableauDichotomiqueDynamiqueVide();
	printf("On commence avec un tableau vide.\n\n");

	x = 57;
	printf("Après insertion de x = %d\n\n", x);
	inserer(ADD, x);
	afficherTableauDichotomiqueDynamique(ADD);

	x = 28;
	printf("Après insertion de x = %d\n\n", x);
	inserer(ADD, x);
	afficherTableauDichotomiqueDynamique(ADD);

	x = 75;
	printf("Après insertion de x = %d\n\n", x);
	inserer(ADD, x);
	afficherTableauDichotomiqueDynamique(ADD);

	x = 29;
	printf("Après insertion de x = %d\n\n", x);
	inserer(ADD, x);
	afficherTableauDichotomiqueDynamique(ADD);

	for (i = 0; i < NINS; i++)
	{
		printf("Après insertion de x = %d\n\n", i);
		inserer(ADD, i);
		afficherTableauDichotomiqueDynamique(ADD);
	}

	for (i = 0; i < NSUPP; i++)
	{
		printf("Après suppression de x = %d\n\n", i);
		supprimer(ADD, i);
		afficherTableauDichotomiqueDynamique(ADD);
	}

	NOEUD *ni = (NOEUD *)malloc(sizeof(NOEUD));
	ni->cle = NIL;
	ni->gauche = ni;
	ni->droit = ni;
	ni->taille = 0;

	NOEUD *n1 = creerNoeud(42, ni, ni);
	n1->taille = 1;

	NOEUD *n2 = creerNoeud(35, ni, n1);
	n2->taille = 2;

	NOEUD *n3 = creerNoeud(28, ni, n2);
	n3->taille = 3;

	NOEUD *n4 = creerNoeud(16, ni, ni);
	n4->taille = 1;

	NOEUD *n5 = creerNoeud(22, n4, n3);
	n5->taille = 5;

	NOEUD *n6 = creerNoeud(7, ni, ni);
	n6->taille = 1;

	NOEUD *n7 = creerNoeud(15, n6, n5);
	n7->taille = 7;

	ni->p = n1;
	n1->p = n2;
	n2->p = n3;
	n3->p = n5;
	n4->p = n5;
	n5->p = n7;
	n6->p = n7;

	ABR *AR = (ABR *)malloc(sizeof(ABR));
	AR->racine = n7;
	AR->nil = ni;

	afficherArbre(AR, AR->racine);
	printf("\n\n");

	ABR *AREQ = equilibrer(AR);
	afficherArbre(AREQ, AREQ->racine);
	printf("\n\n");

	return 0;
}

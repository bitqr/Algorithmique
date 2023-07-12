#include <stdio.h>
#include <stdlib.h>
#include "ImplementationObjets.h"

int libre = 4;
int L = 7;
int succ[TAILLE] = {-1, 3, -1, 8, 2, 1, 5, 6};
int cle[TAILLE] = {-1, 4, 1, -1, 16, -1, 9, -1};
int pred[TAILLE] = {-1, 5, 2, -1, 7, -1, -1, -1};

int unique[H * TAILLE] = {17, 5, 11, 11, 8, 20, 23, -1, -1, 2, 19, 5, 20, 13, -1, -1, 11, 2, 5, 4, 14, -1, -1, -1};
int L2 = 14;
int libre2 = 8;

void liberer_objet(int x)
{
	succ[x - 1] = libre;
	libre = x;
}

void afficherObjet()
{
	int i;
	printf("libre : %d \nL    : %d\n", libre, L);
	printf("\nsucc:\t");
	for (i = 0; i < TAILLE; i++)
	{
		if (succ[i] != -1)
		{
			printf("%d\t", succ[i]);
		}
		else
		{
			printf("\\\t");
		}
	}
	printf("\ncle:\t");
	for (i = 0; i < TAILLE; i++)
	{
		if (cle[i] != -1)
		{
			printf("%d\t", cle[i]);
		}
		else
		{
			printf("\\\t");
		}
	}
	printf("\npred:\t");
	for (i = 0; i < TAILLE; i++)
	{
		if (pred[i] != -1)
		{
			printf("%d\t", pred[i]);
		}
		else
		{
			printf("\\\t");
		}
	}
	printf("\n\n\n");
}

void afficherObjet2()
{
	int i;
	printf("libre = %d\n", libre2);
	printf("L = %d\n\n", L2);
	for (i = 0; i < H * TAILLE; i++)
		if (unique[i] != -1)
		{
			printf("%d ", unique[i]);
		}
		else
		{
			printf("/ ");
		}
	printf("\n\n");
}

int main(int argc, char **argv)
{
	afficherObjet();
	densifier_liste(pred, cle, succ, &L, &libre);
	int j;
	for (j = libre; j < TAILLE; j++)
	{
		succ[j - 1] = j + 1;
		pred[j - 1] = -1;
	}
	succ[j - 1] = -1;
	pred[j - 1] = -1;
	afficherObjet();

	succ[pred[X - 1] - 1] = succ[X - 1];
	pred[succ[X - 1] - 1] = pred[X - 1];
	cle[X - 1] = -1;
	pred[X - 1] = -1;
	liberer_objet(X);
	afficherObjet();
	int ind = allouer_objet(succ, &libre);
	int ins = 22;
	cle[ind - 1] = ins;
	succ[ind - 1] = L;
	L = ind;
	afficherObjet();

	afficherObjet2();
	int ind2 = allouer_objet_2(unique, &libre2);
	unique[ind2 - 1] = 22;
	unique[ind2 - 2] = L2;
	unique[L2] = ind2;
	L2 = ind2;
	afficherObjet2();
	unique[X - 1] = -1;
	unique[unique[X] - 2] = unique[X - 2];
	unique[unique[X - 2]] = unique[X];
	unique[X] = -1;
	liberer_objet_2(X, unique, &libre2);
	afficherObjet2();
	return 0;
}

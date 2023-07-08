#include <stdio.h>
#include <stdlib.h>
#include "Arborescence.h"

void afficher_arbre(ARBREBINAIRE *A)
{
	if (A != NULL)
	{
		printf("%d\t", A->cle);
		afficher_arbre(A->gauche);
		afficher_arbre(A->droit);
	}
}

ARBREBINAIRE *creerNoeud(int cle, ARBREBINAIRE *g, ARBREBINAIRE *d, ARBREBINAIRE *p)
{
	ARBREBINAIRE *noeud = (ARBREBINAIRE *)malloc(sizeof(ARBREBINAIRE));
	noeud->cle = cle;
	noeud->gauche = g;
	noeud->droit = d;
	noeud->p = p;
	return noeud;
}

ARBRE *creerNoeud2(int cle, ARBRE *fig, ARBRE *frd, ARBRE *p)
{
	ARBRE *noeud = (ARBRE *)malloc(sizeof(ARBRE));
	noeud->cle = cle;
	noeud->filsg = fig;
	noeud->frered = frd;
	noeud->p = p;
	return noeud;
}

int main(int argc, char **argv)
{
	ARBREBINAIRE *A;
	ARBREBINAIRE *A1;
	ARBREBINAIRE *A2;
	ARBREBINAIRE *A11 = creerNoeud(4, NULL, NULL, NULL);
	ARBREBINAIRE *A12 = creerNoeud(18, NULL, NULL, NULL);
	ARBREBINAIRE *A21 = creerNoeud(121, NULL, NULL, NULL);
	ARBREBINAIRE *A22 = creerNoeud(8, NULL, NULL, NULL);
	A1 = creerNoeud(12, A11, A12, NULL);
	A11->p = A1;
	A12->p = A1;
	A2 = creerNoeud(1, A21, A22, NULL);
	A21->p = A2;
	A22->p = A2;
	A = creerNoeud(22, A1, A2, NULL);
	A1->p = A;
	A2->p = A;

	ARBRE *B;
	ARBRE *B1;
	ARBRE *B31 = creerNoeud2(2, NULL, NULL, NULL);
	ARBRE *B32 = creerNoeud2(18, NULL, B31, NULL);
	B31->p = B32;
	ARBRE *B33 = creerNoeud2(4, NULL, B32, NULL);
	B32->p = B33;
	ARBRE *B3 = creerNoeud2(12, B33, NULL, NULL);
	B33->p = B3;

	ARBRE *B2;
	ARBRE *B21 = creerNoeud2(7, NULL, NULL, NULL);
	B2 = creerNoeud2(8, B21, B3, NULL);
	B21->p = B2;
	B3->p = B2;
	ARBRE *B11 = creerNoeud2(3, NULL, NULL, NULL);
	ARBRE *B12 = creerNoeud2(11, NULL, B11, NULL);
	B1 = creerNoeud2(14, B12, B2, NULL);
	B11->p = B12;
	B12->p = B1;
	B2->p = B1;
	B = creerNoeud2(4, B1, NULL, NULL);
	B1->p = B;

	afficher_arbre(A);
	printf("\n");
	afficher_arbre_2(A);
	printf("\n");
	afficher_arbre_3(B);
	printf("\n");
	afficher_arbre_4(A);
	printf("\n");
	return 0;
}

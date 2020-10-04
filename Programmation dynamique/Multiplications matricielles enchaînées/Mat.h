#ifndef DEF_MAT
#define DEF_MAT

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct matrice{
	int lignes;
	int colonnes;
	int **tab;
};

typedef struct matrice MATRICE;

struct dimensions{
	int longueur;
	int *p;
};

typedef struct dimensions DIM;

void affichage_parenthesage_optimal(int **s, int i, int j);
MATRICE * multiplication_chaine_matrices(MATRICE **A, int **s, int i, int j);
MATRICE * multiplier_matrices(MATRICE *A, MATRICE *B);
MATRICE *creerMatrice(int nl, int nc);

#endif


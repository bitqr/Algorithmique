#ifndef DEF_MAT
#define DEF_MAT

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 6
#define INFINI 10000000
#define LIM 10
#define I 0
#define J 3

struct matrice
{
	int lignes;
	int colonnes;
	int **tab;
};

typedef struct matrice MATRICE;

struct dimensions
{
	int longueur;
	int *p;
};

typedef struct dimensions DIM;

void affichage_parenthesage_optimal(int **s, int i, int j);
MATRICE *multiplication_chaine_matrices(MATRICE **A, int **s, int i, int j);
MATRICE *multiplier_matrices(MATRICE *A, MATRICE *B);
MATRICE *creerMatrice(int nl, int nc);
int memorisation_chaine_matrices(DIM *p, int **m);
int recuperer_chaine(DIM *p, int i, int j, int **m);

#endif

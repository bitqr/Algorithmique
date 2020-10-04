#ifndef DEF_ABR
#define DEF_ABR

#include<stdio.h>
#include<stdlib.h>

#define INFINI 1000000
#define N 5
#define N2 7

#define GAUCHE 1
#define DROITE 0

float **creerMatrice(int m, int n);
int **creerMatriceEntiers(int m, int n);
float ** abr_optimal(float *p, float *q, int n, int **racine);
void afficherMatrice(float **e, int m, int n);
void afficherMatriceEntiers(int **e, int m, int n);
void construire_abr_optimal(int **racine, int n);
void construire_abr_recursif(int **racine, int i, int j, int n, int cote);
float ** abr_optimal_efficace(float *p, float *q, int n, int **racine);

#endif

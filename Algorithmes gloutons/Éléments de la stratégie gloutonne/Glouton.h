#ifndef DEF_GL
#define DEF_GL

#include<stdio.h>
#include<stdlib.h>

#define N 10
#define WW 16
#define N2 10
#define N3 5


void permuter(int*A,int i, int j);
int partition(int * A, int p, int r);
void tri_rapide(int*A, int p, int r);
void pre_tri(int *V, int *w , int n);
int partitionReels(double * A, int p, int r);
void permuterReels(double*A,int i, int j);
void tri_rapideReels(double*A, int p, int r);
int * sac_a_dos(int *V, int *w, int W, int n);
double *enveloppe(double *x, int n);
long long int indemnite_produit_maximal(int *A, int *B, int n);

#endif




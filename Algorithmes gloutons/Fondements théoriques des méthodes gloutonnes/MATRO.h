#ifndef DEF_MAT
#define DEF_MAT

#include<stdio.h>
#include<stdlib.h>

#define MAX 70
#define N 10
#define M1 54

struct ensemble{
	int taille;
	int longueur;
	int *elements;
	};

typedef struct ensemble ENSEMBLE;

struct independants{
	int taille;
	int longueur;
	ENSEMBLE **ensembles;
	};

typedef struct independants INDEPENDANTS;

struct matroide{
	ENSEMBLE *E;
	ENSEMBLE *S;
	INDEPENDANTS *I;
	};

typedef struct matroide MATROIDE;


#endif

#ifndef DEF_VDCB
#define DEF_VDCB

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define N 7
#define M 10
#define N2 15
#define M1 9
#define N1 10
#define C_COP 1
#define C_REMP 2
#define C_SUP 3
#define C_INS 3
#define C_PERM 3
#define C_EQ 3
#define NB 17
#define NS 10
#define CHEMIN_INEXISTANT 0
#define NP 5
#define NDAMIER 8
#define RND 10
#define INIT 0
#define HAUT 1
#define HAUT_GAUCHE 2
#define HAUT_DROITE 3
#define NORDO 7
#define INFINI 1000000000

struct point
{
	float x;
	float y;
};

typedef struct point POINT;

struct noeud
{
	struct noeud *p;
	struct noeud *fils_gauche;
	struct noeud *frere_droite;
	char *nom;
	double note;
};

typedef struct noeud NOEUD;

struct arbre
{
	struct noeud *racine;
	struct noeud *nil;
};

typedef struct arbre ARBRE;

struct solution
{
	double cout;
	struct noeud *employe;
};

typedef struct solution SOLUTION;

struct graphe
{
	int nombre_sommets;
	char **aretes;
};

typedef struct graphe GRAPHE;

struct graphe_etendu
{
	int nombre_sommets;
	char **aretes;
	double **p;
};

typedef struct graphe_etendu GRAPHE_ETENDU;

struct carre
{
	double h;
	double hg;
	double hd;
};

typedef struct carre CARRE;

struct choix
{
	int tache;
	int profit;
	int temps;
};

typedef struct choix CHOIX;

void afficher_couts_reels(float **c, int n);
void afficher_couts(int **c, int n, int e);

#endif

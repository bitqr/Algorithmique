#ifndef DEF_PROB
#define DEF_PROB

#include<stdio.h>
#include<stdlib.h>

#define K 6
#define N 7
#define M 10

struct tableau{
	int * tab;
	int longueur;
};

typedef struct tableau TABLEAU;

struct liste_chainee{
	int cle;
	struct liste_chainee *suiv;
	struct liste_chainee *tete;
};

typedef struct liste_chainee LISTE_CHAINEE;

struct arete{
	int a;
	int b;
};

typedef struct arete ARETE;

struct liste_arete{
	ARETE cle;
	struct liste_arete *suiv;
	struct liste_arete *tete;
};

typedef struct liste_arete LISTE_ARETE;

struct graphe_non_oriente{
	int n;
	int m;
	ARETE *arete;
	int *sommet;
};

typedef struct graphe_non_oriente GRAPHE_NO;

struct noeud{
	int cle;
	int occupe;
	struct noeud *p;
};

typedef struct noeud NOEUD;

int * rendu_monnaie(int n);
int * rendu(TABLEAU C, int n);
void permuter(int* A, int i, int j);
int partition_taches(int * A, int *P, int a, int b);
void tri_rapide_taches(int* A, int *P, int a, int b);
int * ordonnancement_taches(int *A, int *P, int n);
LISTE_CHAINEE * ordonnancement_preemptif(int *A, int *P, int *R, int n);
LISTE_CHAINEE *creerElement(int cle);
LISTE_ARETE *creerArete(ARETE ar);
void permuter_arete(ARETE* A, int i, int j);
int partition_arete(ARETE * A, int *w, int a, int b);
void tri_rapide_arete(ARETE* A, int *w, int a, int b);
LISTE_ARETE *acyclique_maximal(GRAPHE_NO *G, int *w);
NOEUD *creerEnsemble(int cle);
void lier(NOEUD *x, NOEUD *y);
NOEUD * trouverEnsemble(NOEUD *x);
void unionEnsemble(NOEUD *x, NOEUD *y);
int * ordonnancement_variante(int *D, int n);

#endif


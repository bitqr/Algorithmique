#ifndef DEF_PLSC
#define DEF_PLSC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LX 9
#define LY 10
#define N 20
#define INFINI 100000

struct sequence {
  int longueur;
  char *table;
  int *entiers;
};

typedef struct sequence SEQUENCE;

#define ROUGE 0
#define NOIR 1

struct noeud {
  int cle;
  int couleur;
  struct noeud *p;
  struct noeud *gauche;
  struct noeud *droite;
};

typedef struct noeud NOEUD;

struct arbreRN {
  NOEUD *racine;
  NOEUD *nil;
};

typedef struct arbreRN ARN;

void imprimer_suite(int *P, SEQUENCE *X, int ind);
int plus_proche_inferieur(SEQUENCE *X, int *M, int e, int f, int c);
int recherche_idoine(ARN *A, int *M, NOEUD *x, SEQUENCE *X, int c);
void pls_croissante_efficace(SEQUENCE *X);
void rotation_gauche(ARN *T, NOEUD *x);
void rotation_droite(ARN *T, NOEUD *x);
void rn_inserer(ARN *T, NOEUD *z);
void rn_inserer_correction(ARN *T, NOEUD *z);
NOEUD *creerNoeudRN(int cle, NOEUD *g, NOEUD *d, int couleur);
ARN *creerARN(NOEUD *racine, NOEUD *nil);
void imprimer_plsc(char **b, SEQUENCE *X, int i, int j);
int recensement(int **c, int i, int j, SEQUENCE *X, SEQUENCE *Y);
int longueur_plsc_recensement(SEQUENCE *X, SEQUENCE *Y);
int **initTables(int n, int m);
char **initSP(int n, int m);
SEQUENCE *creerSequence(int longueur);
int **longueur_plsc(SEQUENCE *X, SEQUENCE *Y, char **b);
void plsc_croissante(SEQUENCE *X);
void initSequenceEntiers(SEQUENCE *S, int *C, int n);
void tri_fusion(int *A, int p, int r);
void fusion(int *A, int p, int q, int r);
void afficherTables(int **A, int n, int m);
int **longueurPlscEntiers(SEQUENCE *X, SEQUENCE *Y, char **b);
void imprimerPlscEntiers(char **b, SEQUENCE *X, int i, int j);

#endif

#ifndef DEF_B_ARBRE
#define DEF_B_ARBRE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define K 45
#define VRAI 1
#define FAUX 0
#define NIL NULL
#define t 2

struct noeud_B_arbre{
	int n;
	int *cle;
	int feuille;
	struct noeud_B_arbre **c;
};

typedef struct noeud_B_arbre NOEUD_B_ARBRE;

struct couple{
	NOEUD_B_ARBRE *y;
	int i;	
};

typedef struct couple COUPLE;

struct B_arbre{
	NOEUD_B_ARBRE *racine;
};

typedef struct B_arbre B_ARBRE;

COUPLE *rechercher_B_arbre(NOEUD_B_ARBRE *x, int k);
void lireDisque(NOEUD_B_ARBRE *x);
void ecrireDisque(NOEUD_B_ARBRE *x);
void supprimer_B_arbre(B_ARBRE *T, int k);
void supprimer_B_arbre_incomplet(NOEUD_B_ARBRE *x, int k);
int cle_maximale(NOEUD_B_ARBRE *x);
int cle_minimale(NOEUD_B_ARBRE *x);
void fusionner(NOEUD_B_ARBRE *x, int i, NOEUD_B_ARBRE *y, NOEUD_B_ARBRE *z);
void echanger_frere(NOEUD_B_ARBRE *x, int i, NOEUD_B_ARBRE *z, NOEUD_B_ARBRE *y);

#endif


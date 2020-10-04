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
void creer_B_arbre(B_ARBRE *T);
NOEUD_B_ARBRE *allouerNoeud();
void ecrireDisque(NOEUD_B_ARBRE *x);
void partager_enfant_B_arbre(NOEUD_B_ARBRE *x, int i, NOEUD_B_ARBRE *y);
void inserer_B_arbre(B_ARBRE *T, int k);
void inserer_B_arbre_incomplet(NOEUD_B_ARBRE *x, int k);
int minimum_B_arbre(B_ARBRE *T);
int predecesseur_B_arbre(B_ARBRE *T, int k);

#endif


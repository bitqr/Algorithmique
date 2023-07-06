#ifndef DEF_AVL
#define DEF_AVL

#include <stdio.h>
#include <stdlib.h>

struct noeud
{
	int cle;
	int h;
	struct noeud *p;
	struct noeud *gauche;
	struct noeud *droite;
};

typedef struct noeud NOEUD;

struct arbreAVL
{
	NOEUD *racine;
	NOEUD *nil;
};

typedef struct arbreAVL AVL;

NOEUD *creerNoeudAVL(int cle, int h, NOEUD *g, NOEUD *d);
int max(int a, int b);
void avl_inserer(AVL *T, NOEUD *x, NOEUD *z);
void equilibre(AVL *T, NOEUD *x);

#endif

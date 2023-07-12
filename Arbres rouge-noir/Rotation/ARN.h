#ifndef DEF_RN
#define DEF_RN

#include <stdio.h>
#include <stdlib.h>

struct noeud
{
	int cle;
	int couleur;
	struct noeud *p;
	struct noeud *gauche;
	struct noeud *droite;
};

typedef struct noeud NOEUD;

struct arbreRN
{
	NOEUD *racine;
	NOEUD *nil;
};

typedef struct arbreRN ARN;

void rotation_gauche(ARN *T, NOEUD *x);
void rotation_droite(ARN *T, NOEUD *x);
NOEUD *creerNoeud(int cle, NOEUD *g, NOEUD *d);
ARN *creerARN(NOEUD *racine, NOEUD *nil);
void parcoursInfixe(NOEUD *x);

#endif

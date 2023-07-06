#ifndef DEF_AP
#define DEF_AP

#include <stdio.h>
#include <stdlib.h>

struct noeud
{
	int cle;
	struct noeud *gauche;
	struct noeud *droite;
};

typedef struct noeud NOEUD;

struct arbreP
{
	NOEUD *racine;
	NOEUD *nil;
};

typedef struct arbreP ABRP;

NOEUD *creerNoeudABRP(int cle, NOEUD *g, NOEUD *d);
ABRP *creerABRP(NOEUD *racine, NOEUD *nil);
void parcoursPrefixeABRP(NOEUD *x, NOEUD *nl);

#endif

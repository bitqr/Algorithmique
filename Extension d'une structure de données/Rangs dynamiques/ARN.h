#ifndef DEF_RN
#define DEF_RN

#include <stdio.h>
#include <stdlib.h>

#define ROUGE 0
#define NOIR 1

struct noeud
{
	int cle;
	int couleur;
	int taille;
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

struct noeudpoint
{
	float cle;
	int couleur;
	int etiquette;
	int taille;
	int doublon;
	struct noeudpoint *p;
	struct noeudpoint *gauche;
	struct noeudpoint *droite;
	struct noeudpoint *jumeau;
};

typedef struct noeudpoint NOEUDPOINT;

struct arbreRNP
{
	NOEUDPOINT *racine;
	NOEUDPOINT *nil;
};

typedef struct arbreRNP ARNP;

int determiner_rang(ARN *T, NOEUD *x);
NOEUD *recuperer_rang_iteratif(NOEUD *x, int i);
int rechercher_rang_cle(NOEUD *x, int k);

#endif

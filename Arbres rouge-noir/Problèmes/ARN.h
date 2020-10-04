#ifndef DEF_RN
#define DEF_RN

#include<stdio.h>
#include<stdlib.h>

#define ROUGE 0
#define NOIR 1

struct noeud{
	int cle;
	int couleur;
	struct noeud *p;
	struct noeud *gauche;
	struct noeud *droite;
};

typedef struct noeud NOEUD;	

struct arbreRN{
	NOEUD *racine;
	NOEUD *nil;
	int hn;
};

typedef struct arbreRN ARN;

NOEUD * creerNoeudRN(int cle, NOEUD *g, NOEUD *d,int couleur);

#endif


#ifndef DEF_AT
#define DEF_AT

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct noeud{
	int cle;
	int priorite;
	struct noeud *p;
	struct noeud *gauche;
	struct noeud *droite;
	};

typedef struct noeud NOEUD;	

struct arbreTas{
	NOEUD *racine;
	NOEUD *nil;
	};

typedef struct arbreTas ARBRETAS;


NOEUD * creerNoeudARBRETAS(int cle, int priorite, NOEUD *g, NOEUD *d);

#endif





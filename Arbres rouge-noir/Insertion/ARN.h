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
	};

typedef struct arbreRN ARN;



void rotation_gauche(ARN *T, NOEUD *x);
void rotation_droite(ARN *T, NOEUD *x);
void rn_inserer(ARN *T, NOEUD *z);
void rn_inserer_correction(ARN *T, NOEUD *z);
NOEUD * creerNoeudRN(int cle, NOEUD *g, NOEUD *d,int couleur);
ARN * creerARN(NOEUD *racine, NOEUD *nil);
void parcoursPrefixeRN(NOEUD *x, NOEUD *nl);

#endif





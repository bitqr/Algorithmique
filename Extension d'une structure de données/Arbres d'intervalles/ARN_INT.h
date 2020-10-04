#ifndef DEF_RN
#define DEF_RN

#include<stdio.h>
#include<stdlib.h>

#define ROUGE 0
#define NOIR 1
#define INFINI 100000
#define MINFINI -100000

struct intervalle{
	int debut;
	int fin;
};
	
typedef struct intervalle INTERVALLE;

struct noeud{
	int cle;
	int couleur;
	int max;
	INTERVALLE *Int;
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

struct rectangle{
	int minx, miny, maxx, maxy;
};

typedef struct rectangle RECTANGLE;

struct noeud_vlsi{
	int cle;
	int couleur;
	int max;
	INTERVALLE *intx;
	INTERVALLE *inty;
	struct noeud_vlsi *p;
	struct noeud_vlsi *gauche;
	struct noeud_vlsi *droite;
	RECTANGLE *rect;
};

typedef struct noeud_vlsi NOEUD_VLSI;	

struct arbreRN_VLSI{
	NOEUD_VLSI *racine;
	NOEUD_VLSI *nil;
};

typedef struct arbreRN_VLSI ARN_VLSI;

void rotation_gauche(ARN *T, NOEUD *x);
NOEUD *rechercher_intervalle_ouvert(ARN *T, INTERVALLE *i);
NOEUD *rechercher_intervalle_avant(ARN *T, INTERVALLE *i);
INTERVALLE *creeInt(int debut, int fin);

#endif


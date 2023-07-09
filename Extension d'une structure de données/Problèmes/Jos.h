#ifndef DEF_JS
#define DEF_JS

#include <stdio.h>
#include <stdlib.h>

struct Liste_Doublement_Chaine_Circulaire
{
	int cle;
	struct Liste_Doublement_Chaine_Circulaire *suiv;
	struct Liste_Doublement_Chaine_Circulaire *pred;
	struct Liste_Doublement_Chaine_Circulaire *tete;
};

typedef struct Liste_Doublement_Chaine_Circulaire LDCC;

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

int *josephus_efficace(int n, int m);
NOEUD *recuperer_rang(NOEUD *x, int i);
NOEUD *creerNoeudRN(int cle, NOEUD *g, NOEUD *d, int couleur);
ARN *creerARN(NOEUD *racine, NOEUD *nil);
void rotation_gauche(ARN *T, NOEUD *x);
void rotation_droite(ARN *T, NOEUD *x);
void rn_inserer_correction(ARN *T, NOEUD *z);
void rn_inserer(ARN *T, NOEUD *z);
void rn_supprimer_correction(ARN *T, NOEUD *x);
NOEUD *arbre_minimum(NOEUD *x, NOEUD *nl);
NOEUD *arbre_successeur(NOEUD *x, NOEUD *nl);
NOEUD *rn_supprimer(ARN *T, NOEUD *z);

#endif

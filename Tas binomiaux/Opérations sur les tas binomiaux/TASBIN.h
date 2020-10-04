#ifndef TASBIN
#define TASBIN

#define NIL NULL
#define INFINI 1000000

#include<stdio.h>
#include<stdlib.h>

struct noeud_tas_binomial{
	int cle;
	struct noeud_tas_binomial *frere;
	struct noeud_tas_binomial *p;
	struct noeud_tas_binomial *enfant;
	int degre;
};

typedef struct noeud_tas_binomial NOEUD_TAS_BINOMIAL;

struct tas_binomial{
	struct noeud_tas_binomial *tete;
};

typedef struct tas_binomial TAS_BINOMIAL;

NOEUD_TAS_BINOMIAL *minimum_tas_binomial(TAS_BINOMIAL *T);
void lien_binomial(NOEUD_TAS_BINOMIAL *y, NOEUD_TAS_BINOMIAL *z);
void afficherArbreBinomial(NOEUD_TAS_BINOMIAL *x, int profondeur);
TAS_BINOMIAL *creer_tas_binomial();
NOEUD_TAS_BINOMIAL *fusionner_tas_binomiaux(TAS_BINOMIAL *T1, TAS_BINOMIAL *T2);
TAS_BINOMIAL *union_tas_binomiaux(TAS_BINOMIAL *T1, TAS_BINOMIAL *T2);
NOEUD_TAS_BINOMIAL *creerNoeudTasBinomial(int cle, NOEUD_TAS_BINOMIAL *parent, NOEUD_TAS_BINOMIAL *fils, int degre, NOEUD_TAS_BINOMIAL *frere);
void afficherTasBinomial(TAS_BINOMIAL *T);
void tas_binomial_inserer(TAS_BINOMIAL **T, NOEUD_TAS_BINOMIAL *x);
NOEUD_TAS_BINOMIAL *tas_binomial_extraire_min(TAS_BINOMIAL **T);
void tas_binomial_diminuer_cle(TAS_BINOMIAL *T, NOEUD_TAS_BINOMIAL *x, int k);
void tas_binomial_supprimer(TAS_BINOMIAL **T, NOEUD_TAS_BINOMIAL *x);
NOEUD_TAS_BINOMIAL *minimum_tas_binomial_avec_infini(TAS_BINOMIAL *T);
void tas_binomial_supprimer_sans_infini(TAS_BINOMIAL **T, NOEUD_TAS_BINOMIAL *x);
void tas_binomial_inserer_direct(TAS_BINOMIAL *T, NOEUD_TAS_BINOMIAL *x);

#endif



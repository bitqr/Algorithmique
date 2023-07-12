#ifndef DEF_TAS_2_3_4
#define DEF_TAS_2_3_4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VRAI 1
#define FAUX 0
#define NIL NULL
#define CLEDIMINUEE 4

struct noeud_tas_2_3_4
{
	int n;
	int cle;
	int petit;
	int feuille;
	int hauteur;
	struct noeud_tas_2_3_4 *p;
	struct noeud_tas_2_3_4 **c;
};

typedef struct noeud_tas_2_3_4 NOEUD_TAS_2_3_4;

struct tas_2_3_4
{
	NOEUD_TAS_2_3_4 *racine;
};

typedef struct tas_2_3_4 TAS_2_3_4;

struct arete
{
	int u;
	int v;
	double w;
};

typedef struct arete ARETE;

struct graphe
{
	int n;
	int m;
	ARETE *aretes;
	int **incidentes;
	int *degres;
};

typedef struct graphe GRAPHE;

struct noeud_tas_binomial
{
	int cle;
	struct noeud_tas_binomial *frere;
	struct noeud_tas_binomial *p;
	struct noeud_tas_binomial *enfant;
	int degre;
};

typedef struct noeud_tas_binomial NOEUD_TAS_BINOMIAL;

struct tas_binomial
{
	struct noeud_tas_binomial *tete;
};

typedef struct tas_binomial TAS_BINOMIAL;

struct noeud_tas_binomial_arete
{
	double cle;
	ARETE arete;
	struct noeud_tas_binomial_arete *frere;
	struct noeud_tas_binomial_arete *p;
	struct noeud_tas_binomial_arete *enfant;
	int degre;
};

typedef struct noeud_tas_binomial_arete NOEUD_TAS_BINOMIAL_ARETE;

struct tas_binomial_aretes
{
	struct noeud_tas_binomial_arete *tete;
};

typedef struct tas_binomial_aretes TAS_BINOMIAL_ARETES;

NOEUD_TAS_2_3_4 *minimum(TAS_2_3_4 *T);
void afficherTas234(TAS_2_3_4 *T);
void afficherNoeudTas234(NOEUD_TAS_2_3_4 *x, int profondeur);
void diminuer_cle(TAS_2_3_4 *T, NOEUD_TAS_2_3_4 *x, int k);
void inserer(TAS_2_3_4 *T, int k);
NOEUD_TAS_2_3_4 *allouerNoeud();
void partager(NOEUD_TAS_2_3_4 *x);
void inserer_incomplet(NOEUD_TAS_2_3_4 *x, int k);
void supprimer(TAS_2_3_4 *T, NOEUD_TAS_2_3_4 *x);
void supprimer_interne(TAS_2_3_4 *T, NOEUD_TAS_2_3_4 *x);
NOEUD_TAS_2_3_4 *extraire_min(TAS_2_3_4 *T);
TAS_2_3_4 *union_tas_2_3_4(TAS_2_3_4 *T1, TAS_2_3_4 *T2);
void union_incomplet(NOEUD_TAS_2_3_4 *x1, NOEUD_TAS_2_3_4 *x2, int h);
TAS_BINOMIAL *creer_tas_binomial();
TAS_BINOMIAL_ARETES *creerTasBinomialAretes();
NOEUD_TAS_BINOMIAL *fusionner_tas_binomiaux(TAS_BINOMIAL *T1, TAS_BINOMIAL *T2);
NOEUD_TAS_BINOMIAL_ARETE *fusionnerTasBinomiauxAretes(TAS_BINOMIAL_ARETES *T1, TAS_BINOMIAL_ARETES *T2);
void lien_binomial(NOEUD_TAS_BINOMIAL *y, NOEUD_TAS_BINOMIAL *z);
void lienBinomial(NOEUD_TAS_BINOMIAL_ARETE *y, NOEUD_TAS_BINOMIAL_ARETE *z);
TAS_BINOMIAL *union_tas_binomiaux(TAS_BINOMIAL *T1, TAS_BINOMIAL *T2);
TAS_BINOMIAL_ARETES *unionTasBinomiauxAretes(TAS_BINOMIAL_ARETES *T1, TAS_BINOMIAL_ARETES *T2);
void tas_binomial_inserer(TAS_BINOMIAL **T, NOEUD_TAS_BINOMIAL *x);
void insererTasBinomialAretes(TAS_BINOMIAL_ARETES **T, NOEUD_TAS_BINOMIAL_ARETE *x);
NOEUD_TAS_BINOMIAL_ARETE *tasBinomialAretesExtraireMin(TAS_BINOMIAL_ARETES **T);
void afficherGraphe(GRAPHE *G);
ARETE *ACM(GRAPHE *G);

#endif

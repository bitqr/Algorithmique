#ifndef TASFIB
#define TASFIB

#define NIL NULL
#define FAUX 0
#define VRAI 1

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct noeud_tas_fibonacci
{
	struct noeud_tas_fibonacci *p;
	struct noeud_tas_fibonacci *gauche;
	struct noeud_tas_fibonacci *droite;
	int degre;
	int marque;
	struct noeud_tas_fibonacci *enfant;
	int cle;
};

typedef struct noeud_tas_fibonacci NOEUD_TAS_FIBONACCI;

struct tas_fibonacci
{
	struct noeud_tas_fibonacci *min;
	int n;
};

typedef struct tas_fibonacci TAS_FIBONACCI;

int afficherArbreTasFibonacci(NOEUD_TAS_FIBONACCI *x, int profondeur);
void afficherTasFibonacci(TAS_FIBONACCI *T);
void ajouterListeRacines(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x);
void concatenerListes(NOEUD_TAS_FIBONACCI *x, NOEUD_TAS_FIBONACCI *r);
void consolider(TAS_FIBONACCI *T);
NOEUD_TAS_FIBONACCI *creerNoeudTasFibonacci(int cle, NOEUD_TAS_FIBONACCI *enfant, NOEUD_TAS_FIBONACCI *pere, NOEUD_TAS_FIBONACCI *g, NOEUD_TAS_FIBONACCI *d, int m, int dg);
TAS_FIBONACCI *creer_tas_fib();
NOEUD_TAS_FIBONACCI *extraire_min_tas_fib(TAS_FIBONACCI *T);
void inserer_tas_fib(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x);
void permuter(NOEUD_TAS_FIBONACCI **x, NOEUD_TAS_FIBONACCI **y);
void relier_tas_fib(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *y, NOEUD_TAS_FIBONACCI *x);
void supprimerRacine(NOEUD_TAS_FIBONACCI *x);
TAS_FIBONACCI *union_tas_fib(TAS_FIBONACCI *T1, TAS_FIBONACCI *T2);

#endif

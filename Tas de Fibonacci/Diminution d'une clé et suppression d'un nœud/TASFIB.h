#ifndef TASFIB
#define TASFIB

#define NIL NULL
#define FAUX 0
#define VRAI 1
#define INFINI 1000000

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

void diminuer_cle_tas_fib(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x, int k);
void couper(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x, NOEUD_TAS_FIBONACCI *y);
void supprimerEnfant(NOEUD_TAS_FIBONACCI *x, NOEUD_TAS_FIBONACCI *y);
void ajouterListeRacines(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x);
void coupe_en_cascade(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *y);
NOEUD_TAS_FIBONACCI *creerNoeudTasFibonacci(int cle, NOEUD_TAS_FIBONACCI *enfant, NOEUD_TAS_FIBONACCI *pere, NOEUD_TAS_FIBONACCI *g, NOEUD_TAS_FIBONACCI *d, int m, int dg);
int afficherArbreTasFibonacci(NOEUD_TAS_FIBONACCI *x, int profondeur);
void afficherTasFibonacci(TAS_FIBONACCI *T);
void supprimer_tas_fib(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x);
NOEUD_TAS_FIBONACCI *extraire_min_tas_fib(TAS_FIBONACCI *T);
void supprimerRacine(NOEUD_TAS_FIBONACCI *x);
void concatenerListes(NOEUD_TAS_FIBONACCI *x, NOEUD_TAS_FIBONACCI *r);
void consolider(TAS_FIBONACCI *T);
void permuter(NOEUD_TAS_FIBONACCI **x, NOEUD_TAS_FIBONACCI **y);
void relier_tas_fib(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *y, NOEUD_TAS_FIBONACCI *x);
void ajouterNoeudListeRacines(NOEUD_TAS_FIBONACCI *x, NOEUD_TAS_FIBONACCI *r);

#endif

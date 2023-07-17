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

struct noeud_tas_fibonacci_pour_elagage
{
	struct noeud_tas_fibonacci_pour_elagage *p;
	struct noeud_tas_fibonacci_pour_elagage *gauche;
	struct noeud_tas_fibonacci_pour_elagage *droite;
	int degre;
	int marque;
	struct noeud_tas_fibonacci_pour_elagage *enfant;
	struct noeud_tas_fibonacci_pour_elagage *fg;
	struct noeud_tas_fibonacci_pour_elagage *fd;
	int cle;
};

typedef struct noeud_tas_fibonacci_pour_elagage NOEUD_TAS_FIBONACCI_POUR_ELAGAGE;

struct tas_fibonacci
{
	struct noeud_tas_fibonacci *min;
	int n;
};

typedef struct tas_fibonacci TAS_FIBONACCI;

struct tas_fibonacci_pour_elagage
{
	struct noeud_tas_fibonacci_pour_elagage *min;
	struct noeud_tas_fibonacci_pour_elagage *feuilles;
	int n;
};

typedef struct tas_fibonacci_pour_elagage TAS_FIBONACCI_POUR_ELAGAGE;

int afficherArbreTasFibonacci(NOEUD_TAS_FIBONACCI *x, int profondeur);
int afficherArbreTasFibonacciPourElagage(NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *x, int profondeur);
void afficherTasFibonacci(TAS_FIBONACCI *T);
void afficherTasFibonacciPourElagage(TAS_FIBONACCI_POUR_ELAGAGE *T);
void ajouterEnfantsAuxRacines(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x);
void ajouterFeuillePourElagage(TAS_FIBONACCI_POUR_ELAGAGE *T, NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *x);
void ajouterListeRacines(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x);
void concatenerListes(NOEUD_TAS_FIBONACCI *x, NOEUD_TAS_FIBONACCI *r);
void consolider(TAS_FIBONACCI *T);
void coupe_en_cascade(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *y);
void couper(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x, NOEUD_TAS_FIBONACCI *y);
NOEUD_TAS_FIBONACCI *creerNoeudTasFibonacci(int cle, NOEUD_TAS_FIBONACCI *enfant, NOEUD_TAS_FIBONACCI *pere, NOEUD_TAS_FIBONACCI *g, NOEUD_TAS_FIBONACCI *d, int m, int dg);
NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *creerNoeudTasFibonacciPourElagage(int cle, NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *enfant, NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *pere, NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *g, NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *d, int m, int dg, NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *fg, NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *fd);
void diminuer_cle_tas_fib(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x, int k);
void elaguer_tas_fib(TAS_FIBONACCI_POUR_ELAGAGE *T, int r);
NOEUD_TAS_FIBONACCI *extraire_min_tas_fib(TAS_FIBONACCI *T);
void permuter(NOEUD_TAS_FIBONACCI **x, NOEUD_TAS_FIBONACCI **y);
void relier_tas_fib(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *y, NOEUD_TAS_FIBONACCI *x);
void supprimer_pisano(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x);
void supprimerEnfant(NOEUD_TAS_FIBONACCI *x, NOEUD_TAS_FIBONACCI *y);
void supprimerEnfantPourElagage(NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *x, NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *y);
void supprimerFeuillePourElagage(TAS_FIBONACCI_POUR_ELAGAGE *T, NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *x);
void supprimerRacine(NOEUD_TAS_FIBONACCI *x);
void supprimerRacinePourElagage(NOEUD_TAS_FIBONACCI_POUR_ELAGAGE *x);
void supprimerRacinePisano(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x);
void tas_fib_modifier_cle(TAS_FIBONACCI *T, NOEUD_TAS_FIBONACCI *x, int k);

#endif

#ifndef PROB
#define PROB

#define K 4
#define L 1000
#define NIL -1
#define NINS 20
#define NSUPP 5

typedef struct
{
	unsigned int longueur;
	int *val;
} TABLEAU;

typedef struct
{
	unsigned int longueur;
	unsigned int tailleBinaire;
	int *representationBinaire;
	int **val;
} TABLEAUDICHOTOMIQUEDYNAMIQUE;

struct noeud
{
	int cle;
	int taille;
	struct noeud *p;
	struct noeud *gauche;
	struct noeud *droit;
};

typedef struct noeud NOEUD;

typedef struct
{
	NOEUD *racine;
	NOEUD *nil;
} ABR;

int rev(int k, int a);
int *permutation_miroir(int *A, int k);
void afficherTableau(int *A, int n);
int *creerTableau(int n, int limite);
void incrementer_miroir(TABLEAU *A);
TABLEAU *inventerTableau(unsigned int l);
void ecrireTableau(TABLEAU *A);
TABLEAUDICHOTOMIQUEDYNAMIQUE *creerTableauDichotomiqueDynamiqueVide();
int rechercher(TABLEAUDICHOTOMIQUEDYNAMIQUE *A, int x);
void afficherTableauDichotomiqueDynamique(TABLEAUDICHOTOMIQUEDYNAMIQUE *A);
void inserer(TABLEAUDICHOTOMIQUEDYNAMIQUE *A, int x);
void supprimer(TABLEAUDICHOTOMIQUEDYNAMIQUE *A, int x);
NOEUD *minimum(ABR *A, NOEUD *x);
NOEUD *successeur(ABR *A, NOEUD *x);
ABR *construire_arbre(NOEUD **T, int a, int b);
ABR *equilibrer(ABR *A);
void afficherArbre(ABR *A, NOEUD *x);
NOEUD *creerNoeud(int cle, NOEUD *g, NOEUD *d);

#endif

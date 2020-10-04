#ifndef DEF_HUFF
#define DEF_HUFF

#include<stdio.h>
#include<stdlib.h>

#define INFINI 1000000
#define LG 12

struct noeud{
	int f;
	struct noeud * gauche;
	struct noeud * droite;
};

typedef struct noeud NOEUD;

struct file_priorite {
	int longueur;
	int taille ;
	NOEUD ** tableau;
};
       
typedef struct file_priorite FILE_DE_PRIORITE;

struct noeud_ternaire{
	int f;
	struct noeud_ternaire * gauche;
	struct noeud_ternaire * centre;
	struct noeud_ternaire * droite;
};

typedef struct noeud_ternaire NOEUD_TERNAIRE;

struct file_priorite_ternaire {
	int longueur;
	int taille ;
	NOEUD_TERNAIRE ** tableau;
};
       
typedef struct file_priorite_ternaire FILE_DE_PRIORITE_TERNAIRE;

NOEUD * extraire_min(FILE_DE_PRIORITE * fp);
void entasser_min(FILE_DE_PRIORITE * fp, int i);
int gauche(int i);
int droite(int i);
void echanger(NOEUD ** A, int a, int b);
void inserer(FILE_DE_PRIORITE * fp, NOEUD * x);
void diminuer_cle_tas(FILE_DE_PRIORITE * fp, int i, NOEUD * x);
int parent(int i);
FILE_DE_PRIORITE * creer_tas(int longueur, int taille);
NOEUD * allouerNoeud();
NOEUD_TERNAIRE * allouerNoeudTernaire();
FILE_DE_PRIORITE_TERNAIRE * creerTasTernaire(int longueur, int taille);
void echangerTernaire(NOEUD_TERNAIRE ** A, int a, int b);
void diminuerCleTasTernaire(FILE_DE_PRIORITE_TERNAIRE * fp, int i, NOEUD_TERNAIRE * x);
void insererTernaire(FILE_DE_PRIORITE_TERNAIRE * fp, NOEUD_TERNAIRE * x);
void entasserMinTernaire(FILE_DE_PRIORITE_TERNAIRE * fp, int i);
NOEUD_TERNAIRE * extraireMinTernaire(FILE_DE_PRIORITE_TERNAIRE * fp);
void affichagePrefixeTernaire(NOEUD_TERNAIRE *z);
NOEUD_TERNAIRE * Huffman_ternaire(FILE_DE_PRIORITE_TERNAIRE * C);

#endif


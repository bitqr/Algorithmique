#ifndef DEUX
#define DEUX

#include<stdio.h>
#include<stdlib.h>

#define N 8

struct PILE{
    int taille;
    int sommet;
    int *tableau;
};

typedef struct PILE PILE;

struct FILEDEUXPILES{
	PILE *p;
	PILE *q;
	int longueur;
};

typedef struct FILEDEUXPILES FILEDEUXPILES;

PILE *creer_pile(int taille);
FILEDEUXPILES *creer_file_deux_piles(int longueur);
void empiler(PILE *P,int x);
void enfiler_deux_piles(FILEDEUXPILES *F, int x);
void afficher_file_deux_piles(FILEDEUXPILES *F);
int pile_vide(PILE *P);
int depiler(PILE *P);
int defiler_deux_piles(FILEDEUXPILES *F);

#endif


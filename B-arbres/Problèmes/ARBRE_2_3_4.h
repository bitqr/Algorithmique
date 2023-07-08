#ifndef DEF_ARBRE_2_3_4
#define DEF_ARBRE_2_3_4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VRAI 1
#define FAUX 0
#define NIL NULL
#define K 60

struct noeud_arbre_2_3_4 {
  int n;
  int *cle;
  int feuille;
  int hauteur;
  struct noeud_arbre_2_3_4 **c;
};

typedef struct noeud_arbre_2_3_4 NOEUD_ARBRE_2_3_4;

struct couple {
  NOEUD_ARBRE_2_3_4 *y;
  int i;
};

typedef struct couple COUPLE;

struct arbre_2_3_4 {
  NOEUD_ARBRE_2_3_4 *racine;
};

typedef struct arbre_2_3_4 ARBRE_2_3_4;

struct couple_arbres_apres_scission {
  ARBRE_2_3_4 *arbre1;
  ARBRE_2_3_4 *arbre2;
};

typedef struct couple_arbres_apres_scission COUPLE_ARBRES_APRES_SCISSION;

struct pile {
  int taille;
  int sommet;
  int *tableau;
};

typedef struct pile PILE;

struct pile_arbre_2_3_4 {
  int taille;
  int sommet;
  ARBRE_2_3_4 **tableau;
};

typedef struct pile_arbre_2_3_4 PILE_ARBRE_2_3_4;

void lireDisque(NOEUD_ARBRE_2_3_4 *x);
NOEUD_ARBRE_2_3_4 *allouerNoeud();
void ecrireDisque(NOEUD_ARBRE_2_3_4 *x);
COUPLE *rechercher_arbre_2_3_4_avec_hauteur(NOEUD_ARBRE_2_3_4 *x, int k);
void inserer_arbre_2_3_4_avec_hauteur(ARBRE_2_3_4 *T, int k);
void partager_enfant_arbre_2_3_4_avec_hauteur(NOEUD_ARBRE_2_3_4 *x, int i,
                                              NOEUD_ARBRE_2_3_4 *y);
void inserer_arbre_2_3_4_avec_hauteur_incomplet(NOEUD_ARBRE_2_3_4 *x, int k);
void supprimer_arbre_2_3_4_avec_hauteur(ARBRE_2_3_4 *T, int k);
int supprimer_cle_maximale_arbre_2_3_4_avec_hauteur(NOEUD_ARBRE_2_3_4 *x);
void supprimer_arbre_2_3_4_avec_frere_gauche(NOEUD_ARBRE_2_3_4 *x, int j);
void supprimer_arbre_2_3_4_fusion_frere_gauche_incomplet(NOEUD_ARBRE_2_3_4 *x,
                                                         int j);
int supprimer_cle_minimale_arbre_2_3_4_avec_hauteur(NOEUD_ARBRE_2_3_4 *x);
void supprimer_arbre_2_3_4_avec_frere_droit(NOEUD_ARBRE_2_3_4 *x, int j);
void supprimer_arbre_2_3_4_fusion_frere_droit_incomplet(NOEUD_ARBRE_2_3_4 *x,
                                                        int j);
void supprimer_arbre_2_3_4_fusion_frere_gauche(ARBRE_2_3_4 *T, int j);
void supprimer_arbre_2_3_4_fusion_frere_droit(ARBRE_2_3_4 *T, int j);
void supprimer_arbre_2_3_4_avec_hauteur_incomplet(NOEUD_ARBRE_2_3_4 *x, int k);
ARBRE_2_3_4 *jointure_arbres_2_3_4(ARBRE_2_3_4 *T1, int k, ARBRE_2_3_4 *T2);
void inserer_hauteur(int k, ARBRE_2_3_4 *T1, int h, ARBRE_2_3_4 *T2);
void inserer_hauteur_incomplet(int k, NOEUD_ARBRE_2_3_4 *x1, int h,
                               NOEUD_ARBRE_2_3_4 *x2);
COUPLE_ARBRES_APRES_SCISSION scission_arbre_2_3_4(ARBRE_2_3_4 *T, int k);
ARBRE_2_3_4 *creer_arbre_2_3_4();
PILE *creerPile(int taille);
PILE_ARBRE_2_3_4 *creerPileArbre234(int taille);
void partager_avec_chemin(NOEUD_ARBRE_2_3_4 *x, int k, PILE *K1,
                          PILE_ARBRE_2_3_4 *T1, PILE *K2, PILE_ARBRE_2_3_4 *T2);
void empilerArbre234(PILE_ARBRE_2_3_4 *P, ARBRE_2_3_4 *T);
void empiler(PILE *P, int k);
int pileVideArbre234(PILE_ARBRE_2_3_4 *P);
int pileVide(PILE *P);
ARBRE_2_3_4 *depilerArbre234(PILE_ARBRE_2_3_4 *P);
int depiler(PILE *P);

#endif

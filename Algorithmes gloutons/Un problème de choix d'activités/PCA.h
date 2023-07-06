#ifndef DEF_PCA
#define DEF_PCA

#include <stdio.h>
#include <stdlib.h>

#define N 11
#define INFINI 65000

struct file
{
    int longueur;
    int tete;
    int queue;
    int *tableau;
};

typedef struct file FILES;

struct tableau
{
    int longueur;
    int *valeurs;
};

typedef struct tableau TABLEAU;

FILES *creer_file_vide(int taille);
void afficher_file(FILES *F);
FILES *enfiler(FILES *F, int x);
FILES *choix_d_activites_recursif(int *s, int *f, int i, int n);
FILES *choix_d_activites_glouton(TABLEAU *s, TABLEAU *f);
int **creerMatriceEntiers(int m, int n);
int choix_dynamique(int *s, int *f, int n);
int *coloration_salles(int *s, int *f, int n);

#endif

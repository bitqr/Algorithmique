#include <stdio.h>
#include <stdlib.h>
#define N1 10

typedef struct tas
{
    int longueur; /* limite sous laquelle le tableau peut contenir des nombres valides */
    int taille;   /* limite des nombres compris dans le tas */
    int *tableau; /* tableau contenant les éléments du tas */
} TAS;

typedef TAS *P_TAS;

int maximum_tas(P_TAS t)
{
    return t->tableau[0];
}

P_TAS creer_tas(int longueur, int taille)
{
    P_TAS t = (P_TAS)malloc(sizeof(TAS));
    t->longueur = longueur;
    t->taille = taille;
    int *tab = (int *)malloc(longueur * sizeof(int));
    t->tableau = tab;
    return t;
}

int main()
{
    P_TAS tas = creer_tas(N1, N1);
    int tab[N1] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    tas->tableau = tab;
    printf("Le maximum du tas est %d\n\n", maximum_tas(tas));
    free(tas);
    return 0;
}

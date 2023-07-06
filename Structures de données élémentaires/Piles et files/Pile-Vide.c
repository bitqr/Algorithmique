#include <stdio.h>
#include <stdlib.h>
#define N 8

struct PILE
{
    int taille;
    int sommet;
    int *tableau;
};

typedef struct PILE PILE;

PILE *creer_pile(int taille)
{
    PILE *P = (PILE *)malloc(sizeof(PILE));
    int *t = (int *)malloc(taille * sizeof(int));
    P->sommet = -1;
    P->taille = taille;
    P->tableau = t;
    return P;
}

int pile_vide(PILE *P)
{
    return (P->sommet == -1);
}

int main(int agrc, char **argv)
{
    PILE *P = creer_pile(N);
    if (pile_vide(P))
        printf("La pile est vide\n\n");
    else
        printf("La pile n'est ps vide\n\n");
    free(P->tableau);
    free(P);
    return 0;
}

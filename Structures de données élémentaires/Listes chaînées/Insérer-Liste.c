#include <stdio.h>
#include <stdlib.h>
#define N 8

struct LISTCHAIN
{
    struct LISTCHAIN *tete;
    int cle;
    struct LISTCHAIN *succ;
    struct LISTCHAIN *pred;
};

typedef struct LISTCHAIN *LISTECHAINEE;

LISTECHAINEE creer_liste()
{
    LISTECHAINEE L = (LISTECHAINEE)malloc(sizeof(struct LISTCHAIN));
    return L;
}

void afficher_liste(LISTECHAINEE L)
{
    LISTECHAINEE x = L->tete;
    while (x != NULL)
    {
        printf("%d\t", x->cle);
        x = x->succ;
    }
}

void detruire_liste(LISTECHAINEE L)
{
    free(L->tete);
    while (L->succ)
    {

        L = L->succ;
        free(L->pred);
    }
    free(L);
}

void inserer_liste(LISTECHAINEE L, LISTECHAINEE x)
{
    x->succ = L->tete;
    if (L->tete != NULL)
    {
        L->tete->pred = x;
    }
    L->tete = x;
    x->pred = NULL;
}

int main(int argc, char **argv)
{
    LISTECHAINEE L = creer_liste();
    L->tete = creer_liste();
    L->cle = 2;
    L->tete = L;
    L->pred = NULL;
    LISTECHAINEE L2 = creer_liste();
    L->succ = L2;
    L2->pred = L;
    L2->cle = 8;
    LISTECHAINEE L3 = creer_liste();
    L2->succ = L3;
    L3->pred = L2;
    L3->cle = 9;
    L3->succ = NULL;
    afficher_liste(L);
    printf("\n\n");
    LISTECHAINEE x = creer_liste();
    x->cle = 18;
    inserer_liste(L, x);
    afficher_liste(L);
    L = L->tete;
    detruire_liste(L);
    return 0;
}

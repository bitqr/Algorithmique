#include <stdio.h>
#include <stdlib.h>

struct LISTCHAIN
{
    struct LISTCHAIN *nil;
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
    LISTECHAINEE x = L->nil->succ;
    LISTECHAINEE n = L->nil;
    while (x != n)
    {
        printf("%d\t", x->cle);
        x = x->succ;
    }
}

LISTECHAINEE rechercher_liste2(LISTECHAINEE L, int k)
{
    LISTECHAINEE x = L->nil->succ;
    while ((x != L->nil) && (x->cle != k))
    {
        x = x->succ;
    }
    return x;
}

void supprimer_liste_2(LISTECHAINEE L, LISTECHAINEE x)
{
    x->pred->succ = x->succ;
    x->succ->pred = x->pred;
}

int main(int argc, char **argv)
{
    LISTECHAINEE L = creer_liste();
    L->nil = creer_liste();
    L->cle = 2;
    L->nil->succ = L;
    L->pred = L->nil;
    LISTECHAINEE L2 = creer_liste();
    L->succ = L2;
    L2->pred = L;
    L2->cle = 8;
    LISTECHAINEE L3 = creer_liste();
    L2->succ = L3;
    L3->pred = L2;
    L3->cle = 9;
    L3->succ = L->nil;
    L->nil->pred = L3;
    afficher_liste(L);
    printf("\n\n");
    LISTECHAINEE x = rechercher_liste2(L, 2);
    supprimer_liste_2(L, x);
    afficher_liste(L);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "Arborescence.h"

void empiler(PILE *P, ARBREBINAIRE *x)
{
    P->sommet++;
    P->tableau[P->sommet] = x;
}

int pile_vide(PILE *P)
{
    return (P->sommet == -1);
}

ARBREBINAIRE *depiler(PILE *P)
{
    if (pile_vide(P))
    {
        printf("Erreur, debordement negatif!\n");
        exit(EXIT_FAILURE);
    }
    P->sommet--;
    return P->tableau[P->sommet + 1];
}

PILE *creer_pile(int taille)
{
    PILE *P = (PILE *)malloc(sizeof(PILE));
    ARBREBINAIRE **t = (ARBREBINAIRE **)malloc(taille * sizeof(ARBREBINAIRE *));
    int i;
    for (i = 0; i < taille; i++)
        t[i] = (ARBREBINAIRE *)malloc(taille * sizeof(ARBREBINAIRE));
    P->sommet = -1;
    P->taille = taille;
    P->tableau = t;
    return P;
}

void afficher_arbre_2(ARBREBINAIRE *A)
{
    if (A != NULL)
    {
        PILE *p = creer_pile(3);
        empiler(p, A);
        ARBREBINAIRE *b;
        while (!pile_vide(p))
        {
            b = p->tableau[p->sommet];
            printf("%d\t", depiler(p)->cle);
            if (b->droit != NULL)
            {
                empiler(p, b->droit);
            }
            if (b->gauche != NULL)
            {
                empiler(p, b->gauche);
            }
        }
        free(p);
    }
}

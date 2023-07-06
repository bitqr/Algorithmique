#include <stdio.h>
#include <stdlib.h>
#define N 8

typedef struct
{
    int taille;
    int sommet;
    int *tableau;
} PILE;

PILE *creer_pile(int taille)
{
    PILE *P = (PILE *)malloc(sizeof(PILE));
    int *t = (int *)malloc(taille * sizeof(int));
    P->sommet = -1;
    P->taille = taille;
    P->tableau = t;
    return P;
}

void afficher_pile(PILE *P)
{
    int s = P->sommet;
    int i;
    printf("Les éléments de la pile du plus ancien au plus récent sont : \n\n");
    for (i = 0; i <= s; i++)
        printf("%d\t", P->tableau[i]);
    printf("\n\n");
}

int pile_vide(PILE *P)
{
    return (P->sommet == -1);
}

int depiler(PILE *P)
{
    if (pile_vide(P))
    {
        printf("Erreur, débordement négatif!\n");
        exit(EXIT_FAILURE);
    }
    P->sommet--;
    return P->tableau[P->sommet + 1];
}

void empiler(PILE *P, int x)
{
    P->sommet++;
    P->tableau[P->sommet] = x;
}

void multidep(PILE *S, int k)
{
    while ((!pile_vide(S)) && (k != 0))
    {
        depiler(S);
        k--;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage : %s taille_pile\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    PILE *P = creer_pile(N);
    int i;
    for (i = 0; i < N; i++)
        empiler(P, i);
    int k = atoi(argv[1]);
    printf("\nBonjour et bienvenue! Voici la pile construite avant que l'on dépile le moindre élément :\n\n");
    afficher_pile(P);
    multidep(P, k);
    printf("\n\nEt maintenant la pile obtenue après avoir dépilé %d éléments :\n\n", k);
    afficher_pile(P);
    free(P->tableau);
    free(P);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define N 8

struct FILES
{
    int longueur;
    int tete;
    int queue;
    int *tableau;
};

typedef struct FILES FILES;

FILES *creer_file(int taille)
{
    FILES *F = (FILES *)malloc(sizeof(FILES));
    int *t = (int *)malloc(taille * sizeof(int));
    F->tete = 0;
    F->longueur = taille;
    F->queue = 0;
    F->tableau = t;
    return F;
}

void afficher_file(FILES *F)
{
    if (F->tete == F->queue)
    {
        printf("La liste est vide\n\n");
    }
    else
    {
        int i = F->tete;
        printf("Les éléments de la file du plus ancien au plus récent sont : \n\n");
        while (i != F->queue)
        {
            printf("%d\t", F->tableau[i]);
            i++;
            i = i % F->longueur;
        }
        printf("\n\n");
    }
}

void enfiler(FILES *F, int x)
{
    F->tableau[F->queue] = x;
    if (F->queue + 1 == F->longueur)
    {
        F->queue = 0;
    }
    else
    {
        F->queue++;
    }
}

int defiler(FILES *F)
{
    int x = F->tableau[F->tete];
    if (F->tete + 1 == F->longueur)
    {
        F->tete = 0;
    }
    else
    {
        F->tete++;
    }
    return x;
}

int main(int agrc, char **argv)
{
    FILES *F = creer_file(N);
    enfiler(F, 4);
    enfiler(F, 6);
    enfiler(F, 17);
    defiler(F);
    afficher_file(F);
    free(F->tableau);
    free(F);
    return 0;
}
